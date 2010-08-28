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
 * SCI Script Compiler Main Header
 ******************************************************************************/
#ifndef _SCC_SCC_H
#define _SCC_SCC_H
/******************************************************************************/
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <alloc.h>
#ifndef SCC_MACOS
	#include <mem.h>
#endif

#include "define.h"
#include "struct.h"
#include "dirlist.h"
/******************************************************************************/
/* SCC.C */
BOOL CompileScript(char *ScriptName, int Package);
BOOL PrecompileOne(void);
BOOL PrecompileTwo(void);
BOOL PrecompileThree(void);
BOOL FinalCompile(void);
void FreeEverything(void);
int ShowMessage(int Message, char *String, ...);
BOOL DoInclude(char *FileName, BOOL FULL_PROCESS);
void SetInBuf(char *NewPos);
BOOL SkipSegment(void);
BOOL CountStringSegment(void);
BOOL LoadObjectFile(char *FileName, BOOL FULL_PROCESS);
BOOL WriteObjectFile(void);
/* STRHNDLR.C */
char *GetNextWord(char **_Buf);
void SeekBack(char **_Buf);
int  StrToInt(char *String);
BOOL IsStringLabel(char *String);
int  IsStringName(char *String);
int  IsStringOperator(char *String);
int IsSegmentName(char *String);
BOOL IsStringNum(char *String);
BOOL IsLabelDefined(char *String);
int  IsObjectPropPtr(char *String);
int  GetSegmentIndex(char *String);
void CheckWordDefined(void);
tsSELFINFO GetClassIndex(char *String);
int  GetSelectorIndex(char *String, BOOL CAN_ADD);
int  GetPropertyInClass(int Class, int Index);
int  GetClassEntry(int Class);
int  GetPropertyIndex(int Class, char *String, BOOL INSTANCE);
int  AddString(char *String);
BOOL DoString(void);
int IsOpcodeName(char *String);
int  IsKernelName(char *String);
int  IsProcedureName(char *String);
int  IsExpProcedureName(char *String);
tsVARSTRUCT IsVarName(char *String);
int  IsStringInVocab(char *String);        
int  GetPropertyValue(char *String, int Class, int Property, BOOL INSTANCE);
BOOL SkipPropertyValue(void);
int  GetPropChange(int Class, int Property, BOOL INSTANCE);
/* VOCAB.C */
BOOL LoadVocab000(void);
BOOL LoadVocab900(void);
BOOL LoadVocab996(void);
BOOL WriteVocab996(void);
int  GetNextFreeClassIndex(void);
BOOL LoadVocab997(void);
BOOL WriteVocab997(void);
int  AddSelectorName(char *String);  
BOOL LoadVocab999(void);
/* CODE.C */
BOOL CompileCode(int FunctionType, BOOL _RET);
void WriteOpcode(BYTE Code, BOOL BFLAG);
void WriteOpInt(BYTE Code, int Value);
void WriteSendOpcode(void);
void SCIPush(int Value,BOOL SHORTEN);
void SCILDI(int Value);
void AddCodeB(BYTE Code);
void AddCodeW(int Code);
BOOL CompileGetVarCode(tsVARSTRUCT VarStruct, BYTE LoadTo);
BOOL CompileIfStatement(int FunctionType, int IfType);
BOOL CompileSwitch(int FunctionType);       
BOOL DoAssembly(int FunctionType);
BOOL CompileFor(int FunctionType);
BOOL CompileReturn(void);
int  CompileTempVar(void);
int  CompileSaid(void);
BOOL DoFunctionArgs(void);
void FreeVars(int Type);
BOOL SkipArrayInOut(void);
int  GetArraySize(int *OutVal);
int  HandleSend(int FunctionType);
int  SkipCodeBlock(void);
BOOL CompileChunk(BOOL fSTACK, int *_CodeBrackets, int FunctionType, BOOL GET_NEXT_WORD);
BOOL HandleGetVarProp(tsVS *ccVS, BOOL fSTACK, BYTE *OpRes, char**GVPInBuf, WORD *OldCodeBufOffset, BOOL *fADDITIONAL_INDEX, int FunctionType);
/******************************************************************************/
extern tsVERSION VERSION;

