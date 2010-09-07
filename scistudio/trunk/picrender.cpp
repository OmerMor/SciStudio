//---------------------------------------------------------------------------
// SCI Studio 3+
// http://scistudio.sf.net/
//---------------------------------------------------------------------------

#include <vcl.h>
#include <time.h>

#pragma hdrstop

#include "scihdr.h"
#include "picrender.h"  
#include "gfxedits.h"

/*****************************************************************************/

FUNC picOps[] = {
/*0xF0*/	{picop_SetColour},
/*0xF1*/	{picop_DisableVisual},
/*0xF2*/	{picop_SetPriority},
/*0xF3*/	{picop_DisablePriority},
/*0xF4*/	{picop_RelativePatterns},
/*0xF5*/	{picop_MediumLines},
/*0xF6*/	{picop_LongLines},
/*0xF7*/	{picop_ShortLines},
/*0xF8*/	{picop_Fill},
/*0xF9*/	{picop_SetPattern},
/*0xFA*/	{picop_AbsolutePattern},
/*0xFB*/	{picop_SetControl},
/*0xFC*/	{picop_DisableControl},
/*0xFD*/	{picop_MediumPatterns},
/*0xFE*/	{picop_Ext},
/*0xFF*/	{picop_SkipNothing}
} ;
FUNC picSkipOps[] = {
	{picop_SkipSet},
	{picop_SkipNothing},
	{picop_SkipSet},
	{picop_SkipNothing},
	{picop_SkipRelativePatterns},
	{picop_SkipMediumLines},
	{picop_SkipAbs},
	{picop_SkipShortLines},
	{picop_SkipAbs},
	{picop_SkipSetPattern},
	{picop_SkipAbsolutePattern},
	{picop_SkipSet},
	{picop_SkipNothing},
	{picop_SkipMediumPatterns},
	{picop_SkipExt},
	{picop_SkipNothing}
};
FUNC picPrintOps[] = {
	{picop_PrintSetVis},
	{picop_SkipNothing},
	{picop_PrintSetPriCon},
	{picop_SkipNothing},
	{picop_PrintRelativePatterns},
	{picop_PrintMediumLines},
	{picop_PrintAbs},
	{picop_PrintShortLines},
	{picop_PrintAbs},
	{picop_PrintSetPattern},
	{picop_PrintAbsolutePattern},
	{picop_PrintSetPriCon},
	{picop_SkipNothing},
	{picop_PrintMediumPatterns},
	{picop_PrintExt},
	{picop_SkipNothing}
};
/*****************************************************************************/
U8 palDefault[40] = {
	0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
	0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0x88,
	0x88, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x88,
	0x88, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff,
	0x08, 0x91, 0x2a, 0x3b, 0x4c, 0x5d, 0x6e, 0x88
};

U8 priTable[40] = {
	0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
	0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xFF,
	0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
	0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xFF,
	0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
};


  char circles[][30] = { /* bitmaps for circle patterns */
    {0x80},
    {0x4e, 0x40},
    {0x73, 0xef, 0xbe, 0x70},
    {0x38, 0x7c, 0xfe, 0xfe, 0xfe, 0x7c, 0x38, 0x00},
    {0x1c, 0x1f, 0xcf, 0xfb, 0xfe, 0xff, 0xbf, 0xef, 0xf9, 0xfc, 0x1c},
    {0x0e, 0x03, 0xf8, 0x7f, 0xc7, 0xfc, 0xff, 0xef, 0xfe, 0xff, 0xe7,
	   0xfc, 0x7f, 0xc3, 0xf8, 0x1f, 0x00},
    {0x0f, 0x80, 0xff, 0x87, 0xff, 0x1f, 0xfc, 0xff, 0xfb, 0xff, 0xef,
	   0xff, 0xbf, 0xfe, 0xff, 0xf9, 0xff, 0xc7, 0xff, 0x0f, 0xf8,
	   0x0f, 0x80},
    {0x07, 0xc0, 0x1f, 0xf0, 0x3f, 0xf8, 0x7f, 0xfc, 0x7f, 0xfc, 0xff,
	   0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0x7f,
	   0xfc, 0x7f, 0xfc, 0x3f, 0xf8, 0x1f, 0xf0, 0x07, 0xc0}};
  unsigned char junq[32] = { /* random-looking fill pattern */
    0x20, 0x94, 0x02, 0x24, 0x90, 0x82, 0xa4, 0xa2, 0x82, 0x09, 0x0a, 0x22,
    0x12, 0x10, 0x42, 0x14, 0x91, 0x4a, 0x91, 0x11, 0x08, 0x12, 0x25, 0x10,
    0x22, 0xa8, 0x14, 0x24, 0x00, 0x50, 0x24, 0x04};
  unsigned char junqindex[128] = { /* starting points for junq fill */
    0x00, 0x18, 0x30, 0xc4, 0xdc, 0x65, 0xeb, 0x48,
    0x60, 0xbd, 0x89, 0x05, 0x0a, 0xf4, 0x7d, 0x7d,
    0x85, 0xb0, 0x8e, 0x95, 0x1f, 0x22, 0x0d, 0xdf,
    0x2a, 0x78, 0xd5, 0x73, 0x1c, 0xb4, 0x40, 0xa1,
    0xb9, 0x3c, 0xca, 0x58, 0x92, 0x34, 0xcc, 0xce,
    0xd7, 0x42, 0x90, 0x0f, 0x8b, 0x7f, 0x32, 0xed,
    0x5c, 0x9d, 0xc8, 0x99, 0xad, 0x4e, 0x56, 0xa6,
    0xf7, 0x68, 0xb7, 0x25, 0x82, 0x37, 0x3a, 0x51,
    0x69, 0x26, 0x38, 0x52, 0x9e, 0x9a, 0x4f, 0xa7,
    0x43, 0x10, 0x80, 0xee, 0x3d, 0x59, 0x35, 0xcf,
    0x79, 0x74, 0xb5, 0xa2, 0xb1, 0x96, 0x23, 0xe0,
    0xbe, 0x05, 0xf5, 0x6e, 0x19, 0xc5, 0x66, 0x49,
    0xf0, 0xd1, 0x54, 0xa9, 0x70, 0x4b, 0xa4, 0xe2,
    0xe6, 0xe5, 0xab, 0xe4, 0xd2, 0xaa, 0x4c, 0xe3,
    0x06, 0x6f, 0xc6, 0x4a, 0xa4, 0x75, 0x97, 0xe1
    };

