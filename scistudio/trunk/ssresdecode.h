//---------------------------------------------------------------------------
// SCI Studio 3+
// http://scistudio.sf.net/
//---------------------------------------------------------------------------
#ifndef _ssresdecode_h_
#define _ssresdecode_h_      
//---------------------------------------------------------------------------
#include "SynEditHighlighter.hpp"
#include "SynHighlighterSCI.hpp"
#include "SynMemo.hpp"
#include "SynEdit.hpp"
#include "SynEditExport.hpp"
#include "SynEditPrint.hpp"
#include "SynEditPrintPreview.hpp"
#include "SynExportHTML.hpp"

//---------------------------------------------------------------------------
typedef struct {
    int bitdepth;
	TColor cols[256];
	U32 wCols[256];
    PLOGPALETTE lPal;
    HPALETTE handle;
} tPAL;

typedef struct {
	U8 infoBits;
    U8 red;
    U8 green;
    U8 blue;
} sciCOL;

typedef struct _sciPALETTE {
	sciCOL cols[256];
    tPAL pal;
    BOOL SET;   
    BOOL FIXED;
    int maxCol;
} sciPALETTE;

extern tPAL palEGA,palFont,palCursor,palCursorVGA;
extern sciCOL amiga4096[4096];
//---------------------------------------------------------------------------
#define		sCEL_ISMIRROR(l,c) (c->loop!=l->loop)

typedef struct _sciVIEWCEL {
	// next entries
	_sciVIEWCEL *prev;
	_sciVIEWCEL *next;
	U16 loop,cel; // the cel's loop and cel indexes--not necessarily the
    			  // physical loops and cels if it's mirrored
    // if the cel is not a mirror, these store the info
	U16 width,height;
	S16 x,y;
    U8 transCol;
    U8 fFlipH; 		// mirror the bitmap
	U8 *data;
} sciVIEWCEL;

typedef struct _sciVIEWLOOP {
	// next entries
	_sciVIEWLOOP *prev;
	_sciVIEWLOOP *next;      
    // if the loop is a mirror of another, use this pointer for it
    // if the loop is not a mirror, this will be NULL
	_sciVIEWLOOP *mirror;
                              
	U16 loop;
    U16 totalCels;
    sciVIEWCEL *firstCel;
} sciVIEWLOOP;

typedef struct {
	U16 totalLoops;
    U16 maxWidth,maxHeight;
	sciVIEWLOOP *firstLoop;

    sciPALETTE *palVGA; // for VGA
} sciVIEW;
//---------------------------------------------------------------------------
#define sPIC_WIDTH 		320
#define sPIC_HEIGHT		190  
#define sPIC_MAXX		319
#define sPIC_MAXY		189
#define sPIC_SIZE		60800U
#define sPIC_TOTALBMPS	4

#define plEDITOR		1
#define plEXPLORER		2
typedef struct {
	U16 length,offset;
    U8 mode;
	U8 *data;
    U8 *bitmaps[sPIC_TOTALBMPS];

    U8 palette[4][40];     
    U8 colLocked[40];
    U8 drawenable;
    U8 col[3],visPal;
    U8 patCode,patNum;

    sciPALETTE *palVGA; // for VGA

    U16 priBars[14];

    S16 width,height,x,y;
    U8 transCol;
} sciPIC;
//---------------------------------------------------------------------------
typedef struct {
	U16 length;
    char *dump;
} sciSCRIPT;
//---------------------------------------------------------------------------
typedef struct {
	U16 length;
	U16 totalStrings;
	char *data;
} sciTEXT;
//---------------------------------------------------------------------------
typedef struct {
	U16 length;
	char *data;
} sciSOUND;
//---------------------------------------------------------------------------
//MEMORY not used
//---------------------------------------------------------------------------
typedef struct {
//	U16 length;
//	char *data;
} sciVOCAB000;

typedef struct {
    int Mask;
    char* Name;
} VOCTYPES;

#define vtNO_WORD   0x000
#define vtANY_WORD  0x4FF

#define vtiNO_WORD  0
#define vtiANY_WORD 11

#define TOTAL_VT    12

extern VOCTYPES vocabTypes[TOTAL_VT];
//---------------------------------------------------------------------------
typedef struct _sciFONTCHAR {
	_sciFONTCHAR *prev;
	_sciFONTCHAR *next;
	U16 index;
	U8 width,height;
	U8 *data;
} sciFONTCHAR;

