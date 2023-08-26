/****************************************************************************
******************************* C HEADER FILE *******************************
**                           *******************                           **
**                                                                         **
** project : Control by UART                                               **
** filename : gpio.h                                                       **
** date : 11/08/2023                                                       **
*****************************************************************************
*****************************************************************************
VERSION HISTORY:
----------------
Version : 1
Date : 11/08/2023
Revised by : Le Dinh Duy
Description: init GPIO ( led and switch)
****************************************************************************/
#ifndef _GPIO_H_
#define _GPIO_H_
/****************************************************************************/
/**                                                                        **/
/**                             MODULES USED                               **/
/**                                                                        **/
/****************************************************************************/
#include <stdint.h>
/****************************************************************************/
/**                                                                        **/
/**                     DEFINITIONS AND MACROS                             **/
/**                                                                        **/
/****************************************************************************/
/* PIN SW */
#define SW1                     (1<<3)
#define SW2                     (1 << 12)
/* PIN LED */
#define RED_LED_PIN             (1<<29)
#define GREEN_LED_PIN           (1<<5)
/* GPIOA memory map */
#define GORTA_PDOR                               *(uint32_t *)0x400FF000u
#define GPIOA_PSOR                               *(uint32_t *)0x400FF004u
#define GPIOA_PCOR                               *(uint32_t *)0x400FF008u
#define GPIOA_PTOR                               *(uint32_t *)0x400FF00Cu
#define GPIOA_PDIR                               *(uint32_t *)0x400FF010u
#define GPIOA_PDDR                               *(uint32_t *)0x400FF014u
/* GPIOC memory map */
#define GORTC_PDOR                               *(uint32_t *)0x400FF080u
#define GPIOC_PSOR                               *(uint32_t *)0x400FF084u
#define GPIOC_PCOR                               *(uint32_t *)0x400FF088u
#define GPIOC_PTOR                               *(uint32_t *)0x400FF08Cu
#define GPIOC_PDIR                               *(uint32_t *)0x400FF090u
#define GPIOC_PDDR                               *(uint32_t *)0x400FF094u
/* GPIOD memory map */
#define GORTD_PDOR                               *(uint32_t *)0x400FF0C0u
#define GPIOD_PSOR                               *(uint32_t *)0x400FF0C4u
#define GPIOD_PCOR                               *(uint32_t *)0x400FF0C8u
#define GPIOD_PTOR                               *(uint32_t *)0x400FF0CCu
#define GPIOD_PDIR                               *(uint32_t *)0x400FF0D0u
#define GPIOD_PDDR                               *(uint32_t *)0x400FF0D4u
/* GPIOE memory map */
#define GORTE_PDOR                               *(uint32_t *)0x400FF100u
#define GPIOE_PSOR                               *(uint32_t *)0x400FF104u
#define GPIOE_PCOR                               *(uint32_t *)0x400FF108u
#define GPIOE_PTOR                               *(uint32_t *)0x400FF10Cu
#define GPIOE_PDIR                               *(uint32_t *)0x400FF110u
#define GPIOE_PDDR                               *(uint32_t *)0x400FF114u
/* PORTA PCR pin 1 and pin 2*/
#define PORTA_PCR1                               *(uint32_t *)0x40049004u
#define PORTA_PCR2                               *(uint32_t *)0x40049008u
/* PORTC PCR pin 3 and pin 12*/
#define PORTC_PCR3                               *(uint32_t *)0x4004B00Cu
#define PORTC_PCR12                              *(uint32_t *)0x4004B030u
/* PORTD PCR pin 5*/
#define PORTD_PCR5                               *(uint32_t *)0x4004C014u
/* PORTE PCR pin 29 */
#define PORTE_PCR29                              *(uint32_t *)0x4004D074u
/* PORTC Interrupt status flag*/
#define PORTC_ISFR                               *(uint32_t *)0x4004B0A0u


/* SCGC5 - System Clock Gating Control Register 5 */
#define SIM_SCGC5_PORTA_MASK                     (0x200U)
#define SIM_SCGC5_PORTA_SHIFT                    (9U)
#define SIM_SCGC5_PORTA(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTA_SHIFT)) & SIM_SCGC5_PORTA_MASK)
#define SIM_SCGC5_PORTB_MASK                     (0x400U)
#define SIM_SCGC5_PORTB_SHIFT                    (10U)
#define SIM_SCGC5_PORTB(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTB_SHIFT)) & SIM_SCGC5_PORTB_MASK)
#define SIM_SCGC5_PORTC_MASK                     (0x800U)
#define SIM_SCGC5_PORTC_SHIFT                    (11U)
#define SIM_SCGC5_PORTC(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTC_SHIFT)) & SIM_SCGC5_PORTC_MASK)
#define SIM_SCGC5_PORTD_MASK                     (0x1000U)
#define SIM_SCGC5_PORTD_SHIFT                    (12U)
#define SIM_SCGC5_PORTD(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTD_SHIFT)) & SIM_SCGC5_PORTD_MASK)
#define SIM_SCGC5_PORTE_MASK                     (0x2000U)
#define SIM_SCGC5_PORTE_SHIFT                    (13U)
#define SIM_SCGC5_PORTE(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTE_SHIFT)) & SIM_SCGC5_PORTE_MASK)
/* PCR - Pin Control Register n */
#define PORT_PCR_MUX_MASK                        (0x700U)
#define PORT_PCR_MUX_SHIFT                       (8U)
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_MUX_SHIFT)) & PORT_PCR_MUX_MASK)
#define PORT_PCR_IRQC_MASK                       (0xF0000U)
#define PORT_PCR_IRQC_SHIFT                      (16U)
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x)) << PORT_PCR_IRQC_SHIFT)) & PORT_PCR_IRQC_MASK)
#define PORT_PCR_PE_MASK                         (0x2U)
#define PORT_PCR_PE_SHIFT                        (1U)
#define PORT_PCR_PE(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PE_SHIFT)) & PORT_PCR_PE_MASK)
#define PORT_PCR_PS_MASK                         (0x1U)
#define PORT_PCR_PS_SHIFT                        (0U)
#define PORT_PCR_PS(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PS_SHIFT)) & PORT_PCR_PS_MASK)

/****************************************************************************
 * Function Name : Led_Init                                                 *
 * Parameters    : None                                                     *
 * Return        : None                                                     *
 *END************************************************************************/
void Led_Init(void);
/****************************************************************************
 * Function Name : SW_Init                                                  *
 * Parameters    : None                                                     *
 * Return        : None                                                     *
 *END************************************************************************/
void SW_Init(void);
/****************************************************************************
 * Function Name : Off_Red_Led                                              *
 * Parameters    : None                                                     *
 * Return        : None                                                     *
 *END************************************************************************/
void Off_Red_Led();
/****************************************************************************
 * Function Name : On_Red_Led                                               *
 * Parameters    : None                                                     *
 * Return        : None                                                     *
 *END************************************************************************/
void On_Red_Led();
/****************************************************************************
 * Function Name : toggleRedLed                                             *
 * Parameters    : None                                                     *
 * Return        : None                                                     *
 *END************************************************************************/
void toggleRedLED(void);
/****************************************************************************
 * Function Name : toggleGreenLED                                           *
 * Parameters    : None                                                     *
 * Return        : None                                                     *
 *END************************************************************************/
void toggleGreenLED(void);
#endif /* GPIO_H */