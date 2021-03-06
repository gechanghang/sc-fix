////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//            Copyright (C) 2003-2007, Coolsand Technologies, Inc.            //
//                            All Rights Reserved                             //
//                                                                            //
//      This source code is the property of Coolsand Technologies and is      //
//      confidential.  Any  modification, distribution,  reproduction or      //
//      exploitation  of  any content of this file is totally forbidden,      //
//      except  with the  written permission  of  Coolsand Technologies.      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  $HeadURL: http://10.10.100.14/svn/developing/modem2G/trunk/platform/edrv/memd/flsh_svme6432uta/src/drv_flsh.c $ //
//	$Author: ytt $                                                        // 
//	$Date: 2010-09-01 20:00:04 +0800                       //   
//	$Revision:  $                                                          //   
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
/// @file drv_flsh.c                                                          //
/// That file provides the driver implementation for the flsh_svme6432uta          //
/// flash.                                                                    //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include "cs_types.h"

#include "hal_ebc.h"
#include "hal_sys.h"

#include "string.h"

#include "memd_m.h"
#include "memdp_debug.h"
#include "memdp.h"
#include "hal_host.h"


/* banks at flash bit 20 */
/* for spansion 64k */
#define FLASHBANK_MASK      (0x3<<(23))     // Actually only need 1 bits, but have to use 2 due to shift
#define FLASH_ADDR_MASK 0x00ffffff

#define KBYTES 1024
#define MBYTES (1024*KBYTES)
#define HAL_TICK1S 16384

// -------------------------------
// FLASH/RAM configuration
// -------------------------------
#define FLASH_SIZE  8*MBYTES // 8MB
#define SECOND        * HAL_TICK1S
#define MILLI_SECOND  SECOND / 1000
#define MILLI_SECONDS MILLI_SECOND



// =============================================================================
//  GLOBAL VARIABLES
// =============================================================================
/// Base address
UINT32 g_memdFlashBaseAddress  = 0;


BOOL g_memdDybOverride = FALSE;

PRIVATE BOOL memd_DYBCheck(VOLATILE UINT16 *Addr, VOLATILE UINT16 *Ptr);





// =============================================================================
// memd_FlashOpen
// -----------------------------------------------------------------------------
/// That function configures the flash.
/// It must be called before using any other function of the MEMD API.
///
/// @param cfg Pointer to the configuration to use to open the flash.
/// This parameter is ignored by the romulator driver.
/// @return Pointer towards the structure describing the flash.
// =============================================================================
PUBLIC MEMD_FLASH_LAYOUT_T* memd_FlashOpen(CONST MEMD_FLASH_CONFIG_T* cfg)
{
    MEMD_ASSERT(cfg != NULL, "Opening flash with a NULL configuration");
//     hal_HstSendEvent(0x654321);
    // Open EBC ? (not needed with new hardware, as the only option
    // is enable ...

    // Open Flash, and store base address.
    g_memdFlashBaseAddress = (UINT32) hal_EbcFlashOpen(HAL_SYS_FREQ_39M,
                            &cfg->csConfig, NULL);

    return ((MEMD_FLASH_LAYOUT_T*) &g_memdFlashLayout);
}




// =============================================================================
// memd_RamOpen
// -----------------------------------------------------------------------------
/// That function configures the RAM.
/// It must be called to configure the best settings for the RAM, thus enabling
/// the fatest access.
/// @param cfg Ram configuration used to open the RAM.
///
// =============================================================================
PUBLIC VOID memd_RamOpen(CONST MEMD_RAM_CONFIG_T* cfg)
{
    MEMD_ASSERT(cfg != NULL, "Opening RAM with a NULL configuration");
//     hal_HstSendEvent(0x112233);

    // Open External SRAM
    hal_EbcCsOpen(HAL_EBC_SRAM, &cfg->csConfig);
}






//PRIVATE VOID memd_DYBOverride(BOOL Enable)
//{
//   g_memdDybOverride = Enable;
//}


