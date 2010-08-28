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
 * SCI Script Compiler Compiler Aid Routines
 ******************************************************************************/
#include "scc.h"
/******************************************************************************/
#ifdef SCC_SCISTUDIO_WIN32
#pragma hdrstop
#pragma package(smart_init)
#endif
/******************************************************************************/
char *GetNextWord(char **_Buf)
{
	char *xBuf = *_Buf;
	int  CharPos = 0;
	BOOL WORD_FOUND = FALSE;

	if(*_Buf=='\0') {
		TempString[0] = '\0';
		return TempString;
	}

    OldBuf = xBuf;      
    OldLine = LineNumber;

	while(!WORD_FOUND) {
        if(*xBuf=='{') {
            xBuf++;
            while(*xBuf!='}'&&*xBuf!='\0')
                TempString[CharPos++] = *xBuf++;
            TempString[CharPos] = '\0';
            TempString[CharPos+1] = SPECIAL_STRING_CHAR;
            xBuf++;
            *_Buf = xBuf;
            return TempString;
        }
		if(( *xBuf=='+'&& *(xBuf+1)=='+' ) ||
		   ( *xBuf=='-'&& *(xBuf+1)=='-' )) {
				TempString[0] = *xBuf;
				TempString[1] = *xBuf;
				TempString[2] = 0;
				xBuf+=2;
				*_Buf = xBuf;
				return TempString;
		}
		if(!IN_ASM_MODE&&(( *xBuf=='+'&& (!isdigit( *(xBuf+1) )) ) ||
		   ( *xBuf=='-'&& (!isdigit( *(xBuf+1) )) ))) {
				TempString[0] = *xBuf;
				TempString[1] = 0;
				xBuf++;
				*_Buf = xBuf;
				return TempString;
		}
		if((*xBuf=='<'||*xBuf=='>')&&
           (*(xBuf+1)=='='||*(xBuf+1)=='u')
        ) {
				TempString[0] = *xBuf;
				TempString[1] = *(xBuf+1);
                if(*(xBuf+1)=='='&&*(xBuf+2)=='u') {
				    TempString[2] = *(xBuf+2);
				    TempString[3] = 0;
				    xBuf+=3;
				} else {
                    TempString[2] = 0;
				    xBuf+=2;
                }
				*_Buf = xBuf;
				return TempString;
		}
		switch(*xBuf) {
			case '/': /* get rid of commented code */
				if(*(xBuf+1) == '/') { /* // - one line comment */
					xBuf+=2;
					while(*xBuf != '\n' && *xBuf != '\0') xBuf++;
					if(*xBuf == '\n') {
						LineNumber++;
						xBuf++;
					}
				} else if(*(xBuf+1) == '*') {/* '/''*' to '*''/' - multiline */
					xBuf+=2;
					while(!(*xBuf == '*' && *(xBuf+1) == '/') && *xBuf != '\0') {
						if(*xBuf == '\n') LineNumber++;
						xBuf++;
					}
					xBuf+=2;
				} else {
					TempString[0] = *xBuf;
					TempString[1] = '\0';
					xBuf++;
					*_Buf = xBuf;
			    	return TempString;
				}
				break; /* Word still not found, will loop */
			case '&':
                if(*(xBuf+1)=='r') {
				    TempString[0] = *xBuf;
				    xBuf++;
				    CharPos = 1;
                    continue;
                }
			case '(':
			case ')':
			case '"':
			case '\'':
			case ':':
			case ',':
			case '.':
			case '=':
			case '{':
			case '}':
			case '!':
			case '[':
			case ']':
			case '@':
			case '*':
			case '<':
			case '>':
			case '%':
			case '^':
			case '|':
			case '#':
			case '?':
				TempString[0] = *xBuf;
                if((*xBuf=='>'||*xBuf=='<')&&
                   (*(xBuf+1)=='>'||*(xBuf+1)=='<')) {
					TempString[1] = *(xBuf+1);
					TempString[2] = '\0';
					xBuf+=2;
				} else if(*xBuf=='='&&*(xBuf+1)=='=') {
					TempString[1] = '=';
					TempString[2] = '\0';
					xBuf+=2;
				} else {
					TempString[1] = '\0';
					xBuf++;
				}
				*_Buf = xBuf;
				return TempString;
			case '\t':
			case '\n':
			case '\r':
			case ' ':
				while(*xBuf == ' ' || *xBuf == '\n' || *xBuf == '\r' || *xBuf == '\t')
					if(*xBuf++ == '\n') LineNumber++;
				if(*xBuf == '\0') {
					TempString[0] = '\0';
					return TempString;
				}
				break;  /* Word still not found, will loop */
			case '+':
			case '-':
			case '$': /* hex */
				TempString[0] = *xBuf;
				xBuf++;
				CharPos = 1;
				/* clears the way for no alphanum chars, continue */
			default:
				if((!isalnum(*xBuf)) && (*xBuf != '_')) {
					TempString[0] = '\0';
					return TempString;
				}
				while(isalnum(*xBuf) || *xBuf == '_') TempString[CharPos++] = *xBuf++;
                if(IN_ASM_MODE&&*xBuf == '?') {
                    TempString[CharPos++] = *xBuf++;
                }
				TempString[CharPos] = '\0';

				if(USE_DEFINES) CheckWordDefined();

				/*WordInDefine(TempString);*/
				WORD_FOUND = TRUE;
		}
	}
	*_Buf = xBuf;
	return TempString;
}
/******************************************************************************/
void SeekBack(char **_Buf)
{
    LineNumber = OldLine;
    *_Buf = OldBuf;
}
/******************************************************************************/
int StrToInt(char *String)
{
	 int i;
	 long Num = 0;

	 /* Check the format (is it HEX) */
	 if(String[0] == '$') {
		  for(i = 1; String[i] != '\0'; i++) {
				Num <<= 4;
				if(String[i] >= '0' && String[i] <= '9')
					  Num += String[i]-'0';
				else if(((char)(String[i] & 0xDF) >= 'A') &&
					  ((char)(String[i] & 0xDF) <= 'F'))
					 Num += ((char)(String[i] & 0xDF)-'A') + 10;
		  }
	 } else {
		  i = 0;
          if(strcmp(String,"scriptNumber")==0) {
		  	 if(ScriptNumber==-1) {
				ShowMessage(errSCRIPTNUMNOTSPEC,NULL);
				return FALSE;
             }
             return ScriptNumber;
          }
		  if(String[0] == '+' || String[0] == '-') i++;
		  while(String[i] != 0) {
				Num = (Num * 10) + (String[i]-'0');
				i++;
		  }
		  if(String[0] == '-') Num = -Num;
	 }

	return (int)(Num);
}
/******************************************************************************/
BOOL IsStringLabel(char *String)
{
	int CharPos;
	if(String[strlen(String)+1]==SPECIAL_STRING_CHAR) return TRUE;
    if(!isalpha(String[0]) && String[0]!='_') return FALSE;
	for(CharPos = 1; String[CharPos] != '\0'; CharPos++)
		if(!isalnum(String[CharPos]) && String[CharPos]!='_') return FALSE;
	return TRUE;
}     
/******************************************************************************/
int IsStringOperator(char *String)
{
	int i;       
	for(i = 0; i<TOTAL_OPS; i++)
		if(strcmp(String,Operators[i].String)==0) return i;
	return -1;
}
/******************************************************************************/
int IsSegmentName(char *String)
{
	int i;       
	for(i = 0; i<TOTAL_SEGMENTS; i++)
		if(strcmp(String,SegmentNames[i])==0) return i;
	return -1;
}
/******************************************************************************/
BOOL IsStringNum(char *String)
{
	 int CharPos = 0;
	 if(String[0] == '\0') return FALSE;
	 if(String[0] == '$') {
		  if(String[1] == '\0') return FALSE;
		  CharPos++;
		  while(String[CharPos] != '\0')
				if(!((String[CharPos] >= '0' && String[CharPos] <= '9') ||
				((char)(String[CharPos] & 0xDF) >= 'A' && (char)(String[CharPos] & 0xDF) <= 'F')))
					 return FALSE;
				else CharPos++;
	 } else {
		  if(String[0] == '+' || String[0] == '-') {
				CharPos++;
				if(String[1] == '\0') return FALSE;
		  }
          if(strcmp(TempString,"scriptNumber")==0)
          	return TRUE;
		  while(String[CharPos] != '\0')
				if(String[CharPos] < '0' || String[CharPos] > '9')
						  return FALSE;
				else CharPos++;
	 }
	 return TRUE;
}
/******************************************************************************/
BOOL IsLabelDefined(char *String)
{
	int i,j;
	/* Check the variables */
	for(i = 0; i < 4; i++)
		for(j = 0; j < TotalVar[i]; j++)
            if(Var[i][j].Label!=NULL)
			    if(strcmp(String,Var[i][j].Label)==0) return TRUE;
    for(j = 0; j < TotalStrings; j++)
        if(Strings[j].Label!=NULL)
            if(strcmp(String,Strings[j].Label)==0) return TRUE;
	return FALSE;
}
/******************************************************************************/
int IsStringName(char *String)
{
	int i;
    for(i = 0; i < TotalStrings; i++)
        if(Strings[i].Label!=NULL)
            if(strcmp(String,Strings[i].Label)==0) return i;
	return -1;
}
/******************************************************************************/
int GetSegmentIndex(char *String)
{
	int i;
	for(i = 0; i < TOTAL_SEGMENTS; i++)
		if(strcmp(SegmentNames[i],String)==0&&SegmentNames[i][0]!='\0')
			return i;
	return -1;
}
/******************************************************************************/
void CheckWordDefined()
{
	int i;
	for(i=0;i<TotalDefines;i++)
		if(strcmp(Defines[i].Label,TempString)==0) {
			strcpy(TempString,Defines[i].Definition);
			return;
		}
}
/******************************************************************************/
tsSELFINFO GetClassIndex(char *String)
{
	 int Class;
     tsSELFINFO si = {-1,-1};
     for(Class = 0; Class < TotalLocalClasses; Class++)
        if(sClasses[Class].Name!=NULL&&strcmp(sClasses[Class].Name,String)==0){
            si.Index = Class;
            si.INSTANCE = FALSE;
            return si;
        }
     for(Class = 0; Class < TotalInstances; Class++)
        if(Instances[Class].Name!=NULL&&strcmp(Instances[Class].Name,String)==0) {
            si.Index = Class;
            si.INSTANCE = TRUE;
            return si;
        }

	 return si;
}
/******************************************************************************/
int GetSelectorIndex(char *String, BOOL CAN_ADD)
{
	 int Selector;
	 for(Selector = 0; Selector < TotalSelectorNames; Selector++)
		  if(strcmp(SelectorNames[Selector],String)==0)
			return Selector;

	 if(CAN_ADD) return AddSelectorName(String);
     return -1;
}
/******************************************************************************/
int GetPropertyInClass(int Class, int Index)
{
	 int Property;
	 for(Property = 0; Property < sClasses[Class].TotalProperties; Property++)
		  if(sClasses[Class].PropertyNameIndexes[Property] == Index)
			return Property;

	 return -1;
}
/******************************************************************************/
int GetClassEntry(int Class)
{
    int i;
    for(i=0;i<TotalGlobalClasses;i++)
        if(sClasses[i].Species==Class) {
            return i;
        }
    return -1;
}
/******************************************************************************/
int GetPropertyIndex(int Class, char *String, BOOL INSTANCE)
{
	 int Property;
     if((Property=IsObjectPropPtr(String))!=-1)
     	return(Property);
     if(INSTANCE) {
     	if(Instances[Class].TotalProperties) {
	    	for(Property = 0; Property < Instances[Class].TotalProperties; Property++)
		    	if(strcmp(SelectorNames[Instances[Class].PropertyNameIndexes[Property]],String)==0)
			    	return Property;
        } else {
        	Class = GetClassEntry(Instances[Class].Superclass);
	    	for(Property = 0; Property < sClasses[Class].TotalProperties; Property++)
		    	if(strcmp(SelectorNames[sClasses[Class].PropertyNameIndexes[Property]],String)==0)
			    	return Property;
        }
     } else {
	    for(Property = 0; Property < sClasses[Class].TotalProperties; Property++) {
		    if(strcmp(SelectorNames[sClasses[Class].PropertyNameIndexes[Property]],String)==0)
			    return Property;
        }
     }
    return(-1);
}
/******************************************************************************/
int AddString(char *String)
{
	 int RetVal = StringSegLen, StrLen = strlen(String)+1;
	 memcpy(StringSegment+StringSegLen,String,StrLen);
	 StringSegLen += StrLen;

	 return RetVal;
}
/******************************************************************************/
BOOL DoString()
{
    int StrLen=0;
    while(*InBuf!='\0') {
        if(*InBuf == '"' && *(InBuf-1) != '\\') {
        	if(*(InBuf+1)=='+') {
            	InBuf+=2;
            	while(*InBuf!='\0'&&(*InBuf==' '||*InBuf=='\t'||*InBuf=='\r'||*InBuf=='\n')) {
                        if(*InBuf=='\n') LineNumber++;
                    	InBuf++;
                }
                if(*InBuf!='"') {
                  	ShowMessage(errENDOFSTRINGEXP,NULL);
                    return FALSE;
                }
           		InBuf++;
            } else break;
        }
        else if(*InBuf == '\\') {
            switch(*(InBuf+1)) {
                case 'n':
                    TempString[StrLen++]='\n';
                    InBuf+=2;
                    break;
                case 't':
                    TempString[StrLen++]='\t';
                    InBuf+=2;
                    break;
                case '"':
                    TempString[StrLen++]='"';
                    InBuf+=2;
                    break;
                case '\\':
                    TempString[StrLen++]='\\';
                    InBuf+=2;
                    break;
                default: InBuf++;
            }
        } else TempString[StrLen++]=*InBuf++;
    }
    if(*InBuf=='\0') return FALSE;
    TempString[StrLen]='\0';
    InBuf++; /* +1 for end quote */
    return TRUE;
}
/******************************************************************************/
int IsOpcodeName(char *String)
{
	int i;
	for(i = 0; i < TOTAL_OPCODES; i++)
		if(strcmp(OpcodeNames[i],String)==0)
			return i;

	return -1;
}
/******************************************************************************/
int IsKernelName(char *String)
{
	int i;
	for(i = 0; i < TotalKernels; i++)
		if(strcmp(KernelNames[i],String)==0)
			return i;

	return -1;
}
/******************************************************************************/
int IsProcedureName(char *String)
{
	int i;
	for(i = 0; i < TotalProcedures; i++)
		if(strcmp(Procedures[i].Label,String)==0)
			return i;

	return -1;
}
/******************************************************************************/
int IsExpProcedureName(char *String)
{
	int i;
	for(i = 0; i < TotalExternalProcs; i++)
		if(ExternalProcs[i].Label!=NULL&&strcmp(ExternalProcs[i].Label,String)==0)
			return i;

	return -1;
}
/******************************************************************************/
tsVARSTRUCT IsVarName(char *String)
{
	int i,j;
	tsVARSTRUCT vs = {-1,0};
	for(j = 0; j < 4; j++)
		for(i = 0; i < TotalVar[j]; i++)
            if(Var[j][i].Label!=NULL)
  			    if(strcmp(String,Var[j][i].Label)==0) {
                    if(ScriptNumber==0&&j==vLOCAL)
                        j = vGLOBAL;
				    vs.Type = j;

				    vs.Index = i;
				    return vs;
			    } 
    for(i=0;i<4;i++)
        if(strcmp(VarNames[i],String)==0) {
            vs.Type = i;
            return vs;
        }
    if(strcmp("paramTotal",String)==0) {
        vs.Type = vPARAM;
        return vs;
    }

	return vs;
}
/******************************************************************************/
int IsStringInVocab(char *String)
{
	int i;
/*#ifndef SCI1MODE  */
	for(i = 0; i < TotalVoc0Words; i++) {
		if(strcmp(Voc000[i].String,String)==0)
			return Voc000[i].Group;
    }
/*#endif  */
	return -1;
}
/******************************************************************************/
int GetPropertyValue(char *String, int Class, int Property, BOOL INSTANCE)
{
    int Value, Index;
    tsVARSTRUCT VarStruct;

    if(IsStringNum(String)) return StrToInt(TempString);

    ChgOffProp[TotalChgOffProp  ].Class    = Class;
    ChgOffProp[TotalChgOffProp  ].Property = Property;
    ChgOffProp[TotalChgOffProp  ].INSTANCE = INSTANCE;

    if(String[0]=='@') {
    /* Get variable address */
        GetNextWord(&InBuf);
        if((VarStruct=IsVarName(TempString)).Type!=vLOCAL) {
            ShowMessage(errLOCALVAREXP,NULL);
            return FALSE;
        }
        GetArraySize(&VarStruct.Index);

        ChgOffProp[TotalChgOffProp++].VAR = TRUE;
        return (VarStruct.Index<<1);
    } else if(String[0]=='"'||(Index=IsStringName(String))!=-1) {
        if(String[0]=='"') {
            if(!DoString()) return FALSE;
            Value = AddString(TempString);
        } else {
            Value = Strings[Index].Offset;
            if(*InBuf=='[') {
                InBuf++;
                GetNextWord(&InBuf);
                if(!IsStringNum(TempString)) {
                    ShowMessage(errINTEXP,NULL);
                    return -1;
                }
                Value+=StrToInt(TempString);
                if(*InBuf!=']')  {
                    ShowMessage(errARRAYENDEXP,NULL);
                    return FALSE;
                }
                InBuf++;
            }
        }
        ChgOffProp[TotalChgOffProp++].STRING = TRUE;
        return Value;
    } else if(String[0]=='\'') {
        if((Value=CompileSaid())==-1) {
            ShowMessage(errINVSAID,NULL);
            return -1;
        }
        ChgOffProp[TotalChgOffProp++].SAID   = TRUE;
        return Value;
    }
    return -1;
}
/******************************************************************************/
BOOL SkipPropertyValue()
{
    if(IsStringNum(TempString)||IsStringName(TempString)!=-1) return TRUE;
    if(TempString[0]=='@') {
    /* Get variable address */
        GetNextWord(&InBuf);
        return TRUE;
    } else if(TempString[0]=='"') {
        InBuf++;

    while(*InBuf!='\0') {
        if(*InBuf == '"' && *(InBuf-1) != '\\') {
        	if(*(InBuf+1)=='+') {
            	InBuf+=2;
            	while(*InBuf!='\0'&&
                	(*InBuf==' '||*InBuf=='\t'||*InBuf=='\r'||*InBuf=='\n')) InBuf++;
                if(*InBuf!='"') {
                  	/*ShowMessage(smERROR,"");*/
                    return FALSE;
                }
           		InBuf++;
            } else break;
        } else InBuf++;
    }
    if(*InBuf=='\0') return FALSE;

        InBuf++;
        return (*(InBuf-1)=='\"');
    } else if(TempString[0]=='\'') {
        InBuf++;
        while(*InBuf!='\''&&*InBuf!='\0') InBuf++;
        InBuf++;
        return (*(InBuf-1)=='\'');
    }
    return FALSE;
}
/******************************************************************************/
int GetPropChange(int Class, int Property, BOOL INSTANCE)
{
    int i;
    for(i=0;i<TotalChgOffProp;i++)
        if(ChgOffProp[i].Class == Class&&
            ChgOffProp[i].Property == Property&&
            ChgOffProp[i].INSTANCE == INSTANCE)
                return i;
    return -1;
}            
/******************************************************************************/
int IsObjectPropPtr(char *String)
{
	int i;
	for(i = 0; i < TOTAL_OBJPROPPTR; i++) {
		if(strcmp(ObjectPropPtr[i].String,String)==0)
			return i;
    }
	return -1;
}
/******************************************************************************/

/***************************************************************************
 *  Copyright (C) 1999-2001 Brian Provinciano, http://www.bripro.com
 ***************************************************************************/
