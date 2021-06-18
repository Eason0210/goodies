// =================================================================================================
//   Implementation of DLL Exports.
//
// Copyright © InnovMetric Software Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL,
//      run nmake -f CompanyNameScannerps.mk in the project directory.

#include "stdafx.h"
#include <afxdllx.h>    // Don't remove (required if _AFXEXT is used)

// NOTE from MSDN
//
// The header file AFXDLLX.H contains special definitions for structures used in extension DLLs,
// such as the definition for AFX_EXTENSION_MODULE and CDynLinkLibrary.
//
// If this header is not included, it will compile but calls to AfxTermExtensionModule( ) will
// cause MFC stack corruption when an application does not support a plug-in DLL. The DLL will
// be loaded then unloaded immediately resulting a call to AfxTermExtensionModule( ).
//
// EX: IMEdit will be corrupted if this plug-in is present without this header.

#include "CompanyNamePolygonalModelScanner.h"

#include "resource.h"
#include <initguid.h>

#include "CompanyNamePolygonalModelScanner_i.c"

#include "CCompanyNameScanner.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

class CCompanyNameScannerModule : public CAtlMfcModule
{
public:
    DECLARE_LIBID( LIBID_COMPANYNAMEPOLYGONALMODELSCANNERLib );

    HRESULT AddCommonRGSReplacements( IRegistrarBase* pRegistrar_ ) throw( ) override
    {
        if ( pRegistrar_ == nullptr )
        {
            return S_FALSE;
        }

        HRESULT hr = S_OK;
        if ( SUCCEEDED( hr = pRegistrar_->AddReplacement( L"IID",   L"{D10E4D18-C9DE-4E69-AB9F-A4FB2697E64F}" ) ) &&
             SUCCEEDED( hr = pRegistrar_->AddReplacement( L"TLBID", L"{DF4B9AC1-5A7A-4E53-ACA4-621CE4167372}" ) ) &&
             SUCCEEDED( hr = pRegistrar_->AddReplacement( L"CLSID", L"{D9234185-7439-4B5A-8F9A-6BCBCBCA4A62}" ) ) &&
             SUCCEEDED( hr = pRegistrar_->AddReplacement( L"APPID", L"{D9234185-7439-4B5A-8F9A-6BCBCBCA4A62}" ) ) )
        {
            /*hr = CAtlModule::AddCommonRGSReplacements( pRegistrar_ );                                */
        }
        return hr;
    }
};

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

AFX_EXTENSION_MODULE g_afxExtensionModule = {};

CCompanyNameScannerModule _AtlModule;

HINSTANCE g_pluginInstance = nullptr;

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

BEGIN_OBJECT_MAP( ObjectMap )
    OBJECT_ENTRY( CLSID_CompanyNamePolygonalModelScanner, CCompanyNameScanner )
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

#ifdef _MANAGED
#pragma managed(push, off)
#endif


// =================================================================================================
// The DLL main entry function used to initialize and uninitialize the plugin.
// -------------------------------------------------------------------------------------------------
extern "C" int APIENTRY DllMain( HINSTANCE hInstance_, DWORD dwReason_, LPVOID lpReserved_ )
{
    // Remove this if you use lpReserved
    UNREFERENCED_PARAMETER( lpReserved_ );

    if ( DLL_PROCESS_ATTACH == dwReason_ )
    {
        // Extension DLL one-time initialization
        if ( !AfxInitExtensionModule( g_afxExtensionModule, hInstance_ ) )
        {
            return 0;
        }

        // Insert this DLL into the resource chain
        // NOTE: If this Extension DLL is being implicitly linked to by
        //  an MFC Regular DLL (such as an ActiveX Control)
        //  instead of an MFC application, then you will want to
        //  remove this line from DllMain and put it in a separate
        //  function exported from this Extension DLL.  The Regular DLL
        //  that uses this Extension DLL should then explicitly call that
        //  function to initialize this Extension DLL.  Otherwise,
        //  the CDynLinkLibrary object will not be attached to the
        //  Regular DLL's resource chain, and serious problems will
        //  result.
        new CDynLinkLibrary( g_afxExtensionModule );

        g_pluginInstance = hInstance_;

        DisableThreadLibraryCalls( g_pluginInstance );
    }
    else if ( DLL_PROCESS_DETACH == dwReason_ )
    {
        // Terminate the library before destructors are called
        AfxTermExtensionModule( g_afxExtensionModule );

        _AtlModule.Term();
    }

    return 1; // ok
}

#ifdef _MANAGED
#pragma managed(pop)
#endif


// =================================================================================================
// Used to determine whether the DLL can be unloaded by OLE
// -------------------------------------------------------------------------------------------------
STDAPI DllCanUnloadNow( void )
{
    if ( _AtlModule.GetLockCount() > 0 )
    {
        return S_FALSE;
    }

    return AfxDllCanUnloadNow();
}

// =================================================================================================
// Returns a class factory to create an object of the requested type
// -------------------------------------------------------------------------------------------------
STDAPI DllGetClassObject( REFCLSID rclsid_, REFIID riid_, LPVOID* ppv_ )
{
    if ( S_OK == _AtlModule.GetClassObject( rclsid_, riid_, ppv_ ) )
    {
        return S_OK;
    }

    return AfxDllGetClassObject( rclsid_, riid_, ppv_ );
}

// =================================================================================================
// Adds entries to the system registry
// -------------------------------------------------------------------------------------------------
STDAPI DllRegisterServer( void )
{
    // registers object, typelib and all interfaces in typelib
    _AtlModule.UpdateRegistryAppId( TRUE );
    HRESULT hRes = _AtlModule.RegisterServer( TRUE );
    if ( hRes != S_OK )
    {
        return hRes;
    }

    if ( !AfxOleRegisterTypeLib( g_afxExtensionModule.hModule, LIBID_COMPANYNAMEPOLYGONALMODELSCANNERLib ) )
    {
        return SELFREG_E_TYPELIB;
    }

    if ( !COleObjectFactory::UpdateRegistryAll() )
    {
        return SELFREG_E_CLASS;
    }

    return S_OK;
}

// =================================================================================================
// Removes entries from the system registry
// -------------------------------------------------------------------------------------------------
STDAPI DllUnregisterServer( void )
{
    const WORD wVerMajor = 1;
    const WORD wVerMinor = 0;

    _AtlModule.UpdateRegistryAppId( FALSE );
    HRESULT hRes = _AtlModule.UnregisterServer( TRUE );
    if ( hRes != S_OK )
    {
        return hRes;
    }

    if ( !AfxOleUnregisterTypeLib( LIBID_COMPANYNAMEPOLYGONALMODELSCANNERLib, wVerMajor, wVerMinor ) )
    {
        return SELFREG_E_TYPELIB;
    }

    if ( !COleObjectFactory::UpdateRegistryAll( FALSE ) )
    {
        return SELFREG_E_CLASS;
    }

    return S_OK;
}
