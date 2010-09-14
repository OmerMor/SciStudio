//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
                   
#include "about.h"
#include "scihdr.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgAbout *DlgAbout;
//---------------------------------------------------------------------------
__fastcall TDlgAbout::TDlgAbout(TComponent* Owner)
	: TForm(Owner)
{          
    Label2->Caption = AnsiString(Program.name);
    Label3->Caption = "Version "+AnsiString(Program.version)+"   "+AnsiString(Program.buildDate);

    Memo1->Lines->Add((AnsiString)"This program is FREEWARE. You are encouraged to share it with everyone and use it for free forever. However, you can not sell it, not even for the cost of the disks! It comes with no warranty!");
    Memo1->Lines->Add((AnsiString)"");
    Memo1->Lines->Add((AnsiString)"Special Thanks to...");
    Memo1->Lines->Add((AnsiString)"...Yannick Bertrand, Ravi Iyengar, Carl Muckenhoupt, Christoph Reichenbach, Lars Skovlund and Rink Springer for all the help they have given me with SCI resource decoding.");
    Memo1->Lines->Add((AnsiString)"...Ravi Iyengar and Juha Terho for proof reading the tutorial.");
    Memo1->Lines->Add((AnsiString)"...The Beta Testers: Ravi Iyengar, Matt Hargett.");

    ::SetFocus(OKBtn->Handle);

    b = new Graphics::TBitmap;
    b->Width = 40;
    b->Height = 24;
}
//---------------------------------------------------------------------------

void __fastcall TDlgAbout::OKBtnClick(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------
void __fastcall TDlgAbout::Label8Click(TObject *Sender)
{
    ShellExecute(Handle, 0, "http://www.bripro.com/scistudio", 0, 0, SW_NORMAL);
}
//---------------------------------------------------------------------------
void __fastcall TDlgAbout::FormClose(TObject *Sender, TCloseAction &Action)
{          
	delete b;
    Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TDlgAbout::Timer1Timer(TObject *Sender)
{
    if(f==7) {
    	Timer1->Enabled = FALSE;
    }
	ImageList1->Draw(b->Canvas,0,0,f<4?f:7-f,TRUE);
	f++;
    Image3->Canvas->Draw(0,0,b);
}
//---------------------------------------------------------------------------
void __fastcall TDlgAbout::Image3Click(TObject *Sender)
{
	f=0;
	Timer1->Enabled = TRUE;
}
//---------------------------------------------------------------------------



