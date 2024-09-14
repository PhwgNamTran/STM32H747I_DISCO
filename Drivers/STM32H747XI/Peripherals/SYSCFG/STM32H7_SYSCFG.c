#include "STM32H7_SYSCFG.h"

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
 * Configures the specified GPIO pin to be used as an EXTI (External Interrupt) line.
 *
 * Parameters:
 *   GPIOx - Pointer to the GPIO peripheral instance. This parameter can be one of the following values:
 *           - GPIO_A
 *           - GPIO_B
 *           - GPIO_C
 *           - GPIO_D
 *           - GPIO_E
 *           - GPIO_F
 *           - GPIO_G
 *           - GPIO_H
 *           - GPIO_I
 *           - GPIO_J
 *           - GPIO_K
 *   GPIO_Pin - Specifies the GPIO pin to be configured for EXTI. This parameter must be a value between
 *              GPIO_PIN_0 and GPIO_PIN_15.
 *
 * Returns:
 *   None
 */
void SYSCFG_EXITx_GPIO_Cfg(GPIO_ST *GPIOx, uint8_t GPIO_Pin)
{
    // Check if the GPIO port is GPIO_K and the pin is in the range 8 to 15
    if((GPIOx == GPIOK)
       && ((GPIO_PIN_8 <= GPIO_Pin)&&(GPIO_PIN_15 >= GPIO_Pin)))
    {
        /* GPIO K Pin from 8 to 15 not supported for EXTI */
    }
    else
    {
        // Clear the previous EXTI configuration for the specified pin
        CLEAR_BIT(SYSCFG->EXTICR[GPIO_Pin / 4], (0xF << ((GPIO_Pin % 4) * 4)));
        
        // Set the EXTI configuration based on the GPIO port
        if(GPIOx == GPIOA)
        {
            SET_BIT(SYSCFG->EXTICR[GPIO_Pin / 4], (0x0 << ((GPIO_Pin % 4) * 4)));
        }
        else if(GPIOx == GPIOB)
        {
            SET_BIT(SYSCFG->EXTICR[GPIO_Pin / 4], (0x1 << ((GPIO_Pin % 4) * 4)));
        }
        else if(GPIOx == GPIOC)
        {
            SET_BIT(SYSCFG->EXTICR[GPIO_Pin / 4], (0x2 << ((GPIO_Pin % 4) * 4)));
        }
        else if(GPIOx == GPIOD)
        {
            SET_BIT(SYSCFG->EXTICR[GPIO_Pin / 4], (0x3 << ((GPIO_Pin % 4) * 4)));
        }
        else if(GPIOx == GPIOE)
        {
            SET_BIT(SYSCFG->EXTICR[GPIO_Pin / 4], (0x4 << ((GPIO_Pin % 4) * 4)));
        }
        else if(GPIOx == GPIOF)
        {
            SET_BIT(SYSCFG->EXTICR[GPIO_Pin / 4], (0x5 << ((GPIO_Pin % 4) * 4)));
        }
        else if(GPIOx == GPIOG)
        {
            SET_BIT(SYSCFG->EXTICR[GPIO_Pin / 4], (0x6 << ((GPIO_Pin % 4) * 4)));
        }
        else if(GPIOx == GPIOH)
        {
            SET_BIT(SYSCFG->EXTICR[GPIO_Pin / 4], (0x7 << ((GPIO_Pin % 4) * 4)));
        }
        else if(GPIOx == GPIOI)
        {
            SET_BIT(SYSCFG->EXTICR[GPIO_Pin / 4], (0x8 << ((GPIO_Pin % 4) * 4)));
        }
        else if(GPIOx == GPIOJ)
        {
            SET_BIT(SYSCFG->EXTICR[GPIO_Pin / 4], (0x9 << ((GPIO_Pin % 4) * 4)));
        }
        else if(GPIOx == GPIOK)
        {
            SET_BIT(SYSCFG->EXTICR[GPIO_Pin / 4], (0xA << ((GPIO_Pin % 4) * 4)));
        }
        else
        {
            // Handle invalid GPIO port
        }
    }
}
