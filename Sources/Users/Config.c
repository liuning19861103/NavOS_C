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
/***************************************************************** 
*  @brief:          
*  @Function: 
*  @inparam:
*  @outparam:  
*  @Author:       
*  @Date:         
*  @CopyRight:
*  @Version:     
*  @Description:
*****************************************************************/
void System_Init(void){

  delay_init(200);
  Sensor_Read_Init();
  System_Work_Info.Product_ID=YEAR;
  
  /*Open the set comm that is connect to pc or dl*/
	HAL_UART_Receive_DMA(&huart1,Uart_Control[USART1_ID].RX_Buffer,1);
//  HAL_UART_Receive_IT(&huart1,Uart_Control[USART1_ID].RX_Buffer,1);
//  __HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);
  
  /*Open the FPGA*/
	HAL_Delay(40); 
  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);    
  
  HAL_Delay(20);  
  HAL_GPIO_WritePin(GPIOG,GPIO_PIN_4,GPIO_PIN_SET);   //RESET
  HAL_GPIO_WritePin(GPIOG,GPIO_PIN_3,GPIO_PIN_RESET); //WR
  HAL_Delay(1);  
  HAL_GPIO_WritePin(GPIOG,GPIO_PIN_4,GPIO_PIN_RESET);
  HAL_Delay(1);  
  HAL_GPIO_WritePin(GPIOG,GPIO_PIN_3,GPIO_PIN_SET);  
	
  
  HAL_TIM_Base_Start_IT(&htim3);
  HAL_TIM_Base_Start(&htim5);
  HAL_TIM_Base_Start_IT(&htim6); 
}

