//---------------------------------------------------------------------------

#ifndef printprevH
#define printprevH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SynEditPrintPreview.hpp"
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TDlgPrintPrev : public TForm
{
__published:	// IDE-managed Components
	TSynEditPrintPreview *SynEditPrintPreview1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton4;
	TToolButton *BtnFirst;
	TToolButton *ToolButton9;
	TToolButton *BtnPrev;
	TToolButton *ToolButton10;
	TToolButton *BtnNext;
	TToolButton *ToolButton11;
	TToolButton *BtnLast;
	TToolButton *ToolButton3;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TToolButton *ToolButton2;
	TStatusBar *StatusBar1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall BtnFirstClick(TObject *Sender);
	void __fastcall BtnPrevClick(TObject *Sender);
	void __fastcall BtnNextClick(TObject *Sender);
	void __fastcall BtnLastClick(TObject *Sender);
	void __fastcall ToolButton5Click(TObject *Sender);
	void __fastcall ToolButton6Click(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgPrintPrev(TComponent* Owner);
    void __fastcall UpdateUI();
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgPrintPrev *DlgPrintPrev;
//---------------------------------------------------------------------------
#endif
