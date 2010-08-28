//---------------------------------------------------------------------------
#ifndef _sseditors_h_
#define _sseditors_h_
//---------------------------------------------------------------------------
#define	ewSTAND_ALONE			((U16)0x0000)
#define	ewEXPLORER_EDITOR		((U16)0x0001) 
#define ewHEADER                ((U16)0x0010)
#define ewCLOSING_EXPLORER      ((U16)0x0800)
#define	ewRES_CHANGED			((U16)0x8000)
#define	ewRES_NEW				((U16)0x4000)
                                          
#define CLEAR_EXPLORERED() \
    EDTTAG->edtWnd->flags &= (~ewEXPLORER_EDITOR)
#define CLEAR_RESCHANGED() \
    EDTTAG->edtWnd->flags &= (~ewRES_CHANGED)
#define CLEAR_RESNEW() \
    EDTTAG->edtWnd->flags &= (~ewRES_NEW)
#define CHECK_EXPLORERED() \
    (EDTTAG->edtWnd->flags & ewEXPLORER_EDITOR)
#define CHECK_RESCHANGED() \
    (EDTTAG->edtWnd->flags & ewRES_CHANGED)
#define CHECK_HEADER() \
    (EDTTAG->edtWnd->flags & ewHEADER)
#define CHECK_RESNEW() \
    (EDTTAG->edtWnd->flags & ewRES_NEW)
#define SET_EXPLORERED() \
    EDTTAG->edtWnd->flags |= (ewEXPLORER_EDITOR)
#define SET_RESCHANGED() \
    EDTTAG->edtWnd->flags |= (ewRES_CHANGED)
#define SET_RESNEW() \
    EDTTAG->edtWnd->flags |= (ewRES_NEW)

#define CLEAR_FILENAME()\
	EDTTAG->edtWnd->fileName[0]='\0'
    
struct _EDTWND {
	_EDTWND *prev;  	// the linked list
	_EDTWND *next;

	TForm	*Wnd; 		// the editor window!
    RESTYPE	*resType; 	// the editor's resource type
    RESIDFO	resIDfo;	// the currently open resource

    U16		flags;
    	// ewSTAND_ALONE/ewEXPLORER_EDITOR -- if it was spawned from the IDE or explorer
		// ewRES_CHANGED -- for whether or not the app needs to ask the user to save or not
      	// ewCLOSING_EXPLORER
  	char	fileName[1024];

    TTabSheet *taskTab;

};
typedef struct _EDTWND EDTWND;
                
extern EDTWND *edtWndFirst,*edtWndLast;
extern int totalEdtWnds;
extern int winNum;

extern EDTWND edtWnds[TOTAL_RES_TYPES3];

extern EDTWND *scrEdtWnd;
//---------------------------------------------------------------------------
#define SVCHG_YES		1
#define SVCHG_NO		2
#define SVCHG_CANCEL	0
int ParseSaveChanges(EDTWND *edtWnd);

BOOL InitEditWnds(void);
BOOL DisposeEditWnds(void);
EDTWND *NewEditWnd(int resType, RESINFO *resInfo, U16 flags, U8 *resBuf, S16 resVer);
BOOL FreeEditWnd(EDTWND *edtWnd);

//---------------------------------------------------------------------------
#define UPDATE_CAPTION()\
	UpdateCaption(EDTTAG->edtWnd,this,AnsiString(EDTTAG->defCaption))
void UpdateCaption(EDTWND *edtWnd, TForm *Form, AnsiString DefCaption);

//---------------------------------------------------------------------------
typedef struct _EDITORTAG {
    void (*EditorClose)(_EDITORTAG *edtTag);
	BOOL (*QueryClose)(_EDITORTAG *edtTag);
    void (*SaveRes)(_EDITORTAG *edtTag);
    EDTWND *edtWnd;
    char defCaption[ssMAX_PATH_LEN];
    TForm *Form;
} EDITORTAG;
#define EDTTAG	((EDITORTAG*)Tag)
//---------------------------------------------------------------------------
#endif                                                                  
//---------------------------------------------------------------------------


 