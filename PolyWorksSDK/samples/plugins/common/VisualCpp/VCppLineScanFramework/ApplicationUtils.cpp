// =================================================================================================
//   Utility functions.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================
#include "stdafx.h"

#include "ApplicationUtils.h"

#include <PolyWorksSDK/COM/IIMCommandCenter.h>
#include <PolyWorksSDK/COM/IIMCommandCenter_i.c>
#include <PolyWorksSDK/COM/IIMMessageCenter.h>
#include <PolyWorksSDK/COM/IIMMessageCenter_i.c>
#include <assert.h>
#include <comutil.h>

#include "CCompanyNameScannerSettings.h"
#include "CompanyNameConst.h"

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
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

// =================================================================================================
//   Retrieves all the string parameters generated when running a given script
//
// Parameter : script_   : script to execute
// Parameter : varNames_ : name of the variables to retrieve
// Parameter : values_   : values retrieved
// Parameter : withEcho_ : indicates whether the command should be visible in the application's Command History
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
static bool RunScriptAndReadValues( const std::wstring& script_, const std::vector< std::wstring >& varNames_, std::vector< std::wstring >& values_, bool withEcho_ )
{
    CComPtr< IIMCommandCenter > pCommandCenter;
    HRESULT hr = GITGetInterfaceFromGlobal( g_cookieCommandCenter, IID_IIMCommandCenter, ( void** )&pCommandCenter );
    if ( ( hr != S_OK ) || ( pCommandCenter == nullptr ) )
    {
        return false;
    }

    long retVal = 0;
    if ( withEcho_ )
    {
        pCommandCenter->CommandExecute( L"EchoOn",       &retVal );
        pCommandCenter->CommandExecute( L"RecordableOn", &retVal );
    }
    else
    {
        pCommandCenter->CommandExecute( L"EchoOff",       &retVal );
        pCommandCenter->CommandExecute( L"RecordableOff", &retVal );
    }

    // Run the script
    long isSuccess = 0;
    if ( !SUCCEEDED( pCommandCenter->ScriptExecuteFromBuffer( script_.c_str(), nullptr, &retVal ) ) ||
         !SUCCEEDED( pCommandCenter->ReturnValueIsSuccess( retVal, &isSuccess ) ) ||
         ( isSuccess != 1 ) )
    {
        return false;
    }

    // Retrieve the value
    for ( const auto& varName : varNames_ )
    {
        CComBSTR value;
        if ( !SUCCEEDED(  pCommandCenter->ScriptVariableGetValueAsString( varName.c_str(), 1, &value, &retVal ) ) ||
             !SUCCEEDED(  pCommandCenter->ReturnValueIsSuccess( retVal, &isSuccess ) ) ||
             ( isSuccess != 1 ) ||
             ( value == nullptr ) )
        {
            return false;
        }
        values_.push_back( std::wstring( value ) );
    }

    return true;
}

// =================================================================================================
//   Retrieves the string parameter generated when running a given script
//
// Parameter : script_   : script to execute
// Parameter : varName_  : name of the variable to retrieve
// Parameter : value_    : value retrieved
// Parameter : withEcho_ : indicates whether the command should be visible in the application's Command History
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
static bool RunScriptAndReadValue( const std::wstring& script_, const std::wstring& varName_, std::wstring& value_, bool withEcho_ )
{
    std::vector< std::wstring > values;
    if ( !RunScriptAndReadValues( script_, { varName_ }, values, withEcho_ ) )
    {
        return false;
    }
    value_ = values[ 0 ];
    return true;
}

// =================================================================================================
//   Convert a choice to a string
//
// Parameter : choice_          : choice to convert
// Parameter : possibleChoices_ : possible choice strings
// Parameter : firstChoice_     : first choice
// Parameter : count_           : number of choices
//
// Return : Choice string
// -------------------------------------------------------------------------------------------------
std::wstring ConvertChoiceToString( int choice_, const std::wstring possibleChoices_[], int firstChoice_, int count_ )
{
    int index = choice_ - firstChoice_;
    if ( ( index >= 0 ) && ( index < count_ ) )
    {
        return possibleChoices_[ index ];
    }

    assert( 0 );
    return L"";
}