/*****************************************************************************/
U8 *ptr;
U8 *bitmaps[5],*picStart,bmVis[sPIC_SIZE],bmX[sPIC_SIZE];
U8 col1, col2, priority, control, drawenable, visIndex;

U8 palette[4][40];
U8 colLocked[40];
int pattern_nr,pattern_code,pattern_size,palette_number,position;
sPOINT coords,oldCoords;
sciPALETTE *sci1Pal;

AnsiString codeStr;

int (*PCRD)(int x,int y);
void (*PlotPix)(U16 x, U16 y);

void PlotPixEGA(U16 x, U16 y);
void PlotPixVGA(U16 x, U16 y);

int picType;
U16 *priBars;

/*****************************************************************************/
U8 PeekInput() {
	return *ptr;
}
/*****************************************************************************/
U8 GetInput()
{
    position++;
	return *ptr++;
}
/*****************************************************************************/
void SkipInput(int amount)
{
	ptr 		+=	amount;
	position 	+=	amount;
}
/*****************************************************************************/
sPOINT GetAbsCoordinates()
{
	sPOINT s;

    U8 u = GetInput();
	s.x = ((u & 0xf0) << 4) | (0xff & GetInput());
	s.y = ((u & 0x0f) << 8) | (0xff & GetInput());

	return s;
}
/*****************************************************************************/
sPOINT GetRel8Coordinates(S16 x, S16 y)
{
	sPOINT s;

    U8 code = GetInput();
    if (code & 0x80)
    	s.y = y - (code & 0x7f);
    else
    	s.y = y + code;

    s.x = (S16)x + (S16)((S8)GetInput());

	return s;
}
/*****************************************************************************/
sPOINT GetRel4Coordinates(S16 x, S16 y)
{
	sPOINT s;
    U8 u = GetInput();
	if (u & 0x80)
		x -= (u >> 4)&7;
	else
		x += (u >> 4)&7;

	if(u & 0x08)
		y -= (u & 0x7);
	else
		y += (u & 0x7);

	s.x = x;
	s.y = y;

	return s;
}
/*****************************************************************************/
U8 GetPattern()
{
	if (pattern_code & PATTERN_FLAG_USE_PATTERN)
		pattern_nr = (GetInput() >> 1) & 0x7f;
	return pattern_nr;
}
/*****************************************************************************/
void AppendCoords(sPOINT coords)
{
	codeStr = codeStr+"("+IntToStr(coords.x)+","+IntToStr(coords.y)+")";
}

/*****************************************************************************/
U16 PicSkipTo(sciPIC *pic, int direction)
{
	U16 lastPos;

    pattern_nr 		= 0;
    pattern_code 	= 0;
    palette_number 	= 0;

	position = 0;
    lastPos = 0;
    ptr = pic->data;
    while(PeekInput()!=0xFF&&position<pic->length) {
    	lastPos = position;
        picSkipOps[GetInput()&0xF].func();
        if(direction==psBACKWARD) {
         	if(position>=pic->offset)
             	return lastPos;
        } else {
         	if(position>pic->offset)
             	return position;
        }
    }

    return position;
}

