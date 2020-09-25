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
#include "GNSSSolve.h"
/*-----------------------Variable Define-----------------------------*/
GNSSAdvace GNSSAdvInfo;
GNSS GNSSInfo;
Mes_Info GNSS_Mes;

GNSS_Func_Info GNSS_Func_Par={&GNSSSolve_Init,&GPS_ISR,&GPS_Resolve};

void GNSSSolve_Init(void){
  GNSS_Mes.Flag=false;  
}

