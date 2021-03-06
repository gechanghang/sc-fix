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

/*******************************************************************************
 * Filename:
 * ---------
 *	  VdoRecStrEnum.h
 *
 * Project:
 * --------
 
 *
 * Description:
 * ------------
 *   Video Recorder String enum.
 *
 * Author:
 * -------
 *	
 *==============================================================================
 * 				HISTORY
 
 *------------------------------------------------------------------------------
 * 
 *------------------------------------------------------------------------------
 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_VDORECSTRENUM_H
#define _MMI_VDORECSTRENUM_H

#include "mmi_features_video.h"

/***************************************************************************** 
* Define
*****************************************************************************/
/* camera setting */
#define VDOREC_WB_BASE					(VDOREC_BASE+110)
#define VDOREC_LED_HIGHLIGHT_BASE	(VDOREC_BASE+120)
#define VDOREC_EV_BASE					(VDOREC_BASE+130)
#define VDOREC_NIGHT_BASE				(VDOREC_BASE+140)
#define VDOREC_BANDING_BASE			(VDOREC_BASE+150)

#define VDOREC_VIDEO_SIZE_BASE		(VDOREC_BASE+160)
#define VDOREC_VIDEO_QTY_BASE			(VDOREC_BASE+170)
#define VDOREC_SIZE_LIMIT_BASE		(VDOREC_BASE+180)
#define VDOREC_TIME_LIMIT_BASE		(VDOREC_BASE+190)
#define VDOREC_RECORD_AUD_BASE		(VDOREC_BASE+200)
#define VDOREC_VIDEO_FORMAT_BASE		(VDOREC_BASE+210)
#define VDOREC_EFFECT_BASE				(VDOREC_BASE+220) /* reserve 30 for this */
#define VDOREC_CONTRAST_BASE				(VDOREC_BASE+250) /* add by zhangl for greenstone */

#define VDOREC_WB_ITEM_COUNT					(STR_ID_VDOREC_WB_END-STR_ID_VDOREC_WB_START-1)
#define VDOREC_LED_HIGHLIGHT_ITEM_COUNT	(STR_ID_VDOREC_LED_HIGHLIGHT_END-STR_ID_VDOREC_LED_HIGHLIGHT_START-1)
#define VDOREC_EV_ITEM_COUNT					(STR_ID_VDOREC_EV_END-STR_ID_VDOREC_EV_START-1)
#define VDOREC_NIGHT_ITEM_COUNT				(STR_ID_VDOREC_NIGHT_END-STR_ID_VDOREC_NIGHT_START-1)
#define VDOREC_BANDING_ITEM_COUNT			(STR_ID_VDOREC_BANDING_END-STR_ID_VDOREC_BANDING_START-1)

#define VDOREC_VIDEO_SIZE_ITEM_COUNT		(STR_ID_VDOREC_VIDEO_SIZE_END-STR_ID_VDOREC_VIDEO_SIZE_START-1)
#define VDOREC_VIDEO_QTY_ITEM_COUNT			(STR_ID_VDOREC_VIDEO_QTY_END-STR_ID_VDOREC_VIDEO_QTY_START-1)
#define VDOREC_SIZE_LIMIT_ITEM_COUNT		(STR_ID_VDOREC_SIZE_LIMIT_END-STR_ID_VDOREC_SIZE_LIMIT_START-1)
#define VDOREC_TIME_LIMIT_ITEM_COUNT		(STR_ID_VDOREC_TIME_LIMIT_END-STR_ID_VDOREC_TIME_LIMIT_START-1)
#define VDOREC_RECORD_AUD_ITEM_COUNT		(STR_ID_VDOREC_RECORD_AUD_END-STR_ID_VDOREC_RECORD_AUD_START-1)
#define VDOREC_VIDEO_FORMAT_ITEM_COUNT		(STR_ID_VDOREC_VIDEO_FORMAT_END-STR_ID_VDOREC_VIDEO_FORMAT_START-1)
#define VDOREC_EFFECT_ITEM_COUNT				(STR_ID_VDOREC_EFFECT_END-STR_ID_VDOREC_EFFECT_START-1)



