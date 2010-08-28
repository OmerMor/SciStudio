//---------------------------------------------------------------------------

#ifndef aboutH
#define aboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TDlgAbout : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TBevel *Bevel2;
	TLabel *Label6;
	TLabel *Label8;
	TLabel *Label7;
	TLabel *Label12;
	TLabel *Label10;
	TLabel *Label11;
	TImage *Image2;
	TLabel *Label1;
	TMemo *Memo1;
	TButton *OKBtn;
	TMemo *Memo2;
	TMemo *Memo3;
	TImageList *ImageList1;
	TTimer *Timer1;
	TImage *Image3;
	TImage *Image4;
	void __fastcall OKBtnClick(TObject *Sender);
	void __fastcall Label8Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgAbout(TComponent* Owner);

    int f;
    Graphics::TBitmap *b;
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgAbout *DlgAbout;
//---------------------------------------------------------------------------
#endif
