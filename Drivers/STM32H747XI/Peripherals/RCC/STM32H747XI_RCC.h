#ifndef STM32H747XI_RCC_H
#define STM32H747XI_RCC_H

#include "Common.h"

/* Refer to RM0399 Reference Manual from http://www.st.com */

/**< RCC Core Register - Refer to CMSIS Library */
typedef struct
{
    volatile uint32_t RSR;            /**< RCC Reset status register,                              Address offset: 0x00 */
    volatile uint32_t AHB3ENR;        /**< RCC AHB3 peripheral clock  register,                    Address offset: 0x04 */
    volatile uint32_t AHB1ENR;        /**< RCC AHB1 peripheral clock  register,                    Address offset: 0x08 */
    volatile uint32_t AHB2ENR;        /**< RCC AHB2 peripheral clock  register,                    Address offset: 0x0C */
    volatile uint32_t AHB4ENR;        /**< RCC AHB4 peripheral clock  register,                    Address offset: 0x10 */
    volatile uint32_t APB3ENR;        /**< RCC APB3 peripheral clock  register,                    Address offset: 0x14 */
    volatile uint32_t APB1LENR;       /**< RCC APB1 peripheral clock  Low Word register,           Address offset: 0x18 */
    volatile uint32_t APB1HENR;       /**< RCC APB1 peripheral clock  High Word register,          Address offset: 0x1C */
    volatile uint32_t APB2ENR;        /**< RCC APB2 peripheral clock  register,                    Address offset: 0x20 */
    volatile uint32_t APB4ENR;        /**< RCC APB4 peripheral clock  register,                    Address offset: 0x24 */
    volatile uint32_t RESERVED9;      /**< Reserved,                                               Address offset: 0x28 */
    volatile uint32_t AHB3LPENR;      /**< RCC AHB3 peripheral sleep clock  register,              Address offset: 0x3C */
    volatile uint32_t AHB1LPENR;      /**< RCC AHB1 peripheral sleep clock  register,              Address offset: 0x40 */
    volatile uint32_t AHB2LPENR;      /**< RCC AHB2 peripheral sleep clock  register,              Address offset: 0x44 */
    volatile uint32_t AHB4LPENR;      /**< RCC AHB4 peripheral sleep clock  register,              Address offset: 0x48 */
    volatile uint32_t APB3LPENR;      /**< RCC APB3 peripheral sleep clock  register,              Address offset: 0x4C */
    volatile uint32_t APB1LLPENR;     /**< RCC APB1 peripheral sleep clock  Low Word register,     Address offset: 0x50 */
    volatile uint32_t APB1HLPENR;     /**< RCC APB1 peripheral sleep clock  High Word register,    Address offset: 0x54 */
    volatile uint32_t APB2LPENR;      /**< RCC APB2 peripheral sleep clock  register,              Address offset: 0x58 */
    volatile uint32_t APB4LPENR;      /**< RCC APB4 peripheral sleep clock  register,              Address offset: 0x5C */
    volatile uint32_t RESERVED10[4];  /**< Reserved, 0x60-0x6C                                     Address offset: 0x60 */
} RCC_Core_ST;

#define RCC_BASE    0x58024400U     /**< RCC Base Address */
#define RCC_C1_BASE 0x58024530U     /**< RCC Core 1 Base Address */
#define RCC_C2_BASE 0x58024590U     /**< RCC Core 2 Base Address */

/* RCC & RCC Core Declaration */
#define RCC         ((RCC_ST *) RCC_BASE)
#define RCC_C1      ((RCC_Core_ST *) RCC_C1_BASE)
#define RCC_C2      ((RCC_Core_ST *) RCC_C2_BASE)

#define System_Clock_Source_HSI         1U
#define System_Clock_Source_HSE         2U
#define System_Clock_Source_CSI         3U
#define System_Clock_Source_PLL1_P_CK   4U

#define CR_HSI_POS      0U
#define CR_HSI          (1 << CR_HSI_POS)

#define CR_HSIDIV_POS   3U

#define HSI_Clock   64000000U

#endif