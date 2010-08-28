/*****************************************************************************************

LZS unpacker, part of VAG's SCI Tools - Implementation of STAC's LZS decompression
Copyright (C) 2001-2002  VAG

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
   This file contains my implementation of STAC Electronic's LZS unpacking
  algo. Actual algorithm description was taken from RFC1974, p.2.5.5.
   TODO: Reimplement as a class to support multithreading.
        **** Please inform me if you found any bugs here, thanks! ****

  File created: VAG, 17 jul 2001 - Initial implementation
  Was modified: VAG, 20 jul 2002 - Comments, critical bugfix in getlen()
  Was modified: VAG, 21 jul 2002 - Speed optimization
*/
#include "stdafx.h"
#include "lzs.h"

//Report about unpacking problems
#define SELFDEBUG

unsigned char *s,*d;
unsigned long srcpos;

unsigned long getrevbits(int numbits)
{
//up to 16 bits at once
	unsigned long result=0;
	if(numbits>0)
	{
		int bytpos=srcpos/8;
		int bitpos=srcpos%8;
		result=(s[bytpos]<<16)|(s[bytpos+1]<<8)|s[bytpos+2];
		result=(result>>(24-numbits-bitpos))&((1L<<numbits)-1);
		srcpos+=numbits;
	}
	return result;
}

int getlen(void)
{
	int bits;
	int length=2;
	do
	{
		bits=getrevbits(2);
		length+=bits;
	}
	while((bits==3)&&(length<8));

	if(length==8)
		do
		{
			bits=getrevbits(4);
			length+=bits;
		}
		while(bits==15);

	return length;
}

/*
	Unpack p to u, return actual unpacked data size.
*/
unsigned long lzs_unpack(void *p,void *u)
{
	s=(unsigned char*)p;
	d=(unsigned char*)u;

	srcpos=0;

	do
	{
		int tag=getrevbits(1);
		if(tag==0)					// Uncompressed byte
			*d++=(unsigned char)getrevbits(8);
		else						// Chain
		{
			int ofs;
			tag=getrevbits(1);
			if(tag==1)				// 7-bit offset or END
			{
				ofs=getrevbits(7);
				if(ofs==0)			// END of stream
					break;
			}
			else					// 11-bit offset
				ofs=getrevbits(11);
			int len=getlen();
			unsigned char *dic=&d[-ofs];
			if(dic<u)
			{
#ifdef SELFDEBUG
				printf("LZSUnp: Dictionary underflow\n");
#endif
				break;
			}
			while(len--)
				*d++=*dic++;
		}
	}
	while(1);						//Until breaked

	return (long)d-(long)u;
}
