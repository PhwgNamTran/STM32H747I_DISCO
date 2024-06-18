#include "Interrupt_Handler.h"
#include "Common.h"

void EXTI15_10_IRQHandler(void)
{
    if(EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_10))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_10);
        /* USER CODE START */

        /* USER CODE END */
    }

    if(EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_11))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_11);
        /* USER CODE START */

        /* USER CODE END */
    }

    if(EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_12))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_12);
        /* USER CODE START */

        /* USER CODE END */
    }

    if(EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_13))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_13);
        /* USER CODE START */

        /* USER CODE END */
    }

    if(EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_14))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_14);
        /* USER CODE START */

        /* USER CODE END */
    }

    if(EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_15))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_15);
        /* USER CODE START */

        /* USER CODE END */
    }
    
}