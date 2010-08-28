//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
                 
#include "main.h"
#include "scriptedit.h"
#include "makefile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgMakeFile *DlgMakeFile;
//---------------------------------------------------------------------------
__fastcall TDlgMakeFile::TDlgMakeFile(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

