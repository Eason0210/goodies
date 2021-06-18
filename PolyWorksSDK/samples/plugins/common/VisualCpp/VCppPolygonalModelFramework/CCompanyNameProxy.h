#pragma once

// =================================================================================================
// Proxy class.
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "CCompanyNameSDK.h"
#include "CPolygonalModel.h"
#include "CThreadHelper.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class ICompanyNameScanner;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// The proxy is a class to hide the difference between the multiple SDK implementations and
// make them similar for the plug-in.
//
// The SDK can use different methodologies and technologies but, at the end, the proxy should
// expose basic functionalities like connect, scan, ... without exposing the complexity of the SDK
// usage implementating them.
// -------------------------------------------------------------------------------------------------
class CCompanyNameProxy
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------
    CCompanyNameProxy( ICompanyNameScanner& plugin_ );
    CCompanyNameProxy( const CCompanyNameProxy& rhs_ ) = delete;
    CCompanyNameProxy( CCompanyNameProxy&& rhs_ )      = delete;
    virtual ~CCompanyNameProxy();

    CCompanyNameProxy& operator=( const CCompanyNameProxy& rhs_ ) = delete;
    CCompanyNameProxy& operator=( CCompanyNameProxy&& rhs_ )      = delete;

    bool Connect();
    bool IsConnected() const;
    void Disconnect();

    bool ScanningStart( IIMPolygonalModel& polygonalModel_ );
    bool ScanningEnd();

    bool HostUnitsScalingFactorSet( double scalingFactor_ );

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------
    void PostProcess( EDigitizingVectorDirections&    dir_,
                      PointF&                         dirVector_,
                      std::vector< PointF >&          coordinates_,
                      std::vector< TriangleIndexes >& triangleIndexes_ );

    void            ThreadProc();
    static unsigned SThreadProc( void* pThis_ );

    // ---------------- Private Member Variables ---------------------------------------------------

    // COM Interface wrapper to transfer the polygonal model
    CPolygonalModel m_polygonalModel;

    // Interface to the plug-in
    ICompanyNameScanner& m_plugin;

    // SDK to scan data
    // TODO: Replace by your own SDK implementation
    CCompanyNameSDK m_sdk;

    // Thread and utilities to interface to the SDK
    // As the CCompanyNameSDK SDK is synchronous, we are using a thread and events 
    // to interface it with the proxy on a non-blocking way. Following the integration of 
    // your SDK, some modifications may be required.
    CThreadHelper m_thread;
    HANDLE        m_scanStartEvent = nullptr;
    HANDLE        m_scanDoneEvent  = nullptr;

    // Units scalling factor
    double m_hostUnitsScalingFactor = -1.0;
};
