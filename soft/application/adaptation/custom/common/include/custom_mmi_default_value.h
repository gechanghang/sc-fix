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
 * custom_mmi_default_value.h
 *
 * Project:
 * --------
 
 *
 * Description:
 * ------------
 *    This file is for customers to config/customize their parameters to NVRAM Layer and
 *    Driver Layer.
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
 *
 *
 *------------------------------------------------------------------------------
 
 *============================================================================
 ****************************************************************************/
#ifndef _CUSTOM_MMI_DEFAULT_VALUE_H
#define _CUSTOM_MMI_DEFAULT_VALUE_H
#include "datetimetype.h"//fengzb
#include "audioinc.h"//fengzb
#include "settingprofile.h"//fengzb
#ifndef __MMI_SECTION__ //__RESET_FACTORY__
/*********************** profile setting use*****************************/
#define MAX_ELEMENTS 7

#define LEVEL1 0
#define LEVEL2 1
#define LEVEL3 2
#define LEVEL4 3
#define LEVEL5 4
#define LEVEL6 5
#define LEVEL7 6

#define NO_COLOR 0
#define COLOR_PATTERN1 1
#define COLOR_PATTERN2 2
#define COLOR_PATTERN3 3
#define COLOR_PATTERN4 4
#define COLOR_PATTERN5 5
#define COLOR_PATTERN6 6

#define SINGLE		0
#define REPEAT  1
#define ASCENDING	2

#define POWEROFF_SILENT		0
#define POWERON_SILENT		0
#define COVER_OPEN_SILENT	0
#define	COVER_CLOSE_SILENT  0
#define MESSAGE_SILENT		0


#define KEYPAD_SILENT 0
#define KEYPAD_CLICK 1
#define KEYPAD_TONE 2
#define KEYPAD_TONE_HUMAN_VOICE_1 3
#define KEYPAD_TONE_HUMAN_VOICE_2 4
#define KEYPAD_TONE_HUMAN_VOICE_3 5
#define KEYPAD_TONE_HUMAN_VOICE_4 6
#define KEYPAD_TONE_HUMAN_VOICE_5 7
#define KEYPAD_TONE_HUMAN_VOICE_6 8
#define KEYPAD_TONE_CUST_1 9
#define KEYPAD_TONE_CUST_2 10
#define KEYPAD_TONE_CUST_3 11
#define KEYPAD_TONE_CUST_4 12
#define KEYPAD_TONE_CUST_5 13
#define KEYPAD_TONE_CUST_6 14

#define THEME_DEFAULT 0
#define SMALL 1 
#define MEDIUM 2 
#define LARGE 3

#define MAX_ACTIVITIES_PER_DAY 10
#define NUMBER_OF_WEEKDAYS 7

#define MAX_PB_NUMBER_LENGTH	40
#define MAX_PB_NAME_LENGTH		30
#define ENCODING_LENGTH			2
#define MAX_SPEED_DIAL_NUMBER	8
#define MAX_GRP_NAME_LENGTH		20
#define MAX_PB_CALLER_GROUPS	 5

//These should be the same as "PhoneBookTypes.h"
#define MAX_PB_COMPANY_LENGTH 20
#define MAX_PB_EMAIL_LENGTH 60
#define MAX_PB_VIEW_FIELDS 8

//This should be the same as "PhoneBookTypes.h"
#define MAX_PB_PHONE_ENTRIES   PHONE_PHB_ENTRY_COUNT
//This should be the same as "PhoneBookDef.h". 0 for undefined image.
// dingjian 20080409 Temp
//#define IMG_PHB_DEFAULT		  0

//This should be in sync with resource_audio.h. Or else "resource_audio.h" should be included.
#define MIN_MIDI_ID				151
#if 0//fengzb
typedef enum {
	MMI_ALERT_NONE,
	MMI_RING,
	MMI_VIBRATION_ONLY,
	MMI_VIBRATION_AND_RING,
	MMI_VIBRATION_THEN_RING,
	MMI_SILENT
} MMI_ALERT_TYPE;

#ifdef __MMI_CONNECT_NOTICE__
typedef enum {
	MMI_NOTICE_NONE,
	MMI_NOTICE_TONE_ONLY,
	MMI_NOTICE_VIB_ONLY,
	MMI_NOTICE_TONE_AND_VIB
} MMI_CONNECT_NOTICE_TYPE;
#endif

typedef struct {
kal_uint8 setsec;
}SET_TIMER;


typedef struct {
kal_uint8 status;
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(LCDBACKLIGHT)
unsigned short lcdBacklight;
#endif
SET_TIMER timer;
}LIGHT;

typedef struct{
   kal_uint16 ringTone;	
   kal_int16 powerOffTone;
   kal_int16 powerOnTone;
    
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_CLAMSHELL__)
   kal_int16 coverOpenTone;
   kal_int16 coverCloseTone;
#endif
   kal_int16 messageTone;
   kal_uint8 keypadTone;
   kal_uint16 alarmTone;
#ifdef __MMI_DUAL_PROFILE_SUPPORT__  //Add by Renyh for 221 project   20090213
   kal_uint16 card2_ringTone;
   kal_int16 card2_messageTone;
 #endif                                                        //Add by Renyh for 221 project   20090213  
} TONE_SETUP;
typedef struct{
unsigned short errorTone;
unsigned short connectTone;
unsigned short campOnTone;
unsigned short warningTone;
}EXTRA_TONE;

typedef enum {
	MMI_INTELLIGENT_CALL_ALERT_OFF,
	MMI_INTELLIGENT_CALL_ALERT_ON
} MMI_INTELLIGENT_CALL_ALERT_TYPE;

