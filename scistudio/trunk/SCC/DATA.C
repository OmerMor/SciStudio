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
 * SCI Script Compiler Compiler Data
 ******************************************************************************/
#include "scc.h"
/******************************************************************************/
#ifdef SCC_SCISTUDIO_WIN32
#pragma hdrstop
#pragma package(smart_init)
#endif
/******************************************************************************/
char *SegmentNames[] = {
	/* Script segments */
	"",               		/* 0. return */
	"instance",             /* 1. Object definition */
	"",                 	/* 2. Code (p-code instructions) */
	"synonyms",        		/* 3. Synonym word lists */
	"",                     /* 4. Said() Method arguments */
	"string",               /* 5. Vector of strings */
	"class",                /* 6. Class object definition */
	"",                     /* 7. Exports for external references */
	"",           			/* 8. Script offset relocation table */
	"preload",              /* 9. Preload text flag */
	"local",                /* 10.Local script variables */
	/* Compiler directives */
	"script",               /* 11.The number to save the script as (script.nnn) */
	"define",               /* 12. */
	"include",              /* 13. */
	"use",                  /* 14. */
	"procedure",            /* 15. Procedure - Callable code segments */
	"publics",              /* 16. Public Prototypes */
};
/******************************************************************************/
char *ResNames[] = {
    "View", "Pic", "Script", "Text", "Sound",
    "Memory", "Vocab", "Font","Cursor", "Patch"
};                
/******************************************************************************/
char *ResNamesShort[] = {
    "v56", "p56", "scr", "tex", "snd",
    "mem", "voc", "fon","cur", "pat"
};
/******************************************************************************/
BYTE OpArgs[256] = {
	/*bnot*/     0,0,
	/*add*/      0,0,
	/*sub*/      0,0,
	/*mul*/      0,0,
	/*div*/      0,0,
	/*mod*/      0,0,
	/*shr*/      0,0,
	/*shl*/      0,0,
	/*xor*/      0,0,
	/*and*/      0,0,
/*10*/
	/*or*/       0,0,
	/*neg*/      0,0,
	/*not*/      0,0,
	/*eq?*/      0,0,
	/*ne?*/      0,0,
	/*gt?*/      0,0,
	/*ge?*/      0,0,
	/*lt?*/      0,0,
	/*le?*/      0,0,
	/*ugt?*/     0,0,
/*20*/
	/*uge?*/     0,0,
	/*ult?*/     0,0,
	/*ule?*/     0,0,
	/*bt*/       2,1,
	/*bnt*/      2,1,
	/*jmp*/      2,1,
	/*ldi*/      2,1,
	/*push*/     0,0,
	/*pushi*/    2,1,
	/*toss*/     0,0,
/*30*/
	/*dup*/      0,0,
	/*link*/     2,1,
	/*call*/     3,2,
	/*callk*/    3,2,
	/*callb*/    3,2,
	/*calle*/    5,3,
	/*ret*/      0,0,
	/*send*/     1,1,
	/**/         0,0,
	/**/         0,0,
/*40*/
	/*class*/    2,1,
	/**/         0,0,
	/*self*/     0,0,
	/*super*/    3,2,
	/*rest*/    2,1,
	/*lea*/      2,1,
	/*selfID*/   0,0,
	/**/         0,0,
	/*pprev*/    0,0,
	/*pToa*/     2,1,
/*50*/
	/*aTop*/     2,1,
	/*pTos*/     2,1,
	/*sTop*/     2,1,
	/*ipToa*/    2,1,
	/*dpToa*/    2,1,
	/*ipTos*/    2,1,
	/*dpTos*/    2,1,
	/*lofsa*/    2,1,
	/*lofss*/    2,1,
	/*push0*/    0,0,
/*60*/
	/*push1*/    0,0,
	/*push2*/    0,0,
	/*pushSelf*/ 0,0,
	/**/         0,0,
	/*lag*/      2,1,
	/*lal*/      2,1,
	/*lat*/      2,1,
	/*lap*/      2,1,
	/*lsg*/      2,1,
	/*lsl*/      2,1,
/*70*/
	/*lst*/      2,1,
	/*lsp*/      2,1,
	/*lagi*/     2,1,
	/*lali*/     2,1,
	/*lati*/     2,1,
	/*lapi*/     2,1,
	/*lsgi*/     2,1,
	/*lsli*/     2,1,
	/*lsti*/     2,1,
	/*lspi*/     2,1,
/*80*/
	/*sag*/      2,1,
	/*sal*/      2,1,
	/*sat*/      2,1,
	/*sap*/      2,1,
	/*ssg*/      2,1,
	/*ssl*/      2,1,
	/*sst*/      2,1,
	/*ssp*/      2,1,
	/*sagi*/     2,1,
	/*sali*/     2,1,
/*90*/
	/*sati*/     2,1,
	/*sapi*/     2,1,
	/*ssgi*/     2,1,
	/*ssli*/     2,1,
	/*ssti*/     2,1,
	/*sspi*/     2,1,
	/*+ag*/      2,1,
	/*+al*/      2,1,
	/*+at*/      2,1,
	/*+ap*/      2,1,
/*100*/
	/*+sg*/      2,1,
	/*+sl*/      2,1,
	/*+st*/      2,1,
	/*+sp*/      2,1,
	/*+agi*/     2,1,
	/*+ali*/     2,1,
	/*+ati*/     2,1,
	/*+api*/     2,1,
	/*+sgi*/     2,1,
	/*+sli*/     2,1,
/*110*/
	/*+sti*/     2,1,
	/*+spi*/     2,1,
	/*-ag*/      2,1,
	/*-al*/      2,1,
	/*-at*/      2,1,
	/*-ap*/      2,1,
	/*-sg*/      2,1,
	/*-sl*/      2,1,
	/*-st*/      2,1,
	/*-sp*/      2,1,
/*120*/
	/*-agi*/     2,1,
	/*-ali*/     2,1,
	/*-ati*/     2,1,
	/*-api*/     2,1,
	/*-sgi*/     2,1,
	/*-sli*/     2,1,
	/*-sti*/     2,1,
	/*-spi*/     2,1
};
/******************************************************************************/
BYTE OpArgTypes[TOTAL_OPCODES][3] = {
	/*bnot*/     {0,0,0},
	/*add*/      {0,0,0},
	/*sub*/      {0,0,0},
	/*mul*/      {0,0,0},
	/*div*/      {0,0,0},
	/*mod*/      {0,0,0},
	/*shr*/      {0,0,0},
	/*shl*/      {0,0,0},
	/*xor*/      {0,0,0},
	/*and*/      {0,0,0},
/*10*/
	/*or*/       {0,0,0},
	/*neg*/      {0,0,0},
	/*not*/      {0,0,0},
	/*eq?*/      {0,0,0},
	/*ne?*/      {0,0,0},
	/*gt?*/      {0,0,0},
	/*ge?*/      {0,0,0},
	/*lt?*/      {0,0,0},
	/*le?*/      {0,0,0},
	/*ugt?*/     {0,0,0},
/*20*/
	/*uge?*/     {0,0,0},
	/*ult?*/     {0,0,0},
	/*ule?*/     {0,0,0},
	/*bt*/       {otLABEL,0,0},
	/*bnt*/      {otLABEL,0,0},
	/*jmp*/      {otLABEL,0,0},
	/*ldi*/      {otINT,0,0},
	/*push*/     {0,0,0},
	/*pushi*/    {otINT,0,0},
	/*toss*/     {0,0,0},
/*30*/
	/*dup*/      {0,0,0},
	/*link*/     {otINT,0,0},
	/*call*/     {otLABEL,otINT,0},
	/*callk*/    {otKERNEL,otINT8,0},
	/*callb*/    {otPUBPROC,otINT8,0},
	/*calle*/    {otINT,otPUBPROC,otINT8},
	/*ret*/      {0,0,0},
	/*send*/     {otINT8,0,0},
	/**/         {0,0,0},
	/**/         {0,0,0},
/*40*/
	/*class*/    {otCLASS,0,0},
	/**/         {0,0,0},
	/*self*/     {otINT8,0,0},
	/*super*/    {otCLASS,otINT8,0},
	/*rest*/    {otPVAR,0,0},
	/*lea*/      {otINT,otINT,0},
	/*selfID*/   {0,0,0},
	/**/         {0,0,0},
	/*pprev*/    {0,0,0},
	/*pToa*/     {otPROP,0,0},
/*50*/
	/*aTop*/     {otPROP,0,0},
	/*pTos*/     {otPROP,0,0},
	/*sTop*/     {otPROP,0,0},
	/*ipToa*/    {otPROP,0,0},
	/*dpToa*/    {otPROP,0,0},
	/*ipTos*/    {otPROP,0,0},
	/*dpTos*/    {otPROP,0,0},
	/*lofsa*/    {otOFFS,0,0},
	/*lofss*/    {otOFFS,0,0},
	/*push0*/    {0,0,0},
/*60*/
	/*push1*/    {0,0,0},
	/*push2*/    {0,0,0},
	/*pushSelf*/ {0,0,0},
	/**/         {0,0,0},
	/*lag*/      {otVAR,0,0},
	/*lal*/      {otVAR,0,0},
	/*lat*/      {otVAR,0,0},
	/*lap*/      {otVAR,0,0},
	/*lsg*/      {otVAR,0,0},
	/*lsl*/      {otVAR,0,0},
/*70*/
	/*lst*/      {otVAR,0,0},
	/*lsp*/      {otVAR,0,0},
	/*lagi*/     {otVAR,0,0},
	/*lali*/     {otVAR,0,0},
	/*lati*/     {otVAR,0,0},
	/*lapi*/     {otVAR,0,0},
	/*lsgi*/     {otVAR,0,0},
	/*lsli*/     {otVAR,0,0},
	/*lsti*/     {otVAR,0,0},
	/*lspi*/     {otVAR,0,0},
/*80*/
	/*sag*/      {otVAR,0,0},
	/*sal*/      {otVAR,0,0},
	/*sat*/      {otVAR,0,0},
	/*sap*/      {otVAR,0,0},
	/*ssg*/      {otVAR,0,0},
	/*ssl*/      {otVAR,0,0},
	/*sst*/      {otVAR,0,0},
	/*ssp*/      {otVAR,0,0},
	/*sagi*/     {otVAR,0,0},
	/*sali*/     {otVAR,0,0},
/*90*/
	/*sati*/     {otVAR,0,0},
	/*sapi*/     {otVAR,0,0},
	/*ssgi*/     {otVAR,0,0},
	/*ssli*/     {otVAR,0,0},
	/*ssti*/     {otVAR,0,0},
	/*sspi*/     {otVAR,0,0},
	/*+ag*/      {otVAR,0,0},
	/*+al*/      {otVAR,0,0},
	/*+at*/      {otVAR,0,0},
	/*+ap*/      {otVAR,0,0},
/*100*/
	/*+sg*/      {otVAR,0,0},
	/*+sl*/      {otVAR,0,0},
	/*+st*/      {otVAR,0,0},
	/*+sp*/      {otVAR,0,0},
	/*+agi*/     {otVAR,0,0},
	/*+ali*/     {otVAR,0,0},
	/*+ati*/     {otVAR,0,0},
	/*+api*/     {otVAR,0,0},
	/*+sgi*/     {otVAR,0,0},
	/*+sli*/     {otVAR,0,0},
/*110*/
	/*+sti*/     {otVAR,0,0},
	/*+spi*/     {otVAR,0,0},
	/*-ag*/      {otVAR,0,0},
	/*-al*/      {otVAR,0,0},
	/*-at*/      {otVAR,0,0},
	/*-ap*/      {otVAR,0,0},
	/*-sg*/      {otVAR,0,0},
	/*-sl*/      {otVAR,0,0},
	/*-st*/      {otVAR,0,0},
	/*-sp*/      {otVAR,0,0},
/*120*/
	/*-agi*/     {otVAR,0,0},
	/*-ali*/     {otVAR,0,0},
	/*-ati*/     {otVAR,0,0},
	/*-api*/     {otVAR,0,0},
	/*-sgi*/     {otVAR,0,0},
	/*-sli*/     {otVAR,0,0},
	/*-sti*/     {otVAR,0,0},
	/*-spi*/     {otVAR,0,0},
};
/******************************************************************************/
char *OpcodeNames[]={
	"bnot",
	"add",
	"sub",
	"mul",
	"div",
	"mod",
	"shr",
	"shl",
	"xor",
	"and",
	"or",
	"neg",
	"not",
	"eq?",
	"ne?",
	"gt?",
	"ge?",
	"lt?",
	"le?",
	"ugt?",
	"uge?",
	"ult?",
	"ule?",
	"bt",
	"bnt",
	"jmp",
	"ldi",
	"push",
	"pushi",
	"toss",
	"dup",
	"link",
	"call",
	"callk",
	"callb",
	"calle",
	"ret",
	"send",
    "",
    "",
	"class",
    "",
	"self",
	"super",
	"&rest",
	"lea",
	"selfID",  
    "",
	"pprev",
	"pToa",
	"aTop",
	"pTos",
	"sTop",
	"ipToa",
	"dpToa",
	"ipTos",
	"dpTos",
	"lofsa",
	"lofss",
	"push0",
	"push1",
	"push2",
	"pushSelf",  
    "",
	"lag",
	"lal",
	"lat",
	"lap",
	"lsg",
	"lsl",
	"lst",
	"lsp",
	"lagi",
	"lali",
	"lati",
	"lapi",
	"lsgi",
	"lsli",
	"lsti",
	"lspi",
	"sag",
	"sal",
	"sat",
	"sap",
	"ssg",
	"ssl",
	"sst",
	"ssp",
	"sagi",
	"sali",
	"sati",
	"sapi",
	"ssgi",
	"ssli",
	"ssti",
	"sspi",
	"+ag",
	"+al",
	"+at",
	"+ap",
/*100*/
	"+sg",
	"+sl",
	"+st",
	"+sp",
	"+agi",
	"+ali",
	"+ati",
	"+api",
	"+sgi",
	"+sli",
/*110*/
	"+sti",
	"+spi",
	"-ag",
	"-al",
	"-at",
	"-ap",
	"-sg",
	"-sl",
	"-st",
	"-sp",
/*120*/
	"-agi",
	"-ali",
	"-ati",
	"-api",
	"-sgi",
	"-sli",
	"-sti",
	"-spi"
};
#define TOTAL_OPS 20
tsOPERATORS Operators[] = {
    {"+",   acADD},
    {"-",   acSUB},
    {"*",   acMUL},
    {"/",   acDIV},
    {"<<",  acSHL},
    {">>",  acSHR},
    {"%",   acMOD},
    {"^",   acXOR},
    {"&",   acAND},
    {"|",   acOR}, /*
};
#define TOTAL_IF_OPS 10
tsOPERATORS IfOperators[] = {   */
    {"==",  acEQ},
    {"<>",  acNE},
    {"<",   acLT},
    {">",   acGT},
    {"<=",  acLE},
    {">=",  acGE},
    {"<u",  acULT},
    {">u",  acUGT},
    {"<=u", acULE},
    {">=u", acUGE},
};
/******************************************************************************/
tsKRNLINFO KrnlInfo[114] = {
	{"number","Abs","number value"},
	{"void","AddAfter","heapPtr pList, heapPtr afterNode, heapPtr pNode"},
	{"void","AddMenu","string caption, string itemCaptions"},
	{"void","AddToEnd","heapPtr pList, heapPtr pNode"},
	{"void","AddToFront","heapPtr pList, heapPtr pNode"},
	{"void","AddToPic","heapPtr viewList"},
	{"void","Animate","[heapPtr cast, bool cycle]"},
	{"void","BaseSetter","heapPtr viewObj"},
	{"bool","CanBeHere","heapPtr viewObj[, heapPtr pList]"},
	{"number","CelHigh","number view, number loop, number cel"},
	{"number","CelWide","number view, number loop, number cel"},
	{"bool","CheckFreeSpace","string directory"},
	{"bool","CheckSaveGame","string gameName, number slotNumber[, string gameVersion]"},
	{"heapPtr","Clone","heapPtr object"},
	{"number","CoordPri","number y"},
	{"number","CosDiv","number angle, number factor"},
	{"number","CosMult","number angle, number factor"},
	{"void","DeleteKey","heapPtr pList, number key"},
	{"heapPtr","DeviceInfo","diGET_DEVICE, string thePath, string strBuf"},
	{"void","DirLoop","heapPtr viewObj, number angle"},
	{"[heapPtr]","Display","string text[, params]"},
	{"void","DisposeClone","heapPtr object"},
	{"void","DisposeList","heapPtr pList"},
	{"void","DisposeScript","number scriptNum"},
	{"void","DisposeWindow","heapPtr Window"},
	{"void","DoAvoider","heapPtr moverObj"},
	{"bool","DoBresen","heapPtr moverObj"},
	{"void","DoSound","number subFunction, ..."},
	{"void","DrawCel","number view, number loop, number cel, point position, number priority"},
	{"void","DrawControl","heapPtr control"},
	{"void","DrawMenuBar","bool mode"},
	{"void","DrawPic","number picNum, [number animation, bool clear, number defaultPalette]"},
	{"void","DrawStatus","string text"},
	{"void","EditControl","heapPtr control, heapPtr event"},
	{"bool","EmptyList","heapPtr pList"},
	{"void","FClose","number handle"},
	{"number","FGets","string buffer, number max, number handle"},
	{"heapPtr","FindKey","heapPtr pList, number key"},
	{"heapPtr","FirstNode","heapPtr pList"},
	{"void","FlushResources",""},
	{"number","FOpen","string name, number mode"},
	{"string","Format","string destString, string fmtString[, parameters]"},
	{"void","FPuts","number handle, string buffer"},
	{"bool","GameIsRestarting",""},
	{"number","GetAngle","point origin, point dest"},
	{"string","GetCWD","string strBuf"},
	{"number","GetDistance","point origin, point dest"},
	{"bool","GetEvent","number types, heapPtr event"},
	{"string","GetFarText","number rsNumber, number index, string aString"},
	{"*","GetMenu","number menuItem, number subfunction, param"},
	{"void","GetPort","heapPtr newPort"},
	{"string","GetSaveDir",""},
	{"number","GetSaveFiles","string gameName, strings descBuffer, @number descSlots[]"},
	{"number","GetTime","[bool fTIME_OF_DAY]"},
	{"void","GlobalToLocal","heapPtr event"},
	{"*","Graph","number subFunction, ..."},
	{"bool","HaveMouse",""},
	{"void","HiliteControl","heapPtr control"},
	{"void","InitBresen","heapPtr moverObj[, number stepMult]"},
	{"void","InspectObj","heapPtr pObj"},
	{"bool","IsObject","heapPtr obj"},
	{"number","Joystick","number subfunction, number state"},
	{"heapPtr","LastNode","heapPtr pList"},
	{"heapPtr","Load","number type, number resNum"},
	{"void","LocalToGlobal","heapPtr event"},
	{"heapPtr","MapKeyToDir","heapPtr event"},
	{"number","MemoryInfo","number type"},
	{"number","MenuSelect","heapPtr event"},
	{"heapPtr","NewList",""},
	{"heapPtr","NewNode","number value, number key"},
	{"heapPtr","NewWindow","rect bounds, string title, number flags, number priority, number forecolour, number backcolour"},
	{"heapPtr","NextNode","heapPtr pNode"},
	{"number","NodeValue","heapPtr pNode"},
	{"number","NumCels","heapPtr obj"},
	{"number","NumLoops","heapPtr obj"},
	{"number","OnControl","number map, point xy or rect aRect "},
	{"bool","Parse","heapPtr event, string text"},
	{"number","PicNotValid","[number newFlag]"},
	{"heapPtr","PrevNode","heapPtr pNode"},
	{"void","Profiler",""},
	{"number","Random","number min, number max"},
	{"number","ReadNumber","string aString"},
	{"bool","RespondsTo","heapPtr anObject, selector aSelector"},
	{"*","RestartGame",""},
	{"void","RestoreGame","string gameName, number slotNumber, string gameVersion"},
	{"bool","Said","said saidString"},
	{"bool","SaveGame","string gameName, number slotNumber, string description, string gameVersion"},
	{"heapPtr","ScriptID","number scriptNum, number Index"},
	{"void","SetCursor","number resNumber, bool visible[,point coords]"},
	{"void","SetDebug",""},
	{"void","SetJump","heapPtr moverObj, number dx, number dy, number gy"},
	{"void","SetMenu","number menuItem, [number subfunction, params]"},
	{"void","SetNowSeen","heapPtr viewObj"},
	{"void","SetPort","heapPtr newPort"},
	{"void","SetSynonyms","heapPtr scrListObj"},
	{"void","ShakeScreen","number shakeCount, [number direction]"},
	{"void","Show",""},
	{"void","ShowFree",""},
	{"void","ShowObjs",""},
	{"void","ShowSends",""},
	{"number","SinDiv","number angle, number factor"},
	{"number","SinMult","number angle, number factor"},
	{"number","Sqrt","number value"},
	{"number","StackUsage",""},
	{"char","StrAt","string aString, number index[, char replacement]"},
	{"string","StrCat","string destString, string srcString"},
	{"number","StrCmp","string aString, string bString[, number max]"},
	{"string","StrCpy","string destString, string srcString[, number max]"},
	{"string","StrEnd","string aString"},
	{"number","StrLen","string aString"},
	{"void","TextSize","@rect sizeRect, string text, number font[, number maxWidth]"},
	{"void","UnLoad","number type, number resNum"},
	{"bool","ValidPath","string aDirectory"},
	{"number","Wait","number ticks"}
};
/******************************************************************************/
char *VarNames[] = {
    "global",
    "local",
    "temp",
    "param",
};