extern BOOL
	USE_DEFINES, IN_HEADER, V996_CHANGED, V999_CHANGED,
    IN_ASM_MODE;

#ifdef SCC_MSDOS
extern char far
#else       
extern char
#endif
	*InBuf;

extern char
	*OldBuf, *InBufStart, *ScriptPtr, ScriptName[256], IncludeFileName[128],
	TempString[2048],
	*StringInPtr,*LocalInPtr,*PublicInPtr,
	**ClassInPtr,**InstanceInPtr,**ProcedureInPtr, **SelectorNames,
	*StringSegment, *SynonymInPtr,
    **KernelNames,*KernelNamesBuf;

#ifdef SCC_MSDOS
extern BYTE far
#else
extern BYTE
#endif
	*OutBuf, *CodeBuf, *SaidSegment;

extern BYTE
	SynonymsSegment[256];

extern int
	ScriptNumber, CurrentClass, CurrentInstance, TotalPubProcs, TotalPubInstances,
    *Vocab996, FirstSameScript, TotalChgOffProp, TotalChgOffString,
    OldLine, TotalSynonyms, ResPackage, TotalLabels,TotalKernels;
extern WORD
	TotalDefines,TotalIncludes,TotalStrings,TotalSaid, TotalPublics,TotalRelocation,
	TotalVar[4],TotalLocalClasses,TotalInstances,TotalProcedures,
	LineNumber, Offset, CurrentDefine, TotalVoc0Words, CodeOffset,
	TotalSelectorNames, TotalGlobalClasses, TotalChgOffCode,  OldGlobalClasses,
	Relocation[512],StringSegLen, CodeBufOffset, StringsOffset,
	TotalExternalProcs, SaidSegLen, SaidOffset, MaxSelectorNames;
extern long
	SourceFileLen;
extern FILE
	*fHandle;
extern char *SegmentNames[], *ResNames[], *ResNamesShort[], *OpcodeNames[];
extern BOOL PRELOAD_TEXT;
extern BYTE OpArgs[TOTAL_OPCODES*2], OpArgTypes[TOTAL_OPCODES][3];
/******************************************************************************/
#define TOTAL_OPS 20
extern tsOPERATORS Operators[TOTAL_OPS];
#define TOTAL_IF_OPS 10
extern tsOPERATORS IfOperators[TOTAL_IF_OPS];
extern char *VarNames[4];
#define TOTAL_OBJPROPPTR 9
extern tsOBJPROPPTR ObjectPropPtr[TOTAL_OBJPROPPTR];
#define TOTAL_SAID_ARGS 10
extern tsSAIDARG SaidArgs[TOTAL_SAID_ARGS];
extern char *Errors[TOTAL_ERRORS];
/******************************************************************************/
extern tsDEFINE *Defines;
extern tsSTRING *Strings;
extern tsPUBLIC *Publics;
extern tsSAID *Said;
extern tsVAR *Var[4];
extern tsCLASS *sClasses, *Instances;
extern tsPROCEDURE *Procedures;
extern tsPUBPROC *ExternalProcs;
extern tsVOC000 *Voc000;
extern tsSELFINFO SelfInfo;
extern tsCHANGEOFFSET *ChgOffCode, *ChgOffString;
extern tsPROPCHANGEOFFSET *ChgOffProp;  
extern tsASMLABEL ASMLabels[MAX_LABELS];    
extern tsKRNLINFO KrnlInfo[114];
/******************************************************************************/
extern tsLOOPSTACK LoopStack[MAX_LOOP_STACK_SIZE];
extern int LoopStackCount;
/******************************************************************************/
#endif
/******************************************************************************/
/***************************************************************************
 *  Copyright (C) 1999-2001 Brian Provinciano, http://www.bripro.com
 ***************************************************************************/