/*****************************************************************************/
U8 PicGetLastCode(sciPIC *pic)
{
	U16 lastPos;

    if(!pic->offset) return 0;

    pattern_nr 		= 0;
    pattern_code 	= 0;
    palette_number 	= 0;

	position = 0;
    lastPos = 0;
    ptr = pic->data;
    while(PeekInput()!=0xFF&&position<pic->length) {
    	lastPos = position;
        picSkipOps[GetInput()&0xF].func();
        if(position>=pic->offset)
        	return pic->data[lastPos];
    }

    return 0;
}
/*****************************************************************************/
U16 PicGetNextCmdOffset(sciPIC *pic)
{
    if(!pic) return 0;

    pattern_nr 		= pic->patNum;
    pattern_code 	= pic->patCode;
    palette_number 	= pic->visPal;
                            

    position = pic->offset;
    ptr = pic->data+position;
    if(PeekInput()!=0xFF)
    	picSkipOps[GetInput()&0xF].func();
    return position;
}
/*****************************************************************************/
U16 PicPrintCode(sciPIC *pic,BOOL SETTER)
{
	if(SETTER) {
    	pattern_nr 		= pic->patNum;
    	pattern_code 	= pic->patCode;
    	palette_number 	= pic->visPal;
		position = pic->offset;
    	ptr = pic->data+position;
    }
    codeStr = "";
    picPrintOps[GetInput()&0xF].func();

    return position;
}
/*****************************************************************************/
void DrawPic(int CUMULATIVE, int defaultPalette, sciPIC *pic, S16 ver)
{
	int i;

    if(!pic) return;

    ptr = pic->data;
    picStart = ptr;

    picType = ver;

    if(picType!=sv_PT_VGA10)
    	PlotPix = PlotPixEGA;
    else
    	PlotPix = PlotPixVGA;

	if (!CUMULATIVE) {
		SCI1PalDispose(pic->palVGA);
		sci1Pal			= NULL;
		drawenable 		= 0;//DRAW_ENABLE_VISUAL | DRAW_ENABLE_PRIORITY;
		priority 		= 0;
		control 		= 0;
		col1 = col2 	= 0;
		pattern_nr 		= 0;
		pattern_code 	= 0;
    	palette_number 	= defaultPalette;

		for(i=0;i<4;i++) {
			memcpy(palette[i],palDefault,40);
    		bitmaps[i] = pic->bitmaps[i];
    	}
        bitmaps[asBITMAP] = bmVis;

		memset(bitmaps[asVISUAL],0,sPIC_SIZE);
		memset(bmVis,0xF,sPIC_SIZE);
		memset(bmX,0xFF,sPIC_SIZE);
		for(int i=1;i<4;i++)
			memset(bitmaps[i],0,sPIC_SIZE);

        // though it's random, just to make things clean
        memset(colLocked,0,sizeof(colLocked));

        priBars = pic->priBars;
	} else {
		sci1Pal			= pic->palVGA;
		memcpy(palette,pic->palette,sizeof(palette));
    	memcpy(colLocked,pic->colLocked,sizeof(colLocked));
		for(i=0;i<4;i++) {
    		bitmaps[i] = pic->bitmaps[i];
    	}

		drawenable 		= pic->drawenable;
		priority 		= pic->col[asPRIORITY];
		control 		= pic->col[asCONTROL];
		col1 			= (palette[GET_PALDEX(pic->col[asVISUAL])][GET_PALCOL(pic->col[asVISUAL])]>>4)&0xF;
		col2 			=  palette[GET_PALDEX(pic->col[asVISUAL])][GET_PALCOL(pic->col[asVISUAL])]&0xF;
        visIndex		= GET_PALDEX(pic->col[asVISUAL]);
		pattern_nr 		= pic->patNum;
		pattern_code 	= pic->patCode;
    	palette_number 	= pic->visPal;
    }

    if(pic->mode==plEDITOR) {
		PCRD = PCRDED;
    } else {
		PCRD = PCRDEX;
    }

    position = 0;
	while(PeekInput()!=0xFF&&position<pic->offset) {
    	picOps[GetInput()&0xF].func();
	}        


    if((ver==sv_PT_VGA10||ver==sv_PT_AMIGA10)&&!sci1Pal)
    	sci1Pal = SCI1PalLoad(defPalette,0x504,FALSE);

               /*
    U8 *p,*q;
    long c;
    c = sPIC_SIZE;
    p = (U8*)pic->bitmaps[asVISUAL];
    q = (U8*)bmVis;

    while(c) {
    	*p &= (*q)^0xFF;
    	*p |= (*q);
        p++;
        q++;
        c--;
    }       */
    //if(picType!=sv_PT_EGA00) {
    	U8 *p,*q,*x;
    	long c;
    	c = sPIC_SIZE;
    	p = (U8*)pic->bitmaps[asVISUAL];
    	q = (U8*)bmVis;
    	x = (U8*)bmX;

        // yeah, two extra 64K arrays for the embedded cels, but hey,
        // sure beats a 64K+ cmps/jmps per draw!
    	while(c) {
            *p &= *x^0xFF;
            *p |= *q&*x;
        	p++;
        	q++;
            x++;
        	c--;
    	}
    //} else
    //	memcpy(pic->bitmaps[asVISUAL],bmVis,sPIC_SIZE);

    memcpy(pic->palette,palette,sizeof(palette));
    memcpy(pic->colLocked,colLocked,sizeof(colLocked));

    pic->drawenable 		= drawenable;
	pic->col[asPRIORITY] 	= priority;
    pic->col[asCONTROL]		= control;
	pic->col[asVISUAL]		= visIndex;
	pic->patNum	 			= pattern_nr;
    pic->patCode 			= pattern_code;   
    pic->palVGA				= sci1Pal;
}
/*****************************************************************************/
int PCRDEX(int x,int y) {
	return y*sPIC_WIDTH+x;
}
/*****************************************************************************/
int PCRDED(int x,int y) {
	return (sPIC_MAXY-y)*sPIC_WIDTH+x;
}
/*****************************************************************************/
void PlotPixEGA(U16 x, U16 y)
{
	if(x>=sPIC_WIDTH||y>=sPIC_HEIGHT) return;
	int p = PCRD(x,y);
	if(drawenable&DRAW_ENABLE_VISUAL)
    	bmVis[p]		= ((x^y)&1)?col1:col2;
	if(drawenable&DRAW_ENABLE_PRIORITY)
    	bitmaps[asPRIORITY][p]	= priority;
	if(drawenable&DRAW_ENABLE_CONTROL)
    	bitmaps[asCONTROL][p]		= control;

    bitmaps[asEXXO][p] |= drawenable;
}
/*****************************************************************************/
void PlotPixVGA(U16 x, U16 y)
{
	if(x>=sPIC_WIDTH||y>=sPIC_HEIGHT) return;
	int p = PCRD(x,y);
	if(drawenable&DRAW_ENABLE_VISUAL)
    	bmVis[p]		= visIndex;
	if(drawenable&DRAW_ENABLE_PRIORITY)
    	bitmaps[asPRIORITY][p]	= priority;
	if(drawenable&DRAW_ENABLE_CONTROL)
    	bitmaps[asCONTROL][p]		= control;

    bitmaps[asEXXO][p] |= drawenable;
}
/*****************************************************************************/
U8 GetPix(U16 x, U16 y, U16 screen)
{
  	return(bitmaps[screen][PCRD(x,y)]);
}
/*****************************************************************************/
void DrawPattern(U16 x, U16 y, BOOL solid, U16 pattern_size, U16 pattern_nr,
                 BOOL rectangle)
{

  int k, l, size;
  unsigned char junqbit = junqindex[pattern_nr];
  size = pattern_size;
  if (x<size) x=size;
  else if (x>320-size) x=319-size;
  if (y<size) y = size;
  else if (y>=190-size) y=189-size;
  if (rectangle) { /* rectangle */
    for (l=y-size; l<=y+size; l++) for (k=x-size; k<=x+size+1; k++) {
      if (solid) {
	if ((junq[junqbit>>3] >> (7-(junqbit & 7))) & 1) PlotPix(k, l);
	junqbit++;
	if (junqbit == 0xff) junqbit=0;
      }
      else PlotPix(k, l);
    }
  }
  else { /* circle */
    int circlebit = 0;
    for (l=y-size; l<=y+size; l++) for (k=x-size; k<=x+size+1; k++) {
      if ((circles[pattern_size][circlebit>>3] >> (7-(circlebit & 7))) & 1) {
	if (solid) {
	  if ((junq[junqbit>>3] >> (7-(junqbit & 7))) & 1) PlotPix(k, l);
	  junqbit++;
	  if (junqbit == 0xff) junqbit=0;
	}
	else PlotPix(k, l);
      }
      circlebit++;
    }
  }
}
/*****************************************************************************/
#define LINEMACRO(startx, starty, deltalinear, deltanonlinear, linearvar, nonlinearvar, \
                  linearend, nonlinearstart, linearmod, nonlinearmod) \
   x = (startx); y = (starty); \
   incrNE = ((deltalinear) > 0)? (deltalinear) : -(deltalinear); \
   incrNE <<= 1; \
   deltanonlinear <<= 1; \
   incrE = ((deltanonlinear) > 0) ? -(deltanonlinear) : (deltanonlinear);  \
   d = nonlinearstart-1;  \
   while (linearvar != (linearend)) { \
     PlotPix(x,y); \
     linearvar += linearmod; \
     if ((d+=incrE) < 0) { \
       d += incrNE; \
       nonlinearvar += nonlinearmod; \
     }; \
   }; \
   PlotPix(x,y);

