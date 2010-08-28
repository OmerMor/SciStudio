/*****************************************************************************************

SCI resource dumper, part of VAG's SCI Tools - Dumper for Sierra's SCI resources.
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
               SIERRA's SCI Hacking project by VAG at 2001-2002
     This file may contain some information about SCI internals. All such
  information/data formats is discovered by myself and may me wrong/incomplete.
  If you found this file useful or have additional information - please contact
  me, i'll glad to hear your comments.

  File created:  VAG, 19 jul 2002
  Last modified: VAG, 20 jul 2002 - Some cleanups of comments
*/

/*
  About SCI versions
 --------------------

  Due to very long period of SCI usage, engine has been modified several
  times. So, at this moment we know following major modifications (all
  names was taken from FreeSCI community)

  SCI0    -   The first (initial) edition of SCI. Almost reversed by FreeSCI
              team, so i'll not mention it in my specs. All EGA games. 16-bit.
  SCI1    -   The next edition of SCI. Used by all Sierra's VGA games. Core
              engine is still 16-bit.
  SCI32   -   Latest known major edition. Engine core has rewritten in 32-bits,
              almost all resource formats is modified.
  SCIW    -   Windows port of SCI1/32. Actually, available two versions of
              SCIW - SCI1-based (16-bit, only for Windows 3.x) and SCI32-based,
              with Windows 9x support. In this and all my other SCI specs i
              assume SCIW - SCI32.
*/


#pragma pack(1)
// Resource map structures
/*
   General resource map format
---------------------------------

   Resource map is used to quick lookup for resource stored in main
  data volume(s). Actually, volume can be browsed without this map, but
  it will take much longer time to find neccessary resource then.

   Each resource map file has 2 mandatory parts and 1 optional.
  Mandatory parts is the Types directory and the IDs list. Optional part -
  version stamp. Types directory has identical format for both SCI1/SCI32/W
  engines (only resource types is different) , but IDs list formats is different
  (perhaps to support larger volumes?)
  All parts stored in following order:
  <BeginOfFile><TypesDirectory>[VersionStamp]<IDsList><EndOfFile>

   The Types directory contains links to lists of resources of same type -
  all Pic, Views, Scripts, etc.
   The IDs list contains offsets of each resource of same type in main
  volume(s). This list is also sorted by ID's value to allow fast searching
  of resource.

   Version stamp, used to check if resources is compatible with current version
   of interepter. The stamp is just a long integer value + 0x1234, which should
   be the same as interepter has. The Version stamp field present only in main
   resource map file(s). 

   Resource searching algo
-----------------------------

   To find resource of specified type and ID, check the following algo.

  STEP1: Scan Type directory for specified type entry
  STEP2: Get the offset of the IDs list for this type
  STEP3: Get the size of the IDs list (the difference between next list
         offset and current list offset)
  STEP4: While in IDs list, scan for our ID
  STEP5: Retrieve resource offset and (for SCI32/W) - volume number

  NOTE1: If STEP1 or STEP4 has failed - were is no resource in volume(s)
  NOTE2: SCI uses fast implementation of STEP4 by `half-cut` method

*/

// Directory entries for resource map
// For both SCI1 and SCI32/W
// RESOURCE.MAP / RESMAP.*
//
//  Note:
//  Last directory item has 0xFF type, list value is valid and points to the
// end of previous IDs list.
//  Right after 0xFF directory usually stored resources version stamp (long).

typedef struct _RESMAPDIRSCI {
unsigned char  type;               // Type of resources, 0xFF - end of list
unsigned short list;               // Offset of IDs list
} RESMAPDIRSCI, *PRESMAPDIRSCI;
#define RESMAPDIRSCISIZE (sizeof(_RESMAPDIRSCI))

// IDs list entry for resource map
// Valid only for SCI1
// RESOURCE.MAP
//
// Important note!
//  Actually, offset field has 3 bytes. But i expanded it to 4 for easer
// manipulating. This is also caused structure expanding, so always use
// RESMAPIDSSCI1SIZE as proper structure size!
//  Offset is divided by 2, so real_volume_offset=offset*2
//
typedef struct _RESMAPIDSSCI1 {
unsigned short id;                 // ID of resource
unsigned long  offset:24;          // Offset of resource in volume / 2
} RESMAPIDSSCI1, *PRESMAPIDSSCI1;
#define RESMAPIDSSCI1SIZE (sizeof(_RESMAPIDSSCI1)-1)

// IDs list entry for resource map
// Valid only for SCI32
// RESMAP.*
//
// Important note!
//  Probably in some editions of SCI32 few highter bits of offset also
// represents actual resource's volume number. I'm not sure about this, i
// need to recheck it later.
//
typedef struct _RESMAPIDSSCI32 {
unsigned short id;                 // ID of resource
unsigned long  offset;             // Offset of resource in volume
} RESMAPIDSSCI32, *PRESMAPIDSSCI32;
#define RESMAPIDSSCI32SIZE (sizeof(_RESMAPIDSSCI32))

// Resource volume structures
/*
   General resource volume format
------------------------------------

   Resource volume(s) is used as main SCI's data storage. Actually, volume is
  just like an archive of standalone files (not really, but...). Resources in
  volume(s) can be stored in compressed or raw (uncompressed) form. Each
  resource in volume has it's own header (not resource file header!), this
  header contains useful information about resource - it's size, type, etc.
  Resources stored in random order (unlike resource map ID's list).

   As i wrote before, it is not neccessary to use resource map to find
  resource in volume. You just can check each resource header to find
  specified resource. It will take some time, but can be used as `cheap`
  solution. The potential problem is if were are any `holes` between resources.
  But i never seen it, so probabaly everything will works fine.

   For description of packing methods, read notes below

*/

// Resource entry for resource volume(s)
// Valid only for SCI1
// RESOURCE.*
//
// Important notes!
//  Size of data[] is equal paklen.
//  If pakmeth is 0 , data is not compressed. Otherwise, PKDCL compression
// is used.
//
typedef struct _RESVOLENTRYSCI1 {
unsigned char  type;               // Type of resource
unsigned short id;                 // ID of resource
unsigned short paklen;             // Size of packed resource (stored in vol)
unsigned short unplen;             // Size of unpacked resource (actual size)
unsigned short pakmeth;            // Packing method
unsigned char  data[1];            // Packed or raw resource data
} RESVOLENTRYSCI1, *PRESVOLENTRYSCI1;
#define RESVOLENTRYSCI1SIZE (sizeof(_RESVOLENTRYSCI1)-1)

// Resource entry for resource volume(s)
// Valid only for SCI32/W
// RESSCI.*
//
// Important notes!
//  Size of data[] is equal paklen.
//  pakmeth is not checked. To determinate if data is compressed or not,
// compare paklen and unplen. If paklen is less than unplen, data is
// compressed with LZS algo.
//
typedef struct _RESVOLENTRYSCI32 {
unsigned char  type;               // Type of resource
unsigned short id;                 // ID of resource
unsigned long  paklen;             // Size of packed resource (stored in vol)
unsigned long  unplen;             // Size of unpacked resource (actual size)
unsigned short pakmeth;            // Packing method
unsigned char  data[1];            // Packed or raw resource data
} RESVOLENTRYSCI32, *PRESVOLENTRYSCI32;
#define RESVOLENTRYSCI32SIZE (sizeof(_RESVOLENTRYSCI32)-1)


#pragma pack()