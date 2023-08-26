/****************************************************************************
******************************* C HEADER FILE *******************************
**                           *******************                           **
**                                                                         **
** project : Control by UART                                               **
** filename : uart.h                                                     **
** date : 11/08/2023                                                       **
*****************************************************************************
*****************************************************************************
VERSION HISTORY:
----------------
Version : 1
Date : 11/08/2023
Revised by : Le Dinh Duy
Description: init uart, transmit or receive data
****************************************************************************/
#ifndef _UART_H
#define _UART_H
/****************************************************************************/
/**                                                                        **/
/**                             MODULES USED                               **/
/**                                                                        **/
/****************************************************************************/
#include <stdint.h> 
/****************************************************************************/
/**                                                                        **/
/**                       DEFINITIONS AND MACROS                           **/
/**                                                                        **/
/****************************************************************************/
/* UART memory map */
#define UART0_C2                                 *(uint32_t *)0x4006A003u
#define UART0_C4                                 *(uint32_t *)0x4006A00Au
#define UART0_C5                                 *(uint32_t *)0x4006A00Bu
#define UART0_BDH                                *(uint32_t *)0x4006A000u
#define UART0_BDL                                *(uint32_t *)0x4006A001u
#define UART0_D                                  *(uint32_t *)0x4006A007u
#define UART0_S1                                 *(uint32_t *)0x4006A004u
/* C2 - UART Control Register 2 */
#define UART0_C2_TE_MASK                         (0x8U)
#define UART0_C2_TE_SHIFT                        (3U)
#define UART0_C2_TE(x)                           (((uint8_t)(((uint8_t)(x)) << UART0_C2_TE_SHIFT)) & UART0_C2_TE_MASK)
#define UART0_C2_RE_MASK                         (0x4U)
#define UART0_C2_RE_SHIFT                        (2U)
#define UART0_C2_RE(x)                           (((uint8_t)(((uint8_t)(x)) << UART0_C2_RE_SHIFT)) & UART0_C2_RE_MASK)
/* C4 - UART Control Register 4 */
#define UART0_C4_OSR_MASK                        (0x1FU)
#define UART0_C4_OSR_SHIFT                       (0U)
#define UART0_C4_OSR(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_C4_OSR_SHIFT)) & UART0_C4_OSR_MASK)
/* C5 - UART Control Register 5 */
#define UART0_C5_BOTHEDGE_MASK                   (0x2U)
#define UART0_C5_BOTHEDGE_SHIFT                  (1U)
#define UART0_C5_BOTHEDGE(x)                     (((uint8_t)(((uint8_t)(x)) << UART0_C5_BOTHEDGE_SHIFT)) & UART0_C5_BOTHEDGE_MASK)
/* BDL - UART Baud Rate Register Low */
#define UART0_BDL_SBR_MASK                       (0xFFU)
#define UART0_BDL_SBR_SHIFT                      (0U)
#define UART0_BDL_SBR(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_BDL_SBR_SHIFT)) & UART0_BDL_SBR_MASK)
/* BDH - UART Baud Rate Register High */
#define UART0_BDH_SBR_MASK                       (0x1FU)
#define UART0_BDH_SBR_SHIFT                      (0U)
#define UART0_BDH_SBR(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_BDH_SBR_SHIFT)) & UART0_BDH_SBR_MASK)
/* S1 - UART Status Register 1 */
#define UART0_S1_RDRF_MASK                       (0x20U)
#define UART0_S1_RDRF_SHIFT                      (5U)
#define UART0_S1_RDRF(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_S1_RDRF_SHIFT)) & UART0_S1_RDRF_MASK)
#define UART0_S1_TC_MASK                         (0x40U)
#define UART0_S1_TC_SHIFT                        (6U)
#define UART0_S1_TC(x)                           (((uint8_t)(((uint8_t)(x)) << UART0_S1_TC_SHIFT)) & UART0_S1_TC_MASK)

/****************************************************************************
 * Function Name : UART_Init                                                *
 * Parameters    : sysclk and baud_rate                                     *
 *Description    : init uart with desired baud_rate                         *
 * Return        : baudrate of uart                                         *
 *END************************************************************************/
void UART_Init(uint32_t sysclk, uint32_t baud_rate);
/****************************************************************************
 * Function Name : UartRxByte                                               *
 * Parameters    : None                                                     *
 *Description    : receive data                                             *
 * Return        : the 8-bit data from the receiver                         *
 *END************************************************************************/
uint8_t UartRxByte(void);
/****************************************************************************
 * Function Name : UartRxMsg                                                *
 * Parameters    : None                                                     *
 *Description    : receive message                                          *
 * Return        : None                                                     *
 *END************************************************************************/
char UartRxMsg();
/****************************************************************************
 * Function Name : UartTxMsg                                                *
 * Parameters    : &data and size data                                      *
 *Description    : transmit message                                         *
 * Return        : None                                                     *
 *END************************************************************************/
void UartTxMsg(uint8_t *data, uint8_t size);
/****************************************************************************
 * Function Name : uart_getchar                                             *
 * Parameters    : None                                                     *
 *Description    : get char                                                 *
 * Return        : the 8-bit data from the receiver                         *
 *END************************************************************************/
char uart_getchar ();
/****************************************************************************
 * Function Name : Uart_putchar                                             *
 * Parameters    : char                                                     *
 *Description    : put char                                                 *
 * Return        : None                                                     *
 *END************************************************************************/
void uart_putchar ( char ch);
/****************************************************************************
 * Function Name : Uart_putstr                                              *
 * Parameters    : &str                                                     *
 *Description    : put string                                               *
 * Return        : None                                                     *
 *END************************************************************************/
void UART_putstr(char *str);
#endif /* UART_H */