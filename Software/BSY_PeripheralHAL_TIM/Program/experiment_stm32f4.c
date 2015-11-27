/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\stm32f4_system.h"

#include "experiment_stm32f4.h"
/*====================================================================================================*/
/*====================================================================================================*/
TIM_HandleTypeDef TIM_HandleStruct;
/*====================================================================================================*/
/*====================================================================================================*/
void System_Init( void )
{
  HAL_Init();
  GPIO_Config();
  TIM_Config();
}

int main( void )
{
  System_Init();

  while(1) {
    LED_G_Toggle();
    LED_B_Toggle();
    Delay_100ms(1);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
void TIM_Config( void )
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_TIM3_CLK_ENABLE();

  HAL_NVIC_SetPriority(TIM3_IRQn, 3, 0);
  HAL_NVIC_EnableIRQ(TIM3_IRQn);

  /* TIM3 use APB1 = 45 MHz */
  TIM_HandleStruct.Instance               = TIM3;
  TIM_HandleStruct.Init.Prescaler         = 4500 - 1;
  TIM_HandleStruct.Init.Period            = 10000 - 1;
  TIM_HandleStruct.Init.ClockDivision     = 0;
  TIM_HandleStruct.Init.CounterMode       = TIM_COUNTERMODE_UP;
  TIM_HandleStruct.Init.RepetitionCounter = 0;
  HAL_TIM_Base_Init(&TIM_HandleStruct);
  HAL_TIM_Base_Start_IT(&TIM_HandleStruct);
}
void TIM3_UpdateEven_CallBack( TIM_HandleTypeDef *htim )
{
  LED_R_Toggle();
}
/*====================================================================================================*/
/*====================================================================================================*/
