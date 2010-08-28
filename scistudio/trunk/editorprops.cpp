//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
                   
#include "main.h"
#include "scriptedit.h"
#include "editorprops.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SynEdit"
#pragma link "SynEditHighlighter"
#pragma link "SynHighlighterSCI"
#pragma link "SynMemo"
#pragma resource "*.dfm"
TDlgEditorProps *DlgEditorProps;  
char *hlNames[] = {
    "Normal",
    "Number",
    "String",
    "Keyword",
    "Operator",
    "Comment",
    "White space"
};
//---------------------------------------------------------------------------
__fastcall TDlgEditorProps::TDlgEditorProps(TComponent* Owner)
	: TForm(Owner)
{                
    SETTING_IT = FALSE;

    
    ParentWin = ((TWndScriptEdit*) Owner);
    SynSCISyn1->Assign(WndMain->SynSCISyn1);

    for(int i = 0; i < hlTOTAL; i++)
        lbHlNames->Items->Add(hlNames[i]);

    SynAttr[0] = SynSCISyn1->NormalAttri;
    SynAttr[1] = SynSCISyn1->NumberAttri;
    SynAttr[2] = SynSCISyn1->StringAttri;
    SynAttr[3] = SynSCISyn1->KeyAttri;
    SynAttr[4] = SynSCISyn1->OperatorAttri;
    SynAttr[5] = SynSCISyn1->CommentAttri;
    SynAttr[6] = SynSCISyn1->SpaceAttri;

    lbHlNames->ItemIndex = 0;
    lbHlNamesClick(Owner);

    SCIMemo->Font->Name = ParentWin->activeMemo->Memo->Font->Name;
    SCIMemo->Font->Size = ParentWin->activeMemo->Memo->Font->Size;

    for(int i = 0; i < Screen->Fonts->Count; i++) {
        cbFontName->Items->Add(Screen->Fonts->Strings[i]);
        if(Screen->Fonts->Strings[i]==SCIMemo->Font->Name)
            cbFontName->ItemIndex = i;
    }

    for(int i = 6; i <= 30; i++) {
        cbFontSize->Items->Add(IntToStr(i));
        if(i==SCIMemo->Font->Size)
            cbFontSize->ItemIndex = i-6;
    }

    SCIMemo->Gutter->Visible = ParentWin->activeMemo->Memo->Gutter->Visible;
    cbGutterVisible->Checked = SCIMemo->Gutter->Visible;
    SCIMemo->Gutter->ShowLineNumbers = ParentWin->activeMemo->Memo->Gutter->ShowLineNumbers;
    cbLineNumbers->Checked = SCIMemo->Gutter->ShowLineNumbers;
    SCIMemo->Options = ParentWin->activeMemo->Memo->Options;
    cbAutoIndent->Checked = SCIMemo->Options.Contains(eoAutoIndent);
    cbSmartTabs->Checked = SCIMemo->Options.Contains(eoSmartTabs);
    cbTabsToSpaces->Checked = SCIMemo->Options.Contains(eoTabsToSpaces);
    cbTrimTrailingSpaces->Checked = SCIMemo->Options.Contains(eoTrimTrailingSpaces);

	cbGroupUndo->Checked		= SCIMemo->Options.Contains(eoGroupUndo);
	cbSmartTabDelete->Checked	= SCIMemo->Options.Contains(eoSmartTabDelete);
	cbDragDrop->Checked			= SCIMemo->Options.Contains(eoDragDropEditing);
	cbScrollEOF->Checked		= SCIMemo->Options.Contains(eoScrollPastEof);
	cbNoCaret->Checked			= SCIMemo->Options.Contains(eoNoCaret);

    SCIMemo->Gutter->Width   = ParentWin->activeMemo->Memo->Gutter->Width;
    for(int i = 3; i <= 60; i++) {
        cbGutterWidth->Items->Add(IntToStr(i));
        if(i==SCIMemo->Gutter->Width)
            cbGutterWidth->ItemIndex = i-3;
    }
    SCIMemo->TabWidth   = ParentWin->activeMemo->Memo->TabWidth;
    for(int i = 0; i <= 30; i++) {
        cbTabSize->Items->Add(IntToStr(i));
        if(i==SCIMemo->TabWidth)
            cbTabSize->ItemIndex = i;
    }
    SCIMemo->ExtraLineSpacing   = ParentWin->activeMemo->Memo->ExtraLineSpacing;
    for(int i = 0; i <= 20; i++) {
        cbExtraLineSpacing->Items->Add(IntToStr(i));
        if(i==SCIMemo->ExtraLineSpacing)
            cbExtraLineSpacing->ItemIndex = i;
    }
}
//---------------------------------------------------------------------------
void __fastcall TDlgEditorProps::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
}
//---------------------------------------------------------------------------