// =================================================================================================
//   Convert a string to a choice
//
// Parameter : choice_          : string to convert
// Parameter : possibleChoices_ : possible choice strings
// Parameter : firstChoice_     : first choice
// Parameter : count_           : number of choices
//
// Return : Choice
// -------------------------------------------------------------------------------------------------
int ConvertStringToChoice( const std::wstring& choice_, const std::wstring possibleChoices_[], int firstChoice_, int count_ )
{
    int index;
    for ( index = 0; index < count_; index++ )
    {
        if ( choice_ == possibleChoices_[ index ] )
        {
            return index + firstChoice_;
        }
    }

    assert( 0 );
    return firstChoice_;
}

// =================================================================================================
//   Executes a command on the host application.
//
// Parameter : command_                : the command to execute
// Parameter : withEcho_               : indicates whether the command should be visible in the
//                                      application's Command History
// Parameter : interactive_            : true for interactive behavior, false for script behavior
// Parameter : waitForInteractiveMode_ : enable waiting for Interactive Mode
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
const bool ExecuteCommandOnApp(
    const wchar_t* command_,
    bool           withEcho_,
    bool           interactive_,
    bool           waitForInteractiveMode_ )
{
    bool success = false;

    CComPtr< IIMCommandCenter > pCommandCenter;
    if ( g_cookieCommandCenter != 0 )
    {
        GITGetInterfaceFromGlobal( g_cookieCommandCenter, IID_IIMCommandCenter, ( void** ) &pCommandCenter );
    }

    if ( pCommandCenter == nullptr )
    {
        return success;
    }

    long retVal    = 0;
    long isSuccess = 0;

    if ( withEcho_ )
    {
        pCommandCenter->CommandExecute( L"EchoOn",       &retVal );
        pCommandCenter->CommandExecute( L"RecordableOn", &retVal );
    }
    else
    {
        pCommandCenter->CommandExecute( L"EchoOff",       &retVal );
        pCommandCenter->CommandExecute( L"RecordableOff", &retVal );
    }

    // Interactivity activation
    pCommandCenter->CommandExecute( interactive_ ? L"InteractivityOn" : L"InteractivityOff", &retVal );

    // Don't wait for the Interactive Mode
    if ( !waitForInteractiveMode_ )
    {
        pCommandCenter->CommandExecute( L"WaitOnInteractiveModeOff", &retVal );
    }

    // Execute the command
    if ( ( pCommandCenter->CommandExecute( command_, &retVal ) == S_OK ) &&
         ( pCommandCenter->ReturnValueIsSuccess( retVal, &isSuccess ) == S_OK ) &&
         ( isSuccess == 1 ) )
    {
        success = true;
    }

    // Restore the Interactive Mode waiting
    if ( !waitForInteractiveMode_ )
    {
        pCommandCenter->CommandExecute( L"WaitOnInteractiveModeOn", &retVal );
    }

    return success;
}


// =================================================================================================
//   Pops up a message dialog box in the host application.
//
// Parameter : type_               : message type
// Parameter : message_            : message string
// Parameter : parentWindowHandle_ : handle of the window to use as parent for the message dialog box
//
// Return : ID of the button pressed
// -------------------------------------------------------------------------------------------------
long IMMessageBox( EMessageTypes type_, const wchar_t* message_, HWND parentWindowHandle_ /*= nullptr*/ )
{
    long buttonID = 0;
    CComPtr< IIMMessageCenter > pMessageCenter;
    HRESULT hr = GITGetInterfaceFromGlobal( g_cookieHost, IID_IIMMessageCenter, ( void** )&pMessageCenter );

    if ( ( hr == S_OK ) && ( pMessageCenter != nullptr ) )
    {
        pMessageCenter->MessageBox( type_, _bstr_t( message_ ), nullptr, nullptr, HandleToLong( parentWindowHandle_ ), ( VARIANT_BOOL )-1, nullptr, 0, &buttonID );
    }

    return buttonID;
}

// =================================================================================================
//   Generate a unique object name from a base name if necessary.
//
// Parameter : baseName_ : base name
//
// Return : Unique name generate from base name
// -------------------------------------------------------------------------------------------------
std::wstring ObtainUniqueNameFromApp( const std::wstring& baseName_ )
{
    if ( baseName_.empty() )
    {
        return L"";
    }

    std::wstring uniqueNameVar = L"uniqueName";
    std::wstring script        = SCRIPT_VERSION_DECLARATION;
    script += L"\n";
    script += L"DECLARE ";
    script += uniqueNameVar;
    script += L"\n";
    script += L"TREEVIEW NAME GENERATE_UNIQUE ( \"";
    script += baseName_;
    script += L"\", ";
    script += uniqueNameVar;
    script += L")\n";

    std::wstring value;
    RunScriptAndReadValue( script, uniqueNameVar, value, false );
    return value;
}

