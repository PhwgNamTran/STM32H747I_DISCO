#include "STM32H7_EXTI.h"

/*
 * Function: EXTI_Enable_Event_Input_Interrupt_CPU1
 * --------------------
 * Enables event input interrupt for Cortex-M7 core.
 *
 * Parameters:
 *   Event_Input: Event input number from 0 to 88.
 *
 * Returns:
 *   None
 */
void EXTI_Enable_Event_Input_Interrupt_CPU1(Event_Input_N Event_Input)
{
    uint8_t C1IMR_idx = 0;
    uint8_t C1IMR_pos = 0;

    C1IMR_idx = Event_Input / 32;
    C1IMR_pos = Event_Input % 32;

    switch (C1IMR_idx)
    {
        case 0:
            SET_BIT(EXTI_D1->IMR1, (1 << C1IMR_pos));
            break;

        case 1:
            SET_BIT(EXTI_D1->IMR2, (1 << C1IMR_pos));
            break;

        case 2:
            SET_BIT(EXTI_D1->IMR3, (1 << C1IMR_pos));
            break;

        default:
            break;
    }
}

/*
 * Function: EXTI_Enable_Event_Input_Interrupt_CPU2
 * --------------------
 * Enables event input interrupt for Cortex-M4 core.
 *
 * Parameters:
 *   Event_Input: Event input number from 0 to 88.
 *
 * Returns:
 *   None
 */
void EXTI_Enable_Event_Input_Interrupt_CPU2(Event_Input_N Event_Input)
{
    uint8_t C2IMR_idx = 0;
    uint8_t C2IMR_pos = 0;

    C2IMR_idx = Event_Input / 32;
    C2IMR_pos = Event_Input % 32;

    switch (C2IMR_idx)
    {
        case 0:
            SET_BIT(EXTI_D2->IMR1, (1 << C2IMR_pos));
            break;

        case 1:
            SET_BIT(EXTI_D2->IMR2, (1 << C2IMR_pos));
            break;

        case 2:
            SET_BIT(EXTI_D2->IMR3, (1 << C2IMR_pos));
            break;

        default:
            break;
    }
}

/*
 * Function: EXTI_Disable_Event_Input_Interrupt_CPU1
 * --------------------
 * Disables event input interrupt for Cortex-M7 core.
 *
 * Parameters:
 *   Event_Input: Event input number from 0 to 88.
 *
 * Returns:
 *   None
 */
void EXTI_Disable_Event_Input_Interrupt_CPU1(Event_Input_N Event_Input)
{
    uint8_t C1IMR_idx = 0;
    uint8_t C1IMR_pos = 0;

    C1IMR_idx = Event_Input / 32;
    C1IMR_pos = Event_Input % 32;

    switch (C1IMR_idx)
    {
        case 0:
            CLEAR_BIT(EXTI_D1->IMR1, (1 << C1IMR_pos));
            break;

        case 1:
            CLEAR_BIT(EXTI_D1->IMR2, (1 << C1IMR_pos));
            break;

        case 2:
            CLEAR_BIT(EXTI_D1->IMR3, (1 << C1IMR_pos));
            break;

        default:
            break;
    }
}

/*
 * Function: EXTI_Disable_Event_Input_Interrupt_CPU2
 * --------------------
 * Disables event input interrupt for Cortex-M4 core.
 *
 * Parameters:
 *   Event_Input: Event input number from 0 to 88.
 *
 * Returns:
 *   None
 */
void EXTI_Disable_Event_Input_Interrupt_CPU2(Event_Input_N Event_Input)
{
    uint8_t C2IMR_idx = 0;
    uint8_t C2IMR_pos = 0;

    C2IMR_idx = Event_Input / 32;
    C2IMR_pos = Event_Input % 32;

    switch (C2IMR_idx)
    {
        case 0:
            CLEAR_BIT(EXTI_D2->IMR1, (1 << C2IMR_pos));
            break;

        case 1:
            CLEAR_BIT(EXTI_D2->IMR2, (1 << C2IMR_pos));
            break;

        case 2:
            CLEAR_BIT(EXTI_D2->IMR3, (1 << C2IMR_pos));
            break;

        default:
            break;
    }
}

