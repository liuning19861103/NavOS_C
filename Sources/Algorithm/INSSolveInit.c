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

#include "INSSolve.h"


void INS_Load_Data(void){

  INS_Sensor_Par[Gyro].data[GyroX] = Dev_Sol_Info[DEV_GX].Out_Data*ATR;
  INS_Sensor_Par[Gyro].data[GyroY] = Dev_Sol_Info[DEV_GY].Out_Data*ATR;
  INS_Sensor_Par[Gyro].data[GyroZ] = Dev_Sol_Info[DEV_GZ].Out_Data*ATR;

  INS_Sensor_Par[Acc].data[AccX] = Dev_Sol_Info[DEV_AX].Out_Data;
  INS_Sensor_Par[Acc].data[AccY] = Dev_Sol_Info[DEV_AY].Out_Data;
  INS_Sensor_Par[Acc].data[AccZ] = Dev_Sol_Info[DEV_AZ].Out_Data;

  INS_Sensor_Par[Mag].data[MagX] = Dev_Sol_Info[DEV_MX].Out_Data;
  INS_Sensor_Par[Mag].data[MagY] = Dev_Sol_Info[DEV_MY].Out_Data;
  INS_Sensor_Par[Mag].data[MagZ] = Dev_Sol_Info[DEV_MZ].Out_Data;
}

void INSSolve_Init(void){
  INS_Cal_Par.BufferSize = 10;
  INS_Nav_Par.AlignData  = Command_Par_Info[COMMAND_ALLIGN].Buffer;

}
void INS_Cal(void){
	INS_Nav_Par.AttResol(Bika, 2,
	                     INS_Sensor_Par[Gyro].data, INS_Cal_Par.dt, INS_Nav_Par.Q, INS_Nav_Par.Cbn, INS_Nav_Par.Att);
	INS_Nav_Par.VelResol(INS_Nav_Par.Cbn, INS_Sensor_Par[Acc].data, INS_Nav_Par.Vel, INS_Cal_Par.dt);
	INS_Nav_Par.PosResol(INS_Nav_Par.Vel, INS_Nav_Par.Pos, INS_Cal_Par.dt);
}
