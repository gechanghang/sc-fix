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
 * MainMenuDef.h
 *
 * Project:
 * --------
 
 *
 * Description:
 * ------------
 *   This file is intends for main menu defination 
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

/**********************************************************************************
	Filename:		mainmenu_def.h
	Author:			
	Date Created:	September-07-2002
	Contains:		Main menu application
**********************************************************************************/

#ifndef MAINMENUDEF_H
#define MAINMENUDEF_H

#include "mmi_features.h"

/*+ zhouqin 2011-02-16 modify for q6 320X240 */
#ifdef __MMI_BLACK_BERRY_MAIN_MENU__
#define MAX_MAIN_MENU_ITEMS                  30
#else
#define MAX_MAIN_MENU_ITEMS						20
#endif
/*- zhouqin 2011-02-16 modify for q6 320X240 */

#define MAIN_MENU_SCREENID					(MAIN_MENU_BASE+1)
												
/*	Main menu string IDs	*/					
#define MAIN_MENU_PHONEBOOK_TEXT				(PHONE_BOOK_BASE+0)
#define MAIN_MENU_MESSAGES_TEXT					(MESSAGES_BASE+0)
#define MAIN_MENU_FUNANDGAMES_TEXT				(FUN_GAMES_BASE+0)
#define MAIN_MENU_ORGANIZER_TEXT				(ORGANIZER_BASE+0)
#define MAIN_MENU_SETTINGS_TEXT					(SETTINGS_BASE+0)
#define MAIN_MENU_CONNECT_TEXT					(CONNECTS_BASE+0)
#define MAIN_MENU_SHORTCUTS_TEXT				(SHORTCUTS_BASE+0)
#define MAIN_MENU_SERVICES_TEXT					(SERVICES_BASE+0)
#define MAIN_MENU_CALL_HISTORY_TEXT				(CALL_HISTORY + 0)
#define MAIN_MENU_PROFILES_TEXT					(PROFILES_BASE+0)
												
 
#define MAIN_MENU_FILE_MNGR_TEXT				(FILE_MANAGER_BASE+0)
#define MAIN_MENU_MMEDIA_TEXT					(MMEDIA_BASE+0)
#define MAIN_MENU_EXTRA_TEXT					(EXTRA_APP_BASE+0)


/*	Main menu image IDs		*/					

enum MAIN_MENU_TEXT_ID
{
	MAIN_MENU_TITLE_TEXT=MAIN_MENU_BASE+1,
	MAIN_MENU_MENU_TEXT,
	STR_699_SYSTEM_SHUTDOWN,
	MAIN_MENU_AVZONE_TEXT,
	MAIN_MENU_PIM_TEXT,
	MAIN_MENU_ENTERTAINMENT_TEXT,
	MAIN_MENU_SYSTEM_TEXT,
	MAIN_MENU_CAMERA_TEXT,
	MAIN_MENU_VDOREC_TEXT,
	MAIN_MENU_VDOPLY_TEXT,
	MAIN_MENU_AUDPLY_TEXT
#if defined(__MMI_MAINLCD_128X160__)
	, MAIN_MENU_FRIENDS_TEXT
	, MAIN_MENU_CHATTING_TEXT
	, MAIN_MENU_NEWS_TEXT
#endif
#if defined(__MMI_MAINLCD_160X128__)
    ,MAIN_MENU_MODETOOLS_TEXT
    ,MAIN_MENU_MATERIAL_TEXT
#endif
};

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__

enum MAIN_MENU_IMG_ID
{
#if !defined(__MMI_POWER_ON_OFF_DISPLAY__)
	IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT1=MAIN_MENU_BASE+1,
	IMG_SUBLCD_SYSTEM_SHUTDOWN,
#else	
	IMG_SUBLCD_SYSTEM_SHUTDOWN=MAIN_MENU_BASE+1,
#endif	