typedef struct {
	U16 foo; // first two bytes--unknown or unused
	U16 totalChars;
	U16 height;
	sciFONTCHAR *firstChar,*lastChar;
} sciFONT;
//---------------------------------------------------------------------------
#define sCSR_WIDTH		16
#define sCSR_HEIGHT		16
#define sCSR_SIZE		256
#define sCSR_FILELEN		68
typedef struct {
	U16 hotSpotX;
	U16 hotSpotY;
	U16 hotSpot;
	U8 data[sCSR_SIZE];
} sciCURSOR;
//---------------------------------------------------------------------------
BOOL		 SaveResourceToFile(U8 type, U16 number, U8 *buf, U16 len, U8 mode);

void 		SetupSCIPal(sciPALETTE *pal);
sciPALETTE	*SCI1PalLoad(U8 *buf, U16 len,BOOL FIX);
sciPALETTE	*SCI11PalLoad(U8 *buf, U16 len,BOOL FIX);
void 		SCI1PalDisposeX(sciPALETTE **pal);
#define 	SCI1PalDispose(x) SCI1PalDisposeX(&x)
void		DecodeSCI1Bits(U8 *inBits, U8 *outBits, int width, int height, U8 transCol, BOOL mirLp);
U16 		EncodeSCI1Bits(U8 *inBits, U8 *outBits, int width, int height, U8 transCol, BOOL mirLp);
void		DecodeSCIAmigaBits(U8 *inBits, U8 *outBits, int width, int height, U8 transCol, BOOL mirLp);
void		DecodeSCI0Bits(U8 *inBits, U8 *outBits, int width, int height, U8 transCol, BOOL mirLp);
U16 		EncodeSCI0Bits(U8 *inBits, U8 *outBits, int width, int height, U8 transCol, BOOL mirLp);

sciVIEW		*ViewLoad(U8 *buf, U16 len, S16 ver); 		// load a view into an sciVIEW struct
U8 			*ViewSave(sciVIEW *view, U16 *len, S16 ver);	// save the view data, return it's data, and len
#define 	 ViewDispose(c) pViewDispose(&c)
void		 pViewDispose(sciVIEW **pView);
void		 ViewClearLoop(sciVIEWLOOP *loop);
BOOL		 ViewDeleteLoop(sciVIEW *view,sciVIEWLOOP *loop);
void 		 ViewDeleteCel(sciVIEWLOOP *loop,sciVIEWCEL *cel);
sciVIEWLOOP	*ViewFindLoopEntry(sciVIEW	*view, int e);
sciVIEWCEL  *ViewFindCelEntry(sciVIEWLOOP *loop, int e);
sciVIEWLOOP	*ViewGetLoop(sciVIEW	*view, int lp);
sciVIEWCEL	*ViewLoopGetCel(sciVIEWLOOP *loop, int cl);
sciVIEWLOOP	*GetRealLoop(sciVIEWLOOP *loop);
void		 ViewUnmirrorLoop(sciVIEWLOOP *loop);                                           
sciVIEWLOOP *ViewAddLoop(sciVIEW *view,int loopNum);
sciVIEWCEL  *ViewAddCel(sciVIEWLOOP *loop,int celNum, U8 fillCol, U16 width, U16 height);
sPOINT 		 GetLoopMaxSize(sciVIEWLOOP *loop);

sciPIC		*PicLoad(U8 *buf, U16 len,U8 mode, U8 defPal, S16 ver); 	// load a pic into an sciPIC struct
BOOL		 PicDraw(sciPIC *pic, S16 ver); 			// draw the pic from pic->data to pic->bitmap(s)
U8 			*PicSave(sciPIC *pic, U16 *len, S16 ver); // save the pic data, return it's data, and len
#define 	 PicDispose(c) pPicDispose(&c)
void		 pPicDispose(sciPIC **pPic);

sciFONT		*FontLoad(U8 *buf, U16 len);
U8 			*FontSave(sciFONT *font, U16 *len);
sciFONTCHAR	*GetFontChar(sciFONT *font, int index);
#define 	 FontDispose(c) pFontDispose(&c)
void		 pFontDispose(sciFONT **pFont);

sciCURSOR	*CursorLoad(U8 *buf, U16 len);
U8 			*CursorSave(sciCURSOR *cursor, U16 *len);
#define 	 CursorDispose(c) pCursorDispose(&c)
void		 pCursorDispose(sciCURSOR **pCursor);

void		 GetScriptInfo(U8 *ScrData, U16 Len,TSynMemo *Memo);
void 		TextToMemo(U8 *Data,U16 Len,TMemo *Memo);
void 		DecodeVocab(U8 *Data, int Num, U16 Len, TMemo *Memo);
void		MessageToMemo(U8 *Data,U16 Len,TMemo *Memo);
//---------------------------------------------------------------------------
#endif                                                                  
//---------------------------------------------------------------------------
