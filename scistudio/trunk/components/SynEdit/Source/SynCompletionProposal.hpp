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
#include <SynEditKbdHandler.hpp>	// Pascal unit
#include <SynEditHighlighter.hpp>	// Pascal unit
#include <SynEditKeyCmds.hpp>	// Pascal unit
#include <SynEditTypes.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Syncompletionproposal
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum SynCompletionType { ctCode, ctHint, ctParams };
#pragma option pop

typedef TForm TSynForm;
;

typedef bool __fastcall (__closure *TSynBaseCompletionProposalPaintItem)(AnsiString AKey, Graphics::TCanvas* 
	ACanvas, int X, int Y);

typedef void __fastcall (__closure *TCodeCompletionEvent)(AnsiString &Value, Classes::TShiftState Shift
	);

typedef void __fastcall (__closure *TValidateEvent)(System::TObject* Sender, Classes::TShiftState Shift
	);

typedef void __fastcall (__closure *TCompletionParameter)(System::TObject* Sender, int CurrentIndex, 
	int &Level, int &IndexToDisplay, char &Key, AnsiString &DisplayString);

typedef void __fastcall (__closure *TCompletionExecute)(SynCompletionType Kind, System::TObject* Sender
	, AnsiString &AString, int x, int y, bool &CanExecute);

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
	Classes::TStrings* FInsertList;
	Classes::TStrings* FAssignedList;
	int FPosition;
	int FNbLinesInWindow;
	int FFontHeight;
	Stdctrls::TScrollBar* Scroll;
	TValidateEvent FOnValidate;
	Classes::TNotifyEvent FOnCancel;
	Graphics::TColor FClSelect;
	Graphics::TColor fClText;
	Graphics::TColor fClSelectText;
	Graphics::TColor fClBackGround;
	bool FAnsi;
	bool fCase;
	bool fShrink;
	int FMouseWheelAccumulator;
	SynCompletionType FDisplayKind;
	TCompletionParameter FParameterToken;
	int FCurrentIndex;
	int FCurrentLevel;
	SynCompletionType FDefaultKind;
	bool FUsePrettyText;
	AnsiString FBiggestWord;
	bool FMatchText;
	AnsiString FEndOfTokenChr;
	bool OldShowCaret;
	void __fastcall SetCurrentString(const AnsiString Value);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	DYNAMIC void __fastcall Paint(void);
	void __fastcall ScrollGetFocus(System::TObject* Sender);
	DYNAMIC void __fastcall Activate(void);
	DYNAMIC void __fastcall Deactivate(void);
	void __fastcall MoveLine(int cnt);
	void __fastcall ScrollChange(System::TObject* Sender);
	void __fastcall ScrollOnScroll(System::TObject* Sender, Stdctrls::TScrollCode ScrollCode, int &ScrollPos
		);
	void __fastcall SetItemList(const Classes::TStrings* Value);
	void __fastcall SetInsertList(const Classes::TStrings* Value);
	HIDESBASE void __fastcall SetPosition(const int Value);
	void __fastcall SetNbLinesInWindow(const int Value);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	HIDESBASE MESSAGE void __fastcall WMMouseWheel(Messages::TMessage &Msg);
	void __fastcall StringListChange(System::TObject* Sender);
	void __fastcall DoDoubleClick(System::TObject* Sender);
	AnsiString __fastcall intLowerCase(AnsiString s);
	void __fastcall DoFormShow(System::TObject* Sender);
	void __fastcall DoFormHide(System::TObject* Sender);
	
private:
	Graphics::TBitmap* Bitmap;
	Classes::TComponent* fCurrentEditor;
	bool FUseInsertList;
	void __fastcall SetShrink(const bool Value);
	HIDESBASE MESSAGE void __fastcall WMActivate(Messages::TWMActivate &Message);
	