	IMG_MAIN_MENU_BG,
	IMG_MAIN_MENU_BG1,
	IMG_MAIN_MENU_BG2,
	IMG_MAIN_MENU_BG3,
	MAIN_MENU_TITLE_ICON,
#ifdef __MMI_MATRIX_MAIN_MENU_FULL_BACKGROUND__
	MAIN_MENU_MATRIX_SOFTKEY_BG,	  
#endif

#ifdef __MMI_MAINLCD_220X176__
	MAIN_MENU_MATRIX_ICON_IMGBASE, //14004
	MAIN_MENU_MATRIX_CALL_HISTORY_ICON,
	MAIN_MENU_MATRIX_PHONEBOOK_ICON,
	MAIN_MENU_MATRIX_MP3_ICON,
	MAIN_MENU_MATRIX_SERVICES_ICON,
	MAIN_MENU_MATRIX_MESSAGES_ICON,
	MAIN_MENU_MATRIX_FILEMNGR_ICON,
	MAIN_MENU_MATRIX_ORGANIZER_ICON,
	MAIN_MENU_MATRIX_MULTIMEDIA_ICON,
	MAIN_MENU_MATRIX_EXTRA_ICON,
	MAIN_MENU_MATRIX_FUNANDGAMES_ICON,
	MAIN_MENU_MATRIX_PROFILES_ICON,
	MAIN_MENU_MATRIX_SETTINGS_ICON,
	MAIN_MENU_MATRIX_SHORTCUTS_ICON, //14011
//	MAIN_MENU_MATRIX_MESSAGE_CLUB_ICON,
	//MAIN_MENU_MATRIX_EBOOK_ICON,
	MAIN_MENU_MATRIX_ICON_IMGBASE_MAX,


	MAIN_MENU_MATRIX_ICON_FOCUS_IMGBASE, //14004

	MAIN_MENU_MATRIX_CALL_HISTORY_ICON_FOCUS,
	MAIN_MENU_MATRIX_PHONEBOOK_ICON_FOCUS,
	MAIN_MENU_MATRIX_MP3_ICON_FOCUS,
	MAIN_MENU_MATRIX_SERVICES_ICON_FOCUS,
	MAIN_MENU_MATRIX_MESSAGES_ICON_FOCUS,
	MAIN_MENU_MATRIX_FILEMNGR_ICON_FOCUS,
	MAIN_MENU_MATRIX_ORGANIZER_ICON_FOCUS,
	MAIN_MENU_MATRIX_MULTIMEDIA_ICON_FOCUS,
	MAIN_MENU_MATRIX_EXTRA_ICON_FOCUS,
	MAIN_MENU_MATRIX_FUNANDGAMES_ICON_FOCUS,
	MAIN_MENU_MATRIX_PROFILES_ICON_FOCUS,

	MAIN_MENU_MATRIX_SETTINGS_ICON_FOCUS,
	//MAIN_MENU_MATRIX_SHORTCUTS_ICON_FOCUS, //14011
	//	MAIN_MENU_MATRIX_MESSAGE_CLUB_ICON,
	//MAIN_MENU_MATRIX_EBOOK_ICON,
	MAIN_MENU_MATRIX_ICON_FOCUS_IMGBASE_MAX,
		
	MAIN_MENU_MATRIX_ICON_ANI_IMGBASE,  //14019
	MAIN_MENU_MATRIX_CALL_HISTORY_ANIMATION,
	MAIN_MENU_MATRIX_PHONEBOOK_ANIMATION,
	MAIN_MENU_MATRIX_MP3_ANIMATION,
	MAIN_MENU_MATRIX_SERVICES_ANIMATION,
	MAIN_MENU_MATRIX_MESSAGES_ANIMATION,
	MAIN_MENU_MATRIX_FILEMNGR_ANIMATION,
	MAIN_MENU_MATRIX_ORGANIZER_ANIMATION,
	MAIN_MENU_MATRIX_MULTIMEDIA_ANIMATION,
	MAIN_MENU_MATRIX_EXTRA_ANIMATION,
	MAIN_MENU_MATRIX_FUNANDGAMES_ANIMATION,
	MAIN_MENU_MATRIX_PROFILES_ANIMATION,
	MAIN_MENU_MATRIX_SETTINGS_ANIMATION,
	MAIN_MENU_MATRIX_SHORTCUTS_ANIMATION,
//	MAIN_MENU_MATRIX_MESSAGE_CLUB_ANIMATION,
	//MAIN_MENU_MATRIX_EBOOK_ANIMATION,
	MAIN_MENU_MATRIX_ICON_ANI_IMGBASE_MAX,


