/*----------------------------------------------------------------------------
 * Name:    BlinkySingleLED.c
 * Purpose: LED Flasher
 *----------------------------------------------------------------------------*/

#include <stm32f10x.h>                       /* STM32F103 definitions         */
#define GIGI_USE_ODR 999

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
  // equivalent to RCC->APB2ENR |= (1UL << 3);                
  GPIOB->CRH    =  0x00000003;               /* PB.8 defined as Output   */
	i = 1<<8;
#ifdef GIGI_USE_ODR
  while (1) {		// Loop forever
      GPIOB->ODR ^= i;                       // Toggle LED
      wait ();                               /* call wait function            */
  }
#else
  while (1) {		// Loop forever
      GPIOB->BSRR = i;                       /* Turn LED on                   */
      wait ();                               /* call wait function            */
      GPIOB->BRR = i;                        /* Turn LED off                  */
      wait ();                               /* call wait function            */
  }
#endif
}
