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
 * SCI Script Compiler Compiler Code Handler
 ******************************************************************************/
#include "scc.h"
/******************************************************************************/
#ifdef SCC_SCISTUDIO_WIN32
#pragma hdrstop
#pragma package(smart_init)
#endif
/******************************************************************************/

BOOL CAN_DUP;
WORD LastPush;

BOOL CompileCode(int FunctionType, BOOL _RET)
{
	int  TotalCodeBrackets, i;

    CAN_DUP = FALSE;
    TotalCodeBrackets = 1;

    GetNextWord(&InBuf);
	if(_RET) {
    	LoopStackCount = 0;
        TotalVar[vTEMP] = 0;
        if(TempString[0]=='(') {
	        /* Temp var by "link" */
				GetNextWord(&InBuf);
	        if(strcmp(TempString,"var")==0) {
                if(CompileTempVar()==-1) return FALSE;
                if(TotalVar[vTEMP]) {
                	WriteOpInt(acLINK, TotalVar[vTEMP]);
                    for(i=0;i<TotalVar[vTEMP];i++) {
                		if(Var[vTEMP][i].Value) {
                        	WriteOpInt(acLDI, Var[vTEMP][i].Value);
                			WriteOpInt(acSAT, i);
                        }
                    }
                }
                GetNextWord(&InBuf);
	        } else TotalCodeBrackets++;
        }
	}

	while(TotalCodeBrackets && TempString[0]!='\0') {
        if(!CompileChunk(ccACC,&TotalCodeBrackets,FunctionType,TRUE)) {
        	if(_RET) {
            	FreeVars(vTEMP);
                FreeVars(vPARAM);
            }
            return FALSE;
        }
	}

	if(_RET) {
        FreeVars(vTEMP);
        FreeVars(vPARAM);
        WriteOpcode(acRET,0);
    }
    CAN_DUP = FALSE;
	return TRUE;
}
/******************************************************************************/
void WriteOpcode(BYTE Code, BOOL BFLAG)
{
	CodeBuf[CodeBufOffset++] = (BYTE)((Code<<1)|BFLAG);
}
/******************************************************************************/
void WriteOpInt(BYTE Code, int Value)
{
    BOOL IS_BYTE = (((WORD)Value)<256);
    WriteOpcode(Code,IS_BYTE);
    if(IS_BYTE) AddCodeB(Value);
    else AddCodeW(Value);
}
/******************************************************************************/
void SCIPush(int Value, BOOL SHORTEN)
{
	BOOL IS_BYTE;

    if(CAN_DUP) {
        if(LastPush==Value) {
	        CodeBuf[CodeBufOffset++] = (BYTE)((acDUP<<1)|1);
            return;
        }
    }

    CAN_DUP = FALSE;/*TRUE; */
    LastPush = Value;

	if(SHORTEN) {
		switch(Value) {
			case 0:
				CodeBuf[CodeBufOffset++] = acPUSH0<<1;
				return;
			case 1:
				CodeBuf[CodeBufOffset++] = acPUSH1<<1;
				return;
			case 2:
				CodeBuf[CodeBufOffset++] = acPUSH2<<1;
				return;
			default:
				IS_BYTE = (((unsigned)Value)<256)&1;
				if(IS_BYTE) {
					CodeBuf[CodeBufOffset]   = (BYTE)((acPUSHI<<1)|1);
					CodeBuf[CodeBufOffset+1] = Value;
					CodeBufOffset += 2;
				} else {
					CodeBuf[CodeBufOffset]   = (BYTE)(acPUSHI<<1);
					CodeBuf[CodeBufOffset+1] = (BYTE)(Value&0xFF);
					CodeBuf[CodeBufOffset+2] = (BYTE)(Value>>8);
					CodeBufOffset += 3;
				}
		}
	  	return;
	}

	CodeBuf[CodeBufOffset]   = (BYTE)(acPUSHI<<1);
	CodeBuf[CodeBufOffset+1] = (BYTE)(Value&0xFF);
	CodeBuf[CodeBufOffset+2] = (BYTE)(Value>>8);
	CodeBufOffset += 3;
}
/******************************************************************************/
void SCILDI(int Value)
{
	CodeBuf[CodeBufOffset]   = (BYTE)(acLDI<<1);
	CodeBuf[CodeBufOffset+1] = (BYTE)(Value&0xFF);
	CodeBuf[CodeBufOffset+2] = (BYTE)(Value>>8);
	CodeBufOffset += 3;
}
/******************************************************************************/
void AddCodeB(BYTE Code) {
	CodeBuf[CodeBufOffset++] = (BYTE)(Code);
}
/******************************************************************************/
void AddCodeW(int Code) {
	CodeBuf[CodeBufOffset  ] = (BYTE)(Code&0xFF);
	CodeBuf[CodeBufOffset+1] = (BYTE)(Code>>8);
	CodeBufOffset += 2;
}
/******************************************************************************/
void WriteSendOpcode()
{
	/*if(SCI1)    */
        CodeBuf[CodeBufOffset++] = (BYTE)((acSEND<<1)); /*
    else
        CodeBuf[CodeBufOffset++] = (BYTE)((acSEND<<1)|1);   */
}
/******************************************************************************/
BOOL CompileGetVarCode(tsVARSTRUCT VarStruct, BYTE LoadTo)
{
	BYTE Operator, IS_BYTE = (((WORD)VarStruct.Index)<256);

	/* Bit 0 - BYTE FLAG */
	Operator = IS_BYTE?0x81:0x80;
	/* Bit 1-2 - var type */
	Operator |= (VarStruct.Type<<1)&6;
	if(LoadTo==ccSTACK) Operator |= 8;

    GetArraySize(&VarStruct.Index);
	AddCodeB(Operator);
	if(IS_BYTE) AddCodeB(VarStruct.Index);
	else AddCodeW(VarStruct.Index);

	return TRUE;
}
/******************************************************************************/
void DoBranch(int IfEnd, int *BranchPos, int *pTotalBranchPos)
{
	int i, Value, TotalBranchPos = *pTotalBranchPos;
	for(i = 0; i < TotalBranchPos; i++) {
		Value = (int)(((signed)IfEnd) - ((signed) (BranchPos[i]+2)));
		CodeBuf[BranchPos[i]  ]=(BYTE)(Value&0xFF);
		CodeBuf[BranchPos[i]+1]=(BYTE)(Value>>8);
	}
	*pTotalBranchPos = 0;
}
/******************************************************************************/
BOOL CompileEvaluation(int **_BranchPos, int **_ORBranchPos, int *_TotalBranchPos, int *_TotalORBranchPos, BOOL *_PREVIF, int FunctionType)
{
	 int *BranchPos=*_BranchPos,*ORBranchPos=*_ORBranchPos,
		 TotalBranchPos=*_TotalBranchPos,TotalORBranchPos=*_TotalORBranchPos,
		  ifAND, ifOR, PREVIF=*_PREVIF, TotalBrackets=1;

    CAN_DUP = FALSE;

	GetNextWord(&InBuf);
	if(TempString[0]!='(') {
		ShowMessage(errINBRACEXP,NULL);
		return FALSE;
	}

	TotalBranchPos = 0;
	ifAND = FALSE;
	ifOR = FALSE;
	while(TotalBrackets&&TempString[0]!='\0') {
    	GetNextWord(&InBuf);
        if(strcmp(TempString,"and")==0) {
				 ifAND = TRUE;
                 GetNextWord(&InBuf);
        } else if(strcmp(TempString,"or")==0) {
				ifOR = TRUE;
                GetNextWord(&InBuf);
        }

		if(ifAND) {
			WriteOpcode(acBNT,FALSE);
			BranchPos[TotalBranchPos++] = CodeBufOffset;
			AddCodeW(0);
		} else if(ifOR) {
			if(TotalBranchPos) DoBranch(CodeBufOffset, BranchPos, &TotalBranchPos);
			PREVIF = piOR;
			WriteOpcode(acBT,FALSE);
			ORBranchPos[TotalORBranchPos++] = CodeBufOffset;
			AddCodeW(0);
		}
        if(!CompileChunk(ccACC,&TotalBrackets, FunctionType, FALSE)) return FALSE;

		ifAND = FALSE;
		ifOR = FALSE;
	}

	if(TotalBrackets) {
		ShowMessage(errOUTBRACEXP,NULL,NULL);
		return FALSE;
	}

    *_TotalBranchPos    =TotalBranchPos;
    *_TotalORBranchPos    =TotalORBranchPos;
    *_TotalBranchPos    =TotalBranchPos;
    *_TotalORBranchPos    =TotalORBranchPos;
    *_PREVIF            =PREVIF;  
    CAN_DUP = FALSE;
    return TRUE;
}
/******************************************************************************/
#define FREE_BRANCHES() \
            if(BranchPos!=NULL)   free(BranchPos); \
            if(ORBranchPos!=NULL) free(ORBranchPos);

