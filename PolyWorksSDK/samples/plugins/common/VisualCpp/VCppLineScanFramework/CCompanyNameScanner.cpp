// =================================================================================================
//   Implementation of CCompanyNameScanner.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CCompanyNameScanner.h"

#include <PolyWorksSDK/COM/IIMAlign.h>
#include <PolyWorksSDK/COM/IIMAlign_i.c>
#include <PolyWorksSDK/COM/IIMAlignProject.h>
#include <PolyWorksSDK/COM/IIMCommand.h>
#include <PolyWorksSDK/COM/IIMCommandCenter.h>
#include <PolyWorksSDK/COM/IIMHost_i.c>
#include <PolyWorksSDK/COM/IIMInspect.h>
#include <PolyWorksSDK/COM/IIMInspect_i.c>
#include <PolyWorksSDK/COM/IIMInspectProject.h>
#include <assert.h>
#include <sstream>

#include "ApplicationUtils.h"
#include "CComCommandInfo.h"
#include "CComCommandParameter.h"
#include "CComCommandParameterEnum.h"
#include "CComCommandParameterInfo.h"
#include "CCompanyNameCmd.h"
#include "CCompanyNameScannerSettings.h"
#include "CDlgIMAlign.h"
#include "CDlgIMInspect.h"
#include "Diagnostics.h"
#include "SafeArrayConversion.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

extern bool g_diagnostics;

static const wchar_t* const _pluginMenuLocation = L"CompanyName\\Line Scanner...";

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

static bool ReceiverUpdateAndLaunch( CCompanyNameScannerReceiver* pReceiver_, IIMLineScan* pLineScan_, IIMPointCloud* pPointCloud_ );

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

// =================================================================================================
// Updates the Receiver's parameters and starts scanning
bool ReceiverUpdateAndLaunch(
    CCompanyNameScannerReceiver* pReceiver_,
    IIMLineScan*                 pLineScan_,
    IIMPointCloud*               pPointCloud_ )
{
    if ( ( pReceiver_   == nullptr ) ||
         ( ( pLineScan_   == nullptr ) &&
           ( pPointCloud_ == nullptr ) ) )
    {
        return false;
    }

    int nbLines = theCompanyNameScannerSettings().NbLinesTransferredGet();
    pReceiver_->NbLinesToAccumulateSet( nbLines );

    int refreshDelay = theCompanyNameScannerSettings().RefreshDelayGet();
    pReceiver_->RefreshDelaySet( refreshDelay );

    bool res = pReceiver_->ReceiveScanData( pLineScan_, pPointCloud_ );
    if ( res )
    {
        bool useAutoViewpoint = false;
        // TODO: Put the value of the "Use automatic viewpoint" check box in the useAutoViewpoint variable
        pReceiver_->EnableAutoViewpoint( useAutoViewpoint );
    }

    if ( res )
    {
        res = pReceiver_->ScanStart();
        if ( !res )
        {
            pReceiver_->ReceiveScanDataCancel();

            HWND dialogHandle = nullptr;
            // TODO: Set dialogHandle to the handle of the dialog
            IMMessageBox( E_MESSAGE_TYPE_ERROR, L"Unable to start scanning", dialogHandle );
        }
    }

    return res;
}

/////////////////////////////////////////////////////////////////////////////
// CCompanyNameScanner

CCompanyNameScanner::CCompanyNameScanner()
{
}

//////////////// IIMPlugin ////////////////////////

