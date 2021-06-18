// =================================================================================================
//   Plug-in dialog base class implementation.
//
// Copyright © InnovMetric Softwares Inc. 2016 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CIMDlgOptionsBase.h"

#include "ApplicationUtils.h"
#include "CIMPropertyGridCheckBoxProperty.h"
#include "CIMPropertyGridColorProperty.h"
#include "CIMPropertyGridCtrl.h"
#include "CIMPropertyGridProperty.h"

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
// Update property values from get commands
// -------------------------------------------------------------------------------------------------
void UpdateFromCmds( TPropertyValues& values_ )
{
    for ( auto& value : values_ )
    {
        value.UpdateFromCmd();
    }
}

// =================================================================================================
// Update property values to set commands if required
// -------------------------------------------------------------------------------------------------
bool UpdateToCmds( TPropertyValues& values_ )
{
    bool result = true;
    for ( auto& value : values_ )
    {
        result = result && value.UpdateToCmd();
    }

    return result;
}

// =================================================================================================
// CPropertyValue Ctor
//
// Parameter: property_ : Property type
// Parameter: cmdName_  : Command name
// -------------------------------------------------------------------------------------------------
CPropertyValue::CPropertyValue(
    const EPropertyType property_,
    const wchar_t*      propertyName_,
    const wchar_t*      cmdName_ )
: m_cmdName( cmdName_ )
, m_propertyName( propertyName_ )
, m_propertyType( property_ )
{
    switch ( property_ )
    {
        case E_PROPERTY_TYPE_BOOL:
            m_property = COleVariant( static_cast< short >( VARIANT_FALSE ), VT_BOOL );
            break;
        case E_PROPERTY_TYPE_LONG:
            m_property = COleVariant( 0L );
            break;
        case E_PROPERTY_TYPE_DOUBLE:
            m_property = COleVariant( 0.0 );
            break;
        case E_PROPERTY_TYPE_STRING:
            m_property = COleVariant( L"" );
            break;
        case E_PROPERTY_TYPE_COLOR:
            m_property = COleVariant( 0L );
            break;
        default:
            ASSERT( false );
            break;
    }

    UpdateFromCmd();
}

// =================================================================================================
// Update property value from get command
// -------------------------------------------------------------------------------------------------
void CPropertyValue::UpdateFromCmd()
{
    if ( !m_cmdName.empty() )
    {
        std::wstring value;
        if ( m_propertyType == E_PROPERTY_TYPE_COLOR )
        {
            COLORREF color = 0;
            if ( ValueColorGetFromApp( m_cmdName + L" GET", color ) )
            {
                VERIFY( m_property.vt == VT_I4 );

                m_property.intVal = static_cast< int >( color );
            }
            else
            {
                ASSERT( false );
            }
        }
        else if ( ValueStrGetFromApp( m_cmdName + L" GET", value ) )
        {
            switch ( m_property.vt )
            {
                case VT_BOOL:
                    m_property.boolVal = ( value == L"On" ? VARIANT_TRUE : VARIANT_FALSE );
                    break;
                case VT_I4:
                    m_property = _tstol( value.c_str() );
                    break;
                case VT_R8:
                    m_property = _tstof( value.c_str() );
                    break;
                case VT_BSTR:
                    m_property = value.c_str();
                    break;
                default:
                    ASSERT( false );
                    break;
            }
        }
    }
    else
    {
        ASSERT( false );
    }
}

