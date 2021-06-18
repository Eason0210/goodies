#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IPointWithNormalArray.h
///    \brief    This file contains the interface for an array of points with normal.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/Size.h>
#include <PolyWorksSDK/Geom/CGeometryStatus.h>
#include <PolyWorksSDK/Geom/CUnitVector.h>
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
///    \brief    The point with normal array interface.
///
///              Note that each time you manipulate an object
///              of this type, you must take in account that the geometry might have been created
///              from different implementations. We strongly recommend that you read the documentation
///              of the function returning the pointer to understand the particularities of the implementation
///              behind the object you manipulate.
///
///              To obtain a pointer to this geometry, you have the following options:
///              - Get the IGeometry derived class from an IPWObject class.
///              - Use Create and Destroy from FnIGeometry.h.
///              - Derive your own class from this class.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class IPointWithNormalArray : public IPointArray
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IPointWithNormalArray() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IPointWithNormalArray() {}


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
    ///    \brief    Inserts a point with normal somewhere in the array.
    ///
    ///    \param[ in ] point_     The point to be inserted.
    ///    \param[ in ] normal_    The normal of the point to be inserted.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus Add( const CPoint& point_, const CUnitVector& normal_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns whether there is a normal at the given location. If there is no normal, calling
    ///              NormalGetAt must return an arbitrary normal.
    ///
    ///    \param[ in ] idx_    The index of the normal to access.
    ///
    ///    \return    true if there is a normal, false otherwise.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool HasNormalAt( TSize idx_ ) const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Return a copy of the normal located at a given index. Make sure to call HasNormalAt
    ///              prior to calling this function.
    ///
    ///    \param[ in ] idx_    The index of the normal to access.
    ///
    ///    \return    A copy of the normal object.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CUnitVector NormalGetAt( TSize idx_ ) const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Modify the value of a normal at a given position in the array.
    ///
    ///    \param[ in ] idx_       The index of the object to modify.
    ///    \param[ in ] normal_    The new value to apply.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CGeometryStatus NormalSetAt( TSize idx_, const CUnitVector& normal_ ) = 0;


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
