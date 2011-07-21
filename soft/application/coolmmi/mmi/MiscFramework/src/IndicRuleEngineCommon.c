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
 *    IndicRuleEngineCommon.c
 *
 * Project:
 * --------
 *   Indic Languages
 *
 * Description:
 * ------------
 *   header file of Indic language engine 
 *
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#include "hf_rules.h"
#include "bididef.h"

/****************************EXTERN DEFINITION*********************/
#if defined (__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__)

extern const ire_main_glyph_table_struct hfDvngTbl[]; 
extern const ire_character_info_table_struct hindi_character_info_table[]; 
extern const ire_character_info_table_struct hindi_ligature_info_table[]; 
#endif /* defined (__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) */ 

#if defined (__MMI_LANG_TAMIL__) 

extern const ire_main_glyph_table_struct TamilDvngTbl[]; 
extern const ire_character_info_table_struct tamil_character_info_table[]; 
extern const ire_character_info_table_struct tamil_ligature_info_table[]; 

#endif /* defined (__MMI_LANG_TAMIL__) */ 
#if defined (__MMI_LANG_BENGALI__) 

extern const ire_main_glyph_table_struct BengaliDvngTbl[]; 
extern const ire_character_info_table_struct bengali_character_info_table[]; 
extern const ire_character_info_table_struct bengali_ligature_info_table[]; 

#endif /* defined (__MMI_LANG_BENGALI__) */ 
#if defined (__MMI_LANG_PUNJABI__) 

extern const ire_main_glyph_table_struct PunjabiTbl[]; 
extern const ire_character_info_table_struct punjabi_character_info_table[]; 
extern const ire_character_info_table_struct punjabi_ligature_info_table[]; 

#endif /* defined (__MMI_LANG_PUNJABI__) */ 

#if defined (__MMI_LANG_GUJARATI__) 

extern const ire_main_glyph_table_struct GujaratiTbl[]; 
extern const ire_character_info_table_struct gujarati_character_info_table[]; 
extern const ire_character_info_table_struct gujarati_ligature_info_table[]; 

#endif

#if defined (__MMI_LANG_MALAYALAM__) 

extern const ire_main_glyph_table_struct MALAYALAMTbl[]; 
extern const ire_character_info_table_struct malayalam_character_info_table[]; 
extern const ire_character_info_table_struct malayalam_ligature_info_table[]; 

#endif
#if defined (__MMI_LANG_ORIYA__) 

extern const ire_main_glyph_table_struct OriyaTbl[]; 
extern const ire_character_info_table_struct oriya_character_info_table[]; 
extern const ire_character_info_table_struct oriya_ligature_info_table[]; 

#endif


#if defined (__MMI_LANG_TELUGU__) 

extern const ire_main_glyph_table_struct TELUGUTbl[]; 
extern const ire_character_info_table_struct telugu_character_info_table[]; 
extern const ire_character_info_table_struct telugu_ligature_info_table[]; 

#endif /* defined (__MMI_LANG_TELUGU__) */ 

#if defined (__MMI_LANG_KANNADA__) 

extern const ire_main_glyph_table_struct KANNADATbl[]; 
extern const ire_character_info_table_struct kannada_character_info_table[]; 
extern const ire_character_info_table_struct kannada_ligature_info_table[]; 

#endif /* defined (__MMI_LANG_KANNADA__) */ 

#if defined (__MMI_LANG_KHMER__) 

extern const ire_main_glyph_table_struct KhmerDvngTbl[]; 
extern const ire_character_info_table_struct khmer_character_info_table[]; 
extern const ire_character_info_table_struct khmer_ligature_info_table[]; 

#endif /* defined (__MMI_LANG_KHMER__) */ 

#if defined (__MMI_LANG_MYANMAR__) 
#include "myanmar.h"
extern const ire_main_glyph_table_struct MyanmarDvngTbl[]; 
extern const ire_character_info_table_struct myanmar_character_info_table[]; 
extern const ire_character_info_table_struct myanmar_ligature_info_table[]; 

#endif /* defined (__MMI_LANG_MYANMAR__) */ 


/**********************ARRAY'S DEFINITION*****************************************************/