// =================================================================================================
// Update property value to set command if required
// -------------------------------------------------------------------------------------------------
bool CPropertyValue::UpdateToCmd()
{
    bool result = true;
    if ( !m_cmdName.empty() )
    {
        if ( m_propertyType == E_PROPERTY_TYPE_COLOR )
        {
            VERIFY( m_property.vt == VT_I4 );

            COLORREF color = 0;
            if ( ValueColorGetFromApp( m_cmdName + L" GET", color ) &&
                 ( color != m_property.intVal ) )
            {
                std::wstring colorValue = ValueToString( GetRValue( m_property.intVal ) ) + L"\",\"" +
                                          ValueToString( GetGValue( m_property.intVal ) ) + L"\",\"" +
                                          ValueToString( GetBValue( m_property.intVal ) );
                if ( !ValueStrSetToApp( m_cmdName, colorValue, true, true ) )
                {
                    result = false;
                }
            }
        }
        else
        {
            std::wstring tmp;
            switch ( m_property.vt )
            {
                case VT_BOOL:
                    if ( ( ValueStrGetFromApp( m_cmdName + L" GET", tmp ) &&
                           ( ( tmp == L"On" ) != ( m_property.boolVal != VARIANT_FALSE ) ) ) )
                    {
                        if ( !ValueStrSetToApp( m_cmdName, m_property.boolVal != VARIANT_FALSE ? L"On" : L"Off", true, true ) )
                        {
                            result = false;
                        }
                    }
                    break;
                case VT_I4:
                    if ( ( ValueStrGetFromApp( m_cmdName + L" GET", tmp ) &&
                           ( _tstol( tmp.c_str() ) != m_property.intVal ) ) )
                    {
                        if ( !ValueStrSetToApp( m_cmdName, ValueToString( m_property.intVal ), true, true ) )
                        {
                            result = false;
                        }
                    }
                    break;
                case VT_R8:
                    if ( ( ValueStrGetFromApp( m_cmdName + L" GET", tmp ) &&
                           ( _tstof( tmp.c_str() ) != m_property.dblVal ) ) )
                    {
                        if ( !ValueStrSetToApp( m_cmdName, ValueToString( m_property.dblVal ), true, true ) )
                        {
                            result = false;
                        }
                    }
                    break;
                case VT_BSTR:
                    if ( ( ValueStrGetFromApp( m_cmdName + L" GET", tmp ) &&
                           _tcsicmp( tmp.c_str(), m_property.bstrVal ) != 0 ) )
                    {
                        if ( !ValueStrSetToApp( m_cmdName, m_property.bstrVal, true, true ) )
                        {
                            result = false;
                        }
                    }
                    break;
                default:
                    ASSERT( false );
                    break;
            }
        }
    }
    else
    {
        ASSERT( false );
    }

    return result;
}

IMPLEMENT_DYNAMIC( CIMDlgOptionsBase, CDialog )

// =================================================================================================
// Message map.
// -------------------------------------------------------------------------------------------------
BEGIN_MESSAGE_MAP( CIMDlgOptionsBase, CDialog )
    ON_WM_MOVE()
    ON_NOTIFY( TVN_SELCHANGED, IDC_TREE_OPTIONS, OnTvnSelchangedTreeOptions )
    ON_REGISTERED_MESSAGE( AFX_WM_PROPERTY_CHANGED, OnPropertyChanged )
END_MESSAGE_MAP()

// =================================================================================================
//   Ctor of CDlgOptionsBase.
//
// Parameter: nIDTemplate_ : Contains a null-terminated string that is the name of a dialog-box
//                           template resource
// Parameter: pParent_     : Contains the ID number of a dialog-box template resource
// -------------------------------------------------------------------------------------------------
CIMDlgOptionsBase::CIMDlgOptionsBase( UINT nIDTemplate_, CWnd* pParent_ /*=nullptr*/ )
: CDialog( nIDTemplate_, pParent_ )
, m_dialogInitialized( false )
, m_pPropertyTree( new CTreeCtrl )
, m_pPropertyGridCtrl( new CIMPropertyGridCtrl )
{
}


// =================================================================================================
//   Dtor of CDlgOptionsBase.
// -------------------------------------------------------------------------------------------------
CIMDlgOptionsBase::~CIMDlgOptionsBase()
{

}


// =================================================================================================
//   Synchronize controls value from configuration.
// -------------------------------------------------------------------------------------------------
void CIMDlgOptionsBase::DialogUpdate()
{
    UpdateFromCmds( m_propertyValues );

    UpdateData( FALSE );

    PropertyGridInit( m_pPropertyTree->GetSelectedItem() );
}

// =================================================================================================
//   MFC function to transfer data between GUI and variables.
// -------------------------------------------------------------------------------------------------
void CIMDlgOptionsBase::DoDataExchange( CDataExchange* pDX_ )
{
    __super::DoDataExchange( pDX_ );

    DDX_Control( pDX_, IDC_TREE_OPTIONS,            *m_pPropertyTree );
    DDX_Control( pDX_, IDC_MFCPROPERTYGRID_OPTIONS, *m_pPropertyGridCtrl );
}

