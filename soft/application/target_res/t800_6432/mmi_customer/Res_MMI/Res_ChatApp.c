/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of CoolSand Inc. (C) 2005
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

/**************************************************************

	FILENAME	: Res_.c

  	PURPOSE		: Populate Resource for 

 

 

	DATE		: Feb-23-2004

**************************************************************/
 #include "cs_types.h"
#include "custdatares.h"
#include "gui_data_types.h"
#include "stdc.h"
#include "customcfg.h"
#include "mmi_features.h"
#ifdef __MMI_MESSAGES_CHAT__
#include "chatappdef.h"

#ifdef FIRST_PASS
#include "buildcfg.h"
#endif

#include "wgui_categories.h"

#ifdef __MMI_MULTI_SIM__
#include "mtpnp_ad_resdef.h"
#endif



#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "populateres.h"
#include "custresdef.h"
#include "messagesresourcedata.h"



void PopulateChatAppImgRes();
void PopulateChatAppStrRes();
void PopulateChatAppMenuRes();
void PopulateChatAppMenuRes(void)
{
	ADD_APPLICATION_MENUITEM((MENU_CHATAPP_ID,MAIN_MENU_MESSAGES_MENUID,2,
								MENU_CHAT_ROOM1,
								MENU_CHAT_ROOM2,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_ROOM_MENU_TEXT,IMG_CHAT_MESSAGE_ID));
	
	ADD_APPLICATION_MENUITEM((MENU_CHAT_ROOM1,MENU_CHATAPP_ID,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_STRING1,0));
	
	ADD_APPLICATION_MENUITEM((MENU_DEACTIVE_CHAT_ROOM,0,2,
								MENU_CHATROOM_INFO,
								MENU_START_NEW,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_ROOM_TEXT,0));
	ADD_APPLICATION_MENUITEM((MENU_ACTIVE_CHAT_ROOM,0,3,
								MENU_CHATROOM_INFO,
								MENU_RESUME_CHAT,
								MENU_END_CHAT,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_ROOM_TEXT,0));

	ADD_APPLICATION_MENUITEM((MENU_CHAT_ROOM2,MENU_CHATAPP_ID,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_STRING2,0));
	ADD_APPLICATION_MENUITEM((MENU_CHATROOM_INFO,MENU_ACTIVE_CHAT_ROOM,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_ROOM_INFO_STR,0));
	#ifndef __MMI_MULTI_SIM__
	ADD_APPLICATION_MENUITEM((MENU_START_NEW,MENU_DEACTIVE_CHAT_ROOM,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_ROOM_NEW_STR,0));
	#else /* __MMI_MULTI_SIM__ */
	U8 i;
	ADD_APPLICATION_MENUITEM((MENU_START_NEW,MENU_DEACTIVE_CHAT_ROOM,MMI_SIM_NUMBER,
								MULTI_MENU(MENU_MTPNP_CHARSTART_MASTER_NEW),
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_ROOM_NEW_STR,0));
    #if 0
	for(i = 0; i < MMI_SIM_NUMBER; i++)
	{
		ADD_APPLICATION_MENUITEM((MENU_MTPNP_CHARSTART_MASTER_NEW + i,MENU_START_NEW,0,
									SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STRING_MTPNP_CHOOSE_MASTER_CHAT + i,0));
	}
    #endif
		ADD_APPLICATION_MENUITEM((MENU_MTPNP_CHARSTART_MASTER_NEW ,MENU_START_NEW,0,
									SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STRING_MTPNP_CHOOSE_MASTER_CHAT ,0));
		ADD_APPLICATION_MENUITEM((MENU_MTPNP_CHARSTART_MASTER_NEW + 1,MENU_START_NEW,0,
									SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STRING_MTPNP_CHOOSE_MASTER_CHAT + 1,0));
		ADD_APPLICATION_MENUITEM((MENU_MTPNP_CHARSTART_MASTER_NEW + 2,MENU_START_NEW,0,
									SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STRING_MTPNP_CHOOSE_MASTER_CHAT + 2,0));
	#endif /* __MMI_MULTI_SIM__ */
	ADD_APPLICATION_MENUITEM((MENU_RESUME_CHAT,MENU_ACTIVE_CHAT_ROOM,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_ROOM_RESUME,0));
	ADD_APPLICATION_MENUITEM((MENU_END_CHAT,MENU_ACTIVE_CHAT_ROOM,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_ROOM_END,0));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_OPTION,0,5,
								MENU_CHATMSG_SEND,
								MENU_CHATAPP_TEMPLATE,
								MENU_CHAT_PHB_NUM,
								MENU_CHAT_PHB_NAM,
								MENU_CHAT_INPUT_METHOD,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_CHAT_OPTIONS,IMG_GLOBAL_OPTIONS));
	ADD_APPLICATION_MENUITEM((MENU_CHATMSG_SEND,MENU_CHAT_OPTION,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_GLOBAL_SEND,0));
	ADD_APPLICATION_MENUITEM((MENU_CHATAPP_TEMPLATE,MENU_CHAT_OPTION,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_GLOBAL_USE_TEMPLATE,0));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_PHB_NUM,MENU_CHAT_OPTION,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_PHB_NUM_STR,0));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_PHB_NAM,MENU_CHAT_OPTION,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_PHB_NAME_STR,0));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_INPUT_METHOD,MENU_CHAT_OPTION,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_GLOBAL_INPUT_METHOD,0));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_ROOM_SCRN,0,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTIONS));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_OPTION_SCRN,0,6,
								MENU_CHAT_REPLY_SCRN,
								MENU_CHAT_USE_NUM_SCRN,
								MENU_CHAT_CLEAR_SCRN,
								MENU_CHAT_TEMP_SCRN,
								MENU_CHAT_QUIT_SCRN,
								MENU_CHATROOM_INFO,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTIONS));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_REPLY_SCRN,MENU_CHAT_OPTION_SCRN,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_GLOBAL_REPLY,0));

	ADD_APPLICATION_MENUITEM((MENU_CHAT_USE_NUM_SCRN,MENU_CHAT_OPTION_SCRN,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_CHAT_USE_NUMBER,0));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_CLEAR_SCRN,MENU_CHAT_OPTION_SCRN,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_CHAT_CLEAR_CHAT,0));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_TEMP_SCRN,MENU_CHAT_OPTION_SCRN,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_CHAT_TEMP_LEAVE,0));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_QUIT_SCRN,MENU_CHAT_OPTION_SCRN,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_CHAT_QUIT,0));

}

