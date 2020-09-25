/***************************************************************** 
*  @brief:        
*  @File:          
*  @Project:    
*  @Author:      
*  @Date:         
*  @CopyRight:   
*  @Version:      
*  @Description:  
*****************************************************************/
#ifndef __EXTDEVCON_H
#define __EXTDEVCON_H

/*-select the device platform-*/
#if defined(STM32F429xx)
	#include "stm32f4xx_hal.h"
#elif defined(STM32F767xx)
  #include "stm32f7xx_hal.h"
#endif

#include "Config.h"
#include "GlobalDefine.h"
#include "INSSolve.h"
#include "MagDataAnalysis.h"
#include "PulseEngine.h"

#define POWERON    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_SET)
#define POWERDOWN  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_RESET)

#define GPSUARTON      HAL_UART_Receive_DMA(&huart2, Uart_Control[USART2_ID].RX_Buffer, Uart_Control[USART2_ID].RX_Size)  //single byte receive
#define GPSUARTDOWN    HAL_UART_DMAStop(&huart2)

#define MAGSET     HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_SET)
#define MAGRESET   HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_RESET)

typedef struct{
  uint8_t   OpenFlag;
  float32_t OpenTime;
}Power_Set_Info;

typedef struct{
  uint8_t ResetFlag;
  uint8_t PulseCount;  //Deifine the pulse number
  uint8_t SetCount;
  uint8_t ResetCount;
}Mag_Set_Info;


typedef struct{
  float32_t *BufferData;
  uint8_t   PowerOpenFlag;
  float32_t PowerOpenTime;
  
  uint8_t ResetFlag;
  uint8_t PulseCount;  //Deifine the pulse number
  float32_t ResetTime;
}ExtDev_Con_Info;

extern ExtDev_Con_Info ExtDev_Par;

enum ExtDev_Type{
    ResMode     =0,
    MagAutoCal  =1,
    MagManualCal=2,
    PowerCon    =3,
    MagResetPar =4,
    DHCon       =5
  };

typedef struct{
  void (*Init) (void);
  void (*Update) (void);
  void (*PowSwitch) (void);
  void (*MagSetReset) (void);
  void (*DetectFire) (void);
}ExtCon_Func_Info;

extern ExtCon_Func_Info ExtCon_Func;

void ExtDevCon_Init(void);               //external device control initial
void ExtDevCon_Data_Update(void);        //external device data update through the com
void ExtDevCon_Power(void);
void ExtDevCon_Mag(void);
void ExtDevCon_DetectFire(void);


#endif

