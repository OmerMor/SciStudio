//---------------------------------------------------------------------------

#include <vcl.h>
#include <FileCtrl.hpp>
#pragma hdrstop

#include "explorer.h"
#include "scihdr.h"
#include "main.h"
#include "addresource.h"
#include "properties.h"
#include "resrebuild.h"
#include "dirdialog.h"
#include "gfxedits.h"
#include "config.h"
#include "scriptedit.h"
#include "picrender.h"
#include "expcels.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SynEdit"
#pragma link "SynMemo"
#pragma resource "*.dfm"
TWndExplorer *WndExplorer;
//---------------------------------------------------------------------------
AnsiString INIFileName;
AnsiString FilterAllRes=
	"All Resources|VIEW.*;PIC.*;SCRIPT.*;TEXT.*;SOUND.*;"
    "MEMORY.*;VOCAB.*;FONT.*;CURSOR.*;PATCH.*|View Resource (view.*)|"
    "VIEW.*|Pic Resource (pic.*)|PIC.*|Script Resource (script.*)|SCRIPT.*|"
    "Text Resource (text.*)|TEXT.*|Sound Resource (sound.*)|SOUND.*|Vocab "
    "Resource (vocab.*)|VOCAB.*|Font Resource (font.*)|FONT.*|Cursor Resource "
    "(cursor.*)|CURSOR.*|Patch Resource (patch.*)|PATCH.*|All Files (*.*)|*.*";
AnsiString FliterScript=
	"Script Resource (script.*)|SCRIPT.*|All Files (*.*)|*.*";

TViewStyle vsListView[4] = {vsIcon,vsSmallIcon,vsList,vsReport};
//---------------------------------------------------------------------------
#define RESET_SELLV() \
	ResListViewGotoRes( ResListViewGetRes(lvResources->Items->Item[0]) )
#define SET_SELLV_ITEM(i) \
    	ResIdx.selResItems[ResIdx.selRes] = ResListViewGetRes(i)
#define GET_SELLV_ITEM() \
    	ResIdx.selResItems[ResIdx.selRes]
#define FORMAT_RESNUMSTR(s,n)\
	s.sprintf("%03d", n)
#define MAKE_DEFAULT_RESLABEL(s,t,n)\
	s.sprintf("%s%03d", resTypes[t].name,n)

#define SOURCE_FILES_EXIST()\
	DirectoryExists(AnsiString(Game.path)+"\\src")


#define CENTER_IT(a,b)  \
	a->Left = (b->Width-a->Width)>>1;   \
    if(a->Left<0) a->Left = 0;          \
	a->Top = (b->Height-a->Height)>>1;  \
    if(a->Top<0) a->Top = 0

#define SetFlag(t, n) \
	DONE_FLAGS[(t<<7)+(n>>3)] |= (1<<(n&7))
#define GetFlag(t, n) \
	((DONE_FLAGS[(t<<7)+(n>>3)]>>(n&7)) & 1)
#define SetFlagPack(n) \
	RES_PACKS[(n>>3)] |= (1<<(n&7))
#define GetFlagPack(n) \
	((RES_PACKS[(n>>3)]>>(n&7)) & 1)
