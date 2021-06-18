// =================================================================================================
//   Implementation to show tooltip on each list item in a combo box
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "TooltipComboBox.h"

#include <assert.h>

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

///////////////////////////////////////////////////////////////////////////////
// CTooltipComboBox

BEGIN_MESSAGE_MAP( CTooltipComboBox, CComboBox )
    //{{AFX_MSG_MAP( CTooltipComboBox )
    ON_WM_CTLCOLOR()
    ON_WM_DESTROY()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

// =================================================================================================
//   Ctor
// -------------------------------------------------------------------------------------------------
CTooltipComboBox::CTooltipComboBox()
{
}

// =================================================================================================
//   Dtor
// -------------------------------------------------------------------------------------------------
CTooltipComboBox::~CTooltipComboBox()
{
    if ( ::IsWindow( GetSafeHwnd() ) )
    {
        DestroyWindow();
    }
}

// =================================================================================================
//   Indicates if tooltip is visible
//
// Return : true if tooltip is visible
// -------------------------------------------------------------------------------------------------
bool CTooltipComboBox::IsTootipVisible()
{
    return m_listbox.IsTootipVisible();
}

// =================================================================================================
//   Uses OnCtlColor to call SubclassWindow of the combo box list box
//
// Parameter : pDC_       : DC of the combo box
// Parameter : pWnd_      : Handle of the combo box
// Parameter : nCtlColor_ : Control color
//
// Return : Handle to the control global brush
// -------------------------------------------------------------------------------------------------
HBRUSH CTooltipComboBox::OnCtlColor( CDC* pDC_, CWnd* pWnd_, UINT nCtlColor_ )
{
    if ( nCtlColor_ == CTLCOLOR_LISTBOX )
    {
        if ( m_listbox.GetSafeHwnd() == nullptr )
        {
            m_listbox.SubclassWindow( pWnd_->GetSafeHwnd() );
        }
    }

    return __super::OnCtlColor( pDC_, pWnd_, nCtlColor_ );
}

// =================================================================================================
//   Call UnsubclassWindow of the list box when the combo box is closed
// -------------------------------------------------------------------------------------------------
void CTooltipComboBox::OnDestroy()
{
    if ( m_listbox.GetSafeHwnd() != nullptr )
    {
        m_listbox.UnsubclassWindow();
        m_listbox.DestroyTooltip();
    }

    __super::OnDestroy();
}

// =================================================================================================
//   Assign standard profile tooltips
//
// Parameter : tooltips_ : Standard profile tooltips
// -------------------------------------------------------------------------------------------------
void CTooltipComboBox::TooltipsSet( const TWStrings& tooltips_ )
{
    m_listbox.TooltipsSet( tooltips_ );
}

///////////////////////////////////////////////////////////////////////////////
// CTooltipListBox

BEGIN_MESSAGE_MAP( CTooltipListBox, CListBox )
    //{{AFX_MSG_MAP( CTooltipListBox )
    ON_WM_MOUSEMOVE()
    ON_WM_TIMER()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

// =================================================================================================
//   Ctor
// -------------------------------------------------------------------------------------------------
CTooltipListBox::CTooltipListBox()
: m_hWndToolTip( nullptr )
, m_currentItem( -1 )
{
}

// =================================================================================================
//   Destruction of the tooltip
// -------------------------------------------------------------------------------------------------
void CTooltipListBox::DestroyTooltip()
{
    if ( m_hWndToolTip != nullptr )
    {
        ::DestroyWindow( m_hWndToolTip );
        m_hWndToolTip = nullptr;
    }
}

// =================================================================================================
//   Indicates if tooltip is visible
//
// Return : true if tooltip is visible
// -------------------------------------------------------------------------------------------------
bool CTooltipListBox::IsTootipVisible()
{
    return ( m_hWndToolTip != nullptr ) && ( ::IsWindowVisible( m_hWndToolTip ) == TRUE );
}

