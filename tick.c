#include "tick.h"
#include "stm32f10x.h"
volatile unsigned long int ticks;

void tickInit(void)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
  TIM_OCInitTypeDef TIM_OCInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	// enable timer clock
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);

  ticks = 0;

  /* Configure two bits for preemption priority */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  /* Enable the TIM2 Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  // configure timer
  // read default values into TIM_TimeBaseStructure
  TIM_TimeBaseStructInit (& TIM_TimeBaseStructure);
  // PWM frequency = 1 KHz with 72MHz system clock
  // 72M/720 = 100000 Hz
  // 100000/100 = 1 KHz
  TIM_TimeBaseStructure.TIM_Prescaler = SystemCoreClock /100000 - 1; // 719
  TIM_TimeBaseStructure.TIM_Period = 100 - 1; // 99
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  // Initialize TIM2 as specified in the TIM_TimeBaseInitStruct.
  TIM_TimeBaseInit(TIM2 , &TIM_TimeBaseStructure);

  // PWM1 Mode configuration: Channel2
  // read default values into TIM_OCInitStructure
  TIM_OCStructInit (& TIM_OCInitStructure);
  // Set mode to PWM1
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OC2Init(TIM2 , &TIM_OCInitStructure);

  // Enable Timer
  TIM_Cmd(TIM2 , ENABLE);
	
	/* Enables the TIM2 Capture Compare channel 2 Interrupt source */
  TIM_ITConfig(TIM2, TIM_IT_CC2, ENABLE );
  /* Clear the TIM2 Capture Compare 2 flag */
  TIM_ClearFlag(TIM2, TIM_FLAG_CC2);
}

void tickReset(void)
{
#ifdef TICK_IS_RESETTABLE
  ticks = 0;
#endif
}

unsigned long int tickGet(void) {
  return ticks;
}
