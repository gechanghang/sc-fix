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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   bluetooth_sap.h
 *
 * Project:
 * --------
 
 *
 * Description:
 * ------------
 *   This file is defines SAP for BT.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 
 *============================================================================
 ****************************************************************************/
   MSG_ID_BT_NOTIFY_EVM_IND = BT_MSG_CODE_BEGIN,
   MSG_ID_BT_POWERON_REQ,
   MSG_ID_BT_POWERON_CNF,
   MSG_ID_BT_ENGINEER_MODE_POWERON_REQ,
   MSG_ID_BT_ENGINEER_MODE_POWERON_CNF,
   MSG_ID_BT_POWEROFF_REQ,
   MSG_ID_BT_POWEROFF_IND,
   MSG_ID_BT_POWEROFF_CNF,
   MSG_ID_BT_ENGINEER_MODE_POWEROFF_REQ,
   MSG_ID_BT_ENGINEER_MODE_POWEROFF_CNF,   
   MSG_ID_BT_RESET_REQ_IND,
   MSG_ID_BT_MMI_RESET_REQ,
   MSG_ID_BT_MMI_RESET_CNF,
   MSG_ID_BT_L4C_RESET_REQ,
   MSG_ID_BT_L4C_RESET_CNF,   
   MSG_ID_BT_RESTART_REQ,
   MSG_ID_BT_READY_IND,
   MSG_ID_BT_DATA_TO_READ_IND,
   MSG_ID_BT_HOST_WAKE_UP_IND,
   MSG_ID_BT_WIFI_SET_CHNL_REQ,   
   MSG_ID_BT_JSR_ACTIVE_REQ,   
   MSG_ID_BT_JSR_ACTIVE_CNF,      
   MSG_ID_BT_JSR_DEACTIVE_REQ,   
   MSG_ID_BT_JSR_DEACTIVE_CNF,      
   MSG_ID_BT_JSR_TEST_INIF_REQ,   
   MSG_ID_BT_JSR_TEST_CMD1_REQ,   
   MSG_ID_BT_JSR_TEST_CMD2_REQ,      
   MSG_ID_BT_JSR_TEST_CMD3_REQ,   
   MSG_ID_BT_JSR_TEST_CMD4_REQ,      
   MSG_ID_BT_JSR_TEST_CMD5_REQ,      
   
   /*EM test command*/
   MSG_ID_BT_TEST_MODE_REQ,      
   MSG_ID_BT_TEST_CMD_REQ,
   MSG_ID_BT_L4C_TEST_CMD_CNF,
   MSG_ID_BT_PCM_LB_REQ,
   MSG_ID_BT_PCM_LB_CNF,
   MSG_ID_BT_SET_BD_ADDR_REQ,
   MSG_ID_BT_SET_POWER_TABLE_REQ,
   MSG_ID_BT_SET_ANA_TRIM_REQ,
   MSG_ID_BT_L4C_AT_GENERAL_CNF,
   MSG_ID_BT_GET_BD_ADDR_REQ,
   MSG_ID_BT_GET_BD_ADDR_CNF,
   MSG_ID_BT_GET_BT_VERSION_REQ,
   MSG_ID_BT_GET_BT_VERSION_CNF,   
   MSG_ID_BT_ENGINEER_MODE_CNF,   
   MSG_ID_BT_ENGINEER_MODE_TXRX_TEST_REQ,
   MSG_ID_BT_ENGINEER_MODE_TXRX_TEST_CNF,
   MSG_ID_BT_ENGINEER_MODE_POWER_TEST_REQ,
   MSG_ID_BT_ENGINEER_MODE_POWER_TEST_CNF,
    MSG_TAG_BT_SAP_START_MSG,
   /*APP --> SPP, DUN*/
   MSG_TAG_BT_SPP_FIRST_REQ_MSG,
   MSG_ID_BT_SPP_ACTIVATE_REQ = MSG_TAG_BT_SPP_FIRST_REQ_MSG,
   MSG_ID_BT_SPP_CONNECT_REQ,  
   MSG_ID_BT_SPP_SCO_CONNECT_REQ, 
   MSG_ID_BT_SPP_SEND_DATA_REQ,
   MSG_ID_BT_SPP_GET_DATA_REQ,   
   MSG_ID_BT_SPP_DEACTIVATE_REQ,
   MSG_ID_BT_SPP_DISCONNECT_REQ,
   MSG_ID_BT_SPP_AUDIO_CONNECT_REQ,
   MSG_ID_BT_SPP_AUDIO_DISCONNECT_REQ, 
   MSG_ID_BT_SPP_AUTH_RSP, 
    
   MSG_ID_BT_SPP_UART_OWNER_CNF,
    
   MSG_ID_BT_SPP_UART_PLUGOUT_CNF,
   MSG_ID_BT_DUN_ACTIVATE_REQ,
   MSG_ID_BT_DUN_DEACTIVATE_REQ,
   MSG_ID_BT_DUN_DISCONNECT_REQ,
   MSG_ID_BT_DUN_AUTH_RSP,
   
    
   MSG_ID_BT_FAX_ACTIVATE_REQ,
   MSG_ID_BT_FAX_DEACTIVATE_REQ,
   MSG_ID_BT_FAX_DISCONNECT_REQ,
   MSG_ID_BT_FAX_AUTH_RSP,
   MSG_TAG_BT_SPP_LAST_REQ_MSG = MSG_ID_BT_FAX_AUTH_RSP,  

   /*APP <-- SPP*/
   MSG_ID_BT_SPP_CONNECT_IND,
   MSG_ID_BT_SPP_SCO_CONNECT_IND,   
   MSG_ID_BT_SPP_DISCONNECT_IND,
   MSG_ID_BT_SPP_ACTIVATE_CNF,
   MSG_ID_BT_SPP_DEACTIVATE_CNF,
   MSG_ID_BT_SPP_DISCONNECT_CNF,
   MSG_ID_BT_SPP_AUTH_REQ, 
   MSG_ID_BT_SPP_AUDIO_CONNECT_CNF,
   MSG_ID_BT_SPP_AUDIO_CONNECT_IND,
   MSG_ID_BT_SPP_AUDIO_DISCONNECT_CNF,
   MSG_ID_BT_SPP_AUDIO_DISCONNECT_IND, 
   MSG_ID_BT_SPP_SCO_RSSI_IND, 
   MSG_ID_BT_SPP_CONNECT_CNF,   

   MSG_ID_BT_SPP_UART_OWNER_IND,  

   /*APP <-- DUN*/
   MSG_ID_BT_DUN_CONNECT_IND,
   MSG_ID_BT_DUN_DISCONNECT_IND,
   MSG_ID_BT_DUN_ACTIVATE_CNF,
   MSG_ID_BT_DUN_DEACTIVATE_CNF,
   MSG_ID_BT_DUN_DISCONNECT_CNF,
   MSG_ID_BT_DUN_AUTH_REQ,

    
   MSG_ID_BT_FAX_CONNECT_IND,
   MSG_ID_BT_FAX_DISCONNECT_IND,
   MSG_ID_BT_FAX_ACTIVATE_CNF,
   MSG_ID_BT_FAX_DEACTIVATE_CNF,
   MSG_ID_BT_FAX_DISCONNECT_CNF,
   MSG_ID_BT_FAX_AUTH_REQ,

    /*APP --> BMA*/
    MSG_TAG_BT_BM_FIRST_REQ_MSG,
    MSG_ID_BT_BM_DISCOVERY_REQ = MSG_TAG_BT_BM_FIRST_REQ_MSG,
    MSG_ID_BT_BM_DISCOVERY_CANCEL_REQ,
    MSG_ID_BT_BM_WRITE_LOCAL_NAME_REQ,
    MSG_ID_BT_BM_READ_LOCAL_NAME_REQ,
    MSG_ID_BT_BM_READ_REMOTE_NAME_REQ,
    MSG_ID_BT_BM_WRITE_SCANENABLE_MODE_REQ,
    MSG_ID_BT_BM_READ_SCANENABLE_MODE_REQ,
    MSG_ID_BT_BM_READ_LOCAL_ADDR_REQ,
    MSG_ID_BT_BM_READ_LOCAL_COD_REQ,
    MSG_ID_BT_BM_WRITE_LOCAL_COD_REQ,
    MSG_ID_BT_BM_READ_PROPERTY_REQ,
    MSG_ID_BT_BM_WRITE_AUTHENTICATION_MODE_REQ,
    MSG_ID_BT_BM_PIN_CODE_RSP,
    MSG_ID_BT_BM_BONDING_REQ,
    MSG_ID_BT_BM_DELETE_TRUST_REQ,
    MSG_ID_BT_BM_DELETE_TRUST_ALL_REQ,
    MSG_ID_BT_BM_BONDING_CANCEL_REQ,
    MSG_ID_BT_BM_PAIRING_CANCEL_REQ,
    MSG_ID_BT_BM_SAVE_SETTING_REQ,
    MSG_ID_BT_BM_RESTORE_SETTING_REQ,
    MSG_ID_BT_BM_SERVICE_SEARCH_REQ,
    MSG_ID_BT_BM_SEARCH_ATTRIBUTE_REQ,
    MSG_ID_BT_BM_SEARCH_RAW_REQ,
    MSG_ID_BT_BM_LINK_ALLOW_REQ,
    MSG_ID_BT_BM_LINK_DISALLOW_REQ,
    MSG_ID_BT_BM_LINK_CONNECT_ACCEPT_NOT_AUTO_REQ,
    MSG_ID_BT_BM_LINK_CONNECT_ACCEPT_RSP,    
    MSG_ID_BT_BM_GET_LINK_STATE_REQ,
    MSG_ID_BT_BM_SET_LINK_STATE_REQ,   
    MSG_TAG_BT_BM_LAST_REQ_MSG = MSG_ID_BT_BM_SET_LINK_STATE_REQ,

    /*BMA --> APP*/
    MSG_TAG_BT_BMAPP_FIRST_REQ_MSG,
    MSG_ID_BT_BM_DISCOVERY_RESULT_IND = MSG_TAG_BT_BMAPP_FIRST_REQ_MSG,
    MSG_ID_BT_BM_DISCOVERY_CNF,
    MSG_ID_BT_BM_DISCOVERY_CANCEL_CNF,
    MSG_ID_BT_BM_WRITE_LOCAL_NAME_CNF,
    MSG_ID_BT_BM_READ_LOCAL_NAME_CNF,
    MSG_ID_BT_BM_READ_REMOTE_NAME_CNF,
    MSG_ID_BT_BM_WRITE_SCANENABLE_MODE_CNF,
    MSG_ID_BT_BM_READ_SCANENABLE_MODE_CNF,
    MSG_ID_BT_BM_READ_LOCAL_ADDR_CNF,
    MSG_ID_BT_BM_READ_LOCAL_COD_CNF,
    MSG_ID_BT_BM_WRITE_LOCAL_COD_CNF,
    MSG_ID_BT_BM_READ_PROPERTY_CNF,
    MSG_ID_BT_BM_WRITE_AUTHENTICATION_MODE_CNF,
    MSG_ID_BT_BM_PIN_CODE_IND,
    MSG_ID_BT_BM_BONDING_CNF,
    MSG_ID_BT_BM_BE_BONDING_CNF,
    MSG_ID_BT_BM_BONDING_RESULT_IND,
    MSG_ID_BT_BM_DELETE_TRUST_CNF,
    MSG_ID_BT_BM_DELETE_TRUST_ALL_CNF,
    MSG_ID_BT_BM_BONDING_CANCEL_CNF,
    MSG_ID_BT_BM_PAIRING_CANCEL_CNF,
    MSG_ID_BT_BM_SAVE_SETTING_CNF,
    MSG_ID_BT_BM_RESTORE_SETTING_CNF,
    MSG_ID_BT_BM_SERVICE_SEARCH_RESULT_IND,
    MSG_ID_BT_BM_SERVICE_SEARCH_CNF,
    MSG_ID_BT_BM_SEARCH_ATTRIBUT_RESULT_IND,
    MSG_ID_BT_BM_SEARCH_ATTRIBUTE_CNF,
    MSG_ID_BT_BM_SEARCH_RAW_RESULT,    
    MSG_ID_BT_BM_SEARCH_RAW_CNF,
    MSG_ID_BT_BM_LINK_STATE_IND,
    MSG_ID_BT_BM_LINK_ALLOW_CNF,
    MSG_ID_BT_BM_LINK_DISALLOW_CNF,    
    MSG_ID_BT_BM_LINK_CONNECT_ACCEPT_IND,    
    MSG_ID_BT_BM_GET_LINK_STATE_CNF,   
    MSG_ID_BT_BM_SET_LINK_STATE_CNF,   
    MSG_TAG_BT_BMAPP_LAST_REQ_MSG = MSG_ID_BT_BM_SET_LINK_STATE_CNF,


    /* APP --> HSG */
    MSG_TAG_BT_HSG_FIRST_REQ_MSG,
    MSG_ID_BT_HSG_ACTIVATE_REQ = MSG_TAG_BT_HSG_FIRST_REQ_MSG,
    MSG_ID_BT_HSG_DEACTIVATE_REQ,
    MSG_ID_BT_HSG_CONNECT_REQ,
	MSG_ID_BT_HSG_CONNECT_IND_RES,
    MSG_ID_BT_HSG_DISCONNECT_REQ,    
    MSG_ID_BT_HSG_BUTTONPRESS_REQ,
    MSG_ID_BT_HSG_MVOLUMEDOWN_REQ,
    MSG_ID_BT_HSG_MVOLUMEUP_REQ,
    MSG_ID_BT_HSG_SVOLUMEDOWN_REQ,
    MSG_ID_BT_HSG_SVOLUMEUP_REQ,  
    MSG_ID_BT_HSG_SPEAKER_GAIN_REQ,
    MSG_ID_BT_HSG_MIC_GAIN_REQ,
    MSG_TAG_BT_HSG_LAST_REQ_MSG = MSG_ID_BT_HSG_MIC_GAIN_REQ,
	
    /* APP <-- HSG */
    MSG_ID_BT_HSG_ACTIVATE_CNF,
    MSG_ID_BT_HSG_DEACTIVATE_CNF,    
    MSG_ID_BT_HSG_CONNECT_CNF,
    MSG_ID_BT_HSG_CONNECT_IND,
	MSG_ID_BT_HSG_CONNECT_IND_REQ,
    MSG_ID_BT_HSG_DISCONNECT_CNF,
    MSG_ID_BT_HSG_DISCONNECT_IND,
    MSG_ID_BT_HSG_SPEAKER_GAIN_CNF,
    MSG_ID_BT_HSG_SPEAKER_GAIN_IND,
    MSG_ID_BT_HSG_MIC_GAIN_IND,
    MSG_ID_BT_HSG_MIC_GAIN_CNF,
    MSG_ID_BT_HSG_HANGUP_REQ,
    MSG_ID_BT_HSG_INCOMING_ACCEPT_REQ,
      
   /*APP --> HFG*/
   MSG_TAG_BT_HFG_FIRST_REQ_MSG,
   MSG_ID_BT_HFG_ACTIVATE_REQ = MSG_TAG_BT_HFG_FIRST_REQ_MSG,   
   MSG_ID_BT_HFG_DEACTIVATE_REQ,
   MSG_ID_BT_HFG_DISCONNECT_REQ,
   MSG_ID_BT_HFG_CONNECT_REQ,
   MSG_ID_BT_HFG_CONNECT_IND_RES,
   MSG_ID_BT_HFG_SCO_CONNECT_REQ,
   MSG_ID_BT_HFG_SCO_DISCONNECT_REQ,
   MSG_ID_BT_HFG_SPEAKER_GAIN_REQ,
   MSG_ID_BT_HFG_MIC_GAIN_REQ,
 //  MSG_ID_BT_HFG_REDIAL_FIAL_IND,
   MSG_ID_BT_HFG_INCOMING_DISCONNECT_REQ,
   MSG_ID_BT_HFG_SEND_DATA_REQ,
   MSG_TAG_BT_HFG_LAST_REQ_MSG = MSG_ID_BT_HFG_SEND_DATA_REQ,

   /*APP <-- HFG*/
   MSG_ID_BT_HFG_ACTIVATE_CNF,
   MSG_ID_BT_HFG_DEACTIVATE_CNF,   
   MSG_ID_BT_HFG_CONNECT_CNF,   
   MSG_ID_BT_HFG_CONNECT_IND,
   MSG_ID_BT_HFG_SLC_FINISH_IND,
   MSG_ID_BT_HFG_CONNECT_IND_REQ,
   MSG_ID_BT_HFG_DISCONNECT_CNF,   
   MSG_ID_BT_HFG_DISCONNECT_IND,
   MSG_ID_BT_HFG_SCO_CONNECT_CNF,
   MSG_ID_BT_HFG_SCO_CONNECT_IND,
   MSG_ID_BT_HFG_SCO_DISCONNECT_CNF,
   MSG_ID_BT_HFG_SCO_DISCONNECT_IND,
   MSG_ID_BT_HFG_SPEAKER_GAIN_CNF,
   MSG_ID_BT_HFG_SPEAKER_GAIN_IND,
   MSG_ID_BT_HFG_MIC_GAIN_IND,
   MSG_ID_BT_HFG_MIC_GAIN_CNF,
   MSG_ID_BT_HFG_HANGUP_REQ,
   MSG_ID_BT_HFG_INCOMING_ACCEPT_REQ,
   MSG_ID_BT_HFG_INCOMING_REJECT_REQ,
   MSG_ID_BT_HFG_REDIAL_LASTNUMB_REQ,
   
   /*APP --> HIDD*/
   MSG_TAG_BT_HIDD_FIRST_REQ_MSG,
   MSG_ID_BT_HIDD_ACTIVATE_REQ = MSG_TAG_BT_HIDD_FIRST_REQ_MSG,   
   MSG_ID_BT_HIDD_DEACTIVATE_REQ,
   MSG_ID_BT_HIDD_CONNECT_REQ,
   MSG_ID_BT_HIDD_CONNECTION_AUTHORIZE_RSP,
   MSG_ID_BT_HIDD_CONTROL_REQ,
   MSG_ID_BT_HIDD_DISCONNECT_REQ,
   MSG_ID_BT_HIDD_INTERRUPT_DATA_REQ,
   MSG_ID_BT_HIDD_GET_REPORT_RSP,
   MSG_ID_BT_HIDD_SET_REPORT_RSP,
   MSG_ID_BT_HIDD_GET_PROTOCOL_RSP,
   MSG_ID_BT_HIDD_SET_PROTOCOL_RSP,
   MSG_ID_BT_HIDD_GET_IDLE_RATE_RSP,
   MSG_ID_BT_HIDD_SET_IDLE_RATE_RSP,
   MSG_TAG_BT_HIDD_LAST_REQ_MSG = MSG_ID_BT_HIDD_SET_IDLE_RATE_RSP,

   /*APP <-- HIDD*/
   MSG_ID_BT_HIDD_ACTIVATE_CNF,
   MSG_ID_BT_HIDD_DEACTIVATE_CNF,   
   MSG_ID_BT_HIDD_CONNECT_CNF,   
   MSG_ID_BT_HIDD_CONNECT_IND,
   MSG_ID_BT_HIDD_CONNECTION_AUTHORIZE_IND,
   MSG_ID_BT_HIDD_DISCONNECT_CNF,   
   MSG_ID_BT_HIDD_DISCONNECT_IND,
   MSG_ID_BT_HIDD_CONTROL_CNF,
   MSG_ID_BT_HIDD_CONTROL_IND,
   MSG_ID_BT_HIDD_INTERRUPT_DATA_CNF,
   MSG_ID_BT_HIDD_INTERRUPT_DATA_IND,
   MSG_ID_BT_HIDD_GET_REPORT_IND,
   MSG_ID_BT_HIDD_SET_REPORT_IND,
   MSG_ID_BT_HIDD_GET_PROTOCOL_IND,
   MSG_ID_BT_HIDD_SET_PROTOCOL_IND,
   MSG_ID_BT_HIDD_GET_IDLE_RATE_IND,
   MSG_ID_BT_HIDD_SET_IDLE_RATE_IND,

   /*APP --> AVRCP*/
   MSG_TAG_BT_AVCTP_FIRST_REQ_MSG,
   MSG_ID_BT_AVCTP_ACTIVATE_REQ = MSG_TAG_BT_AVCTP_FIRST_REQ_MSG,   
   MSG_ID_BT_AVCTP_INIT_REQ,
   MSG_ID_BT_AVCTP_CONNECT_REQ,
   MSG_ID_BT_AVCTP_CONNECT_RSP,            
   MSG_ID_BT_AVCTP_DISCONNECT_REQ,     
   MSG_ID_BT_AVCTP_DATA_REQ,    
   MSG_TAG_BT_AVCTP_LAST_REQ_MSG = MSG_ID_BT_AVCTP_DATA_REQ,

   
   /*A2DP*/
   // for MMI
   MSG_ID_BT_A2DP_ACTIVATE_REQ,
   MSG_ID_BT_A2DP_ACTIVATE_CNF,
   MSG_ID_BT_A2DP_DEACTIVATE_REQ,
   MSG_ID_BT_A2DP_DEACTIVATE_CNF,
   MSG_ID_BT_A2DP_SIGNAL_CONNECT_REQ,
   MSG_ID_BT_A2DP_SIGNAL_CONNECT_CNF,
   MSG_ID_BT_A2DP_SIGNAL_CONNECT_IND,
   MSG_ID_BT_A2DP_SIGNAL_DISCONNECT_REQ,
   MSG_ID_BT_A2DP_SIGNAL_DISCONNECT_CNF,
   MSG_ID_BT_A2DP_SIGNAL_DISCONNECT_IND,
   // for MED
   MSG_ID_BT_A2DP_SEP_DISCOVER_REQ,
   MSG_ID_BT_A2DP_SEP_DISCOVER_CNF,
   MSG_ID_BT_A2DP_SEP_DISCOVER_IND,
   MSG_ID_BT_A2DP_SEP_DISCOVER_RES,
   MSG_ID_BT_A2DP_CAPABILITIES_GET_REQ,
   MSG_ID_BT_A2DP_CAPABILITIES_GET_CNF,
   MSG_ID_BT_A2DP_CAPABILITIES_GET_IND,
   MSG_ID_BT_A2DP_CAPABILITIES_GET_RES,
   MSG_ID_BT_A2DP_STREAM_CONFIG_REQ,
   MSG_ID_BT_A2DP_STREAM_CONFIG_CNF,
   MSG_ID_BT_A2DP_STREAM_CONFIG_IND,
   MSG_ID_BT_A2DP_STREAM_CONFIG_RES,
   MSG_ID_BT_A2DP_STREAM_RECONFIG_REQ,
   MSG_ID_BT_A2DP_STREAM_RECONFIG_CNF,
   MSG_ID_BT_A2DP_STREAM_RECONFIG_IND,
   MSG_ID_BT_A2DP_STREAM_RECONFIG_RES,
   MSG_ID_BT_A2DP_STREAM_OPEN_REQ,
   MSG_ID_BT_A2DP_STREAM_OPEN_CNF,
   MSG_ID_BT_A2DP_STREAM_OPEN_IND,
   MSG_ID_BT_A2DP_STREAM_OPEN_RES,
   MSG_ID_BT_A2DP_STREAM_START_REQ,
   MSG_ID_BT_A2DP_STREAM_START_CNF,
   MSG_ID_BT_A2DP_STREAM_START_IND,
   MSG_ID_BT_A2DP_STREAM_START_RES,
   MSG_ID_BT_A2DP_STREAM_PAUSE_REQ,
   MSG_ID_BT_A2DP_STREAM_PAUSE_CNF,
   MSG_ID_BT_A2DP_STREAM_PAUSE_IND,
   MSG_ID_BT_A2DP_STREAM_PAUSE_RES,
   MSG_ID_BT_A2DP_STREAM_QOS_IND,
   MSG_ID_BT_A2DP_STREAM_DATA_SEND_REQ,
   MSG_ID_BT_A2DP_STREAM_CLOSE_REQ,
   MSG_ID_BT_A2DP_STREAM_CLOSE_CNF,
   MSG_ID_BT_A2DP_STREAM_CLOSE_IND,
   MSG_ID_BT_A2DP_STREAM_CLOSE_RES,
   MSG_ID_BT_A2DP_STREAM_ABORT_REQ,
   MSG_ID_BT_A2DP_STREAM_ABORT_CNF,
   MSG_ID_BT_A2DP_STREAM_ABORT_IND,
   MSG_ID_BT_A2DP_STREAM_ABORT_RES,

   /*AVRCP*/   
   MSG_ID_BT_AVRCP_ACTIVATE_REQ,
   MSG_ID_BT_AVRCP_ACTIVATE_CNF,
   MSG_ID_BT_AVRCP_DEACTIVATE_REQ,
   MSG_ID_BT_AVRCP_DEACTIVATE_CNF,
   MSG_ID_BT_AVRCP_CONNECT_REQ,
   MSG_ID_BT_AVRCP_CONNECT_CNF,
   MSG_ID_BT_AVRCP_CONNECT_IND,
   MSG_ID_BT_AVRCP_CONNECT_IND_RES,
   MSG_ID_BT_AVRCP_DISCONNECT_REQ,
   MSG_ID_BT_AVRCP_DISCONNECT_CNF, 
   MSG_ID_BT_AVRCP_DISCONNECT_IND,
   
   MSG_ID_BT_AVRCP_CMD_FRAME_REQ,
   MSG_ID_BT_AVRCP_CMD_FRAME_CNF,
   MSG_ID_BT_AVRCP_CMD_FRAME_IND,
   MSG_ID_BT_AVRCP_CMD_FRAME_IND_RES,


   MSG_TAG_BT_TEST_FIRST_REQ_MSG,

   MSG_ID_BT_SDP_TEST_ACTIVATE_REQ = MSG_TAG_BT_TEST_FIRST_REQ_MSG,
   MSG_ID_BT_SDP_TEST_CLOSE_REQ,
   MSG_ID_BT_RFCOMM_TEST_ACTIVATE_REQ,
   MSG_ID_BT_L2CAP_TEST_CMD_REQ,
   MSG_ID_BT_GAP_TEST_CMD_REQ,
   MSG_ID_BT_AVDTP_TEST_CMD_REQ,
   MSG_ID_BT_JBT_TEST_CMD_REQ,
   MSG_ID_BT_SIMAP_TEST_ACTIVATE_REQ,
   MSG_TAG_BT_TEST_LAST_REQ_MSG = MSG_ID_BT_SIMAP_TEST_ACTIVATE_REQ,
   
   MSG_TAG_BT_SDPDB_FIRST_REQ_MSG,
   MSG_ID_BT_SDPDB_REGISTER_REQ = MSG_TAG_BT_SDPDB_FIRST_REQ_MSG,
   MSG_ID_BT_SDPDB_DEREGISTER_REQ,
   MSG_TAG_BT_SDPDB_LAST_REQ_MSG = MSG_ID_BT_SDPDB_DEREGISTER_REQ,
   MSG_ID_BT_SDPDB_REGISTER_CNF,
   MSG_ID_BT_SDPDB_DEREGISTER_CNF,
   
   /* JSR82 SDPDB REGISTERATION */
   MSG_TAG_BT_APP_SDPDB_FIRST_MSG,
   MSG_ID_BT_APP_SDPDB_GET_HANDLE_REQ = MSG_TAG_BT_APP_SDPDB_FIRST_MSG,
   MSG_ID_BT_APP_SDPDB_REGISTER_REQ,
   MSG_ID_BT_APP_SDPDB_RETRIEVE_RECOED_REQ,
   MSG_ID_BT_APP_SDPDB_DEREGISTER_REQ,
   MSG_ID_BT_APP_SDPDB_GET_HANDLE_CNF,
   MSG_ID_BT_APP_SDPDB_REGISTER_CNF,
   MSG_ID_BT_APP_SDPDB_RETRIEVE_RECOED_CNF,
   MSG_ID_BT_APP_SDPDB_DEREGISTER_CNF,
   MSG_TAG_BT_APP_SDPDB_LAST_MSG = MSG_ID_BT_APP_SDPDB_DEREGISTER_CNF,

   /* JSR82 SECURITY REGISTERATION */
   MSG_TAG_BT_JSR82_SEC_FIRST_MSG,
   MSG_ID_BT_JSR82_AUTHENTICATION_REQ = MSG_TAG_BT_JSR82_SEC_FIRST_MSG,
   MSG_ID_BT_JSR82_AUTHORIZATION_REQ,
   MSG_ID_BT_JSR82_ENCRYPTION_REQ,
   MSG_ID_BT_JSR82_AUTHENTICATION_CNF,
   MSG_ID_BT_JSR82_AUTHORIZATION_CNF,
   MSG_ID_BT_JSR82_ENCRYPTION_CNF,
   MSG_TAG_BT_SEC_LAST_MSG = MSG_ID_BT_JSR82_ENCRYPTION_CNF,

   /*GOEP*/
   MSG_ID_GOEP_REGISTER_SERVER_REQ,
   MSG_ID_GOEP_REGISTER_SERVER_RSP,
   MSG_ID_GOEP_DEREGISTER_SERVER_REQ,
   MSG_ID_GOEP_DEREGISTER_SERVER_RSP,
   MSG_ID_GOEP_CONNECT_IND,
   MSG_ID_GOEP_CONNECT_RES,
   MSG_ID_GOEP_PUSH_IND,
   MSG_ID_GOEP_PUSH_RES,
   MSG_ID_GOEP_PULL_IND,
   MSG_ID_GOEP_PULL_RES,
   MSG_ID_GOEP_SET_FOLDER_IND,
   MSG_ID_GOEP_SET_FOLDER_RES,
   MSG_ID_GOEP_ABORT_IND,
   MSG_ID_GOEP_ABORT_RES,
   MSG_ID_GOEP_AUTH_REQ,
   MSG_ID_GOEP_AUTH_RSP,
   MSG_ID_GOEP_REGISTER_CLIENT_REQ,
   MSG_ID_GOEP_REGISTER_CLIENT_RSP,
   MSG_ID_GOEP_DEREGISTER_CLIENT_REQ,
   MSG_ID_GOEP_DEREGISTER_CLIENT_RSP,
   MSG_ID_GOEP_CONNECT_REQ,
   MSG_ID_GOEP_CONNECT_RSP,
   MSG_ID_GOEP_PUSH_REQ,
   MSG_ID_GOEP_PUSH_RSP,
   MSG_ID_GOEP_PULL_REQ,
   MSG_ID_GOEP_PULL_RSP,
   MSG_ID_GOEP_SET_FOLDER_REQ,
   MSG_ID_GOEP_SET_FOLDER_RSP,
   MSG_ID_GOEP_ABORT_REQ,
   MSG_ID_GOEP_ABORT_RSP,
   MSG_ID_GOEP_DISCONNECT_REQ,
   MSG_ID_GOEP_DISCONNECT_RSP,
   MSG_ID_GOEP_DISCONNECT_IND,
   MSG_ID_GOEP_DISCONNECT_RES,
   MSG_ID_GOEP_TPDISCONNECT_REQ,
   MSG_ID_GOEP_AUTH_IND,
   MSG_ID_GOEP_AUTH_RES,
   MSG_ID_GOEP_AUTHORIZE_IND,
   MSG_ID_GOEP_AUTHORIZE_RES,
      
   MSG_TAG_BT_APP_REG_SERVICE_FIRST_REQ_MSG,
   MSG_ID_BT_RECORD_REG_REQ = MSG_TAG_BT_APP_REG_SERVICE_FIRST_REQ_MSG,
   MSG_ID_BT_RECORD_UNREQ_REQ,
   MSG_ID_BT_RECORD_REQ_CNF,
   MSG_ID_BT_RECORD_UNREQ_CNF,
   MSG_TAG_BT_APP_REG_SERVICE_LAST_REQ_MSG = MSG_ID_BT_RECORD_UNREQ_CNF,

      
   /* SIM Access Profile : SIMAP */

   /* APP --> BT SIMAP */
   MSG_TAG_BT_SIMAP_FIRST_REQ_MSG,
   MSG_ID_BT_SIMAP_ACTIVATE_REQ = MSG_TAG_BT_SIMAP_FIRST_REQ_MSG,
   MSG_ID_BT_SIMAP_DEACTIVATE_REQ,
   MSG_ID_BT_SIMAP_AUTH_RSP,
   /* MSG_ID_BT_SIMAP_DISCONNECT_REQ: This msg is used to notify BT that the user wants to close the connection */
   MSG_ID_BT_SIMAP_DISCONNECT_REQ,
   MSG_TAG_BT_SIMAP_LAST_REQ_MSG = MSG_ID_BT_SIMAP_DISCONNECT_REQ,
   
   /* BT SIMAP --> APP */
   
   /* MSG_ID_BT_SIMAP_AUTH_REQ: This msg is used to let MMI ask the user to accept the remote connection or not */
   MSG_ID_BT_SIMAP_ACTIVATE_CNF,
   MSG_ID_BT_SIMAP_DEACTIVATE_CNF, 
   MSG_ID_BT_SIMAP_AUTH_REQ,
   MSG_ID_BT_SIMAP_CONNECT_CNF,
   MSG_ID_BT_SIMAP_CONNECT_IND,
   MSG_ID_BT_SIMAP_DISCONNECT_CNF,
   /* MSG_ID_BT_SIMAP_DISCONNECT_IND: This msg is used to notify MMI that the connection is closed */  
   MSG_ID_BT_SIMAP_DISCONNECT_IND,
   
   

 
   /* BT SIMAP -> SIM */
   MSG_ID_BT_SIM_CONNECT_REQ,
   MSG_ID_BT_SIM_RESET_REQ,
   MSG_ID_BT_SIM_APDU_REQ,
   MSG_ID_BT_SIM_DISCONNECT_REQ,
   MSG_ID_BT_SIM_POWER_OFF_REQ,
   
   /* SIM --> BT SIMAP */
   MSG_TAG_BT_SIM_FIRST_REQ_MSG,
   MSG_ID_BT_SIM_CONNECT_CNF = MSG_TAG_BT_SIM_FIRST_REQ_MSG,
   MSG_ID_BT_SIM_RESET_CNF,
   MSG_ID_BT_SIM_APDU_CNF,
   MSG_ID_BT_SIM_DISCONNECT_CNF,
   MSG_ID_BT_SIM_POWER_OFF_CNF,   
   MSG_TAG_BT_SIM_LAST_REQ_MSG = MSG_ID_BT_SIM_POWER_OFF_CNF,

 /* JSR82 SESSION OPERATION */
   MSG_TAG_BT_JSR82_SECTION_FIRST_MSG,
   MSG_ID_BT_JSR82_CONNECT_REQ = MSG_TAG_BT_JSR82_SECTION_FIRST_MSG,
   MSG_ID_BT_JSR82_CONNECT_CFN,
   MSG_ID_BT_JSR82_ENABLE_SERVICE_REQ,
   MSG_ID_BT_JSR82_ENABLE_SERVICE_CNF,
   MSG_ID_BT_JSR82_TURNON_SERVICE_REQ,
   MSG_ID_BT_JSR82_TURNON_SERVICE_CNF,
   MSG_ID_BT_JSR82_DISABLE_SERVICE_REQ,
   MSG_ID_BT_JSR82_DISABLE_SERVICE_CNF,   
   MSG_ID_BT_JSR82_CONNECT_IND,
   MSG_ID_BT_JSR82_CONNECT_RSP,
   MSG_ID_BT_JSR82_DISCONNECT_REQ,
   MSG_ID_BT_JSR82_DISCONNECT_IND,
   MSG_ID_BT_JSR82_TX_DATA_REQ,
   MSG_ID_BT_JSR82_TX_DATA_CFN,   
   MSG_ID_BT_JSR82_RX_DATA_IND,
   MSG_ID_BT_JSR82_RX_DATA_RSP,   
   MSG_TAG_BT_JSR82_SECTION_LAST_MSG = MSG_ID_BT_JSR82_RX_DATA_RSP,   
   
   /* BPP */
   MSG_ID_BT_BPP_CONNECT_REQ,
   MSG_ID_BT_BPP_CONNECT_CNF,
   MSG_ID_BT_BPP_AUTHENTICATION_IND,
   MSG_ID_BT_BPP_AUTHENTICATION_RSP,
   MSG_ID_BT_BPP_DISCONNECT_REQ,
   MSG_ID_BT_BPP_DISCONNECT_IND,
   MSG_ID_BT_BPP_GET_PRINTER_ATTR_REQ,
   MSG_ID_BT_BPP_GET_PRINTER_ATTR_CNF,
   MSG_ID_BT_BPP_CREATE_JOB_REQ,
   MSG_ID_BT_BPP_CREATE_JOB_CNF,
   MSG_ID_BT_BPP_EVENT_IND,
   MSG_ID_BT_BPP_SEND_DOC_REQ,
   MSG_ID_BT_BPP_SEND_DOC_CNF,
   MSG_ID_BT_BPP_PROG_UPDATE_IND,
   MSG_ID_BT_BPP_PROG_UPDATE_RSP,
   
   /* BIP */
   MSG_ID_BT_BIP_CONNECT_REQ,
   MSG_ID_BT_BIP_CONNECT_CNF,
   MSG_ID_BT_BIP_DISCONNECT_REQ,
   MSG_ID_BT_BIP_GET_CAPABILITIES_REQ,
   MSG_ID_BT_BIP_GET_CAPABILITIES_CNF,
   MSG_ID_BT_BIP_PUT_IMG_REQ,
   MSG_ID_BT_BIP_PUT_IMG_CNF,
   MSG_ID_BT_BIP_PUT_LINKED_THUMBNAIL_REQ,
   MSG_ID_BT_BIP_PUT_LINKED_THUMBNAIL_CNF,
   MSG_ID_BT_BIP_GET_IMG_LIST_REQ,
   MSG_ID_BT_BIP_GET_IMG_LIST_CNF,
   MSG_ID_BT_BIP_GET_IMG_PROP_REQ,
   MSG_ID_BT_BIP_GET_IMG_PROP_CNF,
   MSG_ID_BT_BIP_GET_IMG_REQ,
   MSG_ID_BT_BIP_GET_IMG_CNF,
   MSG_ID_BT_BIP_GET_LINKED_THUMBNAIL_REQ,
   MSG_ID_BT_BIP_GET_LINKED_THUMBNAIL_CNF,
   MSG_ID_BT_BIP_GET_MONITORING_IMG_REQ,
   MSG_ID_BT_BIP_GET_MONITORING_IMG_CNF,
   MSG_ID_BT_BIP_ABORT_REQ,
   MSG_ID_BT_BIP_ABORT_CNF,
   MSG_ID_BT_BIP_ACTIVATE_REQ,
   MSG_ID_BT_BIP_ACTIVATE_CNF,
   MSG_ID_BT_BIP_DEACTIVATE_REQ,
   MSG_ID_BT_BIP_DEACTIVATE_CNF,
   MSG_ID_BT_BIP_CONNECT_IND,
   MSG_ID_BT_BIP_CONNECT_RSP,
   MSG_ID_BT_BIP_GET_CAPABILITIES_IND,
   MSG_ID_BT_BIP_GET_CAPABILITIES_RSP,
   MSG_ID_BT_BIP_PUT_IMG_IND,
   MSG_ID_BT_BIP_PUT_IMG_RSP,
   MSG_ID_BT_BIP_PUT_LINKED_THUMBNAIL_IND,
   MSG_ID_BT_BIP_PUT_LINKED_THUMBNAIL_RSP,
   MSG_ID_BT_BIP_GET_IMG_LIST_IND,
   MSG_ID_BT_BIP_GET_IMG_LIST_RSP,
   MSG_ID_BT_BIP_GET_IMG_PROP_IND,
   MSG_ID_BT_BIP_GET_IMG_PROP_RSP,
   MSG_ID_BT_BIP_GET_IMG_IND,
   MSG_ID_BT_BIP_GET_IMG_RSP,
   MSG_ID_BT_BIP_GET_LINKED_THUMBNAIL_IND,
   MSG_ID_BT_BIP_GET_LINKED_THUMBNAIL_RSP,
   MSG_ID_BT_BIP_GET_MONITORING_IMG_IND,
   MSG_ID_BT_BIP_GET_MONITORING_IMG_RSP,
   MSG_ID_BT_BIP_CONTINUE_IND,
   MSG_ID_BT_BIP_CONTINUE_RSP,
   MSG_ID_BT_BIP_ABORT_IND,
   MSG_ID_BT_BIP_COMPLETE_IND,
   MSG_ID_BT_BIP_DISCONNECT_IND,

   MSG_TAG_BT_SAP_END_MSG,

