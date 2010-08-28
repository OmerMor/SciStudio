//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "printprev.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SynEditPrintPreview"
#pragma resource "*.dfm"
TDlgPrintPrev *DlgPrintPrev;
//---------------------------------------------------------------------------
__fastcall TDlgPrintPrev::TDlgPrintPrev(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDlgPrintPrev::FormShow(TObject *Sender)
{
    SynEditPrintPreview1->UpdatePreview();
    SynEditPrintPreview1->Paint();
    BtnFirstClick(this);
}     
//---------------------------------------------------------------------------
void __fastcall TDlgPrintPrev::UpdateUI()
{
    BtnFirst->Enabled =
            SynEditPrintPreview1->PageNumber!=1;
    BtnPrev->Enabled =
            SynEditPrintPreview1->PageNumber!=1;
    BtnNext->Enabled =
        SynEditPrintPreview1->SynEditPrint->PageCount!=
            SynEditPrintPreview1->PageNumber;
    BtnLast->Enabled =
        SynEditPrintPreview1->SynEditPrint->PageCount!=
            SynEditPrintPreview1->PageNumber;

    StatusBar1->Panels->Items[0]->Text = "Page "+
        IntToStr(SynEditPrintPreview1->PageNumber)+" of "+
        IntToStr(SynEditPrintPreview1->SynEditPrint->PageCount);
    StatusBar1->Panels->Items[1]->Text = "Scale "+
        IntToStr(SynEditPrintPreview1->ScalePercent)+"%";
}
//---------------------------------------------------------------------------

void __fastcall TDlgPrintPrev::ToolButton1Click(TObject *Sender)
{
    SynEditPrintPreview1->Print();
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TDlgPrintPrev::BtnFirstClick(TObject *Sender)
{
    SynEditPrintPreview1->FirstPage();
    UpdateUI();
}
//---------------------------------------------------------------------------

void __fastcall TDlgPrintPrev::BtnPrevClick(TObject *Sender)
{
    SynEditPrintPreview1->PreviousPage();
    UpdateUI();
}
//---------------------------------------------------------------------------

void __fastcall TDlgPrintPrev::BtnNextClick(TObject *Sender)
{
    SynEditPrintPreview1->NextPage();
    UpdateUI();
}
//---------------------------------------------------------------------------

void __fastcall TDlgPrintPrev::BtnLastClick(TObject *Sender)
{
    SynEditPrintPreview1->LastPage();
    UpdateUI();
}
//---------------------------------------------------------------------------

void __fastcall TDlgPrintPrev::ToolButton5Click(TObject *Sender)
{
    SynEditPrintPreview1->ScalePercent += 20;
    UpdateUI();
}
//---------------------------------------------------------------------------

void __fastcall TDlgPrintPrev::ToolButton6Click(TObject *Sender)
{
    if(SynEditPrintPreview1->ScalePercent > 20)
        SynEditPrintPreview1->ScalePercent -= 20;
    UpdateUI();
}
//---------------------------------------------------------------------------

void __fastcall TDlgPrintPrev::ToolButton2Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TDlgPrintPrev::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
}
//---------------------------------------------------------------------------

