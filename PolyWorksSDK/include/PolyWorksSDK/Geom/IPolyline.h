#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IPolyline.h
///    \brief    This file contains the interface for a three-dimensional polyline geometry.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "FnIPolyline.h"

#include <PolyWorksSDK/Base/Size.h>
#include <PolyWorksSDK/Geom/CGeometryStatus.h>
#include <PolyWorksSDK/Geom/IPointArray.h>

namespace IM { class CPoint; }

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_INTERFACES
///
///    \brief    The three-dimensional polyline geometry interface.
///
///              Note that each time you manipulate
///              an object of this type, you must take in account that the geometry might have been
///              created from different implementations. We strongly recommend that you read the
///              documentation of the function returning the pointer to understand the particularities
///              of the implementation behind the object you manipulate.
///
///              To obtain a pointer to this geometry, you have the following options:
///              - Get the IGeometry derived class from an IPWObject class.
///              - Use Create and Destroy from FnIGeometry.h.
///              - Derive your own class from this class.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class IPolyline : public IPointArray
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IPolyline() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IPolyline() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Sets the closed property in the polyline geometry.
    ///
    ///    \param[ in ] closed_    The closed state to be applied to the polyline geometry.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus ClosedSet( bool closed_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Inserts a point at a given position in the polyline.  The point will be inserted
    ///              at the specified index, moving back all points from this position up to the end
    ///              of the polyline.
    ///
    ///    \param[ in ] idx_      The index where the point will be inserted.
    ///    \param[ in ] point_    The point to be inserted.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus InsertAt( TSize idx_, const CPoint& point_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Inserts a point at the end of the polyline.
    ///
    ///    \param[ in ] point_    The point to be inserted.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus InsertBack( const CPoint& point_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Test if the polyline is closed.
    ///
    ///    \return    Indicate if the polyline is closed.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool IsClosed() const = 0;


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
