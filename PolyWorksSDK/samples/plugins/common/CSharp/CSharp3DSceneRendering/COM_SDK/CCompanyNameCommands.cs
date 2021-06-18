// =================================================================================================
// Plug-in's commands.
//
// Copyright © InnovMetric Logiciels Inc. 2012 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace CSharp3DSceneRendering
{
    public static class Constants
    {
        // TODO: Change CompanyName for your company name because draw node names must be unique
        public static string _drawNodeNamePolyline2D = "CompanyNameDrawNodePolyline2D";
        public static string _drawNodeNamePolyline2DXOR = "CompanyNameDrawNodePolyline2DXOR";
        public static string _drawNodeNamePolyline3D = "CompanyNameDrawNodePolyline3D";
        public static string _drawNodeNamePolyline3DXOR = "CompanyNameDrawNodePolyline3DXOR";
        public static string _drawNodeNamePoints = "CompanyNameDrawNodePoints";
        public static string _drawNodeNamePointsXOR = "CompanyNameDrawNodePointsXOR";
        public static string _drawNodeNameTriangles = "CompanyNameDrawNodeTriangles";
        public static string _drawNodeNameText = "CompanyNameDrawNodeText";
        public static string _drawText = "PolyWorks SDK 3D Scene Rendering Sample";
        public static IMM.IAnnotation _pAnchoredAnnotation = null;
        public static IMM.IAnnotation _pFloatingAnnotation = null;
    }

    // =================================================================================================
    // MSCL command drawing in the 3D Scene.
    //
    // TODO: Rename CompanyNameAction with your company name.
    // -------------------------------------------------------------------------------------------------
    public class CCmdCompanyName3DSceneRenderingStart : IM.CComCommand
    {
        // =================================================================================================
        // Commands constructor. 
        // This constructor is only called one time when the command is registered to the application.
        //
        // Parameter: info_ : Parameters necessary to build the command.
        // -------------------------------------------------------------------------------------------------
        public CCmdCompanyName3DSceneRenderingStart(IM.CComCommandInfo info_)
            : base(info_)
        { 
        }

        // =================================================================================================
        // Starts drawing into the 3D Scene.
        //
        // Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
        //
        // Return: COM error code.
        // -------------------------------------------------------------------------------------------------
        public override IMPluginLib.ECommandReturnCodes Execute2(IMPluginLib.IIMCommandArgumentEnum iIMCommandArgumentEnum_)
        {
            // Add some draw nodes to the host application's draw nodes. 
            // Note the last parameters. 
            // It is very important that you specify the right draw node type.
            Functions.DrawNodeAddOne(new CDrawNodePoints(Constants._drawNodeNamePoints, new IMM.CPoint2D(0, 4)), IMM.DrawNodeTypes.EDrawNodeType.E_DRAW_NODE_TYPE_3D);
            Functions.DrawNodeAddOne(new CDrawNodePoints(Constants._drawNodeNamePointsXOR, new IMM.CPoint2D(4, 4)), IMM.DrawNodeTypes.EDrawNodeType.E_DRAW_NODE_TYPE_XOR);
            Functions.DrawNodeAddOne(new CDrawNodePolyline2D(Constants._drawNodeNamePolyline2D, 10), IMM.DrawNodeTypes.EDrawNodeType.E_DRAW_NODE_TYPE_2D);
            Functions.DrawNodeAddOne(new CDrawNodePolyline2D(Constants._drawNodeNamePolyline2DXOR, 5), IMM.DrawNodeTypes.EDrawNodeType.E_DRAW_NODE_TYPE_XOR);
            Functions.DrawNodeAddOne(new CDrawNodePolyline3D(Constants._drawNodeNamePolyline3D, new IMM.CPoint2D(0, 0)), IMM.DrawNodeTypes.EDrawNodeType.E_DRAW_NODE_TYPE_3D);
            Functions.DrawNodeAddOne(new CDrawNodePolyline3D(Constants._drawNodeNamePolyline3DXOR, new IMM.CPoint2D(4, 0)), IMM.DrawNodeTypes.EDrawNodeType.E_DRAW_NODE_TYPE_XOR);
            Functions.DrawNodeAddOne(new CDrawNodeText(Constants._drawNodeNameText, Constants._drawText), IMM.DrawNodeTypes.EDrawNodeType.E_DRAW_NODE_TYPE_2D);
            Functions.DrawNodeAddOne(new CDrawNodeTriangles(Constants._drawNodeNameTriangles, new IMM.CPoint2D(2, 2)), IMM.DrawNodeTypes.EDrawNodeType.E_DRAW_NODE_TYPE_3D);

            // Creation of a floating annotation
            if (Constants._pFloatingAnnotation == null)
            {
                IMM.FnIAnnotation.Create(out Constants._pFloatingAnnotation);
                if (Constants._pFloatingAnnotation != null)
                {
                    Constants._pFloatingAnnotation.ColorSet(new IMM.CColorRGBA(0, 128, 255, 255));
                    Constants._pFloatingAnnotation.PositionSet(new IMM.CPoint2D(0.1, 0.1));
                    Constants._pFloatingAnnotation.TextSet("PolyWorks SDK\nFloating Annotation");
                    Constants._pFloatingAnnotation.VisibleSet(true);
                }
            }

            // Creation of anchored annotation
            if (Constants._pAnchoredAnnotation == null)
            {
                IMM.FnIAnnotation.Create(out Constants._pAnchoredAnnotation);
                if (Constants._pAnchoredAnnotation != null)
                {
                    Constants._pAnchoredAnnotation.AnchorPointSet(new IMM.CPoint(0.0, 0.0, 0.0));
                    Constants._pAnchoredAnnotation.ColorSet(new IMM.CColorRGBA(0, 128, 0, 255));
                    Constants._pAnchoredAnnotation.TextSet("PolyWorks SDK\nAnchored Annotation");
                    Constants._pAnchoredAnnotation.VisibleSet(true);
                }
            }

            return IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED;
        }
    }

    // =================================================================================================
    // MSCL command removing any drawing in the 3D Scene created by 
    // CCmdCompanyName3DSceneRenderingStart.
    //
    // TODO: Rename CompanyNameAction with your company name.
    // -------------------------------------------------------------------------------------------------
    public class CCmdCompanyName3DSceneRenderingStop : IM.CComCommand
    {
        // =================================================================================================
        // Commands constructor. 
        // This constructor is only called one time when the command is registered to the application.
        //
        // Parameter: info_ : Parameters necessary to build the command.
        // -------------------------------------------------------------------------------------------------
        public CCmdCompanyName3DSceneRenderingStop(IM.CComCommandInfo info_)
            : base(info_)
        { 
        }

        // =================================================================================================
        // Stops drawing in the 3D Scene
        //
        // Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
        //
        // Return: COM error code.
        // -------------------------------------------------------------------------------------------------
        public override IMPluginLib.ECommandReturnCodes Execute2(IMPluginLib.IIMCommandArgumentEnum iIMCommandArgumentEnum_)
        {
            // Remove all annotations
            Functions.AnnotationsRemoveAll();

            // Remove all draw nodes
            Functions.DrawNodesRemoveAll();

            return IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED;
        }
    }

    public static class Functions
    {
        // =================================================================================================
        // Remove one given annotation from the 3D Scene and free up any memory associated to it.
        //
        // Parameter: pAnnotation_ : Reference to a pointer to an annotation.
        // -------------------------------------------------------------------------------------------------
        public static void AnnotationsRemoveOne(ref IMM.IAnnotation pAnnotation_)
        {
            if (pAnnotation_ != null)
            {
                IMM.FnIAnnotation.Destroy(pAnnotation_);
                pAnnotation_ = null;
            }
        }

        // =================================================================================================
        // Removes all annotations from the 3D Scene.
        // -------------------------------------------------------------------------------------------------
        public static void AnnotationsRemoveAll()
        {
            AnnotationsRemoveOne(ref Constants._pAnchoredAnnotation);
            AnnotationsRemoveOne(ref Constants._pFloatingAnnotation);
        }

        // =================================================================================================
        // Adds (if possible) a draw node to the applications draw node collection. 
        // If the operation fails, the draw nodes memory is freed.
        //
        // Parameter: pDrawNode_    : Pointer to a draw node
        // Parameter: drawNodeType_ : Draw node type
        // -------------------------------------------------------------------------------------------------
        public static void DrawNodeAddOne(IMM.IDrawNode pDrawNode_,
                                          IMM.DrawNodeTypes.EDrawNodeType drawNodeType_)
        {
            if (IMM.FnIDrawNodes.DrawNodesGet() == null)
            {
                return;
            }

            if (!IMM.FnIDrawNodes.DrawNodesGet().Add(pDrawNode_, drawNodeType_))
            {
                pDrawNode_.Dispose();
            }
        }

        // =================================================================================================
        // Removes all draw nodes and make sure any memory associated to it is freed.
        //
        // Parameter: drawNodeName_ : Draw node's name
        // -------------------------------------------------------------------------------------------------
        public static void DrawNodesRemoveOne(string drawNodeName_)
        {
            if (IMM.FnIDrawNodes.DrawNodesGet() == null)
            {
                return;
            }

            IMM.IDrawNode pDrawNode = IMM.FnIDrawNodes.DrawNodesGet().Remove(drawNodeName_);

            if (pDrawNode != null)
            {
                pDrawNode.Dispose();
            }
        }

        // =================================================================================================
        // Remove all draw nodes potentially added previously from the host application draw nodes 
        // collection.
        // -------------------------------------------------------------------------------------------------
        public static void DrawNodesRemoveAll()
        {
            DrawNodesRemoveOne(Constants._drawNodeNamePolyline2D);
            DrawNodesRemoveOne(Constants._drawNodeNamePolyline2DXOR);
            DrawNodesRemoveOne(Constants._drawNodeNamePolyline3D);
            DrawNodesRemoveOne(Constants._drawNodeNamePolyline3DXOR);
            DrawNodesRemoveOne(Constants._drawNodeNamePoints);
            DrawNodesRemoveOne(Constants._drawNodeNamePointsXOR);
            DrawNodesRemoveOne(Constants._drawNodeNameTriangles);
            DrawNodesRemoveOne(Constants._drawNodeNameText);
        }
    }
}
