// =================================================================================================
// Implement hidden window to call commands asynchronously.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CMessageOnlyWindow.h"

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
//   Constructor
//
// Parameter: wndProc_ : Specifies the window process handler
// -------------------------------------------------------------------------------------------------
CMessageOnlyWindow::CMessageOnlyWindow( WNDPROC wndProc_, const std::wstring& className_ )
: m_wndProc( wndProc_ )
, m_className( className_ )
{
    Create();
}

// =================================================================================================
//   Destructor
// -------------------------------------------------------------------------------------------------
CMessageOnlyWindow::~CMessageOnlyWindow()
{
    Cleanup();
}

// =================================================================================================
// Register the window class
//
// Parameter: wndProc_ : Specifies the window process handler
// -------------------------------------------------------------------------------------------------
void CMessageOnlyWindow::ClassRegister( WNDPROC wndProc_ )
{
    HINSTANCE  hCurrentInstance = GetModuleHandle( nullptr );
    WNDCLASSEX wex              = { 0 };
    wex.cbSize        = sizeof( WNDCLASSEX );
    wex.lpfnWndProc   = wndProc_;
    wex.hInstance     = hCurrentInstance;
    wex.lpszClassName = m_className.c_str();
    if ( RegisterClassEx( &wex ) == 0 )
    {
        ASSERT( 0 );
    }
}

// =================================================================================================
//   Destroy the window and unregister the class
// -------------------------------------------------------------------------------------------------
void CMessageOnlyWindow::Cleanup()
{
    if ( !m_isInitialized )
    {
        return;
    }

    m_isInitialized = false;
    DestroyWindow( m_hWnd );
    UnregisterClass( m_className.c_str(), GetModuleHandle( nullptr ) );
}

// =================================================================================================
//   Register the window class and create the window
// -------------------------------------------------------------------------------------------------
void CMessageOnlyWindow::Create()
{
    if ( m_isInitialized != false )
    {
        ASSERT( 0 );
        return;
    }

    m_isInitialized = true;
    ClassRegister( m_wndProc );
    WindowCreate();
}

// =================================================================================================
// Parameter : uMsg_   : Message to post
// Parameter : wParam_ : First parameter (optional)
// Parameter : lParam_ : Second parameter (optional)
//
// return : true if succeeded, false otherwise
// -------------------------------------------------------------------------------------------------
bool CMessageOnlyWindow::PostMessage( UINT uMsg_, WPARAM wParam_, LPARAM lParam_ )
{
    if ( ( m_isInitialized == false ) ||
         ( m_hWnd == nullptr ) )
    {
        ASSERT( 0 );
        return false;
    }

    return ::PostMessage( m_hWnd, uMsg_, wParam_, lParam_ ) != FALSE;
}

// =================================================================================================
// Create the invisible window
// -------------------------------------------------------------------------------------------------
void CMessageOnlyWindow::WindowCreate()
{
    m_hWnd = CreateWindow( m_className.c_str(), nullptr, 0, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, HWND_MESSAGE, nullptr, nullptr, nullptr );
}
