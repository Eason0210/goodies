// =================================================================================================
//   Data receiver from the device.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CCompanyNameScannerReceiver.h"

#include <assert.h>
#include <atlsafe.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include <PolyWorksSDK/COM/IIMPlanarGrid.h>
#include <PolyWorksSDK/COM/IIMPlanarGrid_i.c>
#include <PolyWorksSDK/COM/IIMSettingsRepository_i.c>
#include <PolyWorksSDK/COM/IIMSceneCamera.h>
#include <PolyWorksSDK/COM/IIMSceneCamera_i.c>
#include <PolyWorksSDK/COM/IIMVisualFeedback.h>
#include <PolyWorksSDK/COM/IIMVisualFeedback_i.c>
#include <PolyWorksSDK/UI/IDialogZone.h>

#include "ApplicationUtils.h"
#include "CComMessageFilter.h"
#include "CCompanyNameScannerSettings.h"
#include "CCompanyNameSDKStub.h"
#include "CDlgCompanyName.h"
#include "CDlgIMAlign.h"
#include "CDlgIMAlignOptions.h"
#include "CDlgIMInspect.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

static const IM::CWString COMPANY_NAME_PLANAR_SCANNER_DLG_NAME = L"CompanyNamePlanarScannerInterface";

enum
{
    WM_SCANNING_END = WM_APP
};

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

// =================================================================================================
// Hidden window message handler.
//
// Parameter : hwnd_   : MSDN
// Parameter : uMsg_   : MSDN
// Parameter : wParam_ : 0
// Parameter : lParam_ : 0
//
// return : MSDN
// -------------------------------------------------------------------------------------------------
static LRESULT CALLBACK SWindowProc( HWND hwnd_, UINT uMsg_, WPARAM wParam_, LPARAM lParam_ )
{
    if ( uMsg_ == WM_SCANNING_END )
    {
        return ExecuteCommandOnApp( L"DIGITIZE DEVICE SCAN END", true, true, false ) ? TRUE : FALSE;
    }

    return DefWindowProc( hwnd_, uMsg_, wParam_, lParam_ );
}

// =================================================================================================
//   Constructor.
// -------------------------------------------------------------------------------------------------
CCompanyNameScannerReceiver::CCompanyNameScannerReceiver()
: m_companyNameSDKStub( *this )
, m_cookiePlanarGrid( 0 )
, m_messageOnlyWindow( SWindowProc, L"CompanyNamePlanarScanner CMessageOnlyWindow" )
{
}

// =================================================================================================
//   Destructor.
// -------------------------------------------------------------------------------------------------
CCompanyNameScannerReceiver::~CCompanyNameScannerReceiver()
{
}


// =================================================================================================
//   Disconnects any other potentially conflicting plug-ins.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::ConflictingPluginsDisconnect()
{
    // TODO: In order to avoid conflict while accessing hardware or software ressources that might be used by
    //       another plug-in, it is recommended to send commands (if any exist) in order to close and disconnect
    //       any existing plug-in that might use the same ressources before attempting to connect to those
    //       ressources in this plug-in.
    //
    //       For example, if you have a scanning plug-in that uses the same tracking system as an existing probing plug-in,
    //       then you might want to call "PROBE DEVICE CONNECT ("Off")" (in IMInspect only) as one of the very first steps
    //       when attempting to connect to your hardware or software ressources, just to be sure.
    //       This is exactly what is done in the code below.

    // Only IMInspect handles probing plugins
    if ( theCompanyNameScannerSettings().HostApplicationGet() == E_APPLICATION_IMINSPECT )
    {
        std::wstring command = L"PROBE DEVICE CONNECT";
        command += L"( \"Off\" )";
        ExecuteCommandOnApp( command.c_str(), true );
    }
}

