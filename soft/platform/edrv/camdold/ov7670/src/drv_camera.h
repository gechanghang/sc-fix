// Here is where all the model specific defines should be


#include "hal_i2c.h"
#include "camera_m.h"

//#define  DRV_CAM_FRAME_6    1
 #define  DRV_CAM_FRAME_10    1
//#define  DRV_CAM_FRAME_12    1
typedef struct
{
    UINT32 Addr;            // Register Address
    UINT8 Data;             // Register Data
    UINT16 Wait;            // Time to wait after write
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

// use this for 320x240 (VGA) capture
const CAM_REG_T RG_InitPowerOnQvga[] = 
{   
#if 0 //for RGB
       {0x12,0x80,10},
             //; Insert 5ms delay here
       {0x11,0x01, 1}, 

       {0x3a,0x04,1},
	{0x12,0x04,1},
       {0x40,0xd0,1},      
	{0x32,0x80,1},      
	{0x17,0x16,1},      
	{0x18,0x04,1},      
	{0x19,0x02,1},      
	{0x1a,0x7a,1},      
	{0x03,0x0a,1},      
	{0x0c,0x04,1},      
	
	
	{0x3e,0x19,1},      
	{0x70,0x3a,1},      
	{0x71,0x35,1},      
	{0x72,0x11,1},      
	{0x73,0xf1,1},      
	{0xa2,0x02,1},  
#endif 

       //for yuv
	 {0x12,0x80,10},
             //; Insert 5ms delay here
  #ifdef  DRV_CAM_FRAME_6
       {0x11,0x00, 1}, 
  #else
	{0x11,0x01, 1},
  #endif 
	 
       {0x3a,0x04,1},
       {0x12,0x00,1},
       {0x40,0xc0,1}, 
       {0x8c,0x00,1},

     //Qvga Format
	    
	{0x17,0x15,1},      
	{0x18,0x03,1},  
        {0x32,0x36,1},      
	{0x19,0x02,1},      
	{0x1a,0x7a,1},      
	{0x03,0x0a,1},      
	{0x0c,0x04,1},      
	
	
	{0x3e,0x19,1},      
	{0x70,0x3a,1},      
	{0x71,0x35,1},      
	{0x72,0x11,1},      
	{0x73,0xf1,1},      
	{0xa2,0x02,1},  
	
	 {0x7a, 0x20,1},
	 {0x7b, 0x1c,1},
	 {0x7c, 0x28,1},
	 {0x7d ,0x3c,1},
	 {0x7e, 0x5a,1},
	 {0x7f ,0x68,1},
	 {0x80 ,0x76,1},
	 {0x81, 0x80,1},
	 {0x82 ,0x88,1},
	 {0x83 ,0x8f,1},
	 {0x84, 0x96,1},
	 {0x85, 0xa3,1},
	 {0x86 ,0xaf,1},
	 {0x87, 0xc4,1},
	 {0x88, 0xd7,1},
	 {0x89, 0xe8,1},
	
	{0x13,0xe0,1},      
	{0x00,0x00,1},      
	{0x10,0x00,1},      
	{0x0d,0x40,1},      
	{0x14,0x38,1},      
	{0xa5,0x05,1},      
	{0xab,0x07,1},      
	{0x24,0x95,1},      
	{0x25,0x33,1},      
	{0x26,0xe3,1},      
	{0x9f,0x78,1},      
	{0xa0,0x68,1},      
	{0xa1,0x03,1},      
	{0xa6,0xd8,1},      
	{0xa7,0xd8,1},      
	{0xa8,0xf0,1},      
	{0xa9,0x90,1},      
	{0xaa,0x94,1},      
	{0x13,0xe5,1},      
	{0x0e,0x61,1},      
	{0x0f,0x4b,1},      
	{0x16,0x02,1},      
	{0x1e,0x07,1},      
	{0x21,0x02,1},      
	{0x22,0x91,1},      
	{0x29,0x07,1},      
	{0x33,0x0b,1},      
	{0x35,0x0b,1},      
	{0x37,0x1d,1},      
	{0x38,0x71,1},      
	{0x39,0x2a,1},      
	{0x3c,0x78,1},      
	{0x4d,0x40,1},      
	{0x4e,0x20,1},      
	{0x69,0x00,1},      
	{0x6b,0x4a,1},      
	{0x74,0x19,1},      
	{0x8d,0x4f,1},      
	{0x8e,0x00,1},      
	{0x8f,0x00,1},      
	{0x90,0x00,1},      
	{0x91,0x00,1},      
	{0x96,0x00,1},      
	{0x9a,0x80,1},      
	{0xb0,0x84,1},      
	{0xb1,0x0c,1},      
	{0xb2,0x0e,1},      
	{0xb3,0x82,1},      
	{0xb8,0x0a,1}, 
        // update AWB setting
	{0x43,0x0a,1},    //  
	{0x44,0xf0,1},      
	{0x45,0x38,1},    //  
	{0x46,0x66,1},    //  
	{0x47,0x24,1},     // 
	{0x48,0x3a,1},    //  
	{0x59,0x8a,1},   //   
	{0x5a,0x9c,1},      
	{0x5b,0x55,1},      
	{0x5c,0x7d,1},      
	{0x5d,0x4c,1},      
	{0x5e,0x0f,1},      
	{0x6c,0x0a,1},      
	{0x6d,0x55,1},      
	{0x6e,0x11,1},      
	{0x6f,0x96,1},      
	{0x6a,0x40,1},   
	
	{0x01,0x40,1},      
	{0x02,0x40,1},      
	{0x13,0xe7,1},   
          
         //saturation
        #if 0 //for saturation 0
	{0x4f,0x80,1},      
	{0x50,0x80,1},      
	{0x51,0x00,1},      
	{0x52,0x22,1},      
	{0x53,0x5e,1},      
	{0x54,0x80,1},      
	{0x58,0x9e,1}, 
       #endif 
        //for saturation +1
        {0x4f,0x99,1},      
	{0x50,0x99,1},      
	{0x51,0x00,1},      
	{0x52,0x28,1},      
	{0x53,0x71,1},      
	{0x54,0x99,1},      
	{0x58,0x9e,1}, 
 	
	{0x41,0x08,1},      
	{0x3f,0x00,1},      
	{0x75,0x05,1},      
	{0x76,0xe1,1},      
	{0x4c,0x00,1},      
	{0x77,0x01,1},      
	{0x3d,0xc0,1},      
	{0x4b,0x09,1},       
	{0xc9,0x60,1},

	{0x41,0x38,1},   
	//append lens correction setting
	{0x62,0x10,1},
	{0x63,0x30,1},
	{0x64,0x0c,1},
	{0x94,0x0b,1},
	{0x95,0x10,1},
	{0x65,0x00,1},
	{0x66,0x05,1},
	
	{0x27,0x80,1},
	{0x28,0x80,1},
	{0x2c,0x80,1},
	{0x56,0x40,1},   
	{0x34,0x11,1},   
	//{0x3b,0x02,1},  
	{0x3b,0x0a,1},
	{0xa4,0x88,1},   
	{0x96,0x00,1},   
	{0x97,0x30,1},   
	{0x98,0x20,1},   
	{0x99,0x30,1},   
	{0x9a,0x84,1},   
	{0x9b,0x29,1},   
	{0x9c,0x03,1},   
	{0x9d,0x4c,1},   
	{0x9e,0x3f,1},   
	{0x78,0x04,1},   
	{0x79,0x01,1},   
	{0xc8,0xf0,1},   
	{0x79,0x0f,1},   
	{0xc8,0x00,1},   
	{0x79,0x10,1},   
	{0xc8,0x7e,1},   
	{0x79,0x0a,1},   
	{0xc8,0x80,1},   
	{0x79,0x0b,1},   
	{0xc8,0x01,1},   
	{0x79,0x0c,1},   
	{0xc8,0x0f,1},   
	{0x79,0x0d,1},   
	{0xc8,0x20,1},   
	{0x79,0x09,1},   
	{0xc8,0x80,1},   
	{0x79,0x02,1},   
	{0xc8,0xc0,1},   
	{0x79,0x03,1},   
	{0xc8,0x40,1},   
	{0x79,0x05,1},   
	{0xc8,0x30,1},   
	{0x79,0x26,10},   

	//for 6pfs
#ifdef  DRV_CAM_FRAME_6
	{0x6b,0x0a,1},
	{0x92,0x10,1},
	{0x93,0x00,1},
	{0x2a,0x00,1},
	{0x2b,0x00,1},

	{0x9d,0x47,1},
	{0x9e,0x3B,1},

	{0xa5,0x06,1},
	{0xab,0x07,1},
 #endif 
	   	
   // for 12 pfs
#ifdef 	DRV_CAM_FRAME_12
       {0x6b,0x4a,1},  //
	{0x92,0x53,1}, 
       {0x93,0x00,1},
	{0x2a,0x00,1},
	{0x2b,0x00,1},

	{0x9d,0x76,1}, //
	{0x9e,0x63,1}, //

	{0xa5,0x04,1}, //
	{0xab,0x05,1}, //
#endif 

 //for 10pfs
#ifdef 	DRV_CAM_FRAME_10
       {0x6b,0x4a,1},  //
       {0x92,0xC9,1}, //for 10pfs
	{0x93,0x00,1},
	{0x2a,0x00,1},
	{0x2b,0x00,1},

	{0x9d,0x8E,1}, //
	{0x9e,0x76,1}, //

	{0xa5,0x04,1}, //
	{0xab,0x05,1}, //
#endif
        {0x5f,0xf0,1},  //b limit
	{0x60,0xf0,1},  //r limit 70
	{0x61,0xf0,1},  //g limit

};

// use this for 640x480 (VGA) capture
const CAM_REG_T RG_InitPowerOnVga[] = 
{
       
	{0x12,0x80,10},
       {0x11,0x06,1},  //frame rate
             	   
       {0x3a,0x04,1},
	{0x12,0x04,1},
       {0x40,0xd0,1},      
	{0x17,0x13,1},      
	{0x18,0x01,1},      
	{0x32,0xb6,1},      
	{0x19,0x02,1},      
	{0x1a,0x7a,1},      
	{0x03,0x0a,1},      
	{0x0c,0x00,1},  
	
	
	{0x3e,0x00,1},      
	{0x70,0x3a,1},     
	{0x71,0x35,1},      
	{0x72,0x11,1},      
	{0x73,0xf0,1},      
	{0xa2,0x02,1},    
	
	{0x7a, 0x19,1}, 
	{0x7b, 0x0c,1},
	{0x7c, 0x18,1},
	{0x7d, 0x2f,1},
	{0x7e, 0x54,1},
	{0x7f, 0x64,1},
	{0x80, 0x71,1},
	{0x81, 0x7d,1},
	{0x82, 0x88,1},
	{0x83, 0x91,1},
	{0x84, 0x98,1},
	{0x85, 0xa7,1},
	{0x86, 0xb4,1},
	{0x87, 0xcb,1},
	{0x88, 0xde,1},
	{0x89, 0xed,1},
	
	{0x13,0xe0,1},      
	{0x00,0x00,1},      
	{0x10,0x00,1},      
	{0x0d,0x40,1},      
	{0x14,0x38,1},      
	{0xa5,0x05,1},      
	{0xab,0x07,1},      
	{0x24,0x95,1},      
	{0x25,0x33,1},      
	{0x26,0xe3,1},      
	{0x9f,0x78,1},      
	{0xa0,0x68,1},      
	{0xa1,0x03,1},      
	{0xa6,0xd8,1},      
	{0xa7,0xd8,1},      
	{0xa8,0xf0,1},      
	{0xa9,0x90,1},      
	{0xaa,0x94,1},      
	{0x13,0xe5,1},      
	{0x0e,0x61,1},      
	{0x0f,0x4b,1},      
	{0x16,0x02,1},      
	{0x1e,0x07,1},      
	{0x21,0x02,1},      
	{0x22,0x91,1},      
	{0x29,0x07,1},      
	{0x33,0x0b,1},      
	{0x35,0x0b,1},      
	{0x37,0x1d,1},      
	{0x38,0x71,1},      
	{0x39,0x2a,1},      
	{0x3c,0x78,1},      
	{0x4d,0x40,1},      
	{0x4e,0x20,1},      
	{0x69,0x00,1},      
	{0x6b,0x4a,1},      
	{0x74,0x19,1},      
	{0x8d,0x4f,1},      
	{0x8e,0x00,1},      
	{0x8f,0x00,1},      
	{0x90,0x00,1},      
	{0x91,0x00,1},      
	{0x96,0x00,1},      
	{0x9a,0x80,1},      
	{0xb0,0x84,1},      
	{0xb1,0x0c,1},      
	{0xb2,0x0e,1},      
	{0xb3,0x82,1},      
	{0xb8,0x0a,1},      
	{0x43,0x14,1},      
	{0x44,0xf0,1},      
	{0x45,0x34,1},      
	{0x46,0x58,1},      
	{0x47,0x28,1},      
	{0x48,0x3a,1},      
	{0x59,0x88,1},      
	{0x5a,0x88,1},      
	{0x5b,0x44,1},      
	{0x5c,0x67,1},      
	{0x5d,0x49,1},      
	{0x5e,0x0e,1},      
	{0x6c,0x0a,1},      
	{0x6d,0x55,1},      
	{0x6e,0x11,1},      
	{0x6f,0x9f,1},     
	{0x6a,0x40,1},      
	{0x01,0x40,1},      
	{0x02,0x40,1},      
	{0x13,0xe7,1},      
	{0x4f,0x80,1},      
	{0x50,0x80,1},      
	{0x51,0x00,1},      
	{0x52,0x22,1},      
	{0x53,0x5e,1},      
	{0x54,0x80,1},      
	{0x58,0x9e,1},      
	{0x41,0x08,1},      
	{0x3f,0x00,1},  
	
	{0x75,0x05,1},   
	
	{0x76,0xe1,1},      
	{0x4c,0x00,1},      
	{0x77,0x01,1},      
	{0x3d,0xc0,1},      
	{0x4b,0x09,1},      
	{0xc9,0x60,1},

	{0x41,0x38,1},   
	{0x56,0x40,1},   
	{0x34,0x11,1},   
	
	{0x3b,0x0a,1},
	{0xa4,0x88,1},   
	{0x96,0x00,1},   
	{0x97,0x30,1},   
	{0x98,0x20,1},   
	{0x99,0x30,1},   
	{0x9a,0x84,1},   
	{0x9b,0x29,1},   
	{0x9c,0x03,1},   
	{0x9d,0x4c,1},   
	{0x9e,0x3f,1},   
	{0x78,0x04,1},   
	{0x79,0x01,1},   
	{0xc8,0xf0,1},   
	{0x79,0x0f,1},   
	{0xc8,0x00,1},   
	{0x79,0x10,1},   
	{0xc8,0x7e,1},   
	{0x79,0x0a,1},   
	{0xc8,0x80,1},   
	{0x79,0x0b,1},   
	{0xc8,0x01,1},   
	{0x79,0x0c,1},   
	{0xc8,0x0f,1},   
	{0x79,0x0d,1},   
	{0xc8,0x20,1},   
	{0x79,0x09,1},   
	{0xc8,0x80,1},   
	{0x79,0x02,1},   
	{0xc8,0xc0,1},   
	{0x79,0x03,1},   
	{0xc8,0x40,1},   
	{0x79,0x05,1},   
	{0xc8,0x30,1},   
	{0x79,0x26,10},  
	
};


// use this for 160*120 (QQVGA) capture
const CAM_REG_T RG_InitPowerOnQqvga[] = 
{
        {0x12, 0x80,10},            //  Reset
       
        {0x11, 0x01,1},             //frame rate
	 {0x3a, 0x04,1},
	 {0x12 ,0x00,1},             //yuv output		
	 {0x17, 0x13,1},
	 {0x18, 0x01,1},
	 {0x32, 0xb6,1},
	 {0x19, 0x02,1},
	 {0x1a ,0x7a,1},
	 {0x03, 0x0d,1},
	 {0x0c, 0x00,1},	   
	 {0x3e, 0x00,1},
	 {0x70, 0x3a,1},
	 {0x71, 0x35,1},
	 {0x72 ,0x11,1},	 
	 {0x73, 0xf0,1},
	 {0xa2 ,0x02,1},

 
///////////////////////
	 {0x7a, 0x20,1},
	 {0x7b, 0x1c,1},
	 {0x7c, 0x28,1},
	 {0x7d ,0x3c,1},
	 {0x7e, 0x5a,1},
	 {0x7f ,0x68,1},
	 {0x80 ,0x76,1},
	 {0x81, 0x80,1},
	 {0x82 ,0x88,1},
	 {0x83 ,0x8f,1},
	 {0x84, 0x96,1},
	 {0x85, 0xa3,1},
	 {0x86 ,0xaf,1},
	 {0x87, 0xc4,1},
	 {0x88, 0xd7,1},
	 {0x89, 0xe8,1},

	 {0x13, 0xe0,1},
	 {0x01, 0x50,1},
	 {0x02, 0x68,1},
	 {0x00, 0x00,1},
	 {0x10, 0x00,1},
	 {0x0d, 0x40,1},
	 {0x14, 0x18,1},
	 {0xa5, 0x07,1},
	 {0xab, 0x08,1},
	 {0x24, 0x95,1},
	 {0x25, 0x33,1},
	 {0x26, 0xe3,1},
	 {0x9f, 0x78,1},
	 {0xa0, 0x68,1},
	 {0xa1, 0x03,1},
	 {0xa6, 0xd8,1},
	 {0xa7, 0xd8,1},
	 {0xa8, 0xf0,1},
	 {0xa9, 0x90,1},
	 {0xaa, 0x94,1},
	 {0x13, 0xe5,1},

	 {0x0e, 0x61,1},
	 {0x0f, 0x4b,1},
	 {0x16, 0x02,1},
	 {0x1e, 0x07,1},
	 {0x21, 0x02,1},
	 {0x22, 0x91,1},
	 {0x29, 0x07,1},
	 {0x33, 0x0b,1},
	 {0x35, 0x0b,1},
	 {0x37, 0x1d,1},
	 {0x38, 0x71,1},
	 {0x39, 0x2a,1},
	 {0x3c, 0x78,1},
	 {0x4d, 0x40,1},
	 {0x4e, 0x20,1},
	 {0x69, 0x00,1},
	 {0x6b, 0x4a,1},
	 {0x74, 0x10,1},
	 {0x8d, 0x4f,1},
	 {0x8e ,0x00,1},
	 {0x8f ,0x00,1},
	 {0x90, 0x00,1},
	 {0x91, 0x00,1},
	 {0x91, 0x66,1},
	 {0x96 ,0x00,1},
	 {0x9a ,0x80,1},
	 {0xb0 ,0x84,1},
	 {0xb1 ,0x0c,1},
	 {0xb2 ,0x0e,1},
	 {0xb3 ,0x82,1},
	 {0xb8 ,0x0a,1},

	 {0x43, 0x14,1},
	 {0x44, 0xf0,1},
	 {0x45, 0x34,1},
	 {0x46, 0x58,1},
	 {0x47, 0x28,1},
	 {0x48, 0x3a,1},
	 {0x59, 0x88,1},
	 {0x5a, 0x88,1},
	 {0x5b, 0x44,1},
	 {0x5c, 0x67,1},
	 {0x5d, 0x49,1},
	 {0x5e, 0x0e,1},	 
	 {0x64, 0x04,1},
	 
	 {0x65, 0x20,1},
	 {0x66, 0x05,1},
	 {0x94, 0x04,1},
	 {0x95, 0x08,1},	 
	 {0x6c, 0x0a,1},
	 {0x6d, 0x55,1},
	 {0x6e, 0x11,1},
	 {0x6f, 0x9f,1},
	 {0x6a, 0x40,1},
	 {0x01, 0x40,1},
	 {0x02, 0x40,1},
	 {0x13, 0xe7,1},

	 {0x4f, 0x80,1},
	 {0x50, 0x80,1},
	 {0x51, 0x00,1},
	 {0x52, 0x22,1},
	 {0x53, 0x5e,1},
	 {0x54, 0x80,1},
	 {0x58, 0x9e,1},

	 {0x41, 0x08,1},
	 {0x3f, 0x00,1},
        {0x75, 0x03,1},
	 {0x76, 0xe1,1},
	 {0x4c, 0x00,1},
	 {0x77, 0x00,1},
	 {0x3d, 0xc3,1},   	  
	 {0x4b, 0x09,1},
	 {0xc9, 0x60,1},
	 {0x41, 0x38,1},
	 {0x56, 0x40,1},
	 
	 {0x34, 0x11,1},
	 {0x3b, 0x0a,1},
	 {0xa4, 0x88,1},
	 {0x96, 0x00,1},
	 {0x97 ,0x30,1},
	 {0x98 ,0x20,1},
	 {0x99, 0x30,1},
	 {0x9a, 0x84,1},
	 {0x9b, 0x29,1},
	 {0x9c, 0x03,1},
	 {0x9d, 0x98,1},
	 {0x9e, 0x3f,1},
	 {0x78, 0x04,1},

	 {0x79, 0x01,1},
	 {0xc8, 0xf0,1},
	 {0x79, 0x0f,1},
	 {0xc8, 0x00,1},
	 {0x79, 0x10,1},
	 {0xc8, 0x7e,1},
	 {0x79, 0x0a,1},
	 {0xc8, 0x80,1},
	 {0x79, 0x0b,1},
	 {0xc8, 0x01,1},
	 {0x79, 0x0c,1},
	 {0xc8, 0x0f,1},
	 {0x79, 0x0d,1},
	 {0xc8, 0x20,1},
	 {0x79, 0x09,1},
	 {0xc8, 0x80,1},
	 {0x79, 0x02,1},
	 {0xc8, 0xc0,1},
	 {0x79, 0x03,1},
	 {0xc8, 0x40,1},
	 {0x79, 0x05,1},
	 {0xc8, 0x30,1},
	 {0x79, 0x26,10},
	 {0x2d, 0x00,1},
	 {0x2e, 0x00,10},	

	 
	 {0x11,0x01,1},	//
	// {0x3a,0x04,1},
	 {0x3a,0x0c,1},
	 {0x12,0x00,1},	
	 {0x17, 0x16,1},
	 {0x18, 0x04,1},
	 {0x32, 0xa4,1},
	 {0x19, 0x02,1},
	 {0x1a ,0x7a,1},
	 {0x03, 0x0d,1},
	 {0x0c, 0x04,1},	   
	 {0x3e, 0x1a,1},
	 {0x70, 0x3a,1},
	 {0x71, 0x35,1},
	 {0x72 ,0x22,1},	 
	 {0x73, 0xf2,1},
	 {0xa2 ,0x02,1},
     

	   #if 1
	{0x6b,0x4a,1},  //

#ifdef 	DRV_CAM_FRAME_12
	{0x92,0x53,1}, // for 12 pfs
#else
       {0x92,0xC9,1}, //for 10pfs
#endif

	{0x93,0x00,1},
	{0x2a,0x00,1},
	{0x2b,0x00,1},

	{0x9d,0x8E,1}, //
	{0x9e,0x76,1}, //

	{0xa5,0x04,1}, //
	{0xab,0x05,1}, //
	#endif 

	#if 0 // for 6pfs
	{0x11,0x00,1},	
	{0x6b,0x0a,1},
	{0x92,0x10,1},
	{0x93,0x00,1},
	{0x2a,0x00,1},
	{0x2b,0x00,1},

	{0x9d,0x47,1},
	{0x9e,0x3B,1},

	{0xa5,0x06,1},
	{0xab,0x07,1},

	#endif

};

const CAM_REG_T RG_VidFormatVga[] = 
{
        
	{0x17,0x13,1},      
	{0x18,0x01,1},      
	{0x32,0xb6,1},      
	{0x19,0x02,1},      
	{0x1a,0x7a,1},      
	{0x03,0x0a,1},      
	{0x0c,0x00,1},      
	{0x3e,0x00,1},      
	{0x70,0x3a,1},     
	{0x71,0x35,1},      
	{0x72,0x11,1},      
	{0x73,0xf0,1},      
};

const CAM_REG_T RG_VidFormatQvga[] = 
{
            	     
	{0x17,0x16,1},      
	{0x18,0x04,1},  
	{0x32,0x80,1}, 
	{0x19,0x02,1},      
	{0x1a,0x7a,1},      
	{0x03,0x0a,1},      
	{0x0c,0x04,1},      
	{0x3e,0x19,1},      
	{0x70,0x3a,1},      
	{0x71,0x35,1},      
	{0x72,0x11,1},      
	{0x73,0xf1,1},  
};

const CAM_REG_T RG_VidFormatQqvga[] = 
{
        
	
	 {0x17, 0x39,1},
	 {0x18, 0x03,1},
	 {0x32, 0x80,1},
	 {0x19, 0x03,1},
	 {0x1a ,0x7b,1},
	 {0x03, 0x0a,1},
	 {0x0c, 0x0c,1},
	 {0x3e, 0x11,1},
	 {0x70, 0x3a,1},
	 {0x71, 0x35,1},
	 {0x72 ,0x11,1},
	 {0x73, 0xf1,1},
	
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
    CAM_SIZE_T          npixels;
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
    "OV7670 RGB Mode",      // char desc[40];	

    0,                      // UINT8 snrtype; (rgb)
    1,                      // UINT8 pclk; use or don't use PCLK of sensor???
    0,                      // UINT8 clkcfg; ???
    HAL_I2C_BPS_100K,       // UINT16 i2crate;
    0x21,                   // UINT8 i2caddress; this is the _REAL_ slave address.  
                           //  The value written in phase 1 of a write cycle will be 0x42
                           //  while the value just before the read will be 0x43
    0x21,                   // UINT8 i2cispaddress;
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

VOID  camera_WriteOneReg( UINT8 Addr, UINT8 Data);
VOID camera_Delay(UINT16 Wait_mS);
VOID camera_WriteReg(CAM_REG_T RegWrite);
UINT8 camera_ReadReg(UINT8 Addr);
VOID camera_SendRgSeq(const CAM_REG_T *RegList, UINT16 Len);
VOID camera_InteruptHandler();
