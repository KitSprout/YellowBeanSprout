/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\stm32f4_system.h"
#include "modules\module_serial.h"

#include "beanSproutY.h"
/*====================================================================================================*/
/*====================================================================================================*/
void BSY_Init( void )
{
  SystemInit();
  HAL_InitTick();

  BSY_GPIO_Config();
  BSY_UART_Config(NULL);
}
/*====================================================================================================*/
/*====================================================================================================*/
void Serial_demo( void )
{
  static uint8_t i = 0;

  uint8_t recvData = 0;
  int8_t state = Serial_RecvDataWTO(&recvData, 1, 500);

  if(state == ERROR) {
    LED_R_Toggle();
    printf("Timeout ... %d\r\n", i);
    i = (i == 255) ? 0 : i + 1;
  }
  else if(recvData == 0x0D) { // if press enter
    LED_G_Toggle();
    Serial_SendStr("\r\n");
  }
  else {
    LED_B_Toggle();
    Serial_SendData(&recvData, 1);
  }
  if(KEY_WU_Read()) {
    Serial_SendStr("\f");
  }
}

void BSY_Loop( void )
{
  while(1) {
    Serial_demo();
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
