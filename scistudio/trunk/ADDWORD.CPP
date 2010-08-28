//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
                    
#include "scihdr.h"
#include "vocabedit.h"
#include "addword.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgAddWord *DlgAddWord;
//---------------------------------------------------------------------------
__fastcall TDlgAddWord::TDlgAddWord(TComponent* Owner)
	: TForm(Owner)
{
	wndVoc = (TWndVocabEdit*)Owner;
}
//---------------------------------------------------------------------------
void __fastcall TDlgAddWord::Button1Click(TObject *Sender)
{                      
    if(Edit1->Text == "") {
        ShowMessage("Error! No word entered!");
        return;
    }
    int g = StrToInt(ComboBox1->Items->Strings[ComboBox1->ItemIndex]);
	if(wndVoc->AddWord(Edit1->Text, g)) {  
    	wndVoc->currentGroup = g;
    	wndVoc->LoadListViewVocab(TRUE);
    	wndVoc->GotoCurrentItem();
    	Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TDlgAddWord::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
