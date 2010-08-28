//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "addresource.h"
#include "explorer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgAddResource *DlgAddResource; 
//---------------------------------------------------------------------------
__fastcall TDlgAddResource::TDlgAddResource(TComponent* Owner)
	: TForm(Owner)
{
	WndExplorer->dlgCANCLOSE = TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TDlgAddResource::ButtonCancel1Click(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------
void __fastcall TDlgAddResource::ButtonOK1Click(TObject *Sender)
{
    // If they are, it is okay to close
    WndExplorer->adrsPackage = StrToInt(PackageEdit->Text);
    WndExplorer->adrsNumber = StrToInt(NumberEdit->Text);

	WndExplorer->dlgCANCLOSE = FALSE;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TDlgAddResource::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TDlgAddResource::NumberEditChange(TObject *Sender)
{                               
    // Make sure the values are in range

	if(CheckStringNum(NumberEdit->Text.c_str())&&(StrToInt(NumberEdit->Text) >= 0) && (StrToInt(NumberEdit->Text) <= 999)) {
		aszTemp.sprintf("Name of Resource: %s.%03d", ResourceType.c_str(), StrToInt(NumberEdit->Text));
    	ButtonOK1->Enabled = TRUE;
    	ResourceName->Caption = aszTemp;
    } else {
		ShowMessage("Please specify a resource number between 0 and 999.");
        aszTemp.sprintf("Name of Resource: <INVALID>");
    	ButtonOK1->Enabled = FALSE;
    	ResourceName->Caption = aszTemp;
        return;
    }
    if(CheckStringNum(PackageEdit->Text.c_str())&&(StrToInt(PackageEdit->Text) >= 1) && (StrToInt(PackageEdit->Text) <= 63)) {
        aszTemp.sprintf("Name of Package: resource.%03d", StrToInt(PackageEdit->Text));
     	Label3->Caption = aszTemp;
    	ButtonOK1->Enabled = TRUE;
    } else {
        ShowMessage("Please specify a resource package between 1 and 63.");
        aszTemp.sprintf("Name of Package: <INVALID>");
     	Label3->Caption = aszTemp;
		ButtonOK1->Enabled = FALSE;
    }
}
//---------------------------------------------------------------------------


void __fastcall TDlgAddResource::UpDown1Click(TObject *Sender,
      TUDBtnType Button)
{
    if((Button == Comctrls::btPrev) && (StrToInt(PackageEdit->Text) > 1))
        PackageEdit->Text = IntToStr(StrToInt(PackageEdit->Text)-1);
    else if((Button == Comctrls::btNext) && (StrToInt(PackageEdit->Text) < 63))
        PackageEdit->Text = IntToStr(StrToInt(PackageEdit->Text)+1);
}
//---------------------------------------------------------------------------

void __fastcall TDlgAddResource::UpDown2Click(TObject *Sender,
      TUDBtnType Button)
{
    if((Button == Comctrls::btPrev) && (StrToInt(NumberEdit->Text) > 0))
        NumberEdit->Text = IntToStr(StrToInt(NumberEdit->Text)-1);
    else if((Button == Comctrls::btNext) && (StrToInt(NumberEdit->Text) < 999))
        NumberEdit->Text = IntToStr(StrToInt(NumberEdit->Text)+1);
}
//---------------------------------------------------------------------------

