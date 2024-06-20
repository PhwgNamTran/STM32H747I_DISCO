#include "Common.h"
#include "UserLED.h"
#include "WkButton.h"
#include "Project_config.h"
#include "System_Init.h"


int main(void)
{
    Periperals_Init();
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