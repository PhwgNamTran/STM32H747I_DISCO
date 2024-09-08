#include "STM32H747XI_NVIC.h"

/*
 * Function: NVIC_EnableIRQ
 * ------------------------
 * Enables a device-specific interrupt in the NVIC interrupt controller.
 *
 * Parameters:
 *   IRQn: Device-specific interrupt number to enable.
 *
 * Returns:
 *   None
 */
void NVIC_EnableIRQ(IRQn_N IRQn)  
{
    uint32_t ISER_Idx = 0;
    uint32_t IRQn_Pos = 0;
    if((uint8_t)IRQn >= 0)
    {
        ISER_Idx = ((uint8_t)IRQn) >> 5UL;
        IRQn_Pos = 1UL << (((uint8_t)IRQn) & 0x1FUL);
        SET_BIT(NVIC->ISER[ISER_Idx], IRQn_Pos);
    }
}

/*
 * Function: NVIC_GetEnableIRQ
 * ---------------------------
 * Checks if a device-specific interrupt is enabled in the NVIC interrupt controller.
 *
 * Parameters:
 *   IRQn: Device-specific interrupt number to check.
 *
 * Returns:
 *   BOOL: TRUE if the interrupt is enabled, FALSE otherwise.
 */
BOOL NVIC_GetEnableIRQ(IRQn_N IRQn)       
{
    uint32_t ISER_Idx = 0;
    uint32_t IRQn_Pos = 0;
    BOOL   IRQn_Enabled = FALSE;

    if((uint8_t)IRQn >= 0)
    {
        ISER_Idx = ((uint8_t)IRQn) >> 5UL;
        IRQn_Pos = 1UL << (((uint8_t)IRQn) & 0x1FUL);
        IRQn_Enabled = CHECK_BIT(NVIC->ISER[ISER_Idx], IRQn_Pos);
    }
    else
    {
        IRQn_Enabled = FALSE;
    }
    return IRQn_Enabled;
}

/*
 * Function: NVIC_DisableIRQ
 * -------------------------
 * Disables a device-specific interrupt in the NVIC interrupt controller.
 *
 * Parameters:
 *   IRQn: Device-specific interrupt number to disable.
 *
 * Returns:
 *   None
 */
void NVIC_DisableIRQ(IRQn_N IRQn)      
{
    // Implementation needed
}

/*
 * Function: NVIC_GetPendingIRQ
 * ----------------------------
 * Gets the pending status of a device-specific interrupt in the NVIC interrupt controller.
 *
 * Parameters:
 *   IRQn: Device-specific interrupt number to check.
 *
 * Returns:
 *   uint32_t: The pending status (always returns 0 for this implementation).
 */
uint32_t NVIC_GetPendingIRQ(IRQn_N IRQn)   
{
    return 0;
}

/*
 * Function: NVIC_SetPendingIRQ
 * ----------------------------
 * Sets the pending status of a device-specific interrupt in the NVIC interrupt controller.
 *
 * Parameters:
 *   IRQn: Device-specific interrupt number to set pending.
 *
 * Returns:
 *   None
 */
void NVIC_SetPendingIRQ(IRQn_N IRQn) 
{
    // Implementation needed
}

/*
 * Function: NVIC_ClearPendingIRQ
 * ------------------------------
 * Clears the pending status of a device-specific interrupt in the NVIC interrupt controller.
 *
 * Parameters:
 *   IRQn: Device-specific interrupt number to clear pending.
 *
 * Returns:
 *   None
 */
void NVIC_ClearPendingIRQ(IRQn_N IRQn)
{
    // Implementation needed
}

/*
 * Function: NVIC_GetActive
 * ------------------------
 * Gets the active status of a device-specific interrupt in the NVIC interrupt controller.
 *
 * Parameters:
 *   IRQn: Device-specific interrupt number to check.
 *
 * Returns:
 *   uint32_t: The active status (always returns 0 for this implementation).
 */
uint32_t NVIC_GetActive(IRQn_N IRQn)
{
    return 0;
}

/*
 * Function: NVIC_SetPriority
 * --------------------------
 * Sets the priority of a device-specific interrupt in the NVIC interrupt controller.
 *
 * Parameters:
 *   IRQn: Device-specific interrupt number to set priority.
 *   Priority: Priority value to set (8 bits).
 *
 * Returns:
 *   None
 */
void NVIC_SetPriority(IRQn_N IRQn, uint8_t Priority)
{
    if((uint8_t)IRQn >= 0)
    {
        SET_BIT(NVIC->IP[((uint8_t)IRQn)], (uint8_t)((Priority & 0xFFUL)));
    }
}

/*
 * Function: NVIC_GetPriority
 * --------------------------
 * Gets the priority of a device-specific interrupt in the NVIC interrupt controller.
 *
 * Parameters:
 *   IRQn: Device-specific interrupt number to get priority.
 *
 * Returns:
 *   uint32_t: The priority value (always returns 0 for this implementation).
 */
uint32_t NVIC_GetPriority(IRQn_N IRQn)
{
    return 0;
}
