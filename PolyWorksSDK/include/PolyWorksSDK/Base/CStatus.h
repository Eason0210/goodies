#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CStatus.h
///    \brief    This file contains the declaration of the status information object.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/CTrueTypedef.h>
#include <PolyWorksSDK/Base/CWString.h>

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
///    \brief    The template definition for the status information object.  This object contains
///              an easily comparable unsigned integer value as well as a description in the case
///              of an error. In most cases, the status code should be checked for success using
///              the implicit boolean conversion operator. It is the faster and the easiest way to
///              use the status objects.  Status information object are used throughout the PolyWorks
///              SDK to indicate the success or error of various operations. There exist, however,
///              a distinct status object for each package in the PolyWorks SDK (for example, the
///              "Geom" or the "Object" folders) and only those of the same package can be compared.
///              This distinction was made because some error types are more dedicated to a certain
///              package and will never arise in another.  Parameter: TStatusCodeUnique : Type used
///              to make CStatus class type unique. Please use CTrueTypedef class in conjunction
///              with CStatus.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
template< class TStatusCodeUnique >
class CStatus
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///    \brief    Status code type definition.
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    typedef CTrueTypedef< unsigned int, TStatusCodeUnique > TCode;


    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor with a status code only.
    ///
    ///    \param[ in ] code_    The status code value.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CStatus( const TCode& code_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor with a status code and a description.
    ///
    ///    \param[ in ] code_       The status code value.
    ///    \param[ in ] message_    The description of the status or error.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CStatus( const TCode& code_, const CWString& message_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CStatus();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Comparison operator
    ///
    ///              Example:
    ///              \code{.cpp}
    ///              // Using the comparison operator for comparing status code
    ///            IM::CGeometryStatus status = pPointArray->SetAt( idx, IM::CPoint( 0.0, 0.0, 0.0 );
    ///            if( status == IM::GeometryStatusNotSupportedGet() )
    ///            {
    ///                pEditErrorMessage->SetWindowText( status.MessageGet() );
    ///            }
    ///              \endcode
    ///
    ///    \param[ in ] rhs_    The reference status object to compare to.
    ///
    ///    \return    Indicate if the two status code are equals.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool operator== ( const CStatus& rhs_ ) const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Difference operator
    ///
    ///              Example:
    ///              \code{.cpp}
    ///              // Using the difference operator for comparing status code
    ///              IM::CGeometryStatus status = pPointArray->SetAt( idx, IM::CPoint( 0.0, 0.0, 0.0 );
    ///              if( status != IM::GeometryStatusOutOfRangeGet() )
    ///              {
    ///                  pEditErrorMessage->SetWindowText( status.MessageGet() );
    ///              }
    ///              \endcode
    ///
    ///    \param[ in ] rhs_    The reference status object to compare to.
    ///
    ///    \return    Indicate if the two status code are different.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool operator!= ( const CStatus& rhs_ ) const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Implicit boolean conversion operator.
    ///
    ///              Example:
    ///              \code{.cpp}
    ///              // Using the implicit boolean conversion operation to test the success of an operation
    ///              ASSERT( pPointArray->Clear() );
    ///              \endcode
    ///
    ///    \return    Indicate if the status correspond to a success (true) or failure (false).
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    operator bool() const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Status description message access function.
    ///
    ///    \return    The status description message for the object.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    const CWString& MessageGet() const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Status description message modification function.
    ///
    ///    \param[ in ] message_    The new status description message.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    void MessageSet( const CWString& message_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Status code access function.
    ///
    ///    \return    The status code of the object.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    const TCode& CodeGet() const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Status code modification function.
    ///
    ///    \param[ in ] status_    The new status code to assign to the object.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    void CodeSet( const TCode& status_ );


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------
    CWString m_message;
    TCode    m_code;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ================================= INLINE FUNCTION DEFINITIONS ===================================

template< class TStatusCodeUnique >
inline CStatus< TStatusCodeUnique >::CStatus( const TCode& code_ )
: m_code( code_ )
{

}

// -------------------------------------------------------------------------------------------------

template< class TStatusCodeUnique >
inline CStatus< TStatusCodeUnique >::CStatus( const TCode& code_, const CWString& message_ )
: m_code( code_ )
, m_message( message_ )
{

}

// -------------------------------------------------------------------------------------------------

template< class TStatusCodeUnique >
inline CStatus< TStatusCodeUnique >::~CStatus()
{

}

// -------------------------------------------------------------------------------------------------

template< class TStatusCodeUnique >
bool CStatus< TStatusCodeUnique >::operator== ( const CStatus& rhs_ ) const
{
    return m_code == rhs_.m_code;
}

// -------------------------------------------------------------------------------------------------

template< class TStatusCodeUnique >
bool CStatus< TStatusCodeUnique >::operator!= ( const CStatus& rhs_ ) const
{
    return m_code != rhs_.m_code;
}

// -------------------------------------------------------------------------------------------------

template< class TStatusCodeUnique >
inline CStatus< TStatusCodeUnique >::operator bool() const
{
    // The global value definition for successful operation of all types is the value 0.
    return m_code.ValueGet() == 0;
}

// -------------------------------------------------------------------------------------------------

template< class TStatusCodeUnique >
inline const typename CStatus< TStatusCodeUnique >::TCode& CStatus< TStatusCodeUnique >::CodeGet() const
{
    return m_code;
}

// -------------------------------------------------------------------------------------------------

template< class TStatusCodeUnique >
inline void CStatus< TStatusCodeUnique >::CodeSet( const TCode& code_ )
{
    m_code = code_;
}

// -------------------------------------------------------------------------------------------------

template< class TStatusCodeUnique >
inline const CWString& CStatus< TStatusCodeUnique >::MessageGet() const
{
    return m_message;
}

// -------------------------------------------------------------------------------------------------

template< class TStatusCodeUnique >
inline void CStatus< TStatusCodeUnique >::MessageSet( const CWString& message_ )
{
    m_message = message_;
}

// -------------------------------------------------------------------------------------------------

} // namespace IM
