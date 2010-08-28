//---------------------------------------------------------------------------

#ifndef newroomH
#define newroomH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "scihdr.h"
#include "scriptedit.h"
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
class TDlgNewRoom : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit1;
	TCheckListBox *CheckListBox1;
	TGroupBox *GroupBox1;
	TEdit *Edit2;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TEdit *Edit3;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall RadioButton2Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgNewRoom(TComponent* Owner);
    void __fastcall FindSCOs();
    void __fastcall SetItUp(TWndScriptEdit *aScrEdit, AnsiString aDir);
    TWndScriptEdit *ScrEdit;
    AnsiString Dir;
    int SCOFileCount;
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgNewRoom *DlgNewRoom;
//---------------------------------------------------------------------------
#endif
 