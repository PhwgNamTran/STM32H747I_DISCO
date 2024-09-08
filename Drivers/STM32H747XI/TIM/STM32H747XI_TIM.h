#ifndef STM32H747XI_TIM_H
#define STM32H747XI_TIM_H

#include "Common.h"
#include "STM32H747XI_RCC.h"

/* Refer to RM0399 Reference Manual from http://www.st.com and CMSIS Library */

/* TIM Register - Refer to CMSIS Library */
typedef struct
{
    volatile uint32_t CR1;         /**< TIM control register 1,                   Address offset: 0x00 */
    volatile uint32_t CR2;         /**< TIM control register 2,                   Address offset: 0x04 */
    volatile uint32_t SMCR;        /**< TIM slave mode control register,          Address offset: 0x08 */
    volatile uint32_t DIER;        /**< TIM DMA/interrupt enable register,        Address offset: 0x0C */
    volatile uint32_t SR;          /**< TIM status register,                      Address offset: 0x10 */
    volatile uint32_t EGR;         /**< TIM event generation register,            Address offset: 0x14 */
    volatile uint32_t CCMR1;       /**< TIM capture/compare mode register 1,      Address offset: 0x18 */
    volatile uint32_t CCMR2;       /**< TIM capture/compare mode register 2,      Address offset: 0x1C */
    volatile uint32_t CCER;        /**< TIM capture/compare enable register,      Address offset: 0x20 */
    volatile uint32_t CNT;         /**< TIM counter register,                     Address offset: 0x24 */
    volatile uint32_t PSC;         /**< TIM prescaler,                            Address offset: 0x28 */
    volatile uint32_t ARR;         /**< TIM auto-reload register,                 Address offset: 0x2C */
    volatile uint32_t RCR;         /**< TIM repetition counter register,          Address offset: 0x30 */
    volatile uint32_t CCR1;        /**< TIM capture/compare register 1,           Address offset: 0x34 */
    volatile uint32_t CCR2;        /**< TIM capture/compare register 2,           Address offset: 0x38 */
    volatile uint32_t CCR3;        /**< TIM capture/compare register 3,           Address offset: 0x3C */
    volatile uint32_t CCR4;        /**< TIM capture/compare register 4,           Address offset: 0x40 */
    volatile uint32_t BDTR;        /**< TIM break and dead-time register,         Address offset: 0x44 */
    volatile uint32_t DCR;         /**< TIM DMA control register,                 Address offset: 0x48 */
    volatile uint32_t DMAR;        /**< TIM DMA address for full transfer,        Address offset: 0x4C */
    volatile uint32_t RESERVED1;   /**< Reserved, 0x50                                                 */
    volatile uint32_t CCMR3;       /**< TIM capture/compare mode register 3,      Address offset: 0x54 */
    volatile uint32_t CCR5;        /**< TIM capture/compare register5,            Address offset: 0x58 */
    volatile uint32_t CCR6;        /**< TIM capture/compare register6,            Address offset: 0x5C */
    volatile uint32_t AF1;         /**< TIM alternate function option register 1, Address offset: 0x60 */
    volatile uint32_t AF2;         /**< TIM alternate function option register 2, Address offset: 0x64 */
    volatile uint32_t TISEL;       /**< TIM Input Selection register,             Address offset: 0x68 */
} TIM_ST;

// Control Register 1 (CR1) Bit Definitions
#define CR1_CEN     (1 << 0)  // Counter enable bit in the TIM CR1 register
#define CR1_DIR     (1 << 4)  // Direction bit in the TIM CR1 register

// Status Register (SR) Bit Definitions
#define SR_UIF      (1 << 0)  // Update interrupt flag

// Counter Direction Options
#define TIM_Direction_Up            FALSE  // Up-counting mode
#define TIM_Direction_Down          TRUE   // Down-counting mode

// DMA and Interrupt Modes
#define TIM_No_DMA_Interrupt        255U   // No DMA/Interrupt
#define TIM_Update_Interrupt        0U     // Update interrupt
#define TIM_CC1_Interrupt           1U     // Capture/Compare 1 interrupt
#define TIM_CC2_Interrupt           2U     // Capture/Compare 2 interrupt
#define TIM_CC3_Interrupt           3U     // Capture/Compare 3 interrupt
#define TIM_CC4_Interrupt           4U     // Capture/Compare 4 interrupt
#define TIM_COM_Interrupt           5U     // Communication interrupt
#define TIM_Trigger_Interrupt       6U     // Trigger interrupt
#define TIM_Break_Interrupt         7U     // Break interrupt
#define TIM_Update_DMA_Request      8U     // Update DMA request
#define TIM_CC1_DMA_Request         9U     // Capture/Compare 1 DMA request
#define TIM_CC2_DMA_Request         10U    // Capture/Compare 2 DMA request
#define TIM_CC3_DMA_Request         11U    // Capture/Compare 3 DMA request
#define TIM_CC4_DMA_Request         12U    // Capture/Compare 4 DMA request
#define TIM_COM_DMA_Request         13U    // Communication DMA request
#define TIM_Trigger_DMA_Request     14U    // Trigger DMA request
#define TIM_DMA_Interrupt_Reserved  15U    // Reserved DMA/Interrupt

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

extern void TIM_Enable_ClockSource(TIM_ST *TIMx);
extern void TIM_Config(TIM_ST *TIMx, uint32_t TIMx_PSC, uint32_t TIMx_ARR, BOOL Counter_Direction);
extern void TIM_DMA_Interrupt_Mode_Enable(TIM_ST *TIMx, uint8_t DMA_Interrupt_Mode);
extern void TIM_DMA_Interrupt_Mode_Disable(TIM_ST *TIMx, uint8_t DMA_Interrupt_Mode);
extern void TIM_DMA_Interrupt_Clear_Status(TIM_ST *TIMx);
extern BOOL TIM_DMA_Interrupt_Check_Status(TIM_ST *TIMx);
extern void TIM_Enable(TIM_ST *TIMx);

#endif