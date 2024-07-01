#ifndef STM32H747XI_TIM_H
#define STM32H747XI_TIM_H

#include "Common.h"
#include "STM32H747XI_RCC.h"

/* Refer to RM0399 Reference Manual from http://www.st.com and CMSIS Library */

/* TIM Register - Refer to CMSIS Library */
typedef struct
{
    volatile UINT32 CR1;         /**< TIM control register 1,                   Address offset: 0x00 */
    volatile UINT32 CR2;         /**< TIM control register 2,                   Address offset: 0x04 */
    volatile UINT32 SMCR;        /**< TIM slave mode control register,          Address offset: 0x08 */
    volatile UINT32 DIER;        /**< TIM DMA/interrupt enable register,        Address offset: 0x0C */
    volatile UINT32 SR;          /**< TIM status register,                      Address offset: 0x10 */
    volatile UINT32 EGR;         /**< TIM event generation register,            Address offset: 0x14 */
    volatile UINT32 CCMR1;       /**< TIM capture/compare mode register 1,      Address offset: 0x18 */
    volatile UINT32 CCMR2;       /**< TIM capture/compare mode register 2,      Address offset: 0x1C */
    volatile UINT32 CCER;        /**< TIM capture/compare enable register,      Address offset: 0x20 */
    volatile UINT32 CNT;         /**< TIM counter register,                     Address offset: 0x24 */
    volatile UINT32 PSC;         /**< TIM prescaler,                            Address offset: 0x28 */
    volatile UINT32 ARR;         /**< TIM auto-reload register,                 Address offset: 0x2C */
    volatile UINT32 RCR;         /**< TIM repetition counter register,          Address offset: 0x30 */
    volatile UINT32 CCR1;        /**< TIM capture/compare register 1,           Address offset: 0x34 */
    volatile UINT32 CCR2;        /**< TIM capture/compare register 2,           Address offset: 0x38 */
    volatile UINT32 CCR3;        /**< TIM capture/compare register 3,           Address offset: 0x3C */
    volatile UINT32 CCR4;        /**< TIM capture/compare register 4,           Address offset: 0x40 */
    volatile UINT32 BDTR;        /**< TIM break and dead-time register,         Address offset: 0x44 */
    volatile UINT32 DCR;         /**< TIM DMA control register,                 Address offset: 0x48 */
    volatile UINT32 DMAR;        /**< TIM DMA address for full transfer,        Address offset: 0x4C */
    volatile UINT32 RESERVED1;   /**< Reserved, 0x50                                                 */
    volatile UINT32 CCMR3;       /**< TIM capture/compare mode register 3,      Address offset: 0x54 */
    volatile UINT32 CCR5;        /**< TIM capture/compare register5,            Address offset: 0x58 */
    volatile UINT32 CCR6;        /**< TIM capture/compare register6,            Address offset: 0x5C */
    volatile UINT32 AF1;         /**< TIM alternate function option register 1, Address offset: 0x60 */
    volatile UINT32 AF2;         /**< TIM alternate function option register 2, Address offset: 0x64 */
    volatile UINT32 TISEL;       /**< TIM Input Selection register,             Address offset: 0x68 */
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

#define TIM1_Num  1
#define TIM2_Num  2
#define TIM3_Num  3
#define TIM4_Num  4
#define TIM5_Num  5
#define TIM6_Num  6
#define TIM7_Num  7
#define TIM8_Num  8
#define TIM12_Num 12
#define TIM13_Num 13
#define TIM14_Num 14
#define TIM15_Num 15
#define TIM16_Num 16
#define TIM17_Num 17

/* TIM Clock Source Bit in APB2LPENR Register */
#define TIM1_CLKSRC  (1 << 0)  /**< Bit 0: TIM1 clock source enable */
#define TIM8_CLKSRC  (1 << 1)  /**< Bit 1: TIM8 clock source enable */
#define TIM15_CLKSRC (1 << 16) /**< Bit 16: TIM15 clock source enable */
#define TIM16_CLKSRC (1 << 17) /**< Bit 17: TIM16 clock source enable */
#define TIM17_CLKSRC (1 << 18) /**< Bit 18: TIM17 clock source enable */

/* TIM Clock Source Bit in APB1LLPENR Register */
#define TIM2_CLKSRC  (1 << 0)  /**< Bit 0: TIM2 clock source enable */
#define TIM3_CLKSRC  (1 << 1)  /**< Bit 1: TIM3 clock source enable */
#define TIM4_CLKSRC  (1 << 2)  /**< Bit 2: TIM4 clock source enable */
#define TIM5_CLKSRC  (1 << 3)  /**< Bit 3: TIM5 clock source enable */
#define TIM6_CLKSRC  (1 << 4)  /**< Bit 4: TIM6 clock source enable */
#define TIM7_CLKSRC  (1 << 5)  /**< Bit 5: TIM7 clock source enable */
#define TIM12_CLKSRC (1 << 6)  /**< Bit 6: TIM12 clock source enable */
#define TIM13_CLKSRC (1 << 7)  /**< Bit 7: TIM13 clock source enable */
#define TIM14_CLKSRC (1 << 8)  /**< Bit 8: TIM13 clock source enable */

extern void TIM_Enable_ClockSource(UINT8 TIM_Num);

#endif