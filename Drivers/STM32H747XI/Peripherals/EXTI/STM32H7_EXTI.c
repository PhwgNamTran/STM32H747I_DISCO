#include "STM32H7_EXTI.h"

/*
 * Function: EXTI_EventInput_Interrupt_Enable_CPU1
 * -----------------------------------------------
 * Enables the EXTI event input interrupt for CPU1 by setting the corresponding bit in the EXTI
 * interrupt mask registers (IMR1, IMR2, or IMR3) based on the specified event input.
 *
 * This function calculates the index and position within the interrupt mask registers (IMR) for the
 * given EXTI event input, and sets the appropriate bit in the corresponding register to enable the
 * interrupt.
 *
 * Parameters:
 *   EventInput - The EXTI event input to enable the interrupt for. This is of type EXTI_EventInput_N
 *                which corresponds to specific external events or peripherals.
 *
 * Returns:
 *   ReturnType - E_OK if the operation is successful.
 */
ReturnType EXTI_EventInput_Interrupt_Enable_CPU1(EXTI_EventInput_N EventInput)
{
    uint8_t C1IMR_idx = 0; // Index of the interrupt mask register (IMR)
    uint8_t C1IMR_pos = 0; // Position of the event input within the register

    // Calculate the IMR index and position based on the EventInput value
    C1IMR_idx = EventInput / 32;
    C1IMR_pos = EventInput % 32;

    // Set the corresponding bit in the appropriate IMR register to enable the interrupt
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
            break; // Invalid index, no action taken
    }

    return E_OK; // Return successful operation
}


/*
 * Function: EXTI_EventInput_Interrupt_Enable_CPU2
 * -----------------------------------------------
 * Enables the EXTI event input interrupt for CPU2 by setting the corresponding bit in the EXTI
 * interrupt mask registers (IMR1, IMR2, or IMR3) based on the specified event input.
 *
 * This function calculates the index and position within the interrupt mask registers (IMR) for the
 * given EXTI event input, and sets the appropriate bit in the corresponding register to enable the
 * interrupt.
 *
 * Parameters:
 *   EventInput - The EXTI event input to enable the interrupt for. This is of type EXTI_EventInput_N
 *                which corresponds to specific external events or peripherals.
 *
 * Returns:
 *   ReturnType - E_OK if the operation is successful.
 */
ReturnType EXTI_EventInput_Interrupt_Enable_CPU2(EXTI_EventInput_N EventInput)
{
    uint8_t C2IMR_idx = 0; // Index of the interrupt mask register (IMR)
    uint8_t C2IMR_pos = 0; // Position of the event input within the register

    // Calculate the IMR index and position based on the EventInput value
    C2IMR_idx = EventInput / 32;
    C2IMR_pos = EventInput % 32;

    // Set the corresponding bit in the appropriate IMR register to enable the interrupt for CPU2
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
            break; // Invalid index, no action taken
    }

    return E_OK; // Return successful operation
}


/*
 * Function: EXTI_EventInput_Interrupt_Disable_CPU1
 * ------------------------------------------------
 * Disables the EXTI event input interrupt for CPU1 by clearing the corresponding bit in the EXTI
 * interrupt mask registers (IMR1, IMR2, or IMR3) based on the specified event input.
 *
 * This function calculates the index and position within the interrupt mask registers (IMR) for the
 * given EXTI event input, and clears the appropriate bit in the corresponding register to disable the
 * interrupt.
 *
 * Parameters:
 *   EventInput - The EXTI event input to disable the interrupt for. This is of type EXTI_EventInput_N
 *                which corresponds to specific external events or peripherals.
 *
 * Returns:
 *   ReturnType - E_OK if the operation is successful.
 */
ReturnType EXTI_EventInput_Interrupt_Disable_CPU1(EXTI_EventInput_N EventInput)
{
    uint8_t C1IMR_idx = 0; // Index of the interrupt mask register (IMR)
    uint8_t C1IMR_pos = 0; // Position of the event input within the register

    // Calculate the IMR index and position based on the EventInput value
    C1IMR_idx = EventInput / 32;
    C1IMR_pos = EventInput % 32;

    // Clear the corresponding bit in the appropriate IMR register to disable the interrupt
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
            break; // Invalid index, no action taken
    }

    return E_OK; // Return successful operation
}


