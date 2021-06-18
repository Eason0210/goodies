// =================================================================================================
//   Diagnostics functions.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "stdafx.h"

#include "Diagnostics.h"

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <wchar.h>

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

extern HINSTANCE g_pluginInstance;

bool g_diagnostics = false;

static const wchar_t* const _ENV_VARIABLE_DIAGNOSTIC           = L"PW_PLUGIN_DIAGNOSTICS";
static const wchar_t        _ENV_VARIABLE_DIAGNOSTIC_SEPARATOR = L';';

// =================================================================================================
// =================================== FUNCTIONS PROTOTYPES ========================================
static std::wstring DiagnosticModeListGet();
static std::wstring PluginProductNameGet( const wchar_t* pluginDirFileExt_ );

// =================================================================================================
// =================================== FUNCTIONS DEFINITIONS =======================================

// =================================================================================================
// Retrieve the list of plug-ins in diagnostic mode
// -------------------------------------------------------------------------------------------------
std::wstring DiagnosticModeListGet()
{
    // Check the data size of the diagnostic list string in the environment variable
    size_t requiredSize = 0;
    _wgetenv_s( &requiredSize, nullptr, 0, _ENV_VARIABLE_DIAGNOSTIC );
    if ( requiredSize == 0 )
    {
        // Environment variable not found, no list!
        return L"";
    }

    // Retrieve the list of plug-in in diagnostic mode from the environment variable
    auto* pMemBuffer = new wchar_t[ requiredSize ];
    _wgetenv_s( &requiredSize, pMemBuffer, requiredSize, _ENV_VARIABLE_DIAGNOSTIC );
    std::wstring plugInWithDiagnosticList = pMemBuffer;
    delete[] pMemBuffer;

    return plugInWithDiagnosticList;
}

// =================================================================================================
// Retrieve the product name from the resources
// -------------------------------------------------------------------------------------------------
std::wstring PluginProductNameGet( const wchar_t* pluginDirFileExt_ )
{
    DWORD dummy;
    int   size = GetFileVersionInfoSize( pluginDirFileExt_, &dummy );
    if ( size != 0 )
    {
        auto* pMemBuffer = new char[ size ];
        auto  pVersion   = static_cast< LPVOID >( pMemBuffer );
        if ( GetFileVersionInfo( pluginDirFileExt_, 0, size, pVersion ) )
        {
            // Get the Company Name.
            // First, to get string information, we need to get language information.
            WORD*        langInfo;
            unsigned int bufSize;
            VerQueryValueW( pVersion, L"\\VarFileInfo\\Translation", ( void** )&langInfo, &bufSize );

            // Prepare the label -- default lang is bytes 0 & 1 of langInfo
            wchar_t nameQueryStr[ 128 ];
            swprintf_s( nameQueryStr, _countof( nameQueryStr ),
                        L"\\StringFileInfo\\%04x%04x\\ProductName",
                        langInfo[ 0 ], langInfo[ 1 ] );

            // Get the string from the resource data
            void* pName;
            if ( VerQueryValueW( pVersion, nameQueryStr, &pName, &bufSize ) )
            {
                auto* name = static_cast< wchar_t* >( pName );
                if ( wcslen( name ) )
                {
                    delete[] pMemBuffer;
                    return name;
                }
            }
        }
        delete[] pMemBuffer;
    }
    return L"";
}

// =================================================================================================
// Retrieve the diagnostic configuration for the plug-ins.
// -------------------------------------------------------------------------------------------------
void DiagnosticConfigurationUpdate()
{
    g_diagnostics = false;

    // Get the list of plug-in in diagnostic mode.
    std::wstring pluginsInDiagnostic = DiagnosticModeListGet();
    if ( pluginsInDiagnostic.empty() )
    {
        return;
    }

    // Retrieve the path and the name of the current plug-in.
    wchar_t pathAndName[ _MAX_PATH ];
    if ( ::GetModuleFileName( g_pluginInstance, pathAndName, _MAX_PATH ) == 0 )
    {
        return;
    }

    // Extract the product name from the resource. We want the same values as the one presented in the
    //  Workspace Manager.
    std::wstring pluginProductName = PluginProductNameGet( pathAndName );
    if ( pluginProductName.empty() )
    {
        return;
    }

    // Search for the present of the plug-in in the list of plug-ins in diagnostic to see if this
    //   plug-in has it enabled.
    std::wistringstream parser( pluginsInDiagnostic.c_str() );
    std::wstring        token;
    while ( getline( parser, token, _ENV_VARIABLE_DIAGNOSTIC_SEPARATOR ) )
    {
        if ( pluginProductName == token )
        {
            // Found!
            g_diagnostics = true;
            break;
        }
    }
}
