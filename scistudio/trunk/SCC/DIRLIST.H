/***************************************************************************
 *  SCI Studio: SCI Script Compiler
 *  Copyright (C) 2001 Brian Provinciano, http://www.bripro.com,
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
#ifndef _DIRLIST_H
#define _DIRLIST_H
/******************************************************************************/
/* Directory lists */

#ifndef PATH_MAX
#  define PATH_MAX 1024
#endif

#if (defined(SCC_MSDOS) || defined(SCC_WIN32) || defined(SCC_SCISTUDIO_WIN32))
#  define PATH_SEPARATOR "\\"
#else
#  define PATH_SEPARATOR "/"
#endif

typedef struct _directory_list_struct {
	char *dir;
	struct _directory_list_struct *top; /* Needed to append to the end with O(1) */
	struct _directory_list_struct *next;
} directory_list_t;

directory_list_t *
dirlist_add(directory_list_t *list, char *dir);
/* Adds a new directory to a directory list
** Parameters: (directory_list_t *) list: The list to add to (may be NULL)
**             (char *) dir: The directory to add
** Returns   : (directory_list_t *) The resulting directory list
*/

FILE *
dirlist_open(directory_list_t *list, char *file, char *access);
/* Searches through a directory list to find a file
** Parameters: (directory_list_t *) list: The list of directories to search in
**             (char *) file: The file to look for
**             (char *) access: Access mode, as in fopen(3).
** Returns   : (FILE *) A matching FILE * on success, NULL otherwise.
*/

long
dirlist_resload(int Type, int Number, BYTE **buf);
/* Attempts to load/read a resource into the buffer. It checks if the file exists
   loose or in a resource package

   returns the data in buf and the filesize as the return*/

BOOL
dirlist_ressave(int Type, int Number, BYTE *buf, long BufLen);

void
dirlist_free(directory_list_t *list);
/* Frees all memory associated with a directory list
** Parameters: (directory_list_t *) list: The list to free
** Returns   : (void)
*/


/**/
/******************************************************************************/

extern directory_list_t *game_dir, *source_dir, *lib_dirs, *include_dirs;

#endif
