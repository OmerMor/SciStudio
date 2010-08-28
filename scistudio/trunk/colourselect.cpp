//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "picedit.h"
#include "gfxedits.h"
#include "colourselect.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgColourSelect *DlgColourSelect;
//---------------------------------------------------------------------------
__fastcall TDlgColourSelect::TDlgColourSelect(TComponent* Owner)
	: TForm(Owner)
{      
    ResCol = ResPal = 0;
    COLOUR_CHANGED = 0;
}
//---------------------------------------------------------------------------

void __fastcall TDlgColourSelect::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TDlgColourSelect::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    Label1->Caption = "";
}
//---------------------------------------------------------------------------
void __fastcall TDlgColourSelect::BtnSetColourClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TDlgColourSelect::BtnTurnOffClick(TObject *Sender)
{
	ResPal = -1;
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TDlgColourSelect::BtnCancelClick(TObject *Sender)
{
    ResPal = -2;
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TDlgColourSelect::Image1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
	GetDexes(X, Y);
}
//---------------------------------------------------------------------------


void __fastcall TDlgColourSelect::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{                 /*
    BYTE NewPal;

    for(NewPal = 0; _Image!=Image[NewPal]; NewPal++);
    ResCol = ((Y>>3)<<3) + (X/8);
    if(NewPal==ResPal)
        DrawPalettes(1);
    else {
        ResPal=NewPal;
        DrawPalettes(0);
    }
    DrawSelected();  */
    if(GetDexes(X, Y)) {
    	ResCol = palcol;
        ResPal = paldex;   
        DrawPalettes(0);
		DrawSelected();
    }
}
//---------------------------------------------------------------------------

void __fastcall TDlgColourSelect::Image7MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    BYTE Colour = (Y&0xFFF8) + (X / 7);

    if(Button == mbLeft) {
        Palette[ResPal][ResCol] &= 0xF;
        Palette[ResPal][ResCol] |= ((Colour << 4) & 0xF0);
    } else {
        Palette[ResPal][ResCol] &= 0xF0;
        Palette[ResPal][ResCol] |= (Colour & 0xF);
    }

    COLOUR_CHANGED |= 1<<ResPal;

    DrawSelected();
    DrawPalettes(0);
}
//---------------------------------------------------------------------------

void __fastcall TDlgColourSelect::Image9MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    ResCol = ((Y/24)*8) + (X/25);
    DrawSelected();
}
//---------------------------------------------------------------------------

void __fastcall TDlgColourSelect::Timer1Timer(TObject *Sender)
{
    Timer1->Tag = (Timer1->Tag+1)&7;
	if(aScreen==asVISUAL) {
    	Image1->Canvas->Pen->Color = clFados[1][Timer1->Tag<<1];
    	Image1->Canvas->Rectangle(selRect);
    } else {
    	Image9->Canvas->Pen->Color = clFados[1][Timer1->Tag<<1];
    	Image9->Canvas->Rectangle(selRect);
    }
}
//---------------------------------------------------------------------------
void __fastcall TDlgColourSelect::Setup(char Scr, TWndPicEdit *EditWin1)
{
    // No I didn't forget the extra '=', I'm checking for see is aScreen is
    // TRUE (priority) :)
    if((bool)((aScreen = Scr) != asVISUAL)) {
    	PageControl1->ActivePage = PriConTab;
        ClientHeight = 108;
        Image9->Canvas->Brush->Style = bsClear;
    } else {
    	PageControl1->ActivePage = VisualTab;
    }

    EditWin = EditWin1;
    memcpy(Palette, EditWin->pic->palette, sizeof(Palette));
    if(EditWin->pic->drawenable&DRAW_ENABLE_VISUAL) {
    	ResPal = GET_PALDEX(EditWin->pic->col[asVISUAL]);
        ResCol = GET_PALCOL(EditWin->pic->col[asVISUAL]);
    } else {
    	ResPal = 0;
        ResCol = GET_PALCOL(EditWin->pic->col[Scr]);
    }

    DrawPalettes(0);
    DrawSelected();

    Image1->Canvas->Brush->Style = bsClear;
    Image1->Canvas->Pen->Color = clYellow;
}
//---------------------------------------------------------------------------
RECT plimRects[4] = {
  	{1,  1,  65,  41},
  	{73, 1,  137, 41},
  	{1,  49, 65,  89},
  	{73, 49, 137, 89}
};
#define INRECT(x,y,r)\
	(x>=r.left&&x<=r.right&&y>=r.top&&y<=r.bottom)

