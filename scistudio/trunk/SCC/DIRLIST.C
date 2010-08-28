/***************************************************************************
 *  SCI Studio: SCI Script Compiler
 *  Copyright (C) 2001 Brian Provinciano, http://www.bripro.com,
 *                     Christoph Reichenbach
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
#include "scc.h"
/******************************************************************************/
#ifdef SCC_SCISTUDIO_WIN32
#pragma hdrstop
#pragma package(smart_init)
#endif
/******************************************************************************/

directory_list_t *game_dir, *source_dir, *lib_dirs, *include_dirs;

directory_list_t *
dirlist_add(directory_list_t *list, char *dir)
{
	directory_list_t *entry = (directory_list_t*) calloc(sizeof(directory_list_t),1);

	entry->dir = (char*) malloc(strlen(dir)+1);
    strcpy(entry->dir,dir);
	entry->next = NULL;

	if (!list) {
		entry->top = entry;
		return entry;
	} else {
		list->top->next = entry;
		list->top = entry;
		return list;
	}
}

FILE *
_dirlist_open_file(directory_list_t *list, char *file, int filelen, char *access, char *wd)
{
	FILE *f;

	if (!list) {
/*    	ShowMessage(smERROR,"Unable to open file: %s!",file);   */
		return NULL;
    }

	if (list->dir) {
		if (filelen + strlen(list->dir) + 1 < PATH_MAX) {
			wd = strncpy(wd, list->dir, PATH_MAX-1);
			if(strcmp(list->dir+strlen(list->dir)-1,PATH_SEPARATOR)!=0)
            	strcat(wd, PATH_SEPARATOR);
			strcat(wd, file);

			if ((f = (FILE*)fopen(wd, access))!=NULL)
				return f;
		}

	}
	return _dirlist_open_file(list->next, file, filelen, access, wd);
}


FILE *
dirlist_open(directory_list_t *list, char *file, char *access)
{
	char wfile[PATH_MAX + 1];
	int filelen = strlen(file);

	if (!list)
		return fopen(file, access);
	return _dirlist_open_file(list, file, filelen, access, wfile);
}


void
dirlist_free(directory_list_t *list)
{
	if (list) {
        if(list->dir)
            free(list->dir);
        list->dir=NULL;
		dirlist_free(list->next);
		free(list);
        list=NULL;
	}
}






/* The following are used in both decryption algorithms: */
#define MAXBIT 0x2000
unsigned int whichbit;
BYTE bits[0x403];

#define STACKSIZE 1024
char stack[STACKSIZE];
int stackptr;
/*****************  Decryption Method 1  *******************************/
BYTE *inData;
unsigned int getbits1(int numbits) /* handles bitstrings length 9-12 */
{
  int place;
  unsigned long bitstring;
  if (whichbit >= MAXBIT) {
    whichbit -= MAXBIT;
   	memcpy(bits,inData,0x403);
    inData+=0x400;
  }
  place = whichbit >> 3;
  bitstring = bits[place] | (long)(bits[place+1])<<8
	      | (long)(bits[place+2])<<16;
  bitstring >>= (whichbit & 7);
  bitstring &= 0xffffffffUL >> (32-numbits);
  whichbit += numbits;
  return bitstring;
}

void push(char c) {
  stack[stackptr++] = c;
  if (stackptr >= STACKSIZE) {
    ShowMessage(smERROR,"Stack overflow");
/*    exit(1);  */
  }
}
char *popall(char *dest) {
  while (stackptr-- > 0) *(dest++) = stack[stackptr];
  stackptr++;
  return dest;
}

void decryp1(char *data)
{
  WORD field, linkindex = 0x102, nextindex = 0, newindex = 0,
      maxindex = 0x200, width = 9;
  BYTE *links, lastbyte=0, linkbyte=0;
  links = (BYTE*)malloc(12300);
  whichbit = MAXBIT;
  stackptr = 0;
  while ((field = getbits1(width)) != 0x101) { /* exit on 0x101 */
    if (field == 0x100) { /* start over from beginning of table */
      linkindex = 0x102;
      width = 9;
      maxindex = 0x200;
      nextindex = field = getbits1(width);
      *(data++) = lastbyte = linkbyte = (field & 0xff);
    }
    else {
      newindex = field;
      if (field >= linkindex) { /* if it's a forward reference, */
	push(lastbyte);         /* repeat the last thing */
	field = nextindex;
      }
      while (field > 0xff) { /* trace links back */
	push(links[field*3+2]);
	field = (int)(links[field*3]) | (int)(links[field*3+1]) << 8;
      }
      lastbyte = linkbyte = field;
      push(lastbyte);
      data = popall(data);
      links[linkindex*3+2] = linkbyte;
      links[linkindex*3+1] = nextindex >> 8;
      links[linkindex*3+0] = nextindex & 0xff;
      linkindex++;
      nextindex = newindex;
      if (linkindex >= maxindex && width != 12) {
	width++;
	maxindex <<= 1;
      }
    }
  }
  free(links);
}

