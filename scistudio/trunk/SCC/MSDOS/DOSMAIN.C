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
 * SCI Script Compiler Win32 Shell
 * Created: 	April 9th, 2001
 * Modified: 	May 11th, 2002
 ******************************************************************************/
#define PLATFORM_NAME "MS-DOS"

#include "scc.h"
/******************************************************************************/
/*char *FileList[] = {
	"D:\\sci\\game\\obj.sc",
	 "D:\\sci\\game\\game.sc",
	 "D:\\sci\\game\\main.sc",
	 "D:\\sci\\game\\menubar.sc",
	 "D:\\sci\\game\\controls.sc",
};
#define TOTAL_FILES 5
#define DIRECTORY "D:\\sci\\game\\"  */
int main(int argc, char *argv[])
{
	printf(
		"SCI Script Compiler\n"
		"Version %d.%d.%d - (%s)\n"
		"By Brian Provinciano\n\n",
		VERSION.Major,VERSION.Minor,VERSION.Build,
		PLATFORM_NAME
	);
	if(argc < 2) {
		 printf(
			 "\nUseage:\n"
			 "SCC [input.sc] [gamedirectory]\n"
		 );
		return FALSE;
	} else {
		if(argc > 2) strcpy(Directory,argv[2]);
		else strcpy(Directory,".\\");
	 }

	if(strcmp(Directory,".\\")!=0) {
		lib_dirs=dirlist_add(lib_dirs,".\\");
		include_dirs=dirlist_add(include_dirs,".\\");
	 }
	 lib_dirs=dirlist_add(lib_dirs,Directory);
	 include_dirs=dirlist_add(include_dirs,Directory);
	 output_dir=dirlist_add(output_dir,Directory);

	 if(CompileScript(argv[1]))
    	ShowMessage(smCOMPILE,"Successful!");
	else
    	ShowMessage(smCOMPILE,"Failed!");

    FreeEverything();
    dirlist_free(lib_dirs);
    dirlist_free(output_dir);
    dirlist_free(include_dirs);

	return TRUE;
}
/******************************************************************************/
int ShowMessage(int Message, char *String, ...)
{
	va_list argptr;
	int cnt;
	if(Message!=smAPPEND) printf("\n");
	switch(Message) {
		case smNONE:
			break;
		case smERROR:
			printf("[Error]: ");
			break;
		case smWARNING:
			printf("[Warning]: ");
			break;
		case smCOMPILE:
			printf("[Compile]: ");
			break;
		  case smAPPEND:
			break;
		default:
			printf("[Error]: %s(%d): ", IN_HEADER?IncludeFileName:ScriptName, LineNumber);

			 va_start(argptr, String);
			 cnt = vprintf(Errors[Message], argptr);
			 va_end(argptr);
	};
	if(Message<1) {
		va_start(argptr, String);
		cnt = vprintf((char*)String, argptr);
		va_end(argptr);
	}

	return(cnt);
}
/******************************************************************************/

/***************************************************************************
 *  Copyright (C) 1999-2001 Brian Provinciano, http://www.bripro.com
 ***************************************************************************/