/***************************************************************************** 
* Enum
*****************************************************************************/
/******* [Option Menu] ********/
typedef enum {
	#ifndef __VDOPLY_FEATURE_HORIZONTAL_VIEW__
		VDOREC_OPTION_TO_VDOPLY,
	#endif /* !__VDOPLY_FEATURE_HORIZONTAL_VIEW__ */
	
	#ifdef __VDOREC_FEATURE_MERGE_MENU__
		VDOREC_OPTION_CAMCODER_SETTING,
	#else
		VDOREC_OPTION_CAMCODER_SETTING,
		VDOREC_OPTION_VIDEO_SETTING,
	#endif 

	#ifdef __VDOREC_FEATURE_EFFECT__
		VDOREC_OPTION_EFFECT_SETTING,	
	#endif 

	#ifdef __VDOREC_FEATURE_SELF_RECORD__
		VDOREC_OPTION_SELF_RECORD,
	#endif 

	#ifdef __VDOREC_FEATURE_STORAGE__
		VDOREC_OPTION_STORAGE,
	#endif

	VDOREC_OPTION_RESTORE_DEFAULT,
	
	VDOREC_OPTION_ITEM_COUNT
} vdorec_option_count_enum;


/******* [CamCoder Setting] ********/
typedef enum {
	#ifdef __VDOREC_FEATURE_WB__
		VDOREC_CAMCODER_SETTING_WB,
	#endif

	#if defined(__VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__) || defined(__VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__)
		VDOREC_CAMCODER_SETTING_LED_HIGHLIGHT,
	#endif 

	#ifdef __VDOREC_FEATURE_EV__
		VDOREC_CAMCODER_SETTING_EV,
	#endif

	#ifdef __VDOREC_FEATURE_NIGHT__
		VDOREC_CAMCODER_SETTING_NIGHT,	
	#endif
	
	#ifdef __VDOREC_FEATURE_CT__
		VDOREC_CAMCODER_SETTING_CT,	
	#endif
	
	#ifdef __VDOREC_FEATURE_BANDING__
		VDOREC_CAMCODER_SETTING_BANDING,	
	#endif

	#ifdef __VDOREC_FEATURE_MERGE_MENU__
		/* merge "Video Setting" items into "CamCoder Setting" */
		#ifdef __VDOREC_FEATURE_VIDEO_QTY__
			VDOREC_VIDEO_SETTING_VIDEO_QTY,
		#endif 

		#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
			VDOREC_VIDEO_SETTING_SIZE_LIMIT,
		#endif

		#ifdef __VDOREC_FEATURE_TIME_LIMIT__
			VDOREC_VIDEO_SETTING_TIMER_LIMIT,
		#endif

		#ifdef __VDOREC_FEATURE_RECORD_AUD__
			VDOREC_VIDEO_SETTING_RECORD_AUD,
		#endif

		#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
			VDOREC_VIDEO_SETTING_VIDEO_FORMAT,
		#endif 
	#endif /* __VDOREC_FEATURE_MERGE_MENU__ */
	
	VDOREC_CAMCODER_SETTING_ITEM_COUNT
} vdorec_camcoder_setting_count_enum;
	


/******* [Video Setting] ********/
#ifndef __VDOREC_FEATURE_MERGE_MENU__

	typedef enum {

		#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
			VDOREC_VIDEO_SETTING_VIDEO_SIZE,
		#endif 

		#ifdef __VDOREC_FEATURE_VIDEO_QTY__
			VDOREC_VIDEO_SETTING_VIDEO_QTY,
		#endif 

		#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
			VDOREC_VIDEO_SETTING_SIZE_LIMIT,
		#endif

		#ifdef __VDOREC_FEATURE_TIME_LIMIT__
			VDOREC_VIDEO_SETTING_TIMER_LIMIT,
		#endif

		#ifdef __VDOREC_FEATURE_RECORD_AUD__
			VDOREC_VIDEO_SETTING_RECORD_AUD,
		#endif

		#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
			VDOREC_VIDEO_SETTING_VIDEO_FORMAT,
		#endif 

		VDOREC_VIDEO_SETTING_ITEM_COUNT
	} vdorec_video_setting_count_enum;

#endif /* __VDOREC_FEATURE_MERGE_MENU__ */