/*****************  Decryption Method 2  *******************************/
/*This is basically byte-token huffman coding, except that a prefix of
  1 signals a literal byte. In fact, most bytes are literal; only extremely
  common ones are put in the huffman tree. */

char getbits2(int numbits) /* handles bitstrings length 1-8 */
{
  int bitstring, place;
  if (whichbit >= MAXBIT) {
    whichbit -= MAXBIT;
    memcpy(bits, inData, 0x403);
    inData+=0x400;
  }
  place = whichbit >> 3;
  bitstring = bits[place] << 8;
  bitstring |= bits[place+1] & 0x00ff;
  bitstring >>= 16-numbits-(whichbit & 7);
  bitstring &= 0xffffu >> (16-numbits);
  whichbit += numbits;
  return bitstring;
}

int getc2(unsigned char *node)
{
  int next;
  while (node[1] != 0) {
    if (getbits2(1)) {
      next = node[1] & 0xf; /* low 4 bits */
      if (next == 0) return (getbits2(8) | 0x100);
    }
    else next = node[1] >> 4; /* high 4 bits */
    node += next*2;
  }
  return (int)*node;
}

void decryp2(char *data)
{
  BYTE numnodes, terminator;
  char *nodes;
  int c;
  numnodes = *inData++;
  terminator = *inData++;
  nodes = (char *) malloc(2*numnodes);
  memcpy(nodes, inData, 2*numnodes);
  whichbit = MAXBIT;
  while ((c = getc2(nodes)) != (0x0100 | terminator)) {
    *data = (char)c;
    data++;
  }
  free(nodes);
}






long
dirlist_resload(int Type, int Number, BYTE **buf)
{
	FILE *f,*fMap,*fPack;
    int mapLen,pack;
    unsigned short identInfo,encLen,decLen,encMethod;
    unsigned long packInfo,offs;
    BYTE *encData;

    sprintf(TempString,"%s.%03d",ResNames[Type&0xF],Number);
    f=dirlist_open(game_dir, TempString, "rb");

/* it's going to try to extract it from the package */
#ifndef SCI1MODE
	if(!f) {
		if((fMap=dirlist_open(game_dir, "resource.map", "rb"))==NULL)
        	return 0;
    	fseek(fMap,0,SEEK_END);
        mapLen=ftell(fMap);
    	fseek(fMap,0,SEEK_SET);
		Type&=0x0F;
        while(ftell(fMap)<mapLen) {
            identInfo = fgetc(fMap)+(fgetc(fMap)<<8);
            if(	(BYTE)(((identInfo >> 11) & 0x1F) == (BYTE)(Type))
             && ((WORD)((identInfo & 0x7FF)) == (WORD) Number)) {
            	packInfo = fgetc(fMap)+(fgetc(fMap)<<8)+(fgetc(fMap)<<16)+(fgetc(fMap)<<24);
            	pack = (char) (packInfo >> 26);
            	offs = (unsigned long) (packInfo & 0x03FFFFFFul);
                fclose(fMap);
    			sprintf(TempString,"resource.%03d",pack);
                if((fPack=dirlist_open(game_dir, TempString, "rb"))==NULL)
        			return 0;

                fseek(fPack,offs+2,SEEK_SET);
                encLen =
                	fgetc(fPack)+(fgetc(fPack)<<8)-4;
                decLen =
                	fgetc(fPack)+(fgetc(fPack)<<8);
                encMethod =
                	fgetc(fPack)+(fgetc(fPack)<<8);
    			if((encData=(BYTE*)malloc(encLen))==NULL) {
                	fclose(fPack);
                    return 0;
                }
  				fread(encData,encLen,1,fPack);
                fclose(fPack);

    			whichbit = 0;

                if((*buf=(BYTE*)malloc(decLen))==NULL) {
                	free(encData);
                    return 0;
                }
                switch(encMethod) {
                	case 0:
                        memcpy(*buf,encData,decLen);
                    	break;
                    case 1:
                    	inData = encData;
                        decryp1(*buf);
                    	break;
                    case 2:
                    	inData = encData;
                        decryp2(*buf);
                    	break;
                    default:
                    	return 0;
                }
             	free(encData);
                break;
			} else fseek(fMap,4,SEEK_CUR);
        }
        if(ftell(fMap)>=mapLen) {
        	fclose(fMap);
       		return 0;
        }
	} else {
#else
	if(!f) return 0;
#endif
        if(fgetc(f)!=Type||fgetc(f)!=0)
        	return -1;
    	fseek(f,-2,SEEK_END);
    	decLen = ftell(f);
    	fseek(f,2,SEEK_SET);
        if((*buf=(BYTE*)malloc(decLen))==NULL) {
        	fclose(f);
        	return 0;
        }
        fread(*buf,decLen,1,f);
        fclose(f);
#ifndef SCI1MODE
    }
#endif

	return decLen;
}


