// =================================================================================================
//   Plug-in's commands.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CCompanyNameCommands.h"

#include <PolyWorksSDK/Base/CColorRGBA.h>
#include <PolyWorksSDK/Geom/CPoint.h>
#include <PolyWorksSDK/UI/IAnnotation.h>
#include <PolyWorksSDK/UI/IDrawNodes.h>

#include "CDrawNodePoints.h"
#include "CDrawNodePolyline2D.h"
#include "CDrawNodePolyline3D.h"
#include "CDrawNodeText.h"
#include "CDrawNodeTriangles.h"

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

// TODO: Change CompanyName for your company name because draw node names must be unique
static IM::CWString     _drawNodeNamePolyline2D    = L"CompanyNameDrawNodePolyline2D";
static IM::CWString     _drawNodeNamePolyline2DXOR = L"CompanyNameDrawNodePolyline2DXOR";
static IM::CWString     _drawNodeNamePolyline3D    = L"CompanyNameDrawNodePolyline3D";
static IM::CWString     _drawNodeNamePolyline3DXOR = L"CompanyNameDrawNodePolyline3DXOR";
static IM::CWString     _drawNodeNamePoints        = L"CompanyNameDrawNodePoints";
static IM::CWString     _drawNodeNamePointsXOR     = L"CompanyNameDrawNodePointsXOR";
static IM::CWString     _drawNodeNameTriangles     = L"CompanyNameDrawNodeTriangles";
static IM::CWString     _drawNodeNameText          = L"CompanyNameDrawNodeText";
static IM::CWString     _drawText                  = L"PolyWorks SDK 3D Scene Rendering Sample";
static IM::IAnnotation* _pAnchoredAnnotation       = nullptr;
static IM::IAnnotation* _pFloatingAnnotation       = nullptr;

// =================================================================================================
// =================================== FUNCTIONS PROTOTYPES ========================================

// =================================================================================================
// =================================== FUNCTIONS DEFINITIONS =======================================

// =================================================================================================
// Remove one given annotation from the 3D Scene and free up any memory associated to it.
//
// Parameter: pAnnotation_ : Reference to a pointer to an annotation.
// -------------------------------------------------------------------------------------------------
static void AnnotationsRemoveOne( IM::IAnnotation*& pAnnotation_ )
{
    if ( pAnnotation_ != nullptr )
    {
        IM::Destroy( pAnnotation_ );
        pAnnotation_ = nullptr;
    }
}


// =================================================================================================
// Removes all annotations from the 3D Scene.
// -------------------------------------------------------------------------------------------------
void AnnotationsRemoveAll()
{
    AnnotationsRemoveOne( _pAnchoredAnnotation );
    AnnotationsRemoveOne( _pFloatingAnnotation );
}


// =================================================================================================
// Adds (if possible) a draw node to the applications draw node collection. If the operation fails,
// the draw nodes memory is freed.
//
// Parameter: pDrawNode_    : Pointer to a draw node
// Parameter: drawNodeType_ : Draw node type
// -------------------------------------------------------------------------------------------------
static void DrawNodeAddOne(
    IM::IDrawNode*    pDrawNode_,
    IM::EDrawNodeType drawNodeType_ )
{
    if ( IM::DrawNodesGet() == nullptr )
    {
        return;
    }

    if ( !IM::DrawNodesGet()->Add( pDrawNode_, drawNodeType_ ) )
    {
        delete pDrawNode_;
    }
}


// =================================================================================================
// Removes all draw nodes and make sure any memory associated to it is freed.
//
// Parameter: drawNodeName_ : Draw node's name
// -------------------------------------------------------------------------------------------------
static void DrawNodesRemoveOne( const IM::CWString& drawNodeName_ )
{
    if ( IM::DrawNodesGet() == nullptr )
    {
        return;
    }

    IM::IDrawNode* pDrawNode = IM::DrawNodesGet()->Remove( drawNodeName_ );
    if ( pDrawNode != nullptr )
    {
        delete pDrawNode;
    }
}


// =================================================================================================
// Remove all draw nodes potentially added previously from the host application draw nodes
// collection.
// -------------------------------------------------------------------------------------------------
void DrawNodesRemoveAll()
{
    DrawNodesRemoveOne( _drawNodeNamePolyline2D    );
    DrawNodesRemoveOne( _drawNodeNamePolyline2DXOR );
    DrawNodesRemoveOne( _drawNodeNamePolyline3D    );
    DrawNodesRemoveOne( _drawNodeNamePolyline3DXOR );
    DrawNodesRemoveOne( _drawNodeNamePoints        );
    DrawNodesRemoveOne( _drawNodeNamePointsXOR     );
    DrawNodesRemoveOne( _drawNodeNameTriangles     );
    DrawNodesRemoveOne( _drawNodeNameText          );
}


