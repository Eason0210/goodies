#pragma once
// =================================================================================================
// Declatation of the CIMPropertyGridProperty
//
// Copyright © InnovMetric Software Inc. 2017 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <afxdisp.h>
#include <afxpropertygridctrl.h>
#include <minmax.h>

#include "Types.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   CIMPropertyGridProperty class
// -------------------------------------------------------------------------------------------------
class CIMPropertyGridProperty : public CMFCPropertyGridProperty
{
public:
    CIMPropertyGridProperty( const CString&     strGroupName_,
                             DWORD_PTR          dwData_ = 0,
                             BOOL               bIsValueList_ = FALSE,
                             const COleVariant& varValue_     = COleVariant() );

    CIMPropertyGridProperty( const CString&     strName_,
                             const COleVariant& varValue_,
                             LPCTSTR            lpszDescr_        = nullptr,
                             DWORD_PTR          dwData_           = 0,
                             LPCTSTR            lpszEditMask_     = nullptr,
                             LPCTSTR            lpszEditTemplate_ = nullptr,
                             LPCTSTR            lpszValidChars_   = nullptr );

    CIMPropertyGridProperty( const CString&     strName_,
                             const COleVariant& varValue_,
                             const TWStrings&   comboChoices,
                             const BOOL         bAllow_,
                             LPCTSTR            lpszDescr_ = nullptr,
                             DWORD_PTR          dwData_    = 0 );

    BOOL HasList();

    virtual BOOL IsBoolValue() const                  { return FALSE; }
    virtual void GetCheckRect( CRect* /*pRcCheck_*/ ) {}

    CString FormatProperty() override;

protected:
    BOOL HasValueField() const override;

    void OnDrawName( CDC* pDC_, CRect rect_ ) override;
    void OnDrawValue( CDC* pDC_, CRect rect_ ) override;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
