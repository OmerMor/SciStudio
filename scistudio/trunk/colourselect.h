//---------------------------------------------------------------------------

#ifndef colourselectH
#define colourselectH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TDlgColourSelect : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPageControl *PageControl1;
	TTabSheet *VisualTab;
	TBevel *Bevel10;
	TImage *Image1;
	TImage *Image5;
	TBevel *Bevel9;
	TImage *Image7;
	TLabel *Label2;
	TLabel *Label1;
	TLabel *Label3;
	TRadioButton *rbEntirePalette;
	TRadioButton *rbNewColours;
	TTabSheet *PriConTab;
	TBevel *Bevel5;
	TImage *Image9;
	TPanel *Panel2;
	TButton *BtnTurnOff;
	TButton *BtnSetColour;
	TButton *BtnCancel;
	TTimer *Timer1;
	TLabel *Label4;
	TImage *Image2;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall BtnSetColourClick(TObject *Sender);
	void __fastcall BtnTurnOffClick(TObject *Sender);
	void __fastcall BtnCancelClick(TObject *Sender);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall Image7MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall Image9MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Label4MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgColourSelect(TComponent* Owner);

    void __fastcall Setup(char Scr, TWndPicEdit *EditWin1);
    void __fastcall DrawSelected();
    void __fastcall DrawPalettes(BOOL P);
    BOOL __fastcall GetDexes(int X, int Y);

    int ResCol, ResPal, aScreen,paldex,palcol;
    int rX,rY;
    BOOL COLOUR_CHANGED;
    BYTE Palette[4][40];
    RECT selRect;
    TWndPicEdit *EditWin;
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgColourSelect *DlgColourSelect;
//---------------------------------------------------------------------------
#endif