PRIVATE UINT32 memd_FlashGetSectorLimits(UINT32 sectorId, UINT32 *start, UINT32 *end)
{
    UINT32 aStart, aEnd;
    int bankNum = 0;
    int majSecIdx, minSecIdx;
    UINT32 sectSize;

    if (sectorId == g_memdFlashLayout.fullSize)
    {
        *start = g_memdFlashLayout.fullSize;
        *end = g_memdFlashLayout.fullSize;
        return 0;
    }
    else if (sectorId > g_memdFlashLayout.fullSize)
    {
        *start = 0;
        *end = 0;
        MEMD_ASSERT(FALSE, "Out of accessible flash space !!!!");
        return 0;
    }
    else
    {
        while ( (sectorId >= g_memdFlashLayout.bankLayout[bankNum+1].bankStartAddr) &&
                (bankNum < (g_memdFlashLayout.numberOfBank-1)) )
        {
            ++bankNum;
        }
        aStart = g_memdFlashLayout.bankLayout[bankNum].bankStartAddr;

        majSecIdx = 0;
        aEnd = aStart +
            (g_memdFlashLayout.bankLayout[bankNum].sectorLayoutTable[majSecIdx][0] *
            g_memdFlashLayout.bankLayout[bankNum].sectorLayoutTable[majSecIdx][1]);
        while (sectorId >= aEnd)
        {
            if (majSecIdx == 2)
            {
                *start = 0;
                *end = 0;
                MEMD_ASSERT(FALSE, "Out of accessible flash space !!!!");
                return 0;
            } else
            {
                ++majSecIdx;
                aStart = aEnd;
                aEnd = aStart +
                    (g_memdFlashLayout.bankLayout[bankNum].sectorLayoutTable[majSecIdx][0] *
                    g_memdFlashLayout.bankLayout[bankNum].sectorLayoutTable[majSecIdx][1]);
            }
        }

        minSecIdx = 0;
        sectSize = g_memdFlashLayout.bankLayout[bankNum].sectorLayoutTable[majSecIdx][1];
        aEnd = aStart + sectSize;
        while (sectorId >= aEnd)
        {
            aStart = aEnd;
            aEnd = aStart + sectSize;
            ++minSecIdx;
        }

        *start = aStart;
        *end = aEnd;
        return sectSize;
    }
}

PRIVATE BOOL memd_DYBCheck(VOLATILE UINT16 *Addr, VOLATILE UINT16 *Ptr)
{
        return FALSE;
}

#if defined(USER_DATA_CACHE_SUPPORT) && !defined(_T_UPGRADE_PROGRAMMER)
PUBLIC MEMD_ERR_T memd_FlashErase_Continue(UINT8 *startFlashAddress, UINT8 *endFlashAddress,UINT32 time)
{
    UINT8 rdstatus, rdstatus_old;
    UINT32 status;
    VOLATILE UINT8 * ptr;
    VOLATILE UINT16 *flashaddr;
    UINT32 Start, End;
    UINT32 phys_end_add, phys_start_add;
    UINT32 suspend_time = 0,max_time = 0;
    max_time = time MILLI_SECONDS;
//    hal_HstSendEvent(0x5555);
    UINT32 now = hal_TimGetUpTime();
   
    phys_start_add = (UINT32)startFlashAddress;

  //  hal_HstSendEvent(phys_start_add);

    MEMD_ASSERT((phys_start_add & 0xe0000000) == 0, 
        "flash_address is expected to be a byte offset within the flash chip, not an absolute adresse");

    // Check that start & end addresses are aligned
    if (endFlashAddress == NULL)
    {
        memd_FlashGetSectorLimits(phys_start_add, &Start, &End);
        phys_end_add = End;
    } else
    {
        phys_end_add = (UINT32)endFlashAddress;
        MEMD_ASSERT((phys_end_add & 0xe0000000) == 0, 
            "flash_address is expected to be a byte offset within the flash chip, not an absolute adresse")
        if (phys_end_add != FLASH_SIZE)
        {
            memd_FlashGetSectorLimits(phys_end_add , &Start, &End);
            if (phys_end_add != Start)
            {
                return MEMD_ERR_ALIGN;
            }
        }
    }

    memd_FlashGetSectorLimits(phys_start_add, &Start, &End);
    if (phys_start_add != Start)
    {
        return MEMD_ERR_ALIGN;
    }

    hal_EbcFlashWriteEnable(TRUE);

    while (Start != phys_end_add)
    {
        flashaddr = (VOLATILE UINT16 *)(g_memdFlashBaseAddress + (Start&FLASHBANK_MASK));
        ptr = (VOLATILE UINT8 *)(g_memdFlashBaseAddress + (Start&~0xfff));

        if (!g_memdDybOverride)
        {
            if (memd_DYBCheck(flashaddr, (UINT16*)ptr))
            {
                hal_EbcFlashWriteEnable(FALSE);
                return MEMD_ERR_PROTECT;
            }
        }

        status = hal_SysEnterCriticalSection();
        // Sector Erase command

        *(ptr) = 0x30;
        hal_SysExitCriticalSection(status);

        // note the pooling could be done on data == 0xff also
    
        // pooling
        rdstatus = (*ptr);
        while(1){

                suspend_time = hal_TimGetUpTime();
                 if (suspend_time - now > max_time) 
                  {
                      status = hal_SysEnterCriticalSection();
                      *(ptr) = 0xb0;
                      hal_SysExitCriticalSection(status);
                      do
                      {
                         rdstatus_old = (*ptr);
                         rdstatus = (*ptr);
                         rdstatus_old &= 0xc0;
                         rdstatus &= 0xc0;
                        
                      }while (!(rdstatus_old == 0xC0 && rdstatus == 0xC0));	// Wait for suspend active
                      (*flashaddr) = 0xf0;
                                      hal_EbcFlashWriteEnable(FALSE);

                      return MEMD_ERR_SUSPEND;

                  }



          
            rdstatus_old = rdstatus;
            rdstatus = (*ptr);
            // DQ6 & DQ2 not toggling? => done
            if (((rdstatus ^ rdstatus_old) & 0x44) == 0)
            break;
            // DQ5 = 1
            if ((rdstatus & 0x20) == 0x20) {
                rdstatus_old = (*ptr);
                rdstatus = (*ptr);
                // DQ6 & DQ2 not toggling? => done
                if (((rdstatus ^ rdstatus_old) & 0x44) == 0)
                    break;
                // reset
                (*flashaddr) = 0xf0;
                hal_EbcFlashWriteEnable(FALSE);
                return MEMD_ERR_ERASE;
            }
        }
        if (End != FLASH_SIZE)
        {
            memd_FlashGetSectorLimits(End, &Start, &End);
        } else
        {
            Start = End;
        }
    }
    // erase done
    hal_EbcFlashWriteEnable(FALSE);
    return MEMD_ERR_NO;
}

