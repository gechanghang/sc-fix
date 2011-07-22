// Here is where all the model specific defines should be


#include "hal_i2c.h"
#include "hal_camera.h"
#include "camera_m.h"

//#define  DRV_CAM_FRAME_6    1
 #define  DRV_CAM_FRAME_10    1
//#define  DRV_CAM_FRAME_12    1
typedef struct
{
    UINT8 Addr;            // Register Address
    UINT8 Data;             // Register Data
    UINT8 Wait;            // Time to wait after write
} CAM_REG_T;

typedef struct
{
    UINT16 Len;             // Size of array
    CAM_REG_T *RegVal;      // Array of registers
} CAM_REG_GROUP_T;

typedef enum
{
    CAM_MODE_IDLE,
    CAM_MODE_VIEWFINDER,
    CAM_MODE_PREP_IMG_CAPTURE,
    CAM_MODE_IMG_CAPTURE,
    CAM_MODE_PREP_VID_CAPTURE,
    CAM_MODE_VID_CAPTURE
} CAM_MODE_T;

// On FPGA platform, Pixel Clock must not be too fast or xfer screws up
#define CAM_CLK_CFG 0x81

const CAM_REG_T RG_InitPowerOnQvga[] = 
{   	
 {0x12,0x80,0x01},
 {0xff,0xff,0x01},
{0x15,0x02,0x01},  //0x02
{0x3a,0x04,0x01},
{0x09,0x01,0x01},
 {0x11,0x80,0x01},
{0x13,0x00,0x01},
 {0x01,0x15,0x01},
 {0x02,0x22,0x01},
 {0x87,0x18,0x01},
 {0x8c,0x01,0x01},  //02
 {0x8d,0xef,0x01},
 {0x13,0x07,0x01},
// DBLK manual  
 {0x28,0x03,0x01},
 {0x2c,0x03,0x01},  
 {0x00,0x20,0x01},
 {0x0d,0x20,0x01},
 {0x0e,0x20,0x01},
 {0x0f,0x20,0x01},
 {0x05,0x16,0x01},  
 {0x14,0x16,0x01},
 {0x06,0x19,0x01},  
 {0x08,0x19,0x01},
 {0x26,0x08,0x01},  
 {0x27,0x08,0x01},
 {0X1F,0xa0,0x01},
 {0X22,0xa0,0x01},
//DBLK auto  
 {0x28,0x00,0x01},
 {0x2c,0x00,0x01},
 {0x1e,0x00,0x01},  
 {0x3A,0x00,0x01},
 {0x2f,0x00,0x01},
 {0x16,0x00,0x01},
 {0x29,0x04,0x01},
 {0x21,0x00,0x01},
 {0x04,0xbb,0x01},
 {0x56,0x40,0x01},
//lens shading
 {0x35,0x60,0x01},
 {0x65,0x58,0x01},
 {0x66,0x58,0x01},
//global gain
 {0x82,0x16,0x01},
 {0x83,0x25,0x01},
 {0x84,0x20,0x01},// 1a
 {0x85,0x26,0x01},
 {0x86,0x32,0x01}, // 30

 {0x96,0x26,0x01},// AE speed
 {0x97,0x0c,0x01},
 {0x2b,0x00,0x01},
 {0x70,0x2f,0x01},
 {0x72,0x4f,0x01},
 {0x73,0x2f,0x01},
 {0x74,0x27,0x01}, 
 {0x75,0x0e,0x01},
 {0x69,0x00,0x01},
 {0x76,0xff,0x01},
 {0x80,0x55,0x01},// 65
 {0x89,0x01,0x01},// 2
 {0x8a,0xef,0x01},// f8
//black level
 {0x90,0x20,0x01},
 {0x91,0x1c,0x01},
 {0x39,0x80,0x01},  
 {0x3f,0xa8,0x01},
 {0x3b,0x60,0x01},
 {0x3c,0x10,0x01},

/*
//gamma //gamma 1 Ĭ��
 {0X40,0X20,0x01},
 {0X41,0X30,0x01},
 {0X42,0X28,0x01},
 {0X43,0X28,0x01},
 {0X44,0X1d,0x01},
 {0X45,0X15,0x01},
 {0X46,0X13,0x01},
 {0X47,0X10,0x01},
 {0X48,0X0E,0x01},
 {0X49,0X0B,0x01},
 {0X4b,0X0B,0x01},
 {0X4c,0X09,0x01},
 {0X4e,0X07,0x01},
 {0X4f,0X06,0x01},
 {0X50,0X05,0x01},
*/

/*  
  //gamma 2 ����
  {0X1f,0X20,0x01},
  {0X22,0X20,0x01},
  {0X3f,0X90,0x01},				 
  {0X40,0X25,0x01},
  {0X41,0X2a,0x01},
  {0X42,0X28,0x01},
  {0X43,0X28,0x01},
  {0X44,0X20,0x01},
  {0X45,0X1d,0x01},
  {0X46,0X17,0x01},
  {0X47,0X15,0x01},
  {0X48,0X0f,0x01},
  {0X49,0X0e,0x01},
  {0X4b,0X0a,0x01},
  {0X4c,0X06,0x01},
  {0X4e,0X05,0x01},
  {0X4f,0X04,0x01},
  {0X50,0X02,0x01},
*/

  //gamma 3 ����
  {0X1f,0X20,0x01},
  {0X22,0X20,0x01},
  {0X3f,0Xa8,0x01},					 
  {0X40,0X42,0x01},
  {0X41,0X3b,0x01},
  {0X42,0X32,0x01},
  {0X43,0X24,0x01},
  {0X44,0X1c,0x01},
  {0X45,0X15,0x01},
  {0X46,0X11,0x01},
  {0X47,0X0d,0x01},
  {0X48,0X0d,0x01},
  {0X49,0X0B,0x01},
  {0X4b,0X09,0x01},
  {0X4c,0X08,0x01},
  {0X4e,0X08,0x01},
  {0X4f,0X07,0x01},
  {0X50,0X06,0x01},

 /*
  //gamma 4	����
  {0X1f,0X20,0x01},
  {0X22,0X20,0x01},
  {0X3f,0Xa0,0x01},					 
  {0X40,0X32,0x01},
  {0X41,0X2c,0x01},
  {0X42,0X30,0x01},
  {0X43,0X1d,0x01},
  {0X44,0X1a,0x01},
  {0X45,0X14,0x01},
  {0X46,0X11,0x01},
  {0X47,0X0e,0x01},
  {0X48,0X0d,0x01},
  {0X49,0X0c,0x01},
  {0X4b,0X0B,0x01},
  {0X4c,0X09,0x01},
  {0X4e,0X09,0x01},
  {0X4f,0X08,0x01},
  {0X50,0X07,0x01},

   */
  
//color matrix
 {0x51,0x2e,0x01}, // 30
 {0x52,0x92,0x01},
 {0x53,0x04,0x01}, // 02
 {0x54,0x88,0x01}, // 86
 {0x57,0x30,0x01},
 {0x58,0x88,0x01}, // 8a
 {0x59,0x80,0x01},
 {0x5a,0x92,0x01},
 {0x5b,0x32,0x01},

 {0x5c,0x2e,0x01},
 {0x5d,0x17,0x01},
// new  AWB
 {0x6a,0x01,0x01},
 {0x23,0x66,0x01},
 {0xa0,0x9f,0x01},
 {0xa1,0x51,0x01},
 {0xa2,0x10,0x01},
 {0xa3,0x26,0x01},
 {0xa4,0x0b,0x01},
 {0xa5,0x26,0x01},
 {0xa6,0x06,0x01},
 {0xa7,0x98,0x01},
 {0xa8,0x80,0x01},
 {0xa9,0x3e,0x01},
 {0xaa,0x4b,0x01},
 {0xab,0x40,0x01},//3e
 {0xac,0x42,0x01},
 {0xad,0x43,0x01},
 {0xae,0x48,0x01},
 {0xaf,0x2b,0x01},
 {0xc5,0x32,0x01},
 {0xc6,0x34,0x01},
 {0xc7,0x39,0x01},
 {0xc8,0x2f,0x01},
 {0xc9,0x36,0x01},
 {0xca,0x3f,0x01},
 {0xcb,0x40,0x01},//41
 {0xcc,0x45,0x01},
 {0xcd,0x48,0x01},
 {0xce,0x44,0x01},
 {0xcf,0x4C,0x01},
 {0xd0,0x4B,0x01},
 {0xd1,0x59,0x01},// 55
// color saturation
 {0xb0,0xe4,0x01},
 {0xb1,0xc0,0x01},
 {0xb2,0xb0,0x01},
 {0xb3,0x86,0x01},
 
    //AE target
#if 0    
    {0x24,0x88,0x01},//0x8a
    {0x25,0x78,0x01},//0x7a
    {0x80,0x55,0x01},/* 50 Hz */	  
    {0x9d,0xa5,0x01},// MCLK=156M/6=26M
#else
    {0x24, 0x8a, 0x01},
    {0x25, 0x7a, 0x01},
    {0x80, 0x45, 0x01},
    {0x82, 0x02, 0x01},
    {0x86, 0x2c, 0x01},
    {0x87, 0x18, 0x01},
    {0x8b, 0x08, 0x01},
    {0x8c, 0x01, 0x01},
    {0x8d, 0xcb, 0x01},
#endif
    //Fix FR to 24FPS@26M MCLK
    //{0x92,0xb5,0x01},
 /*
    {0x2a,0x00,0x01},//dummy pixel 
    {0x2b,0x64,0x01},//dummy pixel 

    {0x92,0xc8,0x01},//dummy line 
    {0x93,0x00,0x01},//dummy line 
*/
    {0x92,0x00,0x01},
    {0x8e,0x02,0x01},
    {0x8f,0xb3,0x01},


    {0x12,0x10,0x01},//00
/*
//320*240��
{0x17,0x24,0x01},
{0x18,0x74,0x01},
{0x19,0x1e,0x01},
{0x1a,0x5a,0x01},
{0xf0,0x00,0x01},  	
*/
};

