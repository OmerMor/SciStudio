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
#define TSynSpecialChars (System::Set<char, 0, 255> () << '\xc0' << '\xc1' << '\xc2' << '\xc3' << '\xc4' \
	<< '\xc5' << '\xc6' << '\xc7' << '\xc8' << '\xc9' << '\xca' << '\xcb' << '\xcc' << '\xcd' << '\xce' \
	<< '\xcf' << '\xd0' << '\xd1' << '\xd2' << '\xd3' << '\xd4' << '\xd5' << '\xd6' << '\xd8' << '\xd9' \
	<< '\xda' << '\xdb' << '\xdc' << '\xdd' << '\xde' << '\xdf' << '\xe0' << '\xe1' << '\xe2' << '\xe3' \
	<< '\xe4' << '\xe5' << '\xe6' << '\xe7' << '\xe8' << '\xe9' << '\xea' << '\xeb' << '\xec' << '\xed' \
	<< '\xee' << '\xef' << '\xf0' << '\xf1' << '\xf2' << '\xf3' << '\xf4' << '\xf5' << '\xf6' << '\xf8' \
	<< '\xf9' << '\xfa' << '\xfb' << '\xfc' << '\xfd' << '\xfe' << '\xff' )
#define TSynValidStringChars (System::Set<char, 0, 255> () )

}	/* namespace Synedittypes */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Synedittypes;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SynEditTypes
