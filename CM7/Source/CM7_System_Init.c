#include "CM7_System_Init.h"
#include "CM7_Project_Cfg.h"
#include "UserLED.h"
#include "WK_Button.h"
#include "STM32H747XI_SYSCFG.h"
#include "STM32H747XI_EXTI.h"
#include "Common.h"
#include "STM32H747XI_NVIC.h"
#include "STM32H747XI_RCC.h"
#include "STM32H747XI_TIM.h"

/*
 * Function: System_Init
 * ---------------------
 * Initializes the system.
 *
 * This function initializes various peripherals and configurations required
 * for the system to operate.
 *
 * Input:
 *   None
 *
 * Returns:
 *   None
 */
void System_Init(void)
{
    // Implement initialization code here
}

void SystemClock_Config(void)
{
#if(System_Clock_Source == System_Clock_Source_HSI)
    CLEAR_BIT(RCC->CR, CR_HSI);
    SET_BIT(RCC->CR, CR_HSI);

    CLEAR_BIT(RCC->CR, (0x3 << CR_HSIDIV_POS));
    SET_BIT(RCC->CR, (((UINT8)sqrt(HSI_DIV) & 0x3) << CR_HSIDIV_POS));
#endif
}

/*
 * Function: Peripherals_Init
 * --------------------------
 * Initializes peripheral devices based on configuration.
 *
 * This function initializes User LEDs and optionally initializes and configures
 * the WK Button based on the project configuration.
 *
 * Input:
 *   None
 *
 * Returns:
 *   None
 */
void Peripherals_Init(void)
{
#if(USER_LED_1_USED)
    UserLED_Init(UserLED_1);
#endif
#if(USER_LED_2_USED)
    UserLED_Init(UserLED_2);
#endif
#if(USER_LED_3_USED)
    UserLED_Init(UserLED_3);
#endif
#if(USER_LED_4_USED)
    UserLED_Init(UserLED_4);
#endif

#if(WK_BUTTON_USED)
    WK_Button_Init();
#if(WK_BUTTON_Interrupt == STD_ON)
    WK_Button_Interrupt_Init();
#endif
#endif
    Timer_2_Init();
}

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
    TIM_Enable_ClockSource(TIMER_NUM_2);          // Enable clock source for Timer 2
    TIM_Config(TIM2, TIM2_PSC, TIM2_ARR, TIM_Direction_Down);  // Configure Timer 2 with prescaler and auto-reload values, set direction down
    TIM_DMA_Interrupt_Mode_Enable(TIM2, TIM_Update_Interrupt);  // Enable DMA interrupt mode for Timer 2 update events
    TIM_DMA_Interrupt_Clear_Status(TIM2);          // Clear DMA interrupt status for Timer 2
    NVIC_EnableIRQ(IRQn_TIM2);                     // Enable NVIC interrupt for Timer 2
    TIM_Enable(TIM2);                              // Enable Timer 2
}
