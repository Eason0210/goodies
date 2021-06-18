// =================================================================================================
// Implementation of the CIMPropertyGridCtrl
//
// Copyright © InnovMetric Software Inc. 2017 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CIMPropertyGridCtrl.h"

#include "CIMPropertyGridColorProperty.h"
#include "CIMPropertyGridProperty.h"

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
//   Called before a message is processed
//
// Parameter : pMsg_ : message to process
//
// Return : TRUE if the message is processed
// -------------------------------------------------------------------------------------------------
BOOL CIMPropertyGridCtrl::PreTranslateMessage( MSG* pMsg_ )
{
    switch ( pMsg_->message )
    {
        case WM_LBUTTONDOWN:
        {
            CPoint point( GET_X_LPARAM( pMsg_->lParam ), GET_Y_LPARAM( pMsg_->lParam ) );

            CMFCPropertyGridProperty* pSel = GetCurSel();

            if ( ( pSel != nullptr ) &&
                 ( pSel->IsInPlaceEditing() != FALSE ) &&
                 pSel->IsEnabled() )
            {
                ASSERT_VALID( pSel );

                auto* pSelEx = dynamic_cast< CIMPropertyGridProperty* >( pSel );
                if ( ( pSelEx != nullptr ) && pSelEx->HasList() )
                {
                    // Set the focus to the property
                    SetFocus();
                }
            }
            else
            {
                CMFCPropertyGridProperty::ClickArea clickArea;
                CMFCPropertyGridProperty*           pHit = HitTest( point, &clickArea );

                if ( pSel != pHit )
                {
                    pSel = pHit;
                    SetCurSel( pSel );
                }

                auto* pPropertyGridColorProp = dynamic_cast< CIMPropertyGridColorProperty* >( pSel );
                if ( ( pPropertyGridColorProp != nullptr ) &&
                     pPropertyGridColorProp->IsEnabled() )
                {
                    CRect rectEdit = pPropertyGridColorProp->GetEditRect();
                    if ( rectEdit.PtInRect( point ) )
                    {
                        // Show the color picker of this property
                        pPropertyGridColorProp->OnClickButton( point );
                    }
                }
            }
        }
        break;
    }

    return __super::PreTranslateMessage( pMsg_ );
}
