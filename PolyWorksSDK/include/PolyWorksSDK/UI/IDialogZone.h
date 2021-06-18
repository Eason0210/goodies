#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IDialogZone.h
///    \brief    IDialogZone class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
/// ************************************************************************** */

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <windef.h>

#include <PolyWorksSDK/Base/CWString.h>
#include "PolyWorksSDK/UI/FnIDialogZone.h"

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
///    \ingroup  IM_INTERFACES
///
///    \brief    Class representing the Dialog Zone. With this class you add your dialogs to the host
///              application's Dialog Zone.
///
///              You can retrieve a pointer to this class by calling IUserInterface::DialogZoneGet.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class IDialogZone
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IDialogZone() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IDialogZone() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Add a plug-in dialog to the Dialog Zone. To avoid drawing issues, the dialog have
    ///              to be hidden before calling this function. The Dialog Zone will show it when needed.
    ///              When added to the Dialog Zone, you will maybe only see parts of it because of the
    ///              size of the Dialog Zone. To make it easier to navigate through it, you may specify
    ///              your dialog's minimum size (in pixels) at any time by calling IDialogZone::DialogMinSizeSet.
    ///              In doing so, scroll bars will appear whenever the Dialog Zone becomes smaller than
    ///              your specified minimum size. The default value of the dialog's minimum size is the
    ///              dialog's size when it's added to the Dialog Zone.
    ///
    ///    \param[ in ] hDlg_                      The dialogs handle
    ///    \param[ in ] uniqueStringIdentifier_    A unique string identifier. We recommend you give
    ///                                            your company name as a prefix and then your dialogs
    ///                                            title. For example: L"CompanyNameDialogTitle"
    ///
    ///    \return    true if the dialog has been added to the Dialog Zone, false otherwise
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool DialogAdd( HWND hDlg_, const CWString& uniqueStringIdentifier_ ) = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Updates the dialog minimal size (useful to make scoll bar appear when the Dialog
    ///              Zone is smaller than the dialog).
    ///
    ///    \param[ in ] uniqueStringIdentifier_    The dialog's unique string identifier
    ///    \param[ in ] minCx_                     Minimum size in x (in pixels)
    ///    \param[ in ] minCy_                     Minimum size in y (in pixels)
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void DialogMinSizeSet( const CWString& uniqueStringIdentifier_, int minCx_, int minCy_ ) = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Remove a plug-in dialog from the Dialog Zone.
    ///
    ///    \param[ in ] uniqueStringIdentifier_    The dialog's unique string identifier
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void DialogRemove( const CWString& uniqueStringIdentifier_ ) = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Brings the dialog identified by uniqueStringIdentifier_ to foreground in the DialogZone.
    ///
    ///
    ///    \param[ in ] uniqueStringIdentifier_    The dialog's unique string identifier
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void DialogSetForeground( const CWString& uniqueStringIdentifier_ ) = 0;

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
