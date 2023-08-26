/****************************************************************************
******************************* C HEADER FILE *******************************
**                           *******************                           **
**                                                                         **
** project : Control by UART                                               **
** filename : interrupt.h                                                  **
** date : 11/08/2023                                                       **
*****************************************************************************
*****************************************************************************
VERSION HISTORY:
----------------
Version : 1
Date : 11/08/2023
Revised by : Le Dinh Duy
Description: init interrupt
****************************************************************************/
#ifndef _INTERRUPT_H
#define _INTERRUPT_H
/****************************************************************************/
/**                                                                        **/
/**                             MODULES USED                               **/
/**                                                                        **/
/****************************************************************************/
#include "MKL46Z4.h"
#include <stdint.h>
/****************************************************************************/
/**                                                                        **/
/**                     DEFINITIONS AND MACROS                             **/
/**                                                                        **/
/****************************************************************************/
/* ISFR - Interrupt Status Flag Register */
#define NVIC_ISER                                *(uint32_t *)0xE000E100u
#define NVIC_ICER                                *(uint32_t *)0xE000E180u
#define NVIC_ISPR                                *(uint32_t *)0xE000E200u  
#define NVIC_ICPR                                *(uint32_t *)0xE000E280u
//#define PORT_ISFR_ISF_MASK                       (0xFFFFFFFFU)
//#define PORT_ISFR_ISF_SHIFT                      (0U)
//#define PORT_ISFR_ISF(x)                         (((uint32_t)(((uint32_t)(x)) << PORT_ISFR_ISF_SHIFT)) & PORT_ISFR_ISF_MASK)
/****************************************************************************
 * Function Name : Interrupt_Init                                                *
 * Parameters    : None                                                     *
 * Return        : None                                                     *
 *END************************************************************************/
void Interrupt_Init();

#endif /* _INTERRUPT_H  */