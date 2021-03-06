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
 *   FMScheduleRecDef.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  .............
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
 *
 *
 *------------------------------------------------------------------------------
 
 *============================================================================
 ****************************************************************************/
#ifndef _MMI_FMSRDEF_H
#define _MMI_FMSRDEF_H

#include "mmi_features.h" 

#ifdef __MMI_FM_RADIO_SCHEDULE_REC__

/* if some header should be include before this one */
//#ifndef _PREINC_H
//#error "preinc.h should be included before header.h"
//#endif


/* 
** Define
*/

/*Note these defines should be the same as sound recorder*/
#define MAX_FMSR_FILE_NAME_LEN		80
#define MAX_FMSR_PATH_LEN			25	/*The path is fixed. i.e "c:\audio\"*/
#define MAX_FMSR_FULL_NAME_LEN	(MAX_FMSR_PATH_LEN+MAX_FMSR_FILE_NAME_LEN)
//#define MAX_FMSR_INPUT_FILE_LEN	35  

#define FMSR_MAX_MSG_BUFFER		500

#define FMSR_FILE_EXT_AMR	".amr"
#define FMSR_FILE_EXT_MP3	".mp3"
#define FMSR_FILE_EXT_WAV	".wav"
#define FMSR_FILE_EXT_AWB	L".awb"

#define FMSR_NUM_DAYS	7
#define FMSR_FREQ_INPUT_LEN	6	/* "107.7" */
#define FMSR_FREQ_DISPLAY_LEN	10	/* "FM 107.7" */
#define FMSR_MIN_FREQUENCY 875
#define FMSR_MAX_FREQUENCY 1080

#define FMSR_MAX_YEAR	2030
#define FMSR_MIN_YEAR	2004


#define FMSR_MSG_NONE	0
#define FMSR_MSG_REC_INTERRUPT		0x00000001
#define FMSR_MSG_USER_STOP			0x00000002
#define FMSR_MSG_REC_PAUSE			0x00000004
#define FMSR_MSG_DEFAULT_FILE		0x00000008

#if defined(__DRM_SUPPORT__)
#define DRM_NOT_PERMIT_TO_APPEND	10000
#endif

#ifndef MAX_VOL_LEVEL
#define MAX_VOL_LEVEL 7
#endif
/* 
** Typedef 
*/

typedef enum 
{
	FMSR_ERROR_TIME_EXPIRE = 10001,
	FMSR_ERROR_INVALID_FREQ,
	FMSR_ERROR_NO_FOLDER,
	FMSR_ERROR_USB_MODE,
	FMSR_ERROR_TOTAL
} fmsr_err_code_enum;


