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

 

 

	DATE		: August-11-2003

**************************************************************/
#include "stdc.h"
#include "customcfg.h"


#ifdef FIRST_PASS
#include "buildcfg.h"
#endif

//#include "commonscreens.h"
#include "messagesresourcedata.h"
#include "mmi_features.h"
#include "kal_non_specific_general_types.h"
#include "servicedefs.h"
#include "dataaccount.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "populateres.h"

/**************************************************************

	FUNCTION NAME		: PopulateDataAccountMenuList()

  	PURPOSE				: Populate the Data Account Menu List

	INPUT PARAMETERS	: void

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

 

**************************************************************/


//micha0202, change all define names

void PopulateDataAccountMenuList(void)
{
#if 0
#ifdef __MMI_WLAN_FEATURES__

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_MAIN,SERVICES_DATA_CONNECT_MAIN_MENU_ID,4,
								MENU_ID_WLAN_POWER,
								MENU_ID_WLAN_CONN_STATUS,
								MENU_ID_WLAN_NETWORK_SETTINGS,
								MENU_ID_WLAN_FIND_NETWORK,
								SHOW,NONMOVEABLE,DISP_LIST,
								SERVICES_DATA_CONNECT_WLAN_STRING_ID,SERVICES_DATA_CONNECT_IMAGE_ID));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_POWER,MENU_ID_WLAN_MAIN,0,
								SHOW,NONMOVEABLE,DISP_LIST,
								STR_ID_DTCNT_WLAN_POWER,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_CONN_STATUS,MENU_ID_WLAN_MAIN,0,
								SHOW,NONMOVEABLE,DISP_LIST, 
								STR_ID_DTCNT_WLAN_CONN_STATUS,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_NETWORK_SETTINGS,MENU_ID_WLAN_MAIN,0,
								SHOW,NONMOVEABLE,DISP_LIST,
								STR_ID_DTCNT_WLAN_NETWORK_SETTINGS,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_TCPIP_SETTINGS,MENU_ID_WLAN_MAIN,0,
								SHOW,NONMOVEABLE,DISP_LIST, 
								STR_ID_DTCNT_WLAN_TCPIP_SETTINGS,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_FIND_NETWORK,MENU_ID_WLAN_MAIN,0,
								SHOW,NONMOVEABLE,DISP_LIST, 
								STR_ID_DTCNT_WLAN_FIND_NETWORK,0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_NETWORK_SETTINGS_OPT, 0, 5,
								MENU_ID_WLAN_NETWORK_SETTINGS_OPT_CONNECT,
								MENU_ID_WLAN_NETWORK_SETTINGS_OPT_EDIT,
								MENU_ID_WLAN_NETWORK_SETTINGS_OPT_ADD,
								MENU_ID_WLAN_NETWORK_SETTINGS_OPT_DELETE,
								MENU_ID_WLAN_NETWORK_SETTINGS_OPT_PRIORITY,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_OPTIONS, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_NETWORK_SETTINGS_OPT_CONNECT, MENU_ID_WLAN_NETWORK_SETTINGS_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_CONNECT_MENUENTRY, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_NETWORK_SETTINGS_OPT_EDIT, MENU_ID_WLAN_NETWORK_SETTINGS_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_EDIT, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_NETWORK_SETTINGS_OPT_ADD, MENU_ID_WLAN_NETWORK_SETTINGS_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_NEW_ACCESS_POINT, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_NETWORK_SETTINGS_OPT_DELETE, MENU_ID_WLAN_NETWORK_SETTINGS_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_DELETE, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_NETWORK_SETTINGS_OPT_PRIORITY, MENU_ID_WLAN_NETWORK_SETTINGS_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_NETWORK_SETTINGS_OPT_PRIORITY, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_FIND_NETWORK_OPT, 0, 4,
								MENU_ID_WLAN_FIND_NETWORK_OPT_CONNECT,
								MENU_ID_WLAN_FIND_NETWORK_OPT_DEFINE,
								MENU_ID_WLAN_FIND_NETWORK_OPT_DETAILS,
								MENU_ID_WLAN_FIND_NETWORK_OPT_REFRESH,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_OPTIONS, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_FIND_NETWORK_OPT2, 0, 1,
								MENU_ID_WLAN_FIND_NETWORK_OPT_REFRESH,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_OPTIONS, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_FIND_NETWORK_OPT_CONNECT, MENU_ID_WLAN_FIND_NETWORK_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_CONNECT_MENUENTRY, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_FIND_NETWORK_OPT_DEFINE, MENU_ID_WLAN_FIND_NETWORK_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_DEFINE_ACCESS_POINT, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_FIND_NETWORK_OPT_DETAILS, MENU_ID_WLAN_FIND_NETWORK_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_NETWORK_DETAILS, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_FIND_NETWORK_OPT_REFRESH, MENU_ID_WLAN_FIND_NETWORK_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_RESCAN_NETWORK, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_EAP_OPT, 0,6,
								MENU_ID_WLAN_EAP_TLS,
								MENU_ID_WLAN_EAP_MD5,
								MENU_ID_WLAN_EAP_PEAP,
								MENU_ID_WLAN_EAP_TTLS,
								MENU_ID_WLAN_EAP_SIM,
								MENU_ID_WLAN_EAP_FAST,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_OPTIONS, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_EAP_TLS, MENU_ID_WLAN_EAP_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_EAP_TLS, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_EAP_MD5, MENU_ID_WLAN_EAP_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_EAP_MD5, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_EAP_PEAP, MENU_ID_WLAN_EAP_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_EAP_PEAP, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_EAP_TTLS, MENU_ID_WLAN_EAP_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_EAP_TTLS, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_EAP_SIM, MENU_ID_WLAN_EAP_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_EAP_SIM, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_EAP_FAST, MENU_ID_WLAN_EAP_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_EAP_FAST, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_PEAP_OPT, 0,2,
								MENU_ID_WLAN_EAP_PEAP_MSCHAP2,
								MENU_ID_WLAN_EAP_PEAP_GTC,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_OPTIONS, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_EAP_PEAP_MSCHAP2, MENU_ID_WLAN_PEAP_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_EAP_MSCHAP2, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_EAP_PEAP_GTC, MENU_ID_WLAN_PEAP_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_EAP_GTC, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_TTLS_OPT, 0,5,
								MENU_ID_WLAN_PAP,
								MENU_ID_WLAN_CHAP,
								MENU_ID_WLAN_MSCHAP,
								MENU_ID_WLAN_MSCHAP2,
								MENU_ID_WLAN_EAP2_OPT,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_OPTIONS, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_PAP, MENU_ID_WLAN_TTLS_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_PAP, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_CHAP, MENU_ID_WLAN_TTLS_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_CHAP, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_MSCHAP, MENU_ID_WLAN_TTLS_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_MSCHAP, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_MSCHAP2, MENU_ID_WLAN_TTLS_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_MSCHAP2, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_EAP2_OPT, MENU_ID_WLAN_TTLS_OPT,4,
								MENU_ID_WLAN_EAP2_MSCHAP2,
								MENU_ID_WLAN_EAP2_MD5,
								MENU_ID_WLAN_EAP2_SIM,
								MENU_ID_WLAN_EAP2_GTC,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_OPTIONS, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_EAP2_MSCHAP2, MENU_ID_WLAN_EAP2_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_EAP_MSCHAP2, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_EAP2_MD5, MENU_ID_WLAN_EAP2_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_EAP_MD5, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_EAP2_SIM, MENU_ID_WLAN_EAP2_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_EAP_SIM, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_WLAN_EAP2_GTC, MENU_ID_WLAN_EAP2_OPT,0,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_ID_DTCNT_WLAN_EAP_GTC, 0));

	ADD_APPLICATION_MENUITEM ((MENU_ID_WLAN_WPA_PASSPHRASE_OPT, 0, 2,
								MENU_DONE_OPTION_ID,
								MENU_INPUT_METHOD_OPTION_ID,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_OPTIONS, 0));
	ADD_APPLICATION_MENUITEM ((MENU_DONE_OPTION_ID,
								MENU_ID_WLAN_WPA_PASSPHRASE_OPT, 0, 
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_DONE, 0));
	ADD_APPLICATION_MENUITEM ((MENU_INPUT_METHOD_OPTION_ID,
								MENU_ID_WLAN_WPA_PASSPHRASE_OPT, 0, 
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_INPUT_METHOD, 0));

	ADD_APPLICATION_MENUITEM ((MENU_ID_WLAN_PASSPHRASE_INTPUT_OPT, 0, 2,
								MENU_DONE_OPTION_ID,
								MENU_INPUT_METHOD_OPTION_ID,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_OPTIONS, 0));
	ADD_APPLICATION_MENUITEM ((MENU_DONE_OPTION_ID,
								MENU_ID_WLAN_PASSPHRASE_INTPUT_OPT, 0, 
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_DONE, 0));
	ADD_APPLICATION_MENUITEM ((MENU_INPUT_METHOD_OPTION_ID,
								MENU_ID_WLAN_PASSPHRASE_INTPUT_OPT, 0, 
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_INPUT_METHOD, 0));

	ADD_APPLICATION_MENUITEM ((MENU_ID_WLAN_EAP_TYPES_OPT, 0, 2,
								MENU_ID_WLAN_EAP_TYPES_OPT_ACTIVATE,
								MENU_ID_WLAN_EAP_TYPES_OPT_EDIT,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_OPTIONS, 0));
	ADD_APPLICATION_MENUITEM ((MENU_ID_WLAN_EAP_TYPES_OPT_ACTIVATE,
								MENU_ID_WLAN_EAP_TYPES_OPT, 0, 
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_ACTIVATE, 0));
	ADD_APPLICATION_MENUITEM ((MENU_ID_WLAN_EAP_TYPES_OPT_EDIT,
								MENU_ID_WLAN_EAP_TYPES_OPT, 0, 
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_EDIT, 0));

	ADD_APPLICATION_MENUITEM ((MENU_ID_WLAN_EAP_TYPES_OPT2, 0, 1,
								MENU_ID_WLAN_EAP_TYPES_OPT_ACTIVATE,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_OPTIONS, 0));

	ADD_APPLICATION_MENUITEM ((MENU_ID_WLAN_EAP_PEAP_TYPES_OPT, 0, 2,
								MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_ACTIVATE,
								MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_EDIT,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_OPTIONS, 0));

	ADD_APPLICATION_MENUITEM ((MENU_ID_WLAN_EAP_PEAP_TYPES_OPT2, 0, 1,
								MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_ACTIVATE,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_OPTIONS, 0));

	ADD_APPLICATION_MENUITEM ((MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_ACTIVATE,
								MENU_ID_WLAN_EAP_PEAP_TYPES_OPT, 0, 
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_ACTIVATE, 0));
	ADD_APPLICATION_MENUITEM ((MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_EDIT,
								MENU_ID_WLAN_EAP_PEAP_TYPES_OPT, 0, 
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_EDIT, 0));

	ADD_APPLICATION_MENUITEM ((MENU_ID_WLAN_EAP_TTLS_TYPES_OPT, 0, 2,
								MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_ACTIVATE,
								MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_EDIT,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_OPTIONS, 0));

	ADD_APPLICATION_MENUITEM ((MENU_ID_WLAN_EAP_TTLS_TYPES_OPT2, 0, 1,
								MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_ACTIVATE,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_OPTIONS, 0));

	ADD_APPLICATION_MENUITEM ((MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_ACTIVATE,
								MENU_ID_WLAN_EAP_TTLS_TYPES_OPT, 0, 
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_ACTIVATE, 0));
	ADD_APPLICATION_MENUITEM ((MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_EDIT,
								MENU_ID_WLAN_EAP_TTLS_TYPES_OPT, 0, 
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_EDIT, 0));

	ADD_APPLICATION_STRING2(SERVICES_DATA_CONNECT_WLAN_STRING_ID,"Wireless LAN","Wireless LAN");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_DISCONNECT,"Disconnect","Disconnect");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_MACADDR,"Phone MAC","Phone MAC");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_BSSID,"BSSID","BSSID");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_CHANNEL,"Channel","Channel");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ADHOC_CHANNEL,"Ad-hoc Channel","Ad-hoc Channel");    
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_SIGNAL_STRENGTH,"Signal Strength","Signal Strength");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_POWER,"Wireless LAN","WLAN Power");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_POWER_ON,"Enable WLAN","Enable WLAN");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_POWER_OFF,"Disable WLAN","Disable WLAN");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_CONN_STATUS,"Current Status","WLAN Current Status");	
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_SETTINGS,"WLAN Settings","WLAN connection settings");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_NETWORK_SETTINGS,"Access Point Settings","Access Point Settings");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_TCPIP_SETTINGS,"TCP/IP Settings","WLAN TCP/IP Settings");	
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_FIND_NETWORK,"Search for networks","Search for wireless networks");	
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_SCAN_RESULT,"Available networks","Site Survey results");	
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_NETWORK_SETTINGS_OPT_PRIORITY,"Change Priority","Change connect priorty");	
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_USE_DHCP, "Use DHCP", "Use DHCP");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_IPADDR, "IP Address", "IP Address");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_NETMASK, "Subnet mask", "Netmask");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_GATEWAY, "Default Gateway", "Gateway");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_DNS1, "Primary DNS", "Primary DNS");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_DNS2, "Secondary DNS", "Secondary DNS");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_NAME, "Connection name", "Connection name");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_SSID, "SSID", "SSID");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_NETWORK_TYPE, "Network Type", "Network Type");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_AUTH_MODE, "WLAN Security Mode", "Authentication Mode");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_SECURITY_SETTINGS, "WLAN Security Settings", "WLAN Security Settings");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ENCRYPT_MODE, "Encryption Mode", "Encryption Mode");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_NETWORK_TYPE_INFRA, "Infrastructure", "Infrastucture Network");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_NETWORK_TYPE_ADHOC, "Ad-hoc", "Ad-hoc Network");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_NETWORK_TYPE_AUTO, "Automatic", "Automatic Selection");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_AUTH_MODE_OPEN, "Open Network", "Open System");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_AUTH_MODE_SHARED, "Shared", "Shared");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_AUTH_MODE_IEEE8021X, "IEEE 802.1x", "IEEE 802.1x");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA, "WPA/WPA2", "WPA/WPA2");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_AUTH_MODE_WPAPSK, "WPA/WPA2 PSK", "WPA/WPA2 PSK");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_AUTH_MODE_WPANONE, "WPA-None", "WPA-None");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_NONE, "None", "No Encryption");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_WEP, "WEP", "WEP");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_TKIP, "TKIP", "TKIP");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_AES, "CCMP/AES", "AES");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_WEP_KEY_ID, "WEP key in use", "WEP key in use");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_WEP_KEY_ID1, "#1", "WEP key #1");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_WEP_KEY_ID2, "#2", "WEP key #2");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_WEP_KEY_ID3, "#3", "WEP key #3");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_WEP_KEY_ID4, "#4", "WEP key #4");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_WEP_KEY_SETTINGS, "WEP key settings", "WEP key settings");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_WEP_KEY_ENCRYPT, "WEP encryption", "WEP encryption strength");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_WEP_KEY_ENCRYPT_64, "64 bits", "64 bits encryption");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_WEP_KEY_ENCRYPT_128, "128 bits", "128 bits encryption");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_WEP_KEY_ENCRYPT_256, "256 bits", "256 bits encryption");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_WEP_KEY_FORMAT, "WEP format", "WEP format");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII, "ASCII", "WEP format ASCII");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_WEP_KEY_FORMAT_HEX, "HEX", "WEP format HEX");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_WEP_KEY, "WEP Key", "WEP Key");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_PROCESSING, "Please wait.", "Background processing");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_OVERWRITE, "Overwrite", "Overwrite - LSK Caption");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_OVERWRITE_CONFIRM, "Overwrite existing setting?", "Overwrite profile confirm");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_CLEAR_CONFIRM, "Delete existing setting?", "Delete profile confirm");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_NEW_ACCESS_POINT, "New access point", "New access point");    
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_DEFINE_ACCESS_POINT, "Define access point", "Define access point");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_FINDING_NETWORK, "Searching", "Searching for available networks");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_NETWORK_DETAILS, "Details", "Network Details");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_CONFIGURE, "Edit", "String for WLAN general use");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL0, "Excellent", "Excellent");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL1, "Very good", "Very good");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL2, "Good", "Good");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL3, "Poor", "Poor");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL4, "Very poor", "Very poor");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_SECURITY, "Security", "Security");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_LINK_SPEED, "Link Speed", "Link Speed");
	
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_RESCAN_NETWORK, "Refresh", "Refresh search result.");

	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_EAP, "EAP", "EAP");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_EAP_TYPES, "EAP Types", "EAP Types");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_EAP_TLS, "EAP-TLS", "EAP-TLS");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_EAP_MD5, "EAP-MD5", "EAP-MD5");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_EAP_PEAP, "EAP-PEAP", "EAP-PEAP");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_EAP_TTLS, "EAP-TTLS", "EAP-TTLS");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_EAP_SIM, "EAP-SIM", "EAP-SIM");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_EAP_FAST, "EAP-FAST", "EAP-FAST");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_EAP_GTC, "EAP-GTC", "EAP-GTC");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_EAP_MSCHAP2, "EAP-MSCHAPv2", "EAP-MSCHAPv2");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_EAP_FAST, "EAP-FAST", "EAP-FAST");

	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_PAP, "PAP", "PAP");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_CHAP, "CHAP", "CHAP");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_MSCHAP, "MS-CHAP", "MS-CHAP");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_MSCHAP2, "MS-CHAPv2", "MS-CHAPv2");

	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_WPA_PASSPHRASE, "Enter a passphrase", "WPA Passphrase");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_USER_CERT, "User certificates", "User certificates");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_CA_CERT, "CA certificates", "CA certificates");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_PRIV_KEY, "Private Key", "Private Key for Client Certificate");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_PRIV_KEY_PASSWD, "Private Key Password", "Private Key password");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_USER_INFO, "Identification Info", "Identification Info");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_EAP_TLS_SETTINGS, "EAP-TLS Settings", "EAP-TLS Settings");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS, "EAP-PEAP Settings", "EAP-PEAP Settings");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS, "EAP-TTLS Settings", "EAP-TTLS Settings");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ALLOW_PEAP_0, "Allow PEAPv0", "Allow PEAPv0");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ALLOW_PEAP_1, "Allow PEAPv1", "Allow PEAPv1");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_USE_ANONYMOUS, "Use Anonymous", "Use Anonymous");
	
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_TUNNELED_AUTH_PROTOCOL, "Tunneled Auth. Proto.", "Tunneled Authentication Protocol of EAP-TTLS");

	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ERROR_PROFILE_FULL, "Memory Full", "Memory Full, no more profile can be added");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY, "Invalid WEP key", "Invalid WEP key");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ERROR_INVALID_SSID, "SSID cannot be empty", "SSID cannot be empty");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ERROR_FILE_OPEN_FAILED, "Failed to create temp file", "Failed to create temp file");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ERROR_INVALID_PASSPHRASE, "Pre-shared key too short", "Pre-shared key too short");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ERROR_IP_CONFLICT, "IP is used by another station", "IP is used by another station");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ERROR_ONE_EAP_NEEDED, "At least one EAP type has to be enabled", "At least one EAP type has to be enabled");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ERROR_NO_AUTH_SETTING, "No security settings for open network", "No security settings for open network");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ERROR_NAME_INUSE, "Name already in use", "Name already in use");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ERROR_AUTH_FAIL, "Authentication failed", "Authentication failed");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ERROR_CONNECT_FAIL, "Unable to connect", "Unable to connect");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ERROR_DEFINE_NETWORK_FIRST, "Please define network first", "Please define network first");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ERROR_INVALID_NAME, "Connection name cannot be empty", "Connection name cannot be empty");

	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_POPUP_CONNECT, CUST_IMG_PATH"/MainLCD/WLAN/WiFi_Connect.gif","Image of WLAN");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_POPUP_SEARCH, CUST_IMG_PATH"/MainLCD/WLAN/WiFi_search.gif","Popup image for Site Survey");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_STATION, CUST_IMG_PATH"/MainLCD/WLAN/SB_WiFi.pbm","Image of access point");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_SECURED_STATION, CUST_IMG_PATH"/MainLCD/WLAN/WiFi_aeria_lock.pbm","Image of secured access point");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_ADHOC, CUST_IMG_PATH"/MainLCD/WLAN/WiFi_access_pc.pbm","Image of ad-hoc station");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_SIGNAL0, CUST_IMG_PATH"/MainLCD/WLAN/WiFi_signal0.bmp","Signal level 0 for scan result");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_SIGNAL1, CUST_IMG_PATH"/MainLCD/WLAN/WiFi_signal1.bmp","Signal level 1 for scan result");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_SIGNAL2, CUST_IMG_PATH"/MainLCD/WLAN/WiFi_signal2.bmp","Signal level 2 for scan result");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_SIGNAL3, CUST_IMG_PATH"/MainLCD/WLAN/WiFi_signal3.bmp","Signal level 3 for scan result");

