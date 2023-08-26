#include "gpio.h"
#include "system.h"
#include "interrupt.h"
#include "PWM.h"

volatile uint32_t delayGreenLED = 4000; // Thoi gian delay mac dinh cho green led (ms)
void pwm_Init()
{
    SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
    PORTD_PCR5 = PORT_PCR_MUX(4); 
    SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK; 
    TPM0_MOD = delayGreenLED; 
    TPM0_SC = TPM_SC_PS(0); 
    TPM0_C0SC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK; 
    TPM0_C0V = delayGreenLED; 
    TPM0_SC |= TPM_SC_CMOD(1); 
}

void PORTC_PORTD_IRQHandler()
{  
    if (PORTC_ISFR & SW1) {
        if (delayGreenLED > 1000) {
            delayGreenLED -= 1000;
        } else {
            delayGreenLED = 4000;
        }
    }
    PORTC_ISFR = PORT_ISFR_ISF(SW1);
  
}

void speed(int x)
  {
    switch(x){
      case 0:
          delayGreenLED = 4000; // Thoi gian delay green led
      case 1:
          delayGreenLED = 4000; // Thoi gian delay green led
      case 2:
          delayGreenLED = 4000; // Thoi gian delay green led
      case 3:
          delayGreenLED = 4000; // Thoi gian delay green led
      default :
          delayGreenLED = 4000;
    }
 }