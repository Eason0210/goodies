// =================================================================================================
// Implementation of the commands.
//
// Copyright © InnovMetric Software Inc. 2017 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CCompanyNameCmd.h"

#include <PolyWorksSDK/COM/IIMCommandArgument.h>

#include "ApplicationUtils.h"
#include "CCompanyNameScannerReceiver.h"
#include "CCompanyNameScannerSettings.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

// =================================================================================================
// Commands constructor.
// This constructor is only called one time when the command is registered to the application.
//
// Parameter: info_ : Parameters necessary to build the command.
// -------------------------------------------------------------------------------------------------
CCmdSharpEdgeMaxPointToPointDist::CCmdSharpEdgeMaxPointToPointDist(
    CComCommandInfo&             info_,
    CCompanyNameScannerReceiver& receiver_,
    const bool                   isGet_ )
: CComCommand( info_ )
, m_Receiver( receiver_ )
, m_isGet( isGet_ )
{
}

// =================================================================================================
// Commands destructor
// -------------------------------------------------------------------------------------------------
CCmdSharpEdgeMaxPointToPointDist::~CCmdSharpEdgeMaxPointToPointDist() = default;

// =================================================================================================
// Sets the sharp edge max point to point distance value setting within the plug-in.
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdSharpEdgeMaxPointToPointDist::Execute2(
    /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    ECommandReturnCodes retCode = E_CMD_FAILED;

    // Getting argument value
    bool   success  = false;
    double argValue = 0.0;

    if ( pIIMCommandArgumentEnum_ != nullptr )
    {
        long nbArg = 0;

        // Checking argument count validity
        if ( ( pIIMCommandArgumentEnum_->ArgsGetNb( &nbArg ) == S_OK ) &&
             ( nbArg > 0 ) )
        {
            CComPtr< IIMCommandArgument > pArgument;

            // Checking availability of first argument
            if ( ( pIIMCommandArgumentEnum_->ArgGet( 0, &pArgument ) == S_OK ) &&
                 ( pArgument != nullptr ) )
            {
                double hostUnitsFactor = theCompanyNameScannerSettings().HostUnitsScalingFactorGet();
                long   retVal          = 0;

                if ( m_isGet )
                {
                    argValue = theCompanyNameScannerSettings().IMISharpEdgeMaxPointToPointDistanceGet() * hostUnitsFactor;
                    // Sets argument value if of valid type
                    if ( ( pArgument->ArgValueSetFromDouble( 1, argValue, &retVal ) == S_OK ) &&
                         ( retVal == 1 ) )
                    {
                        success = true;

                        retCode = E_CMD_SUCCEEDED;
                    }
                }
                else
                {
                    // Checking and retrieving argument value if of valid type
                    if ( ( pArgument->ArgValueGetAsDouble( 1, &argValue, &retVal ) == S_OK ) &&
                         ( retVal == 1 ) )
                    {
                        if ( argValue <= 0 )
                        {
                            IMMessageBox( E_MESSAGE_TYPE_INFORMATION, L"The sharp edge max point to point is out of range" );

                            retCode = E_CMD_ARG_OUT_OF_RANGE;
                        }
                        else
                        {
                            theCompanyNameScannerSettings().IMISharpEdgeMaxPointToPointDistanceSet( argValue / hostUnitsFactor );

                            retCode = E_CMD_SUCCEEDED;
                        }
                    }
                }
            }
        }
    }

    if ( pReturnCode_ != nullptr )
    {
        // Error code assignment
        *pReturnCode_ = retCode;

        return S_OK;
    }

    return S_FALSE;
}

// =================================================================================================
// Commands constructor.
// This constructor is only called one time when the command is registered to the application.
//
// Parameter: info_ : Parameters necessary to build the command.
// -------------------------------------------------------------------------------------------------
CCmdSharpEdgeMinAngle::CCmdSharpEdgeMinAngle(
    CComCommandInfo&             info_,
    CCompanyNameScannerReceiver& receiver_,
    const bool                   isGet_ )
: CComCommand( info_ )
, m_Receiver( receiver_ )
, m_isGet( isGet_ )
{
}

// =================================================================================================
// Commands destructor
// -------------------------------------------------------------------------------------------------
CCmdSharpEdgeMinAngle::~CCmdSharpEdgeMinAngle() = default;