typedef struct {
kal_uint8   ringVolumeLevel;
kal_uint8   keypadVolumeLevel;
kal_uint8   loudSpeakerVolumeLevel;
MMI_ALERT_TYPE mtCallAlertTypeEnum;
LIGHT   light;
kal_uint8 ringTypeEnum;
TONE_SETUP toneSetup;
MMI_ANSWERING_MODE answeringMode;
kal_uint8 fontSizeEnum;

#ifndef MMI_LOW_MEMORY_PHONE
MMI_INTELLIGENT_CALL_ALERT_TYPE intelligentCallAlert;
#endif

EXTRA_TONE extraTone;
} PROFILE;


typedef struct {
 
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_CLAMSHELL__)
  unsigned short coverAnswer; 
#endif
unsigned short anyKey; 
unsigned short automatic;
}MMI_ANSWERING_MODE;


#endif
#ifdef __MMI_CONNECT_NOTICE__
typedef enum {
	MMI_NOTICE_NONE,
	MMI_NOTICE_TONE_ONLY,
	MMI_NOTICE_VIB_ONLY,
	MMI_NOTICE_TONE_AND_VIB
} MMI_CONNECT_NOTICE_TYPE;
#endif






typedef struct {
	kal_uint16 ActivityId[MAX_ACTIVITIES_PER_DAY];
	float CaloriePerActivity[MAX_ACTIVITIES_PER_DAY]; 
	kal_uint16 MinutesPerActivity[MAX_ACTIVITIES_PER_DAY];
} ActivityDetails;

typedef struct {
	kal_uint8	type;
	kal_uint8	storage;
	kal_uint16 	record_index;
	kal_uint8	number[(MAX_PB_NUMBER_LENGTH+1+1)*ENCODING_LENGTH];
	kal_uint8	name[(MAX_PB_NAME_LENGTH+1)*ENCODING_LENGTH];
} SpeedDialInfo;

typedef struct {
    kal_uint8    groupName[(MAX_GRP_NAME_LENGTH+1)*ENCODING_LENGTH];
    kal_uint16    ringToneID;			
    kal_uint16    pictureTagID;
    kal_uint16    LEDPatternId;
    kal_uint16    VideoID;	/*Originally "entryCount" is obselete, so change to store VideoID*/
    kal_uint16    black_list_flag_Id;
    kal_uint16    red_list_flag_Id;
    MMI_ALERT_TYPE    alertType;
    kal_uint8    is_modified;
} PHB_CALLER_GROUP_STRUCT;

typedef struct {
	kal_uint16		pictureTagID;
	kal_uint16		ringToneID;
	kal_uint8		callerGroupID;
} PHB_OPTIONAL_IDS_STRUCT;

/*********************** todolist use **************************/
#ifdef __ASCII
#define ENCODING_LENGTH			1
#endif

#ifdef __UCS2_ENCODING
#define ENCODING_LENGTH			2
#endif

#define MAX_TODO_LIST_NOTE				36 * ENCODING_LENGTH
#define MAX_DAY_IN_WEEK					7
#define MAX_TODO_LIST_TASK				10 
#if 0//fengzb
typedef struct MYTIME
{
	kal_uint16	  nYear;
	kal_uint8	  nMonth;
	kal_uint8	  nDay;
	kal_uint8	  nHour;
	kal_uint8	  nMin;
	kal_uint8	  nSec;
	kal_uint8	  DayIndex; /* 0=Sunday */
}MYTIME;
#endif
typedef struct _todo_list_node {

	MYTIME				Time;			// This variable use to store the date, day and Time of an task
	kal_uint8					EndHour;		// This variable stote the End time in Hours of an Task ( Duration )
	kal_uint8					EndMin;			// This variable stote the End time in Min of an Task ( Duration )
	kal_uint8					Note[MAX_TODO_LIST_NOTE];		// Note of an Task
	kal_uint8					Alarm ;				// Weather Alarm is On or Off
	kal_uint8					Repeat;				// Repeat values of Alarm
	kal_uint8					Days;				// Week days 
	kal_uint8					Present;		// Show the presence of other values	
	
} ToDoListNode ; // Total Size is 94 Bytes.

 
/*********************** downloaded image use **************************/
#define MAX_IMAGE_NAME_EXTENSION_WIDTH		(5*ENCODING_LENGTH)
#define MAX_IMAGE_NAME_WIDTH				((13*ENCODING_LENGTH)	+	MAX_IMAGE_NAME_EXTENSION_WIDTH + ENCODING_LENGTH)
typedef struct
{
	kal_uint8 ImageName[MAX_IMAGE_NAME_WIDTH];
	kal_int16 ImagesId;
}DYNIMAGEINFO;


 
/*********************** downloaded/composed audio use **************************/
#define MAX_IMAGE_NAME_EXTENSION_WIDTH		(5*ENCODING_LENGTH)
#define MAX_AUDIO_NAME_WIDTH				((13*ENCODING_LENGTH)	+	MAX_IMAGE_NAME_EXTENSION_WIDTH + ENCODING_LENGTH)
typedef struct
{
	kal_uint8 AudioName[MAX_AUDIO_NAME_WIDTH];
	kal_int16 AudioId;
}DYNAUDIOINFO;


//CSD Joy added for NVRAM data, 1129
/*********************** SMS use **************************/


#define SMS_CB_MAX_ENTRY		10

#if defined(MMI_CB_ENABLE_PAGING) 
#define MAX_STORE_CB_MSG 		1
#else
#define MAX_STORE_CB_MSG 		5
#endif//defined(MMI_CB_ENABLE_PAGING)

#define SMS_CB_ONE_MSG_LEN		162
#define MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN		13

typedef struct CB_CHANNEL_INDEX
{
	kal_uint8	L4Index[SMS_CB_MAX_ENTRY];	
}CB_CHANNEL_INDEX;

typedef struct CB_CHANNEL_NAME
{
	kal_uint8 	NameDCS;
	kal_uint8 	Name[16];	
}CB_CHANNEL_NAME;	

