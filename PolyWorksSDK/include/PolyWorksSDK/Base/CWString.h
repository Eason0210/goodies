#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CWString.h
///    \brief    This file contains the declaration for the string wrapper object.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "PolyWorksSDKApi.h"
#include "Size.h"

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
///    \brief    This CWString basic wide-string wrapper is used for transferring string values between the
///              plugins and the PolyWorks SDK. The standard template library (STL) wstring class cannot be
///              used since compatibility issues might arise between the different versions of the library.
///              Furthermore, the use of the CWString wrapper can avoid direct string pointer manipulation and
///              the management of dynamically allocated strings. It is compatible with both wide char type :
///              the default typedef declaration as well as the built-in type.
///
///              This class is intended to be only a wrapper. So all string manipulation should be performed
///              using the STL wstring or your favorite string manipulation class.
///
///              This class contains a pointer to a dynamically assigned memory block. A new block is assigned
///              whenever a new string is to be assigned to the CWString either by the constructors or the
///              assignment operators. The size of this block is one wide character longer than the input
///              string's length in order to place the 0x0000 end of string special character.
///
///              In order to speed up the creation of empty strings, no memory will be allocated when the input
///              pointer is NULL. In this case, the implicit conversion operators will return a NULL pointer.
///              After the Clear() operation, a NULL pointer will also be returned from the these operators.
///
///              If the input string of the constructors or of the assignment operators is empty but not NULL,
///              a one character buffer will be allocated and it will contain the end of string character.
///              In this case, the implicit conversion operators will not return NULL.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CWString
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor.  The internal string will be NULL and no memory will be allocated.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CWString();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy constructor.  Allocates a new memory block and copy the string's content in
    ///              the new buffer.
    ///
    ///    \param[ in ] rhs_    The string to be copied.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CWString( const CWString& rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy constructor for the default wchar_t typedef.  Allocates a new memory block and
    ///              copy the string's content in the new buffer.
    ///
    ///    \param[ in ] rhs_    The string to be copied.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CWString( const unsigned short* rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy constructor for the wchar_t as a built-in type.  Allocates a new memory block
    ///              and copy the string's content in the new buffer.
    ///
    ///    \param[ in ] rhs_    The string to be copied.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CWString( const __wchar_t* rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.  Frees up the  internal string's allocated memory.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CWString();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy operator.  Copy the string's content in the internal buffer. This operation
    ///              might clear then reallocate the internal memory block.
    ///
    ///    \param[ in ] rhs_    The string to be copied.
    ///
    ///    \return    A reference to the current string to allow chaining of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CWString& operator= ( const CWString& rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy operator for the default wchar_t typedef.  Copy the string's content in the
    ///              internal buffer. This operation might clear then reallocate the internal memory
    ///              block.
    ///
    ///    \param[ in ] rhs_    The string to be copied.
    ///
    ///    \return    A reference to the current string to allow chaining of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CWString& operator= ( const unsigned short* rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy operator for the wchar_t as a built-in type.  Copy the string's content in the
    ///              internal buffer. This operation might clear then reallocate the internal memory
    ///              block.
    ///
    ///    \param[ in ] rhs_    The string to be copied.
    ///
    ///    \return    A reference to the current string to allow chaining of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CWString& operator= ( const __wchar_t*& rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Implicit conversion operator for the default wchar_t typedef.  This function returns
    ///              a constant-version of the internal pointer. If no memory is currently allocated,
    ///              this conversion operator will return NULL.
    ///
    ///    \return    A constant pointer to the internal string value ( might be NULL ).
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    operator const unsigned short*() const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Implicit conversion operator for the wchar_t as a built-in type.  This function returns
    ///              a constant-version of the internal pointer. If no memory is currently allocated,
    ///              this conversion operator will return NULL.
    ///
    ///    \return    A constant pointer to the internal string value ( might be NULL ).
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    operator const __wchar_t*() const;


    // =================================================================================================
    // Clears the internal string and frees up the allocated memory.  After this operation,
    // the internal dynamically allocated memory pointer will be NULL.
    void Clear();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Test if the string is empty.  A NULL string or a valid string of length 0 are both
    ///              considered empty.
    ///
    ///    \return    Indicate if the string is empty.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool IsEmpty() const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Gets the number of characters in the string.  A NULL string is considered to have
    ///              a length of 0.
    ///
    ///    \return    The length of the string.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    const TSize& Size() const;


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------
    bool Alloc( TSize size_ );
    bool Copy( const unsigned short* rhs_, TSize size_ );

    // ---------------- Private Member Variables ---------------------------------------------------
    unsigned short* m_string;
    TSize           m_size;
};


// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================


} // namespace IM
