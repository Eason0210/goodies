// =================================================================================================
// Implementation of the CIMPropertyGridProperty
//
// Copyright © InnovMetric Software Inc. 2017 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CIMPropertyGridProperty.h"

#include "CCompanyNameScannerSettings.h"

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
//   Ctor for a group.
//
// Parameter: strGroupName_ : The group name
// Parameter: dwData_       : Application-specific data
// Parameter: bIsValueList_ : TRUE if the property represents a list of values;
//                            FALSE if the property represents a single value
// Parameter: varValue_     : The property value
// -------------------------------------------------------------------------------------------------
CIMPropertyGridProperty::CIMPropertyGridProperty( const CString&     strGroupName_,
                                                  DWORD_PTR          dwData_,
                                                  BOOL               bIsValueList_,
                                                  const COleVariant& varValue_ )
: CMFCPropertyGridProperty( strGroupName_, dwData_, bIsValueList_ )
{
    if ( bIsValueList_ == TRUE )
    {
        ASSERT( varValue_.vt != VT_EMPTY );

        SetValue( varValue_ );
    }
}

// =================================================================================================
//   Ctor for an item.
//
// Parameter: strName_          : The name of the property
// Parameter: varValue_         : The property value
// Parameter: lpszDescr_        : The property description
// Parameter: dwData_           : Application-specific data
// Parameter: lpszEditMask_     : The edit mask, if the property is a masked edit control
// Parameter: lpszEditTemplate_ : The edit template, if the property is a masked edit control
// Parameter: lpszValidChars_   : A list of valid characters, if the property is a masked edit control
// -------------------------------------------------------------------------------------------------
CIMPropertyGridProperty::CIMPropertyGridProperty( const CString&     strName_,
                                                  const COleVariant& varValue_,
                                                  LPCTSTR            lpszDescr_,
                                                  DWORD_PTR          dwData_,
                                                  LPCTSTR            lpszEditMask_,
                                                  LPCTSTR            lpszEditTemplate_,
                                                  LPCTSTR            lpszValidChars_ )
: CMFCPropertyGridProperty( strName_, varValue_, lpszDescr_, dwData_, lpszEditMask_, lpszEditTemplate_, lpszValidChars_ )
{
}

// =================================================================================================
//   Ctor for a list combo.
//
// Parameter: strName_          : The name of the property
// Parameter: varValue_         : The property value
// Parameter: comboChoices_     : Combo box options
// Parameter: bAllow_           : TRUE to make the property editable;
//                                FALSE to make the property read-only
// Parameter: lpszDescr_        : The property description
// Parameter: dwData_           : Application-specific data
// -------------------------------------------------------------------------------------------------
CIMPropertyGridProperty::CIMPropertyGridProperty( const CString&     strName_,
                                                  const COleVariant& varValue_,
                                                  const TWStrings&   comboChoices,
                                                  const BOOL         bAllow_,
                                                  LPCTSTR            lpszDescr_,
                                                  DWORD_PTR          dwData_ )
: CMFCPropertyGridProperty( strName_, varValue_, lpszDescr_, dwData_ )
{
    for ( const auto& comboChoice : comboChoices )
    {
        AddOption( comboChoice.c_str() );
    }
    AllowEdit( bAllow_ );
}

// =================================================================================================
//   Return the format of the property
// -------------------------------------------------------------------------------------------------
CString CIMPropertyGridProperty::FormatProperty()
{
    CString format;
    CString str;

    const int nbDigits = max( 1, 3 + log10( 1.0 / theCompanyNameScannerSettings().HostUnitsScalingFactorGet() ) );

    switch ( GetValue().vt )
    {
        case VT_R8:
            format.Format( L"%%.%dlf", nbDigits );
            str.Format( format, GetValue().dblVal );
            break;
        case VT_R4:
            format.Format( L"%%.%df", nbDigits );
            str.Format( format, GetValue().fltVal );
            break;
        default:
            str = __super::FormatProperty();
    }

    return str;
}

// =================================================================================================
// Return true if the property has a list
// -------------------------------------------------------------------------------------------------
BOOL CIMPropertyGridProperty::HasList()
{
    return ( m_dwData != -1 ) && ( m_dwFlags & 0x0001 /*AFX_PROP_HAS_LIST*/ ) != 0;
}

// =================================================================================================
// Return TRUE if the property has a value
// -------------------------------------------------------------------------------------------------
BOOL CIMPropertyGridProperty::HasValueField() const
{
    return m_dwData != -1 ? TRUE : FALSE;
}

// =================================================================================================
// Called when name needs to be drawn.
//
// Parameter : pDC_  : pointer to a device context
// Parameter : rect_ : bounding rectangle that specifies where to draw the property value
// -------------------------------------------------------------------------------------------------
void CIMPropertyGridProperty::OnDrawName( CDC* pDC_, CRect rect_ )
{
    CFont* pOldFont = nullptr;

    if ( ( IsBoolValue() || !HasValueField() ) && IsGroup() )
    {
        CBrush btnFaceBrush( GetSysColor( COLOR_3DFACE ) );
        pDC_->FillRect( rect_, &btnFaceBrush );

        // Correct the indentation of sub groups
        if ( GetParent() != nullptr )
        {
            rect_.left -= rect_.Height();
        }
        else
        {
            pOldFont = static_cast< CFont* >( pDC_->SelectObject( &m_pWndList->GetBoldFont() ) );
        }
    }
    else if ( !IsGroup() && GetParent() == nullptr )
    {
        // Correct the indentation if the first item has no parent
        rect_.left += rect_.Height();
    }

    __super::OnDrawName( pDC_, rect_ );

    if ( pOldFont != nullptr )
    {
        pDC_->SelectObject( pOldFont );
    }
}

// =================================================================================================
// Called when item needs to be drawn.
//
// Parameter : pDC_  : pointer to a device context
// Parameter : rect_ : bounding rectangle that specifies where to draw the property value
// -------------------------------------------------------------------------------------------------
void CIMPropertyGridProperty::OnDrawValue( CDC* pDC_, CRect rect_ )
{
    if ( IsBoolValue() || !HasValueField() )
    {
        if ( IsGroup() )
        {
            CBrush btnFaceBrush( GetSysColor( COLOR_3DFACE ) );
            pDC_->FillRect( rect_, &btnFaceBrush );
        }

        CRect rcCheck;
        GetCheckRect( &rcCheck );

        COLORREF crTextOld = pDC_->GetTextColor();
        CMFCVisualManager::GetInstance()->OnDrawCheckBox( pDC_, rcCheck, FALSE, m_varValue.boolVal, m_bEnabled );
        pDC_->SetTextColor( crTextOld );
    }
    else
    {
        __super::OnDrawValue( pDC_, rect_ );
    }
}