// =================================================================================================
//   Obtains the unique object if from the object name
//
// Parameter : objectName_ : object name
//
// Return : Unique id
// -------------------------------------------------------------------------------------------------
std::wstring ObtainObjectUniqueIDFromApp( const std::wstring& objectName_ )
{
    if ( objectName_.empty() )
    {
        return L"";
    }

    const std::wstring uniqueIDVar = L"uniqueID";
    std::wstring       script      = SCRIPT_VERSION_DECLARATION;
    script += L"\n";
    script += L"DECLARE ";
    script += uniqueIDVar;
    script += L"\n";
    script += L"TREEVIEW OBJECT PROPERTIES UNIQUE_ID GET( \"";
    script += uniqueIDVar;
    script += L"\", ";
    script += objectName_;
    script += L")\n";
    long retVal    = 0;
    long isSuccess = 0;

    std::wstring value;
    RunScriptAndReadValue( script, uniqueIDVar, value, false );
    return value;
}

// =================================================================================================
//   Retrieves a color value from the application, using a command.
//
// Parameter : cmdName_  : command name
// Parameter : value_    : (out) value retrieved
// Parameter : withEcho_ : indicates whether the command should be visible in the application's Command History
// Parameter : cmdArg_   : command arguments
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool ValueColorGetFromApp( const std::wstring& cmdName_, COLORREF& value_, bool withEcho_, const std::wstring& cmdArg_ /*= L""*/ )
{
    const std::vector< std::wstring > valueVars = { L"valueR", L"valueG", L"valueB" };
    std::wstring script                         = SCRIPT_VERSION_DECLARATION;
    script += L"\n";
    script += L"DECLARE ";
    script += valueVars[ 0 ];
    script += L"\n";
    script += L"DECLARE ";
    script += valueVars[ 1 ];
    script += L"\n";
    script += L"DECLARE ";
    script += valueVars[ 2 ];
    script += L"\n";
    script += cmdName_;
    script += L" ( ";
    script += cmdArg_;
    script += valueVars[ 0 ];
    script += L", ";
    script += valueVars[ 1 ];
    script += L", ";
    script += valueVars[ 2 ];
    script += L" )\n";

    std::vector< std::wstring > values;
    if ( !RunScriptAndReadValues( script, valueVars, values, withEcho_ ) )
    {
        return false;
    }

    int color[ 3 ] = { 0 };
    for ( size_t i = 0; i < values.size(); ++i )
    {
        color[ i ] = _wtoi( values[ i ].c_str() );
    }
    value_ = RGB( color[ 0 ], color[ 1 ], color[ 2 ] );
    return true;
}


// =================================================================================================
//   Retrieves a date time value from the application, using a command.
//
// Parameter : cmdName_  : command name
// Parameter : value_    : (out) value retrieved
// Parameter : withEcho_ : indicates whether the command should be visible in the application's Command History
// Parameter : cmdArg_   : command arguments
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool ValueDateTimeGetFromApp( const std::wstring& cmdName_, std::wstring& value_, bool withEcho_, const std::wstring& cmdArg_ /*= L""*/ )
{
    bool success = false;

    CComPtr< IIMCommandCenter > pCommandCenter;
    if ( g_cookieCommandCenter != 0 )
    {
        GITGetInterfaceFromGlobal( g_cookieCommandCenter, IID_IIMCommandCenter, ( void** )&pCommandCenter );
    }

    if ( pCommandCenter == nullptr )
    {
        return success;
    }

    long retVal = 0;

    if ( withEcho_ )
    {
        pCommandCenter->CommandExecute( L"EchoOn",       &retVal );
        pCommandCenter->CommandExecute( L"RecordableOn", &retVal );
    }
    else
    {
        pCommandCenter->CommandExecute( L"EchoOff",       &retVal );
        pCommandCenter->CommandExecute( L"RecordableOff", &retVal );
    }

    const std::wstring valueVar( L"DateTime" );
    std::wstring       script = SCRIPT_VERSION_DECLARATION;
    script += L"\n";
    script += L"DECLARE DateTime\n";
    script += cmdName_;
    script += L" ( ";
    script += cmdArg_;
    for ( int index = 1; index <= 6; ++index )
    {
        if ( index > 1 )
        {
            script += L", ";
        }
        script += valueVar + L"[";
        script += ValueToString( index );
        script += L"]";
    }
    script += L" )\n";

    HRESULT hr = pCommandCenter->ScriptExecuteFromBuffer( script.c_str(), nullptr, &retVal );
    if ( SUCCEEDED( hr ) )
    {
        int dateTime[ 6 ] = { 0 };
        for ( int index = 0; index < _countof( dateTime ); ++index )
        {
            long retVal    = 0;
            long isSuccess = 0;
            int  value     = 0;
            if ( ( pCommandCenter->ScriptVariableGetValueAsInt( valueVar.c_str(), index + 1, &value, &retVal ) == S_OK ) &&
                 ( pCommandCenter->ReturnValueIsSuccess( retVal, &isSuccess ) == S_OK ) &&
                 ( isSuccess == 1 ) )
            {
                dateTime[ index ] = value;
            }
        }

        CStringW dateTimeStr;
        dateTimeStr.Format(
            L"%04d-%02d-%02d %02d:%02d:%02d",
            dateTime[ 0 ],
            dateTime[ 1 ],
            dateTime[ 2 ],
            dateTime[ 3 ],
            dateTime[ 4 ],
            dateTime[ 5 ] );
        value_ = dateTimeStr;

        success = true;
    }

    return success;
}


