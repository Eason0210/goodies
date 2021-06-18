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
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>

#include <PolyWorksSDK/COM/IIMLineScan.h>
#include <PolyWorksSDK/COM/IIMLineScan_i.c>
#include <PolyWorksSDK/COM/IIMPointCloud.h>
#include <PolyWorksSDK/COM/IIMPointCloud_i.c>
#include <PolyWorksSDK/COM/IIMRealTimeInspector2.h>
#include <PolyWorksSDK/COM/IIMRealTimeInspector2_i.c>
#include <PolyWorksSDK/COM/IIMSceneCamera.h>
#include <PolyWorksSDK/COM/IIMSceneCamera_i.c>
#include <PolyWorksSDK/COM/IIMSettingsRepository2_i.c>
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
#include "CDlgIMInspectOptions.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

static const IM::CWString COMPANY_NAME_LINE_SCANNER_DLG_NAME = L"CompanyNameLineScannerInterface";

static const PointD X_AXIS( 1.0, 0.0, 0.0 );

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

static unsigned __stdcall DataThreadProc( void* pReceiver_ );

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

// =================================================================================================
//   Obtains expiration time, which is actual time + delay.
//
// Parameter : duration : delay before expiration
//
// Return : expiration time
// -------------------------------------------------------------------------------------------------
static long _GetExpireTime( long duration_ )   // duration in msec
{
    double clock_time = ( double ) clock() * ( 1000.0 / ( double ) CLOCKS_PER_SEC );
    return duration_ + ( long ) clock_time;
}


// =================================================================================================
//   Checks if a given time has been reached.
//
// Parameter: expire_time : time to check
//
// Return : true if the time has been reached, false otherwise
// -------------------------------------------------------------------------------------------------
static bool _HasTimeExpired( long expire_time_ )
{
    double clock_time = ( double ) clock() * ( 1000.0 / ( double ) CLOCKS_PER_SEC );
    return ( ( long ) clock_time - expire_time_ ) >= 0;
}



// =============================================================================
// Compute arcsin of a double value
//
// Parameter: x_ : Value to compute
//
// Return: arcsin
// -----------------------------------------------------------------------------
double ASin( double x_ )
{
    if ( x_ > -1.0 )
    {
        if ( x_ < 1.0 )
        {
            return asin( x_ );
        }
        else
        {
            return M_PI / 2;
        }
    }
    else
    {
        return -M_PI / 2;
    }
}

// =============================================================================
// Compute the square of a double value
//
// Parameter: val_ : Value to compute
//
// Return: val_ * val_
// -----------------------------------------------------------------------------
double Square( double val_ )
{
    return val_ * val_;
}

// =============================================================================
// Transform matrix to 3 rotations and 3 translations. Rotation vector follows
// OpenGL convention.
//
// Parameter: mat_ : Input matrix
// Parameter: t_   : Translations vector
// Parameter: r_   : Rotations vector (alpha, theta, phi)
//                   [ 0 ] rotation around y
//                   [ 1 ] rotation around x
//                   [ 2 ] rotation around z
//
// Return: true of OK
// -----------------------------------------------------------------------------
bool Matrix4DToParam( const Matrix4D& mat_, double* t_, double* r_ )
{
    double c;

    if ( ( t_ == nullptr ) || ( r_ == nullptr ) )
    {
        return false;
    }

    t_[ 0 ] = mat_( 3, 0 );
    t_[ 1 ] = mat_( 3, 1 );
    t_[ 2 ] = mat_( 3, 2 );

    r_[ MAT_ALPHA ] = ASin( mat_( 0, 2 ) );

    c = cos( r_[ MAT_ALPHA ] );
    if ( fabs( c ) <= GIMBAL_LOCK_THRESHOLD )
    {
        // This situation is a Gimbal Lock, theta is set to zero
        r_[ MAT_PHI ] = 0.0;
        if ( c > 0.0 )
        {
            r_[ MAT_THETA ] = atan2( -mat_( 2, 1 ), mat_( 1, 1 ) );
        }
        else
        {
            r_[ MAT_THETA ] = atan2( mat_( 2, 1 ), -mat_( 1, 1 ) );
        }
    }
    else if ( c > 0.0 )
    {
        r_[ MAT_THETA ] = atan2( -mat_( 1, 2 ), mat_( 2, 2 ) );
        r_[ MAT_PHI ]   = atan2( -mat_( 0, 1 ), mat_( 0, 0 ) );
    }
    else
    {
        r_[ MAT_THETA ] = atan2( mat_( 1, 2 ), -mat_( 2, 2 ) );
        r_[ MAT_PHI ]   = atan2( mat_( 0, 1 ), -mat_( 0, 0 ) );
    }

    return true;
}

// =============================================================================
// Create matrix from 3 rotations and 3 translations. Rotation vector follows
// OpenGL convention.
//
// Parameter: mat_ : Output matrix
// Parameter: t_   : Translations vector
// Parameter: r_   : Rotations vector (alpha, theta, phi)
//                   [ 0 ] rotation around y
//                   [ 1 ] rotation around x
//                   [ 2 ] rotation around z
// -----------------------------------------------------------------------------
void Matrix4DFromParam( Matrix4D& mat_, const double* t_, const double* r_ )
{
    int    i;
    double c[ 3 ], s[ 3 ];

    if ( ( t_ == nullptr ) || ( r_ == nullptr ) )
    {
        return;
    }

    for ( i = 0; i < 3; i++ )
    {
        c[ i ]       = cos( r_[ i ] );
        s[ i ]       = sin( r_[ i ] );
        mat_( i, 3 ) = 0.0;
        mat_( 3, i ) = t_[ i ];
    }

    mat_( 0, 0 ) = c[ MAT_PHI ] * c[ MAT_ALPHA ];
    mat_( 0, 1 ) = -s[ MAT_PHI ] * c[ MAT_ALPHA ];
    mat_( 0, 2 ) = s[ MAT_ALPHA ];

    mat_( 1, 0 ) = ( c[ MAT_PHI ] * s[ MAT_ALPHA ] * s[ MAT_THETA ] ) +
                   ( s[ MAT_PHI ] * c[ MAT_THETA ] );
    mat_( 1, 1 ) = -( s[ MAT_PHI ] * s[ MAT_ALPHA ] * s[ MAT_THETA ] ) +
                   ( c[ MAT_PHI ] * c[ MAT_THETA ] );
    mat_( 1, 2 ) = -( c[ MAT_ALPHA ] * s[ MAT_THETA ] );

    mat_( 2, 0 ) = -( c[ MAT_PHI ] * s[ MAT_ALPHA ] * c[ MAT_THETA ] ) +
                   ( s[ MAT_PHI ] * s[ MAT_THETA ] );
    mat_( 2, 1 ) = ( s[ MAT_PHI ] * s[ MAT_ALPHA ] * c[ MAT_THETA ] ) +
                   ( c[ MAT_PHI ] * s[ MAT_THETA ] );
    mat_( 2, 2 ) = c[ MAT_ALPHA ] * c[ MAT_THETA ];

    mat_( 3, 3 ) = 1.0;
}

