#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CPWOElements.h
///    \brief    CPWOElements class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>
#include <PolyWorksSDK/Base/Size.h>
#include <PolyWorksSDK/Object/CPWOElementsTypes.h>

namespace IM { class IArray; }
namespace IM { class IPWObject; }

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CPWOElementsImpl;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_CLASSES
///
///    \brief    Concrete tool giving a fast read-only access to the properties of a PolyWorks Object's
///              elements. The three possible states exposed by this interface are the selection,
///              the deletion and the visibility ( please see CPWOElementsType.h ).
///
///              These states can be combined using AND and NOT operators in order to perform complex searches.
///
///              In the PolyWorks|Inspector module, no point or triangle can actually be deleted
///              from a PolyWorks Object. Using this interface, they can be flagged as deleted so
///              that all algorithm will ignore them and they won't appear in the 3D Scene.
///
///              Example:
///              \code{.cpp}
///              // Creating the tool to access elements of a certain type.
///              // Visible but not selected elements in this case.
///              IM::CPWOElements elements( pObject, pArray, IM::PWOElementsVisible() && !IM::PWOElementsSelected() );
///              IM::TSize size = pArray->Size();
///              for( IM::TSize i = 0; i < size; ++i )
///              {
///                   if( elements.StateGet( i ) )
///                   {
///                     // TODO: Process the PolyWorks object's elements here.
///                   }
///              }
///              \endcode
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CPWOElements
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor.  The types of elements are defined in the CPWOElementsType.h file and
    ///              can be combined using the operator&& (AND) and inverted using the operator! (NOT).
    ///
    ///    \param[ in ] pPWObject_    The PolyWorks Object that will be queried.
    ///    \param[ in ] pArray_       The PolyWorks Object's geometry that will be queried.
    ///    \param[ in ] types_        The types of desired elements.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPWOElements( const IPWObject* pPWObject_, const IArray* pArray_, const CPWOElementsTypes& types_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~CPWOElements();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the state of an element.  Note that in the PolyWorks|Inspector module, no
    ///              point or triangle can actually be deleted from a PolyWorks Object. Deleted elements
    ///              are only flagged as deleted.
    ///
    ///    \param[ in ] idx_    The index of the element in the specified array.
    ///
    ///    \return    True if the specified element is deleted. False if it is not.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool StateGet( TSize idx_ ) const;


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------
    CPWOElementsImpl* m_pImpl;

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