	MAIN_MENU_PAGE_ICON_IMGBASE = MAIN_MENU_MATRIX_ICON_ANI_IMGBASE_MAX,
#else
	MAIN_MENU_MATRIX_ICON_IMGBASE, //14004
	MAIN_MENU_MATRIX_PHONEBOOK_ICON,
	MAIN_MENU_MATRIX_MESSAGES_ICON,
	MAIN_MENU_MATRIX_FUNANDGAMES_ICON,
	MAIN_MENU_MATRIX_ORGANIZER_ICON,
	MAIN_MENU_MATRIX_SETTINGS_ICON,
	MAIN_MENU_MATRIX_PROFILES_ICON,
	MAIN_MENU_MATRIX_SHORTCUTS_ICON, //14011
	MAIN_MENU_MATRIX_SERVICES_ICON,
	MAIN_MENU_MATRIX_CALL_HISTORY_ICON,
	MAIN_MENU_MATRIX_MULTIMEDIA_ICON,
	MAIN_MENU_MATRIX_FILEMNGR_ICON,
	MAIN_MENU_MATRIX_EXTRA_ICON,
	
//	MAIN_MENU_MATRIX_MESSAGE_CLUB_ICON,
	MAIN_MENU_MATRIX_EBOOK_ICON,
	MAIN_MENU_MATRIX_CAMERA_ICON,
	MAIN_MENU_MATRIX_ICON_IMGBASE_MAX,

	MAIN_MENU_MATRIX_ICON_ANI_IMGBASE,  //14019
	MAIN_MENU_MATRIX_PHONEBOOK_ANIMATION,
	MAIN_MENU_MATRIX_MESSAGES_ANIMATION,
	MAIN_MENU_MATRIX_FUNANDGAMES_ANIMATION,
	MAIN_MENU_MATRIX_ORGANIZER_ANIMATION,
	MAIN_MENU_MATRIX_SETTINGS_ANIMATION,
	MAIN_MENU_MATRIX_PROFILES_ANIMATION,
	MAIN_MENU_MATRIX_SHORTCUTS_ANIMATION,
	MAIN_MENU_MATRIX_SERVICES_ANIMATION,
	MAIN_MENU_MATRIX_CALL_HISTORY_ANIMATION,
	MAIN_MENU_MATRIX_MULTIMEDIA_ANIMATION,
	MAIN_MENU_MATRIX_FILEMNGR_ANIMATION,
	MAIN_MENU_MATRIX_EXTRA_ANIMATION,
//	MAIN_MENU_MATRIX_MESSAGE_CLUB_ANIMATION,
	MAIN_MENU_MATRIX_EBOOK_ANIMATION,
	MAIN_MENU_MATRIX_CAMERA_ANIMATION,
	MAIN_MENU_MATRIX_ICON_ANI_IMGBASE_MAX,


	MAIN_MENU_PAGE_ICON_IMGBASE = MAIN_MENU_MATRIX_ICON_ANI_IMGBASE_MAX,
#endif
	MAIN_MENU_PAGE_PHONEBOOK_ICON, //14034
	MAIN_MENU_PAGE_MESSAGES_ICON,
	MAIN_MENU_PAGE_FUNANDGAMES_ICON,
	MAIN_MENU_PAGE_ORGANIZER_ICON,
	MAIN_MENU_PAGE_SETTINGS_ICON,
	MAIN_MENU_PAGE_PROFILES_ICON,
	MAIN_MENU_PAGE_SHORTCUTS_ICON,
	MAIN_MENU_PAGE_SERVICES_ICON,
	MAIN_MENU_PAGE_CALL_HISTORY_ICON,
	MAIN_MENU_PAGE_MULTIMEDIA_ICON,
	MAIN_MENU_PAGE_FILEMNGR_ICON,
	MAIN_MENU_PAGE_EXTRA_ICON,
	MAIN_MENU_PAGE_EBOOK_ICON,	   //GUOJIAN ADDED
	MAIN_MENU_PAGE_ICON_IMGBASE_MAX,

