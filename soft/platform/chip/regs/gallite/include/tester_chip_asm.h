#ifndef _TESTER_CHIP_ASM_H_
#define _TESTER_CHIP_ASM_H_

//THIS FILE HAS BEEN GENERATED WITH COOLWATCHER. PLEASE EDIT WITH CARE !

#ifndef CT_ASM
#error "You are trying to use in a normal C code the assembly H description of 'tester_chip'."
#endif



//==============================================================================
// tester_chip
//------------------------------------------------------------------------------
/// This module is not inside the gallite chip. It's connected to a Chip select of
/// EBC and placed in the testbench for simulation. It is also partially included
/// in the FPGA.
//==============================================================================
#define REG_TESTER_CHIP_BASE        0x01880000

#define REG_TESTER_CHIP_BASE_HI     BASE_HI(REG_TESTER_CHIP_BASE)
#define REG_TESTER_CHIP_BASE_LO     BASE_LO(REG_TESTER_CHIP_BASE)

#define REG_TESTER_CHIP_STOPPER     REG_TESTER_CHIP_BASE_LO + 0x00000000
#define REG_TESTER_CHIP_WATCH       REG_TESTER_CHIP_BASE_LO + 0x00000004
#define REG_TESTER_CHIP_W0          REG_TESTER_CHIP_BASE_LO + 0x00000008
#define REG_TESTER_CHIP_W1          REG_TESTER_CHIP_BASE_LO + 0x0000000C
#define REG_TESTER_CHIP_TEST_MODE   REG_TESTER_CHIP_BASE_LO + 0x00000010
#define REG_TESTER_CHIP_INPUT       REG_TESTER_CHIP_BASE_LO + 0x00000014
#define REG_TESTER_CHIP_TEST_MODE1  REG_TESTER_CHIP_BASE_LO + 0x00000018
#define REG_TESTER_CHIP_W2_SET      REG_TESTER_CHIP_BASE_LO + 0x00000020
#define REG_TESTER_CHIP_W2_CLR      REG_TESTER_CHIP_BASE_LO + 0x00000024
#define REG_TESTER_CHIP_KEY0        REG_TESTER_CHIP_BASE_LO + 0x00000028
#define REG_TESTER_CHIP_KEY1        REG_TESTER_CHIP_BASE_LO + 0x0000002C
#define REG_TESTER_CHIP_STR_PRINT   REG_TESTER_CHIP_BASE_LO + 0x00000030
#define REG_TESTER_CHIP_TESTPRINT_0 REG_TESTER_CHIP_BASE_LO + 0x00000034
#define REG_TESTER_CHIP_TESTPRINT_1 REG_TESTER_CHIP_BASE_LO + 0x00000036
#define REG_TESTER_CHIP_LED_CTRL    REG_TESTER_CHIP_BASE_LO + 0x00000040
#define REG_TESTER_CHIP_EXL_CTRL    REG_TESTER_CHIP_BASE_LO + 0x00000044
#define REG_TESTER_CHIP_EXL_TRIGGER_SET REG_TESTER_CHIP_BASE_LO + 0x00000048
#define REG_TESTER_CHIP_EXL_TRIGGER_CLR REG_TESTER_CHIP_BASE_LO + 0x0000004C
#define REG_TESTER_CHIP_LA_SET_0    REG_TESTER_CHIP_BASE_LO + 0x00000050
#define REG_TESTER_CHIP_LA_SET_1    REG_TESTER_CHIP_BASE_LO + 0x00000054
#define REG_TESTER_CHIP_LA_SET_2    REG_TESTER_CHIP_BASE_LO + 0x00000058
#define REG_TESTER_CHIP_LA_SET_3    REG_TESTER_CHIP_BASE_LO + 0x0000005C
#define REG_TESTER_CHIP_LA_CLR_0    REG_TESTER_CHIP_BASE_LO + 0x00000060
#define REG_TESTER_CHIP_LA_CLR_1    REG_TESTER_CHIP_BASE_LO + 0x00000064
#define REG_TESTER_CHIP_LA_CLR_2    REG_TESTER_CHIP_BASE_LO + 0x00000068
#define REG_TESTER_CHIP_LA_CLR_3    REG_TESTER_CHIP_BASE_LO + 0x0000006C
#define REG_TESTER_CHIP_PXTS        REG_TESTER_CHIP_BASE_LO + 0x00000070

//Stopper
#define TESTER_CHIP_STOP_CAUSE(n)   (((n)&0xFFFF)<<0)
#define TESTER_CHIP_STOP_CAUSE_SUCCESS (0x1<<0)
#define TESTER_CHIP_STOP_CAUSE_ERROR (0x2<<0)

