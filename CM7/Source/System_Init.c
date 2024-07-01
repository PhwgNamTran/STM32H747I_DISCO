#include "System_Init.h"
#include "Project_Cfg.h"
#include "UserLED.h"
#include "WK_Button.h"
#include "STM32H747XI_SYSCFG.h"
#include "STM32H747XI_EXTI.h"
#include "Common.h"
#include "STM32H747XI_NVIC.h"
#include "STM32H747XI_RCC.h"

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
    SET_BIT(RCC->CR, (1 << 0));
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
#if(USER_LED_1_USED || USER_LED_2_USED || USER_LED_3_USED || USER_LED_4_USED)
    UserLED_Init();
#endif

#if(WK_BUTTON_USED)
    WK_Button_Init();
#if(WK_BUTTON_Interrupt == STD_ON)
    WK_Button_Interrupt_Init();
#endif
#endif
}