PUBLIC MEMD_ERR_T memd_FlashErase_First(UINT8 *startFlashAddress, UINT8 *endFlashAddress,UINT32 time)
{
    UINT8 rdstatus, rdstatus_old;
    UINT32 status;
    VOLATILE UINT8 * ptr;
    VOLATILE UINT16 *flashaddr;
    UINT32 Start, End;
    UINT32 phys_end_add, phys_start_add;
    UINT32 suspend_time = 0,max_time = 0;
    max_time = time MILLI_SECONDS;
//    hal_HstSendEvent(0x5555);
    UINT32 now = hal_TimGetUpTime();
   
    phys_start_add = (UINT32)startFlashAddress;

  //  hal_HstSendEvent(phys_start_add);

    MEMD_ASSERT((phys_start_add & 0xe0000000) == 0, 
        "flash_address is expected to be a byte offset within the flash chip, not an absolute adresse");

    // Check that start & end addresses are aligned
    if (endFlashAddress == NULL)
    {
        memd_FlashGetSectorLimits(phys_start_add, &Start, &End);
        phys_end_add = End;
    } else
    {
        phys_end_add = (UINT32)endFlashAddress;
        MEMD_ASSERT((phys_end_add & 0xe0000000) == 0, 
            "flash_address is expected to be a byte offset within the flash chip, not an absolute adresse")
        if (phys_end_add != FLASH_SIZE)
        {
            memd_FlashGetSectorLimits(phys_end_add , &Start, &End);
            if (phys_end_add != Start)
            {
                return MEMD_ERR_ALIGN;
            }
        }
    }

    memd_FlashGetSectorLimits(phys_start_add, &Start, &End);
    if (phys_start_add != Start)
    {
        return MEMD_ERR_ALIGN;
    }

    hal_EbcFlashWriteEnable(TRUE);

    while (Start != phys_end_add)
    {
        flashaddr = (VOLATILE UINT16 *)(g_memdFlashBaseAddress + (Start&FLASHBANK_MASK));
        ptr = (VOLATILE UINT8 *)(g_memdFlashBaseAddress + (Start&~0xfff));

        if (!g_memdDybOverride)
        {
            if (memd_DYBCheck(flashaddr, (UINT16*)ptr))
            {
                hal_EbcFlashWriteEnable(FALSE);
                return MEMD_ERR_PROTECT;
            }
        }

        status = hal_SysEnterCriticalSection();
        // Sector Erase command
        *(flashaddr+0x555) = 0xaa;
        *(flashaddr+0x2aa) = 0x55;
        *(flashaddr+0x555) = 0x80;
        *(flashaddr+0x555) = 0xaa;
        *(flashaddr+0x2aa) = 0x55;
        *(ptr) = 0x30;
        hal_SysExitCriticalSection(status);

        // note the pooling could be done on data == 0xff also
    
        // pooling
        rdstatus = (*ptr);
        while(1){

                suspend_time = hal_TimGetUpTime();
                 if (suspend_time - now > max_time) 
                  {
                      status = hal_SysEnterCriticalSection();
                      *(ptr) = 0xb0;
                      hal_SysExitCriticalSection(status);
                      do
                      {
                         rdstatus_old = (*ptr);
                         rdstatus = (*ptr);
                         rdstatus_old &= 0xc0;
                         rdstatus &= 0xc0;
                        
                      }while (!(rdstatus_old == 0xC0 && rdstatus == 0xC0));	// Wait for suspend active
                      (*flashaddr) = 0xf0;
                                      hal_EbcFlashWriteEnable(FALSE);

                      return MEMD_ERR_SUSPEND;

                  }



          
            rdstatus_old = rdstatus;
            rdstatus = (*ptr);
            // DQ6 & DQ2 not toggling? => done
            if (((rdstatus ^ rdstatus_old) & 0x44) == 0)
            break;
            // DQ5 = 1
            if ((rdstatus & 0x20) == 0x20) {
                rdstatus_old = (*ptr);
                rdstatus = (*ptr);
                // DQ6 & DQ2 not toggling? => done
                if (((rdstatus ^ rdstatus_old) & 0x44) == 0)
                    break;
                // reset
                (*flashaddr) = 0xf0;
                return MEMD_ERR_ERASE;
            }
        }
        if (End != FLASH_SIZE)
        {
            memd_FlashGetSectorLimits(End, &Start, &End);
        } else
        {
            Start = End;
        }
    }
    // erase done
    hal_EbcFlashWriteEnable(FALSE);
    return MEMD_ERR_NO;
}
#endif
// =============================================================================
// memd_FlashErase
// -----------------------------------------------------------------------------
/// This function erases contiguous flash sectors. 
/// Addresses <B> must be aligned on sectors</B>:
/// - The \c startFlashAddress is the address of the first sector to erase.
/// - The \c endFlashAddress is the address of the first sector NOT to erase.
///   If \c endFlashAddress is \c NULL, only one sector will be erased.
/// .
/// Care must be taken not to erase the code present at the beginning of the flash.
///
/// @param start_flashAddress The address of the first sector to erase
/// @param end_flashAddress The address of the first sector NOT to erase.
///   If \c NULL, only one sector will be erased 
/// @return #MEMD_ERR_NO, #MEMD_ERR_ERASE, #MEMD_ERR_ALIGN or #MEMD_ERR_PROTECT
/// whether the operation succeeded or failed
///
// =============================================================================
PUBLIC MEMD_ERR_T memd_FlashErase(UINT8 *startFlashAddress, UINT8 *endFlashAddress)
{
    UINT8 rdstatus, rdstatus_old;
    UINT32 status;
    VOLATILE UINT8 * ptr;
    VOLATILE UINT16 *flashaddr;
    UINT32 Start, End;
    UINT32 phys_end_add, phys_start_add;

    phys_start_add = (UINT32)startFlashAddress;
    //   hal_HstSendEvent(0x123456);

  //  hal_HstSendEvent(phys_start_add);

    MEMD_ASSERT((phys_start_add & 0xe0000000) == 0, 
        "flash_address is expected to be a byte offset within the flash chip, not an absolute adresse");

    // Check that start & end addresses are aligned
    if (endFlashAddress == NULL)
    {
        memd_FlashGetSectorLimits(phys_start_add, &Start, &End);
        phys_end_add = End;
    } else
    {
        phys_end_add = (UINT32)endFlashAddress;
        MEMD_ASSERT((phys_end_add & 0xe0000000) == 0, 
            "flash_address is expected to be a byte offset within the flash chip, not an absolute adresse")
        if (phys_end_add != FLASH_SIZE)
        {
            memd_FlashGetSectorLimits(phys_end_add , &Start, &End);
            if (phys_end_add != Start)
            {
                return MEMD_ERR_ALIGN;
            }
        }
    }

    memd_FlashGetSectorLimits(phys_start_add, &Start, &End);
    if (phys_start_add != Start)
    {
        return MEMD_ERR_ALIGN;
    }

    hal_EbcFlashWriteEnable(TRUE);

    while (Start != phys_end_add)
    {
        flashaddr = (VOLATILE UINT16 *)(g_memdFlashBaseAddress + (Start&FLASHBANK_MASK));
        ptr = (VOLATILE UINT8 *)(g_memdFlashBaseAddress + (Start&~0xfff));

        if (!g_memdDybOverride)
        {
            if (memd_DYBCheck(flashaddr, (UINT16*)ptr))
            {
                hal_EbcFlashWriteEnable(FALSE);
                return MEMD_ERR_PROTECT;
            }
        }

        status = hal_SysEnterCriticalSection();
        // Sector Erase command
        *(flashaddr+0x555) = 0xaa;
        *(flashaddr+0x2aa) = 0x55;
        *(flashaddr+0x555) = 0x80;
        *(flashaddr+0x555) = 0xaa;
        *(flashaddr+0x2aa) = 0x55;
        *(ptr) = 0x30;
        hal_SysExitCriticalSection(status);

        // note the pooling could be done on data == 0xff also
    
        // pooling
        rdstatus = (*ptr);
        while(1){
            rdstatus_old = rdstatus;
            rdstatus = (*ptr);
            // DQ6 & DQ2 not toggling? => done
            if (((rdstatus ^ rdstatus_old) & 0x44) == 0)
            break;
            // DQ5 = 1
            if ((rdstatus & 0x20) == 0x20) {
                rdstatus_old = (*ptr);
                rdstatus = (*ptr);
                // DQ6 & DQ2 not toggling? => done
                if (((rdstatus ^ rdstatus_old) & 0x44) == 0)
                    break;
                // reset
                (*flashaddr) = 0xf0;
                hal_EbcFlashWriteEnable(FALSE);
                return MEMD_ERR_ERASE;
            }
        }
        if (End != FLASH_SIZE)
        {
            memd_FlashGetSectorLimits(End, &Start, &End);
        } else
        {
            Start = End;
        }
    }
    // erase done
    hal_EbcFlashWriteEnable(FALSE);
    return MEMD_ERR_NO;
}



