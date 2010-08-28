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
 * SCI Script Compiler
 * Created: 	March 14th, 2001 (Brian Provinciano)
 * Modified: 	June 6th, 2002 (Brian Provinciano)
 ******************************************************************************
 * If the indents look funny make sure your tabstop is set to 4.
 ******************************************************************************/
#include "scc.h"
/******************************************************************************/
#ifdef SCC_SCISTUDIO_WIN32
#pragma hdrstop
#pragma package(smart_init)
#endif
/******************************************************************************/
tsVERSION VERSION  = {1,4,0};
tsVERSION oVERSION = {1,0,0}; /* SCO version - no point in changing this unless the format changes */

BOOL
	USE_DEFINES, IN_HEADER, IN_ASM_MODE;

#ifdef SCC_MSDOS
char far
#else
char
#endif
	*InBuf;

char
	*OldBuf, *InBufStart, *ScriptPtr, ScriptName[256], IncludeFileName[128],
	TempString[2048],
	*StringInPtr,*LocalInPtr,*PublicInPtr, *SynonymInPtr,
	**ClassInPtr,**InstanceInPtr,**ProcedureInPtr, **SelectorNames,
	*StringSegment, **ProtPubLabels,
    **KernelNames,*KernelNamesBuf,
    TempString2[1024];

#ifdef SCC_MSDOS
BYTE far
#else   
BYTE
#endif
	*OutBuf, *CodeBuf, *SaidSegment;

BYTE
	SynonymsSegment[256];

int
	ScriptNumber, CurrentClass, CurrentInstance, TotalPubProcs, TotalPubInstances,
	 *Vocab996, FirstSameScript, TotalChgOffProp, TotalChgOffString,
	 OldLine, TotalSynonyms, TotalPubClasses, TotalProtoPubs,TotalKernels;
WORD
	TotalDefines,TotalIncludes,TotalStrings,TotalSaid, TotalPublics,TotalRelocation,
	TotalVar[4],TotalLocalClasses,TotalInstances,TotalProcedures,
	LineNumber, Offset, CurrentDefine, TotalVoc0Words, CodeOffset,
	TotalSelectorNames, TotalGlobalClasses, TotalChgOffCode,  OldGlobalClasses,
	Relocation[512],StringSegLen, CodeBufOffset, StringsOffset,
	TotalExternalProcs, SaidSegLen, SaidOffset, MaxSelectorNames;
long
	SourceFileLen;
FILE
	*fHandle;

int ObjScriptNumber,ObjTotalPublic,ObjTotalClasses,ObjTotalLocal,
	 ObjPublicOffset,ObjClassOffset,ObjLocalOffset,vMajor,vMinor,vBuild,
	  CurrentExpProc, ResPackage, TotalLabels;

BOOL PRELOAD_TEXT;

tsDEFINE *Defines;   
tsSTRING *Strings;
tsPUBLIC *Publics;
tsSAID *Said;
tsVAR *Var[4];
tsCLASS *sClasses, *Instances;
tsPROCEDURE *Procedures;
tsPUBPROC *ExternalProcs;
tsVOC000 *Voc000;
tsSELFINFO SelfInfo;
tsCHANGEOFFSET *ChgOffCode, *ChgOffString;
tsPROPCHANGEOFFSET *ChgOffProp;

int LoopStackCount;
tsLOOPSTACK LoopStack[MAX_LOOP_STACK_SIZE];
                                    
tsASMLABEL ASMLabels[MAX_LABELS];

/******************************************************************************
 * Send the file name of the source script in the 'FileName' param,
 * also 'Directory' should be set, or reset.
 ******************************************************************************/
