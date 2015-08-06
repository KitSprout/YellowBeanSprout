/*====================================================================================================*/
/*====================================================================================================*/
#include "Dirvers\stm32f4_system.h"
#include "Modules\module_rs232.h"

#include "experiment_stm32f4.h"
/*====================================================================================================*/
/*====================================================================================================*/
int main( void )
{
  static uint8_t i = 0;
  static uint8_t RecvData = 0;
  static int8_t State = ERROR;

  HAL_Init();
  GPIO_Config();
  RS232_Config();

  LED_R_Reset;
  printf("\r\nHello World!\r\n\r\n");

  while(1) {
    LED_G_Toggle;
    LED_B_Toggle;

    State = RS232_RecvDataWTO(&RecvData, 1, 200);
    if(State == ERROR) {
      printf("Timeout ... %d\r\n", i);
      i = (i == 255) ? 0 : i + 1;
    }
    else if(RecvData == 0x0D)  // if press enter
      RS232_SendStr("\r\n");
    else
      RS232_SendData(&RecvData, 1);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
void GPIO_Config( void )
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Clk Init *************************************************************/
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /* LED_B PC13 */  /* LED_G PC14 */  /* LED_R PC15 */
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;

  GPIO_InitStruct.Pin   = GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* other pin */
  GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_15;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = GPIO_PIN_0  | GPIO_PIN_1  | GPIO_PIN_3  | GPIO_PIN_4  | GPIO_PIN_5  |
                        GPIO_PIN_6  | GPIO_PIN_7  | GPIO_PIN_8  | GPIO_PIN_9  | GPIO_PIN_10 |
                        GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = GPIO_PIN_0  | GPIO_PIN_1  | GPIO_PIN_2  | GPIO_PIN_3  | GPIO_PIN_5  |
                        GPIO_PIN_6  | GPIO_PIN_7;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* KEY_WU PA0 */  /* KEY_BO PB2 */
  GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  
  GPIO_InitStruct.Pin   = GPIO_PIN_0;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_InitStruct.Pin   = GPIO_PIN_2;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  // Init
  LED_R_Set;
  LED_G_Set;
  LED_B_Set;

  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8  | GPIO_PIN_15, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0  | GPIO_PIN_1  | GPIO_PIN_3  | GPIO_PIN_4  | GPIO_PIN_5  |
                           GPIO_PIN_6  | GPIO_PIN_7  | GPIO_PIN_8  | GPIO_PIN_9  | GPIO_PIN_10 |
                           GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0  | GPIO_PIN_1  | GPIO_PIN_2  | GPIO_PIN_3  | GPIO_PIN_5  |
                           GPIO_PIN_6  | GPIO_PIN_7, GPIO_PIN_SET);
}

void SD_Config( void )
{

}

void FFCSPI_Config( void )
{

}
/*====================================================================================================*/
/*====================================================================================================*/
