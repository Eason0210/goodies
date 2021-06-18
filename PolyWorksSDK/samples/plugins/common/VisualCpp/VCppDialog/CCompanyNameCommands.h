#ifndef _CCOMPANYNAMECOMMANDS_TUESDAY_AUGUST07_085131_H_
#define _CCOMPANYNAMECOMMANDS_TUESDAY_AUGUST07_085131_H_
// =================================================================================================
//   Plug-in's commands.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CComCommand.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CDlgVCppDialog;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Pops up a dialog from a plug-in into the Dialog Zone.
//   TODO: Rename CompanyNameAction with your comany name.
// -------------------------------------------------------------------------------------------------
class CCmdCompanyNameDialogPopUp : public CComCommand
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------
    CCmdCompanyNameDialogPopUp( CComCommandInfo& info_ );
    virtual ~CCmdCompanyNameDialogPopUp();

    STDMETHODIMP Execute2( /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
                           /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

    CDlgVCppDialog* m_pDlgVCppDialog;
};


// =================================================================================================
//   Pops down a dialog from a plug-in into the Dialog Zone.
//   TODO: Rename CompanyNameAction with your comany name.
// -------------------------------------------------------------------------------------------------
class CCmdCompanyNameDialogPopDown : public CComCommand
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------
    CCmdCompanyNameDialogPopDown( CComCommandInfo& info_ );
    virtual ~CCmdCompanyNameDialogPopDown();

    STDMETHODIMP Execute2( /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
                           /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

};


// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================


#endif // _CCOMPANYNAMECOMMANDS_TUESDAY_AUGUST07_085131_H_