typedef struct CB_MESSAGE_LENGTH
{
	kal_uint16 	CBMessageLength[MAX_STORE_CB_MSG];
}CB_MESSAGE_LENGTH;

typedef struct CB_MESSAGE_CONTENT
{
	kal_uint8 	CBMessageContent[SMS_CB_ONE_MSG_LEN];
}CB_MESSAGE_CONTENT;

typedef struct EMS_OBJECT_NAME
{
	kal_uint8	object_name [(MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN*ENCODING_LENGTH)+ENCODING_LENGTH];
}EMS_OBJECT_NAME;

/*********************** SMS end **************************/
//CSD end

#define 	FACTORY_RESTORE_DEFAULT_SPEED_DIAL						0
#define 	FACTORY_RESTORE_DEFAULT_CONTRAST_SUBLCD_LEVEL_VALUE		7
#define 	FACTORY_RESTORE_DEFAULT_CONTRAST_MAINLCD_LEVEL_VALUE	7
#define 	FACTORY_RESTORE_DEFAULT_WELCOME_TEXT_STATUS				0
#define		FACTORY_RESTORE_DEFAULT_APHORISM_TEXT_STATUS			1
#define 	FACTORY_RESTORE_DEFAULT_OWNER_NO_STATUS					0
#define 	FACTORY_RESTORE_DEFAULT_STATUS_SHOW_DT_TIME_STATUS		1
#define 	FACTORY_RESTORE_DEFAULT_AUTOUPDATE_TIME_VALUE			0
#define 	FACTORY_RESTORE_DEFAULT_SCREENSAVER_STATUS				0
#define 	FACTORY_RESTORE_DEFAULT_SCREENSAVER_WAITING_TIME		30
#define		FACTORY_RESTORE_DEFAULT_CURRENT_SCREENSVER_ID			(SCREENSAVER_BASE + 1)
#define		FACTORY_RESTORE_DEFAULT_PROFILES_ACTIVATED_ID			0
#if defined(__PROJECT_GALLITE_C01__) 
#define		FACTORY_RESTORE_DEFAULT_FUNANDGAMES_SETWALLPAPER_ID		(WALLPAPER_BASE + 3)
#define     DEFAULT_FUNANDGAMES_SETWALLPAPER_ID          			(WALLPAPER_BASE + 3)
#else
#define		FACTORY_RESTORE_DEFAULT_FUNANDGAMES_SETWALLPAPER_ID		(WALLPAPER_BASE + 1)
#define     DEFAULT_FUNANDGAMES_SETWALLPAPER_ID          			(WALLPAPER_BASE + 1)
 #endif
#define		DEFAULT_SETWALLPAPER_SUB_ID					(WALLPAPER_BASE + 10)
#define		FACTORY_RESTORE_DEFAULT_SETWALLPAPER_SUB_ID			(WALLPAPER_BASE + 10)  


#define		MAXIMUM_EMS_DOWNLOAD_IMELODY		5
#define		MAXIMUM_DOWNLOAD_IMAGES				15
#define		MAXIMUM_DOWNLOAD_AUDIO				15
#define		MAXIMUM_COMPOSED_RINGTONE			5

#define MAXIMUM_FULLSCREEN_FACTORY_IMAGES			7  
#define MAXIMUM_ASSOCIATED_FACTORY_IMAGES			5
#define		MAXIMUM_FACTORY_TONES				5
#define		MAXIMUM_FACTORY_IMELODY				5

#define FACTORY_RESTORE_DEFAULT_AUDPLY_LIST_AUTO_GEN  1
#define FACTORY_RESTORE_DEFAULT_AUDPLY_VOLUME  4
#define FACTORY_RESTORE_DEFAULT_AUDPLY_PREFER_LIST  0
#define FACTORY_RESTORE_DEFAULT_AUDPLY_SKIN  0
#define FACTORY_RESTORE_DEFAULT_AUDPLY_REPEAT  0
#define FACTORY_RESTORE_DEFAULT_AUDPLY_SHUFFLE  0
#define FACTORY_RESTORE_DEFAULT_AUDPLY_BACKGROUND_PLAY  1

#define FACTORY_RESTORE_DEFAULT_SNDREC_STORAGE  0
#define FACTORY_RESTORE_DEFAULT_SNDREC_FORMAT  0

#define FACTORY_RESTORE_DEFAULT_FMRDO_BACKGROUND_PLAY  1
#define FACTORY_RESTORE_DEFAULT_FMRDO_SKIN  0
#define FACTORY_RESTORE_DEFAULT_FMRDO_VOLUME  4