public:
	__fastcall virtual TSynBaseCompletionProposalForm(Classes::TComponent* AOwner);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	__fastcall virtual ~TSynBaseCompletionProposalForm(void);
	__property SynCompletionType DisplayType = {read=FDisplayKind, write=FDisplayKind, nodefault};
	__property SynCompletionType DefaultType = {read=FDefaultKind, write=FDefaultKind, nodefault};
	__property AnsiString CurrentString = {read=FCurrentString, write=SetCurrentString};
	__property int CurrentIndex = {read=FCurrentIndex, write=FCurrentIndex, nodefault};
	__property int CurrentLevel = {read=FCurrentLevel, write=FCurrentLevel, nodefault};
	__property TCompletionParameter OnParameterToken = {read=FParameterToken, write=FParameterToken};
	__property Controls::TKeyPressEvent OnKeyPress = {read=FOnKeyPress, write=FOnKeyPress};
	__property Classes::TNotifyEvent OnKeyDelete = {read=FOnKeyDelete, write=FOnKeyDelete};
	__property TSynBaseCompletionProposalPaintItem OnPaintItem = {read=FOnPaintItem, write=FOnPaintItem
		};
	__property TValidateEvent OnValidate = {read=FOnValidate, write=FOnValidate};
	__property Classes::TNotifyEvent OnCancel = {read=FOnCancel, write=FOnCancel};
	__property Classes::TStrings* ItemList = {read=FItemList, write=SetItemList};
	__property Classes::TStrings* InsertList = {read=FInsertList, write=SetInsertList};
	__property Classes::TStrings* AssignedList = {read=FAssignedList, write=FAssignedList};
	__property int Position = {read=FPosition, write=SetPosition, nodefault};
	__property int NbLinesInWindow = {read=FNbLinesInWindow, write=SetNbLinesInWindow, nodefault};
	__property AnsiString BiggestWord = {read=FBiggestWord, write=FBiggestWord};
	__property Graphics::TColor ClSelect = {read=FClSelect, write=FClSelect, nodefault};
	__property Graphics::TColor ClSelectedText = {read=fClSelectText, write=fClSelectText, nodefault};
	__property Graphics::TColor ClText = {read=fClText, write=fClText, nodefault};
	__property Graphics::TColor ClBackground = {read=fClBackGround, write=fClBackGround, nodefault};
	__property bool UsePrettyText = {read=FUsePrettyText, write=FUsePrettyText, default=0};
	__property bool UseInsertList = {read=FUseInsertList, write=FUseInsertList, default=0};
	__property bool AnsiStrings = {read=FAnsi, write=FAnsi, nodefault};
	__property bool CaseSensitive = {read=fCase, write=fCase, nodefault};
	__property Classes::TComponent* CurrentEditor = {read=fCurrentEditor, write=fCurrentEditor};
	__property bool MatchText = {read=FMatchText, write=FMatchText, nodefault};
	__property AnsiString EndOfTokenChr = {read=FEndOfTokenChr, write=FEndOfTokenChr};
	__property bool ShrinkList = {read=fShrink, write=SetShrink, nodefault};
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
	TSynBaseCompletionProposalForm* FForm;
	TCompletionExecute FOnExecute;
	int FWidth;
	AnsiString FBiggestWord;
	bool FUsePrettyText;
	int FDotOffset;
	int FOldPos;
	int FOldLeft;
	AnsiString FOldStr;
	bool FUseInsertList;
	AnsiString FEndOfTokenChr;
	Graphics::TColor __fastcall GetClSelect(void);
	void __fastcall SetClSelect(const Graphics::TColor Value);
	AnsiString __fastcall GetCurrentString();
	Classes::TStrings* __fastcall GetItemList(void);
	Classes::TStrings* __fastcall GetInsertList(void);
	int __fastcall GetNbLinesInWindow(void);
	Classes::TNotifyEvent __fastcall GetOnCancel();
	Controls::TKeyPressEvent __fastcall GetOnKeyPress();
	TSynBaseCompletionProposalPaintItem __fastcall GetOnPaintItem();
	TValidateEvent __fastcall GetOnValidate();
	int __fastcall GetPosition(void);
	void __fastcall SetCurrentString(const AnsiString Value);
	void __fastcall SetItemList(const Classes::TStrings* Value);
	void __fastcall SetInsertList(const Classes::TStrings* Value);
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
	SynCompletionType __fastcall GetDisplayKind(void);
	void __fastcall SetDisplayKind(const SynCompletionType Value);
	TCompletionParameter __fastcall GetParameterToken();
	void __fastcall SetParameterToken(const TCompletionParameter Value);
	SynCompletionType __fastcall GetDefaultKind(void);
	void __fastcall SetDefaultKind(const SynCompletionType Value);
	void __fastcall SetUsePrettyText(const bool Value);
	void __fastcall SetUseBiggestWord(const AnsiString Value);
	void __fastcall SetUseInsertList(const bool Value);
	bool __fastcall IsEndToken(char AChar);
	bool __fastcall GetCase(void);
	void __fastcall SetCase(const bool Value);
	Graphics::TColor __fastcall GetClBack(void);
	void __fastcall SetClBack(const Graphics::TColor Value);
	Graphics::TColor __fastcall GetClText(void);
	void __fastcall SetClText(const Graphics::TColor Value);
	Graphics::TColor __fastcall GetClSelectedText(void);
	void __fastcall SetClSelectedText(const Graphics::TColor Value);
	bool __fastcall GetMatchText(void);
	void __fastcall SetMatchText(const bool Value);
	void __fastcall SetEndOfTokenChar(const AnsiString Value);
	bool __fastcall GetShrink(void);
	void __fastcall SetShrink(const bool Value);
	
