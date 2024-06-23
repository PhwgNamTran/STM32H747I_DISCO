#include "System_Init.h"
#include "Project_Cfg.h"
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
#if(WK_BUTTON_Interrupt == STD_ON)
    WK_Button_Interrupt_Init();
#endif
#endif
}