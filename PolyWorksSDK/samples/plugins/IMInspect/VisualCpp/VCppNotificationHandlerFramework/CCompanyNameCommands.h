#ifndef _CCOMPANYNAMECOMMANDS_TUESDAY_APRIL01_045131_H_
#define _CCOMPANYNAMECOMMANDS_TUESDAY_APRIL01_045131_H_
// =================================================================================================
//   Plug-in's commands.
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <functional>

#include "CComCommand.h"
#include "CComCommandInfo.h"
#include "Types.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CDlgCompanyNameNotificationViewer;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Shows or hides plug-in dialog
// -------------------------------------------------------------------------------------------------
class CCmdCompanyNameDlgNotificationViewerShow : public CComCommand
{
public:
    // ---------------- Public Methods  ------------------------------------------------------------
    CCmdCompanyNameDlgNotificationViewerShow( CComCommandInfo& info_, CDlgCompanyNameNotificationViewer& dlg_ );
    ~CCmdCompanyNameDlgNotificationViewerShow() override = default;

    STDMETHODIMP Execute2( /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
                           /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );
private:
    ECommandReturnCodes InterfacePopup();
    ECommandReturnCodes InterfacePopdown();
    // ---------------- Private Member Variables ---------------------------------------------------

    CDlgCompanyNameNotificationViewer* m_pDlg = nullptr;
};

#endif // ifndef _CCOMPANYNAMECOMMANDS_TUESDAY_AUGUST07_085131_H_
