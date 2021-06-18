#pragma once

// =================================================================================================
//   Plug-in dialog base class declaration.
//
// Copyright © InnovMetric Softwares Inc. 2016 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <memory>
#include <unordered_map>
#include <vector>

#include "resource.h"
#include "Types.h"

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CIMPropertyGridColorProperty;
class CIMPropertyGridCtrl;
class CIMPropertyGridProperty;
class CMFCPropertyGridProperty;
class CTreeCtrl;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

enum EPropertyType
{
    E_PROPERTY_TYPE_BOOL,
    E_PROPERTY_TYPE_LONG,
    E_PROPERTY_TYPE_DOUBLE,
    E_PROPERTY_TYPE_STRING,
    E_PROPERTY_TYPE_COLOR,

    E_PROPERTY_TYPE_NB
};

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

typedef std::unordered_map< HTREEITEM, DWORD > TPropertyPageMap;

// =================================================================================================
// CPropertyValue class
// -------------------------------------------------------------------------------------------------
class CPropertyValue
{
public:
    CPropertyValue(
        const EPropertyType property_,
        const wchar_t*      propertyName_,
        const wchar_t*      cmdName_ );

    void UpdateFromCmd();
    bool UpdateToCmd();

    const wchar_t*     NameGet()                        { return m_propertyName.c_str(); }
    const COleVariant& Get()                            { return m_property; }
    void               Set( const COleVariant& value_ ) { m_property = value_; }

private:
    COleVariant         m_property;
    const std::wstring  m_cmdName;
    const std::wstring  m_propertyName;
    const EPropertyType m_propertyType;
};

using TPropertyValues = std::vector< CPropertyValue >;

// =================================================================================================
//   Plug-in base options dialog class
// -------------------------------------------------------------------------------------------------
class CIMDlgOptionsBase : public CDialog
{
    DECLARE_DYNAMIC( CIMDlgOptionsBase )
    DECLARE_MESSAGE_MAP()

public:

    // Public member functions
    ////////////////////////////

    CIMDlgOptionsBase( UINT nIDTemplate_, CWnd* pParent_ = nullptr );
    virtual ~CIMDlgOptionsBase();
    bool PropertiesLog( std::wstring& itemNames_, const bool includeGrid_, const HTREEITEM hItem_          = TVI_ROOT, const size_t indent_ = 0 );
    void PropertyGridLog( std::wstring& itemNames_, CMFCPropertyGridProperty* pProp_, const size_t indent_ = 0 );

    // Dialog Data
    virtual void DialogUpdate();

    // MFC virtual functions
    void DoDataExchange( CDataExchange* pDX_ ) override;
    BOOL OnInitDialog() override;
    void OnOK() override;

    // MFC message handlers
    afx_msg void OnMove( int x_, int y_ );

    // Public member variables
    ////////////////////////////

protected:

    // Protected member Functions
    ///////////////////////////////
    virtual void PropertyEnableUpdate( DWORD propertyData_, BOOL enable_ ) {}
    virtual void PropertyEnableUpdateAuto( DWORD propertyData_ );

    HTREEITEM PropertyPageAdd( DWORD propertyPage_, const wchar_t* const desc_, HTREEITEM hParent_ = TVI_ROOT );
    void      PropertyEnable( DWORD property_, BOOL enable_ = TRUE );
    bool      SubPropertyEnable( CMFCPropertyGridProperty* pParent_, DWORD property_, BOOL enable_ );

    CIMPropertyGridColorProperty* MakePropertyColorValue( DWORD_PTR propertyValueType_ );
    template< typename T >
    T*                       MakePropertyComboValue( DWORD_PTR propertyValueType_, const TWStrings& valueChoices_, const BOOL allowEdit_ );
    CIMPropertyGridProperty* MakePropertyGroup     ( const wchar_t* groupName_ );
    template< typename T >
    T* MakePropertyValueGroup( DWORD_PTR propertyValueType_ );
    template< typename T >
    T* MakePropertyValue     ( DWORD_PTR propertyValueType_ );

    // Protected member variables
    ///////////////////////////////
    bool             m_dialogInitialized;
    TPropertyPageMap m_propertyPageMap;

    // Dialog Controls
    std::unique_ptr< CTreeCtrl >           m_pPropertyTree;
    std::unique_ptr< CIMPropertyGridCtrl > m_pPropertyGridCtrl;

    // Property Values
    TPropertyValues m_propertyValues;

private:

    // Private member functions
    /////////////////////////////

    virtual long WindowPositionXGet()                 = 0;
    virtual void WindowPositionXSet( long position_ ) = 0;
    virtual long WindowPositionYGet()                 = 0;
    virtual void WindowPositionYSet( long position_ ) = 0;

    virtual void TreeViewInit()                              = 0;
    virtual void PropertyGridInit( HTREEITEM selectedItem_ ) = 0;

    afx_msg void    OnTvnSelchangedTreeOptions( NMHDR* pNMHDR_, LRESULT* pResult_ );
    afx_msg LRESULT OnPropertyChanged( WPARAM ctrlID_, LPARAM pProperty_ );

    // Private member variables
    /////////////////////////////
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

void UpdateFromCmds( TPropertyValues& values_ );
bool UpdateToCmds  ( TPropertyValues& values_ );
