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
#include "PulseEngine.h"

PulseCon_Func_Info PulseConParm={&PulseEngine_Init,&PulseCharge,&PulseDisCharge,&PulseCon,0,0,0};

void PulseEngine_Init(void){
  PulseConParm.ChargeNum=0;
  PulseConParm.DisChargeNum=0;
  
}
void PulseCon(void){
  PulseCharge(PulseConParm.ChargeNum);
  PulseDisCharge(PulseConParm.DisChargeNum);
	PulsePowerOpen(PulseConParm.PowerCon);
}


