//---------------------------------------------------------------------------

#ifndef paleditH
#define paleditH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TWndPalEdit : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TImage *imPal;
	TPanel *Panel2;
	TButton *Button4;
	TButton *Button3;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TShape *Shape1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TShape *Shape2;
	TShape *Shape3;
	TShape *Shape4;
	TColorDialog *ColorDialog1;
	TButton *Button1;
	TBevel *Bevel1;
	TLabel *Label9;
	TCheckBox *CheckBox1;
	TSpeedButton *SpeedButton1;
	TTimer *Timer1;
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall imPalMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TWndPalEdit(TComponent* Owner);

    void __fastcall SetUp(sciPALETTE *p);
	void __fastcall DrawPalette();

    sciPALETTE pal;    
	BOOL OK_CLOSE;
    int selCol,selX,selY;
	int colWidth,colHeight,spacingX;
};
//---------------------------------------------------------------------------
extern PACKAGE TWndPalEdit *WndPalEdit;
//---------------------------------------------------------------------------
#endif