// =================================================================================================
//   Create a new device position if necessary
//
// Parameter : isVisibleInCommandHistory_ : true if called secretly (visible in Command History), false otherwise
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::CreateNewDevicePositionIfNeeded( bool isVisibleInCommandHistory_ )
{
    // Device position concept is only supported on PolyWorks|Inspector
    if ( theCompanyNameScannerSettings().HostApplicationGet() == E_APPLICATION_IMINSPECT )
    {
        std::wstring command = L"ALIGN DEVICE_POSITION CREATE";
        command += L"( , , \"On\" )";
        ExecuteCommandOnApp( command.c_str(), isVisibleInCommandHistory_ );
    }
}

// =================================================================================================
//   Connect with the device.
//
// Return : true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::Connect()
{
    // TODO: Uncomment the following line to disconnect other potentially conflicting plug-ins
    //       See the ConflictingPluginsDisconnect method for more information
    //ConflictingPluginsDisconnect();

    if ( !m_companyNameSDKStub.IsConnected() &&
         !m_companyNameSDKStub.Connect() )
    {
        // TODO: Display error message if connection failed.
        return false;
    }

    return true;
}

// =================================================================================================
//   Reaction to a communication lost.
//
// Parameter : connected_ : true if connected, false otherwise
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::ConnectionStateUpdate( const bool connected_ )
{
    if ( !connected_ )
    {
        if ( m_pDlgCompanyName != nullptr )
        {
            m_pDlgCompanyName->Observe( E_DISCONNECT );
        }
    }
}

// =================================================================================================
//   Disconnect from the device.
//
// Return : true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::Disconnect()
{
    bool success = true;

    success &= m_companyNameSDKStub.Disconnect();

    m_nbPointsRecorded = 0;

    auto* pDlgIMAlign = dynamic_cast< CDlgIMAlign* >( m_pDlgCompanyName.get() );
    if ( pDlgIMAlign != nullptr )
    {
        pDlgIMAlign->UpdateNbPoints( m_nbPointsRecorded );
    }

    return success;
}


// =================================================================================================
//   Displays the options window.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::DlgIMAlignOptionsShow( CWnd* pParent_ )
{
    m_pDlgIMAlignOptions = std::make_unique< CDlgIMAlignOptions >(  pParent_  );

    HINSTANCE oldInstance = AfxGetResourceHandle();
    AfxSetResourceHandle( g_afxExtensionModule.hResource );

    m_pDlgIMAlignOptions->DoModal();
    m_pDlgIMAlignOptions.reset();

    AfxSetResourceHandle( oldInstance );
}

// =================================================================================================
//   Pops down the plug-in interface.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::InterfacePopdown()
{
    EHostApplication software = theCompanyNameScannerSettings().HostApplicationGet();
    if ( software == E_APPLICATION_IMINSPECT || software == E_APPLICATION_IMALIGN )
    {
        if ( m_pDlgCompanyName != nullptr )
        {
            if ( m_pDlgCompanyName->GetSafeHwnd() != nullptr )
            {
                // Detach from the Dialog Zone
                IM::IDialogZone* pDialogZone = IM::DialogZoneGet();
                if ( pDialogZone != nullptr )
                {
                    pDialogZone->DialogRemove( COMPANY_NAME_PLANAR_SCANNER_DLG_NAME );
                }
            }

            m_pDlgCompanyName->Uninit();
            m_pDlgCompanyName = nullptr;
        }
    }
    else
    {
        // Other software not supported by the plug-in
        ASSERT( 0 );
        return false;
    }

    return true;
}