// =============================================================================
// Make transformation matrix rigid
//
// Parameter: mat_ : Input matrix
// Parameter: rig_ : Output rigid matrix
//
// Return: true of OK
// -----------------------------------------------------------------------------
bool Matrix4DRigid( const Matrix4D& mat_, Matrix4D& rig_ )
{
    double t[ 3 ], r[ 3 ];

    if ( !Matrix4DToParam( mat_, t, r ) )
    {
        return false;
    }

    Matrix4DFromParam( rig_, t, r );

    return true;
}

// =============================================================================
// Rotate a point. Right side multiplication convention (same as OpenGL).
//
// Parameter: in_  : Input point
// Parameter: mat_ : Rotation matrix
// Parameter: out_ : Output point
// -----------------------------------------------------------------------------
void PointTransformRotate( const PointD& in_, const Matrix4D& mat_, PointF& out_ )
{
    int i;

    for ( i = 0; i < 3; i++ )
    {
        out_[ i ] = ( float )( in_[ 0 ] * mat_( i, 0 ) +
                               in_[ 1 ] * mat_( i, 1 ) +
                               in_[ 2 ] * mat_( i, 2 ) );
    }
}

// =============================================================================
// Compute rotation matrix from Euler angles (Roll, Pitch and Yaw in degrees)
//
//   RPY used convention ( R rotates around X0,
//   ===================   P rotates around Y0,
//                         Y rotates around Z0 )
//
//   Euler ZYX equivalent ( Y rotates around Z0,
//                          P rotates around Y1,
//                          R rotates around X2 )
//
//   NOTE: The produced matrix is a linear matrix (OpenGL convention).
//
// Parameter: rpy_[3]    : Euler angles ( Roll, Pitch, Yaw in degrees )
// Parameter: transform_ : Output rotation matrix
// -----------------------------------------------------------------------------
void RPYToTransform( PointD& rpy_, Matrix4D& transform_ )
{
    double cos_r = cos( DEG_TO_RAD( rpy_[ 0 ] ) );
    double sin_r = sin( DEG_TO_RAD( rpy_[ 0 ] ) );
    double cos_p = cos( DEG_TO_RAD( rpy_[ 1 ] ) );
    double sin_p = sin( DEG_TO_RAD( rpy_[ 1 ] ) );
    double cos_y = cos( DEG_TO_RAD( rpy_[ 2 ] ) );
    double sin_y = sin( DEG_TO_RAD( rpy_[ 2 ] ) );

    /* Transform equation from Introduction to Robotics, Craig; Rx'y'z'(Y, P, R) */
    transform_( 0, 0 ) = cos_y * cos_p;
    transform_( 1, 0 ) = ( cos_y * sin_p * sin_r ) + ( sin_y * cos_r );
    transform_( 2, 0 ) = -( cos_y * sin_p * cos_r ) + ( sin_y * sin_r );
    transform_( 3, 0 ) = 0.0;

    transform_( 0, 1 ) = -sin_y * cos_p;
    transform_( 1, 1 ) = -( sin_y * sin_p * sin_r ) + ( cos_y * cos_r );
    transform_( 2, 1 ) = ( sin_y * sin_p * cos_r ) + ( cos_y * sin_r );
    transform_( 3, 1 ) = 0.0;

    transform_( 0, 2 ) = sin_p;
    transform_( 1, 2 ) = -cos_p * sin_r;
    transform_( 2, 2 ) = cos_p * cos_r;
    transform_( 3, 2 ) = 0.0;

    transform_( 0, 3 ) = 0.0;
    transform_( 1, 3 ) = 0.0;
    transform_( 2, 3 ) = 0.0;
    transform_( 3, 3 ) = 1.0;

    Matrix4DRigid( transform_, transform_ );
}

// =============================================================================
// Basic algorithm to detect sharp edges of simulated data.
//
// Parameter: scan_line_in_  : Input line scan
// Parameter: edgePoints_    : Detected sharp edge points
//
// TODO: Do not use this algorithm as it is. It is used only to illustrate
//       edge extraction with simulated data points. If you don't have an
//       appropriate edge extraction algorithm, remove implementation relative
//       to the E_SCAN_TYPE_SHARP_EDGE scan type.
// -----------------------------------------------------------------------------
void DetectRidgeEdgesOfSimulatedData( const std::vector< PointF >& scan_line_in_, std::vector< PointF >& edgePoints_ )
{
    if ( scan_line_in_.size() < 3 )
    {
        return;
    }

    edgePoints_.reserve( scan_line_in_.size() );

    const double minAngleInRad             = DEG_TO_RAD( theCompanyNameScannerSettings().IMISharpEdgeMinAngleGet() );
    const double squareMaxPointToPointDist = Square( theCompanyNameScannerSettings().IMISharpEdgeMaxPointToPointDistanceGet() );

    // Get three consecutive points
    auto firstPoint  = scan_line_in_.begin();
    auto secondPoint = firstPoint + 1;
    auto thirdPoint  = secondPoint + 1;

    while ( ( ++firstPoint  != scan_line_in_.end() ) &&
            ( ++secondPoint != scan_line_in_.end() ) &&
            ( ++thirdPoint  != scan_line_in_.end() ) )
    {
        // Check the max distance between the first and the second point
        if ( squareMaxPointToPointDist <
             ( Square( firstPoint->m_values[ 0 ] - secondPoint->m_values[ 0 ] ) +
               Square( firstPoint->m_values[ 1 ] - secondPoint->m_values[ 1 ] ) +
               Square( firstPoint->m_values[ 2 ] - secondPoint->m_values[ 2 ] ) ) )
        {
            continue;
        }

        // Check the max distance between the second and the third point
        if ( squareMaxPointToPointDist <
             ( Square( thirdPoint->m_values[ 0 ] - secondPoint->m_values[ 0 ] ) +
               Square( thirdPoint->m_values[ 1 ] - secondPoint->m_values[ 1 ] ) +
               Square( thirdPoint->m_values[ 2 ] - secondPoint->m_values[ 2 ] ) ) )
        {
            continue;
        }

        // Create vectors from the three consecutive points
        PointF u( secondPoint->m_values[ 0 ] - firstPoint->m_values[ 0 ],
                  secondPoint->m_values[ 1 ] - firstPoint->m_values[ 1 ],
                  secondPoint->m_values[ 2 ] - firstPoint->m_values[ 2 ] );
        PointF v( thirdPoint->m_values[ 0 ] - secondPoint->m_values[ 0 ],
                  thirdPoint->m_values[ 1 ] - secondPoint->m_values[ 1 ],
                  thirdPoint->m_values[ 2 ] - secondPoint->m_values[ 2 ] );

        // Compute the scalar product and the square modulus of the two vectors
        float u_dot_v = u[ 0 ] * v[ 0 ] + u[ 1 ] * v[ 1 ] + u[ 2 ] * v[ 2 ];
        float mod_u_2 = Square( u[ 0 ] ) + Square( u[ 1 ] ) + Square( u[ 2 ] );
        float mod_v_2 = Square( v[ 0 ] ) + Square( v[ 1 ] ) + Square( v[ 2 ] );

        // Compute the angle between the two vectors u and v
        float theta = abs( acosf( u_dot_v / sqrtf( mod_u_2 * mod_v_2 ) ) );

        // If the angle is higher than the sharp edge min angle
        if ( theta > minAngleInRad )
        {
            edgePoints_.push_back( *secondPoint );
        }
    }
}

