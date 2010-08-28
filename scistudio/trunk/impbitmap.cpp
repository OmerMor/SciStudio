//---------------------------------------------------------------------------

#include <vcl.h>     
#include <ClipBrd.hpp>
#pragma hdrstop     

#include "picedit.h"
#include "impbitmap.h"
#include "gfxedits.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgImpBitmap *DlgImpBitmap;
//---------------------------------------------------------------------------
__fastcall TDlgImpBitmap::TDlgImpBitmap(TComponent* Owner)
	: TForm(Owner)
{
	wndPic=(TWndPicEdit*)Owner;
	Graphics::TBitmap *b = DrawBufferToBitmap(wndPic->pic->bitmaps[wndPic->activeScreen],sPIC_WIDTH,sPIC_HEIGHT,(wndPic->pic->palVGA)?&(wndPic->pic->palVGA->pal):&palEGA,FALSE,FALSE);
    pBmp = new Graphics::TBitmap;
    pBmp->Width = sPIC_WIDTH;
    pBmp->Height = sPIC_HEIGHT;
    pBmp->Canvas->Draw(0,0,b);
    delete b;
	dBmp = NULL;
    memset(bMask,0xFF,sizeof(bMask));
    DRAGGING = FALSE;
}
//---------------------------------------------------------------------------
void __fastcall TDlgImpBitmap::SetBitmap()
{
	if(!dBmp) return;
	pBmp->Canvas->Draw(rcBmp.left,rcBmp.top,dBmp);
    int x1,x2,y1,y2;
	x1 = rcBmp.left>0?rcBmp.left:0;
	y1 = rcBmp.top>0?rcBmp.top:0;
	x2 = (rcBmp.left+dBmp->Width);
	if(x2>=sPIC_WIDTH) x2 = sPIC_WIDTH-1;
	y2 = (rcBmp.top+dBmp->Height);
	if(y2>=sPIC_HEIGHT) y2 = sPIC_HEIGHT-1;
	for(int y = y1; y <= y2; y++)
    	memset(bMask+(y*sPIC_WIDTH)+x1,0,x2-x1);
    FULL_DELETE(dBmp);      
	Image1->Canvas->Draw(0,0,pBmp);
}
//---------------------------------------------------------------------------
void __fastcall TDlgImpBitmap::SetCoords()
{
	if(!dBmp) return;            
    rcBmp.right = rcBmp.left+dBmp->Width;
    rcBmp.bottom = rcBmp.top+dBmp->Height;
	Image1->Canvas->Draw(0,0,pBmp);
	Image1->Canvas->Draw(rcBmp.left,rcBmp.top,dBmp);
}
//---------------------------------------------------------------------------
void __fastcall TDlgImpBitmap::ToolButton2Click(TObject *Sender)
{
	if(!BGOpenDialog->Execute()) return;
	SetBitmap();
    dBmp = new Graphics::TBitmap;
    dBmp->LoadFromFile(BGOpenDialog->FileName);
    rcBmp.left = 0;
    rcBmp.top = 0;
    SetCoords();
}
//---------------------------------------------------------------------------
#define SET_PANEL_TEXT(s) \
	StatusBar->SimpleText = s
//---------------------------------------------------------------------------
U32 GetColsUsed(U32 *bmpBuf, U32 bufSize, U32 *palBuf)
{
	U32 i=0,j=0,cu=0,c;
    BOOL INC;
    for(i=0;i<bufSize;i++) {
    	INC = TRUE;
        c=bmpBuf[i];
    	for(j=0;j<cu;j++)
       		if(palBuf[j]==c) {
             	INC = FALSE;
                break;
            }
        if(INC) {
        	palBuf[cu] = c;
        	cu++;
            if(cu>=256)
            	break;
        }
    }
    return cu;
}
//---------------------------------------------------------------------------
#define GET_R(c) (c&0xFF)
#define GET_G(c) ((c>>8) &0xFF)
#define GET_B(c) ((c>>16)&0xFF)
#define ABX(a) ((a<0)?-a:a)
#define GET_DIFF(c1, c2)\
	(ABX(GET_R(c1)-GET_R(c2))+ABX(GET_G(c1)-GET_G(c2))+ABX(GET_B(c1)-GET_B(c2)))
#define GET_DIFFR(c1, c2)\
	ABX(GET_R(c1)-GET_R(c2))
#define GET_DIFFG(c1, c2)\
	ABX(GET_G(c1)-GET_G(c2))
