//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "wait.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgWait *DlgWait;
//---------------------------------------------------------------------------
__fastcall TDlgWait::TDlgWait(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDlgWait::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;	
}
//---------------------------------------------------------------------------