// =================================================================================================
//   Constructor.
// -------------------------------------------------------------------------------------------------
CCompanyNameScannerReceiver::CCompanyNameScannerReceiver()
: m_companyNameSDKStub( this )
, m_cookieLineScan( 0 )
, m_cookiePointCloud( 0 )
, m_newRecordData( false )
, m_DataIterIdx( 0 )
, m_iterFromBeginning( true )
, m_nbLinesToAccumulate( 1 )
, m_refreshDelay( 1000 )
, m_pVector( nullptr )
, m_pCoords( nullptr )
, m_pSizes( nullptr )
, m_nbPointsRecorded( 0 )
, m_cursorSegmentsMaxDist( 0 )
, m_useAutomaticViewpoint( true )
, m_acquisitionIsStarted( false )
, m_passIsStarted( false )
, m_scanPassChanging( false )
, m_scanType( E_SCAN_TYPE_SURFACE )
, m_useSMIFilter( false )
, m_isUpdatingFromSettings( false )
{
    InitializeCriticalSection( &m_DataRead );
    InitializeCriticalSection( &m_DataWrite );
}


// =================================================================================================
//   Destructor.
// -------------------------------------------------------------------------------------------------
CCompanyNameScannerReceiver::~CCompanyNameScannerReceiver()
{
    DeleteCriticalSection( &m_DataRead );
    DeleteCriticalSection( &m_DataWrite );
}


// =================================================================================================
//   Disconnects any other potentially conflicting plug-ins.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::ConflictingPluginsDisconnect()
{
    // TODO: In order to avoid conflict while accessing hardware or software resources that might be used by
    //       another plug-in, it is recommended to send commands (if any exist) in order to close and disconnect
    //       any existing plug-in that might use the same resources before attempting to connect to those
    //       resources in this plug-in.
    //
    //       For example, if you have a scanning plug-in that uses the same tracking system as an existing probing plug-in,
    //       then you might want to call "PROBE DEVICE CONNECT ("Off")" (in PolyWorks|Inspector only) as one of the very first steps
    //       when attempting to connect to your hardware or software resources, just to be sure.
    //       This is exactly what is done in the code below.

    // Only PolyWorks|Inspector handles probing plugins
    if ( theCompanyNameScannerSettings().HostApplicationGet() == E_APPLICATION_IMINSPECT )
    {
        std::wstring command = L"PROBE DEVICE CONNECT";
        command += L"( \"Off\" )";
        ExecuteCommandOnApp( command.c_str(), true );
    }
}