// use this for 640x480 {VGA) capture
PRIVATE const CAM_REG_T RG_InitPowerOnVga[] = 
{   
 {0x12,0x80,0x01},
 {0xff,0xff,0x01},
 {0x15,0x02,0x01},  //0x02
 {0x3a,0x04,0x01},
 {0x09,0x01,0x01},
 {0x11,0x80,0x01},
 {0x13,0x00,0x01},
 {0x01,0x15,0x01},
 {0x02,0x22,0x01},
 {0x87,0x18,0x01},
 {0x8c,0x01,0x01},  //02
 {0x8d,0xef,0x01},
 {0x13,0x07,0x01},

// DBLK manual  
 {0x28,0x03,0x01},
 {0x2c,0x03,0x01},  
 {0x00,0x20,0x01},
 {0x0d,0x20,0x01},
 {0x0e,0x20,0x01},
 {0x0f,0x20,0x01},
 {0x05,0x16,0x01},  
 {0x14,0x16,0x01},
 {0x06,0x19,0x01},  
 {0x08,0x19,0x01},
 {0x26,0x08,0x01},  
 {0x27,0x08,0x01},
 {0X1F,0xa0,0x01},
 {0X22,0xa0,0x01},

//DBLK auto  
 {0x28,0x00,0x01},
 {0x2c,0x00,0x01},
 {0x1e,0x00,0x01},  
 {0x3A,0x00,0x01},
 {0x2f,0x00,0x01},
 {0x16,0x00,0x01},
 {0x29,0x04,0x01},
 {0x21,0x00,0x01},
 {0x04,0xbb,0x01},
 {0x56,0x40,0x01},

//lens shading
 {0x35,0x60,0x01},
 {0x65,0x58,0x01},
 {0x66,0x58,0x01},

//global gain
 {0x82,0x16,0x01},
 {0x83,0x25,0x01},
 {0x84,0x20,0x01},// 1a
 {0x85,0x26,0x01},
 {0x86,0x32,0x01}, // 30

 {0x96,0x26,0x01},// AE speed
 {0x97,0x0c,0x01},
 {0x2b,0x00,0x01},
 {0x70,0x2f,0x01},
 {0x72,0x4f,0x01},
 {0x73,0x2f,0x01},
 {0x74,0x27,0x01}, 
 {0x75,0x0e,0x01},
 {0x69,0x00,0x01},
 {0x76,0xff,0x01},
 {0x80,0x55,0x01},// 65
 {0x89,0x01,0x01},// 2
 {0x8a,0xef,0x01},// f8

//black level
 {0x90,0x20,0x01},
 {0x91,0x1c,0x01},
 {0x39,0x80,0x01},  
 {0x3f,0xa8,0x01},
 {0x3b,0x60,0x01},
 {0x3c,0x10,0x01},

//gamma //gamma 1 Ĭ��
/*
 {0X40,0X20,0x01},
 {0X41,0X30,0x01},
 {0X42,0X28,0x01},
 {0X43,0X28,0x01},
 {0X44,0X1d,0x01},
 {0X45,0X15,0x01},
 {0X46,0X13,0x01},
 {0X47,0X10,0x01},
 {0X48,0X0E,0x01},
 {0X49,0X0B,0x01},
 {0X4b,0X0B,0x01},
 {0X4c,0X09,0x01},
 {0X4e,0X07,0x01},
 {0X4f,0X06,0x01},
 {0X50,0X05,0x01},
 */
/*
//gamma 2 ����
 {0X1f,0X20,0x01},
 {0X22,0X20,0x01},
 {0X3f,0X90,0x01},				 
 {0X40,0X25,0x01},
 {0X41,0X2a,0x01},
 {0X42,0X28,0x01},
 {0X43,0X28,0x01},
 {0X44,0X20,0x01},
 {0X45,0X1d,0x01},
 {0X46,0X17,0x01},
 {0X47,0X15,0x01},
 {0X48,0X0f,0x01},
 {0X49,0X0e,0x01},
 {0X4b,0X0a,0x01},
 {0X4c,0X06,0x01},
 {0X4e,0X05,0x01},
 {0X4f,0X04,0x01},
 {0X50,0X02,0x01},
*/

//gamma 3 ����
  {0X1f,0X20,0x01},
  {0X22,0X20,0x01},
  {0X3f,0Xa8,0x01},					 
  {0X40,0X42,0x01},
  {0X41,0X3b,0x01},
  {0X42,0X32,0x01},
  {0X43,0X24,0x01},
  {0X44,0X1c,0x01},
  {0X45,0X15,0x01},
  {0X46,0X11,0x01},
  {0X47,0X0d,0x01},
  {0X48,0X0d,0x01},
  {0X49,0X0B,0x01},
  {0X4b,0X09,0x01},
  {0X4c,0X08,0x01},
  {0X4e,0X08,0x01},
  {0X4f,0X07,0x01},
  {0X50,0X06,0x01},

/*
//gamma 4	����
  {0X1f,0X20,0x01},
  {0X22,0X20,0x01},
  {0X3f,0Xa0,0x01},					 
  {0X40,0X32,0x01},
  {0X41,0X2c,0x01},
  {0X42,0X30,0x01},
  {0X43,0X1d,0x01},
  {0X44,0X1a,0x01},
  {0X45,0X14,0x01},
  {0X46,0X11,0x01},
  {0X47,0X0e,0x01},
  {0X48,0X0d,0x01},
  {0X49,0X0c,0x01},
  {0X4b,0X0B,0x01},
  {0X4c,0X09,0x01},
  {0X4e,0X09,0x01},
  {0X4f,0X08,0x01},
  {0X50,0X07,0x01},
*/
  
//color matrix
 {0x51,0x2e,0x01}, // 30
 {0x52,0x92,0x01},
 {0x53,0x04,0x01}, // 02
 {0x54,0x88,0x01}, // 86
 {0x57,0x30,0x01},
 {0x58,0x88,0x01}, // 8a
 {0x59,0x80,0x01},
 {0x5a,0x92,0x01},
 {0x5b,0x32,0x01},

 {0x5c,0x2e,0x01},
 {0x5d,0x17,0x01},

// new  AWB
 {0x6a,0x01,0x01},
 {0x23,0x66,0x01},
 {0xa0,0x9f,0x01},
 {0xa1,0x51,0x01},
 {0xa2,0x10,0x01},
 {0xa3,0x26,0x01},
 {0xa4,0x0b,0x01},
 {0xa5,0x26,0x01},
 {0xa6,0x06,0x01},
 {0xa7,0x98,0x01},
 {0xa8,0x80,0x01},
 {0xa9,0x3e,0x01},
 {0xaa,0x4b,0x01},
 {0xab,0x40,0x01},//3e
 {0xac,0x42,0x01},
 {0xad,0x43,0x01},
 {0xae,0x48,0x01},
 {0xaf,0x2b,0x01},
 {0xc5,0x32,0x01},
 {0xc6,0x34,0x01},
 {0xc7,0x39,0x01},
 {0xc8,0x2f,0x01},
 {0xc9,0x36,0x01},
 {0xca,0x3f,0x01},
 {0xcb,0x40,0x01},//41
 {0xcc,0x45,0x01},
 {0xcd,0x48,0x01},
 {0xce,0x44,0x01},
 {0xcf,0x4C,0x01},
 {0xd0,0x4B,0x01},
 {0xd1,0x59,0x01},// 55

// color saturation
 {0xb0,0xe4,0x01},
 {0xb1,0xc0,0x01},
 {0xb2,0xb0,0x01},
 {0xb3,0x86,0x01},

//AE target
 {0x24,0x88,0x01},//0x8a
 {0x25,0x78,0x01},//0x7a
 /*
 {0x2a,0x00,0x01},//dummy pixel 
 {0x2b,0x64,0x01},//dummy pixel 

 {0x92,0xc8,0x01},//dummy line 
 {0x93,0x00,0x01},//dummy line 
*/
 {0x80,0x55,0x01},/* 50 Hz */	  
 {0x9d,0x8e,0x01},// MCLK=156M/7=22.2875M
 
//Fix FR to 20FPS@26M MCLK
/*
 {0x92,0xc8,0x01},
 {0x93,0x00,0x01},
*/
 {0x8e,0x02,0x01},
 {0x8f,0xc6,0x01},
 
 {0x12,0x00,0x01},

//640*480��
 {0x17,0x00,0x01},
 {0x18,0xa0,0x01},
 {0x19,0x00,0x01},
 {0x1a,0x78,0x01},
 {0xf0,0x00,0x01},
};
  
