#include "uart.h"
#include "PWM.h"
#include "system.h"
#include "gpio.h"
#include "interrupt.h"
#include "app.h"

void main()
{
  Clock_Init();
  Led_Init();
  pwm_Init();
  Interrupt_Init();
  UART_Init(48000, 115200);  
  while(1){
    control();
  }
}