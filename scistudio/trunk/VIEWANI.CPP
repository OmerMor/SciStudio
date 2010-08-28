//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "ssresdecode.h"
#include "viewedit.h"
#include "gfxedits.h"
#include "viewani.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgViewAni *DlgViewAni;
//---------------------------------------------------------------------------
__fastcall TDlgViewAni::TDlgViewAni(TComponent* Owner)
	: TForm(Owner)
{
    Cel=0;
    W = imgView->Width;
    H = imgView->Height;
    imgView->Canvas->Brush->Style = bsSolid;
    imgView->Canvas->Brush->Color = clBtnFace;
    imgView->Canvas->Pen->Style = psSolid;
    imgView->Canvas->Pen->Color = clBtnFace;
}
//---------------------------------------------------------------------------
void __fastcall TDlgViewAni::Timer1Timer(TObject *Sender)
{
	TrackBar1->OnChange=NULL;
    Label1->Caption="Loop:"+IntToStr(loop->loop)+"  Cel:"+IntToStr(Cel);
    Graphics::TBitmap *b = ViewDrawCelBitmap(view,loop->loop,Cel,pal);
    scbView->Color = pal->cols[ViewLoopGetCel(loop,Cel)->transCol];
    W=b->Width<<1;
    H=b->Height<<1;

    imgView->Left = ((scbView->Width-W)>>1);//+((signed int)offCel->x*2);
    imgView->Top = ((scbView->Height-H)>>1);//+((signed int)offCel->y*2);
    imgView->Width = W;
    imgView->Height = H;
    shpView->Left = imgView->Left-1;
    shpView->Top = imgView->Top-1;
    shpView->Width = W+2;
    shpView->Height = H+2;

	imgView->Picture->Bitmap->Assign(b);

    DeletePaledBitmap(b);
    Cel=(Cel+1)%(realLoop->totalCels);

	TrackBar1->Position = Cel;
	TrackBar1->SelEnd = Cel;
    TrackBar1->OnChange=TrackBar1Change;
}
//---------------------------------------------------------------------------
void __fastcall TDlgViewAni::ToolButton1Click(TObject *Sender)
{
    ToolButton2->Enabled = TRUE;
    ToolButton3->Enabled = TRUE;
	Cel = 0;
    Timer1Timer(this);
    Timer1->Enabled = TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TDlgViewAni::ToolButton2Click(TObject *Sender)
{
    Timer1->Enabled = !Timer1->Enabled;
}
//---------------------------------------------------------------------------
void __fastcall TDlgViewAni::ToolButton3Click(TObject *Sender)
{
    ToolButton2->Enabled = FALSE;
    ToolButton3->Enabled = FALSE;
	Cel = 0;    
    Timer1->Enabled = FALSE;
}
//---------------------------------------------------------------------------
void __fastcall TDlgViewAni::TrackBar2Change(TObject *Sender)
{
	Timer1->Enabled = FALSE;
    Timer1->Interval = TrackBar2->Position*100;
    Timer1->Enabled = TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TDlgViewAni::TrackBar1Change(TObject *Sender)
{
	Cel = TrackBar1->Position;
	TrackBar1->SelEnd = Cel;
    Timer1Timer(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TDlgViewAni::FormClose(TObject *Sender,
      TCloseAction &Action)
{
	ViewEditWin->aniSpeed = TrackBar2->Position;
	Timer1->Enabled = FALSE;
	Action = caFree;
}
//---------------------------------------------------------------------------
