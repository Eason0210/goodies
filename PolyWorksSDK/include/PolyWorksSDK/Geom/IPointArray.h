#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IPointArray.h
///    \brief    This file contains the interface declaration for an array of points.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/IArray.h>
#include <PolyWorksSDK/Base/Size.h>
#include <PolyWorksSDK/Geom/CGeometryStatus.h>
#include <PolyWorksSDK/Geom/CPoint.h>
#include <PolyWorksSDK/Geom/IGeometry.h>
#include "FnIPointArray.h"


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
///    \brief    The point array interface.  Note that each time you manipulate an object of this
///              type, you must take in account that the geometry might have been created from different
///              implementations. We strongly recommend that you read the documentation of the function
///              returning the pointer to understand the particularities of the implementation behind
///              the object you manipulate.
///
///              To obtain a pointer to this geometry, you have the following options:
///              - Get the IGeometry derived class from an IPWObject class.
///              - Use Create and Destroy from FnIGeometry.h.
///              - Derive your own class from this class.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class IPointArray : public IArray, public IGeometry
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IPointArray() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IPointArray() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Inserts a point somewhere in the array.
    ///
    ///    \param[ in ] point_    The point to be inserted.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus Add( const CPoint& point_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Erases a all objects in the array.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus Clear() = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Erases a point located at a given index in the array.
    ///
    ///    \param[ in ] idx_    The index of the object to delete.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus EraseAt( TSize idx_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Return a copy of the point located at a given index.
    ///
    ///    \param[ in ] idx_    The index of the object to access.
    ///
    ///    \return    Point at the given index.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CPoint PointGetAt( TSize idx_ ) const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Modify the value of a point at a given position in the array.
    ///
    ///    \param[ in ] idx_      The index of the object to modify.
    ///    \param[ in ] point_    The new value to apply.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus PointSetAt( TSize idx_, const CPoint& point_ ) = 0;


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
