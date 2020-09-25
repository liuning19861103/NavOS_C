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
#include "Interrupt.h"

void Interrupt_Init(void){
  
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim){

  if(htim == (&htim3)){
    Tim_Control[TIM3_ID].ISR_Func();
  }else if(htim ==(&htim6)){
    Tim_Control[TIM6_ID].ISR_Func();
  }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef * huart){
  if(huart == (&huart1)){
    __HAL_DMA_DISABLE(huart->hdmatx);  
    Uart_Control[USART1_ID].Transmit_Over_Flag = DMA_SendOver;
    Uart_Control[USART1_ID].RX_Tx_Flag     =0;
  }else if(huart ==(&huart2)){
    __HAL_DMA_DISABLE(huart->hdmatx);  
    Uart_Control[USART2_ID].Transmit_Over_Flag = DMA_SendOver;    
  }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef * huart){
  if(huart == (&huart1)){
    ISR_Usart1_Rx_Task();
  }else if(huart ==(&huart2)){
    ISR_Usart2_Rx_Task();
  }
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
  if(GPIO_Pin == GPIO_PIN_8){
    ISR_EXIT8_Task();
  }
}