#endif //__MMI_SECTION__ //__RESET_FACTORY__
#ifndef NEPTUNE_MMI
typedef enum 
{
	NVRAM_PHONELOCK_INDEX, 
	NVRAM_AUTOLOCK_TIMEOUT_INDEX,
	NVRAM_SETTING_PHONELOCK,
	NVRAM_SETTING_AUTOKEYPADLOCK,
	NVRAM_SETTING_AUTOREDIAL,
	NVRAM_SETTING_AUTOKEYPADLOCK_TIME, //5
	NVRAM_SETTING_WELCOME_TEXT,
	NVRAM_SETTING_APHORISM_TEXT,
	NVRAM_SETTING_CALL_TIME_DISPLAY,
	NVRAM_SETTING_SPEED_DIAL,
	NVRAM_SETTING_CONTRAST_LEVEL, //10
	NVRAM_SETTING_AUTOUPDATE_DT_TIME,
	NVRAM_SETTING_OWNER_NO,
	NVRAM_SETTING_STATUS_DT_TIME,
	NVRAM_SETTING_LANG,
	NVRAM_SETTING_CTR,//15
	NVRAM_SETTING_CONTRAST_SUBLCD_LEVEL,
	NVRAM_HELP_ENABLED_FLAG,
	NVRAM_PROFILES_ACTIVATED,
	NVRAM_CH_QUICK_END_FLAG,
	NVRAM_SMSCOUNTERS_SENT,//20
	NVRAM_SMSCOUNTERS_RECD,
	NVRAM_DOWNLOAD_IMAGE,
	NVRAM_DOWNLOAD_TONE,
	CURRENT_CITY,
	TIME_FORMAT,//25
	DATE_FORMAT,
	NVRAM_GAME_SNAKE_LEVEL,
	LUNAR_CALENDAR,
	NVRAM_DOWNLOAD_CITY1,
	NVRAM_DOWNLOAD_CITY2, //30
	NVRAM_SCREENSAVER_STATUS,		// 0 for Off, 1 for On
	NVRAM_SCREENSAVER_WAITING,		// 0 for 5 Sec, 1 for 15 Sec, 2 for 30 Sec, 3 for 1 Minute
	NVRAM_CALLERID,
	NVRAM_GROUPINDEX,
	NVRAM_GAME_RICHES_STATUS,//35
	NVRAM_RICHES_OPTION_STATUS,
	NVRAM_PROFILES_LASTACTIVATED,
	TOH_CURRENT_LEVEL,
	SMASH_CURRENT_LEVEL,
	NVRAM_SMS_ACTIVE_PROFILE_INDEX, //40
	NVRAM_SLAVE_ACTIVE_PROFILE_IDX,
	NVRAM_SIM3_ACTIVE_PROFILE_IDX,
	NVRAM_SIM4_ACTIVE_PROFILE_IDX,
	SMS_CONCAT_MSG_REF_VALUE,
	NVRAM_COLORBALLS_OPTION_STATUS,//45
	NVRAM_PROFILES_LOUDSPKR,
	RESTORE_DEFAULT_SPEED_DIAL,
	RESTORE_DEFAULT_CONTRAST_SUBLCD_LEVEL,
	RESTORE_DEFAULT_CONTRAST_LEVEL,
	RESTORE_DEFAULT_WELCOME_TEXT,//50
	RESTORE_DEFAULT_APHORISM_TEXT,
	RESTORE_DEFAULT_OWNER_NO,
	RESTORE_DEFAULT_STATUS_SHOW_DT_TIME,
	RESTORE_DEFAULT_AUTOUPDATE_TIME,
	RESTORE_DEFAULT_SCREENSAVER_STATUS,//55
	RESTORE_DEFAULT_SCREENSAVER_WAITING,	
	RESTORE_DEFAULT_PROFILES_ACTIVATED,
	RESTORE_DEFAULT_TIME_FORMAT,
	RESTORE_DEFAULT_DATE_FORMAT,
	NVRAM_DOWNLOAD_MELODY,//60
	NVRAM_NORMAL_MODE_VOICE_LEVEL,
	NVRAM_LDSPK_MODE_VOICE_LEVEL,
	NVRAM_HDSET_MODE_VOICE_LEVEL,
	NVRAM_NITZTIMEZONE,
	NVRAM_WALLPAPER_ROTATE_STATUS,//65
	NVRAM_GX_MAJUNG_LEVEL,
	NVRAM_GX_MEMORY_LEVEL,
	NVRAM_DEFAULT_USB_APP,
	/* FM Radio */
	NVRAM_FMRDO_BACKGROUND_PLAY,
	NVRAM_FMRDO_SKIN,//70
	NVRAM_FMRDO_VOLUME,
	/* Audio Player */
	NVRAM_AUDPLY_LIST_AUTO_GEN,
	NVRAM_AUDPLY_VOLUME,
	NVRAM_AUDPLY_PREFER_LIST,
	NVRAM_AUDPLY_SKIN,
	NVRAM_AUDPLY_REPEAT,
	NVRAM_AUDPLY_SHUFFLE,
	NVRAM_AUDPLY_BACKGROUND_PLAY,
	NVRAM_AUDPLY_LYRICS_DISPLAY,
	/* Sound Recorder */	
	NVRAM_SNDREC_STORAGE,
	NVRAM_SNDREC_FORMAT,
	NVRAM_IP_NUMBER_SETTING,
	NVRAM_SIM2_IP_NUMBER_SETTING,
	NVRAM_SIM3_IP_NUMBER_SETTING,
	NVRAM_SIM4_IP_NUMBER_SETTING,
	NVRAM_SET_MAINMENU_STYLE,
	NVRAM_EF_FMGR_SORT_OPTION_LID,
	NVRAM_GFX_AUDIO_SETTING,
	NVRAM_GFX_AUDIO_VOLUMN, 
	NVRAM_GFX_VIBRATION_SETTING,
	NVRAM_GX_PUZZLE_LEVEL,
	NVRAM_GX_STAIR_LEVEL,
	NVRAM_SETTING_DEF_ENCODING,
	NVRAM_STOPWATCH_TOTAL_RECORDS,
	/* Java Setting */	
	NVRAM_JAVA_SETTING_SOUND,
	NVRAM_JAVA_SETTING_PROF_ID,
	NVRAM_ALM_SNOOZE_TIME,
	NVRAM_VDOPLY_VOLUMN,
	NVRAM_SETTING_OPN_DISPLAY, 
	RESTORE_DEFAULT_OPN_DISPLAY,
	NVRAM_BLACK_LIST_SETTING,
	NVRAM_VRSD_RCG_SETTING, 
	NVRAM_PHB_SPEAK_NAME_ON_OFF,
	NVRAM_JAVA_SETTING_VIB,
	NVRAM_JAVA_SETTING_SIM_ID,
	NVRAM_JAVA_SETTING_BKL,
	NVRAM_JAVA_SETTING_LED,
	NVRAM_VRSI_RCG_SETTING, 
	NVRAM_IRDA_STORAGE,
	NVRAM_PEN_SPEED,
	NVRAM_PEN_COLOR,
	NVRAM_SETTING_DT_DST,
	NVRAM_SSC_DISABLE_FLAG,
	NVRAM_ABREPEAT_VOLUME,
	NVRAM_IMGVIEW_VIEW_SYTLE,
	NVRAM_ABREPEAT_STORAGE,
	NVRAM_WC_DST,
	NVRAM_GFX_BACKGROUND_MUSIC_SETTING,
	NVRAM_GFX_SOUND_EFFECT_SETTING,
	NVRAM_PHNSET_IDLE_CLOCK_TYPE,
	RESOTRE_DEFAULT_IDLE_CLOCK_TYPE,
	NVRAM_FMRDO_RECORD_FORMAT,
	NVRAM_FMRDO_RECORD_STORAGE,
	NVRAM_POC_ANS_MODE,
	NVRAM_POC_DND_MODE,
	NVRAM_POC_START_BOOTUP,
	NVRAM_POC_PROFILE_ACTIVE,
#if defined (__LED__) || defined (__MMI_RUNNING_LED__)	
	NVRAM_PHN_ENABLE_SCROLL_LIGHT,
#endif	
	NVRAM_SETTING_SOUND_WARNNING_TIME,
	NVRAM_FMRDO_AUDIO_OUT,	
	NVRAM_FMSR_AUDIO_OUT,
	NVRAM_USB_BOOT_MODE,		//licheng added for selected usb boot mode
#ifdef JATAAYU_SUPPORT
	NVRAM_PH_ACTIVATED_WAP_PROFILE_INDEX,
	NVRAM_PH_ACTIVATED_WAP_PROFILE_INDEX_SIM2,
	NVRAM_PH_ACTIVATED_WAP_PROFILE_INDEX_SIM3,
	NVRAM_PH_ACTIVATED_WAP_PROFILE_INDEX_SIM4,
	NVRAM_PH_ACTIVATED_MMS_PROFILE_INDEX,
	NVRAM_PH_ACTIVATED_MMS_PROFILE_INDEX_SIM2,
	NVRAM_PH_ACTIVATED_MMS_PROFILE_INDEX_SIM3,
	NVRAM_PH_ACTIVATED_MMS_PROFILE_INDEX_SIM4,
#ifdef __MMI_MULTI_SIM__
	NVRAM_MTPNP_WAP_PROFILE_SELECT_SIMTYPE,
#endif
#endif

#ifdef __MMI_MULTI_SIM__
	NVRAM_MTPNP_SMS_SHOW_STYLE,
#endif
	NVRAM_FTP_ACCESS_RIGHT,
#if defined(MOTION_SENSOR_SUPPORT)
	NVRAM_SETTING_MOTION_SENSOR,
#endif
#if defined(MMI_2D_SENSOR_SUPPORT)||defined(CAM_MD_SUPPORT)
	NVRAM_SETTING_2D_SENSOR,
#endif
#ifdef __MMI_CHANGE_WIN_WITH_DYNAMIC__
	NVRAM_CHANGE_SCREEN_MODE,
#endif
#ifdef MAGIC_AE_SUPPORT
	NVRAM_SETTING_MAGIC_SOUND_STATE,
#endif
#ifdef __FT_IDLE_SMART_DIAL__
	NVRAM_SETTING_DIAL_STYLE,
#endif
#ifdef __MMI_AUTO_PLUS_ENABLE__
	NVRAM_SETTING_AUTO_PLUSE_STATE,
#endif

#if defined(__MMI_NOKIA_STYLE_N800__)||defined(CAM_MD_SUPPORT)
        NVRAM_AUDPLY_ROTATED_ENABLE,
#endif

NVRAM_CUSTOMER_BT_STORGE_FLASH_SETTED,
        NVRAM_PWR_NOKIA_SETTED,
NVRAM_ANALOGTV_BRIGHT_SETTING,
NVRAM_GX_FRUIT_LEVEL,

#ifdef __MMI_MESSAGES_BLACK_LIST__
	NVRAM_MESSAGES_BLACK_LIST_SETTING,
#endif
#if defined(__MMI_SAVE_CURRENT_TIME__)
	NVRAM_SAVE_CURRENT_TIME,
#endif
#ifdef __NATIVE_JAVA__
	NVRAM_JAVA_SETTING_STORAGEPATH,
#endif

       NVRAM_LAST_BYTE_ELEMENT

}BYTEDATA;



