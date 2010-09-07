//---------------------------------------------------------------------------
// SCI Studio 3.0
// http://scistudio.sourceforge.net/
//---------------------------------------------------------------------------

#include <vcl.h>     
#include <WinInet.h>
#include <FileCtrl.hpp> 
#include <htmlhelp.h>

#pragma hdrstop
                  
#include "scihdr.h"
#include "main.h"
#include "explorer.h"
#include "about.h"
#include "textedit.h"
#include "gfxedits.h"
#include "settings.h"
#include "viewedit.h"
#include "scriptedit.h"
#include "splash.h"
#include "checkversion.h"
#include "newgame.h"
#include "welcome.h"
//---------------------------------------------------------------------------
ssPGM Program = {
 	PROGRAM_NAME,
 	PROGRAM_TITLE,
    PROGRAM_VERSION,
    PROGRAM_BUILDDATE,
 	"",
	""
};
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGAUGES"
#pragma resource "*.dfm"
TWndMain *WndMain;
TWndScriptEdit *TheScriptWindow;

#define SOUNDBOXPATH (AnsiString(Program.path)+"\\plugins\\soundbox.exe")
//---------------------------------------------------------------------------
__fastcall TWndMain::TWndMain(TComponent* Owner)
	: TForm(Owner)
{
    AnsiString ProgramDir=GetCurrentDir();
    if(!FileExists(ProgramDir+"\\scistudio.exe"))
    	ProgramDir=AnsiString(GetProgramPath());
    strcpy(Program.path,ProgramDir.c_str());

    WndExplorer = NULL;
	DirDialog = new TDirDialog;
                       
    TBHeight_Nml = 47;
    TBHeight_Txt = 23;
    TBHeight_Ntx = 35;

    LoadConfig();

    if(config.SHOW_WELCOME) {
		DlgWelcome = new TDlgWelcome(this);
		DlgWelcome->ShowModal();
    	delete DlgWelcome;
    }
    if(config.SHOW_SPLASH) {
		DlgSplash = new TDlgSplash(this);
		DlgSplash->Show();
    	tmrSplash->Enabled = TRUE;
    }
    Caption = AnsiString(Program.title);

    if(FileExists(SOUNDBOXPATH)) {
     	SoundBox1->Visible = TRUE;
     	SB_Sound->Visible = TRUE;
    }

    Game.version = &versions[svSCI_00_LATE]; // until I fully impement the rest

    InitResInfo(FALSE);

    UpdateMenuBar();

	if(DirectoryExists(ProgramDir+"\\samples")) {
    	LoadSampleDir((ProgramDir+"\\samples\\cursors").c_str(), Cursor1, "*.bin");
    	LoadSampleDir((ProgramDir+"\\samples\\fonts").c_str(), Font1, "*.bin");
    	LoadSampleDir((ProgramDir+"\\samples\\pics").c_str(), Pic1, "*.bin");
    	LoadSampleDir((ProgramDir+"\\samples\\views").c_str(), View2, "*.bin");
    } else AddSample1->Enabled = FALSE;

    SetCurrentDir(ProgramDir);

    SetupLogPal(&palEGA);
    SetupLogPal(&palFont);
    SetupLogPal(&palCursor);
    SetupLogPal(&palCursorVGA);

    InitEditWnds();
}
//---------------------------------------------------------------------------
void __fastcall TWndMain::NewGame1Click(TObject *Sender)
{
	TDlgNewGame *dng = new TDlgNewGame(this);
	dng->ShowModal();

    delete dng;
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::ExploreGame(AnsiString path,AnsiString name)
{
    // If any windows are open, close them
    CloseGame1Click(this);
    if(TaskBarPanel->Visible) return;

	FixPath(path.c_str());
    strcpy(Game.path, path.c_str());
	strcpy(Game.name,name.c_str());
    if(!LoadGame(Game.path)) {
    	CloseGame1Click(this);
        return;
    }
    NewEditWnd(wnEXPLORER, NULL, NULL, NULL, 0);
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::OpenGame1Click(TObject *Sender)
{                       
    // Get the directory which the game is located
    DirDialog->Title = "Open Game";
    DirDialog->Caption = "Please select the directory which the game you wish to open is located in.";
    DirDialog->MAP_CHECK = TRUE;
    if(!DirDialog->Execute()) {
        return;
    }
	DirDialog->InitialDir = DirDialog->FullPath;
    ExploreGame(DirDialog->FullPath,"");
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::CloseGame1Click(TObject *Sender)
{
	int oldCount;
	EDTWND *edtWnd = edtWndFirst,*edtNext;
    if(WndExplorer) {
    	WndExplorer->edTag.edtWnd->flags|=ewCLOSING_EXPLORER;
        if(edtWnd!=NULL) {
        	while(edtWnd) {
                edtNext = edtWnd->next;
                if(edtWnd->Wnd != WndExplorer) {
        			oldCount = totalEdtWnds;
       				edtWnd->Wnd->Close();
            		if(oldCount==totalEdtWnds) return;
                }
        		edtWnd = edtNext;
        	}
            // WndExplorer should equal edtWndFirst
			if(totalEdtWnds>1||edtWndFirst->Wnd != WndExplorer) {
             	//HTF would this happen? dunno, but good to be clean
                return;
            }
      		((TWndExplorer*)edtWndFirst->Wnd)->Close();
        	WndExplorer = NULL;
        }
    } else {
        while(edtWnd) {
        	oldCount = totalEdtWnds;  
			edtNext = edtWnd->next;
       		edtWnd->Wnd->Close();
            if(oldCount==totalEdtWnds) return;
        	edtWnd = edtNext;
        }
    }
    DisposeEditWnds();
    FreeGame();

    // Disable buttons which cannot be used when the game is closed
    SB_CloseGame->Enabled 	= FALSE;
    SB_RunGame->Enabled 	= FALSE;
    Run1->Enabled	 		= FALSE;
    Close1->Enabled 		= FALSE;
    Resource1->Visible 		= FALSE;
    ManagerBar1->Visible 	= FALSE;
    PreviewBar1->Visible 	= FALSE;

    // Reset the form caption to normal
    Caption = AnsiString(Program.title);

    Game.version = &versions[svSCI_00_LATE];	// until I fully impement the rest
												// of formats for the stand alone editors

    WRITE_STATUS("Game Closed.");
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::RunGame1Click(TObject *Sender)
{
    DoGameExecution(AnsiString(Game.path));
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::Settings1Click(TObject *Sender)
{
    // Create the settings dialog
    DlgSettings = new TDlgSettings(this);
    // Show it
    DlgSettings->ShowModal();

    delete DlgSettings;
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::Exit1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TWndMain::About1Click(TObject *Sender)
{
    // Create the about dialog
    DlgAbout = new TDlgAbout(this);

    // Show it
    DlgAbout->ShowModal();
    delete DlgAbout;
}
//---------------------------------------------------------------------------
void TWndMain::AddToTaskbar(EDTWND *edtWnd)
{
	TTabSheet *sheet;
    TaskBar->Enabled = FALSE;
    sheet = new TTabSheet(TaskBar);
    sheet->Parent = TaskBar;
    sheet->PageControl = TaskBar;
   	sheet->Tag = (int)edtWnd;
    sheet->ImageIndex = edtWnd->resType->iconIndex;
    sheet->Caption = edtWnd->Wnd->Caption;
    sheet->TabVisible = true;
                  
    TaskBar->ActivePage = sheet;
    edtWnd->taskTab = sheet;
    TaskBar->Enabled = TRUE;

    ToggleVisibleTaskBar();
    edtWnd->Wnd->OnActivate = UpdateTaskBar;

}
//---------------------------------------------------------------------------
void TWndMain::DeleteFromTaskbar(EDTWND *edtWnd)
{
	if(!TaskBar->PageCount) return;
    edtWnd->Wnd->OnActivate = NULL;
	TaskBar->Enabled=FALSE;
  	TaskBar->OnChange=NULL;
    edtWnd->taskTab->PageControl = NULL;
	delete edtWnd->taskTab;
    ToggleVisibleTaskBar();
	TaskBar->OnChange=TaskBarChange;
	TaskBar->Enabled=TRUE;
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::TaskBarChange(TObject *Sender)
{
    if(TaskBar->ActivePage==NULL) return;
    // Show The Correct Form when tab selected
    TForm *f=((EDTWND*)(TaskBar->ActivePage->Tag))->Wnd;
    if(!f) return;
    if(f->WindowState == wsMinimized)
        f->WindowState = ActiveMDIChild->WindowState!=wsMinimized?ActiveMDIChild->WindowState:wsNormal;
    f->BringToFront();
}
//---------------------------------------------------------------------------
void __fastcall TWndMain::UpdateTaskBar(System::TObject *Sender)
{
	if(!Sender||!((TForm*)Sender)->Tag||!((TForm*)Sender)->Enabled||
		ActiveMDIChild==NULL||!ActiveMDIChild->Tag) return;
    // Show The Correct Form when tab selected
    TaskBar->ActivePage = ((EDITORTAG*)ActiveMDIChild->Tag)->edtWnd->taskTab;
    UpdateTaskBarCaption(((EDITORTAG*)ActiveMDIChild->Tag)->edtWnd->taskTab);
}
//---------------------------------------------------------------------------
void __fastcall TWndMain::ToggleVisibleTaskBar()
{
    // If there are no items on the taskbar...
    if(!TaskBar->PageCount) {
        // Hide the empty bar
        TaskBarPanel->Visible = false;
    } else
        if(!TaskBarPanel->Visible) { // Show the taskbar
            TaskBarPanel->Visible = true;
            StatusBar->Top = ClientHeight;
            TaskBarPanel->Top = StatusBar->Top-TaskBarPanel->Height;
        }
}
//---------------------------------------------------------------------------
// UpdateTaskBarCaption
void __fastcall TWndMain::UpdateTaskBarCaption(TTabSheet *taskTab)
{
    if(taskTab) taskTab->Caption = ((EDTWND*)(taskTab->Tag))->Wnd->Caption;
}
//---------------------------------------------------------------------------


void __fastcall TWndMain::SB_EditorClick(TObject *Sender)
{
	NewEditWnd(((TForm*)Sender)->Tag, NULL, ewSTAND_ALONE, NULL, 1);
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::ToolBar3Click(TObject *Sender)
{
    // Toggle showing/hiding the main toolbar

    // If it is visible, hide it
    if(MainPanel->Visible) {
    	MainPanel->Visible	= FALSE;
    	ToolBar3->Checked	= FALSE;
    } else {
    // Otherwise, show it
        MainPanel->Visible	= TRUE;
        ToolBar3->Checked	= TRUE;
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::TextLabels1Click(TObject *Sender)
{
    if(TextLabels1->Checked) {
        pnlToolBar->ShowCaptions				= FALSE;
        pnlToolBar->ButtonHeight				= 30;
        pnlToolBar->ButtonWidth				= 30;
        MainPanel2->Bands->Items[0]->MinHeight	= TBHeight_Ntx;
        MainPanel->Constraints->MinHeight		= TBHeight_Ntx;
        MainPanel->Constraints->MaxHeight		= TBHeight_Ntx;

        TextLabels1->Checked					= FALSE;
        if(!TextLabels1->Checked && !Images1->Checked) {
            Images1Click(this);
            TextLabels1->Checked 				= TRUE;
            TextLabels1Click(this);
        }
    } else {
        pnlToolBar->ShowCaptions 				= TRUE;
        pnlToolBar->ButtonHeight 				= 42;
        pnlToolBar->ButtonWidth 				= 36;
        MainPanel2->Bands->Items[0]->MinHeight 	= TBHeight_Nml;
        MainPanel->Constraints->MinHeight 		= TBHeight_Nml;
        MainPanel->Constraints->MaxHeight 		= TBHeight_Nml;

        TextLabels1->Checked 					= TRUE;
    }
    if(WndExplorer) WndExplorer->UpdateExplorerBar(TextLabels1->Checked);
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::Images1Click(TObject *Sender)
{
    if(Images1->Checked) {
        pnlToolBar->DisabledImages = NULL;
        pnlToolBar->HotImages = NULL;
        pnlToolBar->Images = NULL;
        pnlToolBar->ButtonHeight = 19;
        pnlToolBar->ButtonWidth = 30;
        MainPanel2->Bands->Items[0]->MinHeight = TBHeight_Txt;
        MainPanel->Constraints->MinHeight = TBHeight_Txt;
        MainPanel->Constraints->MaxHeight = TBHeight_Txt;

        Images1->Checked = FALSE;
        if(!TextLabels1->Checked && !Images1->Checked) {
            TextLabels1Click(this);
            Images1->Checked = TRUE;
            Images1Click(this);
        }
    } else {
        pnlToolBar->HotImages = (AlwaysColour1->Checked)?ilMainToolbarB:ilMainToolbarA;
        pnlToolBar->Images = (AlwaysColour1->Checked)?ilMainToolbarA:ilMainToolbarD;
        pnlToolBar->ButtonHeight = 42;
        pnlToolBar->ButtonWidth = 36;           
        MainPanel2->Bands->Items[0]->MinHeight = TBHeight_Nml;
        MainPanel->Constraints->MinHeight = TBHeight_Nml;
        MainPanel->Constraints->MaxHeight = TBHeight_Nml;

        Images1->Checked = TRUE;
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::AlwaysColour1Click(TObject *Sender)
{
    // Query to show the main tool bar buttons always in colour
    if(!Images1->Checked) Images1Click(this);

    // If the button glyphs are colour, then set them to grey scale
    if(AlwaysColour1->Checked) {
        pnlToolBar->Images = ilMainToolbarD;
        pnlToolBar->HotImages = ilMainToolbarA;
        AlwaysColour1->Checked = FALSE;
    } else {
    // Otherwise, set them to colour    
        pnlToolBar->Images = ilMainToolbarA;
        pnlToolBar->HotImages = ilMainToolbarB;
        AlwaysColour1->Checked = TRUE;
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::More1Click(TObject *Sender)
{
    // Create the settings dialog
    DlgSettings = new TDlgSettings(this);

    // Show it
    DlgSettings->PageControl1->ActivePage = DlgSettings->Desktop;
    DlgSettings->ShowModal();
    delete DlgSettings;
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::ManagerBar1Click(TObject *Sender)
{
    ManagerBar1->Checked = !ManagerBar1->Checked;
    WndExplorer->pnResTypes->Visible = ManagerBar1->Checked;
    WndExplorer->spResTypes->Visible = ManagerBar1->Checked;
    WndExplorer->pnResTypes->Left = 0;
    WndExplorer->spResTypes->Left = WndExplorer->pnResTypes->Width;
    WndExplorer->pnPreview->Left = WndExplorer->spResTypes->Left+WndExplorer->pnResTypes->Width;
    WndExplorer->spPreview->Left = WndExplorer->pnPreview->Left+WndExplorer->pnPreview->Width;
    config.ewsManagerBarV = ManagerBar1->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::PreviewBar1Click(TObject *Sender)
{
    PreviewBar1->Checked = !PreviewBar1->Checked;
    WndExplorer->pnPreview->Visible = PreviewBar1->Checked;
    WndExplorer->spPreview->Visible = PreviewBar1->Checked;
    WndExplorer->pnResTypes->Left = 0;
    WndExplorer->spResTypes->Left = WndExplorer->pnResTypes->Width;  
    if(PreviewBar1->Checked) {
    	WndExplorer->PanelLV->Align = alLeft;
    	WndExplorer->PanelLV->Width = 340;
    } else
    	WndExplorer->PanelLV->Align = alClient;
    WndExplorer->pnPreview->Left = WndExplorer->spPreview->Left+WndExplorer->spPreview->Width;
    WndExplorer->spPreview->Left = WndExplorer->pnPreview->Left+WndExplorer->pnPreview->Width;
    config.ewsSHOW_PREVIEW = PreviewBar1->Checked;
}       
//---------------------------------------------------------------------------

void __fastcall TWndMain::ResourceCaption1Click(TObject *Sender)
{
    ResourceCaption1->Checked = !ResourceCaption1->Checked;
    WndExplorer->pnResCap->Visible = ResourceCaption1->Checked;
    config.ewsSHOW_RESCAP = ResourceCaption1->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::StatusBar2Click(TObject *Sender)
{
	StatusBar2->Checked = !StatusBar2->Checked;
	StatusBar->Visible  = StatusBar2->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::FullScreen1Click(TObject *Sender)
{
	bool OldVis = Visible;
    Visible = FALSE;
	if(!FullScreen1->Checked) {
        OldX = Left;
        OldY = Top;
        OldWS = WindowState;
        OldH = Height;
        OldW = Width;
    	WindowState = wsNormal;
        FullScreen1->Checked = TRUE;
        StatusBar->SizeGrip = FALSE;

    	TBHeight_Nml = 45;
    	TBHeight_Txt = 21;
    	TBHeight_Ntx = 33;
    	Bevel1->Visible = FALSE;

		MainPanel->Constraints->MinHeight -= 2;
		MainPanel->Constraints->MaxHeight -= 2;
		MainPanel->Height -= 2;

        long l=GetWindowLong(Handle,GWL_STYLE);
        SetWindowLong(Handle, GWL_STYLE, l & (~(WS_CAPTION|WS_THICKFRAME)) );
        int sx=0/*GetSystemMetrics(SM_CXFRAME)*/,sy=0/*GetSystemMetrics(SM_CXFRAME)*/;
        Left =-sx;
        Top = -sy;
        Width = Screen->Width+(sx*2);
        Height = Screen->Height+(sy*2);
    } else {
    	BorderStyle = bsSizeable;
    	Left = OldX;
    	Top = OldY;
    	WindowState = OldWS;
    	Width = OldW;
    	Height = OldH;
        FullScreen1->Checked = FALSE;
        StatusBar->SizeGrip = TRUE;

    	TBHeight_Nml = 47;
    	TBHeight_Txt = 23;
    	TBHeight_Ntx = 35;
    	Bevel1->Visible = TRUE;
                                   
		MainPanel->Constraints->MinHeight += 2;
		MainPanel->Constraints->MaxHeight += 2;
		MainPanel->Height += 2;
        long l=GetWindowLong(Handle,GWL_STYLE);
        SetWindowLong(Handle, GWL_STYLE, l | WS_CAPTION | WS_THICKFRAME);
    }
	Visible = OldVis;
    UpdateWindow(Handle);
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::SCIVersionDetector1Click(TObject *Sender)
{

	U32 len,ofs;
	unsigned char *buf;

        OpenDialog->FileName = "SCIV.EXE";
        OpenDialog->Filter = "Programs (*.exe)|*.exe";
    if(!OpenDialog->Execute())
    	return;

	if((buf=ssLoadFileEx(ssFIO_ROOT|ssFIO_MESSAGE,OpenDialog->FileName.c_str(),&len))==NULL) {
		return;
	}

	if(buf[0]!='M'||buf[1]!='Z') {
		ssMessage(ssERROR,"%s is not a valid executable!",OpenDialog->FileName.c_str());
		return;
	}

	ofs = 0;
	while(ofs<len) {
		if(isalnum(buf[ofs]) && buf[ofs+1]=='.' &&
			buf[ofs+5]=='.'  &&
			isalnum(buf[ofs+2]) && isalnum(buf[ofs+3]) &&
			isalnum(buf[ofs+4]) && isalnum(buf[ofs+6]) &&
			isalnum(buf[ofs+7]) && isalnum(buf[ofs+8])) {
           		buf[ofs+9]='\0';
            	ssMessage(
                	ssNOTICE,
    				"SCI Version Detected\n\nFile %s is SCI Version: \n\n %s",OpenDialog->FileName.c_str(),(char*)(buf+ofs)
                );
                ssFree(buf);
                return;
		}
		ofs++;
	}
	ssFree(buf);
    ssMessage(ssERROR,
        "SCI Version Detection Failed! Unable to find version! It is packed and must be unpacked before it can be read."
    );
}
//---------------------------------------------------------------------------


void __fastcall TWndMain::CheckforLatestVersion1Click(TObject *Sender)
{
    HINTERNET hSession;
    hSession = InternetOpen(PROGRAM_NAME, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if(!hSession) ShowMessage("Error obtaining latest version information!");

    DWORD dwSize;
    CHAR   szHead[] = "Accept: */*\r\n\r\n";
    char szTemp[21];
    HINTERNET  hConnect;

    TDlgCheckVersion *VersionDlg=new TDlgCheckVersion(this);
    VersionDlg->Label2->Caption = " Checking for the latest version...";
	VersionDlg->Label3->Caption = ("Connecting...");
    VersionDlg->Show();
    VersionDlg->Repaint();
    VersionDlg->Animate();
    hConnect = InternetOpenUrl((HINTERNET)hSession, (LPCTSTR)"http://scistudio.sourceforge.net/", (LPCTSTR)szHead, (DWORD) lstrlen(szHead),
       (DWORD )INTERNET_FLAG_DONT_CACHE, NULL);  
    VersionDlg->Animate();
    if(!hConnect) {
        VersionDlg->Label3->Caption = ("Error obtaining latest version information!");
        return;
    }
    for(int i=0;i<20;i++) {
		VersionDlg->Animate();
    	if(!InternetReadFile (hConnect, szTemp+i, 1,  &dwSize) || dwSize>1) {
        	VersionDlg->Label3->Caption = ("Error obtaining latest version information!");
        	return;
    	}
    }
    VersionDlg->Animate();
    VersionDlg->Label2->Caption = " Checking for the latest version...done";
    if(strcmp(PROGRAM_VERSION,szTemp)==0)
        VersionDlg->Label3->Caption = ("There is currently no newer version available.");
    else {
    	VersionDlg->Label3->Font->Style = TFontStyles()<< fsBold;
        VersionDlg->Label3->Caption = ("There is a newer version available!");
        VersionDlg->Label4->Caption = (
                                       "You are using "+AnsiString(PROGRAM_VERSION)+"."
                                       "\nThe latest version is "+AnsiString(szTemp)+".");
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::GotoSCIStudiosWebSite1Click(TObject *Sender)
{
    ShellExecute(Handle, 0, "http://scistudio.sourceforge.net/", 0, 0, SW_NORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::Contents1Click(TObject *Sender)
{
    SCIHtmlHelp(
         GetDesktopWindow(),
         (AnsiString(HELP_NAME)+"::/main.html").c_str(),
         HH_DISPLAY_TOC,
         NULL
    );
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::Index1Click(TObject *Sender)
{
    SCIHtmlHelp(
         Handle,
         HELP_NAME,
         HH_DISPLAY_INDEX,
         0
    );
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::Search1Click(TObject *Sender)
{
    HH_FTS_QUERY q;
    q.cbStruct = sizeof(HH_FTS_QUERY);

    SCIHtmlHelp(
         Handle,
         HELP_NAME,
         HH_DISPLAY_SEARCH,
         (DWORD)&q
    );
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::GotoTheOnlineTutorial1Click(TObject *Sender)
{
    ShellExecute(Handle, 0, (AnsiString(Program.path)+"\\tutorial\\index.html").c_str(), 0, 0, SW_NORMAL);
}
//---------------------------------------------------------------------------
void __fastcall TWndMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caNone;
    CloseGame1Click(this);
    if(TaskBarPanel->Visible) {
    	 return;
    }

    FreeLogPal(&palEGA);
    FreeLogPal(&palFont);
    FreeLogPal(&palCursor);

    if(hhHandle) {
    	SCIHtmlHelp(0, NULL, HH_CLOSE_ALL, 0);
    	FreeLibrary(hhHandle);
    }

    SaveConfig();  
	delete DirDialog;

    Action = caFree;
}
//---------------------------------------------------------------------------
// Get path where the current process (.EXE) is located.
// This may be different from the current directory.
char szPath[1024];
LPCTSTR TWndMain::GetProgramPath()
{
	int i;
	BOOL bInString = FALSE;
	static TCHAR szPath[1024];

	strcpy(szPath, GetCommandLine());

	// Extract first argument
	for (i = 0; i < (int)strlen(szPath); i++)
	{
		if (szPath[i] == '"')
			bInString = !bInString;

		if (szPath[i] == ' ' && !bInString)
		{
			szPath[i] = 0;
			break;
		}
	}

	// Remove file name
	bool bFoundPath = FALSE;

	for (i = strlen(szPath) - 1; i >= 0; i--)
		if (szPath[i] == '\\')
		{
			szPath[i] = 0;
			bFoundPath = TRUE;
			break;
		}

	if (!bFoundPath)
	{
		// Command line does not contain path.
		// Assume working directory.
		GetCurrentDirectory(MAX_PATH, szPath);
	}

	// Remove leading quote, if any
	if (szPath[0] == '"')
		return szPath + 1;
	else
		return szPath;
}
//---------------------------------------------------------------------------
void __fastcall TWndMain::DoCommandLine()
{
	AnsiString CmdLn, ext;
    EDTWND *edtWnd;
    U8 *resBuf;
    U32 len;
    int type;

    if(!sCmdLine) return;
    if(!strlen(sCmdLine)) return;

	if(sCmdLine[0]=='"') {
    	int i,len=strlen(sCmdLine);
    	for(i=1;sCmdLine[i]!='"'&&i<len;i++)
        	sCmdLine[i-1]=sCmdLine[i];
 		if(i==len) sCmdLine[i]='\0';
        else sCmdLine[i-1]='\0';
    }

    if(sCmdLine[strlen(sCmdLine)-1]=='\\') sCmdLine[strlen(sCmdLine)-1]='\0';
    CmdLn = AnsiString(sCmdLine);
	if(!FileExists(CmdLn)) {
    	CmdLn = CmdLn.LowerCase();
        if(FileExists(CmdLn+"\\resource.map"))
    		ExploreGame(CmdLn,"");
     	return;
    }

    ext = ExtractFileExt(CmdLn);
	ext = ext.LowerCase();
	if(ext == ".sc" || ext == ".sh") {
		edtWnd = NewEditWnd(rsSCRIPT, NULL, ewSTAND_ALONE, NULL, 0);
        ((TWndScriptEdit*)edtWnd->Wnd)->OpenScript(CmdLn,ext==".sh");
        edtWnd->Wnd->BringToFront();
	} else if(ext == ".map") {
 		ExploreGame(ExtractFilePath(CmdLn),"");
	} else {
   		if((resBuf=ssLoadFile(ssFIO_ROOT|ssFIO_MESSAGE, sCmdLine, &len))==NULL)
    		return;
    	if((len<=2)||(type=CheckSCIFileHeader(resBuf))==-1) {
			ssMessage(ssERROR,"The file your are trying to open, %s, is not a valid SCI %s resource, or does not contain a valid header",sCmdLine,resTypes[type].name);
        	ssFree(resBuf);
        	return;
    	}
        len -= (U16)2;

        switch(type) {
        	case rsVIEW:  
        	case rsFONT:
        	case rsCURSOR:
				edtWnd = NewEditWnd(type, NULL, ewSTAND_ALONE, NULL, 0);
				strcpy(edtWnd->fileName,sCmdLine);
                ((TWndGfxEdit*)edtWnd->Wnd)->LoadRes(resBuf+2, len);
        		edtWnd->Wnd->BringToFront();
                break;
        	case rsPIC:
				edtWnd = NewEditWnd(rsPIC, NULL, ewSTAND_ALONE, NULL, 0);
				strcpy(edtWnd->fileName,sCmdLine);
                //((TWndPicEdit*)edtWnd->Wnd)->LoadRes(resBuf+2, len);
        		edtWnd->Wnd->BringToFront();
                break;
        	case rsTEXT:
				edtWnd = NewEditWnd(rsTEXT, NULL, ewSTAND_ALONE, NULL, 0);
				strcpy(edtWnd->fileName,sCmdLine);
                //((TWndTextEdit*)edtWnd->Wnd)->LoadRes(resBuf+2, len);
        		edtWnd->Wnd->BringToFront();
                break;
        	default:
            	ssMessage(ssERROR,"File %s is an unsupported resource format!", sCmdLine);
                break;
        }
		ssFree(resBuf);
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::FormShow(TObject *Sender)
{
	DoCommandLine();
}

//---------------------------------------------------------------------------
void __fastcall TWndMain::AddOpenGameToList(AnsiString Directory)
{
	AnsiString s;
    FixPath(s.c_str());
    for(int i=0;i<PrevOpenCount;i++) {
    	s = PrevOpened[i]->Caption.SubString(4,PrevOpened[i]->Caption.Length()-3);
    	if(s.LowerCase() == Directory.LowerCase()) {
    		for(int j=i;j>0;j--) {
            	PrevOpened[j]->Caption = PrevOpened[j-1]->Caption;
            	PrevOpened[j]->Caption.c_str()[1] = (char)((char)j+'0');
            }
			PrevOpened[0]->Caption = "&0 "+Directory;
            return;
        }
    }
	if(PrevOpenCount<10) {
    	PrevOpened[PrevOpenCount]=new TMenuItem(mnuRecent);
        PrevOpened[PrevOpenCount]->OnClick = PrevOpenClick;
    	PrevOpenCount++;
    }
    for(int i=PrevOpenCount-1;i>0;i--) {
    	PrevOpened[i]->Caption = PrevOpened[i-1]->Caption; 
        PrevOpened[i]->Caption.c_str()[1] = (char)((char)i+'0');
    }
	PrevOpened[0]->Caption = "&0 "+Directory;
    UpdateMenuBar();
}                
//---------------------------------------------------------------------------
void __fastcall TWndMain::PrevOpenClick(TObject *Sender)
{
	TMenuItem *ClickedItem = dynamic_cast<TMenuItem *>(Sender);
    AnsiString s=ClickedItem->Caption.SubString(4,ClickedItem->Caption.Length()-3);
    ExploreGame(s,"");
}
//---------------------------------------------------------------------------
void __fastcall TWndMain::UpdateMenuBar()
{
	if(!PrevOpenCount) {
    	empty1->Visible = TRUE;
    	return;
    }
    empty1->Visible = FALSE;
    for(int i=0;i<PrevOpenCount;i++) {
    	if(PrevOpened[i]!=NULL&&mnuRecent->Items->Count<2+i) {
        	PrevOpened[i]->OnClick = PrevOpenClick;

			mnuRecent->Items->Add(PrevOpened[i]);
            mnuRecent->Items->Visible = TRUE;
        }
    }
}          
//---------------------------------------------------------------------------
void __fastcall TWndMain::SampleItemClick(TObject *Sender)
{        
    U8 *resBuf;
    U32 len;
    int type;
    RESINFO *ri;

	TMenuItem *menuItem = (TMenuItem*)Sender;
    TMenuItem *parentMenu = menuItem->Parent;

    AnsiString FileName = AnsiString(Program.path)+"\\samples\\"+parentMenu->Caption+"s\\"+menuItem->Caption+".bin";
         
    if((resBuf=ssLoadFile(ssFIO_ROOT|ssFIO_MESSAGE, FileName.c_str(), &len))==NULL)
    		return;
    if((type=CheckSCIFileHeader(resBuf))==-1) {
    	ssMessage(ssERROR,"The file your are trying to open, %s, is not a valid SCI %s resource, or does not contain a valid header",sCmdLine,resTypes[type].name);
        ssFree(resBuf);
        return;
    }
    if((ri=AddResource((U8*)(resBuf+2), (U16)(len-2), (U8)type, (S16)-1, (U8)Game.defaultPack))==NULL) {
    	ssFree(resBuf);
        WndExplorer->FillListView();
        return;
    }                 
    ssFree(resBuf);
    WndExplorer->ChangeSelResType(ri->type);
    WndExplorer->FillListView();
    WndExplorer->ResListViewGotoRes(ri);
}
//---------------------------------------------------------------------------
BOOL TWndMain::LoadSampleDir (char *FromDirectory, TMenuItem *MenuItem, char *Filter)
{
    char DirectoryString[201];
    WIN32_FIND_DATA FindFileData;
    HANDLE hFindFile;

    wsprintf(DirectoryString, "%s\\%s", FromDirectory, Filter);
    hFindFile = FindFirstFile(
        DirectoryString,
        &FindFileData
    );

    do {
        if(FindFileData.dwFileAttributes!=FILE_ATTRIBUTE_DIRECTORY) {
        	for(int i=strlen(FindFileData.cFileName)-1;i>=0;i--) {
            	if(FindFileData.cFileName[i]=='.') {
                	FindFileData.cFileName[i]='\0';
                    break;
                }
            }
    		TMenuItem *newItem = new TMenuItem(MenuItem);
        	newItem->OnClick = SampleItemClick;
        	newItem->Caption = AnsiString(FindFileData.cFileName);
            MenuItem->Add(newItem);
        }
    } while(FindNextFile(hFindFile,	&FindFileData));
    return TRUE;
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::sbHideToolBarClick(TObject *Sender)
{
    // Hide the main toolbar
    MainPanel->Visible	= FALSE;
    ToolBar3->Checked	= FALSE;
}

//---------------------------------------------------------------------------

void __fastcall TWndMain::DoGameExecution(AnsiString _GameDir)
{
    if(_GameDir!=""&&_GameDir.c_str()[_GameDir.Length()-1]!='\\')
    	_GameDir = _GameDir+"\\";
    AnsiString INIFileName,GameExecutable;
    INIFileName = _GameDir+"game.ini";
    if(!FileExists(INIFileName))
    	INIFileName = _GameDir+"scistudio.ini";

    TIniFile *GameINI = new TIniFile(INIFileName);
    if(!FileExists(INIFileName)||!GameINI->ValueExists("Game","Executable")) {
        ShowMessage("Please select the game's executable (ie. SCIV.EXE)");
        OpenDialog->InitialDir = _GameDir;
        OpenDialog->FileName = "SCIV.EXE";
        OpenDialog->Filter = "Programs (*.exe, *.com, *.bat)|*.exe;*.com;*.bat";
        if(!OpenDialog->Execute()) {
        	delete GameINI;
        	return;
        }
        GameExecutable = OpenDialog->FileName;

        GameINI->WriteString("Game","Executable",ExtractFileName(GameExecutable));
    }

    GameExecutable = _GameDir+GameINI->ReadString("Game","Executable","");

    delete GameINI;

    if(!ShellExecute(Handle,0,GameExecutable.c_str(),0,_GameDir.c_str(),SW_SHOWNORMAL)) {
        ShowMessage("Error executing game executable: \""+GameExecutable+"\"!");
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::tmrSplashTimer(TObject *Sender)
{
	tmrSplash->Enabled = FALSE;
    delete DlgSplash;	
}
//---------------------------------------------------------------------------
HWND WINAPI TWndMain::SCIHtmlHelp(HWND hwndCaller, LPCSTR pszFile, UINT uCommand, DWORD_PTR dwData)
{
	typedef HWND WINAPI (*PHtmlHelpX)(HWND,LPCSTR,UINT,DWORD_PTR);
    PHtmlHelpX HtmlHelpX; 
	HWND Result = NULL;
	if(hhHandle==NULL)
		hhHandle = LoadLibrary("hhctrl.ocx");
	if(hhHandle) {
    	HtmlHelpX = (PHtmlHelpX) GetProcAddress(hhHandle, "HtmlHelpA");
    	Result = HtmlHelpX(hwndCaller, pszFile, uCommand, dwData);
    }/* else {
    	ShowMessage("You need to install Microsoft's HtmlHelp");
        Index1->Enabled = FALSE;
        Contents1->Enabled = FALSE;
        SB_Help->Enabled = FALSE;     
        Search1->Enabled = FALSE;
    }  */
    if(Result==NULL)
 		ShellExecute(NULL, 0, pszFile, 0, 0, SW_NORMAL);
    return Result;
}         
//---------------------------------------------------------------------------


void __fastcall TWndMain::AddResource1Click(TObject *Sender)
{
	WndExplorer->tbAddClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::ExtractResource1Click(TObject *Sender)
{
	WndExplorer->tbExtractClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::RemoveResource1Click(TObject *Sender)
{
	WndExplorer->tbDeleteClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::ExtractAllScriptRelatedFiles1Click(
      TObject *Sender)
{
	WndExplorer->ExtractAllScrRes();
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::RebuildResources1Click(TObject *Sender)
{
	WndExplorer->tbRebuildClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TWndMain::SoundBox1Click(TObject *Sender)
{
	if(!FileExists(SOUNDBOXPATH)) {
		ssMessage(ssNOTICE,"Soundbox.exe not found in the SCI Studio plugins directory!\n\nPlease make sure to extract it to :\n%s\nor it can not be executed from within the studio.",SOUNDBOXPATH.c_str());
		return;
	}
    ShellExecute(Handle, 0, SOUNDBOXPATH.c_str(), 0, 0, SW_NORMAL);
}
//---------------------------------------------------------------------------

