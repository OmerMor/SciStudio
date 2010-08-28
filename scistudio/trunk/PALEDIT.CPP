//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "scihdr.h"
#include "gfxedits.h"
#include "paledit.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWndPalEdit *WndPalEdit;
//---------------------------------------------------------------------------
__fastcall TWndPalEdit::TWndPalEdit(TComponent* Owner)
	: TForm(Owner)
{      
	OK_CLOSE = FALSE;
}
//---------------------------------------------------------------------------
void __fastcall TWndPalEdit::SetUp(sciPALETTE *p)
{
	memcpy(pal.cols,p->cols,sizeof(p->cols));
    pal.SET = p->SET;
    selCol = 0;
    DrawPalette();
    Timer1->Enabled = TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TWndPalEdit::DrawPalette()
{
	DrawPaletteAsBitmap(imPal->Picture->Bitmap,&pal,16,16,imPal->Width,imPal->Height, clBtnFace);
	Shape1->Brush->Color = (TColor)((pal.cols[selCol].red)|(pal.cols[selCol].green<<8)|(pal.cols[selCol].blue<<16));
    Shape2->Brush->Color = (TColor)(pal.cols[selCol].red);
    Label4->Caption = IntToStr(pal.cols[selCol].red);
    Shape3->Brush->Color = (TColor)(pal.cols[selCol].green<<8);
    Label5->Caption = IntToStr(pal.cols[selCol].green);
    Shape4->Brush->Color = (TColor)(pal.cols[selCol].blue<<16);
    Label6->Caption = IntToStr(pal.cols[selCol].blue);
    CheckBox1->Checked = pal.cols[selCol].infoBits;

    Label9->Caption = " Index: "+IntToStr(selCol)+"/255";

    colWidth	= imPal->Width/16;
    colHeight	= imPal->Height/16;
    selX = ((imPal->Width%16)>>1)+((selCol%16)*colWidth);
    selY = ((imPal->Height%16)>>1)+((selCol/16)*colHeight);

}
//---------------------------------------------------------------------------
void __fastcall TWndPalEdit::ToolButton1Click(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TWndPalEdit::ToolButton2Click(TObject *Sender)
{
//	
}
//---------------------------------------------------------------------------
void __fastcall TWndPalEdit::ToolButton3Click(TObject *Sender)
{
//	
}
//---------------------------------------------------------------------------
void __fastcall TWndPalEdit::imPalMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{                
	int colWidth,colHeight,spacingX;

    if(!Shift.Contains(ssLeft)) return;
    colWidth	= imPal->Width/16;
    colHeight	= imPal->Height/16;

    spacingX = 3;

    Y -= (imPal->Height%16)>>1;
    X -= (imPal->Width%16)>>1;
    int c = (Y/colHeight)*16+(X/colWidth);
    if((Y%colHeight)<(colHeight-spacingX)&&(X%colWidth)<(colWidth-spacingX)) {
   		selCol = c;
     	DrawPalette();
    }
}
//---------------------------------------------------------------------------
void __fastcall TWndPalEdit::Button1Click(TObject *Sender)
{
	if(ColorDialog1->Execute()) {
		pal.cols[selCol].red = ColorDialog1->Color&0xFF;
		pal.cols[selCol].green = (ColorDialog1->Color>>8)&0xFF;
		pal.cols[selCol].blue = (ColorDialog1->Color>>16)&0xFF;
        DrawPalette();
    }
}
//---------------------------------------------------------------------------
void __fastcall TWndPalEdit::Button3Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TWndPalEdit::Button4Click(TObject *Sender)
{
	OK_CLOSE = TRUE;   
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TWndPalEdit::CheckBox1Click(TObject *Sender)
{                
    pal.cols[selCol].infoBits = CheckBox1->Checked;
	DrawPalette();
}
//---------------------------------------------------------------------------
void __fastcall TWndPalEdit::FormClose(TObject *Sender,
      TCloseAction &Action)
{                     
    Timer1->Enabled = FALSE;
}
//---------------------------------------------------------------------------
void __fastcall TWndPalEdit::Timer1Timer(TObject *Sender)
{
    Timer1->Tag = (Timer1->Tag+2)&0xF;
    imPal->Canvas->Brush->Style = bsClear;
    imPal->Canvas->Pen->Style = psSolid;
    imPal->Canvas->Pen->Color = clFados[1][Timer1->Tag];;
    imPal->Canvas->Pen->Width = 2;
    imPal->Canvas->Rectangle(selX-1,selY-1,selX+colWidth,selY+colHeight);
}
//---------------------------------------------------------------------------
