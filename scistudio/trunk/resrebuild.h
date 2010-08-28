//---------------------------------------------------------------------------

#ifndef DlgResRebuildH
#define DlgResRebuildH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CGAUGES.h"
#include "piereg.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TDlgResRebuild : public TForm
{
__published:	// IDE-managed Components
	TLabel *Status;
	TPanel *Panel1;
	TCGauge *ProgressGauge;
	TButton *OKButton;
	TPanel *pnlClient;
	TShape *Shape1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TShape *Shape2;
	TPie *Pie4;
	TPie *Pie3;
	TPie *Pie2;
	TPie *Pie1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall OKButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgResRebuild(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgResRebuild *DlgResRebuild;
//---------------------------------------------------------------------------
#endif