// use this for 160*120 {QQVGA) capture
const CAM_REG_T RG_InitPowerOnQqvga[] = 
#if 0
{   
    {0x12,0x80,0x01},
    {0xff,0xff,0x01},	
    {0x15,0x02,0x01},  
    {0x3a,0x04,0x01},
    {0x12,0x10,0x01},//00
    {0x09,0x01,0x01},
    {0x11,0x80,0x01},
    {0x13,0x00,0x01},
    {0x01,0x15,0x01},
    {0x02,0x22,0x01},
    {0x87,0x18,0x01},
    {0x8c,0x01,0x01},  //02
    {0x8d,0x7c,0x01},
    {0x13,0x07,0x01},

// DBLK manual  
    {0x28,0x03,0x01},
    {0x2c,0x03,0x01},  
    {0x00,0x20,0x01},
    {0x0d,0x20,0x01},
    {0x0e,0x20,0x01},
    {0x0f,0x20,0x01},
    {0x05,0x16,0x01},  
    {0x14,0x16,0x01},
    {0x06,0x19,0x01},  
    {0x08,0x19,0x01},
    {0x26,0x08,0x01},  
    {0x27,0x08,0x01},
    {0X1F,0xa0,0x01},
    {0X22,0xa0,0x01},

//DBLK auto  
    {0x28,0x00,0x01},
    {0x2c,0x00,0x01},
    {0x1e,0x00,0x01},  
    {0x3A,0x00,0x01},
    {0x2f,0x00,0x01},
    {0x16,0x00,0x01},
    {0x29,0x04,0x01},
    {0x21,0x00,0x01},
    {0x04,0xbb,0x01},
    {0x56,0x40,0x01},

//lens shading
    {0x35,0x60,0x01},
    {0x65,0x58,0x01},
    {0x66,0x58,0x01},

//global gain
    {0x82,0x16,0x01},
    {0x83,0x25,0x01},
    {0x84,0x1a,0x01},
    {0x85,0x26,0x01},
    {0x86,0x30,0x01},

    {0x96,0x26,0x01},// AE speed
    {0x97,0x0c,0x01},
    {0x2b,0x06,0x01},
    {0x70,0x2f,0x01},
    {0x72,0x4f,0x01},
    {0x73,0x2f,0x01},
    {0x74,0x27,0x01},
    {0x75,0x0e,0x01},
    {0x69,0x80,0x01},
    {0x76,0xff,0x01},
    {0x80,0x55,0x01},// 65
    {0x89,0x02,0x01},
    {0x8a,0xf8,0x01},

//black level
    {0x90,0x20,0x01},
    {0x91,0x1c,0x01},
    {0x39,0x80,0x01},  
    {0x3f,0x90,0x01},
    {0x3b,0x60,0x01},
    {0x3c,0x10,0x01},

//gamma //gamma 1 Ĭ��
/*
    {0X40,0X20,0x01},
    {0X41,0X30,0x01},
    {0X42,0X28,0x01},
    {0X43,0X28,0x01},
    {0X44,0X1d,0x01},
    {0X45,0X15,0x01},
    {0X46,0X13,0x01},
    {0X47,0X10,0x01},
    {0X48,0X0E,0x01},
    {0X49,0X0B,0x01},
    {0X4b,0X0B,0x01},
    {0X4c,0X09,0x01},
    {0X4e,0X07,0x01},
    {0X4f,0X06,0x01},
    {0X50,0X05,0x01},
*/

//gamma 2 ����
    {0X1f,0X20,0x01},
    {0X22,0X20,0x01},
    {0X3f,0X90,0x01},				 
    {0X40,0X25,0x01},
    {0X41,0X2a,0x01},
    {0X42,0X28,0x01},
    {0X43,0X28,0x01},
    {0X44,0X20,0x01},
    {0X45,0X1d,0x01},
    {0X46,0X17,0x01},
    {0X47,0X15,0x01},
    {0X48,0X0f,0x01},
    {0X49,0X0e,0x01},
    {0X4b,0X0a,0x01},
    {0X4c,0X06,0x01},
    {0X4e,0X05,0x01},
    {0X4f,0X04,0x01},
    {0X50,0X02,0x01},

/*
//gamma 3 ����
    {0X1f,0X20,0x01},
    {0X22,0X20,0x01},
    {0X3f,0Xa0,0x01},					 
    {0X40,0X42,0x01},
    {0X41,0X3b,0x01},
    {0X42,0X32,0x01},
    {0X43,0X24,0x01},
    {0X44,0X1c,0x01},
    {0X45,0X15,0x01},
    {0X46,0X11,0x01},
    {0X47,0X0d,0x01},
    {0X48,0X0d,0x01},
    {0X49,0X0B,0x01},
    {0X4b,0X09,0x01},
    {0X4c,0X08,0x01},
    {0X4e,0X08,0x01},
    {0X4f,0X07,0x01},
    {0X50,0X06,0x01},
*/

//gamma 4	����
/*
    {0X1f,0X20,0x01},
    {0X22,0X20,0x01},
    {0X3f,0Xa0,0x01},					 
    {0X40,0X32,0x01},
    {0X41,0X2c,0x01},
    {0X42,0X30,0x01},
    {0X43,0X1d,0x01},
    {0X44,0X1a,0x01},
    {0X45,0X14,0x01},
    {0X46,0X11,0x01},
    {0X47,0X0e,0x01},
    {0X48,0X0d,0x01},
    {0X49,0X0c,0x01},
    {0X4b,0X0B,0x01},
    {0X4c,0X09,0x01},
    {0X4e,0X09,0x01},
    {0X4f,0X08,0x01},
    {0X50,0X07,0x01},
*/

//color matrix
    {0x51,0x2e,0x01}, // 30
    {0x52,0x92,0x01},
    {0x53,0x04,0x01}, // 02
    {0x54,0x88,0x01}, // 86
    {0x57,0x30,0x01},
    {0x58,0x88,0x01}, // 8a
    {0x59,0x80,0x01},
    {0x5a,0x92,0x01},
    {0x5b,0x32,0x01},

    {0x5c,0x2e,0x01},
    {0x5d,0x17,0x01},

// new  AWB
    {0x6a,0x01,0x01},
    {0x23,0x66,0x01},
    {0xa0,0x9f,0x01},
    {0xa1,0x51,0x01},
    {0xa2,0x10,0x01},
    {0xa3,0x26,0x01},
    {0xa4,0x0b,0x01},
    {0xa5,0x26,0x01},
    {0xa6,0x06,0x01},
    {0xa7,0x98,0x01},
    {0xa8,0x80,0x01},
    {0xa9,0x3e,0x01},
    {0xaa,0x4b,0x01},
    {0xab,0x3e,0x01},
    {0xac,0x42,0x01},
    {0xad,0x43,0x01},
    {0xae,0x48,0x01},
    {0xaf,0x2b,0x01},
    {0xc5,0x32,0x01},
    {0xc6,0x34,0x01},
    {0xc7,0x39,0x01},
    {0xc8,0x2f,0x01},
    {0xc9,0x36,0x01},
    {0xca,0x3f,0x01},
    {0xcb,0x41,0x01},
    {0xcc,0x45,0x01},
    {0xcd,0x48,0x01},
    {0xce,0x44,0x01},
    {0xcf,0x4C,0x01},
    {0xd0,0x4B,0x01},
    {0xd1,0x55,0x01},

// color saturation
    {0xb0,0xe4,0x01},
    {0xb1,0xc0,0x01},
    {0xb2,0xb0,0x01},
    {0xb3,0x86,0x01},

//AE target
    {0x24,0x94,0x01},//0x8a
    {0x25,0x82,0x01},//0x7a
    {0x80,0x55,0x01},/* 50 Hz */	  
    {0x9d,0x7e,0x01},// 4c ��Ƶ	99 ����Ƶ 

    {0x15,0x00,0x01},  
    {0x3a,0x00,0x01},
    {0x3d,0xc2,0x01},
    {0x12,0x10,0x01},//00
/*    
    {0x2a,0x00,0x01},//dummy pixel 
    {0x2b,0x64,0x01},//dummy pixel 

    {0x92,0xc8,0x01},//dummy line 
    {0x93,0x00,0x01},//dummy line 
*/    
    {0x2a,0x00,0x01},//dummy pixel 
    {0x2b,0x64,0x01},//dummy pixel 

    {0x92,0xc8,0x01},//dummy line 
    {0x93,0x00,0x01},//dummy line 

    {0x8e,0x02,0x01},
    {0x8f,0xc6,0x01},    

 //160*120��
    {0x17,0x24,0x01},
    {0x18,0x74,0x01},
    {0x19,0x1e,0x01},
    {0x1a,0x5a,0x01},
    {0xf0,0x00,0x01},	

    {0xf0,0x00,0x01},  		
}
#else
{   

{0x12,0x80,0x01},
 {0xff,0xff,0x01},
{0x15,0x02,0x01},  //0x02
{0x3a,0x04,0x01},
{0x09,0x00,0x01},
 {0x11,0x80,0x01},
{0x13,0x00,0x01},
 {0x01,0x15,0x01},
 {0x02,0x22,0x01},
 {0x87,0x18,0x01},
 {0x8c,0x01,0x01},  //02
 {0x8d,0xef,0x01},
 {0x13,0x07,0x01},
// DBLK manual  
 {0x28,0x03,0x01},
 {0x2c,0x03,0x01},  
 {0x00,0x20,0x01},
 {0x0d,0x20,0x01},
 {0x0e,0x20,0x01},
 {0x0f,0x20,0x01},
 {0x05,0x16,0x01},  
 {0x14,0x16,0x01},
 {0x06,0x19,0x01},  
 {0x08,0x19,0x01},
 {0x26,0x08,0x01},  
 {0x27,0x08,0x01},
 {0X1F,0xa0,0x01},
 {0X22,0xa0,0x01},
//DBLK auto  
 {0x28,0x00,0x01},
 {0x2c,0x00,0x01},
 {0x1e,0x00,0x01},  
 {0x3A,0x00,0x01},
 {0x2f,0x00,0x01},
 {0x16,0x00,0x01},
 {0x29,0x04,0x01},
 {0x21,0x00,0x01},
 {0x04,0xbb,0x01},
 {0x56,0x40,0x01},
//lens shading
 {0x35,0x60,0x01},
 {0x65,0x58,0x01},
 {0x66,0x58,0x01},
//global gain
 {0x82,0x16,0x01},
 {0x83,0x25,0x01},
 {0x84,0x20,0x01},// 1a
 {0x85,0x26,0x01},
 {0x86,0x32,0x01}, // 30

 {0x96,0x26,0x01},// AE speed
 {0x97,0x0c,0x01},
 {0x2b,0x00,0x01},
 {0x70,0x2f,0x01},
 {0x72,0x4f,0x01},
 {0x73,0x2f,0x01},
 {0x74,0x27,0x01}, 
 {0x75,0x0e,0x01},
 {0x69,0x00,0x01},
 {0x76,0xff,0x01},
 {0x80,0x55,0x01},// 65
 {0x89,0x01,0x01},// 2
 {0x8a,0xef,0x01},// f8
//black level
 {0x90,0x20,0x01},
 {0x91,0x1c,0x01},
 {0x39,0x80,0x01},  
 {0x3f,0xa8,0x01},
 {0x3b,0x60,0x01},
 {0x3c,0x10,0x01},
//gamma //gamma 1 Ĭ��
/*
 {0X40,0X20,0x01},
 {0X41,0X30,0x01},
 {0X42,0X28,0x01},
 {0X43,0X28,0x01},
 {0X44,0X1d,0x01},
 {0X45,0X15,0x01},
 {0X46,0X13,0x01},
 {0X47,0X10,0x01},
 {0X48,0X0E,0x01},
 {0X49,0X0B,0x01},
 {0X4b,0X0B,0x01},
 {0X4c,0X09,0x01},
 {0X4e,0X07,0x01},
 {0X4f,0X06,0x01},
 {0X50,0X05,0x01},
  */
  /*
  //gamma 2 ����
  {0X1f,0X20,0x01},
  {0X22,0X20,0x01},
  {0X3f,0X90,0x01},				 
  {0X40,0X25,0x01},
  {0X41,0X2a,0x01},
  {0X42,0X28,0x01},
  {0X43,0X28,0x01},
  {0X44,0X20,0x01},
  {0X45,0X1d,0x01},
  {0X46,0X17,0x01},
  {0X47,0X15,0x01},
  {0X48,0X0f,0x01},
  {0X49,0X0e,0x01},
  {0X4b,0X0a,0x01},
  {0X4c,0X06,0x01},
  {0X4e,0X05,0x01},
  {0X4f,0X04,0x01},
  {0X50,0X02,0x01},
  */
 
  //gamma 3 ����
  {0X1f,0X20,0x01},
  {0X22,0X20,0x01},
  {0X3f,0Xa8,0x01},					 
  {0X40,0X42,0x01},
  {0X41,0X3b,0x01},
  {0X42,0X32,0x01},
  {0X43,0X24,0x01},
  {0X44,0X1c,0x01},
  {0X45,0X15,0x01},
  {0X46,0X11,0x01},
  {0X47,0X0d,0x01},
  {0X48,0X0d,0x01},
  {0X49,0X0B,0x01},
  {0X4b,0X09,0x01},
  {0X4c,0X08,0x01},
  {0X4e,0X08,0x01},
  {0X4f,0X07,0x01},
  {0X50,0X06,0x01},
 
 /*
  //gamma 4	����
  {0X1f,0X20,0x01},
  {0X22,0X20,0x01},
  {0X3f,0Xa0,0x01},					 
  {0X40,0X32,0x01},
  {0X41,0X2c,0x01},
  {0X42,0X30,0x01},
  {0X43,0X1d,0x01},
  {0X44,0X1a,0x01},
  {0X45,0X14,0x01},
  {0X46,0X11,0x01},
  {0X47,0X0e,0x01},
  {0X48,0X0d,0x01},
  {0X49,0X0c,0x01},
  {0X4b,0X0B,0x01},
  {0X4c,0X09,0x01},
  {0X4e,0X09,0x01},
  {0X4f,0X08,0x01},
  {0X50,0X07,0x01},

   */
  
//color matrix
 {0x51,0x2e,0x01}, // 30
 {0x52,0x92,0x01},
 {0x53,0x04,0x01}, // 02
 {0x54,0x88,0x01}, // 86
 {0x57,0x30,0x01},
 {0x58,0x88,0x01}, // 8a
 {0x59,0x80,0x01},
 {0x5a,0x92,0x01},
 {0x5b,0x32,0x01},

 {0x5c,0x2e,0x01},
 {0x5d,0x17,0x01},
// new  AWB
 {0x6a,0x01,0x01},
 {0x23,0x66,0x01},
 {0xa0,0x9f,0x01},
 {0xa1,0x51,0x01},
 {0xa2,0x10,0x01},
 {0xa3,0x26,0x01},
 {0xa4,0x0b,0x01},
 {0xa5,0x26,0x01},
 {0xa6,0x06,0x01},
 {0xa7,0x98,0x01},
 {0xa8,0x80,0x01},
 {0xa9,0x3e,0x01},
 {0xaa,0x4b,0x01},
 {0xab,0x40,0x01},//3e
 {0xac,0x42,0x01},
 {0xad,0x43,0x01},
 {0xae,0x48,0x01},
 {0xaf,0x2b,0x01},
 {0xc5,0x32,0x01},
 {0xc6,0x34,0x01},
 {0xc7,0x39,0x01},
 {0xc8,0x2f,0x01},
 {0xc9,0x36,0x01},
 {0xca,0x3f,0x01},
 {0xcb,0x40,0x01},//41
 {0xcc,0x45,0x01},
 {0xcd,0x48,0x01},
 {0xce,0x44,0x01},
 {0xcf,0x4C,0x01},
 {0xd0,0x4B,0x01},
 {0xd1,0x59,0x01},// 55
// color saturation
 {0xb0,0xe4,0x01},
 {0xb1,0xc0,0x01},
 {0xb2,0xb0,0x01},
 {0xb3,0x86,0x01},
//AE target
 {0x24,0x88,0x01},//0x8a
 {0x25,0x78,0x01},//0x7a
 /*
 {0x2a,0x00,0x01},//dummy pixel 
 {0x2b,0x64,0x01},//dummy pixel 

 {0x92,0xc8,0x01},//dummy line 
 {0x93,0x00,0x01},//dummy line 
*/
  {0x80,0x55,0x01},/* 50 Hz */	  
  {0x9d,0xa5,0x01},// MCLK=156M/6=26M
   

  //Fix FR to 20FPS@26M MCLK
     {0x92,0x3F,0x01},
    {0x93,0x01,0x01},

    {0x8e,0x03,0x01},
  {0x8f,0x3D,0x01},

 //160*120��
 {0x12,0x10,0x01},
 
 {0x17,0x24,0x01},
 {0x18,0x74,0x01},
 {0x19,0x1e,0x01},
 {0x1a,0x5a,0x01},
 {0x03,0x00,0x01},

/*
 {0x17,0x50,0x01},
 {0x18,0x4c,0x01},
 {0x19,0x3c,0x01},
 {0x1a,0x2d,0x01},
 {0x03,0x00,0x01},
*/


//{0x4a,0x01,0x01},

{0xf0,0x00,0x01},  		
 

}
#endif
;
  
