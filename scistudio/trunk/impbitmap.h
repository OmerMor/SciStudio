//---------------------------------------------------------------------------

#ifndef impbitmapH
#define impbitmapH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TDlgImpBitmap : public TForm
{
__published:	// IDE-managed Components
	TToolBar *ToolBar3;
	TToolButton *ToolButton6;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton5;
	TBevel *Bevel1;
	TButton *Button1;
	TButton *Button2;
	TImage *Image1;
	TOpenPictureDialog *BGOpenDialog;
	TStatusBar *StatusBar;
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ToolButton5Click(TObject *Sender);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall StatusBarDrawPanel(TStatusBar *StatusBar,
          TStatusPanel *Panel, const TRect &Rect);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgImpBitmap(TComponent* Owner);
    void __fastcall SetBitmap();
    void __fastcall SetCoords();
    TWndPicEdit *wndPic;
    Graphics::TBitmap *pBmp,*dBmp;
    RECT rcBmp;
    U8 bMask[sPIC_SIZE];
    int dnX,dnY,mvX,mvY;
    BOOL DRAGGING;
    
    int maxCols;
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgImpBitmap *DlgImpBitmap;
//---------------------------------------------------------------------------
#endif