#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ERROR_NO_PROFILES, "No valid settings", "No valid settings");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_ERROR_PROFILE_IN_USE, "Can't replace setting in use", "Can't replace setting in use");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_SKIP_INVALID_PROFILES, "Skip invalid settings", "Skip invalid settings");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_AUTO_RENAME_PROFILE, "Name in use. Auto rename setting", "Name in use. Auto rename setting");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_INSTALL_PROFILE, "Install Setting", "Install Setting");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_REPLACE_PROFILE, "Replace Setting", "Replace Setting");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_WLAN_REPLACE_CONFIRM, "Replace existing setting?", "Replace existing setting?");
#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */

#endif /* __MMI_WLAN_FEATURES__ */

	ADD_APPLICATION_MENUITEM((SERVICES_DATA_CONNECT_MENU_ID,SERVICES_DATA_CONNECT_MAIN_MENU_ID,0,
								SHOW,NONMOVEABLE,DISP_LIST,
								SERVICES_DATA_CONNECT_GSM_STRING_ID,SERVICES_DATA_CONNECT_IMAGE_ID));

	ADD_APPLICATION_STRING2(SERVICES_DATA_CONNECT_GSM_STRING_ID,"GSM Data","GSM Data account");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_EMPTY ,"<Empty>","String for Data Account empty Name");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_CAPTION ,"Data Account","Title String for Data Acouunt main screen");

	ADD_APPLICATION_STRING2(STR_ID_DTCNT_RENAME,"Account Name"," Rename String for Data Account Screen");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_DIAL_NUMBER,"Number"," Dial Number String for Data Account Screen");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_USER_NAME,"User Name","User mane String for Data Account Screen");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_PASSWD,"Password"," Password String for Data Account Screen");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_DIAL_TYPE,"Line Type"," Dial Type String for Data Account Screen");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_DATA_RATE,"Speed"," Data Rate String for Data Account Screen");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_DNS_ADDRESS,"DNS"," DNS Address String for Data Account Screen");