// =================================================================================================
// Adds MSCL commands to the commands vector member variable.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScanner::CommandsAdd()
{
    // DIGITIZE DEVICE COMPANY_NAME SCAN BOUNDARY MAX_POINT_TO_POINT_DIST [GET]
    // ------------------------------------------------------------------------

    {
        CComCommandInfo cmdInfo( g_cmdSharpEdgeMaxPointToPointDistSet, L"Sets the sharp edge max point to point distance." );

        CComCommandParameterInfo param01( L"Max distance", E_PARAM_DIR_IN, E_PARAM_TYPE_DOUBLE );
        param01.ValuesSet( L"Greater than 0" );
        cmdInfo.ParameterEnumGet().CommandParameterAdd( new CComCommandParameter( param01 ) );

        // Add the command to the command vector
        m_commands.push_back( new CCmdSharpEdgeMaxPointToPointDist( cmdInfo, m_Receiver, false ) );
    }

    {
        CComCommandInfo cmdInfo( g_cmdSharpEdgeMaxPointToPointDistGet, L"Gets the sharp edge max point to point distance." );

        CComCommandParameterInfo param01( L"Max distance", E_PARAM_DIR_OUT, E_PARAM_TYPE_DOUBLE );
        param01.ValuesSet( L"Greater than 0" );
        cmdInfo.ParameterEnumGet().CommandParameterAdd( new CComCommandParameter( param01 ) );

        // Add the command to the command vector
        m_commands.push_back( new CCmdSharpEdgeMaxPointToPointDist( cmdInfo, m_Receiver, true ) );
    }

    // DIGITIZE DEVICE COMPANY_NAME SCAN BOUNDARY MIN_EDGE_ANGLE [GET]
    // ---------------------------------------------------------------

    {
        CComCommandInfo cmdInfo( g_cmdSharpEdgeMinAngleSet, L"Sets the sharp edge min angle." );

        CComCommandParameterInfo param01( L"Min angle", E_PARAM_DIR_IN, E_PARAM_TYPE_DOUBLE );
        param01.ValuesSet( L"Greater than 0 and smaller than 180" );
        cmdInfo.ParameterEnumGet().CommandParameterAdd( new CComCommandParameter( param01 ) );

        // Add the command to the command vector
        m_commands.push_back( new CCmdSharpEdgeMinAngle( cmdInfo, m_Receiver, false ) );
    }

    {
        CComCommandInfo cmdInfo( g_cmdSharpEdgeMinAngleGet, L"Gets the sharp edge min angle." );

        CComCommandParameterInfo param01( L"Min angle", E_PARAM_DIR_OUT, E_PARAM_TYPE_DOUBLE );
        param01.ValuesSet( L"Greater than 0 and smaller than 180" );
        cmdInfo.ParameterEnumGet().CommandParameterAdd( new CComCommandParameter( param01 ) );

        // Add the command to the command vector
        m_commands.push_back( new CCmdSharpEdgeMinAngle( cmdInfo, m_Receiver, true ) );
    }

    // DIGITIZE DEVICE COMPANY_NAME SCAN OPTIONS DLG PROPERTY_GRID LOG
    // ---------------------------------------------------------------

    {
        CComCommandInfo cmdInfo( g_cmdOptionsDlgPropertyGridLog, L"Logs the content of the options dialog property grid." );

        CComCommandParameterInfo param01( L"Log file path", E_PARAM_DIR_IN, E_PARAM_TYPE_STRING );
        cmdInfo.ParameterEnumGet().CommandParameterAdd( new CComCommandParameter( param01 ) );

        // Add the command to the command vector
        m_commands.push_back( new CCmdLog( cmdInfo, m_Receiver ) );
    }
}

// =================================================================================================
// Releases any commands added in CommandsAdd.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScanner::CommandsRemove()
{
    m_commands.clear();
}

