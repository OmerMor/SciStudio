//---------------------------------------------------------------------------

#ifndef newgameH
#define newgameH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TDlgNewGame : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *edName;
	TLabel *Label2;
	TEdit *edPath;
	TButton *Button1;
	TImage *Image1;
	TButton *Button2;
	TButton *Button3;
	TRadioButton *rbEmpty;
	TRadioButton *rbTemplate;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgNewGame(TComponent* Owner);
    BOOL __fastcall ParseCreate();
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgNewGame *DlgNewGame;
//---------------------------------------------------------------------------
#endif
