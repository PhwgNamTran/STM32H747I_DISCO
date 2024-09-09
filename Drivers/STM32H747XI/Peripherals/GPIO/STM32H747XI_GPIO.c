#include "STM32H747XI_GPIO.h"

/*
 * Function: GPIO_Enable_ClockSource
 * --------------------
 * Enables the clock source for a GPIO port.
 *
 * Parameters:
 *   GPIOx_CLKSRC: GPIO Port Clock Source to enable.
 *                 Use GPIOx_CLKSRC macros defined in STM32H747XI_GPIO.h.
 *
 * Returns:
 *   None
 */
void GPIO_Enable_ClockSource(uint16_t GPIOx_CLKSRC)
{
    SET_BIT(RCC->AHB4ENR, GPIOx_CLKSRC);
}

/*
 * Function: GPIO_Disable_ClockSource
 * --------------------
 * Disables the clock source for a GPIO port.
 *
 * Parameters:
 *   GPIOx_CLKSRC: GPIO Port Clock Source to disable.
 *                 Use GPIOx_CLKSRC macros defined in STM32H747XI_GPIO.h.
 *
 * Returns:
 *   None
 */
void GPIO_Disable_ClockSource(uint16_t GPIOx_CLKSRC)
{
    CLEAR_BIT(RCC->AHB4ENR, GPIOx_CLKSRC);
}

/*
 * Function: GPIO_Mode_Set
 * --------------------
 * Sets the mode for a GPIO pin.
 *
 * Parameters:
 *   GPIOx: Pointer to GPIO structure (GPIO Port A, B, C, ...K).
 *   Pin: GPIO Pin number (0 to 15).
 *   Mode: GPIO mode to set (Input, Output, Alternate Function, Analog).
 *         Use GPIO_MODE_* macros defined in STM32H747XI_GPIO.h.
 *
 * Returns:
 *   None
 */
void GPIO_Mode_Set(GPIO_ST *GPIOx, uint8_t Pin, uint8_t Mode)
{
    // Clear the mode register for the specified pin
    CLEAR_BIT(GPIOx->MODER, (0x3 << (Pin * 2)));
    // Set the new mode for the specified pin
    SET_BIT(GPIOx->MODER, ((Mode & 0x3) << (Pin * 2)));
}

/*
 * Function: GPIO_Pull_Set
 * --------------------
 * Configures the pull-up/pull-down resistor for a GPIO pin.
 *
 * Parameters:
 *   GPIOx: Pointer to GPIO structure (GPIO Port A, B, C, ...K).
 *   Pin: GPIO Pin number (0 to 15).
 *   Pull: Pull-up/pull-down configuration (No pull, Pull up, Pull down, Reserved).
 *         Use GPIO_PULL_* macros defined in STM32H747XI_GPIO.h.
 *
 * Returns:
 *   None
 */
void GPIO_Pull_Set(GPIO_ST *GPIOx, uint8_t Pin, uint8_t Pull)
{
    // Clear the pull-up/pull-down register for the specified pin
    CLEAR_BIT(GPIOx->PUPDR, (0x3 << (Pin * 2)));
    // Set the new pull-up/pull-down configuration for the specified pin
    SET_BIT(GPIOx->PUPDR, ((Pull & 0x3) << (Pin * 2)));
}

/*
 * Function: GPIO_OutputType_Set
 * --------------------
 * Sets the output type for a GPIO pin (PushPull or Open drain).
 *
 * Parameters:
 *   GPIOx: Pointer to GPIO structure (GPIO Port A, B, C, ...K).
 *   Pin: GPIO Pin number (0 to 15).
 *   OutputType: Output type to set (PushPull or Open drain).
 *               Use GPIO_OUTPUT_TYPE_* macros defined in STM32H747XI_GPIO.h.
 *
 * Returns:
 *   None
 */
void GPIO_OutputType_Set(GPIO_ST *GPIOx, uint8_t Pin, boolean OutputType)
{
    // Clear the output type register for the specified pin
    CLEAR_BIT(GPIOx->OTYPER, (0x1 << Pin));
    // Set the new output type for the specified pin
    SET_BIT(GPIOx->OTYPER, (OutputType << Pin));
}

/*
 * Function: GPIO_OutputData_Set
 * --------------------
 * Sets the output data for a GPIO pin to high (1).
 *
 * Parameters:
 *   GPIOx: Pointer to GPIO structure (GPIO Port A, B, C, ...K).
 *   Pin: GPIO Pin number (0 to 15).
 *
 * Returns:
 *   None
 */
void GPIO_OutputData_Set(GPIO_ST *GPIOx, uint8_t Pin)
{
    // Set the output data register for the specified pin
    SET_BIT(GPIOx->ODR, (0x1 << Pin));
}

/*
 * Function: GPIO_OutputData_Reset
 * --------------------
 * Resets the output data for a GPIO pin to low (0).
 *
 * Parameters:
 *   GPIOx: Pointer to GPIO structure (GPIO Port A, B, C, ...K).
 *   Pin: GPIO Pin number (0 to 15).
 *
 * Returns:
 *   None
 */
void GPIO_OutputData_Reset(GPIO_ST *GPIOx, uint8_t Pin)
{
    // Clear the output data register for the specified pin
    CLEAR_BIT(GPIOx->ODR, (0x1 << Pin));
}

/*
 * Function: GPIO_OutputData_Toggle
 * --------------------
 * Toggles the output data for a GPIO pin.
 *
 * Parameters:
 *   GPIOx: Pointer to GPIO structure (GPIO Port A, B, C, ...K).
 *   Pin: GPIO Pin number (0 to 15).
 *
 * Returns:
 *   None
 */
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

/*
 * Function: GPIO_Select_Alternate_Function
 * ----------------------------------------
 * Configures the alternate function for a specific GPIO pin.
 *
 * Parameters:
 *   GPIOx - Pointer to the GPIO peripheral
 *   Pin   - GPIO pin number (0-15)
 *   AFx   - Alternate function number (0-15)
 *
 * Returns:
 *   None
 */
void GPIO_Select_Alternate_Function(GPIO_ST *GPIOx, uint8_t Pin, uint8_t AFx)
{
    // Clear the current alternate function for the specified pin
    CLEAR_BIT(GPIOx->AFR[(Pin / 8)], (0xF << ((Pin % 8) * 4)));
    
    // Set the new alternate function for the specified pin
    SET_BIT(GPIOx->AFR[(Pin / 8)], (AFx << ((Pin % 8) * 4)));
}

