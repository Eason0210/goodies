#pragma once

// =================================================================================================
// Wrapper for the IIMPolygonalModel COM interface
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <PolyWorksSDK/COM/IMTypes.h>
#include <afxwin.h>
#include <memory>
#include <string>
#include <vector>

#include "Types.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

struct IIMPolygonalModel;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

using TUniqueID = std::wstring;

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// Class to easily access the COM Interface IIMPolygonalModel and hide the data transformation
// required when calling COM from C++
// -------------------------------------------------------------------------------------------------
class CPolygonalModel
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    CPolygonalModel()                              = default;
    CPolygonalModel( const CPolygonalModel& rhs_ ) = delete;
    CPolygonalModel( CPolygonalModel&& rhs_ )      = delete;
    virtual ~CPolygonalModel();

    CPolygonalModel& operator=( const CPolygonalModel& rhs_ ) = delete;
    CPolygonalModel& operator=( CPolygonalModel&& rhs_ )      = delete;

    // Initialization
    bool Initialize( IIMPolygonalModel& polygonalModel_ );
    bool IsInitialized() const;
    void Uninitialize();

    // COM functionalities
    bool PointsAndTrianglesGet( float                           unitConversionFactor_,
                                std::vector< PointF >&          coordinates_,
                                std::vector< TriangleIndexes >& triangleIndexes_ );

    bool PointsAndTrianglesTransfer( float                                 unitConversionFactor_,
                                     EDigitizingVectorDirections           dir_,
                                     const PointF&                         dirVector_,
                                     const std::vector< PointF >&          coordinates_,
                                     const std::vector< TriangleIndexes >& triangleIndexes_ );

    TUniqueID UniqueIDGet();

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

    // Cookie for the COM Interface
    DWORD m_cookie = 0;
};

std::unique_ptr< CPolygonalModel > PolygonalModelCreate( const TUniqueID& uniqueID_ );

bool Compare( const TUniqueID& uniqueID1_, const TUniqueID& uniqueID2_  );