// =============================================================================
// memd_FlashWrite
// -----------------------------------------------------------------------------
/// This function writes data in the flash. It gets its data from \c buffer, copies 
/// \c byteSize bytes to the flash location designed by \c flashAddress. \c 
/// pWrittenbyteSize is filled with the actual number of written bytes (Equal 
/// to size, or less in case of error).
/// 
/// @param  flashAddress The byte offset within the flash chip. (Take care not 
/// to overwrite the code present at the beginning of the flash)
/// @param  byteSize Number of bytes to write in flash
/// @param  pWrittenbyteSize Number of bytes actually written in flash
/// @param  buffer Buffer where to get the data to write in the flash
/// @return #MEMD_ERR_NO, #MEMD_ERR_WRITE or #MEMD_ERR_PROTECT
/// whether the operation succeeded or failed.
// =============================================================================
PUBLIC MEMD_ERR_T memd_FlashWrite(UINT8 *flashAddress,
        UINT32 byteSize, 
        UINT32 * pWrittenbyteSize, 
        CONST UINT8* buffer)
{
    VOLATILE UINT16 * flashaddr;
    VOLATILE UINT16 * ptr;
    UINT16 rdstatus, data;
    UINT32 bsize=0, wsize=0, owsize=0;
    MEMD_ERR_T errorcode=MEMD_ERR_NO;
    UINT32 status;
    UINT32 phys_add;


    *pWrittenbyteSize=0;
    if (byteSize==0)
    {
        return MEMD_ERR_NO;
    }

    hal_EbcFlashWriteEnable(TRUE);

    phys_add = (UINT32)flashAddress;
  //   hal_HstSendEvent(phys_add);

    MEMD_ASSERT((phys_add & 0xe0000000) == 0,
        "flash_address is expected to be a byte offset within the flash chip, not an absolute adresse")

    flashaddr = (VOLATILE UINT16 *)(g_memdFlashBaseAddress + (phys_add&FLASHBANK_MASK));

    if (!g_memdDybOverride)
    {
        ptr = (VOLATILE UINT16 *)(g_memdFlashBaseAddress + (phys_add&~0xfff));
        if (memd_DYBCheck(flashaddr, (UINT16*)ptr))
        {
            hal_EbcFlashWriteEnable(FALSE);
            return MEMD_ERR_PROTECT;
        }
    }

    ptr = (VOLATILE UINT16 *)(g_memdFlashBaseAddress + (phys_add&~1));

    // Unlock Bypass Entry
    status = hal_SysEnterCriticalSection();
    *(flashaddr+0x555) = 0xaa;
    *(flashaddr+0x2aa) = 0x55;
    *(flashaddr+0x555) = 0x20;
    hal_SysExitCriticalSection(status);

    if ((phys_add&1) == 1)
    {
        data = *(ptr);
    } else {
        data = (*buffer) | ~0x00ff;
        buffer ++;
        bsize ++;
    }
    if (bsize<byteSize)
    {
        data = data & (((*buffer) << 8) | 0x00ff);
        buffer ++;
        bsize ++;
    }

    if (bsize==byteSize)
    {
        // last byte
        data = data & *(ptr);
    }
    // first byte is prepared
    /* 16b data ready write it to flash*/
    status = hal_SysEnterCriticalSection();
    *(flashaddr) = 0xa0;
    *(ptr)=data;
    hal_SysExitCriticalSection(status);

    while(bsize<byteSize) {
        UINT16 tdata;
        VOLATILE UINT16 * tptr;

        // do the next data preparation before the pooling so we are ready to do a new programming just after pooling is OK.
        tdata = data;
        tptr = ptr;

        owsize = wsize;

        wsize = bsize;
        ptr+=1;


        if (bsize<byteSize) {
            data = (*buffer) | ~0x00ff;
            buffer ++;
            bsize ++;
        }
        if(bsize<byteSize) {
            data = data & (((*buffer) << 8) | 0x00ff);
            buffer ++;
            bsize ++;
        }

        // pooling
        while(1)
        {
            rdstatus = (*tptr);
            // DQ7 = prog value ? ok done
            if (((rdstatus ^ tdata) & 0x80) == 0)
                break;
            // DQ5 = 1
            if ((rdstatus & 0x20) == 0x20)
            {
                rdstatus = (*tptr);
                // DQ7 = prog value ? ok done
                if (((rdstatus ^ tdata) & 0x80) == 0)
                    break;
                errorcode=MEMD_ERR_WRITE;
                break;
            }
        }
        if (errorcode!=MEMD_ERR_NO) break;
        if(bsize==byteSize) {
            /* last byte */
            data = data & *(ptr);
        }
        /* 16b data ready write it to flash*/
        status = hal_SysEnterCriticalSection();
        *(flashaddr) = 0xa0;
        *(ptr)=data;
        hal_SysExitCriticalSection(status);
    }
    if (errorcode!=MEMD_ERR_NO)
    {
        wsize = owsize;
    } else
    {
        // last data pooling
        while(1)
        {
            rdstatus = (*ptr);
            // DQ7 = prog value ? ok done
            if (((rdstatus ^ data) & 0x80) == 0)
                break;
            // DQ5 = 1
            if ((rdstatus & 0x20) == 0x20)
            {
                rdstatus = (*ptr);
                // DQ7 = prog value ? ok done
                if (((rdstatus ^ data) & 0x80) == 0)
                    break;
                errorcode=MEMD_ERR_WRITE;
                break;
            }
        }
        wsize = bsize;
    }
    
    *pWrittenbyteSize = wsize;
    // Unlock Bypass Exit
    status = hal_SysEnterCriticalSection();
    *(flashaddr) = 0x90;
    *(flashaddr) = 0x00;
    hal_SysExitCriticalSection(status);

    hal_EbcFlashWriteEnable(FALSE);
    return errorcode;
}



