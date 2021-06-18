// =================================================================================================
// SAFEARRAY utilities.
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "SafeArrayConversion.h"

#include <comutil.h>

namespace SafeArrayConversion
{

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// =================================== FUNCTIONS PROTOTYPES ========================================

// =================================================================================================
// =================================== FUNCTIONS DEFINITIONS =======================================

// =============================================================================
// Insert wstrings from a vector into a SAFEARRAY.
// If SAFEARRAY not created yet (pointer is nullptr), it is created,
// otherwise, new elements are added after existing ones
//
// Parameter: wstrings_     : wstrings to add
// Parameter: pArrayMatrix_ : pointer to SAFEARRAY to fill (created if nullptr)
//
// Returb: bool : true on success
// -----------------------------------------------------------------------------
bool SafeArrayConversion::Insert_WStrings(
    const std::vector< std::wstring >& wstrings_,
    SAFEARRAY**                        pArrayBSTRs_ )
{
    if ( !( pArrayBSTRs_ != nullptr ) )
    {
        return false;
    }

    LONG startingIndex = 0;

    if ( *pArrayBSTRs_ == nullptr )
    {
        *pArrayBSTRs_ = SafeArrayCreateVector( VT_BSTR, 0, static_cast< ULONG >( wstrings_.size() ) );
    }
    else
    {
        VARTYPE varType = VT_EMPTY;
        SafeArrayGetVartype( *pArrayBSTRs_, &varType );

        // Elements must be of the same type
        if ( !( varType == VT_BSTR ) )
        {
            return false;
        }

        SafeArrayGetUBound( *pArrayBSTRs_, 1, &startingIndex );
        startingIndex++;    // To get actual element count

        // Preparing to add elements
        SAFEARRAYBOUND saBound;
        saBound.lLbound   = 0;
        saBound.cElements = startingIndex + static_cast< ULONG >( wstrings_.size() );
        SafeArrayRedim( *pArrayBSTRs_, &saBound );
    }

    // Adding elements
    LONG currentIdx = startingIndex;
    for ( const auto& str : wstrings_ )
    {
        SafeArrayPutElement( *pArrayBSTRs_, &currentIdx, ( void* )::SysAllocString( str.c_str() ) );
        currentIdx++;
    }

    return true;
}

// =================================================================================================
//   Gets array of strings from safe array of strings
//
// Parameter : pArrayBSTRs_ : Safe array of strings
// Parameter : wstrings_    : Extracted array of strings
//
// Return : true if succeeded, false if failed
// -------------------------------------------------------------------------------------------------
bool SafeArrayConversion::SafeArrayStringsGet( SAFEARRAY** pArrayBSTRs_, TWStrings& wstrings_ )
{
    bool success = false;
    long lBound  = 0;
    long uBound  = 0;

    wstrings_.clear();

    if ( !( ( *pArrayBSTRs_ == nullptr ) ||
            ( SafeArrayGetDim( *pArrayBSTRs_ ) < 1 ) ||
            !SUCCEEDED( SafeArrayGetUBound( *pArrayBSTRs_, 1, &uBound ) ) ||
            !SUCCEEDED( SafeArrayGetLBound( *pArrayBSTRs_, 1, &lBound ) ) ||
            ( uBound < 0 ) || ( lBound < 0 ) ) )
    {
        //----------------------
        // Extract BSTRs

        BSTR* pBSTR = nullptr;
        SafeArrayAccessData( *pArrayBSTRs_, ( void** )&pBSTR );

        int idxBSTRs = 0;
        int nbBSTRs  = uBound - lBound + 1;
        while ( idxBSTRs < nbBSTRs )
        {
            wstrings_.emplace_back( pBSTR != nullptr ? *pBSTR : L"" );

            idxBSTRs++;
            pBSTR++;
        }

        SafeArrayUnaccessData( *pArrayBSTRs_ );

        success = true;
    }

    return success;
}

// =================================================================================================
//   Sets array of strings to safe array of strings
//
// Parameter : wstrings_    : Array of strings
// Parameter : pArrayBSTRs_ : Safe array of strings to set
//
// Return : true if succeeded, false if failed
// -------------------------------------------------------------------------------------------------
bool SafeArrayConversion::SafeArrayStringsSet( const TWStrings& wstrings_, SAFEARRAY** pArrayBSTRs_ )
{
    if ( !( pArrayBSTRs_ != nullptr ) )
    {
        return false;
    }

    LONG startingIndex = 0;

    if ( *pArrayBSTRs_ == nullptr )
    {
        *pArrayBSTRs_ = SafeArrayCreateVector( VT_BSTR, 0, static_cast< ULONG >( wstrings_.size() ) );
    }
    else
    {
        VARTYPE varType = VT_EMPTY;
        SafeArrayGetVartype( *pArrayBSTRs_, &varType );

        // Elements must be of the same type
        if ( !( varType == VT_BSTR ) )
        {
            return false;
        }

        SafeArrayGetUBound( *pArrayBSTRs_, 1, &startingIndex );
        startingIndex++;    // To get actual element count

        // Preparing to add elements
        SAFEARRAYBOUND saBound;
        saBound.lLbound   = 0;
        saBound.cElements = startingIndex + static_cast< ULONG >( wstrings_.size() );
        SafeArrayRedim( *pArrayBSTRs_, &saBound );
    }

    // Adding elements
    LONG currentIdx = startingIndex;
    for ( const auto& str : wstrings_ )
    {
        SafeArrayPutElement( *pArrayBSTRs_, &currentIdx, ( void* )::SysAllocString( str.c_str() ) );
        currentIdx++;
    }

    return true;
}

}  // namespace SafeArrayConversion