// =================================================================================================
//   Retrieves a string value from the application, using a command.
//
// Parameter : cmdName_  : command name
// Parameter : value_    : (out) value retrieved
// Parameter : withEcho_ : indicates whether the command should be visible in the application's Command History
// Parameter : cmdArg_   : command arguments
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool ValueStrGetFromApp( const std::wstring& cmdName_, std::wstring& value_, bool withEcho_, const std::wstring& cmdArg_ /*= L""*/ )
{
    const std::wstring valueVar = L"value";
    std::wstring       script   = SCRIPT_VERSION_DECLARATION;
    script += L"\n";
    script += L"DECLARE ";
    script += valueVar;
    script += L"\n";
    script += cmdName_;
    script += L" ( ";
    script += cmdArg_;
    if ( !cmdArg_.empty() )
    {
        script += L", ";
    }
    script += valueVar;
    script += L" )\n";

    return RunScriptAndReadValue( script, valueVar, value_, withEcho_ );
}

// =================================================================================================
//   Retrieves an array of string values from the application, using a command.
//
// Parameter : cmdName_  : command name
// Parameter : values_    : (out) value retrieved
// Parameter : withEcho_ : indicates whether the command should be visible in the application's Command History
// Parameter : cmdArg_   : command arguments
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool ValueStrGetFromApp( const std::wstring& cmdName_, std::vector< std::wstring >& values_, bool withEcho_, const std::wstring& cmdArg_ )
{
    CComPtr< IIMCommandCenter > pCommandCenter;
    if ( g_cookieCommandCenter != 0 )
    {
        GITGetInterfaceFromGlobal( g_cookieCommandCenter, IID_IIMCommandCenter, ( void** ) &pCommandCenter );
    }

    if ( pCommandCenter == nullptr )
    {
        return false;
    }

    long retVal = 0;

    if ( withEcho_ )
    {
        pCommandCenter->CommandExecute( L"EchoOn",       &retVal );
        pCommandCenter->CommandExecute( L"RecordableOn", &retVal );
    }
    else
    {
        pCommandCenter->CommandExecute( L"EchoOff",       &retVal );
        pCommandCenter->CommandExecute( L"RecordableOff", &retVal );
    }

    std::wstring valueVar = L"value";
    std::wstring script   = SCRIPT_VERSION_DECLARATION;
    script += L"\n";
    script += L"DECLARE ";
    script += valueVar;
    script += L"\n";
    script += cmdName_;
    script += L" ( ";
    script += cmdArg_;
    if ( !cmdArg_.empty() )
    {
        script += L", ";
    }
    script += valueVar;
    script += L" )\n";

    HRESULT hr = pCommandCenter->ScriptExecuteFromBuffer( script.c_str(), nullptr, &retVal );
    if ( SUCCEEDED( hr ) )
    {
        long nbValues = 0;
        if ( !SUCCEEDED( pCommandCenter->ScriptVariableGetNbValues( valueVar.c_str(), &nbValues ) ) )
        {
            return false;
        }

        std::wstring currentName;
        for ( long iValue = 0; iValue < nbValues; iValue++ )
        {
            long     success = 0;
            CComBSTR tmpName;
            if ( !( ( pCommandCenter->ScriptVariableGetValueAsString( valueVar.c_str(), ( iValue + 1 ), &tmpName, &retVal ) == S_OK ) &&
                    ( pCommandCenter->ReturnValueIsSuccess( retVal, &success ) == S_OK ) &&
                    ( success == 1 ) ) )
            {
                return false;
            }
            currentName = tmpName;
            if ( ( nbValues == 1 ) && ( currentName == L"0" ) )
            {
                break;
            }
            values_.push_back( currentName );
        }
    }

    return true;
}