// =================================================================================================
//   Pops up the plug-in interface.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::InterfacePopup()
{
    EHostApplication software = theCompanyNameScannerSettings().HostApplicationGet();

    if ( ( software == E_APPLICATION_IMINSPECT ) || ( software == E_APPLICATION_IMALIGN ) )
    {
        if ( m_pDlgCompanyName == nullptr )
        {
            // Create dialog class
            if ( software == E_APPLICATION_IMINSPECT )
            {
                m_pDlgCompanyName = std::make_unique< CDlgIMInspect >();
            }
            else
            {
                m_pDlgCompanyName = std::make_unique< CDlgIMAlign >();
            }
        }

        if ( m_pDlgCompanyName != nullptr )
        {
            if ( m_pDlgCompanyName->GetSafeHwnd() == nullptr )
            {
                m_pDlgCompanyName->Init( this );

                // Create the dialog
                if ( !m_pDlgCompanyName->DialogCreate() )
                {
                    return false;
                }

                // Attach the dialog to the Dialog Zone
                if ( !IM::DialogZoneGet()->DialogAdd( m_pDlgCompanyName->GetSafeHwnd(), COMPANY_NAME_PLANAR_SCANNER_DLG_NAME ) )
                {
                    InterfacePopdown();

                    return false;
                }
            }

            // Bring the dialog to foreground
            IM::DialogZoneGet()->DialogSetForeground( COMPANY_NAME_PLANAR_SCANNER_DLG_NAME );

            return true;
        }
    }
    else
    {
        // Other software not supported by the plug-in
        ASSERT( 0 );
    }

    return false;
}

// =================================================================================================
// Called when data is received
//
// Parameter: data_ : Received data
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::OnDataAcquired( SScanData& data_ )
{
    CComPtr< IIMPlanarGrid > pPlanarGrid;
    GITGetInterfaceFromGlobal( m_cookiePlanarGrid, IID_IIMPlanarGrid, reinterpret_cast< void** >( &pPlanarGrid ) );
    if ( pPlanarGrid == nullptr )
    {
        ASSERT( 0 );
        return;
    }

    // Packaging digitizing vector for COM transfer ( using +Z for simulation )
    m_digitizingVector = { data_.m_A, data_.m_B, data_.m_C };

    CComSafeArray< float > pDigitizingVector( 3 );
    for ( int index = 0; index < m_digitizingVector.size(); ++index )
    {
        pDigitizingVector[ index ] = m_digitizingVector[ index ];
    }

    // Beginning transfer
    HRESULT res = pPlanarGrid->TransferStart( data_.m_width + 1,
                                              data_.m_height + 1,
                                              E_DIGITIZING_VECTOR_DIRECTION_OBJECT_TO_SCANNER,
                                              pDigitizingVector.GetSafeArrayPtr() );

    if ( res == S_OK )
    {
        // Creating simulation data, format : x,y,z,row,col
        std::vector< float > points;
        for ( auto& point : data_.m_points )
        {
            points.push_back( point.m_coordinate[ 0 ] );    // x
            points.push_back( point.m_coordinate[ 1 ] );    // y
            points.push_back( point.m_coordinate[ 2 ] );    // z
            points.push_back( point.m_row );
            points.push_back( point.m_col );
        }

        // Transfer data
        DataTransfer( pPlanarGrid, points );

        m_nbPointsRecorded += static_cast< long >( points.size() / 5 );

        auto* pDlgIMAlign = dynamic_cast< CDlgIMAlign* >( m_pDlgCompanyName.get() );
        if ( pDlgIMAlign != nullptr )
        {
            pDlgIMAlign->UpdateNbPoints( m_nbPointsRecorded );
        }
    }

    m_messageOnlyWindow.PostMessage( WM_SCANNING_END, 0, 0 );
}

// =================================================================================================
// Called when the scanning ends
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::OnScanEnd()
{
    ScanningEnd();
}

// =================================================================================================
//   Gets available objet names and the current choice for a specific scan type.
//
// Parameter : scanType_     : Scan type to which the objects are related
// Parameter : objectNames_  : Available object names
// Parameter : currentChoice_: Current choice. If the current choice is a name
//                             that doesn't appear in objectNames_, this means that
//                             a new object with this name will be created upon
//                             receiving new scanned points.
//
// Return : true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::ScanningObjectsGet( EScanTypes                   scanType_,
                                                      std::vector< std::wstring >& objectNames_,
                                                      std::wstring&                currentChoice_ ) const
{
    switch ( scanType_ )
    {
        case E_SCAN_TYPE_SURFACE:
            objectNames_   = m_surfaceScanName;
            currentChoice_ = m_surfaceScanNameCurrentChoice;
            break;

        default:
            return false;
    }

    return true;
}

