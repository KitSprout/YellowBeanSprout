/*=====================================================================================================*/
/*=====================================================================================================*/
#include "stm32f4_system.h"
#include "stm32f4_flash.h"
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_WritePageU8
**功能 : U8 Write FLASH
**輸入 : WritePage, *WriteData, DataLen
**輸出 : None
**使用 : Flash_WritePageU8(FLASH_ADDR_SECTOR_3, WriteData, 1024);
**=====================================================================================================*/
/*=====================================================================================================*/
HAL_StatusTypeDef Flash_WritePageU8( uint32_t WriteAddr, const uint8_t *WriteData, uint32_t DataLens )
{
  HAL_StatusTypeDef status = HAL_ERROR;

  uint32_t count = 0;

  HAL_FLASH_Unlock();
  do {
    status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, WriteAddr + count, WriteData[count]);
  } while((++count < DataLens) && (status == HAL_OK));
  HAL_FLASH_Lock();

  return status;
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_WritePageU16
**功能 : U16 Write FLASH
**輸入 : WritePage, *WriteData, DataLen
**輸出 : None
**使用 : Flash_WritePageU16(FLASH_ADDR_SECTOR_3, WriteData, 512);
**=====================================================================================================*/
/*=====================================================================================================*/
HAL_StatusTypeDef Flash_WritePageU16( uint32_t WriteAddr, const uint16_t *WriteData, uint32_t DataLens )
{
  HAL_StatusTypeDef status = HAL_ERROR;

  uint32_t count = 0;

  HAL_FLASH_Unlock();
  do {
    status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, WriteAddr + (count << 1), WriteData[count]);
  } while((++count < DataLens) && (status == HAL_OK));
  HAL_FLASH_Lock();

  return status;
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_WritePageU32
**功能 : U32 Write Flash
**輸入 : WritePage, *WriteData, DataLen
**輸出 : None
**使用 : Flash_WritePageU32(FLASH_ADDR_SECTOR_3, WriteData, 256);
**=====================================================================================================*/
/*=====================================================================================================*/
HAL_StatusTypeDef Flash_WritePageU32( uint32_t WriteAddr, const uint32_t *WriteData, uint32_t DataLens )
{
  HAL_StatusTypeDef status = HAL_ERROR;

  uint32_t count = 0;

  HAL_FLASH_Unlock();
  do {
    status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, WriteAddr + (count << 2), WriteData[count]);
  } while((++count < DataLens) && (status == HAL_OK));
  HAL_FLASH_Lock();

  return status;
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_WritePageU64
**功能 : U64 Write Flash
**輸入 : WritePage, *WriteData, DataLen
**輸出 : None
**使用 : Flash_WritePageU64(FLASH_ADDR_SECTOR_3, WriteData, 128);
**=====================================================================================================*/
/*=====================================================================================================*/
//HAL_StatusTypeDef Flash_WritePageU64( uint32_t WriteAddr, const uint64_t *WriteData, uint32_t DataLens )
//{
//  HAL_StatusTypeDef status = HAL_ERROR;

//  uint32_t count = 0;

//  HAL_FLASH_Unlock();
//  do {
//    status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, WriteAddr + (count << 3), WriteData[count]);
//  } while((++count < DataLens) && (status == HAL_OK));
//  HAL_FLASH_Lock();

