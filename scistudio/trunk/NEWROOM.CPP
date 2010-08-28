//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "newroom.h"
#include "explorer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgNewRoom *DlgNewRoom;
//---------------------------------------------------------------------------
#define TOTAL_AUTOCHECKS 8
AnsiString AutoChecks[TOTAL_AUTOCHECKS] = {
	"main",
	"controls",
	"cycle",
	"game",
	"feature",
	"obj",
	"inv",
	"door"
};
//---------------------------------------------------------------------------
__fastcall TDlgNewRoom::TDlgNewRoom(TComponent* Owner)
	: TForm(Owner)
{
}      
//---------------------------------------------------------------------------
void WriteLineSep(FILE *f)
{
	ssFPrint(f,"/******************************************************************************/\n");
}
//---------------------------------------------------------------------------
void __fastcall TDlgNewRoom::Button2Click(TObject *Sender)
{
	int RoomNumber,PicNumber;
    char Ext[5],FileName[201];
    strcpy(Ext,Edit1->Text.c_str());
	for(int i=0;i<Edit1->Text.Length();i++)
		if(((char)(Ext[i]))<(char)'0'||((char)(Ext[i]))>(char)'9') {
   			ShowMessage("Room number must be from 0 to 999");
        	return;
    	}
	RoomNumber = StrToInt(Edit1->Text);

    strcpy(Ext,Edit1->Text.c_str());
	for(int i=Edit2->Text.Length()-1;i>=0;i--)
		if(((char)(Ext[i]))<(char)'0'||((char)(Ext[i]))>(char)'9') {
   			ShowMessage("Picture number must be from 0 to 999");
        	return;
    	}
	PicNumber = StrToInt(Edit2->Text);

    Edit3->Text = ExcludeTrailingBackslash(Edit3->Text);
	sprintf(FileName,"%s\\rm%03d.sc",Edit3->Text.c_str(),RoomNumber);
    if(FileExists(AnsiString(FileName))) {
    	if(Application->MessageBox(
        	("File "+AnsiString(FileName)+" already exists! Overwrite?").c_str(),
            "File Exists",
            MB_YESNO)==IDNO)
            	return;
    }
    FILE *f;
    if((f=ssOpenFile(ssFIO_ROOT|ssFIO_MESSAGE,FileName,"wb"))==NULL)
        return;

	WriteLineSep(f);
    ssFPrint(f,"(include \"sci.sh\")\n(include \"game.sh\")\n");
	WriteLineSep(f);
    ssFPrint(f,"(script %d)\n",RoomNumber);
	WriteLineSep(f);
    for(int i=0;i<SCOFileCount;i++) {
    	if(CheckListBox1->Checked[i])
    		fprintf(f,"(use \"%s\")\n",CheckListBox1->Items->Strings[i].c_str());
    }
	WriteLineSep(f);
    ssFPrint(f,"(instance public rm%03d of Rm\n\t(properties\n",RoomNumber);
    if(RoomNumber==PicNumber)
    	ssFPrint(f,"\t\tpicture scriptNumber\n");
    else
    	ssFPrint(f,"\t\tpicture %d\n",PicNumber);

	ssFPrint(f,
    	"\t\tnorth 0\n"
    	"\t\teast 0\n"
    	"\t\tsouth 0\n"
    	"\t\twest 0\n"
    	"\t)\n"
    	"\t(method (init)\n"
    	"\t\t(super:init())\n"
    	"\t\t(self:setScript(RoomScript))\n\n"
    	"\t\t(switch(gPreviousRoomNumber)\n"
    	"\t\t\t(default\n"
    	"\t\t\t\t(send gEgo:\n"
    	"\t\t\t\t\tposn(150 130)\n"
    	"\t\t\t\t\tloop(1)\n"
    	"\t\t\t\t)\n"
    	"\t\t\t)\n"
    	"\t\t)\n\n"
    	"\t\tSetUpEgo()\n"
    	"\t\t(send gEgo:init())\n"
    	"\t)\n"
    	")\n"
    );       
	WriteLineSep(f);
	ssFPrint(f,
    	"(instance RoomScript of Script\n"
		"\t(properties)\n"
		")\n"
    );
	WriteLineSep(f);
    ssCloseFile(f);
	ScrEdit->OpenScript(AnsiString(FileName),FALSE);
    if(WndExplorer) {
    	AnsiString ININame = AnsiString(Game.path)+"\\game.ini";
    	AnsiString s1,s2;
    	s1.sprintf("n%03d",RoomNumber);
    	s2.sprintf("rm%03d",RoomNumber);
    	if(FileExists(ININame)) {
    		TIniFile *GameINI = new TIniFile(ININame);
       		GameINI->WriteString("Script",s1,s2);
        	delete GameINI;
    	}
    }
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TDlgNewRoom::Button3Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TDlgNewRoom::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}               
//---------------------------------------------------------------------------
void __fastcall TDlgNewRoom::FindSCOs()
{
    char DirectoryString[201];
    WIN32_FIND_DATA FindFileData;
    HANDLE hFindFile;

    wsprintf(DirectoryString, "%s\\*.sco", Dir.c_str());
    hFindFile = FindFirstFile(
        DirectoryString,
        &FindFileData
    );
	CheckListBox1->Items->Clear();
    SCOFileCount=0;
    if(hFindFile==INVALID_HANDLE_VALUE) {
    	CheckListBox1->Enabled = FALSE;
        return;
    }
    do {
        if(FindFileData.dwFileAttributes!=FILE_ATTRIBUTE_DIRECTORY) {
        	for(int i=strlen(FindFileData.cFileName)-1;i>=0;i--) {
            	if(FindFileData.cFileName[i]=='.') {
                	FindFileData.cFileName[i]='\0';
                    break;
                }
            }
    		CheckListBox1->Items->Add(AnsiString(FindFileData.cFileName));
            SCOFileCount++;
        }
    } while(FindNextFile(hFindFile,	&FindFileData));

    for(int i=0;i<TOTAL_AUTOCHECKS;i++) {
    	for(int j=SCOFileCount-1;j>=0;j--) {
        	if(CheckListBox1->Items->Strings[j]==AutoChecks[i])
            	CheckListBox1->Checked[j] = TRUE;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TDlgNewRoom::SetItUp(TWndScriptEdit *aScrEdit, AnsiString aDir)
{
	ScrEdit = aScrEdit;

	Dir = aDir;
    Edit3->Text = Dir;

    RadioButton1Click(this);
    FindSCOs();
}
//---------------------------------------------------------------------------
void __fastcall TDlgNewRoom::RadioButton1Click(TObject *Sender)
{
	Edit2->Enabled = FALSE;
}
//---------------------------------------------------------------------------
void __fastcall TDlgNewRoom::RadioButton2Click(TObject *Sender)
{
	Edit2->Enabled = TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TDlgNewRoom::Edit1Change(TObject *Sender)
{
	if(RadioButton1->Checked)
    	Edit2->Text = Edit1->Text;
}
//---------------------------------------------------------------------------
void __fastcall TDlgNewRoom::Button1Click(TObject *Sender)
{                           
    TDirDialog *DirDialog;
    DirDialog = new TDirDialog;
    DirDialog->Caption = "Script Directory";
    DirDialog->Title = "Please select the directory in which your game's source files are located.";
    DirDialog->InitialDir = Dir;
    if(!DirDialog->Execute()) {
    	delete DirDialog;
    	return;
    }
    Dir = DirDialog->FullPath;
    Edit3->Text = DirDialog->FullPath;
    FindSCOs();
    delete DirDialog;
}
//---------------------------------------------------------------------------
