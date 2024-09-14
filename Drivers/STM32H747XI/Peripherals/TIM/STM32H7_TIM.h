#ifndef STM32H7_TIM_H
#define STM32H7_TIM_H

#include "STM32H747xx.h"
#include "STM32H7_RCC.h"

/* Refer to RM0399 Reference Manual from http://www.st.com and CMSIS Library */

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
extern void TIM_Config(TIM_ST *TIMx, uint32_t TIMx_PSC, uint32_t TIMx_ARR, boolean Counter_Direction);
extern void TIM_DMA_Interrupt_Mode_Enable(TIM_ST *TIMx, uint8_t DMA_Interrupt_Mode);
extern void TIM_DMA_Interrupt_Mode_Disable(TIM_ST *TIMx, uint8_t DMA_Interrupt_Mode);
extern void TIM_DMA_Interrupt_Clear_Status(TIM_ST *TIMx);
extern boolean TIM_DMA_Interrupt_Check_Status(TIM_ST *TIMx);
extern void TIM_Enable(TIM_ST *TIMx);

#endif