//---------------------------------------------------------------------------
#include "scihdr.h"
#include "main.h"
//---------------------------------------------------------------------------
ssGAME	Game;

tsSCIVERSION versions[svTOTAL] = {
	{
     	"SCI 0.000.xxx (ORIGINAL)",
       	svSCI_00_EARLY,
        sv_CL_EGA,
        sv_ST_SCI0a,
        sv_VT_EGA,
		sv_PT_EGA00,
        sv_CT_2COL,
        sv_FT_STD,
		sv_WT_00,  
        -1,
        sv_MT_0,
        2,
        svDECOMP_0,
        rfVIEW|rfPIC|rfSCRIPT|rfTEXT|rfSOUND|rfVOCAB|rfFONT|rfCURSOR|rfPATCH
    },
	{
     	"SCI 0.000.xxx (SECOND GEN)",
       	svSCI_00_LATE,
        sv_CL_EGA,
        sv_ST_SCI0b,
        sv_VT_EGA,
		sv_PT_EGA00,
        sv_CT_2COL,
        sv_FT_STD,  
		sv_WT_00,  
        -1,
        sv_MT_0,
        2,
        svDECOMP_0,
        rfVIEW|rfPIC|rfSCRIPT|rfTEXT|rfSOUND|rfVOCAB|rfFONT|rfCURSOR|rfPATCH
    },
	{
     	"SCI 1.000.xxx (EGA,ORIGINAL)",
       	svSCI_10_EGA_EARLY,
        sv_CL_EGA,
        sv_ST_SCI1,
        sv_VT_EGA,
		sv_PT_EGA10,
        sv_CT_2COL,
        sv_FT_EXT,
		sv_WT_10,   
        -1,
        sv_MT_0,
        2,
        svDECOMP_0,
        rfVIEW|rfPIC|rfSCRIPT|rfTEXT|rfSOUND|rfVOCAB|rfFONT|rfCURSOR|rfPATCH
    },
	{
     	"SCI 1.000.xxx (EGA,SECOND GEN)",
       	svSCI_10_EGA_LATE,
        sv_CL_EGA,
        sv_ST_SCI1,
        sv_VT_EGA,
		sv_PT_EGA10,
        sv_CT_2COL,
        sv_FT_EXT, 
		sv_WT_10,  
        -1,
        sv_MT_0,
        3,
        svDECOMP_1,
        rfVIEW|rfPIC|rfSCRIPT|rfTEXT|rfSOUND|rfVOCAB|rfFONT|rfCURSOR|rfPATCH
    },
	{
     	"SCI 1.000.xxx (EGA,THIRD GEN)",
       	svSCI_10_VGA_EARLY,
        sv_CL_EGA,
        sv_ST_SCI1,
        sv_VT_EGA,
		sv_PT_EGA10,
        sv_CT_2COL,
        sv_FT_EXT,
        sv_WT_10,
        -1,
        sv_MT_1,
        4,
        svDECOMP_2,
		rfVIEW|rfPIC|rfSCRIPT|rfTEXT|rfSOUND|rfVOCAB|rfFONT|rfCURSOR|rfPATCH|rfPALETTE
    },
	{
     	"SCI 1.000.xxx (VGA,ORIGINAL)",
       	svSCI_10_VGA_EARLY,
        sv_CL_VGA,
        sv_ST_SCI1,
        sv_VT_VGA10,
		sv_PT_VGA10,
        sv_CT_3COL,
        sv_FT_EXT,
        -1,
        sv_PALT_10,
        sv_MT_1,
        4,
        svDECOMP_2,
		rfVIEW|rfPIC|rfSCRIPT|rfTEXT|rfSOUND|rfVOCAB|rfFONT|rfCURSOR|rfPATCH|rfPALETTE
    },
	{
     	"SCI 1.000.xxx (AMIGA)",
       	svSCI_10_AMIGA,
        sv_CL_AMIGA,
        sv_ST_SCI1,
        sv_VT_AMIGA10,
		sv_PT_AMIGA10,
        sv_CT_3COL,
        sv_FT_EXT,
        -1,
        sv_PALT_AMIGA,
        sv_MT_1,
        4,
        svDECOMP_2,
		rfVIEW|rfPIC|rfSCRIPT|rfTEXT|rfSOUND|rfVOCAB|rfFONT|rfCURSOR|rfPATCH|rfPALETTE
    },
	{
     	"SCI 1.000.xxx (VGA,SECOND GEN)",
       	svSCI_10_VGA_LATE,
        sv_CL_VGA,
        sv_ST_SCI1,
        sv_VT_VGA10,
		sv_PT_VGA10,
        sv_CT_3COL,
        sv_FT_EXT,
        -1,
        sv_PALT_10,
        sv_MT_2,
        4,
        svDECOMP_2,
		rfVIEW|rfPIC|rfSCRIPT|rfTEXT|rfSOUND|rfVOCAB|rfFONT|rfCURSOR|rfPATCH|rfPALETTE
    },
	{
     	"SCI 1.001.xxx (ORIGINAL)",
       	svSCI_11_ORIGINAL,
        sv_CL_VGA,
        sv_ST_SCI11,
        sv_VT_VGA32,
		sv_PT_VGA11,
        sv_CT_3COL,
        sv_FT_EXT,   
        -1,
        sv_PALT_11,
        sv_MT_3,
        123,
        svDECOMP_3,
		rfVIEW|rfPIC|rfSCRIPT|rfTEXT|rfSOUND|rfVOCAB|rfFONT|rfCURSOR|rfPATCH|
        rfBITMAP|rfPALETTE|rfCDAUDIO|rfAUDIO|rfSYNC|rfMESSAGE|rfMAP|rfHEAP
    },
	{
     	"SCI32 (THE ULTIMATE SCI!)",
       	svSCI_32,
        sv_CL_VGA,
        sv_ST_SCI32,
        sv_VT_VGA32,
		sv_PT_VGA32,
        sv_CT_3COL,
        sv_FT_EXT,   
        -1,        
        sv_PALT_11,
        sv_MT_4,
        123,
        svDECOMP_4,
		rfVIEW|rfPIC|rfSCRIPT|rfTEXT|rfSOUND|rfVOCAB|rfFONT|rfCURSOR|rfPATCH|
        rfBITMAP|rfPALETTE|rfCDAUDIO|rfAUDIO|rfSYNC|rfMESSAGE|rfMAP|rfHEAP|
        rfCHUNK|rfAUDIO36|rfSYNC36|rfTRANSLATION|rfROBOT|rfVMD|rfDUCK|rfCLUT|
        rfTARGA|rfZZZ
    },
	{
     	"LSCI (On-Line SCI)",
       	svSCI_L,
        sv_CL_VGA,
        sv_ST_SCI1,
        sv_VT_VGA10,
		sv_PT_VGA10,
        sv_CT_3COL,
        sv_FT_EXT,
        -1,       
        sv_PALT_10,
        sv_MT_1,
        8,
        svDECOMP_5,
		rfVIEW|rfPIC|rfSCRIPT|rfTEXT|rfSOUND|rfVOCAB|rfFONT|rfCURSOR|rfPATCH|rfPALETTE
    }
};
//---------------------------------------------------------------------------
BOOL LoadGame(char *gamePath)
{
	if(strlen(gamePath)>=ssGM_MAXPATH) {
        ssMessage(ssERROR,"Game path too long!");
    	return FALSE;
    }
    strcpy(Game.path,gamePath);
    Game.flags = 0;

    Game.defaultPack = 1;

    if(!LoadMap()) {
    	WRITE_STATUS("Loading Game Failed!");
    	return FALSE;
    }
    WRITE_STATUS("Game Loaded.");
	return TRUE;
}
//---------------------------------------------------------------------------

void FreeGame()
{
    DisposeResInfo();
	//memset(&Game,0,sizeof(ssGAME));
}
//---------------------------------------------------------------------------


