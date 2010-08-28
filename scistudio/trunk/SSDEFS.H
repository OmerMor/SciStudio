//---------------------------------------------------------------------------
#ifndef _ssdefs_h_
#define _ssdefs_h_
//---------------------------------------------------------------------------
// data types
typedef unsigned char		U8;
typedef signed char			S8;
typedef unsigned short		U16;
typedef signed short		S16;
typedef unsigned long		U32;
typedef signed long			S32;

//---------------------------------------------------------------------------
// resources
#define TOTAL_RES_TYPES			28
#define TOTAL_RES_TYPES2		29
#define TOTAL_RES_TYPES3		30

#define rsVIEW                  0
#define rsPIC                   1
#define rsSCRIPT                2
#define rsTEXT                  3
#define rsSOUND                 4
#define rsMEMORY                5
#define rsVOCAB                 6
#define rsFONT                  7
#define rsCURSOR                8
#define rsPATCH                 9
#define rsBITMAP                10
#define rsPALETTE               11   
#define rsCDAUDIO              	12
#define rsAUDIO              	13
#define rsSYNC		           	14
#define rsMESSAGE           	15
#define rsMAP		         	16
#define rsHEAP		         	17
#define rsCHUNK					18
#define rsAUDIO36				19
#define rsSYNC36				20
#define rsTRANSLATION			21
#define rsROBOT					22
#define rsVMD					23
#define rsDUCK					24
#define rsCLUT					25
#define rsTARGA					26
#define rsZZZ					27

#define rfVIEW                  0x00000001
#define rfPIC                   0x00000002
#define rfSCRIPT                0x00000004
#define rfTEXT                  0x00000008
#define rfSOUND                 0x00000010
#define rfMEMORY                0x00000020
#define rfVOCAB                 0x00000040
#define rfFONT                  0x00000080
#define rfCURSOR                0x00000100
#define rfPATCH                 0x00000200
#define rfBITMAP                0x00000400
#define rfPALETTE               0x00000800
#define rfCDAUDIO              	0x00001000
#define rfAUDIO              	0x00002000
#define rfSYNC		           	0x00004000
#define rfMESSAGE           	0x00008000
#define rfMAP		         	0x00010000
#define rfHEAP		         	0x00020000
#define rfCHUNK					0x00040000
#define rfAUDIO36				0x00080000
#define rfSYNC36				0x00100000
#define rfTRANSLATION			0x00200000
#define rfROBOT					0x00400000
#define rfVMD					0x00800000
#define rfDUCK					0x01000000
#define rfCLUT					0x02000000
#define rfTARGA					0x04000000
#define rfZZZ					0x08000000

#define lvHEADER				28

#define wnEXPLORER				29

#define rsMAX_SIZE				64000u  // some like pics are actually less
	// than this (max @ 11-12K) --in theory it should be able to handle
    // 65535/6, but let's keep it at this :)



//---------------------------------------------------------------------------
#define SET_BIT32(f,n) \
	f |= (1<<(n&0x1F))
#define GET_BIT32(f,n) \
	((f >> (n&0x1F))&1)
#define CLEAR_BIT32(f,n) \
	f &= ~(1<<(n&0x1F))

#define SET_FLAG32(f,n) \
	f[(n>>5)] |= (1<<(n&0x1F))
#define GET_FLAG32(f,n) \
	((f[n>>5] >> (n&0x1F))&1)
#define CLEAR_FLAG32(f,n) \
	f[(n>>5)] &= ~(1<<(n&0x1F))

#define SET_FLAG(f,n) \
	f[(n>>3)] |= (1<<(n&7))
#define GET_FLAG(f,n) \
	((f[n>>3] >> (n&7))&1)
#define CLEAR_FLAG(f,n) \
	f[(n>>3)] &= ~(1<<(n&7))
//---------------------------------------------------------------------------
#define FULL_DELETE(b)\
	if(b) { delete b; b = NULL; } 
//---------------------------------------------------------------------------
typedef struct {
	S16 x,y;
} sPOINT;
//---------------------------------------------------------------------------
#define clMagicFrame		((TColor)0x00000000)
#define clMagicText			((TColor)0x00FFFFFF)
#define clMagicFace			((TColor)0x00FC9702)
#define clMagicShadow		((TColor)0x00ff6060)
#define clMagicHighlight	((TColor)0x00ffc680)
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------

 