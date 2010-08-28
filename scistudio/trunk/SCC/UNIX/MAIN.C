/***************************************************************************
 *  SCI Studio: SCI Script Compiler (UNIX main file)
 *  Copyright (C) 2001 Brian Provinciano, http://www.bripro.com,
 *                     Christoph Reichenbachx
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

#include <getopt.h>
#include "../scc.h"

/* ShowMessage is essentially the same as for the DOS version, in order not
** to break compatibility -- CR */
int ShowMessage(int Message, char *String, ...)
{
	va_list argptr;
	int cnt = 0;
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


#define OPTIONS_STRING "hvI:L:o:"

#ifdef HAVE_GETOPT_LONG
#  define EXPLAIN_OPTION(longopt, shortopt, description) "  " longopt "\t" shortopt "\t" description "\n"
#  define NEXT_OPTION getopt_long(argc, argv, OPTIONS_STRING, options, &optindex)
#else /* !HAVE_GETOPT_LONG */
#  define EXPLAIN_OPTION(longopt, shortopt, description) "  " shortopt "\t" description "\n"
#  define NEXT_OPTION getopt(argc, argv, OPTIONS_STRING)
#endif /* !HAVE_GETOPT_LONG */

#ifdef HAVE_GETOPT_LONG
static struct option options[] = {
	{"include-path", required_argument, 0, 'I'},
	{"object-path", required_argument, 0, 'L'},
	{"library-path", required_argument, 0, 'L'},
	{"output-path", required_argument, 0, 'o'},
	{"help", no_argument, 0, 'h'},
	{"version", no_argument, 0, 'v'},
	{0, 0, 0, 0}
};
#endif

int
main(int argc, char **argv)
{
	char c;
	char *_output_dir = ".";
#ifdef HAVE_GETOPT_LONG
	int optindex;
#endif


	while ((c = NEXT_OPTION) > -1) {
		switch(c) {

		case 'v':
			printf("SCI Script compiler\n"
			       "Version %d.%d.%d - (UNIX)\n"
			       "Compiler by Brian Provinciano, UNIX frontend by Christoph Reichenbach\n"
			       "\nThis program is provided WITHOUT WARRANTY of any kind.\n"
			       "Please refer to the accompanying file COPYING for licensing details.\n",
			       VERSION.Major, VERSION.Minor, VERSION.Build);
			return 0;

		case 'h':
			printf("Usage:\n\tscc [options] <source file>+\n"
			       "Options:\n"
			       EXPLAIN_OPTION("include-path", "-I", "Specifies where include files are read from")
			       EXPLAIN_OPTION("object-path", "-L", "Specifies the sco source path")
			       EXPLAIN_OPTION("output-path", "-o", "Specifies the directory all output is written to")
			       EXPLAIN_OPTION("help     ", "-h", "Displays this help message")
			       EXPLAIN_OPTION("version  ", "-v", "Prints the compiler version and copyright\n")
			       "If no include/object path is set, '.' is substituted implicitly.\n");
			return 0;

		case 'o': _output_dir = malloc(strlen(optarg + 2));
			strcpy(_output_dir, optarg);
			strcat(_output_dir, "/");
			break;

		case 'I': include_dirs = dirlist_add(include_dirs, optarg);
			break;

		case 'L': lib_dirs = dirlist_add(lib_dirs, optarg);
			break;

		}
	}

	output_dir = dirlist_add(NULL, _output_dir);

	if (optind >= argc) {
		fprintf(stderr, "No files were specified (use '%s -h' for help)\n", argv[0]);
		return 1;
	}

	while (optind < argc) { /* Iterate over all parameters */
		if (!CompileScript(argv[optind])) {
			ShowMessage(smCOMPILE,"Failed for %s\n", argv[optind]);
			return 1;
		}
		optind++;
	}
	putchar('\n');

	FreeEverything();

	return 0;
}





