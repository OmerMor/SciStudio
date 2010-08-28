//---------------------------------------------------------------------------

#ifndef expcelsH
#define expcelsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>   
#include "ssresdecode.h"
#include "viewedit.h"
#include "gfxedits.h"
//---------------------------------------------------------------------------
class TDlgExpCels : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label2;
	TButton *Button1;
	TButton *Button2;
	TScrollBox *ScrollBox1;
	TImage *Image1;
	TEdit *ebSpacing;
	TRadioButton *rbCurrentLoop;
	TRadioButton *rbAllLoops;
	TSaveDialog *SaveDialog;
	void __fastcall rbAllLoopsClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgExpCels(TComponent* Owner, sciVIEW *view, int loopNum);

    void __fastcall DrawBitmap();
    sciVIEW *view;
	int loopNum;
    Graphics::TBitmap *b;
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgExpCels *DlgExpCels;
//---------------------------------------------------------------------------
#endif
