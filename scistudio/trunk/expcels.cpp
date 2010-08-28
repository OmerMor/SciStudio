//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
                      
#include "main.h"  
#include "expcels.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgExpCels *DlgExpCels;
//---------------------------------------------------------------------------
__fastcall TDlgExpCels::TDlgExpCels(TComponent* Owner, sciVIEW *view, int loopNum)
	: TForm(Owner)
{
    this->view 		= view;
    this->loopNum	= loopNum;
    b = NULL;
    DrawBitmap();
}
//---------------------------------------------------------------------------

void __fastcall TDlgExpCels::DrawBitmap()
{
    sciVIEWLOOP *loop;
    int fLoop,lLoop;
    if(rbAllLoops->Checked) {
     	fLoop=0;
        lLoop=view->totalLoops-1;
    } else {
     	fLoop=loopNum;
        lLoop=loopNum;
    }
    int Spacing = StrToInt(ebSpacing->Text);
    int bmHeight=Spacing,bmWidth=0;
    int newW=0;
    for(int l=fLoop;l<=lLoop;l++) {
    	loop = GetRealLoop(ViewGetLoop(view,l));
		sPOINT p = GetLoopMaxSize(loop);
        newW =(p.x+Spacing)*loop->totalCels;
        if(newW>bmWidth) bmWidth = newW;
        bmHeight += p.y+Spacing;
    }
    bmWidth += Spacing;
    int y=Spacing,x;
    FULL_DELETE(b);
    b = NewPaledBitmap(view->palVGA==NULL?&palEGA:&view->palVGA->pal, bmWidth, bmHeight);
    for(int l=fLoop;l<=lLoop;l++) {
    	x = Spacing;
    	loop = GetRealLoop(ViewGetLoop(view,l));
		sPOINT p = GetLoopMaxSize(loop);
        for(int c=0;c<loop->totalCels;c++) {
			Graphics::TBitmap *bc = ViewDrawCelBitmap(view, l, c,(view->palVGA)?&(view->palVGA->pal):&palEGA);
            b->Canvas->Draw(x+((p.x-bc->Width)/2),y+(p.y-bc->Height),bc);
            x+=p.x+Spacing;
            DeletePaledBitmap(bc);
        }
        y+=p.y+Spacing;
    }
    Image1->Width  = bmWidth<<1;
    Image1->Height = bmHeight<<1;
    Image1->Picture->Bitmap->Assign(b);
}
//---------------------------------------------------------------------------

void __fastcall TDlgExpCels::rbAllLoopsClick(TObject *Sender)
{
    DrawBitmap();
}
//---------------------------------------------------------------------------
void __fastcall TDlgExpCels::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TDlgExpCels::Button1Click(TObject *Sender)
{
	if(!SaveDialog->Execute()) return;
    b->SaveToFile(SaveDialog->FileName);
    DeletePaledBitmap(b);
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TDlgExpCels::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    FULL_DELETE(b);
	Action = caFree;
}
//---------------------------------------------------------------------------

