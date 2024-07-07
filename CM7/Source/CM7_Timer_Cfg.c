#include "Common.h"
#include "STM32H747XI_TIM.h"
#include "STM32H747XI_NVIC.h"
#include "CM7_Project_Cfg.h"
#include "CM7_Timer_Cfg.h"

/*
 * Function: Timer_2_Init
 * ----------------------
 * Initializes Timer 2 for operation.
 * Configures timer settings, enables DMA interrupt mode for update events,
 * enables the NVIC interrupt for Timer 2, and starts Timer 2.
 *
 * Parameters:
 *   None
 *
 * Returns:
 *   None
 */
void Timer_2_Init(void)
{
#if(TIM2_USED)
    TIM_Enable_ClockSource(TIM2_Num);          // Enable clock source for Timer 2
    TIM_Config(TIM2, TIM2_PSC, TIM2_ARR, TIM_Direction_Down);  // Configure Timer 2 with prescaler and auto-reload values, set direction down
#if(TIM2_Interrupt_USED)
    TIM_DMA_Interrupt_Mode_Enable(TIM2, TIM_Update_Interrupt);  // Enable DMA interrupt mode for Timer 2 update events
    TIM_DMA_Interrupt_Clear_Status(TIM2);          // Clear DMA interrupt status for Timer 2
    NVIC_EnableIRQ(IRQn_TIM2);                     // Enable NVIC interrupt for Timer 2
#endif
    TIM_Enable(TIM2);                              // Enable Timer 2
#endif
}