/* ======================================================================= */
/*                  TARGET CONFIGURATION SECTION                           */
/* ======================================================================= */
/* The following values are defined in ff_target.def and exported by the Makefile */
/*  FLASH_SIZE              */
/*  RAM_SIZE                */
/*  CALIB_BASE              */
/*  FACT_SETTINGS_BASE      */
/*  CODE_BASE               */
/*  USER_DATA_BASE          */
/*  USER_DATA_SIZE          */
/* ======================================================================= */
/*                  END CONFIGURATION SECTION                              */
/* ======================================================================= */
/* The linker script depends on the following defines */
/*  - CONST_IN_RAM : all constants are placed in RAM, this is useful for ram_run */
/*  - CODE_IN_RAM : All code is executed from RAM, this is useful for ram_run or code running from RAM on romulator */
/*  - PRELOADED_INT_SRAM : The internal SRAM are already preloaded, useful for ram_run */
/*  - PRELOADED_RAM : The external RAm is already preloaded, useful for ram_run or simu */

/* Those are constants of the system */


/* ROM content selection: things to include
    WARNING: the DISCARD section uses the opposite -->
    do all inclusion before discard !*/


/* Take into account assert bug in binutils-2.15*/
#if (USE_BINUTILS_2_19 == 1)
#define LD_ASSERT(condition, small, full)   ASSERT(condition, full)
#else
#define LD_ASSERT(condition, small, full)   ASSERT(condition, small)
#endif

/*Mandatory to have the BB side irq handler linked */
ENTRY (asicsimu_BootSector)
EXTERN (__bb_int_handler)
EXTERN (_sxr_Irq_handler)
EXTERN (boot_loader)
EXTERN (asicsimu_BootSector)
EXTERN (__flash_start)

