/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\stm32f4_system.h"

#include "experiment_stm32f4.h"

#include "cmsis_os.h"
/*====================================================================================================*/
/*====================================================================================================*/
static void osTimer_Callback( void const *argument )
{
  (void) argument;  

  LED_R_Toggle();
}
static void thread_ToggleLEDG( void const *argument )
{
  (void) argument;

  while(1) {
    LED_G_Toggle();
    osDelay(400);
  }
}
static void thread_ToggleLEDB( void const *argument )
{
  (void) argument;

  while(1) {
    LED_B_Toggle();
    osDelay(800);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
static void System_Init( void )
{
  HAL_Init();
  GPIO_Config();
}

static void FreeRTOS_Init( void )
{
  /* Create Timer */
  osTimerDef(timer, osTimer_Callback);
  osTimerId osTimer = osTimerCreate(osTimer(timer), osTimerPeriodic, NULL);

  /* Start Timer */
  osTimerStart(osTimer, 200);

  /* Create LED Thread */
  osThreadDef(threadLEDG, thread_ToggleLEDG, osPriorityNormal, 1, configMINIMAL_STACK_SIZE);
  osThreadCreate(osThread(threadLEDG), NULL);
  osThreadDef(threadLEDB, thread_ToggleLEDB, osPriorityNormal, 1, configMINIMAL_STACK_SIZE);
  osThreadCreate(osThread(threadLEDB), NULL);

  /* Start scheduler */
  osKernelStart();
}

int main( void )
{
  System_Init();
  FreeRTOS_Init();

  while(1) {

  }
}
/*====================================================================================================*/
/*====================================================================================================*/