typedef enum 
{
	NVRAM_SHORTDATA1_INDEX,
	NVRAM_SHORTDATA2_INDEX,
//	SPOF_RECORD_NVRAM_INDEX1,
//	SPOF_RECORD_NVRAM_INDEX2,
//	SPOF_RECORD_NVRAM_INDEX3,
//	SPOF_RECORD_NVRAM_INDEX4,
	NVRAM_SNAKE_LEVEL1_SCORE,
	NVRAM_SNAKE_LEVEL2_SCORE,
	NVRAM_SNAKE_LEVEL3_SCORE,
	NVRAM_SNAKE_LEVEL4_SCORE,
	NVRAM_F1RACE_SCORE,
    NVRAM_CURRENT_SCREENSVER_ID,
	NVRAM_PHB_STORAGE_LOCATION,
	NVRAM_FUNANDGAMES_SETWALLPAPER,
	NVRAM_GAME_DOLL_GRADE,
	TOH_LEVEL1_HIGHEST_SCORE,
	TOH_LEVEL2_HIGHEST_SCORE,
	TOH_LEVEL3_HIGHEST_SCORE,
	TOH_LEVEL4_HIGHEST_SCORE,
	NVRAM_RICHES_EASY_SCORE,
	NVRAM_RICHES_NORMAL_SCORE,
	NVRAM_RICHES_HARD_SCORE,
	NVRAM_COLORBALLS_EASY_SCORE,
	NVRAM_COLORBALLS_NORMAL_SCORE,
	NVRAM_COLORBALLS_HARD_SCORE,
	NVRAM_SMASH_NORMAL_SCORE,
	NVRAM_SMASH_SPEEDY_SCORE,
	NVRAM_SMASH_ACCURACY_SCORE,
	NVRAM_SETTING_CTR_TIME,
	NVRAM_SETTING_PREFER_INPUT_METHOD,
	RESTORE_DEFAULT_CURRENT_SCREENSVER_ID,
	RESTORE_DEFAULT_FUNANDGAMES_SETWALLPAPER,
	RESTORE_PREFER_INPUT_METHOD,
	NVRAM_GX_NINJA_SCORE,					/* Ninja Game */
	NVRAM_GX_MAJUNG_EASY_SCORE,			/* Majung Game */
	NVRAM_GX_MAJUNG_NORMAL_SCORE,		
	NVRAM_GX_MAJUNG_HARD_SCORE,		
	NVRAM_GX_MEMORY_EASY_SCORE,			/* Memory Game */
	NVRAM_GX_MEMORY_NORMAL_SCORE,
	NVRAM_GX_MEMORY_HARD_SCORE,	
	NVRAM_GX_COPTER_SCORE,				   /* Copter Game */
	NVRAM_GX_PUZZLE_EASY_SCORE,			/* Puzzle Game */
	NVRAM_GX_PUZZLE_NORMAL_SCORE,
	NVRAM_GX_PUZZLE_HARD_SCORE,
	NVRAM_GX_PANDA_SCORE,               /* Panda Game */
	NVRAM_GX_STAIR_EASY_SCORE,			   /* Stair Game */
	NVRAM_GX_STAIR_NORMAL_SCORE,
	NVRAM_GX_STAIR_HARD_SCORE,
	NVRAM_GX_UFO_SCORE,                 /* UFO Game */
	NVRAM_GX_DANCE_SCORE,               /* Dance Game */
	NVRAM_CAM_FILENAME_SEQ_NO,
	NVRAM_IMG_VIEWER_FILE_PATH,
	NVRAM_VDOREC_FILENAME_SEQ_NO,
	NVRAM_VDOPLY_SNAPSHOT_SEQ_NO,
	NVRAM_RESTORE_POWER_ON_DISPLAY,
	NVRAM_RESTORE_POWER_OFF_DISPLAY,
	NVRAM_CURRENT_POWER_ON_DISPLAY,
	NVRAM_CURRENT_POWER_OFF_DISPLAY,
	NVRAM_POWER_ON_DISPLAY_SUCCESS,
	NVRAM_POWER_OFF_DISPLAY_SUCCESS,
	NVRAM_SCREENSAVER_DISPLAY_SUCCESS,
	NVRAM_POWER_ON_FORCE_STOP_TIME,
	NVRAM_POWER_OFF_FORCE_STOP_TIME,
	NVRAM_SETWALLPAPER_SUB,/*59*/
	RESTORE_DEFAULT_SETWALLPAPER_SUB,  
	NVRAM_CH_QUICK_END_TIME,
	NVRAM_GX_MAGICSUSHI_SCORE,				/* Magicsushi Game */
	NVRAM_SCR_SNAPSHOT_SEQ_NO,	
	NVRAM_SETTING_TVOUT_FORMAT,
	NVRAM_SETTING_TVOUT_STYLE,
	NVRAM_AUDIO_MIC_VOLUME_SET,
        NVRAM_SMS_CONCAT_MSG_REF_VALUE,
	NVRAM_SMSCOUNTERS_SENT_SHORT,
	NVRAM_SIM2SMSCOUNTERS_SENT_SHORT, 
	NVRAM_SIM3SMSCOUNTERS_SENT_SHORT, 
	NVRAM_SIM4SMSCOUNTERS_SENT_SHORT, 
	NVRAM_SMSCOUNTERS_RECD_SHORT,
	NVRAM_SIM2SMSCOUNTERS_RECD_SHORT,
	NVRAM_SIM3SMSCOUNTERS_RECD_SHORT,
	NVRAM_SIM4SMSCOUNTERS_RECD_SHORT,
	NVRAM_EBOOK_NFO_LID,
	NVRAM_EBOOK_LAST_HIGHLIGHT_ID,
	NVRAM_FMRDO_FREQUENCY,					/* FM Radio Frequency*/
        NVRAM_GX_FRUIT_EASY_SCORE,
        NVRAM_GX_FRUIT_NORMAL_SCORE,        /* 70 */
        NVRAM_GX_FRUIT_HARD_SCORE,
	NVRAM_TIMEZONE,
	/* don not remove last element */
	NVRAM_LAST_ELEMENT
}SHORTDATA;


