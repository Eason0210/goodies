#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IPlugin.h
///    \brief    IPlugin class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

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
///    \brief    Class defining the entry point of the host application into the plug-in. Every plug-in
///              must derive a class from IPlugin and implement it's pure virtual methods. Your plug-in
///              object must last as long as the DLL is loaded into the host application. For example,
///              you should create your IPlugin derived object when DllMain is called for the DLL_PROCESS_ATTACH
///              reason and destroy it when DllMain is called for the DLL_PROCESS_DETACH reason.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class IPlugin
{
public:
    // --------------  Types publics   -------------------------------------------------------------

    // --------------  Méthodes publiques  ---------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IPlugin() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IPlugin() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    This function is called by the host application when the plug-ins exported PluginInterfaceGet
    ///              function is called by the application. When this function is called, you may decide
    ///              (via the return code) to refuse the connection to the host application. At this
    ///              point, you have access to the IKernel object via the KernelGet method.
    ///
    ///    \return    true if the plug-in accepts the kernel, false otherwise
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool Load() = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    This function is called by the host application when the plug-ins is unloaded by
    ///              the host application. We suggest you free up any memory associated with your plug-in
    ///              at this point. IPlugin::Unload will always be called even if IPlugin::Load returned
    ///              false.
    ///
    ///    \return    true if the unload process went well, false otherwise
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool Unload() = 0;


protected:
    // --------------- Méthodes protégées ----------------------------------------------------------

    // --------------- Variables membres protégées -------------------------------------------------

private:
    // --------------- Méthodes privées ------------------------------------------------------------

    // --------------- Variables membres privées ---------------------------------------------------

};

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

} // namespace IM
