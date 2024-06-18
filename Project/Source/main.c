#include "Common.h"
#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"
#include "UserLED.h"
#include "WkButton.h"
#include "Project_config.h"


int main(void)
{
    while (1) 
    {
#if(WK_BUTTON_Interrupt != STD_ON)
        if(WK_Button_Pressed_then_Released_B())
        {
            UserLED_TOGGLE(UserLED_1);
        }
#endif
    }
    return 0;
}