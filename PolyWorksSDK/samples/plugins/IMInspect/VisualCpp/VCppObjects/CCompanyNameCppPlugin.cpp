﻿// =================================================================================================
//   CCompanyNameComPlugin class.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "stdafx.h"

#include "CCompanyNameCppPlugin.h"

#include <PolyWorksSDK/Object/IPWObjects.h>

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// =================================== FUNCTIONS PROTOTYPES ========================================

// =================================================================================================
// =================================== FUNCTIONS DEFINITIONS =======================================

// =================================================================================================
// Default constructor.
// -------------------------------------------------------------------------------------------------
CCompanyNameCppPlugin::CCompanyNameCppPlugin()
{
}


// =================================================================================================
// Destructor.
// -------------------------------------------------------------------------------------------------
CCompanyNameCppPlugin::~CCompanyNameCppPlugin()
{
}


// =================================================================================================
// Called when the plug-in is loaded by the host application. You may do whatever initialisation
// you want here.
//
// Return: Returns whether there is a support for accessing PolyWorks Objects.
// -------------------------------------------------------------------------------------------------
bool CCompanyNameCppPlugin::Load()
{
    return IM::PWObjectsGet() != nullptr;
}


// =================================================================================================
// Called when the plug-in is unloaded by the host application. You may do whatever uninitialisation
// you want here.
//
// Return: Always true.
//         You could decide to return false to refuse the connection to the host application.
// -------------------------------------------------------------------------------------------------
bool CCompanyNameCppPlugin::Unload()
{
    return true;
}