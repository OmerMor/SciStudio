//---------------------------------------------------------------------------

#ifndef gfxeditsH
#define gfxeditsH
//---------------------------------------------------------------------------
#include "scihdr.h"
//---------------------------------------------------------------------------
#define MAX_HEIGHT 		190
#define MAX_WIDTH  		320

#define MAX_FONT_HEIGHT	127
#define MAX_CHAR_WIDTH	127
#define MAX_CHAR_HEIGHT	127

#define CRZ_NONE	0
#define CRZ_WIDTH	1
#define CRZ_HEIGHT	2
#define CRZ_BOTH	3

typedef struct {
	int index;
    char *name;
} tsCSRRES;

#define TOOLS_SELECTION	0x0A
#define GET_TOOL_GROUP(s) (s>>8)

#define TOTAL_EDIT_TOOLS	18
extern tsCSRRES csrRes[TOTAL_EDIT_TOOLS];
#define DRAWING_CURSOR 	1

#define TOOL_PEN		0x0101
#define TOOL_REPLACE	0x0102
#define TOOL_LINE		0x0103
#define TOOL_FILL		0x0104
#define TOOL_RECT		0x0105
#define TOOL_RECTF		0x0106
#define TOOL_RRECT		0x0107
#define TOOL_RRECTF		0x0108
#define TOOL_ELLIPSE	0x0109
#define TOOL_ELLIPSEF	0x010A

#define TOOL_ARROW		0x0201
#define TOOL_GRABBER	0x0202
#define TOOL_ZOOM		0x0203
#define TOOL_SCROLL		0x0204
#define TOOL_SELECTION	0x0A05
#define TOOL_SELRESIZE	0x0A06
#define TOOL_SELMOVE	0x0A07
#define TOOL_SELCOPY	0x0A08

#define TOOL_SHIFTUP	0x0301
#define TOOL_SHIFTDOWN	0x0302
#define TOOL_SHIFTLEFT	0x0303
#define TOOL_SHIFTRIGHT	0x0304
#define TOOL_FLIPH		0x0305
#define TOOL_FLIPV		0x0306

#define TOOL_INVERT		0x0401
#define TOOL_GREYSCALE	0x0402



#define smWITH_LOOP 	0
#define smWITHOUT_LOOP	1
#define smWITH_COLOUR	2
//---------------------------------------------------------------------------
extern TColor clFados[5][16];
extern U8 defView[56],defCursor[68],defFont[1308],defPic[178],defPalette[1284];
//---------------------------------------------------------------------------
U8	 GetPaldex(TColor cl, tPAL *pal);
U8  *ResizeBits(U8 *bits, int oWidth, int oHeight, int nWidth, int nHeight, U8 bkCol);
void BitmapToBits(Graphics::TBitmap *bmp, U8 *bits, tPAL *pal);

BOOL InRect(TRect SelRect, int X, int Y);

void ImageSetSize(TImage *im, int w, int h);
void DrawBufferToCanvas(TCanvas *c, int x, int y, U8 *b, int w, int h, tPAL *p);
Graphics::TBitmap *DrawBufferToBitmap(U8 *b, int w, int h, tPAL *p, BOOL mirx, BOOL miry);
void SetupLogPal(tPAL *pal);
void FreeLogPal(tPAL *pal);
Graphics::TBitmap *NewPaledBitmap(tPAL *pal, int Width, int Height);
void xDeletePaledBitmap(Graphics::TBitmap *b);
#define DeletePaledBitmap(b)\
	xDeletePaledBitmap(b);b=NULL

void PenDraw(Graphics::TBitmap *b,int x,int y);
void PenReplaceDraw(Graphics::TBitmap *b,int x,int y, TColor c1, TColor c2);
void ShapeDraw(Graphics::TBitmap *b,int x1,int y1,int x2,int y2,int tool);
void LineDraw(Graphics::TBitmap *b,int x1,int y1,int x2,int y2);

Graphics::TBitmap *DrawPicBitmap(sciPIC *pic, U8 *data, tPAL *pal);
void DrawPicImage(TImage *img, sciPIC *pic, U8 *data, tPAL *pal);

void ViewSetUpUpDowns(sciVIEW *view,TUpDown *udLoop,TUpDown *udCel);
void ViewSetCelUpDown(sciVIEWLOOP *loop,TUpDown *udCel);
Graphics::TBitmap *ViewDrawCelBitmap(sciVIEW *view, int loop, int cel, tPAL *viewPal);
void ViewDrawCelImage(TImage *imgView, sciVIEW *view, tPAL *viewPal, int loop, int cel, int shift);

void CursorDrawImage(TImage *bm, sciCURSOR *cr, tPAL *pal);
Graphics::TBitmap *CursorDrawBitmap(sciCURSOR *cr, tPAL *pal);

int  CalcFontBoundsHeight(sciFONT *fn,int maxWidth, int spacing, char *str);
void FontDrawImage(TImage *im, sciFONT *fn);
Graphics::TBitmap *FontDrawCharBitmap(sciFONT *font, int fChar);

void DrawPaletteAsBitmap(Graphics::TBitmap *b, sciPALETTE *p, int hC, int vC, int w, int h,TColor c);

void ClearImage(TImage *Image, TColor Colour);
void ClearBitmap(Graphics::TBitmap *Bitmap, TColor Colour);

void FlipBitmapH(Graphics::TBitmap *Bitmap);
void FlipBitmapV(Graphics::TBitmap *Bitmap);

void BitmapShiftUp(Graphics::TBitmap *Bitmap, TColor Colour, char Method);
void BitmapShiftDown(Graphics::TBitmap *Bitmap, TColor Colour, char Method);
void BitmapShiftLeft(Graphics::TBitmap *Bitmap, TColor Colour, char Method);
void BitmapShiftRight(Graphics::TBitmap *Bitmap, TColor Colour, char Method);

void GreyScaleBitmap(Graphics::TBitmap *Bitmap);
void InvertBitmap(Graphics::TBitmap *Bitmap);

float PointsToAngle(float xOne, float yOne, float X, float Y);
int CalcAct(int x, int z);
//---------------------------------------------------------------------------
#endif
