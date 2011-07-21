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
 * TimerEvents.h
 *
 * Project:
 * --------
 
 *
 * Description:
 * ------------
 *   This file is intends for MMI timer resource.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 
 *------------------------------------------------------------------------------
 *
 *
 *------------------------------------------------------------------------------
 
 *============================================================================
 ****************************************************************************/

/**************************************************************

	FILENAME	: TimerEvents.h

  	PURPOSE		: struct, defines & globle variables

 

	AUTHOR		: Magesh k

	DATE		: sep' 03, 2002

**************************************************************/

#ifndef _PIXCOM_TIMER_EVENT_H
#define _PIXCOM_TIMER_EVENT_H
#include "cos.h"

#if defined (MMI_ON_WIN32)
#define COS_MMI_TIMER_ID_BASE  0x000
#define COS_MMI_TIMER_ID_END_  0x3FF
#endif


typedef enum
{
	/*
	** Start for for Keypad based timer.
	*/
	KEY_TIMER_ID_NONE=COS_MMI_TIMER_ID_BASE,
	KEY_TIMER_ID0,
	KEY_TIMER_ID1,
	KEY_TIMER_ID2,
	KEY_TIMER_ID3,
	KEY_TIMER_ID4,
	KEY_TIMER_ID5,
	KEY_TIMER_ID6,
	KEY_TIMER_ID7,
	KEY_TIMER_ID8,					
	KEY_TIMER_ID9,					
	KEY_TIMER_ID10,					
	KEY_TIMER_ID11,
	KEY_TIMER_ID12,
	KEY_TIMER_ID13,
	KEY_TIMER_ID14,
	KEY_TIMER_ID15,
	KEY_TIMER_ID16,
	KEY_TIMER_ID17,
	KEY_TIMER_ID18,
	KEY_TIMER_ID19,
	KEY_TIMER_ID20,
	KEY_TIMER_ID21,
	KEY_TIMER_ID22,
	KEY_TIMER_ID23,
	KEY_TIMER_ID24,
	KEY_TIMER_ID25,
	KEY_TIMER_ID26,
	KEY_TIMER_ID27,
	KEY_TIMER_ID28,
	KEY_TIMER_ID29,
	KEY_TIMER_ID30,
	KEY_TIMER_ID31,
	KEY_TIMER_ID32,
	KEY_TIMER_ID33,
	KEY_TIMER_ID34,
	KEY_TIMER_ID35,
	KEY_TIMER_ID36,
	KEY_TIMER_ID37,
	KEY_TIMER_ID38,
	KEY_TIMER_ID39,
	KEY_TIMER_ID40,
	KEY_TIMER_ID41,
	KEY_TIMER_ID42,
	KEY_TIMER_ID43,
	KEY_TIMER_ID44,
	KEY_TIMER_ID45,
	KEY_TIMER_ID46,
	KEY_TIMER_ID47,
	KEY_TIMER_ID48,
	KEY_TIMER_ID49,
	KEY_TIMER_ID50,
	KEY_TIMER_ID51,
	KEY_TIMER_ID52,
	KEY_TIMER_ID53,
	KEY_TIMER_ID54,
	KEY_TIMER_ID55,
	KEY_TIMER_ID56,
	KEY_TIMER_ID57,
	KEY_TIMER_ID58,
	KEY_TIMER_ID59,
	KEY_TIMER_ID60,
	KEY_TIMER_ID61,
	KEY_TIMER_ID62,
	KEY_TIMER_ID63,
	KEY_TIMER_ID64,
	KEY_TIMER_ID65,
	KEY_TIMER_ID66,
	KEY_TIMER_ID67,
	KEY_TIMER_ID68,
	KEY_TIMER_ID69,

	/*
	** Start for for UI based timer.
	*/
	UI_TIMER_ID_BASE, 
	UI_TIMER_ID_MAX=(UI_TIMER_ID_BASE+20), 	

	/*
	** Start for MMI APP based timer
	*/
	//MMI_TIMER_BASE=UI_TIMER_ID_MAX+1,  del by wuzc 2007 0820 because of no using.

	/*
	** For GUI
	*/
	UI_ELEMENTS_TIMER,

	/*
	** For Sim detection timers
	*/
	SAT_MESSAGE_WAIT_TIMER,
	SAT_TERMINAL_RESP_TIMER,
	//micha1108
	SAT_PLAY_TONE_TIMER,
	SAT_HELP_TIMER,
//micha0201
        SAT_500_TIMER,
        SAT_3000_TIMER,
	SAT_REFRESH_REBOOT_TIMER,
	KEYPADUNLOCKEDMESSAGE_TIMER,
	
	/*
	** Timer for showing "press to unlock" after pressing
	*/
	KEYPADUNLOCKEDHELPMESSAGE_TIMER,
	

	/*
	** For Call Management 
	*/
	CM_REDIAL_TIMER,
	CM_ALERT_NOTIFYDURATION_TIMER,
	CM_AUTOANSWER_NOTIFYDURATION_TIMER,
	CM_AUTO_DTMF_CONFIRM_TIMER,
	CM_CCBS_NOTIFYDURATION_TIMER,
	CM_GET_TIME_CALLBACK,
	CM_NOTIFYDURATION_TIMER,
        CM_CTR_TIMER,
        CM_DIAL_P_TIMER,
	CALL_SETTING_SOUND_WARNNING_TIMER,

	/*
	** For Boot Up and system
	*/
	SYSTEM_SHUTDOWN,
	TIMER_REAL_TIME_CLOCK,
	APHORISM_SCR_TIMER,
	WELCOME_SCR_TIMER,
	KEYPAD_LOCK_TIMER,
	LOW_BATTERY_SCR_TIMER,
	BOOTUP_CHARGER_DETECT_TIMER,
	SEARCHING_SCREEN_TIMER,   

	/*
	** for PHB 
	*/
	PHB_NOTIFYDURATION_TIMER,
	PHB_READ_OPT_FILED_TIMER,
	PHB_READ_SPEED_DIAL_TIMER,
	PHB_QUICK_SEARCH_TIMER,
	PHB_LIST_SPEAK_NAME_TIMER,

	/*
	** for SMS
	*/
	MESSAGES_SMS_BOOTUP_TIMER_ID,
	MESSAGES_SMS_BOOTUP_NO_LIST_RSP_TIMER_ID,
	MESSAGES_CB_BOOTUP_TIMER_ID,
	MESSAGES_SUBLCD_TIMER_ID,
	MESSAGES_INPROGRESS_TIMER_ID,
	MESSAGES_LMS_RECV_TIMER_ID,
	MESSAGES_EMS_OBJECT_PLAY_TIMER_ID,

	/*
	** for Help Application Timer
	*/
	HELP_APPLICATION_TIMER,

	/*
	** for Ring Tone Compser Timer
	*/
	TIMER_COMPOSE_RINGTONE,

	/*
	** for Alarm timer
	*/
	ALARM_TIMER_WAIT_FOR_CALL,
	ALARM_TIMER_WAIT_FOR_RESPONSE,
	ALARM_SIMULATE_ON_WIN32,
	ALARM_ALERT_NOTIFYDURATION_TIMER,

	/*
	** for Idle and Misc 
	*/
	KEY_VOL_TIMER_ID,
	TOGGLE_TIMER,
	SP_FAIL_TIMER,
	EARPHONE_SCR_TIMER,
	BACKLIGHT_TIMER,
	IDLE_SHOW_BADFILE_WARNING_TIMER,
	IDLE_APP_AUTO_LOCK_TIMER_ID,
	EMERGENCY_NO_DIALED_TRANSIANT_SCR_TIMER,

	/*
	** for SIM 
	*/
	CODE_VERIFIED_TIMER,

	/*
	** for Organize,  Fun and Game
	*/
	PLAY_DOWNLOAD_AUDIO,
	SCREENSAVER_TIMER,
	AT_TEST_TIMER,
	TIMER_POPUP_HEALTH_MENSIS,

	/*
	** for input method
	*/
	T9_REQ_TIMER,
	T9_FRAME_TIMER,
	BLINKING_CURSOR,
	ZI_REQ_TIMER,
	ZI_FRAME_TIMER,
	NOTE_MULTITAP_TIMER,	 

	/*
	** for Engineering mode
	*/
	EM_NOTIFYDURATION_TIMER,
	EM_RINGTONE_HIGHLIGHT_TIMER,
	EM_GPRS_PING_TIMER,
	EM_GPRS_SOC_DEMO_APP_TIMER,	
	FM_LCD_COLOR_CHANGE_TIMER,
	FM_AUTO_TEST_COMMNON_TIMER,
	FM_RTC_START_TIMER,
	FM_VIB_TIMER,
	FM_GENERAL_TIMER,

	/*
	** for Profiles and Settings
	*/
	TIMER_PROFILES_TONE_PLAY,
	TIMER_PROFILES_ALERT_PLAY,
	TIMER_KEYPAD_BACKLIGHT,
//micha1109
	TIMER_SET_GPRS_MODE,

	/*
	** for Common Screen
	*/
	POPUP_TIMER,
	BOOTUP_POPUP_TIMER,
	POPUP_SUBLCD,

	/*
	** for USB
	*/
	USB_SHUTDOWN_SCR_TIMER,
	PENDING_USBDETECTION_HDLR_TIMER,

	/*
	** for file management
	*/
	FMGR_AUDIO_TIMER,
	/*WUZC Add Start For MMIFS Ver:    on 2007-1-12 15:0 */
	FMGR_SCR_TIMER,
	/*WUZC Add End  For MMIFS Ver:    on 2007-1-12 15:0 */
	FMGR_PROG_UPDATE_TIMER,
	FMGR_DELAY_DECODE_0,
	FMGR_DELAY_DECODE_1,
	FMGR_DELAY_DECODE_2,
	FMGR_DELAY_DECODE_3,
	FMGR_DELAY_DECODE_4,
	FMGR_DELAY_DECODE_5,
	FMGR_DELAY_DECODE_6,	
	FMGR_DELAY_DECODE_7,	
	FMGR_DELAY_DECODE_8,	
	FMGR_DELAY_DECODE_9,	
	FMGR_DELAY_DECODE_10,	
	FMGR_DELAY_DECODE_11,	
	FMGR_DELAY_DECODE_12,	
	FMGR_DELAY_DECODE_13,	
	FMGR_DELAY_DECODE_14,	
	FMGR_DELAY_DECODE_15, 	
	
	/*
	** for Bluetooth
	*/
	
	BT_INQ_TIMER,
	BT_RING_TIMER,
	BT_AUD_OFF_TIMER,
	BT_DEV_DISC_TIMER,
	BT_DISCOVER_PERIOD_TIMER,
	BT_CMD_GUARD_TIMER,
	BT_MAKE_IDLE_STATE_TIMER,
	BT_WAIT_POWER_OFF_TIMER,
	BT_WAIT_POWER_ON_TIMER,	
	
//	BT_LPM_TIMER, //for ACCEL BT CLIP rev-F only
//	BT_ADP_INQ_TIMER, //for ACCEL BT CLIP rev-F only

    /*
     * for Audio via SCO
     */
    BT_SCO_CONNECT_TIMER,
    BT_SCO_ENABLE_CONNECT_DELAY_TIMER,

	
    BT_POPUP_TIMER,
    BT_PASSCODE_INPUT_PROMPTED_TIMER,
    BT_DISCONNECT_2ND_INCOMING_HFG_TIMER,
    BT_DEACTIVATE_PROHIBITED_PROFILES_TIMER,
    BT_ACTIVATE_PROFILE_TIMER,
    BT_WAIT_HW_READY_TIMER,
    BT_LP2_TESTING_TIMER,
    BT_LP2_DELAY_TIMER,
    BT_DELAY_DEACTIVATE_OBEX_RELATED_PROFILES_TIMER,
    BT_DELAY_AVRCP_CONN_POPUP_TIMER,
    BT_DELAY_AVRCP_DISC_POPUP_TIMER,
    BT_POWER_OFF_GUARD_TIMER,
    BT_DELAY_SCO_CONN_POPUP_TIMER,
    BT_RELEASE_ALL_CON_GUARD_TIMER,
    BT_DUMMY_SCR_TIMER,


//Renwy add begine 2008/07/28
	 /*
     * for BT OPP request timeout
     */
    BT_OPP_REQ_TIMER,
    BT_OPP_ACCEPT_CONNECT_TIMER,
    BT_OPP_ABORT_REQ_TIMER,
    BT_OPP_PUSH_IND_TIMER,
    /*
     * for BT FTP request timeout
     */
     BT_FTPS_RECV_TIMEROUT,
    BT_FTP_REQ_TIMER,
    BT_FTP_ACCEPT_CONNECT_TIMER,
    BT_FTPS_PUSH_FH_CHECK_TIMER,
    BT_FTPC_BROWSE_FILES_FAILED_TIMER,
    BT_FTPS_ICON_STOP_TIMER,
    BT_FTPS_PULL_IND_TIMER,
    /*
     * for BT BPP printing timeout
     */
   // BT_BPP_PRINTING_TIMER,
    
    /*
     * for BT BIP request timeout
     */
//    BT_BIP_REQ_TIMER,
//    BT_BIP_BLINKING_TIMER,
//    BT_BIP_FS_TIMER,
    /*
     * AV BT app
     */ 
    AV_BT_DISC_TIMER,
    AV_BT_START_TIMER,
    BT_AVRCP_AUTO_RELEASE_TIMER,
    BT_AVRCP_TEST_TIMER,


    /*
     * for BT HID user confirm timeout
     */
//    BT_HID_USER_CNF_TIMER,
//Renwy add end 2008/07/28
	/*
	** for audio player
	*/
	AUDPLY_PROCESS_ADD_FILE_TIMER,
	AUDPLY_COUNT_PLAY_TIMER,
	AUDPLY_DELAY_PLAY_TIMER,
	AUDPLY_SINGLE_PLAY_TIMER,


	/*
	** for AB repeater
	*/
	ABREPEAT_PROGRESS_BAR_DRAW_TIMER,
	ABREPEAT_DELAY_PLAY_TIMER,
	ABREPEAT_DUMMY_FILE_PROG_TIMER,

	/*
	** for mdi_audio_play_text
	*/
	MDI_AUDIO_PLAYER_TEXT_TIMER,

	/*
	** for fm radio
	*/
	FMRDO_TWINKLE_FREQUENCY_TIMER,
	FMRDO_REPEAT_STEP_TIMER,

	/*
	** for MMIAPI
	*/
	MMIAPI_SMS_TIMER,

	/*
	** for GPIO
	*/
	GPIO_KEYPAD_LIGHT_TIMER,

	/*
	** for WAP
	*/
	WAP_NOT_READY_TIMER,
	WAP_GOTO_IDLE_TIMER,
	WAP_EDITOR_MESSAGEBOX_TIMER,

	/*
	** for J2ME
	*/
	JVM_TIMER,
	J2ME_TIMEALARM_TIMER,
	J2ME_NOT_READY_TIMER,

	/*
	** for VRSD
	*/
	VRSD_DIAL_AUTO_DIAL_TIMER,
	VRSD_DIAL_PLAYBACK_TIMER,
	VRSD_PLAYTONE_TIMER,

	/*
	** for touch screen
	*/
	PEN_POLLING_TIMER,

	/*
	** for GDI,( allocate 128 timer id )
	*/
	GDI_TIMER_BASE,
	GDI_TIMER_END=GDI_TIMER_BASE +  64 , //mod by wuzc 64 to 32 because of 64 too many
	 
	/*
	** for PoC
	*/
	POC_IND_TIMER,
	JESSAMINE_CHARGER_DETECT,
	/*
	** for Shcedule FM Recording
	*/
	FMSR_CHCEK_STOP_TIMER,

	/*
	**for long key press
	*/
	KEYPAD_LONG_PRESS,

	PEN_HANDLE_TIMER,

       PEN_REPEAT_HANDLE_TIMER,
       
	VIBRATE_TIME_REPEAT_ID,
	VIBRATE_TIME_ONCE_ID,
	VIBRATE_TIME_DUR_ID,
	POWER_ON_ANIMATION_DEDLAY,
  	PHBLIST_COPY_OR_DELETE_TIMEROUTID,
  	 EV_MP3_TIMER_ID,
  	//EV_VIDEO_TIMER_ID,
//	MED_BASE_TIMER_ID,   //multimedia
//	MED_END_TIMER_ID  = MED_BASE_TIMER_ID + 10,

	EBOOK_RECURSIVE_TIMER,
	EBR_SEARCH_BLOCK_TIMER,

	GPRS_ATTACH_DELAY_TIMER,
	GPRS_ATTACH_DELAY_TIMER_SIM1,
	GPRS_ATTACH_DELAY_TIMER_SIM2,
	GPRS_ATTACH_DELAY_TIMER_SIM3,
	GPRS_DETACH_DELAY_TIMER,
	GPRS_DETACH_DELAY_TIMER_SIM1,
	GPRS_DETACH_DELAY_TIMER_SIM2,
	GPRS_DETACH_DELAY_TIMER_SIM3,
	ADP_SS_CALL_FORWARD_QUERY_TIMER,

	TFLASH_ACTIVE_DELAY_TIMER,
    POWER_ON_OFF_LED_TIMER,
    
#if defined( __MMI_ANALOGTV__)	
    RDAMTV_STATUS_CHECK_TIMER,
	ANALOGTV_AUTO_SEARCH_TIMER,
	ANALOGTV_SPLITSCR_TIMER_ID,
	ANALOGTV_READ_LIST_TIMER_ID,
	ANALOGTV_RECORD_TIMER_ID,
#endif
#ifdef __ZYX_PLATFORM_SUPPORT__
	ZYX_TIMER_BEGIN,
	ZYX_TIMER_END = ZYX_TIMER_BEGIN+20,
#endif
#ifdef __SG_MMI_MEDIA_SPECIAL_MENU__
       MEDIA_MENU_EFFECT_TIMER,
	MEDIA_MENU_EFFECT_BALL_TIMER,
#endif
#ifdef __MMI_SUPPORT_JME__
      JMETOC_TIMERS_BASE_BEGIN,
      JMETOC_TIMERS_BASE_END =JMETOC_TIMERS_BASE_BEGIN+10,
#endif
	MAX_TIMERS_END /* Imp: Please do not modify this */ 	  
	 
}MMI_TIMER_IDS;

#if (MAX_TIMERS_END>COS_MMI_TIMER_ID_END_)
/*MMI TIMER ID SHOULD BETWEEN COS_MMI_TIMER_ID_BASE AND COS_MMI_TIMER_ID_END_ */
#error "MAX_TIMERS>COS_MMI_TIMER_ID_END_"
#endif
#define MAX_TIMERS (MAX_TIMERS_END-KEY_TIMER_ID_NONE)
#endif	// _PIXCOM_TIMER_EVENT_H