// =================================================================================================
//   Shows a cursor line.
//
// Parameter: points_   : line cursor points
// Parameter: nbPoints_ : nb of points
// Parameter: roll_     : scanner's Roll rotation
// Parameter: pitch_    : scanner's Pitch rotation
// Parameter: yaw_      : scanner's Yaw rotation
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::CursorSend(
    PointF* points_,
    int     nbPoints_,
    float   roll_,
    float   pitch_,
    float   yaw_ )
{
    if ( m_cookieLineScan == 0 )
    {
        return;
    }

    if ( nbPoints_ == 0 )
    {
        CComPtr< IIMVisualFeedback > pVisualFeedback;
        GITGetInterfaceFromGlobal( m_cookieLineScan, IID_IIMVisualFeedback, ( void** ) &pVisualFeedback );
        if ( pVisualFeedback != nullptr )
        {
            pVisualFeedback->PolylineDraw( nullptr, nullptr );
        }
        return;
    }

    // Convert points data to PointF
    std::vector< PointF > cursorPoints;
    cursorPoints.reserve( nbPoints_ );
    for ( int iPoints = 0; iPoints < nbPoints_; iPoints++ )
    {
        cursorPoints.emplace_back(
            points_[ iPoints ][ 0 ],
            points_[ iPoints ][ 1 ],
            points_[ iPoints ][ 2 ] );
    }

    SAFEARRAY* pVector = nullptr;
    SAFEARRAY* pCoords = nullptr;

    PrepareData(
        roll_,
        pitch_,
        yaw_,
        cursorPoints,
        &pVector,
        pCoords );

    if ( pCoords == nullptr )
    {
        CComPtr< IIMVisualFeedback > pVisualFeedback;
        GITGetInterfaceFromGlobal( m_cookieLineScan, IID_IIMVisualFeedback, ( void** ) &pVisualFeedback );
        if ( pVisualFeedback != nullptr )
        {
            pVisualFeedback->PolylineDraw( nullptr, nullptr );
        }
        return;
    }

    // Determine the number of points per segment
    std::vector< long > segmentSizes;
    long currentSegmentSize = 1;

    LONG nbFloats = 0;
    SafeArrayGetUBound( pCoords, 1, &nbFloats );
    nbFloats++;  // To have the current number of elements

    PointF currentPoint, previousPoint;
    long   pos   = 0;
    int    index = 0;
    if ( nbFloats >= 3 )
    {
        for ( pos = 0, index = 0; pos < 3; pos++, index++ )
        {
            SafeArrayGetElement( pCoords, &pos, &previousPoint[ index ] );
        }
    }

    if ( nbFloats == 3 )
    {
        // When having only 1 point, we create a unique segment with this point
        segmentSizes.push_back( currentSegmentSize );
    }
    else
    {
        // We cut the line of points in segments, each one being at a
        // distance of at least m_cursorSegmentsMaxDist from the next
        for ( int iFlt = 3; iFlt + 2 < nbFloats; iFlt += 3 )
        {
            for ( pos = iFlt, index = 0; pos < iFlt + 3; pos++, index++ )
            {
                SafeArrayGetElement( pCoords, &pos, &currentPoint[ index ] );
            }

            double pointsDistance = 0;
            // TODO: Compute point to point distance between previousPoint and currentPoint
            //       Put this distance in the pointsDistance variable
            if ( ( fabs( pointsDistance ) > m_cursorSegmentsMaxDist ) )
            {
                segmentSizes.push_back( currentSegmentSize );
                currentSegmentSize = 1;
            }
            else
            {
                currentSegmentSize++;
            }

            if ( ( iFlt + 2 ) == ( nbFloats - 1 ) ) // The last point
            {
                segmentSizes.push_back( currentSegmentSize );
            }

            previousPoint = currentPoint;
        }
    }

    // Add the sizes
    SAFEARRAY* pSizes = nullptr;
    pSizes = SafeArrayCreateVector( VT_I4, 0, ( ULONG ) segmentSizes.size() );

    for ( LONG iSize = 0; iSize < ( LONG ) segmentSizes.size(); iSize++ )
    {
        SafeArrayPutElement( pSizes, &iSize, &( segmentSizes[ iSize ] ) );
    }

    // Show the visual feedback
    CComPtr< IIMVisualFeedback > pVisualFeedback;
    GITGetInterfaceFromGlobal( m_cookieLineScan, IID_IIMVisualFeedback, ( void** ) &pVisualFeedback );
    if ( pVisualFeedback != nullptr )
    {
        // TODO: If your device do not support directly application units,
        //       make sure that coordinates are converted into application units using
        //       theCompanyNameScannerSettings().HostUnitsScalingFactorGet()

        HRESULT hr = pVisualFeedback->PolylineDraw( &pCoords, &pSizes );

        if ( ( hr == S_OK ) && m_useAutomaticViewpoint && ( pVector != nullptr ) )
        {
            // Change the viewpoint
            CComPtr< IIMSceneCamera > pSceneCamera;
            GITGetInterfaceFromGlobal( m_cookieLineScan, IID_IIMSceneCamera, ( void** ) &pSceneCamera );
            if ( pSceneCamera != nullptr )
            {
                pSceneCamera->ViewpointSet( &pVector );
            }
        }
    }

    SafeArrayDestroy( pVector );
    pVector = nullptr;
    SafeArrayDestroy( pCoords );
    pCoords = nullptr;
    SafeArrayDestroy( pSizes );
    pSizes = nullptr;
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

    if ( m_dataThread.ThreadLaunch( DataThreadProc, this ) )
    {
        m_dataThread.ThreadResume();
    }

    UpdateFromSettings();

    return true;
}


// =================================================================================================
//   Handling a communication lost.
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
    m_dataThread.ThreadKill();

    bool success = true;

    success &= m_companyNameSDKStub.Disconnect();

    m_nbPointsRecorded = 0;

    return success;
}


// =================================================================================================
//   Displays the options window.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::DlgIMAlignOptionsShow( CWnd* pParent_ )
{
    m_pDlgIMAlignOptions = std::make_unique< CDlgIMAlignOptions >( pParent_ );

    HINSTANCE oldInstance = AfxGetResourceHandle();
    AfxSetResourceHandle( g_afxExtensionModule.hResource );

    m_pDlgIMAlignOptions->DoModal();
    m_pDlgIMAlignOptions.reset();

    AfxSetResourceHandle( oldInstance );
}


// =================================================================================================
//   Displays the options window.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::DlgIMInspectOptionsShow( CWnd* pParent_ )
{
    m_pDlgIMInspectOptions = std::make_unique< CDlgIMInspectOptions >( pParent_ );

    HINSTANCE oldInstance = AfxGetResourceHandle();
    AfxSetResourceHandle( g_afxExtensionModule.hResource );

    m_pDlgIMInspectOptions->DoModal();
    m_pDlgIMInspectOptions.reset();

    AfxSetResourceHandle( oldInstance );
}

// =================================================================================================
//   Logs the options window.
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::DlgOptionsLog( const std::wstring& logFilePath_ )
{
    if ( !logFilePath_.empty() )
    {
        std::wofstream logFile( logFilePath_.c_str() );
        if ( logFile.is_open() )
        {
            std::wstring itemNames;

            if ( m_pDlgIMInspectOptions != nullptr )
            {
                m_pDlgIMInspectOptions->PropertiesLog( itemNames, true );
            }
            else if ( m_pDlgIMAlignOptions != nullptr )
            {
                m_pDlgIMAlignOptions->PropertiesLog( itemNames, true );
            }

            if ( !itemNames.empty() )
            {
                logFile << itemNames;
            }

            return !itemNames.empty();
        }
    }

    return false;
}

// =================================================================================================
//   Starts an acquisition on the COM object.
//
// Return : true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::DoAcquisitionStart()
{
    CComPtr< IIMLineScan > pLineScan;
    GITGetInterfaceFromGlobal( m_cookieLineScan, IID_IIMLineScan, ( void** ) &pLineScan );
    if ( pLineScan != nullptr )
    {
        HRESULT res = pLineScan->TransferStart(
            ( theCompanyNameScannerSettings().InvertDigitizingVectorsGet() == E_INVERT ) ?
            E_DIGITIZING_VECTOR_DIRECTION_OBJECT_TO_SCANNER : E_DIGITIZING_VECTOR_DIRECTION_SCANNER_TO_OBJECT );
        if ( res != S_OK )
        {
            return false;
        }
    }

    m_acquisitionIsStarted = true;

    m_nbPointsRecorded = 0;

    return true;
}


// =================================================================================================
//   Ends an acquisition on the COM object.
//
// Return : true
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::DoAcquisitionEnd()
{
    m_dataThread.ThreadSuspend();

    DoPassEnd();

    if ( ( m_cookieLineScan != 0 ) && m_acquisitionIsStarted )
    {
        CComPtr< IIMLineScan > pLineScan;
        GITGetInterfaceFromGlobal( m_cookieLineScan, IID_IIMLineScan, ( void** ) &pLineScan );
        if ( pLineScan != nullptr )
        {
            pLineScan->TransferEnd();
        }
    }

    m_acquisitionIsStarted = false;

    m_dataThread.ThreadResume();

    return true;
}


