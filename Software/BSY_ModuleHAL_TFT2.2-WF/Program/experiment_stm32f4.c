/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\stm32f4_system.h"
#include "modules\module_ili9341.h"
#include "algorithms\algorithm_mathUnit.h"
#include "api\api_waveForm.h"

#include "experiment_stm32f4.h"
/*====================================================================================================*/
/*====================================================================================================*/
void WaveForm_Init( void );
void WaveForm_demo( void );

WaveForm_Struct WaveForm;
/*====================================================================================================*/
/*====================================================================================================*/
void System_Init( void )
{
  HAL_Init();
  GPIO_Config();
  ILI9341_Config();
  ILI9341_Init();
  WaveForm_Init();
}

int main( void )
{
  System_Init();

  while(1) {
    LED_R_Toggle();
    LED_G_Toggle();
    LED_B_Toggle();
    WaveForm_demo();
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
void WaveForm_Init( void )
{
	WaveForm.Channel = 4;
	WaveForm.WindowColor = WHITE;
	WaveForm.BackColor = BLACK;
  for(uint8_t i = 0; i < WaveForm.Channel; i++) {
    WaveForm.Data[i] = 0;
    WaveForm.Scale[i] = 100;
  }
	WaveForm.PointColor[0] = RED;
  WaveForm.PointColor[1] = BLUE;
  WaveForm.PointColor[2] = YELLOW;
  WaveForm.PointColor[3] = GREEN;

  LCD_Clear(BLACK);
}
void WaveForm_demo( void )
{
  float data = 0.0f;
  float rad = 0.0f;
  static int32_t theta = 0;

  theta += 2;
  if(theta == 360) theta = 0;
  rad = toRad(theta);

  for(uint8_t i = 1; i < 10; i = i + 2)
    data += (1.0f/i) * arm_sin_f32(i * rad);

  WaveForm.Data[0] = arm_sin_f32(rad)*8000;
  WaveForm.Data[1] = (1.0f/3) * arm_sin_f32(3 * rad)*8000;
  WaveForm.Data[2] = (1.0f/5) * arm_sin_f32(5 * rad)*8000;
  WaveForm.Data[3] = data*8000;
  WaveFormPrint(&WaveForm, ENABLE);
}
/*====================================================================================================*/
/*====================================================================================================*/