// =================================================================================================
//   Changes a string value in the application, using a command.
//
// Parameter : cmdName_  : command name
// Parameter : value_    : new value
// Parameter : withEcho_ : indicates whether the command should be visible in the application's Command History
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool ValueStrSetToApp( const std::wstring& cmdName_, const std::wstring& value_, bool withEcho_, bool interactive_ )
{
    bool success = false;

    CComPtr< IIMCommandCenter > pCommandCenter;
    if ( g_cookieCommandCenter != 0 )
    {
        GITGetInterfaceFromGlobal( g_cookieCommandCenter, IID_IIMCommandCenter, ( void** ) &pCommandCenter );
    }

    if ( pCommandCenter == nullptr )
    {
        return success;
    }

    long retVal = 0;

    if ( withEcho_ )
    {
        pCommandCenter->CommandExecute( L"EchoOn",       &retVal );
        pCommandCenter->CommandExecute( L"RecordableOn", &retVal );
    }
    else
    {
        pCommandCenter->CommandExecute( L"EchoOff",       &retVal );
        pCommandCenter->CommandExecute( L"RecordableOff", &retVal );
    }

    pCommandCenter->CommandExecute( interactive_ ? L"InteractivityOn" : L"InteractivityOff", &retVal );

    std::wstring script = SCRIPT_VERSION_DECLARATION;
    script += L"\n";
    script += cmdName_;
    script += L" ( \"";
    script += value_;
    script += L"\" )\n";

    HRESULT hr = pCommandCenter->ScriptExecuteFromBuffer( script.c_str(), nullptr, &retVal );
    if ( SUCCEEDED( hr ) )
    {
        long isSuccess = 0;
        pCommandCenter->ReturnValueIsSuccess( retVal, &isSuccess );
        if ( isSuccess == 1 )
        {
            success = true;
        }
    }

    return success;
}


// =================================================================================================
//   Synchronizes, if necessary, a string value with the application.
//
// Parameter : getCmdName_ : Get command name
// Parameter : setCmdName_ : Set command name
// Parameter : value_      : new value
// Parameter : withEcho_   : indicates whether the Set command should be visible in the application's Command History
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool ValueOnOffSynchWithApp(
    const std::wstring& getCmdName_,
    const std::wstring& setCmdName_,
    bool                value_,
    bool                withEcho_ )
{
    const std::wstring value = g_OnOffChoiceStrings[ value_ ? E_OO_ON : E_OO_OFF ];
    std::wstring       valueFromApp;
    bool success = ValueStrGetFromApp( getCmdName_, valueFromApp );
    if ( success && ( valueFromApp != value ) )
    {
        success = ValueStrSetToApp( setCmdName_, value, withEcho_ );
    }
    return success;
}


// =================================================================================================
//   Synchronizes, if necessary, a string value with the application.
//
// Parameter : getCmdName_ : Get command name
// Parameter : setCmdName_ : Set command name
// Parameter : value_      : new value
// Parameter : withEcho_   : indicates whether the Set command should be visible in the application's Command History
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool ValueIntSynchWithApp(
    const std::wstring& getCmdName_,
    const std::wstring& setCmdName_,
    int                 value_,
    bool                withEcho_ )
{
    std::wstring valueFromApp;
    bool         success = ValueStrGetFromApp( getCmdName_, valueFromApp );
    if ( success && ( _wtoi( valueFromApp.c_str() ) != value_ ) )
    {
        std::wstringstream valueFmt;
        valueFmt << value_;
        const std::wstring value = valueFmt.str();
        success = ValueStrSetToApp( setCmdName_, value, withEcho_ );
    }
    return success;
}


