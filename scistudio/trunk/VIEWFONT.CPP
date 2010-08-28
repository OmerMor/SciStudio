//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
                  
#include "main.h"
#include "ssresdecode.h"
#include "viewedit.h"
#include "gfxedits.h"
#include "viewfont.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgViewFont *DlgViewFont;
//---------------------------------------------------------------------------
__fastcall TDlgViewFont::TDlgViewFont(TComponent* Owner)
	: TForm(Owner)
{
	TWndGfxEdit *w = (TWndGfxEdit*)Owner;
    f = w->font;
    FormResize(this);
}
//---------------------------------------------------------------------------

void __fastcall TDlgViewFont::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TDlgViewFont::FormResize(TObject *Sender)
{
	imgFont->Width = (scrFont->Width-20);
 	if(imgFont->Width<1) imgFont->Width = 16;
	FontDrawImage(imgFont,f);
}
//---------------------------------------------------------------------------