	MAIN_MENU_LIST_ICON_IMGBASE,
	MAIN_MENU_LIST_PHONEBOOK_ICON,
	MAIN_MENU_LIST_MESSAGES_ICON,
	MAIN_MENU_LIST_FUNANDGAMES_ICON,
	MAIN_MENU_LIST_ORGANIZER_ICON,
	MAIN_MENU_LIST_SETTINGS_ICON,
	MAIN_MENU_LIST_PROFILES_ICON,
	MAIN_MENU_LIST_SHORTCUTS_ICON,
	MAIN_MENU_LIST_SERVICES_ICON,
	MAIN_MENU_LIST_CALL_HISTORY_ICON,
	MAIN_MENU_LIST_MULTIMEDIA_ICON,
	MAIN_MENU_LIST_FILEMNGR_ICON,
	MAIN_MENU_LIST_EXTRA_ICON,
	MAIN_MENU_LIST_ICON_IMGBASE_MAX,


	MAIN_MENU_CIRCULAR_ICON_IMGBASE,
	MAIN_MENU_CIRCULAR_PHONEBOOK_ICON,
	MAIN_MENU_CIRCULAR_MESSAGES_ICON,
	MAIN_MENU_CIRCULAR_FUNANDGAMES_ICON,
	MAIN_MENU_CIRCULAR_ORGANIZER_ICON,
	MAIN_MENU_CIRCULAR_SETTINGS_ICON,
	MAIN_MENU_CIRCULAR_PROFILES_ICON,
	MAIN_MENU_CIRCULAR_SHORTCUTS_ICON,
	MAIN_MENU_CIRCULAR_SERVICES_ICON,
	MAIN_MENU_CIRCULAR_CALL_HISTORY_ICON,
	MAIN_MENU_CIRCULAR_MULTIMEDIA_ICON,
	MAIN_MENU_CIRCULAR_FILEMNGR_ICON,
	MAIN_MENU_CIRCULAR_EXTRA_ICON,
	MAIN_MENU_CIRCULAR_ICON_IMGBASE_MAX,

	//////////ROTATE Main Menu//////////////
	MAIN_MENU_ROTATE_ICON_IMGBASE,
	MAIN_MENU_ROTATE_PHONEBOOK_ICON,
	MAIN_MENU_ROTATE_MESSAGES_ICON,
	MAIN_MENU_ROTATE_FUNANDGAMES_ICON,
	MAIN_MENU_ROTATE_ORGANIZER_ICON,
	MAIN_MENU_ROTATE_SETTINGS_ICON,
	MAIN_MENU_ROTATE_PROFILES_ICON,
	MAIN_MENU_ROTATE_SHORTCUTS_ICON,
	MAIN_MENU_ROTATE_SERVICES_ICON,
	MAIN_MENU_ROTATE_CALL_HISTORY_ICON,
	MAIN_MENU_ROTATE_MULTIMEDIA_ICON,
	MAIN_MENU_ROTATE_FILEMNGR_ICON,
	MAIN_MENU_ROTATE_EXTRA_ICON,
	MAIN_MENU_ROTATE_ICON_IMGBASE_MAX,

 
	//////////TAB Main Menu//////////////
	MAIN_MENU_TAB_ICON_IMGBASE,
	MAIN_MENU_TAB_PHONEBOOK_ICON,
	MAIN_MENU_TAB_MESSAGES_ICON,
	MAIN_MENU_TAB_FUNANDGAMES_ICON,
	MAIN_MENU_TAB_ORGANIZER_ICON,
	MAIN_MENU_TAB_SETTINGS_ICON,
	MAIN_MENU_TAB_PROFILES_ICON,
	MAIN_MENU_TAB_SHORTCUTS_ICON,
	MAIN_MENU_TAB_SERVICES_ICON,
	MAIN_MENU_TAB_CALL_HISTORY_ICON,
	MAIN_MENU_TAB_MULTIMEDIA_ICON,
	MAIN_MENU_TAB_FILEMNGR_ICON,
	MAIN_MENU_TAB_EXTRA_ICON,
	MAIN_MENU_TAB_ICON_IMGBASE_MAX,
 
