#include "interrupt.h"
#include "gpio.h"

/* interrupt for Switch */
void Interrupt_Init()
{
  NVIC_ClearPendingIRQ(PORTC_PORTD_IRQn);
  NVIC_EnableIRQ(PORTC_PORTD_IRQn);
  NVIC_SetPriority(PORTC_PORTD_IRQn,1);
}


    

