/***************************************************************** 
*  @brief:       Data Link file, This file defined the message how to storage in ARM
*  @File:        DataLinkInit.c
*  @Project:     BMD
*  @Author:      LiuNing
*  @Date:        20180407
*  @CopyRight:   HDNT
*  @Version:     BMD.FT.3.1
*  @Description: 
*****************************************************************/
#include "DataLink.h"

Command_Info Command_Par_Info[COMMAND_NUM];
Command_Info *Current_Command_Info;
Output_Command_Info Output_Command_Par[OUTPUT_COMMAND_NUM];

void DataLink_Init(void){
  /*1.system setting command*/
  Command_Par_Info[COMMAND_SETTING].Sector      = Par_Storage_Info[PAR_SETTING].Setctor;
  Command_Par_Info[COMMAND_SETTING].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_SETTING].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_SETTING].Header[1]   = 0xAA;
  Command_Par_Info[COMMAND_SETTING].Resovle_Func= &Command_Setting_Resolve;
  Command_Par_Info[COMMAND_SETTING].id          = COMMAND_SETTING;
  Command_Par_Info[COMMAND_SETTING].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_SETTING].Storage_Func= &Storage_Setting_Par;
  Command_Par_Info[COMMAND_SETTING].FlagAdd     = Par_Storage_Info[PAR_SETTING].Start_Address+0x00;
  /*2*/
  Command_Par_Info[COMMAND_DEV_RC].Sector      = Par_Storage_Info[PAR_CALI].Setctor;
  Command_Par_Info[COMMAND_DEV_RC].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_DEV_RC].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_DEV_RC].Header[1]   = 0x11;
  Command_Par_Info[COMMAND_DEV_RC].Resovle_Func= &Command_DEV_RC_Resolve;
  Command_Par_Info[COMMAND_DEV_RC].id          = COMMAND_DEV_RC;
  Command_Par_Info[COMMAND_DEV_RC].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_DEV_RC].Storage_Func= &Storage_Cali_Par;
  Command_Par_Info[COMMAND_DEV_RC].FlagAdd     = Par_Storage_Info[PAR_CALI].Start_Address+0x00;
  /*3*/
  Command_Par_Info[COMMAND_DEV_TN].Sector   = Par_Storage_Info[PAR_CALI].Setctor;
  Command_Par_Info[COMMAND_DEV_TN].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_DEV_TN].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_DEV_TN].Header[1]   = 0x12;
  Command_Par_Info[COMMAND_DEV_TN].Resovle_Func= &Command_DEV_TN_Resolve;
  Command_Par_Info[COMMAND_DEV_TN].id          = COMMAND_DEV_TN;
  Command_Par_Info[COMMAND_DEV_TN].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_DEV_TN].Storage_Func= &Storage_Cali_Par;
  Command_Par_Info[COMMAND_DEV_TN].FlagAdd     = Par_Storage_Info[PAR_CALI].Start_Address+0x02;
  /*4*/
  Command_Par_Info[COMMAND_DEV_SF].Sector   = Par_Storage_Info[PAR_CALI].Setctor;
  Command_Par_Info[COMMAND_DEV_SF].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_DEV_SF].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_DEV_SF].Header[1]   = 0x13;
  Command_Par_Info[COMMAND_DEV_SF].Resovle_Func= &Command_DEV_SF_Resolve;
  Command_Par_Info[COMMAND_DEV_SF].id          = COMMAND_DEV_SF;
  Command_Par_Info[COMMAND_DEV_SF].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_DEV_SF].Storage_Func= &Storage_Cali_Par;
  Command_Par_Info[COMMAND_DEV_SF].FlagAdd     = Par_Storage_Info[PAR_CALI].Start_Address+0x04;
  /*5*/
  Command_Par_Info[COMMAND_DEV_CR].Sector   = Par_Storage_Info[PAR_CALI].Setctor;
  Command_Par_Info[COMMAND_DEV_CR].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_DEV_CR].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_DEV_CR].Header[1]   = 0x14;
  Command_Par_Info[COMMAND_DEV_CR].Resovle_Func= &Command_DEV_CR_Resolve;
  Command_Par_Info[COMMAND_DEV_CR].id          = COMMAND_DEV_CR;
  Command_Par_Info[COMMAND_DEV_CR].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_DEV_CR].Storage_Func= &Storage_Cali_Par;
  Command_Par_Info[COMMAND_DEV_CR].FlagAdd     = Par_Storage_Info[PAR_CALI].Start_Address+0x06;
  /*6*/
  Command_Par_Info[COMMAND_DEV_TSF].Sector   = Par_Storage_Info[PAR_CALI].Setctor;
  Command_Par_Info[COMMAND_DEV_TSF].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_DEV_TSF].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_DEV_TSF].Header[1]   = 0x15;
  Command_Par_Info[COMMAND_DEV_TSF].Resovle_Func= &Command_DEV_TSF_Resolve;
  Command_Par_Info[COMMAND_DEV_TSF].id          = COMMAND_DEV_TSF;
  Command_Par_Info[COMMAND_DEV_TSF].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_DEV_TSF].Storage_Func= &Storage_Cali_Par;
  Command_Par_Info[COMMAND_DEV_TSF].FlagAdd     = Par_Storage_Info[PAR_CALI].Start_Address+0x08;
  /*7*/
  Command_Par_Info[COMMAND_DEV_GA].Sector   = Par_Storage_Info[PAR_CALI].Setctor;
  Command_Par_Info[COMMAND_DEV_GA].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_DEV_GA].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_DEV_GA].Header[1]   = 0x16;
  Command_Par_Info[COMMAND_DEV_GA].Resovle_Func= &Command_DEV_GA_Resolve;
  Command_Par_Info[COMMAND_DEV_GA].id          = COMMAND_DEV_GA;
  Command_Par_Info[COMMAND_DEV_GA].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_DEV_GA].Storage_Func= &Storage_Cali_Par;
  Command_Par_Info[COMMAND_DEV_GA].FlagAdd     = Par_Storage_Info[PAR_CALI].Start_Address+0x0A;
  /*8*/
  Command_Par_Info[COMMAND_DEV_PAR].Sector   = Par_Storage_Info[PAR_CALI].Setctor;
  Command_Par_Info[COMMAND_DEV_PAR].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_DEV_PAR].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_DEV_PAR].Header[1]   = 0x17;
  Command_Par_Info[COMMAND_DEV_PAR].Resovle_Func= &Command_DEV_PAR_Resolve;
  Command_Par_Info[COMMAND_DEV_PAR].id          = COMMAND_DEV_PAR;
  Command_Par_Info[COMMAND_DEV_PAR].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_DEV_PAR].Storage_Func = &Storage_Cali_Par;
  Command_Par_Info[COMMAND_DEV_PAR].FlagAdd      = Par_Storage_Info[PAR_CALI].Start_Address+0x0C;
  /*9*/
  Command_Par_Info[COMMAND_FIL_CH1].Sector   = Par_Storage_Info[PAR_DEV].Setctor;
  Command_Par_Info[COMMAND_FIL_CH1].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_FIL_CH1].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_FIL_CH1].Header[1]   = 0x20;
  Command_Par_Info[COMMAND_FIL_CH1].Resovle_Func= &Command_FIR_CH1_Resolve;
  Command_Par_Info[COMMAND_FIL_CH1].id          = COMMAND_FIL_CH1;
  Command_Par_Info[COMMAND_FIL_CH1].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_FIL_CH1].Storage_Func = &Storage_Dev_Par;
  Command_Par_Info[COMMAND_FIL_CH1].FlagAdd      = Par_Storage_Info[PAR_DEV].Start_Address+0x00;
  /*10*/
  Command_Par_Info[COMMAND_FIL_CH2].Sector   = Par_Storage_Info[PAR_DEV].Setctor;
  Command_Par_Info[COMMAND_FIL_CH2].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_FIL_CH2].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_FIL_CH2].Header[1]   = 0x21;
  Command_Par_Info[COMMAND_FIL_CH2].Resovle_Func= &Command_FIR_CH2_Resolve;
  Command_Par_Info[COMMAND_FIL_CH2].id          = COMMAND_FIL_CH2;
  Command_Par_Info[COMMAND_FIL_CH2].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_FIL_CH2].Storage_Func = &Storage_Dev_Par;
  Command_Par_Info[COMMAND_FIL_CH2].FlagAdd      = Par_Storage_Info[PAR_DEV].Start_Address+0x02;
  /*11*/
  Command_Par_Info[COMMAND_FIL_CH3].Sector   = Par_Storage_Info[PAR_DEV].Setctor;
  Command_Par_Info[COMMAND_FIL_CH3].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_FIL_CH3].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_FIL_CH3].Header[1]   = 0x22;
  Command_Par_Info[COMMAND_FIL_CH3].Resovle_Func= &Command_FIR_CH3_Resolve;
  Command_Par_Info[COMMAND_FIL_CH3].id          = COMMAND_FIL_CH3;
  Command_Par_Info[COMMAND_FIL_CH3].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_FIL_CH3].Storage_Func = &Storage_Dev_Par;
  Command_Par_Info[COMMAND_FIL_CH3].FlagAdd      = Par_Storage_Info[PAR_DEV].Start_Address+0x04;
  /*12*/
  Command_Par_Info[COMMAND_FIL_CH4].Sector   = Par_Storage_Info[PAR_DEV].Setctor;
  Command_Par_Info[COMMAND_FIL_CH4].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_FIL_CH4].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_FIL_CH4].Header[1]   = 0x23;
  Command_Par_Info[COMMAND_FIL_CH4].Resovle_Func= &Command_FIR_CH4_Resolve;
  Command_Par_Info[COMMAND_FIL_CH4].id          = COMMAND_FIL_CH4;
  Command_Par_Info[COMMAND_FIL_CH4].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_FIL_CH4].Storage_Func = &Storage_Dev_Par;
  Command_Par_Info[COMMAND_FIL_CH4].FlagAdd      = Par_Storage_Info[PAR_DEV].Start_Address+0x06;
  /*13*/
  Command_Par_Info[COMMAND_FIL_CH5].Sector   = Par_Storage_Info[PAR_DEV].Setctor;
  Command_Par_Info[COMMAND_FIL_CH5].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_FIL_CH5].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_FIL_CH5].Header[1]   = 0x24;
  Command_Par_Info[COMMAND_FIL_CH5].Resovle_Func= &Command_FIR_CH5_Resolve;
  Command_Par_Info[COMMAND_FIL_CH5].id          = COMMAND_FIL_CH5;
  Command_Par_Info[COMMAND_FIL_CH5].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_FIL_CH5].Storage_Func = &Storage_Dev_Par;
  Command_Par_Info[COMMAND_FIL_CH5].FlagAdd      = Par_Storage_Info[PAR_DEV].Start_Address+0x08;
  /*14*/
  Command_Par_Info[COMMAND_FIL_CH6].Sector   = Par_Storage_Info[PAR_DEV].Setctor;
  Command_Par_Info[COMMAND_FIL_CH6].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_FIL_CH6].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_FIL_CH6].Header[1]   = 0x25;
  Command_Par_Info[COMMAND_FIL_CH6].Resovle_Func= &Command_FIR_CH6_Resolve;
  Command_Par_Info[COMMAND_FIL_CH6].id          = COMMAND_FIL_CH6;
  Command_Par_Info[COMMAND_FIL_CH6].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_FIL_CH6].Storage_Func = &Storage_Dev_Par;
  Command_Par_Info[COMMAND_FIL_CH6].FlagAdd      = Par_Storage_Info[PAR_DEV].Start_Address+0x0A;
  /*15*/
  Command_Par_Info[COMMAND_FIL_CH7].Sector   = Par_Storage_Info[PAR_DEV].Setctor;
  Command_Par_Info[COMMAND_FIL_CH7].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_FIL_CH7].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_FIL_CH7].Header[1]   = 0x26;
  Command_Par_Info[COMMAND_FIL_CH7].Resovle_Func= &Command_FIR_CH7_Resolve;
  Command_Par_Info[COMMAND_FIL_CH7].id          = COMMAND_FIL_CH7;
  Command_Par_Info[COMMAND_FIL_CH7].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_FIL_CH7].Storage_Func = &Storage_Dev_Par;
  Command_Par_Info[COMMAND_FIL_CH7].FlagAdd      = Par_Storage_Info[PAR_DEV].Start_Address+0x0C;
  /*16*/
  Command_Par_Info[COMMAND_FIL_CH8].Sector   = Par_Storage_Info[PAR_DEV].Setctor;
  Command_Par_Info[COMMAND_FIL_CH8].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_FIL_CH8].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_FIL_CH8].Header[1]   = 0x27;
  Command_Par_Info[COMMAND_FIL_CH8].Resovle_Func= &Command_FIR_CH8_Resolve;
  Command_Par_Info[COMMAND_FIL_CH8].id          = COMMAND_FIL_CH8;
  Command_Par_Info[COMMAND_FIL_CH8].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_FIL_CH8].Storage_Func = &Storage_Dev_Par;
  Command_Par_Info[COMMAND_FIL_CH8].FlagAdd      = Par_Storage_Info[PAR_DEV].Start_Address+0x0E;
  /*17*/
  Command_Par_Info[COMMAND_FIL_CH9].Sector   = Par_Storage_Info[PAR_DEV].Setctor;
  Command_Par_Info[COMMAND_FIL_CH9].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_FIL_CH9].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_FIL_CH9].Header[1]   = 0x28;
  Command_Par_Info[COMMAND_FIL_CH9].Resovle_Func= &Command_FIR_CH9_Resolve;
  Command_Par_Info[COMMAND_FIL_CH9].id          = COMMAND_FIL_CH9;
  Command_Par_Info[COMMAND_FIL_CH9].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_FIL_CH9].Storage_Func = &Storage_Dev_Par;
  Command_Par_Info[COMMAND_FIL_CH9].FlagAdd      = Par_Storage_Info[PAR_DEV].Start_Address+0x10;
  /*18*/
  Command_Par_Info[COMMAND_FIL_CH10].Sector   = Par_Storage_Info[PAR_DEV].Setctor;
  Command_Par_Info[COMMAND_FIL_CH10].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_FIL_CH10].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_FIL_CH10].Header[1]   = 0x29;
  Command_Par_Info[COMMAND_FIL_CH10].Resovle_Func= &Command_FIR_CH10_Resolve;
  Command_Par_Info[COMMAND_FIL_CH10].id          = COMMAND_FIL_CH10;
  Command_Par_Info[COMMAND_FIL_CH10].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_FIL_CH10].Storage_Func = &Storage_Dev_Par;
  Command_Par_Info[COMMAND_FIL_CH10].FlagAdd      = Par_Storage_Info[PAR_DEV].Start_Address+0x12;
  /*19*/
  Command_Par_Info[COMMAND_FIL_CH11].Sector   = Par_Storage_Info[PAR_DEV].Setctor;
  Command_Par_Info[COMMAND_FIL_CH11].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_FIL_CH11].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_FIL_CH11].Header[1]   = 0x2A;
  Command_Par_Info[COMMAND_FIL_CH11].Resovle_Func= &Command_FIR_CH11_Resolve;
  Command_Par_Info[COMMAND_FIL_CH11].id          = COMMAND_FIL_CH11;
  Command_Par_Info[COMMAND_FIL_CH11].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_FIL_CH11].Storage_Func = &Storage_Dev_Par;
  Command_Par_Info[COMMAND_FIL_CH11].FlagAdd      = Par_Storage_Info[PAR_DEV].Start_Address+0x14;
  /*20*/
  Command_Par_Info[COMMAND_FIL_CH12].Sector   = Par_Storage_Info[PAR_DEV].Setctor;
  Command_Par_Info[COMMAND_FIL_CH12].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_FIL_CH12].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_FIL_CH12].Header[1]   = 0x2B;
  Command_Par_Info[COMMAND_FIL_CH12].Resovle_Func= &Command_FIR_CH12_Resolve;
  Command_Par_Info[COMMAND_FIL_CH12].id          = COMMAND_FIL_CH12;
  Command_Par_Info[COMMAND_FIL_CH12].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_FIL_CH12].Storage_Func = &Storage_Dev_Par;
  Command_Par_Info[COMMAND_FIL_CH12].FlagAdd      = Par_Storage_Info[PAR_DEV].Start_Address+0x16;
  /*21*/
  Command_Par_Info[COMMAND_FIL_CH13].Sector   = Par_Storage_Info[PAR_DEV].Setctor;
  Command_Par_Info[COMMAND_FIL_CH13].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_FIL_CH13].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_FIL_CH13].Header[1]   = 0x2C;
  Command_Par_Info[COMMAND_FIL_CH13].Resovle_Func= &Command_FIR_CH13_Resolve;
  Command_Par_Info[COMMAND_FIL_CH13].id          = COMMAND_FIL_CH13;
  Command_Par_Info[COMMAND_FIL_CH13].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_FIL_CH13].Storage_Func = &Storage_Dev_Par;
  Command_Par_Info[COMMAND_FIL_CH13].FlagAdd      = Par_Storage_Info[PAR_DEV].Start_Address+0x18;
  /*22*/
  Command_Par_Info[COMMAND_FIL_CH14].Sector   = Par_Storage_Info[PAR_DEV].Setctor;
  Command_Par_Info[COMMAND_FIL_CH14].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_FIL_CH14].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_FIL_CH14].Header[1]   = 0x2D;
  Command_Par_Info[COMMAND_FIL_CH14].Resovle_Func= &Command_FIR_CH14_Resolve;
  Command_Par_Info[COMMAND_FIL_CH14].id          = COMMAND_FIL_CH14;
  Command_Par_Info[COMMAND_FIL_CH14].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_FIL_CH14].Storage_Func = &Storage_Dev_Par;
  Command_Par_Info[COMMAND_FIL_CH14].FlagAdd      = Par_Storage_Info[PAR_DEV].Start_Address+0x1A;
  /*23*/
  Command_Par_Info[COMMAND_FIL_CH15].Sector   = Par_Storage_Info[PAR_DEV].Setctor;
  Command_Par_Info[COMMAND_FIL_CH15].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_FIL_CH15].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_FIL_CH15].Header[1]   = 0x2E;
  Command_Par_Info[COMMAND_FIL_CH15].Resovle_Func= &Command_FIR_CH15_Resolve;
  Command_Par_Info[COMMAND_FIL_CH15].id          = COMMAND_FIL_CH15;
  Command_Par_Info[COMMAND_FIL_CH15].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_FIL_CH15].Storage_Func = &Storage_Dev_Par;
  Command_Par_Info[COMMAND_FIL_CH15].FlagAdd      = Par_Storage_Info[PAR_DEV].Start_Address+0x1C;
  /*24*/
  Command_Par_Info[COMMAND_KALMAN].Sector   = Par_Storage_Info[PAR_CALI].Setctor;
  Command_Par_Info[COMMAND_KALMAN].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_KALMAN].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_KALMAN].Header[1]   = 0x2F;
  Command_Par_Info[COMMAND_KALMAN].Resovle_Func= &Command_Kalman_Resolve;
  Command_Par_Info[COMMAND_KALMAN].id          = COMMAND_KALMAN;
  Command_Par_Info[COMMAND_KALMAN].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_KALMAN].Storage_Func = &Storage_Dev_Par;
  Command_Par_Info[COMMAND_KALMAN].FlagAdd      = Par_Storage_Info[PAR_DEV].Start_Address+0x1E;
  /*25*/
  Command_Par_Info[COMMAND_DEVCON].Sector   = Par_Storage_Info[PAR_USER].Setctor;
  Command_Par_Info[COMMAND_DEVCON].StorageFlag = Data_Storage_Flash;//Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_DEVCON].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_DEVCON].Header[1]   = 0x30;
  Command_Par_Info[COMMAND_DEVCON].Resovle_Func= &Command_DevCon_Resolve;
  Command_Par_Info[COMMAND_DEVCON].id          = COMMAND_DEVCON;
  Command_Par_Info[COMMAND_DEVCON].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_DEVCON].Storage_Func = &Storage_User_Par;
  Command_Par_Info[COMMAND_DEVCON].FlagAdd      = Par_Storage_Info[PAR_USER].Start_Address+0x00;
  /*26*/
  Command_Par_Info[COMMAND_USER].Sector      = Par_Storage_Info[PAR_USER].Setctor;
  Command_Par_Info[COMMAND_USER].StorageFlag = Data_Storage_RAM;   //see Data_Type_Info
  Command_Par_Info[COMMAND_USER].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_USER].Header[1]   = 0x31;
  Command_Par_Info[COMMAND_USER].Resovle_Func= &Command_User_Resolve;
  Command_Par_Info[COMMAND_USER].id          = COMMAND_USER;
  Command_Par_Info[COMMAND_USER].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_USER].Storage_Func = &Storage_User_Par;
  Command_Par_Info[COMMAND_USER].FlagAdd      = Par_Storage_Info[PAR_USER].Start_Address+0x02;
  /*27*/
  Command_Par_Info[COMMAND_RES].Sector      = Par_Storage_Info[PAR_RES].Setctor;
  Command_Par_Info[COMMAND_RES].StorageFlag = Data_Storage_Flash;//Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_RES].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_RES].Header[1]   = 0x60;
  Command_Par_Info[COMMAND_RES].Resovle_Func= &Command_Res_Resolve;
  Command_Par_Info[COMMAND_RES].id          = COMMAND_USER;
  Command_Par_Info[COMMAND_RES].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_RES].Storage_Func = &Storage_Res_Par;
  Command_Par_Info[COMMAND_RES].FlagAdd      = Par_Storage_Info[PAR_RES].Start_Address+0x00;
  /*28*/
  Command_Par_Info[COMMAND_RES1].Sector      = Par_Storage_Info[PAR_RES].Setctor;
  Command_Par_Info[COMMAND_RES1].StorageFlag = Data_Storage_Flash;   //see Data_Type_Info
  Command_Par_Info[COMMAND_RES1].Header[0]   = 0x55;
  Command_Par_Info[COMMAND_RES1].Header[1]   = 0x61;
  Command_Par_Info[COMMAND_RES1].Resovle_Func= &Command_Res1_Resolve;
  Command_Par_Info[COMMAND_RES1].id          = COMMAND_USER;
  Command_Par_Info[COMMAND_RES1].Ask_Flag    = Ask_Valid;
  Command_Par_Info[COMMAND_RES1].Storage_Func = &Storage_Res_Par;
  Command_Par_Info[COMMAND_RES1].FlagAdd      = Par_Storage_Info[PAR_RES].Start_Address+0x02;
  /*29*/
  Command_Par_Info[COMMAND_IQL_STATUS].StorageFlag= Data_Storage_RAM;
  Command_Par_Info[COMMAND_IQL_STATUS].Header[0] = 0x55;
  Command_Par_Info[COMMAND_IQL_STATUS].Header[1] = 0xC2;
  Command_Par_Info[COMMAND_IQL_STATUS].Resovle_Func= &Command_Iqiure_Status_Resolve;
  Command_Par_Info[COMMAND_IQL_STATUS].id          = COMMAND_IQL_STATUS;
  Command_Par_Info[COMMAND_IQL_STATUS].Ask_Flag    = Ask_InValid;
  /*30*/
  Command_Par_Info[COMMAND_IQL_CALI].StorageFlag= Data_Storage_RAM;
  Command_Par_Info[COMMAND_IQL_CALI].Header[0] = 0x55;
  Command_Par_Info[COMMAND_IQL_CALI].Header[1] = 0xC1;
  Command_Par_Info[COMMAND_IQL_CALI].Resovle_Func= &Command_Iqiure_CALI_Resolve;
  Command_Par_Info[COMMAND_IQL_CALI].id          = COMMAND_IQL_STATUS;
  Command_Par_Info[COMMAND_IQL_CALI].Ask_Flag    = Ask_InValid;
  /*31*/
  Command_Par_Info[COMMAND_FLASH_OP].StorageFlag= Data_Storage_RAM;
  Command_Par_Info[COMMAND_FLASH_OP].Header[0] = 0x77;
  Command_Par_Info[COMMAND_FLASH_OP].Header[1] = 0x11;
  Command_Par_Info[COMMAND_FLASH_OP].Resovle_Func= &Command_Flash_Resolve;
  Command_Par_Info[COMMAND_FLASH_OP].id          = COMMAND_FLASH_OP;
  Command_Par_Info[COMMAND_FLASH_OP].Ask_Flag    = Ask_Valid;
  /*32*/
  Command_Par_Info[COMMAND_ALLIGN].StorageFlag = Data_Storage_RAM;
  Command_Par_Info[COMMAND_ALLIGN].Header[0] = 0x55;
  Command_Par_Info[COMMAND_ALLIGN].Header[1] = 0x41;
  Command_Par_Info[COMMAND_ALLIGN].Resovle_Func= &Command_Allign_Resolve;
  Command_Par_Info[COMMAND_ALLIGN].id          = COMMAND_ALLIGN;
  Command_Par_Info[COMMAND_ALLIGN].Ask_Flag    = Ask_InValid;
  /*33*/
  Command_Par_Info[COMMAND_COMMU].StorageFlag = Data_Storage_RAM;
  Command_Par_Info[COMMAND_COMMU].Header[0] = 0x55;
  Command_Par_Info[COMMAND_COMMU].Header[1] = 0x81;
  Command_Par_Info[COMMAND_COMMU].Resovle_Func= &Command_Commu_Resovle;
  Command_Par_Info[COMMAND_COMMU].id          = COMMAND_COMMU;
  Command_Par_Info[COMMAND_COMMU].Ask_Flag    = Ask_InValid;
  
  Output_Command_Par[REP_COMMAND].Header[0]=0XAA;Output_Command_Par[REP_COMMAND].Header[1]=0XAA;
  Output_Command_Par[REP_COMMAND_CALI].Header[0]=0X55;Output_Command_Par[REP_COMMAND_CALI].Header[1]=0XC1;
  Output_Command_Par[REP_COMMAND_STATUS].Header[0]=0X55;Output_Command_Par[REP_COMMAND_STATUS].Header[1]=0XC2;
  
  Output_Command_Par[REP_OUTPUT].Header[0]=0X55;Output_Command_Par[REP_OUTPUT].Header[1]=0XAA;

  
}



