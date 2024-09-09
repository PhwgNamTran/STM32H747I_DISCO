#ifndef STM32H747XI_NVIC_H
#define STM32H747XI_NVIC_H

#include "Common.h"

/* Refer to RM0399 Reference Manual from http://www.st.com and CMSIS Library */

/*
 * Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
typedef struct
{
    volatile uint32_t ISER[8U];               /**< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
    volatile uint32_t RESERVED0[24U];
    volatile uint32_t ICER[8U];               /**< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
    volatile uint32_t RESERVED1[24U];
    volatile uint32_t ISPR[8U];               /**< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
    volatile uint32_t RESERVED2[24U];
    volatile uint32_t ICPR[8U];               /**< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
    volatile uint32_t RESERVED3[24U];
    volatile uint32_t IABR[8U];               /**< Offset: 0x200 (R/W)  Interrupt Active bit Register */
    volatile uint32_t RESERVED4[56U];
    volatile uint8_t  IP[240U];               /**< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
    volatile uint32_t RESERVED5[644U];
    volatile uint32_t STIR;                   /**< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_ST;

#define NVIC_BASE   0xE000E100UL                /**< NVIC Base Address */
#define NVIC        ((NVIC_ST *) NVIC_BASE)     /**< NVIC structure pointer declaration */

/*
 * NVIC Functions Declarations
 * ---------------------------
 * These functions provide access to NVIC (Nested Vectored Interrupt Controller) operations
 * for enabling/disabling interrupts, managing interrupt pending status, and setting/getting priorities.
 */
extern void   NVIC_EnableIRQ(IRQn_N IRQn);              
extern boolean   NVIC_GetEnableIRQ(IRQn_N IRQn);           
extern void   NVIC_DisableIRQ(IRQn_N IRQn);             
extern uint32_t NVIC_GetPendingIRQ(IRQn_N IRQn);          
extern void   NVIC_SetPendingIRQ(IRQn_N IRQn);          
extern void   NVIC_ClearPendingIRQ(IRQn_N IRQn);        
extern uint32_t NVIC_GetActive(IRQn_N IRQn);              
extern void   NVIC_SetPriority(IRQn_N IRQn, uint8_t Priority);            
extern uint32_t NVIC_GetPriority(IRQn_N IRQn);                       

#endif