//Watch
#define TESTER_CHIP_WATCH(n)        (((n)&0xFFFF)<<0)

//W0
#define TESTER_CHIP_W0(n)           (((n)&0xFFFFFFFF)<<0)

//W1
#define TESTER_CHIP_W1(n)           (((n)&0xFFFFFFFF)<<0)

//Test_Mode
#define TESTER_CHIP_CLK_SYSTEM_SEL_CLK_26M (0<<0)
#define TESTER_CHIP_CLK_SYSTEM_SEL_CLK_OUT (1<<0)
#define TESTER_CHIP_CLK_HST_DISABLE (1<<1)
#define TESTER_CHIP_RFSPI_AREO1     (1<<2)
#define TESTER_CHIP_RFSPI_AREO2     (1<<3)
#define TESTER_CHIP_SPI_LOOP0_EN    (1<<4)
#define TESTER_CHIP_SPI_SIMULATOR_SEL (1<<5)
#define TESTER_CHIP_DAI_MODE        (1<<6)
#define TESTER_CHIP_KEYON_VALUE     (1<<7)
#define TESTER_CHIP_UART_DIVIDER(n) (((n)&0xFF)<<8)
#define TESTER_CHIP_AUDIO_CLK_DIV2_DIS (1<<16)
#define TESTER_CHIP_UART_SEL(n)     (((n)&3)<<17)
#define TESTER_CHIP_GPIO_SEL        (1<<19)
#define TESTER_CHIP_GPO_SEL         (1<<20)
#define TESTER_CHIP_I2C_SEL         (1<<21)
#define TESTER_CHIP_DAI_I2S_MODE    (1<<22)
#define TESTER_CHIP_I2S_SIMULATOR_SEL (1<<23)
#define TESTER_CHIP_ANALOG_TEST_SEL (1<<24)
#define TESTER_CHIP_BOOT_MODE_TEST_SEL (1<<25)
#define TESTER_CHIP_DEBUG_PORT_SIMULATOR_SEL_DISABLE (0<<26)
#define TESTER_CHIP_DEBUG_PORT_SIMULATOR_SEL_ENABLE (1<<26)
#define TESTER_CHIP_DEBUG_CLOCK_CHECKER_SEL (1<<27)
#define TESTER_CHIP_USB_SIMULATOR_SEL(n) (((n)&3)<<28)
#define TESTER_CHIP_USB_EXTPHY_SEL  (1<<30)
#define TESTER_CHIP_ADMUX_MEMORIES  (1<<31)

//Input
#define TESTER_CHIP_INPUT(n)        (((n)&0xFFFFFFFF)<<0)

