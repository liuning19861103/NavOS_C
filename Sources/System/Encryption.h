/***************************************************************** 
*  @brief:         HardWare Encryption 
*  @File:          
*  @Project:     
*  @Author:      
*  @Date:         
*  @CopyRight:
*  @Version:     
*  @Description:
*****************************************************************/
#ifndef __ENCRYPTION_H__
#define __ENCRYPTION_H__

#if defined(STM32F429xx)
  #include "stm32f4xx_hal.h"
#elif defined(STM32F767xx)
  #include "stm32f7xx_hal.h"
#elif defined(STM32H753xx)
  #include "stm32h7xx_hal.h"
#endif

typedef struct{
  uint32_t MCUID0;
}Enc_Par;

extern Enc_Par Enc_Par_Info;

#endif


