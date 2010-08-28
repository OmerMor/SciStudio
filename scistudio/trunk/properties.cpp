//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "scihdr.h"
#include "properties.h"
#include "explorer.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDlgProperties *DlgProperties;
//---------------------------------------------------------------------------
#define DRAW_ICON()\
	Image1->Canvas->Brush->Color = clBtnFace; \
    Image1->Canvas->FillRect(Rect(0,0,32,32));        \
    WndMain->ilResIcons->GetBitmap(GetResTypeIndex(cbResourceType->Items->Strings[cbResourceType->ItemIndex].c_str()),Image1->Picture->Bitmap)
//---------------------------------------------------------------------------
__fastcall TDlgProperties::TDlgProperties(TComponent* Owner)
	: TForm(Owner)
{
	cbResourceType->Items->Clear();
    for(int i=0;i<TOTAL_RES_TYPES;i++) {
    	if(GAME_USES_RES(i))
    		cbResourceType->Items->Add(AnsiString(resTypes[i].name));
    }
}
//---------------------------------------------------------------------------
void __fastcall TDlgProperties::FillInfo(RESINFO *_resInfo)
{
	resInfo = _resInfo;

    for(int i=0;i<TOTAL_RES_TYPES;i++) {
    	if(cbResourceType->Items->Strings[i]==AnsiString(resTypes[resInfo->type].name)) {
    		cbResourceType->ItemIndex = i;
            break;
        }
    }
    EdtResourceNumber->Text = IntToStr(resInfo->number);
    Package->Text = IntToStr(resInfo->pack);
    PackageOffset->Text = "0x"+IntToHex((__int64)resInfo->offset,8);
    EncodedLength->Text = IntToStr(resInfo->encSize);
    DecodedLength->Text = IntToStr(resInfo->size);
    EncodingMethod->Text = IntToStr(resInfo->encType);
	DRAW_ICON();
}
//---------------------------------------------------------------------------
void __fastcall TDlgProperties::UpDown1Click(TObject *Sender,
      TUDBtnType Button)
{
    int ResourceNumber;
	if(CheckStringNum(EdtResourceNumber->Text.c_str()))
		ResourceNumber = StrToInt(EdtResourceNumber->Text);
    else
		ResourceNumber = 0;


    if((Button == Comctrls::btPrev) && ResourceNumber > 0)
        ResourceNumber--;
    else if((Button == Comctrls::btNext) && ResourceNumber < 999)
        ResourceNumber++;

    EdtResourceNumber->Text = IntToStr(ResourceNumber);
}
//---------------------------------------------------------------------------
void __fastcall TDlgProperties::EdtResourceNumberChange(TObject *Sender)
{                                                
	if(!CheckStringNum(EdtResourceNumber->Text.c_str())) {
    	ssMessage(ssNOTICE, "The resource number must be between 0 and 999!");
        return;
    }

    UpDown1->Position = (short)StrToInt(EdtResourceNumber->Text);
}
//---------------------------------------------------------------------------
void __fastcall TDlgProperties::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TDlgProperties::BitBtn2Click(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------
void __fastcall TDlgProperties::BitBtn1Click(TObject *Sender)
{                                                       
	FILE *fMap,*fPack;
    U16 ident;
    // load the map
    if((fMap=FindMapEntry(resInfo,NULL))==NULL) return;
    sprintf(szTemp,"resource.%03d",resInfo->pack);
    if((fPack=ssOpenFile(ssFIO_GAME|ssFIO_MESSAGE,szTemp,"rb+"))==0) {
    	ssCloseFile(fMap);
    	return;
    }

    resInfo->type = GetResTypeIndex(cbResourceType->Items->Strings[cbResourceType->ItemIndex].c_str());
   	if(resInfo->type==-1) {
    	ssCloseFile(fMap);
    	return;
    }

    resInfo->number = (U16)StrToInt(EdtResourceNumber->Text);
    ident = (U16)rmSET_TYPE(resInfo->type)|(U16)rmSET_NUMBER(resInfo->number);
    ssFSeek(fPack,resInfo->offset,SEEK_SET);
	ssFPutW(ident,fMap);
	ssFPutW(ident,fPack);
    ssCloseFile(fMap);
    ssCloseFile(fPack);

    RESIDFO resIDfo;
    SetResIDfo(&resIDfo, resInfo);
    WndExplorer->ReopenGame();
    resInfo = FindRes(resIDfo.type, resIDfo.number, resIDfo.pack, -1);
    if(resInfo) // no way it'd be false, but good to DOUBLE check to be safe
    	WndExplorer->ResListViewGotoRes(resInfo);

	Close();
}
//---------------------------------------------------------------------------
void __fastcall TDlgProperties::cbResourceTypeChange(TObject *Sender)
{
	DRAW_ICON();
}
//---------------------------------------------------------------------------

