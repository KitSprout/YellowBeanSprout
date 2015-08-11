/*====================================================================================================*/
/*====================================================================================================*/
#include "Dirvers\stm32f4_system.h"
#include "Modules\module_ili9341.h"

#include "experiment_stm32f4.h"
/*====================================================================================================*/
/*====================================================================================================*/
void System_Init( void )
{
  HAL_Init();
  GPIO_Config();
  ILI9341_Config();
  ILI9341_Init();

  LCD_TestColoBar();
}

int main( void )
{
  System_Init();

  while(1) {
    LED_R_Toggle;
    LED_G_Toggle;
    LED_B_Toggle;
    Delay_100ms(5);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
void GPIO_Config( void )
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Clk ******************************************************************/
  LED_R_GPIO_CLK_ENABLE();
  LED_G_GPIO_CLK_ENABLE();
  LED_B_GPIO_CLK_ENABLE();
  KEY_WU_GPIO_CLK_ENABLE();
  KEY_BO_GPIO_CLK_ENABLE();

  /* GPIO Pin ******************************************************************/
  /* LED */
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;

  GPIO_InitStruct.Pin   = LED_R_PIN;
  HAL_GPIO_Init(LED_R_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin   = LED_G_PIN;
  HAL_GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin   = LED_B_PIN;
  HAL_GPIO_Init(LED_B_GPIO_PORT, &GPIO_InitStruct);

  /* KEY */
  GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;

  GPIO_InitStruct.Pin   = KEY_WU_PIN;
  HAL_GPIO_Init(KEY_WU_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin   = KEY_BO_PIN;
  HAL_GPIO_Init(KEY_BO_GPIO_PORT, &GPIO_InitStruct);

  /* GPIO Pin ******************************************************************/
  LED_R_Set;
  LED_G_Set;
  LED_B_Set;
}
/*====================================================================================================*/
/*====================================================================================================*/