STDMETHODIMP CCompanyNameScanner::PlgNameGet(
    /* [out] */ BSTR* pName_ )
{
    ::SysFreeString( *pName_ );

    *pName_ = ::SysAllocString( g_PluginName );
    assert( *pName_ != nullptr );

    return ( *pName_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}


STDMETHODIMP CCompanyNameScanner::PlgVersionGet(
    /* [out] */ long* pMajor_,
    /* [out] */ long* pMinor_,
    /* [out] */ long* pDot_ )
{
    int major = 1;
    int minor = 0;
    int dot   = 0;
    // TODO: Set appropriate version info
    *pMajor_ = ( long ) major;
    *pMinor_ = ( long ) minor;
    *pDot_   = ( long ) dot;

    return S_OK;
}


STDMETHODIMP CCompanyNameScanner::Load(
    /* [in] */ IIMHost*       pIIMHost_,
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( ( pIIMHost_ == nullptr ) ||
         ( pReturnVal_ == nullptr ) )
    {
        return S_FALSE;
    }

    *pReturnVal_ = 0;

    // Configure diagnostics
    DiagnosticConfigurationUpdate();

    // TODO Using the g_diagnostics value, implement special case to diagnose the plug-in
    if ( g_diagnostics )
    {
        // The diagnostic is enabled, let the user know.
        const wchar_t* pMessage = L"Diagnostics are activated for this plug-in.\n\nDiagnostics can be deactivated on the Plug-ins page of the Workspace Manager options.";
        ::MessageBoxW( nullptr, pMessage, L"Diagnostics", MB_OK );
    }

    EHostApplication app = E_APPLICATION_UNKNOWN;

    // We can accept PolyWorks|Inspector...
    CComQIPtr< IIMInspect > pIMInspect( pIIMHost_ );
    if ( pIMInspect != nullptr )
    {
        app = E_APPLICATION_IMINSPECT;

        // Obtains IIMCommandCenter from PolyWorks|Inspector project
        CComPtr< IIMInspectProject > pIMInspectProject;
        pIMInspect->ProjectGetCurrent( &pIMInspectProject );

        if ( pIMInspectProject != nullptr )
        {
            CComPtr< IIMCommandCenter > pCommandCenter;
            pIMInspectProject->CommandCenterCreate( &( pCommandCenter ) );

            if ( pCommandCenter != nullptr )
            {
                GITRegisterInterfaceInGlobal( pCommandCenter, IID_IIMCommandCenter, &g_cookieCommandCenter );
            }
        }

        *pReturnVal_ = 1;
    }
    else
    {
        // ... or IMAlign
        CComQIPtr< IIMAlign > pIMAlign( pIIMHost_ );
        if ( pIMAlign != nullptr )
        {
            app = E_APPLICATION_IMALIGN;

            // Obtains IIMCommandCenter from IMAlign project
            CComPtr< IIMAlignProject > pIMAlignProject;
            pIMAlign->ProjectGetCurrent( &pIMAlignProject );

            if ( pIMAlignProject != nullptr )
            {
                CComPtr< IIMCommandCenter > pCommandCenter;
                pIMAlignProject->CommandCenterCreate( &( pCommandCenter ) );

                if ( pCommandCenter != nullptr )
                {
                    GITRegisterInterfaceInGlobal( pCommandCenter, IID_IIMCommandCenter, &g_cookieCommandCenter );
                }
            }

            *pReturnVal_ = 1;
        }
    }


    if ( *pReturnVal_ == 1 )
    {
        theCompanyNameScannerSettings().Initialize( app );

        if ( GITRegisterInterfaceInGlobal( pIIMHost_, IID_IIMHost, &g_cookieHost ) != S_OK )
        {
            *pReturnVal_ = 0;
        }
    }

    return ( *pReturnVal_ == 1 ) ? S_OK : S_FALSE;
}


STDMETHODIMP CCompanyNameScanner::Unload(
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( m_Receiver.m_pDlgCompanyName != nullptr )
    {
        m_Receiver.m_dataThread.ThreadKill(); // Stop data transfer

        m_Receiver.m_pDlgCompanyName->ScanEnd();
    }

    m_Receiver.InterfacePopdown();

    *pReturnVal_ = ( m_Receiver.Disconnect() ? 1 : 0 );

    m_Receiver.Reset();

    // Release the IIMCommandCenter
    GITRevokeInterfaceFromGlobal( g_cookieCommandCenter );

    GITRevokeInterfaceFromGlobal( g_cookieHost );

    CommandsRemove();

    return ( *pReturnVal_ == 1 ) ? S_OK : S_FALSE;
}

//////////////// IIMScanner ////////////////////////

STDMETHODIMP CCompanyNameScanner::ScanningDeviceNameGet( /* [retval][out] */ BSTR* pName_ )
{
    ::SysFreeString( *pName_ );

    *pName_ = ::SysAllocString( g_PluginName );
    assert( *pName_ != nullptr );

    return ( *pName_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}

STDMETHODIMP CCompanyNameScanner::ScanningConnectionInit(
    /* [in] */ IIMScannerFeedback* pScannerFeedback_,
    /* [retval][out] */ long*      pReturnVal_ )
{
    if ( pReturnVal_ == nullptr )
    {
        return S_FALSE;
    }

    *pReturnVal_ = 0;

    if ( !m_Receiver.Connect() )
    {
        return S_FALSE;
    }

    if ( pScannerFeedback_ != nullptr )
    {
        GITRegisterInterfaceInGlobal( pScannerFeedback_, IID_IIMScannerFeedback, &g_cookieScannerFeedback );
    }

    // Synchronize the host application with our own settings
    std::wstring command;
    command  = g_cmdAutoViewpointSet;
    command += L"( \"";
    command += theCompanyNameScannerSettings().UseAutoViewpointGet() ? L"On" : L"Off";
    command += L"\" )";
    ExecuteCommandOnApp( command.c_str() );

    command  = g_cmdAutoViewpointVerticalAxisSet;
    command += L"( \"";
    command += g_StandardAxes[ theCompanyNameScannerSettings().DeviceVerticalAxisGet() ];
    command += L"\" )";
    ExecuteCommandOnApp( command.c_str() );

    std::wstringstream stream;
    stream << g_cmdAutoViewpointCloseUpZoomSet
           << L"( \""
           << theCompanyNameScannerSettings().AutoViewpointZoomCloseUpGet()
           << L"\" )";
    command = stream.str();
    ExecuteCommandOnApp( command.c_str() );

    m_Receiver.EnableRealTimeMeshing( theCompanyNameScannerSettings().IMIRealTimeMeshingGet() );

    *pReturnVal_ = 1;

    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::ScanningConnectionEnd( /* [retval][out] */ long* pReturnVal_ )
{
    if ( pReturnVal_ != nullptr )
    {
        *pReturnVal_ = m_Receiver.Disconnect() ? 1 : 0;
        return ( *pReturnVal_ ) ? S_OK : S_FALSE;
    }
    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::ScanningDlgShow()
{
    return ( m_Receiver.InterfacePopup() ) ? S_OK : S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::ScanningDlgClose()
{
    return ( m_Receiver.InterfacePopdown() ) ? S_OK : S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::ScanNameDefaultGet(
    /* [retval][out] */ BSTR* /* pName_ */ )
{
    // This method is now obsolete

    return E_NOTIMPL;
}

STDMETHODIMP CCompanyNameScanner::ScanNameSet(
    /* [in] */ BSTR /* name_ */ )
{
    // This method is now obsolete

    return E_NOTIMPL;
}

STDMETHODIMP CCompanyNameScanner::MeshMaxEdgeLengthGet(
    /* [retval][out] */ double* pMaxEdgeLength_ )
{
    if ( pMaxEdgeLength_ != nullptr )
    {
        double scalingFactor = theCompanyNameScannerSettings().HostUnitsScalingFactorGet();
        *pMaxEdgeLength_ = theCompanyNameScannerSettings().IMAMaxEdgeLengthGet() * scalingFactor;
        return S_OK;
    }
    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::MeshMaxEdgeLengthSet(
    /* [in] */ double maxEdgeLength_ )
{
    double scalingFactor = theCompanyNameScannerSettings().HostUnitsScalingFactorGet();
    theCompanyNameScannerSettings().IMAMaxEdgeLengthSet( maxEdgeLength_ / scalingFactor );
    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::MeshInterpolationStepGet(
    /* [retval][out] */ double* pInterpolationStep_ )
{
    if ( pInterpolationStep_ != nullptr )
    {
        double scalingFactor = theCompanyNameScannerSettings().HostUnitsScalingFactorGet();
        *pInterpolationStep_ = theCompanyNameScannerSettings().IMAInterpolationStepGet() * scalingFactor;
        return S_OK;
    }
    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::MeshInterpolationStepSet(
    /* [in] */ double interpolationStep_ )
{
    double scalingFactor = theCompanyNameScannerSettings().HostUnitsScalingFactorGet();
    theCompanyNameScannerSettings().IMAInterpolationStepSet( interpolationStep_ / scalingFactor );
    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::MeshMaxAngleGet(
    /* [retval][out] */ double* pMaxAngle_ )
{
    if ( pMaxAngle_ != nullptr )
    {
        *pMaxAngle_ = theCompanyNameScannerSettings().IMAMaxAngleGet();
        return S_OK;
    }
    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::MeshMaxAngleSet(
    /* [in] */ double maxAngle_ )
{
    theCompanyNameScannerSettings().IMAMaxAngleSet( maxAngle_ );
    return S_OK;
}

//////////////// IIMScanner2 ////////////////////////

STDMETHODIMP CCompanyNameScanner::ScanningDeviceMenuLocationGet( /* [retval][out] */ BSTR* pMenuPath_ )
{
    ::SysFreeString( *pMenuPath_ );

    *pMenuPath_ = ::SysAllocString( _pluginMenuLocation );
    assert( *pMenuPath_ != nullptr );

    return ( *pMenuPath_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}

//////////////// IIMScanner3 ////////////////////////
STDMETHODIMP CCompanyNameScanner::OnScanningEvent( /* [in] */ EScanningEvents event_ )
{
    // TODO: React to the scanning events that might happen in the host application
    // Ex:
    //if( event_ == E_SCANNING_EVENT_LEAVING_SCAN_MODE )
    //{
    //    // Any reaction to this event...
    //}

    switch ( event_ )
    {
        case E_SCANNING_EVENT_DEVICE_SELECTED:
        case E_SCANNING_EVENT_UPDATE_APP_SETTINGS:
            m_Receiver.UpdateFromSettings();
            break;
        case E_SCANNING_EVENT_APP_SETTING_MODIFIED:
            m_Receiver.UpdateSettingsFromApp( true );
            break;
        case E_SCANNING_EVENT_POST_PROFILE_CHANGED:
            m_Receiver.UpdateSettingsFromApp( false );
            m_Receiver.UpdateFromSettings();
            break;
    }

    return S_OK;
}

//////////////// IIMScanner4 ////////////////////////
STDMETHODIMP CCompanyNameScanner::DeviceDeprecatedNamesGet( /* [out][in] */ SAFEARRAY** pNames_ )
{
    // TODO: Implement this method only if your plug-in changes name and there
    //       are existing scripts using the deprecated name(s).
    return E_NOTIMPL;
}


STDMETHODIMP CCompanyNameScanner::ScanningOptionsDlgShow()
{
    const EHostApplication host = theCompanyNameScannerSettings().HostApplicationGet();
    if ( host == E_APPLICATION_IMINSPECT )
    {
        m_Receiver.DlgIMInspectOptionsShow( nullptr );
    }
    else if ( host == E_APPLICATION_IMALIGN )
    {
        m_Receiver.DlgIMAlignOptionsShow( nullptr );
    }

    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::HasScanningOptionsDlg( /* [retval][out] */ VARIANT_BOOL* pHasOptionsDlg_ )
{
    if ( pHasOptionsDlg_ != nullptr )
    {
        const EHostApplication host = theCompanyNameScannerSettings().HostApplicationGet();
        if ( host == E_APPLICATION_IMINSPECT ||
             host == E_APPLICATION_IMALIGN )
        {
            *pHasOptionsDlg_ = VARIANT_TRUE;
        }
        else
        {
            *pHasOptionsDlg_ = VARIANT_FALSE;
        }
    }
    return S_FALSE;
}

//////////////// IIMLineScanner ////////////////////////

STDMETHODIMP CCompanyNameScanner::ScanningStart(
    /* [ in ] */ IIMLineScan*   pIIMLineScan_,
    /* [ in ] */ IIMPointCloud* pIIMPointCloud_,
    /* [retval][out] */ long*   pReturnVal_ )
{
    if ( ( pReturnVal_ == nullptr ) ||
         ( ( pIIMLineScan_   == nullptr ) &&
           ( pIIMPointCloud_ == nullptr ) ) )
    {
        return S_FALSE;
    }

    *pReturnVal_ = 0;

    m_Receiver.CursorSegmentsMaxDistSet( theCompanyNameScannerSettings().CursorSegmentsMaxDistGet() );

    // Starts the acquisition
    if ( ReceiverUpdateAndLaunch( &m_Receiver, pIIMLineScan_, pIIMPointCloud_ ) )
    {
        // Turn on real-time inspection, if requested
        bool useRTI = false;
        if ( theCompanyNameScannerSettings().HostApplicationGet() == E_APPLICATION_IMINSPECT &&
             !theCompanyNameScannerSettings().IMIRealTimeMeshingGet() )
        {
            useRTI = theCompanyNameScannerSettings().IMIRealTimeInspectionGet();
        }
        m_Receiver.EnableRealTimeInspection( useRTI );

        // TODO: Optional: if you want your plug-in to support sharp edge scanning (E_SCAN_TYPE_SHARP_EDGE)
        //       or object scanning (E_SCAN_TYPE_OBJECT) (see ScanTypeSet to accept those scan types),
        //       you will need to keep the pPointCloud_ interface pointer in the GIT (using
        //       GITRegisterInterfaceInGlobal) and in these cases instead of calling
        //       Line[s]Add on the IIMLineScan to send points, you will have to call PointsAdd
        //       on the IIMPointCloud interface.
        m_Receiver.DoAcquisitionStart();

        *pReturnVal_ = 1;

        return S_OK;
    }

    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::ScanningEnd( /* [retval][out] */ long* pReturnVal_ )
{
    if ( pReturnVal_ == nullptr )
    {
        return S_FALSE;
    }

    m_Receiver.ScanEnd();
    m_Receiver.DoAcquisitionEnd();

    m_Receiver.ReceiveScanDataCancel();

    *pReturnVal_ = 1;

    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::ScanTypeGet( /* [retval][out] */ EScanTypes* pScanType_ )
{
    if ( pScanType_ != nullptr )
    {
        *pScanType_ = theCompanyNameScannerSettings().ScanTypeGet();
        return S_OK;
    }
    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::ScanTypeSet(
    /* [ in ] */ EScanTypes   scanType_,
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( pReturnVal_ == nullptr )
    {
        return S_FALSE;
    }

    // TODO: Optional: if you want your plug-in to support sharp edge scanning (E_SCAN_TYPE_SHARP_EDGE)
    //       or object scanning (E_SCAN_TYPE_OBJECT) (see ScanTypeSet to accept those scan types),
    //       add them to the list of supported types below.
    //       You will then have to perform additionnal scan data processing to either extract
    //       and send only boundary points (for boundary scanning) or to create objects
    //       (using MSCL scripts, for example) and send only points related to those objects.
    if ( scanType_ == E_SCAN_TYPE_SURFACE ||
         scanType_ == E_SCAN_TYPE_SURFACE_AND_BOUNDARY ||
         scanType_ == E_SCAN_TYPE_SHARP_EDGE )
    {
        theCompanyNameScannerSettings().ScanTypeSet( scanType_ );

        // Update the dialog
        if ( m_Receiver.m_pDlgCompanyName != nullptr )
        {
            m_Receiver.m_pDlgCompanyName->DialogUpdate();
        }

        *pReturnVal_ = 1;
        return S_OK;
    }
    else
    {
        *pReturnVal_ = 0;
        return S_FALSE;
    }
}

STDMETHODIMP CCompanyNameScanner::ExtractNormalsGet(
    /* [retval][out] */ VARIANT_BOOL* pExtractNormals_ )
{
    if ( pExtractNormals_ != nullptr )
    {
        *pExtractNormals_ = theCompanyNameScannerSettings().IMIExtractNormalsGet() ? VARIANT_TRUE : VARIANT_FALSE;
        return S_OK;
    }
    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::ExtractNormalsSet(
    /* [in] */ VARIANT_BOOL extractNormals_ )
{
    theCompanyNameScannerSettings().IMIExtractNormalsSet( extractNormals_ == VARIANT_TRUE );
    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::ExtractNormalsMinSearchDistGet(
    /* [retval][out] */ double* pMinSearchDist_ )
{
    if ( pMinSearchDist_ != nullptr )
    {
        double scalingFactor = theCompanyNameScannerSettings().HostUnitsScalingFactorGet();
        *pMinSearchDist_ = theCompanyNameScannerSettings().IMIMinSearchDistGet() * scalingFactor;
        return S_OK;
    }
    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::ExtractNormalsMinSearchDistSet(
    /* [in] */ double minSearchDist_ )
{
    double scalingFactor = theCompanyNameScannerSettings().HostUnitsScalingFactorGet();
    theCompanyNameScannerSettings().IMIMinSearchDistSet( minSearchDist_ / scalingFactor );
    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::ExtractNormalsMaxSearchDistGet(
    /* [retval][out] */ double* pMaxSearchDist_ )
{
    if ( pMaxSearchDist_ != nullptr )
    {
        double scalingFactor = theCompanyNameScannerSettings().HostUnitsScalingFactorGet();
        *pMaxSearchDist_ = theCompanyNameScannerSettings().IMIMaxSearchDistGet() * scalingFactor;
        return S_OK;
    }
    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::ExtractNormalsMaxSearchDistSet(
    /* [in] */ double maxSearchDist_ )
{
    double scalingFactor = theCompanyNameScannerSettings().HostUnitsScalingFactorGet();
    theCompanyNameScannerSettings().IMIMaxSearchDistSet( maxSearchDist_ / scalingFactor );
    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::ExtractHoleBoundariesGet(
    /* [retval][out] */ VARIANT_BOOL* pExtractHoleBoundaries_ )
{
    if ( pExtractHoleBoundaries_ != nullptr )
    {
        // TODO: If you need to extract boundaries when scanning objects (scan type E_SCAN_TYPE_OBJECT),
        //       return VARIANT_TRUE instead of the VARIANT_FALSE below.
        *pExtractHoleBoundaries_ = VARIANT_FALSE;
        return S_OK;
    }
    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::ExtractHoleBoundariesSet(
    /* [in] */ VARIANT_BOOL extractHoleBoundaries_ )
{
    // Reserved for future use.
    return E_NOTIMPL;
}

STDMETHODIMP CCompanyNameScanner::ExtractHoleBoundariesMinWidthGet(
    /* [retval][out] */ double* pMinWidth_ )
{
    if ( pMinWidth_ != nullptr )
    {
        double scalingFactor = theCompanyNameScannerSettings().HostUnitsScalingFactorGet();
        *pMinWidth_ = theCompanyNameScannerSettings().IMIMinHoleWidthGet() * scalingFactor;
        return S_OK;
    }
    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::ExtractHoleBoundariesMinWidthSet(
    /* [in] */ double minWidth_ )
{
    double scalingFactor = theCompanyNameScannerSettings().HostUnitsScalingFactorGet();
    theCompanyNameScannerSettings().IMIMinHoleWidthSet( minWidth_ / scalingFactor );
    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::TestModeGet(
    /* [retval][out] */ VARIANT_BOOL* pTestMode_ )
{
    if ( pTestMode_ != nullptr )
    {
        *pTestMode_ = theCompanyNameScannerSettings().TestModeGet() ? VARIANT_TRUE : VARIANT_FALSE;
        return S_OK;
    }
    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::TestModeSet(
    /* [in] */ VARIANT_BOOL testMode_ )
{
    theCompanyNameScannerSettings().TestModeSet( testMode_ == VARIANT_TRUE );
    return S_OK;
}

//////////////// IIMLineScanner2 ////////////////////////
STDMETHODIMP CCompanyNameScanner::RealTimeComparisonGet( /* [retval][out] */ VARIANT_BOOL* pRealTimeComp_ )
{
    if ( pRealTimeComp_ != nullptr )
    {
        if ( theCompanyNameScannerSettings().IMIRealTimeInspectionGet() )
        {
            *pRealTimeComp_ = VARIANT_TRUE;
        }
        else
        {
            *pRealTimeComp_ = VARIANT_FALSE;
        }

        return S_OK;
    }

    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::RealTimeComparisonSet( /* [in] */ VARIANT_BOOL realTimeComp_ )
{
    CCompanyNameScannerSettings& settings = theCompanyNameScannerSettings();

    bool use = realTimeComp_ == VARIANT_TRUE;
    settings.IMIRealTimeInspectionSet( use );
    m_Receiver.EnableRealTimeInspection( use );

    // Update the dialog to show the new setting
    m_Receiver.m_pDlgCompanyName->DialogUpdate();

    return S_OK;
}


//////////////// IIMCommandEnum ////////////////////////

STDMETHODIMP CCompanyNameScanner::CmdsGetNb(
    /* [retval][out] */ long* pArgNb_ )
{
    if ( m_commands.empty() )
    {
        CommandsAdd();
    }

    *pArgNb_ = static_cast< long >( m_commands.size() );

    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::CmdGet(
    /* [in] */ long          number_,
    /* [out] */ IIMCommand** pIIMCommand_ )
{
    if ( ( pIIMCommand_ != nullptr ) &&
         ( number_ >= 0 ) &&
         ( number_ < static_cast< long >( m_commands.size() ) ) )
    {
        ( *pIIMCommand_ ) = m_commands[ number_ ];
        ( *pIIMCommand_ )->AddRef();

        return S_OK;
    }

    return S_FALSE;
}


//////////////// IIMLanguage ////////////////////////

STDMETHODIMP CCompanyNameScanner::LanguageSet(
    /* [in] */ BSTR           pLanguage_,
    /* [in] */ BSTR           pFontName_,
    /* [in] */ ECharacterSets charSet_ )
{
    // Validate the parameters
    if ( ( pLanguage_ == nullptr ) || ( wcslen( pLanguage_ ) == 0 ) ||
         ( pFontName_ == nullptr ) || ( wcslen( pFontName_ ) == 0 ) )
    {
        return S_FALSE;
    }

    // TODO: Translate the dialogs in the appropriate language
    //       If this is not required, then remove this method
    //       and all references to IIMLanguage

    return S_OK;
}

//////////////// IIMScanningObjectsUser /////////////

STDMETHODIMP CCompanyNameScanner::ScanningObjectsSet(
    /* [in] */ EScanTypes  scanType_,
    /* [in] */ SAFEARRAY** pArrayObjects_,
    /* [in] */ BSTR        currentChoice_ )
{
    if ( pArrayObjects_ == nullptr ||
         currentChoice_ == nullptr )
    {
        return S_FALSE;
    }

    TWStrings objectNames;
    SafeArrayConversion::SafeArrayStringsGet( pArrayObjects_, objectNames );

    m_Receiver.ScanningObjectsSet( scanType_, objectNames, currentChoice_ );

    return S_OK;
}

//////////////// IIMScanningProfilesUser /////////////

STDMETHODIMP CCompanyNameScanner::ScanningProfileSettingsGet(
    /* [out][in] */ SAFEARRAY** pProfileSettings_ )
{
    TWStrings profileSettings;
    theCompanyNameScannerSettings().ScanningProfileSettingsGet( profileSettings );

    return SafeArrayConversion::SafeArrayStringsSet( profileSettings, pProfileSettings_ ) ? S_OK : S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::StandardScanningProfileDoubleSettingValueGet(
    /* [in] */ EStandardScanningProfiles standardProfile_,
    /* [in] */ BSTR                      setting_,
    /* [out] */ double*                  pValue_ )
{
    if ( pValue_ == nullptr )
    {
        return S_FALSE;
    }

    return theCompanyNameScannerSettings().StandardScanningProfileDoubleSettingValueGet( standardProfile_, setting_, *pValue_ ) ? S_OK : E_INVALIDARG;
}

STDMETHODIMP CCompanyNameScanner::StandardScanningProfileLongSettingValueGet(
    /* [in] */ EStandardScanningProfiles standardProfile_,
    /* [in] */ BSTR                      setting_,
    /* [out] */ long*                    pValue_ )
{
    if ( pValue_ == nullptr )
    {
        return S_FALSE;
    }

    return theCompanyNameScannerSettings().StandardScanningProfileLongSettingValueGet( standardProfile_, setting_, *pValue_ ) ? S_OK : E_INVALIDARG;
}

STDMETHODIMP CCompanyNameScanner::StandardScanningProfileStringSettingValueGet(
    /* [in] */ EStandardScanningProfiles standardProfile_,
    /* [in] */ BSTR                      setting_,
    /* [out] */ BSTR*                    pValue_ )
{
    if ( pValue_ == nullptr )
    {
        return S_FALSE;
    }

    ::SysFreeString( *pValue_ );

    std::wstring value;
    if ( !theCompanyNameScannerSettings().StandardScanningProfileStringSettingValueGet( standardProfile_, setting_, value ) )
    {
        return E_INVALIDARG;
    }

    *pValue_ = ::SysAllocString( value.c_str() );
    return ( *pValue_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}

STDMETHODIMP CCompanyNameScanner::ScanningProfilesSet(
    /* [in] */ SAFEARRAY** pCmdArgNames_,
    /* [in] */ SAFEARRAY** pDisplayNames_,
    /* [in] */ SAFEARRAY** pInfos_,
    /* [in] */ BSTR        current_ )
{
    if ( ( pCmdArgNames_  == nullptr ) ||
         ( pDisplayNames_ == nullptr ) ||
         ( pInfos_        == nullptr ) ||
         ( current_       == nullptr ) )
    {
        return S_FALSE;
    }

    TWStrings profileCmdArgNames;
    TWStrings profileDisplayNames;
    TWStrings profileAdditionnalInfos;
    if ( !SafeArrayConversion::SafeArrayStringsGet( pCmdArgNames_, profileCmdArgNames )   ||
         !SafeArrayConversion::SafeArrayStringsGet( pDisplayNames_, profileDisplayNames ) ||
         !SafeArrayConversion::SafeArrayStringsGet( pInfos_, profileAdditionnalInfos ) )
    {
        return FALSE;
    }

    m_Receiver.ScanningProfilesSet( profileCmdArgNames, profileDisplayNames, profileAdditionnalInfos, current_ );

    return S_OK;
}

//////////////// IIMSettings ////////////////////////

STDMETHODIMP CCompanyNameScanner::DoubleSettingsNbGet(
    /* [out] */ long* nbSettings_ )
{
    return theCompanyNameScannerSettings().DoubleSettingsNbGet( nbSettings_ );
}


STDMETHODIMP CCompanyNameScanner::DoubleSettingGet(
    /* [in] */ long           settingIndex_,
    /* [out] */ BSTR*         pSettingName_,
    /* [out] */ double*       pDefaultValue_,
    /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    return theCompanyNameScannerSettings().DoubleSettingGet(
        settingIndex_,
        pSettingName_,
        pDefaultValue_,
        pIsUserSpecific_,
        pIsHostSpecific_,
        pIsProjectSetting_ );
}


STDMETHODIMP CCompanyNameScanner::LongSettingsNbGet(
    /* [out] */ long* nbSettings_ )
{
    return theCompanyNameScannerSettings().LongSettingsNbGet( nbSettings_ );
}


STDMETHODIMP CCompanyNameScanner::LongSettingGet(
    /* [in] */ long           settingIndex_,
    /* [out] */ BSTR*         pSettingName_,
    /* [out] */ long*         pDefaultValue_,
    /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    return theCompanyNameScannerSettings().LongSettingGet(
        settingIndex_,
        pSettingName_,
        pDefaultValue_,
        pIsUserSpecific_,
        pIsHostSpecific_,
        pIsProjectSetting_ );
}


STDMETHODIMP CCompanyNameScanner::StringSettingsNbGet(
    /* [out] */ long* nbSettings_ )
{
    return theCompanyNameScannerSettings().StringSettingsNbGet( nbSettings_ );
}


STDMETHODIMP CCompanyNameScanner::StringSettingGet(
    /* [in] */ long           settingIndex_,
    /* [out] */ BSTR*         pSettingName_,
    /* [out] */ BSTR*         pDefaultValue_,
    /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    return theCompanyNameScannerSettings().StringSettingGet(
        settingIndex_,
        pSettingName_,
        pDefaultValue_,
        pIsUserSpecific_,
        pIsHostSpecific_,
        pIsProjectSetting_ );
}

//////////////// IIMSettings2 ////////////////////////

STDMETHODIMP CCompanyNameScanner::MatrixSettingsNbGet(
    /* [out] */ long* nbSettings_ )
{
    return theCompanyNameScannerSettings().MatrixSettingsNbGet( nbSettings_ );
}


STDMETHODIMP CCompanyNameScanner::MatrixSettingGet(
    /* [in] */ long           settingIndex_,
    /* [out] */ BSTR*         pSettingName_,
    /* [out] */ SAFEARRAY**   pDefaultValue_,
    /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    return theCompanyNameScannerSettings().MatrixSettingGet(
        settingIndex_,
        pSettingName_,
        pDefaultValue_,
        pIsUserSpecific_,
        pIsHostSpecific_,
        pIsProjectSetting_ );
}

//////////////// IIMSettings3 ////////////////////////

STDMETHODIMP CCompanyNameScanner::OnSettingsChange(
    /* [in] */ SAFEARRAY* pSettingNames_ )
{
    // TODO : This function is called when the application has changed one or more
    //        of the plug-in's settings. This can happen for example during the
    //        execution of the CONFIG POP command.
    //        The pSettingNames_ parameter is an array containing the name of
    //        all parameters that were modified.
    //        You should perform whatever action is needed by your plug-in to
    //        adapt to the changed settings.
    //        Note that if your plug-in uses simple settings that are always read
    //        from the CCompanyNameScannerSettings object, you may not have
    //        anything to do in this function.

    return S_OK;
}

//////////////// IIMUnitsUser ////////////////////////

STDMETHODIMP CCompanyNameScanner::UnitsScalingFactorSet(
    /* [in] */ double scalingFactor_ )
{
    // A PolyWorks plug-in implementing the UnitsScalingFactorSet method should:
    //
    // - use the specified units scaling factor to convert data to be sent
    //   to the application from plug-in units to host application units
    // - use the specified units scaling factor to convert data sent by
    //   the application from host application units to plug-in units

    if ( theCompanyNameScannerSettings().HostUnitsScalingFactorSet( scalingFactor_ ) )
    {
        // TODO: Make appropriate calls to ensure appropriate propagation of new units for data conversion

        return S_OK;
    }

    return S_FALSE;
}
