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
#include "MagDataAnalysis.h"

Mag_Func_Info Mag_Func_Par={&MagDataAnalysisInit,&USERData_Update,&Time_Detector};


void USERData_Update(void){
	Mag_Coe.Coe_A[0][0]=MagCal_Par.BufferData[0];
	Mag_Coe.Coe_A[0][1]=MagCal_Par.BufferData[1];
	Mag_Coe.Coe_A[0][2]=MagCal_Par.BufferData[2];
	Mag_Coe.Coe_A[1][0]=MagCal_Par.BufferData[3];
  Mag_Coe.Coe_A[1][1]=MagCal_Par.BufferData[4];
  Mag_Coe.Coe_A[1][2]=MagCal_Par.BufferData[5];
  Mag_Coe.Coe_A[2][0]=MagCal_Par.BufferData[6];
  Mag_Coe.Coe_A[2][1]=MagCal_Par.BufferData[7];
  Mag_Coe.Coe_A[2][2]=MagCal_Par.BufferData[8];
	
	Mag_Coe.Coe_K[0]=MagCal_Par.BufferData[9];
	Mag_Coe.Coe_K[1]=MagCal_Par.BufferData[10];
	
	Mag_Coe.Coe_B[0][0]=MagCal_Par.BufferData[11];
	Mag_Coe.Coe_B[0][1]=MagCal_Par.BufferData[12];
	Mag_Coe.Coe_B[0][2]=MagCal_Par.BufferData[13];
	Mag_Coe.Coe_B[1][0]=MagCal_Par.BufferData[14];
	Mag_Coe.Coe_B[1][1]=MagCal_Par.BufferData[15];
	Mag_Coe.Coe_B[1][2]=MagCal_Par.BufferData[16];	
  Mag_Coe.Coe_B[2][0]=MagCal_Par.BufferData[17];
	Mag_Coe.Coe_B[2][1]=MagCal_Par.BufferData[18];
	Mag_Coe.Coe_B[2][2]=MagCal_Par.BufferData[19];
	
	Mag_Coe.Coe_C[0][0]=MagCal_Par.BufferData[20];
	Mag_Coe.Coe_C[0][1]=MagCal_Par.BufferData[21];
	Mag_Coe.Coe_C[0][2]=MagCal_Par.BufferData[22];
	Mag_Coe.Coe_C[1][0]=MagCal_Par.BufferData[23];
	Mag_Coe.Coe_C[1][1]=MagCal_Par.BufferData[24];
	Mag_Coe.Coe_C[1][2]=MagCal_Par.BufferData[25];		
  Mag_Coe.Coe_C[2][0]=MagCal_Par.BufferData[26];
	Mag_Coe.Coe_C[2][1]=MagCal_Par.BufferData[27];
	Mag_Coe.Coe_C[2][2]=MagCal_Par.BufferData[28];	
	
	Mag_Coe.Tre[0]     =MagCal_Par.BufferData[29];   //a0
	Mag_Coe.Tre[1]     =MagCal_Par.BufferData[30];   //a1
	Mag_Coe.Tre[2]     =MagCal_Par.BufferData[31];   //time
	Mag_Coe.Tre[3]     =MagCal_Par.BufferData[43];   //ay1
	Mag_Coe.Tre[4]     =MagCal_Par.BufferData[44];   //az1
	
	Mag_Coe.Mx_Theory  =MagCal_Par.BufferData[32];
	Mag_Coe.My_Theory  =MagCal_Par.BufferData[33];
  Mag_Coe.Mz_Theory  =MagCal_Par.BufferData[34];
	Mag_Coe.Auto_Time  =MagCal_Par.BufferData[35];
	Mag_Coe.Pulse_Num  =MagCal_Par.BufferData[36];
	Mag_Coe.Set_Time   =MagCal_Par.BufferData[37];
	Mag_Coe.Reset_Time =MagCal_Par.BufferData[38];
	
	MagUpdatNum        =(uint16_t)MagCal_Par.BufferData[39];  //xÖáyÖá×Ô¶¯ÐÞÕý´ÎÊý
  MagSlopeNum        =(uint16_t)MagCal_Par.BufferData[40];
  MagSlopeTre        =(uint16_t)MagCal_Par.BufferData[41];
	
	ADSampleSetNum     =(uint16_t)(1/(MagCal_Par.BufferData[42]*1000.0f)/(20E-6f));
	if(ADSampleSetNum==0) ADSampleSetNum=1;

}

void MagDataAnalysisInit(void){


}

