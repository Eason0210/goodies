#pragma once

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class IPWObject;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_CLASSES
///
///    \brief    Simple class used delay actions on a PolyWorks Object. When instanciated and attached
///              to a IPWObject, actions supporting the CPWODelayer in the PolyWorks Object will
///              occur in batch when the CPWODelayer object is destroyed. To fully understand what
///              actions are affected by attaching a IPWObject to a CPWODelayer, we suggest that
///              you carefully read the documentation of IPWObject derived classes.
///
///              The main purpose of this class is to speed up some actions that, done in batch, are much more quicker
///              then when done separatly. For example, in PolyWorks|Inspector, when 3D coordinates
///              of points in a IPointCloud are modified, features may be recalculated. To prevent
///              these recalculations each time a point is modified (or added), you must use a CPWODelayer
///              object that will apply the modifications only once it is destroyed.
///
///              A IPWObject may only be attached to one CPWODelayer at a time so, after the first attachment,
///              subsequent attachments have no effects. You may use attach your IPWObject in two
///              ways: via CPWODelayer::CPWODelayer or via CPWODelayer::Attach. The first method
///              has the advantage of beeing more compact and the second will tell you if the attachment
///              was successful.
///
///              You have to be careful when using this object. We strongly suggest
///              CPWODelayer are declared without using dynamic allocation (new/delete) and are always
///              scoped within a function (do not make it global variable or object member).
///
///              Example:
///              \code{.cpp}
///              void MyFunc( IM::IPointCloud* pPointCloud_ )
///              {
///                  // Starts recording changes when the object is created.
///                  IM::CPWODelayer delayer( pPointCloud_ );
///                  // Do modifications to the IM::IPointCloud geometries
///                  // When the IM::CPWODelayer object is destroyed, modifications will be applied in batch.
///              }
///              \endcode
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CPWODelayer
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor. Make sure you call CPWODelayer::Attach once.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPWODelayer();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor attaching a IPWObject automatically. You do not need to call CPWODelayer::Attach.
    ///
    ///    \param[ in ]    pPWObject_    Pointer to the PolyWorks object to attach.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPWODelayer( IPWObject* pPWObject_ );

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor. When called, it will ask the attached IPWObject to apply all actions.
    ///              it documents as supporting CPWODelayer.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CPWODelayer();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Attache a IPWObject to the delayer. This function must be called only when using
    ///              the default constructor.  Parameter: pPWObject_ : Pointer to the PolyWorks object
    ///              to attach.
    ///
    ///    \return    true if the attachment went well, false if there was an error (object already  attached
    ///               to another CPWODelayer).
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool Attach( IPWObject* pPWObject_ );


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

    IPWObject* m_pPWObject;
};


// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
