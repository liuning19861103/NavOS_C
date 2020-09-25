/***************************************************************** 
*  @brief:       Sensor Input Through External ADC/ Internal ADC/FMC  
*  @File:        SensorRead.h
*  @Project:     MIMU
*  @Author:      Liu Ning
*  @Date:        20180405 
*  @CopyRight:   Copyright (c) 2017 HDNT, ISC License (open source)
*  @Version:     V1.0
*  @Description: SensorRead header file
*****************************************************************/

#ifndef __SENSORREAD_H
#define __SENSORREAD_H

#if defined(STM32F429xx)
	#include "stm32f4xx_hal.h"
#elif defined(STM32F767xx)
  #include "stm32f7xx_hal.h"
#elif defined(STM32F401xE)
  #include "stm32f4xx_hal.h"
#elif defined(STM32H753xx)
  #include "stm32h7xx_hal.h"
#endif

//#include "PlatformCon.h"
#include "IMUConfig.h"
#include "Delay.h"

/*-AD channel-*/
#define AX1_ADC_CH   2
#define AY1_ADC_CH   1
#define AZ1_ADC_CH   0
#define AX2_ADC_CH   10
#define AY2_ADC_CH   8
#define AZ2_ADC_CH   9
#define GX_ADC_CH    3
#define GY_ADC_CH    4
#define GZ_ADC_CH    11
#define GXT_ADC_CH   5
#define GYT_ADC_CH   12
#define GZT_ADC_CH   13
#define TEMP_ADC_CH  6
#define MX_ADC_CH    16
#define MY_ADC_CH    17
#define MZ_ADC_CH    18

/*-Global Variable Declarition-*/
#define FIR_CH     12
#define ADC_CH     20
/*Sensor's struct used to descript the sensor's character.*/

typedef struct{
  uint16_t AD_DATA[ADC_CH];            //storage adc data from adc
  uint16_t AD_Buffer[ADC_CH][256];     //the max order is 255
#if defined(AD_FIR_MODE)
  uint8_t  AD_Buffer_Size[ADC_CH];     //adc buffer length, this value will changed through the filter mess command
  uint16_t Fitler_Coe[ADC_CH][256];    //Fir coe array
  uint16_t ADF_DATA[ADC_CH];           //after filter data
#endif
  void (*updata_func) (void);
  uint8_t (*SelfTest_func) (void);
  void (*Init_Func) (void);
  uint8_t FIR_Flag; //
}ADC_Info;

extern ADC_Info Sensor_Original_Info;

void Sensor_Read_Init(void);
void Sensor_Updata(void); //all the sensor's data updata from adc
uint8_t Sensor_Check(void);
void Sensor_Init(void);
void Sensor_Read(void);


#endif
