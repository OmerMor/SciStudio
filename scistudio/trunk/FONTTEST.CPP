//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
                 
#include "main.h"
#include "ssresdecode.h"
#include "viewedit.h"
#include "gfxedits.h"
#include "fonttest.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgFontTest *DlgFontTest;
//---------------------------------------------------------------------------
__fastcall TDlgFontTest::TDlgFontTest(TComponent* Owner)
	: TForm(Owner)
{
}   
//---------------------------------------------------------------------------
void TDlgFontTest::Setup(sciFONT *F)
{
 	Fnt=F;

    ClientHeight = 54+F->height*2;
    Shape2->Height = F->height*2+8;
	EditBmp = new Graphics::TBitmap;
    EditBmp->Width=270;
    EditBmp->Height=F->height;
    ClearBitmap(EditBmp,clWhite);
    CharPos=0;
    Image1->Width = 540;
    Image1->Height = F->height*2;
    ClearImage(Image1,clWhite);
    EditBmp->Canvas->Pen->Color=clWhite;            
    EditBmp->Canvas->Pen->Style=psSolid;
    EditBmp->Canvas->Brush->Color=clWhite;
    EditBmp->Canvas->Brush->Style=bsSolid;
}
//---------------------------------------------------------------------------
void __fastcall TDlgFontTest::Button1Click(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------
void __fastcall TDlgFontTest::FormClose(TObject *Sender,
      TCloseAction &Action)
{
	delete EditBmp;
	Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TDlgFontTest::FormKeyPress(TObject *Sender, char &Key)
{
	if(Key>=Fnt->totalChars) {
    	ssMessage(ssNOTICE,"Character out of range!");
        return;
    }
	int Char = Key;
    sciFONTCHAR *c = GetFontChar(Fnt, Char);
    int Diff = (CharPos+c->width)-269;
	if(Diff>0) {
     	EditBmp->Canvas->CopyRect(
        	Rect(0,0,269-Diff,c->height),
            EditBmp->Canvas,
        	Rect(Diff,0,269,c->height)
        );
    	CharPos = 269-c->width;
    }                                                  
    EditBmp->Canvas->FillRect(
        	Rect(CharPos,0,CharPos+c->width,Fnt->height)
    );
    Graphics::TBitmap *b = FontDrawCharBitmap(Fnt, Char);
    EditBmp->Canvas->Draw(CharPos,0,b);
    DeletePaledBitmap(b);
    CharPos+=c->width;
    Image1->Canvas->StretchDraw(Rect(0,0,540,Fnt->height*2),EditBmp);
}
//---------------------------------------------------------------------------
void __fastcall TDlgFontTest::Shape1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    ReleaseCapture();
    SendMessage(Handle, WM_SYSCOMMAND, 61458, 0);
}
//---------------------------------------------------------------------------
