//==============================================================================
//                                                                              
//            Copyright (C) 2003-2007, Coolsand Technologies, Inc.              
//                            All Rights Reserved                               
//                                                                              
//      This source code is the property of Coolsand Technologies and is        
//      confidential.  Any  modification, distribution,  reproduction or        
//      exploitation  of  any content of this file is totally forbidden,        
//      except  with the  written permission  of  Coolsand Technologies.        
//                                                                              
//==============================================================================
//                                                                              
//    THIS FILE WAS GENERATED FROM ITS CORRESPONDING XML VERSION WITH COOLXML.  
//                                                                              
//                       !!! PLEASE DO NOT EDIT !!!                             
//                                                                              
//  $HeadURL: http://svn.coolsand-tech.com/svn/developing1/Sources/chip/branches/gallite441/regs/greenstone/include/globals.h $                                                                   
//    $Author: admin $                                                                    
//    $Date: 2010-07-07 20:28:03 +0800 (Wed, 07 Jul 2010) $                                                                      
//    $Revision: 269 $                                                                  
//                                                                              
//==============================================================================
//
/// @file
//
//==============================================================================

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#ifdef CT_ASM
#error "You are trying to use in an assembly code the normal H description of 'globals'."
#endif

#include "debug_host.h"
#include "sys_ctrl.h"


// =============================================================================
//  MACROS
// =============================================================================
/// AHB Address bus size
#define NB_BITS_ADDR                             (25)
/// Bigest Address space: 16 MB max
#define NB_BITS_MAXSPACE                         (24)
/// The System SRam size
#define SYS_SRAM_ADDR_WIDTH                      (13)
#define SYS_SRAM_SIZE                            (EXP2(SYS_SRAM_ADDR_WIDTH+2))
/// System Ahb Bus Configuration
#define SYS_NB_BITS_MASTER                       (3)

/// XHALT macro will send the event 0x4a17 to the debug host and
/// will stall the XCPU.  The XCPU can be released from Coolwatcher
/// by issuing a xrbp command.
#define XHALT { \
    asm("nop "); \
    asm("nop "); \
    asm("nop "); \
    asm("nop "); \
    while (hwp_debugHost->event != DEBUG_HOST_EVENT0_SEMA); \
    hwp_debugHost->event = 0x4a17; \
    hwp_sysCtrl->XCpu_Dbg_BKP |= SYS_CTRL_STALLED; \
    asm("nop "); \
    asm("nop "); \
    asm("nop "); \
    asm("nop "); \
}


typedef enum {
    SYS_MID_DUMMY                               = 0x00000000,
    SYS_MID_BIST                                = 0x00000001,
    SYS_MID_DMA                                 = 0x00000002,
    SYS_MID_XCPU                                = 0x00000003,
    SYS_MID_AHB2AHB                             = 0x00000004,
    SYS_MID_IFC                                 = 0x00000005,
    SYS_MID_USB                                 = 0x00000006
} SYS_MASTER_ID_T;

/// After this starts the Round Robib Pool
#define SYS_MID_RR_START                         (2)
#define SYS_MID_RR_END                           (7)
#define SYS_NB_STATIC_MASTER                     (SYS_MID_RR_START-1)
#define SYS_NB_MASTERS                           (SYS_MID_RR_END-1)
#define SYS_NB_BITS_SLAVE                        (3)

typedef enum {
    SYS_SID_DUMMY                               = 0x00000000,
    SYS_SID_MEM_BRIDGE                          = 0x00000001,
    SYS_SID_AHB2AHB                             = 0x00000002,
    SYS_SID_IFC                                 = 0x00000003,
    SYS_SID_USB                                 = 0x00000004
} SYS_SLAVE_ID_T;

#define SYS_SID_END                              (5)
#define SYS_NB_SLAVES                            (SYS_SID_END-1)
/// System Apb Bus Configuration
#define SYS_NB_BITS_PSEL                         (6)
#define SYS_NB_BITS_PADDR                        (12)
#define SYS_APB_STEP                             (EXP2(SYS_NB_BITS_PADDR))

