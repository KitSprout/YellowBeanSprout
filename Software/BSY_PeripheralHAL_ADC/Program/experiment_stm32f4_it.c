/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\stm32f4_system.h"
/*====================================================================================================*/
/*====================================================================================================*/
void NMI_Handler( void ) { while(1); }
void HardFault_Handler( void ) { while(1); }
void MemManage_Handler( void ) { while(1); }
void BusFault_Handler( void ) { while(1); }
void UsageFault_Handler( void ) { while(1); }
void SVC_Handler( void ) {}
void DebugMon_Handler( void ) {}
void PendSV_Handler( void ) {}
void SysTick_Handler( void ) { HAL_IncTick(); }
/*====================================================================================================*/
/*====================================================================================================*/
//void WWDG_IRQHandler( void ) {}
//void PVD_IRQHandler( void ) {}
//void TAMP_STAMP_IRQHandler( void ) {}
//void RTC_WKUP_IRQHandler( void ) {}
//void FLASH_IRQHandler( void ) {}
//void RCC_IRQHandler( void ) {}
//void EXTI0_IRQHandler( void ) {}
//void EXTI1_IRQHandler( void ) {}
//void EXTI2_IRQHandler( void ) {}
//void EXTI3_IRQHandler( void ) {}
//void EXTI4_IRQHandler( void ) {}
//void DMA1_Stream0_IRQHandler( void ) {}
//void DMA1_Stream1_IRQHandler( void ) {}
//void DMA1_Stream2_IRQHandler( void ) {}
//void DMA1_Stream3_IRQHandler( void ) {}
//void DMA1_Stream4_IRQHandler( void ) {}
//void DMA1_Stream5_IRQHandler( void ) {}
//void DMA1_Stream6_IRQHandler( void ) {}
//void ADC_IRQHandler( void ) {}
//void CAN1_TX_IRQHandler( void ) {}
//void CAN1_RX0_IRQHandler( void ) {}
//void CAN1_RX1_IRQHandler( void ) {}
//void CAN1_SCE_IRQHandler( void ) {}
//void EXTI9_5_IRQHandler( void ) {}
//void TIM1_BRK_TIM9_IRQHandler( void ) {}
//void TIM1_UP_TIM10_IRQHandler( void ) {}
//void TIM1_TRG_COM_TIM11_IRQHandler( void ) {}
//void TIM1_CC_IRQHandler( void ) {}
//void TIM2_IRQHandler( void ) {}
//void TIM3_IRQHandler( void ) {}
//void TIM4_IRQHandler( void ) {}
//void I2C1_EV_IRQHandler( void ) {}
//void I2C1_ER_IRQHandler( void ) {}
//void I2C2_EV_IRQHandler( void ) {}
//void I2C2_ER_IRQHandler( void ) {}
//void SPI1_IRQHandler( void ) {}
//void SPI2_IRQHandler( void ) {}
//void USART1_IRQHandler( void ) {}
//void USART2_IRQHandler( void ) {}
//void USART3_IRQHandler( void ) {}
//void EXTI15_10_IRQHandler( void ) {}
//void RTC_Alarm_IRQHandler( void ) {}
//void OTG_FS_WKUP_IRQHandler( void ) {}
//void TIM8_BRK_TIM12_IRQHandler( void ) {}
//void TIM8_UP_TIM13_IRQHandler( void ) {}
//void TIM8_TRG_COM_TIM14_IRQHandler( void ) {}
//void TIM8_CC_IRQHandler( void ) {}
//void DMA1_Stream7_IRQHandler( void ) {}
//void FMC_IRQHandler( void ) {}
//void SDIO_IRQHandler( void ) {}
//void TIM5_IRQHandler( void ) {}
//void SPI3_IRQHandler( void ) {}
//void UART4_IRQHandler( void ) {}
//void UART5_IRQHandler( void ) {}
//void TIM6_DAC_IRQHandler( void ) {}
//void TIM7_IRQHandler( void ) {}
//void DMA2_Stream0_IRQHandler( void ) {}
//void DMA2_Stream1_IRQHandler( void ) {}
//void DMA2_Stream2_IRQHandler( void ) {}
//void DMA2_Stream3_IRQHandler( void ) {}
//void DMA2_Stream4_IRQHandler( void ) {}
//void CAN2_TX_IRQHandler( void ) {}
//void CAN2_RX0_IRQHandler( void ) {}
//void CAN2_RX1_IRQHandler( void ) {}
//void CAN2_SCE_IRQHandler( void ) {}
//void OTG_FS_IRQHandler( void ) {}
//void DMA2_Stream5_IRQHandler( void ) {}
//void DMA2_Stream6_IRQHandler( void ) {}
//void DMA2_Stream7_IRQHandler( void ) {}
//void USART6_IRQHandler( void ) {}
//void I2C3_EV_IRQHandler( void ) {}
//void I2C3_ER_IRQHandler( void ) {}
//void OTG_HS_EP1_OUT_IRQHandler( void ) {}
//void OTG_HS_EP1_IN_IRQHandler( void ) {}
//void OTG_HS_WKUP_IRQHandler( void ) {}
//void OTG_HS_IRQHandler( void ) {}
//void DCMI_IRQHandler( void ) {}
//void FPU_IRQHandler( void ) {}
//void SPI4_IRQHandler( void ) {}
//void SAI1_IRQHandler( void ) {}
//void SAI2_IRQHandler( void ) {}
//void QuadSPI_IRQHandler( void ) {}
//void CEC_IRQHandler( void ) {}
//void SPDIF_RX_IRQHandler( void ) {}
//void I2C4_Event_IRQHandler( void ) {}
//void I2C4_Error_IRQHandler( void ) {}
/*====================================================================================================*/
/*====================================================================================================*/
