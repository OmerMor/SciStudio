//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <ActnList.hpp>
#include <StdActns.hpp>
#include <Clipbrd.hpp>
#include "SynEditHighlighter.hpp"
#include "SynHighlighterSCI.hpp"
#include "SynMemo.hpp"
#include "SynEdit.hpp"
#include "SynEditExport.hpp"
#include "SynEditPrint.hpp"
#include "SynEditPrintPreview.hpp"
#include "SynExportHTML.hpp"
#include <Dialogs.hpp>
#include <Graphics.hpp>
#include "CGAUGES.h"
                           
#define hlTOTAL 				7


#include "dirdialog.h"

#include "config.h"
#include "scihdr.h"
#include <Graphics.hpp>
#include <Dialogs.hpp>


//---------------------------------------------------------------------------
class TWndMain : public TForm
{
__published:	// IDE-managed Components
	TImageList *ilTreeView;
	TImageList *ilMainToolbarA;
	TImageList *ilEditBars;
	TImageList *ilMainToolbarB;
	TImageList *ilMainToolbarC;
	TImageList *ilXtraA;
	TImageList *ilXtraB;
	TMainMenu *MainMenu1;
	TMenuItem *MNUI_File;
	TMenuItem *New1;
	TMenuItem *Open1;
	TMenuItem *Close1;
	TMenuItem *N4;
	TMenuItem *Run1;
	TMenuItem *N8;
	TMenuItem *Settings1;
	TMenuItem *N3;
	TMenuItem *Exit1;
	TMenuItem *Resource1;
	TMenuItem *AddResource1;
	TMenuItem *ExtractResource1;
	TMenuItem *RemoveResource1;
	TMenuItem *N9;
	TMenuItem *AddSample1;
	TMenuItem *Cursor1;
	TMenuItem *Font1;
	TMenuItem *Pic1;
	TMenuItem *View2;
	TMenuItem *N7;
	TMenuItem *ExtractAllScriptRelatedFiles1;
	TMenuItem *N5;
	TMenuItem *RebuildResources1;
	TMenuItem *View1;
	TMenuItem *ToolBar1;
	TMenuItem *ToolBar3;
	TMenuItem *N6;
	TMenuItem *TextLabels1;
	TMenuItem *Images1;
	TMenuItem *AlwaysColour1;
	TMenuItem *More1;
	TMenuItem *ManagerBar1;
	TMenuItem *PreviewBar1;
	TMenuItem *StatusBar2;
	TMenuItem *N12;
	TMenuItem *FullScreen1;
	TMenuItem *Tools1;
	TMenuItem *ViewEditor1;
	TMenuItem *PictureEditor1;
	TMenuItem *FontEditor1;
	TMenuItem *CursorEditor1;
	TMenuItem *TextEditor1;
	TMenuItem *VocabEditor1;
	TMenuItem *ScriptEditor1;
	TMenuItem *N1;
	TMenuItem *SCIVersionDetector1;
	TMenuItem *Window1;
	TMenuItem *WindowCascadeItem;
	TMenuItem *WindowTileItem;
	TMenuItem *WindowTileItem2;
	TMenuItem *WindowMinimizeItem;
	TMenuItem *WindowArrangeItem;
	TMenuItem *Web1;
	TMenuItem *CheckforLatestVersion1;
	TMenuItem *GotoSCIStudiosWebSite1;
	TMenuItem *Help1;
	TMenuItem *Contents1;
	TMenuItem *Index1;
	TMenuItem *Search1;
	TMenuItem *N11;
	TMenuItem *GotoTheOnlineTutorial1;
	TMenuItem *N2;
	TMenuItem *About1;
	TPopupMenu *TaskbarMenu;
	TMenuItem *WindowCascadeItemX;
	TMenuItem *WindowTileItem1X;
	TMenuItem *WindowTileItem2X;
	TMenuItem *WindowMinimizeItemX;
	TMenuItem *WindowArrangeItemX;
	TWindowCascade *WindowCascade1;
	TWindowTileHorizontal *WindowTileHorizontal1;
	TWindowTileVertical *WindowTileVertical1;
	TWindowMinimizeAll *WindowMinimizeAll1;       
	TWindowArrange *WindowArrangeAll1;
	TStatusBar *StatusBar;
	TPanel *TaskBarPanel;
	TPageControl *TaskBar;
	TImageList *ilResIconsS;
	TImageList *ilResIcons;
	TImageList *ilStyles;
	TImage *imResize;
	TPanel *MainPanel;
	TBevel *Bevel1;
	TBevel *Bevel2;
	TCoolBar *MainPanel2;
	TToolBar *ToolBar2;
	TToolButton *sbHideToolBar;
	TToolBar *pnlToolBar;
	TToolButton *SB_OpenGame;
	TToolButton *SB_CloseGame;
	TToolButton *SB_RunGame;
	TToolButton *ToolButton1;
	TToolButton *SB_ViewEdit;
	TToolButton *SB_PicEdit;
	TToolButton *SB_FontEdit;
	TToolButton *SB_CurEdit;
	TToolButton *SB_TextEdit;
	TToolButton *SB_Vocab;
	TToolButton *SB_Script;
	TToolButton *ToolButton2;
	TToolButton *SB_Help;
	TOpenDialog *OpenDialog;
	TImageList *ilMainToolbarD;
	TMenuItem *ResourceCaption1;
	TTimer *tmrSplash;
	TPopupMenu *mnuRecent;
	TMenuItem *empty1;
	TImageList *ilEditBarsH;
	TToolButton *SB_Sound;
	TMenuItem *SoundBox1;
	TSynSCISyn *SynSCISyn1;
	void __fastcall NewGame1Click(TObject *Sender);
	void __fastcall OpenGame1Click(TObject *Sender);
	void __fastcall CloseGame1Click(TObject *Sender);
	void __fastcall RunGame1Click(TObject *Sender);
	void __fastcall Settings1Click(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);
	void __fastcall TaskBarChange(TObject *Sender);
	void __fastcall SB_EditorClick(TObject *Sender);
	void __fastcall ToolBar3Click(TObject *Sender);
	void __fastcall TextLabels1Click(TObject *Sender);
	void __fastcall Images1Click(TObject *Sender);
	void __fastcall AlwaysColour1Click(TObject *Sender);
	void __fastcall More1Click(TObject *Sender);
	void __fastcall ManagerBar1Click(TObject *Sender);
	void __fastcall PreviewBar1Click(TObject *Sender);
	void __fastcall StatusBar2Click(TObject *Sender);
	void __fastcall FullScreen1Click(TObject *Sender);
	void __fastcall SCIVersionDetector1Click(TObject *Sender);
	void __fastcall CheckforLatestVersion1Click(TObject *Sender);
	void __fastcall GotoSCIStudiosWebSite1Click(TObject *Sender);
	void __fastcall Contents1Click(TObject *Sender);
	void __fastcall Index1Click(TObject *Sender);
	void __fastcall Search1Click(TObject *Sender);
	void __fastcall GotoTheOnlineTutorial1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall sbHideToolBarClick(TObject *Sender);
	void __fastcall ResourceCaption1Click(TObject *Sender);
	void __fastcall tmrSplashTimer(TObject *Sender);
	void __fastcall AddResource1Click(TObject *Sender);
	void __fastcall ExtractResource1Click(TObject *Sender);
	void __fastcall RemoveResource1Click(TObject *Sender);
	void __fastcall ExtractAllScriptRelatedFiles1Click(TObject *Sender);
	void __fastcall RebuildResources1Click(TObject *Sender);
	void __fastcall SoundBox1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TWndMain(TComponent* Owner);