//	ADD_APPLICATION_STRING2(STR_ID_DTCNT_SAVE_QUERY ,"Save"," Querry to User");
	
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_ANALOGUE_STR ,"Analogue"," String of Dial Type");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_ISDN_STR ,"ISDN"," String of Dial Type");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_RATE_STR_ONE ,"4.8 Kbps "," String of Dial Rate 1");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_RATE_STR_TWO ,"9.6 Kbps"," String of Dial Rate 2");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_RATE_STR_THREE ,"14.4 Kbps"," String of Dial Rate 3");

	ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME ,"Account "," Default Account Name");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_ONE ,"Account 1"," Default Account Name");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_TWO ,"Account 2"," Default Account Name");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_THREE ,"Account 3"," Default Account Name");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_FOUR ,"Account 4"," Default Account Name");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_FIVE ,"Account 5"," Default Account Name");

//micha1230
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_SIX ,"Account 6"," Default Account Name");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_SEVEN ,"Account 7"," Default Account Name");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_EIGHT ,"Account 8"," Default Account Name");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_NINE ,"Account 9"," Default Account Name");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_TEN ,"Account 10"," Default Account Name");

//micha0120
#ifdef __MMI_GPRS_FEATURES__
	ADD_APPLICATION_MENUITEM((SERVICES_DATA_CONNECT_GPRS_MENU_ID,SERVICES_DATA_CONNECT_MAIN_MENU_ID,0,
								SHOW,NONMOVEABLE,DISP_LIST,
								SERVICES_DATA_CONNECT_GPRS_STRING_ID,SERVICES_DATA_CONNECT_IMAGE_ID));

	ADD_APPLICATION_STRING2(SERVICES_DATA_CONNECT_GPRS_STRING_ID,"GPRS","GPRS Data account");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_GPRS_PAP_AUTH ,"Normal"," GPRS PAP Auth.");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_GPRS_CHAP_AUTH ,"Secure"," GPRS CHAP Auth.");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_GPRS_APN ,"APN"," GPRS APN Name");
	ADD_APPLICATION_STRING2(STR_ID_DTCNT_GPRS_AUTH_TYP ,"Auth. Type"," GPRS Authentication Type");

	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_GPRS_AC_NAME,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_ACCN.gif","Image of GPRS Data Account");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_GPRS_APN,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_PHONE.gif","Image of GPRS Data Account");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_GPRS_USER_NAME,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_NAME.gif","Image of GPRS Data Account");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_GPRS_PASSWD,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_PASS.gif","Image of GPRS Data Account");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_GPRS_CONNTYPE,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_TYPE.gif","Image of GPRS Data Account");