void DitherLine(sPOINT from, sPOINT to)
{
	int dx, dy, incrE, incrNE, d, finalx, finaly;
	int x = from.x;
	int y = from.y;
	dx = to.x-from.x;
	dy = to.y-from.y;
	finalx = to.x;
	finaly = to.y;

	dx = abs(dx);
	dy = abs(dy);

	if (dx > dy) {
		if (finalx < x) {
			if (finaly < y) { /* llu == left-left-up */
				LINEMACRO(x, y, dx, dy, x, y, finalx, dx, -1, -1);
			} else {         /* lld */
				LINEMACRO(x, y, dx, dy, x, y, finalx, dx, -1, 1);
			}
		} else { /* x1 >= x */
			if (finaly < y) { /* rru */
				LINEMACRO(x, y, dx, dy, x, y, finalx, dx, 1, -1);
			} else {         /* rrd */
				LINEMACRO(x, y, dx, dy, x, y, finalx, dx, 1, 1);
			}
		}
	} else { /* dx <= dy */
		if (finaly < y) {
			if (finalx < x) { /* luu */
				LINEMACRO(x, y, dy, dx, y, x, finaly, dy, -1, -1);
			} else {         /* ruu */
				LINEMACRO(x, y, dy, dx, y, x, finaly, dy, -1, 1);
			}
		} else { /* y1 >= y */
			if (finalx < x) { /* ldd */
				LINEMACRO(x, y, dy, dx, y, x, finaly, dy, 1, -1);
			} else {         /* rdd */
				LINEMACRO(x, y, dy, dx, y, x, finaly, dy, 1, 1);
			}
		}
	}
}
/*****************************************************************************/
/*BOOL fillboundary(S16 fx, S16 fy)
{
	if( fx<0 || fx>=sPIC_WIDTH || fy<0 || fy>=sPIC_HEIGHT )
    	return TRUE;

	return  ((drawenable & GetPix(fx, fy, asEXXO)) &&
			      !((drawenable&DRAW_ENABLE_VISUAL) && (GetPix(fx, fy, asVISUAL)==15)));
}                */

#define FILL_BOUNDS(fx, fy) ((drawenable & GetPix(fx, fy, asEXXO)) && \
			      !((drawenable&DRAW_ENABLE_VISUAL) && ((GetPix(fx, fy, asBITMAP)==15))))
#define FILL_BOUNDS2(fx, fy) ((drawenable & GetPix(fx, fy, asEXXO)) && \
			      !((drawenable&DRAW_ENABLE_VISUAL) && (picType==sv_PT_EGA00)))
