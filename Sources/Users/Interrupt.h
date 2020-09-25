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
#ifndef __INTTERUPT_H
#define __INTTERUPT_H

#if defined(STM32F429xx)
	#include "stm32f4xx_hal.h"
#elif defined(STM32F767xx)
  #include "stm32f7xx_hal.h"
#elif defined(STM32F401xE)
  #include "stm32f4xx_hal.h"
#endif
#include "usart.h"
#include "tim.h"
#include "Config.h"
#include "DataLink.h"
#include "GNSSSolve.h"
#include "GlobalDefine.h"

void ISR_Usart1_Rx_Task(void);    //usart1 receive interrupt task
void ISR_Usart1_Tx_Task(void);//usart1 transmit interrupt task
void ISR_Usart2_Rx_Task(void);
void ISR_Usart2_Tx_Task(void);
void ISR_Tim3_Task(void);
void ISR_Tim6_Task(void);
void IDLE_Usart1_Rx_Task(void);  //idle task of usart1 receive
void IDLE_Usart2_Rx_Task(void);  //idle task of usart1 receive
void ISR_EXIT8_Task(void);


#endif


