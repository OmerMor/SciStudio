//---------------------------------------------------------------------------

#ifndef addwordH
#define addwordH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TDlgAddWord : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label1;
	TEdit *Edit1;
	TLabel *Label2;
	TComboBox *ComboBox1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgAddWord(TComponent* Owner);
    TWndVocabEdit *wndVoc;
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgAddWord *DlgAddWord;
//---------------------------------------------------------------------------
#endif