// =================================================================================================
// Create a color property
//
// Parameter: propertyValue_ : The property value
//
// Return : Pointer to the created property
// -------------------------------------------------------------------------------------------------
CIMPropertyGridColorProperty* CIMDlgOptionsBase::MakePropertyColorValue( DWORD_PTR propertyValue_ )
{
    return new CIMPropertyGridColorProperty(
        m_propertyValues[ propertyValue_ ].NameGet(),
        static_cast< COLORREF >( m_propertyValues[ propertyValue_ ].Get().intVal ),
        nullptr,
        nullptr,
        propertyValue_ );
}

// =================================================================================================
// Create a combo box property
//
// Parameter: propertyValue_ : The property value
// Parameter: valueChoices_  : The combo box choices
// Parameter: allowEdit_     : TRUE to allow edit
//
// Return : Pointer to the created property
// -------------------------------------------------------------------------------------------------
template< typename T >
T* CIMDlgOptionsBase::MakePropertyComboValue( DWORD_PTR propertyValue_, const TWStrings& valueChoices_, const BOOL allowEdit_ )
{
    return new T(
        m_propertyValues[ propertyValue_ ].NameGet(),
        m_propertyValues[ propertyValue_ ].Get(),
        valueChoices_,
        allowEdit_,
        nullptr,
        propertyValue_ );
}
// explicit specialization
template CIMPropertyGridProperty* CIMDlgOptionsBase::MakePropertyComboValue( DWORD_PTR propertyValueType_, const TWStrings& valueChoices_, const BOOL allowEdit_ );

// =================================================================================================
// Create a property group
//
// Parameter: groupName_ : The group name
//
// Return : Pointer to the created property
// -------------------------------------------------------------------------------------------------
CIMPropertyGridProperty* CIMDlgOptionsBase::MakePropertyGroup( const wchar_t* groupName_ )
{
    return new CIMPropertyGridProperty( groupName_, -1, TRUE );
}

// =================================================================================================
// Create a property group with a value
//
// Parameter: propertyValue_ : The property value
//
// Return : Pointer to the created property
// -------------------------------------------------------------------------------------------------
template< typename T >
T* CIMDlgOptionsBase::MakePropertyValueGroup( DWORD_PTR propertyValue_ )
{
    return new T(
        m_propertyValues[ propertyValue_ ].NameGet(),
        propertyValue_,
        TRUE,
        m_propertyValues[ propertyValue_ ].Get() );
}
// explicit specialization
template CIMPropertyGridCheckBoxProperty* CIMDlgOptionsBase::MakePropertyValueGroup( DWORD_PTR propertyValueType_ );

// =================================================================================================
// Create a property value
//
// Parameter: propertyValue_ : The property value
//
// Return : Pointer to the created property
// -------------------------------------------------------------------------------------------------
template< typename T >
T* CIMDlgOptionsBase::MakePropertyValue( DWORD_PTR propertyValue_ )
{
    return new T(
        m_propertyValues[ propertyValue_ ].NameGet(),
        m_propertyValues[ propertyValue_ ].Get(),
        nullptr,
        propertyValue_ );
}
// explicit specializations
template CIMPropertyGridProperty*         CIMDlgOptionsBase::MakePropertyValue( DWORD_PTR propertyValueType_ );
template CIMPropertyGridCheckBoxProperty* CIMDlgOptionsBase::MakePropertyValue( DWORD_PTR propertyValueType_ );

// =================================================================================================
//   Handling the WM_INITDIALOG message.
// -------------------------------------------------------------------------------------------------
BOOL CIMDlgOptionsBase::OnInitDialog()
{
    BOOL result = __super::OnInitDialog();

    // Place the window to the correct place
    RECT rect;
    GetWindowRect( &rect );

    // Set the new position
    int x = WindowPositionXGet();
    int y = WindowPositionYGet();
    int w = abs( rect.right - rect.left );
    int h = abs( rect.bottom - rect.top );

    // TODO: For added safety, you could make sure that the dialog is within the boundaries of the desktop

    // Move the dialog to its new position
    MoveWindow( x, y, w, h, FALSE );

    m_dialogInitialized = true;

    DialogUpdate();

    TreeViewInit();

    return result;
}


// =================================================================================================
//   Handling a move.
//
// Parameter: x_ : not used
// Parameter: y_ : not used
// -------------------------------------------------------------------------------------------------
void CIMDlgOptionsBase::OnMove( int /*x_*/, int /*y_*/ )
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
//   Handling the OK button.
// -------------------------------------------------------------------------------------------------
void CIMDlgOptionsBase::OnOK()
{
    if ( !UpdateToCmds( m_propertyValues ) )
    {
        DialogUpdate();
        return;
    }

    __super::OnOK();
}

