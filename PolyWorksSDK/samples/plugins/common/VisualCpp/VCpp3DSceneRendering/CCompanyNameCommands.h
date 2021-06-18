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

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   MSCL command drawing in the 3D Scene.
//
//   TODO: Rename CompanyNameAction with your comany name.
// -------------------------------------------------------------------------------------------------
class CCmdCompanyName3DSceneRenderingStart : public CComCommand
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------
    CCmdCompanyName3DSceneRenderingStart( CComCommandInfo& info_ );
    virtual ~CCmdCompanyName3DSceneRenderingStart();

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
//   MSCL command removing any drawing in the 3D Scene created by
//   CCmdCompanyName3DSceneRenderingStart.
//
//   TODO: Rename CompanyNameAction with your comany name.
// -------------------------------------------------------------------------------------------------
class CCmdCompanyName3DSceneRenderingStop : public CComCommand
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------
    CCmdCompanyName3DSceneRenderingStop( CComCommandInfo& info_ );
    virtual ~CCmdCompanyName3DSceneRenderingStop();

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

void AnnotationsRemoveAll();
void DrawNodesRemoveAll();

#endif // _CCOMPANYNAMECOMMANDS_TUESDAY_AUGUST07_085131_H_
