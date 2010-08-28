//---------------------------------------------------------------------------

#ifndef texteditH
#define texteditH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MenuBar.hpp"
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TWndTextEdit : public TForm
{
__published:	// IDE-managed Components
	TSplitter *Splitter1;
	TCoolBar *CoolBar1;
	TMenuBar *MenuBar1;
	TToolBar *ToolBar1;
	TToolButton *tbNew;
	TToolButton *tbOpen;
	TToolButton *tbSave;
	TToolButton *tbWriteScriptHeader;
	TToolButton *ToolButton6;
	TToolButton *tbViewAsMessageBox;
	TToolButton *ToolButton3;
	TToolButton *tbCopy;
	TToolButton *ToolButton2;
	TToolButton *tbAdd;
	TToolButton *tbDelete;
	TToolButton *tbMoveUp;
	TToolButton *tbMoveDown;
	TPanel *EditPanel;
	TPanel *NamePanel;
	TLabel *NameLabel;
	TEdit *NameEdit;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *New1;
	TMenuItem *Open1;
	TMenuItem *Save1;
	TMenuItem *SaveAs1;
	TMenuItem *SaveToGame1;
	TMenuItem *N3;
	TMenuItem *WriteScriptHeader1;
	TMenuItem *N1;
	TMenuItem *Exit1;
	TMenuItem *Entries1;
	TMenuItem *Add1;
	TMenuItem *Delete1;
	TMenuItem *N2;
	TMenuItem *MoveUp1;
	TMenuItem *MoveDown1;
	TMenuItem *View1;
	TMenuItem *AsMessageBox1;
	TMenuItem *Edit1;
	TMenuItem *Copy1;
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
	TPanel *Panel1;
	TListView *ListView;
	TPanel *Panel2;
	TMemo *EditBox;
	void __fastcall tbNewClick(TObject *Sender);
	void __fastcall tbOpenClick(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall tbWriteScriptHeaderClick(TObject *Sender);
	void __fastcall tbViewAsMessageBoxClick(TObject *Sender);
	void __fastcall tbCopyClick(TObject *Sender);
	void __fastcall tbAddClick(TObject *Sender);
	void __fastcall tbDeleteClick(TObject *Sender);
	void __fastcall tbMoveUpClick(TObject *Sender);
	void __fastcall tbMoveDownClick(TObject *Sender);
	void __fastcall SaveAs1Click(TObject *Sender);
	void __fastcall SaveToGame1Click(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall NameEditChange(TObject *Sender);
	void __fastcall EditBoxChange(TObject *Sender);
	void __fastcall ListViewDblClick(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ListViewChange(TObject *Sender, TListItem *Item,
          TItemChange Change);
private:	// User declarations
public:		// User declarations
	__fastcall TWndTextEdit(TComponent* Owner); 
                      
    BOOL InitEditor(EDTWND *_edtWnd, U8 *resBuf, S16 resVer);
	EDITORTAG edTag;

    void LoadText();
    void __fastcall LoadTextFile(AnsiString FileName);
	BOOL TestString(AnsiString String);
	void UpdateItemNumbers();

    sciTEXT text;
};
//---------------------------------------------------------------------------
extern PACKAGE TWndTextEdit *WndTextEdit;
//---------------------------------------------------------------------------
#endif
