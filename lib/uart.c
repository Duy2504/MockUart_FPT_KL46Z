#include "uart.h"
#include "system.h"
#include "gpio.h"

void UART_Init(uint32_t sysclk, uint32_t baud_rate)
{
    uint8_t i;
    uint32_t calculated_baud = 0;
    uint32_t baud_diff = 0;
    uint32_t osr_val = 0;
    uint32_t sbr_val, uart0clk;
    uint32_t reg_temp = 0;
    uint32_t temp = 0;
    /* Set Mux UART */
    PORTA_PCR1= PORT_PCR_MUX(2);
    PORTA_PCR2= PORT_PCR_MUX(2);
    SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
    UART0_C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);
    /* Change units to Hz */
    uart0clk = sysclk * 1000;
    /* Calculate the first baud rate using the lowest OSR value possible */
    i = 4;
    sbr_val = (uint32_t)(uart0clk/(baud_rate * i));
    calculated_baud = (uart0clk / (i * sbr_val));
    baud_diff = abs(calculated_baud - baud_rate);
    osr_val = i;
    /* Select the bester OSR value */
    for (i = 5; i <= 32; i++)
    {
        sbr_val = (uint32_t)(uart0clk/(baud_rate * i));
        calculated_baud = (uart0clk / (i * sbr_val));
        temp = abs(calculated_baud - baud_rate);
        if (temp <= baud_diff)
        {
            baud_diff = temp;
            osr_val = i;
        }
    }

    if (baud_diff < ((baud_rate / 100) * 3))
    {
        if ((osr_val >3) && (osr_val < 9))UART0_C5 |= UART0_C5_BOTHEDGE_MASK;
        /* Setup OSR value */
        reg_temp = UART0_C4;
        reg_temp &= ~UART0_C4_OSR_MASK;
        reg_temp |= UART0_C4_OSR(osr_val-1);
        /* Write reg_temp to C4 register */
        UART0_C4 = reg_temp;
        reg_temp = (reg_temp & UART0_C4_OSR_MASK) + 1;
        sbr_val = (uint32_t)((uart0clk)/(baud_rate * (reg_temp)));
         /* Save off the current value of the uartx_BDH except for the SBR field */
        reg_temp = UART0_BDH & ~(UART0_BDH_SBR(0x1F));
        UART0_BDH = reg_temp |  UART0_BDH_SBR(((sbr_val & 0x1F00) >> 8));
        UART0_BDL = (uint8_t)(sbr_val & UART0_BDL_SBR_MASK);
        /* Enable receiver and transmitter */
        UART0_C2 |= (UART0_C2_TE_MASK | UART0_C2_RE_MASK );
    }
    else
    {
    	while(1);
    }
}
void UartTxMsg(uint8_t *data, uint8_t size)
{
	uint8_t *pTX = (uint8_t*)&UART0_D;
	while(size--)
	{
		while((UART0_S1 & (UART0_S1_TC(1))) == 0);
		*pTX = *data++;
	}

}
char UartRxMsg()
{
	/* Wait until character has been received */
	while (!(UART0_S1 & UART0_S1_RDRF_MASK));
	/* Return the 8-bit data from the receiver */
	return UART0_D;
}
uint8_t UartRxByte()
{
	/* Wait until character has been received */
	while (!(UART0_S1 & UART0_S1_RDRF_MASK));
	/* Return the 8-bit data from the receiver */
	return UART0_D;
}

char uart_getchar ()
{
      /* Wait until character has been received */
      while (!(UART0_S1 & UART0_S1_RDRF_MASK));  
      /* Return the 8-bit data from the receiver */
      return UART0_D;
}
unsigned short canT;
void uart_putchar ( char ch)
{
      canT = (UART0_S1 & UART0_S1_TC_MASK) >> UART0_S1_TC_SHIFT;
      /* Wait until space is available in the FIFO */
      while(((UART0_S1 & UART0_S1_TC_MASK) >> UART0_S1_TC_SHIFT)==0);
    
      /* Send the character */
      UART0_D = (uint8_t)ch;
}
void UART_putstr(char *str)
{
  while(*str)
  {
    if(*str == '\n')
    {
      uart_putchar('\r');
    }
    uart_putchar(*str++);
  }
}