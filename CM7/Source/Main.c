#include "Common.h"
#include "UserLED.h"
#include "WkButton.h"
#include "Project_Cfg.h"
#include "System_Init.h"

int main(void)
{
    /* Initialize peripherals */
    Peripherals_Init();
    
    /* Main application loop */
    while (1) 
    {
#if (WK_BUTTON_Interrupt != STD_ON)
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
