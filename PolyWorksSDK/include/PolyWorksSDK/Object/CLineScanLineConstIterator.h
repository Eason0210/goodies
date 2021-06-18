#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CLineScanLineConstIterator.h
///    \brief    CLineScanLineConstIterator class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>
#include <PolyWorksSDK/Object/CLineScanLineIterator.h>

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CILineScanPass;
class CLineScanLineConstIteratorImpl;
class ILineScanLine;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_CLASSES
///
///    \brief    Constant iterator giving access to lines in a ILineScanLine collection. Those iterators
///              are created by calling methods from ILineScanPass class.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CLineScanLineConstIterator
{
    friend CILineScanPass;

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
    CLineScanLineConstIterator( const CLineScanLineConstIterator& rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy constructor.
    ///
    ///    \param[ in ] rhs_    The iterator to be copied.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CLineScanLineConstIterator( const CLineScanLineIterator& rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CLineScanLineConstIterator();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy operator taking an iterator as a parameter.
    ///
    ///    \param[ in ] rhs_    The iterator to be copied.
    ///
    ///    \return    A reference to the current iterator to allow chaining of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CLineScanLineConstIterator& operator=( const CLineScanLineConstIterator& rhs_ );
    CLineScanLineConstIterator& operator=( const CLineScanLineIterator& rhs_ );


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
    bool operator==( const CLineScanLineConstIterator& rhs_ ) const;


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
    bool operator!=( const CLineScanLineConstIterator& rhs_ ) const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Prefix increment operator. Moves the iterator the next line scan line.
    ///
    ///    \return    A reference to the current iterator which has been incremented to allow chaining
    ///               of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CLineScanLineConstIterator& operator++();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Dereference operator. Gives access to the line scan line found at the iterator's
    ///              position.
    ///
    ///    \return    A reference to the line scan line found at the iterator's position.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    const ILineScanLine& operator*() const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Member access operator. Simplify the access of the line scan line's member functions
    ///              when using iterators.
    ///
    ///    \return    A pointer to the line scan line found at the iterator's position.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    const ILineScanLine* operator->() const;


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    CLineScanLineConstIterator( CLineScanLineConstIteratorImpl* pImpl_ );

    // ---------------- Private Member Variables ---------------------------------------------------

    CLineScanLineConstIteratorImpl* m_pImpl;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
