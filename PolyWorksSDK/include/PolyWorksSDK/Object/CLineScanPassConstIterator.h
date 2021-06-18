#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CLineScanPassConstIterator.h
///    \brief    CLineScanPassConstIterator class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>
#include <PolyWorksSDK/Object/CLineScanPassIterator.h>

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CLineScanPassConstIteratorImpl;
class ILineScanPass;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_ClASSES
///
///    \brief    Constant iterator giving access to passes in a ILineScanPass collection. Those iterators
///              are created by calling methods from ILineScan class.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CLineScanPassConstIterator
{
    friend class CILineScan;

public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy constructor taking a constant iterator as a parameter.
    ///
    ///    \param[ in ] rhs_    The constant iterator to be copied.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CLineScanPassConstIterator( const CLineScanPassConstIterator& rhs_ );

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy constructor.
    ///
    ///    \param[ in ] rhs_    The iterator to be copied.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CLineScanPassConstIterator( const CLineScanPassIterator& rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CLineScanPassConstIterator();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy operator taking an iterator as a parameter.
    ///
    ///    \param[ in ] rhs_    The  iterator to be copied.
    ///
    ///    \return    A reference to the current iterator to allow chaining of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CLineScanPassConstIterator& operator=( const CLineScanPassConstIterator& rhs_ );
    CLineScanPassConstIterator& operator=( const CLineScanPassIterator& rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Equality operator for iterators. Indicate if the two iterators are positioned at
    ///              the same line scan pass.
    ///
    ///    \param[ in ] rhs_    The iterator to be compared.
    ///
    ///    \return    Indicate if the iterators are positioned at the same line scan pass.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool operator==( const CLineScanPassConstIterator& rhs_ ) const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Inequality operator for iterators. Indicate if the two iterators are positioned at
    ///              different line scan pass.
    ///
    ///    \param[ in ] rhs_    The iterator to be compared.
    ///
    ///    \return    Indicate if the iterators are positioned at different line scan pass.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool operator!=( const CLineScanPassConstIterator& rhs_ ) const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Prefix increment operator. Moves the iterator the next line scan pass.
    ///
    ///    \return    A reference to the current iterator which has been incremented to allow chaining
    ///               of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CLineScanPassConstIterator& operator++();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Dereference operator. Gives access to the line scan pass found at the iterator's
    ///              position.
    ///
    ///    \return    A reference to the line scan pass found at the iterator's position.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    const ILineScanPass& operator*() const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Member access operator. Simplify the access of the line scan pass's member functions
    ///              when using iterators.
    ///
    ///    \return    A pointer to the line scan pass found at the iterator's position.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    const ILineScanPass* operator->() const;


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    CLineScanPassConstIterator( CLineScanPassConstIteratorImpl* pImpl_ );

    // ---------------- Private Member Variables ---------------------------------------------------

    CLineScanPassConstIteratorImpl* m_pImpl;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