// =================================================================================================
//   Sets the available objet names and the current choice for a specific scan type.
//
// Parameter : scanType_     : Scan type to which the objects are related
// Parameter : objectNames_  : Available object names
// Parameter : currentChoice_: Current choice. If the current choice is a name
//                             that does appear in pArrayObjects, this means that
//                            a new object with this name will be created upon
//                            receiving new scanned points.
//
// Return : true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::ScanningObjectsSet( EScanTypes                         scanType_,
                                                      const std::vector< std::wstring >& objectNames_,
                                                      const std::wstring&                currentChoice_ )
{
    switch ( scanType_ )
    {
        case E_SCAN_TYPE_SURFACE:
            m_surfaceScanName              = objectNames_;
            m_surfaceScanNameCurrentChoice = currentChoice_;
            break;

        default:
            return false;
    }

    if ( m_pDlgCompanyName != nullptr )
    {
        m_pDlgCompanyName->Observe( E_DATA_OBJECT_CHANGE );
    }

    return true;
}

// =================================================================================================
// Ends scanning operation
//
// Return : true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::ScanningEnd()
{
    CComPtr< IIMPlanarGrid > pPlanarGrid;
    GITGetInterfaceFromGlobal( m_cookiePlanarGrid, IID_IIMPlanarGrid, reinterpret_cast< void** >( &pPlanarGrid ) );
    if ( pPlanarGrid != nullptr )
    {
        pPlanarGrid->TransferEnd();

        // Setting view point
        if ( theCompanyNameScannerSettings().UseAutoViewpointGet() )
        {
            ViewPointSet( pPlanarGrid, m_digitizingVector );
        }
    }

    // Freeing planar grid COM object pointer
    GITRevokeInterfaceFromGlobal( m_cookiePlanarGrid );

    // Notify GUI that scanning is completed
    CDlgCompanyName* pDlg = m_pDlgCompanyName.get();

    if ( pDlg != nullptr )
    {
        pDlg->Observe( E_SCAN_END );
    }

    return true;
}

// =================================================================================================
// Starts scanning operation
//
// Parameter: pPlanarGrid_ : [IN] Planar grid COM object pointer
//
// Return : true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::ScanningStart( IIMPlanarGrid* pPlanarGrid_ )
{
    // On conserve simplement le pointeur de grille planaire
    if ( pPlanarGrid_ != nullptr )
    {
        // On conserve le pointeur de feedback
        GITRegisterInterfaceInGlobal( pPlanarGrid_, IID_IIMPlanarGrid, &m_cookiePlanarGrid );
    }

    m_nbPointsRecorded = 0;

    // Notify GUI that scanning is starting
    CDlgCompanyName* pDlg = m_pDlgCompanyName.get();

    if ( pDlg != nullptr )
    {
        pDlg->Observe( E_SCAN_START );
    }

    // Start scanning
    if ( m_companyNameSDKStub.ScanningStart() )
    {
        return true;
    }

    return false;
}


// =================================================================================================
//   Update application from plug-in settings
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::UpdateFromSettings()
{
    m_isUpdatingFromSettings = true;

    CCompanyNameScannerSettings settings = theCompanyNameScannerSettings();

    // Update application auto viewpoint settings
    ValueOnOffSynchWithApp( L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT GET",
                            L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT",
                            settings.UseAutoViewpointGet(),
                            true );

    ValueStrSynchWithApp( L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT DEVICE_VERTICAL_AXIS GET",
                          L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT DEVICE_VERTICAL_AXIS",
                          ConvertChoiceToString( settings.DeviceVerticalAxisGet(), g_StandardAxes, E_X_POS, _countof( g_StandardAxes ) ),
                          true );

    ValueIntSynchWithApp( L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT CLOSE_UP SCAN_LINE_ZOOM GET",
                          L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT CLOSE_UP SCAN_LINE_ZOOM",
                          settings.AutoViewpointZoomCloseUpGet(),
                          true );

    m_isUpdatingFromSettings = false;
}

