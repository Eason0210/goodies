#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     ITriangleArray.h
///    \brief    This file contains the interface for an array of triangles.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/IArray.h>
#include <PolyWorksSDK/Base/Size.h>
#include <PolyWorksSDK/Geom/CGeometryStatus.h>
#include <PolyWorksSDK/Geom/CTriangle.h>
#include <PolyWorksSDK/Geom/CUnitVector.h>
#include <PolyWorksSDK/Geom/IGeometry.h>

namespace IM { class IPointArray; }

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
///
///    \brief    The triangle array interface.
///              Note that each time you manipulate an object of this
///              type, you must take in account that the geometry might have been created from different
///              implementations. We strongly recommend that you read the documentation of the function
///              returning the pointer to understand the particularities of the implementation behind
///              the object you manipulate.
///
///              To obtain a pointer to this geometry, you have the following
///              - Get the IGeometry derived class from an IPWObject class.
///              - Use Createand Destroy from FnIGeometry.h.
///              - Derive your own class from this class.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class ITriangleArray : public IArray, public IGeometry
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ITriangleArray() {}


    // =================================================================================================
    // Destructor
    virtual ~ITriangleArray() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Adds a triangle somewhere in the array.
    ///
    ///    \param[ in ] tri_    The triangle to be inserted.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus Add( const CTriangle& tri_ ) = 0;


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
    ///    \brief    Erases an object located at a given index in the array.
    ///
    ///    \param[ in ] idx_    The index of the object to delete.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus EraseAt( TSize idx_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Return a copy of the normal located at a given index.
    ///
    ///    \param[ in ] idx_    The index of the normal to access.
    ///
    ///    \return    A copy of the normal object.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CUnitVector NormalGetAt( TSize idx_ ) const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Return a pointer to the point array geometry referenced by the triangle array.
    ///
    ///    \return    A pointer to the point array interface.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual IPointArray* PointArrayGet() = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Return a constant pointer to the point array geometry referenced by the triangle
    ///              array.
    ///
    ///    \return    A constant pointer to the point array interface.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual const IPointArray* PointArrayGet() const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Return a copy of the triangle located at a given index.
    ///
    ///    \param[ in ] idx_    The index of the triangle to access.
    ///
    ///    \return    A copy of the triangle object.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CTriangle TriangleGetAt( TSize idx_ ) const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Modify the value of a triangle at a given position in the array.
    ///
    ///    \param[ in ] idx_    The index of the object to modify.
    ///    \param[ in ] tri_    The new value to apply.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus TriangleSetAt( TSize idx_, const CTriangle& tri_ ) = 0;


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
