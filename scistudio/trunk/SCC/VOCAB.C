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
 * SCI Script Compiler Compiler Vocab Handlers
 ******************************************************************************/
#include "scc.h"
/******************************************************************************/
#ifdef SCC_SCISTUDIO_WIN32
#pragma hdrstop
#pragma package(smart_init)
#endif
/******************************************************************************/
BOOL LoadVocab000()
{
	BYTE *Vocab000;
    long Offset,FileLen;
	int i, vWord;

    FileLen=dirlist_resload(idVOCAB, 0, &Vocab000);
	if(FileLen==0) {
		ShowMessage(smERROR,"Unable to open vocab.000 for reading!");
		return FALSE;
	}
    if(FileLen==-1) {
		ShowMessage(smERROR,"Invalid SCI header in vocab.000!");
		return FALSE;
    }
	Offset = 52;
	/* Get the total number of words */
	TotalVoc0Words = 0;
	while(Offset<FileLen) { 
    	Offset++;
		while(Offset<FileLen&&Vocab000[Offset++] < 0x80);
        if(Offset>=FileLen) break;
		Offset+=3;
        TotalVoc0Words++;
	}
	/* Allocate memory for the class names table */
	if((Voc000 = (tsVOC000 *) calloc(TotalVoc0Words, sizeof(tsVOC000)))==NULL)
	{
		ShowMessage(smERROR,"Unable to allocate vocab.000 buffer!");
		return FALSE;
	}

	/* Loop through each class */
	Offset = 52;
	for(vWord = 0; vWord < TotalVoc0Words; vWord++) {
		i = (BYTE)(Vocab000[Offset++]);
		while(Offset < FileLen && (BYTE) (TempString[i++] = (BYTE)(Vocab000[Offset++])) < 0x80);
        if(Offset >= FileLen) break;
		TempString[i-1] &= 0x7F;
		TempString[i] = '\0';
		/* Clear the string variable */
		Voc000[vWord].String = (char *) malloc(i);
		/* Read the string */
		strcpy(Voc000[vWord].String, TempString);

		Voc000[vWord].Group = (WORD) (((Vocab000[Offset+1] << 8) & 0xF00) | (Vocab000[Offset+2] & 0xFF)) & 0xFFF;
		Offset+=3;
	}

	 /* toss the data */
	 free(Vocab000);
    return TRUE;
}
/******************************************************************************/
BOOL LoadVocab900()
{
	BYTE *Vocab900;
    long Offset,FileLen;
	int i, vWord;

    FileLen=dirlist_resload(idVOCAB, 900, &Vocab900);
	if(FileLen==0) {
		ShowMessage(smERROR,"Unable to open vocab.900 for reading!");
		return FALSE;
	}
    if(FileLen==-1) {
		ShowMessage(smERROR,"Invalid SCI header in vocab.900!");
		return FALSE;
    }
	Offset = 0x1FE;
	/* Get the total number of words */
	TotalVoc0Words = 0;
	while(Offset<FileLen) {
    	Offset++;
		while(Offset<FileLen&&Vocab900[Offset++] != '\0');
        if(Offset>=FileLen) break;
		Offset+=3;
        TotalVoc0Words++;
	}
	/* Allocate memory for the class names table */
	if((Voc000 = (tsVOC000 *) calloc(TotalVoc0Words, sizeof(tsVOC000)))==NULL)
	{
		ShowMessage(smERROR,"Unable to allocate vocab.000 buffer!");
		return FALSE;
	}

	/* Loop through each class */
	Offset = 0x1FE;
	for(vWord = 0; vWord < TotalVoc0Words; vWord++) {
		i = (BYTE)(Vocab900[Offset++]);
		while(Offset < FileLen && (BYTE) (TempString[i++] = (BYTE)(Vocab900[Offset++])) != '\0');
        if(Offset >= FileLen) break;
		/* Clear the string variable */
		Voc000[vWord].String = (char *) malloc(i);
		/* Read the string */
		strcpy(Voc000[vWord].String, TempString);

		Voc000[vWord].Group = (WORD) (((Vocab900[Offset+1] << 8) & 0xF00) | (Vocab900[Offset+2] & 0xFF)) & 0xFFF;
		Offset+=3;
	}

	 /* toss the data */
	 free(Vocab900);
    return TRUE;
}
/******************************************************************************/
BOOL LoadVocab996()
{
	BYTE *buf;
	long FileLen,Offset;

	TotalGlobalClasses = 0;
    FirstSameScript = -1;

	/* Open vocab.996 for reading */
    FileLen=dirlist_resload(idVOCAB, 996, &buf);
	if(FileLen==0) {
		if((Vocab996 = (int *) calloc(32,sizeof(int)))==NULL)
		{
			ShowMessage(smERROR,"Unable to allocate vocab.996 buffer!");
			return FALSE;
		}
		OldGlobalClasses=0;
		return TRUE;
	}
    if(FileLen==-1) {
		ShowMessage(smERROR,"Invalid SCI header in vocab.996!");
		return FALSE;
    }

   /* leeway for 32 new classes */
   if((Vocab996 = (int *) calloc((FileLen>>2)+32,sizeof(int)))==NULL)
   {
			ShowMessage(smERROR,"Unable to allocate vocab.996 buffer!");
			return FALSE;
   }
   Offset = 0;
	while(Offset<FileLen) {
        Vocab996[TotalGlobalClasses] = buf[Offset+2]+(buf[Offset+3]<<8);
        if(FirstSameScript==-1&&Vocab996[TotalGlobalClasses]==ScriptNumber)
            FirstSameScript = TotalGlobalClasses;
        TotalGlobalClasses++;
        Offset += 4;
	}
	free(buf);

    OldGlobalClasses=TotalGlobalClasses;

	return TRUE;
}
/******************************************************************************/
BOOL WriteVocab996()
{
	BYTE *buf;
    long fileLen,i;
    int j;

    /* No update needed? */
    if(OldGlobalClasses==TotalGlobalClasses) return TRUE;

	buf = (BYTE*) calloc(TotalGlobalClasses,4);
    fileLen = TotalGlobalClasses<<2;
    j=0;
	for(i=0;i<fileLen;i+=4) {
	    buf[i+2] = Vocab996[j]&0xFF;
	    buf[i+3] = Vocab996[j]>>8;
        j++;
	}

	/* Open vocab.996 for reading */
	if(dirlist_ressave(idVOCAB, 996, buf, fileLen)==NULL) {
        ShowMessage(smWARNING,"Unable to write file: vocab.996! File skipped.");
		free(buf);
		return TRUE;
	}

	free(buf);

	return TRUE;
}
/******************************************************************************/
int GetNextFreeClassIndex()
{
    int i, RetVal = FirstSameScript;

    if(FirstSameScript!=-1) {
        for(i = FirstSameScript+1; i < TotalGlobalClasses; i++)
            if(Vocab996[i]==ScriptNumber) {
                FirstSameScript = i;
                return RetVal;
            }
        FirstSameScript = -1;
        return RetVal;
    }
    FirstSameScript = -1;
    Vocab996[TotalGlobalClasses]=ScriptNumber;
    TotalGlobalClasses++;
    return(TotalGlobalClasses-1);
}                    
/******************************************************************************/
BOOL LoadVocab997()
{
	BYTE *buf;
	WORD CurrentSelector, StringLength;
    long Offset,FileLen;
	/* Open vocab.997 for reading */

    FileLen=dirlist_resload(idVOCAB, 997, &buf);
	if(FileLen==0) {
    	TotalSelectorNames = 0;
        MaxSelectorNames = 64;
        SelectorNames = (char **) calloc(MaxSelectorNames,sizeof(char *));
        return TRUE;
	}
    if(FileLen==-1) {
		ShowMessage(smERROR,"Invalid SCI header in vocab.997!");
		return FALSE;
    }

	TotalSelectorNames = ( (buf[0]+(buf[1]<<8))  + 1) & 0xFFFF;
    MaxSelectorNames = TotalSelectorNames+64;
	SelectorNames = (char **) calloc(MaxSelectorNames, sizeof(char *));

	for(CurrentSelector = 0; CurrentSelector < TotalSelectorNames; CurrentSelector++) {
		/* Get the string offset and seek to it */
		Offset = (CurrentSelector << 1) + 2;
        Offset = buf[Offset]+(buf[Offset+1]<<8);

		/* Get the length */
		StringLength = buf[Offset]+(buf[Offset+1]<<8);
		Offset+=2;
		SelectorNames[CurrentSelector] = (char *) calloc(1, StringLength + 1);
		memcpy(SelectorNames[CurrentSelector], buf+Offset, StringLength);
	}
	free(buf);
	return TRUE;
}
/******************************************************************************/
BOOL WriteVocab997()
{
	BYTE *buf;
	int i, Offs, strLen;

    /* No update needed? */
    if(TotalSelectorNames==MaxSelectorNames-64) return TRUE;

	buf = (BYTE*) malloc((unsigned short) 65535u );
    buf[0]=(TotalSelectorNames-1)&0xFF;
    buf[1]=(TotalSelectorNames-1)>>8;

    Offs=(TotalSelectorNames<<1)+2;

	for(i=0;i<TotalSelectorNames;i++) {
    	buf[(i<<1)+2] = Offs&0xFF;
    	buf[(i<<1)+3] = Offs>>8;

        strLen = strlen(SelectorNames[i]);
    	buf[Offs  ] = (strLen)&0xFF;
    	buf[Offs+1] = (strLen)>>8;
        Offs+=2;
        memcpy(buf+Offs,SelectorNames[i],strLen);
        Offs+=strLen;
	}

	/* write vocab.997 */
	if(dirlist_ressave(idVOCAB, 997, buf, Offs)==NULL) {
        ShowMessage(smWARNING,"Unable to write file: vocab.997! File skipped.");
		free(buf);
		return TRUE;
	}

	free(buf);
	return TRUE;
}
/******************************************************************************/
BOOL WriteVocab999()
{
	FILE *Vocab997;
	int i, Offs;

	/* Open vocab.997 for reading */
	if((Vocab997=dirlist_open(game_dir,"vocab.999","wb"))==NULL) {
        ShowMessage(smWARNING,"Unable to write file: %s. File skipped.", TempString);
		return TRUE;
	}

    /* header */
	fwrite("\x86\0",2,1,Vocab997);
    fputc((TotalKernels-1)&0xFF,Vocab997);
    fputc((TotalKernels-1)>>8,Vocab997);
    fseek(Vocab997,TotalKernels<<1,SEEK_CUR);

	for(i=0;i<TotalKernels;i++) {
		  Offs = (WORD) ftell(Vocab997);
        fseek(Vocab997,(i+2)<<1,SEEK_SET);
        fputc((Offs-2)&0xFF,Vocab997);
        fputc((Offs-2)>>8,Vocab997);
        fseek(Vocab997,Offs,SEEK_SET);

        Offs = strlen(KernelNames[i]);
        fputc((Offs)&0xFF,Vocab997);
        fputc((Offs)>>8,Vocab997);

	    fwrite(KernelNames[i],Offs,1,Vocab997);
	}
	fclose(Vocab997);
	return TRUE;
}
/******************************************************************************/
int  AddSelectorName(char *String)
{
    if(MaxSelectorNames==TotalSelectorNames) return -1;

    SelectorNames[TotalSelectorNames]=(char*)malloc(strlen(String)+1);
    strcpy(SelectorNames[TotalSelectorNames],String);
    TotalSelectorNames++;
    return (TotalSelectorNames-1);
}          
/******************************************************************************/
BOOL LoadVocab999()
{
	WORD i, StringLength;
    long Offset,FileLen;
	/* Open vocab.999 for reading */

    FileLen=dirlist_resload(idVOCAB, 999, (BYTE**)&KernelNamesBuf);
	if(FileLen==0) {
		ShowMessage(smERROR,"Unable to load file: vocab.999!");
		return FALSE;
	}
    if(FileLen==-1) {
		ShowMessage(smERROR,"Invalid SCI header in vocab.999!");
		return FALSE;
    }         /*
#ifndef SCI1MODE
	TotalKernels = ( (KernelNamesBuf[0]+(KernelNamesBuf[1]<<8))  + 1) & 0xFFFF;
	KernelNames = (char **) calloc(TotalKernels, sizeof(char *));

	for(i = 0; i < TotalKernels; i++) {
		/* Get the string offset and seek to it */  /*
		Offset = (i << 1) + 2;
        Offset = KernelNamesBuf[Offset]+(KernelNamesBuf[Offset+1]<<8);

		/* Get the length */      /*
		StringLength = KernelNamesBuf[Offset]+(KernelNamesBuf[Offset+1]<<8);
        KernelNames[i] = KernelNamesBuf+Offset;
        memcpy(KernelNames[i],KernelNamesBuf+Offset+2,StringLength);
        KernelNames[i][StringLength] = '\0';
	}
#else   */
	TotalKernels=0;
 	for(Offset = 0; Offset < FileLen; Offset++)
		if(KernelNamesBuf[Offset]=='\0')
        	TotalKernels++;
	KernelNames = (char **) calloc(TotalKernels, sizeof(char *));

    Offset=0;
	for(i = 0; i < TotalKernels; i++) {
        KernelNames[i] = KernelNamesBuf+Offset;
        Offset += strlen(KernelNames[i])+1;
	}     /*
#endif   */
	return TRUE;
}
/******************************************************************************/

/***************************************************************************
 *  Copyright (C) 1999-2001 Brian Provinciano, http://www.bripro.com
 ***************************************************************************/