void __fastcall TDlgEditorProps::BitBtn1Click(TObject *Sender)
{
    WndMain->SynSCISyn1->Assign(SynSCISyn1);

    sMEMO *m = ParentWin->firstMemo;
    while(m) {
    	m->Memo->Font->Name = SCIMemo->Font->Name;
    	m->Memo->Font->Size = SCIMemo->Font->Size;

    	m->Memo->Gutter = SCIMemo->Gutter;
    	m->Memo->Options = SCIMemo->Options;

    	m->Memo->TabWidth = SCIMemo->TabWidth;

    	m->Memo->ExtraLineSpacing = SCIMemo->ExtraLineSpacing;
     	m = m->next;
    }
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::BitBtn2Click(TObject *Sender)
{
    Close();
}         
//---------------------------------------------------------------------------
void __fastcall TDlgEditorProps::AssignSynAttr()
{
    if(SETTING_IT) return;

    SynAttr[lbHlNames->ItemIndex]->Background = TColor(pnBG->Color);
    SynAttr[lbHlNames->ItemIndex]->Foreground = TColor(~pnFG->Color);
    SynAttr[lbHlNames->ItemIndex]->Foreground = TColor(pnFG->Color);
    if(cbBold->Checked)
        SynAttr[lbHlNames->ItemIndex]->Style = SynAttr[lbHlNames->ItemIndex]->Style << fsBold;
    else
        SynAttr[lbHlNames->ItemIndex]->Style = SynAttr[lbHlNames->ItemIndex]->Style >> fsBold;
    if(cbItalic->Checked)
        SynAttr[lbHlNames->ItemIndex]->Style = SynAttr[lbHlNames->ItemIndex]->Style << fsItalic;
    else
        SynAttr[lbHlNames->ItemIndex]->Style = SynAttr[lbHlNames->ItemIndex]->Style >> fsItalic;
    if(cbUnderlined->Checked)
        SynAttr[lbHlNames->ItemIndex]->Style = SynAttr[lbHlNames->ItemIndex]->Style << fsUnderline;
    else
        SynAttr[lbHlNames->ItemIndex]->Style = SynAttr[lbHlNames->ItemIndex]->Style >> fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::lbHlNamesClick(TObject *Sender)
{
    SETTING_IT = TRUE;
    pnBG->Color = SynAttr[lbHlNames->ItemIndex]->Background;
    BtnBG->Font->Color = TColor((~pnBG->Color)&0xFFFFFF);
    pnFG->Color = SynAttr[lbHlNames->ItemIndex]->Foreground;
    BtnFG->Font->Color = TColor((~pnFG->Color)&0xFFFFFF);

    cbBold->Checked =
        SynAttr[lbHlNames->ItemIndex]->Style.Contains(fsBold);
    cbItalic->Checked =
        SynAttr[lbHlNames->ItemIndex]->Style.Contains(fsItalic);
    cbUnderlined->Checked =
        SynAttr[lbHlNames->ItemIndex]->Style.Contains(fsUnderline);  /*
    ShowMessage(
        IntToStr(lbHlNames->ItemIndex)+"\nBOLD:"+
        IntToStr(SynAttr[lbHlNames->ItemIndex]->Style.Contains(fsBold))+"\nITALIC:"+
        IntToStr(SynAttr[lbHlNames->ItemIndex]->Style.Contains(fsItalic))+"\nUN:"+
        IntToStr(SynAttr[lbHlNames->ItemIndex]->Style.Contains(fsUnderline)));  */
    SETTING_IT = FALSE;
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::UpdateAttr1Click(TObject *Sender)
{
    AssignSynAttr();
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::cbFontNameChange(TObject *Sender)
{
    if(cbFontName->Items->Strings[cbFontName->ItemIndex]!="")
        SCIMemo->Font->Name =
            cbFontName->Items->Strings[cbFontName->ItemIndex].c_str();
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::cbFontSizeChange(TObject *Sender)
{
    if(cbFontSize->Items->Strings[cbFontSize->ItemIndex]!="")
        SCIMemo->Font->Size =
            StrToInt(cbFontSize->Items->Strings[cbFontSize->ItemIndex]);
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::cbGutterVisibleClick(TObject *Sender)
{
    SCIMemo->Gutter->Visible = cbGutterVisible->Checked;
}    
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::cbLineNumbersClick(TObject *Sender)
{
    SCIMemo->Gutter->ShowLineNumbers = cbLineNumbers->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::cbGutterWidthChange(TObject *Sender)
{
    if(cbGutterWidth->Items->Strings[cbGutterWidth->ItemIndex]!="")
        SCIMemo->Gutter->Width = StrToInt(cbGutterWidth->Items->Strings[cbGutterWidth->ItemIndex]);
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::BtnFGClick(TObject *Sender)
{
    ColorDialog->Color = pnFG->Color;
    if(ColorDialog->Execute()) {
        pnFG->Color = ColorDialog->Color;
        AssignSynAttr();
    }
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::BtnBGClick(TObject *Sender)
{
    ColorDialog->Color = pnBG->Color;
    if(ColorDialog->Execute()) {
        pnBG->Color = ColorDialog->Color;
        AssignSynAttr();
    }
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::cbTabSizeChange(TObject *Sender)
{
    if(cbTabSize->Items->Strings[cbTabSize->ItemIndex]!="")
        SCIMemo->TabWidth = StrToInt(cbTabSize->Items->Strings[cbTabSize->ItemIndex]);
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::cbExtraLineSpacingChange(TObject *Sender)
{
    if(cbExtraLineSpacing->Items->Strings[cbExtraLineSpacing->ItemIndex]!="")
        SCIMemo->ExtraLineSpacing = StrToInt(cbExtraLineSpacing->Items->Strings[cbExtraLineSpacing->ItemIndex]);
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::cbAutoIndentClick(TObject *Sender)
{
    if(cbAutoIndent->Checked)
        SCIMemo->Options << eoAutoIndent;
    else
        SCIMemo->Options >> eoAutoIndent;
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::cbSmartTabsClick(TObject *Sender)
{
    if(cbSmartTabs->Checked)
        SCIMemo->Options << eoSmartTabs;
    else
        SCIMemo->Options >> eoSmartTabs;
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::cbSmartTabDeleteClick(TObject *Sender)
{
    if(cbSmartTabDelete->Checked)
        SCIMemo->Options << eoSmartTabDelete;
    else
        SCIMemo->Options >> eoSmartTabDelete;
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::cbTabsToSpacesClick(TObject *Sender)
{
    if(cbTabsToSpaces->Checked)
        SCIMemo->Options << eoTabsToSpaces;
    else
        SCIMemo->Options >> eoTabsToSpaces;	
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::cbTrimTrailingSpacesClick(TObject *Sender)
{
    if(cbTrimTrailingSpaces->Checked)
        SCIMemo->Options << eoTrimTrailingSpaces;
    else
        SCIMemo->Options >> eoTrimTrailingSpaces;
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::cbGroupUndoClick(TObject *Sender)
{
    if(cbGroupUndo->Checked)
        SCIMemo->Options << eoGroupUndo;
    else
        SCIMemo->Options >> eoGroupUndo;
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::cbDragDropClick(TObject *Sender)
{
    if(cbDragDrop->Checked)
        SCIMemo->Options << eoDragDropEditing;
    else
        SCIMemo->Options >> eoDragDropEditing;
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::cbScrollEOFClick(TObject *Sender)
{
    if(cbScrollEOF->Checked)
        SCIMemo->Options << eoScrollPastEof;
    else
        SCIMemo->Options >> eoScrollPastEof;
}
//---------------------------------------------------------------------------

void __fastcall TDlgEditorProps::cbNoCaretClick(TObject *Sender)
{
    if(cbNoCaret->Checked)
        SCIMemo->Options << eoNoCaret;
    else
        SCIMemo->Options >> eoNoCaret;
}
//---------------------------------------------------------------------------

