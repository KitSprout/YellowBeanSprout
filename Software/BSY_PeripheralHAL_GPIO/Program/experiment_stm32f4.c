/*====================================================================================================*/
/*====================================================================================================*/
#include "Dirvers\stm32f4_system.h"

#include "experiment_stm32f4.h"
/*====================================================================================================*/
/*====================================================================================================*/
void System_Init( void )
{
  HAL_Init();
  GPIO_Config();
  GPIO_EX_Config();
}

int main( void )
{
  System_Init();

  while(1) {
    LED_R_Toggle();
    LED_G_Toggle();
    LED_B_Toggle();

    GPIO_A_Toggle();
    GPIO_B_Toggle();
    GPIO_C_Toggle();

    Delay_1ms(100);
 
    while(KEY_WU_Read()) {
      LED_R_Toggle();
      LED_G_Toggle();
      LED_B_Toggle();
      Delay_1ms(200);

      GPIO_A_Set();
      GPIO_B_Set();
      GPIO_C_Set();
    }
    while(KEY_BO_Read()) {
      LED_R_Toggle();
      LED_G_Toggle();
      LED_B_Toggle();
      Delay_1ms(50);

      GPIO_A_Reset();
      GPIO_B_Reset();
      GPIO_C_Reset();
    }
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
