#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     FnDialog.h
///    \brief    Functions for managing dialog boxes.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
/// ************************************************************************** */

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <windows.h> // IWYU pragma: keep

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>

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

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Adds control information which is used to keep a modified state and an association
///              with a red label. When that control is marked as modified, its associated red label
///              will be displayed using a red color.
///
///    \param[ in ] hDlg_         The dialog's handle
///    \param[ in ] hCtl_         The control which modified state will be reflected by the red label
///    \param[ in ] hRedLabel_    The control that will be displayed in red if the hCtl_ is marked as
///                               modified
///
///    \return    true if the control information was added successfully
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool DialogRedLabelsControlAdd( HWND hDlg_, HWND hCtl_, HWND hRedLabel_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Adds control information which is used to keep a modified state and an association
///              with a red label. When that control is marked as modified, its associated red label
///              will be displayed using a red color.  The red label will association automatically
///              be distributed following these rules:  * For Edit boxes, Combo boxes, List boxes,
///              the preceeding control in the tab order will become the red label. * For Check boxes
///              and Radio buttons, the red label is the control itself.
///
///    \param[ in ] hDlg_    The dialog's handle
///    \param[ in ] hCtl_    The control which modified state will be reflected by the red label
///
///    \return    true if the control information was added successfully
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool DialogRedLabelsControlAddAuto( HWND hDlg_, HWND hCtl_ );

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Tells whether the control is marked as modified
///
///    \param[ in ] hDlg_    The dialog's handle
///    \param[ in ] hCtl_    The control which modified state will be evaluated
///
///    \return    true if the control is marked as modified; false otherwise
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool DialogRedLabelsControlIsModified( HWND hDlg_, HWND hCtl_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Sets whether the control will be marked as modified. Therefore, changing the displaying
///              color of its associated red label.
///
///    \param[ in ] hDlg_        The dialog's handle
///    \param[ in ] hCtl_        The control which modified state will be modified
///    \param[ in ] modified_    true to mark the control as modified; false to unmark.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API void DialogRedLabelsControlModifiedSet( HWND hDlg_, HWND hCtl_, bool modified_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    This function is designed to be called in the dialog box's OnCommand ( WM_COMMAND
///              ). It checks if the message is a user input in a control with red label information,
///              then sets the controls modified state to true and changes the color of the associated
///              red label.  Note that the WM_COMMAND message cannot differenciate user input from
///              SetWindowText or Button_SetCheck like messages. Therefore, it is the programmer's
///              responsability to manually unmark a control as modified after such manual resetting
///              operations.
///
///    \param[ in ] hDlg_      The dialog's handle
///    \param[ in ] wParam_    WPARAM of the WM_COMMAND message
///    \param[ in ] lParam_    LPARAM of the WM_COMMAND message
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API void DialogRedLabelsOnCommand( HWND hDlg_, WPARAM wParam_, LPARAM lParam_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    This function is designed to be called in the dialog box's OnCtlColor ( WM_CTLCOLOR
///              ). It checks if the message is related to a red label, then changes the control's
///              display color depending on the modified state of its associated control.
///
///    \param[ in ] hDlg_    The dialog's handle
///    \param[ in ] hdc_     The display device context for the control
///    \param[ in ] hCtl_    The red label which associated control's modified state will be evaluated
///                          to determine which color
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API void DialogRedLabelsOnCtlColor( HWND hDlg_, HDC hdc_, HWND hCtl_ );

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    This function is designed to be called in the dialog box's OnDestroy (WM_DESTROY).
///              It uninitializes the red label tool associated to the dialog box.
///
///    \param[ in ] hDlg_    The dialog's handle
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API void DialogRedLabelsUninit( HWND hDlg_ );

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    NOTE: As of version 2015, this function is deprecated and does nothing.  Make a plug-in
///              dialog have the same look as every other dialog in the host application. The visual
///              style of the background and controls will change to make the dialog look as if it
///              was totally integrated.
///
///    \param[ in ] hDlg_                    The dialog's handle
///    \param[ in ] forceApplyTabTexture_    true if the dialog is to be contained in a tab control,
///                                          false otherwise.
///
///    \return    true if the skin has been added successfully, false otherwise.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool DialogSkinSet( HWND hDlg_, bool forceApplyTabTexture_ = false );

} // namespace IM
