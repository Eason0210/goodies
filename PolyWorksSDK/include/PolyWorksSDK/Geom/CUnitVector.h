#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CUnitVector.h
///    \brief    This file contains the declaration of the CUnitVector object.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>

#include "FnCUnitVector.h"

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
///    \ingroup  IM_CLASSES
///
///    \brief    The CUnitVector direction object.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CUnitVector
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor.  The object is constructed with a default direction that is
    ///              not guaranteed.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CUnitVector();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor with arguments.  Construct a unit vector object and normalise its length
    ///              to unity.  The parameters MUST NOT be all zeros. In this case the object is constructed
    ///              with a default direction that is not guaranteed.
    ///
    ///    \param[ in ] x_    The X component of the direction.
    ///    \param[ in ] y_    The Y component of the direction.
    ///    \param[ in ] z_    The Z component of the direction.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CUnitVector( const double& x_, const double& y_, const double& z_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CUnitVector();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Read-only access operator.
    ///
    ///    \param[ in ] idx_    The index of the desired component:
    ///                         - 0 for the X component
    ///                         - 1 for the Y component
    ///                         - 2 for the Z component
    ///
    ///    \return    A constant reference to the desired component.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    const double& operator[] ( const unsigned int& idx_ ) const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Affectation function.  Sets the direction of the object and normalise its length
    ///              to unity.  The operation will fail if all the component are zeros. In this case
    ///              the object is left unchanged.
    ///
    ///    \param[ in ] x_    The X component of the direction.
    ///    \param[ in ] y_    The Y component of the direction.
    ///    \param[ in ] z_    The Z component of the direction.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool Set( const double& x_, const double& y_, const double& z_ );


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------
    double m_vector[ 3 ];
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
