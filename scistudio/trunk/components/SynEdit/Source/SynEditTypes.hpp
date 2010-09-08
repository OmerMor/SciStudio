// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SynEditTypes.pas' rev: 5.00

#ifndef SynEditTypesHPP
#define SynEditTypesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Synedittypes
{
//-- type declarations -------------------------------------------------------
typedef Set<char, 0, 255>  TSynIdentChars;

#pragma option push -b-
enum TSynSelectionMode { smNormal, smLine, smColumn };
#pragma option pop

typedef TSynSelectionMode *PSynSelectionMode;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Synedittypes */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Synedittypes;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SynEditTypes
