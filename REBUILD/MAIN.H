//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TButton *Button1;
	TButton *Button2;
	TEdit *Edit1;
	TLabel *Label1;
	TCheckBox *CheckBox1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TCheckBox *CheckBox2;
	TLabel *Label6;
	TEdit *Edit2;
	TButton *Button5;
	TButton *Button4;
	TOpenDialog *OpenDialog1;
	TOpenDialog *OpenDialog2;
	TPanel *Panel1;
	TLabel *Label7;
	TLabel *Label8;
	TButton *Button3;
	TListBox *ListBox1;
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