BOOL CompileScript(char *FileName, int Package)
{                              
    ResPackage				= Package;

	/* Reset everything */
	ScriptNumber 			= -1;

    Procedures				= NULL;
    SaidSegment				= NULL;

	TotalDefines 			= 0;
	TotalIncludes			= 0;
	TotalStrings			= 0;
	TotalSaid 				= 0;
	TotalPublics			= 0;
	TotalRelocation 		= 0;
	TotalLocalClasses 		= 0;
	TotalInstances			= 0;
	TotalProcedures			= 0;
	TotalChgOffCode	 		= 0;
    TotalChgOffProp     	= 0;
    TotalChgOffString   	= 0;
    ChgOffString			= NULL;
    TotalExternalProcs      = 0;
    LoopStackCount			= 0;
    TotalPubProcs			= 0;
    TotalPubInstances 		= 0;
    TotalPubClasses         = 0;
    
    TotalProtoPubs          = 0;
    ProtPubLabels           = NULL;

    PRELOAD_TEXT			= FALSE;

    Instances = NULL;
    sClasses = NULL;

	memset(TotalVar,0,sizeof(TotalVar));
	 Var[vLOCAL]				= NULL;
    Var[vGLOBAL]  			= NULL;
    Var[vPARAM]				= NULL;
    Var[vTEMP] 				= NULL;

	TotalVoc0Words			= 0;
    Voc000                  = NULL;
    Vocab996                = NULL;
	TotalSelectorNames 	= 0;

	StringSegLen			= 0;
    SaidSegLen              = 0;
	CodeBufOffset			= 0;
	TotalGlobalClasses	    = 0; /* will get from v996 */

	USE_DEFINES				= FALSE;
	IN_HEADER				= FALSE;

	InBuf 					= NULL;
	OutBuf 					= NULL;
   ScriptPtr				= NULL;

	StringInPtr 			= NULL;
	LocalInPtr 				= NULL;
	PublicInPtr 			= NULL;
	ClassInPtr 				= NULL;
	InstanceInPtr 			= NULL;
	ProcedureInPtr 	    	= NULL;

    Strings 				= NULL;
	 Said 					= NULL;
	Defines 				= NULL;
    Publics 				= NULL;
	TotalDefines 			= 0;
	TotalStrings 			= 0;
	TotalSaid 				= 0;
    TotalPublics 			= 0;
	ExternalProcs 			= NULL;
	TotalExternalProcs 		= 0;
	ClassInPtr 				= NULL;
	InstanceInPtr 			= NULL;
	TotalLocalClasses 		= 0;
	InstanceInPtr 			= 0;
	TotalInstances 			= 0;
	ProcedureInPtr  		= NULL;
	TotalProcedures 		= 0;

	Voc000 					= NULL;
	TotalVoc0Words 			= 0;

    Vocab996 				= NULL;

	SelectorNames 			= NULL;
	TotalSelectorNames 		= 0;
	StringSegLen 			= 0;
	CodeBufOffset 			= 0;
	StringSegment 			= NULL;
	CodeBuf 				= NULL;
                                   
    KernelNames				= NULL;
    KernelNamesBuf			= NULL;
    TotalKernels			= 0;

	TotalStrings 			= 0;

	sClasses 				= NULL;
	TotalLocalClasses 		= 0;

	TotalChgOffCode 		= 0;
    ChgOffCode				= NULL;

    ChgOffProp 				= NULL;
    CurrentExpProc 			= 0;

    SynonymInPtr			= NULL;
    TotalSynonyms			= 0;

    TotalLabels             = 0;

    IN_ASM_MODE             = FALSE;


	/* Save the file name*/
	strcpy(ScriptName,FileName);

	/* Open the source */
	if((fHandle=fopen(ScriptName,"rb"))==NULL) {
		ShowMessage(smERROR,"Unable to open file: %s for reading!",ScriptName);
		return FALSE;
	}
	fseek(fHandle,0,SEEK_END);
	SourceFileLen = ftell(fHandle);
#ifdef SCC_MSDOS
	if((InBuf=(char *)farmalloc((SourceFileLen+1)))==NULL) {
#else
	if((InBuf=(char*)malloc((SourceFileLen+1)))==NULL) {
#endif
		ShowMessage(smERROR,"Unable to allocate buffer for source file!");
		return FALSE;
	}
	fseek(fHandle,0,SEEK_SET);
	fread(InBuf,(size_t)SourceFileLen,1,fHandle);
	InBuf[(size_t)SourceFileLen]='\0';
	fclose(fHandle);
	InBufStart = InBuf; /* Because I will be incrementing it, so I can free it */

	/* Allocate the output buffer */

#ifdef SCC_MSDOS
	if((OutBuf=(BYTE *)farcalloc(MAX_SCRIPT_SIZE,1))==NULL) {
#else
	if((OutBuf=(BYTE*)calloc(MAX_SCRIPT_SIZE,1))==NULL) {
#endif
		ShowMessage(smERROR,"Unable to allocate output buffer!");
		return FALSE;
	}
	 #ifndef SCC_SCISTUDIO_WIN32
	ShowMessage(smNONE,"Precompile one...");
	 #endif
	 if(!PrecompileOne()) return FALSE;
	 #ifndef SCC_SCISTUDIO_WIN32
	ShowMessage(smAPPEND,"done!");
	 #endif
                                 
	 #ifndef SCC_SCISTUDIO_WIN32
	ShowMessage(smNONE,"Precompile two...");  
    #endif
    if(!PrecompileTwo()) return FALSE;  
    #ifndef SCC_SCISTUDIO_WIN32
	ShowMessage(smAPPEND,"done!");
    #endif

    #ifndef SCC_SCISTUDIO_WIN32
	ShowMessage(smNONE,"Precompile three...");
    #endif
    if(!PrecompileThree()) return FALSE;  
    #ifndef SCC_SCISTUDIO_WIN32
	ShowMessage(smAPPEND,"done!");
    #endif
                                     
    #ifndef SCC_SCISTUDIO_WIN32
	ShowMessage(smNONE,"Finalizing...");
    #endif
    if(!FinalCompile()) return FALSE;
    #ifndef SCC_SCISTUDIO_WIN32
	ShowMessage(smAPPEND,"done!");
    #endif

	/* Open the output for writing */
	if(dirlist_ressave(idSCRIPT, ScriptNumber, OutBuf, Offset)==NULL) {
		ShowMessage(smERROR,"Unable to save file: script.%03d",ScriptNumber);
		return FALSE;
	}

	WriteObjectFile();
	WriteVocab996();
	WriteVocab997();

	return TRUE;
}
/******************************************************************************
 * Get the offsets and info on everything so that the memory cal be allocated
 ******************************************************************************/
BOOL PrecompileOne()
{
	int Segment, StrLen;
	char IncludeFileName[128];

	LineNumber 			= 1;

	/* Not really necessary here, but just to be clean */
	InBuf 				= InBufStart;

	/* Start the precompile */
	GetNextWord(&InBuf);
	while(TempString[0]!='\0') {
		/* syntax: "(" "segment name"... */
		if(TempString[0]!='(') {
			ShowMessage(errINBRACEXP,NULL);
			return FALSE;
		}
		/* Get the segment name */
		if((Segment=GetSegmentIndex(GetNextWord(&InBuf)))==-1) {
			ShowMessage(errSEGNAMEEXP,NULL);
			return FALSE;
		}
		/* Parse the segment */
		switch(Segment) {  
			case sgPUBLICS:
                while(GetNextWord(&InBuf)[0]!=')'&&TempString[0]!='\0')
                    TotalProtoPubs++;
                if(TempString[0]=='\0') {
			        ShowMessage(errOUTBRACEXP,NULL);
			        return FALSE;
                }
				break;
			case sgINSTANCE:
				if(!SkipSegment()) return FALSE;
				TotalInstances++;
				break;
			case sgSTRINGS:
				/* Check to see if there's already been a string declared */
				if(StringInPtr!=NULL) {
					ShowMessage(errSTRINGALREADYDEF,NULL);
					return FALSE;
				}
				StringInPtr = InBuf;
				if(!CountStringSegment()) return FALSE;
				break;
            case sgPRELOAD_TEXT:
				if(!SkipSegment()) return FALSE;
                break;
            case sgSYNONYM:
            	SynonymInPtr = InBuf;
				if(!SkipSegment()) return FALSE;
                break;
			case sgCLASS:
				if(!SkipSegment()) return FALSE;
				TotalLocalClasses++;
				break;
			case sgPUBLIC:
				/* Check to see if there's already been a public declared */
				if(PublicInPtr!=NULL) {
					ShowMessage(errPUBLICALREADYDEF,NULL);
					return FALSE;
				}
				PublicInPtr = InBuf;
				break;
			case sgLOCAL:
				/* Check to see if there's already been a local declared */
				if(LocalInPtr!=NULL) {
					ShowMessage(errLOCALALREADYDEF,NULL);
					return FALSE;
				}
				LocalInPtr = InBuf;
				if(!SkipSegment()) return FALSE;
				break;
			case sgSCRIPT:
   		/* Check to see if the script number has already been declared */
				if(ScriptPtr!=NULL) {
					ShowMessage(errSCRNUMALREADYDEF,NULL);
					return FALSE;
				}
         	ScriptPtr = InBuf;
            GetNextWord(&InBuf);
            if(GetNextWord(&InBuf)[0]!=')') {
            	ShowMessage(errOUTBRACEXP,NULL);
               return FALSE;
            }
				break;
			case sgDEFINE:
				GetNextWord(&InBuf);
				GetNextWord(&InBuf);
				if(GetNextWord(&InBuf)[0]!=')') {
					ShowMessage(errOUTBRACEXP,NULL);
					return FALSE;
				}
				TotalDefines++;
				break;
			case sgINCLUDE:
				/* get the include file name */
				if(GetNextWord(&InBuf)[0]!='"') {
					ShowMessage(errQUOTEEXP,NULL);
					return FALSE;
				}
				StrLen = 0;
				while(*(InBuf+StrLen) != '\0') {
					if(*(InBuf+StrLen) == '"' && *(InBuf+StrLen-1) != '\\') break;
					StrLen++;
				}
				memcpy(TempString,InBuf,StrLen+1);
				TempString[StrLen]='\0';
				/*sprintf(IncludeFileName,"%s%s",Directory,TempString);*/
                strcpy(IncludeFileName,TempString);
				InBuf += StrLen+1;

				/* check syntax */
				if(GetNextWord(&InBuf)[0]!=')') {
					ShowMessage(errOUTBRACEXP,NULL);
					return FALSE;
				}
				if(!DoInclude(IncludeFileName,FALSE)) return FALSE;
				break;
			case sgUSE:
				/* get the include file name */
				if(GetNextWord(&InBuf)[0]!='"') {
					ShowMessage(errQUOTEEXP,NULL);
					return FALSE;
				}
				StrLen = 0;
				while(*(InBuf+StrLen) != '\0') {
					if(*(InBuf+StrLen) == '"' && *(InBuf+StrLen-1) != '\\') break;
					StrLen++;
				}
				memcpy(TempString,InBuf,StrLen+1);
				TempString[StrLen]='\0';
				sprintf(IncludeFileName,"%s.sco",TempString);
				InBuf += StrLen+1;

				/* check syntax */
				if(GetNextWord(&InBuf)[0]!=')') {
					ShowMessage(errOUTBRACEXP,NULL);
					return FALSE;
				}
				if(!LoadObjectFile(IncludeFileName,FALSE)) return FALSE;
				break;
			case sgPROCEDURE:
				TotalProcedures++;
				if(!SkipSegment()) return FALSE;
				break;
			default:; /* No need to give an error for an invalid segment,
							 it's already been caught */
		}
		GetNextWord(&InBuf);
	}


/*#ifndef SCI1MODE
	if(!LoadVocab000()) return FALSE;
#else     */
	if(!LoadVocab900()) return FALSE; /*
#endif                    */
	if(!LoadVocab997()) return FALSE;
	if(!LoadVocab999()) return FALSE;

	return TRUE;
}
/******************************************************************************
 * Get the defines, process the includes, and get the inbuf offsets + total #
 * of the other segments
 ******************************************************************************/
BOOL PrecompileTwo()
{
	int Segment,StrLen,i,Procedure=0,TotalValueBrackets,ArraySize,
        ProtPubCount=0,sz;
	char IncludeFileName[128];
	CurrentClass=0;
	CurrentInstance=0;

	CurrentDefine		= 0;
	LineNumber 			= 1;

	/* Not really necessary here, but just to be clean */
	InBuf 				= InBufStart;

	/* Pre allocate some stuff to save time */
	if(TotalDefines)
		if((Defines = (tsDEFINE*) calloc(sizeof(tsDEFINE),TotalDefines))==NULL) {
			ShowMessage(smERROR,"Unable to allocate buffer for defines!");
			return FALSE;
		}
	if(TotalProcedures) {
		if((ProcedureInPtr = (char**) calloc(sizeof(char*),TotalProcedures))==NULL) {
			ShowMessage(smERROR,"Unable to allocate buffer for class pointers!");
			return FALSE;
		}
		if((Procedures = (tsPROCEDURE*) calloc(sizeof(tsPROCEDURE),TotalProcedures))==NULL) {
			ShowMessage(smERROR,"Unable to allocate buffer for TotalProcedures!");
			return FALSE;
		}
	}
    if(TotalExternalProcs)
        if((ExternalProcs = (tsPUBPROC*) calloc(sizeof(tsPUBPROC),TotalExternalProcs))==NULL) {
            ShowMessage(smERROR,"Unable to allocate buffer for ExternalProcs!");
            return FALSE;
        }
	if(TotalLocalClasses) {
		if((ClassInPtr = (char**) malloc(sizeof(char*)*TotalLocalClasses))==NULL) {
			ShowMessage(smERROR,"Unable to allocate buffer for class pointers!");
			return FALSE;
		}
		if((sClasses = (tsCLASS*) calloc(sizeof(tsCLASS),TotalLocalClasses))==NULL) {
			ShowMessage(smERROR,"Unable to allocate buffer for classes!");
			return FALSE;
		}
		for(i=0;i<TotalLocalClasses;i++)
			sClasses[i].EXPORTED = TRUE;
	}
	if(TotalInstances) {
		if((InstanceInPtr = (char**) malloc(sizeof(char*)*TotalInstances))==NULL) {
			ShowMessage(smERROR,"Unable to allocate buffer for Instance pointers!");
			return FALSE;
		}
		if((Instances = (tsCLASS*) calloc(sizeof(tsCLASS),TotalInstances))==NULL) {
			ShowMessage(smERROR,"Unable to allocate buffer for Instancees!");
			return FALSE;
		}
	}

	if((StringSegment = (char*) calloc(MAX_SEGMENT_SIZE,1))==NULL) {
			ShowMessage(smERROR,"Unable to allocate buffer for string segment!");
			return FALSE;
	}
	if((SaidSegment = (BYTE*) calloc(MAX_SEGMENT_SIZE,1))==NULL) {
			ShowMessage(smERROR,"Unable to allocate buffer for said segment!");
			return FALSE;
	}
	if(TotalStrings)
        if((Strings = (tsSTRING*) calloc(sizeof(tsSTRING),TotalStrings))==NULL) {
			ShowMessage(smERROR,"Unable to allocate buffer for Strings!");
			return FALSE;
		 }
#ifdef SCC_MSDOS
	if((CodeBuf = (BYTE *) farmalloc(MAX_SEGMENT_SIZE))==NULL) {
#else
	if((CodeBuf = (BYTE*) malloc(MAX_SEGMENT_SIZE))==NULL) {
#endif
			ShowMessage(smERROR,"Unable to allocate buffer for code segment!");
			return FALSE;
	}
	if((ChgOffCode = (tsCHANGEOFFSET*) calloc(sizeof(tsCHANGEOFFSET),MAX_CHANGE_OFFSETS))==NULL) {
			ShowMessage(smERROR,"Unable to allocate buffer for ChgOffCode!");
			return FALSE;
	}
	if((ChgOffString = (tsCHANGEOFFSET*) calloc(sizeof(tsCHANGEOFFSET),MAX_CHANGE_OFFSETS))==NULL) {
			ShowMessage(smERROR,"Unable to allocate buffer for ChgOffString (%d bytes)!", MAX_CHANGE_OFFSETS*sizeof(tsCHANGEOFFSET));
			return FALSE;
	}
	if((ChgOffProp = (tsPROPCHANGEOFFSET*) calloc(sizeof(tsPROPCHANGEOFFSET),MAX_CHANGE_OFFSETS))==NULL) {
			ShowMessage(smERROR,"Unable to allocate buffer for ChgOffProp!");
			return FALSE;
	}

	if(TotalProtoPubs)
	    if((ProtPubLabels = (char**) calloc(TotalProtoPubs+1,sizeof(char*)))==NULL) {
			ShowMessage(smERROR,"Unable to allocate buffer for ProtPubLabels!");
			return FALSE;
	    }

	/* Start the precompile */
	GetNextWord(&InBuf);
	while(TempString[0]!='\0') {
		/* syntax: "(" "segment name"... */
		if(TempString[0]!='(') {
			ShowMessage(errINBRACEXP,NULL);
			return FALSE;
		}
		/* Get the segment name */
		if((Segment=GetSegmentIndex(GetNextWord(&InBuf)))==-1) {
			ShowMessage(errSEGNAMEEXP,NULL);
			return FALSE;
		}
		/* Parse the segment */

		switch(Segment) { 
			case sgPUBLICS:
                while(GetNextWord(&InBuf)[0]!=')') {
                	sz=strlen(TempString)+1; // OB1 bug fixed 2004/09/29
                    ProtPubLabels[ProtPubCount] = (char*) malloc(sz);
                    memcpy(ProtPubLabels[ProtPubCount],TempString,sz);
                    ProtPubCount++;
                }
				break;
			case sgINSTANCE:
         	GetNextWord(&InBuf);
        		if(strcmp(TempString,"public")==0) {
                	Instances[CurrentInstance].PUBLIC = TRUE;
                  TotalPubInstances++;
                	GetNextWord(&InBuf);
           	}
				if(!IsStringLabel(TempString)) {
					ShowMessage(errCLASSNAMEEXP,NULL);
					return FALSE;
				}
				Instances[CurrentInstance].Name = (char*) malloc(strlen(TempString)+1);
				strcpy(Instances[CurrentInstance].Name,TempString);

				Instances[CurrentInstance].NamePtr = AddString(TempString);

				InstanceInPtr[CurrentInstance++]=InBuf;
				if(!SkipSegment()) return FALSE;
				break;
            case sgPRELOAD_TEXT:
				if(strcmp(GetNextWord(&InBuf),"text")!=0) {
					ShowMessage(errTEXTEXP,NULL);
					return FALSE;
				}
				if(strcmp(GetNextWord(&InBuf),")")!=0) {
					ShowMessage(errOUTBRACEXP,NULL);
					return FALSE;
				}
                PRELOAD_TEXT = TRUE;
                break;
			case sgSTRINGS:
				if(!SkipSegment()) return FALSE;
				break;
			case sgSYNONYM:
				if(!SkipSegment()) return FALSE;
				break;
			case sgCLASS:
				/* class name */   
         	    GetNextWord(&InBuf);
                if(strcmp(TempString,"public")==0) {
                    sClasses[CurrentClass].PUBLIC = TRUE;
                    TotalPubClasses++;
                    GetNextWord(&InBuf);
                }
				if(!IsStringLabel(TempString)) {
					ShowMessage(errCLASSNAMEEXP,NULL);
					return FALSE;
				}
				sClasses[CurrentClass].Name = (char*) malloc(strlen(TempString)+1);
				strcpy(sClasses[CurrentClass].Name,TempString);

				sClasses[CurrentClass].NamePtr = AddString(TempString);
				sClasses[CurrentClass].Species = -1;

				sClasses[CurrentClass].EXPORTED = FALSE;
				ClassInPtr[CurrentClass++]=InBuf;
				if(!SkipSegment()) return FALSE;
				break;
			case sgPUBLIC:
				break;
			case sgLOCAL:
				GetNextWord(&InBuf);
				while(TempString[0] != ')' &&TempString[0] != '\0') {
                    ArraySize = 0;
                    if(GetArraySize(&ArraySize)==-1) return FALSE;
					if(TempString[0]=='=') {
                        TotalValueBrackets = 0;
                        GetNextWord(&InBuf);
                        do {
                            if(TempString[0]=='(') TotalValueBrackets++;
                            else if(TempString[0]==')') TotalValueBrackets--;
                            if(TotalValueBrackets) GetNextWord(&InBuf);
                        } while(TotalValueBrackets&&TempString[0]!='\0');
                    } else {
                        if(ArraySize)
                            TotalVar[vLOCAL]+=ArraySize;
                        else
                            TotalVar[vLOCAL]++;
                    }    
                        GetNextWord(&InBuf);
                }
				break;
			case sgSCRIPT:
				GetNextWord(&InBuf);
            GetNextWord(&InBuf);
				break;
			case sgDEFINE:
				/* Get the label */
				Defines[CurrentDefine].Label = (char*)malloc(strlen(GetNextWord(&InBuf))+1);
				strcpy(Defines[CurrentDefine].Label, TempString);
				Defines[CurrentDefine].Definition = (char*)malloc(strlen(GetNextWord(&InBuf))+1);
				strcpy(Defines[CurrentDefine].Definition, TempString);
				CurrentDefine++;
				/* Segment closing bracket */
				if(GetNextWord(&InBuf)[0]!=')') {
					ShowMessage(errOUTBRACEXP,NULL);
					return FALSE;
				}
				break;
			case sgINCLUDE:
				/* get the include file name */
				if(GetNextWord(&InBuf)[0]!='"') {
					ShowMessage(errQUOTEEXP,NULL);
					return FALSE;
				}
				StrLen = 0;
				while(*(InBuf+StrLen) != '\0') {
					if(*(InBuf+StrLen) == '"' && *(InBuf+StrLen-1) != '\\') break;
					StrLen++;
				}
				memcpy(TempString,InBuf,StrLen+1);
				TempString[StrLen]='\0';
                /*sprintf(IncludeFileName,"%s%s",Directory,TempString); */
                strcpy(IncludeFileName,TempString);
				InBuf += StrLen+1;

				/* check syntax */
				if(GetNextWord(&InBuf)[0]!=')') {
					ShowMessage(errOUTBRACEXP,NULL);
					return FALSE;
				}
				if(!DoInclude(IncludeFileName,TRUE)) return FALSE;
				break;
			case sgUSE:
				/* get the include file name */
				if(GetNextWord(&InBuf)[0]!='"') {
					ShowMessage(errQUOTEEXP,NULL);
					return FALSE;
				}
				StrLen = 0;
				while(*(InBuf+StrLen) != '\0') {
					if(*(InBuf+StrLen) == '"' && *(InBuf+StrLen-1) != '\\') break;
					StrLen++;
				}
				memcpy(TempString,InBuf,StrLen+1);
				TempString[StrLen]='\0';
				sprintf(IncludeFileName,"%s.sco",TempString);
				InBuf += StrLen+1;

				/* check syntax */
				if(GetNextWord(&InBuf)[0]!=')') {
					ShowMessage(errOUTBRACEXP,NULL);
					return FALSE;
				}
				if(!LoadObjectFile(IncludeFileName,TRUE)) return FALSE;
				break;
			case sgPROCEDURE:
                GetNextWord(&InBuf);
                if(strcmp(TempString,"public")==0) {
                	Procedures[Procedure].PUBLIC = TRUE;
                    TotalPubProcs++;
                	GetNextWord(&InBuf);
                }
				if(TempString[0]!='(') {
					ShowMessage(errINBRACEXP,NULL);
					return FALSE;
				}
				if(!IsStringLabel(GetNextWord(&InBuf))) {
					ShowMessage(errPROCNAMEEXP,NULL);
					return FALSE;
				}

				Procedures[Procedure].Label = (char*) malloc(strlen(TempString)+1);
				strcpy(Procedures[Procedure].Label, TempString);

				ProcedureInPtr[Procedure]=InBuf;

				if(!SkipSegment()) return FALSE;
				if(!SkipSegment()) return FALSE;
				Procedure++;
				break;
			default:; /* No need to give an error for an invalid segment,
							 it's already been caught */
		}
		GetNextWord(&InBuf);
	}

	/* If there are any defines, GetNextWord() will now check them */
	if(TotalDefines) USE_DEFINES = TRUE;

	return TRUE;
}
/******************************************************************************/
BOOL PrecompileThree()
{
	int CurrentLocal, Property, TopProperty, SuperProperty, StrLen, ArraySize,
		Class, Instance, Procedure = 0, String, TotalBrackets=0, TotalValueBrackets,
        Value, Index, i, Synonym1, Synonym2,
        SuperIndex;
	WORD OldLine;
	char *OldPtr;
    BYTE *SynPtr;
    tsSELFINFO tempSI;

	/* Get the script number */
   if(ScriptPtr!=NULL) {
      GetNextWord(&ScriptPtr);
   	if(!IsStringNum(TempString)) {
   		ShowMessage(errINTEXP,NULL);
      	return FALSE;
   	}
   	ScriptNumber = StrToInt(TempString);
      if(ScriptNumber<0 || ScriptNumber>999) {
   		ShowMessage(errBADSCRIPTNUM,NULL);
      	return FALSE;
   	}
   } else {
		ShowMessage(errSCRIPTNUMNOTSPEC,NULL);
		return FALSE;
   }           

	if(!LoadVocab996()) return FALSE; /* Will only happen if the header is bad */

	/* Allocate */
	if(TotalVar[vLOCAL])
		if((Var[vLOCAL] = (tsVAR*) calloc(sizeof(tsVAR),TotalVar[vLOCAL]))==NULL) {
			ShowMessage(smERROR,"Unable to allocate buffer for locals!");
			return FALSE;
		}

	/* Do the locals */
	if(TotalVar[vLOCAL]) {
		SetInBuf(LocalInPtr);
		CurrentLocal = 0;
		GetNextWord(&InBuf);
		while(TempString[0]!='\0'&&TempString[0]!=')') {
			if(!IsStringLabel(TempString)) {
				ShowMessage(errVARNAMEEXP,NULL);
				return FALSE;
			}
			if(IsLabelDefined(TempString)) {
				ShowMessage(errLABELAREADYDEF,NULL,TempString);
				return FALSE;
			}
			Var[vLOCAL][CurrentLocal].Label=(char*)malloc(strlen(TempString)+1);
			strcpy(Var[vLOCAL][CurrentLocal].Label,TempString);

            ArraySize = 0;
            GetArraySize(&ArraySize);
            if(ArraySize==-1) {
                ShowMessage(errARRAYSIZEZ,NULL,ArraySize);
                return FALSE;
            }
            GetNextWord(&InBuf);
            for(i=1;i<ArraySize;i++)
                Var[vLOCAL][CurrentLocal+i].Label=NULL;
            if(TempString[0]=='=') {
                TotalValueBrackets = TotalBrackets;
                Index = 0;
                GetNextWord(&InBuf);
                do {
                    if(TempString[0]=='(') {
                        TotalValueBrackets++;
                    } else if(TempString[0]==')') {
                        TotalValueBrackets--;
                    } else if(IsStringNum(TempString)) {
                        Var[vLOCAL][CurrentLocal+(Index++)].Value = StrToInt(TempString);
                    } else {
                        ShowMessage(errINTEXP,NULL,TempString);
                        return FALSE;
                    }
                    if(ArraySize&&ArraySize<Index) {
                        ShowMessage(errARRAYLTENTRIES,NULL,ArraySize,Index);
                        return FALSE;
                    }
                    GetNextWord(&InBuf);
                } while(TotalValueBrackets>TotalBrackets&&TempString[0]!='\0');
            } else if(TempString[0]!=')'&&!IsStringLabel(TempString)) {
                ShowMessage(errVARNAMEOROUTBRAC,NULL);
                return FALSE;
            }
            if(ArraySize)
                CurrentLocal+=ArraySize;
            else
                CurrentLocal++;
        }
		if(TempString[0]!=')') {
			ShowMessage(errOUTBRACEXP,NULL);
			return FALSE;
		}
	}

    if(StringInPtr) {
        SetInBuf(StringInPtr);
		String = 0;
        TotalBrackets = 1;
		GetNextWord(&InBuf);
		while(TempString[0]!='\0'&&TotalBrackets) {
            if(TempString[0]=='(') {
                if(++TotalBrackets) GetNextWord(&InBuf);
            } else if(TempString[0]==')') {
                if(--TotalBrackets) GetNextWord(&InBuf);
            } else {
                ArraySize = 0;
			    if(!IsStringLabel(TempString)) {
				    ShowMessage(errSTRNAMEEXP,NULL);
				    return FALSE;
			    }
			    if(IsLabelDefined(TempString)) {
				    ShowMessage(errLABELAREADYDEF,NULL,TempString);
				    return FALSE;
			    }
			    Strings[String].Label=(char*)malloc(strlen(TempString)+1);
			    strcpy(Strings[String].Label,TempString);
                GetNextWord(&InBuf);      
                StringSegLen = (StringSegLen+2)&0xFFFE;
                Strings[String].Offset = StringSegLen;
                if(TempString[0]=='[') {
                    InBuf--;
                    GetArraySize(&ArraySize);
                    if(ArraySize<1) {
                        ShowMessage(errARRAYSIZEZ,NULL,ArraySize);
                        return FALSE;
                    }
                    GetNextWord(&InBuf);
                    if(ArraySize) {
                        StringSegLen += ArraySize;
                    }
			    }
                Strings[String].String=StringSegment+Strings[String].Offset;
                if(TempString[0]=='=') {
                    TotalValueBrackets = TotalBrackets;
                    StrLen = 0;
                    GetNextWord(&InBuf);
                    do {
                        if(TempString[0]=='(') {
                            TotalValueBrackets++;
                        } else if(TempString[0]==')') {
                            TotalValueBrackets--;
                        } else if(TempString[0]=='"') {
                            if(!DoString()) return FALSE;
                            strcpy(StringSegment+Strings[String].Offset+StrLen,TempString);
                            StrLen += strlen(TempString);
                        } else if(IsStringNum(TempString)) {
                            Value = StrToInt(TempString);
                            StringSegment[Strings[String].Offset+StrLen  ] = Value&0xFF;
                            StrLen++;
                        } else {
				            ShowMessage(errQUOTEORINTEXP,NULL,TempString);
				            return FALSE;
                        }
                        if(ArraySize)
                            if(ArraySize<StrLen) {
                                ShowMessage(errARRAYLTSTR,NULL,ArraySize,Index);
                                return FALSE;
                            }
                        GetNextWord(&InBuf);
                    } while(TotalValueBrackets>TotalBrackets);
                    if(!ArraySize) StringSegment[Strings[String].Offset+(StrLen++)]='\0';
                    StringSegLen+=StrLen;
                }
			    String++;
            }
		}
		if(TempString[0]!=')') {
			ShowMessage(errOUTBRACEXP,NULL);
			return FALSE;
		}
	}

	for(Class=0;Class<TotalLocalClasses;Class++) {
		if(!sClasses[Class].EXPORTED) {
         sClasses[Class].Species = GetNextFreeClassIndex();
      }
   }           
	for(Class=0;Class<TotalLocalClasses;Class++) {
		if(!sClasses[Class].EXPORTED) {
			SetInBuf(ClassInPtr[Class]);
			/* check for super */
			if(strcmp(GetNextWord(&InBuf),"of")==0) {
				if((Value = GetClassIndex(GetNextWord(&InBuf)).Index)==-1) {
					ShowMessage(errSUPCLASSNAMEEXP,NULL);
					return FALSE;
				}
                sClasses[Class].Superclass = sClasses[Value].Species;
				if(sClasses[Class].Superclass==sClasses[Class].Species) {
					ShowMessage(errCLASSOFSAMECLASS,NULL);
					return FALSE;
				}
				GetNextWord(&InBuf);
			} else sClasses[Class].Superclass = -1;
            SelfInfo.Index = Class;
            SelfInfo.INSTANCE = FALSE;

			sClasses[Class].TotalProperties 	= 0;
			sClasses[Class].TotalMethods 		= 0;

			while(TempString[0]!=')') {
				if(TempString[0]!='(') {
					ShowMessage(errINOROUTBRACEXP,NULL);
					return FALSE;
				}
				GetNextWord(&InBuf);
				if(strcmp(TempString,"properties")==0) {
					OldPtr = InBuf;
					OldLine = LineNumber;
					if(sClasses[Class].Superclass!=-1)
						sClasses[Class].TotalProperties =
							sClasses[GetClassEntry(sClasses[Class].Superclass)].TotalProperties;

					while(GetNextWord(&InBuf)[0]!=')'&&TempString[0]!='\0') {
						if(!IsStringLabel(TempString)) {
							ShowMessage(errPROPNAMEEXP,NULL);
							return FALSE;
						}
                        if(sClasses[Class].Superclass==-1)
                        	sClasses[Class].TotalProperties++;
						else {
                        	Value = GetClassEntry(sClasses[Class].Superclass);
                        	if(Value==-1) {
								ShowMessage(errPROPNAMEEXP,NULL);
								return FALSE;
                            } else
                            	if(GetPropertyIndex(Value, TempString, FALSE)==-1)
									sClasses[Class].TotalProperties++;
                        }
								GetNextWord(&InBuf);
						if(!SkipPropertyValue()) {
							ShowMessage(errINTEXP,NULL);
							return FALSE;
						}
					}
					sClasses[Class].PropertyValues = (int*) malloc(sClasses[Class].TotalProperties*sizeof(int));
					sClasses[Class].PropertyNameIndexes = (int*) malloc(sClasses[Class].TotalProperties*sizeof(int));

					InBuf = OldPtr;
					LineNumber = OldLine;
					if(sClasses[Class].Superclass!=-1) {
						for(TopProperty=0;TopProperty<sClasses[GetClassEntry(sClasses[Class].Superclass)].TotalProperties;TopProperty++) {
							sClasses[Class].PropertyNameIndexes[TopProperty] =
								sClasses[GetClassEntry(sClasses[Class].Superclass)].PropertyNameIndexes[TopProperty];
							sClasses[Class].PropertyValues[TopProperty] =
								sClasses[GetClassEntry(sClasses[Class].Superclass)].PropertyValues[TopProperty];
						}
					} else TopProperty = 0;

					while(GetNextWord(&InBuf)[0]!=')'&&TempString[0]!='\0') {
						if(sClasses[Class].Superclass==-1||
						(SuperProperty=GetPropertyIndex(GetClassEntry(sClasses[Class].Superclass), TempString, FALSE))==-1) {
							if((Property=GetSelectorIndex(TempString, caCAN_ADD))==-1) {
								ShowMessage(errPROPNAMEEXP,NULL);
								return FALSE;
							} else {
								sClasses[Class].PropertyNameIndexes[TopProperty]=Property;
								sClasses[Class].PropertyValues[TopProperty] = GetPropertyValue(GetNextWord(&InBuf),Class,TopProperty,FALSE);
								TopProperty++;
							}
						} else {
							sClasses[Class].PropertyNameIndexes[SuperProperty] =
								sClasses[GetClassEntry(sClasses[Class].Superclass)].PropertyNameIndexes[SuperProperty];
							sClasses[Class].PropertyValues[SuperProperty] = GetPropertyValue(GetNextWord(&InBuf),Class,SuperProperty,FALSE);
						}
					}
				} else if(strcmp(TempString,"method")==0) {
					if(GetNextWord(&InBuf)[0]!='(') {
						ShowMessage(errINBRACEXP,NULL);
						return FALSE;
					}
					if(!IsStringLabel(GetNextWord(&InBuf))) {
						ShowMessage(errMETHODNAMEEXP,NULL);
						return FALSE;
					}
					sClasses[Class].MethodNameIndexes[sClasses[Class].TotalMethods] =
						GetSelectorIndex(TempString, caCAN_ADD);
                    DoFunctionArgs();
                    CodeBufOffset=(CodeBufOffset+2)&0xFFFE;
					sClasses[Class].MethodCodeOffsets[sClasses[Class].TotalMethods] = CodeBufOffset;
					if(!CompileCode(ccMETHOD,TRUE)) return FALSE;
                    sClasses[Class].TotalMethods++;
            		CodeBufOffset=(CodeBufOffset+2)&0xFFFE;
				} else {
					ShowMessage(errPROPORMETHEXP,NULL);
					return FALSE;
				}
				GetNextWord(&InBuf);
			}
		}
	}
	for(Instance=0;Instance<TotalInstances;Instance++) {
		SetInBuf(InstanceInPtr[Instance]);

		/* check for super */
		if(strcmp(GetNextWord(&InBuf),"of")!=0) {
			ShowMessage(errSUPCLASSNAMEEXP,NULL);
			return FALSE;
		}
                   
		if(sClasses==NULL) {
			ShowMessage(errSUPCLASSNAMEEXP,NULL);
			return FALSE;
		}
        GetNextWord(&InBuf);
        tempSI = GetClassIndex(TempString);
		if(tempSI.Index==-1) {
			ShowMessage(errSUPCLASSNAMEEXP,NULL);
			return FALSE;
		}
        Instances[Instance].Superclass = sClasses[tempSI.Index].Species;
		Instances[Instance].Species = Instances[Instance].Superclass;

        SelfInfo.Index = Instance;
        SelfInfo.INSTANCE = TRUE;

		Instances[Instance].TotalProperties 	= 0;
		Instances[Instance].TotalMethods 		= 0;

		GetNextWord(&InBuf);
		while(TempString[0]!=')') {
			if(TempString[0]!='(') {
				ShowMessage(errINOROUTBRACEXP,NULL);
				return FALSE;
			}
			GetNextWord(&InBuf);
			if(strcmp(TempString,"properties")==0) {
				OldPtr = InBuf;
				OldLine = LineNumber;

                SuperIndex = GetClassEntry(Instances[Instance].Superclass);
				while(GetNextWord(&InBuf)[0]!=')'&&TempString[0]!='\0') {
					if(!IsStringLabel(TempString)) {
						ShowMessage(errPROPNAMEEXP,NULL);
						return FALSE;
					}
					if(GetPropertyIndex(SuperIndex, TempString, FALSE)==-1) {
						ShowMessage(errPROPNOTMEMBER,NULL,TempString,
                            sClasses[SuperIndex].Name);
						return FALSE;
					}
                    GetNextWord(&InBuf);
						  if(!SkipPropertyValue()) {
							ShowMessage(errINTEXP,NULL);
							return FALSE;
						  }
				}

                Instances[Instance].TotalProperties = sClasses[SuperIndex].TotalProperties;
				Instances[Instance].PropertyNameIndexes = (int*) malloc(Instances[Instance].TotalProperties*sizeof(int));
				Instances[Instance].PropertyValues = (int*) malloc(Instances[Instance].TotalProperties*sizeof(int));

				InBuf = OldPtr;
				LineNumber = OldLine;
                for(SuperProperty = 0; SuperProperty<Instances[Instance].TotalProperties;SuperProperty++) {
				    Instances[Instance].PropertyValues[SuperProperty] =
                        sClasses[SuperIndex].PropertyValues[SuperProperty];
				    Instances[Instance].PropertyNameIndexes[SuperProperty] =
                        sClasses[SuperIndex].PropertyNameIndexes[SuperProperty];
                }
				while(GetNextWord(&InBuf)[0]!=')'&&TempString[0]!='\0') {
                    if((SuperProperty = GetSelectorIndex(TempString, caCAN_NOT_ADD))==-1){
						ShowMessage(errADDINGSELECTOR,NULL,TempString);
						return FALSE;
                    }
                    if((SuperProperty=GetPropertyInClass(SuperIndex,SuperProperty))==-1){
						ShowMessage(errPROPINDEX,NULL,TempString);
						return FALSE;
                    }
                    Instances[Instance].PropertyValues[SuperProperty] = GetPropertyValue(GetNextWord(&InBuf),Instance,SuperProperty,TRUE);
				}
			} else if(strcmp(TempString,"method")==0) {
				if(GetNextWord(&InBuf)[0]!='(') {
					ShowMessage(errINBRACEXP,NULL);
					return FALSE;
				}
				if(!IsStringLabel(GetNextWord(&InBuf))) {
					ShowMessage(errMETHODNAMEEXP,NULL);
					return FALSE;
				}
				Instances[Instance].MethodNameIndexes[Instances[Instance].TotalMethods] =
				GetSelectorIndex(TempString, caCAN_ADD);
                DoFunctionArgs();
                CodeBufOffset=(CodeBufOffset+2)&0xFFFE;
				Instances[Instance].MethodCodeOffsets[Instances[Instance].TotalMethods++] = CodeBufOffset;
				if(!CompileCode(ccMETHOD,TRUE)) return FALSE;
                CodeBufOffset=(CodeBufOffset+2)&0xFFFE;
			} else {
				ShowMessage(errPROPORMETHEXP,NULL);
				return FALSE;
			}
			GetNextWord(&InBuf);
		}
                    /*
    	if(Instances[Instance].TotalProperties==0&&sClasses[SuperIndex].TotalProperties) {
        	Instances[Instance].TotalProperties=sClasses[SuperIndex].TotalProperties;
            Instances[Instance].PropertyNameIndexes = (int*) malloc(Instances[Instance].TotalProperties*sizeof(int));
			Instances[Instance].PropertyValues = (int*) malloc(Instances[Instance].TotalProperties*sizeof(int));

				InBuf = OldPtr;
				LineNumber = OldLine;
                for(SuperProperty = 0; SuperProperty<Instances[Instance].TotalProperties;SuperProperty++) {
				    Instances[Instance].PropertyValues[SuperProperty] =
                        sClasses[SuperIndex].PropertyValues[SuperProperty];
				    Instances[Instance].PropertyNameIndexes[SuperProperty] =
                        sClasses[SuperIndex].PropertyNameIndexes[SuperProperty];
                }
        }   */
	}

	if(TotalProcedures)
		for(Procedure = 0; Procedure < TotalProcedures; Procedure++) {
			SetInBuf(ProcedureInPtr[Procedure]);
            DoFunctionArgs();
            GetNextWord(&InBuf);
            Procedures[Procedure].Super = -1;
            if(strcmp(TempString,"of")==0)  {
            	SelfInfo = GetClassIndex(GetNextWord(&InBuf));
				if(SelfInfo.Index==-1) {
					ShowMessage(errSUPCLASSNAMEEXP,NULL);
					return FALSE;
				}
				if(SelfInfo.INSTANCE) {
					ShowMessage(errEXPCLASSGOTIN,NULL);
					return FALSE;
				}
                Procedures[Procedure].Super = SelfInfo.Index;
				SelfInfo.INSTANCE = FALSE;
			} else SeekBack(&InBuf);

            CodeBufOffset=(CodeBufOffset+2)&0xFFFE;
            Procedures[Procedure].Offset = CodeBufOffset;
			if(!CompileCode((Procedures[Procedure].Super!=-1)?ccPROCEDUREOF:ccPROCEDURE,TRUE)) return FALSE;
            CodeBufOffset=(CodeBufOffset+2)&0xFFFE;
		}

    if(SynonymInPtr) {
        SetInBuf(SynonymInPtr);
        TotalSynonyms = 0;

        TotalBrackets = 1;
		GetNextWord(&InBuf);
		while(TempString[0]!='\0'&&TotalBrackets) {
            if(TempString[0]=='(') {
                if(++TotalBrackets) GetNextWord(&InBuf);
            } else if(TempString[0]==')') {
                if(--TotalBrackets) GetNextWord(&InBuf);
            } else {
                if(TempString[0]!='\'') {
                	ShowMessage(errSINGLEQUOTEEXP,NULL);
                    return FALSE;
                }
				GetNextWord(&InBuf);
            	if((Synonym1 = IsStringInVocab(TempString))==-1) {
                	ShowMessage(errWORDNIV,NULL,TempString);
                    return FALSE;
                }
				GetNextWord(&InBuf);
                if(TempString[0]!='\'') {
                	ShowMessage(errSINGLEQUOTEEXP,NULL);
                    return FALSE;
                }
				GetNextWord(&InBuf);
                if(TempString[0]!='=') {
                	ShowMessage(errEQUALEXP,NULL);
                    return FALSE;
                }
				GetNextWord(&InBuf);
                if(TempString[0]!='\'') {
                	ShowMessage(errSINGLEQUOTEEXP,NULL);
                    return FALSE;
                }
				GetNextWord(&InBuf);
            	if((Synonym2 = IsStringInVocab(TempString))==-1) {
                	ShowMessage(errWORDNIV,NULL,TempString);
                    return FALSE;
                }
				GetNextWord(&InBuf);
                if(TempString[0]!='\'') {
                	ShowMessage(errSINGLEQUOTEEXP,NULL);
                    return FALSE;
                }
                SynPtr = SynonymsSegment+(TotalSynonyms<<2);
                /* I'll manually do them at bytes to keep compatibility
                   on non PCs */
                SynPtr[0] = Synonym1&0xFF;
                SynPtr[1] = Synonym1>>8;
                SynPtr[2] = Synonym2&0xFF;
                SynPtr[3] = Synonym2>>8;
                TotalSynonyms++;
				GetNextWord(&InBuf);
            }
        }
    }
	return TRUE;
}
/******************************************************************************/
BOOL FinalCompile()
{
	int SegLen, i, j, Property, Method, Value, Class, Instance, CurrentPublic = 0;
	WORD ClassStart, LocalsOffset, SelectorID, ci,ActualOffset;
    BOOL ALIGN_SEGMENTS=TRUE;
    short *oo,v;
    tsASMLABEL *al;
	Offset = 0;

    TotalPublics = TotalPubProcs;
    if(TotalPubInstances) TotalPublics+=TotalPubInstances;
    if(TotalPubClasses) TotalPublics+=TotalPubClasses;

                     /*
    U16 SEG_ID : $0008
    U16 SEG_LEN: .....
    U16 TOTAL  : .....
    U32 ADDRESS 1
    U32 ADDRESS 2...    */

    if(TotalProtoPubs&&TotalProtoPubs<TotalPublics) {
        ShowMessage(errMISSINGPROTOS,NULL);
        return FALSE;
    }
    if(TotalProtoPubs) {
        if((Publics = (tsPUBLIC*) calloc(sizeof(tsPUBLIC),TotalProtoPubs))==NULL) {
            ShowMessage(smERROR,"Unable to allocate buffer for Publics!");
            return FALSE;
        }
		OutBuf[Offset] = sgPUBLIC;

#ifdef SCI1MODE
        	SegLen = (TotalProtoPubs<<2)+6;
            if(ALIGN_SEGMENTS)
        	    SegLen = (SegLen+2)&0xFFFE;
		    OutBuf[Offset+4] = (BYTE)(TotalProtoPubs&0xFF);
		    OutBuf[Offset+5] = (BYTE)(TotalProtoPubs>>8);
#else
        	SegLen = (TotalProtoPubs<<1)+6;
            if(ALIGN_SEGMENTS)
        	    SegLen = (SegLen+2)&0xFFFE;
		    OutBuf[Offset+4] = (BYTE)(TotalProtoPubs&0xFF);
		    OutBuf[Offset+5] = (BYTE)(TotalProtoPubs>>8);
#endif

		OutBuf[Offset+2] = (BYTE)(SegLen&0xFF);
		OutBuf[Offset+3] = (BYTE)(SegLen>>8);
		Offset+=SegLen;
    } else {
    if(TotalPublics) {
        if((Publics = (tsPUBLIC*) calloc(sizeof(tsPUBLIC),TotalPublics))==NULL) {
            ShowMessage(smERROR,"Unable to allocate buffer for Publics!");
            return FALSE;
        }
		OutBuf[Offset] = sgPUBLIC;

#ifdef SCI1MODE
        	SegLen = (TotalPublics<<2)+6;
            if(ALIGN_SEGMENTS)
        	    SegLen = (SegLen+2)&0xFFFE;
		    OutBuf[Offset+4] = (BYTE)(TotalPublics&0xFF);
		    OutBuf[Offset+5] = (BYTE)(TotalPublics>>8);
#else
        	SegLen = (TotalPublics<<1)+6;
            if(ALIGN_SEGMENTS)
        	    SegLen = (SegLen+2)&0xFFFE;
		    OutBuf[Offset+4] = (BYTE)(TotalPublics&0xFF);
		    OutBuf[Offset+5] = (BYTE)(TotalPublics>>8);
#endif

		OutBuf[Offset+2] = (BYTE)(SegLen&0xFF);
		OutBuf[Offset+3] = (BYTE)(SegLen>>8);
		Offset+=SegLen;
	}
    }
	for(Class = 0; Class < TotalLocalClasses; Class++) {
		if(!sClasses[Class].EXPORTED) {
			ClassStart = Offset;
			OutBuf[Offset] = sgCLASS;
			/* three bytes skipped */
			OutBuf[Offset+4] = 0x34;
			OutBuf[Offset+5] = 0x12;
			/* four bytes skipped */
			OutBuf[Offset+10] = (BYTE)((sClasses[Class].TotalProperties+4)&0xFF);
			OutBuf[Offset+11] = (BYTE)((sClasses[Class].TotalProperties+4)>>8);

			OutBuf[Offset+12] = (BYTE)(sClasses[Class].Species&0xFF);
			OutBuf[Offset+13] = (BYTE)(sClasses[Class].Species>>8);

			OutBuf[Offset+14] = (BYTE)(sClasses[Class].Superclass&0xFF);
			OutBuf[Offset+15] = (BYTE)(sClasses[Class].Superclass>>8);

			/* -info- */
			OutBuf[Offset+16] = (BYTE)(sClasses[Class].Superclass==0)?0x00:0x00;
			OutBuf[Offset+17] = (BYTE)(0x80);

			OutBuf[Offset+18] = (BYTE)(sClasses[Class].NamePtr&0xFF);
			OutBuf[Offset+19] = (BYTE)(sClasses[Class].NamePtr>>8);

            ChgOffString[TotalChgOffString++].Offset = Offset + 18;

		    if(sClasses[Class].PUBLIC) {
			    ChgOffString[TotalChgOffString-1].Class = Class;
            } else
                ChgOffString[TotalChgOffString-1].Class=(WORD)0xFFFF;
			Offset += 20;

			for(Property=0;Property<sClasses[Class].TotalProperties;Property++) {
                if((Value=GetPropChange(Class,Property,FALSE))!=-1)
                    ChgOffProp[Value].Offset = Offset;
                OutBuf[Offset  ] = (BYTE)(sClasses[Class].PropertyValues[Property]&0xFF);
                OutBuf[Offset+1] = (BYTE)(sClasses[Class].PropertyValues[Property]>>8);
				Offset+=2;
			}
            SelectorID = GetSelectorIndex("species", caCAN_ADD);
            OutBuf[Offset  ] = (BYTE)(SelectorID&0xFF);
            OutBuf[Offset+1] = (BYTE)(SelectorID>>8);
            SelectorID = GetSelectorIndex("superClass", caCAN_ADD);
            OutBuf[Offset+2] = (BYTE)(SelectorID&0xFF);
            OutBuf[Offset+3] = (BYTE)(SelectorID>>8);
            SelectorID = GetSelectorIndex("-info-", caCAN_ADD);
            OutBuf[Offset+4] = (BYTE)(SelectorID&0xFF);
            OutBuf[Offset+5] = (BYTE)(SelectorID>>8);
            SelectorID = GetSelectorIndex("name", caCAN_ADD);
            OutBuf[Offset+6] = (BYTE)(SelectorID&0xFF);
            OutBuf[Offset+7] = (BYTE)(SelectorID>>8);
            Offset+=8;

			for(Property=0;Property<sClasses[Class].TotalProperties;Property++) {
                OutBuf[Offset  ] = (BYTE)(sClasses[Class].PropertyNameIndexes[Property]&0xFF);
                OutBuf[Offset+1] = (BYTE)(sClasses[Class].PropertyNameIndexes[Property]>>8);
				Offset+=2;
			}

			OutBuf[ClassStart+8]=(BYTE)((Offset-ClassStart-10)&0xFF);
			OutBuf[ClassStart+9]=(BYTE)((Offset-ClassStart-10)>>8);
			OutBuf[Offset  ] = (BYTE)(sClasses[Class].TotalMethods&0xFF);
			OutBuf[Offset+1] = (BYTE)(sClasses[Class].TotalMethods>>8);
			Offset+=2;

			for(Method=0;Method<sClasses[Class].TotalMethods;Method++) {
				OutBuf[Offset  ] = (BYTE)(sClasses[Class].MethodNameIndexes[Method]&0xFF);
				OutBuf[Offset+1] = (BYTE)(sClasses[Class].MethodNameIndexes[Method]>>8);
				Offset += 2;
			}

			Offset += 2;

			for(Method=0;Method<sClasses[Class].TotalMethods;Method++) {
				ChgOffCode[TotalChgOffCode++].Offset = Offset;
				OutBuf[Offset  ] = (BYTE)(sClasses[Class].MethodCodeOffsets[Method]&0xFF);
				OutBuf[Offset+1] = (BYTE)(sClasses[Class].MethodCodeOffsets[Method]>>8);
				Offset += 2;
			}

			/* write the length */

            if(ALIGN_SEGMENTS) Offset = (Offset +2)&0xFFFE;

            Value = (Offset-ClassStart);
            OutBuf[ClassStart+2] = (BYTE)(Value&0xFF);
            OutBuf[ClassStart+3] = (BYTE)(Value>>8);
		}
	}
	for(Instance = 0; Instance < TotalInstances; Instance++) {
		ClassStart = Offset;
        Instances[Instance].Offset = Offset;
		OutBuf[Offset] = sgINSTANCE;
		/* three bytes skipped */
		OutBuf[Offset+4] = 0x34;
		OutBuf[Offset+5] = 0x12;
		/* four bytes skipped */
		OutBuf[Offset+10] = (BYTE)((Instances[Instance].TotalProperties+4)&0xFF);
		OutBuf[Offset+11] = (BYTE)((Instances[Instance].TotalProperties+4)>>8);

		OutBuf[Offset+12] = (BYTE)(Instances[Instance].Species&0xFF);
		OutBuf[Offset+13] = (BYTE)(Instances[Instance].Species>>8);

		OutBuf[Offset+14] = (BYTE)(Instances[Instance].Superclass&0xFF);
		OutBuf[Offset+15] = (BYTE)(Instances[Instance].Superclass>>8);

		/* -info- */
		OutBuf[Offset+16] = (BYTE)0x00;
		OutBuf[Offset+17] = (BYTE)0x00;

		OutBuf[Offset+18] = (BYTE)(Instances[Instance].NamePtr&0xFF);
		OutBuf[Offset+19] = (BYTE)(Instances[Instance].NamePtr>>8);


        ChgOffString[TotalChgOffString++].Offset = Offset + 18;

		if(Instances[Instance].PUBLIC) {
			ChgOffString[TotalChgOffString-1].Class = Instance|0x8000;
        } else
            ChgOffString[TotalChgOffString-1].Class=(WORD)0xFFFF;

		/*AddComReloc(srSTRINGS,Instances[Instance].NamePtr);*/
		Offset += 20;

		for(Property=0;Property<Instances[Instance].TotalProperties;Property++) {
            if((Value=GetPropChange(Instance,Property,TRUE))!=-1)
                ChgOffProp[Value].Offset = Offset;
            OutBuf[Offset  ] = (BYTE)(Instances[Instance].PropertyValues[Property]&0xFF);
            OutBuf[Offset+1] = (BYTE)(Instances[Instance].PropertyValues[Property]>>8);
			Offset+=2;
		}

		OutBuf[ClassStart+8]=(BYTE)((Offset-ClassStart-10)&0xFF);
		OutBuf[ClassStart+9]=(BYTE)((Offset-ClassStart-10)>>8);
		OutBuf[Offset  ] = (BYTE)(Instances[Instance].TotalMethods&0xFF);
		OutBuf[Offset+1] = (BYTE)(Instances[Instance].TotalMethods>>8);
		Offset+=2;

		for(Method=0;Method<Instances[Instance].TotalMethods;Method++) {
			OutBuf[Offset  ] = (BYTE)(Instances[Instance].MethodNameIndexes[Method]&0xFF);
			OutBuf[Offset+1] = (BYTE)(Instances[Instance].MethodNameIndexes[Method]>>8);
			Offset += 2;
		}

		Offset += 2;

		for(Method=0;Method<Instances[Instance].TotalMethods;Method++) {
			ChgOffCode[TotalChgOffCode++].Offset = Offset;
			OutBuf[Offset  ] = (BYTE)(Instances[Instance].MethodCodeOffsets[Method]&0xFF);
			OutBuf[Offset+1] = (BYTE)(Instances[Instance].MethodCodeOffsets[Method]>>8);
			Offset += 2;
		}

		/* write the length */
        if(ALIGN_SEGMENTS) Offset = (Offset +2)&0xFFFE;

        Value = (Offset-ClassStart);
        OutBuf[ClassStart+2] = (BYTE)(Value&0xFF);
        OutBuf[ClassStart+3] = (BYTE)(Value>>8);
	}
	if(CodeBufOffset) {
        for(i=0;i<TotalLabels;i++) {
            al = &ASMLabels[i];
            oo = al->Offsets;
            if(ASMLabels[i].Offset==-1) {
                ShowMessage(errLABELUNDEF,NULL,ASMLabels[i].Name);
                return FALSE;
            }
            for(j=0;j<al->TotalOffsets;j++) {
                v = CodeBuf[oo[j]]+(CodeBuf[oo[j]+1]<<8);
                ActualOffset =  (short)((short)al->Offset-(short)v);
                CodeBuf[oo[j]  ] = ActualOffset&0xFF;
                CodeBuf[oo[j]+1] = ActualOffset>>8;
            }
        }

		OutBuf[Offset] = sgCODE;
		if(ALIGN_SEGMENTS)
        	SegLen = ((CodeBufOffset+4)+2)&0xFFFE;
        else
        	SegLen = (CodeBufOffset+4)+0xF;
		OutBuf[Offset+2] = (BYTE)(SegLen&0xFF);
		OutBuf[Offset+3] = (BYTE)(SegLen>>8);
		Offset += 4;

		CodeOffset = Offset;

		memcpy(OutBuf+Offset,CodeBuf,CodeBufOffset);
		Offset += SegLen-4;
	}     
	if(SaidSegLen) {
		OutBuf[Offset] = sgSAID;
		if(ALIGN_SEGMENTS)
        	SegLen = ((SaidSegLen+4)+2)&0xFFFE;
        else
        	SegLen = SaidSegLen+4;
		OutBuf[Offset+2] = (BYTE)(SegLen&0xFF);
		OutBuf[Offset+3] = (BYTE)(SegLen>>8);
		Offset += 4;

		SaidOffset = Offset;

		memcpy(OutBuf+Offset,SaidSegment,SaidSegLen);
		Offset += SegLen-4;
	}

	if(StringSegLen) {
		OutBuf[Offset] = sgSTRINGS;
		if(ALIGN_SEGMENTS)
        	SegLen = ((StringSegLen+4)+2)&0xFFFE;
        else
        	SegLen = StringSegLen+4;
		OutBuf[Offset+2] = (BYTE)(SegLen&0xFF);
		OutBuf[Offset+3] = (BYTE)(SegLen>>8);
		Offset += 4;

		StringsOffset = Offset;

		memcpy(OutBuf+Offset,StringSegment,StringSegLen);
		Offset += SegLen-4;
	}

    if(PRELOAD_TEXT) {
		OutBuf[Offset  ] = (BYTE)(9);
		OutBuf[Offset+1] = (BYTE)(0);
		OutBuf[Offset+2] = (BYTE)(4);
		OutBuf[Offset+3] = (BYTE)(0);
		Offset+=4;
    }

	if(TotalVar[vLOCAL]) {
		OutBuf[Offset] = sgLOCAL;
		SegLen = (TotalVar[vLOCAL]<<1)+4;
        if(ALIGN_SEGMENTS) SegLen = (SegLen+2)&0xFFFE;
		OutBuf[Offset+2] = (BYTE)(SegLen&0xFF);
		OutBuf[Offset+3] = (BYTE)(SegLen>>8);
		Offset += 4;

        LocalsOffset = Offset;

		for(i=0;i<TotalVar[vLOCAL];i++) {
			OutBuf[Offset  ] = (BYTE)(Var[vLOCAL][i].Value&0xFF);
			OutBuf[Offset+1] = (BYTE)(Var[vLOCAL][i].Value>>8);
			Offset += 2;
		}
        if(ALIGN_SEGMENTS) Offset = (Offset+2)&0xFFFE;
	}     

	if(TotalSynonyms) {
		OutBuf[Offset] = sgSYNONYM;
		if(ALIGN_SEGMENTS)
        	SegLen = (((TotalSynonyms<<2)+6)+2)&0xFFFE;
        else
        	SegLen = (TotalSynonyms<<2)+6;
		OutBuf[Offset+2] = (BYTE)(SegLen&0xFF);
		OutBuf[Offset+3] = (BYTE)(SegLen>>8);
		Offset += 4;

		memcpy(OutBuf+Offset,SynonymsSegment,SegLen-6);
		Offset += SegLen-6;
		OutBuf[Offset  ] = 0xFF;
		OutBuf[Offset+1] = 0xFF;
		Offset += 2;
	}
	/* finalize the script fixing up offsets */

	for(i = 0; i < TotalProcedures; i++)
		Procedures[i].Offset += CodeOffset;

	for(i=0;i<TotalChgOffCode;i++) {
		if(ChgOffCode[i].STRING) {
        	ChgOffCode[i].Offset += CodeOffset;

#ifdef SCI1MODE
		    	Value = OutBuf[ChgOffCode[i].Offset]+(OutBuf[ChgOffCode[i].Offset+1]<<8)+StringsOffset;
		    	OutBuf[ChgOffCode[i].Offset  ]=(BYTE)(Value&0xFF);
		    	OutBuf[ChgOffCode[i].Offset+1]=(BYTE)(Value>>8);
		    	Relocation[TotalRelocation++]=ChgOffCode[i].Offset;
#else
            	Value = (int)(((signed)((OutBuf[ChgOffCode[i].Offset]+(OutBuf[ChgOffCode[i].Offset+1]<<8))+StringsOffset)) - ((signed) (ChgOffCode[i].Offset+2)));
				OutBuf[ChgOffCode[i].Offset  ]=(BYTE)(Value&0xFF);
				OutBuf[ChgOffCode[i].Offset+1]=(BYTE)(Value>>8);
#endif
		} else if(ChgOffCode[i].SAID) {
			ChgOffCode[i].Offset += CodeOffset;
			Value = (int)(((signed)((OutBuf[ChgOffCode[i].Offset]+(OutBuf[ChgOffCode[i].Offset+1]<<8))+SaidOffset)) - ((signed) (ChgOffCode[i].Offset+2)));
			OutBuf[ChgOffCode[i].Offset  ]=(BYTE)(Value&0xFF);
			OutBuf[ChgOffCode[i].Offset+1]=(BYTE)(Value>>8);
		} else if(ChgOffCode[i].REL) {
			ChgOffCode[i].Offset += CodeOffset;
			Value = (int)(((signed)Procedures[ChgOffCode[i].Procedure].Offset) - ((signed) (ChgOffCode[i].Offset+3)));
			OutBuf[ChgOffCode[i].Offset  ]=(BYTE)(Value&0xFF);
			OutBuf[ChgOffCode[i].Offset+1]=(BYTE)(Value>>8);
		} else if(ChgOffCode[i].INSTANCE) {
            ChgOffCode[i].Offset += CodeOffset;

#ifdef SCI1MODE
		    	Value = OutBuf[ChgOffCode[i].Offset]+(OutBuf[ChgOffCode[i].Offset+1]<<8);
		    	Value = Instances[Value].Offset+12;
		    	OutBuf[ChgOffCode[i].Offset  ]=(BYTE)(Value&0xFF);
		    	OutBuf[ChgOffCode[i].Offset+1]=(BYTE)(Value>>8);
		    	Relocation[TotalRelocation++]=ChgOffCode[i].Offset;
#else
                Value = OutBuf[ChgOffCode[i].Offset]+(OutBuf[ChgOffCode[i].Offset+1]<<8);
			    Value = (int)(((signed)((
                    Instances[Value].Offset
                    ))) - ((signed) (ChgOffCode[i].Offset-10)));
			    OutBuf[ChgOffCode[i].Offset  ]=(BYTE)(Value&0xFF);
			    OutBuf[ChgOffCode[i].Offset+1]=(BYTE)(Value>>8);
#endif
		} else if(ChgOffCode[i].CLASS) {
            ChgOffCode[i].Offset += CodeOffset;

#ifdef SCI1MODE
		    	Value = OutBuf[ChgOffCode[i].Offset]+(OutBuf[ChgOffCode[i].Offset+1]<<8);
		    	Value = sClasses[Value].Offset+12;
		    	OutBuf[ChgOffCode[i].Offset  ]=(BYTE)(Value&0xFF);
		    	OutBuf[ChgOffCode[i].Offset+1]=(BYTE)(Value>>8);
		    	Relocation[TotalRelocation++]=ChgOffCode[i].Offset;
#else
                Value = OutBuf[ChgOffCode[i].Offset]+(OutBuf[ChgOffCode[i].Offset+1]<<8);
			    Value = (int)(((signed)((
                    sClasses[Value].Offset
                    ))) - ((signed) (ChgOffCode[i].Offset-10)));
			    OutBuf[ChgOffCode[i].Offset  ]=(BYTE)(Value&0xFF);
			    OutBuf[ChgOffCode[i].Offset+1]=(BYTE)(Value>>8);
#endif
		} else {
			Value = (OutBuf[ChgOffCode[i].Offset]+(OutBuf[ChgOffCode[i].Offset+1]<<8))+CodeOffset;
			OutBuf[ChgOffCode[i].Offset  ]=(BYTE)(Value&0xFF);
			OutBuf[ChgOffCode[i].Offset+1]=(BYTE)(Value>>8);
		}
	}

	for(i=0;i<TotalChgOffString;i++) {
  		Value = OutBuf[ChgOffString[i].Offset]+(OutBuf[ChgOffString[i].Offset+1]<<8)+StringsOffset;
		OutBuf[ChgOffString[i].Offset  ]=(BYTE)(Value&0xFF);
		OutBuf[ChgOffString[i].Offset+1]=(BYTE)(Value>>8);
		Relocation[TotalRelocation++]=ChgOffString[i].Offset;
		if(ChgOffString[i].Class!=(WORD)0xFFFF) {
			Publics[CurrentPublic].Offset = ChgOffString[i].Offset-6;
            if(ChgOffString[i].Class&0x8000) {
        	    Publics[CurrentPublic].Label = (char*) malloc(strlen(Instances[ChgOffString[i].Class&0x7FFF].Name)+1);
        	    strcpy(Publics[CurrentPublic].Label,Instances[ChgOffString[i].Class&0x7FFF].Name);
            } else {
        	    Publics[CurrentPublic].Label = (char*) malloc(strlen(sClasses[ChgOffString[i].Class].Name)+1);
        	    strcpy(Publics[CurrentPublic].Label,sClasses[ChgOffString[i].Class].Name);
            }
            CurrentPublic++;
		}
	}

	for(i=0;i<TotalChgOffProp;i++) {
        if(ChgOffProp[i].STRING) {
		    Value = OutBuf[ChgOffProp[i].Offset]+(OutBuf[ChgOffProp[i].Offset+1]<<8)+StringsOffset;
		    OutBuf[ChgOffProp[i].Offset  ]=(BYTE)(Value&0xFF);
		    OutBuf[ChgOffProp[i].Offset+1]=(BYTE)(Value>>8);
		    Relocation[TotalRelocation++]=ChgOffProp[i].Offset;
        } else if(ChgOffProp[i].SAID) {
		    Value = OutBuf[ChgOffProp[i].Offset]+(OutBuf[ChgOffProp[i].Offset+1]<<8)+SaidOffset;
		    OutBuf[ChgOffProp[i].Offset  ]=(BYTE)(Value&0xFF);
		    OutBuf[ChgOffProp[i].Offset+1]=(BYTE)(Value>>8);
		    Relocation[TotalRelocation++]=ChgOffProp[i].Offset;
        } else if(ChgOffProp[i].VAR) {
		    Value = OutBuf[ChgOffProp[i].Offset]+(OutBuf[ChgOffProp[i].Offset+1]<<8)+LocalsOffset;
		    OutBuf[ChgOffProp[i].Offset  ]=(BYTE)(Value&0xFF);
		    OutBuf[ChgOffProp[i].Offset+1]=(BYTE)(Value>>8);
		    Relocation[TotalRelocation++]=ChgOffProp[i].Offset;
        }
	}

	/* write the relocation table */
	if(TotalRelocation) {
		OutBuf[Offset] = sgRELOCATION;
        if(ALIGN_SEGMENTS)
        	SegLen = (((TotalRelocation<<1)+6)+2)&0xFFFE;
        else
        	SegLen = (TotalRelocation<<1)+6;


#ifdef SCI1MODE       
			OutBuf[Offset+2] = (BYTE)((SegLen+2)&0xFF);
			OutBuf[Offset+3] = (BYTE)((SegLen+2)>>8);
			OutBuf[Offset+4] = (BYTE)((TotalRelocation)&0xFF);
			OutBuf[Offset+5] = (BYTE)((TotalRelocation)>>8);
        	OutBuf[Offset+6] = 0;
			OutBuf[Offset+7] = 0;
			Offset += 8;
#else
			OutBuf[Offset+2] = (BYTE)(SegLen&0xFF);
			OutBuf[Offset+3] = (BYTE)(SegLen>>8);
			OutBuf[Offset+4] = (BYTE)(TotalRelocation&0xFF);
			OutBuf[Offset+5] = (BYTE)(TotalRelocation>>8);
			Offset += 6;
#endif

		for(i=0;i<TotalRelocation;i++) {
			OutBuf[Offset  ]=(BYTE)(Relocation[i]&0xFF);
			OutBuf[Offset+1]=(BYTE)(Relocation[i]>>8);
			Offset+=2;
		}
        if(ALIGN_SEGMENTS) Offset = (Offset+2)&0xFFFE;
	}

    for(i=0;i<TotalProcedures;i++) {
    	if(Procedures[i].PUBLIC) {
        	Publics[CurrentPublic].Offset = Procedures[i].Offset;
        	Publics[CurrentPublic].Label = (char*) malloc(strlen(Procedures[i].Label)+1);
        	strcpy(Publics[CurrentPublic].Label,Procedures[i].Label);
        	CurrentPublic++;
        }
    }
    if(TotalProtoPubs) {

#ifdef SCI1MODE
			for(i=0;i<TotalProtoPubs;i++) {
                memset(OutBuf+(i<<2)+6,0,4);
                for(j=0;j<TotalPublics;j++) {
                    if(strcmp(Publics[j].Label,ProtPubLabels[i])==0) {
				        OutBuf[(i<<2)+6]=(BYTE)(Publics[j].Offset&0xFF);
			    	    OutBuf[(i<<2)+7]=(BYTE)(Publics[j].Offset>>8);
                        break;
                    }
                }
			}
#else 
			for(i=0;i<TotalProtoPubs;i++) {
                memset(OutBuf+(i<<1)+6,0,2);
                for(j=0;j<TotalPublics;j++) {
                    if(strcmp(Publics[j].Label,ProtPubLabels[i])==0) {
				        OutBuf[(i<<1)+6]=(BYTE)(Publics[j].Offset&0xFF);
			    	    OutBuf[(i<<1)+7]=(BYTE)(Publics[j].Offset>>8);
                        break;
                    }
                }
			}
#endif
    } else {
	if(TotalPublics) {

#ifdef SCI1MODE
			for(i=0;i<TotalPublics;i++) {
				OutBuf[(i<<2)+6]=(BYTE)(Publics[i].Offset&0xFF);
				OutBuf[(i<<2)+7]=(BYTE)(Publics[i].Offset>>8);
				OutBuf[(i<<2)+8]=(BYTE)(0);
				OutBuf[(i<<2)+9]=(BYTE)(0);
					Publics[i].Offset = i;
			}
#else
			for(i=0;i<TotalPublics;i++) {
				OutBuf[(i<<1)+6]=(BYTE)(Publics[i].Offset&0xFF);
				OutBuf[(i<<1)+7]=(BYTE)(Publics[i].Offset>>8);
					Publics[i].Offset = i;
			}
#endif
	}
    }

	/* close the script */
	OutBuf[Offset] = sgRETURN;
	Offset += 2;

	return TRUE;
}
/******************************************************************************/
void FreeEverything()
{
	int i;

#ifdef SCC_MSDOS
	if(InBuf) farfree(InBufStart);
	if(OutBuf) farfree(OutBuf);
	if(CodeBuf!=NULL) farfree(CodeBuf);
#else
	if(InBuf) free(InBufStart);
	if(OutBuf) free(OutBuf);
	if(CodeBuf!=NULL) free(CodeBuf);
#endif

	if(StringSegment!=NULL) free(StringSegment);
	 if(SaidSegment!=NULL) free(SaidSegment);

	if(Defines) {
		for(i = 0; i < TotalDefines; i++) {
			free(Defines[i].Label);
			free(Defines[i].Definition);
		}
		  free(Defines);
	 }
	if(Strings!=NULL)		free(Strings);
	if(Said!=NULL)		    free(Said);
	 if(ExternalProcs!=NULL) {
		for(i = 0; i < TotalExternalProcs; i++)
			if(ExternalProcs[i].Label)
				free(ExternalProcs[i].Label);
		  free(ExternalProcs);
	 }

	 if(Publics!=NULL) {
		  for(i = 0; i < TotalPublics; i++)
			 if(Publics[i].Label!=NULL)
          	free(Publics[i].Label);
		  free(Publics);
	 }
	if(ClassInPtr!=NULL)     free(ClassInPtr);
	if(InstanceInPtr!=NULL)  free(InstanceInPtr);
	if(ProcedureInPtr!=NULL) free(ProcedureInPtr);

	if(Voc000) {
		  for(i = 0; i < TotalVoc0Words; i++)
			 if(Voc000[i].String) free(Voc000[i].String);
		 free(Voc000);
	 }

	 if(Vocab996) free(Vocab996);

	if(SelectorNames!=NULL) {
		  for(i = 0; i < TotalSelectorNames; i++)
			 if(SelectorNames[i])
					 free(SelectorNames[i]);
		  free(SelectorNames);
	 }

	if(KernelNamesBuf!=NULL)
    	free(KernelNamesBuf);

	if(sClasses!=NULL) {
		  for(i = 0; i < TotalLocalClasses; i++) {
			 free(sClasses[i].Name);
			 free(sClasses[i].PropertyNameIndexes);
			 free(sClasses[i].PropertyValues);
		 }
		  free(sClasses);
	 }
	if(Instances!=NULL) {
		  for(i = 0; i < TotalInstances; i++) {
			 free(Instances[i].Name);
			 free(Instances[i].PropertyNameIndexes);
			 free(Instances[i].PropertyValues);
		  }
		  free(Instances);
	}

     if(Procedures!=NULL) {
	 	for(i=0;i<TotalProcedures;i++)
			free(Procedures[i].Label);
		free(Procedures);
     }

     if(ProtPubLabels!=NULL) {
	 	for(i=0;i<TotalProtoPubs;i++)
			free(ProtPubLabels[i]);
		free(ProtPubLabels);
     }

	if(ChgOffCode!=NULL) free(ChgOffCode);
	if(ChgOffString!=NULL) free(ChgOffString);
	if(ChgOffProp!=NULL) free(ChgOffProp);

	 for(i=0;i<4;i++) {
		  FreeVars(i);
	 }

    if(TotalLabels)
        memset(ASMLabels,0,sizeof(ASMLabels));
}
/******************************************************************************/
BOOL DoInclude(char *FileName, BOOL FULL_PROCESS)
{
	int Segment, StrLen;
	WORD OldLineNumber = LineNumber;
	long IncludeFileLen;
	char *IncludeBuf, *IncludeBufStart;

	IN_HEADER = TRUE;
	strcpy(IncludeFileName, FileName);
	LineNumber=1;

	/* open the include file */
	if((fHandle = dirlist_open(include_dirs, FileName,"rb"))==NULL) {
		ShowMessage(smERROR,"Unable to open file: %s for reading!",FileName);
		return FALSE;
	}
	fseek(fHandle,0,SEEK_END);
	IncludeFileLen = ftell(fHandle);
	if((IncludeBuf=(char*)malloc((size_t)IncludeFileLen+1))==NULL) {
		ShowMessage(smERROR,"Unable to allocate buffer for source file!");
		return FALSE;
	}
	fseek(fHandle,0,SEEK_SET);
	fread(IncludeBuf,(size_t)IncludeFileLen,1,fHandle);
	IncludeBuf[(size_t)IncludeFileLen]='\0';
	fclose(fHandle);

	IncludeBufStart = IncludeBuf;

	/* Do Include */
	GetNextWord(&IncludeBuf);
	while(TempString[0]!='\0') {
		/* syntax: "(" "segment name"... */
		if(TempString[0]!='(') {
			ShowMessage(errINBRACEXP,NULL);
			free(IncludeBufStart);
			return FALSE;
		}
		/* Get the segment name */
		Segment=GetSegmentIndex(GetNextWord(&IncludeBuf));
		/* Parse the segment */
		switch(Segment) {
			case sgDEFINE:
				/* Get the label */
				if(FULL_PROCESS) {
					Defines[CurrentDefine].Label = (char*)malloc(strlen(GetNextWord(&IncludeBuf))+1);
					strcpy(Defines[CurrentDefine].Label, TempString);
					Defines[CurrentDefine].Definition = (char*)malloc(strlen(GetNextWord(&IncludeBuf))+1);
					strcpy(Defines[CurrentDefine].Definition, TempString);
					CurrentDefine++;
				} else {
					GetNextWord(&IncludeBuf);
					GetNextWord(&IncludeBuf);
					TotalDefines++;
				}
				/* Segment closing bracket */
				if(GetNextWord(&IncludeBuf)[0]!=')') {
					ShowMessage(errOUTBRACEXP,NULL);
					free(IncludeBufStart);
					return FALSE;
				}
				break;
			case sgINCLUDE:
				/* get the include file name */
				if(GetNextWord(&IncludeBuf)[0]!='"') {
					ShowMessage(errQUOTEEXP,NULL);
					free(IncludeBufStart);
					return FALSE;
				}
				StrLen = 0;
				while(*(IncludeBuf+StrLen) != '\0') {
					if(*(IncludeBuf+StrLen) == '"' && *(IncludeBuf+StrLen-1) != '\\') break;
					StrLen++;
				}
				memcpy(TempString,IncludeBuf,StrLen);
				TempString[StrLen]='\0';
				strcpy(IncludeFileName,TempString);
				IncludeBuf += StrLen+1;

				/* check syntax */
				if(GetNextWord(&IncludeBuf)[0]!=')') {
					ShowMessage(errOUTBRACEXP,NULL);
					free(IncludeBufStart);
					return FALSE;
				}
				if(!DoInclude(IncludeFileName,FULL_PROCESS)) {
					free(IncludeBufStart);
					return FALSE;
				}
				strcpy(IncludeFileName, FileName);
				break;
			default:
				ShowMessage(errINVHDRSEG,NULL);
				free(IncludeBufStart);
				return FALSE;
		}
		GetNextWord(&IncludeBuf);
	}

	free(IncludeBufStart);
	LineNumber = OldLineNumber;
	IN_HEADER = FALSE;
	return TRUE;
}
/******************************************************************************/
void SetInBuf(char *NewPos)
{
	LineNumber = 1;
	InBuf = InBufStart;
	while(InBuf!=NewPos && *InBuf!='\0') {
		if(*InBuf=='\n') LineNumber++;
		InBuf++;
	}
}
/******************************************************************************/
BOOL SkipSegment()
{
	/* nice and easy segment skip */
	int TotalBrackets = 1;
    char lastC=0;

	while(TotalBrackets) {
        GetNextWord(&InBuf);
		switch(TempString[0]) {
			case '\0':
				ShowMessage(errOUTBRACEXP,NULL);
				return FALSE;
			case '(': TotalBrackets++; break;
			case ')': TotalBrackets--; break;
			case '"':
				while(*InBuf!='\0') {
					if(*InBuf=='"'&&*(InBuf-1)!='\\') break;
					InBuf++;
				}
                InBuf++;
				break;
            case '\'':
				while(*InBuf!='\0'&&*InBuf!='\'') InBuf++;
                InBuf++;
				break;
            default:
                if(TotalBrackets>2&&((lastC=='('&&(IsSegmentName(TempString)!=-1&&strcmp(TempString,"script")!=0)) ||
                    strcmp(TempString,"method")==0)) {
				    ShowMessage(errOUTBRACEXP,NULL);
				    return FALSE;
                }

		}
        lastC = TempString[0];
	}
	return TRUE;
}
/******************************************************************************/
BOOL CountStringSegment()
{
	int TotalBrackets = 1;
    TotalStrings = 0;
    GetNextWord(&InBuf);
	while(TotalBrackets) {
		if(TempString[0]=='\0') {
            ShowMessage(errOUTBRACEXP,NULL);
            return FALSE;
		} else if(TempString[0]=='(') {
			TotalBrackets++;
		} else if(TempString[0]==')') {
			TotalBrackets--;
		} else if(TempString[0]=='=') {
		} else if(TempString[0]=='"') {
            if(!DoString()) return FALSE;
		} else if(IsStringLabel(TempString)) {
            TotalStrings++;
        }
        if(TotalBrackets) GetNextWord(&InBuf);
	}
	return TRUE;
}
/******************************************************************************/
BOOL WriteObjectFile()
{
	int i, j, OldOffset, StrLen, xTotalClasses = 0, xTotalPublics = 0;
    WORD Offs;
	char *ObjFileName;

	for(i=strlen(ScriptName)-1;i>=0;i--)
		if(ScriptName[i]=='.') break;

	if(i==0) i = strlen(ScriptName)-1;


	for(j=strlen(ScriptName)-1;j>0;j--)
		if(ScriptName[j]=='\\') {
            j++;
            break;
        }

	if((ObjFileName = (char*) malloc(i-j+5))==NULL){
		ShowMessage(smERROR,"Unable to allocate memory for ObjFileName!");
		return FALSE;
	}
	memcpy(ObjFileName,ScriptName+j,i-j);
	memcpy(ObjFileName+i-j,".sco\0",5);

	/* Open the output for writing */
	if((fHandle=dirlist_open(source_dir, ObjFileName, "wb"))==NULL) {
		ShowMessage(smERROR,"Unable to open file: %s for writing!",ObjFileName);
        free(ObjFileName);
		return FALSE;
	}
    free(ObjFileName);
	fwrite("SCO",3,1,fHandle);
	fputc(oVERSION.Major,fHandle);
	fputc(oVERSION.Minor,fHandle);
	fputc(oVERSION.Build,fHandle);

	fputc(0,fHandle); /* SCI Version */
    fputc(0,fHandle); /* alignment */

	fputc(ScriptNumber&0xFF,fHandle);
	fputc(ScriptNumber>>8,fHandle);

    if(TotalProtoPubs) xTotalPublics=TotalProtoPubs;
    else
	    for(i=0;i<TotalPublics;i++)
		    if(Publics[i].Label!=NULL) xTotalPublics++;

	fputc(xTotalPublics&0xFF,fHandle);
	fputc(xTotalPublics>>8,fHandle);
	fwrite("\0\0",2,1,fHandle);

	for(i=0;i<TotalLocalClasses;i++)
		if(!sClasses[i].EXPORTED) xTotalClasses++;
	fputc(xTotalClasses&0xFF,fHandle);
	fputc(xTotalClasses>>8,fHandle);
	fwrite("\0\0",2,1,fHandle);
	fputc(TotalVar[vLOCAL]&0xFF,fHandle);
	fputc(TotalVar[vLOCAL]>>8,fHandle);
	fwrite("\0\0",2,1,fHandle);

	if(xTotalPublics) {
		OldOffset = (int) ftell(fHandle);
		fseek(fHandle,12,SEEK_SET);
		 fputc(OldOffset&0xFF,fHandle);
	    fputc(OldOffset>>8,fHandle);
		fseek(fHandle,OldOffset,SEEK_SET);

        if(TotalProtoPubs) {
            for(i=0;i<TotalProtoPubs;i++) {
                Offs=i;
                for(j=0;j<TotalPublics;j++) {
                    if(strcmp(Publics[j].Label,ProtPubLabels[i])==0) {
				        //Offs=Publics[j].Offset;
                        break;
                    }
                }
                fputc(Offs&0xFF,fHandle);
                fputc(Offs>>8,fHandle);
                StrLen = strlen(ProtPubLabels[i])+1;
                fputc(StrLen&0xFF,fHandle);
                fputc(StrLen>>8,fHandle);
                fwrite(ProtPubLabels[i],StrLen,1,fHandle);
		    }
        } else for(i=0;i<TotalPublics;i++) {
            if(Publics[i].Label!=NULL) {
	            fputc(Publics[i].Offset&0xFF,fHandle);
	            fputc(Publics[i].Offset>>8,fHandle);
			    StrLen = strlen(Publics[i].Label)+1;
	            fputc(StrLen&0xFF,fHandle);
	            fputc(StrLen>>8,fHandle);
			    fwrite(Publics[i].Label,StrLen,1,fHandle);
            }
		}
	}

	if(xTotalClasses) {
		OldOffset = (int) ftell(fHandle);
		fseek(fHandle,16,SEEK_SET);
        fputc(OldOffset&0xFF,fHandle);
        fputc(OldOffset>>8,fHandle);
		fseek(fHandle,OldOffset,SEEK_SET);

		for(i=0;i<TotalLocalClasses;i++) {
			if(!sClasses[i].EXPORTED) {
				StrLen = strlen(sClasses[i].Name)+1;
	            fputc(StrLen&0xFF,fHandle);
	            fputc(StrLen>>8,fHandle);
				fwrite(sClasses[i].Name,StrLen,1,fHandle);
					fputc(sClasses[i].TotalProperties&0xFF,fHandle);
	            fputc(sClasses[i].TotalProperties>>8,fHandle);
	            fputc(sClasses[i].TotalMethods&0xFF,fHandle);
	            fputc(sClasses[i].TotalMethods>>8,fHandle);
	            fputc(sClasses[i].Species&0xFF,fHandle);
	            fputc(sClasses[i].Species>>8,fHandle);
	            fputc(sClasses[i].Superclass&0xFF,fHandle);
	            fputc(sClasses[i].Superclass>>8,fHandle);
				for(j=0;j<sClasses[i].TotalProperties;j++) {
	                fputc(sClasses[i].PropertyNameIndexes[j]&0xFF,fHandle);
	                fputc(sClasses[i].PropertyNameIndexes[j]>>8,fHandle);
	                fputc(sClasses[i].PropertyValues[j]&0xFF,fHandle);
	                fputc(sClasses[i].PropertyValues[j]>>8,fHandle);
				}
				for(j=0;j<sClasses[i].TotalMethods;j++) {
	                fputc(sClasses[i].MethodNameIndexes[j]&0xFF,fHandle);
	                fputc(sClasses[i].MethodNameIndexes[j]>>8,fHandle);
                }
			}
		}
	}
	if(TotalVar[vLOCAL]) {
		OldOffset = (int) ftell(fHandle);
		fseek(fHandle,20,SEEK_SET);
        fputc(OldOffset&0xFF,fHandle);
        fputc(OldOffset>>8,fHandle);
		fseek(fHandle,OldOffset,SEEK_SET);

		for(i=0;i<TotalVar[vLOCAL];i++) {
				if(Var[vLOCAL][i].Label!=NULL) {
			    StrLen = strlen(Var[vLOCAL][i].Label)+1;
                fputc(StrLen&0xFF,fHandle);
                fputc(StrLen>>8,fHandle);
			    fwrite(Var[vLOCAL][i].Label,StrLen,1,fHandle);
            } else {
                fputc(0,fHandle);
                fputc(0,fHandle);
            }
		}
	}

	fclose(fHandle);

	return TRUE;
}
/******************************************************************************/
BOOL LoadObjectFile(char *FileName, BOOL FULL_PROCESS)
{
	int i, j, StrLen, MaxClass;
	if((fHandle=dirlist_open(lib_dirs,FileName,"rb"))==NULL) {
		ShowMessage(smERROR,"Unable to open file: %s for reading!",FileName);
		return FALSE;
	}
	fread(TempString,3,1,fHandle);
	TempString[3]='\0';
	if(strcmp(TempString,"SCO")!=0) {
		ShowMessage(smERROR,"Invalid object header in %s!",FileName);
		return FALSE;
	}
    vMajor = fgetc(fHandle);
    vMinor = fgetc(fHandle);
    vBuild = fgetc(fHandle);
	if(vMajor!=oVERSION.Major||vMinor!=oVERSION.Minor||vBuild!=oVERSION.Build) {
		ShowMessage(smERROR,"Incorrect object version in %s!",FileName);
		ShowMessage(smERROR,"Wanted %d.%d.%d got %d.%d.%d!",oVERSION.Major,oVERSION.Minor,oVERSION.Build,vMajor,vMinor,vBuild);
		return FALSE;
	}
	fgetc(fHandle); /* SCI Version */
    fgetc(fHandle);

	ObjScriptNumber	= fgetw(fHandle);

	ObjTotalPublic 	= fgetw(fHandle);
	ObjPublicOffset 	= fgetw(fHandle);
    if(!FULL_PROCESS) TotalExternalProcs += ObjTotalPublic;
	ObjTotalClasses 	= fgetw(fHandle);
	ObjClassOffset 	= fgetw(fHandle);

	ObjTotalLocal 		= fgetw(fHandle);
	ObjLocalOffset 	= fgetw(fHandle);

	fseek(fHandle,ObjPublicOffset,SEEK_SET);
    if(FULL_PROCESS)  {
		for(i=CurrentExpProc;i<CurrentExpProc+ObjTotalPublic;i++) {
            ExternalProcs[i].Script = ObjScriptNumber;
            ExternalProcs[i].Index = fgetw(fHandle);
            StrLen 	= fgetw(fHandle);
			ExternalProcs[i].Label = (char*) malloc(StrLen);
            fread(ExternalProcs[i].Label,StrLen,1,fHandle);
		}
        CurrentExpProc += ObjTotalPublic;
    }

	fseek(fHandle,ObjClassOffset,SEEK_SET);
	if(!FULL_PROCESS) TotalLocalClasses+=ObjTotalClasses;
	else {
		MaxClass = CurrentClass+ObjTotalClasses;
		for(i=CurrentClass;i<MaxClass;i++) {
			StrLen 	= fgetw(fHandle);
			sClasses[i].Name = (char*) malloc(StrLen);
			fread(sClasses[i].Name,StrLen,1,fHandle);

			sClasses[i].TotalProperties = fgetw(fHandle);
			sClasses[i].TotalMethods    = fgetw(fHandle);
			sClasses[i].Species         = fgetw(fHandle);
			sClasses[i].Superclass      = fgetw(fHandle);

			if(sClasses[i].TotalProperties) {
				sClasses[i].PropertyNameIndexes = (int*) malloc(sClasses[i].TotalProperties*sizeof(int));
				sClasses[i].PropertyValues = (int*) malloc(sClasses[i].TotalProperties*sizeof(int));
				for(j=0;j<sClasses[i].TotalProperties;j++) {
					sClasses[i].PropertyNameIndexes[j] = fgetw(fHandle);
					sClasses[i].PropertyValues[j] = fgetw(fHandle);
				}
			}
			if(sClasses[i].TotalMethods) {
				for(j=0;j<sClasses[i].TotalMethods;j++)
					sClasses[i].MethodNameIndexes[j] = fgetw(fHandle);
			}
			CurrentClass++;
		}
	}

	if(ObjScriptNumber==0&&ObjTotalLocal) {
		fseek(fHandle,ObjLocalOffset,SEEK_SET);
		TotalVar[vGLOBAL] = ObjTotalLocal;
		if(FULL_PROCESS) {
			if((Var[vGLOBAL] = (tsVAR*) malloc(sizeof(tsVAR)*ObjTotalLocal))==NULL) {
				ShowMessage(smERROR,"Unable to allocate buffer for globals!");
				return FALSE;
			}
			for(i=0;i<ObjTotalLocal;i++) {
				StrLen 	= fgetw(fHandle);
				Var[vGLOBAL][i].Label = (char*) malloc(StrLen);
				fread(Var[vGLOBAL][i].Label,StrLen,1,fHandle);
			}
		}
	}

	fclose(fHandle);

	return TRUE;
}
/******************************************************************************/

/***************************************************************************
 *  Copyright (C) 1999-2001 Brian Provinciano, http://www.bripro.com
 ***************************************************************************/

