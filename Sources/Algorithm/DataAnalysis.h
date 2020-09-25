/**/
#ifndef __DATAANALYSIS_H
#define __DATAANALYSIS_H
#if defined(STM_RUN)
  #if defined(STM32F429xx)
    #include "stm32f4xx_hal.h"
  #elif defined(STM32F767xx)
    #include "stm32f7xx_hal.h"
	#elif defined(STM32H753xx)
    #include "stm32h7xx_hal.h"
  #endif
#elif defined(VS_SIM)
  
#endif

#include "PlatformCon.h"

#endif

