//---------------------------------------------------------------------------
#ifndef _scistudio_h_
#define _scistudio_h_
//---------------------------------------------------------------------------
#define PROGRAM_NAME		"SCI Studio"
#define PROGRAM_TITLE		"SCI Studio 3.+"
#define PROGRAM_VERSION		"3.0.+.36 DEVELOPMENT"
#define PROGRAM_BUILDDATE	"March 25th, 2003"
#define HELP_NAME      		"SCIStudio.chm"
//---------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ComCtrls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <vcl.h>
#pragma hdrstop

#include "ssmessage.h"
#include "ssdefs.h"
#include "ssalloc.h"
#include "ssgame.h"
#include "ssfileio.h"
#include "ssres.h"    
#include "sseditors.h"
#include "ssresdecode.h"
//---------------------------------------------------------------------------
typedef struct {    
	char *name;
	char *title;
	char *version;
	char *buildDate;
	char *author; // don't change this!!! It's mine damn it :)
    char path[1024];
} ssPGM;
extern ssPGM Program;
//---------------------------------------------------------------------------
#endif                                                                  
//---------------------------------------------------------------------------