typedef enum 
{
	STR_ID_FMSR_BASE = FM_SCHEDULE_REC_BASE+1,
	STR_ID_FMSR_APP,
	STR_ID_FMSR_SAVE_CONFIRM,
	STR_ID_FMSR_CHAN_SETTING,
	STR_ID_FMSR_CHAN_LIST,
	STR_ID_FMSR_CHAN_MANUAL,
	STR_ID_FMSR_REC_SETTING,
	STR_ID_FMSR_REPEAT,
	STR_ID_FMSR_ONCE,
	STR_ID_FMSR_EVERYDAY,
	STR_ID_FMSR_DAYS,
	STR_ID_FMSR_WEEKLY,
	STR_ID_FMSR_MONTHLY,
	STR_ID_FMSR_REC_FORMAT,
	STR_ID_FMSR_REC_TYPE,
	STR_ID_FMSR_REC_STORAGE,
	STR_ID_FMSR_AMR,
	STR_ID_FMSR_WAV,
	STR_ID_FMSR_NEW_FILE,
	STR_ID_FMSR_APPEND_FILE,
	STR_ID_FMSR_PHONE,
	STR_ID_FMSR_CARD,
	STR_ID_FMSR_STOP,
	STR_ID_FMSR_PAUSE,
	STR_ID_FMSR_RESUME,
	STR_ID_FMSR_RECORDING,
	STR_ID_FMSR_BAD_FORMAT,
	STR_ID_FMSR_INVALID_FORMAT,
	STR_ID_FMSR_DEVICE_BUSY,
	STR_ID_FMSR_OPEN_FILE_ERROR,
	STR_ID_FMSR_NO_CARD,
	STR_ID_FMSR_WRITE_PROTECTION_ERROR,
	STR_ID_FMSR_VALID_FREQUENCY,
	STR_ID_FMSR_FILENAME_TOO_LONG,
	STR_ID_FMSR_FILE_EMPTY,
	STR_ID_FMSR_FILE_EXIST,
	STR_ID_FMSR_END_TIME_INCORRECT,
	STR_ID_FMSR_START_TIME_INCORRECT,
	STR_ID_FMSR_TIME_OVERLAP,
	STR_ID_FMSR_SYSTEM_INTERRUPT,
	STR_ID_FMSR_USER_STOP,
	STR_ID_FMSR_USER_PAUSE,
	STR_ID_FMSR_USE_DEFAULT_FILE,
	STR_ID_FMSR_TIME_EXPIRE,
	STR_ID_FMSR_INVALID_FREQUENCY,
	STR_ID_FMSR_CANT_CREATE_FOLDER,
	STR_ID_FMSR_IN_USB_MODE,
	STR_ID_FMSR_RECORD_FINISH_1,
	STR_ID_FMSR_RECORD_FINISH_2,
	STR_ID_FMSR_RECORD_FINISH_3,
	STR_ID_FMSR_RECORD_FINISH_4,	
	NO_OF_STR_ID_FMSR
} fmsr_str_id_enum;

typedef enum 
{
	IMG_ID_FMSR_BASE = FM_SCHEDULE_REC_BASE+1,
	IMG_ID_FMSR_APP,
	IMG_ID_FMSR_BACKGROUND,
	NO_OF_IMG_ID_FMSR
} fmsr_img_id_enum;

typedef enum 
{
	SCR_ID_FMSR_BASE = FM_SCHEDULE_REC_BASE+1,
	SCR_ID_FMSR_MAIN_LIST,
	SCR_ID_FMSR_MAIN_SETTING,
	SCR_ID_FMSR_CHAN_SETTNIG,
	SCR_ID_FMSR_CHAN_LIST,
	SCR_ID_FMSR_CHAN_MANUAL,
	SCR_ID_FMSR_REC_SETTING,
	//SCR_ID_FMSR_REC_EDIT_NAME,
	//SCR_ID_FMSR_REC_EDIT_NAME_OPTIONS,
	SCR_ID_FMSR_RECORDING,
	SCR_ID_FMSR_SHOW_MESSAGE,
	NO_OF_SCR_ID_FMSR
} fmsr_scr_id_enum;

typedef enum
{
	FMSR_FORMAT_AMR,
	FMSR_FORMAT_WAV,
	FMSR_REC_FORMAT_NUM
}fmsr_record_format;

typedef enum
{
	FMSR_TYPE_NEW,
	FMSR_TYPE_APPEND,
	FMSR_REC_TYPE_NUM
}fmsr_record_type;

typedef enum
{
	FMSR_STORAGE_PHONE,
	FMSR_STORAGE_CARD,
	FMSR_REC_STORAGE_NUM
} fmsr_record_storage;

typedef enum {
	FMSR_STATE_IDLE,
	FMSR_STATE_READY, /*Power on*/
	FMSR_STATE_RECORD,
	FMSR_STATE_PAUSE,
	FMSR_STATE_TOTAL
} fmsr_rec_state_enum;

typedef enum
{
	FMSR_REPEAT_ONCE,
	FMSR_REPEAT_EVERYDAY,
	FMSR_REPEAT_DAYS,
	FMSR_REPEAT_WEEKLY,
	FMSR_REPEAT_MONTHLY,
	FMSR_REPEAT_NUM
}fmsr_repeat_type_enum;

/* 
** Extern Global Variable
*/

/* 
** Extern Global Function
*/

#endif /* #ifdef __MMI_FM_RADIO_SCHEDULE_REC__ */
#endif /* #ifndef _MMI_FMSRDEF_H */
