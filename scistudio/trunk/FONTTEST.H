//---------------------------------------------------------------------------

#ifndef fonttestH
#define fonttestH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TDlgFontTest : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape1;
	TSpeedButton *Button1;
	TImage *ImgEnter;
	TShape *Shape2;
	TImage *Image1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall Shape1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgFontTest(TComponent* Owner);   
    void Setup(sciFONT *F);

    sciFONT *Fnt;
    Graphics::TBitmap *EditBmp;
    int CharPos;
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgFontTest *DlgFontTest;
//---------------------------------------------------------------------------
#endif
