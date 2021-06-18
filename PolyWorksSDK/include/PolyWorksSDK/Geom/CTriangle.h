#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CTriangle.h
///    \brief    This file contains the declaration of the CTriangle triangle object.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <assert.h>
#include <limits.h>

#include "FnCTriangle.h"

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
///    \brief    The CTriangle triangle object.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class CTriangle
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor.  The object is constructed with three invalid indexes.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CTriangle();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor with arguments.  Construct a triangle with the specified point indexes.
    ///
    ///
    ///    \param[ in ] idx1_    The index of the first  point of the triangle in a point array.
    ///    \param[ in ] idx2_    The index of the second point of the triangle in a point array.
    ///    \param[ in ] idx3_    The index of the third  point of the triangle in a point array.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CTriangle( const unsigned int& idx1_, const unsigned int& idx2_, const unsigned int& idx3_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CTriangle();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Read-only access operator.
    ///
    ///    \param[ in ] idx_    The index of the triangle's desired point index.
    ///
    ///    \return    A constant reference to the desired point index.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    const unsigned int& operator[] ( const unsigned int& idx_ ) const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Read/Write access operator.
    ///
    ///    \param[ in ] idx_    The index of the triangle's desired point index.
    ///
    ///    \return    A reference to the desired point index.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned int& operator[] ( const unsigned int& idx_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Affectation function.  Sets the indexes of the triangle's points.
    ///
    ///    \param[ in ] idx1_    The index of the first  point of the triangle in a point array.
    ///    \param[ in ] idx2_    The index of the second point of the triangle in a point array.
    ///    \param[ in ] idx3_    The index of the third  point of the triangle in a point array.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    void Set( const unsigned int& idx1_, const unsigned int& idx2_, const unsigned int& idx3_ );


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------
    unsigned int m_tri[ 3 ];

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ================================= INLINE FUNCTION DEFINITIONS ===================================

inline CTriangle::CTriangle()
{
    m_tri[ 0 ] = UINT_MAX;
    m_tri[ 1 ] = UINT_MAX;
    m_tri[ 2 ] = UINT_MAX;
}

// -------------------------------------------------------------------------------------------------

inline CTriangle::CTriangle( const unsigned int& idx1_, const unsigned int& idx2_, const unsigned int& idx3_ )
{
    m_tri[ 0 ] = idx1_;
    m_tri[ 1 ] = idx2_;
    m_tri[ 2 ] = idx3_;
}

// -------------------------------------------------------------------------------------------------

inline CTriangle::~CTriangle()
{

}

// -------------------------------------------------------------------------------------------------

inline const unsigned int& CTriangle::operator[] ( const unsigned int& idx_ ) const
{
    assert( idx_ < 3 );
    return m_tri[ idx_ ];
}

// -------------------------------------------------------------------------------------------------

inline unsigned int& CTriangle::operator[] ( const unsigned int& idx_ )
{
    assert( idx_ < 3 );
    return m_tri[ idx_ ];
}

// -------------------------------------------------------------------------------------------------

inline void CTriangle::Set( const unsigned int& idx1_, const unsigned int& idx2_, const unsigned int& idx3_ )
{
    m_tri[ 0 ] = idx1_;
    m_tri[ 1 ] = idx2_;
    m_tri[ 2 ] = idx3_;
}

// -------------------------------------------------------------------------------------------------

} // namespace IM
