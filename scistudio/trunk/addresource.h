//---------------------------------------------------------------------------

#ifndef addresourceH
#define addresourceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TDlgAddResource : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label2;
	TLabel *Label1;
	TLabel *ResourceName;
	TButton *ButtonOK1;
	TButton *ButtonCancel1;
	TEdit *PackageEdit;
	TEdit *NumberEdit;
	TLabel *Label3;
	TUpDown *UpDown1;
	TUpDown *UpDown2;
	void __fastcall ButtonCancel1Click(TObject *Sender);
	void __fastcall ButtonOK1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall NumberEditChange(TObject *Sender);
	void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
	void __fastcall UpDown2Click(TObject *Sender, TUDBtnType Button);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgAddResource(TComponent* Owner);

    AnsiString ResourceType;
	AnsiString aszTemp;
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgAddResource *DlgAddResource;
//---------------------------------------------------------------------------
#endif
