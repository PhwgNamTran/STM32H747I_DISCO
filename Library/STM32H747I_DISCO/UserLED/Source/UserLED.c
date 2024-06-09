#include "Common.h"
#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"
#include "UserLED.h"
#include "Project_config.h"

void UserLED_Init(void)
{
    /* Enable clock for UserLED */
    GPIO_Enable_ClockSource(UserLED_ClockSrc);

#if(USER_LED_1_USED == STD_ON)
    GPIO_Mode_Set(UserLED_Port, UserLED_1_PIN, GPIO_Mode_General_Purpose_Output);
    GPIO_Pull_Set(UserLED_Port, UserLED_1_PIN, GPIO_No_Pull);
    GPIO_OutputType_Set(UserLED_Port, UserLED_1_PIN, GPIO_Output_PushPull);
#endif

#if(USER_LED_2_USED == STD_ON)
    GPIO_Mode_Set(UserLED_Port, UserLED_2_PIN, GPIO_Mode_General_Purpose_Output);
    GPIO_Pull_Set(UserLED_Port, UserLED_2_PIN, GPIO_No_Pull);
    GPIO_OutputType_Set(UserLED_Port, UserLED_2_PIN, GPIO_Output_PushPull);
#endif

#if(USER_LED_3_USED == STD_ON)
    GPIO_Mode_Set(UserLED_Port, UserLED_3_PIN, GPIO_Mode_General_Purpose_Output);
    GPIO_Pull_Set(UserLED_Port, UserLED_3_PIN, GPIO_No_Pull);
    GPIO_OutputType_Set(UserLED_Port, UserLED_3_PIN, GPIO_Output_PushPull);
#endif

#if(USER_LED_4_USED == STD_ON)
    GPIO_Mode_Set(UserLED_Port, UserLED_4_PIN, GPIO_Mode_General_Purpose_Output);
    GPIO_Pull_Set(UserLED_Port, UserLED_4_PIN, GPIO_No_Pull);
    GPIO_OutputType_Set(UserLED_Port, UserLED_4_PIN, GPIO_Output_PushPull);
#endif
}