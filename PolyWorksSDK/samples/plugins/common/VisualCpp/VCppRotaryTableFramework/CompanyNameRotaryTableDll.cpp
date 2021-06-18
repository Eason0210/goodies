// CompanyNameRotaryTable.cpp : Implementation of DLL Exports.

#include "stdafx.h"

#include <initguid.h>

#include "CCompanyNameRotaryTablePlugin.h"
#include "CompanyNameRotaryTable_i.c"
#include "resource.h"

HINSTANCE  g_pluginInstance = 0;
CComModule _Module;

BEGIN_OBJECT_MAP( ObjectMap )
    OBJECT_ENTRY( CLSID_CompanyNameRotaryTablePlugin, CCompanyNameRotaryTablePlugin )
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain( HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/ )
{
    if ( dwReason == DLL_PROCESS_ATTACH )
    {
        _Module.Init( ObjectMap, hInstance, &LIBID_COMPANYNAMEROTARYTABLELib );
        DisableThreadLibraryCalls( hInstance );

        g_pluginInstance = hInstance;
    }
    else if ( dwReason == DLL_PROCESS_DETACH )
    {
        _Module.Term();
    }
    return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow( void )
{
    return ( _Module.GetLockCount() == 0 ) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject( REFCLSID rclsid, REFIID riid, LPVOID* ppv )
{
    return _Module.GetClassObject( rclsid, riid, ppv );
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer( void )
{
    // registers object, typelib and all interfaces in typelib
    return _Module.RegisterServer( TRUE );
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer( void )
{
    return _Module.UnregisterServer( TRUE );
}