protected:
	virtual void __fastcall loaded(void);
	
public:
	__fastcall virtual TSynBaseCompletionProposal(Classes::TComponent* Aowner);
	__fastcall virtual ~TSynBaseCompletionProposal(void);
	void __fastcall Execute(AnsiString s, int x, int y);
	void __fastcall ExecuteEx(AnsiString s, int x, int y, SynCompletionType Kind);
	void __fastcall Activate(void);
	void __fastcall Deactivate(void);
	__property Controls::TKeyPressEvent OnKeyPress = {read=GetOnKeyPress, write=SetOnKeyPress};
	__property Classes::TNotifyEvent OnKeyDelete = {read=GetOnKeyDelete, write=SetOnKeyDelete};
	__property TValidateEvent OnValidate = {read=GetOnValidate, write=SetOnValidate};
	__property Classes::TNotifyEvent OnCancel = {read=GetOnCancel, write=SetOnCancel};
	__property AnsiString CurrentString = {read=GetCurrentString, write=SetCurrentString};
	__property int DotOffset = {read=FDotOffset, write=FDotOffset, nodefault};
	__property SynCompletionType DisplayType = {read=GetDisplayKind, write=SetDisplayKind, nodefault};
	__property TSynBaseCompletionProposalForm* Form = {read=FForm, write=FForm};
	
__published:
	__property SynCompletionType DefaultType = {read=GetDefaultKind, write=SetDefaultKind, nodefault};
	__property TCompletionExecute OnExecute = {read=FOnExecute, write=FOnExecute};
	__property TCompletionParameter OnParameterToken = {read=GetParameterToken, write=SetParameterToken
		};
	__property TSynBaseCompletionProposalPaintItem OnPaintItem = {read=GetOnPaintItem, write=SetOnPaintItem
		};
	void __fastcall ClearList(void);
	AnsiString __fastcall DisplayItem(int AIndex);
	AnsiString __fastcall InsertItem(int AIndex);
	void __fastcall AddItemAt(int Where, AnsiString ADisplayText, AnsiString AInsertText);
	void __fastcall AddItem(AnsiString ADisplayText, AnsiString AInsertText);
	__property Classes::TStrings* ItemList = {read=GetItemList, write=SetItemList};
	void __fastcall ResetAssignedList(void);
	__property Classes::TStrings* InsertList = {read=GetInsertList, write=SetInsertList};
	__property int Position = {read=GetPosition, write=SetPosition, nodefault};
	__property int NbLinesInWindow = {read=GetNbLinesInWindow, write=SetNbLinesInWindow, nodefault};
	__property Graphics::TColor ClSelect = {read=GetClSelect, write=SetClSelect, nodefault};
	__property Graphics::TColor ClText = {read=GetClText, write=SetClText, nodefault};
	__property Graphics::TColor ClSelectedText = {read=GetClSelectedText, write=SetClSelectedText, nodefault
		};
	__property Graphics::TColor ClBackground = {read=GetClBack, write=SetClBack, nodefault};
	__property bool AnsiStrings = {read=SFAnsi, write=RFAnsi, nodefault};
	__property bool CaseSensitive = {read=GetCase, write=SetCase, nodefault};
	__property bool ShrinkList = {read=GetShrink, write=SetShrink, nodefault};
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
	__property AnsiString BiggestWord = {read=FBiggestWord, write=SetUseBiggestWord};
	__property bool UsePrettyText = {read=FUsePrettyText, write=SetUsePrettyText, default=0};
	__property bool UseInsertList = {read=FUseInsertList, write=SetUseInsertList, default=0};
	__property AnsiString EndOfTokenChr = {read=FEndOfTokenChr, write=SetEndOfTokenChar};
	__property bool LimitToMatchedText = {read=GetMatchText, write=SetMatchText, nodefault};
};