#define PUSH_LOOP_STACK(BranchPos, BranchCount) \
			LoopStack[LoopStackCount].BranchPos = BranchPos; \
			LoopStack[LoopStackCount].TotalBranchPos = &BranchCount; \
            LoopStackCount++;

#define POP_LOOP_STACK() \
            LoopStackCount--;

/* add an address to the branch pos list on the top of the stack */
#define USE_LOOP_STACK(o) \
		LoopStack[LoopStackCount-1].BranchPos[(*LoopStack[LoopStackCount-1].TotalBranchPos)] = o; \
        (*LoopStack[LoopStackCount-1].TotalBranchPos)++
/******************************************************************************/
BOOL CompileIfStatement(int FunctionType, int IfType)
{
	int *BranchPos=NULL, *ORBranchPos=NULL;
    int IfStart = 0, TotalBranchPos = 0, TotalORBranchPos = 0;
    BOOL PREVIF;
    int _OldLine;
    char* _OldBuf;
	 WORD ORPos=0;

    CAN_DUP = FALSE;


	IfStart = CodeBufOffset;
	if(IfType==itDOWHILE) {
        ORPos = CodeBufOffset;                 
        CAN_DUP = FALSE;
		if(!CompileCode(FunctionType,FALSE)) return FALSE; 
        CAN_DUP = FALSE;
		if(strcmp(GetNextWord(&InBuf),"while")!=0) {
			ShowMessage(errWHILEEXP,NULL);
			return FALSE;
		}
	}


    BranchPos = (int*) calloc(32,sizeof(int));
    ORBranchPos = (int*) calloc(32,sizeof(int));
    if(IfType==itDOWHILE||IfType==itWHILE) {
    	PUSH_LOOP_STACK(BranchPos, TotalBranchPos);
    }

	 if(!CompileEvaluation(&BranchPos, &ORBranchPos, &TotalBranchPos, &TotalORBranchPos, &PREVIF, FunctionType)) {
        FREE_BRANCHES();
        return FALSE;
    }

	if(IfType!=itDOWHILE) {     
        CAN_DUP = FALSE;
		WriteOpcode(acBNT,FALSE);
		BranchPos[TotalBranchPos++] = CodeBufOffset;
		AddCodeW(0);

        ORPos = CodeBufOffset;
		if(!CompileCode(FunctionType,FALSE)) {
            FREE_BRANCHES();
            return FALSE;
        }       
        CAN_DUP = FALSE;
	}
	if(IfType==itIF) {
        _OldLine = LineNumber;
		  _OldBuf = InBuf;
		GetNextWord(&InBuf);
		if(TempString[0]=='('&&strcmp(GetNextWord(&InBuf),"else")==0) {  
            CAN_DUP = FALSE;
    		if(TotalORBranchPos) DoBranch(ORPos, ORBranchPos, &TotalORBranchPos);
    		DoBranch(CodeBufOffset+3, BranchPos, &TotalBranchPos);

			WriteOpcode(acJMP,FALSE);
			BranchPos[TotalBranchPos++] = CodeBufOffset;
			AddCodeW(0);

			if(!CompileCode(FunctionType,FALSE)) {
                FREE_BRANCHES();
                return FALSE;
            }   
            CAN_DUP = FALSE;
		} else {
            LineNumber = _OldLine;
            InBuf = _OldBuf;
		}
	} else {
		WriteOpcode(IfType==itWHILE?acJMP:acBT,FALSE);
		AddCodeW((int)( ((signed)IfStart) - ((signed) (CodeBufOffset+2)) ));
	}                              /*
    if(IfType==itDOWHILE||IfType==itWHILE)
       IfType=IfType;            */    
    CAN_DUP = FALSE;
	if(TotalORBranchPos) DoBranch(ORPos, ORBranchPos, &TotalORBranchPos);
    DoBranch(CodeBufOffset, BranchPos, &TotalBranchPos);

    if(IfType==itDOWHILE||IfType==itWHILE) {
    	POP_LOOP_STACK();
    }

    FREE_BRANCHES();  
    CAN_DUP = FALSE;
	return TRUE;
}

