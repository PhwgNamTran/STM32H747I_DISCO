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
    UINT32 ISER_Idx = 0;
    UINT32 IRQn_Pos = 0;
    if((UINT8)IRQn >= 0)
    {
        ISER_Idx = ((UINT8)IRQn) >> 5UL;
        IRQn_Pos = 1UL << (((UINT8)IRQn) & 0x1FUL);
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
    UINT32 ISER_Idx = 0;
    UINT32 IRQn_Pos = 0;
    BOOL   IRQn_Enabled = FALSE;

    if((UINT8)IRQn >= 0)
    {
        ISER_Idx = ((UINT8)IRQn) >> 5UL;
        IRQn_Pos = 1UL << (((UINT8)IRQn) & 0x1FUL);
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
 *   UINT32: The pending status (always returns 0 for this implementation).
 */
UINT32 NVIC_GetPendingIRQ(IRQn_N IRQn)   
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
 *   UINT32: The active status (always returns 0 for this implementation).
 */
UINT32 NVIC_GetActive(IRQn_N IRQn)
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
void NVIC_SetPriority(IRQn_N IRQn, UINT8 Priority)
{
    if((UINT8)IRQn >= 0)
    {
        SET_BIT(NVIC->IP[((UINT8)IRQn)], (UINT8)((Priority & 0xFFUL)));
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
 *   UINT32: The priority value (always returns 0 for this implementation).
 */
UINT32 NVIC_GetPriority(IRQn_N IRQn)
{
    return 0;
}