// =================================================================================================
//   Starts a pass on the COM object.
//
// Return : true
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::DoPassStart()
{
    // Already changing scan pass
    if ( m_scanPassChanging )
    {
        return false;
    }

    m_scanPassChanging = true;

    CComPtr< IIMLineScan > pLineScan;
    GITGetInterfaceFromGlobal( m_cookieLineScan, IID_IIMLineScan, ( void** ) &pLineScan );
    if ( pLineScan != nullptr )
    {
        pLineScan->PassStart();
    }

    m_passIsStarted = true;

    if ( m_pDlgCompanyName != nullptr )
    {
        m_pDlgCompanyName->Observe( E_PASS_START );
    }

    m_scanPassChanging = false;

    return true;
}


// =================================================================================================
//   Ends a pass on the COM object.
//
// Return : true
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::DoPassEnd()
{
    // Already changing scan pass
    if ( m_scanPassChanging )
    {
        return false;
    }

    m_scanPassChanging = true;

    // Flush the data received until now
    {
        EnterCriticalSection( &m_DataRead );
        SendNewData( true );
        EnterCriticalSection( &m_DataWrite );
        m_Data.clear();
        m_DataIterIdx       = 0;
        m_iterFromBeginning = true;
        LeaveCriticalSection( &m_DataWrite );
        LeaveCriticalSection( &m_DataRead );
    }

    if ( ( m_cookieLineScan != 0 ) && m_passIsStarted )
    {
        CComPtr< IIMLineScan > pLineScan;
        GITGetInterfaceFromGlobal( m_cookieLineScan, IID_IIMLineScan, ( void** ) &pLineScan );
        if ( pLineScan != nullptr )
        {
            pLineScan->PassEnd();
        }
    }

    m_passIsStarted = false;

    if ( m_pDlgCompanyName != nullptr )
    {
        m_pDlgCompanyName->Observe( E_PASS_STOP );
    }

    m_scanPassChanging = false;

    return true;
}


// =================================================================================================
//   Activates (or deactivates) the use of the auto viewpoint.
//
// Parameter : use_ : true to activate, false to deactivate
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::EnableAutoViewpoint( bool use_ )
{
    m_useAutomaticViewpoint = use_;
}


// =================================================================================================
//   Activates (or deactivates) the real-time inspection.
//
// Parameter: use_ : true to activate, false to deactivate
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::EnableRealTimeInspection( bool use_ )
{
    if ( m_cookieLineScan != 0 )
    {
        long retVal = 0;
        CComPtr< IIMRealTimeInspector2 > pInspector;
        GITGetInterfaceFromGlobal( m_cookieLineScan, IID_IIMRealTimeInspector2, ( void** ) &pInspector );
        if ( pInspector != nullptr )
        {
            if ( !SUCCEEDED( pInspector->RealTimeInspectionEnable( use_ ? VARIANT_TRUE : VARIANT_FALSE, &retVal ) ) )
            {
                assert( 0 );
            }
        }
    }
}


// =================================================================================================
// Activates (or deactivates) real-time meshing.
//
// Parameter : use_ : true to activate, false to deactivate
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::EnableRealTimeMeshing( bool use_ )
{
    if ( theCompanyNameScannerSettings().HostApplicationGet() == E_APPLICATION_IMINSPECT )
    {
        ValueOnOffSynchWithApp(
            g_cmdDigitizeLineScanSurfaceRTQMGet,
            g_cmdDigitizeLineScanSurfaceRTQMSet,
            use_,
            true );
    }
}


// =================================================================================================
//   Initialize the pointer.
//
// Parameter : pLineScan_   : pointer to use for line scanning
// Parameter : pPointCloud_ : pointer to use for sharp edge scanning
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::InitLineScanPtr( IIMLineScan* pLineScan_, IIMPointCloud* pPointCloud_ )
{
    long waitTime = _GetExpireTime( 2000 );
    while ( ( ( m_cookieLineScan   != 0 ) ||
              ( m_cookiePointCloud != 0 ) ) &&
            !_HasTimeExpired( waitTime ) )
    {
    }

    if ( _HasTimeExpired( waitTime ) )
    {
        ResetLineScanPtr();
        assert( 0 );   // Pointers should have been freed first!
    }

    GITRegisterInterfaceInGlobal( pLineScan_,   IID_IIMLineScan,   &m_cookieLineScan );
    GITRegisterInterfaceInGlobal( pPointCloud_, IID_IIMPointCloud, &m_cookiePointCloud );
}


// =================================================================================================
//   Sends a command to stop scanning.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::ScanEnd()
{
    bool isOK = true;

    if ( m_acquisitionIsStarted )
    {
        isOK = m_companyNameSDKStub.ScanningEnd();
    }

    return isOK;
}


// =================================================================================================
//   Sends a command to start scanning.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::ScanStart()
{
    bool isOK = true;

    if ( !m_acquisitionIsStarted )
    {
        isOK = m_companyNameSDKStub.ScanningStart();

        if ( isOK )
        {
            m_scanType         = theCompanyNameScannerSettings().ScanTypeGet();
            m_nbPointsRecorded = 0;
        }
    }

    return isOK;
}


