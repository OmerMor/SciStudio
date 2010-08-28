//---------------------------------------------------------------------------

#ifndef piceditH
#define piceditH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MenuBar.hpp"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp> 
#include <ExtDlgs.hpp>

#include "scihdr.h"  
#include "picrender.h"
#include <Graphics.hpp>
//---------------------------------------------------------------------------
#define PTOOL_OFF			0
#define PTOOL_LINE			1
#define PTOOL_SHORTLINE		2
#define PTOOL_TINYLINE		3
#define PTOOL_FILL			4
#define PTOOL_ABSPEN		5
#define PTOOL_NEARPEN		6
#define PTOOL_CLSPEN		7

#define PTOOL_ZOOM			8  

#define PTOOL_RECTANGLE		9
#define PTOOL_ELLIPSE		10
#define PTOOL_CHANGEBMP		11
#define PTOOL_SETPRI		12

#define TOTAL_PIC_TOOLS		13
//---------------------------------------------------------------------------
class TWndPicEdit : public TForm
{
__published:	// IDE-managed Components
	TCoolBar *CoolBar1;
	TMenuBar *MenuBar1;
	TToolBar *ToolBar1;
	TToolButton *sbNew;
	TToolButton *sbOpen;
	TToolButton *sbSave;
	TToolButton *sbLoadBackground;
	TToolButton *ToolButton8;
	TToolButton *sbCopy;
	TToolButton *sbPasteBackground;
	TToolBar *ToolBar4;
	TToolButton *sbOff;
	TToolButton *sbLine12;
	TToolButton *sbLine7;
	TToolButton *sbLine3;
	TToolButton *sbFill;
	TToolButton *sbPenAbs;
	TToolButton *sbPenClose;
	TPanel *Panel2;
	TLabel *Label1;
	TBevel *Bevel8;
	TLabel *Label3;
	TToolBar *ToolBar5;
	TToolButton *tbVisual;
	TToolButton *tbPriority;
	TToolButton *tbControl;
	TToolBar *ToolBar6;
	TToolButton *tbPal0;
	TToolButton *tbPal1;
	TToolButton *tbPal2;
	TToolButton *tbPal3;
	TToolBar *ToolBar2;
	TScrollBox *ScrollBox1;
	TPaintBox *pbSurface;
	TPanel *pnPicBar;
	TPanel *Panel4;
	TSpeedButton *SpeedButton8;
	TSpeedButton *SpeedButton9;
	TPanel *Panel5;
	TImage *ImgData;
	TPanel *Panel6;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton11;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TPanel *Panel7;
	TSpeedButton *sbPattern;
	TSpeedButton *sbSolid;
	TBevel *Bevel3;
	TSpeedButton *sbSquare;
	TSpeedButton *sbCircle;
	TBevel *Bevel2;
	TSpeedButton *sbVis;
	TSpeedButton *sbPri;
	TSpeedButton *sbCtl;
	TBevel *Bevel4;
	TLabel *XLabel;
	TLabel *YLabel;
	TBevel *Bevel5;
	TLabel *PriLabel1;
	TBevel *Bevel6;
	TLabel *ColLabel1;
	TBevel *Bevel1;
	TImage *imCol;
	TLabel *AngleLabel;
	TBevel *Bevel7;
	TPanel *Panel8;
	TLabel *PenSizeE;
	TUpDown *UpDown1;
	TPanel *Panel3;
	TSpeedButton *SpeedButton3;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *New1;
	TMenuItem *Open1;
	TMenuItem *Save1;
	TMenuItem *SaveAs1;
	TMenuItem *SaveToGame1;
	TMenuItem *N1;
	TMenuItem *Close1;
	TMenuItem *Edit1;
	TMenuItem *CommandHistory1;
	TMenuItem *N2;
	TMenuItem *Copy1;
	TMenuItem *PasteTracingImage1;
	TMenuItem *Background1;
	TMenuItem *LoadTracingImage1;
	TMenuItem *N4;
	TMenuItem *ShowTracingImage1;
	TMenuItem *ShowPriorityBars1;
	TMenuItem *Zoom1;
	TMenuItem *NormalViewing1;
	TMenuItem *N5;
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
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
	TToolButton *ToolButton1;
	TToolButton *tbTracingBitmap;
	TToolButton *tbPriLines;
	TToolButton *ToolButton4;
	TOpenPictureDialog *BGOpenDialog;
	TToolButton *sbPenNear;
	TShape *shCol;
	TLabel *ColLabel;
	TShape *shPri;
	TLabel *PriLabel;
	TImage *imNoCol;
	TToolBar *ToolBar3;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TToolButton *ToolButton9;
	void __fastcall New1Click(TObject *Sender);
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall SaveAs1Click(TObject *Sender);
	void __fastcall SaveToGame1Click(TObject *Sender);
	void __fastcall Close1Click(TObject *Sender);
	void __fastcall CommandHistory1Click(TObject *Sender);
	void __fastcall Copy1Click(TObject *Sender);
	void __fastcall PasteTracingImage1Click(TObject *Sender);
	void __fastcall LoadTracingImage1Click(TObject *Sender);
	void __fastcall ShowTracingImage1Click(TObject *Sender);
	void __fastcall ShowPriorityBars1Click(TObject *Sender);
	void __fastcall ZoomIn1Click(TObject *Sender);
	void __fastcall ZoomOut1Click(TObject *Sender);
	void __fastcall ShapeSelectClick(TObject *Sender);
	void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton11Click(TObject *Sender);
	void __fastcall SpeedButton10Click(TObject *Sender);
	void __fastcall SpeedButton9Click(TObject *Sender);
	void __fastcall SpeedButton8Click(TObject *Sender);
	void __fastcall ToolClick(TObject *Sender);
	void __fastcall ScreenClick(TObject *Sender);
	void __fastcall PaletteClick(TObject *Sender);
	void __fastcall pbSurfaceMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall pbSurfaceMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
	void __fastcall pbSurfaceMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall pbSurfacePaint(TObject *Sender);
	void __fastcall ZoomClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall sbVisClick(TObject *Sender);
	void __fastcall sbPriClick(TObject *Sender);
	void __fastcall sbCtlClick(TObject *Sender);
	void __fastcall ScrollBox1Resize(TObject *Sender);
	void __fastcall pnPicBarResize(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ToolButton2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TWndPicEdit(TComponent* Owner);

    BOOL InitEditor(EDTWND *_edtWnd, U8 *resBuf, S16 resVer);
	EDITORTAG edTag;

    int picType;

	BOOL SavePic();
	BOOL LoadPic(U8 *buf, U32 len);
	BOOL UpdatePic();
	BOOL ClosePic();
	BOOL NewPic();     

    void __fastcall AssignBack(Graphics::TBitmap *TempBit);
	void __fastcall DrawActiveScreen(BOOL FULL);

    void __fastcall AddCode(U8 code);
	void __fastcall AddCoords(S16 x, S16 y);
	void __fastcall AddRel8Coords(S16 x1, S16 y1, S16 x2, S16 y2);
	void __fastcall AddRel4Coords(S16 x1, S16 y1, S16 x2, S16 y2);
	void __fastcall FixCoords8Bit(int *x, int *y);
	void __fastcall FixCoords4Bit(int *x, int *y);
    void __fastcall DeleteCode(U16 position);
    void __fastcall CropCode(U16 position);
    void __fastcall SkipTo(U16 position);

    void __fastcall DoAngleThing(int *_x, int *_y, BOOL LOCK);
    void __fastcall FillListView(TListBox *lb, WORD o);
    void __fastcall GetColour(int scr, sciPIC *pic);
    void __fastcall UpdateDataEdit();
    void __fastcall DrawColour(int scr);
	void __fastcall WritePattern();
    void FixUpSurface();
    void __fastcall DrawSurface();

    void BitsLine(int x1, int y1, int x2, int y2, U8 *b, U8 c);

    sciPIC *pic;

    int dnX,dnY,mvX,mvY,upX,upY;

    int activeScreen,activePalette;
    BOOL PICBMP;

    int zoomLevel;
    int FromTop,FromLeft,nDestHeight,nDestWidth,nSrcHeight,nSrcWidth;

    int drawingCursor;
    int drawingTool; // the tool which the user has drawn with and still is drawing with for appending codes

    TToolButton *tbCurTool;
    int curTool,lastTool;

    tPAL *pal;


    BOOL BACK_LOADED, PIC_LOADED;

	HBITMAP PicBitmap, BackBitmap;
	U8 PicBitmapBits[sPIC_SIZE*sizeof(long)],TempBitmapBits[sPIC_SIZE*sizeof(long)],TempBitmapBits2[sPIC_SIZE*sizeof(long)],BackBitmapBits[sPIC_SIZE*sizeof(long)];
	BITMAPINFO binfo;

    U16 oldPicLen;

    sPOINT lastPoint;

    int paramCount;

    int Angle,settingPri;
    BOOL CAN_DRAW,MOUSE_DOWN;
    int newCount;
};
//---------------------------------------------------------------------------
extern PACKAGE TWndPicEdit *WndPicEdit;
//---------------------------------------------------------------------------
#endif