// =============================================================================
// memd_FlashRead
// -----------------------------------------------------------------------------
/// This function reads data from the flash. It gets its data from \c flashAddress, 
/// copies \c byteSize bytes to \c buffer. \c pReadbyteSize is filled with the 
/// actual number of read bytes (Equal to \c byteSize, or less in case of error)
///
/// @param flashAddress The byte offset within the flash chip (Take care of 
/// the  positions of the code in the flash)
/// @param byteSize Number of bytes to read from the flash
/// @param pReadbyteSize Filled with the number of bytes actually read
/// @param buffer Buffer to fill with data from flash
/// @return #MEMD_ERR_NO
// =============================================================================
PUBLIC MEMD_ERR_T memd_FlashRead(UINT8 *flashAddress,
        UINT32  byteSize, 
        UINT32* pReadbyteSize,
        UINT8*  buffer)
{
    VOLATILE UINT8 * ptr;
    UINT32 phys_add;


    phys_add = (UINT32)flashAddress;
    MEMD_ASSERT((phys_add & 0xe0000000) == 0,
        "flash_address is expected to be a byte offset within the flash chip, not an absolute adresse")

    ptr = (VOLATILE UINT8 *)(g_memdFlashBaseAddress + phys_add);
    /* could do aligned read from flash to improve bus accesses as it is uncached */
    memcpy(buffer, (UINT8 *)ptr, byteSize);
    *pReadbyteSize=byteSize;
    return MEMD_ERR_NO;
}