/******************************************************************************/
#define TOTAL_OBJPROPPTR 9
tsOBJPROPPTR ObjectPropPtr[] = {
    {"objectType",-12},
    {"objectSize",-10},
    {"objectLocal",-6},
    {"objectFunctionArea",-4},
    {"objectTotalProperties",-2},
    {"objectSpecies",0},
    {"objectSuperclass",2},
    {"objectInfo",4},
    {"objectName",6},
};
/*
    pToa [32762] objectFunctionArea
    pToa [65534] objectInfo
    pToa [32761] objectLocal
    pToa [65535] objectName
    pToa [32759] objectSize
    pToa [65532] objectSpecies
    pToa [65533] objectSuperclass
    pToa [32763] objectTotalProperties
    pToa [32758] objectType*/

/******************************************************************************/
tsSAIDARG SaidArgs[] = {
    {',', 0xF0}, /*"OR". Used to specify alternatives to words, such as "take , get".*/
    {'&', 0xF1}, /*Unknown. Probably used for debugging.*/
    {'/', 0xF2}, /*Sentence part separator. Only two of these tokens may be used, since sentences are split into a maximum of three parts.*/
    {'(', 0xF3}, /*Used together with ')' for grouping*/
    {')', 0xF4}, /*See '('*/
    {'[', 0xF5}, /*Used together with '[' for optional grouping. "[ a ]" means "either a or nothing" */
    {']', 0xF6}, /*See '['.*/
    {'#', 0xF7}, /*Unknown. Assumed to have been used exclusively for debugging, if at all.*/
    {'<', 0xF8}, /*Semantic reference operator (as in "get < up").*/
    {'>', 0xF9}  /*Instructs Said() not to claim the event passed to the previous Parse() call on a match. Used for successive matching.*/
};
/******************************************************************************/
char *Errors[TOTAL_ERRORS] = {
	"",
	"In bracket ('(') expected.",
	"Segment name expected.",
	"Out bracket (')') expected.",
	"In or out bracket ('(' or ')') expected.",
	"Script number already defined. It can only be defined once per script.",
	"Said segment already defined. It can only be defined once per script.",
	"String segment already defined. It can only be defined once per script.",
	"Public segment already defined. It can only be defined once per script.",
	"Local segment already defined. It can only be defined once per script.",
	"Script number not specified.",
	"Integer expected.",
	"Quote ('\"') expected.",
	"Invalid header segment.",
	"Variable name expected.",
	"Variable name \"%s\" already defined. You must use another.",
	"Invalid vocab header.",
	"Class name expected.",
	"Superclass name expected.",
	"'properties' or 'method' expected.",
	"Property name expected.",
	"Expression syntax.",
	"Comma or out bracket (',' or ')') expected.",
	"Method name expected.",
	"Cannot have a class of same class.",
	"Instance name expected.",
	"Procedure name expected.",
	"Class pointer ('.') expected.",
	"Equal operator ('=') expected.",
	"Operator expected.",
	"Plus operator ('+') expected.",
	"Minus operator ('-') expected.",
	"Else (\"else\") keyword expected.",
	"While (\"while\") keyword expected.",
	"Invalid argument \"%s\".",
	"Invalid switch argument \"%s\"",
    "Case (\"case\") keyword expected.",
    "Invalid argument initalization.",
    "Undefined symbol \"%s\".",
    "String name expected.",
    "Array start bracket ('[') expected.",
    "Array end bracket (']') expected.",
    "Variable name or out bracket (')') expected.",
    "Array size (%d) invalid. It must be greater than zero.",
    "Array size (%d) less than string length (%d)",
	"Quote ('\"') or integer expected.",
    "Array size (%d) less than total number of entries (%d)",
    "Local variable name expected",
    "Property (\"%s\") not member of class (\"%s\").",
    "Invalid said string",
    "Word (\"%s\") is not in the game's vocabulary.",
    "Paramater variable expected.",
    "Undefined selector (\"%s\").",
    "Class (\"%s\") has no SuperClass.",
    "Property (\"%s\") not member of SuperClass (\"%s\").",
    "Selectors can only be sent to classes, not instances.",
    "Unable to add selector (\"%s\").",
    "Selector name expected.",
    "Adresses cannot be obtained from properties.",
    "Unable to get the property's index in the instance.",
    "'break' statements can only be used within loops.",
    "Expected a class name. Got an instance name.",
    "Colon (\":\") expected for send instruction.",
    "Bad syntax. Format: (<varname><:>...).",
    "Bad syntax. Format: (preload text).",
    "Bad script number! It must be between 0 and 999",
    "Single quote ( ' ) expected!",
    "String expected!",
    "\"%s\" is not a valid SCI opcode!",
    "Kernel name expected in argument #%d!",
    "Label name (\"%s\") too long!",
    "Maximum labels reached (%d)!",
    "Label name (\"%s\") already defined!",
    "Label name (\"%s\") not defined!",
    "Label name (\"%s\") over used!",
    "Not all publics prototyped!",
};
/******************************************************************************/

/***************************************************************************
 *  Copyright (C) 1999-2001 Brian Provinciano, http://www.bripro.com
 ***************************************************************************/