BOOL
dirlist_ressave(int Type, int Number, BYTE *buf, long BufLen)
{
	FILE *f,*fMap,*fPack;
    BYTE *mapBuf;
    BOOL REPLACING_RESOURCE=FALSE;
    int mapLen;
    unsigned short identInfo, pack, encLen;
    unsigned long packInfo,offs,packLen;

	if(ResPackage==-1) {  
#ifdef SCI1MODE
            sprintf(TempString,"%d.%s",Number,ResNamesShort[Type&0xF]);
#else
            sprintf(TempString,"%s.%03d",ResNames[Type&0xF],Number);
#endif
    	if((f=dirlist_open(game_dir, TempString, "wb"))==NULL)
        	return FALSE;
        fputc(Type,f);
        fputc(0,f);
		fwrite(buf,BufLen,1,f);
        fclose(f);
        return TRUE;
    }

    if((fMap=dirlist_open(game_dir, "resource.map", "rb"))==NULL)
    	return FALSE;
	fseek(fMap,0,SEEK_END);
    mapLen=ftell(fMap);
    fseek(fMap,0,SEEK_SET);
	if((mapBuf=(BYTE*)malloc(mapLen))==NULL) {
    	fclose(fMap);
    	return FALSE;
    }
    fread(mapBuf,mapLen,1,fMap);
    fclose(fMap);

    sprintf(TempString,"resource.%03d",ResPackage);
    if((fPack=dirlist_open(game_dir, TempString, "rb+"))==NULL) {
    	free(mapBuf);
		return FALSE;
    }

    identInfo = mapBuf[0]+(mapBuf[1]<<8);
    packInfo = mapBuf[2]+(mapBuf[3]<<8)+(mapBuf[4]<<16)+(mapBuf[5]<<24);
    pack = (char) (packInfo >> 26);

    offs = (unsigned long) (packInfo & 0x03FFFFFFul);
    if(	(pack==ResPackage) &&
    	((BYTE)(((identInfo >> 11) & 0x1F) == (BYTE)(Type&0xF))) &&
     	(((WORD)((identInfo & 0x7FF)) == (WORD) Number))) {
		fseek(fPack,0,SEEK_END);
    	packLen=ftell(fPack);
    	fseek(fPack,0,SEEK_SET);
    	fseek(fPack,offs+2,SEEK_SET);
        encLen = fgetc(fPack)+(fgetc(fPack)<<8);
        if((WORD)(ftell(fPack)+encLen)==(WORD)packLen) {
    		fseek(fPack,offs,SEEK_SET);
            REPLACING_RESOURCE = TRUE;
        } else {
    		fseek(fPack,0,SEEK_END);
        	offs = ftell(fPack);
        }
    } else {
    	fseek(fPack,0,SEEK_END);
    	offs = ftell(fPack);
    }

	identInfo = (Type<<11)|(Number&0x7FF);
    fputc(identInfo&0xFF,fPack);
    fputc(identInfo>>8,fPack);
    fputc((BufLen+4)&0xFF,fPack);
    fputc((BufLen+4)>>8,fPack);
    fputc(BufLen&0xFF,fPack);
    fputc(BufLen>>8,fPack);
    fputc(0,fPack);
    fputc(0,fPack);
    fwrite(buf,BufLen,1,fPack);
    fclose(fPack);
                     
	packInfo = (ResPackage<<26)|(offs&0x03FFFFFFul);

    if(!REPLACING_RESOURCE) {
    	if((fMap=dirlist_open(game_dir, "resource.map", "wb"))==NULL) {
    		free(mapBuf);
    		return FALSE;
        }
        fputc(identInfo&0xFF,fMap);
        fputc(identInfo>>8,fMap);
        fputc(packInfo&0xFF,fMap);
        fputc((packInfo>>8)&0xFF,fMap);
        fputc((packInfo>>16)&0xFF,fMap);
        fputc((packInfo>>24)&0xFF,fMap);   
    	fwrite(mapBuf,mapLen,1,fMap);
    }

    free(mapBuf);
    fclose(fMap);

	return TRUE;
}



