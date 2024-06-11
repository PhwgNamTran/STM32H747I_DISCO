#include "System_Init.h"
#include "Project_config.h"
#include "UserLED.h"
#include "WkButton.h"
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
#endif
}