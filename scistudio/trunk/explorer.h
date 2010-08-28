//---------------------------------------------------------------------------

#ifndef explorerH
#define explorerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <inifiles.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
#include "scihdr.h"
#include <Graphics.hpp>
#include <ExtDlgs.hpp>
#include "SynEdit.hpp"
#include "SynMemo.hpp"
//---------------------------------------------------------------------------
#define lvcNAME		-1
#define lvcNUMBER	0   
#define lvcSIZE		1
#define lvcPACKAGE	2
#define lvcOFFSET	3
#define lvcENCODE	4
//---------------------------------------------------------------------------
class TWndExplorer : public TForm
{
__published:	// IDE-managed Components
	TToolBar *tbExplorer;
	TToolButton *tbAdd;
	TToolButton *tbExtract;
	TToolButton *tbDelete;
	TToolButton *ToolButton4;
	TToolButton *tbEdit;
	TToolButton *tbPropeties;
	TToolButton *ToolButton7;
	TToolButton *tbRebuild;
	TToolButton *tbView;
	TToolButton *ToolButton1;
	TPopupMenu *popExplorer;
	TMenuItem *Add1;
	TMenuItem *Extract1;
	TMenuItem *Delete1;
	TMenuItem *MenuItem2;
	TMenuItem *RebuildResources2;
	TMenuItem *MenuItem3;
	TMenuItem *ViewStyle1;
	TMenuItem *LargeIcon1;
	TMenuItem *SmallIcon1;
	TMenuItem *List1;
	TMenuItem *Details1;
	TMenuItem *N1;
	TMenuItem *Properties1;
	TPopupMenu *popViewStyle;
	TMenuItem *LargeIcon2;
	TMenuItem *SmallIcon2;
	TMenuItem *List2;
	TMenuItem *Details2;
	TImageList *ilExplorer;
	TSaveDialog *SaveDialog;
	TOpenDialog *OpenDialog;
	TPanel *Panel1;
	TPanel *PanelLV;
	TListView *lvResources;
	TPanel *pnResTypes;
	TTreeView *tvResTypes;
	TSplitter *spResTypes;
	TPanel *Panel6;
	TLabel *Label1;
	TPanel *Panel7;
	TSpeedButton *BtnCloseResTV;
	TSplitter *spPreview;
	TPanel *pnResCap;
	TPanel *Panel14;
	TPanel *Panel16;
	TLabel *lblResType;
	TImage *imgResType;
	TPanel *Panel15;
	TSpeedButton *SpeedButton1;
	TPanel *Panel17;
	TLabel *lblResTypeDesc;
	TTimer *tmrView;
	TTimer *tmrPic;
	TPanel *pnPreview;
	TPanel *Panel8;
	TLabel *PreviewCaption;
	TPanel *Panel10;
	TSpeedButton *SpeedButton2;
	TPageControl *PreviewPC;
	TTabSheet *ViewPage;
	TScrollBox *scbView;
	TImage *imgView;
	TShape *shpView;
	TPanel *Panel2;
	TLabel *Label5;
	TShape *TransColour;
	TLabel *Label9;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *CelStats;
	TLabel *LoopStats;
	TLabel *Label6;
	TLabel *Label7;
	TSpeedButton *btnAnimateView;
	TEdit *Mirroring;
	TEdit *CelHeight;
	TEdit *CelWidth;
	TUpDown *SwitchCel_UpDn;
	TUpDown *SwitchLoop_UpDn;
	TTabSheet *PicPage;
	TScrollBox *PicScrollBox;
	TPanel *pnlPic;
	TShape *shpPic;
	TImage *imgPic;
	TTabSheet *FontPage;
	TScrollBox *scrFont;
	TImage *imgFont;
	TTabSheet *CursorPage;
	TPanel *pnlCursor;
	TLabel *MouseHS;
	TShape *Shape1;
	TImage *imgCursor;
	TTabSheet *MemoPage;
	TMemo *PreviewMemo;
	TTabSheet *SoundPage;
	TLabel *Label2;
	TLabel *Label16;
	TLabel *Label18;
	TLabel *Label21;
	TTabSheet *PageNoPrev;
	TLabel *Label11;
	TTabSheet *PageNone;
	TLabel *LblPgNone;
	TTabSheet *UnkComPage;
	TLabel *Label8;
	TLabel *Label10;
	TTabSheet *ErrPage;
	TLabel *Label12;
	TLabel *Label13;
	TTabSheet *PageGameInfo;
	TPanel *Panel5;
	TShape *shpGameIcon;
	TLabel *Label14;
	TLabel *lName;
	TLabel *lLocation;
	TLabel *Label17;
	TImage *imgGameIcon;
	TPanel *Panel9;
	TPanel *Panel11;
	TLabel *Label15;
	TMemo *mmoGameNotes;
	TPanel *pnlGamePic;
	TShape *shpGamePic;
	TImage *imgGamePic;
	TOpenPictureDialog *OpenPictureDialog;
	TImageList *ImageList1;
	TLabel *Label19;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TPanel *Panel3;
	TButton *Button1;
	TLabel *Label20;
	TTabSheet *ScriptPage;
	TSynMemo *ScriptMemo;
	TToolButton *ToolButton2;
	TLabel *Label26;
	TLabel *lbSCIVersion;
	TTabSheet *PalPrevPage;
	TImage *imPalPrev;
	TImage *imVPal;
	TPanel *pnPicCtl;
	TSpeedButton *VisualButton;
	TSpeedButton *PriorityButton;
	TSpeedButton *ControlButton;
	TSpeedButton *btnAnimatePic;
	TLabel *Label22;
	TToolBar *ToolBar6;
	TToolButton *tbPal0;
	TToolButton *tbPal1;
	TToolButton *tbPal2;
	TToolButton *tbPal3;
	TImage *imPPal;
	TComboBox *cbViewPal;
	TSpeedButton *btnToBmp;
	TSpeedButton *SpeedButton3;
	void __fastcall tbAddClick(TObject *Sender);
	void __fastcall tbExtractClick(TObject *Sender);
	void __fastcall tbEditClick(TObject *Sender);
	void __fastcall tbPropetiesClick(TObject *Sender);
	void __fastcall tbRebuildClick(TObject *Sender);
	void __fastcall tbViewClick(TObject *Sender);
	void __fastcall tvResTypesClick(TObject *Sender);
	void __fastcall tvResTypesChange(TObject *Sender, TTreeNode *Node);
	void __fastcall lvResourcesClick(TObject *Sender);
	void __fastcall lvResourcesChange(TObject *Sender, TListItem *Item,
          TItemChange Change);
	void __fastcall ViewStylesClick(TObject *Sender);
	void __fastcall lvResourcesColumnClick(TObject *Sender,
          TListColumn *Column);
	void __fastcall tvResTypesEdited(TObject *Sender, TTreeNode *Node,
          AnsiString &S);
	void __fastcall lvResourcesEdited(TObject *Sender, TListItem *Item,
          AnsiString &S);
	void __fastcall tbDeleteClick(TObject *Sender);
	void __fastcall btnPicScreenClick(TObject *Sender);
	void __fastcall scrFontResize(TObject *Sender);
	void __fastcall SwitchLoop_UpDnClick(TObject *Sender, TUDBtnType Button);
	void __fastcall btnAnimateViewClick(TObject *Sender);
	void __fastcall tmrViewTimer(TObject *Sender);
	void __fastcall scbViewResize(TObject *Sender);
	void __fastcall PicScrollBoxResize(TObject *Sender);
	void __fastcall CursorPageResize(TObject *Sender);
	void __fastcall btnAnimatePicClick(TObject *Sender);
	void __fastcall tmrPicTimer(TObject *Sender);
	void __fastcall lvResourcesDblClick(TObject *Sender);
	void __fastcall pnlGamePicResize(TObject *Sender);
	void __fastcall BtnCloseResTVClick(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall tbPal0Click(TObject *Sender);
	void __fastcall imgGameIconClick(TObject *Sender);
	void __fastcall imgGamePicClick(TObject *Sender);
	void __fastcall mmoGameNotesChange(TObject *Sender);
	void __fastcall Label20Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall PalPrevPageResize(TObject *Sender);
	void __fastcall cbViewPalChange(TObject *Sender);
	void __fastcall btnToBmpClick(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall lvResourcesKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TWndExplorer(TComponent* Owner);
                     
    BOOL InitEditor(EDTWND *_edtWnd, U8 *resBuf, S16 resVer);
	EDITORTAG edTag;
    void ClearResStructs();

    void ChangeSelResType(int newResType);    
    void DoPreview();

    void __fastcall ReopenGame();

	void __fastcall SetUpInterface();
	void __fastcall FillListView();
	void __fastcall ProcessConfig();
	void __fastcall MakeConfig();
	void __fastcall FillTreeView(int resType);
    TTreeNode *GetResTVItem(int resType);
    int GetResTVType();

    RESINFO *ResListViewGetRes(TListItem* Selected);
    void ResListViewGotoItem(TListItem* Item);
    TListItem* ResListViewGotoRes(RESINFO *ri);
    void __fastcall lvResourcesSortColumns(int Index);

    RESINFO *SaveResToGame(U8 *buf, U16 len, U8 type, U16 num);
    void __fastcall CopyFile(AnsiString from, AnsiString to);

    void __fastcall lvHeadersClick(TObject *Sender);
    void __fastcall ExtractAllScrRes();
    void __fastcall UpdateExplorerBar(BOOL f);

    BOOL dlgCANCLOSE,lvKEYS_ENABLED;
    int adrsPackage,adrsNumber;
    AnsiString aszTemp;

    TListView *lvHeaders;

    char szTemp[1024];


    sciVIEW *pvView;
    	sciVIEWLOOP *pvLoop,*pvLoopReal;
        sciVIEWCEL	*pvCel;
    sciPIC  *pvPic;
    sciSCRIPT *pvScript;
    sciTEXT *pvText;
    sciVOCAB000 *pvVocab000;
    sciFONT *pvFont;
    sciCURSOR *pvCursor;
    sciPALETTE *pvPal,*viewPal;

    RESINFO **palInfo;
    BOOL PAL_CAN_DISPOSE;

    U8 activePalette,activeScreen;

    BOOL RES_FREE;

    BOOL ANIVIEW,SAVE_GAME_NOTES;
};
extern AnsiString FilterAllRes;
extern AnsiString FliterScript;
//---------------------------------------------------------------------------
extern PACKAGE TWndExplorer *WndExplorer;
//---------------------------------------------------------------------------
#endif