/***************************************************************************** 
* Sting ID
*****************************************************************************/
typedef enum {
	/* app */
	STR_ID_VDOREC_APP_NAME = VDOREC_BASE+1,

	/* OSD */
	STR_ID_VDOREC_PAUSE, //40502
	STR_ID_VDOREC_STOP,   //40503
	STR_ID_VDOREC_RESUME,	 //40504

	/* option menu */
	STR_ID_VDOREC_TO_VDOPLY,   //40505
	STR_ID_VDOREC_CAMCODER_SETTING,   //40506
	STR_ID_VDOREC_VIDEO_SETTING,   //40507
	STR_ID_VDOREC_EFFECT_SETTING,   //40508
	STR_ID_VDOREC_SELF_RECORD,	  //40509
	STR_ID_VDOREC_STORAGE,   //40510
	STR_ID_VDOREC_RESTORE_DEFAULT,	 //40511
	
	/* camecoder setting */
	STR_ID_VDOREC_WB, //40512  白平衡White Blance
	STR_ID_VDOREC_LED_HIGHLIGHT,  //40513  补光LED Hightlight
	STR_ID_VDOREC_EV,  //40514   曝光补偿 EV
	STR_ID_VDOREC_NIGHT,  //40515  夜拍模式Night Mode
	STR_ID_VDOREC_BANDING,  //40516  电波频率 Banding

	/* video setting */
	STR_ID_VDOREC_VIDEO_SIZE,	  //40517  
	STR_ID_VDOREC_VIDEO_QTY,  //40518 影片品质Video Quality
	STR_ID_VDOREC_SIZE_LIMIT,  //40519   文件大小限制File Size Limit
	STR_ID_VDOREC_TIME_LIMIT, //40520  录像时间限制Rec Time Limit
	STR_ID_VDOREC_RECORD_AUD,   //40521  收录音效  Record Audio
	STR_ID_VDOREC_VIDEO_FORMAT, //40522  压缩格式Encode Format

	/* storage */
	STR_ID_VDOREC_STORAGE_PHONE,  //40523
	STR_ID_VDOREC_STORAGE_MEMORY_CARD,  //40524
	/*+ zhouqin modify for dual t-flash card 20110503*/
	#if defined(DUAL_TFLASH_SUPPORT)
	STR_ID_VDOREC_STORAGE_MEMORY_SEC_CARD,
	#endif
	/*- zhouqin modify for dual t-flash card 20110503*/
	/* Notify */
	STR_ID_VDOREC_NOTIFY_DISK_FULL,  //40525
	STR_ID_VDOREC_NOTIFY_NO_MEMORY_CARD,  //40526
	STR_ID_VDOREC_NOTIFY_WRITE_PROTECTION,  //40527
	STR_ID_VDOREC_NOTIFY_ERROR,  //40528  
	STR_ID_VDOREC_NOTIFY_SAVING,  //40529  Saving...  正在保存。。。 
	STR_ID_VDOREC_NOTIFY_HW_NOT_READY,   //40530 Hardware Not Ready  设备忙
	STR_ID_VDOREC_NOTIFY_RESTORE_DEFAULT_CONFIRM,    //40531 还原到默认设定?
	STR_ID_VDOREC_NOTIFY_SAVE_CONFIRM,    //40532  保存视频文件?
	STR_ID_VDOREC_NOTIFY_SAVE_FILE_ERROR,    //40533  Save File Error! 保存文件出错!
	STR_ID_VDOREC_NOTIFY_REACH_TIME_LIMIT,    //40534  达到影片限制时间Reach Time Limit !
	STR_ID_VDOREC_NOTIFY_REACH_SIZE_LIMIT,    //40535  达到影片限制大小 Reach Size limit !

	/* 23KEY */
	STR_ID_VDOREC_RSK_RECORD,   //40536

	STR_ID_VDOREC_CONTRAST,  // add by zhangl for greenstone
	STR_ID_VDOREC_BRIGHTNESS, // add by zhangl for greenstone
	
	STR_ID_VDOREC_TOTAL_COUNT
} vdorec_str_id_enum;






/***************** WB *******************/
typedef enum {

	STR_ID_VDOREC_WB_START = VDOREC_WB_BASE,
		
//#ifdef __VDOREC_FEATURE_WB_AUTO__
	STR_ID_VDOREC_WB_AUTO,   //40611  自动 Auto
//#endif

//#ifdef __VDOREC_FEATURE_WB_DAYLIGHT__
	STR_ID_VDOREC_WB_DAYLIGHT,   //40612  太阳光 Daylight
//#endif

//#ifdef __VDOREC_FEATURE_WB_TUNGSTEN__
	STR_ID_VDOREC_WB_TUNGSTEN,   //40613 钨丝光 Tungsten
//#endif

//#ifdef __VDOREC_FEATURE_WB_FLUORESCENT__
	STR_ID_VDOREC_WB_FLUORESCENT,  //40614 荧光灯 Fluorescent
//#endif

//#ifdef __VDOREC_FEATURE_WB_CLOUD__
	STR_ID_VDOREC_WB_CLOUD,	  //40615  阴天 Cloud
//#endif

//#ifdef __VDOREC_FEATURE_WB_INCANDESCENCE__
	STR_ID_VDOREC_WB_INCANDESCENCE,  //40616  白热光Incandescence
//#endif

	STR_ID_VDOREC_WB_END
	
} vdorec_wb_str_id_enum;

	
/***************** LED Highlight *******************/