typedef enum {
    SYS_ID_SYS_CTRL                             = 0x00000000,
    SYS_ID_IRQ                                  = 0x00000001,
    SYS_ID_TIMER                                = 0x00000002,
    SYS_ID_GPIO                                 = 0x00000003,
    SYS_ID_EBC                                  = 0x00000004,
    SYS_ID_KEYPAD                               = 0x00000005,
    SYS_ID_PWM                                  = 0x00000006,
    SYS_ID_I2C                                  = 0x00000007,
    SYS_ID_DMA                                  = 0x00000008,
    SYS_ID_IFC                                  = 0x00000009,
    SYS_ID_CALENDAR                             = 0x0000000A,
    SYS_ID_COMREGS                              = 0x0000000B,
    SYS_ID_PAGE_SPY                             = 0x0000000C,
    SYS_ID_DEBUG_PORT                           = 0x0000000D,
    SYS_ID_RF_SPI                               = 0x0000000E,
    SYS_ID_TCU                                  = 0x0000000F,
/// The following modules are linked to ifc dma req with 2 requests per module
    SYS_ID_SCI                                  = 0x00000010,
    SYS_ID_SPI                                  = 0x00000011,
    SYS_ID_SPI2                                 = 0x00000012,
    SYS_ID_DEBUG_UART                           = 0x00000013,
    SYS_ID_UART                                 = 0x00000014,
    SYS_ID_UART2                                = 0x00000015,
    SYS_ID_SDMMC                                = 0x00000016,
    SYS_ID_EXT_APB                              = 0x00000017,
    SYS_ID_LCDC                                 = 0x00000018,
    SYS_ID_CAMERA                               = 0x00000019,
    SYS_ID_XCPU_REG                             = 0x0000001A,
    SYS_ID_XCPU_TAG                             = 0x0000001B,
    SYS_ID_XCPU_IDATA                           = 0x0000001C,
    SYS_ID_XCPU_DDATA                           = 0x0000001D,
    SYS_ID_SYS_AHBC_MON                         = 0x0000001E,
    SYS_ID_BB_AHBC_MON                          = 0x0000001F,
    SYS_ID_BIST                                 = 0x00000020,
    SYS_ID_GPADC                                = 0x00000021,
    SYS_ID_PA_AFC                               = 0x00000022,
    SYS_ID_ANA_FE                               = 0x00000023
} SYS_MODULE_ID_T;

#define FIRST_SYS_ID_DATA                        (14)
#define LAST_SYS_ID_DATA                         (26)
/// The maximum number of slaves is currently 33 (excluding the HOST).
#define SYS_NB_PSEL                              (36)
/// The debug host is placed at last PSEL63 in the IFC
#define SYS_ID_DEBUG_HOST                        (EXP2(SYS_NB_BITS_PSEL)-1)

typedef enum {
    SYS_ID_TX_SCI                               = 0x00000000,
    SYS_ID_RX_SCI                               = 0x00000001,
    SYS_ID_TX_SPI                               = 0x00000002,
    SYS_ID_RX_SPI                               = 0x00000003,
    SYS_ID_TX_SPI2                              = 0x00000004,
    SYS_ID_RX_SPI2                              = 0x00000005,
    SYS_ID_TX_DEBUG_UART                        = 0x00000006,
    SYS_ID_RX_DEBUG_UART                        = 0x00000007,
    SYS_ID_TX_UART                              = 0x00000008,
    SYS_ID_RX_UART                              = 0x00000009,
    SYS_ID_TX_UART2                             = 0x0000000A,
    SYS_ID_RX_UART2                             = 0x0000000B,
    SYS_ID_TX_SDMMC                             = 0x0000000C,
    SYS_ID_RX_SDMMC                             = 0x0000000D,
    SYS_ID_TX_EXT_APB                           = 0x0000000E,
    SYS_ID_RX_EXT_APB                           = 0x0000000F,
    SYS_ID_TX_LCDC                              = 0x00000010,
    SYS_ID_RX_CAMERA                            = 0x00000013
} SYS_IFC_REQUEST_IDS_T;

#define SYS_NB_DMA_REQ                           (18)

typedef enum {
/// System IRQ IDs
/// Pulse IRQ
    SYS_IRQ_TCU0                                = 0x00000000,
    SYS_IRQ_TCU1                                = 0x00000001,
    SYS_IRQ_FRAME                               = 0x00000002,
    SYS_IRQ_DMA_TX_SDMMC                        = 0x00000003,
    SYS_IRQ_DMA_RX_SDMMC                        = 0x00000004,
    SYS_IRQ_DMA_TX_LCDC                         = 0x00000005,
    SYS_IRQ_DMA_RX_CAMERA                       = 0x00000006,
/// Level IRQ
    SYS_IRQ_COM0                                = 0x00000007,
    SYS_IRQ_COM1                                = 0x00000008,
    SYS_IRQ_VOC                                 = 0x00000009,
    SYS_IRQ_DMA                                 = 0x0000000A,
    SYS_IRQ_GPIO                                = 0x0000000B,
    SYS_IRQ_KEYPAD                              = 0x0000000C,
    SYS_IRQ_TIMERS                              = 0x0000000D,
    SYS_IRQ_OS_TIMER                            = 0x0000000E,
    SYS_IRQ_CALENDAR                            = 0x0000000F,
    SYS_IRQ_SPI                                 = 0x00000010,
    SYS_IRQ_SPI2                                = 0x00000011,
    SYS_IRQ_DEBUG_UART                          = 0x00000012,
    SYS_IRQ_UART                                = 0x00000013,
    SYS_IRQ_UART2                               = 0x00000014,
    SYS_IRQ_I2C                                 = 0x00000015,
    SYS_IRQ_SCI                                 = 0x00000016,
    SYS_IRQ_RF_SPI                              = 0x00000017,
    SYS_IRQ_LPS                                 = 0x00000018,
    SYS_IRQ_BBIFC0                              = 0x00000019,
    SYS_IRQ_BBIFC1                              = 0x0000001A,
    SYS_IRQ_USBC                                = 0x0000001B,
    SYS_IRQ_LCDC                                = 0x0000001C,
    SYS_IRQ_SDMMC                               = 0x0000001D,
    SYS_IRQ_CAMERA                              = 0x0000001E,
    SYS_IRQ_EXTAPB                              = 0x0000001F
} SYS_IRQ_ID_T;