const CAM_REG_T RG_VidFormatVga[] = 
{ 
     {0x12,0x00,0x01},//00
  //640*480��
{0x17,0x00,0x01},
 {0x18,0xa0,0x01},
 {0x19,0x00,0x01},
 {0x1a,0x78,0x01},
  {0x2a,0x00,0x01},//dummy pixel 
  {0x2b,0x64,0x01},//dummy pixel 

 {0x92,0xc8,0x01},//dummy line 
 {0x93,0x00,0x01},//dummy line 
};
  
const CAM_REG_T RG_VidFormatQvga[] = 
{ 
        {0x12,0x10,0x01},//00
        {0x2a,0x00,0x01},//dummy pixel 
       {0x2b,0x64,0x01},//dummy pixel 
       
       {0x92,0xc8,0x01},//dummy line 
       {0x93,0x00,0x01},//dummy line 
       /*
       //320*240��
       {0x17,0x24,0x01},
       {0x18,0x74,0x01},
       {0x19,0x1e,0x01},
       {0x1a,0x5a,0x01},
       */
       
       
};
  
const CAM_REG_T RG_VidFormatQqvga[] = 
{ 
    //160*120��
    {0x12,0x10,0x01},//00
    {0x17,0x24,0x01},
    {0x18,0x74,0x01},
    {0x19,0x1e,0x01},
    {0x1a,0x5a,0x01},
/*    
    {0x2a,0x00,0x01},//dummy pixel 
    {0x2b,0x64,0x01},//dummy pixel 

    {0x92,0xc8,0x01},//dummy line 
    {0x93,0x00,0x01},//dummy line 
*/    
	
};
  
