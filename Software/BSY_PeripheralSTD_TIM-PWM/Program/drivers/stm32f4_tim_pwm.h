/* #include "stm32f4_tim_pwm.h" */

#ifndef __STM32F4_TIM_PWM_H
#define __STM32F4_TIM_PWM_H

#include "stm32f4xx.h"
/*====================================================================================================*/
/*====================================================================================================*/
#define TIMx                  TIM1
#define TIMx_CLK_ENABLE()     RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE)
#define TIMx_CHANNEL          TIM_CHANNEL_1
#define TIMx_OCxInit          TIM_OC1Init
#define TIMx_PRES             (uint32_t)(SystemCoreClock / 1000000)
#define TIMx_PERIOD           (uint32_t)(1000)

#define TIMx_PWM_PERI         TIMx->PSC
#define TIMx_PWM_PULSE        TIMx->ARR
#define TIMx_PWM_DUTY         TIMx->CCR1

#define PWM_MAX   TIMx_PERIOD
#define PWM_MED   500
#define PWM_MIN   0
/*====================================================================================================*/
/*====================================================================================================*/
void TIM_PWM_Config( void );

void TIM_PWM_setDuty( uint16_t duty );
void TIM_PWM_setFreq( uint32_t freq );
/*====================================================================================================*/
/*====================================================================================================*/
#endif	 