typedef enum {

	STR_ID_VDOREC_LED_HIGHLIGHT_START = VDOREC_LED_HIGHLIGHT_BASE,
	STR_ID_VDOREC_LED_HIGHLIGHT_OFF,   //40621  关闭 Off

//#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__

	STR_ID_VDOREC_LED_HIGHLIGHT_ON, //40622  开启  On
	
//#endif /* __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__ */

//#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__

	STR_ID_VDOREC_LED_HIGHLIGHT_WHITE,	//40623		
	STR_ID_VDOREC_LED_HIGHLIGHT_RED,	//40624		
	STR_ID_VDOREC_LED_HIGHLIGHT_GREEN,		//40625		
	STR_ID_VDOREC_LED_HIGHLIGHT_BLUE,		//40626			
	STR_ID_VDOREC_LED_HIGHLIGHT_YELLOW,	//40627					
	STR_ID_VDOREC_LED_HIGHLIGHT_PURPLE,		//40628					
	STR_ID_VDOREC_LED_HIGHLIGHT_CYAN,	//40629
	
//#endif /* __VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__ */

	STR_ID_VDOREC_LED_HIGHLIGHT_END  
	
} vdorec_led_highlight_str_id_enum;




/***************** EV *******************/
typedef enum {

	STR_ID_VDOREC_EV_START = VDOREC_EV_BASE + 2,   //因为EV 的宏__VDOREC_FEATURE_EV_4__ 和__VDOREC_FEATURE_EV_4__
													//没有打开，所以要跳过前面两个枚举值

#ifdef __VDOREC_FEATURE_EV_4__
	STR_ID_VDOREC_EV_N4,  //40631  补偿-4   EV -4
#endif

#ifdef __VDOREC_FEATURE_EV_3__	
	STR_ID_VDOREC_EV_N3,  //40632 补偿-3  EV -3
#endif


//#ifdef __VDOREC_FEATURE_EV_2__	
	STR_ID_VDOREC_EV_N2,  //40633 补偿-2  EV -2
//#endif	
	
	STR_ID_VDOREC_EV_N1,  //40634   补偿-1   EV -1
	STR_ID_VDOREC_EV_0,	 //40635  补偿0   EV 0
	STR_ID_VDOREC_EV_P1, //40636    补偿+1   EV +1
	
//#ifdef __VDOREC_FEATURE_EV_2__
	STR_ID_VDOREC_EV_P2,  //40637  补偿+2   EV +2
//#endif

#ifdef __VDOREC_FEATURE_EV_3__
	STR_ID_VDOREC_EV_P3,  //40638    补偿+3  EV +3
#endif

#ifdef __VDOREC_FEATURE_EV_4__
	STR_ID_VDOREC_EV_P4,  //40639    补偿+4  EV +4
#endif

	STR_ID_VDOREC_EV_END
	
} vdorec_ev_str_id_enum;

/***************** CONTRAST for greenstone *******************/
typedef enum {

	STR_ID_VDOREC_CONTRAST_START = VDOREC_CONTRAST_BASE ,   
													
	STR_ID_VDOREC_CONTRAST_L1,	 // has no str_id
	STR_ID_VDOREC_CONTRAST_L2, 
	
	STR_ID_VDOREC_CONTRAST_L3,  

	STR_ID_VDOREC_CONTRAST_L4,  

	STR_ID_VDOREC_CONTRAST_L5,  

	STR_ID_VDOREC_CONTRAST_END
	
} vdorec_ct_str_id_enum;

/***************** Night *******************/
typedef enum {

	STR_ID_VDOREC_NIGHT_START = VDOREC_NIGHT_BASE,
		
	STR_ID_VDOREC_NIGHT_OFF,	  //40641 关闭 Off
	STR_ID_VDOREC_NIGHT_ON,  //40642  开启 On
	
	STR_ID_VDOREC_NIGHT_END
	
} vdorec_night_str_id_enum;


