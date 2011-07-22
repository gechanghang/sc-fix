#ifndef _RESOURCE_SHORTCUTS_H
#define _RESOURCE_SHORTCUTS_H

#include "mmi_features.h"
#include "globalmenuitems.h"
#include "mmi_data_types.h"
/*dongwg Add Start For 6152 Ver: TBM780  on 2007-8-14 13:26 */
#include "mdiplayer.h"
/*dongwg Add End  For 6152 Ver: TBM780  on 2007-8-14 13:26 */

#define	SHCT_MAX_CANDI_LIST 		50  
#define	SHCT_MAX_SEL_LIST 			10  

const U8 shct_max_list_cand    = SHCT_MAX_CANDI_LIST;
const U8 shct_max_list_default = SHCT_MAX_SEL_LIST;

/*Candidate List*/
const U16 gShctCandList[SHCT_MAX_CANDI_LIST]=
{
		MITEM101_PBOOK_SEARCH_ENTRY,
		MITEM102_PBOOK_NEW_ENTRY,
		MITEM109_PBOOK_CALLER_GROUPS,	
		MESSAGES_MENU_WMESSAGE_MENU_ID,	
		MITEM1101_PBOOK_MEMORY_STATUS,
		MITEM1102_PBOOK_STORAGE_LOCATION,		
		ORGANIZER_CALENDER_MENU,
#ifdef __MMI_STYLE_E71_QCIF_S__
		MAIN_MENU_ALARM_MENUID,
#else
		ORGANIZER_ALARM_MENU,
#endif		
#ifdef __MMI_SUPPORT_BLUETOOTH__
		MENU_CONN_BT_MAIN,
#endif //__MMI_SUPPORT_BLUETOOTH__
		MENU_MT_CALL_ALERT_TYPE,		
		MENU3104_VOICE_MEMO,
		MENU_TONE_SETUP,
		ORGANIZER_NOTEPAD_MENU,
		MENU_ID_CAMERA_APP,
		ORGANIZER_CALCULATOR_MENU,
		MAIN_MENU_PROFILES_MENUID,
		ORGANIZER_TODOLIST_MENU,		
		MENU_ID_FMRDO_MAIN,
		AUDIO_PLAYER_MAIN_MENUID,
		MENU_ID_VDOPLY_APP,
		MENU_ID_VDOREC_APP,
		MENU_ID_SNDREC_MAIN,				//Added by jinzh end:20070725
		MENU_ID_IMGVIEW_APP,
		MENU_SETTING_SCR_SVR,
		MENU_SETTING_WALLPAPER,
		MENU3105_GAMES,                     //Added by jinzh start:20070725
		MENU9165_PHONE_LOCK,
		MESSAGES_MENU_INBOX_MENUID,
#if defined(__MMI_FILE_MANAGER__)
		MAIN_MENU_FILE_MNGR_MENUID,
#endif
//add wap/mms		
#ifdef JATAAYU_SUPPORT
		WAP_MAIN_SCREEN_MENUID,
		MMS_MAIN_SCREEN_MENUID,
#endif

#if 0
		MITEM101_PBOOK_SEARCH_ENTRY,
		MITEM102_PBOOK_NEW_ENTRY,
		MITEM109_PBOOK_CALLER_GROUPS,
#if 0  //TBM780menu tree中已经删除这项了,Modified by jinzh:20070621
		MITEM105_PBOOK_OWNER_NUMBER,
#endif 
		MITEM1101_PBOOK_MEMORY_STATUS,
		MITEM1102_PBOOK_STORAGE_LOCATION,
		MENU9146_WELCOME_TEXT,
		MENU_SETTING_PREFERED_INPUT_METHOD,
#if 0    //状态
		MENU_SETTING_DEF_ENCODING_TYPE,
#endif
		MENU8237_SCR8093_MNGCALL_MENU_FWD,
		MENU_SETTING_WALLPAPER,
		MENU_SETTING_SCR_SVR,
#if 0   //对比度
		MENU_SETTING_CONTRAST_LEVEL,
#endif 
		MENU_SETTING_SCHEDULE_POWER,
		MENU9165_PHONE_LOCK,
		MENU3104_VOICE_MEMO,
		//MENU3101_THEMES,
		MAIN_MENU_PROFILES_MENUID,
		MENU_MT_CALL_ALERT_TYPE,
		MENU_TONE_SETUP,
		/*JINZH Add Start For 5605 Ver: TBM780  on 2007-8-2 13:35 */
		MENU_ID_IMGVIEW_APP,
		/*JINZH Add End  For 5605 Ver: TBM780  on 2007-8-2 13:35 */
		MENU3105_GAMES,                     //Added by jinzh start:20070725
		//MENU3101_THEMES1, //qiff del theme menu for M301 bug:10738
		AUDIO_PLAYER_MAIN_MENUID,
		MENU_ID_CAMERA_APP,
		MENU_ID_VDOPLY_APP,
		MENU_ID_SNDREC_MAIN,				//Added by jinzh end:20070725
		/*Guojian Add Start  Ver: Jessamine  on 2008-6-28 12:54 */
	//	MENU_ID_VDOREC_APP,
		MENU_ID_FMRDO_MAIN,
		MENU_ID_FMSR_MAIN,
#if 0 //def __MMI_PHOTOEDITOR__		 //qiff 2008/10/20 for greenstone bug:10104
		MENU_ID_PHOART_APP,//照片艺术家
#endif		
		/*Guojian Add End  Ver: Jessamine  on 2008-6-28 12:54 */
		 MENU8101_RECEIVED_CALLS,
		 MENU8102_DIALED_CALLS,
		 MENU8103_MISSED_CALLS,
		ORGANIZER_CALENDER_MENU,
		ORGANIZER_TODOLIST_MENU,
		ORGANIZER_ALARM_MENU,
		ORGANIZER_CALCULATOR_MENU,
		ORGANIZER_UNITCONVERTOR_MENU,
		ORGANIZER_CURRENCYCONVERTOR_MENU,
	//	ORGANIZER_HEALTH_MENU_BMI,
	//	ORGANIZER_HEALTH_MENU_MENSTRUAL,
	//	MITEM_WORLDCLOCK_BROWSECITY,
		MESSAGES_MENU_WMESSAGE_MENU_ID,
		MESSAGES_MENU_INBOX_MENUID,
		MESSAGES_MENU_OUTBOX_MENUID,
		MESSAGES_MENU_VMAIL_MENUID,
		MENU_ID_IMPS_MAIN,
		/*JINZH Add Start For 5605 Ver: TBM780  on 2007-8-2 13:35 */
		MAIN_MENU_FILE_MNGR_MENUID,
		/*JINZH Add End  For 5605 Ver: TBM780  on 2007-8-2 13:35 */
		MENU3103_RINGTONE_COMPOSER
#endif		
};

