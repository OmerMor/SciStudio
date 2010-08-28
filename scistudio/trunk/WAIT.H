//---------------------------------------------------------------------------

#ifndef waitH
#define waitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TDlgWait : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TProgressBar *ProgressBar;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgWait(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgWait *DlgWait;
//---------------------------------------------------------------------------
#endif
