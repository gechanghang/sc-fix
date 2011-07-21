/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of COOLSAND Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("COOLSAND SOFTWARE")
*  RECEIVED FROM COOLSAND AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. COOLSAND EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES COOLSAND PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE COOLSAND SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. COOLSAND SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY COOLSAND SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND COOLSAND'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE COOLSAND SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT COOLSAND'S OPTION, TO REVISE OR REPLACE THE COOLSAND SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  COOLSAND FOR SUCH COOLSAND SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *	 PhotoEditor.c
 *
 * Project:
 * --------
 
 *
 * Description:
 * ------------
 *  PhotoEditor Header
 *
 * Author:
 * -------
 * -------
 *                      
 *============================================================================
 *             HISTORY
 
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 
 *============================================================================
 ****************************************************************************/
#ifndef _PHOTOEDITOR_IMG_H_
#define _PHOTOEDITOR_IMG_H_



/***************************************************************************** 
* Image ID
*****************************************************************************/
typedef enum {

	/************* Photo Editor **************/
	IMG_ID_PHOEDT_APP_ICON = PHOEDT_BASE+1,

	
	/************* Photo Art **************/
	IMG_ID_PHOART_APP_ICON,  //41602
	IMG_ID_PHOART_OPTION_ARROW,		//41603 /* arrow to notify user to start from "Option" */

	IMG_ID_PHOART_FRAME_START,
	IMG_ID_PHOART_FRAME_1,
	IMG_ID_PHOART_FRAME_2,
	IMG_ID_PHOART_FRAME_3,
	IMG_ID_PHOART_FRAME_4,
	IMG_ID_PHOART_FRAME_5,
	IMG_ID_PHOART_FRAME_6,  //41610
	IMG_ID_PHOART_FRAME_7,
	IMG_ID_PHOART_FRAME_8,
	IMG_ID_PHOART_FRAME_9,
	IMG_ID_PHOART_FRAME_10,

	IMG_ID_PHOART_ICON_START,  //41615
	IMG_ID_PHOART_ICON_1,
	IMG_ID_PHOART_ICON_2,
	IMG_ID_PHOART_ICON_3,
	IMG_ID_PHOART_ICON_4,
	IMG_ID_PHOART_ICON_5,
	IMG_ID_PHOART_ICON_6,
	IMG_ID_PHOART_ICON_7,
	IMG_ID_PHOART_ICON_8,
	IMG_ID_PHOART_ICON_9,
	IMG_ID_PHOART_ICON_10,
	IMG_ID_PHOART_ICON_11,
	IMG_ID_PHOART_ICON_12,
	IMG_ID_PHOART_ICON_13,
	IMG_ID_PHOART_ICON_14,
	IMG_ID_PHOART_ICON_15,
	IMG_ID_PHOART_ICON_16,
	IMG_ID_PHOART_ICON_17,
	IMG_ID_PHOART_ICON_18,  //41633

	IMG_ID_PHOART_TEXT_TEXT_COLOR,
	IMG_ID_PHOART_TEXT_BORDER_COLOR,
	IMG_ID_PHOART_TEXT_SHADOW_COLOR,
	IMG_ID_PHOART_TEXT_SIZE,
	IMG_ID_PHOART_TEXT_ITALIC,

	IMG_ID_PHOART_ADJUST_IMAGE_START,
	IMG_ID_PHOART_ADJUST_BRIGHTNESS,
	IMG_ID_PHOART_ADJUST_CONTRAST,
	IMG_ID_PHOART_ADJUST_SATURATION,		
	IMG_ID_PHOART_ADJUST_HUE,
	
	IMG_ID_PHOART_ADJUST_COLOR_START,	
	IMG_ID_PHOART_ADJUST_COLOR_R,
	IMG_ID_PHOART_ADJUST_COLOR_G,
	IMG_ID_PHOART_ADJUST_COLOR_B,	

	IMG_ID_PHOART_ADJUST_IMAGE_HILIGHT_START,
	IMG_ID_PHOART_ADJUST_BRIGHTNESS_HILIGHT,
	IMG_ID_PHOART_ADJUST_CONTRAST_HILIGHT,
	IMG_ID_PHOART_ADJUST_SATURATION_HILIGHT,
	IMG_ID_PHOART_ADJUST_HUE_HILIGHT,	

	IMG_ID_PHOART_ADJUST_COLOR_HILIGHT_START,
	IMG_ID_PHOART_ADJUST_COLOR_R_HILIGHT,
	IMG_ID_PHOART_ADJUST_COLOR_G_HILIGHT,
	IMG_ID_PHOART_ADJUST_COLOR_B_HILIGHT,	
	
	IMG_ID_PHOART_ADJUST_SLIDER,
	IMG_ID_PHOART_ADJUST_BAR,


	/************* Scene Master **************/
	IMG_ID_SCENMAST_APP,

	
	/************* Image Tile **************/	
	IMG_ID_IMGTILE_APP,

	
	/************* Slide Show **************/	
	IMG_ID_SLIDSHOW_APP
	
} phoedt_img_id_enum;




#endif /* _PHOTOEDITOR_IMG_H_ */


