//---------------------------------------------------------------------------

#ifndef editorpropsH
#define editorpropsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SynEdit.hpp"
#include "SynEditHighlighter.hpp"
#include "SynHighlighterSCI.hpp"
#include "SynMemo.hpp"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TDlgEditorProps : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TComboBox *cbFontName;
	TComboBox *cbFontSize;
	TGroupBox *GroupBox2;
	TLabel *Label3;
	TCheckBox *cbGutterVisible;
	TComboBox *cbGutterWidth;
	TCheckBox *cbLineNumbers;
	TGroupBox *GroupBox3;
	TLabel *Label6;
	TLabel *Label5;
	TComboBox *cbTabSize;
	TCheckBox *cbSmartTabs;
	TCheckBox *cbTabsToSpaces;
	TCheckBox *cbTrimTrailingSpaces;
	TCheckBox *cbAutoIndent;
	TComboBox *cbExtraLineSpacing;
	TCheckBox *cbGroupUndo;
	TCheckBox *cbSmartTabDelete;
	TCheckBox *cbDragDrop;
	TCheckBox *cbScrollEOF;
	TCheckBox *cbNoCaret;
	TTabSheet *TabSheet2;
	TPanel *pnBG;
	TSpeedButton *BtnBG;
	TListBox *lbHlNames;
	TCheckBox *cbBold;
	TCheckBox *cbItalic;
	TCheckBox *cbUnderlined;
	TSynMemo *SCIMemo;
	TPanel *pnFG;
	TSpeedButton *BtnFG;
	TPanel *Panel1;
	TButton *BitBtn1;
	TButton *BitBtn2;
	TColorDialog *ColorDialog;
	TSynSCISyn *SynSCISyn1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall lbHlNamesClick(TObject *Sender);
	void __fastcall UpdateAttr1Click(TObject *Sender);
	void __fastcall cbFontNameChange(TObject *Sender);
	void __fastcall cbFontSizeChange(TObject *Sender);
	void __fastcall cbGutterVisibleClick(TObject *Sender);
	void __fastcall cbGutterWidthChange(TObject *Sender);
	void __fastcall cbLineNumbersClick(TObject *Sender);
	void __fastcall BtnFGClick(TObject *Sender);
	void __fastcall BtnBGClick(TObject *Sender);
	void __fastcall cbTabSizeChange(TObject *Sender);
	void __fastcall cbExtraLineSpacingChange(TObject *Sender);
	void __fastcall cbAutoIndentClick(TObject *Sender);
	void __fastcall cbSmartTabsClick(TObject *Sender);
	void __fastcall cbSmartTabDeleteClick(TObject *Sender);
	void __fastcall cbTabsToSpacesClick(TObject *Sender);
	void __fastcall cbTrimTrailingSpacesClick(TObject *Sender);
	void __fastcall cbGroupUndoClick(TObject *Sender);
	void __fastcall cbDragDropClick(TObject *Sender);
	void __fastcall cbScrollEOFClick(TObject *Sender);
	void __fastcall cbNoCaretClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgEditorProps(TComponent* Owner);

    void __fastcall AssignSynAttr();
    TWndScriptEdit *ParentWin;
    BOOL SETTING_IT;

	TSynHighlighterAttributes *SynAttr[hlTOTAL];
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgEditorProps *DlgEditorProps;
//---------------------------------------------------------------------------
#endif