//---------------------------------------------------------------------------
int __stdcall SubItemSort(long Item1, long Item2, long ParamSort);
int __stdcall ItemSort(long Item1, long Item2, long ParamSort);
int __stdcall SubItemSort_Size(long Item1, long Item2, long ParamSort);
int __stdcall SubItemSort_Encode(long Item1, long Item2, long ParamSort);
int curColumn;
//---------------------------------------------------------------------------
void exEditorClose(EDITORTAG *edtTag)
{
	TWndExplorer *we = ((TWndExplorer*)edtTag->Form);

    we->scrFont->OnResize       = NULL;
    we->scbView->OnResize       = NULL;
    we->PalPrevPage->OnResize	= NULL;
    we->PicScrollBox->OnResize  = NULL;
    we->CursorPage->OnResize    = NULL;
    we->pnlGamePic->OnResize    = NULL;

    we->lvResources->OnChange 	= NULL;
    we->lvResources->OnKeyUp  	= NULL;
    we->tvResTypes->OnChange  	= NULL;

    we->tmrView->Enabled 		= FALSE;
    we->tmrPic->Enabled 		= FALSE;
    we->tmrView->OnTimer      	= NULL;
    we->tmrPic->OnTimer       	= NULL;

    if(we->SAVE_GAME_NOTES)
		we->mmoGameNotes->Lines->SaveToFile(AnsiString(Game.path)+"\\game.txt");

    switch(we->lvResources->ViewStyle) {
    	case vsIcon:
        	config.ewsViewStyle = 0;
            break;
        case vsList:
        	config.ewsViewStyle = 1;
        	break;
        case vsReport:
            config.ewsViewStyle = 2;
            break;
        case vsSmallIcon:
            config.ewsViewStyle = 3;
            break;
    }

    config.ewsManagerBarWidth = we->pnResTypes->Width;
    config.ewsPreviewBarWidth = we->pnPreview->Width;

	if(we->lvHeaders) delete we->lvHeaders;

    we->ClearResStructs();
    ssFree(we->palInfo);
}
//---------------------------------------------------------------------------
BOOL exQueryClose(EDITORTAG *edtTag)
{
    return TRUE;
}
//---------------------------------------------------------------------------
BOOL TWndExplorer::InitEditor(EDTWND *_edtWnd, U8 *resBuf, S16 resVer)
{
    edTag.EditorClose = exEditorClose;
    edTag.QueryClose = exQueryClose;
    edTag.edtWnd = _edtWnd;
    strcpy(edTag.defCaption,Caption.c_str());
    edTag.Form = this;
	Tag = (int)&edTag;

	WndExplorer = (TWndExplorer*) _edtWnd->Wnd;

	// set up the resType array so SS can run at top-notch efficiency!
	resTypes[rsVIEW].previewPage 		= ViewPage;
	resTypes[rsPIC].previewPage 		= PicPage;
	resTypes[rsSCRIPT].previewPage 		= ScriptPage;
	resTypes[rsTEXT].previewPage 		= MemoPage;
	resTypes[rsSOUND].previewPage 		= SoundPage;
	resTypes[rsMEMORY].previewPage 		= PageNoPrev;
	resTypes[rsVOCAB].previewPage 		= MemoPage;
	resTypes[rsFONT].previewPage 		= FontPage;
	resTypes[rsCURSOR].previewPage 		= CursorPage;
	resTypes[rsPATCH].previewPage 		= PageNoPrev;
	resTypes[rsBITMAP].previewPage 		= PageNoPrev;
	resTypes[rsPALETTE].previewPage 	= PalPrevPage;
	resTypes[rsCDAUDIO].previewPage 	= PageNoPrev;
	resTypes[rsAUDIO].previewPage 		= PageNoPrev;
	resTypes[rsSYNC].previewPage 		= PageNoPrev;
	resTypes[rsMESSAGE].previewPage 	= MemoPage;
	resTypes[rsMAP].previewPage 		= PageNoPrev;
	resTypes[rsHEAP].previewPage 		= PageNoPrev;
	resTypes[rsCHUNK].previewPage 		= PageNoPrev;
	resTypes[rsAUDIO36].previewPage 	= PageNoPrev;
	resTypes[rsSYNC36].previewPage 		= PageNoPrev;
	resTypes[rsTRANSLATION].previewPage = PageNoPrev;
	resTypes[rsROBOT].previewPage 		= PageNoPrev;
	resTypes[rsVMD].previewPage 		= PageNoPrev;
	resTypes[rsDUCK].previewPage 		= PageNoPrev;
	resTypes[rsCLUT].previewPage 		= PageNoPrev;
	resTypes[rsTARGA].previewPage 		= PageNoPrev;
	resTypes[rsZZZ].previewPage 		= PageNoPrev;

	resTypes[lvHEADER].previewPage 		= ScriptPage;

    pvView		= NULL;
    pvPic		= NULL;
    pvScript   	= NULL;
    pvText		= NULL;
    pvVocab000	= NULL;
    pvFont		= NULL;
    pvCursor	= NULL;
    pvPal		= NULL;
    viewPal		= NULL;
    palInfo		= NULL;

    scrEdtWnd	= NULL;

    PAL_CAN_DISPOSE = FALSE;

	SetUpInterface();

    return TRUE;
}                
//---------------------------------------------------------------------------
void TWndExplorer::ClearResStructs()
{                   
	ViewDispose(pvView);
	PicDispose(pvPic);
	ssFree(pvScript);
	ssFree(pvText);
	ssFree(pvVocab000);  
	FontDispose(pvFont);
	CursorDispose(pvCursor);
    SCI1PalDispose(pvPal);
    if(PAL_CAN_DISPOSE)
    	SCI1PalDispose(viewPal);
}
//---------------------------------------------------------------------------
void TWndExplorer::ChangeSelResType(int newResType)
{
	if(ResIdx.selRes == newResType) return;

    if(ResIdx.selRes < TOTAL_RES_TYPES && ResIdx.selRes != -1 && GET_SELLV_ITEM() && GET_SELLV_ITEM()->type != ResIdx.selRes) {
     	if(ResIdx.totalRes[ResIdx.selRes])
        	RESET_SELLV();
        else
        	ResIdx.selResItems[ResIdx.selRes]= NULL;
    }

    ResIdx.selRes = newResType;
                         
    // Show the tree view of the selected resource type
	if(newResType==lvHEADER) {
      	lvResources->Visible	= FALSE;
      	lvHeaders->Visible		= TRUE;
		DoPreview();
    } else {            
      	if(lvHeaders) lvHeaders->Visible		= FALSE;
      	lvResources->Visible	= TRUE;
   	 	FillListView();
    }
}
//---------------------------------------------------------------------------
void TWndExplorer::DoPreview()
{
	RESTYPE *resType=&resTypes[ResIdx.selRes];
    RESINFO *resInfo;
    U8 *resBuf=NULL,*palBuf=NULL;
    U16 resLen,palLen;
    BOOL oldANIVIEW;

    if(ResIdx.selRes < 0 || ResIdx.selRes >= TOTAL_RES_TYPES2 || resType==NULL) return;

    PreviewCaption->Caption = AnsiString(resType->name)+" Preview";
    lblResType->Caption = AnsiString(resType->name)+" Resources";
    lblResTypeDesc->Caption = "The game's "+AnsiString(resType->description)+".";

    PanelLV->Visible = TRUE;
	imgResType->Canvas->Brush->Color = clBtnFace;
    imgResType->Canvas->FillRect(Rect(0,0,25,25));
    WndMain->ilMainToolbarA->GetBitmap(resType->iconIndex,imgResType->Picture->Bitmap);

    if((ResIdx.selRes<TOTAL_RES_TYPES&&((lvResources->Items->Count==0)||lvResources->SelCount>1))||(ResIdx.selRes>=TOTAL_RES_TYPES&&((lvHeaders->Items->Count==0)||lvHeaders->SelCount>1))) {
		PreviewPC->ActivePage = PageNoPrev;
        return;
    }

    if((ResIdx.selRes<TOTAL_RES_TYPES&&lvResources->Selected==NULL)||(ResIdx.selRes>=TOTAL_RES_TYPES&&lvHeaders->Selected==NULL)) {
        return;
    }

    PreviewPC->ActivePage = resType->previewPage;

    if(!config.ewsSHOW_PREVIEW||!RES_FREE) return;
    ClearResStructs();

    // extract the resource for previewing
    if(ResIdx.selRes < TOTAL_RES_TYPES) {
    	resInfo = ResListViewGetRes(lvResources->Selected);
		if((resBuf = ExtractResource(resInfo, erBUFFER, &resLen, NULL))==NULL) return;
    	RES_FREE = FALSE;
    }

    switch(ResIdx.selRes) {
     	case rsVIEW:    /*
    		if(Game.version->viewType!=sv_VT_EGA&&Game.version->viewType!=sv_VT_VGA10) {
                PreviewPC->ActivePage = PageNoPrev;
    			break;
    		}     */
        	oldANIVIEW = ANIVIEW;
            ANIVIEW = FALSE;
            if((pvView = ViewLoad(resBuf,resLen,Game.version->viewType))==NULL) break;
            ViewSetUpUpDowns(pvView,SwitchLoop_UpDn,SwitchCel_UpDn);

    		if(PAL_CAN_DISPOSE)
    			SCI1PalDispose(viewPal);
  			PAL_CAN_DISPOSE = FALSE;
            if(pvView->palVGA) {
            	imVPal->Visible = TRUE;
                if(pvView->palVGA->SET) {
            		cbViewPal->Visible = FALSE;
                   	viewPal = pvView->palVGA;
                } else {            
            		cbViewPal->Visible = TRUE;
                	if(palInfo[cbViewPal->ItemIndex]&&(palBuf = ExtractResource(palInfo[cbViewPal->ItemIndex], erBUFFER, &palLen, NULL))==NULL) {
                   	} else {
    					if(Game.version->palType==sv_PALT_11) {
    						if((viewPal = SCI11PalLoad(palBuf,palLen,FALSE))==NULL) break;
    					} else {
    						if((viewPal = SCI1PalLoad(palBuf,palLen,FALSE))==NULL) break;
    					}
                    	if(!viewPal) {
                    		WRITE_STATUS("Unable to load external palette!");
                    	   	viewPal = pvView->palVGA;
                   		}
                    }
                    if(!viewPal) {
                    	WRITE_STATUS("Unable to load external palette!");
                       	viewPal = pvView->palVGA;
             		} else
                    	PAL_CAN_DISPOSE = TRUE;
                }
                DrawPaletteAsBitmap(imVPal->Picture->Bitmap,viewPal,16,16,imVPal->Width,imVPal->Height,clWindow);
            } else {
            	imVPal->Visible = FALSE;
            	cbViewPal->Visible = FALSE;
            }
            SwitchLoop_UpDnClick(SwitchLoop_UpDn,(TUDBtnType)NULL);
            ANIVIEW = oldANIVIEW;
            scbViewResize(this);
        	break;
     	case rsPIC:              /*
    		if(Game.version->picType==sv_PT_VGA11||Game.version->picType==sv_PT_VGA32) {
                PreviewPC->ActivePage = PageNoPrev;
    			break;
    		}                   */
            if((pvPic = PicLoad(resBuf,resLen,plEXPLORER,activePalette,Game.version->picType))==NULL) break;
            btnPicScreenClick(VisualButton);
            if(pvPic->palVGA) {
            	imPPal->Top = imgPic->Top+imgPic->Height+4;
            	pnPicCtl->Top = imPPal->Top+imPPal->Height+4;
            	imPPal->Visible = TRUE;
            	DrawPaletteAsBitmap(imPPal->Picture->Bitmap,pvPic->palVGA,32,8,imPPal->Width,imPPal->Height,clWindow);
            } else {
            	imPPal->Top = imgPic->Top+imgPic->Height+4;
            	pnPicCtl->Top = imPPal->Top;
            	imPPal->Visible = FALSE;
            }
            PicScrollBoxResize(this);
        	break;
     	case rsSCRIPT:
        	if(SOURCE_FILES_EXIST()) {
        		aszTemp = AnsiString(Game.path)+"\\src\\"+lvResources->Selected->Caption+".sc";
        		if(FileExists(aszTemp)) {
                 	ScriptMemo->Lines->LoadFromFile(aszTemp);
                	break;
                }
            }
            GetScriptInfo(resBuf,resLen,ScriptMemo);
        	break;
     	case rsTEXT:
        	TextToMemo(resBuf,resLen,PreviewMemo);
        	break;
     	case rsSOUND:
        	break;
     	case rsVOCAB:   
            DecodeVocab(resBuf,resInfo->number,resLen,PreviewMemo);
        	break;
     	case rsFONT:
            if((pvFont = FontLoad(resBuf,resLen))==NULL) break;
            scrFontResize(this);
        	break;
     	case rsCURSOR:
            if((pvCursor = CursorLoad(resBuf,resLen))==NULL) break;
            if(Game.version->cursorType==sv_CT_2COL) {
        		CursorDrawImage(imgCursor,pvCursor,&palCursor);
            	MouseHS->Caption = "Hot Spot: "+AnsiString(pvCursor->hotSpot?
					"Center (8,8)":"Top Left (0,0)");
            } else {
        		CursorDrawImage(imgCursor,pvCursor,&palCursorVGA);
            	MouseHS->Caption = "Hot Spot: ("+IntToStr(pvCursor->hotSpotX)+","+IntToStr(pvCursor->hotSpotY)+")";
            }
            CursorDispose(pvCursor);
            CursorPageResize(this);
        	break;
     	case rsPATCH:
        	break;
     	case lvHEADER: 
        	if(SOURCE_FILES_EXIST()) {
        		if(!lvHeaders->Selected) break;
                aszTemp = AnsiString(Game.path)+"\\src\\"+lvHeaders->Selected->Caption+".sh";
        		if(FileExists(aszTemp)) {
                 	ScriptMemo->Lines->LoadFromFile(aszTemp);
                	break;
                }
            }
        	break;  
     	case rsPALETTE:
        	SCI1PalDispose(pvPal);
            if(Game.version->palType==sv_PALT_11) {
            	if((pvPal = SCI11PalLoad(resBuf,resLen,FALSE))==NULL) break;
            } else {
            	if((pvPal = SCI1PalLoad(resBuf,resLen,FALSE))==NULL) break;
            }
            PalPrevPageResize(this);
        	break;
     	case rsMESSAGE:
        	MessageToMemo(resBuf,resLen,PreviewMemo);
        	break;
        default:;
    }

    ssFree(resBuf); // not to worry if it wasn't allocated, it's set to NULL at
    				// the start, and my free routine handles that
	RES_FREE = TRUE;
}
//---------------------------------------------------------------------------
__fastcall TWndExplorer::TWndExplorer(TComponent* Owner)
	: TForm(Owner)
{
}       
//---------------------------------------------------------------------------
void __fastcall TWndExplorer::UpdateExplorerBar(BOOL f)
{
        if(f) {
         	tbExplorer->ShowCaptions	= TRUE;
        	tbExplorer->ButtonHeight	= 40;
        	tbExplorer->ButtonWidth	= 45;
        } else {                         
         	tbExplorer->ShowCaptions = FALSE;
        	tbExplorer->ButtonHeight	= 28;
        	tbExplorer->ButtonWidth	= 29;
        }
}
//---------------------------------------------------------------------------
void __fastcall TWndExplorer::ProcessConfig()
{                   
	TListItem *hItem;
    WIN32_FIND_DATA FindFileData;
    HANDLE hFindFile;

    ResIdx.selRes = -1;

    UpdateExplorerBar(WndMain->pnlToolBar->ShowCaptions);

	TIniFile *GameINI;
    INIFileName = AnsiString(Game.path)+"\\game.ini";
  	if(FileExists(INIFileName)) {
    	Game.flags |= gfHAS_PROJECT;
    	GameINI = new TIniFile(INIFileName);
       	strcpy(Game.name,GameINI->ReadString("Game","Name",Game.name[0]?AnsiString(Game.name):AnsiString("New Game")).c_str());
        delete GameINI;
    } else {
    	if(Game.name[0]=='\0') {
        	strcpy(Game.name,ExtractFileName(AnsiString(Game.path)).c_str());
        	if(Game.name[0]=='\0') strcpy(Game.name,"My Game");
        }
    }

    AnsiString ss=(AnsiString(Game.path)+"\\game.bmp");
    if(FileExists(ss)) {
			imgGamePic->Picture->Bitmap->LoadFromFile(ss);
    }
    ss=(AnsiString(Game.path)+"\\game.ico");
    if(FileExists(ss)) {
			imgGameIcon->Picture->Icon->LoadFromFile(ss);
        	WndMain->ilTreeView->Delete(0);
        	WndMain->ilTreeView->InsertIcon(0, imgGameIcon->Picture->Icon);
    }/* else {
    	WndMain->ilTreeView->GetIcon(0,imgGameIcon->Picture->Icon);
    } */
    SAVE_GAME_NOTES = FALSE;
    ss=(AnsiString(Game.path)+"\\game.txt");
    if(FileExists(ss)) {
			mmoGameNotes->Lines->LoadFromFile(ss);
    }

    lLocation->Caption = AnsiString(Game.path);

    curColumn = lvcNAME;
	memset(ResIdx.selResItems,NULL,sizeof(ResIdx.selResItems));

	// set up header listview
    if(SOURCE_FILES_EXIST()) {
    	TListColumn  *NewColumn;
		lvHeaders = new TListView(PanelLV);
        lvHeaders->Parent = PanelLV;
        lvHeaders->BorderStyle = bsNone;
        lvHeaders->Visible = FALSE;
        lvHeaders->Align = alClient;
        lvHeaders->Top = lvResources->Top;
		lvHeaders->ReadOnly = TRUE;
        lvHeaders->RowSelect = TRUE;
        lvHeaders->MultiSelect = TRUE;
        lvHeaders->HideSelection = FALSE;
        lvHeaders->ViewStyle = vsReport;
        lvHeaders->OnChange = lvResourcesChange;
        lvHeaders->OnClick = lvHeadersClick;
        lvHeaders->OnDblClick = lvResourcesDblClick;

        NewColumn = lvHeaders->Columns->Add();
        NewColumn->Caption="Name";
        NewColumn->AutoSize = TRUE;

    	wsprintf(szTemp, "%s\\src\\*.sh", Game.path);
    	hFindFile = FindFirstFile(
        	szTemp,
        	&FindFileData
    	);
   		if(hFindFile!=INVALID_HANDLE_VALUE) do {
        	if(FindFileData.dwFileAttributes!=FILE_ATTRIBUTE_DIRECTORY) {
        		for(int i=strlen(FindFileData.cFileName)-1;i>=0;i--) {
            		if(FindFileData.cFileName[i]=='.') {
                		FindFileData.cFileName[i]='\0';
                    	break;
                	}
            	}
                hItem = lvHeaders->Items->Add();
                hItem->Caption = AnsiString(FindFileData.cFileName);
        	}
    	} while(FindNextFile(hFindFile,	&FindFileData));

        if(lvHeaders->Items->Count) lvHeaders->Selected = lvHeaders->Items->Item[0];
	} else lvHeaders = NULL;


    	switch(config.ewsViewStyle) {
        	case 0:
            	lvResources->ViewStyle = vsIcon;
            	break;
        	case 1:
       	     	lvResources->ViewStyle = vsList;
            	break;
        	case 2:
            	lvResources->ViewStyle = vsReport;
            	break;
        	case 3:
            	lvResources->ViewStyle = vsSmallIcon;
            	break;
    	}
        lvResources->FlatScrollBars		= (config.ewsFLAT_SCROLL);
        lvResources->GridLines			= (config.ewsGRID_LINES);
        lvResources->HotTrack			= (config.ewsHOT_TRACK);
        if(config.ewsHAND_POINT)		lvResources->HotTrackStyles << htHandPoint;
        if(config.ewsUNDERLINEC)		lvResources->HotTrackStyles << htUnderlineCold;
        if(config.ewsUNDERLINEH)		lvResources->HotTrackStyles << htUnderlineHot;


    WndMain->ManagerBar1->Visible = TRUE;
    WndMain->ManagerBar1->Checked = !config.ewsManagerBarV;
    pnResTypes->Width = config.ewsManagerBarWidth;
    WndMain->ManagerBar1Click(this);
    WndMain->PreviewBar1->Visible = TRUE;
    WndMain->PreviewBar1->Checked = !config.ewsSHOW_PREVIEW;
    pnPreview->Width = config.ewsPreviewBarWidth;
    WndMain->PreviewBar1Click(this);
    WndMain->ResourceCaption1->Visible = TRUE;
    WndMain->ResourceCaption1->Checked = !config.ewsSHOW_RESCAP;
    WndMain->ResourceCaption1Click(this);

	FillTreeView(GAME_USES_RES(config.ewsDefResType)?config.ewsDefResType:0);

    lbSCIVersion->Caption = AnsiString(Game.version->name);
}
//---------------------------------------------------------------------------
// if there is currently no config, but the user edits a label, make one to
// save the changes
void __fastcall TWndExplorer::MakeConfig()
{                              
    Game.flags |= gfHAS_PROJECT;
  	//if(FileExists(INIFileName)) return;

    TIniFile *GameINI = new TIniFile(INIFileName);    
    GameINI->WriteString("Game","Name",Game.name);
    delete GameINI;
}
//---------------------------------------------------------------------------
void __fastcall TWndExplorer::SetUpInterface()
{
    RES_FREE = TRUE;
	lvKEYS_ENABLED=FALSE;

	ProcessConfig();

    if(lvResources->Items->Count) {
    	SET_SELLV_ITEM(lvResources->Items->Item[0]);
    	ResListViewGotoRes(GET_SELLV_ITEM());
	}

    tvResTypesChange(this,tvResTypes->Selected);

    WndMain->AddOpenGameToList(Game.path);

    WndMain->Caption = AnsiString(Program.title)+" - "+AnsiString(Game.name);

    WndMain->Close1->Enabled 		= TRUE;
    WndMain->Run1->Enabled 			= TRUE;
    WndMain->SB_CloseGame->Enabled	= TRUE;
    WndMain->SB_RunGame->Enabled 	= TRUE;
    WndMain->Resource1->Visible 	= TRUE;
    WndMain->ManagerBar1->Visible 	= TRUE;
    WndMain->PreviewBar1->Visible 	= TRUE;

    activePalette = 0;
    activeScreen  = asVISUAL;

    WRITE_STATUS("Game Loaded.");

	lvKEYS_ENABLED=TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TWndExplorer::ReopenGame()
{
	FreeGame();
    if(!LoadMap()) {
		ssMessage(ssERROR,"An extemely odd error occured that shouldn't have. Go figure. The game will now close.");
        Close();
        return;
    }
    SetUpInterface();
}
//---------------------------------------------------------------------------
void __fastcall TWndExplorer::FillTreeView(int resType)
{
	tvResTypes->Visible = FALSE;
	tvResTypes->OnChange = NULL;
	tvResTypes->Items->Clear();

    TTreeNode *TreeNode = tvResTypes->Items->Add(NULL, Game.name);
    TreeNode->ImageIndex = 0;
    TreeNode->SelectedIndex = 0;

	TTreeNode *ChildNode;
    for(int i=0;i<TOTAL_RES_TYPES;i++) {
    	if(GAME_USES_RES(i)) {
			ChildNode = tvResTypes->Items->AddChild(TreeNode,AnsiString(resTypes[i].namePl));
			ChildNode->ImageIndex = resTypes[i].iconIndex;
			ChildNode->SelectedIndex = resTypes[i].iconIndex;
        }
    }                                          
    if(SOURCE_FILES_EXIST()) {
    	ChildNode = tvResTypes->Items->AddChild(tvResTypes->Items->Item[rsSCRIPT+1],AnsiString(resTypes[lvHEADER].namePl));
    	ChildNode->ImageIndex = resTypes[lvHEADER].iconIndex;
    	ChildNode->SelectedIndex = resTypes[lvHEADER].iconIndex;
    }

    tvResTypes->FullExpand();
    tvResTypes->Selected = GetResTVItem(resType);
	tvResTypes->Visible = TRUE;
    tvResTypes->OnChange = tvResTypesChange;   

    ChangeSelResType(resType);
}
//---------------------------------------------------------------------------
void __fastcall TWndExplorer::FillListView()
{
	TIniFile *GameINI;
	int resType = ResIdx.selRes;
	TListItem *hItem;
    RESINFO *ri;
    int i;

    if(Game.flags&gfHAS_PROJECT) {
    	GameINI = new TIniFile(INIFileName);
	}

	lvResources->Visible = FALSE;
    lvResources->Items->Clear();
    lvResources->OnChange = NULL;


    if(ResIdx.totalRes[rsPALETTE]) {
    	cbViewPal->OnChange = NULL;
    	cbViewPal->Visible = FALSE;
    	ri = ResIdx.resInfo[rsPALETTE];
        cbViewPal->Items->Clear();
        i=0;
        ssFree(palInfo);
        palInfo = (RESINFO**)ssAlloc(ResIdx.totalRes[rsPALETTE]*sizeof(RESINFO*));
        do {
        	palInfo[i++] = ri;
            aszTemp.sprintf("%s.%05d", resTypes[rsPALETTE].name,ri->number);
			cbViewPal->Items->Add(aszTemp);
       		ri = ri->next;
        } while(ri!=NULL);
    	cbViewPal->Visible = TRUE;
        cbViewPal->ItemIndex = 0;
    	cbViewPal->OnChange = cbViewPalChange;
    } else {
    	cbViewPal->Enabled = FALSE;
    }

    if(ResIdx.totalRes[resType]) {
    	ri = ResIdx.resInfo[resType];
        do {
			hItem = lvResources->Items->Add();
            aszTemp.sprintf("%03d", ri->number);
            if(Game.flags&gfHAS_PROJECT)
				hItem->Caption = GameINI->ReadString(resTypes[ResIdx.selRes].name,"n"+aszTemp,"");
            if(hItem->Caption=="") hItem->Caption = MAKE_DEFAULT_RESLABEL(aszTemp,ResIdx.selRes,ri->number);

            hItem->SubItems->Add(aszTemp.sprintf("%03d", ri->number));
            hItem->SubItems->Add(FloatToStrF(((float)ri->size)/1024.0,ffNumber,7,2)+" KB");
            hItem->SubItems->Add(IntToStr(ri->pack));
            hItem->SubItems->Add("0x"+IntToHex((__int64)ri->offset,7));
            hItem->SubItems->Add(ri->encType?IntToStr(ri->encType):AnsiString("none"));
            hItem->ImageIndex = resType;
       		ri = ri->next;
        } while(ri!=NULL);
		lvResourcesSortColumns(curColumn);
        if(ResIdx.selResItems[resType])
        	ResListViewGotoRes(ResIdx.selResItems[resType]);
        else
        	RESET_SELLV();
    } else {
    	lvResources->Selected = NULL;
    	DoPreview();
    }
    if(Game.flags&gfHAS_PROJECT) {
		delete GameINI;
    }
    lvResources->OnChange = lvResourcesChange;
    lvResources->Visible = TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TWndExplorer::tbAddClick(TObject *Sender)
{
	U8 *rBuf;
    U32 rLen;
    int type;
    U16 number;
    RESINFO *ri;

	OpenDialog->Filter = FilterAllRes;
	if(!OpenDialog->Execute()) return;
                       
    for(int i=OpenDialog->Files->Count-1;i>=0;i--) {
    	if((rBuf=ssLoadFile(ssFIO_ROOT|ssFIO_MESSAGE,OpenDialog->Files->Strings[i].c_str(),&rLen))==NULL) return;
        if((type=CheckSCIFileHeader(rBuf))==-1) {
        	ssMessage(ssERROR,"The file your are trying to add, %s, is not a valid SCI resource, or does not contain a valid header",OpenDialog->Files->Strings[i].c_str());
        	ssFree(rBuf);
   			FillListView();
            return;
        }
        number = (U16)GetFileExtNumber((char*)OpenDialog->Files->Strings[i].c_str());
    	if((ri=(RESINFO *)AddResource((U8*)(rBuf+2), (U16)(rLen-(U16)2), (U8)type, (U16)number, (U8)(Game.defaultPack)))==NULL) {
        	ssFree(rBuf);
   			FillListView();
            return;
        }
        ssFree(rBuf);
    }
    ChangeSelResType(ri->type);
    FillListView();
    ResListViewGotoRes(ri);
}
//---------------------------------------------------------------------------
RESINFO *TWndExplorer::SaveResToGame(U8 *buf, U16 len, U8 type, U16 num)
{
    RESINFO *ri;

    if((ri=AddResource(buf, len, type, num, Game.defaultPack))==NULL)
		return NULL;

    ChangeSelResType(ri->type);
    FillListView();
    ResListViewGotoRes(ri);

    return ri;
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::tbExtractClick(TObject *Sender)
{
	BOOL fERROR = FALSE;
    RESINFO *resInfo;
	if(lvResources->Selected==NULL) return;

	if(lvResources->SelCount==1) {
		ExtractResource(ResListViewGetRes(lvResources->Selected), erFILE, NULL, NULL);
	} else if(lvResources->SelCount>1) {
		TDirDialog *DirDialog = new TDirDialog;
    	DirDialog->Title = "Extract Resources";
    	DirDialog->Caption = "Please select the directory which you would like to extract the selected resources to.";
//    DirDialog->InitialDir = DirDialog->FullPath;
    	if(!DirDialog->Execute()) {
    		delete DirDialog;
        	return;
    	}
        for(int i=0;i<lvResources->Items->Count;i++) {
            if(lvResources->Items->Item[i]->Selected) {
            	resInfo = ResListViewGetRes(lvResources->Items->Item[i]);
             	sprintf(szTemp,"%s\\%s.%03d",DirDialog->FullPath.c_str(),resTypes[resInfo->type].name,resInfo->number);
                if(!ExtractResource(resInfo, erFILENAME, NULL, szTemp))
                	fERROR = TRUE;
            }
        }        
        delete DirDialog;
        if(fERROR)
        	ssMessage(ssERROR,
             	"One or more files were not extracted successfully.\n\n"
                "Make sure the drive is not write protected or full. "
                "Check to see that the game's resource files are not corrupt."
            );
        WRITE_STATUS("File extracting from "+AnsiString(Game.name)+" completed.");
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::ExtractAllScrRes()
{
	BOOL fERROR = FALSE;

    TDirDialog *DirDialog = new TDirDialog;
    DirDialog->Title = "Extract Resources";
    DirDialog->Caption = "Please select the directory which you would like to extract the script related resources to.";
    if(!DirDialog->Execute()) {
    		delete DirDialog;
        	return;
    }
    ExtractAllRes(DirDialog->FullPath.c_str(), rsSCRIPT);
    ExtractAllRes(DirDialog->FullPath.c_str(), rsTEXT);
    ExtractAllRes(DirDialog->FullPath.c_str(), rsVOCAB);
    delete DirDialog;
    if(fERROR)
		ssMessage(ssERROR,
             	"One or more files were not extracted successfully.\n\n"
                "Make sure the drive is not write protected or full. "
                "Check to see that the game's resource files are not corrupt."
		);
    WRITE_STATUS("File extracting from "+AnsiString(Game.name)+" completed.");
}
//---------------------------------------------------------------------------


void __fastcall TWndExplorer::tbEditClick(TObject *Sender)
{
    RESINFO *resInfo;
    U8 *resBuf=NULL;
    U16 resLen;

	lvKEYS_ENABLED = FALSE;

    if(ResIdx.selRes < 0 || ResIdx.selRes >= TOTAL_RES_TYPES2 || ResIdx.selRes==rsMEMORY) return;
    TListItem *item;
    if(ResIdx.selRes==lvHEADER) {
   		item = lvHeaders->Selected;   
		if(!item) return;
  		resBuf = NULL;
    } else {
   		item = lvResources->Selected;
		if(!item) return;
                        
    	resInfo = ResListViewGetRes(item);
    	if((resBuf = ExtractResource(resInfo, erBUFFER, &resLen, NULL))==NULL) return;
    }
    switch(ResIdx.selRes) {
     	case rsVIEW:
    		if(Game.version->viewType==sv_VT_VGA11||Game.version->viewType==sv_VT_VGA32) {
                ssMessage(ssNOTICE,"Sorry, unimplemented.");
    			break;
    		}
        	NewEditWnd(rsVIEW, resInfo, ewEXPLORER_EDITOR, resBuf, Game.version->viewType);
        	break;
     	case rsPIC:
    		if(Game.version->picType==sv_PT_VGA11||Game.version->picType==sv_PT_VGA32) {
                ssMessage(ssNOTICE,"Sorry, unimplemented.");
    			break;
    		}
        	NewEditWnd(rsPIC, resInfo, ewEXPLORER_EDITOR, resBuf, Game.version->picType);
        	break;
     	case rsSCRIPT:   
     	case lvHEADER:
        	if(SOURCE_FILES_EXIST()) {
        		aszTemp = AnsiString(Game.path)+"\\src\\"+item->Caption+AnsiString((AnsiString)(((bool)(lvHEADER==ResIdx.selRes))?AnsiString(".sh"):AnsiString(".sc")));
        		if(!FileExists(aszTemp)) {
                 	ShowMessage("Cannot open file "+aszTemp+" for editing, it does not exist!");
                    break;
                }
                if(config.ewsSEP_SCR_WNDS||scrEdtWnd==NULL) {
            		// Create and show the new editor window
					scrEdtWnd = NewEditWnd(rsSCRIPT, NULL, ewEXPLORER_EDITOR|((ResIdx.selRes==lvHEADER)?ewHEADER:0), NULL, Game.version->scrType);
                }
                if(scrEdtWnd!=NULL) {
                	((TWndScriptEdit*)scrEdtWnd->Wnd)->OpenScript(aszTemp,(ResIdx.selRes==lvHEADER));
        			scrEdtWnd->Wnd->BringToFront();
                }
            } else ssMessage(ssNOTICE,"Sorry, scripts can not be edited, only created. You can create them with the script compiler.");
        	break;
     	case rsTEXT:
        	NewEditWnd(rsTEXT, resInfo, ewEXPLORER_EDITOR, resBuf, 0);
        	break;
     	case rsVOCAB:
        	if(resInfo->number==0&&Game.version->wordsType==sv_WT_00)
        		NewEditWnd(rsVOCAB, resInfo, ewEXPLORER_EDITOR, resBuf, Game.version->wordsType);
            else
            	if(resInfo->number==900&&Game.version->wordsType==sv_WT_10)
        		NewEditWnd(rsVOCAB, resInfo, ewEXPLORER_EDITOR, resBuf, Game.version->wordsType);
            else
            	ssMessage(ssNOTICE, "Sorry, only vocab.000 can be directly edited in SCI0 games, and only vocab.900 can be directly edited in SCI1 (EGA) games. The other vocab files are generated by the script compiler.");
        	break;
     	case rsFONT:    
        	NewEditWnd(rsFONT, resInfo, ewEXPLORER_EDITOR, resBuf, Game.version->fontType);
        	break;
     	case rsCURSOR:  
        	NewEditWnd(rsCURSOR, resInfo, ewEXPLORER_EDITOR, resBuf, Game.version->cursorType);
        	break;
        default:;
    }

    ssFree(resBuf); // not to worry if it wasn't allocated, it's set to NULL at
    				// the start, and my free routine handles that

	lvKEYS_ENABLED = TRUE;
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::tbPropetiesClick(TObject *Sender)
{                   
    if(Game.version->decType!=svDECOMP_0) {
    	ssMessage(ssNOTICE,"Sorry! Unimplemented!");
        return;
    }
	if(!lvResources->Selected) return;
	DlgProperties = new TDlgProperties(this);
	DlgProperties->FillInfo(GET_SELLV_ITEM());
    DlgProperties->ShowModal();
    delete DlgProperties;
}
//---------------------------------------------------------------------------
void __fastcall TWndExplorer::tbRebuildClick(TObject *Sender)
{
	FILE *fMap,*fMapNew,*fPack,*fPackNew;
	U8 *DONE_FLAGS,*buf;
	U8 RES_PACKS[8];
    int oldSize=0,newSize;
    U32 ulMapLen;
    U16 ident,encLen;
    U32 addr,offset;
           
    if(Game.version->decType!=svDECOMP_0) {
    	ssMessage(ssNOTICE,"Sorry! Unimplemented!");
        return;
    }

    int t = ResIdx.selRes;

    // load the map
    if((fMap=ssOpenFile(ssFIO_GAME|ssFIO_MESSAGE,"resource.map","rb"))==0) return;
    ulMapLen = ssFileLen(fMap);

    // make sure the map is valid
    if(ulMapLen < rmMIN_SIZE) {
		ssMessage(ssERROR,"Invalid resource.map file! File too small!");
        ssCloseFile(fMap);
        return;
    }
    if((fMapNew=ssOpenFile(ssFIO_GAME|ssFIO_MESSAGE,"resmap.tmp","wb"))==0) return;
    if((fPackNew=ssOpenFile(ssFIO_GAME|ssFIO_MESSAGE,"respak.tmp","wb"))==0) return;

    if(Sender) {
    	// Initalize the status window
    	DlgResRebuild = new TDlgResRebuild(this);
    	DlgResRebuild->Show();
    	// Setup the progress gauge
    	DlgResRebuild->ProgressGauge->Progress = 0;
    	DlgResRebuild->ProgressGauge->MaxValue = ulMapLen / 6;
    }

    buf = (U8*)ssAlloc(rsMAX_SIZE);
    DONE_FLAGS = (U8*)ssCalloc(TOTAL_RES_TYPES*128);
	memset(RES_PACKS,0,sizeof(RES_PACKS));  

    for(U32 i=0;i<ulMapLen;i+=6) {
    	ident = ssFGetW(fMap);
        addr = ssFGetL(fMap);
        if(ident==0xFFFF&&addr==0xFFFFFFFF) break;
        if(!GetFlag(rmGET_TYPE(ident),rmGET_NUMBER(ident))) {  
        	SetFlag(rmGET_TYPE(ident),rmGET_NUMBER(ident));
          	sprintf(szTemp,"resource.%03d",rmGET_PACKAGE(addr));
    		if((fPack=ssOpenFile(ssFIO_GAME|ssFIO_MESSAGE,szTemp,"rb"))==0) return; 
            if(!GetFlagPack(rmGET_PACKAGE(addr))) {
            	oldSize += ssFileLen(fPack);
            }
        	SetFlagPack(rmGET_PACKAGE(addr));

            ssFSeek(fPack,rmGET_OFFSET(addr),SEEK_SET);
    		ident = ssFGetW(fPack);
    		encLen = ssFGetW(fPack);
            ssFRead(buf,encLen,fPack);
            ssCloseFile(fPack);

            offset = ftell(fPackNew);
            ssFPutW(ident,fPackNew);
            ssFPutW(encLen,fPackNew);
            ssFWrite(buf,encLen,fPackNew);

            ssFPutW(ident,fMapNew);
            addr = rmSET_PACKAGE(1)|rmSET_OFFSET(offset);
            ssFPutL(addr,fMapNew);
        }
        
    	if(Sender) DlgResRebuild->ProgressGauge->Progress++;
    }         
	ssFWrite("\xFF\xFF\xFF\xFF\xFF\xFF",6,fMapNew);
    ssCloseFile(fMap);
    ssCloseFile(fMapNew);
    newSize = (int)ssFTell(fPackNew);
    ssCloseFile(fPackNew);
	ssFree(buf);      
    ssFree(DONE_FLAGS);

    for(int i=0;i<64;i++)
    	if(GetFlagPack(i)) {
          	aszTemp.sprintf("%s\\resource.%03d",Game.path,i);
    		DeleteFile(aszTemp);
        }                                
    DeleteFile(AnsiString(Game.path)+"\\resource.map");
    RenameFile(AnsiString(Game.path)+"\\resmap.tmp",AnsiString(Game.path)+"\\resource.map");
    DeleteFile(AnsiString(Game.path)+"\\resource.001");
    RenameFile(AnsiString(Game.path)+"\\respak.tmp",AnsiString(Game.path)+"\\resource.001");
       
	ReopenGame();
	ChangeSelResType(t);
         
    if(Sender) {
            // Display the Status
            DlgResRebuild->Pie1->FAngles->StartAngle=0;
            DlgResRebuild->Pie1->FAngles->EndAngle=(int)((float)((float)newSize/(float)oldSize)*360);
            DlgResRebuild->Pie2->FAngles->StartAngle=DlgResRebuild->Pie1->FAngles->EndAngle;
            DlgResRebuild->Pie2->FAngles->EndAngle=DlgResRebuild->Pie1->FAngles->StartAngle;
            DlgResRebuild->Pie3->FAngles->StartAngle = DlgResRebuild->Pie1->FAngles->StartAngle;
            DlgResRebuild->Pie3->FAngles->EndAngle = DlgResRebuild->Pie1->FAngles->EndAngle;
            DlgResRebuild->Pie4->FAngles->StartAngle = DlgResRebuild->Pie2->FAngles->StartAngle;
            DlgResRebuild->Pie4->FAngles->EndAngle = DlgResRebuild->Pie2->FAngles->EndAngle;

            float FileSizeKB;
            FileSizeKB = newSize;
            DlgResRebuild->Label2->Caption = FloatToStrF(FileSizeKB,ffNumber,7,0)+" bytes";
            FileSizeKB /= 1024;
            DlgResRebuild->Label3->Caption = FloatToStrF(FileSizeKB,ffNumber,7,2)+" KB";
            oldSize -= newSize;
            FileSizeKB = oldSize;
            DlgResRebuild->Label5->Caption = FloatToStrF(FileSizeKB,ffNumber,7,0)+" bytes";
            FileSizeKB /= 1024;
            DlgResRebuild->Label4->Caption = FloatToStrF(FileSizeKB,ffNumber,7,2)+" KB";

            DlgResRebuild->Status->Caption = "Rebuilding Resources...Done!";

            DlgResRebuild->OKButton->Enabled = true;

            DlgResRebuild->pnlClient->Visible = TRUE;                              
    		DlgResRebuild->Hide();       
        	DlgResRebuild->ProgressGauge->Progress = DlgResRebuild->ProgressGauge->MaxValue;
    		DlgResRebuild->ShowModal();
        	delete DlgResRebuild;
	}
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::tbViewClick(TObject *Sender)
{
	lvResources->ViewStyle = (TViewStyle)((int)((lvResources->ViewStyle+1)%4));
}        
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::ViewStylesClick(TObject *Sender)
{
	lvResources->ViewStyle = vsListView[((TMenuItem*)Sender)->Tag];
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::tvResTypesClick(TObject *Sender)
{
	if(tvResTypes->Selected->Text.AnsiCompare(Game.name) == 0)
		tvResTypes->ReadOnly = FALSE;
    else
		tvResTypes->ReadOnly = TRUE;
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::tvResTypesChange(TObject *Sender,
      TTreeNode *Node)
{
    if(tvResTypes->Selected->Parent==NULL) {
    	ResIdx.selRes = -1;
        	PreviewCaption->Caption = tvResTypes->Items->Item[0]->Text;
            lName->Caption = PreviewCaption->Caption;
    		PreviewPC->ActivePage = PageGameInfo;
    		PanelLV->Visible = FALSE;
            pnlGamePicResize(this);
            return;
    }
    ChangeSelResType(GetResTVType());
}
//---------------------------------------------------------------------------
void __fastcall TWndExplorer::lvResourcesClick(TObject *Sender)
{
    SET_SELLV_ITEM(lvResources->Selected);
}
//---------------------------------------------------------------------------
void __fastcall TWndExplorer::lvHeadersClick(TObject *Sender)
{
    SET_SELLV_ITEM(lvHeaders->Selected);
}
//---------------------------------------------------------------------------
RESINFO *TWndExplorer::ResListViewGetRes(TListItem* Selected)
{
	if(!Selected) return NULL;
	RESINFO *ri = ResIdx.resInfo[ResIdx.selRes];
    U16 number=(U16)StrToInt(Selected->SubItems->Strings[lvcNUMBER]);
    U8  pack=(U8)StrToInt(Selected->SubItems->Strings[lvcPACKAGE]);
    U32 offset=(U32)StrToInt(Selected->SubItems->Strings[lvcOFFSET]);
    while(ri) {
       	if(ri->number == number &&  ri->pack == pack &&  ri->offset == offset) {
         	return ri;
        }
    	ri = ri->next;
    }
    return NULL;
}
//---------------------------------------------------------------------------
// go to, select and set focus on a specified item in the list view
void TWndExplorer::ResListViewGotoItem(TListItem* Item)
{
	if(Item==NULL) {
    	if(lvResources->Items->Count)
        	Item = lvResources->Items->Item[0];
        else
        	return;
    }
    lvResources->OnChange = NULL;

    if(lvResources->Items->Count)
        for(int i=lvResources->Items->Count-1;i>=0;i--)
            lvResources->Items->Item[i]->Selected = FALSE;

    lvResources->Selected = Item;
//    lvResources->SetFocus();
    Item->MakeVisible(FALSE);
    lvResources->OnChange = lvResourcesChange;
    lvResources->ItemFocused = Item;
}
//---------------------------------------------------------------------------
// goto, select and set focus on the specified resource in the list view
TListItem* TWndExplorer::ResListViewGotoRes(RESINFO *ri)
{
    TListItem *Item;
    U8  pack;
    U32 offset;

	if(ri==NULL) return NULL;

    if(ri->type != ResIdx.selRes) {
    	ChangeSelResType(ri->type);
    }

	// set the type in the tree view
    //tvResTypes->SetFocus();
    tvResTypes->Selected = GetResTVItem(ri->type);


    // find the item
    if(Game.flags&gfHAS_PROJECT) {
    	// check the sub item string (res number)  
    	FORMAT_RESNUMSTR(aszTemp,ri->number);
        if(lvResources->Items->Count)
    	    for(int i=lvResources->Items->Count-1;i>=0;i--) {
        	    if(lvResources->Items->Item[i]->SubItems->Strings[0].AnsiCompare(aszTemp)==0) {
            	    Item = lvResources->Items->Item[i];
				    pack=(U8)StrToInt(Item->SubItems->Strings[lvcPACKAGE]);
				    offset=(U32)StrToInt(Item->SubItems->Strings[lvcOFFSET]);
       			    if(ri->pack == pack &&  ri->offset == offset)
         			    break;
                    Item=NULL;
                }
            }
    } else {
    	// simply check the caption
    	MAKE_DEFAULT_RESLABEL(aszTemp,ResIdx.selRes,ri->number);
        Item = NULL;
        do {
    		Item = lvResources->FindCaption(Item?Item->Index+1:0, aszTemp, FALSE, TRUE, FALSE);
            if(Item) {
				pack=(U8)StrToInt(Item->SubItems->Strings[lvcPACKAGE]);
				offset=(U32)StrToInt(Item->SubItems->Strings[lvcOFFSET]);
       			if(ri->pack == pack &&  ri->offset == offset)
         			break;
            }
        } while(Item);
    }
    if(Item == NULL) return NULL;

    SET_SELLV_ITEM(Item);
    ResListViewGotoItem(Item);

    return Item;
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::lvResourcesChange(TObject *Sender,
      TListItem *Item, TItemChange Change)
{
	if(!Tag) return;
	DoPreview();
}
//---------------------------------------------------------------------------
int __stdcall SubItemSort(long Item1, long Item2, long ParamSort)
{
    __int64 Value1 = StrToInt(((TListItem *)Item1)->SubItems->Strings[curColumn]);
    __int64 Value2 = StrToInt(((TListItem *)Item2)->SubItems->Strings[curColumn]);

    if(Value1 > Value2) return 1;
    if(Value1 < Value2) return -1;

    return 0;
}
//---------------------------------------------------------------------------
int __stdcall SubItemSort_Size(long Item1, long Item2, long ParamSort)
{
	return CompareText(((TListItem *)Item1)->SubItems->Strings[lvcSIZE],((TListItem *)Item2)->SubItems->Strings[lvcSIZE]);
}
//---------------------------------------------------------------------------
#define SUBITEMENCODESORT(i) \
	(__int64)( ((bool)(((TListItem *)i)->SubItems->Strings[lvcENCODE]=="none")) ?0:StrToInt(((TListItem *)i)->SubItems->Strings[lvcENCODE]));
int __stdcall SubItemSort_Encode(long Item1, long Item2, long ParamSort)
{
    __int64 Value1 = SUBITEMENCODESORT(Item1);
    __int64 Value2 = SUBITEMENCODESORT(Item2);

    if(Value1 > Value2) return 1;
    if(Value1 < Value2) return -1;

    return 0;
}
//---------------------------------------------------------------------------
int __stdcall ItemSort(long Item1, long Item2, long ParamSort)
{
	return CompareText(((TListItem *)Item1)->Caption,((TListItem *)Item2)->Caption);
}
//---------------------------------------------------------------------------
void __fastcall TWndExplorer::lvResourcesSortColumns(int Index)
{
    // Sort the list items accordingly
    curColumn = Index;
    if(curColumn==lvcNAME) {    
        lvResources->CustomSort(ItemSort, 0);
    } else {
        switch(curColumn) {
        	case lvcSIZE:
        		lvResources->CustomSort(SubItemSort_Size, 0);
            	break;
        	case lvcENCODE:
        		lvResources->CustomSort(SubItemSort_Encode, 0);
            	break;
            default:
        		lvResources->CustomSort(SubItemSort, 0);
        }
    }           
}
//---------------------------------------------------------------------------
void __fastcall TWndExplorer::lvResourcesColumnClick(TObject *Sender,
      TListColumn *Column)
{
	lvResourcesSortColumns(Column->Index-1);
}                          
//---------------------------------------------------------------------------
TTreeNode *TWndExplorer::GetResTVItem(int resType)
{
    if(!tvResTypes->Items->Count) return NULL;
	for(int i=tvResTypes->Items->Count-1;i>0;i--) {
     	if(tvResTypes->Items->Item[i]->Text == AnsiString(resTypes[resType].namePl))
        	return tvResTypes->Items->Item[i];
    }
    return tvResTypes->Items->Item[0];
}
//---------------------------------------------------------------------------
int TWndExplorer::GetResTVType()
{
	if(tvResTypes->Selected)
		for(int i=0;i<TOTAL_RES_TYPES2;i++) {
     		if(tvResTypes->Selected->Text == AnsiString(resTypes[i].namePl))
     		   	return i;
    	}
    return -1;
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::tvResTypesEdited(TObject *Sender,
      TTreeNode *Node, AnsiString &S)
{
	tvResTypes->ReadOnly = TRUE;

    // UPDATE INI
    MakeConfig();
    TIniFile *GameINI = new TIniFile(INIFileName);
    strcpy(Game.name,S.c_str());
    GameINI->WriteString("Game","Name",S);
    delete GameINI;

    PreviewCaption->Caption = S;
    lName->Caption = PreviewCaption->Caption;
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::lvResourcesEdited(TObject *Sender,
      TListItem *Item, AnsiString &S)
{                    
	MakeConfig();

    TIniFile *GameINI = new TIniFile(INIFileName);
    GameINI->WriteString(resTypes[ResIdx.selRes].name,"n"+Item->SubItems->Strings[0],S);
    delete GameINI;
    	                           
    lvKEYS_ENABLED = TRUE;
}
//---------------------------------------------------------------------------


void __fastcall TWndExplorer::tbDeleteClick(TObject *Sender)
{
	BOOL fERROR = FALSE;
    RESINFO *resInfo;
	if(lvResources->Selected==NULL) return;
    AnsiString elCaption = "";
    TListItem *li=NULL;
    int t = ResIdx.selRes;

	if(lvResources->SelCount==1) {
    	if((ssMessage(ssYESNO,"Are you sure you want to delete the file %s?",lvResources->Selected->Caption.c_str()))==IDNO) return;
    	li = lvResources->GetNextItem(lvResources->Selected, sdBelow, TItemStates() << isNone);
        if(!li)
        	li = lvResources->GetNextItem(lvResources->Selected, sdAbove, TItemStates() << isNone);
        if(li)
        	elCaption = li->Caption;
		fERROR = !DelMapEntry(ResListViewGetRes(lvResources->Selected));
	} else if(lvResources->SelCount>1) {
    	if((ssMessage(ssYESNO,"Are you sure you want to delete the selected %d items?",lvResources->SelCount))==IDNO) return;
        for(int i=0;i<lvResources->Items->Count;i++) {
            if(lvResources->Items->Item[i]->Selected) {
            	resInfo = ResListViewGetRes(lvResources->Items->Item[i]);
             	if(!DelMapEntry(resInfo))
                	fERROR = TRUE;
            }
        }        
    }
    if(fERROR)
        	ssMessage(ssERROR,
             	"One or more files were not delete successfully.\n\n"
                "Make sure the drive is not write protected or full. "
                "Check to see that the game's resource files are not corrupt."
    );
    WRITE_STATUS("File deleting from "+AnsiString(Game.name)+" completed.");

	ReopenGame();
    if(li&&lvResources->Items->Count) {
    	ChangeSelResType(t);
        li = lvResources->FindCaption(0, elCaption, FALSE, TRUE, FALSE);
        if(li)
    		ResListViewGotoItem(li);
    }
}
//---------------------------------------------------------------------------


void __fastcall TWndExplorer::btnPicScreenClick(TObject *Sender)
{
	if(!pvPic) return;
	activeScreen = (U8)((TSpeedButton*)Sender)->Tag;
    ((TSpeedButton*)Sender)->Down = TRUE;
    if(Game.version->picType!=sv_PT_VGA32&&Game.version->picType!=sv_PT_VGA11) {
    	DrawPic(FALSE, activePalette, pvPic,Game.version->picType); /*
        U8 *a=pvPic->bitmaps[activeScreen],*b=pvPic->bitmaps[0];
        for(int y=0;y<sPIC_HEIGHT;y++) {
        	for(int x=0;x<sPIC_WIDTH;x++) {
            	if((!*a) )
                	*a = *b;
                b++;
                a++;
        	}
        }       */
		DrawPicImage(imgPic,pvPic,pvPic->bitmaps[activeScreen],(pvPic->palVGA&&activeScreen==asVISUAL)?&(pvPic->palVGA->pal):&palEGA);
    } else
		DrawPicImage(imgPic,pvPic,pvPic->data,&(pvPic->palVGA->pal));

 	PicScrollBoxResize(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::scrFontResize(TObject *Sender)
{
	if(!Tag) return;
    scrFont->OnResize = scrFontResize;
    if(PreviewPC->ActivePage==FontPage)
    	if(pvFont) {
    		imgFont->Width = (scrFont->Width-20);
    		if(imgFont->Width<1) imgFont->Width = 16;
        	FontDrawImage(imgFont,pvFont);
        }
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::SwitchLoop_UpDnClick(TObject *Sender,
      TUDBtnType Button)
{
	if(!pvView) return;
	if( ((TUpDown*)Sender)->Tag ) {// loop up down
		ViewSetCelUpDown(ViewGetLoop(pvView,SwitchLoop_UpDn->Position),SwitchCel_UpDn);
    }
    LoopStats->Caption = IntToStr(SwitchLoop_UpDn->Position)+"/"+IntToStr(SwitchLoop_UpDn->Max);
    CelStats->Caption  = IntToStr(SwitchCel_UpDn->Position)+"/"+IntToStr(SwitchCel_UpDn->Max);
    pvLoop = ViewGetLoop(pvView,SwitchLoop_UpDn->Position);
    pvLoopReal = GetRealLoop(pvLoop);
    pvCel = ViewLoopGetCel(pvLoopReal,SwitchCel_UpDn->Position);
    CelWidth->Text = IntToStr(pvCel->width);
    CelHeight->Text = IntToStr(pvCel->height);
    Mirroring->Text = sCEL_ISMIRROR(pvLoop,pvCel)?AnsiString("Loop "+IntToStr(pvLoopReal->loop)):AnsiString("No Other Loop");

    TransColour->Brush->Color =
    	(viewPal)?
			viewPal->pal.cols[pvCel->transCol]:
            palEGA.cols[pvCel->transCol];

    sciVIEWCEL *offCel = pvCel;

	ViewDrawCelImage(imgView,pvView,viewPal?&viewPal->pal:&palEGA,SwitchLoop_UpDn->Position,SwitchCel_UpDn->Position,Game.version->num==svSCI_32?1:2);

	imgView->Left	= ((scbView->Width-imgView->Width)>>1);
    imgView->Top	= ((scbView->Height-imgView->Height)>>1);
    shpView->Left	= imgView->Left-1;
    shpView->Top	= imgView->Top-1;
    shpView->Width	= imgView->Width+2;
    shpView->Height	= imgView->Height+2;
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::btnAnimateViewClick(TObject *Sender)
{
	ANIVIEW = !ANIVIEW;
    btnAnimateView->Down = ANIVIEW;
    tmrView->Enabled = ANIVIEW;
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::tmrViewTimer(TObject *Sender)
{
	if(btnAnimateView->Down) {
		if(!ANIVIEW||PreviewPC->ActivePage!=ViewPage) return;
		SwitchLoop_UpDnClick(SwitchCel_UpDn,(TUDBtnType)NULL);
    	if(SwitchCel_UpDn->Position>=SwitchCel_UpDn->Max)
    		SwitchCel_UpDn->Position = 0;
    	else
			SwitchCel_UpDn->Position++;
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::scbViewResize(TObject *Sender)
{             
	if(!Tag) return;
    scbView->OnResize = scbViewResize;
	if(pvView)
		SwitchLoop_UpDnClick(SwitchCel_UpDn,(TUDBtnType)NULL);
}
//---------------------------------------------------------------------------
void __fastcall TWndExplorer::PicScrollBoxResize(TObject *Sender)
{
	if(!Tag) return;  
    PicScrollBox->OnResize = PicScrollBoxResize;

    imgPic->Left	= ((PicScrollBox->Width-imgPic->Width)>>1);
    //imgPic->Top		= ((PicScrollBox->Height-imgPic->Height)>>1);
    imPPal->Left	= ((PicScrollBox->Width-imPPal->Width)>>1);
    pnPicCtl->Left	= ((PicScrollBox->Width-pnPicCtl->Width)>>1);
    shpPic->Left	= imgPic->Left-1;
    shpPic->Top		= imgPic->Top-1;
    shpPic->Width	= imgPic->Width+2;
    shpPic->Height	= imgPic->Height+2;
}
//---------------------------------------------------------------------------
void __fastcall TWndExplorer::CursorPageResize(TObject *Sender)
{
	if(!Tag) return;
    CursorPage->OnResize = CursorPageResize;
	CENTER_IT(pnlCursor,CursorPage);
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::btnAnimatePicClick(TObject *Sender)
{
    tmrPic->Enabled = btnAnimatePic->Down;
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::tmrPicTimer(TObject *Sender)
{
	if(btnAnimatePic->Down) {
		if(VisualButton->Down)
        	btnPicScreenClick(PriorityButton);
        else if(PriorityButton->Down)
        	btnPicScreenClick(ControlButton);
        else if(ControlButton->Down)
        	btnPicScreenClick(VisualButton);
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::lvResourcesDblClick(TObject *Sender)
{
	tbEditClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::pnlGamePicResize(TObject *Sender)
{
	if(!Tag) return;
    pnlGamePic->OnResize = pnlGamePicResize;
	imgGamePic->Left  = (pnlGamePic->Width-imgGamePic->Width)/2;
    shpGamePic->Left  = imgGamePic->Left-1;
    shpGamePic->Width = imgGamePic->Width+2;
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::BtnCloseResTVClick(TObject *Sender)
{
    WndMain->ManagerBar1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::SpeedButton2Click(TObject *Sender)
{
    WndMain->PreviewBar1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::SpeedButton1Click(TObject *Sender)
{
    WndMain->ResourceCaption1Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TWndExplorer::tbPal0Click(TObject *Sender)
{
	((TToolButton*)Sender)->Down = TRUE;
	activePalette = (U8)((TToolButton*)Sender)->Tag;
    if(Game.version->picType!=sv_PT_VGA32&&Game.version->picType!=sv_PT_VGA11) {
    	DrawPic(FALSE, activePalette, pvPic,Game.version->picType);
		DrawPicImage(imgPic,pvPic,pvPic->bitmaps[activeScreen],(pvPic->palVGA&&activeScreen==asVISUAL)?&(pvPic->palVGA->pal):&palEGA);
    } else
	;//	DrawPicImage(imgPic,pvPic,pvPic->data);

 	PicScrollBoxResize(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::CopyFile(AnsiString from, AnsiString to)
{
	FILE *f,*t;
    if((f=ssOpenFile(ssFIO_ROOT,from.c_str(),"rb"))==NULL) return;
    if((t=ssOpenFile(ssFIO_ROOT,to.c_str(),"wb"))==NULL) {
    	ssCloseFile(f);
		return;
    }

    long len = ssFileLen(f);
    while(len) {
    	ssFPutB(ssFGetB(f),t);
        len--;
    }

    ssCloseFile(f);
    ssCloseFile(t);
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::imgGameIconClick(TObject *Sender)
{
	OpenPictureDialog->Filter = "Icons (*.ico)|*.ico";
    if(!OpenPictureDialog->Execute()) return;

    AnsiString ss=(AnsiString(Game.path)+"\\game.ico");
    if(FileExists(ss)) {
     	DeleteFile(ss);
    }
    CopyFile(OpenPictureDialog->FileName,ss);

    imgGameIcon->Picture->Icon->LoadFromFile(ss);
    WndMain->ilTreeView->Delete(0);
    WndMain->ilTreeView->InsertIcon(0, imgGameIcon->Picture->Icon);
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::imgGamePicClick(TObject *Sender)
{
	OpenPictureDialog->Filter = "Bitmaps (*.bmp)|*.bmp";  
    if(!OpenPictureDialog->Execute()) return;

    AnsiString ss=(AnsiString(Game.path)+"\\game.bmp");
    if(FileExists(ss)) {
     	DeleteFile(ss);
    }
    CopyFile(OpenPictureDialog->FileName,ss);
    imgGamePic->Picture->Bitmap->LoadFromFile(ss);
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::mmoGameNotesChange(TObject *Sender)
{
	SAVE_GAME_NOTES=TRUE;
}
//---------------------------------------------------------------------------


void __fastcall TWndExplorer::Label20Click(TObject *Sender)
{
    ShellExecute(Handle, 0, "http://www4.ncsu.edu/~rniyenga/sci/soundbox.html", 0, 0, SW_NORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::Button1Click(TObject *Sender)
{
	WndMain->SoundBox1Click(this);
    if(!lvResources->Selected) return;
	RESINFO *resInfo = ResListViewGetRes(lvResources->Selected);
	sprintf(szTemp,"%s\\temp\\%s.%03d",Program.path,resTypes[resInfo->type].name,resInfo->number);
	if(ExtractResource(resInfo, erFILENAME, NULL, szTemp))
    	WRITE_STATUS(AnsiString(szTemp)+" successfully extracted.");
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::PalPrevPageResize(TObject *Sender)
{          
	if(!Tag||!pvPal) return;
    PalPrevPage->OnResize = PalPrevPageResize;
	DrawPaletteAsBitmap(imPalPrev->Picture->Bitmap,pvPal,16,16,imPalPrev->Width,imPalPrev->Height,clWindow);
}
//---------------------------------------------------------------------------


void __fastcall TWndExplorer::cbViewPalChange(TObject *Sender)
{
	DoPreview();
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::btnToBmpClick(TObject *Sender)
{
	TDlgExpCels *d = new TDlgExpCels(this,pvView,pvLoop->loop);
    d->ShowModal();
    delete d;
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::SpeedButton3Click(TObject *Sender)
{
	SaveDialog->Filter =
    	// All Resources|VIEW.*;PIC.*;SCRIPT.*;TEXT.*;SOUND.*;MEMORY.*;VOCAB.*;FONT.*;CURSOR.*;PATCH.*|View Resource (view.*)|VIEW.*|Pic Resource (pic.*)|PIC.*|Script Resource (script.*)|SCRIPT.*|Text Resource (text.*)|TEXT.*|Sound Resource (sound.*)|SOUND.*|Vocab R
        "Windows Bitmap (*.BMP)|*.bmp";
    SaveDialog->DefaultExt = "bmp";
	if(!SaveDialog->Execute()) return;

    Graphics::TBitmap *b;

    if(Game.version->picType!=sv_PT_VGA32&&Game.version->picType!=sv_PT_VGA11) {
		b = DrawPicBitmap(pvPic,pvPic->bitmaps[activeScreen],(pvPic->palVGA&&activeScreen==asVISUAL)?&(pvPic->palVGA->pal):&palEGA);
    } else
		b = DrawPicBitmap(pvPic,pvPic->data,&(pvPic->palVGA->pal));

    b->SaveToFile(SaveDialog->FileName);
    DeletePaledBitmap(b);
}
//---------------------------------------------------------------------------

void __fastcall TWndExplorer::lvResourcesKeyPress(TObject *Sender,
      char &Key)
{
	if(!lvKEYS_ENABLED) return;

    	switch(Key) {
        	case VK_RETURN:
    			tbEditClick(Sender);
                break;
        	case VK_DELETE:
				tbDeleteClick(Sender);
                break;
        }	
}
//---------------------------------------------------------------------------

