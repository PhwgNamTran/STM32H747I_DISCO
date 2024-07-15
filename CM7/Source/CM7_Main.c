#include "Common.h"
#include "UserLED.h"
#include "WK_Button.h"
#include "CM7_Project_Cfg.h"
#include "CM7_System_Init.h"
#include "STM32H747XI_USART.h"

int main(void)
{
    /* Initialize peripherals */
    Peripherals_Init();
    SystemClock_Config();
    char DDT = 'a';
    /* Main application loop */
    while (1) 
    {

        DDT = USART_Receive(USART1);
        USART_Transmit(USART1, DDT);
#if (WK_BUTTON_USED && (WK_BUTTON_Interrupt_USED != STD_ON))
        /* Check if WK button is pressed then released */
        if (WK_Button_Released_then_Pressed_B())
        {
            /* Toggle UserLED_1 */
            UserLED_TOGGLE(UserLED_1);
        }
#endif
    }
    
    return 0;
}
