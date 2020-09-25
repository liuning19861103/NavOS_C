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
#include "Config.h"

Uart_Info Uart_Control[UART_NUM];

Timer_Info Tim_Control[TIM_NUM];

uint32_t USART1_BaudRate=921600;
uint32_t USART2_BaudRate=9600;

void Config_Init(void){
  
  Uart_Control[USART1_ID].RX_Size=1024;
  Uart_Control[USART1_ID].Init.BaudRate      = (uint32_t)Dev_Set_Info.Output_Baud;
  Uart_Control[USART1_ID].Rx_ISR_Func        = &ISR_Usart1_Rx_Task;
  Uart_Control[USART1_ID].Tx_ISR_Func        = &ISR_Usart1_Tx_Task;
  Uart_Control[USART1_ID].IDLE_Rx_ISR_Func   = &IDLE_Usart1_Rx_Task;
  Uart_Control[USART1_ID].Transmit_Over_Flag = DMA_SendOver;
  Uart_Control[USART1_ID].RX_Tx_Flag         = 0;
  /*set the usart baud rate*/
  USART1_BaudRate                            = Uart_Control[USART1_ID].Init.BaudRate;
  
  Uart_Control[USART2_ID].RX_Size=1;
  Uart_Control[USART2_ID].Init.BaudRate      = 115200;
  Uart_Control[USART2_ID].Rx_ISR_Func        = &ISR_Usart2_Rx_Task;
  Uart_Control[USART2_ID].Tx_ISR_Func        = &ISR_Usart2_Tx_Task;
  Uart_Control[USART2_ID].IDLE_Rx_ISR_Func   = &IDLE_Usart2_Rx_Task;
  Uart_Control[USART2_ID].Transmit_Over_Flag = DMA_SendOver;

  USART2_BaudRate                            = Uart_Control[USART2_ID].Init.BaudRate;
  
  Tim_Control[TIM3_ID].Init.Init.Period      = (uint32_t)1;
  Tim_Control[TIM3_ID].Init.Init.Prescaler   = (uint32_t)1;
  Tim_Control[TIM3_ID].ISR_Func              = &ISR_Tim3_Task;   //set the interrupt function of timer1
  
  Tim_Control[TIM6_ID].Init.Init.Period      = (uint32_t)1;
  Tim_Control[TIM6_ID].Init.Init.Prescaler   = (uint32_t)1;
  Tim_Control[TIM6_ID].ISR_Func              = &ISR_Tim6_Task;  //set the interrupt function of timer6

}


