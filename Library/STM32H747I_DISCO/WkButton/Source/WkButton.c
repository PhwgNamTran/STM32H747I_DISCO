#include "WkButton.h"
#include "Project_config.h"

void WK_Button_Init(void)
{
    GPIO_Enable_ClockSource(WK_Button_ClockSrc);
    GPIO_Mode_Set(WK_Button_Port, WK_Button_PIN, GPIO_Mode_Input);
    GPIO_Pull_Set(WK_Button_Port, WK_Button_PIN, GPIO_No_Pull);
}

ButtonState_N WK_Button_State(void)
{
    ButtonState_N l_WK_Button_State_N = C_Button_Released_N;

    l_WK_Button_State_N = (ButtonState_N)CHECK_BIT(WK_Button_Port->IDR, (0x1 << WK_Button_PIN));

    return l_WK_Button_State_N;
}

BOOL WK_Button_Pressed_then_Released_B(void)
{
    static ButtonState_N ls_PrevButton_State_N = C_Button_Released_N;

    ButtonState_N ls_CurrButton_State_N = C_Button_Released_N;

    BOOL l_Pressed_then_Released_B = FALSE;

    ls_CurrButton_State_N = WK_Button_State();

    if((ls_CurrButton_State_N == C_Button_Released_N) && (ls_PrevButton_State_N == C_Button_Pressed_N))
    {
        l_Pressed_then_Released_B = TRUE;
    }
    else
    {
        l_Pressed_then_Released_B = FALSE;
    }

    ls_PrevButton_State_N = ls_CurrButton_State_N;

    return l_Pressed_then_Released_B;
}