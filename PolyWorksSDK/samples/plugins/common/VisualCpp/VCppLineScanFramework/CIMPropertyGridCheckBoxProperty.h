#pragma once
// =================================================================================================
// Declaration of the CIMPropertyGridCheckBoxProperty
//
// Copyright © InnovMetric Software Inc. 2017 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "CIMPropertyGridProperty.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   CIMPropertyGridCheckBoxProperty class
// -------------------------------------------------------------------------------------------------
class CIMPropertyGridCheckBoxProperty : public CIMPropertyGridProperty
{
public:
    CIMPropertyGridCheckBoxProperty( const CString&     strGroupName_,
                                     DWORD_PTR          dwData_ = 0,
                                     BOOL               bIsValueList_ = FALSE,
                                     const COleVariant& varValue_     = COleVariant() );

    CIMPropertyGridCheckBoxProperty( const CString&     strName_,
                                     const COleVariant& varValue_,
                                     LPCTSTR            lpszDescr_ = nullptr,
                                     DWORD_PTR          dwData_    = 0 );

    BOOL IsBoolValue () const override;
    void GetCheckRect( CRect* pRcCheck_ ) override;

    void ToggleBool (); // toggles the (boolean) value

protected:
    BOOL  OnSetCursor() const override;
    BOOL  HasButton() const override;
    BOOL  PushChar ( UINT nChar_ ) override;
    BOOL  OnClickValue ( UINT uiMsg_, CPoint point_ ) override;
    BOOL  OnDblClk ( CPoint point_ ) override;
    CWnd* CreateInPlaceEdit ( CRect rectEdit_, BOOL& bDefaultFormat_ ) override;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
