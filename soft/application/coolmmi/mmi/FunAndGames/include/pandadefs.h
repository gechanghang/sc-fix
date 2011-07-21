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
 *	PandaDefs_128x160.h
  *
 * Project:
 * --------
 
 *
 * Description:
 * ------------
 *  Game id define Panda.
 *
 * Author:
 * -------
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
#ifndef _MMI_GX_PANDA_DEFS_H
#define _MMI_GX_PANDA_DEFS_H

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* String ID */
typedef enum {
#if defined(__MMI_GAME_PANDA_128x160__) || defined(__MMI_GAME_PANDA_128x128__) || defined(__MMI_GAME_PANDA_176x220__)
	STR_ID_GX_PANDA_GAME_NAME = GAME_PANDA_BASE + 1,
	STR_ID_GX_PANDA_HELP_DESCRIPTION,	
#elif defined(__MMI_GAME_MONKEY_128x160__) || defined(__MMI_GAME_MONKEY_128x128__) || defined(__MMI_GAME_MONKEY_176x220__)
	STR_ID_GX_PANDA_GAME_NAME_MONKEY = GAME_PANDA_BASE + 1,
	STR_ID_GX_PANDA_HELP_DESCRIPTION_MONKEY,	
#endif

	STR_ID_GX_PANDA_COUNT
} gx_panda_str_id_enum;


/* Image ID */
typedef enum {
	IMG_ID_GX_PANDA_GAME_ICON = GAME_PANDA_BASE + 1, 
	IMG_ID_GX_PANDA_DIGIT_0,
	IMG_ID_GX_PANDA_DIGIT_1,
	IMG_ID_GX_PANDA_DIGIT_2,
	IMG_ID_GX_PANDA_DIGIT_3,
	IMG_ID_GX_PANDA_DIGIT_4,
	IMG_ID_GX_PANDA_DIGIT_5,
	IMG_ID_GX_PANDA_DIGIT_6,
	IMG_ID_GX_PANDA_DIGIT_7,
	IMG_ID_GX_PANDA_DIGIT_8,
	IMG_ID_GX_PANDA_DIGIT_9,
	IMG_ID_GX_PANDA_BACKGROUND,
	IMG_ID_GX_PANDA_CLOCK,
	IMG_ID_GX_PANDA_SCORE,
	IMG_ID_GX_PANDA_ROLE_JUMP,
	IMG_ID_GX_PANDA_ROLE_FALL_FRAME_0,
	IMG_ID_GX_PANDA_ROLE_FALL_FRAME_1,
	IMG_ID_GX_PANDA_ROLE_LEFT_FRAME_0,
	IMG_ID_GX_PANDA_ROLE_LEFT_FRAME_1,
	IMG_ID_GX_PANDA_ROLE_RIGHT_FRAME_0,
	IMG_ID_GX_PANDA_ROLE_RIGHT_FRAME_1,
	IMG_ID_GX_PANDA_ROLE_ATTACK_L_FRAME_0,
	IMG_ID_GX_PANDA_ROLE_ATTACK_L_FRAME_1,
	IMG_ID_GX_PANDA_ROLE_ATTACK_R_FRAME_0,
	IMG_ID_GX_PANDA_ROLE_ATTACK_R_FRAME_1,
	IMG_ID_GX_PANDA_ENEMY_1_LEFT,
	IMG_ID_GX_PANDA_ENEMY_2_LEFT,
	IMG_ID_GX_PANDA_ENEMY_3_LEFT,
	IMG_ID_GX_PANDA_ENEMY_1_LEFT_FRAME_2,
	IMG_ID_GX_PANDA_ENEMY_2_LEFT_FRAME_2,
	IMG_ID_GX_PANDA_ENEMY_3_LEFT_FRAME_2,
	IMG_ID_GX_PANDA_ENEMY_1_RIGHT,
	IMG_ID_GX_PANDA_ENEMY_2_RIGHT,
	IMG_ID_GX_PANDA_ENEMY_3_RIGHT,
	IMG_ID_GX_PANDA_ENEMY_1_RIGHT_FRAME_2,
	IMG_ID_GX_PANDA_ENEMY_2_RIGHT_FRAME_2,
	IMG_ID_GX_PANDA_ENEMY_3_RIGHT_FRAME_2,
	IMG_ID_GX_PANDA_GOTEXT,
	IMG_ID_GX_PANDA_GRADESMAP,
	IMG_ID_GX_PANDA_GOPIC,

	IMG_ID_GX_PANDA_COUNT
} gx_panda_img_id_neum;

#endif	/* _MMI_GX_PANDA_DEFS_H */