// =================================================================================================
//   Synchronizes, if necessary, a string value with the application.
//
// Parameter : getCmdName_ : Get command name
// Parameter : setCmdName_ : Set command name
// Parameter : value_      : new value
// Parameter : withEcho_   : indicates whether the Set command should be visible in the application's Command History
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool ValueDoubleSynchWithApp(
    const std::wstring& getCmdName_,
    const std::wstring& setCmdName_,
    double              value_,
    bool                withEcho_ )
{
    std::wstring valueFromApp;
    bool         success = ValueStrGetFromApp( getCmdName_, valueFromApp );
    if ( success && ( _wtof( valueFromApp.c_str() ) != value_ ) )
    {
        std::wstringstream valueFmt;
        valueFmt << value_;
        const std::wstring value = valueFmt.str();
        success = ValueStrSetToApp( setCmdName_, value, withEcho_ );
    }
    return success;
}


// =================================================================================================
//   Synchronizes, if necessary, a string value with the application.
//
// Parameter : getCmdName_ : Get command name
// Parameter : setCmdName_ : Set command name
// Parameter : value_      : new value
// Parameter : withEcho_   : indicates whether the Set command should be visible in the application's Command History
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool ValueStrSynchWithApp(
    const std::wstring& getCmdName_,
    const std::wstring& setCmdName_,
    const std::wstring& value_,
    bool                withEcho_ )
{
    std::wstring valueFromApp;
    bool         success = ValueStrGetFromApp( getCmdName_, valueFromApp );
    if ( success && ( valueFromApp != value_ ) )
    {
        success = ValueStrSetToApp( setCmdName_, value_, withEcho_ );
    }
    return success;
}

// =================================================================================================
//   Synchronizes, if necessary, a double from the application.
//
// Parameter : getCmdName_       : Get command name
// Parameter : value_            : Current value
// Parameter : newValue_         : [OUT] New value
// Parameter : newScalingFactor_ : Unit conversion factor
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool ValueDoubleSynchFromApp( const std::wstring& getCmdName_, double value_, double& newValue_, double newScalingFactor_ )
{
    std::wstring strValue;
    bool         success = ValueStrGetFromApp( getCmdName_, strValue );
    if ( success )
    {
        double doubleValue = _wtof( strValue.c_str() ) / newScalingFactor_;
        if ( value_ != doubleValue )
        {
            newValue_ = doubleValue;
            return true;
        }
    }

    return false;
}

// =================================================================================================
//   Synchronizes, if necessary, a integer from the application.
//
// Parameter : getCmdName_       : Get command name
// Parameter : value_            : Current value
// Parameter : newValue_         : [OUT] New value
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool ValueIntSynchFromApp( const std::wstring& getCmdName_, int value_, int& newValue_ )
{
    std::wstring strValue;
    bool         success = ValueStrGetFromApp( getCmdName_, strValue );
    if ( success )
    {
        int intValue = _wtoi( strValue.c_str() );
        if ( value_ != intValue )
        {
            newValue_ = intValue;
            return true;
        }
    }

    return false;
}

// =================================================================================================
//   Synchronizes, if necessary, a boolean from the application.
//
// Parameter : getCmdName_       : Get command name
// Parameter : value_            : Current value
// Parameter : newValue_         : [OUT] New value
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool ValueOnOffSynchFromApp( const std::wstring& getCmdName_, bool value_, bool& newValue_ )
{
    std::wstring strValue;
    bool         success = ValueStrGetFromApp( getCmdName_, strValue );
    if ( success )
    {
        bool boolValue = ( strValue == g_OnOffChoiceStrings[ E_OO_ON ] );
        if ( value_ != boolValue )
        {
            newValue_ = boolValue;
            return true;
        }
    }

    return false;
}

// =================================================================================================
//   Synchronizes, if necessary, a string from the application.
//
// Parameter : getCmdName_       : Get command name
// Parameter : value_            : Current value
// Parameter : newValue_         : [OUT] New value
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool ValueStrSynchFromApp( const std::wstring& getCmdName_, const std::wstring& value_, std::wstring& newValue_ )
{
    std::wstring strValue;
    bool         success = ValueStrGetFromApp( getCmdName_, strValue );
    if ( success && ( value_ != strValue ) )
    {
        newValue_ = strValue;
        return true;
    }

    return false;
}

// =================================================================================================
//   Converts a value to a string (specialization of unsigned char).
//
// Parameter : value_ : value to convert
//
// Return : String conversion
// -------------------------------------------------------------------------------------------------
template<>
std::wstring ValueToString< unsigned char >( unsigned char value_ )
{
    return ValueToString( static_cast< unsigned int >( value_ ) );
}
