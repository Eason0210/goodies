#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CLineScanLineIterator.h
///    \brief    CLineScanLineIterator class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>

namespace IM { class ILineScanLine; }

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CLineScanLineIteratorImpl;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_ClASSES
///
///    \brief    Iterator giving access to lines in a ILineScanLine collection. Those iterators are
///              created by calling methods from ILineScanPass class.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CLineScanLineIterator
{
    friend class CILineScanPass;
    friend class CLineScanLineConstIterator;

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
    CLineScanLineIterator( const CLineScanLineIterator& rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CLineScanLineIterator();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy operator.
    ///
    ///    \param[ in ] rhs_    The iterator to be copied.
    ///
    ///    \return    A reference to the current iterator to allow chaining of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CLineScanLineIterator& operator=( const CLineScanLineIterator& rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Equality operator for iterators. Indicate if the two iterators are positioned at
    ///              the same line scan line.
    ///
    ///    \param[ in ] rhs_    The iterator to be compared.
    ///
    ///    \return    Indicate if the iterators are positioned at the same line scan line.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool operator==( const CLineScanLineIterator& rhs_ ) const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Inequality operator for iterators. Indicate if the two iterators are positioned at
    ///              different line scan line.
    ///
    ///    \param[ in ] rhs_    The iterator to be compared.
    ///
    ///    \return    Indicate if the iterators are positioned at different line scan line.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool operator!=( const CLineScanLineIterator& rhs_ ) const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Prefix increment operator. Moves the iterator the next line scan line.
    ///
    ///    \return    A reference to the current iterator which has been incremented to allow chaining
    ///               of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CLineScanLineIterator& operator++();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Dereference operator. Gives access to the line scan line found at the iterator's
    ///              position.
    ///
    ///    \return    A reference to the line scan line found at the iterator's position.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ILineScanLine& operator*() const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Member access operator. Simplify the access of the line scan line's member functions
    ///              when using iterators.
    ///
    ///    \return    A pointer to the line scan line found at the iterator's position.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ILineScanLine* operator->() const;


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    CLineScanLineIterator( CLineScanLineIteratorImpl* pImpl_ );

    // ---------------- Private Member Variables ---------------------------------------------------

    CLineScanLineIteratorImpl* m_pImpl;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