// =============================================================================
// memd_FlashGetGlobalAddress
// -----------------------------------------------------------------------------
/// This function returns the global address in the system memory map 
/// from the flash relative address. 
/// Using the returned address, the user will be able to read directly 
/// from the flash, without using #memd_FlashRead
///
/// Note that the flash can be read directly, but it cannot be written without 
/// using the memd driver functions. That's why the returned address is declared 
/// as \c CONST. The content of the flash can be erased without the help of the 
/// CPU (by sending a command to the flash chip), that's why the returned 
/// address is declared as \c VOLATILE.
///
/// @param flashAddress Byte address within the flash chip to be converted 
/// into a global byte address (take care to the positions of the code in flash)
/// @return The byte global address
// =============================================================================
PUBLIC VOLATILE CONST UINT8* memd_FlashGetGlobalAddress(UINT8 *flashAddress)
{
    VOLATILE CONST UINT8* ptr;
    UINT32 phys_add;

    phys_add = (UINT32)flashAddress;
    MEMD_ASSERT((phys_add & 0xe0000000) == 0,
        "flash_address is expected to be a byte offset within the flash chip, not an absolute adresse");

    ptr = (VOLATILE CONST UINT8*)(g_memdFlashBaseAddress + phys_add);
    return ptr;
}



PRIVATE MEMD_ERR_T memd_DYB(UINT8 *startFlashAddress, UINT8 *endFlashAddress, BOOL Enable)
{
    VOLATILE UINT16 * flashaddr;
    VOLATILE UINT16 * ptr;
    UINT32 Start, End;

    if (endFlashAddress == NULL)
    {
        memd_FlashGetSectorLimits((UINT32)startFlashAddress , &Start, &End);
        endFlashAddress = (UINT8*)End;
    } else

    // Check that start & end addresses are aligned
    if ((UINT32)endFlashAddress != FLASH_SIZE) {
        memd_FlashGetSectorLimits((UINT32)endFlashAddress , &Start, &End);
        if ((UINT32)endFlashAddress != Start) {
            return MEMD_ERR_ALIGN;
        }
    }

    memd_FlashGetSectorLimits((UINT32)startFlashAddress , &Start, &End);
    if ((UINT32)startFlashAddress != Start)
        { return MEMD_ERR_ALIGN; }

    hal_EbcFlashWriteEnable(TRUE);

    flashaddr = (VOLATILE UINT16 *)(g_memdFlashBaseAddress + (Start&FLASHBANK_MASK));
    ptr = (VOLATILE UINT16 *)(g_memdFlashBaseAddress + (Start&~0xfff));
    while (Start != (UINT32)endFlashAddress)
    {
        *(flashaddr+0x555) = 0xaa;
        *(flashaddr+0x2aa) = 0x55;
        *(flashaddr+0x555) = 0x48;
        // DYB Set/Clr
        if (Enable)
            *(ptr) = 0x01;
        else
            *(ptr) = 0x00;

        if (End != FLASH_SIZE) {
            memd_FlashGetSectorLimits(End, &Start, &End);
        } else
        {
            Start = End;
        }
        flashaddr = (VOLATILE UINT16 *)(g_memdFlashBaseAddress + (Start&FLASHBANK_MASK));
        ptr = (VOLATILE UINT16 *)(g_memdFlashBaseAddress + (Start&~0xfff));
    }

    hal_EbcFlashWriteEnable(FALSE);

    return MEMD_ERR_NO;
}