typedef enum 
{
//	ALARM_RECORD_NVRAM_INDEX1,
//	ALARM_RECORD_NVRAM_INDEX2,
//	ALARM_RECORD_NVRAM_INDEX3,
//	NVRAM_ALARMS_ALARMID,
	CURRENCY_CONVERTOR_EXCHANGE_RATE,
	NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE1,			/*Notice :: Don't Change the order*/
	NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE2,
	NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE3,
	NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE4,
	NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE5,
	NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE6,
	NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE7,
	NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE8,
	NVRAM_PEN_CALIBRATION_VALUE1,							/*Notice :: Don't Change the order*/
	NVRAM_PEN_CALIBRATION_VALUE2,
	NVRAM_PEN_CALIBRATION_VALUE3,
	NVRAM_PEN_CALIBRATION_VALUE4,
	NVRAM_PEN_CALIBRATION_VALUE5,
	NVRAM_PEN_CALIBRATION_VALUE6,
	NVRAM_PEN_CALIBRATION_VALUE7,
	NVRAM_PEN_CALIBRATION_VALUE8,
	THEME_MANAGER_MAX_THEME_ID,
	THEME_MANAGER_CURR_THEME_ID

}DOUBLEDATA;
#else
typedef enum 
{
	NVRAM_PHONELOCK_INDEX, //0
	NVRAM_AUTOLOCK_TIMEOUT_INDEX,
	NVRAM_SETTING_PHONELOCK,
	NVRAM_SETTING_AUTOKEYPADLOCK,
	NVRAM_SETTING_AUTOREDIAL,
	NVRAM_SETTING_AUTOKEYPADLOCK_TIME, //5
	NVRAM_SETTING_WELCOME_TEXT,
	NVRAM_SETTING_APHORISM_TEXT,
	NVRAM_SETTING_CALL_TIME_DISPLAY,
	NVRAM_SETTING_SPEED_DIAL,
	NVRAM_SETTING_CONTRAST_LEVEL, //10
	NVRAM_SETTING_AUTOUPDATE_DT_TIME,
	NVRAM_SETTING_OWNER_NO,
	NVRAM_SETTING_STATUS_DT_TIME,
	NVRAM_SETTING_LANG,//17
	NVRAM_SETTING_CTR,//15
	NVRAM_SETTING_CONTRAST_SUBLCD_LEVEL,
	NVRAM_HELP_ENABLED_FLAG,
	NVRAM_PROFILES_ACTIVATED,
	NVRAM_MISSED_CALL_NUM,
	NVRAM_SMSCOUNTERS_SENT,//20
	NVRAM_SMSCOUNTERS_RECD,
    NVRAM_DOWNLOAD_IMAGE,
	NVRAM_DOWNLOAD_TONE,
	CURRENT_CITY,
	TIME_FORMAT, //25
	DATE_FORMAT,
	NVRAM_GAME_SNAKE_LEVEL,
	LUNAR_CALENDAR,
	NVRAM_DOWNLOAD_CITY1,
	NVRAM_DOWNLOAD_CITY2, //30
	NVRAM_SCREENSAVER_STATUS,		// 0 for Off, 1 for On
	NVRAM_SCREENSAVER_WAITING,		// 0 for 5 Sec, 1 for 15 Sec, 2 for 30 Sec, 3 for 1 Minute
	NVRAM_CALLERID,
	NVRAM_GROUPINDEX,
    NVRAM_GAME_RICHES_STATUS,//35
	NVRAM_RICHES_OPTION_STATUS,
	NVRAM_PROFILES_LASTACTIVATED,
	TOH_CURRENT_LEVEL,
	SMASH_CURRENT_LEVEL,
	NVRAM_SMS_ACTIVE_PROFILE_INDEX, //40
	NVRAM_SLAVE_ACTIVE_PROFILE_IDX,
	NVRAM_SIM3_ACTIVE_PROFILE_IDX,
	NVRAM_SIM4_ACTIVE_PROFILE_IDX,
	SMS_CONCAT_MSG_REF_VALUE,
	NVRAM_COLORBALLS_OPTION_STATUS,
        NVRAM_PROFILES_LOUDSPKR,
	RESTORE_DEFAULT_SPEED_DIAL,//44
	RESTORE_DEFAULT_CONTRAST_SUBLCD_LEVEL, //45
	RESTORE_DEFAULT_CONTRAST_LEVEL,
	RESTORE_DEFAULT_WELCOME_TEXT,
	RESTORE_DEFAULT_APHORISM_TEXT,
	RESTORE_DEFAULT_OWNER_NO,
	RESTORE_DEFAULT_STATUS_SHOW_DT_TIME,//50
	RESTORE_DEFAULT_AUTOUPDATE_TIME,
	RESTORE_DEFAULT_SCREENSAVER_STATUS,
	RESTORE_DEFAULT_SCREENSAVER_WAITING,	
	RESTORE_DEFAULT_PROFILES_ACTIVATED,
	RESTORE_DEFAULT_TIME_FORMAT,//55
	RESTORE_DEFAULT_DATE_FORMAT,
        NVRAM_DOWNLOAD_MELODY,
		NVRAM_NORMAL_MODE_VOICE_LEVEL,
		NVRAM_LDSPK_MODE_VOICE_LEVEL,
		NVRAM_HDSET_MODE_VOICE_LEVEL,//60
		NVRAM_NITZTIMEZONE,
		NVRAM_WALLPAPER_ROTATE_STATUS,
	NVRAM_GX_MAJUNG_LEVEL,
	NVRAM_GX_MEMORY_LEVEL,
	NVRAM_DEFAULT_USB_APP,  //65
/* FM Radio */
	NVRAM_FMRDO_BACKGROUND_PLAY,
	NVRAM_FMRDO_SKIN,
	NVRAM_FMRDO_VOLUME,
/* Audio Player */
	NVRAM_AUDPLY_LIST_AUTO_GEN,
	NVRAM_AUDPLY_VOLUME,
	NVRAM_AUDPLY_PREFER_LIST,
	NVRAM_AUDPLY_SKIN,
	NVRAM_AUDPLY_REPEAT,
	NVRAM_AUDPLY_SHUFFLE,
	NVRAM_AUDPLY_BACKGROUND_PLAY,
/* Sound Recorder */	
	NVRAM_SNDREC_STORAGE,//70
	NVRAM_SNDREC_FORMAT,
	NVRAM_IP_NUMBER_SETTING,
	NVRAM_SIM2_IP_NUMBER_SETTING,
	NVRAM_SIM3_IP_NUMBER_SETTING,
	NVRAM_SIM4_IP_NUMBER_SETTING,
	NVRAM_SET_MAINMENU_STYLE,
   NVRAM_EF_FMGR_SORT_OPTION_LID, // ??
	NVRAM_GFX_AUDIO_SETTING,
	NVRAM_GFX_AUDIO_VOLUMN,
	NVRAM_GFX_VIBRATION_SETTING,
	NVRAM_GX_PUZZLE_LEVEL,
	NVRAM_GX_STAIR_LEVEL,
	NVRAM_SETTING_DEF_ENCODING,
	NVRAM_STOPWATCH_TOTAL_RECORDS,
/* Java Setting */	
	NVRAM_JAVA_SETTING_SOUND,
	NVRAM_JAVA_SETTING_VIB,
	NVRAM_JAVA_SETTING_SIM_ID,
	NVRAM_ALM_SNOOZE_TIME,
	NVRAM_SETTING_DISPLAY_CHAR_STATUS,	
	RESTORE_DEFAULT_STATUS_DISP_CHAR,
	NVRAM_BLACK_LIST_SETTING,
#ifdef __FT_IDLE_SMART_DIAL__
	NVRAM_SETTING_DIAL_STYLE,
#endif
#ifdef __MMI_MESSAGES_BLACK_LIST__
	NVRAM_MESSAGES_BLACK_LIST_SETTING,
#endif
#if defined(__MMI_SAVE_CURRENT_TIME__)
	NVRAM_SAVE_CURRENT_TIME,
#endif

	NVRAM_LAST_BYTE_ELEMENT

}BYTEDATA;



