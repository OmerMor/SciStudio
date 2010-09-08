// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SynCompletionProposal.pas' rev: 5.00

#ifndef SynCompletionProposalHPP
#define SynCompletionProposalHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SynEdit.hpp>	// Pascal unit
#include <SynEditHighlighter.hpp>	// Pascal unit
#include <SynEditKeyCmds.hpp>	// Pascal unit
#include <SynEditTypes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Syncompletionproposal
{
//-- type declarations -------------------------------------------------------
typedef bool __fastcall (__closure *TSynBaseCompletionProposalPaintItem)(AnsiString AKey, Graphics::TCanvas* 
	ACanvas, int X, int Y);

typedef void __fastcall (__closure *TCodeCompletionEvent)(AnsiString &Value, Classes::TShiftState Shift
	);

typedef void __fastcall (__closure *TValidateEvent)(System::TObject* Sender, Classes::TShiftState Shift
	);

class DELPHICLASS TSynBaseCompletionProposalForm;
class PASCALIMPLEMENTATION TSynBaseCompletionProposalForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
protected:
	AnsiString FCurrentString;
	Controls::TKeyPressEvent FOnKeyPress;
	Classes::TNotifyEvent FOnKeyDelete;
	TSynBaseCompletionProposalPaintItem FOnPaintItem;
	Classes::TStrings* FItemList;
	int FPosition;
	int FNbLinesInWindow;
	int FFontHeight;
	Stdctrls::TScrollBar* Scroll;
	TValidateEvent FOnValidate;
	Classes::TNotifyEvent FOnCancel;
	Graphics::TColor FClSelect;
	bool FAnsi;
	void __fastcall SetCurrentString(const AnsiString Value);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	DYNAMIC void __fastcall Paint(void);
	void __fastcall ScrollGetFocus(System::TObject* Sender);
	DYNAMIC void __fastcall Deactivate(void);
	void __fastcall SelectPrec(void);
	HIDESBASE void __fastcall SelectNext(void);
	void __fastcall ScrollChange(System::TObject* Sender);
	void __fastcall SetItemList(const Classes::TStrings* Value);
	HIDESBASE void __fastcall SetPosition(const int Value);
	void __fastcall SetNbLinesInWindow(const int Value);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	void __fastcall StringListChange(System::TObject* Sender);
	
private:
	Graphics::TBitmap* Bitmap;
	Classes::TComponent* fCurrentEditor;
	
public:
	__fastcall virtual TSynBaseCompletionProposalForm(Classes::TComponent* AOwner);
	__fastcall virtual ~TSynBaseCompletionProposalForm(void);
	
__published:
	__property AnsiString CurrentString = {read=FCurrentString, write=SetCurrentString};
	__property Controls::TKeyPressEvent OnKeyPress = {read=FOnKeyPress, write=FOnKeyPress};
	__property Classes::TNotifyEvent OnKeyDelete = {read=FOnKeyDelete, write=FOnKeyDelete};
	__property TSynBaseCompletionProposalPaintItem OnPaintItem = {read=FOnPaintItem, write=FOnPaintItem
		};
	__property TValidateEvent OnValidate = {read=FOnValidate, write=FOnValidate};
	__property Classes::TNotifyEvent OnCancel = {read=FOnCancel, write=FOnCancel};
	__property Classes::TStrings* ItemList = {read=FItemList, write=SetItemList};
	__property int Position = {read=FPosition, write=SetPosition, nodefault};
	__property int NbLinesInWindow = {read=FNbLinesInWindow, write=SetNbLinesInWindow, nodefault};
	__property Graphics::TColor ClSelect = {read=FClSelect, write=FClSelect, nodefault};
	__property bool ffAnsi = {read=FAnsi, write=FAnsi, nodefault};
	__property Classes::TComponent* CurrentEditor = {read=fCurrentEditor, write=fCurrentEditor};
public:
		
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSynBaseCompletionProposalForm(Classes::TComponent* 
		AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSynBaseCompletionProposalForm(HWND ParentWindow
		) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TSynBaseCompletionProposal;
class PASCALIMPLEMENTATION TSynBaseCompletionProposal : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TSynBaseCompletionProposalForm* Form;
	Classes::TNotifyEvent FOnExecute;
	int FWidth;
	Graphics::TColor __fastcall GetClSelect(void);
	void __fastcall SetClSelect(const Graphics::TColor Value);
	AnsiString __fastcall GetCurrentString();
	Classes::TStrings* __fastcall GetItemList(void);
	int __fastcall GetNbLinesInWindow(void);
	Classes::TNotifyEvent __fastcall GetOnCancel();
	Controls::TKeyPressEvent __fastcall GetOnKeyPress();
	TSynBaseCompletionProposalPaintItem __fastcall GetOnPaintItem();
	TValidateEvent __fastcall GetOnValidate();
	int __fastcall GetPosition(void);
	void __fastcall SetCurrentString(const AnsiString Value);
	void __fastcall SetItemList(const Classes::TStrings* Value);
	void __fastcall SetNbLinesInWindow(const int Value);
	void __fastcall SetOnCancel(const Classes::TNotifyEvent Value);
	void __fastcall SetOnKeyPress(const Controls::TKeyPressEvent Value);
	void __fastcall SetOnPaintItem(const TSynBaseCompletionProposalPaintItem Value);
	void __fastcall SetPosition(const int Value);
	void __fastcall SetOnValidate(const TValidateEvent Value);
	Classes::TNotifyEvent __fastcall GetOnKeyDelete();
	void __fastcall SetOnKeyDelete(const Classes::TNotifyEvent Value);
	void __fastcall RFAnsi(const bool Value);
	bool __fastcall SFAnsi(void);
	void __fastcall SetWidth(int Value);
	
public:
	__fastcall virtual TSynBaseCompletionProposal(Classes::TComponent* Aowner);
	__fastcall virtual ~TSynBaseCompletionProposal(void);
	void __fastcall Execute(AnsiString s, int x, int y);
	void __fastcall Deactivate(void);
	__property Controls::TKeyPressEvent OnKeyPress = {read=GetOnKeyPress, write=SetOnKeyPress};
	__property Classes::TNotifyEvent OnKeyDelete = {read=GetOnKeyDelete, write=SetOnKeyDelete};
	__property TValidateEvent OnValidate = {read=GetOnValidate, write=SetOnValidate};
	__property Classes::TNotifyEvent OnCancel = {read=GetOnCancel, write=SetOnCancel};
	__property AnsiString CurrentString = {read=GetCurrentString, write=SetCurrentString};
	
__published:
	__property Classes::TNotifyEvent OnExecute = {read=FOnExecute, write=FOnExecute};
	__property TSynBaseCompletionProposalPaintItem OnPaintItem = {read=GetOnPaintItem, write=SetOnPaintItem
		};
	__property Classes::TStrings* ItemList = {read=GetItemList, write=SetItemList};
	__property int Position = {read=GetPosition, write=SetPosition, nodefault};
	__property int NbLinesInWindow = {read=GetNbLinesInWindow, write=SetNbLinesInWindow, nodefault};
	__property Graphics::TColor ClSelect = {read=GetClSelect, write=SetClSelect, nodefault};
	__property bool AnsiStrings = {read=SFAnsi, write=RFAnsi, nodefault};
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
};


class DELPHICLASS TSynCompletionProposal;
class PASCALIMPLEMENTATION TSynCompletionProposal : public TSynBaseCompletionProposal 
{
	typedef TSynBaseCompletionProposal inherited;
	
private:
	Classes::TShortCut FShortCut;
	Classes::TList* fEditors;
	Classes::TList* fEditstuffs;
	AnsiString FEndOfTokenChr;
	TCodeCompletionEvent FOnCodeCompletion;
	void __fastcall SetEditor(const Synedit::TCustomSynEdit* Value);
	void __fastcall backspace(System::TObject* Senter);
	void __fastcall Cancel(System::TObject* Senter);
	void __fastcall Validate(System::TObject* Senter, Classes::TShiftState Shift);
	void __fastcall KeyPress(System::TObject* Sender, char &Key);
	void __fastcall EditorKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall EditorKeyPress(System::TObject* Sender, char &Key);
	AnsiString __fastcall GetPreviousToken(Synedit::TCustomSynEdit* FEditor);
	Synedit::TCustomSynEdit* __fastcall GetFEditor(void);
	Synedit::TCustomSynEdit* __fastcall GetEditor(int i);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	void __fastcall SetShortCut(Classes::TShortCut Value);
	
public:
	__fastcall virtual TSynCompletionProposal(Classes::TComponent* AOwner);
	__fastcall virtual ~TSynCompletionProposal(void);
	__property Synedit::TCustomSynEdit* Editors[int i] = {read=GetEditor};
	void __fastcall AddEditor(Synedit::TCustomSynEdit* Editor);
	bool __fastcall RemoveEditor(Synedit::TCustomSynEdit* Editor);
	int __fastcall EditorsCount(void);
	
__published:
	__property Classes::TShortCut ShortCut = {read=FShortCut, write=SetShortCut, nodefault};
	__property Synedit::TCustomSynEdit* Editor = {read=GetFEditor, write=SetEditor};
	__property AnsiString EndOfTokenChr = {read=FEndOfTokenChr, write=FEndOfTokenChr};
	__property TCodeCompletionEvent OnCodeCompletion = {read=FOnCodeCompletion, write=FOnCodeCompletion
		};
};


class DELPHICLASS TSynAutoComplete;
class PASCALIMPLEMENTATION TSynAutoComplete : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TShortCut FShortCut;
	Classes::TList* fEditors;
	Classes::TList* fEditstuffs;
	Classes::TStrings* fAutoCompleteList;
	AnsiString FEndOfTokenChr;
	void __fastcall SetAutoCompleteList(Classes::TStrings* List);
	Synedit::TCustomSynEdit* __fastcall GetEditor(int i);
	Synedit::TCustomSynEdit* __fastcall GetEdit(void);
	void __fastcall SetEdit(const Synedit::TCustomSynEdit* Value);
	
protected:
	void __fastcall SetShortCut(Classes::TShortCut Value);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	virtual void __fastcall EditorKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift
		);
	virtual void __fastcall EditorKeyPress(System::TObject* Sender, char &Key);
	AnsiString __fastcall GetPreviousToken(Synedit::TCustomSynEdit* Editor);
	
