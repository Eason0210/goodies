/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IMTypes.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data
    VC __declspec() decoration level:
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
 */
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __IMTypes_h__
#define __IMTypes_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif


/* interface __MIDL_itf_IMTypes_0000_0000 */
/* [local] */

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "CCE0EEA5-855A-44ad-8A8E-F32541B35868" )
enum ECharacterSets
{
    E_CHARSET_WESTERN_ALPHABET          = 0,
    E_CHARSET_DEFAULT                   = 1,
    E_CHARSET_JAPANESE_SHIFT_JIS        = 128,
    E_CHARSET_KOREAN_HANGEUL            = 129,
    E_CHARSET_KOREAN_JOHAB              = 130,
    E_CHARSET_CHINESE_SIMPLIFIED_GB2312 = 134,
    E_CHARSET_CHINESE_TRADITIONAL_BIG5  = 136,
    E_CHARSET_GREEK_ALPHABET            = 161,
    E_CHARSET_TURKISH_ALPHABET          = 162,
    E_CHARSET_VIETNAMESE                = 163,
    E_CHARSET_HEBREW_ALPHABET           = 177,
    E_CHARSET_ARABIC_ALPHABET           = 178,
    E_CHARSET_BALTIC_ALPHABET           = 186,
    E_CHARSET_CYRILLIC_ALPHABET         = 204,
    E_CHARSET_THAI                      = 222,
    E_CHARSET_CENTRAL_EUROPE_ALPHABET   = 238
}   ECharacterSets;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "89A193ED-4CF8-4707-A557-F1686B563C77" )
enum ECompensationMethods
{
    E_FIRST_COMPENSATION_METHOD               = 0x1,
    E_COMPENSATION_METHOD_FIRST_POINT_VECTOR  = E_FIRST_COMPENSATION_METHOD,
    E_COMPENSATION_METHOD_LAST_POINT_POSITION = 0x2,
    E_COMPENSATION_METHOD_APPROACH_DIRECTION  = 0x3,
    E_LAST_COMPENSATION_METHOD                = E_COMPENSATION_METHOD_APPROACH_DIRECTION
}   ECompensationMethods;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "E652A597-71D9-4305-A4FF-DC9EAFE21DDC" )
enum EDigitizingVectorDirections
{
    E_DIGITIZING_VECTOR_DIRECTION_SCANNER_TO_OBJECT = 0x1,
    E_DIGITIZING_VECTOR_DIRECTION_OBJECT_TO_SCANNER = 0x2
}   EDigitizingVectorDirections;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "CA5A7863-8730-4cdd-9697-8F5ED1EC6189" )
enum EMeasurementStartResult
{
    E_MEASUREMENT_START_FAILED                     = 0,
    E_MEASUREMENT_START_STARTED_CONTINUOUS_MEASURE = 1,
    E_MEASUREMENT_START_COMPLETED_SINGLE_MEASURE   = 2
}   EMeasurementStartResult;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "8B4A6ED7-970F-4617-A6FE-6FF4B298CE36" )
enum EParameterDirection
{
    E_PARAM_DIR_IN  = 0x1,
    E_PARAM_DIR_OUT = 0x2
}   EParameterDirection;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "76D83783-5D33-4808-A5CE-1D8AA3108CF8" )
enum EParameterType
{
    E_PARAM_TYPE_INTEGER       = 0x1,
    E_PARAM_TYPE_DOUBLE        = 0x2,
    E_PARAM_TYPE_STRING        = 0x3,
    E_PARAM_TYPE_INTEGER_ARRAY = 0x4,
    E_PARAM_TYPE_DOUBLE_ARRAY  = 0x5,
    E_PARAM_TYPE_STRING_ARRAY  = 0x6,
    E_PARAM_TYPE_ANY_ARRAY     = 0x7
}   EParameterType;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "D08FB674-035C-46ea-94BC-2B56AE11FC7F" )
enum EArgumentValueType
{
    E_ARG_VALUE_TYPE_INTEGER = 0x1,
    E_ARG_VALUE_TYPE_DOUBLE  = 0x2,
    E_ARG_VALUE_TYPE_STRING  = 0x3
}   EArgumentValueType;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "85D83066-664D-4d2b-93F1-5FDC33FB84C2" )
enum ECommandReturnCodes
{
    E_CMD_FIRST_RETURN_CODE         = 0,
    E_CMD_SUCCEEDED                 = E_CMD_FIRST_RETURN_CODE,
    E_CMD_FAILED                    = ( E_CMD_SUCCEEDED + 1 ),
    E_CMD_CANCELLED                 = ( E_CMD_FAILED + 1 ),
    E_CMD_ARG_INVALID_INDEX         = ( E_CMD_CANCELLED + 1 ),
    E_CMD_ARG_INVALID_STRING        = ( E_CMD_ARG_INVALID_INDEX + 1 ),
    E_CMD_ARG_OUT_OF_RANGE          = ( E_CMD_ARG_INVALID_STRING + 1 ),
    E_CMD_CONSTRAINTS_NOT_RESPECTED = ( E_CMD_ARG_OUT_OF_RANGE + 1 ),
    E_CMD_LAST_RETURN_CODE          = E_CMD_CONSTRAINTS_NOT_RESPECTED
}   ECommandReturnCodes;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "07CA9788-A781-4070-A26E-0EFE3B493B4F" )
enum EDeviceStatus
{
    E_DEVICE_FIRST_STATUS        = 0,
    E_DEVICE_STATUS_READY        = E_DEVICE_FIRST_STATUS,
    E_DEVICE_STATUS_BUSY         = ( E_DEVICE_STATUS_READY + 1 ),
    E_DEVICE_STATUS_NOT_READY    = ( E_DEVICE_STATUS_BUSY + 1 ),
    E_DEVICE_STATUS_INACCURATE   = ( E_DEVICE_STATUS_NOT_READY + 1 ),
    E_DEVICE_STATUS_ENGAGED      = ( E_DEVICE_STATUS_INACCURATE + 1 ),
    E_DEVICE_STATUS_INITIALIZING = ( E_DEVICE_STATUS_ENGAGED + 1 ),
    E_DEVICE_STATUS_WARNING      = ( E_DEVICE_STATUS_INITIALIZING + 1 ),
    E_DEVICE_LAST_STATUS         = E_DEVICE_STATUS_WARNING
}   EDeviceStatus;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "0B41013C-8267-4A56-856A-76B46EFD530D" )
enum ERotationDirection
{
    E_ROTATION_DIRECTION_CLOCKWISE        = 0x1,
    E_ROTATION_DIRECTION_COUNTERCLOCKWISE = 0x2
}   ERotationDirection;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "98614680-9C55-46D2-81BE-981EC5969CAC" )
enum ERotaryTableCommandStatus
{
    E_ROTARY_TABLE_COMMAND_STATUS_SUCCEEDED = 0x1,
    E_ROTARY_TABLE_COMMAND_STATUS_FAILED    = 0x2,
    E_ROTARY_TABLE_COMMAND_STATUS_ABORTED   = 0x3
}   ERotaryTableCommandStatus;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "8D914901-5968-498c-80C8-3B62AB16ED9C" )
enum EProbeTypes
{
    E_PROBE_TYPE_UNDEFINED = 0,
    E_PROBE_TYPE_FIRST     = 0x1,
    E_PROBE_TYPE_PROBE     = E_PROBE_TYPE_FIRST,
    E_PROBE_TYPE_REFLECTOR = 0x2,
    E_PROBE_TYPE_NB        = E_PROBE_TYPE_REFLECTOR
}   EProbeTypes;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "D51A45E0-E7D4-4ee4-805A-F56BBF202CE7" )
enum EButtonEvents
{
    E_BUTTON_EVENT_PRESSED  = 0,
    E_BUTTON_EVENT_RELEASED = ( E_BUTTON_EVENT_PRESSED + 1 )
}   EButtonEvents;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "B3A889D2-79FE-4935-9046-D51C1E2B3B89" )
enum EProbingModeTypes
{
    E_PROBING_MODE_TYPE_UNDEFINED           = 0,
    E_FIRST_PROBING_MODE_TYPE               = 0x1,
    E_PROBING_MODE_TYPE_SINGLE              = E_FIRST_PROBING_MODE_TYPE,
    E_PROBING_MODE_TYPE_CONTINUOUS_TIME     = 0x2,
    E_PROBING_MODE_TYPE_CONTINUOUS_DISTANCE = 0x3,
    E_PROBING_MODE_TYPE_SINGLE_DIRECTION    = 0x4,
    E_LAST_PROBING_MODE_TYPE                = E_PROBING_MODE_TYPE_SINGLE_DIRECTION
}   EProbingModeTypes;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "FD30C36F-DBA9-4fe1-AD6D-D14E3E46CBE0" )
enum EEnvironmentalParametersSources
{
    E_FIRST_ENV_PARAMS_SOURCE  = 0,
    E_ENV_PARAMS_SOURCE_DEVICE = E_FIRST_ENV_PARAMS_SOURCE,
    E_ENV_PARAMS_SOURCE_USER   = 0x1,
    E_LAST_ENV_PARAMS_SOURCE   = E_ENV_PARAMS_SOURCE_USER
}   EEnvironmentalParametersSources;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "31A13144-B021-4dcf-BB52-BAB19DFDBEBA" )
enum ELevelAngleStatus
{
    E_FIRST_LEVEL_ANGLE_STATUS         = 0,
    E_LEVEL_ANGLE_STATUS_OK            = E_FIRST_LEVEL_ANGLE_STATUS,
    E_LEVEL_ANGLE_STATUS_INACCURATE    = 0x1,
    E_LEVEL_ANGLE_STATUS_OUT_OF_RANGE  = 0x2,
    E_LEVEL_ANGLE_STATUS_NOT_AVAILABLE = 0x3,
    E_LAST_LEVEL_ANGLE_STATUS          = E_LEVEL_ANGLE_STATUS_NOT_AVAILABLE
}   ELevelAngleStatus;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "B04133D4-AC1F-4ee6-88C6-AD100A12FFAD" )
enum EPowerSources
{
    E_FIRST_POWER_SOURCE           = 0,
    E_POWER_SOURCE_BATTERY         = E_FIRST_POWER_SOURCE,
    E_POWER_SOURCE_AC              = ( E_POWER_SOURCE_BATTERY + 1 ),
    E_POWER_SOURCE_BATTERY_PROBLEM = ( E_POWER_SOURCE_AC + 1 ),
    E_LAST_POWER_SOURCE            = E_POWER_SOURCE_BATTERY_PROBLEM
}   EPowerSources;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "75E2AA65-9118-4d0b-B4D1-73F748A0CC01" )
enum ELevelCompensationStatus
{
    E_FIRST_LEVEL_COMPENSATION_STATUS        = 0,
    E_LEVEL_COMPENSATION_STATUS_OK           = E_FIRST_LEVEL_COMPENSATION_STATUS,
    E_LEVEL_COMPENSATION_STATUS_OUT_OF_RANGE = ( E_LEVEL_COMPENSATION_STATUS_OK + 1 ),
    E_LAST_LEVEL_COMPENSATION_STATUS         = E_LEVEL_COMPENSATION_STATUS_OUT_OF_RANGE
}   ELevelCompensationStatus;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "8C514E27-B1A9-4300-A576-C78248F833CC" )
enum ECoordinateSystem
{
    E_COORDINATE_SYSTEM_DEVICE_RAW = 0,
    E_COORDINATE_SYSTEM_PROJECT    = 0x1
}   ECoordinateSystem;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "0ED1AD4F-5569-4d0f-9EF7-8FDDD590D766" )
enum EPointCloudType
{
    E_FIRST_POINT_CLOUD_TYPE = 0,
    E_POINT_CLOUD_SURFACE    = E_FIRST_POINT_CLOUD_TYPE,
    E_POINT_CLOUD_BOUNDARY   = ( E_POINT_CLOUD_SURFACE + 1 ),
    E_LAST_POINT_CLOUD_TYPE  = E_POINT_CLOUD_BOUNDARY
}   EPointCloudType;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "7AFED9D6-4647-489c-93D7-C155F88668DF" )
enum EMessageTypes
{
    E_MESSAGE_TYPE_CONFIRMATION         = 0,
    E_MESSAGE_TYPE_ERROR                = ( E_MESSAGE_TYPE_CONFIRMATION + 1 ),
    E_MESSAGE_TYPE_INFORMATION          = ( E_MESSAGE_TYPE_ERROR + 1 ),
    E_MESSAGE_TYPE_QUESTION             = ( E_MESSAGE_TYPE_INFORMATION + 1 ),
    E_MESSAGE_TYPE_QUESTION_YNC         = ( E_MESSAGE_TYPE_QUESTION + 1 ),
    E_MESSAGE_TYPE_QUESTION_WARNING     = ( E_MESSAGE_TYPE_QUESTION_YNC + 1 ),
    E_MESSAGE_TYPE_QUESTION_WARNING_YNC = ( E_MESSAGE_TYPE_QUESTION_WARNING + 1 ),
    E_MESSAGE_TYPE_WARNING              = ( E_MESSAGE_TYPE_QUESTION_WARNING_YNC + 1 ),
    E_MESSAGE_TYPE_QUESTION_ERROR       = ( E_MESSAGE_TYPE_WARNING + 1 ),
    E_MESSAGE_TYPE_QUESTION_ERROR_YNC   = ( E_MESSAGE_TYPE_QUESTION_ERROR + 1 )
}   EMessageTypes;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "95161254-1A35-4e41-8256-0D272568A85B" )
enum ECameraViewClickBehavior
{
    E_FIRST_CAMERA_VIEW_CLICK_BEHAVIOR = 0,
    E_CAMERA_VIEW_CLICK_GO_TO          = E_FIRST_CAMERA_VIEW_CLICK_BEHAVIOR,
    E_CAMERA_VIEW_CLICK_FIND           = 0x1,
    E_CAMERA_VIEW_CLICK_MEASURE        = 0x2,
    E_LAST_CAMERA_VIEW_CLICK_BEHAVIOR  = E_CAMERA_VIEW_CLICK_MEASURE
}   ECameraViewClickBehavior;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "50FA6DCA-01FB-43e6-B027-F87DD5336A26" )
enum EScanTypes
{
    E_FIRST_SCAN_TYPE                     = 0,
    E_SCAN_TYPE_SURFACE                   = E_FIRST_SCAN_TYPE,
    E_SCAN_TYPE_SHARP_EDGE                = 0x1,
    E_SCAN_TYPE_BOUNDARY                  = E_SCAN_TYPE_SHARP_EDGE,
    E_SCAN_TYPE_OBJECT                    = 0x2,
    E_SCAN_TYPE_SURFACE_AND_BOUNDARY      = 0x3,
    E_SCAN_TYPE_SURFACE_AND_HOLE_BOUNDARY = E_SCAN_TYPE_SURFACE_AND_BOUNDARY,
    E_LAST_SCAN_TYPE                      = E_SCAN_TYPE_SURFACE_AND_BOUNDARY
}   EScanTypes;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "37827A1D-07E5-4011-B329-50585804E728" )
enum EScanningEvents
{
    E_FIRST_SCANNING_EVENT                     = 0,
    E_SCANNING_EVENT_LEAVING_SCAN_MODE         = E_FIRST_SCANNING_EVENT,
    E_SCANNING_EVENT_DEVICE_SELECTED           = 0x1,
    E_SCANNING_EVENT_DEVICE_DESELECTED         = 0x2,
    E_SCANNING_EVENT_UPDATE_APP_SETTINGS       = 0x3,
    E_SCANNING_EVENT_APP_SETTING_MODIFIED      = 0x4,
    E_SCANNING_EVENT_POST_PROFILE_CHANGED      = 0x5,
    E_SCANNING_EVENT_DEVICE_SELECTED_FROM_USER = 0x6,
    E_LAST_SCANNING_EVENT                      = E_SCANNING_EVENT_DEVICE_SELECTED_FROM_USER
}   EScanningEvents;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "96E1BA0C-7DA4-457C-BB27-9F3B4F6D51F4" )
enum EStandardScanningProfiles
{
    E_FIRST_STD_SCAN_PROFILE          = 0,
    E_STD_SCAN_PROFILE_COARSE_RES     = E_FIRST_STD_SCAN_PROFILE,
    E_STD_SCAN_PROFILE_STANDARD_RES   = 0x1,
    E_STD_SCAN_PROFILE_FINE_RES       = 0x2,
    E_STD_SCAN_PROFILE_EXTRA_FINE_RES = 0x3,
    E_STD_SCAN_PROFILE_LARGE_STANDOFF = 0x4,
    E_LAST_STD_SCAN_PROFILE           = E_STD_SCAN_PROFILE_LARGE_STANDOFF
}   EStandardScanningProfiles;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "1B7D2F3A-6430-4C0F-813D-247FD6B9E8A7" )
enum EDeviceTypes
{
    E_DEVICE_TYPE_UNDEFINED       = 0,
    E_DEVICE_TYPE_ARM             = 0x1,
    E_DEVICE_TYPE_LASER_TRACKER   = 0x2,
    E_DEVICE_TYPE_OPTICAL_TRACKER = 0x3,
    E_DEVICE_TYPE_CMM             = 0x4
}   EDeviceTypes;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "115E1897-27E4-4825-BD00-98E6F7224207" )
enum EPWModuleTypes
{
    E_PW_MODULE_TYPE_IMALIGN   = 0,
    E_PW_MODULE_TYPE_IMEDIT    = 0x1,
    E_PW_MODULE_TYPE_IMINSPECT = 0x2,
    E_PW_MODULE_TYPE_IMVIEW    = 0x3
}   EPWModuleTypes;

typedef /* [helpstring][uuid] */ DECLSPEC_UUID( "33D4D9B6-9BB1-495D-9BB8-414F3F107180" )
enum ETransformTypes
{
    E_TRANSFORM_ROTATION_TRANSLATION = 0,
    E_TRANSFORM_MIRROR               = 0x1,
    E_TRANSFORM_SCALING              = 0x2
}   ETransformTypes;



extern RPC_IF_HANDLE __MIDL_itf_IMTypes_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IMTypes_0000_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IMTypes_h__