// =================================================================================================
// Commands constructor. This constructor is only called one time when the command is registered to
// the application.
//
// Parameter: info_ : Parameters necessary to build the commmand.
// -------------------------------------------------------------------------------------------------
CCmdCompanyName3DSceneRenderingStart::CCmdCompanyName3DSceneRenderingStart( CComCommandInfo& info_ )
: CComCommand( info_ )
{
}


// =================================================================================================
// Destructor.
// -------------------------------------------------------------------------------------------------
CCmdCompanyName3DSceneRenderingStart::~CCmdCompanyName3DSceneRenderingStart()
{
}


// =================================================================================================
// Starts drawing into the 3D Scene.
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyName3DSceneRenderingStart::Execute2(
    /* [in] */ IIMCommandArgumentEnum*,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    // Add some draw nodes to the host application's draw nodes. Note the last parameters.
    // It is very important that you specify the right draw node type.
    DrawNodeAddOne( new CDrawNodePoints(     _drawNodeNamePoints,        IM::CPoint2D( 0, 4 ) ), IM::E_DRAW_NODE_TYPE_3D  );
    DrawNodeAddOne( new CDrawNodePoints(     _drawNodeNamePointsXOR,     IM::CPoint2D( 4, 4 ) ), IM::E_DRAW_NODE_TYPE_XOR );
    DrawNodeAddOne( new CDrawNodePolyline2D( _drawNodeNamePolyline2D,    10                   ), IM::E_DRAW_NODE_TYPE_2D  );
    DrawNodeAddOne( new CDrawNodePolyline2D( _drawNodeNamePolyline2DXOR, 5                    ), IM::E_DRAW_NODE_TYPE_XOR );
    DrawNodeAddOne( new CDrawNodePolyline3D( _drawNodeNamePolyline3D,    IM::CPoint2D( 0, 0 ) ), IM::E_DRAW_NODE_TYPE_3D  );
    DrawNodeAddOne( new CDrawNodePolyline3D( _drawNodeNamePolyline3DXOR, IM::CPoint2D( 4, 0 ) ), IM::E_DRAW_NODE_TYPE_XOR );
    DrawNodeAddOne( new CDrawNodeText(       _drawNodeNameText,          _drawText            ), IM::E_DRAW_NODE_TYPE_2D  );
    DrawNodeAddOne( new CDrawNodeTriangles(  _drawNodeNameTriangles,     IM::CPoint2D( 2, 2 ) ), IM::E_DRAW_NODE_TYPE_3D  );

    // Creation of a floating annotation
    if ( _pFloatingAnnotation == nullptr )
    {
        IM::Create( _pFloatingAnnotation );
        if ( _pFloatingAnnotation != nullptr )
        {
            _pFloatingAnnotation->ColorSet( IM::CColorRGBA( 0, 128, 255, 255 ) );
            _pFloatingAnnotation->PositionSet( IM::CPoint2D( 0.1, 0.1 ) );
            _pFloatingAnnotation->TextSet( L"PolyWorks SDK\nFloating Annotation" );
            _pFloatingAnnotation->VisibleSet( true );
        }
    }

    // Creation of anchored annotation
    if ( _pAnchoredAnnotation == nullptr )
    {
        IM::Create( _pAnchoredAnnotation );
        if ( _pAnchoredAnnotation != nullptr )
        {
            _pAnchoredAnnotation->AnchorPointSet( IM::CPoint( 0.0, 0.0, 0.0 ) );
            _pAnchoredAnnotation->ColorSet( IM::CColorRGBA( 0, 128, 0, 255 ) );
            _pAnchoredAnnotation->TextSet( L"PolyWorks SDK\nAnchored Annotation" );
            _pAnchoredAnnotation->VisibleSet( true );
        }
    }

    *pReturnCode_ = E_CMD_SUCCEEDED;

    return S_OK;
}


// =================================================================================================
// Commands constructor. This constructor is only called one time when the command is registered to
// the application.
//
// Parameter: info_ : Parameters necessary to build the commmand.
// -------------------------------------------------------------------------------------------------
CCmdCompanyName3DSceneRenderingStop::CCmdCompanyName3DSceneRenderingStop( CComCommandInfo& info_ )
: CComCommand( info_ )
{
}


// =================================================================================================
// Destructor.
// -------------------------------------------------------------------------------------------------
CCmdCompanyName3DSceneRenderingStop::~CCmdCompanyName3DSceneRenderingStop()
{
}


// =================================================================================================
// Stops drawing in the 3D Scene
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyName3DSceneRenderingStop::Execute2(
    /* [in] */ IIMCommandArgumentEnum*,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    // Remove all annotations
    AnnotationsRemoveAll();

    // Remove all draw nodes
    DrawNodesRemoveAll();

    *pReturnCode_ = E_CMD_SUCCEEDED;

    return S_OK;
}