/*
 * Function: EXTI_EventInput_Interrupt_Disable_CPU2
 * ------------------------------------------------
 * Disables the EXTI event input interrupt for CPU2 by clearing the corresponding bit in the EXTI
 * interrupt mask registers (IMR1, IMR2, or IMR3) based on the specified event input.
 *
 * This function calculates the index and position within the interrupt mask registers (IMR) for the
 * given EXTI event input, and clears the appropriate bit in the corresponding register to disable the
 * interrupt.
 *
 * Parameters:
 *   EventInput - The EXTI event input to disable the interrupt for. This is of type EXTI_EventInput_N
 *                which corresponds to specific external events or peripherals.
 *
 * Returns:
 *   ReturnType - E_OK if the operation is successful.
 */
ReturnType EXTI_EventInput_Interrupt_Disable_CPU2(EXTI_EventInput_N EventInput)
{
    uint8_t C2IMR_idx = 0; // Index of the interrupt mask register (IMR)
    uint8_t C2IMR_pos = 0; // Position of the event input within the register

    // Calculate the IMR index and position based on the EventInput value
    C2IMR_idx = EventInput / 32;
    C2IMR_pos = EventInput % 32;

    // Clear the corresponding bit in the appropriate IMR register to disable the interrupt for CPU2
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
            break; // Invalid index, no action taken
    }

    return E_OK; // Return successful operation
}

/*
 * Function: EXTI_Trigger_Request_Occurred_CPU1_B
 * ----------------------------------------------
 * Checks whether an EXTI trigger request has occurred for the specified event input on CPU1.
 * This is determined by checking the corresponding bit in the EXTI pending register (PR1, PR2, or PR3).
 *
 * The function calculates the index and position within the pending registers (PR) based on the given
 * EXTI event input, and checks whether the corresponding bit is set, indicating a trigger request.
 *
 * Parameters:
 *   EventInput - The EXTI event input to check for a trigger request. This is of type EXTI_EventInput_N
 *                which corresponds to specific external events or peripherals.
 *
 * Returns:
 *   boolean - true if the trigger request has occurred, false otherwise.
 */
boolean EXTI_Trigger_Request_Occurred_CPU1_B(EXTI_EventInput_N EventInput)
{
    uint8_t PR_idx = 0;  // Index of the pending register (PR)
    uint8_t PR_pos = 0;  // Position of the event input within the register

    PR_idx = EventInput / 32;
    PR_pos = EventInput % 32;

    boolean Request_Occurred_B = false; // Default to false, meaning no request has occurred

    // Check the corresponding bit in the appropriate PR register to determine if a request occurred
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
            break; // Invalid index, no action taken
    }

    return Request_Occurred_B; // Return whether the trigger request occurred
}


/*
 * Function: EXTI_Trigger_Request_Occurred_CPU2_B
 * ----------------------------------------------
 * Checks whether an EXTI trigger request has occurred for the specified event input on CPU2.
 * This is determined by checking the corresponding bit in the EXTI pending register (C2PR1, C2PR2, or C2PR3).
 *
 * The function calculates the index and position within the pending registers (C2PR) based on the given
 * EXTI event input, and checks whether the corresponding bit is set, indicating a trigger request.
 *
 * Parameters:
 *   EventInput - The EXTI event input to check for a trigger request. This is of type EXTI_EventInput_N
 *                which corresponds to specific external events or peripherals.
 *
 * Returns:
 *   boolean - true if the trigger request has occurred, false otherwise.
 */
boolean EXTI_Trigger_Request_Occurred_CPU2_B(EXTI_EventInput_N EventInput)
{
    uint8_t PR_idx = 0;  // Index of the pending register (C2PR)
    uint8_t PR_pos = 0;  // Position of the event input within the register

    PR_idx = EventInput / 32;
    PR_pos = EventInput % 32;

    boolean Request_Occurred_B = false; // Default to false, meaning no request has occurred

    // Check the corresponding bit in the appropriate C2PR register to determine if a request occurred
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
            break; // Invalid index, no action taken
    }

    return Request_Occurred_B; // Return whether the trigger request occurred
}


