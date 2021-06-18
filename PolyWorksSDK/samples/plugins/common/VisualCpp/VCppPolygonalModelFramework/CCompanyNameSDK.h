#pragma once

// =================================================================================================
// Simple SDK example
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <PolyWorksSDK/COM/IMTypes.h>
#include <vector>

#include "Types.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// This is the simplest possible implementation of an SDK to grab a polygonal model. This SDK is so
// simple that the scanning is blocking!
//
// TODO: You should replace this class from your project with your own SDK and adapt the CCompanyNameProxy
//       class accordingly
//
// -------------------------------------------------------------------------------------------------
class CCompanyNameSDK
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------
    CCompanyNameSDK();
    CCompanyNameSDK( const CCompanyNameSDK& rhs_ ) = delete;
    CCompanyNameSDK( CCompanyNameSDK&& rhs_ )      = delete;
    virtual ~CCompanyNameSDK();

    CCompanyNameSDK& operator=( const CCompanyNameSDK& rhs_ ) = delete;
    CCompanyNameSDK& operator=( CCompanyNameSDK&& rhs_ )      = delete;

    bool Connect();
    bool Disconnect();
    bool IsConnected() const;

    bool ScanStart( EDigitizingVectorDirections& dir_,
                    PointF&                      dirVector_,
                    std::vector< PointF >&       coordinatesInMM_ );
    void ScanEnd();

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

    // Connection state
    bool m_connected = false;

    // Event to End an executing scan
    HANDLE m_scanCancelEvent = nullptr;
};
