//---------------------------------------------------------------------------

#ifndef vieweditH
#define vieweditH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MenuBar.hpp"
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
typedef struct _edUNDO {
	_edUNDO *next,*prev;
    int width,height,n;
    U8 *bits;
} edUNDO;         
//---------------------------------------------------------------------------
class TWndGfxEdit : public TForm
{
__published:	// IDE-managed Components
	TCoolBar *CoolBar1;
	TMenuBar *MenuBar1;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *New1;
	TMenuItem *Open1;
	TMenuItem *Save1;
	TMenuItem *SaveAs1;
	TMenuItem *SaveToGame1;
	TMenuItem *N1;
	TMenuItem *Exit1;
	TMenuItem *Edit1;
	TMenuItem *Undo1;
	TMenuItem *Redo1;
	TMenuItem *N2;
	TMenuItem *Cut1;
	TMenuItem *Copy1;
	TMenuItem *Paste1;
	TMenuItem *Clear1;
	TMenuItem *Image2;
	TMenuItem *Flip1;
	TMenuItem *Horizontally1;
	TMenuItem *Vertically1;
	TMenuItem *Shift1;
	TMenuItem *Up1;
	TMenuItem *Down1;
	TMenuItem *Left1;
	TMenuItem *Right1;
	TMenuItem *N3;
	TMenuItem *Options1;
	TMenuItem *WithLoop1;
	TMenuItem *WithOutLoop1;
	TMenuItem *WithColour1;
	TMenuItem *Invert1;
	TMenuItem *GreyScale1;
	TMenuItem *ViewMenu;
	TMenuItem *N6;
	TMenuItem *Animator1;
	TMenuItem *CharacterTester1;
	TMenuItem *Zoom1;
	TMenuItem *NormalViewing1;
	TMenuItem *N4;
	TMenuItem *ZoomIn1;
	TMenuItem *ZoomOut1;
	TMenuItem *Zoom2;
	TMenuItem *N111;
	TMenuItem *N211;
	TMenuItem *N311;
	TMenuItem *N411;
	TMenuItem *N511;
	TMenuItem *N611;
	TMenuItem *N711;
	TMenuItem *N811;
	TMenuItem *N911;
	TMenuItem *N1011;
	TMenuItem *N1111;
	TMenuItem *N1211;
	TMenuItem *N1311;
	TMenuItem *N1411;
	TMenuItem *N1511;
	TMenuItem *N1611;
	TMenuItem *Import1;
	TMenuItem *WindowsBitmap1;
	TMenuItem *ExportCelsToBitmapBMP1;
	TPanel *pnTools;
	TScrollBox *ScrollBox1;
	TToolBar *ToolBar1;
	TToolButton *sbNew;
	TToolButton *sbOpen;
	TToolButton *sbSave;
	TToolButton *sbExport;
	TToolButton *ToolButton17;
	TToolButton *sbUndo;
	TToolButton *ToolButton18;
	TToolButton *sbCut;
	TToolButton *sbCopy;
	TToolButton *sbPaste;
	TPanel *pnDrawingTools;
	TToolBar *ToolBar2;
	TToolButton *sbPen;
	TToolButton *sbLine;
	TToolButton *sbReplace;
	TToolButton *sbFill;
	TToolButton *sbRect;
	TToolButton *sbFRect;
	TToolButton *sbRRect;
	TToolButton *sbFRRect;
	TToolButton *sbEllipse;
	TToolButton *sbFEllipse;
	TToolBar *ToolBar3;
	TToolButton *sbArrow;
	TToolButton *sbColGrab;
	TToolButton *sbZoom;
	TToolButton *sbScroll;
	TToolButton *sbSelection;
	TToolButton *sbSelectionRZ;
	TToolButton *sbSelectionMove;
	TToolButton *sbSelectionCopy;
	TToolBar *ToolBar4;
	TToolButton *sbMoveUp;
	TToolButton *sbMoveDown;
	TToolButton *sbMoveLeft;
	TToolButton *sbMoveRight;
	TToolButton *sbFlipH;
	TToolButton *sbFlipV;
	TToolBar *ToolBar6;
	TToolButton *sbInvert;
	TToolButton *sbGrey;
	TToolBar *ToolBar5;
	TToolButton *sbBrushStyle;
	TToolButton *sbPenWidth;
	TToolButton *sbPenStyle;
	TPanel *pnPalette;
	TPanel *pnCol;
	TShape *shCol2;
	TShape *shCol1;
	TSpeedButton *sbSwapCols;
	TPanel *pnPal;
	TImage *imPal;
	TPanel *pnView;
	TLabel *lbLoop;
	TUpDown *udLoop;
	TUpDown *udCel;
	TLabel *lbCel;
	TPaintBox *pbSurface;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *edWidth;
	TEdit *edHeight;
	TLabel *Label7;
	TEdit *edY;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *edX;
	TLabel *Label10;
	TComboBox *cbLoopMirror;
	TPanel *Panel7;
	TScrollBar *sbrCels;
	TImage *imCels;
	TPopupMenu *BrushStyleMenu;
	TMenuItem *Solid1;
	TMenuItem *Clear2;
	TMenuItem *BDiagonal1;
	TMenuItem *FDiagonal1;
	TMenuItem *Cross1;
	TMenuItem *DiagCross1;
	TMenuItem *Horizontal1;
	TMenuItem *Vertical1;
	TPopupMenu *PenSizeMenu;
	TMenuItem *N11;
	TMenuItem *N21;
	TMenuItem *N31;
	TMenuItem *N41;
	TMenuItem *N51;
	TMenuItem *N61;
	TMenuItem *N71;
	TMenuItem *N81;
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
	TPopupMenu *PenStyleMenu;
	TMenuItem *Solid2;
	TMenuItem *Dash1;
	TMenuItem *Dot1;
	TMenuItem *DashDot1;
	TMenuItem *DashDotDot1;
	TMenuItem *Clear3;
	TSpeedButton *btnTCol;
	TShape *shpTCol;
	TTimer *tmrSelCel;
	TTimer *tmrSelection;
	TPanel *pnCoords;
	TPanel *Panel8;
	TLabel *lbCoords;
	TPanel *pnFont;
	TPanel *Panel6;
	TPanel *Panel9;
	TImage *imChars;
	TScrollBar *sbrChars;
	TToolBar *tbLoopCel;
	TToolButton *ddLoop;
	TToolButton *ddCel;
	TPopupMenu *pmCel;
	TMenuItem *AddCel1;
	TMenuItem *DeleteCel1;
	TMenuItem *AppendCel1;
	TMenuItem *InsertCel1;
	TPopupMenu *pmLoop;
	TMenuItem *AddLoop1;
	TMenuItem *AppendLoop1;
	TMenuItem *InsertLoop1;
	TMenuItem *DeleteLoop1;
	TMenuItem *AddToEndLoop1;
	TMenuItem *AddToEndCel1;
	TTimer *tmrSelChar;
	TGroupBox *GroupBox1;
	TEdit *edChWidth;
	TEdit *edChHeight;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *lbChar;
	TUpDown *udChar;
	TGroupBox *GroupBox2;
	TEdit *edFnHeight;
	TLabel *Label13;
	TMenuItem *N5;
	TMenuItem *Toolbars1;
	TMenuItem *DrawingTools1;
	TMenuItem *ColourSelection1;
	TMenuItem *Coords1;
	TToolButton *sbRedo;
	TMenuItem *FontMenu;
	TMenuItem *AddCel2;
	TMenuItem *Insert1;
	TMenuItem *Append1;
	TMenuItem *AddToEnd1;
	TMenuItem *DeleteCel2;
	TMenuItem *AddLoop2;
	TMenuItem *Insert2;
	TMenuItem *Append2;
	TMenuItem *AddToEnd2;
	TMenuItem *DeleteLoop2;
	TOpenPictureDialog *OpenPictureDialog1;
	TToolButton *tbSeperator;
	TToolButton *tbAnimate;
	TToolButton *tbFontTest;
	TToolButton *tbViewFont;
	TMenuItem *CursorMenu;
	TMenuItem *SetHotSpot1;
	TMenuItem *HotSpot001;
	TMenuItem *HotSpot881;
	TMenuItem *EGAView1;
	TMenuItem *VGAView1;
	TMenuItem *N128CharFont1;
	TMenuItem *N256CharFont1;
	TMenuItem *N3ColourCursor1;
	TMenuItem *N4ColourCursor1;
	TPanel *pnVGAPal;
	TSpeedButton *SpeedButton1;
	TCheckBox *cbEmbedPalette;
	void __fastcall pnToolsDockDrop(TObject *Sender, TDragDockObject *Source,
          int X, int Y);
	void __fastcall udLoopCelClick(TObject *Sender, TUDBtnType Button);
	void __fastcall pbSurfacePaint(TObject *Sender);
	void __fastcall pbSurfaceMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall pbSurfaceMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
	void __fastcall pbSurfaceMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall WindowsBitmap1Click(TObject *Sender);
	void __fastcall ExportCelsToBitmapBMP1Click(TObject *Sender);
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall SaveAs1Click(TObject *Sender);
	void __fastcall SaveToGame1Click(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall Undo1Click(TObject *Sender);
	void __fastcall Redo1Click(TObject *Sender);
	void __fastcall Cut1Click(TObject *Sender);
	void __fastcall Copy1Click(TObject *Sender);
	void __fastcall Paste1Click(TObject *Sender);
	void __fastcall Clear1Click(TObject *Sender);
	void __fastcall Horizontally1Click(TObject *Sender);
	void __fastcall Vertically1Click(TObject *Sender);
	void __fastcall Invert1Click(TObject *Sender);
	void __fastcall GreyScale1Click(TObject *Sender);
	void __fastcall Up1Click(TObject *Sender);
	void __fastcall Down1Click(TObject *Sender);
	void __fastcall Left1Click(TObject *Sender);
	void __fastcall Right1Click(TObject *Sender);
	void __fastcall Zoom1Click(TObject *Sender);
	void __fastcall ZoomIn1Click(TObject *Sender);
	void __fastcall ZoomOut1Click(TObject *Sender);
	void __fastcall sbSwapColsClick(TObject *Sender);
	void __fastcall tmrSelCelTimer(TObject *Sender);
	void __fastcall sbrCelsChange(TObject *Sender);
	void __fastcall imCelsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall sbToolsClick(TObject *Sender);
	void __fastcall BrushStyle1Click(TObject *Sender);
	void __fastcall PenSize1Click(TObject *Sender);
	void __fastcall PenStyle1Click(TObject *Sender);
	void __fastcall sbPenWidthClick(TObject *Sender);
	void __fastcall sbPenStyleClick(TObject *Sender);
	void __fastcall sbBrushStyleClick(TObject *Sender);
	void __fastcall imPalMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall btnTColClick(TObject *Sender);
	void __fastcall cbLoopMirrorChange(TObject *Sender);
	void __fastcall edWidthExit(TObject *Sender);
	void __fastcall edWidthKeyPress(TObject *Sender, char &Key);
	void __fastcall edHeightExit(TObject *Sender);
	void __fastcall edXExit(TObject *Sender);
	void __fastcall edYExit(TObject *Sender);
	void __fastcall tmrSelectionTimer(TObject *Sender);
	void __fastcall pnToolsDockOver(TObject *Sender, TDragDockObject *Source,
          int X, int Y, TDragState State, bool &Accept);
	void __fastcall pnCoordsEndDock(TObject *Sender, TObject *Target, int X,
          int Y);
	void __fastcall ddLoopClick(TObject *Sender);
	void __fastcall ddCelClick(TObject *Sender);
	void __fastcall AddToEndCel1Click(TObject *Sender);
	void __fastcall AppendCel1Click(TObject *Sender);
	void __fastcall InsertCel1Click(TObject *Sender);
	void __fastcall AddToEndLoop1Click(TObject *Sender);
	void __fastcall AppendLoop1Click(TObject *Sender);
	void __fastcall InsertLoop1Click(TObject *Sender);
	void __fastcall DeleteLoop1Click(TObject *Sender);
	void __fastcall DeleteCel1Click(TObject *Sender);
	void __fastcall udCharClick(TObject *Sender, TUDBtnType Button);
	void __fastcall edChWidthExit(TObject *Sender);
	void __fastcall edChHeightExit(TObject *Sender);
	void __fastcall edFnHeightExit(TObject *Sender);
	void __fastcall imCharsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall sbrCharsChange(TObject *Sender);
	void __fastcall tmrSelCharTimer(TObject *Sender);
	void __fastcall Panel6Resize(TObject *Sender);
	void __fastcall Animator1Click(TObject *Sender);
	void __fastcall ViewFontTable1Click(TObject *Sender);
	void __fastcall FontTester1Click(TObject *Sender);
	void __fastcall Shift1Click(TObject *Sender);
	void __fastcall DrawingTools1Click(TObject *Sender);
	void __fastcall ColourSelection1Click(TObject *Sender);
	void __fastcall Coords1Click(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ScrollBox1Click(TObject *Sender);
	void __fastcall HotSpot001Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall EGAView1Click(TObject *Sender);
	void __fastcall VGAView1Click(TObject *Sender);
	void __fastcall N128CharFont1Click(TObject *Sender);
	void __fastcall N256CharFont1Click(TObject *Sender);
	void __fastcall N3ColourCursor1Click(TObject *Sender);
	void __fastcall N4ColourCursor1Click(TObject *Sender);
	void __fastcall cbEmbedPaletteClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TWndGfxEdit(TComponent* Owner);

    BOOL InitEditor(EDTWND *_edtWnd, U8 *resBuf, S16 resVer);

    void SetUpNew();

    int resType,resVer;

    BOOL SaveRes();
    BOOL LoadRes(U8 *buf, U32 len);  
    BOOL CloseRes();

    BOOL UpdateRes();
    BOOL NewRes(int Type, int Depth);
    BOOL NewView();
    BOOL NewFont();
    BOOL NewCursor();

    void ChangeLoopCel(int lNum, int cNum, BOOL SELO);
    void SetUpCelsSelector();
	void __fastcall DrawCelSelImg(BOOL FIX_UP);
    void __fastcall SetUpSelection(int dnX, int dnY, int upX, int upY);

    edUNDO* AddUndo(AnsiString desc);
    void DeleteUndo(edUNDO* undo);
    void SetUndo(edUNDO *u);
    edUNDO* GetUndo(int i);
    void DoRedo();
    void DoUndo();
    void UpdateUndos();
    void InitUndos();
    void ClearUndos();
    void ClearRedos();

    void SetBits(U8 *bits,int width,int height);
    void SaveBits();
    void StoreBits();

    void ResizeCel(sciVIEWCEL *cel, int nWidth, int nHeight);
    void ResizeChar(sciFONTCHAR *fontChar, int nWidth, int nHeight);

    void __fastcall CancelSelection();
	void __fastcall SetSelection();
                                           
	void DrawSelsCel();

    void ChangeCursor();

    void ChangeChar(int cNum, BOOL SELO);
    void SetUpCharsSelector();
    void __fastcall DrawCharSelImg(BOOL FIX_UP);
    void DrawSelsChar();

    void __fastcall PaintSurface();

    void __fastcall DropImage(Graphics::TBitmap *pBitmap);

    void UpdatePalette(int w, int h);

    Graphics::TBitmap *bmSurface,*bmSavedSurface,*bmSelection;

	edUNDO *firstUndo,*lastUndo;
    int undoTotal,undoPtr,undoXOX,undoYOY;
    int AskSave;

	EDITORTAG edTag;

    int shiftMode;

    BOOL DRAW_SELECTY;

    sciVIEW *view;
    sciFONT *font;
    sciCURSOR *cursor;

    U8 *acBits;
    int acWidth,acHeight;

    float drawPercent;
    int chimH,climW;

    tPAL *pal;

    int curLoop,curCel;
    sciVIEWCEL *cel;
    sciVIEWLOOP *loop,*loopReal;
    sciFONTCHAR *fChar;

    BOOL MIRRORING,DRAG_IN_SELECTION,RESIZE_SELECTION;
    #define SELECTION_ACTIVE tmrSelection->Enabled
    TRect SelRect,SelBounds,SelCutRect;

    int zoomLv;
    int canvasRz,CANVAS_RESIZING,rzWidth,rzHeight;

    Graphics::TBitmap *bmRz;

    TToolButton *tbCurTool;
    int curTool,lastTool;

    int dnX,upX,mvX,dnY,upY,mvY;

    TRect celsRect,fCharsRect;

    int aniSpeed;  // view animator delay

    void DisableInterface();
	void EnableInterface();

    TColor c1,c2;

    BOOL CAN_DRAW,MOUSE_DOWN;

    int newCount;

    int maxUndos;
};
//---------------------------------------------------------------------------
extern PACKAGE TWndGfxEdit *WndGfxEdit;
//---------------------------------------------------------------------------
#endif
