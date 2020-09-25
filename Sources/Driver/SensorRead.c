/***************************************************************** 
*  @brief:       Sensor Input Through External ADC/ Internal ADC/FMC  
*  @File:        SensorRead.c
*  @Project:     MIMU
*  @Author:      Liu Ning
*  @Date:        200180405
*  @CopyRight:   Copyright (c) 2017 HDNT, ISC License (open source)
*  @Version:     V1.0
*  @Description: SensorRead file
*****************************************************************/
#include "SensorRead.h"

//	<o>Begin Address of External SRAM
//		<i>Default: 0x68000000
#define EXT_SRAM_BEGIN          0x60000000 /* the begining address of external SRAM */
// <o> External SRAM memory size[Kbytes]: <8-512>
//	<i>Default: 256
#define EXT_SRAM_SIZE           128
/* End Address of External SRAM */
#define EXT_SRAM_END            (EXT_SRAM_BEGIN + (EXT_SRAM_SIZE * 1024)) /* the end address of external SRAM */
// </e>

uint32_t buffer[20]={0};

void delay(int i)
{
	for(;i>0;i--);
}

uint8_t Sensor_Check(void)
{
	return SUCCESS;
}

void Sensor_Init(void)
{
}

void Sensor_Updata(void)
{
  uint16_t i=0;
  buffer[0]=(*(__IO uint32_t *)(EXT_SRAM_BEGIN | (0x000<<2)));
  buffer[1]=(*(__IO uint32_t *)(EXT_SRAM_BEGIN | (0x002<<2)));
  buffer[2]=(*(__IO uint32_t *)(EXT_SRAM_BEGIN | (0x004<<2)));
  buffer[3]=(*(__IO uint32_t *)(EXT_SRAM_BEGIN | (0x006<<2)));
  buffer[4]=(*(__IO uint32_t *)(EXT_SRAM_BEGIN | (0x008<<2)));
  buffer[5]=(*(__IO uint32_t *)(EXT_SRAM_BEGIN | (0x00a<<2)));
  buffer[6]=(*(__IO uint32_t *)(EXT_SRAM_BEGIN | (0x00C<<2)));
  buffer[7]=(*(__IO uint32_t *)(EXT_SRAM_BEGIN | (0x00E<<2)));
  buffer[8]=(*(__IO uint32_t *)(EXT_SRAM_BEGIN | (0x010<<2)));
  buffer[9]=(*(__IO uint32_t *)(EXT_SRAM_BEGIN | (0x012<<2)));
  for(i=0;i<8;i++){
    Sensor_Original_Info.AD_DATA[i]   = (buffer[i]>>16);
    Sensor_Original_Info.AD_DATA[i+8] = (buffer[i]&0x0000ffff);
  }
  Sensor_Original_Info.AD_DATA[16] = (buffer[8]>>16);
  Sensor_Original_Info.AD_DATA[17] = (buffer[8]&0x0000ffff);
  Sensor_Original_Info.AD_DATA[18] = (buffer[9]>>16);
  Sensor_Original_Info.AD_DATA[19] = (buffer[9]&0x0000ffff);
}






