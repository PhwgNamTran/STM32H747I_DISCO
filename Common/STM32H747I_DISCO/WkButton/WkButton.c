#include "WkButton.h"
#include "Project_Cfg.h"

/*
 * Function: WK_Button_Init
 * ------------------------
 * Initializes the WK Button.
 *
 * - Enables Clock source.
 * - Configures GPIO Mode as Input.
 * - No Pull up/down resistor needed because it already has a pull-down resistor at the HW level.
 */
void WK_Button_Init(void)
{
    GPIO_Enable_ClockSource(WK_Button_ClockSrc);
    GPIO_Mode_Set(WK_Button_Port, WK_Button_PIN, GPIO_Mode_Input);
    GPIO_Pull_Set(WK_Button_Port, WK_Button_PIN, GPIO_No_Pull);
}

/*
 * Function: WK_Button_Interrupt_Init
 * ----------------------------------
 * Initializes WK Button Interrupt.
 *
 * - Enables SYSCFG Clock source.
 * - Configures EXTI GPIO for WK Button.
 * - Enables Rising trigger and disables Falling trigger for WK Button event input.
 * - Enables NVIC IRQ for WK Button.
 */
void WK_Button_Interrupt_Init(void)
{
    SYSCFG_Enable();
    SYSCFG_EXITx_GPIO_Cfg(WK_Button_Port_Num, WK_Button_PIN);
    EXTI_Enable_Event_Input_Interrupt_C1(WK_Button_Event_Input);
    EXTI_Disable_Falling_Trigger(WK_Button_Event_Input);
    EXTI_Enable_Rising_Trigger(WK_Button_Event_Input);
    NVIC_EnableIRQ(WK_Button_IRQn);
}

/*
 * Function: WK_Button_State
 * -------------------------
 * Checks the status of the WK Button.
 *
 * Returns:
 *   Button state:
 *   - C_Button_Released_N (0): Button is released.
 *   - C_Button_Pressed_N (1): Button is pressed.
 */
ButtonState_N WK_Button_State(void)
{
    ButtonState_N l_WK_Button_State_N = C_Button_Released_N;
    l_WK_Button_State_N = (ButtonState_N)CHECK_BIT(WK_Button_Port->IDR, (0x1 << WK_Button_PIN));
    return l_WK_Button_State_N;
}

/*
 * Function: WK_Button_Pressed_then_Released_B
 * -------------------------------------------
 * Checks if WK Button state changed from pressed to released.
 *
 * Returns:
 *   - TRUE if button state changed from pressed to released, FALSE otherwise.
 *
 * Note: This function should be called under a cyclic function or in while(1).
 */
BOOL WK_Button_Pressed_then_Released_B(void)
{
    static ButtonState_N ls_PrevButton_State_N = C_Button_Released_N;
    ButtonState_N ls_CurrButton_State_N = C_Button_Released_N;
    BOOL l_Pressed_then_Released_B = FALSE;

    ls_CurrButton_State_N = WK_Button_State();

    if ((ls_CurrButton_State_N == C_Button_Released_N) && (ls_PrevButton_State_N == C_Button_Pressed_N))
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

/*
 * Function: WK_Button_Released_then_Pressed_B
 * -------------------------------------------
 * Checks if WK Button state changed from released to pressed.
 *
 * Returns:
 *   - TRUE if button state changed from released to pressed, FALSE otherwise.
 *
 * Note: This function should be called under a cyclic function or in while(1).
 */
BOOL WK_Button_Released_then_Pressed_B(void)
{
    static ButtonState_N ls_PrevButton_State_N = C_Button_Released_N;
    ButtonState_N ls_CurrButton_State_N = C_Button_Released_N;
    BOOL l_Released_then_Pressed_B = FALSE;

    ls_CurrButton_State_N = WK_Button_State();

    if ((ls_PrevButton_State_N == C_Button_Released_N) && (ls_CurrButton_State_N == C_Button_Pressed_N))
    {
        l_Released_then_Pressed_B = TRUE;
    }
    else
    {
        l_Released_then_Pressed_B = FALSE;
    }

    ls_PrevButton_State_N = ls_CurrButton_State_N;

    return l_Released_then_Pressed_B;
}