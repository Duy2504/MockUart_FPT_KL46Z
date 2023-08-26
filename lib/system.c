#include "system.h"

void Clock_Init(void)
{
	/*set a safe value for divider */
	SIM_CLKDIV1 |= SIM_CLKDIV1_OUTDIV4_MASK | SIM_CLKDIV1_OUTDIV1_MASK;
        /* Internal clock (32.768kHz) for FLL */
	MCG_C1 |= MCG_C1_IREFS_MASK; 
        /* 32.768 * 1464 = 47972.352kHz ~ 48MHz */
	MCG_C4 |= MCG_C4_DMX32_MASK | MCG_C4_DRST_DRS(1);
        /* Output of FLL is selected for MCGOUTCLK */
	MCG_C1 &= ~MCG_C1_CLKS_MASK; 
        /* wait for Internal clock is selected */
	while((MCG_S & MCG_S_IREFST_MASK) == 0);
        /* wait for FLL is selected */
	while((MCG_S & MCG_S_CLKST_MASK) != 0); 
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
        /* MCGFLLCLK is selected for UART0 clock source */
	SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1); 
}