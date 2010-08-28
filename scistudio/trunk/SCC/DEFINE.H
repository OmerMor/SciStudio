/***************************************************************************
 *  SCI Studio: SCI Script Compiler
 *  Copyright (C) 2001 Brian Provinciano, http://www.bripro.com
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software Foundation,
 *  Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *  Notice
 *  You MUST distribute your source code if you release a program which
 *  uses ANY of my original source code. You MUST put my name in your
 *  program, source AND binary. You MUST leave this header in your source
 *
 *  Copyright (C) 1999-2001 Brian Provinciano, http://www.bripro.com
 ***************************************************************************/

/******************************************************************************
 * SCI Script Compiler Definitions
 ******************************************************************************/
#ifndef _SCC_DEFINE_H
#define _SCC_DEFINE_H
/******************************************************************************/
#ifndef SCC_MACOS
#    define TRUE 		1
#    define FALSE 		0
#endif                               
/******************************************************************************/
#ifndef SCC_MACOS
#   define fgetw(f) ((int)(fgetc(f)+(fgetc(f)<<8)))
#else
#   define fgetw(f) ((int)((fgetc(f)<<8)+fgetc(f)))
#endif
/******************************************************************************/
#define GET_PROPERTY_OFFSET(x) ((x<<1)+8)
/******************************************************************************/
#define SPECIAL_STRING_CHAR '\x01'
/******************************************************************************/
#define TOTAL_SEGMENTS				17

/* Script segments */
#define sgRETURN						0 /* Only used by compiler */
#define sgINSTANCE						1
#define sgCODE							2 /* Only used by compiler */
#define sgSYNONYM						3 /* Only used by compiler */
#define sgSAID                			4 /* Only used by compiler */
#define sgSTRINGS						5
#define sgCLASS               			6
#define sgPUBLIC						7
#define sgRELOCATION					8 /* Only used by compiler */
#define sgPRELOAD_TEXT        			9 /* Only used by compiler */
#define sgLOCAL		     				10

/* Compiler directives */
#define sgSCRIPT                	11
#define sgDEFINE                	12
#define sgINCLUDE               	13
#define sgUSE                  	14
#define sgPROCEDURE             	15
#define sgPUBLICS                   16
/******************************************************************************/
#define idVIEW                  0x80
#define idPIC                   0x81
#define idSCRIPT                0x82
#define idTEXT                  0x83
#define idSOUND                 0x84
#define idMEMORY                0x85
#define idVOCAB                 0x86
#define idFONT                  0x87
#define idCURSOR                0x88
#define idPATCH                 0x89
/******************************************************************************/
#define vGLOBAL						0
#define vLOCAL							1
#define vTEMP							2
#define vPARAM							3
/******************************************************************************/
#define MAX_SCRIPT_SIZE				65535u
#define MAX_SEGMENT_SIZE			0x3FFF
#define MAX_CHANGE_OFFSETS			512
#define MAX_LOOP_STACK_SIZE			64

/******************************************************************************/
#define otEMPTY     0
#define otVAR       2
#define otPVAR      3
#define otCLASS     4
#define otPROP      5
#define otSTRING    6
#define otSAID      7
#define otKERNEL    8
#define otLABEL     9
#define otPUBPROC   10
#define otINT       1
#define otINT8      11
#define otINT16     12
#define otOFFS      13

/******************************************************************************/
#define TOTAL_OPCODES 				    128

#define ccMETHOD						1
#define ccPROCEDURE					    2
#define ccPROCEDUREOF					3

#define ccACC							FALSE
#define ccSTACK						    TRUE

#define caCAN_ADD						TRUE
#define caCAN_NOT_ADD					FALSE

#define acBNOT							0
#define acADD							1
#define acSUB							2
#define acMUL							3
#define acDIV							4
#define acMOD							5
#define acSHR							6
#define acSHL							7
#define acXOR							8
#define acAND							9
#define acOR							10
#define acNEG							11
#define acNOT							12
#define acEQ							13
#define acNE							14
#define acGT							15
#define acGE							16
#define acLT							17
#define acLE							18
#define acUGT							19
#define acUGE							20
#define acULT							21
#define acULE							22
#define acBT							23
#define acBNT							24
#define acJMP							25
#define acLDI							26
#define acPUSH							27
#define acPUSHI						28
#define acTOSS							29
#define acDUP							30
#define acLINK							31
#define acCALL							32
#define acCALLK						33
#define acCALLB						34
#define acCALLE						35
#define acRET							36
#define acSEND							37
#define acCLASS						40
#define acSELF							42
#define acSUPER						43
#define acREST							44
#define acLEA							45
#define acSELFID						46
#define acPPREV						48
#define acPTOA							49
#define acATOP							50
#define acPTOS							51
#define acSTOP							52
#define acIPTOA						53
#define acDPTOA						54
#define acIPTOS						55
#define acDPTOS						56
#define acLOFSA						57
#define acLOFSS						58
#define acPUSH0						59
#define acPUSH1						60
#define acPUSH2						61
#define acPUSHSELF					62
#define acLAG							64
#define acLAL							65
#define acLAT							66
#define acLAP							67
#define acLSG							68
#define acLSL							69
#define acLST							70
#define acLSP							71
#define acLAGI							72
#define acLALI							73
#define acLATI							74
#define acLAPI							75
#define acLSGI							76
#define acLSLI							77
#define acLSTI							78
#define acLSPI							79
#define acSAG							80
#define acSAL							81
#define acSAT							82
#define acSAP							83
#define acSSG							84
#define acSSL							85
#define acSST							86
#define acSSP							87
#define acSAGI							88
#define acSALI							89
#define acSATI							90
#define acSAPI							91
#define acSSGI							92
#define acSSLI							93
#define acSSTI							94
#define acSSPI							95
#define acpAG							96
#define acpAL							97
#define acpAT							98
#define acpAP							99
#define acpSG							100
#define acpSL							101
#define acpST							102
#define acpSP							103
#define acpAGI							104
#define acpALI							105
#define acpATI							106
#define acpAPI							107
#define acpSGI							108
#define acpSLI							109
#define acpSTI							110
#define acpSPI							111
#define acnAG							112
#define acnAL							113
#define acnAT							114
#define acnAP							115
#define acnSG							116
#define acnSL							117
#define acnST							118
#define acnSP							119
#define acnAGI							120
#define acnALI							121
#define acnATI							122
#define acnAPI							123
#define acnSGI							124
#define acnSLI							125
#define acnSTI							126
#define acnSPI							127         
/******************************************************************************/
#define piAND 							1
#define piOR  							2

