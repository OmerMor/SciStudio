//---------------------------------------------------------------------------

#ifndef configH
#define configH
//---------------------------------------------------------------------------
#include "main.h"
//---------------------------------------------------------------------------
#define TOTAL_RTCOLS            6
#define REG_KEY_NAME   AnsiString("Software\\SCIStudio3")      
//---------------------------------------------------------------------------
extern char sCmdLine[1024];
//---------------------------------------------------------------------------
typedef struct {
	TColor Foreground,Background;
	TFontStyles Style;
} sHL;

typedef struct {
	char *Ext;
    char *Desc;
	BOOL Set;
} tsREGEXTSINFO;

typedef struct {
	BOOL	SHOW_SPLASH,
    		SHOW_WELCOME,
			QUERY_SAVING,
            SHOW_CLASS_REF,
            SHOW_KERNEL_REF;
    int		ewsDefResType,
    		ewsViewStyle,
            ewsRTSize[TOTAL_RTCOLS],
            ewsPreviewBarWidth,
            ewsManagerBarWidth,
            ewsPreviewBarV,
            ewsManagerBarV,
            maxUndos;

    BOOL	ewsSHOW_PREVIEW,
            ewsSHOW_RESCAP,
    		ewsFLAT_SCROLL,
            ewsGRID_LINES,
            ewsHOT_TRACK,
            ewsHAND_POINT,
            ewsUNDERLINEC,
            ewsUNDERLINEH,
            ewsSEP_SCR_WNDS;

	TFont	*shFont;
    TSynGutter	*shGutter;
    TSynEditorOptions	shOptions;
    int		shTabWidth;
    int		shExtraLineSpacing;

    sHL		shHighlights[hlTOTAL];
    BOOL	shHighlightsSET;

	AnsiString tbBitmapName;
	tsREGEXTSINFO RegExtInfo[4],PrevRegExtInfo[4];
} sCONFIG;

extern BOOL NO_KEY;
//---------------------------------------------------------------------------
extern sCONFIG config;
//---------------------------------------------------------------------------
#endif
 