// =================================================================================================
//   Converts the data to SAFEARRAYs.
//
// Parameter : Roll_         : Roll angle
// Parameter : Pitch_        : Pitch angle
// Parameter : Yaw_          : Yaw angle
// Parameter : pointsBuffer_ : points data buffer (assuming that points are in mm)
// Parameter : ppVector_     : direction vector SAFEARRAY pointer (may be NULL) (out)
// Parameter : pCoordsRef_   : points SAFEARRAY (out)
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::PrepareData(
    float                  Roll_,
    float                  Pitch_,
    float                  Yaw_,
    std::vector< PointF >& pointsBuffer_,
    SAFEARRAY**            ppVector_,
    SAFEARRAY*&            pCoordsRef_ )
{
    if ( ppVector_ != nullptr )
    {
        PointF dir( 0, 0, 0 );

        // Compute the direction vector (i, j ,k) using the Line Scanner data (using Roll_, Pitch_ and Yaw_, for example)
        // Put this direction vector in the dir variable
        Matrix4D mat;
        PointD   tmp( Roll_, Pitch_, Yaw_ );

        RPYToTransform( tmp, mat );
        PointTransformRotate( X_AXIS, mat, dir );

        LONG startingIndex = 0;
        if ( *ppVector_ == nullptr )
        {
            *ppVector_ = SafeArrayCreateVector( VT_R4, 0, 3 );
        }
        else
        {
            SafeArrayGetUBound( *ppVector_, 1, &startingIndex );
            startingIndex++;    // to have the current number of elements

            SAFEARRAYBOUND saBound;
            saBound.lLbound   = 0;
            saBound.cElements = startingIndex + 3;
            SafeArrayRedim( *ppVector_, &saBound );
        }

        for ( LONG idx = startingIndex, dirIdx = 0; dirIdx < 3; idx++, dirIdx++ )
        {
            SafeArrayPutElement( *ppVector_, &idx, &( dir[ dirIdx ] ) );
        }
    }

    // TODO: If needed, process the scan line points in pointsBuffer_

    // Add the coordinates
    auto totalPoints       = ( LONG ) pointsBuffer_.size();
    LONG transferredCoords = totalPoints * 3;
    LONG startingIndex     = 0;
    if ( pCoordsRef_ == nullptr )
    {
        pCoordsRef_ = SafeArrayCreateVector( VT_R4, 0, transferredCoords );
    }
    else
    {
        SafeArrayGetUBound( pCoordsRef_, 1, &startingIndex );
        startingIndex++;    // to have the current number of elements

        SAFEARRAYBOUND saBound;
        saBound.lLbound   = 0;
        saBound.cElements = startingIndex + transferredCoords;
        SafeArrayRedim( pCoordsRef_, &saBound );
    }

    // TODO: If your device do not support directly application units,
    //       make sure that coordinates are converted into application units using
    //       theCompanyNameScannerSettings().HostUnitsScalingFactorGet()
    const auto unitsScalingFactor = static_cast< float >( theCompanyNameScannerSettings().HostUnitsScalingFactorGet() );

    for ( LONG idx2 = startingIndex, idxPoint = 0, idxTransCoord = 0;
          ( idxPoint < totalPoints ) && ( idxTransCoord + 3 <= transferredCoords );
          idxPoint++ )
    {
        const LONG maxCoordIdx = idx2 + 3;
        for ( LONG iCoord = idx2, iXYZ = 0; iCoord < maxCoordIdx; iCoord++, iXYZ++ )
        {
            float point = pointsBuffer_[ idxPoint ][ iXYZ ] * unitsScalingFactor;

            SafeArrayPutElement( pCoordsRef_, &iCoord, &point );

            idx2++;
            idxTransCoord++;
        }
    }
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
                    pDialogZone->DialogRemove( COMPANY_NAME_LINE_SCANNER_DLG_NAME );
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
                if ( !IM::DialogZoneGet()->DialogAdd( m_pDlgCompanyName->GetSafeHwnd(), COMPANY_NAME_LINE_SCANNER_DLG_NAME ) )
                {
                    InterfacePopdown();

                    return false;
                }
            }

            // Bring the dialog to foreground
            IM::DialogZoneGet()->DialogSetForeground( COMPANY_NAME_LINE_SCANNER_DLG_NAME );

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
//   Receive data from the CompanyName Scanner.
//
// Parameter : pLineScan_   : pointer to the line scan to fill
// Parameter : pPointCloud_ : pointer to the sharp edge point cloud
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::ReceiveScanData( IIMLineScan* pLineScan_, IIMPointCloud* pPointCloud_ )
{
    auto* pDlgIMAlign = dynamic_cast< CDlgIMAlign* >( m_pDlgCompanyName.get() );
    if ( pDlgIMAlign != nullptr )
    {
        pDlgIMAlign->UpdateNbPoints( 0 );
    }

    if ( !m_companyNameSDKStub.ReceiveStart() )
    {
        if ( pLineScan_ != nullptr )
        {
            pLineScan_->Release();
        }
        return false;
    }

    m_newRecordData = false;

    InitLineScanPtr( pLineScan_, pPointCloud_ );

    CComPtr< IIMSceneCamera > pSceneCamera;
    GITGetInterfaceFromGlobal( m_cookieLineScan, IID_IIMSceneCamera, ( void** ) &pSceneCamera );
    if ( pSceneCamera != nullptr )
    {
        double offset = 1000.0 * theCompanyNameScannerSettings().HostUnitsScalingFactorGet();
        pSceneCamera->ClippingPlanesOffsetSet( offset, -offset );
        pSceneCamera->RefreshTriggerSetTimeDelay( m_refreshDelay );
    }

    return true;
}


// =================================================================================================
//   Cancel data reception.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::ReceiveScanDataCancel()
{
    m_companyNameSDKStub.ReceiveEnd();

    ResetLineScanPtr();

    auto* pDlgIMInspect = dynamic_cast< CDlgIMInspect* >( m_pDlgCompanyName.get() );
    if ( pDlgIMInspect != nullptr )
    {
        pDlgIMInspect->Observe( E_SCAN_END );
    }
}


// =================================================================================================
//   Reset the receiver.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::Reset()
{
    m_newRecordData = false;

    ResetLineScanPtr();

    m_DataIterIdx         = 0;
    m_iterFromBeginning   = true;
    m_nbLinesToAccumulate = 1;
    m_refreshDelay        = 1000;
    m_pVector             = nullptr;
    m_pCoords             = nullptr;
    m_pSizes              = nullptr;
}


// =================================================================================================
//   Reset the line scan pointers.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::ResetLineScanPtr()
{
    GITRevokeInterfaceFromGlobal( m_cookieLineScan );
    GITRevokeInterfaceFromGlobal( m_cookiePointCloud );
}


