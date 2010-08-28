//---------------------------------------------------------------------------

#ifndef viewaniH
#define viewaniH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TDlgViewAni : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TTrackBar *TrackBar1;
	TPanel *Panel1;
	TLabel *Label2;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TTrackBar *TrackBar2;
	TTimer *Timer1;
	TImageList *ImageList1;
	TScrollBox *scbView;
	TImage *imgView;
	TShape *shpView;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall TrackBar2Change(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TDlgViewAni(TComponent* Owner);
    sciVIEW *view;
    sciVIEWLOOP *loop,*realLoop;
    int Cel,W,H;
    TWndGfxEdit *ViewEditWin;
    tPAL *pal;
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgViewAni *DlgViewAni;
//---------------------------------------------------------------------------
#endif