/******************************************************************************/
BOOL CompileSwitch(int FunctionType)
{
	int BranchPos[32],xTotalBrackets, yTotalBrackets, TotalBranchPos = 0, EndJump[16],
		TotalEndJump = 0,CaseVal;
     tsVS ccVS = {-1,-1,FALSE};

    CAN_DUP = FALSE;

    GetNextWord(&InBuf);
    xTotalBrackets = 0;
    do {
        if(!CompileChunk(ccSTACK,&xTotalBrackets, FunctionType, TRUE)) return FALSE;
    } while(xTotalBrackets);

	GetNextWord(&InBuf);
    xTotalBrackets = 1;
	do {
		if(TempString[0]=='(') {
			xTotalBrackets++;
		} else if(TempString[0]==')') {
			xTotalBrackets--;
		} else if(strcmp(TempString,"case")==0) {
            WriteOpcode(acDUP,FALSE);  
            CAN_DUP = FALSE;
            yTotalBrackets = 1;
            do {         
                GetNextWord(&InBuf);
                if(!CompileChunk(ccACC,&yTotalBrackets, FunctionType, FALSE)) return FALSE;
            } while(yTotalBrackets>1);
            WriteOpcode(acEQ,FALSE);
            WriteOpcode(acBNT,FALSE);
            BranchPos[TotalBranchPos++] = CodeBufOffset;
				AddCodeW(0);

            if(!CompileCode(FunctionType,FALSE)) return FALSE;
            xTotalBrackets--;

            WriteOpcode(acJMP,FALSE);
            EndJump[TotalEndJump++] = CodeBufOffset;
            AddCodeW(0);

	        DoBranch(CodeBufOffset, BranchPos, &TotalBranchPos);
        } else if(strcmp(TempString,"default")==0) {
            if(!CompileCode(FunctionType,FALSE)) return FALSE;
			xTotalBrackets--;
        } else {
            ShowMessage(errCASEEXP,NULL);
            return FALSE;
		}                 
        CAN_DUP = FALSE;
        if(xTotalBrackets>0) GetNextWord(&InBuf);
	} while(xTotalBrackets&&TempString!='\0');

	if(xTotalBrackets) {
		ShowMessage(errOUTBRACEXP,NULL,NULL);
		return FALSE;
	}

	DoBranch(CodeBufOffset, EndJump, &TotalEndJump);

    WriteOpcode(acTOSS,FALSE);
    CAN_DUP = FALSE;
	return TRUE;
}
/******************************************************************************/
short ASM_AddLabel(BYTE Type, char *Name, int Ln, short cbo)
{
    int i;
    short LabelIndex;
    tsASMLABEL *al;

    if(strlen(Name)>63) {
        ShowMessage(errLABELTOOLONG,NULL,Name);
        return -1;
    }
    for(i=TotalLabels-1;i>=0;i--)
        if(strcmp(ASMLabels[i].Name,Name)==0) break;

    switch(Type) {
        case alLABEL:
            if(i!=-1&&ASMLabels[i].Offset!=-1) {
                ShowMessage(errLABELUSED,NULL,Name);
                return -1;
            }
            if(i==-1) {
                if(TotalLabels>=MAX_LABELS) {
                    ShowMessage(errMAXLABELS,NULL,MAX_LABELS);
                    return -1;
                }
                i = TotalLabels++;
                ASMLabels[i].TotalOffsets = 0;
            } 
            al = &ASMLabels[i];
            strcpy(al->Name,Name);
            al->Offset = cbo;
            break;
        case alOFFSET:
            if(i==-1) {       
                i = TotalLabels++;
                al = &ASMLabels[i];
                strcpy(al->Name,Name);
                al->TotalOffsets = 0;
                al->Offset = -1;
            }
            al = &ASMLabels[i];
            if(al->TotalOffsets>=MAX_LABELOFFSETS) {
                ShowMessage(errLABELOUTUSED,NULL,Name);
                return -1;
            }
            al->Offsets[al->TotalOffsets] = cbo;
            al->Lns[al->TotalOffsets] = Ln;
            al->TotalOffsets++;
            break;
    }
    return i;
}
/******************************************************************************/
/* syntax:
 *   (asm
 *       foo a b
 *       foo x
  *      foo
 *       ...
 *   )
*/
BOOL DoAssembly(int FunctionType)
{
    int TotalBrackets=1, arg;
    int OpIndex, Index, Value;
    short OpOffs;
    tsVARSTRUCT VarStruct = {-1,-1};
    tsSELFINFO si;

    CAN_DUP = FALSE;

    IN_ASM_MODE = TRUE;
    while(TotalBrackets) {
        GetNextWord(&InBuf);
        if(TempString[0] == ')') {
            TotalBrackets--;
        } else if(TempString[0] == '(') {
            TotalBrackets++;
        } else {
            if((OpIndex=IsOpcodeName(TempString))==-1) {
                if(*InBuf!=':') {
		            ShowMessage(errNOTANOPCODE,NULL,TempString);
                    return FALSE;
                }
                InBuf++;
                if(ASM_AddLabel(alLABEL, TempString,LineNumber,CodeBufOffset)==-1)
                    return FALSE;
                continue;
            }
            OpOffs = CodeBufOffset;
            WriteOpcode(OpIndex, FALSE);
            for(arg=0;arg<3;arg++) {
                if(OpArgTypes[OpIndex][arg]==otEMPTY) break;
                switch(OpArgTypes[OpIndex][arg]) {
                    case otINT:
                    case otINT16:
                    case otPVAR:
                    case otPUBPROC:
                    case otINT8:
                    case otVAR:
                        GetNextWord(&InBuf);

                        if((VarStruct=IsVarName(TempString)).Type!=-1) {
                            Value = (VarStruct.Index);
                        } else if(IsStringNum(TempString)) {
                            Value=StrToInt(TempString);
                        } else if(TempString[0]=='#') {
        			        if((Value=GetSelectorIndex(GetNextWord(&InBuf),caCAN_NOT_ADD))==-1) {
            		            ShowMessage(errSELECTORNAMEEXP,NULL);
                                return FALSE;
                            }
                        } else if((Index=IsProcedureName(TempString))!=-1) {
                            Value = Index;
                        } else if((Index=IsExpProcedureName(TempString))!=-1) {
                            Value = Index;
                        } else {
                            ShowMessage(errINTEXP,NULL);
                            return FALSE;
                        }
                        if(OpArgTypes[OpIndex][arg]==otINT8)
                            AddCodeB(Value);
                        else
                            AddCodeW(Value);
                        break;
                    case otKERNEL:
                        if((Index=IsKernelName(GetNextWord(&InBuf)))==-1) {
		                    ShowMessage(errKERNELEXP,NULL,arg);
                            return FALSE;
                        }
                        AddCodeW(Index);
                        break;
                    case otOFFS:  
                    case otSTRING:
                        si = GetClassIndex(GetNextWord(&InBuf));
                        if(si.Index==-1) {
		                    if(TempString[0]=='"'||(Index=IsStringName(TempString))!=-1) {
                                if(TempString[0]=='"') {
				                    if(!DoString()) return FALSE;
                                    Value = AddString(TempString);
                                } else {
				                    Value = Strings[Index].Offset;
                                    if(*InBuf=='[') {
                                        InBuf++;
                                        GetNextWord(&InBuf);
                                        if(!IsStringNum(TempString)) {
                                            ShowMessage(errINTEXP,NULL);
                                            return FALSE;
                                        }
                                        Value+=StrToInt(TempString);
                                        if(*InBuf!=']')  {
                                            ShowMessage(errARRAYENDEXP,NULL);
                                            return FALSE;
                                        }
                                        InBuf++;
                                    }
		                        }
                                ChgOffCode[TotalChgOffCode  ].Offset = CodeBufOffset+1;
                                ChgOffCode[TotalChgOffCode++].STRING = TRUE;
                                AddCodeW(Value);
                            } else {
                                ShowMessage(errINSTANCENAMEEXP,NULL);
                                return FALSE;
                            }
                        } else {
                            if(si.INSTANCE) {
                                ChgOffCode[TotalChgOffCode  ].Offset = CodeBufOffset;
                                ChgOffCode[TotalChgOffCode++].INSTANCE = TRUE;
					            AddCodeW(si.Index);
                            } else {
                                ChgOffCode[TotalChgOffCode  ].Offset = CodeBufOffset;
                                ChgOffCode[TotalChgOffCode++].CLASS = TRUE;
					            AddCodeW(si.Index);
                            }
                        }
                        break;
                    case otCLASS:
                        si = GetClassIndex(GetNextWord(&InBuf));
                        if(si.Index==-1||si.INSTANCE) {
		                    ShowMessage(errCLASSNAMEEXP,NULL);
                            return FALSE;
                        }
                        AddCodeW(sClasses[si.Index].Species);
                        break;
                    case otPROP:
                        GetNextWord(&InBuf);
                        if(FunctionType==ccPROCEDURE||(Index=GetPropertyIndex(SelfInfo.Index,TempString,SelfInfo.INSTANCE))==-1) {
                            ShowMessage(errVARNAMEEXP,NULL);
                            return FALSE;
                        }
                        AddCodeW(GET_PROPERTY_OFFSET(Index));
                        break;
                    case otSAID:
                        if( TempString[0]!='\''||
                            (Value=CompileSaid())==-1
                          )
                        {
                            ShowMessage(errINVSAID,NULL);
                            return FALSE;
                        }
                        ChgOffCode[TotalChgOffCode  ].Offset = CodeBufOffset;
                        ChgOffCode[TotalChgOffCode++].SAID   = TRUE;
                        AddCodeW(Value);
                        break;
                    case otLABEL:
                        if(ASM_AddLabel(alOFFSET, GetNextWord(&InBuf),LineNumber,CodeBufOffset)==-1)
                            return FALSE;
                        AddCodeW(OpOffs+3);
                        break;
                }
            }
        }
    }

    IN_ASM_MODE = FALSE;

	return TRUE;
}
/******************************************************************************/
/* syntax: (for (code1)(conditional)(code2)...)
 *  equivilant to:
 *   code1
 *   (while(conditional)
 *       ...
 *       code2
 *   )
*/
BOOL CompileFor(int FunctionType)
{
    BOOL PREVIF;
    char *IncBufStart, *PrevInBuf;
    WORD EvalStart, EvalEnd;
	int TotalBranchPos = 0, TotalORBranchPos = 0, Value, TotalBrackets=0;
    int *BranchPos,*ORBranchPos;
	 WORD ORPos=0;
               
    CAN_DUP = FALSE;

	if(GetNextWord(&InBuf)[0]!='(') {
		ShowMessage(errINBRACEXP,NULL);
		return FALSE;
	}
    do {
        if(!CompileChunk(ccACC,&TotalBrackets,FunctionType,TRUE)) return FALSE;
    } while(TotalBrackets);

    EvalStart = CodeBufOffset;

    BranchPos = (int*) calloc(32,sizeof(int));
    ORBranchPos = (int*) calloc(32,sizeof(int));
    PUSH_LOOP_STACK(BranchPos, TotalBranchPos);

	 if(!CompileEvaluation(&BranchPos, &ORBranchPos, &TotalBranchPos, &TotalORBranchPos, &PREVIF, FunctionType)) {
        FREE_BRANCHES();
        return FALSE;
    }

    WriteOpcode(acBNT,FALSE);
	 EvalEnd = CodeBufOffset;
    AddCodeW(0);

	if(GetNextWord(&InBuf)[0]!='(') {
		ShowMessage(errINBRACEXP,NULL);
        FREE_BRANCHES();
		return FALSE;
	}
    IncBufStart = InBuf;
    if(!SkipSegment()) {
        FREE_BRANCHES();
        return FALSE;
    }

    if(!CompileCode(FunctionType,FALSE)) {
        FREE_BRANCHES();
        return FALSE;
    }

    PrevInBuf = InBuf;
    InBuf = IncBufStart;
    TotalBrackets = 0;
    GetNextWord(&InBuf);
    do {
        if(!CompileChunk(ccACC,&TotalBrackets,FunctionType,TRUE)) {
            FREE_BRANCHES();
            return FALSE;
        }
    } while(TotalBrackets);

    WriteOpcode(acJMP,FALSE);
    AddCodeW((int)( ((int)EvalStart) - ((int) (CodeBufOffset+2)) ));
	 if(TotalORBranchPos) DoBranch(ORPos, ORBranchPos, &TotalORBranchPos);
	DoBranch(CodeBufOffset, BranchPos, &TotalBranchPos);

    POP_LOOP_STACK();
    Value = (int)( ((int)(CodeBufOffset)) - ((int) (EvalEnd+2)) );
	CodeBuf[EvalEnd  ] = (BYTE)(Value&0xFF);
	CodeBuf[EvalEnd+1] = (BYTE)(Value>>8);

    InBuf = PrevInBuf;

    FREE_BRANCHES();    
    CAN_DUP = FALSE;
	return TRUE;
}
/******************************************************************************/
int CompileTempVar()
{
    int OldLine, TotalTemp, CurTemp, ArraySize;
    char *OldInBuf;

    OldLine = LineNumber;
    OldInBuf = InBuf;

    GetNextWord(&InBuf);
    if(TempString[0]==')') {
        return 0; /* No args */
    }
    TotalTemp = 1;
    while(TempString[0]!='\0'&&TempString[0]!=')') {
    	ArraySize = 0;
        if(GetArraySize(&ArraySize)!=0) TotalTemp += ArraySize-1;
        if(TempString[0]==',') TotalTemp++;
        GetNextWord(&InBuf);
    }
    if(TempString[0]=='\0') {
        ShowMessage(errOUTBRACEXP,NULL);
        return -1;
    }
    LineNumber = OldLine;
    InBuf = OldInBuf;
    GetNextWord(&InBuf);

    Var[vTEMP] = (tsVAR*) calloc(sizeof(tsVAR),TotalTemp);
    CurTemp = 0;
    while(TempString[0]!=')') {
        if(!IsStringLabel(TempString)) {
            ShowMessage(errVARNAMEEXP,NULL);
            FreeVars(vTEMP);
            return -1;
        }
        if(IsLabelDefined(TempString)) {
            ShowMessage(errLABELAREADYDEF,NULL,TempString); 
            FreeVars(vTEMP);
            return -1;
        }
        Var[vTEMP][CurTemp].Label=(char*)malloc(strlen(TempString)+1);
        strcpy(Var[vTEMP][CurTemp].Label,TempString);
        ArraySize = 0;
        if(GetArraySize(&ArraySize)!=0)
        	ArraySize = ArraySize;
        GetNextWord(&InBuf);
        if(ArraySize==0&&TempString[0]=='=') {
            GetNextWord(&InBuf);
            if(!IsStringNum(TempString)) {
            	ShowMessage(errINTEXP,NULL,TempString);    
            	FreeVars(vTEMP);
            	return -1;
        	}
            Var[vTEMP][CurTemp].Value = StrToInt(TempString);
        	GetNextWord(&InBuf);
        }
        if(TempString[0]==',')
            GetNextWord(&InBuf);
        else if(TempString[0]!=')') {
            ShowMessage(errOUTBRACEXP,NULL);  
            FreeVars(vTEMP);
            return -1;
        }

        if(ArraySize) CurTemp += ArraySize;
		else CurTemp++;
    }
    TotalVar[vTEMP] = TotalTemp;

    return TotalTemp;
}
/******************************************************************************/
int AddSaidString(int *_StrLen)
{
    int StrIndex=0;
    int StrLen = *_StrLen;
    if(StrLen) {
        TempString[StrLen]='\0';
        if((StrIndex=IsStringInVocab(TempString))==-1) {
            ShowMessage(errWORDNIV,NULL,TempString);
            return -1;
        }
        SaidSegment[SaidSegLen  ]=StrIndex>>8;
        SaidSegment[SaidSegLen+1]=StrIndex&0xFF;
        SaidSegLen+=2;
        StrLen = 0;
	 }
	 *_StrLen = StrLen;
	 return StrIndex;
}
/******************************************************************************/
int CompileSaid()
{
	 int SaidPtr=SaidSegLen,StrLen=0,i;
	  BOOL SEARCH_STR=0,IS_EMPTY=TRUE;
	 while(*InBuf!='\0'&&*InBuf!='\'') {
			do {
			SEARCH_STR = TRUE;
			for(i=0;i<TOTAL_SAID_ARGS;i++) {
				if(*InBuf==SaidArgs[i].Character) {
                	IS_EMPTY=FALSE;
					if(SEARCH_STR)
						if(AddSaidString(&StrLen)==-1) return -1;
						SaidSegment[SaidSegLen++]=SaidArgs[i].Code;
						InBuf++;
						SEARCH_STR = FALSE;
						break;
					}
				}
		  } while(*InBuf!='\0'&&*InBuf!='\''&&!SEARCH_STR);
		  if(*InBuf!='\'') {
        	if(*InBuf==' ') InBuf++;
            else {
            	IS_EMPTY=FALSE;
            	TempString[StrLen++]=*InBuf;
				InBuf++;
            }
        }
	 }
     if(IS_EMPTY) return -1;
	 if(AddSaidString(&StrLen)==-1) return -1;
	 SaidSegment[SaidSegLen++]=0xFF;
	 if(*InBuf=='\0') return -1;
	 InBuf++;
	 return SaidPtr;
}
/******************************************************************************/
BOOL DoFunctionArgs()
{
    int TotalBrackets, TotalArgs;
	WORD OldLine;
	char *OldPtr;
    TotalBrackets = 1;
    TotalArgs = 0;

    /* Do the arguments */
    OldPtr = InBuf;
    OldLine = LineNumber;
    GetNextWord(&InBuf);

    if(TempString[0]==')') return TRUE;

    while(TempString[0]!='\0'&&TotalBrackets) {
        if(TempString[0]=='(') {
            TotalBrackets++;
        } else if(TempString[0]==')') {
            TotalBrackets--;
        } else if(TempString[0]==',') {
            /* do nothing */
        } else if(IsStringLabel(TempString)) {
            if(IsLabelDefined(TempString)) {
                ShowMessage(errLABELAREADYDEF,NULL,TempString);
                return FALSE;
            }
            TotalArgs++;
        } else {
            ShowMessage(errINVALIDARGINIT,NULL);
            return FALSE;
        }
        if(TotalBrackets) GetNextWord(&InBuf);
    }
    if(TotalArgs) {
        TotalArgs++;
        Var[vPARAM] = (tsVAR*) calloc(sizeof(tsVAR),TotalArgs);
        TotalArgs=1;
        Var[vPARAM][0].Label = (char*) malloc(1);
        Var[vPARAM][0].Label[0]='\0';
        TotalBrackets = 1;
        InBuf = OldPtr;
        LineNumber = OldLine;
        GetNextWord(&InBuf);
        while(TempString[0]!='\0'&&TotalBrackets) {
            if(TempString[0]=='(') {
                TotalBrackets++;
            } else if(TempString[0]==')') {
                TotalBrackets--;
            } else if(TempString[0]==',') {
            } else {
                Var[vPARAM][TotalArgs].Label = (char*)malloc(strlen(TempString)+1);
                strcpy(Var[vPARAM][TotalArgs].Label,TempString);
                TotalArgs++;
            }
            if(TotalBrackets) GetNextWord(&InBuf);
        }
        TotalVar[vPARAM] = TotalArgs;
    }
    return TRUE;
}
/******************************************************************************/
void FreeVars(int Type)
{
    WORD i;
    if(TotalVar[Type]&&Var[Type]!=NULL) {
        for(i=0;i<TotalVar[Type];i++)
            if(Var[Type][i].Label!=NULL)
                free(Var[Type][i].Label);
        free(Var[Type]);
        TotalVar[Type] = 0;
    }
    Var[Type] = NULL;
}
/******************************************************************************/
BOOL SkipArrayInOut()
{
    if(*InBuf=='[') {
        do InBuf++; while(*InBuf!='\0'&&*InBuf!=']');
        InBuf++;
    }
    return(InBuf!='\0');
}
/******************************************************************************/
int GetArraySize(int *OutVal)
{
    if(*InBuf=='[') {
        InBuf++;
        GetNextWord(&InBuf);
        if(!IsStringNum(TempString)) {
            ShowMessage(errINTEXP,NULL);
            return -1;
        }
        (*OutVal)+=StrToInt(TempString);
        if(*InBuf!=']')  {
            ShowMessage(errARRAYENDEXP,NULL);
            return -1;
        }
        InBuf++;
    }
    return(*OutVal);
}                      
/******************************************************************************/
int GetArraySize2(int *OutVal)
{
    if(*InBuf=='[') {
        InBuf++;
        GetNextWord(&InBuf);
        if(!IsStringNum(TempString)) {
            *OutVal = -1;
            return -1;
        }
        (*OutVal)=StrToInt(TempString);
        if(GetNextWord(&InBuf)[0]!=']')  {
            ShowMessage(errARRAYENDEXP,NULL);
            *OutVal = -1;
            return -2;
        }
    }
    return 0;
}
/******************************************************************************/
int HandleFunction(int *_CodeBrackets, int FunctionType)
{
    int TotalCodeArgs;
    int PrevTotalBrackets, TotalCodeBrackets = *_CodeBrackets, xTotalBrackets;
    tsVARSTRUCT VarStruct;

    WORD CodeBufSave;
    PrevTotalBrackets   = TotalCodeBrackets;
    TotalCodeArgs       = 0;
    CodeBufSave         = CodeBufOffset;
    CodeBufOffset       += 2;

    GetNextWord(&InBuf);
    do {
        if(TempString[0]=='(') {
            PrevTotalBrackets++;
            GetNextWord(&InBuf);
        } else if(TempString[0]==')') {
            PrevTotalBrackets--;
            if(PrevTotalBrackets>TotalCodeBrackets)
                GetNextWord(&InBuf);
        } else if(strcmp(TempString,"rest")==0) {
    	/* Rest (&rest) */
        	if((VarStruct=IsVarName(GetNextWord(&InBuf))).Type!=vPARAM) {
            	ShowMessage(errPARAMVAREXP,NULL);
            	return FALSE;
		  	}
	    	WriteOpInt(acREST, VarStruct.Index);
            GetNextWord(&InBuf);
    	} else {
            xTotalBrackets = 1;
            do {
                if(!CompileChunk(ccSTACK,&xTotalBrackets, FunctionType, TRUE)) return -1;
            } while(xTotalBrackets>1);
				TotalCodeArgs++;
        }
    } while(PrevTotalBrackets>TotalCodeBrackets);

    /* Allows for both foo(param1 param2) and authentic (foo param1 param2) */
    TotalCodeBrackets       = PrevTotalBrackets;

    /* The push TotalArgs at the beginning */  
    CAN_DUP = FALSE;
    CodeBuf[CodeBufSave  ]  = (acPUSHI<<1)|1;
    CodeBuf[CodeBufSave+1]  = TotalCodeArgs;

    *_CodeBrackets = TotalCodeBrackets;
    return TotalCodeArgs;
}
/******************************************************************************/
int HandleSend(int FunctionType)
{
	 int TotalCodeArgs, PrevTotalBrackets, NewTotalBrackets, SelectorIndex, TotalSelectors=0;
	 tsVARSTRUCT VarStruct;
     tsVS ccVS = {-1,-1,FALSE};

	 PrevTotalBrackets   = 1;

	 GetNextWord(&InBuf);
	 do {
		  if(TempString[0]=='(') {
				PrevTotalBrackets++;
				GetNextWord(&InBuf);
		  } else if(TempString[0]==')') {
				PrevTotalBrackets--;
				if(PrevTotalBrackets) GetNextWord(&InBuf);
		  } else {
				if(strcmp(TempString,"rest")==0) {
    			/* Rest (&rest) */
        			if((VarStruct=IsVarName(GetNextWord(&InBuf))).Type!=vPARAM) {
            			ShowMessage(errPARAMVAREXP,NULL);
            			return FALSE;
		  			}
	    			WriteOpInt(acREST, VarStruct.Index);
    			} else {
					TotalSelectors++;
                	if((SelectorIndex=GetSelectorIndex(TempString, caCAN_NOT_ADD))!=-1)
					    SCIPush(SelectorIndex,FALSE);
                	else if((VarStruct=IsVarName(TempString)).Type!=-1) {
    					/* Get variable or prop*/
            			if(!HandleGetVarProp(&ccVS,ccSTACK,NULL,NULL,NULL,FALSE,FunctionType))
            			    return -1;
    			    } else {
                	    NewTotalBrackets = PrevTotalBrackets;
                 	   do {
                 	       if(!CompileChunk(ccSTACK,&NewTotalBrackets,FunctionType, FALSE)) return -1;
                	    } while(NewTotalBrackets>PrevTotalBrackets);
                	    SeekBack(&InBuf);
                	}

					if((TotalCodeArgs=HandleFunction(&PrevTotalBrackets,FunctionType))==-1) return -1;
					TotalSelectors+=TotalCodeArgs+1;
                }
				if(PrevTotalBrackets) GetNextWord(&InBuf);
		  }
	 } while(PrevTotalBrackets);

    SeekBack(&InBuf);

	 return TotalSelectors;
}
/******************************************************************************/
BOOL HandleOperator(int Index, int TotalCodeBrackets, int FunctionType)
{
    int UseOp, InBrackets;
    BOOL fTWO_ARGS;
            GetNextWord(&InBuf);
            UseOp = ccSTACK;
            InBrackets = TotalCodeBrackets;
            fTWO_ARGS = FALSE;
            do {
                if(TempString[0]=='(') {
                    InBrackets++;
                    GetNextWord(&InBuf);
                } else if(TempString[0]==')') {
                    InBrackets--;
                    if(InBrackets) GetNextWord(&InBuf);
                } else {
						  if(!CompileChunk(UseOp,&InBrackets, FunctionType, FALSE)) return FALSE;
                    		GetNextWord(&InBuf);
						  UseOp ^= 1;
						  if(UseOp==ccSTACK) {
								fTWO_ARGS = TRUE;
								WriteOpcode(Operators[Index].Code,FALSE);
						  }
					 }
        } while(InBrackets>TotalCodeBrackets||!fTWO_ARGS);
        SeekBack(&InBuf);
	 return TRUE;
}
/******************************************************************************/
BOOL HandleGetVarProp(tsVS *ccVS, BOOL fSTACK, BYTE *OpRes, char**GVPInBuf, WORD *OldCodeBufOffset, BOOL *fADDITIONAL_INDEX, int FunctionType)
{
    BYTE Operator;
    char* OIB;
    int NoBracks;

    tsVARSTRUCT VarStruct = {-1,-1};

    ccVS->Type = -1;
    ccVS->Index = -1;
	ccVS->PROP = FALSE;
    
    if(fADDITIONAL_INDEX!=NULL) *fADDITIONAL_INDEX = FALSE;
    if(GVPInBuf!=NULL) *GVPInBuf = 0;

    if((VarStruct=IsVarName(TempString)).Type==-1) {
        if(FunctionType==ccPROCEDURE||(ccVS->Index=GetPropertyIndex(SelfInfo.Index,TempString,SelfInfo.INSTANCE))==-1) {
            ShowMessage(errVARNAMEEXP,NULL);
            return FALSE;
        }
        ccVS->PROP = TRUE;
        Operator = acPTOA;
        if(fSTACK) Operator+=2;
        if(OpRes==NULL)
            WriteOpInt(Operator,GET_PROPERTY_OFFSET(ccVS->Index));
    } else {
        ccVS->Type = VarStruct.Type;
        ccVS->Index = VarStruct.Index;
        Operator = 0x40|(ccVS->Type&3);
        if(fSTACK) Operator|=4;
        if(*InBuf=='[') {
            InBuf++;
            OIB = InBuf;
            GetNextWord(&InBuf);
            if(IsStringNum(TempString)) {
                ccVS->Index += StrToInt(TempString);
            } else {
                if(GVPInBuf!=NULL) {
                    *OldCodeBufOffset = CodeBufOffset;
                    *GVPInBuf = OIB;
                }
                *fADDITIONAL_INDEX = TRUE;
                NoBracks = 0;
                do {
                    if(NoBracks) GetNextWord(&InBuf);
                    if(!CompileChunk(ccACC,&NoBracks,FunctionType, FALSE)) {
                        return FALSE;
                    }
                } while(NoBracks);

                if(GVPInBuf!=NULL) {
                    CodeBufOffset = *OldCodeBufOffset;
                }       
                /* acc as additional index */
                Operator|=8;
            }

            if(*GetNextWord(&InBuf)!=']') {
                ShowMessage(errARRAYENDEXP,NULL);
                return FALSE;
            }
        }
		  if(OpRes==NULL)
            WriteOpInt(Operator,ccVS->Index);
	 }
    if(OpRes!=NULL) *OpRes = Operator;
    return TRUE;
}
/******************************************************************************/
int SkipCodeBlock()
{
	int TotalBrackets = 0;
   int RetVal = 2;
	do {
   	if(*InBuf=='(') {
			TotalBrackets++;
	 	} else if(*InBuf==')') {
      	TotalBrackets--;
		}
      if(*InBuf=='\0') break;
		InBuf++;
      if(!TotalBrackets&&*InBuf==':') break;
   } while(1);
   if(*InBuf=='\0') {
		ShowMessage(errOUTBRACEXP,NULL);
		return 0;
   }
   return RetVal;
}
/******************************************************************************/
BOOL CompileChunk(BOOL fSTACK, int *_CodeBrackets, int FunctionType, BOOL GET_NEXT_WORD)
{
	 int Index, ArgVal, TotalCodeBrackets = *_CodeBrackets, PrevTotalBrackets,
		  TotalCodeArgs;
     WORD OldCodeBufOffset;
	 BYTE Operator=0;
	 char *GVPInBuf, *SavedInBuf;
	 BOOL fDEC,fADDITIONAL_INDEX;
	 tsSELFINFO ClassInfo;
	  short Super;

	 tsVS ccVS;
	 ccVS.Index = -1;

	  Index = -1;

	 if(TempString[0]=='(') {
		  TotalCodeBrackets++;
	 } else if(TempString[0]==')') {
		  TotalCodeBrackets--;
	 } else if(strcmp(TempString,"if")==0) {
			if(!CompileIfStatement(FunctionType,itIF)) {
            	return FALSE;
            }                          
            CAN_DUP = FALSE;
            if(fSTACK) WriteOpcode(acPUSH,FALSE);
			TotalCodeBrackets--;
     } else if(strcmp(TempString,"do")==0) {
			if(!CompileIfStatement(FunctionType,itDOWHILE)) {
            	return FALSE;
            }
			TotalCodeBrackets--;
		} else if(strcmp(TempString,"while")==0) {
			if(!CompileIfStatement(FunctionType,itWHILE)) {
            	return FALSE;
            }
			TotalCodeBrackets--;
		} else if(strcmp(TempString,"switch")==0) {
			if(!CompileSwitch(FunctionType)) {
            	return FALSE;
            }
            TotalCodeBrackets--;
		} else if(strcmp(TempString,"for")==0) {
			if(!CompileFor(FunctionType)) {
            	return FALSE;
            }
			TotalCodeBrackets--;
		} else  if(strcmp(TempString,"++")==0||strcmp(TempString,"--")==0) {
	 /* int/dec variable */
		 /* Bit 1-2 - var type */
		  fDEC = TempString[0]=='-';

            GetNextWord(&InBuf);
			if(!HandleGetVarProp(&ccVS, fSTACK,&Operator,NULL,NULL,&fADDITIONAL_INDEX,FunctionType))
                return FALSE;

		    if(ccVS.PROP) {
				Operator = acIPTOA;
				if(fDEC)   Operator += 1;
                if(fSTACK) Operator += 2;

				WriteOpInt(Operator,GET_PROPERTY_OFFSET(ccVS.Index));
		    } else {
                if(fSTACK) Operator |= 4;
                WriteOpInt(fDEC?Operator|0x30:Operator|0x20,ccVS.Index);
            }
    } else if((Index=IsStringOperator(TempString))!=-1||TempString[0]=='=') {
    /* Get Operator */
        if(Index!=-1&&*InBuf != '=') {
            if(!HandleOperator(Index,TotalCodeBrackets,FunctionType)) return FALSE;
            
            CAN_DUP = FALSE;
            if(fSTACK) WriteOpcode(acPUSH,FALSE);
		  } else if(*InBuf == '=') {
            InBuf++;
            ccVS.Index = -1;
            ccVS.PROP = FALSE;

            GetNextWord(&InBuf);
            if(!HandleGetVarProp(&ccVS, ccSTACK,NULL,NULL,NULL,&fADDITIONAL_INDEX,FunctionType))
                return FALSE;
            PrevTotalBrackets = TotalCodeBrackets;
            do {                    
                GetNextWord(&InBuf);
                if(!CompileChunk(ccACC,&PrevTotalBrackets,FunctionType, FALSE)) return FALSE;
            } while(PrevTotalBrackets>TotalCodeBrackets);

            WriteOpcode(Operators[Index].Code,FALSE);

            if(ccVS.PROP) {
					 Operator = fSTACK?acATOP+1:acATOP;
	            WriteOpInt(acATOP,GET_PROPERTY_OFFSET(ccVS.Index));
            } else {
                WriteOpInt(0x50|(ccVS.Type&3),ccVS.Index);
                
                CAN_DUP = FALSE;
                if(fSTACK) WriteOpcode(acPUSH,FALSE);
            }
		  } else /* = */ {
            GetNextWord(&InBuf);
            if(!HandleGetVarProp(&ccVS, ccACC,&Operator,&GVPInBuf,&OldCodeBufOffset,&fADDITIONAL_INDEX,FunctionType))
                return FALSE;
            PrevTotalBrackets = TotalCodeBrackets;
				do {                   
                GetNextWord(&InBuf);
                if(!CompileChunk(ccACC,&PrevTotalBrackets,FunctionType, FALSE)) return FALSE;
            } while(PrevTotalBrackets>TotalCodeBrackets);
            if(ccVS.PROP) {
	            WriteOpInt(Operator+1,GET_PROPERTY_OFFSET(ccVS.Index));
				} else {
                if(GVPInBuf) {    
                    CAN_DUP = FALSE;
                    WriteOpcode(acPUSH,FALSE);
                    SavedInBuf=InBuf;
                    InBuf=GVPInBuf;
                    GetNextWord(&InBuf);
                    if(!CompileChunk(ccACC,&PrevTotalBrackets,FunctionType, FALSE)) return FALSE;
                    InBuf=SavedInBuf;
                    Operator |= 4;
                }
                WriteOpInt(Operator|0x10,ccVS.Index);
            }           
            CAN_DUP = FALSE;
            if(fSTACK) WriteOpcode(acPUSH,FALSE);
        }
    } else if(IsStringNum(TempString)) {
    /* Get Integer */
        if(fSTACK) SCIPush(StrToInt(TempString),FALSE);
        else SCILDI(StrToInt(TempString));
	 } else if(IsVarName(TempString).Type!=-1||
		  (FunctionType!=ccPROCEDURE&&(Index=GetPropertyIndex(SelfInfo.Index,TempString,SelfInfo.INSTANCE))!=-1)) {
	 /* Get variable or prop*/
            if(!HandleGetVarProp(&ccVS, fSTACK,NULL,NULL,NULL,&fADDITIONAL_INDEX,FunctionType))
                return FALSE;
    } else if(TempString[0]=='@') {
    /* Get variable address */
        GetNextWord(&InBuf);
        if(!HandleGetVarProp(&ccVS, fSTACK,&Operator,NULL,NULL,&fADDITIONAL_INDEX,FunctionType))
            return FALSE;
        if(ccVS.PROP) {
            ShowMessage(errADDRPROP,NULL);
            return FALSE;
        }
        WriteOpcode(acLEA,FALSE);
        if(fADDITIONAL_INDEX) {
            AddCodeW((ccVS.Type<<1)|0x10);
        } else {
				AddCodeW(ccVS.Type<<1);
        }
        AddCodeW(ccVS.Index);
        CAN_DUP = FALSE;
        if(fSTACK) WriteOpcode(acPUSH, FALSE);
    } else if(TempString[0]=='#') {
    /* Get selector index */
        GetNextWord(&InBuf);
        if((Index=GetSelectorIndex(TempString,caCAN_NOT_ADD))==-1) {
            ShowMessage(errSELECTORNAMEEXP,NULL);
				return FALSE;
        }
        if(fSTACK) SCIPush(Index,FALSE);
        else SCILDI(Index);
    } else if(TempString[0]=='"'||(Index=IsStringName(TempString))!=-1) {
        if(TempString[0]=='"') {
				if(!DoString()) return FALSE;
            ArgVal = AddString(TempString);
        } else {
				ArgVal = Strings[Index].Offset;
            if(*InBuf=='[') {
                InBuf++;
                GetNextWord(&InBuf);
                if(!IsStringNum(TempString)) {
                    ShowMessage(errINTEXP,NULL);
                    return FALSE;
                }
                ArgVal+=StrToInt(TempString);
                if(*InBuf!=']')  {
                    ShowMessage(errARRAYENDEXP,NULL);
                    return FALSE;
                }
                InBuf++;
            }
		  }
        ChgOffCode[TotalChgOffCode  ].Offset = CodeBufOffset+1;
        ChgOffCode[TotalChgOffCode++].STRING = TRUE;
		  WriteOpcode((fSTACK)?acLOFSS:acLOFSA,FALSE);
        AddCodeW(ArgVal);
    } else if(TempString[0]=='\'') {
        if((ArgVal=CompileSaid())==-1) {
            ShowMessage(errINVSAID,NULL);
            return FALSE;
        }
        ChgOffCode[TotalChgOffCode  ].Offset = CodeBufOffset+1;
        ChgOffCode[TotalChgOffCode++].SAID   = TRUE;
        WriteOpcode((fSTACK)?acLOFSS:acLOFSA,FALSE);    
        AddCodeW(ArgVal);
    } else /*if(strcmp(TempString,"rest")==0) {
    /* Rest (&rest) */ /*
        if((VarStruct=IsVarName(GetNextWord(&InBuf))).Type!=vPARAM) {
            ShowMessage(errPARAMVAREXP,NULL);
            return FALSE;
		  }

		 WriteOpInt(acREST, VarStruct.Index);
    } else */if((Index=IsKernelName(TempString))!=-1) {
    /* Kernel call (callk) */
        if((TotalCodeArgs=HandleFunction(&TotalCodeBrackets,FunctionType))==-1) return FALSE;
        WriteOpInt(acCALLK, Index);
        AddCodeB(TotalCodeArgs<<1);
		  /* defalt result in the accumulator. If it's for the stack, push the acc */   
        CAN_DUP = FALSE;
        if(fSTACK) WriteOpcode(acPUSH, FALSE);
    } else if((Index=IsProcedureName(TempString))!=-1) {
    /* Procedure call (call) */
        if((TotalCodeArgs=HandleFunction(&TotalCodeBrackets,FunctionType))==-1) return FALSE;
	    WriteOpcode(acCALL,0);
	    ChgOffCode[TotalChgOffCode  ].Offset = CodeBufOffset;
	    ChgOffCode[TotalChgOffCode  ].REL = TRUE;
	    ChgOffCode[TotalChgOffCode++].Procedure = Index;
	    AddCodeW(0);
        AddCodeB(TotalCodeArgs<<1);
                                    
        CAN_DUP = FALSE;
		  if(fSTACK) WriteOpcode(acPUSH,FALSE);
    } else if((Index=IsExpProcedureName(TempString))!=-1) {
    /* External Procedure call (callb/calle) */
        if((TotalCodeArgs=HandleFunction(&TotalCodeBrackets,FunctionType))==-1) return FALSE;

        if(ExternalProcs[Index].Script) {
			  WriteOpcode(acCALLE,FALSE);
           AddCodeW(ExternalProcs[Index].Script);
           AddCodeW(ExternalProcs[Index].Index);
        } else
	        WriteOpInt(acCALLB,ExternalProcs[Index].Index);
        AddCodeB(TotalCodeArgs<<1);
                          
        CAN_DUP = FALSE;
        if(fSTACK) WriteOpcode(acPUSH,FALSE);
    } else if((ClassInfo=GetClassIndex(TempString)).Index!=-1||strcmp(TempString,"send")==0) {
    		GVPInBuf = NULL;
        if(ClassInfo.Index==-1) {
        		GVPInBuf = InBuf;
				Index = SkipCodeBlock();
            if(Index==0) return FALSE;
            if(*InBuf=='\0') {
                ShowMessage(errCOLONEXP,NULL);
                return FALSE;
            }      
            if(Index==1) InBuf++;
        }
        if(*InBuf==':') {
	 /* Get/Set/Call Class Entires (send) or Get class offset (class) */
            /*if(ClassInfo.INSTANCE) {
                ShowMessage(errSENDTOINST,NULL);
                return FALSE;
				}     */

            InBuf++;
				if((TotalCodeArgs=HandleSend(FunctionType))==-1) return FALSE;
            /*TotalCodeBrackets--;      */
            if((short)ClassInfo.Index!=(short)-1) {
                if(ClassInfo.INSTANCE) {
                    ChgOffCode[TotalChgOffCode  ].Offset = CodeBufOffset+1;
                    ChgOffCode[TotalChgOffCode++].INSTANCE = TRUE;
                    WriteOpcode(acLOFSA,FALSE);
					 AddCodeW(ClassInfo.Index);
                } else
                    WriteOpInt(acCLASS, sClasses[ClassInfo.Index].Species);
            } else {       /*
                if(ccVS.PROP) {
                    WriteOpInt(Operator,GET_PROPERTY_OFFSET(ccVS.Index));
                } else {  */
                    if(GVPInBuf!=NULL) {
                        SavedInBuf=InBuf;
                        InBuf=GVPInBuf;

                        GetNextWord(&InBuf);
                        if(TempString[0]=='(') {
                           PrevTotalBrackets  = 0;
									do {
                					if(!CompileChunk(ccACC,&PrevTotalBrackets,FunctionType, TRUE))
                           		return FALSE;
            					} while(PrevTotalBrackets);
            					if(*InBuf!=':') {
                					ShowMessage(errVARCOLON,NULL);
                					return FALSE;
            					}
                        } else {
                        	if(!CompileChunk(ccACC,&TotalCodeBrackets,FunctionType, FALSE))
                           	return FALSE;
            					if(*InBuf!=':') {
                					ShowMessage(errVARCOLON,NULL);
                					return FALSE;
            					}
                        }
                        InBuf=SavedInBuf;
                    } else {
                    	ShowMessage(errVARCOLON,NULL);
                        return FALSE;
                    }
                /*}*/
            }
            WriteSendOpcode();
            AddCodeB(TotalCodeArgs<<1);   
            CAN_DUP = FALSE;
            if(fSTACK) WriteOpcode(acPUSH,FALSE);
        } else {
            if(ClassInfo.INSTANCE&&((short)ClassInfo.Index!=(short)-1)) {
                ChgOffCode[TotalChgOffCode  ].Offset = CodeBufOffset+1;
                ChgOffCode[TotalChgOffCode++].INSTANCE = TRUE;
                WriteOpcode((fSTACK)?acLOFSS:acLOFSA,FALSE);
					 AddCodeW(ClassInfo.Index);
            } else if(ClassInfo.Index!=-1) {
                 WriteOpInt(acCLASS, sClasses[ClassInfo.Index].Species);    
                CAN_DUP = FALSE;
                 if(fSTACK) WriteOpcode(acPUSH,FALSE);
            } else {
                WriteOpInt(Operator,ccVS.Index);   
                CAN_DUP = FALSE;
                if(fSTACK) WriteOpcode(acPUSH,FALSE);
            }
        }
    } else if(strcmp(TempString,"super")==0) {
    /* Get/Set/Call SuperClass Entires (super) or Get super offset (class) */
        if(sClasses[SelfInfo.Index].Superclass==-1) {
            ShowMessage(errCLASSNOSUPER,NULL,
            	(SelfInfo.INSTANCE)?Instances[SelfInfo.Index].Name:sClasses[SelfInfo.Index].Name);
            return FALSE;
        }
        Super = (SelfInfo.INSTANCE)? Instances[SelfInfo.Index].Superclass:
        	sClasses[SelfInfo.Index].Superclass;
        if(*InBuf==':') {
            InBuf++;
            if((TotalCodeArgs=HandleSend(FunctionType))==-1) return FALSE;
				/*TotalCodeBrackets--;     */
            WriteOpInt(acSUPER,Super);
            AddCodeB(TotalCodeArgs<<1);
        } else WriteOpInt(acCLASS, Super);  
        CAN_DUP = FALSE;
        if(fSTACK) WriteOpcode(acPUSH,FALSE);
    } else if(strcmp(TempString,"self")==0) {
        if(*InBuf==':') {
    /* Get/Set/Call self Entires (self) */
            InBuf++;
				if((TotalCodeArgs=HandleSend(FunctionType))==-1) return FALSE;
            /*TotalCodeBrackets--;*/
            WriteOpcode(acSELF,TRUE);
            AddCodeB(TotalCodeArgs<<1);     
            CAN_DUP = FALSE;
            if(fSTACK) WriteOpcode(acPUSH,FALSE);
        } else {
    /* Get Self Offset (pushSelf) */     
            CAN_DUP = FALSE;
            WriteOpcode(fSTACK?acPUSHSELF:acSELFID, FALSE);
        }
	 } else if(strcmp(TempString,"not")==0) {
    /* Get Operator */
        PrevTotalBrackets = TotalCodeBrackets;
        do {                
            GetNextWord(&InBuf);
            if(!CompileChunk(ccACC,&TotalCodeBrackets,FunctionType, FALSE)) return FALSE;
        } while(TotalCodeBrackets>PrevTotalBrackets);
        WriteOpcode(acNOT,FALSE);       
        CAN_DUP = FALSE;
        if(fSTACK) WriteOpcode(acPUSH,FALSE);
	 }  else if(strcmp(TempString,"neg")==0) {
    /* Get Operator */
        PrevTotalBrackets = TotalCodeBrackets;
        do {                   
            GetNextWord(&InBuf);
            if(!CompileChunk(ccACC,&TotalCodeBrackets,FunctionType, FALSE)) return FALSE;
        } while(TotalCodeBrackets>PrevTotalBrackets);

        WriteOpcode(acNEG,FALSE); 
        CAN_DUP = FALSE;
        if(fSTACK) WriteOpcode(acPUSH,FALSE);
	 }  else if(strcmp(TempString,"bnot")==0) {
    /* Get Operator */
        PrevTotalBrackets = TotalCodeBrackets;
        do {            
            GetNextWord(&InBuf);
            if(!CompileChunk(ccACC,&TotalCodeBrackets,FunctionType, FALSE)) return FALSE;
        } while(TotalCodeBrackets>PrevTotalBrackets);

        WriteOpcode(acBNOT,FALSE);
        CAN_DUP = FALSE;
        if(fSTACK) WriteOpcode(acPUSH,FALSE);
	 } else if(strcmp(TempString,"break")==0) {
    /* Get Operator */
    	if(LoopStackCount==0) {
			ShowMessage(errBADBREAK,NULL);
			return FALSE;
		}
        WriteOpcode(acJMP,FALSE);
        USE_LOOP_STACK(CodeBufOffset);
		AddCodeW(0);
	 } else if((Index=IsObjectPropPtr(TempString))!=-1) {
        if(fSTACK) WriteOpcode(acPTOS,FALSE);
        else WriteOpcode(acPTOA,FALSE);
        AddCodeW(ObjectPropPtr[Index].Code);
    } else if(strcmp(TempString,"asm")==0) {   
        if(!DoAssembly(FunctionType)) {
            return FALSE;
        }                  
        CAN_DUP = FALSE;
        if(fSTACK) WriteOpcode(acPUSH,FALSE);
        TotalCodeBrackets--;
	} else if(strcmp(TempString,"return")==0) {
    /* Return (ret) */
	    if(GetNextWord(&InBuf)[0]=='(') {
            TotalCodeBrackets++;
		    GetNextWord(&InBuf);
            PrevTotalBrackets = TotalCodeBrackets;
            do {
                if(!CompileChunk(ccACC,&TotalCodeBrackets,FunctionType, TRUE)) return FALSE;
            } while(TotalCodeBrackets>PrevTotalBrackets);
            TotalCodeBrackets--;
	    } else SeekBack(&InBuf);
        WriteOpcode(acRET,0);
    } else {
        ShowMessage(errUNDEFSYM,NULL,TempString);
        return FALSE;
    }
    if(TotalCodeBrackets&&GET_NEXT_WORD) GetNextWord(&InBuf);

    *_CodeBrackets = TotalCodeBrackets;
    return TRUE;
}
/******************************************************************************/

/***************************************************************************
 *  Copyright (C) 1999-2001 Brian Provinciano, http://www.bripro.com
 ***************************************************************************/
