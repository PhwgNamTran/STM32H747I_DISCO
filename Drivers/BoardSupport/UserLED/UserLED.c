#include "UserLED.h"

/*
 * Function: UserLED_Init
 * ----------------------
 * Initializes UserLEDs:
 *   - Enables clock source.
 *   - Configures GPIO mode, pull resistor, and output type.
 *   - Sets default state to LED OFF.
 */
void UserLED_Init(UINT8 UserLEDx)
{
    /* Enable clock for UserLED */
    GPIO_Enable_ClockSource(UserLED_ClockSrc);

    switch (UserLEDx)
    {
        case UserLED_1:
            GPIO_Mode_Set(UserLED_Port, UserLED_1_PIN, GPIO_Mode_General_Purpose_Output);
            GPIO_Pull_Set(UserLED_Port, UserLED_1_PIN, GPIO_No_Pull);
            GPIO_OutputType_Set(UserLED_Port, UserLED_1_PIN, GPIO_Output_PushPull);
            UserLED_OFF(UserLED_1);
            break;

        case UserLED_2:
            GPIO_Mode_Set(UserLED_Port, UserLED_2_PIN, GPIO_Mode_General_Purpose_Output);
            GPIO_Pull_Set(UserLED_Port, UserLED_2_PIN, GPIO_No_Pull);
            GPIO_OutputType_Set(UserLED_Port, UserLED_2_PIN, GPIO_Output_PushPull);
            UserLED_OFF(UserLED_2);
            break;

        case UserLED_3:
            GPIO_Mode_Set(UserLED_Port, UserLED_3_PIN, GPIO_Mode_General_Purpose_Output);
            GPIO_Pull_Set(UserLED_Port, UserLED_3_PIN, GPIO_No_Pull);
            GPIO_OutputType_Set(UserLED_Port, UserLED_3_PIN, GPIO_Output_PushPull);
            UserLED_OFF(UserLED_3);
            break;

        case UserLED_4:
            GPIO_Mode_Set(UserLED_Port, UserLED_4_PIN, GPIO_Mode_General_Purpose_Output);
            GPIO_Pull_Set(UserLED_Port, UserLED_4_PIN, GPIO_No_Pull);
            GPIO_OutputType_Set(UserLED_Port, UserLED_4_PIN, GPIO_Output_PushPull);
            UserLED_OFF(UserLED_4);
            break;
    }
}

/*
 * Function: UserLED_ON
 * --------------------
 * Turns ON the specified UserLED.
 *
 * Parameters:
 *   UserLEDx: UserLED number to turn ON (UserLED_1, UserLED_2, UserLED_3, UserLED_4)
 */
void UserLED_ON(UINT8 UserLEDx)
{
    switch (UserLEDx)
    {
        case UserLED_1:
            GPIO_OutputData_Reset(UserLED_Port, UserLED_1_PIN);
            break;

        case UserLED_2:
            GPIO_OutputData_Reset(UserLED_Port, UserLED_2_PIN);
            break;

        case UserLED_3:
            GPIO_OutputData_Reset(UserLED_Port, UserLED_3_PIN);
            break;

        case UserLED_4:
            GPIO_OutputData_Reset(UserLED_Port, UserLED_4_PIN);
            break;

        default:
            break;
    }
}

/*
 * Function: UserLED_OFF
 * ---------------------
 * Turns OFF the specified UserLED.
 *
 * Parameters:
 *   UserLEDx: UserLED number to turn OFF (UserLED_1, UserLED_2, UserLED_3, UserLED_4)
 */
void UserLED_OFF(UINT8 UserLEDx)
{
    switch (UserLEDx)
    {
        case UserLED_1:
            GPIO_OutputData_Set(UserLED_Port, UserLED_1_PIN);
            break;

        case UserLED_2:
            GPIO_OutputData_Set(UserLED_Port, UserLED_2_PIN);
            break;

        case UserLED_3:
            GPIO_OutputData_Set(UserLED_Port, UserLED_3_PIN);
            break;

        case UserLED_4:
            GPIO_OutputData_Set(UserLED_Port, UserLED_4_PIN);
            break;

        default:
            break;
    }
}

/*
 * Function: UserLED_TOGGLE
 * ------------------------
 * Toggles the state of the specified UserLED (ON to OFF or OFF to ON).
 *
 * Parameters:
 *   UserLEDx: UserLED number to toggle (UserLED_1, UserLED_2, UserLED_3, UserLED_4)
 */
void UserLED_TOGGLE(UINT8 UserLEDx)
{
    switch (UserLEDx)
    {
        case UserLED_1:
            GPIO_OutputData_Toggle(UserLED_Port, UserLED_1_PIN);
            break;

        case UserLED_2:
            GPIO_OutputData_Toggle(UserLED_Port, UserLED_2_PIN);
            break;

        case UserLED_3:
            GPIO_OutputData_Toggle(UserLED_Port, UserLED_3_PIN);
            break;

        case UserLED_4:
            GPIO_OutputData_Toggle(UserLED_Port, UserLED_4_PIN);
            break;

        default:
            break;
    }
}