    void AddToTaskbar(EDTWND *edtWnd);
	void DeleteFromTaskbar(EDTWND *edtWnd);
	void __fastcall UpdateTaskBar(System::TObject *Sender);
	void __fastcall ToggleVisibleTaskBar();
	void __fastcall UpdateTaskBarCaption(TTabSheet *taskTab);
	void __fastcall EditFormClose(System::TObject *Sender,TCloseAction &Action);   
//---------------------------------------------------------------------------
	void __fastcall LoadConfig();
	void __fastcall SaveConfig();

	void __fastcall DoCommandLine();
	LPCTSTR GetProgramPath(void);
    void __fastcall AddOpenGameToList(AnsiString Directory);
	void __fastcall PrevOpenClick(TObject *Sender);
    void __fastcall UpdateMenuBar();

	void __fastcall SampleItemClick(TObject *Sender);
	BOOL LoadSampleDir (char *FromDirectory, TMenuItem *MenuItem, char *Filter);

    void __fastcall DoGameExecution(AnsiString _GameDir);
    void __fastcall ExploreGame(AnsiString path,AnsiString name);

    HWND WINAPI SCIHtmlHelp(HWND hwndCaller, LPCSTR pszFile, UINT uCommand, DWORD_PTR dwData);

	int PrevOpenCount;
    TMenuItem *PrevOpened[10];
    TDirDialog *DirDialog;

	BOOL NO_KEY;

    int OldX,OldY,OldH,OldW;
    TWindowState OldWS;
	int TBHeight_Nml,TBHeight_Txt,TBHeight_Ntx;

    HANDLE hhHandle;

    TSynHighlighterAttributes *SynAttr[hlTOTAL];
};

#define WRITE_STATUS(s) WndMain->StatusBar->Panels->Items[1]->Text = s
//---------------------------------------------------------------------------
extern PACKAGE TWndMain *WndMain;
//---------------------------------------------------------------------------
#endif
