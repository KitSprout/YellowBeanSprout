/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\stm32f4_system.h"
#include "modules\module_serial.h"

#include "experiment_stm32f4.h"
/*====================================================================================================*/
/*====================================================================================================*/
#define BUFFER_SIZE 1
__IO uint16_t ADC_ConvVal[BUFFER_SIZE];
/*====================================================================================================*/
/*====================================================================================================*/
void System_Init( void )
{
  HAL_Init();
  GPIO_Config();
  Serial_Config();
  ADC_Config();

  Delay_100ms(1);
  printf("\r\nHello World!\r\n\r\n");
}

int main( void )
{
  System_Init();

  while(1) {
    LED_G_Toggle();
    Delay_100ms(1);
    printf("ADC = %d\r\n", ADC_ConvVal[0]);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
#define ADCx                    ADC1
#define ADCx_CLK_ENABLE()       __HAL_RCC_ADC1_CLK_ENABLE()
#define ADCx_CHANNEL            ADC_CHANNEL_10

#define ADCx_DMAx_CLK_ENABLE()  __HAL_RCC_DMA2_CLK_ENABLE()
#define ADCx_DMA_CHANNEL        DMA_CHANNEL_0
#define ADCx_DMA_STREAM         DMA2_Stream0

#define ADCx_GPIO_PIN           GPIO_PIN_0
#define ADCx_GPIO_PORT          GPIOC
#define ADCx_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOC_CLK_ENABLE()

void ADC_Config( void )
{
  GPIO_InitTypeDef GPIO_InitStruct;
  ADC_HandleTypeDef ADC_InitStruct;
  ADC_ChannelConfTypeDef ADC_ChannelConfStruct;
  DMA_HandleTypeDef DMA_HandleStruct;

  ADCx_CLK_ENABLE();
  ADCx_GPIO_CLK_ENABLE();
  ADCx_DMAx_CLK_ENABLE();

  GPIO_InitStruct.Pin  = ADCx_GPIO_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ADCx_GPIO_PORT, &GPIO_InitStruct);

  ADC_InitStruct.Instance                   = ADCx;
  ADC_InitStruct.Init.ClockPrescaler        = ADC_CLOCKPRESCALER_PCLK_DIV4;
  ADC_InitStruct.Init.Resolution            = ADC_RESOLUTION12b;
  ADC_InitStruct.Init.ScanConvMode          = ENABLE;  // Scan Conv Disable
  ADC_InitStruct.Init.ContinuousConvMode    = ENABLE;
  ADC_InitStruct.Init.DiscontinuousConvMode = DISABLE;
  ADC_InitStruct.Init.NbrOfDiscConversion   = 0;
  ADC_InitStruct.Init.ExternalTrigConvEdge  = ADC_EXTERNALTRIGCONVEDGE_NONE;
  ADC_InitStruct.Init.ExternalTrigConv      = ADC_SOFTWARE_START;
  ADC_InitStruct.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
  ADC_InitStruct.Init.NbrOfConversion       = 1;
  ADC_InitStruct.Init.DMAContinuousRequests = ENABLE;
  ADC_InitStruct.Init.EOCSelection          = DISABLE;
  HAL_ADC_Init(&ADC_InitStruct);

  DMA_HandleStruct.Instance                 = ADCx_DMA_STREAM;
  DMA_HandleStruct.Init.Channel             = ADCx_DMA_CHANNEL;
  DMA_HandleStruct.Init.Direction           = DMA_PERIPH_TO_MEMORY;
  DMA_HandleStruct.Init.PeriphInc           = DMA_PINC_DISABLE;
  DMA_HandleStruct.Init.MemInc              = DMA_MINC_ENABLE;
  DMA_HandleStruct.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
  DMA_HandleStruct.Init.MemDataAlignment    = DMA_MDATAALIGN_HALFWORD;
  DMA_HandleStruct.Init.Mode                = DMA_CIRCULAR;
  DMA_HandleStruct.Init.Priority            = DMA_PRIORITY_HIGH;
  DMA_HandleStruct.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
  DMA_HandleStruct.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_HALFFULL;
  DMA_HandleStruct.Init.MemBurst            = DMA_MBURST_SINGLE;
  DMA_HandleStruct.Init.PeriphBurst         = DMA_PBURST_SINGLE;
  HAL_DMA_Init(&DMA_HandleStruct);

  __HAL_LINKDMA(&ADC_InitStruct, DMA_Handle, DMA_HandleStruct);

  ADC_ChannelConfStruct.Channel      = ADCx_CHANNEL;
  ADC_ChannelConfStruct.Rank         = 1;
  ADC_ChannelConfStruct.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  ADC_ChannelConfStruct.Offset       = 0;
  HAL_ADC_ConfigChannel(&ADC_InitStruct, &ADC_ChannelConfStruct);

  HAL_ADC_Start_DMA(&ADC_InitStruct, (uint32_t*)ADC_ConvVal, BUFFER_SIZE);
  HAL_ADC_Start(&ADC_InitStruct);
}
/*====================================================================================================*/
/*====================================================================================================*/