/// Number of Pulse IRQ
#define SYS_NB_IRQ_PULSE                         (7)
/// Number of IRQ handled by the production driver
#define SYS_IRQ_QTY                              (32)
/// Number of IRQ
#define SYS_NB_IRQ                               (32)
/// Number of Level IRQ
#define SYS_NB_IRQ_LEVEL                         (SYS_NB_IRQ - SYS_NB_IRQ_PULSE)
/// The Baseband SRam size
#define BB_SRAM_ADDR_WIDTH                       (12)
#define BB_SRAM_SIZE                             (13*1024)
/// Baseband Ahb Bus Configuration
#define BB_NB_BITS_MASTER                        (3)

typedef enum {
    BB_MID_DUMMY                                = 0x00000000,
    BB_MID_BIST                                 = 0x00000001,
    BB_MID_VOC                                  = 0x00000002,
    BB_MID_BCPU                                 = 0x00000003,
    BB_MID_AHB2AHB                              = 0x00000004,
    BB_MID_IFC                                  = 0x00000005
} BB_MASTER_ID_T;

/// After this starts the Round Robib Pool
#define BB_MID_RR_START                          (2)
#define BB_MID_RR_END                            (6)
#define BB_NB_STATIC_MASTER                      (BB_MID_RR_START-1)
#define BB_NB_MASTERS                            (BB_MID_RR_END-1)
#define BB_MAX_BURST_SIZE                        (4)
#define BB_MAX_BURST_BITS                        (2)
#define BB_NB_BITS_SLAVE                         (3)

typedef enum {
    BB_SID_DUMMY                                = 0x00000000,
    BB_SID_MEM_BRIDGE                           = 0x00000001,
    BB_SID_AHB2AHB                              = 0x00000002,
    BB_SID_IFC                                  = 0x00000003,
    BB_SID_VOC                                  = 0x00000004,
    BB_SID_SRAM                                 = 0x00000005
} BB_SLAVE_ID_T;

#define BB_SID_END                               (6)
#define BB_NB_SLAVES                             (BB_SID_END-1)
/// BaseBand Apb Bus Configuration
#define BB_NB_BITS_PSEL                          (4)
#define BB_NB_BITS_PADDR                         (12)
#define BB_APB_STEP                              (EXP2(BB_NB_BITS_PADDR))

typedef enum {
    BB_ID_XCOR                                  = 0x00000000,
    BB_ID_IFC                                   = 0x00000001,
    BB_ID_IRQ                                   = 0x00000002,
    BB_ID_ITLV                                  = 0x00000003,
    BB_ID_VITERBI                               = 0x00000004,
    BB_ID_A5                                    = 0x00000005,
    BB_ID_RF                                    = 0x00000006,
    BB_ID_AIF                                   = 0x00000007,
    BB_ID_CP2                                   = 0x00000008,
    BB_ID_BIST                                  = 0x00000009,
    BB_ID_BCPU_REG                              = 0x0000000A,
    BB_ID_BCPU_TAG                              = 0x0000000B,
    BB_ID_BCPU_IDATA                            = 0x0000000C,
    BB_ID_BCPU_DDATA                            = 0x0000000D,
    BB_ID_COMREGS                               = 0x0000000E
} BB_MODULE_ID_T;

/// The maximum number of slaves is currently 32.
#define BB_NB_PSEL                               (15)

typedef enum {
/// Baseband IRQ IDs
/// Pulse IRQ
    BB_IRQ_TCU0                                 = 0x00000000,
    BB_IRQ_TCU1                                 = 0x00000001,
    BB_IRQ_FRAME                                = 0x00000002,
/// Level IRQ
    BB_IRQ_COM0                                 = 0x00000003,
    BB_IRQ_COM1                                 = 0x00000004,
    BB_IRQ_VOC                                  = 0x00000005,
    BB_IRQ_IFC0                                 = 0x00000006,
    BB_IRQ_IFC1                                 = 0x00000007,
    BB_IRQ_IFC2                                 = 0x00000008,
    BB_IRQ_RF_IF                                = 0x00000009,
    BB_IRQ_ITLV                                 = 0x0000000A,
    BB_IRQ_VITAC                                = 0x0000000B,
    BB_IRQ_XCOR                                 = 0x0000000C
} BB_IRQ_ID_T;

/// Number of Pulse IRQ
#define BB_NB_IRQ_PULSE                          (3)
/// Number of IRQ
#define BB_NB_IRQ                                (13)
/// Number of Level IRQ
#define BB_NB_IRQ_LEVEL                          (BB_NB_IRQ - BB_NB_IRQ_PULSE)
/// RF Input samples size (signed)
#define BB_SYMBOL_SIZE                           (13)
/// Vitac Multipliers size
#define VITAC_MULT_SIZE                          (14)

// =============================================================================
//  TYPES
// =============================================================================


#endif
