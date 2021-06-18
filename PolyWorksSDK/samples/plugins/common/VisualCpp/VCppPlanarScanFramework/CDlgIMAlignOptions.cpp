// =================================================================================================
//   Plug-in dialog base class implementation.
//
// Copyright © InnovMetric Softwares Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CDlgIMAlignOptions.h"

#include "ApplicationUtils.h"
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
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

IMPLEMENT_DYNAMIC( CDlgIMAlignOptions, CDialog )

// =================================================================================================
// Message map.
// -------------------------------------------------------------------------------------------------
BEGIN_MESSAGE_MAP( CDlgIMAlignOptions, CDialog )
    ON_WM_MOVE()
END_MESSAGE_MAP()

// =================================================================================================
//   Ctor.
// -------------------------------------------------------------------------------------------------
CDlgIMAlignOptions::CDlgIMAlignOptions( CWnd* pParent_ /*= nullptr*/ )
: CDialog( IDD, pParent_ )
, m_dialogInitialized( false )
{

}


// =================================================================================================
//   Dtor.
// -------------------------------------------------------------------------------------------------
CDlgIMAlignOptions::~CDlgIMAlignOptions()
{

}


// =================================================================================================
//   Reaction to the OK button.
// -------------------------------------------------------------------------------------------------
void CDlgIMAlignOptions::OnOK()
{
    // TODO: Validate values before applying changes

    CString value;

    // Write Max Edge Length if it has changed
    // Using GET and SET setting
    m_maxEdgeLength.GetWindowText( value );
    if ( theCompanyNameScannerSettings().IMAMaxEdgeLengthGet() != _tstof( value ) )
    {
        theCompanyNameScannerSettings().IMAMaxEdgeLengthSet( _tstof( value ) );
    }

    // Write Interpolation Step if it has changed
    // Using GET and SET setting
    m_interpolationStep.GetWindowText( value );
    if ( theCompanyNameScannerSettings().IMAInterpolationStepGet() != _tstof( value ) )
    {
        theCompanyNameScannerSettings().IMAInterpolationStepSet( _tstof( value ) );
    }

    // Write Max Angle if it has changed
    // Using GET and SET setting
    m_maxAngle.GetWindowText( value );
    if ( theCompanyNameScannerSettings().IMAMaxAngleGet() != _tstof( value ) )
    {
        theCompanyNameScannerSettings().IMAMaxAngleSet( _tstof( value ) );
    }

    __super::OnOK();
}


// =================================================================================================
//   Reaction to the WM_INITDIALOG message.
// -------------------------------------------------------------------------------------------------
BOOL CDlgIMAlignOptions::OnInitDialog()
{
    BOOL result = __super::OnInitDialog();

    // Place the window to the correct place
    RECT rect;
    GetWindowRect( &rect );

    // Convert the coordinates for use with MoveWindow
    POINT pt;
    pt.x = rect.left;
    pt.y = rect.top;
    ScreenToClient( &pt );
    rect.right  = rect.right - rect.left;
    rect.bottom = rect.bottom - rect.top;
    rect.left   = pt.x;
    rect.top    = pt.y;

    // Set the new position
    int x = WindowPositionXGet();
    int y = WindowPositionYGet();
    int w = rect.right;
    int h = rect.bottom;

    // TODO: For added safety, you could make sure that the dialog is within the boundaries of the desktop

    // Move the dialog to its new position
    MoveWindow( x, y, w, h, FALSE );

    m_dialogInitialized = true;

    DialogUpdate();

    return result;
}


// =================================================================================================
//   Reaction to a move.
//
// Parameter : x_ : not used
// Parameter : y_ : not used
// -------------------------------------------------------------------------------------------------
void CDlgIMAlignOptions::OnMove( int /*x_*/, int /*y_*/ )
{
    if ( m_dialogInitialized )
    {
        // Memorize the position of the window
        RECT rect;
        GetWindowRect( &rect );
        WindowPositionXSet( rect.left );
        WindowPositionYSet( rect.top );
    }
}


// =================================================================================================
//   Synchronize controls value from configuration.
// -------------------------------------------------------------------------------------------------
void CDlgIMAlignOptions::DialogUpdate()
{
    m_maxEdgeLength.SetWindowText( ValueToString( theCompanyNameScannerSettings().IMAMaxEdgeLengthGet() ).c_str() );
    m_interpolationStep.SetWindowText( ValueToString( theCompanyNameScannerSettings().IMAInterpolationStepGet() ).c_str() );
    m_maxAngle.SetWindowText( ValueToString( theCompanyNameScannerSettings().IMAMaxAngleGet() ).c_str() );

    UpdateData( FALSE );
}

// =================================================================================================
//   MFC function to transfer data between GUI and variables.
// -------------------------------------------------------------------------------------------------
void CDlgIMAlignOptions::DoDataExchange( CDataExchange* pDX_ )
{
    __super::DoDataExchange( pDX_ );

    DDX_Control( pDX_, IDC_EDIT_MAX_EDGE_LENGTH,    m_maxEdgeLength );
    DDX_Control( pDX_, IDC_EDIT_INTERPOLATION_STEP, m_interpolationStep );
    DDX_Control( pDX_, IDC_EDIT_MAX_ANGLE,          m_maxAngle );
}


// =================================================================================================
//   Obtain the X position of the window.
//
// Return : Position
// -------------------------------------------------------------------------------------------------
long CDlgIMAlignOptions::WindowPositionXGet()
{
    return theCompanyNameScannerSettings().IMAOptionsWindowPositionXGet();
}


// =================================================================================================
//   Set the X position of the window.
//
// Parameter : position_ : Position
// -------------------------------------------------------------------------------------------------
void CDlgIMAlignOptions::WindowPositionXSet( long position_ )
{
    theCompanyNameScannerSettings().IMAOptionsWindowPositionXSet( position_ );
}


// =================================================================================================
//   Obtain the Y position of the window.
//
// Return : Position
// -------------------------------------------------------------------------------------------------
long CDlgIMAlignOptions::WindowPositionYGet()
{
    return theCompanyNameScannerSettings().IMAOptionsWindowPositionYGet();
}


// =================================================================================================
//   Sets the Y position of the window.
//
// Parameter : position_ : Position
// -------------------------------------------------------------------------------------------------
void CDlgIMAlignOptions::WindowPositionYSet( long position_ )
{
    theCompanyNameScannerSettings().IMAOptionsWindowPositionYSet( position_ );
}
