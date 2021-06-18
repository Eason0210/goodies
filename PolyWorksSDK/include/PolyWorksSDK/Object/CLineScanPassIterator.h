#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CLineScanPassIterator.h
///    \brief    CLineScanPassIterator class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>

namespace IM { class ILineScanPass; }

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CLineScanPassIteratorImpl;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_ClASSES
///
///    \brief    Iterator giving access to passes in a ILineScanPass collection. Those iterators are
///              created by calling methods from ILineScan class.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CLineScanPassIterator
{
    friend class CILineScan;
    friend class CLineScanPassConstIterator;

public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy constructor.
    ///
    ///    \param[ in ] rhs_    The iterator to be copied.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CLineScanPassIterator( const CLineScanPassIterator& rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CLineScanPassIterator();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy operator.
    ///
    ///    \param[ in ] rhs_    The iterator to be copied.
    ///
    ///    \return    A reference to the current iterator to allow chaining of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CLineScanPassIterator& operator=( const CLineScanPassIterator& rhs_ );


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
    bool operator==( const CLineScanPassIterator& rhs_ ) const;


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
    bool operator!=( const CLineScanPassIterator& rhs_ ) const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Prefix increment operator. Moves the iterator the next line scan pass.
    ///
    ///    \return    A reference to the current iterator which has been incremented to allow chaining
    ///               of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CLineScanPassIterator& operator++();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Dereference operator. Gives access to the line scan pass found at the iterator's
    ///              position.
    ///
    ///    \return    A reference to the line scan pass found at the iterator's position.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ILineScanPass& operator*() const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Member access operator. Simplify the access of the line scan pass's member functions
    ///              when using iterators.
    ///
    ///    \return    A pointer to the line scan pass found at the iterator's position.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ILineScanPass* operator->() const;


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    CLineScanPassIterator( CLineScanPassIteratorImpl* pImpl_ );

    // ---------------- Private Member Variables ---------------------------------------------------

    CLineScanPassIteratorImpl* m_pImpl;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