	////////////////////////////////////
	/* Default Icon is Matrix */
	MAIN_MENU_ICON_IMGBASE,
	MAIN_MENU_PHONEBOOK_ICON,
	MAIN_MENU_MESSAGES_ICON,
	MAIN_MENU_FUNANDGAMES_ICON,
	MAIN_MENU_ORGANIZER_ICON,
	MAIN_MENU_SETTINGS_ICON,
	MAIN_MENU_PROFILES_ICON,
	MAIN_MENU_SHORTCUTS_ICON,
	MAIN_MENU_SERVICES_ICON,
	MAIN_MENU_CALL_HISTORY_ICON,
	MAIN_MENU_MULTIMEDIA_ICON,
	MAIN_MENU_FILEMNGR_ICON,
	MAIN_MENU_EXTRA_ICON,
//	MAIN_MENU_MESSAGE_CLUB_ICON,
    MIAN_MENU_EBOOK_ICON,
	MAIN_MENU_CAMERA_ICON,
	MAIN_MENU_ICON_IMGBASE_MAX,


	MAIN_MENU_ICON_ANI_IMGBASE,
	MAIN_MENU_PHONEBOOK_ANIMATION,
	MAIN_MENU_MESSAGES_ANIMATION,
	MAIN_MENU_FUNANDGAMES_ANIMATION,
	MAIN_MENU_ORGANIZER_ANIMATION,
	MAIN_MENU_SETTINGS_ANIMATION,
	MAIN_MENU_PROFILES_ANIMATION,
	MAIN_MENU_SHORTCUTS_ANIMATION,
	MAIN_MENU_SERVICES_ANIMATION,
	MAIN_MENU_CALL_HISTORY_ANIMATION,
	MAIN_MENU_MULTIMEDIA_ANIMATION,
	MAIN_MENU_FILEMNGR_ANIMATION,
	MAIN_MENU_EXTRA_ANIMATION,
//	MAIN_MENU_MESSAGE_CLUB_ANIMATION,
	MAIN_MENU_EBOOK_ANIMATION,
	MAIN_MENU_CAMERA_ANIMATION,
	MAIN_MENU_ICON_ANI_IMGBASE_MAX,
	
	MAIN_MENU_BG_IMAGE_BASE,
	MAIN_MENU_PHONEBOOK_BG_IMAGE,
	MAIN_MENU_MESSAGES_BG_IMAGE,
	MAIN_MENU_CALL_HISTORY_BG_IMAGE,
	MAIN_MENU_SETTINGS_BG_IMAGE,
	MAIN_MENU_FUNANDGAMES_BG_IMAGE,
	MAIN_MENU_PROFILES_BG_IMAGE,
	MAIN_MENU_ORGANIZER_BG_IMAGE,
	MAIN_MENU_SERVICES_BG_IMAGE,
	MAIN_MENU_SHORTCUTS_BG_IMAGE,

	MAIN_MENU_TITLE_ICON_BASE, //14144
	MAIN_MENU_TITLE_PHONEBOOK_ICON,
	MAIN_MENU_TITLE_MESSAGES_ICON,
	MAIN_MENU_TITLE_FUNANDGAMES_ICON,
	MAIN_MENU_TITLE_ORGANIZER_ICON,
	MAIN_MENU_TITLE_SETTINGS_ICON,
	MAIN_MENU_TITLE_PROFILES_ICON,
	MAIN_MENU_TITLE_SHORTCUTS_ICON,
	MAIN_MENU_TITLE_SERVICES_ICON,
	MAIN_MENU_TITLE_CALL_HISTORY_ICON,
	MAIN_MENU_TITLE_MULTIMEDIA_ICON,
	MAIN_MENU_TITLE_FILE_MNGR_ICON,
	MAIN_MENU_TITLE_EXTRA_APP_ICON,
//	MAIN_MENU_TITLE_MESSAGE_CLUB_ICON,
	MAIN_MENU_TITLE_EBOOK_ICON,  //14157
	MAIN_MENU_TITLE_CAMERA_ICON,

