//---------------------------------------------------------------------------

#ifndef settingsH
#define settingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TDlgSettings : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *General;
	TGroupBox *GroupBox1;
	TCheckBox *cbShowSplashScreen;
	TCheckBox *cbShowWelcomeScreen;
	TGroupBox *GroupBox3;
	TCheckBox *cbQuerySaving;
	TButton *BitBtn1;
	TButton *BitBtn2;
	TTabSheet *Desktop;
	TGroupBox *GroupBox6;
	TLabel *Label3;
	TShape *shBkColour;
	TSpeedButton *SpeedButton1;
	TEdit *edBkColour;
	TGroupBox *GroupBox2;
	TShape *Shape2;
	TLabel *Label9;
	TImage *Image1;
	TCheckBox *cbToolBarVisible;
	TCheckBox *cbShowTextLabels;
	TCheckBox *cbAlwaysColour;
	TCheckBox *bcToolbarBitmap;
	TButton *Button1;
	TTabSheet *Explorer;
	TGroupBox *GroupBox4;
	TLabel *Label1;
	TComboBox *DefaultResourceType;
	TCheckBox *cbShowPreview;
	TGroupBox *GroupBox5;
	TLabel *Label2;
	TCheckBox *cbFlatScroll;
	TCheckBox *cbHotTrack;
	TCheckBox *cbHandPoint;
	TCheckBox *cbUnderlineC;
	TCheckBox *cbUnderlineH;
	TCheckBox *cbGridLines;
	TComboBox *cbViewStyle;
	TGroupBox *GroupBox7;
	TCheckBox *cbSepScrWnds;
	TTabSheet *System;
	TGroupBox *GroupBox8;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TCheckBox *cbAsResourcemap;
	TCheckBox *cbAsSC;
	TCheckBox *cbAsSH;
	TCheckBox *cbFolderShortcut;
	TButton *CancelBtn;
	TButton *OKBtn;
	TButton *ApplyBtn;
	TColorDialog *ColorDialog;
	TOpenPictureDialog *OpenPictureDialog1;
	TLabel *Label10;
	TEdit *edMaxUndos;
	TUpDown *udMaxUndos;
	void __fastcall OKBtnClick(TObject *Sender);
	void __fastcall ApplyBtnClick(TObject *Sender);
	void __fastcall CancelBtnClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall edBkColourChange(TObject *Sender);
	void __fastcall bcToolbarBitmapClick(TObject *Sender);
	void __fastcall udMaxUndosClick(TObject *Sender, TUDBtnType Button);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgSettings(TComponent* Owner);   
    AnsiString tbBitmapName;
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgSettings *DlgSettings;
//---------------------------------------------------------------------------
#endif
