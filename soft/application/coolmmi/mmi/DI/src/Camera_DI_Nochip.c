////////////////////////////////////////////////////////////////////////////////
//        Copyright (C) 2002-2007, Coolsand Technologies, Inc.
//                       All Rights Reserved
// 
// This source code is property of Coolsand. The information contained in this
// file is confidential. Distribution, reproduction, as well as exploitation,
// or transmisison of any content of this file is not allowed except if
// expressly permitted.Infringements result in damage claims!
//
// FILENAME: Camera_DI_Nochip.c
// 
// DESCRIPTION:
//   TODO... 
// 
// REVISION HISTORY:
//   NAME            DATE            REMAKS
//   TODO... 
//   Dingjian
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// DESIGN THOUGHT DESCRIPTOIN 
////////////////////////////////////////////////////////////////////////////////
// TODO.. 

////////////////////////////////////////////////////////////////////////////////
// DECLARE HEAD FILES
////////////////////////////////////////////////////////////////////////////////
// TODO... 
#include <cswtype.h>
#include <mmi_trace.h>
#include <ts.h>
#include "camera_di_nochip.h"


////////////////////////////////////////////////////////////////////////////////
// LOCAL FUNCTION PROTOTYPES
////////////////////////////////////////////////////////////////////////////////
// TODO.. 

////////////////////////////////////////////////////////////////////////////////
// GLOBAL VARIABLES
////////////////////////////////////////////////////////////////////////////////
// TODO... 

extern UINT32 g_DI_CaptureImageSize;
// get preview width and height for update_image update area
extern UINT16 g_sw_DI_PreviewWidth;
extern UINT16 g_sw_DI_PreviewHeight;

////////////////////////////////////////////////////////////////////////////////
// FUNCTION IMPLEMENTATION
////////////////////////////////////////////////////////////////////////////////
// TODO... 
////////////////////////////////////////////////////////////////////////////////
//	FUNCTION NAME		: cam_open
//  	PURPOSE				: set the camera mode
//	INPUT PARAMETERS	: nil
//	OUTPUT PARAMETERS	: nil
//	RETURNS				: nil
 
////////////////////////////////////////////////////////////////////////////////
VOID cam_module_power_on(VOID)
{

}
////////////////////////////////////////////////////////////////////////////////
//	FUNCTION NAME		: cam_close
//  	PURPOSE				: 
//	INPUT PARAMETERS	: nil
//	OUTPUT PARAMETERS	: nil
//	RETURNS				: nil
 
////////////////////////////////////////////////////////////////////////////////
static VOID cam_module_power_off(VOID)
{
}
////////////////////////////////////////////////////////////////////////////////
//	FUNCTION NAME		: cam_previewstart
//  	PURPOSE				: 
//	INPUT PARAMETERS	: nil
//	OUTPUT PARAMETERS	: nil
//	RETURNS				: nil
 
////////////////////////////////////////////////////////////////////////////////
static VOID cam_module_preview(ext_camera_para_struct_di* PreInfo)
{
}
////////////////////////////////////////////////////////////////////////////////
//	FUNCTION NAME		: cam_previewstop
//  	PURPOSE				: 
//	INPUT PARAMETERS	: nil
//	OUTPUT PARAMETERS	: nil
//	RETURNS				: nil
 
////////////////////////////////////////////////////////////////////////////////
static VOID exit_cam_module_preview(VOID)
{
}
////////////////////////////////////////////////////////////////////////////////
//	FUNCTION NAME		: cam_set_para
//  	PURPOSE				: 
//	INPUT PARAMETERS	: 
//                                    
//                                    
//	OUTPUT PARAMETERS	: nil
//	RETURNS				: nil
 
////////////////////////////////////////////////////////////////////////////////
static VOID cam_module_set_para(UINT8 cmd,UINT8 para)
{
}
////////////////////////////////////////////////////////////////////////////////
//	FUNCTION NAME		: cam_capture
//  	PURPOSE				: 
//	INPUT PARAMETERS	: nil
//	OUTPUT PARAMETERS	: nil
//	RETURNS				: nil
 
////////////////////////////////////////////////////////////////////////////////
static VOID cam_module_capture(ext_camera_para_struct_di* PreInfo)
{
}
////////////////////////////////////////////////////////////////////////////////
//	FUNCTION NAME		: cam_module_cmd_mapping
//  	PURPOSE				: 
//	INPUT PARAMETERS	: nil
//	OUTPUT PARAMETERS	: nil
//	RETURNS				: nil
 
