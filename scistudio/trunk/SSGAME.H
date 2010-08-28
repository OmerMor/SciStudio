//---------------------------------------------------------------------------
#ifndef _ssgame_h_
#define _ssgame_h_
//---------------------------------------------------------------------------
#define ssGM_MAXPATH			1024
#define ssGM_MAXNAME			128

#define gfHAS_PROJECT			0x0001

#define svSCI_00_EARLY			0  // like KQ4
#define svSCI_00_LATE			1  // like LSL2/3
#define svSCI_10_EGA_EARLY		2  // like KQ1 remake
#define svSCI_10_EGA_LATE		3  // like QFG 2

//-- the freaked up version which is the exact same as the normal
//   VGA interpreter, but it uses EGA graphic resources
#define svSCI_10_EGA_LATEST		4  // like JITFL EGA

#define svSCI_10_VGA_EARLY		5  // like LSL1VGA
#define svSCI_10_AMIGA			6
#define svSCI_10_VGA_LATE		7  // like LSL5
#define svSCI_11_ORIGINAL		8  // like LSL6
#define svSCI_32				9  // like LSL7
#define svSCI_L					10  // INN
#define svTOTAL					11


#define sv_CL_EGA				1
#define sv_CL_VGA				2
#define sv_CL_AMIGA				3

#define sv_ST_SCI0a				1
#define sv_ST_SCI0b				2
#define sv_ST_SCI1				3
#define sv_ST_SCI11				4
#define sv_ST_SCI32				5

#define sv_VT_EGA				1
#define sv_VT_VGA10				2
#define sv_VT_AMIGA10			3
#define sv_VT_VGA11				4
#define sv_VT_VGA32				5

#define sv_PT_EGA00				1
#define sv_PT_EGA10				2
#define sv_PT_VGA10				3
#define sv_PT_AMIGA10			4
#define sv_PT_VGA11				5
#define sv_PT_VGA32				6

#define sv_CT_2COL				1
#define sv_CT_3COL				2

#define sv_FT_STD				1
#define sv_FT_EXT				2

#define sv_WT_00				1
#define sv_WT_10				2

#define sv_PALT_10				1
#define sv_PALT_AMIGA			2
#define sv_PALT_11				3

#define sv_MT_0					0
#define sv_MT_1					1
#define sv_MT_2					2
#define sv_MT_3					3
#define sv_MT_4					4
                               

#define svDECOMP_0				0
#define svDECOMP_1				1
#define svDECOMP_2				2
#define svDECOMP_3				3
#define svDECOMP_4				4
#define svDECOMP_5				5



#define GAME_USES_RES(r) ((GET_BIT32(Game.version->types,r))?TRUE:FALSE)


typedef struct {
	char	*name;
    U16		num;
    S16 	colours;
    S16		scrType;
    S16		viewType;
    S16		picType;
    S16		cursorType;
    S16		fontType;
    S16		wordsType;
    S16		palType;
    S16		mapType;
    S16 	maxEnc;
    S16		decType;
    U32		types;
} tsSCIVERSION;

typedef struct {
	char	path[ssGM_MAXPATH];
    char	name[ssGM_MAXNAME];
    U16		flags;
    U8		defaultPack;
    tsSCIVERSION *version;
} ssGAME;
                 
extern tsSCIVERSION versions[svTOTAL];
extern ssGAME	Game;
//---------------------------------------------------------------------------
BOOL LoadGame(char *gamePath);
void FreeGame(void);
//---------------------------------------------------------------------------
#endif                                                                  
//---------------------------------------------------------------------------

 