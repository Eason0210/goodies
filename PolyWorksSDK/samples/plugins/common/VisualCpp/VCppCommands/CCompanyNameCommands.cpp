// =================================================================================================
// Plug-in's commands.
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CCompanyNameCommands.h"

#include <PolyWorksSDK/Base/CWString.h>
#include <atlcomcli.h>

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

double       g_doubleSettingValue  = 110.25;
int          g_integerSettingValue = 237;
IM::CWString g_stringSettingValue  = L"String Value";


// =================================================================================================
// =================================== FUNCTIONS PROTOTYPES ========================================

// =================================================================================================
// =================================== FUNCTIONS DEFINITIONS =======================================

// =================================================================================================
// Commands constructor.
// This constructor is only called one time when the command is registered to the application.
//
// Parameter: info_ : Parameters necessary to build the command.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNameAction::CCmdCompanyNameAction( CComCommandInfo& info_ )
: CComCommand( info_ )
{
}

// =================================================================================================
// Commands action.
//
// TODO: Comment the action here
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyNameAction::Execute2(
    /* [in] */ IIMCommandArgumentEnum*,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    // TODO: Add command execution code here.

    *pReturnCode_ = E_CMD_SUCCEEDED;

    return S_OK;
}

// =================================================================================================
// Commands constructor.
// This constructor is only called one time when the command is registered to the application.
//
// Parameter: info_ : Parameters necessary to build the command.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNameDoubleSet::CCmdCompanyNameDoubleSet( CComCommandInfo& info_ )
: CComCommand( info_ )
{
}

// =================================================================================================
// Sets a double value setting within the plug-in.
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyNameDoubleSet::Execute2(
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

                // Checking and retrieving argument value if of valid type
                if ( ( pArgument->ArgValueGetAsDouble( 1, &argValue, &retVal ) == S_OK ) &&
                     ( retVal == 1 ) )
                {
                    success = true;
                }
            }
        }
    }

    // Argument value validation
    if ( success )
    {
        // TODO: Replace validation code by your own depending on wanted argument value valid range
        if ( argValue < 0 )
        {
            retCode = E_CMD_ARG_OUT_OF_RANGE;
        }
        else
        {
            // TODO: Register setting value into the plug-in for future use or execute action using argument value
            // TODO: Replace g_doubleSettingValue use by your own code
            g_doubleSettingValue = argValue;

            retCode = E_CMD_SUCCEEDED;
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
CCmdCompanyNameDoubleGet::CCmdCompanyNameDoubleGet( CComCommandInfo& info_ )
: CComCommand( info_ )
{
}

// =================================================================================================
// Sets a double value setting within the plug-in.
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyNameDoubleGet::Execute2(
    /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    ECommandReturnCodes retCode = E_CMD_FAILED;

    // Setting argument value
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
                // Setting argument value if of valid type
                long retVal = 0;

                // TODO: Get setting value from the plug-in
                // TODO: Replace g_doubleSettingValue use by your own code
                if ( ( pArgument->ArgValueSetFromDouble( 1, g_doubleSettingValue, &retVal ) == S_OK ) &&
                     ( retVal == 1 ) )
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

// =================================================================================================
// Commands constructor.
// This constructor is only called one time when the command is registered to the application.
//
// Parameter: info_ : Parameters necessary to build the command.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNameIntegerSet::CCmdCompanyNameIntegerSet( CComCommandInfo& info_ )
: CComCommand( info_ )
{
}

// =================================================================================================
// Sets an integer value setting within the plug-in.
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyNameIntegerSet::Execute2(
    /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    ECommandReturnCodes retCode = E_CMD_FAILED;

    // Getting argument value
    bool success  = false;
    int  argValue = 0;

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

                // Checking and retrieving argument value if of valid type
                if ( ( pArgument->ArgValueGetAsInt( 1, &argValue, &retVal ) == S_OK ) &&
                     ( retVal == 1 ) )
                {
                    success = true;
                }
            }
        }
    }

    // Argument value validation
    if ( success )
    {
        // TODO: Replace validation code by your own depending on wanted argument value valid range
        if ( argValue < 0 )
        {
            retCode = E_CMD_ARG_OUT_OF_RANGE;
        }
        else
        {
            // TODO: Register setting value into the plug-in for future use or execute action using argument value
            // TODO: Replace g_integerSettingValue use by your own code
            g_integerSettingValue = argValue;

            retCode = E_CMD_SUCCEEDED;
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
CCmdCompanyNameIntegerGet::CCmdCompanyNameIntegerGet( CComCommandInfo& info_ )
: CComCommand( info_ )
{
}

// =================================================================================================
// Sets an integer value setting within the plug-in.
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyNameIntegerGet::Execute2(
    /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    ECommandReturnCodes retCode = E_CMD_FAILED;

    // Setting argument value
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
                // Setting argument value if of valid type
                long retVal = 0;

                // TODO: Get setting value from the plug-in
                // TODO: Replace g_integerSettingValue use by your own code
                if ( ( pArgument->ArgValueSetFromInt( 1, g_integerSettingValue, &retVal ) == S_OK ) &&
                     ( retVal == 1 ) )
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

// =================================================================================================
// Commands constructor.
// This constructor is only called one time when the command is registered to the application.
//
// Parameter: info_ : Parameters necessary to build the command.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNameStringSet::CCmdCompanyNameStringSet( CComCommandInfo& info_ )
: CComCommand( info_ )
{
}

// =================================================================================================
// Sets a string value setting within the plug-in.
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyNameStringSet::Execute2(
    /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    ECommandReturnCodes retCode = E_CMD_FAILED;

    // Getting argument value
    bool         success = false;
    IM::CWString stringValue;

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
                long retVal   = 0;
                BSTR argValue = NULL;

                // Checking and retrieving argument value if of valid type
                if ( ( pArgument->ArgValueGetAsString( 1, &argValue, &retVal ) == S_OK ) &&
                     ( retVal == 1 ) )
                {
                    stringValue = argValue;

                    ::SysFreeString( argValue );

                    success = true;
                }
            }
        }
    }

    // Argument value validation
    if ( success )
    {
        // TODO: Replace validation code by your own depending on wanted argument value valid range
        if ( wcscmp( stringValue, L"Invalid" ) == 0 )
        {
            retCode = E_CMD_ARG_INVALID_STRING;
        }
        else
        {
            // TODO: Register setting value into the plug-in for future use or execute action using argument value
            // TODO: Replace g_stringSettingValue use by your own code
            g_stringSettingValue = stringValue;

            retCode = E_CMD_SUCCEEDED;
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
CCmdCompanyNameStringGet::CCmdCompanyNameStringGet( CComCommandInfo& info_ )
: CComCommand( info_ )
{
}

// =================================================================================================
// Sets a string value setting within the plug-in.
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyNameStringGet::Execute2(
    /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    ECommandReturnCodes retCode = E_CMD_FAILED;

    // Setting argument value
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
                // Setting argument value if of valid type
                long retVal = 0;

                // TODO: Get setting value from the plug-in
                // TODO: Replace g_stringSettingValue use by your own code
                if ( ( pArgument->ArgValueSetFromString( 1, g_stringSettingValue, &retVal ) == S_OK ) &&
                     ( retVal == 1 ) )
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