PRIVATE UINT16 memd_DYBStatus(UINT8 * SectorAddr, UINT16 *DYB)
{

    *DYB = 0;


    return MEMD_ERR_NO;
}


// =============================================================================
// memd_FlashLock
// -----------------------------------------------------------------------------
/// This function protects the sectors between \c start_flashAddress and 
/// \c end_flashAddress.  Addresses must be sector aligned.  The sector 
/// specified by \c end_flashAddress is @b _NOT_ included in the 
/// protect procedure 
///
/// @param startFlashAddress Address of the first sector to protect
/// @param end_LashAddress Address of the first sector not to protect
/// @return #MEMD_ERR_NO or #MEMD_ERR_ALIGN
// =============================================================================
PUBLIC MEMD_ERR_T memd_FlashLock(
    UINT8 *startFlashAddress,
    UINT8 *endFlashAddress)
{
    MEMD_ASSERT((((UINT32)startFlashAddress) & 0xe0000000) == 0,
        "startFlashAddress is expected to be a byte offset within the flash chip, not an absolute address");
    MEMD_ASSERT((((UINT32)endFlashAddress) & 0xe0000000) == 0,
        "endFlashAddress is expected to be a byte offset within the flash chip, not an absolute address");
    return memd_DYB(startFlashAddress, endFlashAddress, TRUE);
}