typedef struct
{ 
// Camera information structure
    char                desc[40];	
  
    UINT8               snrtype;            //sensor type(RGB or YUV)
    UINT8               pclk;               //use PCLK of sensor
    UINT8               clkcfg;             //[0]: VSync delay enable; [1]: Fifo VSync delay enable; [2]: Use PCLK Negtive Edge.
    HAL_I2C_BPS_T       i2crate;            //I2C rate : KHz				
    UINT8               i2caddress;         //I2C address
    UINT8               i2cispaddress;      //ISP I2C address
    UINT8               pwrcfg;             //sensor power initial configure(SIF REG801 BIT[0]~BIT[2])
    BOOL                rstactiveh;         //sensor reset active hi/low polarity (TRUE = active hi)
    BOOL                snrrst;             //Reset sensor enable
  
    CAM_MODE_T          cammode;
  
  
    BOOL                capturevideo;
    BOOL                captureframe;
    UINT8               numactivebuffers;
    UINT8               currentbuf;
  
    UINT8               brightness;         //brightness
    UINT8               contrast;           //contrast
  
    CAM_FORMAT_T        format;
    UINT32              npixels;
    CAM_IMAGE_T         vidbuffer;
  
    CAM_REG_GROUP_T     standby;            //sensor standby register
    CAM_REG_GROUP_T     Initpoweron;        //SENSOR ISP initial configure
  
    CAM_REG_GROUP_T     sifpwronseq;        //Sif config sequence(Reg.800 bit0~2) when sensor power on
    CAM_REG_GROUP_T     sifstdbyseq;        //Sif config sequence(Reg.800 bit0~2) when sensor standby
    CAM_REG_GROUP_T     dsif;               //SIF initial configure
//    TSnrSizeCfgGroup    snrSizeCfg;         //sensor size configure information
  
// This 'callback' mechanism is not necessary because the encapsulation is taken
// care of by the environment
//    PSensorSetReg       snrSetRegCall;      //set reg callback
//    PSensorGetReg       snrGetRegCall;
//    PSnrIdChk           snrIdChkCall;
//    PSnrMirrorFlip      snrMirrorFlipCall;
//    PSnrContrast        snrContrastCall;
//    PSnrBrightness      snrBrightnessCall;
//    PSnrMode            snrModeCall;
//    PSnrGetEt           snrGetEt;
//    PSnrSetEt           snrSetEt;
//    TFlashParm          flashparm;
    CAM_IRQ_HANDLER_T   camirqhandler;
} CAM_INFO_T;
  