// =================================================================================================
//   Send new data to the COM object.
//
// Parameter : all_ : indicates if all data are transferred, regardless of
//                    the number of accumulated lines, and including the last data.
//
// Return : true if new data was sent, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerReceiver::SendNewData( bool all_ )
{
    bool newData = false;
    if ( m_newRecordData || all_ ) // wait for thread on to get recorded data
    {
        m_newRecordData = false;  // tell thread one that you're on it

        CComPtr< IIMVisualFeedback > pVisualFeedback;
        GITGetInterfaceFromGlobal( m_cookieLineScan, IID_IIMVisualFeedback, ( void** ) &pVisualFeedback );
        CComPtr< IIMLineScan > pLineScan;
        GITGetInterfaceFromGlobal( m_cookieLineScan, IID_IIMLineScan, ( void** ) &pLineScan );
        CComPtr< IIMPointCloud > pPointCloud;
        GITGetInterfaceFromGlobal( m_cookiePointCloud, IID_IIMPointCloud, ( void** ) &pPointCloud );

        EnterCriticalSection( &m_DataRead );

        bool   empty        = false;
        size_t nbDataToSend = m_Data.size();
        if ( nbDataToSend == 0 )
        {
            empty = true;
        }
        else if ( m_iterFromBeginning )
        {
            m_DataIterIdx       = 0;
            m_iterFromBeginning = false;
        }

        auto dataIter = m_Data.begin();
        std::advance( dataIter, m_DataIterIdx );

        // We stop at m_Data.size() - 1 to avoid reading a data being written
        for ( ;
              ( nbDataToSend > 0 ) &&                                // Not empty and
              ( ( all_ && ( m_DataIterIdx < nbDataToSend ) ) ||      // we transfer everything or
                ( !all_ && ( m_DataIterIdx < nbDataToSend - 1 ) ) ); // we do not transfer the last one
              ++dataIter, ++m_DataIterIdx )
        {
            LONG transferredCoordsUntilNow = 0;
            if ( m_pCoords != nullptr )
            {
                SafeArrayGetUBound( m_pCoords, 1, &transferredCoordsUntilNow );
                transferredCoordsUntilNow++;    // Accumulated count
            }

            // Resize the vector according to the number of points read
            ( *( dataIter ) ).m_pointsBuffer.reserve( ( *( dataIter ) ).m_nbBytesRead / SIZE_OF_POINT );

            std::vector< PointF >* pArrayToUse = &( *( dataIter ) ).m_pointsBuffer;
            std::vector< PointF >  filteredPoints;
            // Sharp Edge extraction
            if ( m_scanType == E_SCAN_TYPE_SHARP_EDGE )
            {
                // TODO: Apply sharp edge extraction.
                DetectRidgeEdgesOfSimulatedData( *pArrayToUse, filteredPoints );
                pArrayToUse = &filteredPoints;
            }

            // Filter points
            if ( m_useSMIFilter &&
                 ( ( m_scanType == E_SCAN_TYPE_SURFACE ) ||
                   ( m_scanType == E_SCAN_TYPE_SURFACE_AND_BOUNDARY ) ) )
            {
                // TODO: Apply points filtering
            }

            PrepareData(
                ( *( dataIter ) ).m_Roll,
                ( *( dataIter ) ).m_Pitch,
                ( *( dataIter ) ).m_Yaw,
                *pArrayToUse,
                &m_pVector,
                m_pCoords );

            // Adjust the size
            long startingIndex = 0;
            if ( m_pSizes == nullptr )
            {
                m_pSizes = SafeArrayCreateVector( VT_I4, 0, 1 );
            }
            else
            {
                SafeArrayGetUBound( m_pSizes, 1, &startingIndex );
                startingIndex++;    // to have the current number of elements

                SAFEARRAYBOUND saBound;
                saBound.lLbound   = 0;
                saBound.cElements = startingIndex + 1;
                SafeArrayRedim( m_pSizes, &saBound );
            }

            LONG idxSize = startingIndex;   // Index of the next element

            LONG transferredCoords = 0;
            SafeArrayGetUBound( m_pCoords, 1, &transferredCoords );
            transferredCoords++;                                                           // to have the current number of elements
            LONG transferredNbPts = ( transferredCoords - transferredCoordsUntilNow ) / 3; // to have the number of points

            SafeArrayPutElement( m_pSizes, &idxSize, &( transferredNbPts ) );

            LONG sizesSize = 0;
            SafeArrayGetUBound( m_pSizes, 1, &sizesSize );
            sizesSize++;    // to have the current number of elements
            if ( ( sizesSize >= m_nbLinesToAccumulate ) ||
                 ( all_ && ( m_DataIterIdx == nbDataToSend - 1 ) ) )
            {
                if ( pPointCloud != nullptr )
                {
                    pPointCloud->PointsAdd( &m_pCoords, nullptr, nullptr );
                }
                else if ( pLineScan != nullptr )
                {
                    // Erase current cursor
                    if ( pVisualFeedback != nullptr )
                    {
                        pVisualFeedback->PolylineDraw( nullptr, nullptr );
                    }

                    // Transfer the points lines
                    if ( pLineScan->LinesAdd( &m_pVector, &m_pCoords, &m_pSizes ) == S_OK )
                    {
                        m_nbPointsRecorded += ( transferredCoords / 3 );
                        newData             = true;

                        auto* pDlgIMAlign = dynamic_cast< CDlgIMAlign* >( m_pDlgCompanyName.get() );
                        if ( pDlgIMAlign != nullptr )
                        {
                            pDlgIMAlign->UpdateNbPoints( m_nbPointsRecorded );
                        }
                    }
                }

                SafeArrayDestroy( m_pVector );
                m_pVector = nullptr;
                SafeArrayDestroy( m_pCoords );
                m_pCoords = nullptr;
                SafeArrayDestroy( m_pSizes );
                m_pSizes = nullptr;
            }
        }

        LeaveCriticalSection( &m_DataRead );
    }

    return newData;
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
bool CCompanyNameScannerReceiver::ScanningObjectsGet(
    EScanTypes    scanType_,
    TWStrings&    objectNames_,
    std::wstring& currentChoice_ ) const
{
    switch ( scanType_ )
    {
        case E_SCAN_TYPE_SURFACE:
            objectNames_   = m_surfaceScanName;
            currentChoice_ = m_surfaceScanNameCurrentChoice;
            break;

        case E_SCAN_TYPE_SHARP_EDGE:
            objectNames_   = m_boundaryScanName;
            currentChoice_ = m_boundaryScanNameCurrentChoice;
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
bool CCompanyNameScannerReceiver::ScanningObjectsSet(
    EScanTypes          scanType_,
    const TWStrings&    objectNames_,
    const std::wstring& currentChoice_ )
{
    switch ( scanType_ )
    {
        case E_SCAN_TYPE_SURFACE:
            m_surfaceScanName              = objectNames_;
            m_surfaceScanNameCurrentChoice = currentChoice_;
            break;

        case E_SCAN_TYPE_SHARP_EDGE:
            m_boundaryScanName              = objectNames_;
            m_boundaryScanNameCurrentChoice = currentChoice_;
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
//   Update application from plug-in settings
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::UpdateFromSettings()
{
    m_isUpdatingFromSettings = true;

    CCompanyNameScannerSettings settings = theCompanyNameScannerSettings();

    double newScalingFactor = settings.HostUnitsScalingFactorGet();
    EnableAutoViewpoint( settings.UseAutoViewpointGet() );
    if ( settings.HostApplicationGet() == E_APPLICATION_IMINSPECT )
    {
        EnableRealTimeInspection( settings.IMIRealTimeInspectionGet() );
    }

    // Update application auto viewpoint settings
    ValueOnOffSynchWithApp(
        L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT GET",
        L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT",
        settings.UseAutoViewpointGet(),
        true );

    ValueStrSynchWithApp(
        L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT DEVICE_VERTICAL_AXIS GET",
        L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT DEVICE_VERTICAL_AXIS",
        ConvertChoiceToString( settings.DeviceVerticalAxisGet(), g_StandardAxes, E_X_POS, _countof( g_StandardAxes ) ),
        true );

    ValueIntSynchWithApp(
        L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT CLOSE_UP SCAN_LINE_ZOOM GET",
        L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT CLOSE_UP SCAN_LINE_ZOOM",
        settings.AutoViewpointZoomCloseUpGet(),
        true );

    // Update application settings for PolyWorks|Inspector
    if ( settings.HostApplicationGet() == E_APPLICATION_IMINSPECT )
    {

        ValueOnOffSynchWithApp(
            L"DIGITIZE DEVICE SCAN SURFACE EXTRACT_NORMAL_VECTORS GET",
            L"DIGITIZE DEVICE SCAN SURFACE EXTRACT_NORMAL_VECTORS",
            settings.IMIExtractNormalsGet(),
            true );

        ValueDoubleSynchWithApp(
            L"DIGITIZE DEVICE SCAN SURFACE EXTRACT_NORMAL_VECTORS MAX_SEARCH_DISTANCE GET",
            L"DIGITIZE DEVICE SCAN SURFACE EXTRACT_NORMAL_VECTORS MAX_SEARCH_DISTANCE",
            settings.IMIMaxSearchDistGet() * newScalingFactor,
            true );

        ValueDoubleSynchWithApp(
            L"DIGITIZE DEVICE SCAN SURFACE EXTRACT_NORMAL_VECTORS MIN_SEARCH_DISTANCE GET",
            L"DIGITIZE DEVICE SCAN SURFACE EXTRACT_NORMAL_VECTORS MIN_SEARCH_DISTANCE",
            settings.IMIMinSearchDistGet() * newScalingFactor,
            true );

        // Update application real-time meshing settings
        ValueOnOffSynchWithApp(
            g_cmdDigitizeLineScanSurfaceRTQMGet,
            g_cmdDigitizeLineScanSurfaceRTQMSet,
            settings.IMIRealTimeMeshingGet(),
            true );
    }

    m_isUpdatingFromSettings = false;
}

// =================================================================================================
//   Update settings from the application settings
//
// Parameter : updateProfileSettings_ : indicates whether profile settings should be updated
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::UpdateSettingsFromApp( bool updateProfileSettings_ )
{
    if ( m_isUpdatingFromSettings )
    {
        return;
    }

    CCompanyNameScannerSettings settings = theCompanyNameScannerSettings();

    double newScalingFactor = settings.HostUnitsScalingFactorGet();

    bool         boolValue;
    double       doubleValue;
    int          intValue;
    std::wstring strValue;

    // Contains only settings that are also kept by the application.
    // (As a guide line, the get commands must be application commands and not plug-in commands)

    if ( ValueOnOffSynchFromApp(
             L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT GET",
             settings.UseAutoViewpointGet(),
             boolValue ) )
    {
        settings.UseAutoViewpointSet( boolValue );
    }

    if ( updateProfileSettings_ )
    {
        if ( ValueStrSynchFromApp(
                 L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT DEVICE_VERTICAL_AXIS GET",
                 ConvertChoiceToString( settings.DeviceVerticalAxisGet(), g_StandardAxes, E_X_POS, _countof( g_StandardAxes ) ),
                 strValue ) )
        {
            settings.DeviceVerticalAxisSet( static_cast< EStdAxis >( ConvertStringToChoice( strValue, g_StandardAxes, E_X_POS, _countof( g_StandardAxes ) ) ) );
        }
    }

    if ( ValueIntSynchFromApp(
             L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT CLOSE_UP SCAN_LINE_ZOOM GET",
             settings.AutoViewpointZoomCloseUpGet(),
             intValue ) )
    {
        settings.AutoViewpointZoomCloseUpSet( intValue );
    }

    if ( settings.HostApplicationGet() == E_APPLICATION_IMINSPECT )
    {

        if ( ValueOnOffSynchFromApp(
                 L"DIGITIZE DEVICE SCAN SURFACE EXTRACT_NORMAL_VECTORS GET",
                 settings.IMIExtractNormalsGet(),
                 boolValue ) )
        {
            settings.IMIExtractNormalsSet( boolValue );
        }

        if ( ValueDoubleSynchFromApp(
                 L"DIGITIZE DEVICE SCAN SURFACE EXTRACT_NORMAL_VECTORS MAX_SEARCH_DISTANCE GET",
                 settings.IMIMaxSearchDistGet(),
                 doubleValue,
                 newScalingFactor ) )
        {
            settings.IMIMaxSearchDistSet( doubleValue );
        }

        if ( ValueDoubleSynchFromApp(
                 L"DIGITIZE DEVICE SCAN SURFACE EXTRACT_NORMAL_VECTORS MIN_SEARCH_DISTANCE GET",
                 settings.IMIMinSearchDistGet(),
                 doubleValue,
                 newScalingFactor ) )
        {
            settings.IMIMinSearchDistSet( doubleValue );
        }

        if ( ValueOnOffSynchFromApp(
                 g_cmdDigitizeLineScanSurfaceRTQMGet,
                 settings.IMIRealTimeMeshingGet(),
                 boolValue ) )
        {
            settings.IMIRealTimeMeshingSet( boolValue );
        }
    }
}


// =================================================================================================
//   Update profiles in the GUI
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerReceiver::UpdateProfiles()
{
    if ( m_pDlgCompanyName != nullptr )
    {
        m_pDlgCompanyName->PostMessage( WM_COMP_NAME_PLUGIN_UPDATE_PROFILES );
    }
}


///////////// THREADS ///////////////////////////////


static unsigned __stdcall DataThreadProc( void* pReceiver_ )
{
    auto* pReceiver = static_cast< CCompanyNameScannerReceiver* >( pReceiver_ );

    if ( pReceiver == nullptr )
    {
        return 0;
    }

    // This is a secondary thread which transfers the data to the COM objet.
    CoInitializeEx( nullptr, COINIT_APARTMENTTHREADED );
    {   // Begin scope for the COM message filter
        CRAIIComMessageFilter messageFilter;

        // wait until the Initial Suspension is off
        pReceiver->m_dataThread.WaitUntilSuspendOff();

        while ( pReceiver->m_dataThread.IsEnableControl() )
        {
            pReceiver->m_dataThread.MainThreadRelease();

            pReceiver->SendNewData( false );
            ::Sleep( 20 );  // Let other threads run
        }

    }   // End scope for the COM message filter
    CoUninitialize();

    return 0;
}
