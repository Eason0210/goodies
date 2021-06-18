#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IPWObject.h
///    \brief    IPWObject class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Geom/CGeometryType.h>
#include <PolyWorksSDK/Object/CPWObjectType.h>
#include <PolyWorksSDK/Object/CPWOPropertyType.h>

namespace IM { class IGeometry; }
namespace IM { class IPWOProperty; }

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_INTERFACES
///
///    \brief    Base class for all high-level objects that can be found in a project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class IPWObject
{
    friend class CPWODelayer;

public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IPWObject() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IPWObject() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns a pointer to the property associated to the input geometry type.
    ///
    ///    \param[ in ] geometryType_    Unique type of the wanted geometry.
    ///
    ///    \return    Pointer to the geometry. NULL if not found.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual IGeometry*       GeometryGet( const CGeometryType& geometryType_ )       = 0;
    virtual const IGeometry* GeometryGet( const CGeometryType& geometryType_ ) const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns whether the IPWObject is attached to a CPWODelayer object.
    ///
    ///    \return    true if the PolyWorks Object is attached to a CPWODelayer, false otherwise.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool IsAttachedToDelayer() const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns a pointer to the property associated to the input property type.
    ///
    ///    \param[ in ] propertyType_    Unique type of the wanted property.
    ///
    ///    \return    Pointer to the property. NULL if not found.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual const IPWOProperty* PropertyGet( const CPWOPropertyType& propertyType_ ) const = 0;
    virtual IPWOProperty*       PropertyGet( const CPWOPropertyType& propertyType_ )       = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the type of PolyWorks Object that represents the current object.
    ///
    ///    \return    PolyWorks Object type.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CPWObjectType TypeGet() const = 0;


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    This function is called whenever a CPWODelayer is attached to a IPWObject. In this
    ///              function, you must make your PolyWorks Object remember all delayable actions until
    ///              DetachFromDelayer is called.
    ///
    ///    \return    true if the attachment is accepted by the IPWObject, false otherwise
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool AttachToDelayer() = 0;

    // =================================================================================================
    // This function is called whenever a CPWODelayer is detached (its destructor is called)
    // from a IPWObject. In this function, you must execute any delayed function calls
    // made since the call to AttachToDelayer.
    virtual void DetachFromDelayer() = 0;

    // ---------------- Private Member Variables ---------------------------------------------------

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
