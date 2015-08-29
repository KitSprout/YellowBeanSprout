/* #include "stm32f4_flash.h" */

#ifndef __STM32F4_FLASH_H
#define __STM32F4_FLASH_H

#include "stm32f4xx_hal.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
#define FLASH_ADDR_SECTOR_0   ((uint32_t)0x08000000) // Sector 0,   16 Kbytes,   16 KBytes
#define FLASH_ADDR_SECTOR_1   ((uint32_t)0x08004000) // Sector 1,   16 Kbytes,   32 KBytes
#define FLASH_ADDR_SECTOR_2   ((uint32_t)0x08008000) // Sector 2,   16 Kbytes,   48 KBytes
#define FLASH_ADDR_SECTOR_3   ((uint32_t)0x0800C000) // Sector 3,   16 Kbytes,   64 KBytes
#define FLASH_ADDR_SECTOR_4   ((uint32_t)0x08010000) // Sector 4,   64 Kbytes,  128 KBytes
#define FLASH_ADDR_SECTOR_5   ((uint32_t)0x08020000) // Sector 5,  128 Kbytes,  256 KBytes
#define FLASH_ADDR_SECTOR_6   ((uint32_t)0x08040000) // Sector 6,  128 Kbytes,  384 KBytes
#define FLASH_ADDR_SECTOR_7   ((uint32_t)0x08060000) // Sector 7,  128 Kbytes,  512 KBytes
/*=====================================================================================================*/
/*=====================================================================================================*/
HAL_StatusTypeDef Flash_WritePageU8(  uint32_t WriteAddr, const uint8_t  *WriteData, uint32_t DataLens );
HAL_StatusTypeDef Flash_WritePageU16( uint32_t WriteAddr, const uint16_t *WriteData, uint32_t DataLens );
HAL_StatusTypeDef Flash_WritePageU32( uint32_t WriteAddr, const uint32_t *WriteData, uint32_t DataLens );
//HAL_StatusTypeDef Flash_WritePageU64( uint32_t WriteAddr, const uint64_t *WriteData, uint32_t DataLens );
void              Flash_ReadPageU8(  uint32_t ReadAddr, uint8_t  *ReadData, uint32_t DataLens );
void              Flash_ReadPageU16( uint32_t ReadAddr, uint16_t *ReadData, uint32_t DataLens );
void              Flash_ReadPageU32( uint32_t ReadAddr, uint32_t *ReadData, uint32_t DataLens );
//void              Flash_ReadPageU64( uint32_t ReadAddr, uint64_t *ReadData, uint32_t DataLens );
uint32_t          Flash_GetSector( uint32_t address );
HAL_StatusTypeDef Flash_ErasePages( uint32_t ErasePageStart, uint32_t NumPages );
/*=====================================================================================================*/
/*=====================================================================================================*/
#endif	 
