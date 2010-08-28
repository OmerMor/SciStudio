//---------------------------------------------------------------------------

#ifndef checkversionH
#define checkversionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TDlgCheckVersion : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label3;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Button1;
	TImage *Image1;
	TLabel *Label4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Label1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Label2MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgCheckVersion(TComponent* Owner);

    void __fastcall Animate();
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgCheckVersion *DlgCheckVersion;
//---------------------------------------------------------------------------
#endif
