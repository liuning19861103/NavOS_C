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
#include "ExtDevCon.h"

ExtCon_Func_Info ExtCon_Func={&ExtDevCon_Init,&ExtDevCon_Data_Update,&ExtDevCon_Power,&ExtDevCon_Mag,&ExtDevCon_DetectFire};


void ExtDevCon_Init(void){
  MagCal_Par.BufferData = Command_Par_Info[COMMAND_DEVCON].Buffer;
  ExtDev_Par.BufferData = Command_Par_Info[COMMAND_USER].Buffer;
  
  ExtDev_Par.PowerOpenFlag = false;
  ExtDev_Par.ResetFlag     = true;
  ExtDev_Par.PulseCount    = 0;
  ExtDev_Par.PowerOpenTime = 0;
  ExtDev_Par.ResetTime     = 0;
//  Command_Par_Info[COMMAND_USER].Type= PowerCon;
}
/***************************************************************** 
*  @brief:      
*  @Function:    ExtDevCon_Data_Update(void)
*  @inparam:     
*  @outparam:  
*  @Author:       
*  @Date:        180422
*  @CopyRight:
*  @Version:     
*  @Description:
*****************************************************************/
void ExtDevCon_Data_Update(void){
  switch(Command_Par_Info[COMMAND_USER].Type){   //select the message type
    case MagResetPar:{
       Mag_Coe.Set_Time   = ExtDev_Par.BufferData[0];
       Mag_Coe.Reset_Time = ExtDev_Par.BufferData[1];
       Mag_Coe.Pulse_Num  = ExtDev_Par.BufferData[2];
       ExtDev_Par.ResetFlag = true;
    break;}
    case MagAutoCal:{
       if(ExtDev_Par.BufferData[0]==0){  //close the auto calibration
         Auto_Bias_Flag = false;
         Magy_SF_Flag   = false;
         Magx_BIAS_Flag = false;
       }else if(ExtDev_Par.BufferData[0]==1){//open the auto calibration
         Auto_Bias_Flag = true;
         Magy_SF_Flag   = true;
         Magx_BIAS_Flag = true;
         Mag_Solve.Max_Flag[1]=0;
       }else{                            //open the auto calibration and open the reset
         ExtDev_Par.ResetFlag = true;
         Auto_Bias_Flag_Pre=true;
         Magy_SF_Flag=true;
         Magx_BIAS_Flag=true;
         Mag_Solve.Max_Flag[1]=0;   //MAGY
       }
    break;}
    case MagManualCal:{    //open the mannual calibration
        MX_Input_Bias  = ExtDev_Par.BufferData[0];
        MY_Input_Bias  = ExtDev_Par.BufferData[1];
        MY_Input_SF    = ExtDev_Par.BufferData[2];
        MZ_Input_Bias  = ExtDev_Par.BufferData[3];
        MZ_Input_SF    = ExtDev_Par.BufferData[4];
        Mannual_Bias_Flag=true;
    break;}
    case PowerCon:{
       if(ExtDev_Par.BufferData[0]==0){
         ExtDev_Par.PowerOpenFlag = false;  //close the power
       }else{
         ExtDev_Par.PowerOpenFlag = true;   //open the power
       }
    break;}
    case DHCon:{
       PulseConParm.ChargeNum    = (uint16_t)ExtDev_Par.BufferData[0];
       PulseConParm.DisChargeNum = (uint16_t)ExtDev_Par.BufferData[1];
			 PulseConParm.PowerCon     = (uint16_t)ExtDev_Par.BufferData[2];
       Task_Seque_Par.Activate(TASK_PULSE_CON);
    break;}
    default:
      break;
    }
    
}


