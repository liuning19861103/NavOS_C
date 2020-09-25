/**/
#include "PDRsolve.h"

void PDRSolve_Init(void){
	PDR_Set_Par.Mode = 0;
}

void PDR_Cal(void){
	Kalman_Cal_Func.StateCal(INS_Sensor_Par[Gyro].data, INS_Sensor_Par[Acc].data);
	Kalman_Cal_Func.TimeUpdate();
	PDR_Cal_Func.Detector();
	if (PDR_Set_Par.Zupt == true){
		Kalman_Cal_Func.MeasureUpdate();
		Kalman_Cal_Func.StateUpdate();
	}
}