/*
 * Function: EXTI_Clear_Trigger_Request_Flag_CPU1
 * ----------------------------------------------
 * Clears the EXTI trigger request flag for the specified event input on CPU1. 
 * This is achieved by setting the corresponding bit in the EXTI pending register (PR1, PR2, or PR3).
 *
 * The function calculates the index and position within the pending registers (PR) based on the given
 * EXTI event input, and sets the appropriate bit in the corresponding register to clear the trigger request flag.
 *
 * Parameters:
 *   EventInput - The EXTI event input whose trigger request flag needs to be cleared.
 *                This is of type EXTI_EventInput_N and corresponds to specific external events or peripherals.
 *
 * Returns:
 *   ReturnType - E_OK if the operation is successful.
 */
ReturnType EXTI_Clear_Trigger_Request_Flag_CPU1(EXTI_EventInput_N EventInput)
{
    uint8_t PR_idx = 0;  // Index of the pending register (PR)
    uint8_t PR_pos = 0;  // Position of the event input within the register

    // Calculate the PR index and position based on the EventInput value
    PR_idx = EventInput / 32;
    PR_pos = EventInput % 32;

    // Set the corresponding bit in the appropriate PR register to clear the trigger request flag for CPU1
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
            break; // Invalid index, no action taken
    }

    return E_OK; // Return successful operation
}


/*
 * Function: EXTI_Clear_Trigger_Request_Flag_CPU2
 * ----------------------------------------------
 * Clears the EXTI trigger request flag for the specified event input on CPU2.
 * This is done by setting the corresponding bit in the EXTI pending register (C2PR1, C2PR2, or C2PR3).
 *
 * The function calculates the index and position within the pending registers (C2PR) based on the given
 * EXTI event input, and sets the appropriate bit in the corresponding register to clear the trigger request flag.
 *
 * Parameters:
 *   EventInput - The EXTI event input whose trigger request flag needs to be cleared.
 *                This is of type EXTI_EventInput_N and corresponds to specific external events or peripherals.
 *
 * Returns:
 *   ReturnType - E_OK if the operation is successful.
 */
ReturnType EXTI_Clear_Trigger_Request_Flag_CPU2(EXTI_EventInput_N EventInput)
{
    uint8_t PR_idx = 0;  // Index of the pending register (C2PR)
    uint8_t PR_pos = 0;  // Position of the event input within the register

    // Calculate the C2PR index and position based on the EventInput value
    PR_idx = EventInput / 32;
    PR_pos = EventInput % 32;

    // Set the corresponding bit in the appropriate C2PR register to clear the trigger request flag for CPU2
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
            break; // Invalid index, no action taken
    }

    return E_OK; // Return successful operation
}

/*
 * Function: EXTI_Rising_Trigger_Enable
 * ------------------------------------
 * Enables the rising edge trigger for the specified EXTI event input.
 * This is done by setting the corresponding bit in the EXTI rising trigger selection register (RTSR1, RTSR2, or RTSR3).
 *
 * The function calculates the index and position within the rising trigger selection registers (RTSR) based on the given
 * EXTI event input, and sets the appropriate bit in the corresponding register to enable the rising trigger.
 *
 * Parameters:
 *   EventInput - The EXTI event input for which the rising trigger needs to be enabled.
 *                This is of type EXTI_EventInput_N and corresponds to specific external events or peripherals.
 *
 * Returns:
 *   ReturnType - E_OK if the operation is successful.
 */
ReturnType EXTI_Rising_Trigger_Enable(EXTI_EventInput_N EventInput)
{
    uint8_t RTSR_idx = 0;  // Index of the rising trigger selection register (RTSR)
    uint8_t RTSR_pos = 0;  // Position of the event input within the register

    // Calculate the RTSR index and position based on the EventInput value
    RTSR_idx = EventInput / 32;
    RTSR_pos = EventInput % 32;

    // Set the corresponding bit in the appropriate RTSR register to enable the rising trigger
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
            break; // Invalid index, no action taken
    }

    return E_OK; // Return successful operation
}


