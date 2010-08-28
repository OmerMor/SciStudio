//---------------------------------------------------------------------------

#ifndef welcomeH
#define welcomeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TDlgWelcome : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TPanel *Panel1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TTabSheet *TabSheet3;
	TLabel *Label7;
	TLabel *Label8;
	TTabSheet *TabSheet4;
	TLabel *Label9;
	TLabel *Label10;
	TTabSheet *TabSheet5;
	TLabel *Label11;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label12;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Label7Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgWelcome(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgWelcome *DlgWelcome;
//---------------------------------------------------------------------------
#endif
