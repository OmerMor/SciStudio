//---------------------------------------------------------------------------

#ifndef splashH
#define splashH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TDlgSplash : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgSplash(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgSplash *DlgSplash;
//---------------------------------------------------------------------------
#endif
