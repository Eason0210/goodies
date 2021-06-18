#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IPWOElementsProperties.h
///    \brief    IPWOElementsProperties class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/Size.h>
#include <PolyWorksSDK/Object/CPWObjectStatus.h>

namespace IM { class IArray; }

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
///    \brief    Interface giving access to the properties of a PolyWorks Object's elements.
///
///              Once obtained as a property from a PolyWorks Object ( see the example below ), this interface
///              can be used to access and modify ( if supported by the object ) the states of the elements of
///              its geometries. The three possible states exposed by this interface are the selection, the
///              deletion and the visibility.
///
///              In the PolyWorks|Inspector module, no point or triangle can actually be deleted from a PolyWorks Object.
///              Using this interface, they can be flagged as deleted so that all algorithm will ignore them and
///              they won't appear in the 3D Scene.
///
///              In order to increase the performance of the reading states, it is strongly recommanded to use
///              the CPWOElements object ( please see CPWOElements.h ).
///
///              Note that in PolyWorks|Inspector, modifications to any of the states of the elements of an object will
///              clear the undo stack of the module.
///
///              Example:
///              \code{.cpp}
///              // Accessing the elements property of a given PolyWorks Object.
///              IM::IPWOProperty* pProperty = pPWObject->PropertyGet( IM::PWOPropertyElementsTypeGet() );
///              if( pPropertyElements != NULL )
///              {
///                   // Reading the property as a IPWOElementsProperties interface pointer.
///                   IM::IPWOElementsProperties* pElements;
///                   if( pPropertyElements->ValueGet( pElements ) )
///                   {
///                      // TODO: Modify or access the elements' properties here.
///                   }
///              }
///              \endcode
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class IPWOElementsProperties
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IPWOElementsProperties() {}

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IPWOElementsProperties() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the deleted state of an element.  Note that in the PolyWorks|Inspector module,
    ///              no point or triangle can actually be deleted from a PolyWorks Object. Deleted elements
    ///              are only flagged as deleted.
    ///
    ///    \param[ in ] pArray_    The PolyWorks Object's geometry in which the element is located.
    ///    \param[ in ] idx_       The index of the element in the specified array.
    ///
    ///    \return    True if the specified element is deleted. False if it is not.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool DeletedGet( const IArray* pArray_, TSize idx_ ) const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Changes the deleted state of an element.  Note that in the PolyWorks|Inspector module,
    ///              no point or triangle can actually be deleted from a PolyWorks Object. Deleted elements
    ///              are only flagged as deleted.
    ///
    ///    \param[ in ] pArray_    The PolyWorks Object's geometry in which the element is located.
    ///    \param[ in ] idx_       The index of the element in the specified array.
    ///    \param[ in ] state_     The new property state to be affected.
    ///                            - true to delete the element.
    ///                            - false to undelete it.
    ///
    ///    \return    A PolyWorks Object Status indicating the result of the operation.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CPWObjectStatus DeletedSet( IArray* pArray_, TSize idx_, bool state_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the selected state of an element.
    ///
    ///    \param[ in ] pArray_    The PolyWorks Object's geometry in which the element is located.
    ///    \param[ in ] idx_       The index of the element in the specified array.
    ///
    ///    \return    True if the specified element is selected. False if it is not.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool SelectedGet( const IArray* pArray_, TSize idx_ ) const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Changes the selected state of an element.
    ///
    ///    \param[ in ] pArray_    The PolyWorks Object's geometry in which the element is located.
    ///    \param[ in ] idx_       The index of the element in the specified array.
    ///    \param[ in ] state_     The new property state to be affected.
    ///                            - true to select the element.
    ///                            - false to unselected it.
    ///
    ///    \return    A PolyWorks Object Status indicating the result of the operation.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CPWObjectStatus SelectedSet( IArray* pArray_, TSize idx_, bool state_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the visible state of an element.
    ///
    ///    \param[ in ] pArray_    The PolyWorks Object's geometry in which the element is located.
    ///    \param[ in ] idx_       The index of the element in the specified array.
    ///
    ///    \return    True if the specified element is visible. False if it is hidden.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool VisibleGet( const IArray* pArray_, TSize idx_ ) const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Changes the visible state of an element.
    ///
    ///    \param[ in ] pArray_    The PolyWorks Object's geometry in which the element is located.
    ///    \param[ in ] idx_       The index of the element in the specified array.
    ///    \param[ in ] state_     The new property state to be affected.
    ///                            - true to render the element visible.
    ///                            - false to hide it.
    ///
    ///    \return    A PolyWorks Object Status indicating the result of the operation.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CPWObjectStatus VisibleSet( IArray* pArray_, TSize idx_, bool state_ ) = 0;


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
