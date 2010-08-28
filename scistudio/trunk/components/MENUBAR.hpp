// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MenuBar.pas' rev: 5.00

#ifndef MenuBarHPP
#define MenuBarHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ToolWin.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Menubar
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TMenuBar;
class PASCALIMPLEMENTATION TMenuBar : public Comctrls::TToolBar 
{
	typedef Comctrls::TToolBar inherited;
	
private:
	Menus::TMainMenu* FMenu;
	void __fastcall SetMenu(const Menus::TMainMenu* Value);
	
protected:
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	
public:
	__fastcall virtual TMenuBar(Classes::TComponent* AOwner);
	
__published:
	__property EdgeBorders ;
	__property Menus::TMainMenu* Menu = {read=FMenu, write=SetMenu};
public:
	#pragma option push -w-inl
	/* TToolBar.Destroy */ inline __fastcall virtual ~TMenuBar(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TMenuBar(HWND ParentWindow) : Comctrls::TToolBar(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);

}	/* namespace Menubar */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Menubar;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MenuBar
