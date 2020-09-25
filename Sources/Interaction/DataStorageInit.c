/***************************************************************** 
*  @brief:       this file will storage the key parameter to the flash of device includes: setting, calibration
                 users and other key parameter.
*  @File:        DataStorage.c  
*  @Project:      
*  @Author:      Liu Ning
*  @Date:        170613 
*  @CopyRight:    
*  @Version:     V1.0
*  @Description: storage key parameter
                 the total parameter's section will divide to 5 part:
                 1: Software code
                 2: Setting parameter     
                 3: Calibration parameter
                 4: Dev setting parameter
                 5: reserve parameter
*****************************************************************/
#include "DataStorage.h"

Flash_Info Par_Storage_Info[PAR_SECTOR_NUM];
/***************************************************************** 
*  @brief:     storage address initial this function must run in the first positon.
*  @File:      
*  @Project:   
*  @Author:    
*  @Date:      
*  @CopyRight:
*  @Version:     
*  @Description:
*****************************************************************/
void DataStorage_Init(void){
  /*define the setting parameter sector address*/
  Par_Storage_Info[PAR_SETTING].Setctor = FLASH_SECTOR_7;
  Par_Storage_Info[PAR_SETTING].Start_Address = ADDR_FLASH_SECTOR_7;
  Par_Storage_Info[PAR_SETTING].CommandNum    = 1;

  /*define the calibration parameter and filter parameter sector address*/
  Par_Storage_Info[PAR_CALI].Setctor =   FLASH_SECTOR_8;
  Par_Storage_Info[PAR_CALI].Start_Address   = ADDR_FLASH_SECTOR_8;
  Par_Storage_Info[PAR_CALI].CommandNum      = 7;

  /*define the extern device parameter sector address*/
  Par_Storage_Info[PAR_DEV].Setctor = FLASH_SECTOR_9;
  Par_Storage_Info[PAR_DEV].Start_Address   = ADDR_FLASH_SECTOR_9;
  Par_Storage_Info[PAR_DEV].CommandNum      = 16;

  /*define the user parameter sector address*/
  Par_Storage_Info[PAR_USER].Setctor = FLASH_SECTOR_10;
  Par_Storage_Info[PAR_USER].Start_Address   = ADDR_FLASH_SECTOR_10;
  Par_Storage_Info[PAR_USER].CommandNum      = 1;

  /*define the reserve parameter sector address*/
  Par_Storage_Info[PAR_RES].Setctor = FLASH_SECTOR_11;
  Par_Storage_Info[PAR_RES].Start_Address   = ADDR_FLASH_SECTOR_11;
  Par_Storage_Info[PAR_RES].CommandNum      = 2;
}

void Datastorage_Read(void){
  /*Read the parameter from FLASH*/
  Read_Setting_Par();
  Read_Cali_Par();
  Read_Dev_Par();
  Read_User_Par();
  Read_Res_Par();
} 

