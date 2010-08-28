// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SynMemo.pas' rev: 5.00

#ifndef SynMemoHPP
#define SynMemoHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SynEditTypes.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <SynEditKeyCmds.hpp>	// Pascal unit
#include <SynEditHighlighter.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <SynEditMiscClasses.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <SynEdit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Synmemo
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomSynMemo;
class PASCALIMPLEMENTATION TCustomSynMemo : public Synedit::TCustomSynEdit 
{
	typedef Synedit::TCustomSynEdit inherited;
	
public:
	Windows::TPoint __fastcall CharIndexToRowCol(int Index);
	int __fastcall RowColToCharIndex(const Windows::TPoint &RowCol);
public:
	#pragma option push -w-inl
	/* TCustomSynEdit.Create */ inline __fastcall virtual TCustomSynMemo(Classes::TComponent* AOwner) : 
		Synedit::TCustomSynEdit(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomSynEdit.Destroy */ inline __fastcall virtual ~TCustomSynMemo(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomSynMemo(HWND ParentWindow) : Synedit::TCustomSynEdit(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TSynMemo;
class PASCALIMPLEMENTATION TSynMemo : public TCustomSynMemo 
{
	typedef TCustomSynMemo inherited;
	
__published:
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
	__property Lines ;
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
	__property OnClearBookmark ;
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
	/* TCustomSynEdit.Create */ inline __fastcall virtual TSynMemo(Classes::TComponent* AOwner) : TCustomSynMemo(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomSynEdit.Destroy */ inline __fastcall virtual ~TSynMemo(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSynMemo(HWND ParentWindow) : TCustomSynMemo(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Synmemo */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Synmemo;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SynMemo