const ire_indic_languages_table_struct indic_lang_char_info_table[] = 
{
	{0,0,0,0},																						/*Invalid*/

#if defined (__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__)
	{IRE_HINDI_LANG_START_RANGE, IRE_HINDI_LANG_END_RANGE, hindi_character_info_table, hfDvngTbl },	/*Hindi*/
#else
	{0,0,0,0},
#endif

#if defined (__MMI_LANG_BENGALI__)
	{IRE_BENGALI_LANG_START_RANGE, IRE_BENGALI_LANG_END_RANGE, bengali_character_info_table, BengaliDvngTbl },	/*Bengali*/
#else
	{0,0,0,0},
#endif
#if defined (__MMI_LANG_PUNJABI__)
	{IRE_PUNJABI_LANG_START_RANGE, IRE_PUNJABI_LANG_END_RANGE, punjabi_character_info_table, PunjabiTbl },	/*Punjabi*/
#else
	{0,0,0,0},
#endif
#if defined (__MMI_LANG_GUJARATI__)
	{IRE_GUJARATI_LANG_START_RANGE, IRE_GUJARATI_LANG_END_RANGE, gujarati_character_info_table, GujaratiTbl },	
#else
	{0,0,0,0},																						/*Gujrati*/
#endif
#if defined (__MMI_LANG_ORIYA__)
	{IRE_ORIYA_LANG_START_RANGE, IRE_ORIYA_LANG_END_RANGE, oriya_character_info_table, OriyaTbl },	
#else
	{0,0,0,0},																						/*Oriya*/
#endif
#if defined (__MMI_LANG_TAMIL__)
	{IRE_TAMIL_LANG_START_RANGE, IRE_TAMIL_LANG_END_RANGE, tamil_character_info_table, TamilDvngTbl },/*Tamil*/
#else
	{0,0,0,0},
#endif

#if defined (__MMI_LANG_TELUGU__)
	{IRE_TELUGU_LANG_START_RANGE, IRE_TELUGU_LANG_END_RANGE, telugu_character_info_table, TELUGUTbl }, /*Telugu*/
#else
	{0,0,0,0},
#endif	
#if defined (__MMI_LANG_KANNADA__)
	{IRE_KANNADA_LANG_START_RANGE, IRE_KANNADA_LANG_END_RANGE, kannada_character_info_table, KANNADATbl }, /*Kannada*/
#else
	{0,0,0,0},
#endif	
#if defined (__MMI_LANG_MALAYALAM__)
	{IRE_MALAYALAM_LANG_START_RANGE, IRE_MALAYALAM_LANG_END_RANGE, malayalam_character_info_table, MALAYALAMTbl }, /*Malayalam*/
#else
	{0,0,0,0},
#endif

#if defined (__MMI_LANG_KHMER__)
	{IRE_KHMER_LANG_START_RANGE, IRE_KHMER_LANG_END_RANGE, khmer_character_info_table, KhmerDvngTbl }, /*Khmer*/
#else
	{0,0,0,0},
#endif	
#if defined (__MMI_LANG_MYANMAR__)
	{IRE_MYANMAR_LANG_START_RANGE, IRE_MYANMAR_LANG_END_RANGE, myanmar_character_info_table, MyanmarDvngTbl }, /*Myanmar*/
#else
	{0,0,0,0},
#endif																						

};																							  

const ire_indic_languages_table_struct indic_lang_ligature_info_table[] = 
{
	
	{0,0,0,0},																									/*Invalid*/

#if defined (__MMI_LANG_HINDI__)|| defined(__MMI_LANG_MARATHI__)
	{IRE_HINDI_PROPRIETRY_START_RANGE, IRE_HINDI_PROPRIETRY_END_RANGE, hindi_ligature_info_table, hfDvngTbl },	/*Hindi*/
#else
	{0,0,0,0},
#endif

#if defined (__MMI_LANG_BENGALI__)
	{IRE_BENGALI_PROPRIETRY_START_RANGE, IRE_BENGALI_PROPRIETRY_END_RANGE, bengali_ligature_info_table, BengaliDvngTbl },	/*Bengali*/
#else
	{0,0,0,0},
#endif
#if defined (__MMI_LANG_PUNJABI__)
	{IRE_PUNJABI_PROPRIETRY_START_RANGE, IRE_PUNJABI_PROPRIETRY_END_RANGE, punjabi_ligature_info_table, PunjabiTbl },/*Tamil*/
#else
	{0,0,0,0},
#endif
#if defined (__MMI_LANG_GUJARATI__)
	{IRE_GUJARATI_PROPRIETRY_START_RANGE, IRE_GUJARATI_PROPRIETRY_END_RANGE, gujarati_ligature_info_table, GujaratiTbl },/*Gujarati*/
#else
	{0,0,0,0},
#endif
#if defined (__MMI_LANG_ORIYA__)
	{IRE_ORIYA_PROPRIETRY_START_RANGE, IRE_ORIYA_PROPRIETRY_END_RANGE, oriya_ligature_info_table, OriyaTbl },/*Oriya*/
#else
	{0,0,0,0},									/*Oriya*/
#endif
#if defined (__MMI_LANG_TAMIL__)
	{IRE_TAMIL_PROPRIETRY_START_RANGE, IRE_TAMIL_PROPRIETRY_END_RANGE, tamil_ligature_info_table, TamilDvngTbl },/*Tamil*/
#else
	{0,0,0,0},
#endif
#if defined (__MMI_LANG_TELUGU__)
	{IRE_TELUGU_PROPRIETRY_START_RANGE, IRE_TELUGU_PROPRIETRY_END_RANGE, telugu_ligature_info_table, TELUGUTbl },           /*Telugu*/
#else
	{0,0,0,0},
#endif
#if defined (__MMI_LANG_KANNADA__)
	{IRE_KANNADA_PROPRIETRY_START_RANGE, IRE_KANNADA_PROPRIETRY_END_RANGE, kannada_ligature_info_table, KANNADATbl },           /*Kannada*/
#else
	{0,0,0,0},
#endif			
#if defined (__MMI_LANG_MALAYALAM__)
	{IRE_MALAYALAM_PROPRIETRY_START_RANGE, IRE_MALAYALAM_PROPRIETRY_END_RANGE, malayalam_ligature_info_table, MALAYALAMTbl },             /*Malayalam*/
#else
	{0,0,0,0},
#endif
#if defined (__MMI_LANG_KHMER__)
	{IRE_KHMER_PROPRIETRY_START_RANGE, IRE_KHMER_PROPRIETRY_END_RANGE, khmer_ligature_info_table, KhmerDvngTbl },               /*Malayalam*/
#else
	{0,0,0,0},
#endif	
#if defined (__MMI_LANG_MYANMAR__)
	{IRE_MYANMAR_PROPRIETRY_START_RANGE, IRE_MYANMAR_PROPRIETRY_END_RANGE, myanmar_ligature_info_table, MyanmarDvngTbl }               /*Malayalam*/
#else
	{0,0,0,0}
#endif	
};