/*Default List*/
const U16 gShctDefaultList[SHCT_MAX_SEL_LIST]=
{
		MITEM102_PBOOK_NEW_ENTRY,
		MITEM101_PBOOK_SEARCH_ENTRY,
		MITEM109_PBOOK_CALLER_GROUPS,
#if 0	//TBM780menu tree中已经删除这些项了,Modified by jinzh:20070621
		MITEM105_PBOOK_OWNER_NUMBER,
#endif 
		MESSAGES_MENU_WMESSAGE_MENU_ID,  //added by jinzh:20070621  默认的快捷方式加入写短信一项
		MITEM1101_PBOOK_MEMORY_STATUS,
		MITEM1102_PBOOK_STORAGE_LOCATION,
		MENU9146_WELCOME_TEXT,
		MENU_SETTING_PREFERED_INPUT_METHOD,
		MENU_MT_CALL_ALERT_TYPE
};

/*Dedicated List*/
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
#define SHCT_DEFAULT_MENU_ID		0
typedef enum
{
		DEDICATED_KEY_UP		= 	0,
		DEDICATED_KEY_DOWN,
		DEDICATED_KEY_LEFT,
		DEDICATED_KEY_RIGHT,
		DEDICATED_KEY_OK,
		TOTAL_DEDICATED_KEYS
}SHCT_DEDICATED_KEY_ENUM;
const U16 gShctDefaultDediList[TOTAL_DEDICATED_KEYS]=
{
		/*dongwg Modify Start For 6152 Ver: TBM780  on 2007-8-14 13:7 */
		//AUDIO_PLAYER_MAIN_MENUID,
		AUDIO_PLAYER_MAIN_MENUID,
		/*dongwg Modify End  For 6152 Ver: TBM780  on 2007-8-14 13:7 */
		MESSAGES_MENU_WMESSAGE_MENU_ID,
		MESSAGES_MENU_INBOX_MENUID,
		MENU_TONE_SETUP,
		/*dongwg Modify Start For 6152 Ver: TBM780  on 2007-8-14 13:7 */
//		MAIN_MENU_SHORTCUTS_MENUID,
		SHCT_DEFAULT_MENU_ID, //guojian modified for jassmine 20080603
	    //MAIN_MENU_MULTIMEDIA_MENUID,
		/*dongwg Modify End  For 6152 Ver: TBM780  on 2007-8-14 13:7 */
};
#endif
#endif
