// =================================================================================================
//   Plug-in's commands.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CCompanyNameCommands.h"

#include <PolyWorksSDK/Base/CWString.h>
#include <atlcomcli.h>

#include "PolyWorksObjectsReadWrite.h"

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
// Returns an argument as a string value.
// -------------------------------------------------------------------------------------------------
static bool CmdArgValueGetAsWString(
    IIMCommandArgumentEnum* pIIMCommandArgumentEnum_,
    int                     argIdx_,
    long                    arrayValIndex_,
    IM::CWString&           value_ )
{
    bool success = false;

    if ( pIIMCommandArgumentEnum_ != nullptr && argIdx_ >= 0 )
    {
        long nbArg = 0;
        if ( pIIMCommandArgumentEnum_->ArgsGetNb( &nbArg ) == S_OK && argIdx_ < nbArg )
        {
            CComPtr< IIMCommandArgument > pArgument;
            if ( pIIMCommandArgumentEnum_->ArgGet( argIdx_, &pArgument ) == S_OK && pArgument != nullptr )
            {
                BSTR argValue = nullptr;
                long retVal   = 0;
                if ( pArgument->ArgValueGetAsString( arrayValIndex_, &argValue, &retVal ) == S_OK && retVal == 1 )
                {
                    value_  = argValue;
                    success = true;

                    ::SysFreeString( argValue );
                }
            }
        }
    }

    return success;
}


// =================================================================================================
// Commands constructor. This constructor is only called one time when the command is registered to
// the application.
//
// Parameter: info_ : Parameters necessary to build the commmand.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNamePolyWorksObjectRead::CCmdCompanyNamePolyWorksObjectRead( CComCommandInfo& info_ )
: CComCommand( info_ )
{
}


// =================================================================================================
// Destructor.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNamePolyWorksObjectRead::~CCmdCompanyNamePolyWorksObjectRead()
{
}


// =================================================================================================
// Validates input arguments.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyNamePolyWorksObjectRead::ArgsTest(
    /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    *pReturnCode_ = E_CMD_FAILED;

    IM::CWString arg;
    if ( CmdArgValueGetAsWString( pIIMCommandArgumentEnum_, 0, 1, arg ) )
    {
        *pReturnCode_ = E_CMD_SUCCEEDED;
    }

    return S_OK;
}


// =================================================================================================
// Gives information about the selected objects.
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyNamePolyWorksObjectRead::Execute2(
    /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    *pReturnCode_ = E_CMD_FAILED;

    IM::CWString arg;
    if ( CmdArgValueGetAsWString( pIIMCommandArgumentEnum_, 0, 1, arg ) )
    {
        if ( wcslen( static_cast< const wchar_t* >( arg ) ) > 0 )
        {
            _wunlink( static_cast< const wchar_t* >( arg ) );
        }

        IPointCloudRead( static_cast< const wchar_t* >( arg ) );
        ILineScanRead( static_cast< const wchar_t* >( arg ) );
        IPolygonalModelRead( true,  static_cast< const wchar_t* >( arg ) );
        IPolygonalModelRead( false, static_cast< const wchar_t* >( arg ) );

        *pReturnCode_ = E_CMD_SUCCEEDED;
    }

    return ( ( *pReturnCode_ ) == E_CMD_SUCCEEDED ) ? S_OK : S_FALSE;
}


// =================================================================================================
// Commands constructor. This constructor is only called one time when the command is registered to
// the application.
//
// Parameter: info_ : Parameters necessary to build the commmand.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNamePolyWorksObjectILineScanAddLine::CCmdCompanyNamePolyWorksObjectILineScanAddLine( CComCommandInfo& info_ )
: CComCommand( info_ )
{
}


// =================================================================================================
// Destructor.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNamePolyWorksObjectILineScanAddLine::~CCmdCompanyNamePolyWorksObjectILineScanAddLine()
{
}


// =================================================================================================
// Add new passes to selected ILineScan objects.
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyNamePolyWorksObjectILineScanAddLine::Execute2(
    /* [in] */ IIMCommandArgumentEnum*,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    ILineScanAddLines();

    *pReturnCode_ = E_CMD_SUCCEEDED;

    return S_OK;
}


// =================================================================================================
// Commands constructor. This constructor is only called one time when the command is registered to
// the application.
//
// Parameter: info_ : Parameters necessary to build the commmand.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNamePolyWorksObjectIPointCloudAddNoise::CCmdCompanyNamePolyWorksObjectIPointCloudAddNoise( CComCommandInfo& info_ )
: CComCommand( info_ )
{
}


// =================================================================================================
// Destructor.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNamePolyWorksObjectIPointCloudAddNoise::~CCmdCompanyNamePolyWorksObjectIPointCloudAddNoise()
{
}


// =================================================================================================
// Add noise to each points in the selected IPointCloud objects.
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyNamePolyWorksObjectIPointCloudAddNoise::Execute2(
    /* [in] */ IIMCommandArgumentEnum*,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    IPointCloudWrite();

    *pReturnCode_ = E_CMD_SUCCEEDED;

    return S_OK;
}


// =================================================================================================
// Commands constructor. This constructor is only called one time when the command is registered to
// the application.
//
// Parameter: info_ : Parameters necessary to build the commmand.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNamePolyWorksObjectIPointCloudSubsample::CCmdCompanyNamePolyWorksObjectIPointCloudSubsample( CComCommandInfo& info_ )
: CComCommand( info_ )
{
}


// =================================================================================================
// Destructor.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNamePolyWorksObjectIPointCloudSubsample::~CCmdCompanyNamePolyWorksObjectIPointCloudSubsample()
{
}


// =================================================================================================
// Apply a 1:10 subsampling to the selected IPointCloud objects.
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyNamePolyWorksObjectIPointCloudSubsample::Execute2(
    /* [in] */ IIMCommandArgumentEnum*,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    IPointCloudSubsample();

    *pReturnCode_ = E_CMD_SUCCEEDED;

    return S_OK;
}
