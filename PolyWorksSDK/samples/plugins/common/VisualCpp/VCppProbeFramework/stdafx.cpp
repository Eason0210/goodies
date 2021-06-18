// stdafx.cpp : source file that includes just the standard includes
//  stdafx.pch will be the pre-compiled header
//  stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

#if _MSC_VER < 1400

#ifdef _ATL_STATIC_REGISTRY
#include <statreg.h>
#include <statreg.cpp>
#endif // ifdef _ATL_STATIC_REGISTRY

#include <atlimpl.cpp>

#endif // _MSC_VER < 1400 (Visual Studio 2005)
