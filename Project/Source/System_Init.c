#include "System_Init.h"
#include "Project_config.h"
#include "UserLED.h"
#include "WkButton.h"
#include "STM32H747XI_SYSCFG.h"
#include "STM32H747XI_EXTI.h"
#include "Common.h"
#include "STM32H747XI_NVIC.h"
/*
Function description: Init function 
Input: N/A
Return value: N/A
*/
void System_Init(void)
{
    
}

/*
Function description: Init periperals 

*/
void Periperals_Init(void)
{
#if(USER_LED_1_USED || USER_LED_2_USED || USER_LED_3_USED || USER_LED_4_USED)
    UserLED_Init();
#endif

#if(WK_BUTTON_USED)
    WK_Button_Init();
    #if(WK_BUTTON_INTERRUPT == STD_ON)
        SYSCFG_Enable();
        SYSCFG_EXITx_GPIO_Cfg(WK_Button_Port_Num, WK_Button_PIN);
        EXTI_Disable_Event_Input_Interrupt_C1(WK_Button_Event_Input);
        EXTI_Disable_Falling_Trigger(WK_Button_Event_Input);
        EXTI_Enable_Rising_Trigger(WK_Button_Event_Input);
        NVIC_EnableIRQ(WK_Button_IRQn);
    #endif
#endif
}