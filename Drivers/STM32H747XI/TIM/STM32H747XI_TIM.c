#include "STM32H747XI_TIM.h"

/*
 * Function: TIM_Enable_ClockSource
 * --------------------
 * Enables the clock source for a TIM peripheral.
 *
 * Parameters:
 *   TIM_Num: Timer number to enable the clock source for.
 *
 * Returns:
 *   None
 */
void TIM_Enable_ClockSource(UINT8 TIM_Num) {

    switch (TIM_Num)
    {
        case TIM1_Num:
            SET_BIT(RCC->APB2LPENR, TIM1_CLKSRC);  /**< Enable TIM1 clock source */
            break;
        case TIM8_Num:
            SET_BIT(RCC->APB2LPENR, TIM8_CLKSRC);  /**< Enable TIM8 clock source */
            break;
        case TIM15_Num:
            SET_BIT(RCC->APB2LPENR, TIM15_CLKSRC); /**< Enable TIM15 clock source */
            break;
        case TIM16_Num:
            SET_BIT(RCC->APB2LPENR, TIM16_CLKSRC); /**< Enable TIM16 clock source */
            break;
        case TIM17_Num:
            SET_BIT(RCC->APB2LPENR, TIM17_CLKSRC); /**< Enable TIM17 clock source */
            break;
        case TIM2_Num:
            SET_BIT(RCC->APB1LLPENR, TIM2_CLKSRC); /**< Enable TIM2 clock source */
            break;
        case TIM3_Num:
            SET_BIT(RCC->APB1LLPENR, TIM3_CLKSRC); /**< Enable TIM3 clock source */
            break;
        case TIM4_Num:
            SET_BIT(RCC->APB1LLPENR, TIM4_CLKSRC); /**< Enable TIM4 clock source */
            break;
        case TIM5_Num:
            SET_BIT(RCC->APB1LLPENR, TIM5_CLKSRC); /**< Enable TIM5 clock source */
            break;
        case TIM6_Num:
            SET_BIT(RCC->APB1LLPENR, TIM6_CLKSRC); /**< Enable TIM6 clock source */
            break;
        case TIM7_Num:
            SET_BIT(RCC->APB1LLPENR, TIM7_CLKSRC); /**< Enable TIM7 clock source */
            break;
        case TIM12_Num:
            SET_BIT(RCC->APB1LLPENR, TIM12_CLKSRC); /**< Enable TIM12 clock source */
            break;
        case TIM13_Num:
            SET_BIT(RCC->APB1LLPENR, TIM13_CLKSRC); /**< Enable TIM13 clock source */
            break;
        case TIM14_Num:
            SET_BIT(RCC->APB1LLPENR, TIM14_CLKSRC); /**< Enable TIM14 clock source */
            break;
        default:
            // Handle invalid timer number
            break;
    }
}