#endif
#endif
#ifdef __MMI_GPRS_FEATURES__
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_GPRS_AC_NAME,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_ACCN.bmp","Image of GPRS Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_GPRS_APN,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_PHONE.bmp","Image of GPRS Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_GPRS_USER_NAME,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_NAME.bmp","Image of GPRS Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_GPRS_PASSWD,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_PASS.bmp","Image of GPRS Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_GPRS_CONNTYPE,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_TYPE.bmp","Image of GPRS Data Account");
#endif
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_AC_NAME,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_ACCN.bmp","Image of Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_DIAL_NUM,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_PHONE.bmp","Image of Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_USER_NAME,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_NAME.bmp","Image of Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_PASSWD,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_PASS.bmp","Image of Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_DIAL_TYPE,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_TYPE.bmp","Image of Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_DATA_RATE,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_SPEED.bmp","Image of Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_DNS_ADDRESS,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_DNS.bmp","Image of Data Account");

    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_SAVE,CUST_IMG_PATH"/MainLCD/Warningpage/PopUpPage/PP_SAV.gif","Image of Data Account");

    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_CAPTION,CUST_IMG_BASE_PATH"/NoImage.bmp"	,"Title image for Data Account screen");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_LSK_EDIT,CUST_IMG_BASE_PATH"/NoImage.bmp"	,"LSK image for Data Account main screen");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_LSK_OK,CUST_IMG_BASE_PATH"/NoImage.bmp"	,"LSK image for Data Account main screen");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_RSK_BACK,CUST_IMG_BASE_PATH"/NoImage.bmp"	,"RSK image for Data Account main screen");

    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_AC_NAME,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_ACCN.gif","Image of Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_DIAL_NUM,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_PHONE.gif","Image of Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_USER_NAME,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_NAME.gif","Image of Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_PASSWD,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_PASS.gif","Image of Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_DIAL_TYPE,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_TYPE.gif","Image of Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_DATA_RATE,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_SPEED.gif","Image of Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_DNS_ADDRESS,CUST_IMG_PATH"/MainLCD/Submenu/SERVICES/DataAccount/SV_DNS.gif","Image of Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_SAVE,CUST_IMG_PATH"/MainLCD/Warningpage/PopUpPage/PP_SAV.gif","Image of Data Account");
