/***************************************************************************
 *  SCI Studio: SCI Script Compiler
 *  Copyright (C) 2001-2004 Brian Provinciano, http://www.bripro.com
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
 *  Copyright (C) 2001-2004 Brian Provinciano, http://www.bripro.com
 ***************************************************************************/
 /******************************************************************************
 * SCI Script Compiler Win32 Shell
 * Created: 	April 9th, 2001
 * Modified: 	September 29th, 2004
 ******************************************************************************/
#define PLATFORM_NAME "Win32"

#include "scc.h"
#include <conio.h>
/******************************************************************************/

typedef struct {

	short Script;


	char *Name;
} tsSCRIPTNAMES;






tsSCRIPTNAMES CompileOrder[] = {
	/*{-1, "rm100"},*/
	/*{-1, "rm101"},*/
	{-1, "main"},
	{-1, "init"},
	{-1, "932"},
	{-1, "982"},
	{-1, "about"},
	{-1, "block"},
	{-1, "borderwnd"},
	{-1, "chase"},
	{-1, "controls"},
	{-1, "cycle"},
	{-1, "dcicon"},
	{-1, "disposecode"},
	{-1, "disposeload"},
	{-1, "ego"},
	{-1, "egosprays"},
	{-1, "feature"},
	{-1, "features"},
	{-1, "fwdcounter"},
	{-1, "game"},
	{-1, "gamecontrols"},
	{-1, "grooper"},
	{-1, "iconbar"},
	{-1, "inv"},
	{-1, "inventory"},
	{-1, "jump"},
	{-1, "mcycle"},
	{-1, "obj"},
	{-1, "osc"},
	{-1, "pchase"},
	{-1, "polygon"},
	{-1, "polypath"},
	{-1, "pseudomouse"},
	{-1, "randcycle"},
	{-1, "rev"},
	{-1, "room"},
	{-1, "sound"},
	{-1, "speedtest"},
	{-1, "stopwalk"},
	{-1, "syswindow"},
	{-1, "titlescreen"},
	{-1, "user"},
	{-1, "wander"},
	{-1, "window"},
    {-1, ""},
};
#define DIRECTORY "G:\\scigames\\vgadev\\"
#define SRC_DIRECTORY "G:\\scigames\\vgadev\\src\\"
int main(int argc, char *argv[])
{
	int i;
    tsSCRIPTNAMES *sn;

	printf(
		"SCI Script Compiler\n"
		"Version %d.%d.%d - (%s)\n"
		"By Brian Provinciano\n\n",
		VERSION.Major,VERSION.Minor,VERSION.Build,
		PLATFORM_NAME
	);          /*
	if(argc < 2) {
	    printf(
		    "\nUseage:\n"
		    "SCC [input.sc] [gamedirectory]\n"
	    );
		return FALSE;
	} else if(argc > 2) strcpy(Directory,argv[2]);
	else */
                                            /*
    lib_dirs=dirlist_add(lib_dirs,Directory);
    include_dirs=dirlist_add(include_dirs,Directory);
    include_dirs=dirlist_add(output_dir,Directory);         */
    include_dirs=dirlist_add(include_dirs,"E:\\programming\\SCIStudio3\\Bin\\include");
    lib_dirs=dirlist_add(lib_dirs,SRC_DIRECTORY);
   	game_dir=dirlist_add(game_dir,DIRECTORY);
    source_dir=dirlist_add(source_dir,SRC_DIRECTORY);
    include_dirs=dirlist_add(include_dirs,SRC_DIRECTORY);

	/* Compile the script */
    sn = CompileOrder;
    while(sn->Name[0]) {
        sprintf(TempString,"%s%s.sc",SRC_DIRECTORY,sn->Name);
		ShowMessage(0,"\nCompiling File: %s...\n", TempString);
		if(CompileScript(TempString,-1)) ShowMessage(smCOMPILE,"Successful!");
		else {                        /*
    for(i=0;i<TOTAL_FILES;i++) {
        sprintf(TempString,"%s",FileList[i]);
		ShowMessage(0,"\nCompiling File: %s...\n", TempString);
		if(CompileScript(TempString)) ShowMessage(smCOMPILE,"Successful!");
		else {            */
    		ShowMessage(smCOMPILE,"Failed!");
        	getch();
    	}
		FreeEverything();
        sn++;
    }             
    dirlist_free(lib_dirs);
    dirlist_free(include_dirs);  
    dirlist_free(game_dir);
    dirlist_free(source_dir);


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
 *  Copyright (C) 1999-2004 Brian Provinciano, http://www.bripro.com
 ***************************************************************************/
