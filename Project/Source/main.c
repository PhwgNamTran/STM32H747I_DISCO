#include "Common.h"
#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"
#include "UserLED.h"
#include "WkButton.h"


#define LED_ON_STATE    TRUE
#define LED_OFF_STATE   FALSE

void BlinkLED_StateMachine(void)
{
    static BOOL LED_State_B = LED_OFF_STATE;
    switch (LED_State_B)
    {
        case LED_OFF_STATE:
            if(WK_Button_Pressed_then_Released_B())
            {
                UserLED_ON(UserLED_1);
                LED_State_B = LED_ON_STATE;
            }
            break;

        case LED_ON_STATE:
            if(WK_Button_Pressed_then_Released_B())
            {
                UserLED_OFF(UserLED_1);
                LED_State_B = LED_OFF_STATE;
            }
            break;   

        default:
            break;
    }
}

int main(void)
{
    UserLED_Init();
    WK_Button_Init();
    
    UserLED_OFF(UserLED_1);
    UserLED_OFF(UserLED_2);
    UserLED_OFF(UserLED_3);
    UserLED_OFF(UserLED_4);

    while (1) 
    {
        BlinkLED_StateMachine();
    }

    return 0;
}