class DELPHICLASS TSynCompletionProposal;
class PASCALIMPLEMENTATION TSynCompletionProposal : public TSynBaseCompletionProposal 
{
	typedef TSynBaseCompletionProposal inherited;
	
private:
	Classes::TShortCut FShortCut;
	Synedit::TCustomSynEdit* fEditor;
	Syneditkbdhandler::TKeyDownProc* fKeyDownProc;
	Syneditkbdhandler::TKeyPressProc* fKeyPressProc;
	AnsiString FEndOfTokenChr;
	bool fNoNextKey;
	TCodeCompletionEvent FOnCodeCompletion;
	void __fastcall SetEditor(const Synedit::TCustomSynEdit* Value);
	void __fastcall backspace(System::TObject* Sender);
	void __fastcall Cancel(System::TObject* Sender);
	void __fastcall Validate(System::TObject* Sender, Classes::TShiftState Shift);
	void __fastcall KeyPress(System::TObject* Sender, char &Key);
	void __fastcall EditorKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall EditorKeyPress(System::TObject* Sender, char &Key);
	AnsiString __fastcall GetPreviousToken(Synedit::TCustomSynEdit* FEditor);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	void __fastcall SetShortCut(Classes::TShortCut Value);
	
public:
	__fastcall virtual TSynCompletionProposal(Classes::TComponent* AOwner);
	__fastcall virtual ~TSynCompletionProposal(void);
	bool __fastcall RemoveEditor(Synedit::TCustomSynEdit* Editor);
	
__published:
	__property Classes::TShortCut ShortCut = {read=FShortCut, write=SetShortCut, nodefault};
	__property Synedit::TCustomSynEdit* Editor = {read=fEditor, write=SetEditor};
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
	Synedit::TCustomSynEdit* fEditor;
	Classes::TStrings* fAutoCompleteList;
	Syneditkbdhandler::TKeyDownProc* fKeyDownProc;
	Syneditkbdhandler::TKeyPressProc* fKeyPressProc;
	bool fNoNextKey;
	AnsiString FEndOfTokenChr;
	void __fastcall SetAutoCompleteList(Classes::TStrings* List);
	void __fastcall SetEditor(const Synedit::TCustomSynEdit* Value);
	
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
	bool __fastcall RemoveEditor(Synedit::TCustomSynEdit* Editor);
	AnsiString __fastcall GetTokenList();
	AnsiString __fastcall GetTokenValue(AnsiString Token);
	
__published:
	__property Classes::TStrings* AutoCompleteList = {read=fAutoCompleteList, write=SetAutoCompleteList
		};
	__property AnsiString EndOfTokenChr = {read=FEndOfTokenChr, write=FEndOfTokenChr};
	__property Synedit::TCustomSynEdit* Editor = {read=fEditor, write=SetEditor};
	__property Classes::TShortCut ShortCut = {read=FShortCut, write=SetShortCut, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall PrettyTextOut(Graphics::TCanvas* c, int x, int y, AnsiString s, bool 
	DoAlign, AnsiString BiggestWord);

}	/* namespace Syncompletionproposal */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Syncompletionproposal;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SynCompletionProposal
