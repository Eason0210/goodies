﻿#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IKernel.h
///    \brief    IKernel class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "FnIKernel.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class IPWObjects;
class IUserInterface;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_INTERFACES
///
///    \brief    Class representing the entry point of the plug-in into the host application. You
///              can get an access on the application's objects and on the application's user interface
///              via IKernel. To obtain the IKernel pointer, you must call KernelGet.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class IKernel
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IKernel() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IKernel() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns a pointer to the PolyWorks Objects manager.
    ///
    ///    \return    Pointer to the PolyWorks Objects management object.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual IPWObjects* PWObjectsGet() const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns a pointer to the user interface manager.
    ///
    ///    \return    Pointer to the user interface entry point.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual IUserInterface* UserInterfaceGet() const = 0;


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