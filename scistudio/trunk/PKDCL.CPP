/*****************************************************************************************

PKWDCL unpacker, part of VAG's SCI Tools - Implementation of PKWare's DCL decompression
Copyright (C) 2002  VAG

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Any your applications which uses any part of this source(s) SHOULD BE also
distributed with FREELY AVAILABLE source code. Also, you should include my
name in the source and binary file(s) of your application.
Please, do not remove this banner, it must be included in any source based
on this one. Thanks.

Fell free to contact with author at vagsoft@mail.ru

*****************************************************************************************/
/*
     This is a remake of `PKWare Data Compression Libaray (tm)` explode algo.
   Written totally by jcxz's whitepaper, great thanks for excellent research,
   man! Code is quite simple, but can be speed-up by optimizing btree walking.
   TODO: Reimplement as a class to support multithreading.
        **** Please inform me if you found any bugs here, thanks! ****

  File created:  VAG, 21 jul 2001  Initial version
*/

#include "stdafx.h"
#include "pkdcl.h"
#include "pkdcltrees.h"

//Report about unpacking problems
#define SELFDEBUG

#define getbits(bits)     _getbits(pksrcbuf,bits,pksrcidx)
#define readbits(bits)    _readbits(pksrcbuf,bits,pksrcidx)

void *pksrcbuf,*pkdstbuf;
unsigned long pksrcidx,pkdstidx;

unsigned long _getbits(void *buf,int numbits,unsigned long &idx)
{
	unsigned long bytpos=idx/8;
	unsigned long bitpos=idx%8;
	unsigned char *b=&((unsigned char*)buf)[bytpos];
	unsigned long bb=*(unsigned long*)b;
	bb>>=bitpos;
	if(numbits!=32)
		bb&=(1<<numbits)-1;
	idx+=numbits;
	return bb;
}

unsigned long _readbits(void *buf,int numbits,unsigned long &idx)
{
	unsigned long tmpidx=idx;
	return _getbits(buf,numbits,tmpidx);
}

unsigned long getnode(NODE *tree,int maxbits)
{
    unsigned long result=-1;
    unsigned long allbits=readbits(maxbits); //maximum possible bits in token
    while(tree->len!=-1)
    {
        int bitlen=tree->len;
        unsigned long bits=allbits&((1<<bitlen)-1);
        while(tree->len==bitlen)
        {
             if(tree->path==bits)
             {
                 result=tree->value;
                 getbits(bitlen);     //discard found bits
                 break;
             }
             tree++;
        }
        if(result!=-1)
            break;
    }
    return result;
}

/*
	Unpack p to u, return actual unpacked data size.
*/
unsigned long dcl_unpack(void *p,void *u)
{

	char *s=(char *)p;
	char *d=(char *)u;

#ifdef SELFDEBUG
    if(s[0]>1)
        printf("PKWDCLUnp: Strange flexflag\n");
    if((s[1]<4)||(s[1]>6))
        printf("PKWDCLUnp: Strange dictionary size\n");
#endif

	int flexliteral=*s++;     //ASCII-compression, accroding to DCL documentation
	int windowbits=*s++;

	pksrcbuf=(void*)s;
	pkdstbuf=(void*)d;
	pksrcidx=pkdstidx=0;

	do
	{
		if(getbits(1)==0)
		{												//literal token
			if(flexliteral==0)
				*d++=(char)getbits(8);
			else
			{
				unsigned long lit=getnode(literals,13);
				if(lit==-1)
				{ 
#ifdef SELFDEBUG
					printf("PKWDCLUnp: Unknown literal\n");
#endif
					break;
				}
				else
					*d++=(char)lit;
			}
		}
		else
		{
			unsigned long len=getnode(lengths,7);
			if(len==-1)
			{
#ifdef SELFDEBUG
				printf("PKWDCLUnp: Unknown lenght code\n");
#endif
				break;
			}
			else
				len=(len&0xFFF)+getbits((len>>12)&0xF); //12bit base+4bit extra
			if(len==519)
				break;									//End of stream
			long ofs=getnode(distances,8);
			if(ofs==-1)
			{
#ifdef SELFDEBUG
				printf("PKWDCLUnp: Unknown distance code\n");
#endif
				break;
			}
			if(len==2)
				ofs=(ofs<<2)|getbits(2);
			else
				ofs=(ofs<<windowbits)|getbits(windowbits);
			// Done with fetching dist/len, now copy data from dictionary
			char *dic=&d[-ofs-1];
#ifdef SELFDEBUG
			if(dic<u)
			{
				printf("PKWDCLUnp: Dictionary underflow\n");
				break;
			}
#endif
			while(len--)
				*d++=*dic++;
		}
	}
	while(1);
	return (long)(d)-(long)(u);
}
