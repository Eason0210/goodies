// =================================================================================================
// Implementation of the CIMPropertyGridColorProperty
//
// Copyright © InnovMetric Software Inc. 2017 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CIMPropertyGridColorProperty.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

// =================================================================================================
//   Ctor
//
// Parameter: strName_   : The name of the property
// Parameter: color_     : The color value of the property
// Parameter: pPalette_  : Pointer to a palette of colors
// Parameter: lpszDescr_ : The property description
// Parameter: dwData_    : Application-specific data
// -------------------------------------------------------------------------------------------------
CIMPropertyGridColorProperty::CIMPropertyGridColorProperty( const CString&  strName_,
                                                            const COLORREF& color_,
                                                            CPalette*       pPalette_,
                                                            LPCTSTR         lpszDescr_,
                                                            DWORD_PTR       dwData_ )
: CMFCPropertyGridColorProperty( strName_, color_, pPalette_, lpszDescr_, dwData_ )
{
    EnableOtherButton( L"More Colors..." );
    SetColumnsNumber( 8 );
}

// =================================================================================================
//   Return the format of the color property
// -------------------------------------------------------------------------------------------------
CString CIMPropertyGridColorProperty::FormatProperty()
{
    return CString();
}

// =================================================================================================
//   Return TRUE if the property has a value field
// -------------------------------------------------------------------------------------------------
BOOL CIMPropertyGridColorProperty::HasValueField() const
{
    return FALSE;
}

// =================================================================================================
// Return the edit area rectangle
// -------------------------------------------------------------------------------------------------
CRect CIMPropertyGridColorProperty::GetEditRect()
{
    CRect rectEdit;
    CRect rectSpin;

    AdjustInPlaceEditRect( rectEdit, rectSpin );

    rectEdit.InflateRect( m_rectButton.Width(), 0 );

    return rectEdit;
}