SECTIONS
{

    /* ============================= */
    /* boot sector in flash          */
    /* ============================= */
    .boot_code FLASH_BASE :
    {
        _flash_start = .;
#ifdef ROMULATOR
        LONG(0xD9EF0045)  
#else /* ROMULATOR */
        LONG(0xFFFFFFFF)
#endif /* ROMULATOR */

#ifndef RAMRUN
        . = ALIGN(0x10);
        _boot_sector = .;
        *(.boot_sector_start)
        *boot_sector.o(.text)
        *boot_sector_chip.o(.text)
#endif /* RAMRUN */
        . = ALIGN(0x10);
    } 

    /* ============================== */
    /* calib sector in flash          */
    /* ============================== */
    .calib CALIB_BASE : AT(ADDR(.calib))
    {
        _calib_start = .;
        *(.calib);
        . = ALIGN(0x10);
    } 
    _calib_end = .;
    _calib_size = _calib_end - _calib_start;
  
    /* ============================== */
    /* factory settings in flash      */
    /* ============================== */
    .factory_settings FACT_SETTINGS_BASE : AT(ADDR(.factory_settings))
    {
        _factory_start = .;
        *(.factory_settings)
    } 
    _factory_end = .;
    _factory_size = _factory_end - _factory_start;

    /* ============================== */
    /* Main entry point after monitor */
    /* ============================== */
    .main_entry_section CODE_BASE: AT(ADDR(.main_entry_section))
    {
#ifndef RAMRUN
        _boot_loader_magic_number = .;
#ifdef ROMULATOR
        LONG(0x6700FA9B)
#else /* ROMULATOR */
        LONG(0xFFFFFFFF)
#endif /* ROMULATOR */
        . = ALIGN(0x10);
        _code_base = .;
        *boot_loader.o(.text.boot_loader_start)
        *boot_loader.o(.text .rdata .rodata)
#endif /* RAMRUN */

        _board_config_start = .;
        *(.board_config)
        . = ALIGN(0x10);
        _board_config_end = .;
#ifndef RAMRUN
        . = ALIGN(0x10);
#endif /* RAMRUN */
    } 
    _board_config_size = _board_config_end - _board_config_start;
/*  _bb_sram_flash_start_location = .;*/
/*    _int_rom_flash_start_location = .;*/
    _int_rom_tmp_flash_start_location = .;



    _int_rom_tmp_flash_end_location = _int_rom_tmp_flash_start_location ;
    _bb_sram_flash_start_location = _int_rom_tmp_flash_end_location;


/*  ---  */
    /* ================================================= */
    /* in BB SRAM                                        */
    /* ================================================= */
    /*------------------ */
    /* BB SRAM CACHED    */
    /*------------------ */
#ifndef PRELOADED_INT_SRAM
    .bbsram BB_SRAM_BASE : AT ( _bb_sram_flash_start_location ) 
#else
    .bbsram BB_SRAM_BASE :
#endif
    {
        _bb_sram_start = .;
        _bb_sram_cached_start = .;
        *(BB_ITLV_SECTION)     
        . = ALIGN(0x4);
        _bb_sram_romed_itlv_buf_end = .;
/*/     _bb_sram_itlv_buf_end = .;*/
        *(BB_SPC_CTX_SECTION)
        . = ALIGN(0x10);
    } 
    _bb_sram_romed_cached_end = .;
    _bb_sram_cached_end = .;
    _bb_sram_cached_size = _bb_sram_cached_end - _bb_sram_cached_start;

    /*------------------ */
    /* BB SRAM UNCACHED  */
    /*------------------ */
    /* go uncached */
    . = . + 0x20000000;
#ifndef PRELOADED_INT_SRAM
    .bbsramu . : AT (_bb_sram_flash_start_location + _bb_sram_cached_size)
#else
    .bbsramu . :
#endif
    {
        _bb_sram_uncached_start = .;
        _bb_sram_romed_uncached_start = .;
        . = ALIGN(0x10);
        _mbbsramu = .;
        *(BB_STATIC_SECTION)
        . = ALIGN(0x10);
    } 
    _bb_sram_uncached_end = .;
    _bb_sram_uncached_size = _bb_sram_uncached_end - _bb_sram_uncached_start;


    _bb_sram_size = _bb_sram_cached_size + _bb_sram_uncached_size;
    _bb_sram_romed_end = _bb_sram_start + _bb_sram_size;
    _bb_sram_end = _bb_sram_start + _bb_sram_size;

#ifndef PRELOADED_INT_SRAM
    _bb_sram_flash_end_location = _bb_sram_flash_start_location + _bb_sram_size;
#else
    _bb_sram_flash_end_location = _bb_sram_flash_start_location;
#endif

    .bbsram_globals BB_SRAM_BASE + BB_SRAM_SIZE - BB_SRAM_GLOBALS_SIZE: AT(ADDR(.bbsram_globals))
    {
        _bb_sram_romed_globals_start = .;
        _bb_sram_globals_start = .;
        *(BB_SRAM_GLOBALS)
	*(.bbsram_globals)
        _bb_sram_global_buf_end = .;
        _bb_sram_romed_globals_end = .;
    }

    /* ===================================================== */
    /* in SYS SRAM                                           */
    /* ===================================================== */
    _sys_sram_flash_start_location = _bb_sram_flash_end_location;

        /*----------------- */
        /* SYS SRAM UNCACHED  */
        /*----------------- */

    /* HAL Boot Sector structure, contains information written by
     * HAL during the normal execution of the code and used by the
     * Boot Sector when the phone boots.
     * It is mapped in the Internal SRAM because we don't want the Boot
     * Sector code to access the External RAM. And it is mapped at a fixed
     * location (at the place of the last patch for Greenstone) because we
     * don't want the RAMRUN to overwrite it.
     * This structure is "no load" as we don't want it to be loaded
     * by the Ramrun process.
     * For now, the size of the structure g_halBootSectorStruct is 4*4 bytes. */
    /* Use the last patch for the structure */
    .hal_boot_sector_struct (BOOT_SECTOR_STRUCT_BASE) (NOLOAD):
    {
        *(.hal_boot_sector_struct)
    }

    /* For ramruns, this section loads an execution context
     * content allowing to directly executed the 
     * boot sector (preloaded with PC=boot_Sector and SP=0,
     * cf boot_sector.c) */
     .executor_ctx ROM_MISC_UBASE: AT(ADDR(.executor_ctx))
     {
            *(.executor_ctx) 
     }

    /* Which is used by the ROM doesn't need to 
     * be copied anyhow from the flash ... */
    .rom_entries_cached ROM_MISC_BASE (NOLOAD):
    { 
        _hstMonitorXCtx_start = .;
        *boot_host.o(.sram_hst_monitor_ctx )
    }
 

        /*----------------- */
        /* SYS SRAM CACHED  */
        /*----------------- */
    
    /* Boot Sector structure pointer, used to retrieve the command
     * structure filled by HAL and used by the Boot Sector code.
     * This structure is "no load" as we don't want it to be loaded
     * by the Ramrun process. */
    .boot_sector_struct_ptr (SYS_SRAM_AVAILABLE_BASE-4-4) (NOLOAD):
    {
        *(.boot_sector_struct_ptr)
    }

    .fixptr (SYS_SRAM_AVAILABLE_BASE-4) : AT(ADDR(.fixptr))
    {
        *(.fixptr)
    }

#ifndef PRELOADED_INT_SRAM
    .sramtext (SYS_SRAM_AVAILABLE_BASE) : AT (_sys_sram_flash_start_location)
#else
    .sramtext (SYS_SRAM_AVAILABLE_BASE):
#endif
    {
    _sys_sram_start = .;
    _sys_sram_cached_start = .;
    _sys_sram_txt_start = .;
    /* Sys IRQ handler */
    _sys_sram_sys_irq_start = .;
    *hal_irq_handler.o(.irqtext)
    *hal_irq_handler.o(.text .sramtext)

#ifdef RAMRUN
    _boot_sector = .;
    *(.boot_sector_start)
    *boot_sector.o(.text)
    *boot_sector_chip.o(.text)
    
    _boot_loader_magic_number = .;
    LONG(0x6700FA9B)
    _code_base = .;
    *boot_loader.o(.text.boot_loader_start)
    *boot_loader.o(.text .rdata .rodata)
#endif /* RAMRUN */

    . = ALIGN(0x10);
    _sys_sram_sys_irq_txt_end = .;
    _sys_sram_sys_irq_txt_size = _sys_sram_sys_irq_txt_end - _sys_sram_sys_irq_start;

    }

    /* TODO Use a MACRO to define that address */
    /*Address of the BCPU INTSRAM interruption handler */
    .bbIrqSection 0xffffffff80c01200 : AT (_sys_sram_flash_start_location - ADDR(.sramtext) + ADDR(.bbIrqSection))
    {    
        _sys_sram_bb_irq_start = .;
    
    *spal_irq_handler.o(.irqtext .text .sramtext)

        . = ALIGN(0x10);
        _sys_sram_bb_irq_txt_end = .;
        _sys_sram_bb_irq_txt_size = _sys_sram_bb_irq_txt_end - _sys_sram_bb_irq_start;
    }

    .sramtextmisc . : AT (_sys_sram_flash_start_location - ADDR(.sramtext) + ADDR(.sramtextmisc ))
{
#if 0 // no need to place pal in internal ram and this will avoid copy (faster boot)
    *pal_gsmr.o(.text .text.* .gnu.linkonce.t.* .stub)
    *sxr_mem.o(.text .text.* .gnu.linkonce.t.* .stub)
    *sxr_jbsd.o(.text .text.* .gnu.linkonce.t.* .stub)

    *drv_xcv.o(.text .text.* .gnu.linkonce.t.* .stub)
    *drv_sw.o(.text .text.* .gnu.linkonce.t.* .stub)
    *drv_pa.o(.text .text.* .gnu.linkonce.t.* .stub)
    *drv_pasw.o(.text .text.* .gnu.linkonce.t.* .stub)
#endif
    *(.sramtext)

    /* ADDED Those one are in ROM usually but the ROM version is bypassed in that case */
    /* place the non rom version in internal RAM for speed */
    /**spc_*.o(.text .text.* .gnu.linkonce.t.* .stub)*/
    /**spp_*.o(.text .text.* .gnu.linkonce.t.* .stub)*/
    /**spal_*.o(.text .text.* .gnu.linkonce.t.* .stub)*/

    
    . = ALIGN(0x10);
    }
    _sys_sram_txt_end = .;
    _sys_sram_txt_size = _sys_sram_txt_end - _sys_sram_start;


#ifndef PRELOADED_INT_SRAM
    .sramdata _sys_sram_txt_end : AT (_sys_sram_flash_start_location + _sys_sram_txt_size )
#else
    .sramdata _sys_sram_txt_end :
#endif
    {
    _sys_sram_data_start = .;
    *(.sramdata)
    
#if 0 // no need to place pal in internal ram and this will avoid copy (faster boot)
    *pal_gsmr.o(.data .data.* .gnu.linkonce.d.* .data1)
    *pal_gsmr.o(.sdata .sdata.* .gnu.linkonce.s.*)
    *pal_gsmr.o(.sdata2 .sdata2.* .gnu.linkonce.s2.*)
#if 0
    *sxr_*.o(.data .data.* .gnu.linkonce.d.* .data1 .sdata .sdata.* .gnu.linkonce.s.* .sdata2 .sdata2.* .gnu.linkonce.s2.*)
    *l1s_*.o(.data .data.* .gnu.linkonce.d.* .data1 .sdata .sdata.* .gnu.linkonce.s.* .sdata2 .sdata2.* .gnu.linkonce.s2.*)
#endif

    *drv_xcv.o(.data .data.* .gnu.linkonce.d.* .data1 )
    *drv_xcv.o(.sdata .sdata.* .gnu.linkonce.s.*)
    *drv_xcv.o(.sdata2 .sdata2.* .gnu.linkonce.s2.*)
    *drv_sw.o(.data .data.* .gnu.linkonce.d.* .data1)
    *drv_sw.o(.sdata .sdata.* .gnu.linkonce.s.*)
    *drv_sw.o(.sdata2 .sdata2.* .gnu.linkonce.s2.*)
    *drv_pa.o(.data .data.* .gnu.linkonce.d.* .data1)
    *drv_pa.o(.sdata .sdata.* .gnu.linkonce.s.*)
    *drv_pa.o(.sdata2 .sdata2.* .gnu.linkonce.s2.*)
    *drv_pasw.o(.data .data.* .gnu.linkonce.d.* .data1)
    *drv_pasw.o(.sdata .sdata.* .gnu.linkonce.s.*)
    *drv_pasw.o(.sdata2 .sdata2.* .gnu.linkonce.s2.*)
#endif
    *(.srrodata)
    /* added*/
    *spc_*.o(.data .data.* .gnu.linkonce.d.* .data1)
    *spp_*.o(.data .data.* .gnu.linkonce.d.* .data1)
    *spal_*.o(.data .data.* .gnu.linkonce.d.* .data1)

    } 
    _sys_sram_data_end = .;
    _sys_sram_cached_end = .;
    _sys_sram_data_size = _sys_sram_data_end - _sys_sram_data_start;
    _sys_sram_cached_size = _sys_sram_cached_end - _sys_sram_cached_start;

    /*-------------------- */
    /* SYS SRAM UNCACHED   */
    /*-------------------- */
    /* go uncached */
    . = . + 0x20000000;
#ifndef PRELOADED_INT_SRAM
    .sramucdata . : AT ( _sys_sram_flash_start_location + _sys_sram_cached_size )
#else
    .sramucdata . :
#endif
    {
        _sys_sram_uncached_start = .;
        *(.sramucdata)
        *(.srroucdata)
        . = ALIGN(0x10);
    } 
    _sys_sram_uncached_end = .;
    _sys_sram_uncached_size = _sys_sram_uncached_end - _sys_sram_uncached_start;
  
    _sys_sram_size = _sys_sram_cached_size + _sys_sram_uncached_size;
    _sys_sram_end = _sys_sram_start + _sys_sram_size;

#ifndef PRELOADED_INT_SRAM
    _sys_sram_flash_end_location = _sys_sram_flash_start_location + _sys_sram_size;
#else
    _sys_sram_flash_end_location = _sys_sram_flash_start_location;
#endif

    /*----------------------- */
    /* SYS SRAM BSS (CACHED)  */
    /*----------------------- */
    /* go cached */
    . = . - 0x20000000;
  
    .srambss . : AT(ADDR(.srambss))
    {
        _sys_sram_bss_start = .;
        *(.srambss)
        . = ALIGN(0x10);
    } 
    _sys_sram_bss_end = .;
    _sys_sram_bss_size = _sys_sram_bss_end - _sys_sram_bss_start;

    /* Overlay in SYS SRAM*/
    _sys_sram_overlay_start = .;
    OVERLAY . : NOCROSSREFS AT (_sys_sram_flash_end_location)
    {
        #include "int_sram_overlay.ld"
    }

#if (USE_BINUTILS_2_19 == 1)
    _sys_sram_overlay_end           = .;
#else
    /* ld-2.15 End of overlay bug workaround (Manual calculation)*/
    _sys_sram_overlay_end           = _sys_sram_overlay_start + MAX_SIZE_OF_SYS_SRAM_OVERLAY;
    . = _sys_sram_overlay_end;
#endif
    _sys_sram_overlay_flash_size    = FLASH_SIZE_OF_SYS_SRAM_OVERLAY;
    _sys_sram_overlay_flash_end_location = _sys_sram_flash_end_location + _sys_sram_overlay_flash_size;



    /*----------------------- */
    /* SYS SRAM HEAP 1        */
    /*----------------------- */
    _sys_sram_top = SYS_SRAM_END; /* End of internal sram */
    _sys_sram_heap_start = _sys_sram_overlay_end;
    _sys_sram_heap_end = _sys_sram_top - (SYS_SRAM_IRQ_STACKWATCH_SIZE) - (XCPU_IRQ_STACK_SIZE);
    _sys_sram_heap_size = _sys_sram_heap_end - _sys_sram_heap_start;
    
    /* Check that the INT SRAM is not over stuffed */
    LD_ASSERT (_sys_sram_heap_size > 0, "INTS", "Internal SRAM overflow !")

    /*----------------------- */
    /* SYS SRAM IRQ STACK WATCH */
    /*----------------------- */
    _sys_sram_irq_stackwatch_size = (SYS_SRAM_IRQ_STACKWATCH_SIZE) - (PS_STACK_SIZE) ;
    _sys_sram_irq_stackwatch_start = _sys_sram_heap_end;
    _sys_sram_irq_stackwatch_end = _sys_sram_irq_stackwatch_start + _sys_sram_irq_stackwatch_size;

#if (PAGE_SPY_LOG == 1)    
    _sys_sram_sp_stack_start = _sys_sram_irq_stackwatch_end;
    _sys_sram_sp_stack_end = . + PS_STACK_SIZE - 4;
#endif

    /* Caution, _sys_sram_non_romed_top is used by the boot ROM code. */
    .sram_romed_top SYS_SRAM_BASE + SYS_SRAM_SIZE - RESERVED_MBX_SIZE - 4 :
    {
        _sys_sram_non_romed_top = .;
    }


    .mailbox SYS_SRAM_BASE + SYS_SRAM_SIZE - RESERVED_MBX_SIZE + 0x20000000 : AT(ADDR(.mailbox))
    {
        _sys_sram_romed_mbx_start = .;
        *spc_mailbox.o(.mailbox)
        . = ALIGN(0x10);
    } 


    /* Mailbox overflow */
    LD_ASSERT(SIZEOF(.mailbox) <= RESERVED_MBX_SIZE, "MBXO", "Mailbox Overflow !!")

    /*---------------- */
    /* End of SYS SRAM */
    /*---------------- */

#if (CHIP_HAS_PROXY_MEMORY == 1)
    /* ========================================== */
    /* Proxy Memory                               */
    /* ========================================== */
    /* Standard usage of proxy memory */
    /* Manual placing and copy from flash */
    _proxy_memory_flash_start_location = _sys_sram_overlay_flash_end_location;
#ifndef PRELOADED_PROXY_MEMORY
    .proxy_memory SYS_PROXY_MEM_BASE: AT (_proxy_memory_flash_start_location)
#else
    .proxy_memory SYS_PROXY_MEM_BASE: AT (ADDR(.proxy_memory))
#endif
    {
        _proxy_memory_start = .;
/* simu does not want to copy that */
#if 0
/* Loadable as a ramrun since the proxy memory is enabled
   by the romed monitor.*/ 
        *sxs_rlm.o(.text)
        *sxr_rlm.o(.text)
        *hal_timer.o(.text)
        *sxr_tksd.o(.text)
        *sxs_io.o(.text)
        *sxr_tls.o(.text)
        *sxs_tls.o(.text)
        *sxr_sbx.o(.text)
        *sxs_sbx.o(.text)
        *sxr_tim.o(.text)
        *hal_trace.o(.text)
#endif
        . = ALIGN(0x10);
    }

    _proxy_memory_end = . ;
    _proxy_memory_size = _proxy_memory_end - _proxy_memory_start ;

#ifndef PRELOADED_PROXY_MEMORY
    _proxy_memory_flash_end_location = _proxy_memory_flash_start_location + _proxy_memory_size;
#else
    _proxy_memory_flash_end_location = _proxy_memory_flash_start_location;
#endif

    /* Overlay in Proxy Memory*/
    _fast_cpu_memory_overlay_start = .;
    OVERLAY . : NOCROSSREFS AT (_proxy_memory_flash_end_location)
    {
        #include "fast_cpu_memory_overlay.ld"
    }

    /* ld-2.15 End of overlay bug workaround (Manual calculation)*/
    _fast_cpu_memory_overlay_end           = _fast_cpu_memory_overlay_start + MAX_SIZE_OF_FAST_CPU_MEMORY_OVERLAY;

    . = _fast_cpu_memory_overlay_end;
    
    _fast_cpu_memory_overlay_flash_size    = FLASH_SIZE_OF_FAST_CPU_MEMORY_OVERLAY;
    _fast_cpu_memory_overlay_flash_end_location = _proxy_memory_flash_end_location + _fast_cpu_memory_overlay_flash_size;

    _proxy_memory_top = SYS_PROXY_MEM_BASE + SYS_PROXY_MEM_SIZE - 4;
    _proxy_memory_overlay_top = _proxy_memory_top - XCPU_IRQ_STACK_SIZE;
    LD_ASSERT(ABSOLUTE(_fast_cpu_memory_overlay_end) < ABSOLUTE(_proxy_memory_overlay_top), "SPMO", "System Proxy Memory Overlfow !!!")


    /* ========================================== */
    /* End of Proxy Memory                        */
    /* ========================================== */   
#else  // CHIP_HAS_PROXY_MEMORY
    _fast_cpu_memory_overlay_flash_end_location = _sys_sram_overlay_flash_end_location;
#endif // CHIP_HAS_PROXY_MEMORY    
    

    /* ========================================== */
    /* in External RAM                            */
    /* ========================================== */
    _ram_flash_start_location = _fast_cpu_memory_overlay_flash_end_location;
    /* ------------------------------------------------ */
    /* Ext RAM CACHED  - SECTIONS ALWAYS IN RAM */
    /* ------------------------------------------------ */
#ifndef PRELOADED_RAM
    .ram EXT_RAM_BASE : AT (_ram_flash_start_location )
#else
    .ram EXT_RAM_BASE : AT (ADDR(.ram))
#endif
    {
        _ram_start = .;
        _ram_special_cached_start = .;
        _ram_txt_start = .;
        *(.ram)
    } 
    _ram_special_cached_end = .;
    _ram_special_cached_size = _ram_special_cached_end - _ram_special_cached_start;


    /*---------------------------- */
    /* Ext RAM CACHED TXT          */
    /*---------------------------- */
#ifndef PRELOADED_RAM
    .text  _ram_special_cached_end  : AT ( _ram_flash_start_location + _ram_special_cached_size )
#else
    .text  _ram_special_cached_end  : AT (ADDR(.text))
#endif /*PRELOADED_RAM*/
    {
        _ram_cached_txt_start = . ;
        /* The flash driver must always be in RAM
         * because we need to be able to execute its code
         * when writing any sectors (For examplen, the calibration
         * sector which is on the first bank. 
         * And so must be the functions called by the 
         * flash drivers. */
        *drv_flsh.o(.text .rotext .text.* .stub .gnu.linkonce.t.*)
        *hal_ebc.o(.text .rotext .text.* .stub .gnu.linkonce.t.*)
        *hal_flash.o(.text .rotext .text.* .stub .gnu.linkonce.t.*)
#ifdef CODE_IN_RAM
        *(.text .text.* .stub .gnu.linkonce.t.*)
        . = ALIGN(0x10);
#endif
    } =0
    _ram_cached_txt_end = . ;
    ram_cached_txt_size = _ram_cached_txt_end - _ram_cached_txt_start;

    _ram_txt_end = .;


    /*---------------------- */
    /* Ext RAM UNCACHED Data */
    /*---------------------- */
    /* Go Uncached */
    . += 0x20000000;

#ifndef PRELOADED_RAM
    .ucramdata  . : AT ( _ram_flash_start_location + _ram_special_cached_size + ram_cached_txt_size )
#else
    .ucramdata  . : AT (ADDR(.ucramdata))
#endif
    {
        _ram_uncached_data_start = .;
        *(.ucdata)
	
        . = ALIGN(0x10);
    } 
    _ram_uncached_data_end = .;
    _ram_uncached_data_size = _ram_uncached_data_end - _ram_uncached_data_start;

    /*---------------------- */
    /* Ext RAM CACHED Data */
    /*---------------------- */
    /* Go Cached */
    . -= 0x20000000;

#ifndef PRELOADED_RAM
    .data   . : AT ( _ram_flash_start_location + _ram_special_cached_size + ram_cached_txt_size + _ram_uncached_data_size )
#else
    .data   . : AT (ADDR(.data))
#endif
    {
        _ram_cached_data_start = . ;
#ifdef CONST_IN_RAM      
        *(.rdata)    
        *(.rodata .rodata.* .gnu.linkonce.r.*)       
        *(.rodata1)      
        . = ALIGN(0x10);
#endif


        /* The flash driver must always be in RAM
         * because we need to be able to execute its code
         * when writing any sectors (For examplen, the calibration
         * sector which is on the first bank. 
         * And so must be the functions called by the 
         * flash drivers. */
        *drv_flsh.o(.rdata .rodata .rodata.* .gnu.linkonce.r.* .data .data.* .gnu.linkonce.d.* )
        *drv_flsh_map.o(.rdata .rodata .rodata.* .gnu.linkonce.r.* .data .data.* .gnu.linkonce.d.* )
        *hal_ebc.o(.rdata .rodata .rodata.* .gnu.linkonce.r.* .data .data.* .gnu.linkonce.d.* )
        *hal_flash.o(.rdata .rodata .rodata.* .gnu.linkonce.r.* .data .data.* .gnu.linkonce.d.* )

		*hal_host.o(.data  )
        *boot_ram.o(.data)
        *hal_uart_monitor.o(.data  )
        *boot_rom.o(.data  ) 
        *xcpu_monitor.o(.data  )
        *boot_ram.o(.data  )
        *memcpy.o(.data  )
        *memset.o(.data  )
        *hal_uart_monitor.o(.data )

        _int_sram_romed_for_bcpu_start = .;

        *spp*.o(.data  COMMON)
        *spal_*.o(.data  COMMON)    
        *spc_*.o(.data  COMMON)
        *bcpu_*.o(.data  COMMON)

        _int_sram_romed_for_bcpu_end = .;

        *hal_critical_section.o(.data  COMMON .sramdata)

        

        *(.data .data.* .gnu.linkonce.d.*)
        *(.data1)
        _gp = ALIGN(16) + 0x7ff0;
        *(.sdata .sdata.* .gnu.linkonce.s.*)
        *(.sdata2 .sdata2.* .gnu.linkonce.s2.*)
        *(.lit8)
        *(.lit4)

        /* FIXME Catch there to prevent link error in case
         * those symbols appear in the final ELF. 
         * Nothing should be catched, as those symbols only 
         * make sense if coming from the ROM itself. */
        *(.usbFixptr)
        *(.usbmonitorFixptr)
        /* EOF FIXME */

        . = ALIGN(0x4);
        /***barrier : do not remove or edit */
        . = ALIGN(0x10);
    } 
    _ram_cached_data_end = . ;
    _ram_cached_data_size = _ram_cached_data_end - _ram_cached_data_start;
    _ram_end = .;
    _ram_size = _ram_end - _ram_start;

#ifndef PRELOADED_RAM
    _ram_flash_end_location =  _ram_flash_start_location + _ram_size;
#else
    _ram_flash_end_location = _ram_flash_start_location;
#endif

    /*-------------------------------------------------------  */
    /* Uninitialized section in RAM (content kept after reboot)*/
    /*-------------------------------------------------------  */
    .backup . : AT(ADDR(.backup))
    {
        *(.backup)
        . = ALIGN(0x10);
    } 

    /*-------------------------------------------------------  */
    /* RAM BSS (content reset to 0 )                           */
    /*-------------------------------------------------------  */
    .bss    . : AT(ADDR(.bss))
    {
        _ram_bss_start = .;
        /* The flash driver must always be in RAM
         * because we need to be able to execute its code
         * when writing any sectors (For examplen, the calibration
         * sector which is on the first bank. 
         * And so must be the functions called by the 
         * flash drivers.*/
        *drv_flsh.o(.bss .bss.* .gnu.linkonce.b.* COMMON)
        *drv_flsh_map.o(.bss .bss.* .gnu.linkonce.b.* COMMON)
        *hal_ebc.o(.bss .bss.* .gnu.linkonce.b.* COMMON)
        *hal_flash.o(.bss .bss.* .gnu.linkonce.b.* COMMON)

        *(.sbss .sbss.* .gnu.linkonce.sb.*)
        *(.sbss2 .sbss2.* .gnu.linkonce.sb2.*)
        *(.scommon)
        *(.dynbss)
        *(.bss .bss.* .gnu.linkonce.b.*)
        *(COMMON)
        . = ALIGN(0x10);
    } 
    _ram_bss_end = . ;
    _ram_bss_size = _ram_bss_end - _ram_bss_start;

    /*----------- */
    /* End of RAM */
    /*----------- */
    _ram_top = EXT_RAM_BASE + RAM_SIZE;
    _heap_size = _ram_top -_ram_bss_end;
    _heap_start =  _ram_bss_end;
    _heap_end =  _ram_bss_end + _heap_size;

    /* Check that the INT SRAM is not over stuffed */
    LD_ASSERT (_heap_size > 0, "EXTS", "External RAM overflow !")







    /*========================================================= */
    /* In FLASH                                                 */
    /*========================================================= */
    _rom_flash_start_location = _ram_flash_end_location;

    .rotext _rom_flash_start_location : AT(ADDR(.rotext))
    {
        #ifndef CODE_IN_RAM
            *(.text .text.* .stub .gnu.linkonce.t.*)
        #endif
        . = ALIGN(0x10);
    } 

    .rodata . : AT(ADDR(.rodata))
    {
        #ifndef CONST_IN_RAM     
            *(.rdata) 
            *(.rodata .rodata.* .gnu.linkonce.r.*) 
            *(.rodata1)
        #endif
        . = ALIGN(0x10);
    } 
    _flash_end = .;

    /* kept for compatibility */
    _etext = _ram_txt_end;
    _esramtext = _sys_sram_txt_end;
    _end = _ram_bss_end;


    




    /*=================================================== */
    /* Placeholder for misc hacks, not used for real apps */
    /*=================================================== */
    .misc . : AT(ADDR(.misc))
    {
        *(.misc)
    }


    /*================================================= */
    /* Define user data boundaries based on the defines */
    /*================================================= */
    _user_data_start = USER_DATA_BASE;
    _user_data_end = USER_DATA_BASE+USER_DATA_SIZE;
    _user_data_size = USER_DATA_SIZE;

   
    /*Check that the data and code in flash do not overwrite
     * the user data space */
    /* ASSERT seems to be boguous as of binutils-2.15 : we are
     * not allowed to used error messages longer than FLAS in that
     * particular case. Don't ask and port a newer version,
     * maybe. FIXME */
    checkFlashFreeSize = _user_data_start - _flash_end  ;
    LD_ASSERT(ABSOLUTE(checkFlashFreeSize) > 0, "FLAS", "Flash overflow: there is no more space available in flash memory.")
    
    /*"Flash content from linker overlaps User data")*/

    #include "discard.ld"

}