/*****************************************************************************/
/*void fillhelp(int xstart, int xend, int y, int direction)
{
	y += direction;
    if(!CHECK_Y(y)) return;
  	FIX_X(xstart);
  	FIX_X(xend);
	int xright = xstart, xleft = xstart;
		if(!fillboundary(xleft, y)) {
			while(xleft > 0 && !fillboundary(xleft-1, y))
            	xleft--;
			for(xright = xleft; xright < sPIC_WIDTH && !fillboundary(xright, y); xright++)
				PlotPix(xright, y);
      		if(xleft < xstart) fillhelp(xleft, xstart, y, -direction);
      			fillhelp(xleft, xright-1, y, direction);
    	}
    	while(xright <= xend) {
      		while(fillboundary(xright, y)) {
				xright++;
				if(xright > xend)
                	return;
      		}
      		xleft = xright;                                                       
      		while(xright<sPIC_WIDTH && !fillboundary(xright, y)) {
				PlotPix(xright, y);
				xright++;
      		}
      		fillhelp(xleft, xright-1, y, direction);
    	}
    	xright--;
    	if(xright > xend)
        	fillhelp(xend, xright, y, -direction);
} */
/*****************************************************************************/
/*void DitherFill(int x, int y)
{
  int  xstart, xend;
  if(!CHECK_RECT(x,y)) return;
  if(fillboundary(x,y)) return;

  for (xstart = x; xstart >= 0 && !fillboundary(xstart, y); xstart--)
    PlotPix(xstart, y);
  xstart++;
  for(xend = x+1; xend < sPIC_WIDTH && !fillboundary(xend, y); xend++)
  	PlotPix(xend, y);
  xend--;
  fillhelp(xstart, xend, y, 1);
  fillhelp(xstart, xend, y, -1);
}          */       /*
void BrisFillHelp(int x, int y, int direction)
{
	x += direction;
  	if(!CHECK_X(x)) return;
    if(FILL_BOUNDS(x, y)) return;

	for(int nY=y;nY>=0&&!FILL_BOUNDS(x,nY);nY--) {
    	PlotPix(x, nY);
        BrisFillHelp(x, nY, +1);
        BrisFillHelp(x, nY, -1);
    }
	for(int nY=y+1;nY<sPIC_HEIGHT&&!FILL_BOUNDS(x,nY);nY++) {
  		PlotPix(x, nY);
        BrisFillHelp(x, nY, +1);
   		BrisFillHelp(x, nY, -1);
    }
}
void DitherFill(S16 x, S16 y)
{
	if(!CHECK_RECT(x,y)) return;
	if(FILL_BOUNDS(x,y)) return;

	for(int nY=y; nY>=0 && !FILL_BOUNDS(x,nY); nY--)
  		PlotPix(x, nY);
	for(int nY=y+1; nY<sPIC_HEIGHT && !FILL_BOUNDS(x,nY); nY++)
  		PlotPix(x, nY);

	BrisFillHelp(x, y, +1);
	BrisFillHelp(x, y, -1);
}        */        
/* QUEUE DEFINITIONS */

#define MAX ((S32)sPIC_SIZE)
#define EMPTY ((S32)-1)

sPOINT buf[MAX+1];
S32 rpos, spos;     
sPOINT pEmpty={EMPTY,EMPTY};

BOOL qstore(S16 x,S16 y)
{
   if (rpos==MAX)
      return FALSE;
   buf[rpos].x = x;
   buf[rpos].y = y;
   rpos++;
   return TRUE;
}

sPOINT qretrieve()
{
   if (!rpos) {
      return pEmpty;
   }
   rpos--;
   return buf[rpos];
}

#define okToFill(x,y) (CHECK_RECT(x,y)&&!FILL_BOUNDS(x,y))
void DitherFill(S16 x, S16 y)
{
	sPOINT p;
    clock_t clStart;
	clStart = clock();


	if(!CHECK_RECT(x,y)||FILL_BOUNDS2(x,y)||FILL_BOUNDS(x,y)) return;
	S16 x1, y1;
	rpos = spos = 0;

	if(!qstore(x,y)) return;

	for (;;) {
    	if(clock()-clStart>400)
        	return;
      p = qretrieve();
      x1 = p.x;
      y1 = p.y;

      if ((x1 == EMPTY) || (y1 == EMPTY))
	 return;
      else {

	 if (okToFill(x1,y1)) {

	    PlotPix(x1, y1);

	    if (okToFill(x1, y1-1) && (y1!=0)) {
	       if(!qstore(x1,y1-1)) return;
	    }
	    if (okToFill(x1-1, y1) && (x1!=0)) {
	       if(!qstore(x1-1,y1)) return;
	    }
	    if (okToFill(x1+1, y1) && (x1!=sPIC_MAXX)) { 
	       if(!qstore(x1+1,y1)) return;
	    }
	    if (okToFill(x1, y1+1) && (y1!=sPIC_MAXY)) {
	       if(!qstore(x1,y1+1)) return;
	    }

	 }

      }

   }
}
/*****************************************************************************/


/*****************************************************************************/
#define GET_PAL(p,c,n) \
	((p==0)?(colLocked[c]?0:n):p)
