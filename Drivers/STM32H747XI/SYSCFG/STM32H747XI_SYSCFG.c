#include "STM32H747XI_SYSCFG.h"

/*
 * Function: SYSCFG_Enable
 * ------------------------
 * Enables the SYSCFG clock in RCC's APB4ENR register.
 *
 * Parameters:
 *   None
 *
 * Returns:
 *   None
 */
void SYSCFG_Enable(void)
{
    SET_BIT(RCC->APB4ENR, RCC_APB4ENR_SYSCFGEN); 
}

/*
 * Function: SYSCFG_EXITx_GPIO_Cfg
 * -------------------------------
 * Configures the SYSCFG EXTI configuration registers to enable external interrupt for a specific GPIO pin.
 *
 * Parameters:
 *   GPIO_x_Num - GPIO Port number (e.g., GPIO_K_Num)
 *   GPIO_Pin   - GPIO Pin number (0 to 15)
 *
 * Returns:
 *   None
 *
 * Notes:
 *   GPIO K Pin from 8 to 15 is not supported for EXTI.
 */
void SYSCFG_EXITx_GPIO_Cfg(UINT8 GPIO_x_Num, UINT8 GPIO_Pin)
{
    if(GPIO_x_Num == GPIO_K_Num 
       && ((GPIO_PIN_8 <= GPIO_Pin)&&(GPIO_PIN_15 >= GPIO_Pin)))
    {
        /* GPIO K Pin from 8 to 15 not support for EXTI */
    }
    else
    {
        CLEAR_BIT(SYSCFG->EXTICR[GPIO_Pin/4], (0xF << ((GPIO_Pin%4)*4)));
        SET_BIT(SYSCFG->EXTICR[GPIO_Pin/4], ((GPIO_x_Num & 0xF) << ((GPIO_Pin%4)*4)));
    }
}