#ifdef __MMI_GPRS_FEATURES__
    ADD_APPLICATION_STRING2(SERVICES_DATA_CONNECT_STRING_ID,"Data Account","Data Account");
    ADD_APPLICATION_STRING2(SERVICES_DATA_CONNECT_GSM_STRING_ID,"GSM Data","GSM Data account");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_CAPTION ,"Data Account","Title String for Data Acouunt main screen");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_RENAME,"Account Name"," Rename String for Data Account Screen");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_DIAL_NUMBER,"Number"," Dial Number String for Data Account Screen");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_USER_NAME,"User Name","User mane String for Data Account Screen");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_PASSWD,"Password"," Password String for Data Account Screen");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_DIAL_TYPE,"Line Type"," Dial Type String for Data Account Screen");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_DATA_RATE,"Speed"," Data Rate String for Data Account Screen");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_DNS_ADDRESS,"DNS"," DNS Address String for Data Account Screen");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_ANALOGUE_STR ,"Analogue"," String of Dial Type");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_ISDN_STR ,"ISDN"," String of Dial Type");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_RATE_STR_ONE ,"4.8 Kbps "," String of Dial Rate 1");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_RATE_STR_TWO ,"9.6 Kbps"," String of Dial Rate 2");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_RATE_STR_THREE ,"14.4 Kbps"," String of Dial Rate 3");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME ,"Account "," Default Account Name");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_ONE ,"Account 1"," Default Account Name");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_TWO ,"Account 2"," Default Account Name");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_THREE ,"Account 3"," Default Account Name");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_FOUR ,"Account 4"," Default Account Name");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_FIVE ,"Account 5"," Default Account Name");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_SIX ,"Account 6"," Default Account Name");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_SEVEN ,"Account 7"," Default Account Name");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_EIGHT ,"Account 8"," Default Account Name");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_NINE ,"Account 9"," Default Account Name");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_NAME_TEN ,"Account 10"," Default Account Name");
    ADD_APPLICATION_STRING2(SERVICES_DATA_CONNECT_GPRS_STRING_ID,"GPRS","GPRS Data account");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_GPRS_PAP_AUTH ,"Normal"," GPRS PAP Auth.");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_GPRS_CHAP_AUTH ,"Secure"," GPRS CHAP Auth.");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_GPRS_APN ,"APN"," GPRS APN Name");
    ADD_APPLICATION_STRING2(STR_ID_DTCNT_GPRS_AUTH_TYP ,"Auth. Type"," GPRS Authentication Type");
    ADD_APPLICATION_STRING2(SERVICES_DATA_CONNECT_MAIN_STRING_ID,"Data Account","Data Connect Menu Item String");
    ADD_APPLICATION_MENUITEM((SERVICES_DATA_CONNECT_MAIN_MENU_ID,MAIN_MENU_SERVICES_MENUID,2,SERVICES_DATA_CONNECT_MENU_ID,SERVICES_DATA_CONNECT_GPRS_MENU_ID,
				SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,SERVICES_DATA_CONNECT_STRING_ID,IMG_ID_DATAACCOUNT_ICON));
	
    ADD_APPLICATION_MENUITEM((SERVICES_DATA_CONNECT_MENU_ID,SERVICES_DATA_CONNECT_MAIN_MENU_ID,0,
				SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,SERVICES_DATA_CONNECT_GSM_STRING_ID,IMG_ID_DATAACCOUNT_ICON));

    ADD_APPLICATION_MENUITEM((SERVICES_DATA_CONNECT_GPRS_MENU_ID,SERVICES_DATA_CONNECT_MAIN_MENU_ID,0,
				SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,SERVICES_DATA_CONNECT_GPRS_STRING_ID,IMG_ID_DATAACCOUNT_ICON));
#endif

}

#endif