////////////////////////////////////////////////////////////////////////////////
static VOID cam_module_cmd_mapping(VOID)
{
}
////////////////////////////////////////////////////////////////////////////////
//	FUNCTION NAME		: cam_module_reset_status
//  	PURPOSE				: 
//	INPUT PARAMETERS	: nil
//	OUTPUT PARAMETERS	: nil
//	RETURNS				: nil
 
////////////////////////////////////////////////////////////////////////////////
static UINT8 cam_module_reset_status(VOID)
{
    return 1;
}
////////////////////////////////////////////////////////////////////////////////
//	FUNCTION NAME		: cam_module_preview_ready_check
//  	PURPOSE				: 
//	INPUT PARAMETERS	: nil
//	OUTPUT PARAMETERS	: nil
//	RETURNS				: nil
 
////////////////////////////////////////////////////////////////////////////////
static UINT8 cam_module_preview_ready_check(VOID)
{
    return 1;
}
////////////////////////////////////////////////////////////////////////////////
//	FUNCTION NAME		: cam_module_capture_ready_check
//  	PURPOSE				: 
//	INPUT PARAMETERS	: nil
//	OUTPUT PARAMETERS	: nil
//	RETURNS				: nil
 
////////////////////////////////////////////////////////////////////////////////
static UINT32 cam_module_capture_ready_check(VOID)
{
	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//	FUNCTION NAME		: cam_module_jpeg_encode
//  	PURPOSE				: 
//	INPUT PARAMETERS	: nil
//	OUTPUT PARAMETERS	: nil
//	RETURNS				: nil
 
////////////////////////////////////////////////////////////////////////////////
static UINT32 cam_module_jpeg_encode(ext_camera_para_struct_di *ext_cam_para, BOOL back_to_preview)
{
	return 1;
}
////////////////////////////////////////////////////////////////////////////////
//	FUNCTION NAME		: cam_module_write_para
//  	PURPOSE				: 
//	INPUT PARAMETERS	: nil
//	OUTPUT PARAMETERS	: nil
//	RETURNS				: nil
 
////////////////////////////////////////////////////////////////////////////////
static VOID cam_module_write_para(UINT16 cmd, UINT16 para)
{
}
////////////////////////////////////////////////////////////////////////////////
//	FUNCTION NAME		: cam_module_read_para
//  	PURPOSE				: 
//	INPUT PARAMETERS	: nil
//	OUTPUT PARAMETERS	: nil
//	RETURNS				: nil
 
////////////////////////////////////////////////////////////////////////////////
static UINT16 cam_module_read_para(UINT16 cmd)
{
	return 1;
}
////////////////////////////////////////////////////////////////////////////////
//	FUNCTION NAME		: cam_module_frame_rate
//  	PURPOSE				: 
//	INPUT PARAMETERS	: nil
//	OUTPUT PARAMETERS	: nil
//	RETURNS				: nil
 
////////////////////////////////////////////////////////////////////////////////
static UINT8 cam_module_frame_rate(VOID)
{
	return 1;
}
////////////////////////////////////////////////////////////////////////////////
//	FUNCTION NAME		: cam_module_write_lcdfb
//  	PURPOSE				: 
//	INPUT PARAMETERS	: nil
//	OUTPUT PARAMETERS	: nil
//	RETURNS				: nil
 
////////////////////////////////////////////////////////////////////////////////
static VOID cam_module_write_lcdfb(ext_camera_para_struct_di *ext_cam_para)
{
}
////////////////////////////////////////////////////////////////////////////////
Camera_Funcs_DI Camera_Funcs_Instance_DI =
{
    cam_module_power_on,
    cam_module_cmd_mapping,
    cam_module_reset_status,
    cam_module_preview_ready_check,
    cam_module_capture_ready_check,
    cam_module_power_off,
    cam_module_preview,
    exit_cam_module_preview,
    cam_module_capture,
    cam_module_jpeg_encode,
    cam_module_set_para,
    cam_module_write_para,
    cam_module_read_para,
    cam_module_frame_rate,
    cam_module_write_lcdfb,
};
////////////////////////////////////////////////////////////////////////////////