/*
 * Function: EXTI_Rising_Trigger_Disable
 * -------------------------------------
 * Disables the rising edge trigger for the specified EXTI event input.
 * This is done by clearing the corresponding bit in the EXTI rising trigger selection register (RTSR1, RTSR2, or RTSR3).
 *
 * The function calculates the index and position within the rising trigger selection registers (RTSR) based on the given
 * EXTI event input, and clears the appropriate bit in the corresponding register to disable the rising trigger.
 *
 * Parameters:
 *   EventInput - The EXTI event input for which the rising trigger needs to be disabled.
 *                This is of type EXTI_EventInput_N and corresponds to specific external events or peripherals.
 *
 * Returns:
 *   ReturnType - E_OK if the operation is successful.
 */
ReturnType EXTI_Rising_Trigger_Disable(EXTI_EventInput_N EventInput)
{
    uint8_t RTSR_idx = 0;  // Index of the rising trigger selection register (RTSR)
    uint8_t RTSR_pos = 0;  // Position of the event input within the register

    // Calculate the RTSR index and position based on the EventInput value
    RTSR_idx = EventInput / 32;
    RTSR_pos = EventInput % 32;

    // Clear the corresponding bit in the appropriate RTSR register to disable the rising trigger
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
            break; // Invalid index, no action taken
    }

    return E_OK; // Return successful operation
}


/*
 * Function: EXTI_Falling_Trigger_Enable
 * ---------------------------------------
 * Enables the falling edge trigger for the specified EXTI event input.
 * This is achieved by setting the corresponding bit in the EXTI falling trigger selection register (FTSR1, FTSR2, or FTSR3).
 *
 * The function calculates the index and position within the falling trigger selection registers (FTSR) based on the given
 * EXTI event input, and sets the appropriate bit in the corresponding register to enable the falling trigger.
 *
 * Parameters:
 *   EventInput - The EXTI event input for which the falling trigger needs to be enabled.
 *                This is of type EXTI_EventInput_N and corresponds to specific external events or peripherals.
 *
 * Returns:
 *   ReturnType - E_OK if the operation is successful.
 */
ReturnType EXTI_Falling_Trigger_Enable(EXTI_EventInput_N EventInput)
{
    uint8_t FTSR_idx = 0;  // Index of the falling trigger selection register (FTSR)
    uint8_t FTSR_pos = 0;  // Position of the event input within the register

    // Calculate the FTSR index and position based on the EventInput value
    FTSR_idx = EventInput / 32;
    FTSR_pos = EventInput % 32;

    // Set the corresponding bit in the appropriate FTSR register to enable the falling trigger
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
            break; // Invalid index, no action taken
    }

    return E_OK; // Return successful operation
}


/*
 * Function: EXTI_Falling_Trigger_Disable
 * ----------------------------------------
 * Disables the falling edge trigger for the specified EXTI event input.
 * This is achieved by clearing the corresponding bit in the EXTI falling trigger selection register (FTSR1, FTSR2, or FTSR3).
 *
 * The function calculates the index and position within the falling trigger selection registers (FTSR) based on the given
 * EXTI event input, and clears the appropriate bit in the corresponding register to disable the falling trigger.
 *
 * Parameters:
 *   EventInput - The EXTI event input for which the falling trigger needs to be disabled.
 *                This is of type EXTI_EventInput_N and corresponds to specific external events or peripherals.
 *
 * Returns:
 *   ReturnType - E_OK if the operation is successful.
 */
ReturnType EXTI_Falling_Trigger_Disable(EXTI_EventInput_N EventInput)
{
    uint8_t FTSR_idx = 0;  // Index of the falling trigger selection register (FTSR)
    uint8_t FTSR_pos = 0;  // Position of the event input within the register

    // Calculate the FTSR index and position based on the EventInput value
    FTSR_idx = EventInput / 32;
    FTSR_pos = EventInput % 32;

    // Clear the corresponding bit in the appropriate FTSR register to disable the falling trigger
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
            break; // Invalid index, no action taken
    }

    return E_OK; // Return successful operation
}