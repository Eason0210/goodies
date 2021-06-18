// =================================================================================================
//   Some constant values used throughout the plug-in.
//
// Copyright © InnovMetric Software Inc. 2019 All Rights Reserved
// -------------------------------------------------------------------------------------------------

namespace CompanyNameCsPlanarScanner
{

class Consts
{
    // TODO : Change this name to an appropriate name for your plug-in.
    //        This name is not visible to the user and is only used as a key to store
    //        information.
    // Make sure your plug-in name does not exceed 31 characters
    public const string PLUGIN_NAME = "CompanyName CSharpPlanarScanner";

    // Commands
    public const string CMD_GET_SUFFIX                            = " GET";

    public const string CMD_SCAN_END                              = "DIGITIZE DEVICE SCAN END";
    public const string CMD_SCAN_TYPE                             = "DIGITIZE DEVICE SCAN TYPE";
    public const string CMD_SCAN_DEFAULT_SURFACE_OBJECT_NAME      = "CONFIG MODIFY DEFAULT_NAME SURFACE_SCAN GET";
    public const string CMD_SCAN_SURFACE_OBJECT_NAME              = "DIGITIZE DEVICE SCAN SURFACE DATA_OBJECT NAME";

    public const string CMD_AUTO_VIEWPOINT_SET                    = "DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT";
    public const string CMD_AUTO_VIEWPOINT_VERTICAL_AXIS_SET      = "DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT DEVICE_VERTICAL_AXIS";
    public const string CMD_AUTO_VIEWPOINT_CLOSEUP_ZOOM_SET       = "DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT CLOSE_UP SCAN_LINE_ZOOM";
    public const string CMD_DEVICE_POSITION_CREATE                = "ALIGN DEVICE_POSITION CREATE"; 
    public const string CMD_SCAN_SURFACE_IMAGE_NAME               = "DIGITIZE DEVICE SCAN SURFACE IMAGE NAME";

};
}