public:
	__fastcall virtual TSynAutoComplete(Classes::TComponent* AOwner);
	__fastcall virtual ~TSynAutoComplete(void);
	void __fastcall Execute(AnsiString token, Synedit::TCustomSynEdit* Editor);
	__property Synedit::TCustomSynEdit* Editors[int i] = {read=GetEditor};
	void __fastcall AddEditor(Synedit::TCustomSynEdit* Editor);
	bool __fastcall RemoveEditor(Synedit::TCustomSynEdit* Editor);
	int __fastcall EditorsCount(void);
	AnsiString __fastcall GetTokenList();
	AnsiString __fastcall GetTokenValue(AnsiString Token);
	
__published:
	__property Classes::TStrings* AutoCompleteList = {read=fAutoCompleteList, write=SetAutoCompleteList
		};
	__property AnsiString EndOfTokenChr = {read=FEndOfTokenChr, write=FEndOfTokenChr};
	__property Synedit::TCustomSynEdit* Editor = {read=GetEdit, write=SetEdit};
	__property Classes::TShortCut ShortCut = {read=FShortCut, write=SetShortCut, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall PretyTextOut(Graphics::TCanvas* c, int x, int y, AnsiString s);

}	/* namespace Syncompletionproposal */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Syncompletionproposal;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SynCompletionProposal
