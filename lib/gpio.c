#include "gpio.h"
#include "system.h"

void Led_Init(void)
{ 
  /* select port D and E */
  SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK;
  /* init red led */
  PORTE_PCR29 |= PORT_PCR_MUX(1);
  GPIOE_PDDR |= RED_LED_PIN;
  GPIOE_PSOR |= RED_LED_PIN;
  /* init green led */
  PORTD_PCR5 |= PORT_PCR_MUX(1);
  GPIOD_PDDR |= GREEN_LED_PIN;
  GPIOD_PSOR |= GREEN_LED_PIN;
}
void SW_Init(void)
{
  /* select port sw (port C) */
  SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
  /* init sw1 interrupt*/
  PORTC_PCR3 &= ~PORT_PCR_MUX_MASK;
  PORTC_PCR3 |= PORT_PCR_MUX(1);
  PORTC_PCR3 &= ~PORT_PCR_IRQC_MASK;
  PORTC_PCR3 |= PORT_PCR_IRQC(10);
  PORTC_PCR3 |= PORT_PCR_PE_MASK;
  PORTC_PCR3 |= PORT_PCR_PS_MASK;
  GPIOC_PDDR &= ~SW1;
  /* init sw2 interrupt */
  PORTC_PCR12 &= ~PORT_PCR_MUX_MASK;
  PORTC_PCR12 |= PORT_PCR_MUX(1);
  PORTC_PCR12 &= ~PORT_PCR_IRQC_MASK;
  PORTC_PCR12 |= PORT_PCR_IRQC(10);
  PORTC_PCR12 |= PORT_PCR_PE_MASK;
  PORTC_PCR12 |= PORT_PCR_PS_MASK;
  GPIOC_PDDR &= ~SW2;
}
void Off_Red_Led(){
  GPIOE_PSOR |= RED_LED_PIN;
}
void On_Red_Led(){
  GPIOE_PCOR |= RED_LED_PIN;
}
void toggleRedLED(void) {
    GPIOE_PTOR = RED_LED_PIN;
}
void toggleGreenLED(void) {
    GPIOD_PTOR = GREEN_LED_PIN;
}
