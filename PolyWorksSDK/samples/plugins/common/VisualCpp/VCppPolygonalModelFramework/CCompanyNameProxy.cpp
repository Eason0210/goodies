// =================================================================================================
// Implementation of the proxy class
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CCompanyNameProxy.h"

#include "CComMessageFilter.h"
#include "CompanyNameConst.h"
#include "DataGenerator.h"
#include "ICompanyNameScanner.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================


// =================================================================================================
// Contructor
//
// Parameter: plugin_ : Plug interface
// -------------------------------------------------------------------------------------------------
CCompanyNameProxy::CCompanyNameProxy( ICompanyNameScanner& plugin_ )
: m_plugin( plugin_ )
{
    // Initialize the thread interaction control events
    m_scanStartEvent = ::CreateEvent( nullptr, TRUE, FALSE, nullptr );
    m_scanDoneEvent  = ::CreateEvent( nullptr, TRUE, TRUE, nullptr );
}

// =================================================================================================
// Destructor
// -------------------------------------------------------------------------------------------------
CCompanyNameProxy::~CCompanyNameProxy()
{
    ::CloseHandle( m_scanStartEvent );
    ::CloseHandle( m_scanDoneEvent );
}

// =================================================================================================
// Connect to the device
//
// Return: true on success, otherwise false
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProxy::Connect()
{
    // As the CCompanySDK is blocking on scanning we will have a thread to make the scan
    // This thread will also be used to make some post-processing
    if ( !m_thread.ThreadLaunch( SThreadProc, this ) ||
         !m_thread.ThreadResume() )
    {
        return false;
    }

    // Connect to the SDK
    if ( !m_sdk.Connect() )
    {
        Disconnect();
    }

    return true;
}

// =================================================================================================
// Disconnect the device
// -------------------------------------------------------------------------------------------------
void CCompanyNameProxy::Disconnect()
{
    // Ensure that any scanning is terminated before any disconnection
    ScanningEnd();
    ::WaitForSingleObject( m_scanDoneEvent, INFINITE );

    // Disconnect the SDK
    m_sdk.Disconnect();

    // Close the scanning thread
    m_thread.ThreadKill();
}

// =================================================================================================
// Return the connection state
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProxy::IsConnected() const
{
    return m_sdk.IsConnected();
}

// =================================================================================================
// Launch a non-blocking scan on the device
//
// Parameter: polygonalModel_ : The polygonal model used to the transfer the scanned data
//
// Return: true on success, otherwise false
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProxy::ScanningStart( IIMPolygonalModel& polygonalModel_ )
{
    if ( !m_sdk.IsConnected() )
    {
        return false;
    }

    // Keep the reference on the polygonal model. The model will be use later on after the scan to
    // send the data to the application
    if ( !m_polygonalModel.Initialize( polygonalModel_ ) )
    {
        return false;
    }

    // One scan at the time
    ::WaitForSingleObject( m_scanDoneEvent, INFINITE );
    ::ResetEvent( m_scanDoneEvent );

    // Instruct the scan thread to make a scan
    ::SetEvent( m_scanStartEvent );

    return true;
}

// =================================================================================================
// End or cancel the current scan
//
// Return: true on success, otherwise false
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProxy::ScanningEnd()
{
    // Cancel any scan in progress
    m_sdk.ScanEnd();

    // Release the Polygonal Model interface used for the scan.
    m_polygonalModel.Uninitialize();

    return true;
}

// =================================================================================================
// Static function for the scan thread.
//
// Used to be able to call a member thread function
//
// Parameter: pThis_ : Pointer to the current class
// -------------------------------------------------------------------------------------------------
unsigned CCompanyNameProxy::SThreadProc( void* pThis_ )
{
    if ( pThis_ != nullptr )
    {
        CCompanyNameProxy* pThis = ( CCompanyNameProxy* ) pThis_;
        pThis->ThreadProc();
    }
    return 0;
}

// =================================================================================================
// Scan thread
//
// This thread is used to scan the data and send the model to the application
// -------------------------------------------------------------------------------------------------
void CCompanyNameProxy::ThreadProc()
{
    // This thread will require COM usager, it must be initialized properly
    ::CoInitializeEx( nullptr, COINIT_APARTMENTTHREADED );
    {
        CRAIIComMessageFilter messageFilter;

        // wait until the Initial Suspension is off
        m_thread.WaitUntilSuspendOff();

        while ( m_thread.IsEnableControl() )
        {
            m_thread.MainThreadRelease();

            // Check if a ScanningStart requires a new scan
            if ( WaitForSingleObject( m_scanStartEvent, 50 ) == WAIT_OBJECT_0 )
            {
                EDigitizingVectorDirections dir;
                PointF dirVector;
                std::vector< PointF >          coordinates;
                std::vector< TriangleIndexes > triangleIndexes;

                // Launch a blocking scan with the SDK and wait for the data
                if ( m_sdk.ScanStart( dir, dirVector, coordinates ) )
                {
                    // From the raw data from the SDK, make some post processing
                    PostProcess( dir, dirVector, coordinates, triangleIndexes );

                    // Tranfer the data to the application
                    m_polygonalModel.PointsAndTrianglesTransfer( m_hostUnitsScalingFactor, dir, dirVector, coordinates, triangleIndexes );

                    // The scan is done, launch a scan end FROM THE MAIN THREAD to avoid deadlock.
                    // To launch in the main thread, a windows only message is used by the CCompanyNameScanner class
                    m_plugin.ScanningEndInMainThreadRequest();
                }

                // Be ready for another scan
                ::ResetEvent( m_scanStartEvent );

                // The scan is completed
                ::SetEvent( m_scanDoneEvent );
            }
        }

    }   // End scope for the COM message filter
    ::CoUninitialize();
}

// =================================================================================================
// Perform some post-processing to the data
// And make the meshing
//
// Note that this processing is executed inside a secondary thread and while the application is
// scanning
//
// Parameter: dir_             : Direction of the digitizing vector
// Parameter: dirVector_       : Digitizing vector
// Parameter: coordinatesInMM_ : Point coordinates in millimeters
// Parameter: triangleIndexes_ : Index of the points from coordinatesInMM_ to form triangles
// -------------------------------------------------------------------------------------------------
void CCompanyNameProxy::PostProcess(
    EDigitizingVectorDirections&    dir_,
    PointF&                         dirVector_,
    std::vector< PointF >&          coordinates_,
    std::vector< TriangleIndexes >& triangleIndexes_ )
{
    // TODO: Add your own post processing here

    // From the coordinate, we make the meshing into triangle index
    DataGenerator::MeshingGet( coordinates_, triangleIndexes_ );
}

// =================================================================================================
//   Assigns scaling factor for application units usage,
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProxy::HostUnitsScalingFactorSet( double scalingFactor_ )
{
    if ( scalingFactor_ <= 0.0 )
    {
        return false;
    }

    // Recording new scaling factor
    m_hostUnitsScalingFactor = scalingFactor_;

    return true;
}