// =============================================================================
// memd_FlashUnlock
// -----------------------------------------------------------------------------
/// This function unlocks the protection of the flash sectors between 
/// \c start_flashAddress and \c end_flashAddress.  Addresses must be 
/// sector aligned.  The sector specified by \c end_flashAddress is 
/// _NOT_ included in the unprotect procedure 
///
/// @param start_flashAddress Address of the first sector to unprotect
/// @param end_flashAddress Address of the first sector not to unprotect
/// @return #MEMD_ERR_NO or #MEMD_ERR_ALIGN
// ============================================================================
PUBLIC MEMD_ERR_T memd_FlashUnlock(
    UINT8 *startFlashAddress,
    UINT8 *endFlashAddress)
{
    MEMD_ASSERT((((UINT32)startFlashAddress) & 0xe0000000) == 0,
        "startFlashAddress is expected to be a byte offset within the flash chip, not an absolute address");
    MEMD_ASSERT((((UINT32)endFlashAddress) & 0xe0000000) == 0,
        "endFlashAddress is expected to be a byte offset within the flash chip, not an absolute address");
    return memd_DYB(startFlashAddress, endFlashAddress, FALSE);
}

// =============================================================================
// memd_FlashGetLockStatus
// -----------------------------------------------------------------------------
/// This function gets the protections status of the sector starting at 
/// \c start_flashAddress.  This addresses must be sector 
/// aligned.
///
/// @param startFlashAddress Address of the beginning of the sector to check.
/// @param lockStatus Pointer to the boolean value retaining the result of the
/// get: \c TRUE if the sector is protected, \c FALSE otherwise. The value is 
/// only valid if the return value is MEMD_ERR_NO;
/// @return #MEMD_ERR_NO or #MEMD_ERR_ALIGN
// =============================================================================
PUBLIC MEMD_ERR_T memd_FlashGetLockStatus(UINT8* startFlashAddress, BOOL* lockStatus)
{
    UINT16 Locked;
    MEMD_ASSERT((((UINT32)startFlashAddress) & 0xe0000000) == 0,
        "startFlashAddress is expected to be a byte offset within the flash chip, not an absolute address");
    MEMD_ERR_T status = memd_DYBStatus(startFlashAddress, &Locked);
    if (Locked == 0)
    {
        *lockStatus = FALSE;
    }
    else
    {
        /* FIX 'extra' Locked states */
        // Actually, there are 3 other states:
        // 0001 = Locked
        // 0002 = Unlocked and locked-down
        // 0003 = Locked and locked-down
        *lockStatus = TRUE;
    }
    return status;
}


// =============================================================================
// memd_FlashGetUserFieldInfo
// -----------------------------------------------------------------------------
/// That function get the user data info from memd.def.
///
/// @param userFieldBase The USER_DATA_BASE defined in memd.def.
/// @param userFieldSize The USER_DATA_SIZE defined in memd.def.
/// @param sectorSize The sector size of user data field, it is the large sector size.
///        Some small boot sectors can be regarded as one large sector.
/// @return VOID.
// =============================================================================
PUBLIC VOID memd_FlashGetUserFieldInfo(UINT32 *userFieldBase, UINT32 *userFieldSize, UINT32 *sectorSize, UINT32 *blockSize)
{
    UINT32 Start, End;
    
    *userFieldBase = g_memdFlashLayout.userDataBase;
    *userFieldSize = g_memdFlashLayout.userDataSize;
    *sectorSize = memd_FlashGetSectorLimits(*userFieldBase, &Start, &End);
    *blockSize = g_memdFlashLayout.userDataSectorLogicalBlockSize;
}