// =================================================================================================
//   Subclass the list box window to create tooltip
// -------------------------------------------------------------------------------------------------
void CTooltipListBox::PreSubclassWindow()
{
    __super::PreSubclassWindow();

    // The tooltip should not have been created
    assert( m_hWndToolTip == nullptr );

    // Create the tooltip
    m_hWndToolTip = ::CreateWindowEx(
        WS_EX_TOPMOST,
        TOOLTIPS_CLASS,
        nullptr,
        TTS_NOPREFIX | TTS_ALWAYSTIP,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        m_hWnd,
        nullptr,
        nullptr,
        nullptr );
    assert( m_hWndToolTip != nullptr );

    // Initialize toolinfo structure
    memset( &m_ToolInfo, 0, sizeof( m_ToolInfo ) );
    m_ToolInfo.cbSize = sizeof( m_ToolInfo );
    m_ToolInfo.uFlags = TTF_TRACK | TTF_TRANSPARENT;
    m_ToolInfo.hwnd   = m_hWnd;

    // Add the list box
    ::SendMessage( m_hWndToolTip, TTM_SETMAXTIPWIDTH,  0,                                    SHRT_MAX );
    ::SendMessage( m_hWndToolTip, TTM_ADDTOOL,         0,                                    ( LPARAM ) &m_ToolInfo );
    ::SendMessage( m_hWndToolTip, TTM_SETTIPBKCOLOR,   ::GetSysColor( COLOR_HIGHLIGHT ),     0 );
    ::SendMessage( m_hWndToolTip, TTM_SETTIPTEXTCOLOR, ::GetSysColor( COLOR_HIGHLIGHTTEXT ), 0 );

    // Reduce top & bottom margin
    CRect rectMargins( 0, -1, 0, -1 );
    ::SendMessage( m_hWndToolTip, TTM_SETMARGIN, 0, ( LPARAM ) &rectMargins );

    // Set font
    CFont* pFont = GetFont();
    ::SendMessage( m_hWndToolTip, WM_SETFONT, ( WPARAM ) pFont->GetSafeHandle(), FALSE );

    // Remove borders
    LONG lStyle = ::GetWindowLong( m_hWndToolTip, GWL_STYLE );
    lStyle &= ~WS_BORDER;
    ::SetWindowLong( m_hWndToolTip, GWL_STYLE, lStyle );
}

// =================================================================================================
//   Handling the mouse move
//
// Parameter : nFlags_ : Key and button flags
// Parameter : point_  : Cursor position (relative to the window)
// -------------------------------------------------------------------------------------------------
void CTooltipListBox::OnMouseMove( UINT nFlags_, CPoint point_ )
{
    if ( ::IsWindow( GetSafeHwnd() ) && ::IsWindow( m_hWndToolTip ) )
    {
        CRect rectClient;
        GetClientRect( &rectClient );

        if ( rectClient.PtInRect( point_ ) == TRUE )
        {
            BOOL bOutside = FALSE;
            int  nItem    = ItemFromPoint( point_, bOutside ); // item of the list box

            if ( !bOutside && ( nItem >= 0 ) && ( nItem != m_currentItem ) )
            {
                CString strText = _T( "" );
                // If a tooltip is defined
                if ( static_cast< size_t >( nItem ) < m_tooltips.size() )
                {
                    strText = m_tooltips[ nItem ].c_str();
                }
                // Else use item text
                else
                {
                    GetText( nItem, strText );
                }
                m_ToolInfo.lpszText = strText.GetBuffer();

                CRect rect;
                GetItemRect( nItem, &rect );
                ClientToScreen( &rect );

                ::SendMessage( m_hWndToolTip, TTM_UPDATETIPTEXT, 0, ( LPARAM ) &m_ToolInfo );
                ::SendMessage(
                    m_hWndToolTip,
                    TTM_TRACKPOSITION,
                    0,
                    ( LPARAM ) MAKELONG( rect.left + point_.x, rect.top ) );
                ::SendMessage( m_hWndToolTip, TTM_TRACKACTIVATE, TRUE, ( LPARAM ) &m_ToolInfo );

                SetTimer( 1, 80, nullptr );    // Timer to detect if cursor had left

                strText.ReleaseBuffer();

                m_currentItem = nItem;
            }
        }
        else
        {
            ::SendMessage( m_hWndToolTip, TTM_TRACKACTIVATE, FALSE, ( LPARAM ) &m_ToolInfo );
        }
    }

    __super::OnMouseMove( nFlags_, point_ );
}

// =================================================================================================
//   Handling the timer
//
// Parameter : nIDEvent_ : Timer ID
// -------------------------------------------------------------------------------------------------
void CTooltipListBox::OnTimer( UINT_PTR nIDEvent_ )
{
    if ( ::IsWindow( GetSafeHwnd() ) && ::IsWindow( m_hWndToolTip ) )
    {
        CPoint point( ::GetMessagePos() );
        ScreenToClient( &point );

        CRect rectClient;
        GetClientRect( &rectClient );

        DWORD dwStyle = GetStyle();
        if ( ( rectClient.PtInRect( point ) == FALSE ) || ( ( dwStyle & WS_VISIBLE ) == 0 ) )
        {
            KillTimer( nIDEvent_ );

            ::SendMessage( m_hWndToolTip, TTM_TRACKACTIVATE, FALSE, ( LPARAM ) &m_ToolInfo );

            m_currentItem = -1;
        }
    }
}
