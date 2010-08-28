//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
                     
#include "scihdr.h"
#include "vocabedit.h"
#include "vocabfind.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgVocabFind *DlgVocabFind;
//---------------------------------------------------------------------------
__fastcall TDlgVocabFind::TDlgVocabFind(TComponent* Owner)
	: TForm(Owner)
{      
    ResetFind();
}
//---------------------------------------------------------------------------

void __fastcall TDlgVocabFind::BtnFindClick(TObject *Sender)
{
    Edit1->Text = Edit1->Text.LowerCase();
    if(Edit1->Text == "") {
        StatusBar1->SimpleText = "Error: Please enter search string!";
        return;
    }

    for(Group = 0; Group < MAX_VOC_GROUPS; Group++)
        if(aWndVocabEdit->vocGroups[Group])
            for(int s = 0; s < aWndVocabEdit->vocGroups[Group]->Strings->Count; s++)
                if(aWndVocabEdit->vocGroups[Group]->Strings->Strings[s] == Edit1->Text) {
                    StatusBar1->SimpleText = "\""+Edit1->Text+"\" found in Group: "+IntToStr(Group)+".";
                    BtnOK->Enabled = TRUE;
                    BtnGoto->Enabled = TRUE;
                    return;
                }

    StatusBar1->SimpleText = "\""+Edit1->Text+"\" not found!";
    ResetFind();
}
//---------------------------------------------------------------------------
void __fastcall TDlgVocabFind::BtnOKClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TDlgVocabFind::BtnGotoClick(TObject *Sender)
{
    AnsiString StrGroup = IntToStr(Group);
    TListItem *ListItem =
        aWndVocabEdit->ListView->FindCaption(0, StrGroup, FALSE, TRUE, FALSE);

    aWndVocabEdit->ListView->SetFocus();
    aWndVocabEdit->ListView->Selected = ListItem;
    aWndVocabEdit->ListView->ItemFocused = ListItem;
    ListItem->MakeVisible(TRUE);
}
//---------------------------------------------------------------------------
void __fastcall TDlgVocabFind::BtnCancelClick(TObject *Sender)
{
    Close();
}    
//---------------------------------------------------------------------------
void __fastcall TDlgVocabFind::ResetFind()
{
    BtnOK->Enabled = FALSE;
    BtnGoto->Enabled = FALSE;
    Group = -1;
}
//---------------------------------------------------------------------------
void __fastcall TDlgVocabFind::FormClose(TObject *Sender,
      TCloseAction &Action)
{
	Action = caFree;	
}
//---------------------------------------------------------------------------
