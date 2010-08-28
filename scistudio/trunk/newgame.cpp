//---------------------------------------------------------------------------

#include <vcl.h>
#include <FileCtrl.hpp>
#pragma hdrstop

#include "newgame.h"
#include "scihdr.h"
#include "main.h"
#include "explorer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgNewGame *DlgNewGame;
//---------------------------------------------------------------------------
__fastcall TDlgNewGame::TDlgNewGame(TComponent* Owner)
	: TForm(Owner)
{
	edPath->Text = WndMain->DirDialog->InitialDir;
}
//---------------------------------------------------------------------------
BOOL __fastcall TDlgNewGame::ParseCreate()
{
	if(DirectoryExists(edPath->Text)) return TRUE;
    if(ssMessage(ssYESNO,"The path you have entered, '%s' does not exist. Would you like to create it?",edPath->Text.c_str())==IDNO) return FALSE;
	if(!CreateDir(edPath->Text)) {
     	ssMessage(ssERROR,"Unable to create directory!");
        return FALSE;
    }
    return TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TDlgNewGame::Button1Click(TObject *Sender)
{
    WndMain->DirDialog->Title = "Select Game Path";
    WndMain->DirDialog->Caption = "Please select the directory which the game you wish to open is located in.";
    WndMain->DirDialog->InitialDir = WndMain->DirDialog->FullPath = edPath->Text;
    WndMain->DirDialog->MAP_CHECK = FALSE;
    if(!WndMain->DirDialog->Execute())
        return;
    edPath->Text = WndMain->DirDialog->FullPath;
}
//---------------------------------------------------------------------------
void __fastcall TDlgNewGame::Button3Click(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------
void __fastcall TDlgNewGame::Button2Click(TObject *Sender)
{
	if(!ParseCreate()) return;
    FixPath(edPath->Text.c_str());
    if(FileExists(edPath->Text+"\\resource.map"))
    	if(ssMessage(ssYESNO|ssWARNING,"The path you have entered, '%s' already contains an SCI game. Would you like to overwrite it?",edPath->Text.c_str())==IDNO) return;
    if(edPath->Text == AnsiString(Program.path)) {
    	ssMessage(ssWARNING,"The path you have entered, '%s' is the same path that SCI Studio is located in. It is not recommended that you save it there.",edPath->Text.c_str());
        return;
    }
    if(rbTemplate->Checked) {
    	if(!DirectoryExists(AnsiString(Program.path)+"\\template")) {
    		ssMessage(ssERROR,"Template game directory not found! You must reinstall SCI Studio!");
    	    return;
		}
		if(!CopyFiles((AnsiString(Program.path)+"\\template").c_str(),edPath->Text.c_str())) {
    		ssMessage(ssERROR,"An error occured while trying to copy the template game files to %s",edPath->Text.c_str());
    	    return;
        }
	} else {
    	FILE *f;
		if((f=ssOpenFile(ssFIO_ROOT,(edPath->Text+"\\resource.map").c_str(),"wb"))==NULL) {
    		ssMessage(ssERROR,"An error occured while writing to %s",edPath->Text.c_str());
    	    return;
        }
        ssFPrint(f,"\xFF\xFF\xFF\xFF\xFF\xFF");
        ssCloseFile(f);
    }
	WndMain->ExploreGame(edPath->Text,edName->Text);
    WndExplorer->MakeConfig();
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TDlgNewGame::FormClose(TObject *Sender,
      TCloseAction &Action)
{
	Action = caFree;
}
//---------------------------------------------------------------------------
