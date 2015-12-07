/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\stm32f4_system.h"
#include "algorithms\algorithm_mathUnit.h"

#include "experiment_stm32f4.h"
/*====================================================================================================*/
/*====================================================================================================*/
#define DACx                    DAC
#define DACx_CLK_ENABLE()       __HAL_RCC_DAC_CLK_ENABLE()
#define DACx_CHANNEL            DAC_CHANNEL_1

#define DACx_GPIO_PIN           GPIO_PIN_4
#define DACx_GPIO_PORT          GPIOA
#define DACx_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()

#define DAC_CH1                 DAC->DHR12R1
/*====================================================================================================*/
/*====================================================================================================*/
void System_Init( void )
{
  HAL_Init();
  GPIO_Config();
  DAC_Config();

  Delay_100ms(1);
}

int main( void )
{
  float data = 0.0f;
  float rad = 0.0f;
  int32_t theta = 0;

  System_Init();

  while(1) {
    theta += 2;
    if(theta == 360) theta = 0;
    rad = toRad(theta);

    data = 0.0f;
    for(uint8_t i = 1; i < 10; i = i + 2)
      data += (1.0f/i) * arm_sin_f32(i * rad);

    data += 1.0f;

    DAC_CH1 = data * 2048;

    LED_G_Toggle();
    Delay_10ms(1);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
void DAC_Config( void )
{
  GPIO_InitTypeDef GPIO_InitStruct;
  DAC_HandleTypeDef DAC_InitStruct;
  DAC_ChannelConfTypeDef DAC_ChannelConfStruct;

  DACx_CLK_ENABLE();
  DACx_GPIO_CLK_ENABLE();

  GPIO_InitStruct.Pin  = DACx_GPIO_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(DACx_GPIO_PORT, &GPIO_InitStruct);

  DAC_InitStruct.Instance = DACx;
  HAL_DAC_Init(&DAC_InitStruct);

  DAC_ChannelConfStruct.DAC_Trigger = DAC_TRIGGER_NONE;
  DAC_ChannelConfStruct.DAC_OutputBuffer = DAC_OUTPUTBUFFER_DISABLE;
  HAL_DAC_ConfigChannel(&DAC_InitStruct, &DAC_ChannelConfStruct, DACx_CHANNEL);

  HAL_DAC_SetValue(&DAC_InitStruct, DACx_CHANNEL, DAC_ALIGN_12B_R, 0);
  HAL_DAC_Start(&DAC_InitStruct, DACx_CHANNEL);
}
/*====================================================================================================*/
/*====================================================================================================*/
