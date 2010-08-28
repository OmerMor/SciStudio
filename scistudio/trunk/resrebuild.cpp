//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "resrebuild.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGAUGES"
#pragma link "piereg"
#pragma resource "*.dfm"
TDlgResRebuild *DlgResRebuild;
//---------------------------------------------------------------------------
__fastcall TDlgResRebuild::TDlgResRebuild(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDlgResRebuild::FormClose(TObject *Sender, TCloseAction &Action)
{
    Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TDlgResRebuild::FormActivate(TObject *Sender)
{
    Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TDlgResRebuild::OKButtonClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

