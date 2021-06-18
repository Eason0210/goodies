// =================================================================================================
// Implementation of the CIMPropertyGridCheckBoxProperty
//
// Copyright © InnovMetric Software Inc. 2017 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CIMPropertyGridCheckBoxProperty.h"

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
CIMPropertyGridCheckBoxProperty::CIMPropertyGridCheckBoxProperty(
    const CString&     strGroupName_,
    DWORD_PTR          dwData_,
    BOOL               bIsValueList_,
    const COleVariant& varValue_ )
: CIMPropertyGridProperty( strGroupName_, dwData_, bIsValueList_, varValue_ )
{
}

// =================================================================================================
//   Ctor for an item.
//
// Parameter: strName_          : The name of the property
// Parameter: varValue_         : The property value
// Parameter: lpszDescr_        : The property description
// Parameter: dwData_           : Application-specific data
// -------------------------------------------------------------------------------------------------
CIMPropertyGridCheckBoxProperty::CIMPropertyGridCheckBoxProperty(
    const CString&     strName_,
    const COleVariant& varValue_,
    LPCTSTR            lpszDescr_,
    DWORD_PTR          dwData_ )
: CIMPropertyGridProperty( strName_, varValue_, lpszDescr_, dwData_, nullptr, nullptr, nullptr )
{
}

// =================================================================================================
// Called when the cursor needs to be changed.
// -------------------------------------------------------------------------------------------------
BOOL CIMPropertyGridCheckBoxProperty::OnSetCursor() const
{
    if ( IsBoolValue() )
    {
        SetCursor( LoadCursor( nullptr, IDC_ARROW ) );

        return TRUE;
    }

    return __super::OnSetCursor();
}

// =================================================================================================
// Return : TRUE if the value is of type VT_BOOL
// -------------------------------------------------------------------------------------------------
BOOL CIMPropertyGridCheckBoxProperty::IsBoolValue() const
{
    if ( m_varValue.vt == VT_BOOL )
    {
        return TRUE;
    }

    return FALSE;
}

// =================================================================================================
// Return : TRUE if property has a button
// -------------------------------------------------------------------------------------------------
BOOL CIMPropertyGridCheckBoxProperty::HasButton () const
{
    if ( IsBoolValue() )
    {
        return FALSE;
    }

    return __super::HasButton();
}

// =================================================================================================
//   Called from the property list control when the property is selected and the user enters a new character
//
// Parameter : nChar_ : character to be processed
//
// Return : TRUE if the char is processed
// -------------------------------------------------------------------------------------------------
BOOL CIMPropertyGridCheckBoxProperty::PushChar ( UINT nChar_ )
{
    if ( IsBoolValue() && ( nChar_ == VK_SPACE ) ) // toggle with space
    {
        ToggleBool(); // toggle selection
        return TRUE;
    }

    return __super::PushChar( nChar_ );
}

// =================================================================================================
//   Toggles the (boolean) value
// -------------------------------------------------------------------------------------------------
void CIMPropertyGridCheckBoxProperty::ToggleBool ()
{
    ASSERT( IsBoolValue() ); // only bool values can be changed

    m_varValue.boolVal = ( m_varValue.boolVal != VARIANT_FALSE ? VARIANT_FALSE : VARIANT_TRUE );

    m_pWndList->OnPropertyChanged( this );
    m_pWndList->InvalidateRect( GetRect() );
}

// =================================================================================================
//   Called by a parent property list control when a user clicks the value field of a property
//
// Parameter : uiMsg_ : the message to be processed
// Parameter : point_ : the cursor position
//
// Return : TRUE if the message is processed
// -------------------------------------------------------------------------------------------------
BOOL CIMPropertyGridCheckBoxProperty::OnClickValue ( UINT uiMsg_, CPoint point_ )
{
    if ( IsBoolValue() )
    {
        m_pWndList->EndEditItem();

        CRect rcCheck;
        GetCheckRect( &rcCheck );

        if ( rcCheck.PtInRect( point_ ) )
        {
            ToggleBool(); // toggle selection

            return TRUE;
        }

        return FALSE;
    }

    return __super::OnClickValue( uiMsg_, point_ );
}

// =================================================================================================
//   Called by a parent property list control when a user double clicks the value field of a property
//
// Parameter : point_ : the cursor position
//
// Return : TRUE if the message is processed
// -------------------------------------------------------------------------------------------------
BOOL CIMPropertyGridCheckBoxProperty::OnDblClk ( CPoint point_ )
{
    if ( IsBoolValue() )
    {
        ToggleBool();

        m_pWndList->EndEditItem();

        return TRUE;
    }

    return __super::OnDblClk( point_ );
}

// =================================================================================================
//   Calculates checkbox rectangle
//
// Parameter : pRcCheck_ : the check rectangle
// -------------------------------------------------------------------------------------------------
void CIMPropertyGridCheckBoxProperty::GetCheckRect ( CRect* pRcCheck_ )
{
    CRect rcSpin;

    AdjustInPlaceEditRect( *pRcCheck_, rcSpin );

    pRcCheck_->right = pRcCheck_->left + pRcCheck_->Height(); // get left-aligned square of property item rect
}

// =================================================================================================
// Called by the framework to create an editable control for a property.
//
// Parameter : rectEdit_       : The bounding rectangle of the editable control.
// Parameter : bDefaultFormat_ : TRUE to use the default property format to set the text of the
//                               editable control; otherwise, FALSE.
//
// Return : A pointer to the editable control if this method succeeds; otherwise, NULL.
// -------------------------------------------------------------------------------------------------
CWnd* CIMPropertyGridCheckBoxProperty::CreateInPlaceEdit ( CRect rectEdit_, BOOL& bDefaultFormat_ )
{
    if ( IsBoolValue() )
    {
        rectEdit_.OffsetRect( rectEdit_.Width(), 0 ); // place the in-place edit control outside the visible area (we do not need this control, it will be destroyed immediately. offsetting avoids flickering.
    }

    CWnd* pWnd = __super::CreateInPlaceEdit( rectEdit_, bDefaultFormat_ );

    if ( IsBoolValue() && IsGroup() )
    {
        bDefaultFormat_ = FALSE;
    }

    return pWnd;
}
