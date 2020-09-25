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
#ifndef __PULSEENGINE_H
#define __PULSEENGINE_H

/*-select the device platform-*/
#if defined(STM32F429xx)
	#include "stm32f4xx_hal.h"
#elif defined(STM32F767xx)
  #include "stm32f7xx_hal.h"
#endif

#include "Config.h"
#include "GlobalDefine.h"

#define ENGINENUM 8   //define the pulse engine number,in gp is 8,in gcta is 10

typedef struct{
  void (*Init) (void);
  void (*Charge) (uint16_t);
  void (*DisCharge) (uint16_t);
  void (*Control)(void);
  uint16_t ChargeNum;
  uint16_t DisChargeNum;
	uint16_t PowerCon;
}PulseCon_Func_Info;

extern PulseCon_Func_Info PulseConParm;

void PulseEngine_Init(void);
void PulseCharge(uint16_t PulseNum);
void PulseDisCharge(uint16_t PulseNum);
void PulsePowerOpen(uint16_t PowerFlag);
void PulseCon(void);


#endif


