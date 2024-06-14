#include "STM32H747XI_EXTI.h"

/*
Function description:
    - Enable Event Input Interrupt by set corresponding bit of register EXTI_CnIMR1, EXTI_CnIMR2 or EXTI_CnIMR3).
Input:
    - Event_Input number from 0 to 88.
Return value: N/A
*/
void EXTI_Enable_Event_Input_Interrupt_C1(UINT8 Event_Input)
{
    UINT8 C1IMR_idx = 0;
    UINT8 C1IMR_pos = 0;

    C1IMR_idx = Event_Input/32;
    C1IMR_pos = Event_Input%32;

    switch (C1IMR_idx)
    {
        case 0:
            SET_BIT(EXTI_C1->IMR1, (1 << C1IMR_pos));
            break;

         case 1:
            SET_BIT(EXTI_C1->IMR2, (1 << C1IMR_pos));
            break;

        case 2:
            SET_BIT(EXTI_C1->IMR3, (1 << C1IMR_pos));
            break;

        default:
            break;
    } 
}

void EXTI_Enable_Event_Input_Interrupt_C2(UINT8 Event_Input)
{
    UINT8 C2IMR_idx = 0;
    UINT8 C2IMR_pos = 0;

    C2IMR_idx = Event_Input/32;
    C2IMR_pos = Event_Input%32;

    switch (C2IMR_idx)
    {
        case 0:
            SET_BIT(EXTI_C2->IMR1, (1 << C2IMR_pos));
            break;

         case 1:
            SET_BIT(EXTI_C2->IMR2, (1 << C2IMR_pos));
            break;

        case 2:
            SET_BIT(EXTI_C2->IMR3, (1 << C2IMR_pos));
            break;

        default:
            break;
    } 
}

/*
Function description:
    - Disable Event Input Interrupt by clear corresponding bit of register EXTI_CnIMR1, EXTI_CnIMR2 or EXTI_CnIMR3).
Input:
    - Event_Input number from 0 to 88.
Return value: N/A
*/
void EXTI_Disable_Event_Input_Interrupt_C1(UINT8 Event_Input)
{
    UINT8 C1IMR_idx = 0;
    UINT8 C1IMR_pos = 0;

    C1IMR_idx = Event_Input/32;
    C1IMR_pos = Event_Input%32;

    switch (C1IMR_idx)
    {
        case 0:
            CLEAR_BIT(EXTI_C1->IMR1, (1 << C1IMR_pos));
            break;

         case 1:
            CLEAR_BIT(EXTI_C1->IMR2, (1 << C1IMR_pos));
            break;

        case 2:
            CLEAR_BIT(EXTI_C1->IMR3, (1 << C1IMR_pos));
            break;

        default:
            break;
    } 
}

void EXTI_Disable_Event_Input_Interrupt_C2(UINT8 Event_Input)
{
    UINT8 C2IMR_idx = 0;
    UINT8 C2IMR_pos = 0;

    C2IMR_idx = Event_Input/32;
    C2IMR_pos = Event_Input%32;

    switch (C2IMR_idx)
    {
        case 0:
            CLEAR_BIT(EXTI_C2->IMR1, (1 << C2IMR_pos));
            break;

         case 1:
            CLEAR_BIT(EXTI_C2->IMR2, (1 << C2IMR_pos));
            break;

        case 2:
            CLEAR_BIT(EXTI_C2->IMR3, (1 << C2IMR_pos));
            break;

        default:
            break;
    } 
}