#define GET_DIFFB(c1, c2)\
	ABX(GET_B(c1)-GET_B(c2))
//---------------------------------------------------------------------------
U32 MatchCols(U32 *bmpBuf, U32 bufSize, U32 *palBuf, U8 diff, U32 maxCols)
{
	U32 i=0,j=0,cu=0,c,g;
    BOOL INC;
    for(i=0;i<bufSize;i++) {
    	INC = TRUE;
        c=bmpBuf[i];
    	for(j=0;j<cu;j++) {
        	g = palBuf[j];
       		if(((GET_DIFFR(g,c)<=diff)&&(GET_DIFFG(g,c)<=diff)&&(GET_DIFFB(g,c)<=diff))) {
            	bmpBuf[i] = palBuf[j];
             	INC = FALSE;
                break;
            }
        }
        if(INC) {
        	palBuf[cu] = c;
        	cu++;
            if(cu>=maxCols)
            ;//	break;
        }
    }
    return cu;
}
//---------------------------------------------------------------------------
U8 PalEnt(U32 c, U32 *palBuf, U32 totalCols)
{
	for(U32 j=0;j<totalCols;j++)
    	if(palBuf[j]==c)
        	return j;
    return 0;
}
//---------------------------------------------------------------------------
U8 *DecreaseBmpDepth(U32 *bmpBuf, U32 *palBuf, U32 bufSize, U32 maxCols)
{
    U8 *outBuf = (U8*)ssAlloc(bufSize);
	U32 i=0,j=0,cu=0,c;
    BOOL INC;
    for(i=0;i<bufSize;i++) {  
    	INC = TRUE;
        c=bmpBuf[i];
    	for(j=0;j<cu;j++)
       		if(palBuf[j]==c) {
             	INC = FALSE;
                break;
            }
        if(INC) {
        	palBuf[cu] = c;
        	cu++;
            //if(cu==maxCols)
             //	break;
        }   
        outBuf[i] = j+64;
    }
    return outBuf;
}
//---------------------------------------------------------------------------
void __fastcall TDlgImpBitmap::Button1Click(TObject *Sender)
{
	SetBitmap();
    U8 *bmp8Buf;
    U32 *bmpBuf = (U32*)ssAlloc(sPIC_SIZE*sizeof(U32));
    U32 *palBuf = (U32*)ssAlloc(sPIC_SIZE*sizeof(U32)); // erg..I know, lots of mem--max # of unique cols
    U32 j=0;
    SET_PANEL_TEXT("Creating bitmap buffer...");
    TCanvas *cV=pBmp->Canvas;
    for(int y=0;y<sPIC_HEIGHT;y++)
    	for(int x=0;x<sPIC_WIDTH;x++)
        	bmpBuf[j++] = cV->Pixels[x][y]&0x00FFFFFF;
    U32 totalCols;
    maxCols = 191;
    j = 1;
    SET_PANEL_TEXT("Calculating colour depth...");
    totalCols = GetColsUsed(bmpBuf,sPIC_SIZE,palBuf);
    if(totalCols>256) {
    	ShowMessage("Col Depth++!");
        return;
    }
    SET_PANEL_TEXT("Depth="+IntToStr(totalCols)+"...");
    if(totalCols>maxCols) {
    	SET_PANEL_TEXT("Building palette to chosen colour depth...");
		do {
    		totalCols = MatchCols(bmpBuf,sPIC_SIZE,palBuf,j,maxCols);
            j++;
    		SET_PANEL_TEXT("Depth="+IntToStr(totalCols)+"...");
    	} while(totalCols>maxCols);
    	SET_PANEL_TEXT("Depth conversion complete! Depth="+IntToStr(totalCols));
    }
    SET_PANEL_TEXT("Converting 24 bit bitmap to 8 bit...");
	//ssFree(palBuf);
    //palBuf = (U32*)ssAlloc(maxCols*sizeof(U32));
    bmp8Buf = DecreaseBmpDepth(bmpBuf, palBuf, sPIC_SIZE, maxCols);
	ssFree(bmpBuf);
    Image1->Visible = FALSE;
    j=0;
    for(int y=0;y<sPIC_HEIGHT;y++)
    	for(int x=0;x<sPIC_WIDTH;x++)
        	Image1->Canvas->Pixels[x][y]=(TColor)palBuf[bmp8Buf[j++]];
    Image1->Visible = TRUE;
    SET_PANEL_TEXT("Done!");

    U8 *outBits = (U8*)ssAlloc(sPIC_SIZE);
    U16 size = EncodeSCI1Bits(bmp8Buf, outBits, sPIC_WIDTH, sPIC_HEIGHT, 0xFF, FALSE);

	wndPic->AddCode(0xFE);

	wndPic->AddCode(0x01);

	wndPic->AddCode(0);
	wndPic->AddCode(0);
	wndPic->AddCode(0);
    U8 *p = wndPic->pic->data+wndPic->pic->offset;
	wndPic->AddCode(0);
	wndPic->AddCode(0);
	wndPic->AddCode(sPIC_WIDTH&0xFF);
	wndPic->AddCode(sPIC_WIDTH>>8);
	wndPic->AddCode(sPIC_HEIGHT&0xFF);
	wndPic->AddCode(sPIC_HEIGHT>>8);
	wndPic->AddCode(0xFF);
	wndPic->AddCode(0);
	wndPic->AddCode(0);
    for(int i=0;i<size;i++)
		wndPic->AddCode(outBits[i]);

    size = wndPic->pic->data-p;
    p[0] = (size)&0xFF;
    p[1] = ((size)>>8)&0xFF;

	wndPic->AddCode(0xFE);
	wndPic->AddCode(0x02);
    for(int i=0;i<256;i++)
    	wndPic->AddCode(i);
    wndPic->AddCode(0);
    wndPic->AddCode(0xFE);
    wndPic->AddCode(0);
    wndPic->AddCode(0xFF);
    for(int i=0;i<64;i++) {
		wndPic->AddCode(0);
		wndPic->AddCode(0);
		wndPic->AddCode(0);
		wndPic->AddCode(0);
    }
    for(int i=0;i<191;i++) {
		wndPic->AddCode(1);
		wndPic->AddCode(palBuf[i]&0xFF);
		wndPic->AddCode((palBuf[i]>>8)&0xFF);
		wndPic->AddCode((palBuf[i]>>16)&0xFF);
    }   
    wndPic->AddCode(0);
    wndPic->AddCode(0);
    wndPic->AddCode(0);
    wndPic->AddCode(0);

	ssFree(bmp8Buf);
	ssFree(palBuf);
	ssFree(outBits);

    wndPic->UpdatePic();
    Close();

}
//---------------------------------------------------------------------------
void __fastcall TDlgImpBitmap::ToolButton5Click(TObject *Sender)
{
    TClipboard *pCB = Clipboard();

    if(pCB->HasFormat(CF_BITMAP)) {   
		SetBitmap();
        dBmp = new Graphics::TBitmap;
        dBmp->LoadFromClipboardFormat(CF_BITMAP, pCB->GetAsHandle(CF_BITMAP), 0); 
    	rcBmp.left = 0;
    	rcBmp.top = 0;
    	SetCoords();
    } else {
        MessageBeep(0);
        ShowMessage("Clipboard does not contain a valid Bitmap!");
    }
}
//---------------------------------------------------------------------------
void __fastcall TDlgImpBitmap::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	dnX = X;
    dnY = Y;
	if(Shift.Contains(ssLeft))
		DRAGGING = (X>=rcBmp.left&&Y>=rcBmp.top&&X<=rcBmp.right&&Y<=rcBmp.bottom);
}
//---------------------------------------------------------------------------
void __fastcall TDlgImpBitmap::Image1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
	mvX = X;
    mvY = Y;
	if(DRAGGING) {
     	rcBmp.left -= (dnX-mvX);
     	rcBmp.top  -= (dnY-mvY);
        dnX = mvX;
        dnY = mvY;
        SetCoords();
    }
}
//---------------------------------------------------------------------------
void __fastcall TDlgImpBitmap::Image1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	DRAGGING = FALSE;
}
//---------------------------------------------------------------------------
void __fastcall TDlgImpBitmap::StatusBarDrawPanel(TStatusBar *StatusBar,
      TStatusPanel *Panel, const TRect &Rect)
{    /*
  TCanvas *pCanvas = StatusBar->Canvas;

  pCanvas->Brush->Color = clRed;

  pCanvas->FillRect(Rect);
  pCanvas->Font->Color = clYellow;
  ImageList1->Draw(pCanvas,Rect.Left,Rect.Top, Panel->Index, true);
  pCanvas->TextOut(Rect.left + 30, Rect.top + 2, "Panel" + IntToStr(Panel->Index));
*/}
//---------------------------------------------------------------------------

