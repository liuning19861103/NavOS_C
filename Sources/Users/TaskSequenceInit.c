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
#include "TaskSequence.h"

Task_Func_Info Task_Functions[TASK_NUM];

void TaskSequence_Init(void){
  /**/
  Task_Functions[TASK_SENSOR_READ].id           = TASK_SENSOR_READ;
  Task_Functions[TASK_SENSOR_READ].StateType    = Task_Over;
  Task_Functions[TASK_SENSOR_READ].func_p       = Sensor_Original_Info.updata_func;
  Task_Functions[TASK_SENSOR_READ].RunType      = TaskRunInCondition;
	Task_Functions[TASK_SENSOR_READ].Priority     = TaskRunNow;

  Task_Functions[TASK_DEV_CALI].id         = TASK_DEV_CALI;
  Task_Functions[TASK_DEV_CALI].StateType = Task_Over;
  Task_Functions[TASK_DEV_CALI].func_p     = &Dev_Compensation;
  Task_Functions[TASK_DEV_CALI].RunType    = TaskRunInCondition;
  Task_Functions[TASK_DEV_CALI].Priority     = TaskRunInLine;
	
  Task_Functions[TASK_TRANSMIT_DATA].id         = TASK_TRANSMIT_DATA;
  Task_Functions[TASK_TRANSMIT_DATA].StateType  = Task_Over;
  Task_Functions[TASK_TRANSMIT_DATA].func_p     = &Transmit_Data_To_PC; 
  Task_Functions[TASK_TRANSMIT_DATA].RunType    = TaskRunInCondition;
  Task_Functions[TASK_TRANSMIT_DATA].Priority     = TaskRunNow;
	
  Task_Functions[TASK_COMMAND_RESOLVE].id        = TASK_COMMAND_RESOLVE;
  Task_Functions[TASK_COMMAND_RESOLVE].StateType= Task_Over;
  Task_Functions[TASK_COMMAND_RESOLVE].func_p    = &Command_Resolve;
  Task_Functions[TASK_COMMAND_RESOLVE].RunType   = TaskRunInCondition;
  Task_Functions[TASK_COMMAND_RESOLVE].Priority     = TaskRunInLine;

  Task_Functions[TASK_COMMAND_SEND].id          = TASK_COMMAND_SEND;
  Task_Functions[TASK_COMMAND_SEND].StateType   = Task_Over;
  Task_Functions[TASK_COMMAND_SEND].func_p      = &Transmit_Ask_To_PC;
  Task_Functions[TASK_COMMAND_SEND].RunType      = TaskRunInCondition;
  Task_Functions[TASK_COMMAND_SEND].Priority     = TaskRunInLine;

  Task_Functions[TASK_INS_INIT].id             = TASK_INS_INIT;
  Task_Functions[TASK_INS_INIT].StateType      = Task_Ready;
  Task_Functions[TASK_INS_INIT].func_p         = INS_Nav_Par.Init;
  Task_Functions[TASK_INS_INIT].RunType        = TaskRunOnceTime;
  Task_Functions[TASK_INS_INIT].Priority       = TaskRunInLine;

  Task_Functions[TASK_MATRIX_INIT].id             = TASK_MATRIX_INIT;
  Task_Functions[TASK_MATRIX_INIT].StateType      = Task_Ready;
  Task_Functions[TASK_MATRIX_INIT].func_p         = Mat_Cal_Info.Init;
  Task_Functions[TASK_MATRIX_INIT].RunType        = TaskRunOnceTime;
  Task_Functions[TASK_MATRIX_INIT].Priority       = TaskRunInLine;

  Task_Functions[TASK_KALMAN_INIT].id             = TASK_KALMAN_INIT;
  Task_Functions[TASK_KALMAN_INIT].StateType      = Task_Ready;
  Task_Functions[TASK_KALMAN_INIT].func_p         = Kalman_Cal_Func.Init;
  Task_Functions[TASK_KALMAN_INIT].RunType        = TaskRunOnceTime;
  Task_Functions[TASK_KALMAN_INIT].Priority       = TaskRunInLine;
 
//  Task_Functions[TASK_PDR_INIT].id             = TASK_PDR_INIT;
//  Task_Functions[TASK_PDR_INIT].StateType      = Task_Ready;
//  Task_Functions[TASK_PDR_INIT].func_p         = PDR_Cal_Func.Init;
//  Task_Functions[TASK_PDR_INIT].RunType        = TaskRunOnceTime;
//	Task_Functions[TASK_PDR_INIT].Priority       = TaskRunInLine;

  Task_Functions[TASK_ALIGN].id             = TASK_ALIGN;
  Task_Functions[TASK_ALIGN].StateType      = Task_Over;
  Task_Functions[TASK_ALIGN].func_p         = INS_Nav_Par.StaAlign;
  Task_Functions[TASK_ALIGN].RunType        = TaskRunInCondition;
	Task_Functions[TASK_ALIGN].Priority       = TaskRunInLine;

  Task_Functions[TASK_INS_LOAD_DATA].id             = TASK_INS_LOAD_DATA;
  Task_Functions[TASK_INS_LOAD_DATA].StateType      = Task_Over;
  Task_Functions[TASK_INS_LOAD_DATA].func_p         = INS_Nav_Par.LoadData;
  Task_Functions[TASK_INS_LOAD_DATA].RunType        = TaskRunInCondition;
	Task_Functions[TASK_INS_LOAD_DATA].Priority       = TaskRunInLine;

  Task_Functions[TASK_INS_BUFFER_DATA].id             = TASK_INS_BUFFER_DATA;
  Task_Functions[TASK_INS_BUFFER_DATA].StateType      = Task_Over;
  Task_Functions[TASK_INS_BUFFER_DATA].func_p         = INS_Nav_Par.BufferData;
  Task_Functions[TASK_INS_BUFFER_DATA].RunType        = TaskRunInCondition;
	Task_Functions[TASK_INS_BUFFER_DATA].Priority       = TaskRunInLine;

  Task_Functions[TASK_INS_CAL].id             = TASK_INS_CAL;
  Task_Functions[TASK_INS_CAL].StateType      = Task_Over;
  Task_Functions[TASK_INS_CAL].func_p         = INS_Nav_Par.INS_Cal;
  Task_Functions[TASK_INS_CAL].RunType        = TaskRunInCondition;
  Task_Functions[TASK_INS_CAL].Priority       = TaskRunInLine;	

  Task_Functions[TASK_PDR_CAL].id             = TASK_PDR_CAL;
  Task_Functions[TASK_PDR_CAL].StateType      = Task_Over;
  Task_Functions[TASK_PDR_CAL].func_p         = PDR_Cal_Func.Solve;
  Task_Functions[TASK_PDR_CAL].RunType        = TaskRunInCondition;
	Task_Functions[TASK_PDR_CAL].Priority       = TaskRunInLine;
  
  Task_Functions[TASK_POWER_CON].id             = TASK_POWER_CON;
  Task_Functions[TASK_POWER_CON].StateType      = Task_Over;
  Task_Functions[TASK_POWER_CON].func_p         = ExtCon_Func.PowSwitch;
  Task_Functions[TASK_POWER_CON].RunType        = TaskRunForever;
	Task_Functions[TASK_POWER_CON].Priority       = TaskRunInLine;

  Task_Functions[TASK_MAG_RESET].id             = TASK_MAG_RESET;
  Task_Functions[TASK_MAG_RESET].StateType      = Task_Over;
  Task_Functions[TASK_MAG_RESET].func_p         = ExtCon_Func.MagSetReset;
  Task_Functions[TASK_MAG_RESET].RunType        = TaskRunForever;
  Task_Functions[TASK_MAG_RESET].Priority       = TaskRunInLine;

  Task_Functions[TASK_FIRE_DET].id              = TASK_FIRE_DET;
  Task_Functions[TASK_FIRE_DET].StateType       = Task_Over;
  Task_Functions[TASK_FIRE_DET].func_p          = ExtCon_Func.DetectFire;
  Task_Functions[TASK_FIRE_DET].RunType         = TaskRunForever;
  Task_Functions[TASK_FIRE_DET].Priority        = TaskRunInLine;
	
  Task_Functions[TASK_GPS_RES].id              = TASK_GPS_RES;
  Task_Functions[TASK_GPS_RES].StateType       = Task_Over;
  Task_Functions[TASK_GPS_RES].func_p          = GNSS_Func_Par.Res;
  Task_Functions[TASK_GPS_RES].RunType         = TaskRunInCondition;
  Task_Functions[TASK_GPS_RES].Priority        = TaskRunInLine;	
	
  Task_Functions[TASK_GPS_INIT].id              = TASK_GPS_INIT;
  Task_Functions[TASK_GPS_INIT].StateType       = Task_Ready;
  Task_Functions[TASK_GPS_INIT].func_p          = GNSS_Func_Par.Init;
  Task_Functions[TASK_GPS_INIT].RunType         = TaskRunOnceTime;
  Task_Functions[TASK_GPS_INIT].Priority        = TaskRunInLine;		

  Task_Functions[TASK_MAG_INIT].id              = TASK_MAG_INIT;
  Task_Functions[TASK_MAG_INIT].StateType       = Task_Ready;
  Task_Functions[TASK_MAG_INIT].func_p          = Mag_Func_Par.Init;
  Task_Functions[TASK_MAG_INIT].RunType         = TaskRunOnceTime;
  Task_Functions[TASK_MAG_INIT].Priority        = TaskRunInLine;

  Task_Functions[TASK_MAG_SOL].id              = TASK_MAG_SOL;
  Task_Functions[TASK_MAG_SOL].StateType       = Task_Ready;
  Task_Functions[TASK_MAG_SOL].func_p          = Mag_Func_Par.TimeDet;
  Task_Functions[TASK_MAG_SOL].RunType         = TaskRunInCondition;
  Task_Functions[TASK_MAG_SOL].Priority        = TaskRunInLine;

  Task_Functions[TASK_PULSE_CON].id              = TASK_PULSE_CON;
  Task_Functions[TASK_PULSE_CON].StateType       = Task_Ready;
  Task_Functions[TASK_PULSE_CON].func_p          = PulseConParm.Control;
  Task_Functions[TASK_PULSE_CON].RunType         = TaskRunInCondition;
  Task_Functions[TASK_PULSE_CON].Priority        = TaskRunOnceTime;
	
	Task_Functions[TASK_BAS_MAG_READ].id         = TASK_BAS_MAG_READ;
	Task_Functions[TASK_BAS_MAG_READ].StateType  = Task_Ready;
  Task_Functions[TASK_BAS_MAG_READ].func_p     = &BasReadMag;
  Task_Functions[TASK_BAS_MAG_READ].RunType    = TaskRunInCondition;
  Task_Functions[TASK_BAS_MAG_READ].Priority   = TaskRunInLine;	
	
	Task_Functions[TASK_BAS_GNSS_READ].id         = TASK_BAS_GNSS_READ;
	Task_Functions[TASK_BAS_GNSS_READ].StateType  = Task_Ready;
  Task_Functions[TASK_BAS_GNSS_READ].func_p     = &BasReadGNSS;
  Task_Functions[TASK_BAS_GNSS_READ].RunType    = TaskRunInCondition;
  Task_Functions[TASK_BAS_GNSS_READ].Priority   = TaskRunInLine;	
	
	Task_Functions[TASK_BAS_COM_SEND].id         = TASK_BAS_COM_SEND;
	Task_Functions[TASK_BAS_COM_SEND].StateType  = Task_Ready;
  Task_Functions[TASK_BAS_COM_SEND].func_p     = &BasComSend;
  Task_Functions[TASK_BAS_COM_SEND].RunType    = TaskRunInCondition;
  Task_Functions[TASK_BAS_COM_SEND].Priority   = TaskRunInLine;	
	
	Task_Functions[TASK_BAS_CTRL].id         = TASK_BAS_CTRL;
	Task_Functions[TASK_BAS_CTRL].StateType  = Task_Suspend;
  Task_Functions[TASK_BAS_CTRL].func_p     = &BasCtrl;
  Task_Functions[TASK_BAS_CTRL].RunType    = TaskRunForever;
  Task_Functions[TASK_BAS_CTRL].Priority   = TaskRunInLine;	
	
		
	Task_Functions[TASK_BAS_INIT].id         = TASK_BAS_INIT;
	Task_Functions[TASK_BAS_INIT].StateType  = Task_Ready;
  Task_Functions[TASK_BAS_INIT].func_p     = &BasInit;
  Task_Functions[TASK_BAS_INIT].RunType    = TaskRunOnceTime;
  Task_Functions[TASK_BAS_INIT].Priority   = TaskRunInLine;	


//  Task_Seque_Par.Create(TASK_INS_INIT);
//  Task_Seque_Par.Create(TASK_MATRIX_INIT);
//  Task_Seque_Par.Create(TASK_KALMAN_INIT);
//  Task_Seque_Par.Create(TASK_PDR_INIT);
	
	Task_Seque_Par.Create(TASK_GPS_INIT);
  Task_Seque_Par.Create(TASK_MAG_INIT);
  
  Task_Seque_Par.Create(TASK_SENSOR_READ);
  Task_Seque_Par.Create(TASK_DEV_CALI);
//  Task_Seque_Par.Create(TASK_INS_LOAD_DATA);
//  Task_Seque_Par.Create(TASK_INS_BUFFER_DATA);
//  Task_Seque_Par.Create(TASK_ALIGN);
//  Task_Seque_Par.Create(TASK_INS_CAL);
//  Task_Seque_Par.Create(TASK_PDR_CAL);
  Task_Seque_Par.Create(TASK_COMMAND_RESOLVE);
  Task_Seque_Par.Create(TASK_TRANSMIT_DATA);

  Task_Seque_Par.Create(TASK_POWER_CON);
  Task_Seque_Par.Create(TASK_MAG_RESET);
  Task_Seque_Par.Create(TASK_FIRE_DET);
	
	Task_Seque_Par.Create(TASK_GPS_RES);
	Task_Seque_Par.Create(TASK_MAG_SOL);
	Task_Seque_Par.Create(TASK_PULSE_CON);
	
	Task_Seque_Par.Create(TASK_BAS_COM_SEND);
	Task_Seque_Par.Create(TASK_BAS_CTRL );
	Task_Seque_Par.Create(TASK_BAS_GNSS_READ);
	Task_Seque_Par.Create(TASK_BAS_MAG_READ);
	Task_Seque_Par.Create(TASK_BAS_INIT);

//  Task_Seque_Par.Activate(TASK_INS_INIT);
//  Task_Seque_Par.Activate(TASK_MATRIX_INIT);
//  Task_Seque_Par.Activate(TASK_KALMAN_INIT);
//  Task_Seque_Par.Activate(TASK_PDR_INIT);
  Task_Seque_Par.Activate(TASK_GPS_INIT);
  Task_Seque_Par.Activate(TASK_MAG_INIT);

  Task_Seque_Par.Activate(TASK_POWER_CON);
  Task_Seque_Par.Activate(TASK_MAG_RESET);
  Task_Seque_Par.Activate(TASK_FIRE_DET);
	
  Task_Seque_Par.Activate(TASK_BAS_INIT);
  

}

