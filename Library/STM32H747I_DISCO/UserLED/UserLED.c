#include "UserLED.h"
#include "Project_config.h"

/*
Function description: Init UserLED.
        - Enable Cloclsource.
        - Config GPIO Mode, Pull resistor and Output type.
        - Set default state to LED OFF.
*/
void UserLED_Init(void)
{
    /* Enable clock for UserLED */
    GPIO_Enable_ClockSource(UserLED_ClockSrc);

#if(USER_LED_1_USED == STD_ON)
    GPIO_Mode_Set(UserLED_Port, UserLED_1_PIN, GPIO_Mode_General_Purpose_Output);
    GPIO_Pull_Set(UserLED_Port, UserLED_1_PIN, GPIO_No_Pull);
    GPIO_OutputType_Set(UserLED_Port, UserLED_1_PIN, GPIO_Output_PushPull);
    UserLED_OFF(UserLED_1);
#endif

#if(USER_LED_2_USED == STD_ON)
    GPIO_Mode_Set(UserLED_Port, UserLED_2_PIN, GPIO_Mode_General_Purpose_Output);
    GPIO_Pull_Set(UserLED_Port, UserLED_2_PIN, GPIO_No_Pull);
    GPIO_OutputType_Set(UserLED_Port, UserLED_2_PIN, GPIO_Output_PushPull);
    UserLED_OFF(UserLED_2);
#endif

#if(USER_LED_3_USED == STD_ON)
    GPIO_Mode_Set(UserLED_Port, UserLED_3_PIN, GPIO_Mode_General_Purpose_Output);
    GPIO_Pull_Set(UserLED_Port, UserLED_3_PIN, GPIO_No_Pull);
    GPIO_OutputType_Set(UserLED_Port, UserLED_3_PIN, GPIO_Output_PushPull);
    UserLED_OFF(UserLED_3);
#endif

#if(USER_LED_4_USED == STD_ON)
    GPIO_Mode_Set(UserLED_Port, UserLED_4_PIN, GPIO_Mode_General_Purpose_Output);
    GPIO_Pull_Set(UserLED_Port, UserLED_4_PIN, GPIO_No_Pull);
    GPIO_OutputType_Set(UserLED_Port, UserLED_4_PIN, GPIO_Output_PushPull);
    UserLED_OFF(UserLED_4);
#endif
}

/*
Function description: Turn ON UserLED.
*/
void UserLED_ON(UINT8 UserLEDx)
{
    switch (UserLEDx)
    {
#if(USER_LED_1_USED == STD_ON)
        case UserLED_1:
            GPIO_OutputData_Reset(UserLED_Port, UserLED_1_PIN);
            break;
#endif
#if(USER_LED_2_USED == STD_ON)
        case UserLED_2:
            GPIO_OutputData_Reset(UserLED_Port, UserLED_2_PIN);
            break;
#endif
#if(USER_LED_3_USED == STD_ON)
        case UserLED_3:
            GPIO_OutputData_Reset(UserLED_Port, UserLED_3_PIN);
            break;
#endif
#if(USER_LED_4_USED == STD_ON)
        case UserLED_4:
            GPIO_OutputData_Reset(UserLED_Port, UserLED_4_PIN);
            break;
#endif
        default:
            break;
    }
}

/*
Function description: Turn OFF UserLED.
*/
void UserLED_OFF(UINT8 UserLEDx)
{
    switch (UserLEDx)
    {
#if(USER_LED_1_USED == STD_ON)
        case UserLED_1:
            GPIO_OutputData_Set(UserLED_Port, UserLED_1_PIN);
            break;
#endif
#if(USER_LED_2_USED == STD_ON)
        case UserLED_2:
            GPIO_OutputData_Set(UserLED_Port, UserLED_2_PIN);
            break;
#endif
#if(USER_LED_3_USED == STD_ON)
        case UserLED_3:
            GPIO_OutputData_Set(UserLED_Port, UserLED_3_PIN);
            break;
#endif
#if(USER_LED_4_USED == STD_ON)
        case UserLED_4:
            GPIO_OutputData_Set(UserLED_Port, UserLED_4_PIN);
            break;
#endif
        default:
            break;
    }
}

/*
Function description: TOGGLE UserLED.
*/
void UserLED_TOGGLE(UINT8 UserLEDx)
{
    switch (UserLEDx)
    {
#if(USER_LED_1_USED == STD_ON)
        case UserLED_1:
            GPIO_OutputData_Toggle(UserLED_Port, UserLED_1_PIN);
            break;
#endif
#if(USER_LED_2_USED == STD_ON)
        case UserLED_2:
            GPIO_OutputData_Toggle(UserLED_Port, UserLED_2_PIN);
            break;
#endif
#if(USER_LED_3_USED == STD_ON)
        case UserLED_3:
            GPIO_OutputData_Toggle(UserLED_Port, UserLED_3_PIN);
            break;
#endif
#if(USER_LED_4_USED == STD_ON)
        case UserLED_4:
            GPIO_OutputData_Toggle(UserLED_Port, UserLED_4_PIN);
            break;
#endif
        default:
            break;
    }
}