	IMG_MAIN_MENU_CIRCULAR_BG

	 
	,MAIN_MENU_MATRIX_TITLE_BG,
	MAIN_MENU_PAGE_TITLE_BG,
	MAIN_MENU_LIST_TITLE_BG
	 
	/*wuzc Add Start For GDI/GUI Portting Ver:    on 2008-3-18 15:58 */
	,IMG_MAIN_MENU_MATRIX_BG
	/*wuzc Add End  For GDI/GUI Portting Ver:    on 2008-3-18 15:58 */
#ifdef __T800_MAIN_MENU__
      ,IMG_ID_CALL_HISTORY
#endif
      ,MAIN_MENU_SELECT_BG_ICON

};


#else /* !__MMI_MAINMENU_STYLE_CHANGE_EN__ */
/********************************************************
Note : __MMI_BI_DEGREE_MAIN_MENU_STYLE__ shall be enabled 
	only when __MMI_MAINMENU_STYLE_CHANGE_EN__ is disabled 
********************************************************/
enum MAIN_MENU_IMG_ID
{
#if !defined(__MMI_POWER_ON_OFF_DISPLAY__)
//	IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT1=MAIN_MENU_BASE+1,
	IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT1=MAIN_MENU_BI_DEGREE_BASE+1,
	IMG_SUBLCD_SYSTEM_SHUTDOWN,
#else	
//	IMG_SUBLCD_SYSTEM_SHUTDOWN=MAIN_MENU_BASE+1,
	IMG_SUBLCD_SYSTEM_SHUTDOWN=MAIN_MENU_BI_DEGREE_BASE+1,
#endif	

	IMG_MAIN_MENU_BG,  //43802
	IMG_MAIN_MENU_BG1,
	IMG_MAIN_MENU_BG2,
	IMG_MAIN_MENU_BG3,
	MAIN_MENU_TITLE_ICON,
#ifdef __MMI_MATRIX_MAIN_MENU_FULL_BACKGROUND__
	MAIN_MENU_MATRIX_SOFTKEY_BG,	  
#endif

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
	MAIN_MENU_AVZONE_ICON,
	MAIN_MENU_AVZONE_ICON_SELECTED,
	MAIN_MENU_AVZONE_TITLE,
	MAIN_MENU_PIM_ICON,
	MAIN_MENU_PIM_ICON_SELECTED,
	MAIN_MENU_ENTERTAINMENT_ICON,
	MAIN_MENU_ENTERTAINMENT_ICON_SELECTED,
	MAIN_MENU_SYSTEM_ICON,
	MAIN_MENU_SYSTEM_ICON_SELECTED,
#endif
	MAIN_MENU_ICON_IMGBASE,
/*+ zhouqin 2011-02-16 modify for q6 320X240 */
	#ifdef __MMI_BLACK_BERRY_MAIN_MENU__
		MAIN_MENU_ICON_01,
		MAIN_MENU_ICON_02,
		MAIN_MENU_ICON_03,
		MAIN_MENU_ICON_04,
		MAIN_MENU_ICON_05,
		MAIN_MENU_ICON_06,
		MAIN_MENU_ICON_07,
		MAIN_MENU_ICON_08,
		MAIN_MENU_ICON_09,
		MAIN_MENU_ICON_10,
		MAIN_MENU_ICON_11,
		MAIN_MENU_ICON_12,
		MAIN_MENU_ICON_13,
		MAIN_MENU_ICON_14,

		MAIN_MENU_ICON_15,
		MAIN_MENU_ICON_16,
		MAIN_MENU_ICON_17,
		MAIN_MENU_ICON_18,
		MAIN_MENU_ICON_19,
		MAIN_MENU_ICON_20,
		MAIN_MENU_ICON_21,
		MAIN_MENU_ICON_22,
		MAIN_MENU_ICON_23,
		MAIN_MENU_ICON_24,
		MAIN_MENU_ICON_25,
		MAIN_MENU_ICON_26,
	#endif
/*- zhouqin 2011-02-16 modify for q6 320X240 */