/*
 * Function: EXTI_Trigger_Request_Occurred_CPU1_B
 * --------------------
 * Checks if EXTI trigger request has occurred for Cortex-M7 core.
 *
 * Parameters:
 *   Event_Input: Event input number from 0 to 88.
 *
 * Returns:
 *   TRUE: Selected trigger request occurred.
 *   FALSE: No trigger request occurred.
 */
boolean EXTI_Trigger_Request_Occurred_CPU1_B(Event_Input_N Event_Input)
{
    uint8_t PR_idx = 0;
    uint8_t PR_pos = 0;

    PR_idx = Event_Input / 32;
    PR_pos = Event_Input % 32;

    boolean Request_Occurred_B = false;

    switch (PR_idx)
    {
        case 0:
            Request_Occurred_B = CHECK_BIT(EXTI->PR1, (1 << PR_pos));
            break;

        case 1:
            Request_Occurred_B = CHECK_BIT(EXTI->PR2, (1 << PR_pos));
            break;

        case 2:
            Request_Occurred_B = CHECK_BIT(EXTI->PR3, (1 << PR_pos));
            break;

        default:
            break;
    }

    return Request_Occurred_B;
}

/*
 * Function: EXTI_Trigger_Request_Occurred_CPU2_B
 * --------------------
 * Checks if EXTI trigger request has occurred for Cortex-M4 core.
 *
 * Parameters:
 *   Event_Input: Event input number from 0 to 88.
 *
 * Returns:
 *   TRUE: Selected trigger request occurred.
 *   FALSE: No trigger request occurred.
 */
boolean EXTI_Trigger_Request_Occurred_CPU2_B(Event_Input_N Event_Input)
{
    uint8_t PR_idx = 0;
    uint8_t PR_pos = 0;

    PR_idx = Event_Input / 32;
    PR_pos = Event_Input % 32;

    boolean Request_Occurred_B = false;

    switch (PR_idx)
    {
        case 0:
            Request_Occurred_B = CHECK_BIT(EXTI->C2PR1, (1 << PR_pos));
            break;

        case 1:
            Request_Occurred_B = CHECK_BIT(EXTI->C2PR2, (1 << PR_pos));
            break;

        case 2:
            Request_Occurred_B = CHECK_BIT(EXTI->C2PR3, (1 << PR_pos));
            break;

        default:
            break;
    }

    return Request_Occurred_B;
}

/*
 * Function: EXTI_Clear_Trigger_Request_Flag_CPU1
 * --------------------
 * Clears the trigger request flag for Cortex-M7 core.
 *
 * Parameters:
 *   Event_Input: Event input number from 0 to 88.
 *
 * Returns:
 *   None
 */
void EXTI_Clear_Trigger_Request_Flag_CPU1(Event_Input_N Event_Input)
{
    uint8_t PR_idx = 0;
    uint8_t PR_pos = 0;

    PR_idx = Event_Input / 32;
    PR_pos = Event_Input % 32;

    switch (PR_idx)
    {
        case 0:
            SET_BIT(EXTI->PR1, (1 << PR_pos));
            break;

        case 1:
            SET_BIT(EXTI->PR2, (1 << PR_pos));
            break;

        case 2:
            SET_BIT(EXTI->PR3, (1 << PR_pos));
            break;

        default:
            break;
    }
}

/*
 * Function: EXTI_Clear_Trigger_Request_Flag_CPU2
 * --------------------
 * Clears the trigger request flag for Cortex-M4 core.
 *
 * Parameters:
 *   Event_Input: Event input number from 0 to 88.
 *
 * Returns:
 *   None
 */
void EXTI_Clear_Trigger_Request_Flag_CPU2(Event_Input_N Event_Input)
{
    uint8_t PR_idx = 0;
    uint8_t PR_pos = 0;

    PR_idx = Event_Input / 32;
    PR_pos = Event_Input % 32;

    switch (PR_idx)
    {
        case 0:
            SET_BIT(EXTI->C2PR1, (1 << PR_pos));
            break;

        case 1:
            SET_BIT(EXTI->C2PR2, (1 << PR_pos));
            break;

        case 2:
            SET_BIT(EXTI->C2PR3, (1 << PR_pos));
            break;

        default:
            break;
    }
}

