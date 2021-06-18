#pragma once
// =================================================================================================
// Declaration of the commands.
//
// Copyright © InnovMetric Software Inc. 2017 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "CComCommand.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CCompanyNameScannerReceiver;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
// CCmdSharpEdgeMaxPointToPointDist.
// -------------------------------------------------------------------------------------------------
class CCmdSharpEdgeMaxPointToPointDist : public CComCommand
{
public:

    CCmdSharpEdgeMaxPointToPointDist( CComCommandInfo&             info_,
                                      CCompanyNameScannerReceiver& receiver_,
                                      const bool                   isGet_ );
    virtual ~CCmdSharpEdgeMaxPointToPointDist();

    STDMETHODIMP Execute2(
        /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes* pReturnCode_ ) override;

protected:

    // Protected member Functions
    ///////////////////////////////

private:
    const bool                   m_isGet;
    CCompanyNameScannerReceiver& m_Receiver;
};

// =================================================================================================
// CCmdSharpEdgeMinAngle.
// -------------------------------------------------------------------------------------------------
class CCmdSharpEdgeMinAngle : public CComCommand
{
public:

    CCmdSharpEdgeMinAngle( CComCommandInfo&             info_,
                           CCompanyNameScannerReceiver& receiver_,
                           const bool                   isGet_ );
    virtual ~CCmdSharpEdgeMinAngle();

    STDMETHODIMP Execute2(
        /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes* pReturnCode_ ) override;

protected:

    // Protected member Functions
    ///////////////////////////////

private:
    const bool                   m_isGet;
    CCompanyNameScannerReceiver& m_Receiver;
};

// =================================================================================================
// CCmdLog.
// -------------------------------------------------------------------------------------------------
class CCmdLog : public CComCommand
{
public:

    CCmdLog( CComCommandInfo&             info_,
             CCompanyNameScannerReceiver& receiver_ );
    virtual ~CCmdLog();

    STDMETHODIMP Execute2(
        /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes* pReturnCode_ ) override;

protected:

    // Protected member Functions
    ///////////////////////////////

private:
    CCompanyNameScannerReceiver& m_Receiver;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
