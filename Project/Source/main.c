#include "Common.h"
#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"
#include "UserLED.h"
#include "WkButton.h"


int main(void)
{
    while (1) 
    {
        if(WK_Button_Pressed_then_Released_B())
        {
            UserLED_TOGGLE(UserLED_1);
        }
    }
    return 0;
}