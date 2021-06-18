﻿#ifndef _CCOMPANYNAMEPLUGIN_MONDAY_AUGUST06_154342_H_
#define _CCOMPANYNAMEPLUGIN_MONDAY_AUGUST06_154342_H_
// =================================================================================================
//   CompanyNameComPlugin class.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Kernel/IPlugin.h>

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Plug-in C++ interface used to connect to a PolyWorks module.
// -------------------------------------------------------------------------------------------------
class CCompanyNameCppPlugin : public IM::IPlugin
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------
    CCompanyNameCppPlugin();
    virtual ~CCompanyNameCppPlugin();

    virtual bool Load();
    virtual bool Unload();

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

#endif // _CCOMPANYNAMEPLUGIN_MONDAY_AUGUST06_154342_H_
