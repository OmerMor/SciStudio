//---------------------------------------------------------------------------

#ifndef vocabeditH
#define vocabeditH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MenuBar.hpp"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
class sciVocGroup {
	public:
        WORD Type;
        TStringList *Strings;
};        
//---------------------------------------------------------------------------
class TWndVocabEdit : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape4;
	TSpeedButton *SpeedButton3;
	TCoolBar *CoolBar1;
	TMenuBar *MenuBar1;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *New1;
	TMenuItem *Open1;
	TMenuItem *Save1;
	TMenuItem *SaveAs1;
	TMenuItem *SaveToGame1;
	TMenuItem *N1;
	TMenuItem *Exit1;
	TMenuItem *Edit1;
	TMenuItem *Copy2;
	TMenuItem *Search1;
	TMenuItem *FindWord1;
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
	TPopupMenu *PopupMenu1;
	TMenuItem *DeleteGroup1;
	TMenuItem *Copy1;
	TPopupMenu *PopupMenu2;
	TMenuItem *DeleteWord1;
	TPanel *Panel6;
	TListView *ListView;
	TToolBar *ToolBar3;
	TToolButton *tbAddWord;
	TToolButton *tbDeleteGroup;
	TPanel *Panel9;
	TLabel *Label3;
	TPanel *Panel1;
	TPanel *Panel8;
	TListBox *ListBox;
	TPanel *Panel3;
	TLabel *Label2;
	TToolBar *ToolBar2;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TPanel *Panel7;
	TCheckListBox *TypeListBox;
	TPanel *Panel10;
	TLabel *Label1;
	TPanel *Panel4;
	TMenuItem *AddGroup1;
	TMenuItem *AddWord1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TSplitter *Splitter1;
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall SaveAs1Click(TObject *Sender);
	void __fastcall SaveToGame1Click(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall Copy2Click(TObject *Sender);
	void __fastcall FindWord1Click(TObject *Sender);
	void __fastcall ListViewChange(TObject *Sender, TListItem *Item,
          TItemChange Change);
	void __fastcall ListViewColumnClick(TObject *Sender, TListColumn *Column);
	void __fastcall TypeListBoxClick(TObject *Sender);
	void __fastcall AddWordEditKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DeleteGroup1Click(TObject *Sender);
	void __fastcall DeleteWord1Click(TObject *Sender);
	void __fastcall Edit1Click(TObject *Sender);
	void __fastcall tbAddWordClick(TObject *Sender);
	void __fastcall ToolButton8Click(TObject *Sender);
	void __fastcall New1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TWndVocabEdit(TComponent* Owner); 

    BOOL InitEditor(EDTWND *_edtWnd, U8 *resBuf, S16 resVer);
	EDITORTAG edTag;

	AnsiString __fastcall GetTypesAsString(WORD Type);
	void __fastcall UpdateVocabEditVisuals();
	int 			GetVocTypeIndex(AnsiString Str);
	WORD 			GetVocTypeMask(AnsiString Str);
	AnsiString 		GetVocTypeName(int Mask);
	WORD __fastcall HasType(WORD Type, WORD Mask);
	void __fastcall AddType(WORD Group, WORD Type);
	void __fastcall DeleteType(WORD Group, WORD Type);
	void __fastcall NewVocab();
	bool __fastcall LoadVocab(U8 *data,U16 len);
	void __fastcall SaveVocab(int wt);
	void __fastcall LoadListViewVocab(BOOL SELECT);
	bool __fastcall AddWord(AnsiString s, int group);
	void __fastcall ClearFields();
    void __fastcall GotoCurrentItem();

    BOOL WINBLOWS;
    char vocString[256];
    int currentItem, stringCount;
    WORD currentGroup;
    BOOL LOADING_VOCAB;
    U16 wordsType;

    TListItem *selectedListItem;
    AnsiString vocFileName;

    sciVocGroup *vocGroups[MAX_VOC_GROUPS];
};
//---------------------------------------------------------------------------
extern PACKAGE TWndVocabEdit *WndVocabEdit;
//---------------------------------------------------------------------------
#endif
