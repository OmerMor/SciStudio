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
 * SCI Script Compiler Structures
 ******************************************************************************/
#ifndef _SCC_STRUCT_H
#define _SCC_STRUCT_H
/******************************************************************************/
    typedef unsigned char 	BYTE;
    typedef unsigned short 	WORD;
    typedef int				BOOL;
/******************************************************************************/
typedef struct {
	 BYTE Major, Minor, Build;
} tsVERSION;
/******************************************************************************/
typedef struct {
	char *Label,*Definition;
} tsDEFINE;

typedef struct {
	char *Label,*String;
	WORD Offset;
} tsSTRING;

typedef struct {
	char *Label;
	BYTE *Data;
} tsSAID;

typedef struct {
	 char *Label;
	 WORD Offset;
} tsPUBLIC;

typedef struct {
    char *Label;
    WORD Index;
    WORD Script;
} tsPUBPROC;

typedef struct {
	char *Label;
	WORD Value;
} tsVAR;

typedef struct {
	int Type, Index;
} tsVARSTRUCT;

typedef struct {
		  int Type,Index;
		  BOOL PROP;
} tsVS;

typedef struct {
	int   TotalProperties, TotalMethods;
	/* If the superclass is -1, none exists */
	int   Species, Superclass;
	/* The Selectors **/
	/* The index of the selector name for lookup and vocab.997 */
	int *PropertyNameIndexes;
	int *PropertyValues;
	/* The Methods */
	int  MethodNameIndexes[64];
	WORD MethodCodeOffsets[64];
	/* The ASCII name */
	char *Name;
	WORD NamePtr;

    BOOL PUBLIC;   /* make object exported in script */
    BOOL EXPORTED; /* from another script */
    WORD Offset;
} tsCLASS;

typedef struct {
	char *Label;
	int  Super;
	WORD Offset;
    BOOL PUBLIC;
} tsPROCEDURE;

typedef struct {
	 WORD Group;
	 char *String;
} tsVOC000;
                             
typedef struct {
    char Name[64];
    short Offset;
    short TotalOffsets;
    short Lns[MAX_LABELOFFSETS];
    short Offsets[MAX_LABELOFFSETS];
} tsASMLABEL;    

typedef struct {
	char *Ret,*Name,*Params;
} tsKRNLINFO;
/******************************************************************************/
typedef struct {
    char Character;
    BYTE Code;
} tsSAIDARG;

typedef struct {
    char *String;
    BYTE Code;
} tsOPERATORS;

typedef struct {
    char *String;
    int  Code;
} tsOBJPROPPTR;

typedef struct {
    BOOL INSTANCE;
    short  Index;
} tsSELFINFO;
/******************************************************************************/
typedef struct {
    BOOL REL,
	     STRING,
         SKIP,
         SAID,
         INSTANCE,
         CLASS;
    int  Procedure;
    WORD Offset,Class;
} tsCHANGEOFFSET;

typedef struct {
	int *BranchPos;
    int *TotalBranchPos;
} tsLOOPSTACK;
/******************************************************************************/
typedef struct {
	BOOL INSTANCE	,
         STRING 	,
         VAR     	,
         SAID       ;
    int  Class, Property;
    WORD Offset;
} tsPROPCHANGEOFFSET;
/******************************************************************************/
#endif
/******************************************************************************/
/***************************************************************************
 *  Copyright (C) 1999-2001 Brian Provinciano, http://www.bripro.com
 ***************************************************************************/
