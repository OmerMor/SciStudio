//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "welcome.h"
#include "config.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgWelcome *DlgWelcome;
//---------------------------------------------------------------------------
__fastcall TDlgWelcome::TDlgWelcome(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TDlgWelcome::Button2Click(TObject *Sender)
{
	if(PageControl1->ActivePage==TabSheet1) {
        	PageControl1->ActivePage = TabSheet2;
    } else if(PageControl1->ActivePage==TabSheet2) {
        	PageControl1->ActivePage = TabSheet3;
    } else if(PageControl1->ActivePage==TabSheet3) {
        	PageControl1->ActivePage = TabSheet5;
    } else if(PageControl1->ActivePage==TabSheet5) {
        	PageControl1->ActivePage = TabSheet4;
            Button2->Enabled = FALSE;
            Button1->Enabled = TRUE;
    }
}
//---------------------------------------------------------------------------

void __fastcall TDlgWelcome::Label7Click(TObject *Sender)
{
    ShellExecute(Handle, 0, "http://scistudio.sf.net/", 0, 0, SW_NORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TDlgWelcome::Button1Click(TObject *Sender)
{
	config.SHOW_WELCOME = FALSE;
	Close();	
}
//---------------------------------------------------------------------------
