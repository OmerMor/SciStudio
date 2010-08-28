//---------------------------------------------------------------------------

#ifndef propertiesH
#define propertiesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TDlgProperties : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TLabel *Label1;
	TLabel *Label2;
	TBevel *Bevel1;
	TBevel *Bevel2;
	TLabel *Label4;
	TBevel *Bevel3;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TImage *Image1;
	TComboBox *cbResourceType;
	TEdit *EdtResourceNumber;
	TUpDown *UpDown1;
	TEdit *PackageOffset;
	TEdit *EncodedLength;
	TEdit *DecodedLength;
	TEdit *EncodingMethod;
	TEdit *Package;
	TButton *BitBtn1;
	TButton *BitBtn2;
	void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
	void __fastcall EdtResourceNumberChange(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall cbResourceTypeChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgProperties(TComponent* Owner);
    RESINFO *resInfo;
    void __fastcall FillInfo(RESINFO *_resInfo);       
	char szTemp[1024];
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgProperties *DlgProperties;
//---------------------------------------------------------------------------
#endif
