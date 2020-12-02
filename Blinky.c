/*----------------------------------------------------------------------------
 * Name:    BlinkySingleLED.c
 * Purpose: LED Flasher
 *----------------------------------------------------------------------------*/

#include <stm32f10x.h>                       /* STM32F103 definitions         */
#include "lever.h"

#define EMERGENCY_INPUT_PIN 1<<0
#define STOP_INPUT_PIN 1<<1
#define BRAKE_3_INPUT 1<<2
#define BRAKE_2_INPUT 1<<3
#define BRAKE_1_INPUT 1<<4
#define IDLE_INPUT 1<<5
#define ACCELERATION_1_INPUT 1<<6
#define ACCELERATION_2_INPUT 1<<7
#define ACCELERATION_3_INPUT 1<<8




int WAIT;

/*----------------------------------------------------------------------------
  wait function
 *----------------------------------------------------------------------------*/
void wait (void)  {
  int  d, j;
  WAIT = 1;
  for (j=0; j<5; j++)
		for (d = 0; d < 1000000; d++);             /* only to delay for LED flashes */
  WAIT = 0;
}


/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/

int main(void) {
  unsigned int i;                            /* LED variable                  */

  RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;        /* Enable GPIOB clock            */
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;					/* Enable GPIOC clock            */
	            
  GPIOB->CRL    =  0x88888888;
	GPIOB->CRH    =  0x00000008;
	GPIOC->CRL    =  0x00000333;
	GPIOC->CRH    =  0x00003333;
	
	idle();
	
	while (1) {
		if(GPIOB->IDR & IDLE_INPUT) {
			idle();
		}else if(GPIOB->IDR & BRAKE_1_INPUT){
			set_brake_1();
		}
		wait ();
	}
	
}
	
	
	
	