// =================================================================================================
//   Handling a property change.
//
// Parameter: ctrlID_    : ID of the control
// Parameter: pProperty_ : Pointer of the modified property
//
// Return : always returns 0L
// -------------------------------------------------------------------------------------------------
LRESULT CIMDlgOptionsBase::OnPropertyChanged( WPARAM ctrlID_, LPARAM pProperty_ )
{
    auto* pProperty = reinterpret_cast< CMFCPropertyGridProperty* >( pProperty_ );

    DWORD       propertyData = pProperty->GetData();
    COleVariant value        = pProperty->GetValue();

    if ( propertyData < m_propertyValues.size() )
    {
        m_propertyValues[ propertyData ].Set( value );
    }

    if ( value.vt == VT_BOOL )
    {
        PropertyEnableUpdate( propertyData, value.boolVal != VARIANT_FALSE ? TRUE : FALSE );
    }

    return 0L;
}

// =================================================================================================
//   Handling a treeview selection.
//
// Parameter: pNMHDR_  : Selection structure
// Parameter: pResult_ : Result to return
// -------------------------------------------------------------------------------------------------
void CIMDlgOptionsBase::OnTvnSelchangedTreeOptions( NMHDR* pNMHDR_, LRESULT* pResult_ )
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast< LPNMTREEVIEW >( pNMHDR_ );

    PropertyGridInit( pNMTreeView->itemNew.hItem );

    *pResult_ = 0;
}

// =================================================================================================
//   Enable a property.
//
// Parameter: property_ : Property value to enable
// Parameter: enable_   : TRUE to enable, false otherwise
// -------------------------------------------------------------------------------------------------
void CIMDlgOptionsBase::PropertyEnable( DWORD property_, BOOL enable_ )
{
    const int nbProperties = m_pPropertyGridCtrl->GetPropertyCount();
    for ( int i = 0; i < nbProperties; ++i )
    {
        CMFCPropertyGridProperty* pProperty = m_pPropertyGridCtrl->GetProperty( i );
        if ( pProperty != nullptr )
        {
            if ( pProperty->GetData() == property_ )
            {
                pProperty->Enable( enable_ );
                return;
            }
            else if ( SubPropertyEnable( pProperty, property_, enable_ ) )
            {
                return;
            }
        }
    }
}

// =================================================================================================
//   Update the enable state of a property automatically.
//
// Parameter : propertyData_ : Property data ID
// -------------------------------------------------------------------------------------------------
void CIMDlgOptionsBase::PropertyEnableUpdateAuto( DWORD propertyData_ )
{
    if ( ( propertyData_ >= 0 )                      &&
         ( propertyData_ < m_propertyValues.size() ) &&
         ( m_propertyValues[ propertyData_ ].Get().vt == VT_BOOL ) )
    {
        PropertyEnableUpdate( propertyData_, m_propertyValues[ propertyData_ ].Get().boolVal != VARIANT_FALSE ? TRUE : FALSE );
    }
}

// =================================================================================================
//   Enable recursively a sub property.
//
// Parameter: pParent_  : Parent property
// Parameter: property_ : Property value to enable
// Parameter: enable_   : TRUE to enable, false otherwise
//
// Return : true if the specified sub property has been enabled/disabled
// -------------------------------------------------------------------------------------------------
bool CIMDlgOptionsBase::SubPropertyEnable( CMFCPropertyGridProperty* pParent_, DWORD property_, BOOL enable_ )
{
    const int nbSubItems = pParent_->GetSubItemsCount();
    for ( int j = 0; j < nbSubItems; ++j )
    {
        CMFCPropertyGridProperty* pSubItem = pParent_->GetSubItem( j );
        if ( pSubItem != nullptr )
        {
            if ( pSubItem->GetData() == property_ )
            {
                pSubItem->Enable( enable_ );
                return true;
            }
            else if ( SubPropertyEnable( pSubItem, property_, enable_ ) )
            {
                return true;
            }
        }
    }

    return false;
}

