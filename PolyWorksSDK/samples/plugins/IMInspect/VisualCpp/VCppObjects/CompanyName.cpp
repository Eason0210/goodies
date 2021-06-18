// =================================================================================================
//   File containing the plug-in exported methods necessary for it's connection to a PolyWorks
//   module.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

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
// EX: PolyWorks|Modeler will be corrupted if this plug-in is present without this header.

#include "VCppObjects.h"
#include "VCppObjects_i.c"

#include "PolyWorksSDK/Base/Version.h"

#include "CCompanyNameCppPlugin.h"

#include "resource.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

CAtlMfcModule _AtlModule;

AFX_EXTENSION_MODULE   g_afxExtensionModule = { FALSE, nullptr, nullptr, nullptr, nullptr };
CCompanyNameCppPlugin* g_pThePlugin         = nullptr;
HINSTANCE g_pluginInstance                  = 0;


// =================================================================================================
// =================================== FUNCTIONS PROTOTYPES ========================================

// =================================================================================================
// =================================== FUNCTIONS DEFINITIONS =======================================

#ifdef _MANAGED
#pragma managed(push, off)
#endif


// =================================================================================================
// The DLL main entry function used to initialize and uninitialize the plugin.
// -------------------------------------------------------------------------------------------------
extern "C" int APIENTRY DllMain( HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved )
{
    // Remove this if you use lpReserved
    UNREFERENCED_PARAMETER( lpReserved );

    if ( DLL_PROCESS_ATTACH == dwReason )
    {
        // Extension DLL one-time initialization
        if ( !AfxInitExtensionModule( g_afxExtensionModule, hInstance ) )
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

        g_pluginInstance = hInstance;

        // Creates the plugin
        g_pThePlugin = new CCompanyNameCppPlugin();
    }
    else if ( DLL_PROCESS_DETACH == dwReason )
    {
        // Destroys the plugin
        delete g_pThePlugin;
        g_pThePlugin = nullptr;

        // Terminate the library before destructors are called
        AfxTermExtensionModule( g_afxExtensionModule );
    }

    return 1; // ok
}

#ifdef _MANAGED
#pragma managed(pop)
#endif


// =================================================================================================
// Used to determine whether the DLL can be unloaded by OLE
// -------------------------------------------------------------------------------------------------
STDAPI DllCanUnloadNow()
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
STDAPI DllGetClassObject(
    REFCLSID rclsid_,
    REFIID   riid_,
    LPVOID*  ppv_ )
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
STDAPI DllRegisterServer()
{
    // registers object, typelib and all interfaces in typelib
    _AtlModule.UpdateRegistryAppId( TRUE );
    HRESULT hRes = _AtlModule.RegisterServer( TRUE );
    if ( hRes != S_OK )
    {
        return hRes;
    }

    if ( !AfxOleRegisterTypeLib( g_afxExtensionModule.hModule, LIBID_CompanyNameLib ) )
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
STDAPI DllUnregisterServer()
{
    const WORD wVerMajor = 1;
    const WORD wVerMinor = 0;

    _AtlModule.UpdateRegistryAppId( FALSE );
    HRESULT hRes = _AtlModule.UnregisterServer( TRUE );
    if ( hRes != S_OK )
    {
        return hRes;
    }

    if ( !AfxOleUnregisterTypeLib( LIBID_CompanyNameLib, wVerMajor, wVerMinor ) )
    {
        return SELFREG_E_TYPELIB;
    }

    if ( !COleObjectFactory::UpdateRegistryAll( FALSE ) )
    {
        return SELFREG_E_CLASS;
    }

    return S_OK;
}


// =================================================================================================
// Exported function necessary for a PolyWorks module to connect with the plug-in. Returns the
// plug-in interface pointer. The returned pointer will be kept by the host application until as
// long as the plug-in is loaded; it is the plug-in's reponsability to keep the pointer in a valid
// state.
//
// Return: Pointer to the plug-in's interface.
// -------------------------------------------------------------------------------------------------
extern "C" __declspec( dllexport ) IM::IPlugin* PluginInterfaceGet()
{
    return g_pThePlugin;
}


// =================================================================================================
// Returns the PolyWorks' version with which the plug-in was built. Depending on the returned
// version, the host application could refuse the connection due to a version incompatibility. In
// such a case, the plug-in developper would need to recompile the plug-in with a more recent
// version of the PolyWorks SDK.
//
// Parameter: major_ : [out] PolyWorks' major version (major_.minor_.dot_)
// Parameter: minor_ : [out] PolyWorks' minor version (major_.minor_.dot_)
// Parameter: dot_   : [out] PolyWorks' dot version (major_.minor_.dot_)
// -------------------------------------------------------------------------------------------------
extern "C" __declspec( dllexport ) void SDKVersionGet(
    unsigned short& major_,
    unsigned short& minor_,
    unsigned short& dot_ )
{
    major_ = IM::SDK_VERSION_MAJOR;
    minor_ = IM::SDK_VERSION_MINOR;
    dot_   = IM::SDK_VERSION_DOT;
}
