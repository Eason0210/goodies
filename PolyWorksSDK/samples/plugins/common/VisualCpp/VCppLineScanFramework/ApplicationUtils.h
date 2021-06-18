#pragma once

// =================================================================================================
//   Utility functions.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <PolyWorksSDK/COM/IMTypes.h>
#include <sstream>
#include <string>
#include <vector>

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

std::wstring ConvertChoiceToString( int choice_, const std::wstring possibleChoices_[], int firstChoice_, int count_ );

int ConvertStringToChoice( const std::wstring& choice_, const std::wstring possibleChoices_[], int firstChoice_, int count_ );

const bool ExecuteCommandOnApp(
    const wchar_t* command_,
    bool           withEcho_               = false,
    bool           interactive             = false,
    bool           waitForInteractiveMode_ = true );

long IMMessageBox( EMessageTypes type_, const wchar_t* message_, HWND parentWindowHandle_ = nullptr );

std::wstring ObtainUniqueNameFromApp( const std::wstring& baseName_ );

std::wstring ObtainObjectUniqueIDFromApp( const std::wstring& objectName_ );

bool ValueStrSetToApp( const std::wstring& cmdName_, const std::wstring& value_, bool withEcho_, bool interactive = false );

bool ValueColorGetFromApp( const std::wstring& cmdName_, COLORREF& value_, bool withEcho_ = false, const std::wstring& cmdArg_ = L"" );

bool ValueDateTimeGetFromApp( const std::wstring& cmdName_, std::wstring& value_, bool withEcho_ = false, const std::wstring& cmdArg_ = L"" );

bool ValueStrGetFromApp( const std::wstring& cmdName_, std::wstring& value_, bool withEcho_                = false, const std::wstring& cmdArg_ = L"" );
bool ValueStrGetFromApp( const std::wstring& cmdName_, std::vector< std::wstring >& value_, bool withEcho_ = false, const std::wstring& cmdArg_ = L"" );

bool ValueOnOffSynchWithApp(
    const std::wstring& getCmdName_,
    const std::wstring& setCmdName_,
    bool                value_,
    bool                withEcho_ );

bool ValueIntSynchWithApp(
    const std::wstring& getCmdName_,
    const std::wstring& setCmdName_,
    int                 value_,
    bool                withEcho_ );

bool ValueDoubleSynchWithApp(
    const std::wstring& getCmdName_,
    const std::wstring& setCmdName_,
    double              value_,
    bool                withEcho_ );

bool ValueStrSynchWithApp(
    const std::wstring& getCmdName_,
    const std::wstring& setCmdName_,
    const std::wstring& value_,
    bool                withEcho_ );

bool ValueDoubleSynchFromApp( const std::wstring& getCmdName_, double value_, double& newValue_, double newScalingFactor_ );

bool ValueIntSynchFromApp( const std::wstring& getCmdName_, int value_, int& newValue_ );

bool ValueOnOffSynchFromApp( const std::wstring& getCmdName_, bool value_, bool& newValue_ );

bool ValueStrSynchFromApp( const std::wstring& getCmdName_, const std::wstring& value_, std::wstring& newValue_ );

// =================================================================================================
//   Converts a value to a string.
//
// Parameter : value_ : value to convert
//
// Return : String conversion
// -------------------------------------------------------------------------------------------------
template< typename T >
std::wstring ValueToString( const T value_ )
{
    std::wostringstream wStream;

    wStream << value_;
    return wStream.str();
}

template<>
std::wstring ValueToString< unsigned char >( unsigned char value_ );
