#include "Interrupt_Handler.h"
#include "Interrupt_Cfg.h"
#include "Common.h"
#include "UserLED.h"

/*
 * Function: EXTI15_10_IRQHandler
 * ------------------------------
 * Interrupt handler for EXTI lines 10 to 15.
 *
 * This function handles interrupt requests for EXTI lines 10 to 15 based on configuration.
 * It clears the trigger request flag and optionally executes user-defined code.
 */
void EXTI15_10_IRQHandler(void)
{
#if(EXTI_10_ENABLED)
    if (EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_10))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_10);
        /* USER CODE START */

        /* USER CODE END */
    }
#endif

#if(EXTI_11_ENABLED)
    if (EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_11))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_11);
        /* USER CODE START */

        /* USER CODE END */
    }
#endif

#if(EXTI_12_ENABLED)
    if (EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_12))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_12);
        /* USER CODE START */

        /* USER CODE END */
    }
#endif

#if(EXTI_13_ENABLED)
    if (EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_13))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_13);
        /* USER CODE START */
        UserLED_TOGGLE(UserLED_1); // Example user code: Toggle UserLED_1 on EXTI 13
        /* USER CODE END */
    }
#endif

#if(EXTI_14_ENABLED)
    if (EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_14))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_14);
        /* USER CODE START */

        /* USER CODE END */
    }
#endif

#if(EXTI_15_ENABLED)
    if (EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_15))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_15);
        /* USER CODE START */

        /* USER CODE END */
    }
#endif
}