void __fastcall TDlgColourSelect::DrawPalettes(BOOL P)
{
    Graphics::TBitmap *b = new Graphics::TBitmap;
    b->Width = 138;
    b->Height = 90;
    ClearBitmap(b,clBtnFace);
    b->Canvas->Pen->Color = clBlack;
	for(int p=0;p<4;p++) {
     	int fX,fY;
        fX = plimRects[p].left;
        fY = plimRects[p].top;              
    	b->Canvas->Pen->Color = clBtnHighlight;
        b->Canvas->Rectangle(fX-1,fY-1,fX+65,fY+41);
    	b->Canvas->Pen->Color = clBtnShadow;
        b->Canvas->Rectangle(fX-1,fY-1,fX+64,fY+40);
        for(int y=0;y<40;y++)
        	for(int x=0;x<64;x++) {
             	b->Canvas->Pixels[x+fX][y+fY] = palEGA.cols[((x^y)&1)?Palette[p][(x>>3)+(y&0xF8)]>>4:Palette[p][(x>>3)+(y&0xF8)]&0xF];
            }
    }
    Image1->Picture->Bitmap->Assign(b);
    delete b;
}
//---------------------------------------------------------------------------
BOOL __fastcall TDlgColourSelect::GetDexes(int X, int Y)
{
    for(paldex=3;paldex>=0;paldex--) {
    	if(INRECT(X,Y,plimRects[paldex]))
        	break;
    }
    if(paldex==-1) {
    	Label1->Caption = "";
        return FALSE;
    }
    rX = X-plimRects[paldex].left;
    rY = Y-plimRects[paldex].top;
    palcol = (rY&0xF8)+(rX>>3);
	Label1->Caption = "Palette:"+IntToStr(paldex)+" Index:"+IntToStr(palcol);
    return TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TDlgColourSelect::DrawSelected()
{
    int X,Y;
    AnsiString s;
	Timer1->Enabled = FALSE;
	if(aScreen!=asVISUAL) {
        Image9->Canvas->Draw(0,0,Image2->Picture->Bitmap);
        selRect.left = (ResCol&0x7)*25;
        selRect.top =(ResCol>>3)*24;
        selRect.right =(ResCol&0x7)*25+25;
        selRect.bottom =(ResCol>>3)*24+24;      
		Timer1->Enabled = TRUE;
        return;
	}

    Graphics::TBitmap *b = new Graphics::TBitmap;
    b->Width = 58;
    b->Height = 44;
   	ClearBitmap(b,clBtnFace);
    b->Canvas->Brush->Color = clBtnShadow;
    b->Canvas->FillRect(Rect(0,0,48,34));
    b->Canvas->FillRect(Rect(10,10,58,44));
    b->Canvas->Brush->Color = clBtnHighlight;
    b->Canvas->FillRect(Rect(11,11,48,34));
    b->Canvas->FillRect(Rect(11,11,58,44));
    for(Y = 1; Y < 33; Y++)
        for(X = 1; X < 47; X++)
            b->Canvas->Pixels[X][Y] = palEGA.cols[
                (Palette[ResPal][ResCol] >> 4)&0xF];

    for(Y = 11; Y < 43; Y++)
        for(X = 10; X < 57; X++)
            b->Canvas->Pixels[X][Y] = palEGA.cols[
                Palette[ResPal][ResCol]&0xF];

    for(Y = 11; Y < 33; Y++)
        for(X = 10; X < 47; X++)
            b->Canvas->Pixels[X][Y] = palEGA.cols[(((X^Y)&1)?
                (Palette[ResPal][ResCol] >> 4)&0xF:
                Palette[ResPal][ResCol] & 0xF)];
	Image5->Picture->Bitmap->Assign(b);
    delete b;
    selRect.left   = plimRects[ResPal].left+((ResCol&0x7)<<3);
    selRect.top    = plimRects[ResPal].top+(ResCol&0xF8);
    selRect.right  = plimRects[ResPal].left+(((ResCol&0x7)<<3)+8);
    selRect.bottom = plimRects[ResPal].top+((ResCol&0xF8)+8);

    Label2->Caption = "P:"+IntToStr(ResPal)+" I:"+IntToStr(ResCol);
	Timer1->Enabled = TRUE;
}
//---------------------------------------------------------------------------

void __fastcall TDlgColourSelect::Label4MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    ReleaseCapture();
    SendMessage(Handle, WM_SYSCOMMAND, 61458, 0);
}
//---------------------------------------------------------------------------

