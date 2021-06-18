// =================================================================================================
// Implementation of a simple SDK example
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CCompanyNameSDK.h"

#include <PolyWorksSDK/COM/IMTypes.h>

#include "DataGenerator.h"

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
// Constructor
// -------------------------------------------------------------------------------------------------
CCompanyNameSDK::CCompanyNameSDK()
{
    m_scanCancelEvent = ::CreateEvent( nullptr, TRUE, FALSE, nullptr );
}

// =================================================================================================
// Destructor
// -------------------------------------------------------------------------------------------------
CCompanyNameSDK::~CCompanyNameSDK()
{
    Disconnect();

    ::CloseHandle( m_scanCancelEvent );
}

// =================================================================================================
// Connection
//
// Return: true for success, otherwise false
// -------------------------------------------------------------------------------------------------
bool CCompanyNameSDK::Connect()
{
    m_connected = true;
    return true;
}

// =================================================================================================
// Disconnection
//
// Return: true for success, otherwise false
// -------------------------------------------------------------------------------------------------
bool CCompanyNameSDK::Disconnect()
{
    m_connected = false;

    return true;
}

// =================================================================================================
// Return connection state
// -------------------------------------------------------------------------------------------------
bool CCompanyNameSDK::IsConnected() const
{
    return m_connected;
}

// =================================================================================================
// Scan simulation function
// Note that this function is blocking. Some SDK will be not. The difference between these
// will be addressed in the CCompanyNameProxy
//
// Parameter: dir_             : Direction of the digitizing vector
// Parameter: dirVector_       : Digitizing vector
// Parameter: coordinatesInMM_ : Point coordinates in millimeters
//
// Return: true for scan with success, otherwise false
// -------------------------------------------------------------------------------------------------
bool CCompanyNameSDK::ScanStart( EDigitizingVectorDirections& dir_,
                                 PointF&                      dirVector_,
                                 std::vector< PointF >&       coordinatesInMM_ )
{
    coordinatesInMM_.clear();

    if ( !IsConnected() )
    {
        return false;
    }

    ::ResetEvent( m_scanCancelEvent );

    // Simulation of a cancellable scan of 5 sec.
    // We wait for an event to ba able to stop the current scan from another thread if required
    // A real SDK will scan the data here!
    if ( ::WaitForSingleObject( m_scanCancelEvent, 5000 ) != WAIT_TIMEOUT )
    {
        return false;
    }

    // Simulate the polygonal model data
    // We will assume that are returned in millimeters
    DataGenerator::CoordinatesGet( dir_, dirVector_, coordinatesInMM_ );

    return true;
}

// =================================================================================================
// End / Cancel the current scan in progress
// -------------------------------------------------------------------------------------------------
void CCompanyNameSDK::ScanEnd()
{
    ::SetEvent( m_scanCancelEvent );
}