/*
 * Function: EXTI_Enable_Rising_Trigger
 * --------------------
 * Enables rising trigger for configurable event input for Cortex-M7 and M4 cores.
 *
 * Parameters:
 *   Event_Input: Event input number from 0 to 88.
 *
 * Returns:
 *   None
 */
void EXTI_Enable_Rising_Trigger(Event_Input_N Event_Input)
{
    uint8_t RTSR_idx = 0;
    uint8_t RTSR_pos = 0;

    RTSR_idx = Event_Input / 32;
    RTSR_pos = Event_Input % 32;

    switch (RTSR_idx)
    {
        case 0:
            SET_BIT(EXTI->RTSR1, (1 << RTSR_pos));
            break;

        case 1:
            SET_BIT(EXTI->RTSR2, (1 << RTSR_pos));
            break;

        case 2:
            SET_BIT(EXTI->RTSR3, (1 << RTSR_pos));
            break;

        default:
            break;
    }
}

/*
 * Function: EXTI_Disable_Rising_Trigger
 * --------------------
 * Disables rising trigger for configurable event input for Cortex-M7 and M4 cores.
 *
 * Parameters:
 *   Event_Input: Event input number from 0 to 88.
 *
 * Returns:
 *   None
 */
void EXTI_Disable_Rising_Trigger(Event_Input_N Event_Input)
{
    uint8_t RTSR_idx = 0;
    uint8_t RTSR_pos = 0;

    RTSR_idx = Event_Input / 32;
    RTSR_pos = Event_Input % 32;

    switch (RTSR_idx)
    {
        case 0:
            CLEAR_BIT(EXTI->RTSR1, (1 << RTSR_pos));
            break;

        case 1:
            CLEAR_BIT(EXTI->RTSR2, (1 << RTSR_pos));
            break;

        case 2:
            CLEAR_BIT(EXTI->RTSR3, (1 << RTSR_pos));
            break;

        default:
            break;
    }
}

/*
 * Function: EXTI_Enable_Falling_Trigger
 * --------------------
 * Enables falling trigger for configurable event input for Cortex-M7 and M4 cores.
 *
 * Parameters:
 *   Event_Input: Event input number from 0 to 88.
 *
 * Returns:
 *   None
 */
void EXTI_Enable_Falling_Trigger(Event_Input_N Event_Input)
{
    uint8_t FTSR_idx = 0;
    uint8_t FTSR_pos = 0;

    FTSR_idx = Event_Input / 32;
    FTSR_pos = Event_Input % 32;

    switch (FTSR_idx)
    {
        case 0:
            SET_BIT(EXTI->FTSR1, (1 << FTSR_pos));
            break;

        case 1:
            SET_BIT(EXTI->FTSR2, (1 << FTSR_pos));
            break;

        case 2:
            SET_BIT(EXTI->FTSR3, (1 << FTSR_pos));
            break;

        default:
            break;
    }
}

/*
 * Function: EXTI_Disable_Falling_Trigger
 * --------------------
 * Disables falling trigger for configurable event input for Cortex-M7 and M4 cores.
 *
 * Parameters:
 *   Event_Input: Event input number from 0 to 88.
 *
 * Returns:
 *   None
 */
void EXTI_Disable_Falling_Trigger(Event_Input_N Event_Input)
{
    uint8_t FTSR_idx = 0;
    uint8_t FTSR_pos = 0;

    FTSR_idx = Event_Input / 32;
    FTSR_pos = Event_Input % 32;

    switch (FTSR_idx)
    {
        case 0:
            CLEAR_BIT(EXTI->FTSR1, (1 << FTSR_pos));
            break;

        case 1:
            CLEAR_BIT(EXTI->FTSR2, (1 << FTSR_pos));
            break;

        case 2:
            CLEAR_BIT(EXTI->FTSR3, (1 << FTSR_pos));
            break;

        default:
            break;
    }
}