/***************** Banding *******************/
typedef enum {

	STR_ID_VDOREC_BANDING_START = VDOREC_BANDING_BASE,
		
	STR_ID_VDOREC_BANDING_50HZ,	 //40651 50HZ
	STR_ID_VDOREC_BANDING_60HZ, //40652  60HZ
	
	STR_ID_VDOREC_BANDING_END
	
} vdorec_banding_str_id_enum;


/***************** Video size *******************/
typedef enum {

	STR_ID_VDOREC_VIDEO_SIZE_START = VDOREC_VIDEO_SIZE_BASE,

//	#ifdef __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__ 
		STR_ID_VDOREC_VIDEO_SIZE_SQCIF,
//	#endif /* __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__ */

//	#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
		STR_ID_VDOREC_VIDEO_SIZE_QQVGA,
//	#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__ */

//	#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
		STR_ID_VDOREC_VIDEO_SIZE_QCIF,
//	#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QCIF__ */

//	#ifdef __VDOREC_FEATURE_VIDEO_SIZE_CIF__
		STR_ID_VDOREC_VIDEO_SIZE_CIF,
//	#endif /* __VDOREC_FEATURE_VIDEO_SIZE_CIF__ */
	
	STR_ID_VDOREC_VIDEO_SIZE_END
	
} vdorec_video_size_str_id_enum;


/***************** Video Qty *******************/
typedef enum {

	STR_ID_VDOREC_VIDEO_QTY_START = VDOREC_VIDEO_QTY_BASE,

	#ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__ 
		STR_ID_VDOREC_VIDEO_QTY_FINE,  //
	#endif /* __VDOREC_FEATURE_VIDEO_QTY_FINE__ */

	#ifdef __VDOREC_FEATURE_VIDEO_QTY_HIGH__
		STR_ID_VDOREC_VIDEO_QTY_HIGH,  //40672  高等
	#endif /* __VDOREC_FEATURE_VIDEO_QTY_HIGH__ */

	#ifdef __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
		STR_ID_VDOREC_VIDEO_QTY_NORMAL,  
	#endif /* __VDOREC_FEATURE_VIDEO_QTY_NORMAL__ */

	#ifdef __VDOREC_FEATURE_VIDEO_QTY_LOW__
		STR_ID_VDOREC_VIDEO_QTY_LOW,  //40673  低等
	#endif /* __VDOREC_FEATURE_VIDEO_QTY_LOW__ */
	
	STR_ID_VDOREC_VIDEO_QTY_END
	
} vdorec_video_qty_str_id_enum;

	
/***************** Size Limit *******************/
typedef enum {

	STR_ID_VDOREC_SIZE_LIMIT_START = VDOREC_SIZE_LIMIT_BASE,
		
	STR_ID_VDOREC_SIZE_LIMIT_NO_LIMIT,   //40681  无限制
	STR_ID_VDOREC_SIZE_LIMIT_1,  ////40682    4M
	STR_ID_VDOREC_SIZE_LIMIT_2,  //40683   16M
	STR_ID_VDOREC_SIZE_LIMIT_3,  //40684   32M
	
	STR_ID_VDOREC_SIZE_LIMIT_END
	
} vdorec_size_limit_str_id_enum;



/***************** Time Limit *******************/
typedef enum {

	STR_ID_VDOREC_TIME_LIMIT_START = VDOREC_TIME_LIMIT_BASE + 1,
		
//	STR_ID_VDOREC_TIME_LIMIT_NO_LIMIT,  //40691 无限制
	STR_ID_VDOREC_TIME_LIMIT_1,  //40692  1分钟1 minute
	STR_ID_VDOREC_TIME_LIMIT_2,  //40693  10分钟  10 minutes
	STR_ID_VDOREC_TIME_LIMIT_3,	//40694  30分钟  30 minutes
	
	STR_ID_VDOREC_TIME_LIMIT_END
	
} vdorec_time_limit_str_id_enum;


/***************** Record Aud *******************/
typedef enum {

	STR_ID_VDOREC_RECORD_AUD_START = VDOREC_RECORD_AUD_BASE,
	STR_ID_VDOREC_RECORD_AUD_OFF,   //40701   关闭 Off
	STR_ID_VDOREC_RECORD_AUD_ON,  //40702  开启 On
	
	STR_ID_VDOREC_RECORD_AUD_END
	
} vdorec_record_aud_str_id_enum;


