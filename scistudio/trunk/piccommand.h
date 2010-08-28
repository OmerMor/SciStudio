//---------------------------------------------------------------------------

#ifndef piccommandH
#define piccommandH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TDlgPicCommand : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TPanel *Panel1;
	TPanel *Panel2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TListBox *ListBox;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ListBoxClick(TObject *Sender);
	void __fastcall ListBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgPicCommand(TComponent* Owner);

    TWndPicEdit *PicWin;
    long offset;
    int selIndex;
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgPicCommand *DlgPicCommand;
//---------------------------------------------------------------------------
#endif