typedef enum 
{
	NVRAM_SHORTDATA1_INDEX,
	NVRAM_SHORTDATA2_INDEX,
//	SPOF_RECORD_NVRAM_INDEX1,
//	SPOF_RECORD_NVRAM_INDEX2,
//	SPOF_RECORD_NVRAM_INDEX3,
//	SPOF_RECORD_NVRAM_INDEX4,
	NVRAM_SNAKE_LEVEL1_SCORE,
	NVRAM_SNAKE_LEVEL2_SCORE,
	NVRAM_SNAKE_LEVEL3_SCORE,
	NVRAM_SNAKE_LEVEL4_SCORE,
	NVRAM_F1RACE_SCORE,
    NVRAM_CURRENT_SCREENSVER_ID,
	NVRAM_PHB_STORAGE_LOCATION,
	NVRAM_FUNANDGAMES_SETWALLPAPER,
	NVRAM_GAME_DOLL_GRADE,
	TOH_LEVEL1_HIGHEST_SCORE,
	TOH_LEVEL2_HIGHEST_SCORE,
	TOH_LEVEL3_HIGHEST_SCORE,
	TOH_LEVEL4_HIGHEST_SCORE,
	NVRAM_RICHES_EASY_SCORE,
	NVRAM_RICHES_NORMAL_SCORE,
	NVRAM_RICHES_HARD_SCORE,
	NVRAM_COLORBALLS_EASY_SCORE,
	NVRAM_COLORBALLS_NORMAL_SCORE,
	NVRAM_COLORBALLS_HARD_SCORE,
	NVRAM_SMASH_NORMAL_SCORE,
	NVRAM_SMASH_SPEEDY_SCORE,
	NVRAM_SMASH_ACCURACY_SCORE,
	NVRAM_SETTING_CTR_TIME,
	 
	NVRAM_SETTING_PREFER_INPUT_METHOD,
       //CSD end
        RESTORE_DEFAULT_CURRENT_SCREENSVER_ID,
	RESTORE_DEFAULT_FUNANDGAMES_SETWALLPAPER,
        
	RESTORE_PREFER_INPUT_METHOD,
	//CSD end
	NVRAM_GX_NINJA_SCORE,					/* Ninja Game */
	NVRAM_GX_MAJUNG_EASY_SCORE,			/* Majung Game */
	NVRAM_GX_MAJUNG_NORMAL_SCORE,		
	NVRAM_GX_MAJUNG_HARD_SCORE,		
	NVRAM_GX_MEMORY_EASY_SCORE,			/* Memory Game */
	NVRAM_GX_MEMORY_NORMAL_SCORE,
	NVRAM_GX_MEMORY_HARD_SCORE,	
	NVRAM_GX_COPTER_SCORE,				   /* Copter Game */
	NVRAM_GX_PUZZLE_EASY_SCORE,			/* Puzzle Game */
	NVRAM_GX_PUZZLE_NORMAL_SCORE,
	NVRAM_GX_PUZZLE_HARD_SCORE,
	NVRAM_GX_PANDA_SCORE,               /* Panda Game */
	NVRAM_GX_STAIR_EASY_SCORE,			   /* Stair Game */
	NVRAM_GX_STAIR_NORMAL_SCORE,
	NVRAM_GX_STAIR_HARD_SCORE,
	NVRAM_GX_UFO_SCORE,                 /* UFO Game */
	NVRAM_CAM_FILENAME_SEQ_NO,
	NVRAM_IMG_VIEWER_FILE_PATH,
	NVRAM_VDOREC_FILENAME_SEQ_NO,
	NVRAM_SMS_CONCAT_MSG_REF_VALUE,
	NVRAM_EBOOK_NFO_LID,
	NVRAM_EBOOK_LAST_HIGHLIGHT_ID,
	NVRAM_FMRDO_FREQUENCY,		/* FM Radio Frequency*/
	NVRAM_TIMEZONE,
	
	NVRAM_LAST_ELEMENT
}SHORTDATA;


typedef enum 
{
//	ALARM_RECORD_NVRAM_INDEX1,
//	ALARM_RECORD_NVRAM_INDEX2,
//	ALARM_RECORD_NVRAM_INDEX3,
//	NVRAM_ALARMS_ALARMID,
	CURRENCY_CONVERTOR_EXCHANGE_RATE
}DOUBLEDATA;


#endif
#endif

