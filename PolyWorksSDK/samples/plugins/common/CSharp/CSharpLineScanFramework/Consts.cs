// =================================================================================================
//   Some constant values used throughout the plug-in.
//
// Copyright © InnovMetric Software Inc. 2018 All Rights Reserved
// -------------------------------------------------------------------------------------------------

namespace CompanyNameCsLineScanner
{

class Consts
{
    // TODO : Change this name to an appropriate name for your plug-in.
    //        This name is not visible to the user and is only used as a key to store
    //        information.
    // Make sure your plug-in name does not exceed 31 characters
    public const string PLUGIN_NAME = "CompanyName CSharpLineScanner";

    // Commands
    public const string CMD_GET_SUFFIX                            = " GET";

    public const string CMD_SCAN_END                              = "DIGITIZE DEVICE SCAN END";
    public const string CMD_SCAN_TYPE                             = "DIGITIZE DEVICE SCAN TYPE";
    public const string CMD_SCAN_BOUNDARY_OBJECT_NAME             = "DIGITIZE DEVICE SCAN BOUNDARY DATA_OBJECT NAME";
    public const string CMD_SCAN_SURFACE_OBJECT_NAME              = "DIGITIZE DEVICE SCAN SURFACE DATA_OBJECT NAME";

    public const string CMD_AUTO_VIEWPOINT_SET                    = "DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT";
    public const string CMD_AUTO_VIEWPOINT_VERTICAL_AXIS_SET      = "DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT DEVICE_VERTICAL_AXIS";
    public const string CMD_AUTO_VIEWPOINT_CLOSEUP_ZOOM_SET       = "DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT CLOSE_UP SCAN_LINE_ZOOM";
    public const string CMD_DIGITIZE_LINESCAN_SURFACE_RTQM_SET    = "DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING";
    public const string CMD_DIGITIZE_LINESCAN_SURFACE_RTQM_GET    = "DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING GET";
    public const string CMD_RTQM_DATA_TYPE                        = "DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING FINAL_DATA_OBJECT DATA_TYPE";
    public const string CMD_EXTRACT_NORMAL_VECTORS                = "DIGITIZE DEVICE SCAN SURFACE EXTRACT_NORMAL_VECTORS";
    public const string CMD_EXTRACT_NORMALS_MIN_DISTANCE          = "DIGITIZE DEVICE SCAN SURFACE EXTRACT_NORMAL_VECTORS MIN_SEARCH_DISTANCE";
    public const string CMD_EXTRACT_NORMALS_MAX_DISTANCE          = "DIGITIZE DEVICE SCAN SURFACE EXTRACT_NORMAL_VECTORS MAX_SEARCH_DISTANCE";
    public const string CMD_CLIPPING_PLANE                        = "DIGITIZE LINE_SCAN SURFACE CLIPPING_PLANE";

    public const string CMD_SCAN_BOUNDARY_MIN_EDGE_ANGLE          = "DIGITIZE DEVICE COMPANY_NAME_CSHARP SCAN BOUNDARY MIN_EDGE_ANGLE";
    public const string CMD_SCAN_BOUNDARY_MAX_POINT_TO_POINT_DIST = "DIGITIZE DEVICE COMPANY_NAME_CSHARP SCAN BOUNDARY MAX_POINT_TO_POINT_DIST";
};

}