	MAIN_MENU_PHONEBOOK_ICON,
	MAIN_MENU_MESSAGES_ICON,
	MAIN_MENU_FUNANDGAMES_ICON,
	MAIN_MENU_ORGANIZER_ICON,
	MAIN_MENU_SETTINGS_ICON,
	MAIN_MENU_PROFILES_ICON,
	MAIN_MENU_SHORTCUTS_ICON,
	MAIN_MENU_SERVICES_ICON,
	MAIN_MENU_CALL_HISTORY_ICON,
	MAIN_MENU_MULTIMEDIA_ICON,
	MAIN_MENU_FILEMNGR_ICON,
	MAIN_MENU_EXTRA_ICON,
#ifdef __MMI_MAINLCD_128X160__
			MAIN_MENU_FRIENDS_ICON,
			MAIN_MENU_CHATTING_ICON,
			MAIN_MENU_NEWS_ICON,
#endif
	//MAIN_MENU_MESSAGE_CLUB_ICON,
	MAIN_MENU_TITLE_EBOOK_ICON,
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
	MAIN_MENU_CAMERA_ICON,
	MAIN_MENU_VDOREC_ICON,
	MAIN_MENU_VDOPLY_ICON,
	MAIN_MENU_AUDPLY_ICON,
#endif
	MAIN_MENU_CAMERA_ICON,
	MAIN_MENU_SELECT_BG_ICON,

#ifdef __MMI_MAINLCD_220X176__
	/* Default Icon is Matrix */
	MAIN_MENU_TITLE_ICON_BASE, //14144
	MAIN_MENU_TITLE_MESSAGES_ICON,
	MAIN_MENU_TITLE_PHONEBOOK_ICON,
	MAIN_MENU_TITLE_CALL_HISTORY_ICON,
	MAIN_MENU_TITLE_ORGANIZER_ICON,
	MAIN_MENU_TITLE_SETTINGS_ICON,
	MAIN_MENU_TITLE_FM_RADIO_ICON,
	MAIN_MENU_TITLE_ALARM_ICON,
	MAIN_MENU_TITLE_SERVICES_ICON,
	MAIN_MENU_TITLE_FUNANDGAMES_ICON,
	
	MAIN_MENU_TITLE_PROFILES_ICON,
	MAIN_MENU_TITLE_SHORTCUTS_ICON,
	MAIN_MENU_TITLE_MULTIMEDIA_ICON,
	MAIN_MENU_TITLE_FILE_MNGR_ICON,
	MAIN_MENU_TITLE_EXTRA_APP_ICON,
	MAIN_MENU_TITLE_MESSAGE_CLUB_ICON,
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
	MAIN_MENU_TITLE_CAMERA_ICON,
	MAIN_MENU_TITLE_VDOREC_ICON,
	MAIN_MENU_TITLE_VDOPLY_ICON,
	MAIN_MENU_TITLE_AUDPLY_ICON,
#endif

#else
	MAIN_MENU_TITLE_ICON_BASE,
	MAIN_MENU_TITLE_PHONEBOOK_ICON,
	MAIN_MENU_TITLE_MESSAGES_ICON,
	MAIN_MENU_TITLE_FUNANDGAMES_ICON,
	MAIN_MENU_TITLE_ORGANIZER_ICON,
	MAIN_MENU_TITLE_SETTINGS_ICON,
	MAIN_MENU_TITLE_PROFILES_ICON,
	MAIN_MENU_TITLE_SHORTCUTS_ICON,
	MAIN_MENU_TITLE_SERVICES_ICON,
	MAIN_MENU_TITLE_CALL_HISTORY_ICON,
	MAIN_MENU_TITLE_MULTIMEDIA_ICON,
	MAIN_MENU_TITLE_FILE_MNGR_ICON,
	MAIN_MENU_TITLE_EXTRA_APP_ICON,
	MAIN_MENU_TITLE_MESSAGE_CLUB_ICON,
	MAIN_MENU_TITLE_CAMERA_ICON,
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
	MAIN_MENU_TITLE_CAMERA_ICON,
	MAIN_MENU_TITLE_VDOREC_ICON,
	MAIN_MENU_TITLE_VDOPLY_ICON,
	MAIN_MENU_TITLE_AUDPLY_ICON,
#endif
#endif
	MAIN_MENU_BG_IMAGE_BASE,
	MAIN_MENU_PHONEBOOK_BG_IMAGE,
	MAIN_MENU_MESSAGES_BG_IMAGE,
	MAIN_MENU_CALL_HISTORY_BG_IMAGE,
	MAIN_MENU_SETTINGS_BG_IMAGE,
	MAIN_MENU_FUNANDGAMES_BG_IMAGE,
	MAIN_MENU_PROFILES_BG_IMAGE,
	MAIN_MENU_ORGANIZER_BG_IMAGE,
	MAIN_MENU_SERVICES_BG_IMAGE,
	MAIN_MENU_SHORTCUTS_BG_IMAGE,

