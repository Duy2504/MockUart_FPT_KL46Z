/****************************************************************************
******************************* C HEADER FILE *******************************
**                           *******************                           **
**                                                                         **
** project : Control by UART                                               **
** filename : system.h                                                     **
** date : 11/08/2023                                                       **
*****************************************************************************
*****************************************************************************
VERSION HISTORY:
----------------
Version : 1
Date : 11/08/2023
Revised by : Le Dinh Duy
Description: init clock
****************************************************************************/
#ifndef _SYSTEM_H
#define _SYSTEM_H
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
/* Peripheral SIM base address */
#define SIM_BASE                                (0x40047000u)
/* Peripheral MCG base address */
#define MCG_BASE                                (0x40064000u)
/* SIM - Peripheral instance base addresses */
/* SIM memory map */
#define SIM_CLKDIV1                             *(uint32_t *)0x40048044u
#define SIM_SOPT2                               *(uint32_t *)0x40048004u
#define SIM_SCGC4                               *(uint32_t *)0x40048034u
#define SIM_SCGC5                               *(uint32_t *)0x40048038u
#define SIM_SCGC6                               *(uint32_t *)0x4004803Cu

/* MCG - Peripheral instance base addresses */
/* MCG memory map */
#define MCG_C1                                  *(uint32_t *)0x40064000u
#define MCG_C4                                  *(uint32_t *)0x40064003u
#define MCG_S                                   *(uint32_t *)0x40064006u
/* SCGC5 - System Clock Gating Control Register 5 of PORTA*/
#define SIM_SCGC5_PORTA_MASK                     (0x200U)
/* CLKDIV1 - System Clock Divider Register 1 */
#define SIM_CLKDIV1_OUTDIV4_MASK                 (0x70000U)
#define SIM_CLKDIV1_OUTDIV4_SHIFT                (16U)
#define SIM_CLKDIV1_OUTDIV4(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_OUTDIV4_SHIFT)) & SIM_CLKDIV1_OUTDIV4_MASK)
#define SIM_CLKDIV1_OUTDIV1_MASK                 (0xF0000000U)
#define SIM_CLKDIV1_OUTDIV1_SHIFT                (28U)
#define SIM_CLKDIV1_OUTDIV1(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_OUTDIV1_SHIFT)) & SIM_CLKDIV1_OUTDIV1_MASK)
/* C1 - MCG Control 1 Register */
#define MCG_C1_CLKS_MASK                         (0xC0U)
#define MCG_C1_CLKS_SHIFT                        (6U)
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_C1_CLKS_SHIFT)) & MCG_C1_CLKS_MASK)
#define MCG_C1_IREFS_MASK                        (0x4U)
#define MCG_C1_IREFS_SHIFT                       (2U)
#define MCG_C1_IREFS(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_C1_IREFS_SHIFT)) & MCG_C1_IREFS_MASK)
/* C4 - MCG Control 4 Register */
#define MCG_C4_DRST_DRS_MASK                     (0x60U)
#define MCG_C4_DRST_DRS_SHIFT                    (5U)
#define MCG_C4_DRST_DRS(x)                       (((uint8_t)(((uint8_t)(x)) << MCG_C4_DRST_DRS_SHIFT)) & MCG_C4_DRST_DRS_MASK)
#define MCG_C4_DMX32_MASK                        (0x80U)
#define MCG_C4_DMX32_SHIFT                       (7U)
#define MCG_C4_DMX32(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_C4_DMX32_SHIFT)) & MCG_C4_DMX32_MASK)
/* S - MCG Status Register */
#define MCG_S_CLKST_MASK                         (0xCU)
#define MCG_S_CLKST_SHIFT                        (2U)
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_S_CLKST_SHIFT)) & MCG_S_CLKST_MASK)
#define MCG_S_IREFST_MASK                        (0x10U)
#define MCG_S_IREFST_SHIFT                       (4U)
#define MCG_S_IREFST(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_S_IREFST_SHIFT)) & MCG_S_IREFST_MASK)
/* SCGC4 - System Clock Gating Control Register 4 of UART0*/
#define SIM_SCGC4_UART0_MASK                     (0x400U)
#define SIM_SCGC4_UART0_SHIFT                    (10U)
#define SIM_SCGC4_UART0(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART0_SHIFT)) & SIM_SCGC4_UART0_MASK)
/* SOPT2 - System Options Register 2 of UART0*/
#define SIM_SOPT2_UART0SRC_MASK                  (0xC000000U)
#define SIM_SOPT2_UART0SRC_SHIFT                 (26U)
#define SIM_SOPT2_UART0SRC(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_UART0SRC_SHIFT)) & SIM_SOPT2_UART0SRC_MASK)

/****************************************************************************
 * Function Name : Clock_Init                                               *
 * Parameters    : None                                                     *
 * Return        : None                                                     *
 *END************************************************************************/
void Clock_Init(void);

#endif /* SYSTEM_H */