void PopulateChatAppRes(void){
	PopulateChatAppImgRes();
	PopulateChatAppStrRes();
	PopulateChatAppMenuRes();
}
void PopulateChatAppStrRes(){
	ADD_APPLICATION_STRING2( CHAT_STRING_ID, "ChatApp","ChatApp_String_ID" );
	ADD_APPLICATION_STRING2 (CHAT_STRING1, "Chat Room1", "Chat Room No 1");
	ADD_APPLICATION_STRING2 (CHAT_STRING2, "Chat Room2", "Chat Room No 2");
	ADD_APPLICATION_STRING2 (CHAT_ROOM_MENU_TEXT, "Chat ", "Chat Application");
	ADD_APPLICATION_STRING2 (CHAT_ROOM_RESUME, "Resume ", "Chat Application");
	ADD_APPLICATION_STRING2 (CHAT_ROOM_END, "End ", "Chat Application");
	ADD_APPLICATION_STRING2 (STR_CHAT_WRITE_MESSAGE_TITLE, "Write Message ", "Chat Application");
	ADD_APPLICATION_STRING2 (STR_REPLACE_CHAT_INFO_QUERY, "Replace Current Chat Room", "Chat Application");
	ADD_APPLICATION_STRING2 (CHAT_ROOM_TEXT, "Chat Options", "Chat Option Screen");
	ADD_APPLICATION_STRING2 (CHAT_ROOM_INFO_STR, "Chat Room Info", "Chat Room Info");
	ADD_APPLICATION_STRING2 (CHAT_ROOM_NEW_STR, "Start New ", "Start New Chat ");

	ADD_APPLICATION_STRING2 (STR_CLEAR_CHAT_ROOM_QUERY, "Clear Chat Room ", "Clear Chat Room Query ");
	
	
	ADD_APPLICATION_STRING2 (STR_SAVE_CHAT_INFO, "Save Chat Room Info ", "Quit Chat Room Query ");
	ADD_APPLICATION_STRING2 (STR_QUIT_CHAT_ROOM_QUERY, "Quit Chat Room ", "Quit Chat Room Query ");

	ADD_APPLICATION_STRING2 (CHAT_PHB_NUM_STR, "Insert PHB Number ", "Chat Insert PHB Number");
	ADD_APPLICATION_STRING2 (CHAT_PHB_NAME_STR, "Insert PHB Name ", "Chat Insert PHB Name");

		
	ADD_APPLICATION_STRING2 (CHATROOM_NICKNAME, "My Nickname ", "NickName  Option");
	ADD_APPLICATION_STRING2 (CHATROOM_DESTINATION, "Destination Number ", "Chat Destination Number");

	ADD_APPLICATION_STRING2 (CHATROOM_EMPTY_ERROR, "No Destination Number", "Chat Room Number Empty error");
	ADD_APPLICATION_STRING2 (CHATROOM_DUPLICATE_ERROR, "Duplicate Number ", "Chat Room Duplicate Number  error");
	ADD_APPLICATION_STRING2 (CHATROOM_NEW_MSG_RCVD, "New Chat SMS ", "Chat Room New message Indication");
	
	ADD_APPLICATION_STRING2 (CHATROOM_STORAGE_FULL_ERROR, "Storage Full For Incoming Chat SMS", "Storage Full  message Error");
	//ADD_APPLICATION_STRING2 (CHATROOM_STORAGE_EXCEED_ERROR, "Memory Exceed For Incoming Chat SMS", "Storage Exceed  message Error");
	ADD_APPLICATION_STRING2 (CHATROOM_LOCAL_DEFAULT	, "I say", "Chat Local Default");

	ADD_APPLICATION_STRING2 (STR_CHAT_USE_NUMBER, "Use Number ", "Chat Room Use Number");
	ADD_APPLICATION_STRING2 (STR_CHAT_CLEAR_CHAT, "Clear Chat ", "Clear Chat Room messages ");
	ADD_APPLICATION_STRING2 (STR_CHAT_TEMP_LEAVE, "TempLeave ", "Chat Room Temp Leave message ");
	ADD_APPLICATION_STRING2 (STR_CHAT_QUIT, "Quit ", "Quit Chat Room message ");
	ADD_APPLICATION_STRING2 (STR_GLOBAL_CHAT, "Chat ", " Chat Button message");
	ADD_APPLICATION_STRING2 (STR_CHAT_INVITATION, "Chat Invitation ", " Chat Invitation String");
	ADD_APPLICATION_STRING2 (STR_CHAT_FROM, "Chat From: ", " Chat From String");

	ADD_APPLICATION_STRING2 (STR_END_QUERY	, "Sure to End ", " Chat End Query");

	ADD_APPLICATION_STRING2 (STR_CHAT_OPTIONS	, "Option", "Chat Option String");
	ADD_APPLICATION_STRING2 (STR_CHAT_EDIT_KEY	, "Edit", " Chat Edit String");
	ADD_APPLICATION_STRING2 (STR_CHAT_SAVE	, "Save", "Chat Save String");
	
	ADD_APPLICATION_STRING2 (STR_CHAT_SAVE_SUCESS	, "Chat Saved Sucess", "Chat  Save Sucess String");
	ADD_APPLICATION_STRING2 (STR_CHAT_SAVE_FAILED	, "Chat Saved Failed", "Chat  Save Failed String");
	ADD_APPLICATION_STRING2 (STR_CHAT_SAVE_PARTIAL	, "Chat Saved Partial Message", "Chat  Save PartialString");
#ifdef __MMI_MULTI_SIM__
	#ifdef __MMI_MESSAGES_CHAT__
	ADD_APPLICATION_STRING(STRING_MTPNP_CHOOSE_MASTER_CHAT,"Choose Master");
	ADD_APPLICATION_STRING(STRING_MTPNP_CHOOSE_SLAVE_CHAT,"Choose Slave");
	ADD_APPLICATION_STRING(STRING_MTPNP_CHAT_NOT_SUPPORT,"Not Support");
	#if (MMI_SIM_NUMBER >= 3)
	ADD_APPLICATION_STRING(STRING_MTPNP_CHO0SE_SIM3_CHAT,"Choose SIM3");
	#endif
	#if (MMI_SIM_NUMBER >= 4)
	ADD_APPLICATION_STRING(STRING_MTPNP_CHO0SE_SIM3_CHAT,"Choose SIM4");
	#endif
	#endif
#endif
	
}
void PopulateChatAppImgRes(){
	ADD_APPLICATION_IMAGE2 (CHAT_IMAGE_APP_ID, CUST_IMG_PATH"/MainLCD/TitleBar/TB_MG.PBM",
							"CHAT app Menu item LSK common Image");	
	ADD_APPLICATION_IMAGE2 (IMG_CHAT_NICKNAME, CUST_IMG_PATH"/MainLCD/Chat/CT_NAME.gif",
							"CHAT app Menu item LSK common Image");	
	ADD_APPLICATION_IMAGE2 (IMG_CHAT_DESTINATION, CUST_IMG_PATH"/MainLCD/Chat/CT_PHONE.gif",
							"CHAT app Menu item LSK common Image");	
}
#if 0
void PopulateChatAppMenuRes(){
	ADD_APPLICATION_MENUITEM((MENU_CHATAPP_ID,MAIN_MENU_MESSAGES_MENUID,2,
								MENU_CHAT_ROOM1,
								MENU_CHAT_ROOM2,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_ROOM_MENU_TEXT,IMG_CHAT_MESSAGE_ID));
	
	ADD_APPLICATION_MENUITEM((MENU_CHAT_ROOM1,MENU_CHATAPP_ID,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_STRING1,0));
	
	ADD_APPLICATION_MENUITEM((MENU_DEACTIVE_CHAT_ROOM,0,2,
								MENU_CHATROOM_INFO,
								MENU_START_NEW,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_ROOM_TEXT,0));
	ADD_APPLICATION_MENUITEM((MENU_ACTIVE_CHAT_ROOM,0,3,
								MENU_CHATROOM_INFO,
								MENU_RESUME_CHAT,
								MENU_END_CHAT,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_ROOM_TEXT,0));

	ADD_APPLICATION_MENUITEM((MENU_CHAT_ROOM2,MENU_CHATAPP_ID,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_STRING2,0));
	ADD_APPLICATION_MENUITEM((MENU_CHATROOM_INFO,MENU_ACTIVE_CHAT_ROOM,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_ROOM_INFO_STR,0));
	ADD_APPLICATION_MENUITEM((MENU_START_NEW,MENU_DEACTIVE_CHAT_ROOM,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_ROOM_NEW_STR,0));
	ADD_APPLICATION_MENUITEM((MENU_RESUME_CHAT,MENU_ACTIVE_CHAT_ROOM,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_ROOM_RESUME,0));
	ADD_APPLICATION_MENUITEM((MENU_END_CHAT,MENU_ACTIVE_CHAT_ROOM,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_ROOM_END,0));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_OPTION,0,5,
								MENU_CHATMSG_SEND,
								MENU_CHATAPP_TEMPLATE,
								MENU_CHAT_PHB_NUM,
								MENU_CHAT_PHB_NAM,
								MENU_CHAT_INPUT_METHOD,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_CHAT_OPTIONS,IMG_GLOBAL_OPTIONS));
	ADD_APPLICATION_MENUITEM((MENU_CHATMSG_SEND,MENU_CHAT_OPTION,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_GLOBAL_SEND,0));
	ADD_APPLICATION_MENUITEM((MENU_CHATAPP_TEMPLATE,MENU_CHAT_OPTION,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_GLOBAL_USE_TEMPLATE,0));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_PHB_NUM,MENU_CHAT_OPTION,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_PHB_NUM_STR,0));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_PHB_NAM,MENU_CHAT_OPTION,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, CHAT_PHB_NAME_STR,0));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_INPUT_METHOD,MENU_CHAT_OPTION,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_GLOBAL_INPUT_METHOD,0));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_ROOM_SCRN,0,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTIONS));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_OPTION_SCRN,0,6,
								MENU_CHAT_REPLY_SCRN,
								MENU_CHAT_USE_NUM_SCRN,
								MENU_CHAT_CLEAR_SCRN,
								MENU_CHAT_TEMP_SCRN,
								MENU_CHAT_QUIT_SCRN,
								MENU_CHATROOM_INFO,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTIONS));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_REPLY_SCRN,MENU_CHAT_OPTION_SCRN,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_GLOBAL_REPLY,0));

	ADD_APPLICATION_MENUITEM((MENU_CHAT_USE_NUM_SCRN,MENU_CHAT_OPTION_SCRN,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_CHAT_USE_NUMBER,0));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_CLEAR_SCRN,MENU_CHAT_OPTION_SCRN,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_CHAT_CLEAR_CHAT,0));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_TEMP_SCRN,MENU_CHAT_OPTION_SCRN,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_CHAT_TEMP_LEAVE,0));
	ADD_APPLICATION_MENUITEM((MENU_CHAT_QUIT_SCRN,MENU_CHAT_OPTION_SCRN,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST, STR_CHAT_QUIT,0));
}

#endif
#endif
#endif   // Use old menu style Kenneth


