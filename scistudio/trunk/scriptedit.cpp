//---------------------------------------------------------------------------

#include <vcl.h>    
#include <htmlhelp.h>
#pragma hdrstop

#include "scriptedit.h"
#include "main.h"
#include "explorer.h"
#include "config.h"
#include "newroom.h"
#include "printprev.h"
#include "editorprops.h"
#include "makefile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MenuBar"
#pragma link "SynEditPrint"
#pragma link "SynEditExport"
#pragma link "SynEditHighlighter"
#pragma link "SynExportHTML"
#pragma link "SynHighlighterSCI"
#pragma resource "*.dfm"
TWndScriptEdit *WndScriptEdit;     
extern TWndScriptEdit *TheScriptWindow;
//---------------------------------------------------------------------------
#include "code.c"
#include "data.c"
#include "dirlist.c"
#include "scc.c"
#include "strhndlr.c"
#include "vocab.c"
//---------------------------------------------------------------------------
__fastcall TWndScriptEdit::TWndScriptEdit(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::OpenScript(AnsiString fileName,BOOL HEADER)
{
	sMEMO *m;

    m = firstMemo;
    while(m) {
    	if(AnsiString(m->FileName) == fileName) {
         	pcMemos->ActivePage = m->Tab;
            pcMemosChange(this);
            return;
        }
     	m = m->next;
    }

	if(newCount==1 && !activeMemo->Modified && strcmp(activeMemo->FileName,"noname0.sc")==0)
    	DeleteMemo(activeMemo,FALSE);
    strcpy(Directory,ExtractFilePath(fileName).c_str());
    OpenDialog->InitialDir = AnsiString(Directory);
    SaveDialog->InitialDir = AnsiString(Directory);
	m = NewMemo(fileName);
    m->FILE_CAN_COMPILE = TRUE;
    m->HEADER = HEADER;
	m->Memo->Lines->LoadFromFile(fileName);

    pcMemosChange(this);
    WRITE_STATUS("File "+AnsiString(m->FileName)+" successfully loaded.");
}

//---------------------------------------------------------------------------
void scEditorClose(EDITORTAG *edtTag)
{
	EDTWND *edtWnd = (EDTWND*)(edtTag->edtWnd);
	TWndScriptEdit *wnd = (TWndScriptEdit*)(edtTag->edtWnd->Wnd);

    wnd->OnResize = NULL;

    for(int i=0;i<hlTOTAL;i++) {
        config.shHighlights[i].Foreground = WndMain->SynAttr[i]->Foreground;
        config.shHighlights[i].Background = WndMain->SynAttr[i]->Background;
        config.shHighlights[i].Style = WndMain->SynAttr[i]->Style;
    }

	config.SHOW_CLASS_REF  = wnd->pnClassRef->Visible;
	config.SHOW_KERNEL_REF = wnd->pnKernelRef->Visible;

    if(wnd->activeMemo) {
    	config.shHighlightsSET = TRUE;

    	if(!config.shFont)
    	    config.shFont = new TFont;
    	config.shFont->Assign(wnd->activeMemo->Memo->Font);

    	if(!config.shGutter)
    	    config.shGutter = new TSynGutter;
    	config.shGutter->Assign(wnd->activeMemo->Memo->Gutter);

    	config.shTabWidth = wnd->activeMemo->Memo->TabWidth;
   	 	config.shExtraLineSpacing = wnd->activeMemo->Memo->ExtraLineSpacing;
    	config.shOptions = wnd->activeMemo->Memo->Options;
    }

    while(wnd->firstMemo)
     	wnd->DeleteMemo(wnd->firstMemo,FALSE);
    wnd->activeMemo = NULL;

    if(scrEdtWnd==edtWnd) scrEdtWnd = NULL;
}
//---------------------------------------------------------------------------
void scSaveRes(EDITORTAG *edtTag)
{
	((TWndScriptEdit*)edtTag->Form)->Save1Click(edtTag->Form);
}
//---------------------------------------------------------------------------
BOOL TWndScriptEdit::InitEditor(EDTWND *_edtWnd, U8 *resBuf, S16 resVer)
{
    edTag.EditorClose = scEditorClose;
    edTag.SaveRes = scSaveRes;
    edTag.edtWnd = _edtWnd;
    strcpy(edTag.defCaption,Caption.c_str());      
    edTag.Form = this;
	Tag = (int)&edTag;

    InitMemos();

    FindText="";
    RepText="";

    if(WndExplorer) {
    	SET_EXPLORERED();
    	strcpy(Directory,Game.path);
    	strcpy(BinDirectory,Directory);
        CompileAllScripts1->Visible = TRUE;
    } else {
    	strcpy(Directory,Program.path);
    	strcpy(BinDirectory,Directory);
    }

    dockCount = 3;  /*
    char **kptr = (char**)ssalloc(TOTAL_KERNELS*sizeof(char*));
    for(int i=0;i<TOTAL_KERNELS;i++)
    	kptr[i] = KernelNames[i];
    */
    TTreeNode *t;
    for(int i=0;i<114;i++) {
    	t=TreeView1->Items->Add(NULL,(AnsiString)KrnlInfo[i].Name);
        t->ImageIndex = 2;
        t->SelectedIndex = 2;
    }

    ShowCodeReference1Click(this);
    if(!config.SHOW_CLASS_REF)	ClassReference1Click(this);
    if(!config.SHOW_KERNEL_REF)	KernelReference1Click(this);

    Splitter1->Visible = FALSE;
    MessagePanel->Visible = FALSE;

    FormResize(this);


    EmptyScript1Click(this);

	return TRUE;
}           
//---------------------------------------------------------------------------
void TWndScriptEdit::InitMemos()
{
	memoCount	= 0;
    newCount	= 0;
    firstMemo	= NULL;
    lastMemo	= NULL;
    activeMemo	= NULL;
}
//---------------------------------------------------------------------------
sMEMO *TWndScriptEdit::NewMemo(AnsiString FileName)
{
	sMEMO *memo;
    TTabSheet *tabSheet;
    TSynMemo *synMemo;

    memo 					= (sMEMO*)ssAlloc(sizeof(sMEMO));
    if(lastMemo) {
    	lastMemo->next 		= memo;
    } else
    	firstMemo 			= memo;
    memo->prev 				= lastMemo;
    memo->next 				= NULL;
    lastMemo 				= memo;
    activeMemo 				= lastMemo;


    tabSheet 				= new TTabSheet(pcMemos);
    tabSheet->TabVisible 	= FALSE;
    tabSheet->PageControl 	= pcMemos;
    tabSheet->Caption 		= ExtractFileName(FileName);
    tabSheet->Tag 			= (int)memo;
    pcMemos->ActivePage 	= tabSheet;
   	tabSheet->TabVisible 	= TRUE;

    TPanel *p = new TPanel(pcMemos->ActivePage);
    p->Parent = pcMemos->ActivePage;
    p->Align = alClient;
    p->BorderStyle = bsNone;
    p->BevelOuter = bvLowered;
    p->BevelInner = bvNone;
    synMemo 				= new TSynMemo(p);
    synMemo->Parent 		= p;

    if(config.shFont)
        synMemo->Font->Assign(config.shFont);
    if(config.shGutter)
        synMemo->Gutter->Assign(config.shGutter);
    synMemo->TabWidth 			= config.shTabWidth;
    synMemo->TabStop 			= FALSE;
    synMemo->ExtraLineSpacing 	= config.shExtraLineSpacing;
    synMemo->Options 			= config.shOptions;
    synMemo->Highlighter 		= WndMain->SynSCISyn1;
    synMemo->Align 				= alClient;
    synMemo->PopupMenu 			= PopupMenu1;
    synMemo->WantTabs 			= TRUE;
    synMemo->Tag 				= (int)memo;
    synMemo->OnStatusChange 	= MemoStatusChange;
    synMemo->OnChange 			= MemoChange;
    synMemo->OnKeyUp 			= MemoKeyUp;
    synMemo->BorderStyle		= bsNone;

    strcpy(memo->FileName, FileName.c_str());
                                  
    memo->Tab 					= tabSheet;
    memo->Memo 					= synMemo;

    memo->FILE_CAN_COMPILE		= FALSE;
    memo->Modified				= 0;

    memoCount++;

    return memo;
}
//---------------------------------------------------------------------------
void TWndScriptEdit::DeleteMemo(sMEMO *memo,BOOL MAKE_NEW)
{
	if(!memo) return;
    if(memo->Memo)	delete memo->Memo;
    if(memo->Tab)	delete memo->Tab;

    if(memo->next) memo->next->prev = memo->prev;
    else lastMemo = memo->prev;
    if(memo->prev) memo->prev->next = memo->next;
    else firstMemo = memo->next;

    memoCount--;

	ssFree(memo);

    if(memoCount==0) {
    	if(MAKE_NEW) EmptyScript1Click(this);
    } else {
    	activeMemo = (sMEMO*)pcMemos->ActivePage->Tag;
    }
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::EmptyScript1Click(TObject *Sender)
{
	NewMemo("noname"+IntToStr(newCount)+".sc");
    newCount++;
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::RoomScript1Click(TObject *Sender)
{
	AnsiString d;
    if(WndExplorer)
    	d = AnsiString(Game.path)+"\\src";
    else d = GetCurrentDir();

	TDlgNewRoom	*RoomWin = new TDlgNewRoom(this);
	RoomWin->SetItUp(this, d);
    RoomWin->ShowModal();
    delete RoomWin;
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::Open1Click(TObject *Sender)
{
    OpenDialog->Filter = WndMain->SynSCISyn1->DefaultFilter;
    if(!OpenDialog->Execute()) return;
    OpenDialog->InitialDir = "";
    OpenScript(OpenDialog->FileName,ExtractFileExt(OpenDialog->FileName)==".sh");
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::OpenSCISH1Click(TObject *Sender)
{
	AnsiString FileName = AnsiString(Program.path)+"\\include\\sci.sh";
    if(!FileExists(FileName)) {
    	ShowMessage("File "+FileName+" does not exist!");
        return;
    }
    OpenScript(FileName,TRUE);
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::Save1Click(TObject *Sender)
{
	SaveScript(activeMemo,FALSE);
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::SaveAs1Click(TObject *Sender)
{
	SaveScript(activeMemo,TRUE);
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::CloseFile1Click(TObject *Sender)
{
	DeleteMemo(activeMemo,TRUE);
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::Print1Click(TObject *Sender)
{     
    SynEditPrint1->Lines->Assign(activeMemo->Memo->Lines);
    SynEditPrint1->Font = activeMemo->Memo->Font;
    SynEditPrint1->TabWidth = activeMemo->Memo->TabWidth;
    SynEditPrint1->Print();
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::PrintPreview1Click(TObject *Sender)
{
    TDlgPrintPrev *PrintPrevDlg = new TDlgPrintPrev(this);
    SynEditPrint1->Lines->Assign(activeMemo->Memo->Lines);
    SynEditPrint1->Font = activeMemo->Memo->Font;
    SynEditPrint1->TabWidth = activeMemo->Memo->TabWidth;
    PrintPrevDlg->ShowModal();
    delete PrintPrevDlg;
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::Close1Click(TObject *Sender)
{        
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::Undo1Click(TObject *Sender)
{
    activeMemo->Memo->Undo();
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::Cut1Click(TObject *Sender)
{
    activeMemo->Memo->CutToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::Copy1Click(TObject *Sender)
{
    activeMemo->Memo->CopyToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::Paste1Click(TObject *Sender)
{
    activeMemo->Memo->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::Clear1Click(TObject *Sender)
{
    activeMemo->Memo->ClearSelection();
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::SelectAll2Click(TObject *Sender)
{
    activeMemo->Memo->SelectAll();
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::Find1Click(TObject *Sender)
{
    FindDialog1->FindText = FindText;
    FindDialog1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::FindAgain1Click(TObject *Sender)
{      
  if(FindDialog1->FindText == "") FindDialog1->Execute();
  else FindDialog1Find(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::Replace1Click(TObject *Sender)
{
    ReplaceDialog1->FindText = FindText;
    ReplaceDialog1->ReplaceText = RepText;
    ReplaceDialog1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::Messages1Click(TObject *Sender)
{
    Splitter1->Visible = !Splitter1->Visible;
    MessagePanel->Visible = !MessagePanel->Visible;
    UpdateStatus();
}         
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::ShowCodeReference1Click(TObject *Sender)
{
	if(!dockCount) {
        ClassReference1Click(Sender);
        KernelReference1Click(Sender);
    }
	pnRefs->Visible = TRUE;
    //pnRefs->ManualDock(Panel3,NULL,alNone);
	//pnRefs->Visible = TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::ClassReference1Click(TObject *Sender)
{
	pnClassRef->Visible = !pnClassRef->Visible;
    if(pnClassRef->Visible) {
    	if(dockCount) {
        	pnKernelRef->Align = alTop;
        	pnKernelRef->Height = pnRefs->Height/2;
            pnClassRef->Top = pnKernelRef->Height;
            pnClassRef->Align = alClient;
        }
    	dockCount |= 1;
    } else {
    	dockCount &= 2;
		pnKernelRef->Align = alClient;
    }
    ClassReference1->Checked = dockCount&1;
    pnRefsResize(this);
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::KernelReference1Click(TObject *Sender)
{
	pnKernelRef->Visible = !pnKernelRef->Visible;
    if(pnKernelRef->Visible) {
    	if(dockCount) {
        	pnClassRef->Align = alTop;
        	pnClassRef->Height = pnRefs->Height/2;
            pnKernelRef->Top = pnClassRef->Height;
            pnKernelRef->Align = alClient;
        }
    	dockCount |= 2;
    } else {
    	dockCount &= 1;
		pnClassRef->Align = alClient;
    }              
    KernelReference1->Checked = dockCount&2;
    pnRefsResize(this);
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::Compile2Click(TObject *Sender)
{
    int Result;
    char tStr2[255];

    COMPILE_SUCCESS = FALSE;
    Save1Click(this);
    if(!activeMemo->FILE_CAN_COMPILE) return;
    if(!Directory) {
    	ShowMessage("No directory set!");
		return;
    }


    lbMessage->Items->Clear();
    Splitter1->Visible = TRUE;
    MessagePanel->Visible = TRUE;
    UpdateStatus();
    TheScriptWindow = this;

	/* Compile the script */
    if(Directory[0]) {
        if(Directory[strlen(Directory)-1]=='\\')
            Directory[strlen(Directory)-1]='\0';
    }
    if(BinDirectory[0]) {
        if(BinDirectory[strlen(BinDirectory)-1]=='\\')
            BinDirectory[strlen(BinDirectory)-1]='\0';
    }
    include_dirs=NULL;
    lib_dirs=NULL;
   	game_dir=NULL;
    source_dir=NULL;

    if(Directory[0]) include_dirs=dirlist_add(include_dirs,Directory);
    strcpy(tStr2,(AnsiString(Program.path)+"\\include").c_str());
    include_dirs=dirlist_add(include_dirs,tStr2);

    if(Directory[0]) lib_dirs=dirlist_add(lib_dirs,Directory);
    strcpy(tStr2,(AnsiString(Program.path)+"\\lib").c_str());
    lib_dirs=dirlist_add(lib_dirs,tStr2);


    source_dir = dirlist_add(NULL, Directory);
    game_dir = dirlist_add(NULL, BinDirectory);
    strcpy(tStr2,activeMemo->FileName);

    Result = CompileScript(tStr2,1);
	FreeEverything();
    dirlist_free(include_dirs);
    dirlist_free(lib_dirs);
    dirlist_free(game_dir);
    dirlist_free(source_dir);

	if(Result) {
        ShowMessage(smCOMPILE,"%s Successful!", activeMemo->FileName);
        WRITE_STATUS("File "+AnsiString(activeMemo->FileName)+" successfully compiled.");
	} else {
        ShowMessage(smCOMPILE,"%s Failed!", activeMemo->FileName);
        WRITE_STATUS("File "+AnsiString(activeMemo->FileName)+" failed to compile.");
    }

    if(CHECK_EXPLORERED()) {
    	if(ResIdx.selRes==rsSCRIPT&&WndExplorer->lvResources->Selected) {
			AnsiString FileName = AnsiString(Game.path)+"\\src\\"+WndExplorer->lvResources->Selected->Caption+".sc";
            if(FileExists(FileName)) {
            	WndExplorer->ScriptMemo->Lines->LoadFromFile(FileName);
            }
        }
    }

    if(lbMessage->Items->Count) {
        if(lbMessage->ItemIndex==-1) lbMessage->ItemIndex = 0;
        lbMessageClick(this);
    }

    COMPILE_SUCCESS = Result;
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::CompileandRun1Click(TObject *Sender)
{
	if(CHECK_EXPLORERED())
    	strcpy(BinDirectory, Game.path);
    else
    	strcpy(BinDirectory, Directory);
    Compile2Click(this);
    if(COMPILE_SUCCESS)
        WndMain->DoGameExecution(AnsiString(BinDirectory));
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::CompileMakeFile1Click(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::CompileAllScripts1Click(TObject *Sender)
{

    int Result;
    char tStr2[255];

    COMPILE_SUCCESS = FALSE;

    strcpy(Directory,(AnsiString(Game.path)+"\\src").c_str());

    lbMessage->Items->Clear();
    Splitter1->Visible = TRUE;
    MessagePanel->Visible = TRUE;
    UpdateStatus();
    TheScriptWindow = this;

	/* Compile the script */
    if(Directory[0]) {
        if(Directory[strlen(Directory)-1]=='\\')
            Directory[strlen(Directory)-1]='\0';
    }
    if(BinDirectory[0]) {
        if(BinDirectory[strlen(BinDirectory)-1]=='\\')
            BinDirectory[strlen(BinDirectory)-1]='\0';
    }
    include_dirs=NULL;
    lib_dirs=NULL;
   	game_dir=NULL;
    source_dir=NULL;

    if(Directory[0]) include_dirs=dirlist_add(include_dirs,Directory);
    strcpy(tStr2,(AnsiString(Program.path)+"\\include").c_str());
    include_dirs = dirlist_add(include_dirs,tStr2);
    include_dirs = dirlist_add(include_dirs, Directory);

    if(Directory[0]) lib_dirs=dirlist_add(lib_dirs,Directory);
    strcpy(tStr2,(AnsiString(Program.path)+"\\lib").c_str());
    lib_dirs = dirlist_add(lib_dirs,tStr2);
    lib_dirs = dirlist_add(lib_dirs, Directory);


    source_dir = dirlist_add(NULL, Directory);
    game_dir = dirlist_add(NULL, BinDirectory);


    WndExplorer->ChangeSelResType(rsSCRIPT);
    WndExplorer->FillListView();
    for(int i=0;i<WndExplorer->lvResources->Items->Count;i++) {
    	strcpy(tStr2,(AnsiString(Game.path)+"\\src\\"+WndExplorer->lvResources->Items->Item[i]->Caption+".sc").c_str());

    	if(!(bool)(Result = CompileScript(tStr2,1))) break;

        ShowMessage(smCOMPILE,"%s Successful!", tStr2);
        lbMessage->ItemIndex = lbMessage->Items->Count-1;
        Refresh();
        lbMessage->Repaint();
    }
		if(Result) {           
        	ShowMessage(smCOMPILE,"Compile All Done!");
        	WRITE_STATUS("Build Successful!");
		} else {
        	ShowMessage(smCOMPILE,"%s Failed!", tStr2);
        	WRITE_STATUS("Build Failed!");
    	}    
        lbMessage->ItemIndex = lbMessage->Items->Count-1;

	FreeEverything();
    dirlist_free(include_dirs);
    dirlist_free(lib_dirs);
    dirlist_free(game_dir);
    dirlist_free(source_dir);

    if(lbMessage->Items->Count) {
        if(lbMessage->ItemIndex==-1) lbMessage->ItemIndex = 0;
        lbMessageClick(this);
    }

    COMPILE_SUCCESS = Result;
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::CreateMakeFile1Click(TObject *Sender)
{
    TDlgMakeFile *MakeFileWin = new TDlgMakeFile(this);
    MakeFileWin->ShowModal();
	delete MakeFileWin;
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::EnvironmentOptions1Click(TObject *Sender)
{
    TDlgEditorProps *MemoPropWin = new TDlgEditorProps(this);
    MemoPropWin->ShowModal();
    delete MemoPropWin;
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::ExporttoHTML1Click(TObject *Sender)
{
    SaveDialog->Filter = SynExporterHTML1->DefaultFilter;
    SaveDialog->DefaultExt = "html";
    if(!SaveDialog->Execute()) return;
    SaveDialog->InitialDir = "";

    SynExporterHTML1->ExportAll(activeMemo->Memo->Lines);
    SynExporterHTML1->SaveToFile(SaveDialog->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::MenuTitleDraw(TCanvas *ACanvas, TRect &ARect, AnsiString s)
{
    ACanvas->Brush->Color = clMagicFrame;
    ACanvas->FillRect(Rect(ARect.Left,ARect.Top,ARect.Right,ARect.Bottom));
    ACanvas->Brush->Color = clMagicFace;
    ACanvas->FillRect(Rect(ARect.Left+2,ARect.Top+2,ARect.Right-2,ARect.Bottom-2));
    ACanvas->Font->Color = clMagicText;
    ACanvas->TextOut(ARect.left+6,ARect.top+3,s);

	ACanvas->Pen->Color = clMagicShadow;
    ACanvas->MoveTo(ARect.Right-2,ARect.Top+1);
    ACanvas->LineTo(ARect.Right-2,ARect.Bottom-2);
    ACanvas->LineTo(ARect.Left+1,ARect.Bottom-2);
	ACanvas->Pen->Color = clMagicHighlight;
    ACanvas->LineTo(ARect.Left+1,ARect.Top+1);
    ACanvas->LineTo(ARect.Right-2,ARect.Top+1);
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::MenuTitleDrawItem(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, bool Selected)
{                              
    ACanvas->Font->Style = TFontStyles() << fsBold;
    ACanvas->Font->Name = "Tahoma";
    ACanvas->Font->Size = 8;
	MenuTitleDraw(ACanvas,ARect,"Help File");
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::GoToClass1Click(TObject *Sender)
{
	TTreeNode *item=TreeView2->Selected;
    if(!item) return;
    while(item->Parent) item = item->Parent;
    WndMain->SCIHtmlHelp(
         GetDesktopWindow(),
         (AnsiString(HELP_NAME)+"::/scc/class_"+item->Text.LowerCase()+".html").c_str(),
         HH_DISPLAY_TOC,
         NULL
    );
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::ClassSystemHelpIndex1Click(TObject *Sender)
{
    WndMain->SCIHtmlHelp(
         GetDesktopWindow(),
         (AnsiString(HELP_NAME)+"::/scc/classsys.html").c_str(),
         HH_DISPLAY_TOC,
         NULL
    );
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::lbMessageClick(TObject *Sender)
{
    int i;
    char PChr[256];
    if(lbMessage->ItemIndex==-1) return;
    if(strcmp(lbMessage->Items->Strings[lbMessage->ItemIndex].SubString(1,9).c_str(),
        "[Error]: ")!=0) return;

    int StrLen = lbMessage->Items->Strings[lbMessage->ItemIndex].Length()-8;
    strcpy(PChr, lbMessage->Items->Strings[lbMessage->ItemIndex].SubString(10,StrLen).c_str());
    PChr[StrLen]='\0';
    for(i=0;PChr[i]!='\0'&&PChr[i]!='(';i++);
    if(PChr[i]!='(') return;

    PChr[i] = '\0';
    if(strcmp(PChr,ExtractFileName(activeMemo->FileName).c_str())!=0) return;
    char *PCNum = PChr+i+1;
    for(i=0;PCNum[i]!='\0'&&PCNum[i]!=')';i++);
    if(PCNum[i]!=')') return;
    PCNum[i] = '\0';

    int Ln = StrToInt(AnsiString(PCNum));
    free(PChr);

    activeMemo->Memo->CaretY = Ln;
    activeMemo->Memo->EnsureCursorPosVisible();
    TPoint Pnt;
    Pnt.x=1;
    Pnt.y=Ln;
    activeMemo->Memo->BlockBegin = Pnt;
    Pnt.y++;
    activeMemo->Memo->BlockEnd = Pnt;
    activeMemo->Memo->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::lbMessageKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
	lbMessageClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::MemoStatusChange(TObject *Sender,
      TSynStatusChanges Changes)
{
    UpdateStatus();
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::MemoChange(TObject *Sender)
{                              /*
	if(activeMemo->Memo->Modified)*/
    	activeMemo->Modified++; /*
    else
    	activeMemo->Modified=0;  */
	if(activeMemo->Modified==1)
		UpdateTitleBar();
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::UpdateStatus()
{
    StatusBar1->Top = ClientHeight;
    if(MessagePanel->Visible) {
        if(activeMemo) Splitter1->Top = activeMemo->Memo->Top+activeMemo->Memo->Height;
        //MessagePanel->Top = Splitter1->Top+Splitter1->Height;
    }
    if(activeMemo) StatusBar1->Panels->Items[0]->Text = IntToStr(activeMemo->Memo->CaretY)+":"+IntToStr(activeMemo->Memo->CaretX);
}
//---------------------------------------------------------------------------

void __fastcall TWndScriptEdit::MemoKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
	FormKeyDown(Sender,Key,Shift);
}
//---------------------------------------------------------------------------

void __fastcall TWndScriptEdit::FindDialog1Find(TObject *Sender)
{
	if(activeMemo==NULL) return;
    TSynSearchOptions SearchType;
    if(FindDialog1->Options.Contains(frWholeWord)) SearchType << ssoWholeWord;
    if(FindDialog1->Options.Contains(frMatchCase)) SearchType << ssoMatchCase;
    if(!FindDialog1->Options.Contains(frDown)) SearchType << ssoBackwards;

    if(!activeMemo->Memo->SearchReplace(FindDialog1->FindText,NULL,SearchType))
        ShowMessage("Search string '"+FindDialog1->FindText+"' not found!");
    else
        FindText = FindDialog1->FindText;

    FindDialog1->CloseDialog();
}       
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::UpdateTitleBar()
{
    if(!memoCount)
        Caption = "Script Editor";
    else  {
    	activeMemo->Tab->Caption = ExtractFileName(activeMemo->FileName);
    	if(activeMemo->Modified)
        	activeMemo->Tab->Caption = activeMemo->Tab->Caption+AnsiString("*");
        Caption = "Script Editor - "+pcMemos->ActivePage->Caption;
    }
	UpdateCaption(EDTTAG->edtWnd, this, Caption);
}
//---------------------------------------------------------------------------
void TWndScriptEdit::ChangeMemoCaption(sMEMO *memo, AnsiString Caption)
{
    if(memo!=NULL) {
    	memo->Tab->Caption = ExtractFileName(Caption);
    	strcpy(memo->FileName,Caption.c_str());
    }
}

//---------------------------------------------------------------------------
    int LastMessageIndex;
int ShowMessage(int Message, char *String, ...)
{
	va_list argptr;
	int cnt;
    AnsiString MessageStr;

	switch(Message) {
		case smNONE:
		case smAPPEND:
			break;
		case smERROR:
			MessageStr.sprintf("[Error]: ");
			break;
		case smWARNING:
			MessageStr.sprintf("[Warning]: ");
			break;
		case smCOMPILE:
			MessageStr.sprintf("[Compile]: ");
			break;
		default:
			MessageStr.sprintf("[Error]: %s(%d): ", IN_HEADER?IncludeFileName:ExtractFileName(AnsiString(ScriptName)).c_str(), LineNumber);

		    va_start(argptr, String);
		    cnt = MessageStr.cat_vprintf(Errors[Message], argptr);
		    va_end(argptr);
	};
	if(Message<1) {
		va_start(argptr, String);
		cnt = MessageStr.cat_vprintf((char*)String, argptr);
		va_end(argptr);
	}
	if(Message!=smAPPEND)
        LastMessageIndex = TheScriptWindow->lbMessage->Items->Add(MessageStr);
    else
        TheScriptWindow->lbMessage->Items->Strings[LastMessageIndex] =
            TheScriptWindow->lbMessage->Items->Strings[LastMessageIndex]+MessageStr;

	return(cnt);
}            
//---------------------------------------------------------------------------
int TWndScriptEdit::ParseSaveChanges()
{
	int result;
	sMEMO *m = firstMemo;
    while(m) {
		if(m->Modified) {
        	result = ssMessage(ssNOTICE|ssYESNOCANCEL,
				"Would you like to save your changes made to %s?",
				m->FileName);
        	if(result==IDYES) {
            	if(!SaveScript(m,FALSE)) return SVCHG_CANCEL;
            } else if(result==IDCANCEL)
        		return SVCHG_CANCEL;
        }
        m = m->next;
    }

    return SVCHG_NO;
}
//---------------------------------------------------------------------------
BOOL TWndScriptEdit::SaveScript(sMEMO *memo,BOOL ASK_SAVE)
{
    if(ASK_SAVE||!activeMemo->FILE_CAN_COMPILE) {
    	SaveDialog->Filter = WndMain->SynSCISyn1->DefaultFilter;
    	SaveDialog->DefaultExt = "sc";
    	if(!SaveDialog->Execute()) return FALSE;  
    	SaveDialog->InitialDir = "";
    	ChangeMemoCaption(activeMemo, SaveDialog->FileName);
    	strcpy(Directory,ExtractFilePath(activeMemo->FileName).c_str());
    	activeMemo->FILE_CAN_COMPILE = TRUE;
    }

    if(FileExists(AnsiString(activeMemo->FileName)+".bak")) DeleteFile(AnsiString(activeMemo->FileName)+".bak");
    if(FileExists(AnsiString(activeMemo->FileName))) RenameFile(AnsiString(activeMemo->FileName),AnsiString(activeMemo->FileName)+".bak");
    activeMemo->Memo->Lines->SaveToFile(AnsiString(activeMemo->FileName));
    WRITE_STATUS("File "+AnsiString(activeMemo->FileName)+" successfully saved.");

    activeMemo->Modified = 0;

    UpdateTitleBar();
    return TRUE;
}
//---------------------------------------------------------------------------

void __fastcall TWndScriptEdit::FormResize(TObject *Sender)
{
    UpdateStatus();
}
//---------------------------------------------------------------------------
void __fastcall TWndScriptEdit::pcMemosChange(TObject *Sender)
{
	activeMemo = (sMEMO*)pcMemos->ActivePage->Tag;
    if(activeMemo==NULL) return;
    strcpy(Directory,ExtractFilePath(activeMemo->FileName).c_str());
    if(CHECK_EXPLORERED())
    	strcpy(BinDirectory,Game.path);
    else
    	strcpy(BinDirectory,Directory);
    if(activeMemo->HEADER) {
      	tbCompileRun->Enabled = FALSE;
      	tbCompile->Enabled = FALSE;
      	CompileandRun1->Enabled = FALSE;
      	Compile2->Enabled = FALSE;
    } else {
      	tbCompileRun->Enabled = TRUE;
      	tbCompile->Enabled = TRUE;
      	CompileandRun1->Enabled = TRUE;
      	Compile2->Enabled = TRUE;
    }

    UpdateTitleBar();
}
//---------------------------------------------------------------------------


void __fastcall TWndScriptEdit::ReplaceDialog1Replace(TObject *Sender)
{
    TSynSearchOptions SearchType;
    SearchType << ssoReplace;
    if(ReplaceDialog1->Options.Contains(frWholeWord)) SearchType << ssoWholeWord;
    if(ReplaceDialog1->Options.Contains(frMatchCase)) SearchType << ssoMatchCase;
    if(!ReplaceDialog1->Options.Contains(frDown)) SearchType << ssoBackwards;
    if(ReplaceDialog1->Options.Contains(frReplaceAll)) SearchType << ssoReplaceAll;

    if(!activeMemo->Memo->SearchReplace(ReplaceDialog1->FindText,ReplaceDialog1->ReplaceText,SearchType))
        ShowMessage("Search string '"+ReplaceDialog1->FindText+"' not found!");
    else {
        FindText = ReplaceDialog1->FindText;
        RepText = ReplaceDialog1->ReplaceText;
    }

    ReplaceDialog1->CloseDialog();
}
//---------------------------------------------------------------------------

void __fastcall TWndScriptEdit::Redo1Click(TObject *Sender)
{
    activeMemo->Memo->Redo();
}
//---------------------------------------------------------------------------

void __fastcall TWndScriptEdit::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Shift.Contains(ssCtrl)) {
        switch(Key) {
            case 'O':
                Open1Click(Sender);
                break;
            case 'S':
                Save1Click(Sender);
                break;
            case 'P':
                Print1Click(Sender);
                break;
            case 'F':
                Find1Click(Sender);
                break;
            case 'R':
                Replace1Click(Sender);
                break;
        }
    } else {
        switch(Key) {    
    		case VK_F3:
            	FindAgain1Click(Sender);
                break;
            case VK_F8:
                Compile2Click(Sender);
                break;
            case VK_F9:
                CompileandRun1Click(Sender);
                break;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndScriptEdit::pnRefsResize(TObject *Sender)
{
	pnRefs->Visible = (dockCount);
    if(!dockCount) {
    	pnRefs->Width = 0;
    	return;
    }
	pnRefs->Width = 148;
    if(dockCount==3) {
    	spRefs->Visible = TRUE;
        if(pnKernelRef->Top) {
        	spRefs->Top = pnKernelRef->Height;
        } else {
        	spRefs->Top = pnClassRef->Height;
        }
    } else {
    	spRefs->Visible = FALSE;
    }
}
//---------------------------------------------------------------------------



void __fastcall TWndScriptEdit::pnRefsEndDock(TObject *Sender,
      TObject *Target, int X, int Y)
{
	((TPanel*)Sender)->Tag = Tag;
}
//---------------------------------------------------------------------------

void __fastcall TWndScriptEdit::Panel3DockDrop(TObject *Sender,
      TDragDockObject *Source, int X, int Y)
{
	Source->Control->Align = alLeft;
	Source->Control->Left  = 0;
}
//---------------------------------------------------------------------------

void __fastcall TWndScriptEdit::Panel3DockOver(TObject *Sender,
      TDragDockObject *Source, int X, int Y, TDragState State,
      bool &Accept)
{
	Accept = ( ((TPanel*)Source->Control)->Tag == Tag );
}
//---------------------------------------------------------------------------

void __fastcall TWndScriptEdit::GoToKernel1Click(TObject *Sender)
{
	TTreeNode *item=TreeView1->Selected;
    if(!item) return;
    while(item->Parent) item = item->Parent;
    WndMain->SCIHtmlHelp(
         GetDesktopWindow(),
         (AnsiString(HELP_NAME)+"::/scc/kernel_"+item->Text.LowerCase()+".html").c_str(),
         HH_DISPLAY_TOC,
         NULL
    );
}
//---------------------------------------------------------------------------

void __fastcall TWndScriptEdit::KernelMenuTitle1DrawItem(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, bool Selected)
{
	MenuTitleDraw(ACanvas,ARect,"Help File");
}
//---------------------------------------------------------------------------


void __fastcall TWndScriptEdit::KernelFunctionsHelpIndex1Click(
      TObject *Sender)
{
    WndMain->SCIHtmlHelp(
         GetDesktopWindow(),
         (AnsiString(HELP_NAME)+"::/scc/kernels.html").c_str(),
         HH_DISPLAY_TOC,
         NULL
    );
}
//---------------------------------------------------------------------------

void __fastcall TWndScriptEdit::TreeView1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{                 /*
	TTreeNode* t = TreeView1->GetNodeAt( X,  Y);
    if(!t) {
    	pnKrnlInfo->Visible = FALSE;
    	return;
    }
	RECT r,r2;
    GetWindowRect(TreeView1->Handle,&r);
    GetWindowRect(Handle,&r2);
	int i = t->Index;
    AnsiString s = AnsiString(KrnlInfo[i].Ret)+" "+AnsiString(KrnlInfo[i].Name)+" ("+AnsiString(KrnlInfo[i].Params)+")";
    Image1->Canvas->Font = pnKrnlInfo->Font;
    int w = Image1->Canvas->TextWidth(s);
	TRect ARect;
    ARect.left = 0;
    ARect.top = 0;
    ARect.right = w+16;
    ARect.bottom = 22;
    pnKrnlInfo->Left = r.left+X-r2.left;
    pnKrnlInfo->Top = r.top+Y-r2.top;
    pnKrnlInfo->Width  = ARect.right;
    pnKrnlInfo->Height = ARect.bottom;
	Graphics::TBitmap *b = new Graphics::TBitmap;
    b->Width = ARect.right;
    b->Height = ARect.bottom;
    MenuTitleDraw(b->Canvas, ARect, s);
    Image1->Picture->Bitmap->Assign(b);
    delete b;
    pnKrnlInfo->Visible = TRUE; */
}
//---------------------------------------------------------------------------



void __fastcall TWndScriptEdit::muKernelInfoAdvancedDrawItem(
      TObject *Sender, TCanvas *ACanvas, TRect &ARect,
      TOwnerDrawState State)
{
	TTreeNode *item=TreeView1->Selected;
    if(!item) return;
	int i = item->Index;
    AnsiString s = AnsiString(KrnlInfo[i].Ret)+" "+AnsiString(KrnlInfo[i].Name)+" ("+AnsiString(KrnlInfo[i].Params)+")";
    ACanvas->Font->Style = TFontStyles() << fsBold;
    ACanvas->Font->Name = "Tahoma";
    ACanvas->Font->Size = 9;
    MenuTitleDraw(ACanvas, ARect, s);
}
//---------------------------------------------------------------------------


void __fastcall TWndScriptEdit::muKernelInfoMeasureItem(TObject *Sender,
      TCanvas *ACanvas, int &Width, int &Height)
{                    
	TTreeNode *item=TreeView1->Selected;
    if(!item) return;
	int i = item->Index;
    AnsiString s = AnsiString(KrnlInfo[i].Ret)+" "+AnsiString(KrnlInfo[i].Name)+" ("+AnsiString(KrnlInfo[i].Params)+")";

    ACanvas->Font->Style = TFontStyles() << fsBold;
    ACanvas->Font->Name = "Tahoma";
    ACanvas->Font->Size = 9;
    int w = ACanvas->TextWidth(s);
    Width = w+16;
    Height = 22;
}
//---------------------------------------------------------------------------


void __fastcall TWndScriptEdit::TreeView1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	if(Shift.Contains(ssLeft)) PopupMenu5->Popup(Mouse->CursorPos.x-X+TreeView1->Width,Mouse->CursorPos.y);
}
//---------------------------------------------------------------------------


void __fastcall TWndScriptEdit::muClassTitleMeasureItem(TObject *Sender,
      TCanvas *ACanvas, int &Width, int &Height)
{
	Height = 22;
}
//---------------------------------------------------------------------------

void __fastcall TWndScriptEdit::muClassTitleDrawItem(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, bool Selected)
{
	TTreeNode *item=TreeView2->Selected;
    if(!item) return;
    while(item->Parent) item = item->Parent;  
    ACanvas->Font->Style = TFontStyles() << fsBold;
    ACanvas->Font->Name = "Tahoma";
    ACanvas->Font->Size = 9;
    MenuTitleDraw(ACanvas, ARect, "Class: "+item->Text);
}
//---------------------------------------------------------------------------