#define itIF							1
#define itDOWHILE						2
#define itWHILE						    3  
/******************************************************************************/
#define alLABEL                         1
#define alOFFSET                        2

#define MAX_LABELS                      384
#define MAX_LABELOFFSETS                128
/******************************************************************************/
#define TOTAL_SAID_ARGS                 10
/******************************************************************************/
#define smNONE							0
#define smERROR						    -1
#define smWARNING						-2
#define smCOMPILE						-3
#define smAPPEND						-4
/******************************************************************************/
#define errINBRACEXP      			1
#define errSEGNAMEEXP      	  	2
#define errOUTBRACEXP      	  	3
#define errINOROUTBRACEXP    	 	4
#define errSCRNUMALREADYDEF		5
#define errSAIDALREADYDEF			6
#define errSTRINGALREADYDEF		7
#define errPUBLICALREADYDEF		8
#define errLOCALALREADYDEF			9
#define errSCRIPTNUMNOTSPEC		10
#define errINTEXP						11
#define errQUOTEEXP					12
#define errINVHDRSEG					13
#define errVARNAMEEXP				14
#define errLABELAREADYDEF			15
#define errINVALIDVOCABHDR			16
#define errCLASSNAMEEXP				17
#define errSUPCLASSNAMEEXP       18
#define errPROPORMETHEXP			19
#define errPROPNAMEEXP				20
#define errEXPSYNTAX					21
#define errCOMMAOROUTBRACEXP		22
#define errMETHODNAMEEXP			23
#define errCLASSOFSAMECLASS		    24
#define errINSTANCENAMEEXP			25
#define errPROCNAMEEXP				26
#define errCLASSPTREXP				27
#define errEQUALEXP					28
#define errOPERATOREXP				29
#define errPLUSEXP					30
#define errMINUSEXP					31
#define errELSEEXP					32
#define errWHILEEXP					33
#define errINVALIDARGUMENT			34
#define errINVSWITCHARG				35
#define errCASEEXP					36
#define errINVALIDARGINIT           37
#define errUNDEFSYM                 38
#define errSTRNAMEEXP               39
#define errARRAYSTARTEXP            40
#define errARRAYENDEXP              41
#define errVARNAMEOROUTBRAC         42
#define errARRAYSIZEZ               43
#define errARRAYLTSTR               44
#define errQUOTEORINTEXP            45
#define errARRAYLTENTRIES           46
#define errLOCALVAREXP              47
#define errPROPERYNOTMEMBER         48
#define errINVSAID                  49
#define errWORDNIV                  50
#define errPARAMVAREXP              51
#define errUNDEFSELECTOR            52
#define errCLASSNOSUPER             53
#define errPROPNOTMEMBER            54
#define errSENDTOINST               55
#define errADDINGSELECTOR           56
#define errSELECTORNAMEEXP          57
#define errADDRPROP                 58
#define errPROPINDEX                59
#define errBADBREAK                 60
#define errEXPCLASSGOTIN            61
#define errCOLONEXP		            62
#define errVARCOLON					63
#define errTEXTEXP					64
#define errBADSCRIPTNUM					65
#define errSINGLEQUOTEEXP			66
#define errENDOFSTRINGEXP			67
#define errNOTANOPCODE              68
#define errKERNELEXP                69
#define errLABELTOOLONG             70
#define errMAXLABELS                71
#define errLABELUSED                72
#define errLABELUNDEF               73
#define errLABELOUTUSED             74
#define errMISSINGPROTOS            75

#define TOTAL_ERRORS                76
/******************************************************************************/
#endif
/******************************************************************************/
/***************************************************************************
 *  Copyright (C) 1999-2001 Brian Provinciano, http://www.bripro.com
 ***************************************************************************/
