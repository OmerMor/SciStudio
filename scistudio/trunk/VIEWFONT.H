//---------------------------------------------------------------------------

#ifndef viewfontH
#define viewfontH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TDlgViewFont : public TForm
{
__published:	// IDE-managed Components
	TScrollBox *scrFont;
	TImage *imgFont;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgViewFont(TComponent* Owner);

    sciFONT *f;
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgViewFont *DlgViewFont;
//---------------------------------------------------------------------------
#endif