/***************** Video Format *******************/
typedef enum {

	STR_ID_VDOREC_VIDEO_FORMAT_START = VDOREC_VIDEO_FORMAT_BASE,
	STR_ID_VDOREC_VIDEO_FORMAT_3GP,
	STR_ID_VDOREC_VIDEO_FORMAT_MP4,
	
	STR_ID_VDOREC_VIDEO_FORMAT_END
	
} vdorec_video_format_str_id_enum;


/***************** Effect *******************/
typedef enum {

	STR_ID_VDOREC_EFFECT_START = VDOREC_EFFECT_BASE,

#ifdef __VDOREC_FEATURE_EFFECT_NORMAL__
	STR_ID_VDOREC_EFFECT_NORMAL,   //40721
#endif

#ifdef __VDOREC_FEATURE_EFFECT_GRAYSCALE__
	STR_ID_VDOREC_EFFECT_GRAYSCALE,  //40722
#endif

#ifdef __VDOREC_FEATURE_EFFECT_SEPIA__
	STR_ID_VDOREC_EFFECT_SEPIA,  //40723
#endif

#ifdef __VDOREC_FEATURE_EFFECT_SEPIA_GREEN__
	STR_ID_VDOREC_EFFECT_SEPIA_GREEN,  //40724
#endif

#ifdef __VDOREC_FEATURE_EFFECT_SEPIA_BLUE__
	STR_ID_VDOREC_EFFECT_SEPIA_BLUE,  //40725
#endif

#ifdef __VDOREC_FEATURE_EFFECT_COLOR_INVERT__
	STR_ID_VDOREC_EFFECT_COLOR_INVERT,  //40726
#endif

#ifdef __VDOREC_FEATURE_EFFECT_GRAY_INVERT__
	STR_ID_VDOREC_EFFECT_GRAY_INVERT,  //40727
#endif

#ifdef __VDOREC_FEATURE_EFFECT_BLACKBOARD__
	STR_ID_VDOREC_EFFECT_BLACKBOARD,  //40728
#endif

#ifdef __VDOREC_FEATURE_EFFECT_WHITEBOARD__
	STR_ID_VDOREC_EFFECT_WHITEBOARD,  //40729
#endif

#ifdef __VDOREC_FEATURE_EFFECT_COPPER_CARVING__
	STR_ID_VDOREC_EFFECT_COPPER_CARVING,  //40730
#endif

#ifdef __VDOREC_FEATURE_EFFECT_BLUE_CARVING__
	STR_ID_VDOREC_EFFECT_BLUE_CARVING,  //40731
#endif

#ifdef __VDOREC_FEATURE_EFFECT_EMBOSSMENT__
	STR_ID_VDOREC_EFFECT_EMBOSSMENT,	 //40732
#endif

#ifdef __VDOREC_FEATURE_EFFECT_CONTRAST__
	STR_ID_VDOREC_EFFECT_CONTRAST,  //40733
#endif

#ifdef __VDOREC_FEATURE_EFFECT_JEAN__
	STR_ID_VDOREC_EFFECT_JEAN,  //40734
#endif

#ifdef __VDOREC_FEATURE_EFFECT_SKETCH__
	STR_ID_VDOREC_EFFECT_SKETCH,  //40735
#endif

#ifdef __VDOREC_FEATURE_EFFECT_OIL__
	STR_ID_VDOREC_EFFECT_OIL,  //40736
#endif

/////added  by zhangl
#ifdef  __VDOREC_FEATURE_EFFECT_ANTIQUE__
     	STR_ID_VDOREC_EFFECT_ANTIQUE,
#endif

#ifdef  __VDOREC_FEATURE_EFFECT_REDRISH__
     	STR_ID_VDOREC_EFFECT_REDRISH,
#endif

#ifdef  __VDOREC_FEATURE_EFFECT_GREENRISH__
    	STR_ID_VDOREC_EFFECT_GREENRISH,
#endif

#ifdef  __VDOREC_FEATURE_EFFECT_BLUERISH__
   	 STR_ID_VDOREC_EFFECT_BLUERISH,
#endif


#ifdef __VDOREC_FEATURE_EFFECT_BLACKWHITE__
     	STR_ID_VDOREC_EFFECT_BLACKWHITE,
#endif


#ifdef  __VDOREC_FEATURE_EFFECT_NEGATIVE__
   	STR_ID_VDOREC_EFFECT_NEGATIVENESS,
#endif
	
	STR_ID_VDOREC_EFFECT_END
	
} vdorec_effect_str_id_enum;





#endif /* _MMI_VDORECSTRENUM_H */