// =================================================================================================
//   Update settings from the application settings
//
// Parameter : updateProfileSettings_ : Indicates whether profile settings should be updated
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::UpdateSettingsFromApp()
{
    if ( m_isUpdatingFromSettings )
    {
        return;
    }

    CCompanyNameScannerSettings settings = theCompanyNameScannerSettings();

    bool         boolValue = false;
//  double       doubleValue = 0;
    int          intValue = 0;
    std::wstring strValue;

    // Contains only settings that are also kept by the application.
    // (As a guide line, the get commands must be application commands and not plug-in commands)

    if ( ValueOnOffSynchFromApp( L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT GET",
                                 settings.UseAutoViewpointGet(),
                                 boolValue ) )
    {
        settings.UseAutoViewpointSet( boolValue );
    }

    if ( ValueStrSynchFromApp( L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT DEVICE_VERTICAL_AXIS GET",
                               ConvertChoiceToString( settings.DeviceVerticalAxisGet(), g_StandardAxes, E_X_POS, _countof( g_StandardAxes ) ),
                               strValue ) )
    {
        settings.DeviceVerticalAxisSet( static_cast< EStdAxis >( ConvertStringToChoice( strValue, g_StandardAxes, E_X_POS, _countof( g_StandardAxes ) ) ) );
    }

    if ( ValueIntSynchFromApp( L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT CLOSE_UP SCAN_LINE_ZOOM GET",
                               settings.AutoViewpointZoomCloseUpGet(),
                               intValue ) )
    {
        settings.AutoViewpointZoomCloseUpSet( intValue );
    }
}


// =================================================================================================
// Transferring points
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::DataTransfer( IIMPlanarGrid* pPlanarGrid_, std::vector< float >& points_ )
{
    if ( pPlanarGrid_ == nullptr )
    {
        return;
    }

    // Transferring points using groups
    int gridIndex = 0;
    int ptIndex   = 0;

    // Size of block used to transfer points
    ULONG transferSize = static_cast< ULONG >( points_.size() ) / 5;

    CComSafeArray< short > pGrid( transferSize * 2 );
    CComSafeArray< float > pPoint( transferSize * 3 );

    // Scaling factor to convert from mm to application units
    auto scalingFactor = static_cast< float >( theCompanyNameScannerSettings().HostUnitsScalingFactorGet() );

    for ( auto iteratorValue = points_.begin();
          iteratorValue != points_.end(); )
    {
        // Format : x,y,z,row,col

        // x
        pPoint[ ptIndex++ ] = *( iteratorValue++ ) * scalingFactor;

        // y
        pPoint[ ptIndex++ ] = *( iteratorValue++ ) * scalingFactor;

        // z
        pPoint[ ptIndex++ ] = *( iteratorValue++ ) * scalingFactor;

        // row ( y )
        pGrid[ gridIndex++ ] = static_cast< short >( *( iteratorValue++ ) );

        // column ( x )
        pGrid[ gridIndex++ ] = static_cast< short >( *( iteratorValue++ ) );
    }

    pPlanarGrid_->GridPointsAdd( pGrid.GetSafeArrayPtr(), pPoint.GetSafeArrayPtr(), nullptr, nullptr, nullptr );
}

// =================================================================================================
// Changing camera view point
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::ViewPointSet( IIMPlanarGrid* pPlanarGrid_, std::vector< float >& viewPointVector_ )
{
    if ( pPlanarGrid_ == nullptr )
    {
        return;
    }

    CComSafeArray< float > pViewPointVector( 3 );
    for ( int index = 0; index < 3; ++index )
    {
        pViewPointVector[ index ] = viewPointVector_[ index ];
    }

    CComPtr< IIMSceneCamera > pSceneCamera;
    pPlanarGrid_->QueryInterface( IID_IIMSceneCamera, ( void** )&pSceneCamera );

    if ( pSceneCamera != nullptr )
    {
        pSceneCamera->ViewpointSet( pViewPointVector.GetSafeArrayPtr() );
    }
}
