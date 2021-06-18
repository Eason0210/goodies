#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IBBox.h
///    \brief    This file contains the interface for a bounding box geometry.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Geom/CGeometryStatus.h>
#include <PolyWorksSDK/Geom/CPoint.h>
#include <PolyWorksSDK/Geom/IGeometry.h>
#include "FnIBBox.h"


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
///    \brief    The bounding box geometry interface.
///
///              Note that each time you manipulate an object of this type, you must take in account that the
///              geometry might have been created from different implementations. We strongly recommend that you
///              read the documentation of the function returning the pointer to understand the particularities
///              of the implementation behind the object you manipulate.
///
///              To obtain a pointer to this geometry, you have the following options:
///              - Get the IGeometry derived class from an IPWObject class.
///              - Use Create and Destroy from FnIGeometry.h.
///              - Derive your own class from this class.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class IBBox : public IGeometry
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor  Bounding box objects MUST be created using the factory methods. (Please
    ///              see FnIGeometryFactory.h)
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IBBox() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor  Bounding box objects MUST be deleted using the destroy method. (Please
    ///              see FnIGeometryFactory.h)
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IBBox() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Empties the specified bounding box.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus Clear() = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Increases the size of the bounding box to include the specified point.
    ///
    ///    \param[ in ] point_    The point to be included in the bounding box.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus Insert( const CPoint& point_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Test if the bounding box contains at least one point and that the minimum and maximum
    ///              points are valid.
    ///
    ///    \return    Indicate if the bounding box is valid.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool IsValid() const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns a point that have the lowest coordinates of the bounding box.
    ///
    ///    \return    The maximum position in the bounding box.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual const CPoint MaxGet() const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns a point that have the highest coordinates of the bounding box.
    ///
    ///    \return    The minimal position in the bounding box.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual const CPoint MinGet() const = 0;


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
