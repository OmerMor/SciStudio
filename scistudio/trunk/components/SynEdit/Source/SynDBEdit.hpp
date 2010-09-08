// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SynDBEdit.pas' rev: 5.00

#ifndef SynDBEditHPP
#define SynDBEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SynEditTypes.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <SynEditHighlighter.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <SynEditMiscClasses.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SynEditKeyCmds.hpp>	// Pascal unit
#include <SynEdit.hpp>	// Pascal unit
#include <DBCtrls.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Syndbedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomDBSynEdit;
class PASCALIMPLEMENTATION TCustomDBSynEdit : public Synedit::TCustomSynEdit 
{
	typedef Synedit::TCustomSynEdit inherited;
	
private:
	Dbctrls::TFieldDataLink* FDataLink;
	bool FFocused;
	Classes::TNotifyEvent FOldOnChange;
	bool FBeginEdit;
	Classes::TNotifyEvent FLoadData;
	void __fastcall DataChange(System::TObject* Sender);
	void __fastcall EditingChange(System::TObject* Sender);
	AnsiString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	void __fastcall SetDataField(const AnsiString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetFocused(bool Value);
	void __fastcall UpdateData(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall CMEnter(Messages::TWMNoParams &Msg);
	HIDESBASE MESSAGE void __fastcall CMExit(Messages::TWMNoParams &Msg);
	MESSAGE void __fastcall CMGetDataLink(Messages::TMessage &Msg);
	
protected:
	virtual bool __fastcall GetReadOnly(void);
	virtual void __fastcall Loaded(void);
	void __fastcall NewOnChange(System::TObject* Sender);
	virtual void __fastcall SetReadOnly(bool Value);
	
public:
	__fastcall virtual TCustomDBSynEdit(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomDBSynEdit(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	virtual void __fastcall ExecuteCommand(Syneditkeycmds::TSynEditorCommand Command, char AChar, void * 
		Data);
	void __fastcall LoadMemo(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
protected:
	__property AnsiString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property Db::TField* Field = {read=GetField};
	__property Classes::TNotifyEvent OnLoadData = {read=FLoadData, write=FLoadData};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomDBSynEdit(HWND ParentWindow) : Synedit::TCustomSynEdit(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TDBSynEdit;
class PASCALIMPLEMENTATION TDBSynEdit : public TCustomDBSynEdit 
{
	typedef TCustomDBSynEdit inherited;
	
__published:
	__property DataField ;
	__property DataSource ;
	__property Field ;
	__property OnLoadData ;
	__property Align ;
	__property Anchors ;
	__property Constraints ;
	__property Color ;
	__property Ctl3D ;
	__property Enabled ;
	__property Font ;
	__property Height ;
	__property Name ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Tag ;
	__property Visible ;
	__property Width ;
	__property OnClick ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property BookMarkOptions ;
	__property BorderStyle ;
	__property ExtraLineSpacing ;
	__property Gutter ;
	__property HideSelection ;
	__property Highlighter ;
	__property InsertCaret ;
	__property InsertMode ;
	__property Keystrokes ;
	__property MaxLeftChar ;
	__property MaxUndo ;
	__property Options ;
	__property OverwriteCaret ;
	__property ReadOnly ;
	__property RightEdge ;
	__property RightEdgeColor ;
	__property ScrollBars ;
	__property SelectedColor ;
	__property SelectionMode ;
	__property TabWidth ;
	__property WantTabs ;
	__property OnChange ;
	__property OnCommandProcessed ;
	__property OnDropFiles ;
	__property OnGutterClick ;
	__property OnPaint ;
	__property OnPlaceBookmark ;
	__property OnProcessCommand ;
	__property OnProcessUserCommand ;
	__property OnReplaceText ;
	__property OnSpecialLineColors ;
	__property OnStatusChange ;
public:
	#pragma option push -w-inl
	/* TCustomDBSynEdit.Create */ inline __fastcall virtual TDBSynEdit(Classes::TComponent* AOwner) : TCustomDBSynEdit(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomDBSynEdit.Destroy */ inline __fastcall virtual ~TDBSynEdit(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDBSynEdit(HWND ParentWindow) : TCustomDBSynEdit(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Syndbedit */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Syndbedit;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SynDBEdit
