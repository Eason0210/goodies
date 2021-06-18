#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IPolyline2D.h
///    \brief    This file contains the interface for a three-dimensional polyline geometry.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/IArray.h>
#include <PolyWorksSDK/Base/Size.h>
#include <PolyWorksSDK/Geom/CGeometryStatus.h>
#include <PolyWorksSDK/Geom/CPoint2D.h>
#include <PolyWorksSDK/Geom/IGeometry.h>

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
///    \brief    The two-dimensional polyline geometry interface.
///
///              Note that each time you manipulate
///              an object of this type, you must take in account that the geometry might have been
///              created from different implementations. We strongly recommend that you read the
///              documentation of the function returning the pointer to understand the particularities
///              of the implementation behind the object you manipulate.
///
///              To obtain a pointer to
///              this geometry, you have the following options:
///              - Get the IGeometry derived class from an IPWObject class.
///              - Use Create and Destroy from FnIGeometry.h.
///              - Derive your own class from this class.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class IPolyline2D : public IArray, public IGeometry
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IPolyline2D() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IPolyline2D() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Inserts a point in the polyline.  The position where the point will be added is not
    ///              guaranteed. So, your indexes might be invalid after calling this function.
    ///
    ///    \param[ in ] point_    The point to be inserted.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus Add( const CPoint2D& point_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Erases a all points in the polyline.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus Clear() = 0;


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
    ///    \brief    Erases a point located at a given index in the polyline.
    ///
    ///    \param[ in ] idx_    The index of the point to delete.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus EraseAt( TSize idx_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Return a copy of the point located at a given index.
    ///
    ///    \param[ in ] idx_    The index of the point to access.
    ///
    ///    \return    Point at the given index.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CPoint2D PointGetAt( TSize idx_ ) const = 0;


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
    virtual CGeometryStatus InsertAt( TSize idx_, const CPoint2D& point_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Inserts a point at the end of the polyline.
    ///
    ///    \param[ in ] point_    The point to be inserted.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus InsertBack( const CPoint2D& point_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Test if the polyline is closed.
    ///
    ///    \return    Indicate if the polyline is closed.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool IsClosed() const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Modify the value of a point at a given position in the polyline.
    ///
    ///    \param[ in ] idx_      The index of the point to modify.
    ///    \param[ in ] point_    The new value to apply.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus PointSetAt( TSize idx_, const CPoint2D& point_ ) = 0;


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
