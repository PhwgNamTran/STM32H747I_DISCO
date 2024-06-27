#ifndef STM32H747XI_TIM_H
#define STM32H747XI_TIM_H

#include "Common.h"

/* Refer to RM0399 Reference Manual from http://www.st.com and CMSIS Library */

/* TIM Register - Refer to CMSIS Library */
typedef struct
{
    UINT32 CR1;         /**< TIM control register 1,                   Address offset: 0x00 */
    UINT32 CR2;         /**< TIM control register 2,                   Address offset: 0x04 */
    UINT32 SMCR;        /**< TIM slave mode control register,          Address offset: 0x08 */
    UINT32 DIER;        /**< TIM DMA/interrupt enable register,        Address offset: 0x0C */
    UINT32 SR;          /**< TIM status register,                      Address offset: 0x10 */
    UINT32 EGR;         /**< TIM event generation register,            Address offset: 0x14 */
    UINT32 CCMR1;       /**< TIM capture/compare mode register 1,      Address offset: 0x18 */
    UINT32 CCMR2;       /**< TIM capture/compare mode register 2,      Address offset: 0x1C */
    UINT32 CCER;        /**< TIM capture/compare enable register,      Address offset: 0x20 */
    UINT32 CNT;         /**< TIM counter register,                     Address offset: 0x24 */
    UINT32 PSC;         /**< TIM prescaler,                            Address offset: 0x28 */
    UINT32 ARR;         /**< TIM auto-reload register,                 Address offset: 0x2C */
    UINT32 RCR;         /**< TIM repetition counter register,          Address offset: 0x30 */
    UINT32 CCR1;        /**< TIM capture/compare register 1,           Address offset: 0x34 */
    UINT32 CCR2;        /**< TIM capture/compare register 2,           Address offset: 0x38 */
    UINT32 CCR3;        /**< TIM capture/compare register 3,           Address offset: 0x3C */
    UINT32 CCR4;        /**< TIM capture/compare register 4,           Address offset: 0x40 */
    UINT32 BDTR;        /**< TIM break and dead-time register,         Address offset: 0x44 */
    UINT32 DCR;         /**< TIM DMA control register,                 Address offset: 0x48 */
    UINT32 DMAR;        /**< TIM DMA address for full transfer,        Address offset: 0x4C */
    UINT32 RESERVED1;   /**< Reserved, 0x50                                                 */
    UINT32 CCMR3;       /**< TIM capture/compare mode register 3,      Address offset: 0x54 */
    UINT32 CCR5;        /**< TIM capture/compare register5,            Address offset: 0x58 */
    UINT32 CCR6;        /**< TIM capture/compare register6,            Address offset: 0x5C */
    UINT32 AF1;         /**< TIM alternate function option register 1, Address offset: 0x60 */
    UINT32 AF2;         /**< TIM alternate function option register 2, Address offset: 0x64 */
    UINT32 TISEL;       /**< TIM Input Selection register,             Address offset: 0x68 */
} TIM_ST;

/* Base Address of Timers */
#define TIM1_BASE   0x40010000UL  /**< Base address for Timer 1 (TIM1) */
#define TIM2_BASE   0x40000000UL  /**< Base address for Timer 2 (TIM2) */
#define TIM3_BASE   0x40000400UL  /**< Base address for Timer 3 (TIM3) */
#define TIM4_BASE   0x40000800UL  /**< Base address for Timer 4 (TIM4) */
#define TIM5_BASE   0x40000C00UL  /**< Base address for Timer 5 (TIM5) */
#define TIM6_BASE   0x40001000UL  /**< Base address for Timer 6 (TIM6) */
#define TIM7_BASE   0x40001400UL  /**< Base address for Timer 7 (TIM7) */
#define TIM8_BASE   0x40010400UL  /**< Base address for Timer 8 (TIM8) */
#define TIM12_BASE  0x40001800UL  /**< Base address for Timer 12 (TIM12) */
#define TIM13_BASE  0x40001C00UL  /**< Base address for Timer 13 (TIM13) */
#define TIM14_BASE  0x40002000UL  /**< Base address for Timer 14 (TIM14) */
#define TIM15_BASE  0x40014000UL  /**< Base address for Timer 15 (TIM15) */
#define TIM16_BASE  0x40014400UL  /**< Base address for Timer 16 (TIM16) */
#define TIM17_BASE  0x40014800UL  /**< Base address for Timer 17 (TIM17) */

/* Timer Declarations */
#define TIM1  ((TIM_ST *) TIM1_BASE)    /**< TIM1 declaration */
#define TIM2  ((TIM_ST *) TIM2_BASE)    /**< TIM2 declaration */
#define TIM3  ((TIM_ST *) TIM3_BASE)    /**< TIM3 declaration */
#define TIM4  ((TIM_ST *) TIM4_BASE)    /**< TIM4 declaration */
#define TIM5  ((TIM_ST *) TIM5_BASE)    /**< TIM5 declaration */
#define TIM6  ((TIM_ST *) TIM6_BASE)    /**< TIM6 declaration */
#define TIM7  ((TIM_ST *) TIM7_BASE)    /**< TIM7 declaration */
#define TIM8  ((TIM_ST *) TIM8_BASE)    /**< TIM8 declaration */
#define TIM12 ((TIM_ST *) TIM12_BASE)   /**< TIM12 declaration */
#define TIM13 ((TIM_ST *) TIM13_BASE)   /**< TIM13 declaration */
#define TIM14 ((TIM_ST *) TIM14_BASE)   /**< TIM14 declaration */
#define TIM15 ((TIM_ST *) TIM15_BASE)   /**< TIM15 declaration */
#define TIM16 ((TIM_ST *) TIM16_BASE)   /**< TIM16 declaration */
#define TIM17 ((TIM_ST *) TIM17_BASE)   /**< TIM17 declaration */

#endif