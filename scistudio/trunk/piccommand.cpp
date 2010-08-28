//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "picedit.h"
#include "piccommand.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgPicCommand *DlgPicCommand;
//---------------------------------------------------------------------------
__fastcall TDlgPicCommand::TDlgPicCommand(TComponent* Owner)
	: TForm(Owner)
{
	PicWin = (TWndPicEdit*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TDlgPicCommand::Button1Click(TObject *Sender)
{                    
	if(offset==-1) return;
    PicWin->DeleteCode(offset);
    PicWin->FillListView(ListBox,offset);
}
//---------------------------------------------------------------------------
void __fastcall TDlgPicCommand::Button2Click(TObject *Sender)
{
	if(offset==-1) return;
    PicWin->CropCode(offset);
    PicWin->FillListView(ListBox,-1);
}
//---------------------------------------------------------------------------
void __fastcall TDlgPicCommand::Button3Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TDlgPicCommand::ListBoxClick(TObject *Sender)
{
	if(ListBox->ItemIndex==-1) {
    	offset = -1;
    	return;
    }
    AnsiString s;
    s = ListBox->Items->Strings[ListBox->ItemIndex];
    AnsiString os = "0x"+s.SubString(1,4);
    offset = StrToInt(os);
    PicWin->pic->offset = offset;
    PicWin->UpdatePic();
    PicWin->drawingTool = -1;
}
//---------------------------------------------------------------------------
void __fastcall TDlgPicCommand::ListBoxKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	ListBoxClick(Sender);
}
//---------------------------------------------------------------------------
