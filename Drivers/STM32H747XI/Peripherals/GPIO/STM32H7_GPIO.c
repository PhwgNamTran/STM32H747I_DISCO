#include "STM32H7_GPIO.h"

/*
 * Function: GPIO_Mode_Set
 * -----------------------
 * Configures the mode of a specific GPIO pin by clearing the existing mode and setting a new mode.
 * 
 * Parameters:
 *   GPIOx - Pointer to the GPIO structure for the port being configured.
 *   Pin   - GPIO pin number to configure (0-15 for standard GPIO ports).
 *   Mode  - New mode to set for the pin (input, output, alternate function, or analog).
 *
 * Returns:
 *   None
 */

void GPIO_Mode_Set(GPIO_ST *GPIOx, GPIO_Pin_N Pin, GPIO_Mode_N Mode)
{
    // Clear the mode register for the specified pin
    CLEAR_BIT(GPIOx->MODER, (GPIO_MODER_MODE_Mask << (Pin * GPIO_MODER_MODE_Size)));
    // Set the new mode for the specified pin
    SET_BIT(GPIOx->MODER, ((Mode & GPIO_MODER_MODE_Mask) << (Pin * GPIO_MODER_MODE_Size)));
}

void GPIO_OutputType_Set(GPIO_ST *GPIOx, GPIO_Pin_N Pin, GPIO_OutputType_N OutputType)
{
    // Clear the output type register for the specified pin
    CLEAR_BIT(GPIOx->OTYPER, (GPIO_OTYPER_OT_Mask << (Pin * GPIO_OTYPER_OT_Size)));
    // Set the new output type for the specified pin
    SET_BIT(GPIOx->OTYPER, ((OutputType & GPIO_OTYPER_OT_Mask) << (Pin * GPIO_OTYPER_OT_Size)));
}

void GPIO_Pull_Set(GPIO_ST *GPIOx, uint8_t Pin, uint8_t Pull)
{
    // Clear the pull-up/pull-down register for the specified pin
    CLEAR_BIT(GPIOx->PUPDR, (0x3 << (Pin * 2)));
    // Set the new pull-up/pull-down configuration for the specified pin
    SET_BIT(GPIOx->PUPDR, ((Pull & 0x3) << (Pin * 2)));
}

void GPIO_OutputData_Set(GPIO_ST *GPIOx, uint8_t Pin)
{
    // Set the output data register for the specified pin
    SET_BIT(GPIOx->ODR, (0x1 << Pin));
}

void GPIO_OutputData_Reset(GPIO_ST *GPIOx, uint8_t Pin)
{
    // Clear the output data register for the specified pin
    CLEAR_BIT(GPIOx->ODR, (0x1 << Pin));
}

void GPIO_OutputData_Toggle(GPIO_ST *GPIOx, uint8_t Pin)
{
    // Toggle the output data register for the specified pin
    if (READ_BIT(GPIOx->ODR, (0x1 << Pin)))
    {
        CLEAR_BIT(GPIOx->ODR, (0x1 << Pin));
    }
    else
    {
        SET_BIT(GPIOx->ODR, (0x1 << Pin));
    }
}

void GPIO_Select_Alternate_Function(GPIO_ST *GPIOx, uint8_t Pin, uint8_t AFx)
{
    // Clear the current alternate function for the specified pin
    CLEAR_BIT(GPIOx->AFR[(Pin / 8)], (0xF << ((Pin % 8) * 4)));
    
    // Set the new alternate function for the specified pin
    SET_BIT(GPIOx->AFR[(Pin / 8)], (AFx << ((Pin % 8) * 4)));
}

