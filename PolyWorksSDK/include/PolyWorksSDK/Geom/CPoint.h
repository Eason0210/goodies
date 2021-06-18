#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CPoint.h
///    \brief    This file contains the declaration of the CPoint three-dimensional point object.
///
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <assert.h>

#include "FnCPoint.h"

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
///    \brief    The CPoint three-dimensional point object.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class CPoint
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Creates a new point located at ( 0, 0, 0 ).
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPoint();

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Creates a new point.
    ///
    ///    \param[ in ] x_    The x coordinate of the point.
    ///    \param[ in ] y_    The y coordinate of the point.
    ///    \param[ in ] z_    The z coordinate of the point.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPoint( const double& x_, const double& y_, const double& z_ );


    // =================================================================================================
    // Destructor
    ~CPoint();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Coordinate access operator.
    ///
    ///    \param[ in ] idx_    The index of the desired coordinate:
    ///                         - 0 for the X coordinate
    ///                         - 1 for the Y coordinate
    ///                         - 2 for the Z coordinate
    ///
    ///    \return    A reference to the desired coordinate.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    const double& operator[] ( const unsigned int& idx_ ) const;
    double&       operator[] ( const unsigned int& idx_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Affectation function.  Sets the coordinates of the point.
    ///
    ///    \param[ in ] x_    The x coordinate of the point.
    ///    \param[ in ] y_    The y coordinate of the point.
    ///    \param[ in ] z_    The z coordinate of the point.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    void Set( const double& x_, const double& y_, const double& z_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Addition assignment operator.
    ///
    ///    \param[ in ] rhs_    Translation to be added to the point.
    ///
    ///    \return    A reference to the current point to allow chaining of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPoint& operator+= ( const CPoint& rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Subtraction assignment operator.
    ///
    ///    \param[ in ] rhs_    Translation to be subtracted to the point.
    ///
    ///    \return    A reference to the current point to allow chaining of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPoint& operator-= ( const CPoint& rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Multiplication assignment operator.
    ///
    ///    \param[ in ] rhs_    Factor to be applied to the point.
    ///
    ///    \return    A reference to the current point to allow chaining of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPoint& operator*= ( const double& rhs_ );


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------
    double m_point[ 3 ];

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ================================= INLINE FUNCTION DEFINITIONS ===================================

inline CPoint::CPoint()
{
    m_point[ 0 ] = m_point[ 1 ] = m_point[ 2 ] = 0.0;
}

// -------------------------------------------------------------------------------------------------

inline CPoint::CPoint( const double& x_, const double& y_, const double& z_ )
{
    m_point[ 0 ] = x_;
    m_point[ 1 ] = y_;
    m_point[ 2 ] = z_;
}

// -------------------------------------------------------------------------------------------------

inline CPoint::~CPoint()
{

}

// -------------------------------------------------------------------------------------------------

inline const double& CPoint::operator[] ( const unsigned int& idx_ ) const
{
    assert( idx_ < 3 );
    return m_point[ idx_ ];
}

// -------------------------------------------------------------------------------------------------

inline double& CPoint::operator[] ( const unsigned int& idx_ )
{
    assert( idx_ < 3 );
    return m_point[ idx_ ];
}

// -------------------------------------------------------------------------------------------------

inline void CPoint::Set( const double& x_, const double& y_, const double& z_ )
{
    m_point[ 0 ] = x_;
    m_point[ 1 ] = y_;
    m_point[ 2 ] = z_;
}

// -------------------------------------------------------------------------------------------------

inline CPoint& CPoint::operator+= ( const CPoint& rhs_ )
{
    m_point[ 0 ] += rhs_.m_point[ 0 ];
    m_point[ 1 ] += rhs_.m_point[ 1 ];
    m_point[ 2 ] += rhs_.m_point[ 2 ];
    return *this;
}

// -------------------------------------------------------------------------------------------------

inline CPoint& CPoint::operator-= ( const CPoint& rhs_ )
{
    m_point[ 0 ] -= rhs_.m_point[ 0 ];
    m_point[ 1 ] -= rhs_.m_point[ 1 ];
    m_point[ 2 ] -= rhs_.m_point[ 2 ];
    return *this;
}

// -------------------------------------------------------------------------------------------------

inline CPoint& CPoint::operator*= ( const double& rhs_ )
{
    m_point[ 0 ] *= rhs_;
    m_point[ 1 ] *= rhs_;
    m_point[ 2 ] *= rhs_;
    return *this;
}

// -------------------------------------------------------------------------------------------------

} // namespace IM
