//---------------------------------------------------------------------------
// SCI Studio 3+
// By Brian Provinciano
// www.bripro.com
// (c) 1999-2003 Brian Provinciano
//---------------------------------------------------------------------------

#ifndef picrenderH
#define picrenderH  
//---------------------------------------------------------------------------
#include "scihdr.h"
#include "main.h"
//---------------------------------------------------------------------------

#define DRAW_ENABLE_VISUAL   		1
#define DRAW_ENABLE_PRIORITY 		2
#define DRAW_ENABLE_CONTROL 		4
#define DRAW_ENABLE_X				8

#define PATTERN_FLAG_RECTANGLE		0x10
#define PATTERN_FLAG_USE_PATTERN	0x20

#define asVISUAL					0
#define asPRIORITY					1
#define asCONTROL					2
#define asEXXO						3 
#define asBITMAP					4
#define asTOTAL						4

#define GET_PALDEX(s) 				(s/40)
#define GET_PALCOL(s) 				(s%40)
#define SET_PALENT(p,i) 			((p*40)+i)

#define psBACKWARD					(-1)
#define psFORWARD					(+1)

#define VIEW_PRIORITY(y) (((y) < 42)? 0 : (((y) > 180)? 14 : 1\
	+ ((((y) - 42) * 13) / (180 - 42))))


#define FIX_X(x) \
	if(x<0) x=0; \
    else if(x>sPIC_MAXX) x=sPIC_MAXX
#define FIX_Y(y) \
	if(y<0) y=0; \
    else if(y>sPIC_MAXY) y=sPIC_MAXY
#define CHECK_RECT(x,y)\
	( x>=0 && x<sPIC_WIDTH && y>=0 && y<sPIC_HEIGHT )
#define CHECK_X(x)\
	(x>=0 && x<sPIC_WIDTH )
#define CHECK_Y(y)\
	(y>=0 && y<sPIC_HEIGHT )
//---------------------------------------------------------------------------
U16  PicSkipTo(sciPIC *pic, int pos);
U8 	 PicGetLastCode(sciPIC *pic);
U16  PicGetNextCmdOffset(sciPIC *pic);
U16  PicPrintCode(sciPIC *pic, BOOL);
void DrawPic(int CUMULATIVE, int defaultPalette, sciPIC *pic, S16);

void DrawPattern(U16 x, U16 y, BOOL solid, U16 pattern_size, U16 pattern_nr,
                 BOOL rectangle);
void DitherLine(sPOINT from, sPOINT to);
void DitherFill(S16 x, S16 y);

int PCRDEX(int x,int y);
int PCRDED(int x,int y);

void picop_SetColour(void);
void picop_DisableVisual(void);
void picop_SetPriority(void);
void picop_DisablePriority(void);
void picop_RelativePatterns(void);
void picop_MediumLines(void);
void picop_LongLines(void);
void picop_ShortLines(void);
void picop_Fill(void);
void picop_SetPattern(void);
void picop_AbsolutePattern(void);
void picop_SetControl(void);
void picop_DisableControl(void);
void picop_MediumPatterns(void);
void picop_Ext(void);

void picop_SkipSet(void);
void picop_SkipNothing(void);
void picop_SkipRelativePatterns(void);
void picop_SkipMediumLines(void);
void picop_SkipAbs(void);
void picop_SkipShortLines(void);
void picop_SkipSetPattern(void);
void picop_SkipAbsolutePattern(void);
void picop_SkipMediumPatterns(void);
void picop_SkipExt(void);

void picop_PrintSetVis(void);
void picop_PrintSetPriCon(void);
void picop_PrintRelativePatterns(void);
void picop_PrintMediumLines(void);
void picop_PrintAbs(void);
void picop_PrintShortLines(void);
void picop_PrintSetPattern(void);
void picop_PrintAbsolutePattern(void);
void picop_PrintMediumPatterns(void);
void picop_PrintExt(void);

typedef struct {
	void (*func)(void);
} FUNC;

extern AnsiString codeStr;
//---------------------------------------------------------------------------
#endif
