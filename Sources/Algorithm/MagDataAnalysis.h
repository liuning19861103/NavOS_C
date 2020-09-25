/***************************************************************** 
*  @brief:      this file to calculate the mag data includes zero time and value
*  @File:       MagDataAnalysis.h
*  @Project:    
*  @Author:     Liu Ning
*  @Date:       180405
*  @CopyRight:
*  @Version:    V1.0
*  @Description:
*****************************************************************/
#ifndef __MAGDATAANALYSIS_H
#define __MAGDATAANALYSIS_H

#if defined(STM32F429xx)
	#include "stm32f4xx_hal.h"
#elif defined(STM32F767xx)
  #include "stm32f7xx_hal.h"
#elif defined(STM32F401xE)
  #include "stm32f4xx_hal.h"
#elif defined(STM32H753xx)
  #include "stm32h7xx_hal.h"
#endif
#include "GlobalDefine.h"

#define MAGX 0
#define MAGY 1
#define MAGS 2
#define MAGZ 3


#define MAG_NUM 4  //µØ´ÅÍ¨µÀÊý
#define MAG_REC_NUM 50  //Êý¾ÝµÝÍÆÊý
#define MAG_STORE_NUM 5 //²É¼¯Êý¾ÝµãÊý
typedef struct 
{
	float32_t Data[MAG_NUM];  //ÁãÎ»
	float32_t Data1[MAG_NUM];
	float32_t PData[MAG_NUM][MAG_REC_NUM]; 
	float32_t PData1[MAG_NUM][MAG_REC_NUM];
  float32_t Storage_Data[MAG_NUM][MAG_REC_NUM];   //Êý¾Ý´æ´¢¿Õ¼ä
	float32_t Slope[MAG_NUM][MAG_REC_NUM];          //Ð±ÂÊ´æ´¢
	float32_t Maxim[MAG_NUM][2];      //×î´óÖµ
	float32_t Max_Flag[MAG_NUM];
	float32_t Minimum[MAG_NUM][2];    //×îÐ¡Öµ
	float32_t Min_Flag[MAG_NUM];
	float32_t Average[MAG_NUM];    //Æ½¾ùÖµ   
	float32_t Zero_Time[MAG_NUM][3];  //¹ýÁãÊ±¼ä
	float32_t Sample_Time[MAG_NUM];
	float32_t Mag_Tre_Value[MAG_NUM];
	float32_t Mag_Err[MAG_NUM];
	float32_t Zero_Data[MAG_NUM][8];
	float32_t Sum_Bias[MAG_NUM];     //¼ÆËãÆ«ÖµÊ±ÓÃµ½µÄºÍ
	uint32_t Num[MAG_NUM];
	float32_t Bias[MAG_NUM];
	float32_t Mx_Bias_Sum;
	float32_t My_SF;
	float32_t My_SF_Sum;
	float32_t Mz_SF;
	float32_t Mz_SF_Sum;
	float32_t PreHalfValue[MAG_NUM];   //¼ÆËãÇ°°ë¶Î·ûºÅÖµ
	float32_t AftHalfValue[MAG_NUM];   //¼ÆËãºó°ë¶Î·ûºÅÖµ
	float32_t SlopeSign[MAG_REC_NUM];
}Zero_Solve;
extern Zero_Solve Mag_Solve; 

#define MAG_COE_A_NUM 3
#define MAG_COE_K_NUM 2
#define MAG_COE_C_NUM 3
#define MAG_COE_B_NUM 3
#define MAG_COE_NUM   3
typedef struct
{
	float32_t Coe_A[MAG_COE_A_NUM][MAG_COE_NUM];
	float32_t Coe_K[MAG_COE_K_NUM];
	float32_t Coe_C[MAG_COE_C_NUM][MAG_COE_NUM];
	float32_t Coe_B[MAG_COE_B_NUM][MAG_COE_NUM];
	float32_t Tre[5];
	float32_t Mx_Theory;   //x¼ÆËãÊ±µÄÀíÂÛÖµ
	float32_t My_Theory;   //y¼ÆËãÊ±µÄÀíÂÛÖµ
	float32_t Mz_Theory;
	float32_t Auto_Time;   //×Ô¶¯¼ÆËãÁãÎ»¿ªÊ¼Ê±¼ä
	float32_t Pulse_Num;   //¸´Î»Âö³å¸öÊý
	float32_t Set_Time;     //¸ßµçÆ½Ê±¼ä£¬µ¥Î»ms
	float32_t Reset_Time;   //µÍµçÆ½Ê±¼ä£¬µ¥Î»ms
}Mag_Cali;
extern Mag_Cali Mag_Coe;

typedef struct{
  float32_t *BufferData;
}Mag_Cal_Info;

extern Mag_Cal_Info MagCal_Par;

extern uint8_t Auto_Bias_Flag,Mannual_Bias_Flag;  //Auto Caculation Switch
extern uint8_t Auto_Bias_Flag_Pre,Auto_Bias_Flag_Pre2;
extern uint8_t Magy_SF_Flag;
extern uint8_t Magx_BIAS_Flag;
extern uint32_t Magx_BIAS_Count,Magy_SF_Count; //y Axis and x Axis Caculate number
extern float32_t MX_Input_Bias,MY_Input_Bias,MY_Input_SF;
extern float32_t MySfBig;
extern uint8_t Magz_SF_Flag;
extern uint32_t Magz_SF_Count; //y Axis and x Axis Caculate number
extern float32_t MZ_Input_Bias,MZ_Input_SF;
extern float32_t MzSfBig;

extern uint16_t MagSlopeNum;  //slope buffer number
extern uint16_t MagSlopeTre;  //slope tre value
extern uint16_t MagUpdatNum;

extern uint16_t ADSampleSetNum;  //AD sample point number, the pc set is Hz
extern uint16_t ADSampleNum;     //AD sample count number
extern uint8_t MagSolveFlag;

typedef struct{
  void (*Init) (void);
  void (*DataUpdate) (void);
  void (*TimeDet) (void);
}Mag_Func_Info;

extern Mag_Func_Info Mag_Func_Par;

void Time_Detector(void);
void My_Solve(void);
void Mx_Solve(void);
void Ms_Solve(void);
void Mz_Solve(void);
void MagDataAnalysisInit(void);
void USERData_Update(void);

#endif