volatile CAM_INFO_T gSensorInfo =
{ 
    "bf3603 RGB Mode",      // char desc[40];	
  
    0,                      // UINT8 snrtype; (rgb)
    1,                      // UINT8 pclk; use or don't use PCLK of sensor???
    0,                      // UINT8 clkcfg; ???
    HAL_I2C_BPS_100K,       // UINT16 i2crate;
    0x6E,                   // UINT8 i2caddress; this is the _REAL_ slave address.  
                           //  The value written in phase 1 of a write cycle will be 0x42
                           //  while the value just before the read will be 0x43
    0x6E,                   // UINT8 i2cispaddress;
    0x02,                   // UINT8 pwrcfg;???
    TRUE,                   // BOOL rstactiveh;  // active high
    FALSE,                  // BOOL snrrst;
  
    CAM_MODE_IDLE,          // cammode
  
    FALSE,                  // Capture video mode
    FALSE,                  // Capturing single frame
    0,                      // Number of active buffers reserved by the upper layer
    0,                      // current frame buffer
  
    3,                      // UINT8 brightness;
    4,                      // UINT8 contrast;
    CAM_FORMAT_RGB565,      // Format
    CAM_NPIX_VGA,           // npixels(VGA, QVGA, QQVGA...)
    NULL,                   // Video Buffer.  First frame buffer for video or image buffer
  
    {0, NULL},              // CAM_REG_GROUP_T standby;
    // Should start with QQVGA, but for testing, start with VGA
//    {sizeof(RG_InitPowerOnQqvga) / sizeof(CAM_REG_T), (CAM_REG_T*)&RG_InitPowerOnQqvga}, // CAM_REG_GROUP_T Initpoweron;
    {sizeof(RG_InitPowerOnVga) / sizeof(CAM_REG_T), (CAM_REG_T*)&RG_InitPowerOnVga}, // CAM_REG_GROUP_T Initpoweron;
  
    {0, NULL},              // CAM_REG_GROUP_T sifpwronseq;
    {0, NULL},              // CAM_REG_GROUP_T sifstdbyseq;
    {0, NULL},              // CAM_REG_GROUP_T dsif; initial value
    NULL                    // IRQ Callback
};
  