// =================================================================================================
// Sets the sharp edge min angle value setting within the plug-in.
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdSharpEdgeMinAngle::Execute2(
    /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    ECommandReturnCodes retCode = E_CMD_FAILED;

    // Getting argument value
    bool   success  = false;
    double argValue = 0.0;

    if ( pIIMCommandArgumentEnum_ != nullptr )
    {
        long nbArg = 0;

        // Checking argument count validity
        if ( ( pIIMCommandArgumentEnum_->ArgsGetNb( &nbArg ) == S_OK ) &&
             ( nbArg > 0 ) )
        {
            CComPtr< IIMCommandArgument > pArgument;

            // Checking availability of first argument
            if ( ( pIIMCommandArgumentEnum_->ArgGet( 0, &pArgument ) == S_OK ) &&
                 ( pArgument != nullptr ) )
            {
                long retVal = 0;

                if ( m_isGet )
                {
                    argValue = theCompanyNameScannerSettings().IMISharpEdgeMinAngleGet();
                    // Sets argument value if of valid type
                    if ( ( pArgument->ArgValueSetFromDouble( 1, argValue, &retVal ) == S_OK ) &&
                         ( retVal == 1 ) )
                    {
                        success = true;

                        retCode = E_CMD_SUCCEEDED;
                    }
                }
                else
                {
                    // Checking and retrieving argument value if of valid type
                    if ( ( pArgument->ArgValueGetAsDouble( 1, &argValue, &retVal ) == S_OK ) &&
                         ( retVal == 1 ) )
                    {
                        if ( argValue <= 0 || argValue >= 180 )
                        {
                            IMMessageBox( E_MESSAGE_TYPE_INFORMATION, L"The sharp edge min angle is out of range" );

                            retCode = E_CMD_ARG_OUT_OF_RANGE;
                        }
                        else
                        {
                            theCompanyNameScannerSettings().IMISharpEdgeMinAngleSet( argValue );

                            retCode = E_CMD_SUCCEEDED;
                        }
                    }
                }
            }
        }
    }

    if ( pReturnCode_ != nullptr )
    {
        // Error code assignment
        *pReturnCode_ = retCode;

        return S_OK;
    }

    return S_FALSE;
}

// =================================================================================================
// Commands constructor.
// This constructor is only called one time when the command is registered to the application.
//
// Parameter: info_ : Parameters necessary to build the command.
// -------------------------------------------------------------------------------------------------
CCmdLog::CCmdLog(
    CComCommandInfo&             info_,
    CCompanyNameScannerReceiver& receiver_ )
: CComCommand( info_ )
, m_Receiver( receiver_ )
{
}

// =================================================================================================
// Commands destructor
// -------------------------------------------------------------------------------------------------
CCmdLog::~CCmdLog() = default;

// =================================================================================================
// Logs the content of the options dialog property grid.
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdLog::Execute2(
    /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    ECommandReturnCodes retCode = E_CMD_FAILED;

    if ( pIIMCommandArgumentEnum_ != nullptr )
    {
        long nbArg = 0;

        // Checking argument count validity
        if ( ( pIIMCommandArgumentEnum_->ArgsGetNb( &nbArg ) == S_OK ) &&
             ( nbArg > 0 ) )
        {
            CComPtr< IIMCommandArgument > pArgument;

            // Checking availability of first argument
            if ( ( pIIMCommandArgumentEnum_->ArgGet( 0, &pArgument ) == S_OK ) &&
                 ( pArgument != nullptr ) )
            {
                long         retVal   = 0;
                BSTR         argValue = nullptr;
                bool         success  = false;
                std::wstring logFilePath;

                // Checking and retrieving argument value if of valid type
                if ( ( pArgument->ArgValueGetAsString( 1, &argValue, &retVal ) == S_OK ) &&
                     ( retVal == 1 ) )
                {
                    logFilePath = argValue;

                    ::SysFreeString( argValue );

                    success = true;
                }

                if ( success &&
                     m_Receiver.DlgOptionsLog( logFilePath ) )
                {
                    retCode = E_CMD_SUCCEEDED;
                }
            }
        }
    }

    if ( pReturnCode_ != nullptr )
    {
        // Error code assignment
        *pReturnCode_ = retCode;

        return S_OK;
    }

    return S_FALSE;
}