void picop_SetColour()
{
	U8 index = GetInput();
	if(GET_PALDEX(index)<3) { // palette 3 works, but the interpreter ignores draws of 3
    	visIndex = index;
		U8 code = palette[GET_PAL(GET_PALDEX(index),GET_PALCOL(index),palette_number)][GET_PALCOL(index)];
		col1 = (code>>4)&0xF;
		col2 = code&0xF;
		drawenable |= DRAW_ENABLE_VISUAL;
	} else {
		drawenable &= ~DRAW_ENABLE_VISUAL;
    }
}
/*****************************************************************************/
void picop_DisableVisual()
{
	drawenable &= ~DRAW_ENABLE_VISUAL;
}
/*****************************************************************************/
void picop_SetPriority()
{
	priority = GetInput() & 0xf;
	drawenable |= DRAW_ENABLE_PRIORITY;
}
/*****************************************************************************/
void picop_DisablePriority()
{
	drawenable &= ~DRAW_ENABLE_PRIORITY;
}
/*****************************************************************************/
void picop_RelativePatterns()
{
	GetPattern();

	coords = GetAbsCoordinates();

	DrawPattern(coords.x, coords.y,
		pattern_code & PATTERN_FLAG_USE_PATTERN,
		pattern_size, pattern_nr, pattern_code & PATTERN_FLAG_RECTANGLE);

	while (PeekInput() < 0xf0) {
		GetPattern();
		coords = GetRel4Coordinates(coords.x,coords.y);
		DrawPattern(coords.x, coords.y,
			pattern_code & PATTERN_FLAG_USE_PATTERN,
			pattern_size, pattern_nr, pattern_code & PATTERN_FLAG_RECTANGLE);
	}
}
/*****************************************************************************/
void picop_MediumLines()
{
	oldCoords = GetAbsCoordinates();
	while (PeekInput() < 0xf0) {
		coords = GetRel8Coordinates(oldCoords.x, oldCoords.y);
        DitherLine(oldCoords, coords);
        oldCoords = coords;
	}
}
/*****************************************************************************/
void picop_LongLines()
{
	oldCoords =  GetAbsCoordinates();
	while (PeekInput() < 0xf0) {
		coords = GetAbsCoordinates();
        DitherLine(oldCoords, coords);
        oldCoords = coords;
    }
}
/*****************************************************************************/
void picop_ShortLines()
{
	oldCoords =  GetAbsCoordinates();
	while (PeekInput() < 0xf0) {
		coords = GetRel4Coordinates(oldCoords.x, oldCoords.y);
        DitherLine(oldCoords, coords);
        oldCoords = coords;
	}
}
/*****************************************************************************/
void picop_Fill()
{
	while (PeekInput() < 0xf0) {
		coords = GetAbsCoordinates();
		DitherFill(coords.x, coords.y);
	}
}
/*****************************************************************************/
void picop_SetPattern()
{
	pattern_code = GetInput() & 0x37;
	pattern_size = pattern_code & 0x7;
}
/*****************************************************************************/
void picop_AbsolutePattern()
{
	while (PeekInput() < 0xf0) {
		GetPattern();

        coords = GetAbsCoordinates();
        DrawPattern(coords.x, coords.y,
        	pattern_code & PATTERN_FLAG_USE_PATTERN,
            pattern_size, pattern_nr, pattern_code & PATTERN_FLAG_RECTANGLE);
	}
}
/*****************************************************************************/
void picop_SetControl()
{
	control = GetInput() & 0x0f;
	drawenable |= DRAW_ENABLE_CONTROL;
}
/*****************************************************************************/
void picop_DisableControl()
{
	drawenable &= ~DRAW_ENABLE_CONTROL;
}
/*****************************************************************************/
void picop_MediumPatterns()
{
	GetPattern();

	oldCoords =  GetAbsCoordinates();

	DrawPattern(oldCoords.x, oldCoords.y,
			 pattern_code & PATTERN_FLAG_USE_PATTERN,
			 pattern_size, pattern_nr, pattern_code & PATTERN_FLAG_RECTANGLE);

	while (PeekInput() < 0xf0) {
		GetPattern();
		coords = GetRel8Coordinates(oldCoords.x, oldCoords.y);
		DrawPattern(coords.x, coords.y,
				 pattern_code & PATTERN_FLAG_USE_PATTERN,
				 pattern_size, pattern_nr, pattern_code & PATTERN_FLAG_RECTANGLE);
        oldCoords = coords;
	}
}
/*****************************************************************************/
void picop_Ext_DrawVisBitmap(U8 bitType)
{
    int x,y,x1,x2,y1,y2,width,height;
    U8 transCol,mirror;
	U8 *endPtr,*bits;
    U16 endPos = position+5+(ssBGetW(ptr+3));
    endPtr = picStart+endPos;

    x = ptr[1];
    y = ptr[2];
	width = ssBGetW(ptr+5);
	height = ssBGetW(ptr+7);
 	transCol = ptr[9];
 	mirror = ptr[10];
    bits = (U8*)ssAlloc(width*height);
	if(bitType==0)
    	DecodeSCI0Bits(ptr+12, bits, width, height, transCol, mirror);
    else if(bitType==1)
    	DecodeSCI1Bits(ptr+12, bits, width, height, transCol, mirror);
    else
    	DecodeSCIAmigaBits(ptr+12, bits, width, height, transCol, mirror);
  	x2 = x+width;
    if(x2>sPIC_WIDTH)
    	x2 = sPIC_WIDTH;
  	y2 = y+height;
    if(y2>sPIC_HEIGHT)
    	y2 = sPIC_HEIGHT;
    int yA=y;
    int yB=0;
    for(y1=y;y1<y2;y1++) {
        yA = PCRD(x,y1);
        memcpy(bitmaps[asVISUAL]+yA,bits+yB,width);
		for(x1=0;x1<width;x1++) {
            bitmaps[asEXXO][yA+x1] |= DRAW_ENABLE_VISUAL;
            bmX[yA+x1] = 0;
        }    
        yB+=width;
    }
    ssFree(bits);

    position = endPos;
    ptr = endPtr;
}
/*****************************************************************************/
void picop_Ext()
{
	U8 code,index,i;
	code = GetInput();
	switch(code) {
		case 0x00: /* PIC_OPX_SET_PALETTE_ENTRY */
			while(PeekInput() < 0xf0) {
				index = GetInput();
				palette[GET_PALDEX(index)][GET_PALCOL(index)] = GetInput();
            	if(GET_PALDEX(index)==0)
                	colLocked[GET_PALCOL(index)] = TRUE;
			}
			break;
		case 0x01: /* PIC_OPX_SET_PALETTE */
        	if(picType==sv_PT_VGA10) {
            	picop_Ext_DrawVisBitmap(1);
            } else if(picType==sv_PT_AMIGA10) {
            	picop_Ext_DrawVisBitmap(2);
            } else {
				index = GetInput();
				for(i = 0; i <40; i++)
					palette[index][i] = GetInput();
            }
			break;

		case 0x02: /* PIC_OPX_MONO0 */
        	if(picType==sv_PT_VGA10) {
				SCI1PalDispose(sci1Pal);
            	sci1Pal = SCI1PalLoad(ptr,0x504,TRUE);
            	sci1Pal->SET = TRUE;
				SkipInput(0x504);
            } else {
				SkipInput(41);
            }
			break;

		case 0x03: /* PIC_OPX_MONO1 */
			SkipInput(1);
			break;

		case 0x04: /* PIC_OPX_MONO2 */
        	if(picType==sv_PT_VGA10) {
            	SkipInput(14);
                break;
            }
		case 0x05: /* PIC_OPX_MONO3 */
			SkipInput(1);
			break;

		case 0x06: /* PIC_OPX_MONO4 */
			break;
		case 0x07: /* PIC_OPX_EMBEDDED_VIEW */ /* SCI01 operation */
        	if(picType==sv_PT_EGA10) {
            	picop_Ext_DrawVisBitmap(0);
            }
			break;    
		case 0x08: /* PIC_OPX_SET_PRIORITY_TABLE */ /* SCI01 operation */
        	if(picType==sv_PT_EGA10) {
            	SkipInput(14);
                break;
            }
            break;
	}
}
/*****************************************************************************/
void picop_SkipSet()
{
	GetInput();
}
/*****************************************************************************/
void picop_SkipNothing()
{
	//nothing
}
/*****************************************************************************/
void picop_SkipRelativePatterns()
{
	GetPattern();

	SkipInput(3);
	while (PeekInput() < 0xf0) {
		GetPattern();
		GetInput();
	}
}
/*****************************************************************************/
void picop_SkipMediumLines()
{
	SkipInput(3);
	while (PeekInput() < 0xf0) {
		SkipInput(2);
	}
}
/*****************************************************************************/
void picop_SkipAbs()
{
	while (PeekInput() < 0xf0)
		SkipInput(3);
}
/*****************************************************************************/
void picop_SkipShortLines()
{
	SkipInput(3);
	while (PeekInput() < 0xf0) {
		GetInput();
	}
}
/*****************************************************************************/
void picop_SkipSetPattern()
{
	pattern_code = GetInput() & 0x37;
	pattern_size = pattern_code & 0x7;
}
/*****************************************************************************/
void picop_SkipAbsolutePattern()
{
	while (PeekInput() < 0xf0) {
		GetPattern();
        SkipInput(3);
	}
}
/*****************************************************************************/
void picop_SkipMediumPatterns()
{
	GetPattern();
	SkipInput(3);
	while (PeekInput() < 0xf0) {
		GetPattern();
		SkipInput(2);
	}
}
/*****************************************************************************/
void picop_SkipExt()
{
	U8 code;
    U16 size;
	code = GetInput();
	switch(code) {
		case 0x00: /* PIC_OPX_SET_PALETTE_ENTRY */
			while(PeekInput() < 0xf0) {
				SkipInput(2);
			}
			break;

		case 0x01: /* PIC_OPX_SET_PALETTE */
        	if(picType==sv_PT_VGA10) {
            	SkipInput(5+(ssBGetW(ptr+3)));
                break;
            }
			SkipInput(41);  
			break;
		case 0x02: /* PIC_OPX_MONO0 */   
        	if(picType==sv_PT_VGA10) {
            	SkipInput(0x504);
                break;
            }
			SkipInput(41);
			break;

		case 0x04: /* PIC_OPX_MONO2 */
        	if(picType==sv_PT_VGA10) {
            	SkipInput(14);
                break;
            }
		case 0x03: /* PIC_OPX_MONO1 */
		case 0x05: /* PIC_OPX_MONO3 */
			SkipInput(1);
			break;

		case 0x06: /* PIC_OPX_MONO4 */
			break;
		case 0x07: /* PIC_OPX_EMBEDDED_VIEW */ /* SCI01 operation */
        	if(picType==sv_PT_EGA10) {
            	SkipInput(5+(ssBGetW(ptr+3)));
                break;
            }
			break;
		case 0x08: /* PIC_OPX_SET_PRIORITY_TABLE */ /* SCI01 operation */
        	if(picType==sv_PT_EGA10) {
            	SkipInput(14);
                break;
            }
			break;
	}
}
/*****************************************************************************/
void picop_PrintSetVis()
{
	U8 index = GetInput();
    codeStr = IntToStr(GET_PALDEX(index))+":"+IntToHex(GET_PALCOL(index),2);
	//if(GET_PALDEX(index)==palette_number) {
		U8 code = palette[GET_PALDEX(index)][GET_PALCOL(index)];
		col1 = (code>>4)&0xF;
		col2 = code&0xF;
		drawenable |= DRAW_ENABLE_VISUAL;
	//}
}
/*****************************************************************************/
void picop_PrintSetPriCon()
{
    codeStr = IntToHex((U8)(GetInput() & 0xf),2);
}
/*****************************************************************************/
void picop_PrintRelativePatterns()
{
	GetPattern();

	coords = GetAbsCoordinates();

    AppendCoords(oldCoords);

	while (PeekInput() < 0xf0) {
		GetPattern();
		coords = GetRel4Coordinates(coords.x,coords.y);
    	AppendCoords(coords);
	}
}
/*****************************************************************************/
void picop_PrintMediumLines()
{
	oldCoords = GetAbsCoordinates();
    AppendCoords(oldCoords);
	while (PeekInput() < 0xf0) {
		coords = GetRel8Coordinates(oldCoords.x,oldCoords.y);
    	AppendCoords(coords);
        oldCoords = coords;
	}
}
/*****************************************************************************/
void picop_PrintAbs()
{
	while (PeekInput() < 0xf0)
		AppendCoords(GetAbsCoordinates());
}
/*****************************************************************************/
void picop_PrintShortLines()
{
	oldCoords =  GetAbsCoordinates();
    AppendCoords(oldCoords);
	while (PeekInput() < 0xf0) {
		oldCoords = GetRel4Coordinates(oldCoords.x, oldCoords.y);
    	AppendCoords(oldCoords);
	}
}
/*****************************************************************************/
void picop_PrintSetPattern()
{
	pattern_code = GetInput() & 0x37;
	pattern_size = pattern_code & 0x7;
    codeStr = IntToHex(pattern_code,2);
}
/*****************************************************************************/
void picop_PrintAbsolutePattern()
{
	while (PeekInput() < 0xf0) {
		GetPattern();
    	AppendCoords(GetAbsCoordinates());
	}
}
/*****************************************************************************/
void picop_PrintMediumPatterns()
{
	GetPattern();
	
	oldCoords =  GetAbsCoordinates();

    AppendCoords(oldCoords);

	while (PeekInput() < 0xf0) {
		GetPattern();
		coords = GetRel8Coordinates(oldCoords.x, oldCoords.y);
		AppendCoords(coords);
        oldCoords = coords;
	}
}
/*****************************************************************************/
void picop_PrintExt()
{
	U8 code,index,i;
	code = GetInput();
	switch(code) {
		case 0x00: /* PIC_OPX_SET_PALETTE_ENTRY */
        	codeStr = "Set Palette Entries:";
			while(PeekInput() < 0xf0) {
				index = GetInput();
				palette[GET_PALDEX(index)][GET_PALCOL(index)] = GetInput();
                codeStr = codeStr+" "+IntToStr(GET_PALDEX(index))+":"+IntToHex(GET_PALCOL(index),2)+"("+IntToHex(palette[GET_PALDEX(index)][GET_PALCOL(index)],2)+")";
			}
			break;

		case 0x01: /* PIC_OPX_SET_PALETTE */
        	if(picType==sv_PT_VGA10) {
            	SkipInput(5+(ssBGetW(ptr+3)));
                codeStr = "Draw Visual Bitmap";
                break;
            }
			index = GetInput();
        	codeStr = "Set Palette ("+IntToStr(index)+")";
			for(i = 0; i <40; i++)
				palette[index][i] = GetInput();
			break;

		case 0x02: /* PIC_OPX_MONO0 */    
        	if(picType==sv_PT_VGA10) {
            	SkipInput(0x504);
        		codeStr = "Set Palette";
                break;
            }
        	codeStr = "Mono #0";
			SkipInput(41);
			break;

		case 0x03: /* PIC_OPX_MONO1 */
        	codeStr = "Mono #1";
			SkipInput(1);
			break;

		case 0x04: /* PIC_OPX_MONO2 */
        	if(picType==sv_PT_VGA10) {
            	for(int i=0;i<14;i++)
                	priBars[i] = ptr[i];
				SkipInput(14);
        		codeStr = "Set Priority Bars";
                break;
            }
        	codeStr = "Mono #2";
			SkipInput(1);
            break;
		case 0x05: /* PIC_OPX_MONO3 */
        	codeStr = "Mono #3";
			SkipInput(1);
			break;

		case 0x06: /* PIC_OPX_MONO4 */
        	codeStr = "Mono #4";
			break;
		case 0x07: /* PIC_OPX_EMBEDDED_VIEW */ /* SCI01 operation */
        	codeStr = "Embedded View";
        	if(picType==sv_PT_EGA10) {
            	SkipInput(5+(ssBGetW(ptr+3)));
                break;
            }
            break;
		case 0x08: /* PIC_OPX_SET_PRIORITY_TABLE */ /* SCI01 operation */
        	codeStr = "Set Priority Bars";
        	if(picType==sv_PT_EGA10) {
            	SkipInput(14);
                break;
            }
			break;
	}
}
/*****************************************************************************/

