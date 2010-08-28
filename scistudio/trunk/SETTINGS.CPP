//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "settings.h"
#include "config.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgSettings *DlgSettings;     
//---------------------------------------------------------------------------
AnsiString vsNames[4] = {"Icon","Small Icon","List","Details"};
//---------------------------------------------------------------------------
__fastcall TDlgSettings::TDlgSettings(TComponent* Owner)
	: TForm(Owner)
{
    cbShowSplashScreen->Checked = config.SHOW_SPLASH;
    cbShowWelcomeScreen->Checked = config.SHOW_WELCOME;
    cbQuerySaving->Checked = config.QUERY_SAVING;
    cbToolBarVisible->Checked = WndMain->ToolBar3->Checked;
    cbShowTextLabels->Checked = WndMain->TextLabels1->Checked;
    cbAlwaysColour->Checked = WndMain->AlwaysColour1->Checked;
    bcToolbarBitmap->Checked = WndMain->MainPanel2->Bitmap!=NULL;
    tbBitmapName = config.tbBitmapName;
    if(bcToolbarBitmap->Checked)
    	Image1->Picture->Bitmap->Assign(WndMain->MainPanel2->Bitmap);

    for(int i=0;i<TOTAL_RES_TYPES;i++)
        DefaultResourceType->Items->Add(resTypes[i].name);
    DefaultResourceType->ItemIndex = config.ewsDefResType;

    for(int i=0;i<4;i++)
        cbViewStyle->Items->Add(vsNames[i]);
    cbViewStyle->ItemIndex = config.ewsViewStyle;

    cbShowPreview->Checked = config.ewsSHOW_PREVIEW;
    cbFlatScroll->Checked  = config.ewsFLAT_SCROLL;
    cbGridLines->Checked   = config.ewsGRID_LINES;
    cbHotTrack->Checked    = config.ewsHOT_TRACK;
    cbHandPoint->Checked   = config.ewsHAND_POINT;
    cbUnderlineC->Checked  = config.ewsUNDERLINEC;
    cbUnderlineH->Checked  = config.ewsUNDERLINEH;

    shBkColour->Brush->Color = WndMain->Color;
    edBkColour->Text       = IntToHex(shBkColour->Brush->Color,6);
    SpeedButton1->Font->Color = (TColor)((~shBkColour->Brush->Color)&0x00FFFFFF);

    cbSepScrWnds->Checked  = config.ewsSEP_SCR_WNDS;

    cbAsResourcemap->Checked	= config.RegExtInfo[0].Set;
    cbAsSC->Checked				= config.RegExtInfo[1].Set;
    cbAsSH->Checked				= config.RegExtInfo[2].Set;
    cbFolderShortcut->Checked	= config.RegExtInfo[3].Set;

    udMaxUndos->Position		= config.maxUndos;
    udMaxUndosClick(this,(TUDBtnType)NULL);
}
//---------------------------------------------------------------------------
void __fastcall TDlgSettings::OKBtnClick(TObject *Sender)
{        
    ApplyBtnClick(Sender);
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TDlgSettings::ApplyBtnClick(TObject *Sender)
{
    config.SHOW_SPLASH       = cbShowSplashScreen->Checked;
    config.SHOW_WELCOME      = cbShowWelcomeScreen->Checked;
    config.QUERY_SAVING      = cbQuerySaving->Checked;

    if(cbToolBarVisible->Checked!=WndMain->ToolBar3->Checked)
        WndMain->ToolBar3Click(WndMain);
    if(cbShowTextLabels->Checked!=WndMain->TextLabels1->Checked)
        WndMain->TextLabels1Click(WndMain);
    if(cbAlwaysColour->Checked!=WndMain->AlwaysColour1->Checked)
        WndMain->AlwaysColour1Click(WndMain);

	if(!bcToolbarBitmap->Checked) tbBitmapName = "";
    if(tbBitmapName=="") {
    	WndMain->MainPanel2->Bitmap=NULL;
   		config.tbBitmapName = "";
    } else if(tbBitmapName!=config.tbBitmapName) {
    	WndMain->MainPanel2->Bitmap->LoadFromFile(tbBitmapName);
   		config.tbBitmapName = tbBitmapName;
    }                              
    WndMain->pnlToolBar->Left = 0;

    config.ewsDefResType   = DefaultResourceType->ItemIndex;
    config.ewsViewStyle    = cbViewStyle->ItemIndex;

    config.ewsSHOW_PREVIEW = cbShowPreview->Checked;
    config.ewsFLAT_SCROLL  = cbFlatScroll->Checked;
    config.ewsGRID_LINES   = cbGridLines->Checked;
    config.ewsHOT_TRACK    = cbHotTrack->Checked;
    config.ewsHAND_POINT   = cbHandPoint->Checked;
    config.ewsUNDERLINEC   = cbUnderlineC->Checked;
    config.ewsUNDERLINEH   = cbUnderlineH->Checked;

    if(WndMain->Color != shBkColour->Brush->Color) {
        WndMain->Color = shBkColour->Brush->Color;

        WndMain->Hide();
        WndMain->Show();
        SetActiveWindow(Handle);
    }
    config.ewsSEP_SCR_WNDS = cbSepScrWnds->Checked;

    config.RegExtInfo[0].Set = cbAsResourcemap->Checked;
    config.RegExtInfo[1].Set = cbAsSC->Checked;
    config.RegExtInfo[2].Set = cbAsSH->Checked;
    config.RegExtInfo[3].Set = cbFolderShortcut->Checked;

    config.maxUndos = udMaxUndos->Position;
}
//---------------------------------------------------------------------------
void __fastcall TDlgSettings::CancelBtnClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TDlgSettings::FormClose(TObject *Sender,
      TCloseAction &Action)
{                 
    Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TDlgSettings::BitBtn1Click(TObject *Sender)
{
    WndMain->Left = (Screen->Width-WndMain->Width)>>1;
    WndMain->Top = (Screen->Height-WndMain->Height)>>1;
}
//---------------------------------------------------------------------------
void __fastcall TDlgSettings::BitBtn2Click(TObject *Sender)
{
    TRegistry *Reg = new TRegistry;
    if(Application->MessageBox("Are you sure you want to remove SCI Studio from the registry?", PROGRAM_NAME, MB_YESNO) == IDNO) return;

    if(!RegDeleteKey(HKEY_LOCAL_MACHINE, REG_KEY_NAME.c_str())==ERROR_SUCCESS)
        ShowMessage("Error deleting key!");
    else
        ShowMessage("Key successfully removed.\n\nAny setting changes made between now, and the time you exit SCI Studio, will not be saved to the registry.");

    delete Reg;

    WndMain->NO_KEY = TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TDlgSettings::Button1Click(TObject *Sender)
{
	OpenPictureDialog1->FileName = tbBitmapName;
	if(!OpenPictureDialog1->Execute()) return;
    Image1->Picture->Bitmap->LoadFromFile(OpenPictureDialog1->FileName);
	tbBitmapName = OpenPictureDialog1->FileName;
    bcToolbarBitmap->Checked = TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TDlgSettings::SpeedButton1Click(TObject *Sender)
{
    ColorDialog->Color = shBkColour->Brush->Color;
    if(!ColorDialog->Execute()) return;
    shBkColour->Brush->Color = ColorDialog->Color;
    edBkColour->Text = IntToHex(ColorDialog->Color,6);
    SpeedButton1->Font->Color = (TColor)((~shBkColour->Brush->Color)&0x00FFFFFF);
}
//---------------------------------------------------------------------------
void __fastcall TDlgSettings::edBkColourChange(TObject *Sender)
{
    if(edBkColour->Text=="") edBkColour->Text = "000000";
    shBkColour->Brush->Color = (TColor)StrToInt("0x"+edBkColour->Text);
    SpeedButton1->Font->Color = (TColor)((~shBkColour->Brush->Color)&0x00FFFFFF);
}
//---------------------------------------------------------------------------
void __fastcall TDlgSettings::bcToolbarBitmapClick(TObject *Sender)
{
	Image1->Visible = bcToolbarBitmap->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TDlgSettings::udMaxUndosClick(TObject *Sender,
      TUDBtnType Button)
{
	edMaxUndos->Text = IntToStr(udMaxUndos->Position);
}
//---------------------------------------------------------------------------

