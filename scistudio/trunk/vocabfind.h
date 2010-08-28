//---------------------------------------------------------------------------

#ifndef vocabfindH
#define vocabfindH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TDlgVocabFind : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar1;
	TBitBtn *BtnOK;
	TBitBtn *BtnGoto;
	TBitBtn *BtnCancel;
	TBitBtn *BtnFind;
	TEdit *Edit1;
	void __fastcall BtnFindClick(TObject *Sender);
	void __fastcall BtnOKClick(TObject *Sender);
	void __fastcall BtnGotoClick(TObject *Sender);
	void __fastcall BtnCancelClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgVocabFind(TComponent* Owner);
    void __fastcall ResetFind();

    TWndVocabEdit *aWndVocabEdit;
    signed long Group;
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgVocabFind *DlgVocabFind;
//---------------------------------------------------------------------------
#endif
 