// =================================================================================================
//   Add a property page.
//
// Parameter: propertyPage_ : Property page to add
// Parameter: desc_         : Description
// Parameter: hParent_      : Handle to the parent
//
// Return : the handle of the added property page
// -------------------------------------------------------------------------------------------------
HTREEITEM CIMDlgOptionsBase::PropertyPageAdd( DWORD propertyPage_, const wchar_t* const desc_, HTREEITEM hParent_ /*= TVI_ROOT*/ )
{
    HTREEITEM hTreeItem = m_pPropertyTree->InsertItem( desc_, hParent_ );

    m_propertyPageMap[ hTreeItem ] = propertyPage_;

    return hTreeItem;
}

// =================================================================================================
// Recursively find tree items.
//
// Parameter: itemNames_   : List of items
// Parameter: includeGrid_ : true to include the grid content
// Parameter: hItem_       : Item to analyze
// Parameter: indent_      : Desired indentation
//
// Return : true if items found
// -------------------------------------------------------------------------------------------------
bool CIMDlgOptionsBase::PropertiesLog( std::wstring& itemNames_, const bool includeGrid_, const HTREEITEM hItem_, const size_t indent_ )
{
    HTREEITEM hItem = hItem_;

    // Can't log the root, start with it's first child
    if ( hItem == TVI_ROOT )
    {
        hItem =  m_pPropertyTree->GetNextItem( hItem, TVGN_CHILD );
    }

    while ( hItem != nullptr )
    {
        if ( !itemNames_.empty() )
        {
            itemNames_ += L"\n";
        }

        // Log the property page name
        itemNames_ += std::wstring( indent_, wchar_t( ' ' ) );
        itemNames_ += m_pPropertyTree->GetItemText( hItem );

        // Log the grid if required
        if ( includeGrid_ )
        {
            PropertyGridInit( hItem );
            const int count = m_pPropertyGridCtrl->GetPropertyCount();
            for ( int i = 0; i < count; ++i )
            {
                PropertyGridLog( itemNames_, m_pPropertyGridCtrl->GetProperty( i ), indent_ + 4 );
            }
        }

        // Log the child property pages
        HTREEITEM hChild = m_pPropertyTree->GetNextItem( hItem, TVGN_CHILD );
        if ( hChild != nullptr )
        {
            PropertiesLog( itemNames_, includeGrid_, hChild, indent_ + 4 );
        }

        // Goto the next property page
        hItem = m_pPropertyTree->GetNextItem( hItem, TVGN_NEXT );
    }

    return !itemNames_.empty();
}

// =================================================================================================
// Recursively find property grid items.
//
// Parameter: itemNames_ : List of items
// Parameter: pProp_     : Property to analyze
// Parameter: indent_    : Desired indentation
//
// Return : true if items found
// -------------------------------------------------------------------------------------------------
void CIMDlgOptionsBase::PropertyGridLog( std::wstring& itemNames_, CMFCPropertyGridProperty* pProp_, const size_t indent_ )
{
    if ( pProp_ != nullptr )
    {
        if ( !itemNames_.empty() )
        {
            itemNames_ += L"\n";
        }

        // Log the property name
        itemNames_ += std::wstring( indent_, L' ' );
        itemNames_ += pProp_->GetName();

        // Log the value if it is not empty
        const COleVariant& value = pProp_->GetValue();
        if ( value.vt != VT_EMPTY )
        {
            itemNames_ += L": ";
            auto* pColorProp = dynamic_cast< CIMPropertyGridColorProperty* >( pProp_ );
            if ( ( pColorProp != nullptr ) && ( value.vt == VT_I4 ) )
            {
                // Color components
                itemNames_ += ValueToString( GetRValue( value.intVal ) ) + L", ";
                itemNames_ += ValueToString( GetGValue( value.intVal ) ) + L", ";
                itemNames_ += ValueToString( GetBValue( value.intVal ) );
            }
            else if ( value.vt == VT_BOOL )
            {
                // Boolean value
                itemNames_ += value.boolVal ? L"True" : L"False";
            }
            else
            {
                // Formatted value
                itemNames_ += pProp_->FormatProperty();

                // Add options if there is a combo box
                int i = 0;
                for ( ; i < pProp_->GetOptionCount(); ++i )
                {
                    itemNames_ += ( i == 0 ? L" (" : L", " );
                    itemNames_ += pProp_->GetOption( i );
                }
                if ( i != 0 )
                {
                    itemNames_ += L')';
                }
            }
        }

        // Log the child properties
        const int count = pProp_->GetSubItemsCount();
        for ( int i = 0; i < count; ++i )
        {
            PropertyGridLog( itemNames_, pProp_->GetSubItem( i ), indent_ + 4 );
        }
    }
}
