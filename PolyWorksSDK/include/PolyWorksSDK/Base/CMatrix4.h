#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CMatrix4.h
///    \brief    This file contains the declaration of the CMatrix4 transformation matrix object.
///
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>

#include "PolyWorksSDK/Base/FnCMatrix4.h" // IWYU pragma: keep

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
///    \brief    The CMatrix4 transformation matrix object.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CMatrix4
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    The object is constructed as the identity matrix.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CMatrix4();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CMatrix4();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Read-only access operator.
    ///
    ///    \param[ in ] row_    The index of the desired row in the matrix ( 0 to 3 ).
    ///    \param[ in ] col_    The index of the desired column in the matrix ( 0 to 3 ).
    ///
    ///    \return    A constant reference to the desired value.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    const double& operator() ( unsigned int row_, unsigned int col_ ) const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Read/Write access operator.
    ///
    ///    \param[ in ] row_    The index of the desired row in the matrix ( 0 to 3 ).
    ///    \param[ in ] col_    The index of the desired column in the matrix ( 0 to 3 ).
    ///
    ///    \return    A reference to the desired value.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    double& operator() ( unsigned int row_, unsigned int col_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Addition assignment operator.
    ///
    ///    \param[ in ] rhs_    Transformation to be added to the matrix.
    ///
    ///    \return    A reference to the current point to allow chaining of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CMatrix4& operator+= ( const CMatrix4& rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Subtraction assignment operator.
    ///
    ///    \param[ in ] rhs_    Transformation to be subtracted to the matrix.
    ///
    ///    \return    A reference to the current matrix to allow chaining of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CMatrix4& operator-= ( const CMatrix4& rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Multiplication assignment operator.
    ///
    ///    \param[ in ] rhs_    Scaling factor to be applied to the matrix.
    ///
    ///    \return    A reference to the current matrix to allow chaining of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CMatrix4& operator*= ( double rhs_ );

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------
    double m_matrix[ 4 ][ 4 ];
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