//Test_Mode1
#define TESTER_CHIP_CAMERA_SIMULATOR_DISABLE (0<<0)
#define TESTER_CHIP_CAMERA_SIMULATOR_ENABLE (1<<0)
#define TESTER_CHIP_SDMMC_SIMULATOR_DISABLE (0<<1)
#define TESTER_CHIP_SDMMC_SIMULATOR_ENABLE (1<<1)
#define TESTER_CHIP_DAC_BIST_SIMULATOR_DISABLE (0<<2)
#define TESTER_CHIP_DAC_BIST_SIMULATOR_ENABLE (1<<2)
#define TESTER_CHIP_SPI2_SIMULATOR_DISABLE (0<<3)
#define TESTER_CHIP_SPI2_SIMULATOR_ENABLE (1<<3)
#define TESTER_CHIP_PWM_CHECKER_DISABLE (0<<4)
#define TESTER_CHIP_PWM_CHECKER_ENABLE (1<<4)
#define TESTER_CHIP_DAI_SIMULATOR_DISABLE (0<<5)
#define TESTER_CHIP_DAI_SIMULATOR_ENABLE (1<<5)
#define TESTER_CHIP_I2S_SIMULATOR_DISABLE (0<<6)
#define TESTER_CHIP_I2S_SIMULATOR_ENABLE (1<<6)
#define TESTER_CHIP_DIGRF_SIMULATOR_DISABLE (0<<7)
#define TESTER_CHIP_DIGRF_SIMULATOR_ENABLE (1<<7)
#define TESTER_CHIP_SLCD_SIMULATOR_DISABLE (0<<8)
#define TESTER_CHIP_SLCD_SIMULATOR_ENABLE (1<<8)
#define TESTER_CHIP_PLCD_SIMULATOR_DISABLE (0<<9)
#define TESTER_CHIP_PLCD_SIMULATOR_ENABLE (1<<9)
#define TESTER_CHIP_SPI_SIMULATOR_DISABLE (0<<10)
#define TESTER_CHIP_SPI_SIMULATOR_ENABLE (1<<10)
#define TESTER_CHIP_SPI_SIMULATOR_MODE_LOOP_CS0 (0<<11)
#define TESTER_CHIP_SPI_SIMULATOR_MODE_LOOP_CS1 (1<<11)
#define TESTER_CHIP_SPI_SIMULATOR_MODE_LOOP_CS2 (2<<11)
#define TESTER_CHIP_SPI_SIMULATOR_MODE_DIO_D0 (3<<11)
#define TESTER_CHIP_SPI_SIMULATOR_MODE_DIO_D1 (4<<11)
#define TESTER_CHIP_TESTER_CHIP_CHIPSELECT_M_CS_3 (0<<14)
#define TESTER_CHIP_TESTER_CHIP_CHIPSELECT_M_CS_4 (1<<14)
#define TESTER_CHIP_GPIO_IN_DISABLE (0<<15)
#define TESTER_CHIP_GPIO_IN_ENABLE  (1<<15)
#define TESTER_CHIP_DRIVE_BOND_ID_DISABLE (0<<16)
#define TESTER_CHIP_DRIVE_BOND_ID_ENABLE (1<<16)
#define TESTER_CHIP_EXT_M_CS_0_DESTINATION_FLASH (1<<17)
#define TESTER_CHIP_EXT_M_CS_0_DESTINATION_ROM (0<<17)
#define TESTER_CHIP_REMAP_CHECKER_DISABLE (0<<18)
#define TESTER_CHIP_REMAP_CHECKER_ENABLE (1<<18)
#define TESTER_CHIP_CLOCK_CHECKER_SOURCE_CLK_DEBUG (0<<19)
#define TESTER_CHIP_CLOCK_CHECKER_SOURCE_CLK_OUT (1<<19)
#define TESTER_CHIP_CLOCK_CHECKER_SOURCE_CLK_OSC (2<<19)
#define TESTER_CHIP_DEBUG_PORT_SPY_SIMULATOR_SEL_DISABLE (0<<21)
#define TESTER_CHIP_DEBUG_PORT_SPY_SIMULATOR_SEL_ENABLE (1<<21)
#define TESTER_CHIP_I2C2_SEL_DISABLE (0<<22)
#define TESTER_CHIP_I2C2_SEL_ENABLE (1<<22)
#define TESTER_CHIP_I2C3_SEL_DISABLE (0<<23)
#define TESTER_CHIP_I2C3_SEL_ENABLE (1<<23)
#define TESTER_CHIP_SDAT3_SEL_DISABLE (0<<24)
#define TESTER_CHIP_SDAT3_SEL_ENABLE (1<<24)
#define TESTER_CHIP_SDAT3_VAL_VAL_0 (0<<25)
#define TESTER_CHIP_SDAT3_VAL_VAL_1 (1<<25)
#define TESTER_CHIP_RF_CLK_26M_DISABLE (0<<26)
#define TESTER_CHIP_RF_CLK_26M_ENABLE (1<<26)
#define TESTER_CHIP_KEYPAD_DISABLE  (0<<27)
#define TESTER_CHIP_KEYPAD_ENABLE   (1<<27)

//W2_set
#define TESTER_CHIP_W2_SET(n)       (((n)&0xFFFFFFFF)<<0)

//W2_clr
#define TESTER_CHIP_W2_CLR(n)       (((n)&0xFFFFFFFF)<<0)

//Key0
#define TESTER_CHIP_KEY0(n)         (((n)&0xFFFFFFFF)<<0)

//Key1
#define TESTER_CHIP_KEY1(n)         (((n)&0xFFFFFFFF)<<0)

//STR_Print
#define TESTER_CHIP_CHAR(n)         (((n)&0xFF)<<0)

//TestPrint
#define TESTER_CHIP_TEST_NUMBER(n)  (((n)&0x3F)<<0)
#define TESTER_CHIP_STATE(n)        (((n)&3)<<6)

//Led_Ctrl
#define TESTER_CHIP_LED_CTRL(n)     (((n)&0xFFFF)<<0)

//EXL_Ctrl
#define TESTER_CHIP_EXL_CTRL        (1<<0)

//EXL_Trigger_Set
#define TESTER_CHIP_EXL_TRIGGER_SET(n) (((n)&0xFFFF)<<0)

//EXL_Trigger_Clr
#define TESTER_CHIP_EXL_TRIGGER_CLR(n) (((n)&0xFFFF)<<0)

//LA_set
#define TESTER_CHIP_LA_SET(n)       (((n)&0xFFFFFFFF)<<0)

//LA_clr
#define TESTER_CHIP_LA_CLR(n)       (((n)&0xFFFFFFFF)<<0)

//PXTS
#define TESTER_CHIP_PXTS(n)         (((n)&0xFFFF)<<0)




#endif
