#include "CM7_System_Init.h"
#include "CM7_Project_Cfg.h"
#include "UserLED.h"
#include "WK_Button.h"
#include "STLink_VCP.h"
#include "STM32H747XI_SYSCFG.h"
#include "STM32H747XI_EXTI.h"
#include "Common.h"
#include "STM32H747XI_NVIC.h"
#include "STM32H747XI_RCC.h"
#include "STM32H747XI_TIM.h"
#include "CM7_Timer_Cfg.h"

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
    SET_BIT(RCC->CR, (((uint8_t)sqrt(HSI_DIV) & 0x3) << CR_HSIDIV_POS));
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
#if(WK_BUTTON_Interrupt_USED)
    WK_Button_Interrupt_Init();
#endif
#endif

#if(STLINK_VCP_USED)
    STLink_VCP_Init(System_Clock, STLink_VCP_USART_Mode);
#if(STLink_VCP_Interrupt_USED)
    STLink_VCP_Interrupt_Init(STLink_VCP_USART_Interrupt_Mode);
#endif
#endif

#if(TIM2_USED)
    Timer_2_Init();
#endif

}

