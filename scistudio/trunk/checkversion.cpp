//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "checkversion.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgCheckVersion *DlgCheckVersion;
//---------------------------------------------------------------------------
__fastcall TDlgCheckVersion::TDlgCheckVersion(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TDlgCheckVersion::Animate()
{
	Graphics::TBitmap *b = new Graphics::TBitmap;
    b->Assign(Image1->Picture->Bitmap);
    b->Canvas->CopyRect(
    	Rect(8,0,b->Width,8),
        Image1->Picture->Bitmap->Canvas,
    	Rect(0,0,b->Width-8,8)
    );
    b->Canvas->CopyRect(
    	Rect(0,0,8,8),
        Image1->Picture->Bitmap->Canvas,
    	Rect(b->Width-8,0,b->Width,8)
    );
    Image1->Picture->Bitmap->Assign(b);
    delete b;
	Image1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TDlgCheckVersion::Button1Click(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------
void __fastcall TDlgCheckVersion::Label1Click(TObject *Sender)
{
    ShellExecute(Handle, 0, "http://scistudio.sf.net/", 0, 0, SW_NORMAL);
}
//---------------------------------------------------------------------------
void __fastcall TDlgCheckVersion::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TDlgCheckVersion::Label2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    ReleaseCapture();
    SendMessage(Handle, WM_SYSCOMMAND, 61458, 0);
}
//---------------------------------------------------------------------------


