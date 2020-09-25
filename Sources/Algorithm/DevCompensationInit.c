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
#include "DevCompensation.h"
/*-------------------------Global Parameters Defined---------------------------*/

Dev_Info Dev_Sol_Info[DEV_NUM]={{0,0,0,0,0,0,0,0,0,{0},0,true,0},
                                {0,0,0,0,0,0,0,0,0,{0},0,true,0},
                                {0,0,0,0,0,0,0,0,0,{0},0,true,0},
                                {0,0,0,0,0,0,0,0,0,{0},0,true,0},
                                {0,0,0,0,0,0,0,0,0,{0},0,true,0},
                                {0,0,0,0,0,0,0,0,0,{0},0,true,0},
                                {0,0,0,0,0,0,0,0,0,{0},0,true,0},
                                {0,0,0,0,0,0,0,0,0,{0},0,true,0},
                                {0,0,0,0,0,0,0,0,0,{0},0,true,0},
                                {0,0,0,0,0,0,0,0,0,{0},0,true,0},
                                {0,0,0,0,0,0,0,0,0,{0},0,true,0},
                                {0,0,0,0,0,0,0,0,0,{0},0,true,0}};

Error_Info Dev_Err_Info;

FIR_Info Fir_Par[FIR_CHNUM];

/*set the cross coefficient*/
const uint8_t CR_Coe[DEV_NUM][CR_NUM]={{DEV_GY,DEV_GZ},{DEV_GX,DEV_GZ},{DEV_GX,DEV_GY},
                                       {DEV_AY,DEV_AZ},{DEV_AX,DEV_AZ},{DEV_AX,DEV_AY},
                                       {DEV_MY,DEV_MZ},{DEV_MX,DEV_MZ},{DEV_MX,DEV_MY},
                                       {DEV_AY2,DEV_AZ2},{DEV_AX2,DEV_AZ2},{DEV_AX2,DEV_AY2}
  };

void Load_Dev_Data(void){

  Dev_Sol_Info[DEV_AX].Raw_Data = Sensor_Original_Info.AD_DATA[AX1_ADC_CH];
  Dev_Sol_Info[DEV_AY].Raw_Data = Sensor_Original_Info.AD_DATA[AY1_ADC_CH];
  Dev_Sol_Info[DEV_AZ].Raw_Data = Sensor_Original_Info.AD_DATA[AZ1_ADC_CH];

  Dev_Sol_Info[DEV_MX].Raw_Data = 65535-Sensor_Original_Info.AD_DATA[MX_ADC_CH];
  Dev_Sol_Info[DEV_MY].Raw_Data = 65535-Sensor_Original_Info.AD_DATA[MY_ADC_CH];
  Dev_Sol_Info[DEV_MZ].Raw_Data = 65535-Sensor_Original_Info.AD_DATA[MZ_ADC_CH];

  Dev_Sol_Info[DEV_GX].Raw_Data = Sensor_Original_Info.AD_DATA[GX_ADC_CH];
  Dev_Sol_Info[DEV_GY].Raw_Data = Sensor_Original_Info.AD_DATA[GY_ADC_CH];
  Dev_Sol_Info[DEV_GZ].Raw_Data = Sensor_Original_Info.AD_DATA[GZ_ADC_CH];
  
  Dev_Sol_Info[DEV_AX2].Raw_Data = Sensor_Original_Info.AD_DATA[AX2_ADC_CH];
  Dev_Sol_Info[DEV_AY2].Raw_Data = Sensor_Original_Info.AD_DATA[AY2_ADC_CH];
  Dev_Sol_Info[DEV_AZ2].Raw_Data = Sensor_Original_Info.AD_DATA[AZ2_ADC_CH];

  /*load the temperature value*/

  Dev_Sol_Info[DEV_AX].Temp_Data = Sensor_Original_Info.AD_DATA[TEMP_ADC_CH]*(-0.00545f)+185.2842f;
  Dev_Sol_Info[DEV_AY].Temp_Data = Sensor_Original_Info.AD_DATA[TEMP_ADC_CH]*(-0.00545f)+185.2842f;
  Dev_Sol_Info[DEV_AZ].Temp_Data = Sensor_Original_Info.AD_DATA[TEMP_ADC_CH]*(-0.00545f)+185.2842f;
  
  Dev_Sol_Info[DEV_AX2].Temp_Data = Sensor_Original_Info.AD_DATA[TEMP_ADC_CH]*(-0.00545f)+185.2842f;
  Dev_Sol_Info[DEV_AY2].Temp_Data = Sensor_Original_Info.AD_DATA[TEMP_ADC_CH]*(-0.00545f)+185.2842f;
  Dev_Sol_Info[DEV_AZ2].Temp_Data = Sensor_Original_Info.AD_DATA[TEMP_ADC_CH]*(-0.00545f)+185.2842f;
  
  Dev_Sol_Info[DEV_MX].Temp_Data = Sensor_Original_Info.AD_DATA[TEMP_ADC_CH]*(-0.00545f)+185.2842f;
  Dev_Sol_Info[DEV_MY].Temp_Data = Sensor_Original_Info.AD_DATA[TEMP_ADC_CH]*(-0.00545f)+185.2842f;
  Dev_Sol_Info[DEV_MZ].Temp_Data = Sensor_Original_Info.AD_DATA[TEMP_ADC_CH]*(-0.00545f)+185.2842f;
  
  Dev_Sol_Info[DEV_GX].Temp_Data = Sensor_Original_Info.AD_DATA[GXT_ADC_CH]*0.0085f-235;
  Dev_Sol_Info[DEV_GY].Temp_Data = Sensor_Original_Info.AD_DATA[GYT_ADC_CH]*0.0085f-235;
  Dev_Sol_Info[DEV_GZ].Temp_Data = Sensor_Original_Info.AD_DATA[GZT_ADC_CH]*0.0085f-235;

  
}


void DevCompensation_Init(void){
  uint16_t i=0;

  Dev_Err_Info.RC_Data  = Command_Par_Info[COMMAND_DEV_RC].Buffer;
  Dev_Err_Info.SF_Data  = Command_Par_Info[COMMAND_DEV_SF].Buffer;
  Dev_Err_Info.TN_Data  = Command_Par_Info[COMMAND_DEV_TN].Buffer;
  Dev_Err_Info.CR_Data  = Command_Par_Info[COMMAND_DEV_CR].Buffer;
  Dev_Err_Info.TSF_Data = Command_Par_Info[COMMAND_DEV_TSF].Buffer;
  Dev_Err_Info.GA_Data  = Command_Par_Info[COMMAND_DEV_GA].Buffer;
  Dev_Err_Info.PAR_Data = Command_Par_Info[COMMAND_DEV_PAR].Buffer;

  for(i=0;i<FIR_CHNUM;i++){
    Fir_Par[i].Coe      = Command_Par_Info[i+COMMAND_FIL_CH1].Buffer;
  }

  
}

