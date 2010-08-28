//---------------------------------------------------------------------------

#include <vcl.h>    
#include <Clipbrd.hpp>
#pragma hdrstop
                  
#include "scihdr.h"
#include "textedit.h"
#include "main.h"
#include "explorer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MenuBar"
#pragma resource "*.dfm"
TWndTextEdit *WndTextEdit;
//---------------------------------------------------------------------------
__fastcall TWndTextEdit::TWndTextEdit(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void txEditorClose(EDITORTAG *edtTag)
{
}
//---------------------------------------------------------------------------
void txSaveRes(EDITORTAG *edtTag)
{
	((TWndTextEdit*)edtTag->Form)->Save1Click(edtTag->Form);
}
//---------------------------------------------------------------------------
BOOL TWndTextEdit::InitEditor(EDTWND *_edtWnd, U8 *resBuf, S16 resVer)
{
    edTag.EditorClose = txEditorClose;
    edTag.SaveRes = txSaveRes;
    edTag.edtWnd = _edtWnd;
    strcpy(edTag.defCaption,Caption.c_str());
    edTag.Form = this;
	Tag = (int)&edTag;

    if(!WndExplorer)
    	SaveToGame1->Visible = FALSE; 
    else {
		SET_EXPLORERED();
    }
    if(resBuf) {
        	text.data = (char*)resBuf;
            text.length = edTag.edtWnd->resIDfo.size;
            LoadText();    
            UPDATE_CAPTION();
    } else tbNewClick(this);
    FormResize(this);

	return TRUE;
}
//---------------------------------------------------------------------------
void TWndTextEdit::LoadText()
{
	int CurrentItem;

    ListView->Items->BeginUpdate();
    ListView->Items->Clear();
    int Offset = 0;
    text.totalStrings = 0;
    while(Offset < text.length) {
        CurrentItem = ListView->Items->Count;

        ListView->Items->Add();

        ListView->Items->Item[CurrentItem]->Caption = IntToStr(CurrentItem);
        ListView->Items->Item[CurrentItem]->SubItems->Add("");
        ListView->Items->Item[CurrentItem]->SubItems->Add(text.data+Offset);
        while(text.data[Offset++] != 0);
    	text.totalStrings++;
    }
    ListView->Items->EndUpdate();
    ListView->Selected = ListView->Items->Item[0];
    ListView->ItemFocused = ListView->Selected;

    CLEAR_RESCHANGED();
}
//---------------------------------------------------------------------------
void __fastcall TWndTextEdit::LoadTextFile(AnsiString FileName)
{
	U8 *buf;
    U32 len;
    WRITE_STATUS("Loading text...");

   	if((buf=ssLoadFile(ssFIO_ROOT|ssFIO_MESSAGE, FileName.c_str(), &len))==NULL)
    	return;
    if(CheckSCIFileHeader(buf)!=rsTEXT) {
		ssMessage(ssERROR,"The file your are trying to open, %s, is not a valid SCI text resource, or does not contain a valid header",FileName.c_str());
        ssFree(buf);
        return;
    }

    text.data = (char*)(buf+2);
    text.length = (U16)(len-(U16)2);

    LoadText();
                     
    ssFree(buf);

    WRITE_STATUS("Text loaded.");
}
//---------------------------------------------------------------------------
void __fastcall TWndTextEdit::tbNewClick(TObject *Sender)
{
    ListView->Items->Clear();
    ListViewChange(Sender,NULL,(TItemChange)NULL);

    CLEAR_RESCHANGED();
	CLEAR_FILENAME();

    WRITE_STATUS("New text created successfully.");  
    UPDATE_CAPTION();
}
//---------------------------------------------------------------------------
void __fastcall TWndTextEdit::tbOpenClick(TObject *Sender)
{
    if(!OpenDialog->Execute()) return;
    LoadTextFile(OpenDialog->FileName);     
    strcpy(edTag.edtWnd->fileName,OpenDialog->FileName.c_str());
    CLEAR_EXPLORERED();
    UPDATE_CAPTION();
}
//---------------------------------------------------------------------------
void __fastcall TWndTextEdit::Save1Click(TObject *Sender)
{
    if(!ListView->Items->Count) return;
    if((!CHECK_EXPLORERED())&&(edTag.edtWnd->fileName[0]=='\0')) {
        SaveAs1Click(Sender);
        return;
    }

    long TotalStrLen = 0;
    for(int i=0;i<ListView->Items->Count;i++)
        TotalStrLen+=ListView->Items->Item[i]->SubItems->Strings[1].Length()+1;

    WORD Offset=0;
    text.data = (char*)ssAlloc(rsMAX_SIZE);
    for(int i=0;i<ListView->Items->Count;i++) {
        int StrLen = ListView->Items->Item[i]->SubItems->Strings[1].Length()+1;
        char *TempString;
        if(StrLen>0) {
            TempString = (char*) malloc(StrLen+1);
            memcpy(TempString,ListView->Items->Item[i]->SubItems->Strings[1].c_str(),StrLen+1);
            int i=0;
            while(TempString[i]!='\0') {
                if(TempString[i]!='\r')
                    text.data[Offset++] = TempString[i];
                i++;
            }
            free(TempString);
        }
        text.data[Offset++] = '\0';
    }

    if(CHECK_EXPLORERED()) {
        RESINFO *newRI = WndExplorer->SaveResToGame((U8*)text.data, Offset, rsTEXT, EDTTAG->edtWnd->resIDfo.number);
     	if(!newRI) {
    		ssFree(text.data);
    		return;
        } else SetResIDfo(&EDTTAG->edtWnd->resIDfo,newRI);
    } else {
        FILE *fFile;
        if((fFile=ssOpenFile(ssFIO_ROOT|ssFIO_MESSAGE,edTag.edtWnd->fileName,"wb"))==NULL)
            return;
        ssFPutW((0x80|rsTEXT),fFile);
        ssFWrite(text.data,Offset,fFile);
        ssCloseFile(fFile);
    }
    ssFree(text.data);

    CLEAR_RESCHANGED();

    WRITE_STATUS("Text saved.");  
    UPDATE_CAPTION();
}
//---------------------------------------------------------------------------
void __fastcall TWndTextEdit::tbWriteScriptHeaderClick(TObject *Sender)
{
	FILE *fHeader;
    SaveDialog->Filter="SCI Script Header (*.sh)|*.sh|All Files (*.*)|*.*";
    if(OpenDialog->FileName!="")
        SaveDialog->FileName = OpenDialog->FileName+".sh";
    if(!SaveDialog->Execute()) return;

    if((fHeader = ssOpenFile(ssFIO_ROOT|ssFIO_MESSAGE,SaveDialog->FileName.c_str(), "w")) == NULL)
    	return;

    for(int i=0;i<ListView->Items->Count;i++)
        if(ListView->Items->Item[i]->SubItems->Strings[0]!="")
            ssFPrint(fHeader,"(define %s %d)\n",ListView->Items->Item[i]->SubItems->Strings[0].c_str(),i);

    ssCloseFile(fHeader);
}
//---------------------------------------------------------------------------
void __fastcall TWndTextEdit::tbViewAsMessageBoxClick(TObject *Sender)
{
    ShowMessage(ListView->Items->Item[ListView->Selected->Index]->SubItems->Strings[1]);
}
//---------------------------------------------------------------------------
void __fastcall TWndTextEdit::tbCopyClick(TObject *Sender)
{
    Clipboard()->SetTextBuf(ListView->Items->Item[ListView->Selected->Index]->SubItems->Strings[1].c_str());
}                    
//---------------------------------------------------------------------------
void TWndTextEdit::UpdateItemNumbers()
{
    ListView->Items->BeginUpdate();
    for(int i=0; i<ListView->Items->Count; i++)
        ListView->Items->Item[i]->Caption = IntToStr(i);
    ListView->Items->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TWndTextEdit::tbAddClick(TObject *Sender)
{               
    ListView->Items->BeginUpdate();
    ListView->Items->Add();
    TListItem *InsertItem = ListView->Items->Item[ListView->Items->Count-1];
    ListView->OnChange = NULL;
    ListView->Selected = InsertItem;
    ListView->ItemFocused = InsertItem;

    InsertItem->SubItems->Add("");
    InsertItem->SubItems->Add("");
    InsertItem->Caption = "";

    ListView->OnChange = ListViewChange;
    ListView->Items->EndUpdate();

    ListView->SetFocus();
    UpdateItemNumbers();
    InsertItem->SubItems->Strings[0]="";
    InsertItem->SubItems->Strings[1]="";

	SET_RESCHANGED();
}
//---------------------------------------------------------------------------
void __fastcall TWndTextEdit::tbDeleteClick(TObject *Sender)
{                  
    int OldSel = ListView->Selected->Index;
    if(ListView->Selected)
        ListView->Selected->Delete();

    if(!ListView->Items->Count) return;
    ListView->Selected =
        ListView->Items->Item[(OldSel>ListView->Items->Count)?OldSel:OldSel-1];
    UpdateItemNumbers();

	SET_RESCHANGED();
}
//---------------------------------------------------------------------------
void __fastcall TWndTextEdit::tbMoveUpClick(TObject *Sender)
{          
    TListItem *InsertItem, *OldItem = ListView->Items->Item[ListView->Selected->Index];
    int ItemIndex;
    if((ItemIndex=OldItem->Index)>0) {
        ListView->Items->BeginUpdate();
        ListView->OnChange = NULL;
        InsertItem = ListView->Items->Insert(ItemIndex-1);
        InsertItem->SubItems->Add("");
        InsertItem->SubItems->Add("");
        InsertItem->Assign(OldItem);
        ListView->Items->Delete(OldItem->Index);
        ListView->Selected = InsertItem;
        ListView->ItemFocused = InsertItem;
        ListView->Items->EndUpdate();
        UpdateItemNumbers();
        ListView->OnChange = ListViewChange;
    }

	SET_RESCHANGED();
}
//---------------------------------------------------------------------------
void __fastcall TWndTextEdit::tbMoveDownClick(TObject *Sender)
{
    TListItem *InsertItem, *OldItem = ListView->Items->Item[ListView->Selected->Index];
    int ItemIndex;
    if((ItemIndex=OldItem->Index)<ListView->Items->Count-1) {
        ListView->Items->BeginUpdate();
        ListView->OnChange = NULL;
        InsertItem = ListView->Items->Insert(ItemIndex+2);
        InsertItem->SubItems->Add("");
        InsertItem->SubItems->Add("");
        InsertItem->Assign(OldItem);
        ListView->Items->Delete(OldItem->Index);
        ListView->Selected = InsertItem;
        ListView->ItemFocused = InsertItem;
        ListView->Items->EndUpdate();
        UpdateItemNumbers();
        ListView->OnChange = ListViewChange;
    }

	SET_RESCHANGED();
}
//---------------------------------------------------------------------------
void __fastcall TWndTextEdit::SaveAs1Click(TObject *Sender)
{
	if(edTag.edtWnd->fileName[0])
    	SaveDialog->FileName=AnsiString(edTag.edtWnd->fileName);
    else if(CHECK_EXPLORERED())
    	SaveDialog->FileName = AnsiStringFmtRes(edTag.edtWnd->resIDfo.type,edTag.edtWnd->resIDfo.number);
	SaveDialog->Filter=OpenDialog->Filter;
	if(SaveDialog->Execute()) {
    	CLEAR_EXPLORERED();
        strcpy(edTag.edtWnd->fileName,SaveDialog->FileName.c_str());
    	Save1Click(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TWndTextEdit::SaveToGame1Click(TObject *Sender)
{
	SET_EXPLORERED();
    Save1Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TWndTextEdit::Exit1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------


void __fastcall TWndTextEdit::FormResize(TObject *Sender)
{
	if(!Tag) return;
    NameEdit->Width = NamePanel->Width-NameLabel->Width;
}                      
//---------------------------------------------------------------------------
BOOL TWndTextEdit::TestString(AnsiString String)
{
    int StrLen = String.Length();
    if(StrLen>0) {
        char *TempString = (char*) ssAlloc(StrLen+1);
        memcpy(TempString,String.c_str(),StrLen+1);
        for(int i=0;i<StrLen;i++)
            if(!(((TempString[i]>='0'&&TempString[i]<='9')&&i!=0)||
               (TempString[i]>='A'&&TempString[i]<='Z')||
               (TempString[i]>='a'&&TempString[i]<='z')||
                (TempString[i]=='_'))) {
                    ssMessage(ssERROR, "String is not a valid name! The Name may only contain alphanumeric characters and underscores, and can not begin with a number!");
                    ssFree(TempString);
                    return FALSE;
                }
        ssFree(TempString);
    }
    return TRUE;
}
//---------------------------------------------------------------------------

void __fastcall TWndTextEdit::NameEditChange(TObject *Sender)
{                  
	if(!Tag) return;
    if(!ListView->Selected || !ListView->Selected->SubItems->Count) return;
    if(TestString(NameEdit->Text))
        ListView->Selected->SubItems[0].Strings[0] = NameEdit->Text;
    else
        NameEdit->Text = ListView->Selected->SubItems[0].Strings[0];
	SET_RESCHANGED();
}
//---------------------------------------------------------------------------

void __fastcall TWndTextEdit::EditBoxChange(TObject *Sender)
{         
	if(!Tag) return;
    if(ListView->Selected && ListView->Selected->SubItems->Count)
        ListView->Selected->SubItems->Strings[1] = EditBox->Text;  
	SET_RESCHANGED();
}
//---------------------------------------------------------------------------

void __fastcall TWndTextEdit::ListViewDblClick(TObject *Sender)
{
    if(ListView->Selected)
        EditBox->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TWndTextEdit::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if(Shift.Contains(ssCtrl)) {
    	switch(Key) {
            case 'N':
                tbNewClick(Sender);
                break;
            case 'O':
                tbOpenClick(Sender);
                break;
            case 'S':
                Save1Click(Sender);
                break;
         	case 'C':
            	tbCopyClick(Sender);
                break;
         	case 'A':
            	tbAddClick(Sender);
                break;
         	case 'D':
            	tbDeleteClick(Sender);
                break;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndTextEdit::ListViewChange(TObject *Sender,
      TListItem *Item, TItemChange Change)
{
	if(!Tag) return;
    if(ListView->Selected) {
        NameEdit->Text = Item->SubItems[0].Strings[0];
        NameEdit->Enabled = TRUE;
        NameEdit->Color = clWindow;

        EditBox->Lines->BeginUpdate();
        EditBox->Lines->SetText(ListView->Items->Item[Item->Index]->SubItems[0].Strings[1].c_str());
        EditBox->Lines->EndUpdate();
        EditBox->Enabled = TRUE;
        EditBox->Color = clWindow;

        Save1->Enabled = TRUE;
        tbSave->Enabled = TRUE;
        SaveAs1->Enabled = TRUE;
        WriteScriptHeader1->Enabled = TRUE;
        tbWriteScriptHeader->Enabled = TRUE;
        AsMessageBox1->Enabled = TRUE;
        tbViewAsMessageBox->Enabled = TRUE;   
        Delete1->Enabled = TRUE;
        tbDelete->Enabled = TRUE;
        Copy1->Enabled = TRUE;
        tbCopy->Enabled = TRUE;
        MoveUp1->Enabled = TRUE;
        tbMoveUp->Enabled = TRUE;
        MoveDown1->Enabled = TRUE;
        tbMoveDown->Enabled = TRUE;
    } else {
        EditBox->Lines->SetText("");
        EditBox->Enabled = FALSE;
        EditBox->Color = clBtnFace;
        NameEdit->Text = "";
        NameEdit->Enabled = FALSE;
        NameEdit->Color = clBtnFace;

        Save1->Enabled = FALSE;
        tbSave->Enabled = FALSE;
        SaveAs1->Enabled = FALSE;
        WriteScriptHeader1->Enabled = FALSE;
        tbWriteScriptHeader->Enabled = FALSE;
        AsMessageBox1->Enabled = FALSE;
        tbViewAsMessageBox->Enabled = FALSE;  
        Delete1->Enabled = FALSE;
        tbDelete->Enabled = FALSE;
        Copy1->Enabled = FALSE;
        tbCopy->Enabled = FALSE;
        MoveUp1->Enabled = FALSE;
        tbMoveUp->Enabled = FALSE;
        MoveDown1->Enabled = FALSE;
        tbMoveDown->Enabled = FALSE;
    }
}
//---------------------------------------------------------------------------

