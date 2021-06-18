#ifndef _CCOMPANYNAMECOMMANDS_TUESDAY_AUGUST07_085131_H_
#define _CCOMPANYNAMECOMMANDS_TUESDAY_AUGUST07_085131_H_
// =================================================================================================
// Plug-in's commands.
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
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
// TODO: Rename CompanyNameAction with your company name and your action
//
// TODO: Add command description here.
// -------------------------------------------------------------------------------------------------
class CCmdCompanyNameAction : public CComCommand
{
public:

    CCmdCompanyNameAction( CComCommandInfo& info_ );
    virtual ~CCmdCompanyNameAction() {}

    STDMETHODIMP Execute2(
        /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );
};

// =================================================================================================
// TODO: Rename CompanyNameDouble with your company name and double setting name.
//
// Sets a double value setting within the plug-in
// -------------------------------------------------------------------------------------------------
class CCmdCompanyNameDoubleSet : public CComCommand
{
public:

    CCmdCompanyNameDoubleSet( CComCommandInfo& info_ );
    virtual ~CCmdCompanyNameDoubleSet() {}

    STDMETHODIMP Execute2(
        /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );
};

// =================================================================================================
// TODO: Rename CompanyNameDouble with your company name and double setting name.
//
// Gets a double value setting from the plug-in
// -------------------------------------------------------------------------------------------------
class CCmdCompanyNameDoubleGet : public CComCommand
{
public:

    CCmdCompanyNameDoubleGet( CComCommandInfo& info_ );
    virtual ~CCmdCompanyNameDoubleGet() {}

    STDMETHODIMP Execute2(
        /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );
};

// =================================================================================================
// TODO: Rename CompanyNameInteger with your company name and integer setting name.
//
// Sets a integer value setting within the plug-in
// -------------------------------------------------------------------------------------------------
class CCmdCompanyNameIntegerSet : public CComCommand
{
public:

    CCmdCompanyNameIntegerSet( CComCommandInfo& info_ );
    virtual ~CCmdCompanyNameIntegerSet() {}

    STDMETHODIMP Execute2(
        /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );
};

// =================================================================================================
// TODO: Rename CompanyNameInteger with your company name and integer setting name.
//
// Gets a integer value setting from the plug-in
// -------------------------------------------------------------------------------------------------
class CCmdCompanyNameIntegerGet : public CComCommand
{
public:

    CCmdCompanyNameIntegerGet( CComCommandInfo& info_ );
    virtual ~CCmdCompanyNameIntegerGet() {}

    STDMETHODIMP Execute2(
        /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );
};

// =================================================================================================
// TODO: Rename CompanyNameString with your company name and string setting name.
//
// Sets a string value setting within the plug-in
// -------------------------------------------------------------------------------------------------
class CCmdCompanyNameStringSet : public CComCommand
{
public:

    CCmdCompanyNameStringSet( CComCommandInfo& info_ );
    virtual ~CCmdCompanyNameStringSet() {}

    STDMETHODIMP Execute2(
        /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );
};

// =================================================================================================
// TODO: Rename CompanyNameString with your company name and string setting name.
//
// Gets a string value setting from the plug-in
// -------------------------------------------------------------------------------------------------
class CCmdCompanyNameStringGet : public CComCommand
{
public:

    CCmdCompanyNameStringGet( CComCommandInfo& info_ );
    virtual ~CCmdCompanyNameStringGet() {}

    STDMETHODIMP Execute2(
        /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

#endif // _CCOMPANYNAMECOMMANDS_TUESDAY_AUGUST07_085131_H_