	MAIN_MENU_ICON_ANI_IMGBASE,
/*+ zhouqin 2011-02-16 modify for q6 320X240 */
#ifdef __MMI_BLACK_BERRY_MAIN_MENU__
	MAIN_MENU_ICON_ANI_01,
	MAIN_MENU_ICON_ANI_02,
	MAIN_MENU_ICON_ANI_03,
	MAIN_MENU_ICON_ANI_04,
	MAIN_MENU_ICON_ANI_05,
	MAIN_MENU_ICON_ANI_06,
	MAIN_MENU_ICON_ANI_07,
	MAIN_MENU_ICON_ANI_08,
	MAIN_MENU_ICON_ANI_09,
	MAIN_MENU_ICON_ANI_10,
	MAIN_MENU_ICON_ANI_11,
	MAIN_MENU_ICON_ANI_12,
	MAIN_MENU_ICON_ANI_13,
	MAIN_MENU_ICON_ANI_14,
	MAIN_MENU_ICON_ANI_15,
	MAIN_MENU_ICON_ANI_16,
	MAIN_MENU_ICON_ANI_17,
	MAIN_MENU_ICON_ANI_18,
	MAIN_MENU_ICON_ANI_19,
	MAIN_MENU_ICON_ANI_20,
	MAIN_MENU_ICON_ANI_21,
	MAIN_MENU_ICON_ANI_22,
	MAIN_MENU_ICON_ANI_23,
	MAIN_MENU_ICON_ANI_24,
	MAIN_MENU_ICON_ANI_25,
	MAIN_MENU_ICON_ANI_26,
#endif
/*- zhouqin 2011-02-16 modify for q6 320X240 */

	MAIN_MENU_PHONEBOOK_ANIMATION,
	MAIN_MENU_MESSAGES_ANIMATION,
	MAIN_MENU_FUNANDGAMES_ANIMATION,
	MAIN_MENU_ORGANIZER_ANIMATION,
	MAIN_MENU_SETTINGS_ANIMATION,
	MAIN_MENU_PROFILES_ANIMATION,
	MAIN_MENU_SHORTCUTS_ANIMATION,
	MAIN_MENU_SERVICES_ANIMATION,
	MAIN_MENU_CALL_HISTORY_ANIMATION,
	MAIN_MENU_MULTIMEDIA_ANIMATION,
	MAIN_MENU_FILEMNGR_ANIMATION,
	MAIN_MENU_EXTRA_ANIMATION,
#ifdef __MMI_MAINLCD_128X160__
		MAIN_MENU_FRIENDS_ANIMATION,
		MAIN_MENU_CHATTING_ANIMATION,
		MAIN_MENU_NEWS_ANIMATION,
#endif
	MAIN_MENU_MESSAGE_CLUB_ANIMATION,
	MAIN_MENU_ICON_ANI_IMGBASE_MAX,

	 
	MAIN_MENU_MATRIX_TITLE_BG,
	MAIN_MENU_PAGE_TITLE_BG,
	MAIN_MENU_LIST_TITLE_BG,
	 
	/*wuzc Add Start For GDI/GUI Portting Ver:    on 2008-3-18 15:58 */
	IMG_MAIN_MENU_MATRIX_BG
	/*wuzc Add End  For GDI/GUI Portting Ver:    on 2008-3-18 15:58 */
#ifdef __T800_MAIN_MENU__
      ,IMG_ID_CALL_HISTORY
#endif

};


#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */



#endif//MAINMENUDEF_H

