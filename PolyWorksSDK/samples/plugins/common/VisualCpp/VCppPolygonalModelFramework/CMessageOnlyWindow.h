#pragma once

// =================================================================================================
// Hidden window to call commands asynchronously.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================
#include <string>
#include <Windows.h>

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

class CMessageOnlyWindow
{
public:
    // Public member functions
    ////////////////////////////
    CMessageOnlyWindow( WNDPROC wndProc_, const std::wstring& className_ );

    virtual ~CMessageOnlyWindow();
    bool PostMessage( UINT uMsg_, WPARAM wParam_, LPARAM lParam_ );

    CMessageOnlyWindow( const CMessageOnlyWindow& )            = delete;
    CMessageOnlyWindow& operator=( const CMessageOnlyWindow& ) = delete;
private:
    // Private types
    /////////////////////////////
    using TString = std::basic_string< TCHAR >;

    // Private member functions
    /////////////////////////////
    void ClassRegister( WNDPROC wndProc_ );
    void Cleanup();
    void Create();
    void WindowCreate();

    // Private member variables
    /////////////////////////////
    TString m_className;
    bool    m_isInitialized = false;
    WNDPROC m_wndProc;
    HWND    m_hWnd = nullptr;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
