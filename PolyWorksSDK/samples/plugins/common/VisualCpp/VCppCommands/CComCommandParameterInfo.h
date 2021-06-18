#pragma once

// =================================================================================================
// Class describing a COM command parameter
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/CWString.h>
#include <PolyWorksSDK/COM/IMTypes.h>

class CComCommandParameterInfoImpl;

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ===================================== CONSTANTES, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =============================================================================
// COM command parameter class description implementation
// A description, a direction and a type must at least be specified
// Otherwise, only needed members require initialisation
// -----------------------------------------------------------------------------
class CComCommandParameterInfo
{
public:
    CComCommandParameterInfo( const IM::CWString& desc_, EParameterDirection dir_, EParameterType type_ );
    CComCommandParameterInfo( CComCommandParameterInfo& info_ );
    virtual ~CComCommandParameterInfo();

    // Description
    IM::CWString DescGet() const;
    void         DescSet( const IM::CWString& desc_ );

    // Possible values (in a string, separated by comas)
    IM::CWString ValuesGet() const;
    void         ValuesSet( const IM::CWString& values_ );

    // Direction
    EParameterDirection DirGet() const;
    void                DirSet( EParameterDirection dir_ );

    // Type
    EParameterType TypeGet() const;
    void           TypeSet( EParameterType type_ );

    // True if parameter have a default double value
    bool HasDoubleDefaultValueGet() const;
    void HasDoubleDefaultValueSet( bool hasValue_ );

    // Default value for double parameter
    double DoubleDefaultValueGet() const;
    void   DoubleDefaultValueSet( double value_ );

    // True if parameter have a default integer value
    bool HasIntDefaultValueGet() const;
    void HasIntDefaultValueSet( bool hasValue_ );

    // Default value for integer parameter
    int  IntDefaultValueGet() const;
    void IntDefaultValueSet( int value_ );

    // True if parameter have a default string value
    bool HasStringDefaultValueGet() const;
    void HasStringDefaultValueSet( bool hasValue_ );

    // Default value for string parameter
    IM::CWString StringDefaultValueGet() const;
    void         StringDefaultValueSet( const IM::CWString& value_ );

private:
    const CComCommandParameterInfo& operator=( const CComCommandParameterInfo& );

    CComCommandParameterInfoImpl* m_pImpl;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
