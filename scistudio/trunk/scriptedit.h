//---------------------------------------------------------------------------

#ifndef scripteditH
#define scripteditH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MenuBar.hpp"
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include "SynEditHighlighter.hpp"
#include "SynHighlighterSCI.hpp"
#include "SynMemo.hpp"
#include "SynEdit.hpp"
#include "SynEditExport.hpp"
#include "SynEditPrint.hpp"
#include "SynEditPrintPreview.hpp"
#include "SynExportHTML.hpp"   
#include "scihdr.h"
#include "config.h"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
typedef struct _sMEMO {
	_sMEMO *prev,*next;
    TTabSheet *Tab;
    TSynMemo *Memo;
    BOOL FILE_CAN_COMPILE,HEADER;
    int Modified;
    char FileName[1024];
} sMEMO;
//---------------------------------------------------------------------------
class TWndScriptEdit : public TForm
{
__published:	// IDE-managed Components
	TSplitter *Splitter1;
	TCoolBar *CoolBar1;
	TMenuBar *MenuBar1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButton17;
	TToolButton *ToolButton18;
	TToolButton *ToolButton7;
	TToolButton *tbCompileRun;
	TToolButton *tbCompile;
	TToolButton *ToolButton19;
	TToolButton *ToolButton8;
	TToolButton *ToolButton16;
	TToolButton *ToolButton9;
	TToolButton *ToolButton10;
	TToolButton *ToolButton12;
	TToolButton *ToolButton11;
	TToolButton *ToolButton13;
	TToolButton *ToolButton14;
	TToolButton *ToolButton15;
	TStatusBar *StatusBar1;
	TPanel *MessagePanel;
	TPanel *Panel4;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *New1;
	TMenuItem *EmptyScript1;
	TMenuItem *RoomScript1;
	TMenuItem *Open1;
	TMenuItem *OpenSCISH1;
	TMenuItem *Save1;
	TMenuItem *SaveAs1;
	TMenuItem *CloseFile1;
	TMenuItem *N1;
	TMenuItem *Print1;
	TMenuItem *PrintPreview1;
	TMenuItem *N7;
	TMenuItem *Close1;
	TMenuItem *Edit1;
	TMenuItem *Undo1;
	TMenuItem *N3;
	TMenuItem *Cut1;
	TMenuItem *Copy1;
	TMenuItem *Paste1;
	TMenuItem *Clear1;
	TMenuItem *N2;
	TMenuItem *SelectAll2;
	TMenuItem *Search1;
	TMenuItem *Find1;
	TMenuItem *FindAgain1;
	TMenuItem *Replace1;
	TMenuItem *View1;
	TMenuItem *Messages1;
	TMenuItem *ClassReference1;
	TMenuItem *Compile1;
	TMenuItem *Compile2;
	TMenuItem *CompileandRun1;
	TMenuItem *N9;
	TMenuItem *CompileMakeFile1;
	TMenuItem *CompileAllScripts1;
	TMenuItem *Tools1;
	TMenuItem *CreateMakeFile1;
	TMenuItem *EnvironmentOptions1;
	TMenuItem *ExporttoHTML1;
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
	TFindDialog *FindDialog1;
	TReplaceDialog *ReplaceDialog1;
	TPopupMenu *PopupMenu1;
	TMenuItem *Undo2;
	TMenuItem *N4;
	TMenuItem *Cut2;
	TMenuItem *Copy2;
	TMenuItem *Paste2;
	TMenuItem *Delete1;
	TMenuItem *N5;
	TMenuItem *SelectAll1;
	TMenuItem *N6;
	TMenuItem *EditorOptions1;
	TPopupMenu *PopupMenu2;
	TMenuItem *HideMessages1;
	TPopupMenu *PopupMenu3;
	TMenuItem *CloseFile2;
	TImageList *ImageList1;
	TPopupMenu *PopupMenu4;
	TMenuItem *MenuTitle;
	TMenuItem *GoToClass1;
	TMenuItem *ClassSystemHelpIndex1;
	TPageControl *pcMemos;
	TPanel *Panel2;
	TPanel *Panel1;
	TSpeedButton *SpeedButton2;
	TListBox *lbMessage;
	TSynEditPrint *SynEditPrint1;
	TSynExporterHTML *SynExporterHTML1;
	TToolButton *sbRedo;
	TMenuItem *Redo1;
	TMenuItem *KernelReference1;
	TPanel *Panel3;
	TPanel *pnRefs;
	TSplitter *spRefs;
	TPanel *pnKernelRef;
	TPanel *pnKRH;
	TLabel *Label1;
	TSpeedButton *SpeedButton1;
	TTreeView *TreeView1;
	TPanel *pnClassRef;
	TPanel *pnCRH;
	TLabel *Label2;
	TSpeedButton *SpeedButton3;
	TTreeView *TreeView2;
	TMenuItem *N8;
	TMenuItem *ShowCodeReference1;
	TPopupMenu *PopupMenu5;
	TMenuItem *MenuItem1;
	TMenuItem *GoToKernel1;
	TMenuItem *KernelFunctionsHelpIndex1;
	TMenuItem *N10;
	TMenuItem *muKernelInfo;
	TMenuItem *muClassTitle;
	TMenuItem *N11;
	void __fastcall EmptyScript1Click(TObject *Sender);
	void __fastcall RoomScript1Click(TObject *Sender);
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall OpenSCISH1Click(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall SaveAs1Click(TObject *Sender);
	void __fastcall CloseFile1Click(TObject *Sender);
	void __fastcall Print1Click(TObject *Sender);
	void __fastcall PrintPreview1Click(TObject *Sender);
	void __fastcall Close1Click(TObject *Sender);
	void __fastcall Undo1Click(TObject *Sender);
	void __fastcall Cut1Click(TObject *Sender);
	void __fastcall Copy1Click(TObject *Sender);
	void __fastcall Paste1Click(TObject *Sender);
	void __fastcall Clear1Click(TObject *Sender);
	void __fastcall SelectAll2Click(TObject *Sender);
	void __fastcall Find1Click(TObject *Sender);
	void __fastcall FindAgain1Click(TObject *Sender);
	void __fastcall Replace1Click(TObject *Sender);
	void __fastcall Messages1Click(TObject *Sender);
	void __fastcall ClassReference1Click(TObject *Sender);
	void __fastcall Compile2Click(TObject *Sender);
	void __fastcall CompileandRun1Click(TObject *Sender);
	void __fastcall CompileMakeFile1Click(TObject *Sender);
	void __fastcall CompileAllScripts1Click(TObject *Sender);
	void __fastcall CreateMakeFile1Click(TObject *Sender);
	void __fastcall EnvironmentOptions1Click(TObject *Sender);
	void __fastcall ExporttoHTML1Click(TObject *Sender);
	void __fastcall GoToClass1Click(TObject *Sender);
	void __fastcall ClassSystemHelpIndex1Click(TObject *Sender);
	void __fastcall lbMessageClick(TObject *Sender);
	void __fastcall lbMessageKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall FindDialog1Find(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall pcMemosChange(TObject *Sender);
	void __fastcall MenuTitleDrawItem(TObject *Sender, TCanvas *ACanvas,
          TRect &ARect, bool Selected);
	void __fastcall ReplaceDialog1Replace(TObject *Sender);
	void __fastcall Redo1Click(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall KernelReference1Click(TObject *Sender);
	void __fastcall pnRefsResize(TObject *Sender);
	void __fastcall pnRefsEndDock(TObject *Sender, TObject *Target, int X,
          int Y);
	void __fastcall Panel3DockDrop(TObject *Sender, TDragDockObject *Source,
          int X, int Y);
	void __fastcall Panel3DockOver(TObject *Sender, TDragDockObject *Source,
          int X, int Y, TDragState State, bool &Accept);
	void __fastcall ShowCodeReference1Click(TObject *Sender);
	void __fastcall GoToKernel1Click(TObject *Sender);
	void __fastcall KernelMenuTitle1DrawItem(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, bool Selected);
	void __fastcall KernelFunctionsHelpIndex1Click(TObject *Sender);
	void __fastcall TreeView1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
	void __fastcall muKernelInfoAdvancedDrawItem(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TOwnerDrawState State);
	void __fastcall muKernelInfoMeasureItem(TObject *Sender, TCanvas *ACanvas,
          int &Width, int &Height);
	void __fastcall TreeView1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall muClassTitleMeasureItem(TObject *Sender, TCanvas *ACanvas,
          int &Width, int &Height);
	void __fastcall muClassTitleDrawItem(TObject *Sender, TCanvas *ACanvas,
          TRect &ARect, bool Selected);
private:	// User declarations
public:		// User declarations
	__fastcall TWndScriptEdit(TComponent* Owner);

    EDITORTAG edTag;
	BOOL InitEditor(EDTWND *_edtWnd, U8 *resBuf, S16 resVer);

	void __fastcall MemoStatusChange(TObject *Sender,TSynStatusChanges Changes);
	void __fastcall MemoChange(TObject *Sender);
	void __fastcall UpdateStatus();
	void __fastcall MemoKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);

    void InitMemos();
    sMEMO *NewMemo(AnsiString FileName);
    void DeleteMemo(sMEMO *memo,BOOL MAKE_NEW);
    BOOL SaveScript(sMEMO *memo,BOOL ASK_FILE);

    void __fastcall OpenScript(AnsiString fileName,BOOL HEADER);

    void __fastcall UpdateTitleBar();
	void ChangeMemoCaption(sMEMO *memo, AnsiString Caption);

    void __fastcall MenuTitleDraw(TCanvas *ACanvas, TRect &ARect, AnsiString s);

    int ParseSaveChanges();

    int newCount;
    sMEMO *firstMemo,*lastMemo, *activeMemo;

    int memoCount;       

    AnsiString FindText,RepText;

    BOOL COMPILE_SUCCESS;

    char Directory[1024],BinDirectory[1024];

    int dockCount;
};
//---------------------------------------------------------------------------
extern PACKAGE TWndScriptEdit *WndScriptEdit;
//---------------------------------------------------------------------------
#endif