//  return status;
//}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_ReadPageU8
**功能 : U8 Read FLASH
**輸入 : ReadPage, *ReadData, DataLen
**輸出 : None
**使用 : Flash_ReadPageU8(FLASH_ADDR_SECTOR_3, ReadData, 1024);
**=====================================================================================================*/
/*=====================================================================================================*/
void Flash_ReadPageU8( uint32_t ReadAddr, uint8_t *ReadData, uint32_t DataLens )
{
  uint32_t count = 0;

  do {
    ReadData[count] = (uint8_t)(*(__IO uint32_t*)(ReadAddr + count));
  } while(++count < DataLens);
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_ReadPageU16
**功能 : U16 Read FLASH
**輸入 : ReadPage, *ReadData, DataLen
**輸出 : None
**使用 : Flash_ReadPageU16(FLASH_ADDR_SECTOR_3, ReadData, 512);
**=====================================================================================================*/
/*=====================================================================================================*/
void Flash_ReadPageU16( uint32_t ReadAddr, uint16_t *ReadData, uint32_t DataLens )
{
  uint32_t count = 0;

  do {
    ReadData[count] = (uint16_t)(*(__IO uint32_t*)(ReadAddr + (count << 1)));
  } while(++count < DataLens);
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_ReadPageU32
**功能 : U32 Read Flash
**輸入 : ReadPage, *ReadData, DataLen
**輸出 : None
**使用 : Flash_ReadPageU32(FLASH_ADDR_SECTOR_3, ReadData, 256);
**=====================================================================================================*/
/*=====================================================================================================*/
void Flash_ReadPageU32( uint32_t ReadAddr, uint32_t *ReadData, uint32_t DataLens )
{
  uint32_t count = 0;

  do {
    ReadData[count] = (uint32_t)(*(__IO uint32_t*)(ReadAddr + (count << 2)));
  } while(++count < DataLens);
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_ReadPageU64
**功能 : U64 Read Flash
**輸入 : ReadPage, *ReadData, DataLen
**輸出 : None
**使用 : Flash_ReadPageU64(FLASH_ADDR_SECTOR_3, ReadData, 128);
**=====================================================================================================*/
/*=====================================================================================================*/
//void Flash_ReadPageU64( uint32_t ReadAddr, uint64_t *ReadData, uint32_t DataLens )
//{
//  uint32_t count = 0;

//  do {
//    ReadData[count] = (uint64_t)(*(__IO uint32_t*)(ReadAddr + (count << 3)));
//  } while(++count < DataLens);
//}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_GetSector
**功能 : Get Sector
**輸入 : address
**輸出 : sector
**使用 : Flash_GetSector(FLASH_ADDR_SECTOR_3);
**=====================================================================================================*/
/*=====================================================================================================*/
uint32_t Flash_GetSector( uint32_t address )
{
  uint32_t sector = 0;

  if(     (address >= FLASH_ADDR_SECTOR_0) && (address < FLASH_ADDR_SECTOR_1))
    sector = FLASH_SECTOR_0;
  else if((address >= FLASH_ADDR_SECTOR_1) && (address < FLASH_ADDR_SECTOR_2))
    sector = FLASH_SECTOR_1;
  else if((address >= FLASH_ADDR_SECTOR_2) && (address < FLASH_ADDR_SECTOR_3))
    sector = FLASH_SECTOR_2;
  else if((address >= FLASH_ADDR_SECTOR_3) && (address < FLASH_ADDR_SECTOR_4))
    sector = FLASH_SECTOR_3;
  else if((address >= FLASH_ADDR_SECTOR_4) && (address < FLASH_ADDR_SECTOR_5))
    sector = FLASH_SECTOR_4;
  else if((address >= FLASH_ADDR_SECTOR_5) && (address < FLASH_ADDR_SECTOR_6))
    sector = FLASH_SECTOR_5;
  else if((address >= FLASH_ADDR_SECTOR_6) && (address < FLASH_ADDR_SECTOR_7))
    sector = FLASH_SECTOR_6;
  else /*((address >= FLASH_ADDR_SECTOR_7) && (address < FLASH_ADDR_SECTOR_END)) */
    sector = FLASH_SECTOR_7;

  return sector;
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_ErasePages
**功能 : Erase Flash Memory
**輸入 : ErasePageStart, NumPages
**輸出 : status
**使用 : Flash_ErasePages(Flash_GetSector(FLASH_ADDR_SECTOR_3), 8);
**=====================================================================================================*/
/*=====================================================================================================*/
HAL_StatusTypeDef Flash_ErasePages( uint32_t ErasePageStart, uint32_t NumSectors )
{
  FLASH_EraseInitTypeDef EraseInitStruct;
  HAL_StatusTypeDef status = HAL_ERROR;

  uint32_t SectorError = 0;

  HAL_FLASH_Unlock();
  EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
  EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
  EraseInitStruct.Sector        = ErasePageStart;
  EraseInitStruct.NbSectors     = NumSectors;
  status = HAL_FLASHEx_Erase(&EraseInitStruct, &SectorError);

  __HAL_FLASH_DATA_CACHE_DISABLE();
  __HAL_FLASH_INSTRUCTION_CACHE_DISABLE();

  __HAL_FLASH_DATA_CACHE_RESET();
  __HAL_FLASH_INSTRUCTION_CACHE_RESET();

  __HAL_FLASH_INSTRUCTION_CACHE_ENABLE();
  __HAL_FLASH_DATA_CACHE_ENABLE();

  HAL_FLASH_Lock();

  return status;
}
/*=====================================================================================================*/
/*=====================================================================================================*/