// ############
// Private
// ############
  
// These are the commands specific to the SCCB
#define PHASE3_WR_PH1   0x11000     // Start & Write    Slave ID
#define PHASE3_WR_PH2   0x1000      // Write            Slave Register Address
#define PHASE3_WR_PH3   0x1100      // Stop & Write     Slave Register Data
  
#define PHASE2_WR_PH1   0x11000     // Start & Write    Slave ID
#define PHASE2_WR_PH2   0x1100      // Stop & Write     Slave Register Address (to read)
  
#define PHASE2_RD_PH1   0x11000     // Start & Write    Slave ID
#define PHASE2_RD_PH2   0x111       // Stop & Read & NACK   Slave Register Read Data

PRIVATE VOID camerap_WriteOneReg( UINT8 Addr, UINT8 Data);
PRIVATE VOID camerap_Delay(UINT16 Wait_mS);
PRIVATE VOID camerap_WriteReg(CAM_REG_T RegWrite);
PRIVATE UINT8 camerap_ReadReg(UINT8 Addr);
PRIVATE VOID camerap_SendRgSeq(const CAM_REG_T *RegList, UINT16 Len);
PRIVATE VOID camerap_InteruptHandler(HAL_CAMERA_IRQ_CAUSE_T cause);
PRIVATE UINT8 camerap_GetId(VOID);
