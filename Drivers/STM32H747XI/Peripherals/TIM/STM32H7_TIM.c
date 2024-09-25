#include "STM32H7_TIM.h"

void TIM_Config(TIM_ST *TIMx, uint32_t TIMx_PSC, uint32_t TIMx_ARR, boolean Counter_Direction)
{
    WRITE_REG(TIMx->PSC, TIMx_PSC);  // Set the prescaler value
    WRITE_REG(TIMx->ARR, TIMx_ARR);  // Set the auto-reload value
    if(Counter_Direction)
    {
        SET_BIT(TIMx->CR1, TIM_CR1_DIR); // Set the counter direction to down-counting
    }
    else
    {
        CLEAR_BIT(TIMx->CR1, TIM_CR1_DIR); // Set the counter direction to up-counting
    }
}

void TIM_DMA_Interrupt_Mode_Enable(TIM_ST *TIMx, uint8_t DMA_Interrupt_Mode)
{
    if(DMA_Interrupt_Mode < TIM_DMA_Interrupt_Reserved)
    {
        SET_BIT(TIMx->DIER, (1 << DMA_Interrupt_Mode)); // Enable the specified DMA interrupt mode
    }
    else
    {
        /* Nothing to do */
    }
}

void TIM_DMA_Interrupt_Mode_Disable(TIM_ST *TIMx, uint8_t DMA_Interrupt_Mode)
{
    if(DMA_Interrupt_Mode < TIM_DMA_Interrupt_Reserved)
    {
        CLEAR_BIT(TIMx->DIER, (1 << DMA_Interrupt_Mode)); // Disable the specified DMA interrupt mode
    }
    else
    {
        /* Nothing to do */
    }
}


void TIM_DMA_Interrupt_Clear_Status(TIM_ST *TIMx)
{
    CLEAR_BIT(TIMx->SR, TIM_SR_UIF);  // Clear the interrupt status bit
}


boolean TIM_DMA_Interrupt_Check_Status(TIM_ST *TIMx)
{
    if (CHECK_BIT(TIMx->SR, TIM_SR_UIF))
    {
        return true;  // Interrupt status is set
    }
    else
    {
        return false; // Interrupt status is not set
    }
}


/*
 * Function: TIM_Enable
 * ------------------------
 * Enables the TIM peripheral by setting the CEN bit in the CR1 register.
 *
 * Parameters:
 *   TIMx - Pointer to the TIM peripheral.
 *
 * Returns:
 *   None
 */
void TIM_Enable(TIM_ST *TIMx)
{
    SET_BIT(TIMx->CR1, TIM_CR1_CEN); // Enable the TIM peripheral
}
