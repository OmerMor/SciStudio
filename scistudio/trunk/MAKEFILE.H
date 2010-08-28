//---------------------------------------------------------------------------

#ifndef makefileH
#define makefileH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TDlgMakeFile : public TForm
{
__published:	// IDE-managed Components
	TBevel *Bevel1;
	TPanel *Panel1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit1;
	TPanel *Panel2;
	TPanel *Panel4;
	TListView *ListView;
	TToolBar *ToolBar1;
	TToolButton *tbAdd;
	TToolButton *tbDelete;
	TToolButton *tbMoveUp;
	TToolButton *tbMoveDown;
	TToolBar *ToolBar2;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
private:	// User declarations
public:		// User declarations
	__fastcall TDlgMakeFile(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgMakeFile *DlgMakeFile;
//---------------------------------------------------------------------------
#endif
