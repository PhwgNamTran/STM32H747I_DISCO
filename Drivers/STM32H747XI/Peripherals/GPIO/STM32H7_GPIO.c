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
 *   E_OK   - If configuration was successful.
 */
ReturnType GPIO_Mode_Set(GPIO_ST *GPIOx, GPIO_Pin_N Pin, GPIO_Mode_N Mode)
{
    // Clear the mode register for the specified pin
    CLEAR_BIT(GPIOx->MODER, (GPIO_MODER_MODEx_MASK << (Pin * GPIO_MODER_MODEx_SIZE)));
    // Set the new mode for the specified pin
    SET_BIT(GPIOx->MODER, ((Mode & GPIO_MODER_MODEx_MASK) << (Pin * GPIO_MODER_MODEx_SIZE)));

    return E_OK;
}

/*
 * Function: GPIO_OutputType_Set
 * -----------------------------
 * Configures the output type for a specified GPIO pin.
 *
 * Parameters:
 *   GPIOx      - Pointer to the GPIO structure for the specific GPIO port
 *   Pin        - Pin number to configure (GPIO_Pin_N)
 *   OutputType - Desired output type (GPIO_OutputType_N)
 *
 * Returns:
 *   E_OK   - If configuration was successful.
 */
ReturnType GPIO_OutputType_Set(GPIO_ST *GPIOx, GPIO_Pin_N Pin, GPIO_OutputType_N OutputType)
{
    // Clear the output type register for the specified pin
    CLEAR_BIT(GPIOx->OTYPER, (GPIO_OTYPER_OTx_MASK << (Pin * GPIO_OTYPER_OTx_SIZE)));
    
    // Set the new output type for the specified pin, applying a mask to ensure only relevant bits are set
    SET_BIT(GPIOx->OTYPER, ((OutputType & GPIO_OTYPER_OTx_MASK) << (Pin * GPIO_OTYPER_OTx_SIZE)));

    return E_OK;
}

/*
 * Function: GPIO_Pull_Set
 * -----------------------
 * Configures the pull-up/pull-down resistor for a specified GPIO pin.
 *
 * Parameters:
 *   GPIOx - Pointer to the GPIO structure for the specific GPIO port
 *   Pin   - Pin number to configure (GPIO_Pin_N)
 *   Pull  - Desired pull-up/pull-down configuration (GPIO_Pull_N)
 *
 * Returns:
 *   E_OK   - If configuration was successful.
 */
ReturnType GPIO_Pull_Set(GPIO_ST *GPIOx, GPIO_Pin_N Pin, GPIO_Pull_N Pull)
{
    // Clear the pull-up/pull-down register for the specified pin
    CLEAR_BIT(GPIOx->PUPDR, (GPIO_PUPDR_PUPDx_MASK << (Pin * GPIO_PUPDR_PUPDx_SIZE)));
    
    // Set the new pull-up/pull-down configuration for the specified pin, applying a mask to ensure only relevant bits are set
    SET_BIT(GPIOx->PUPDR, ((Pull & GPIO_PUPDR_PUPDx_MASK) << (Pin * GPIO_PUPDR_PUPDx_SIZE)));

    return E_OK;
}

/*
 * Function: GPIO_Alternate_Function_Set
 * -------------------------------------
 * Configures the alternate function for a specified GPIO pin.
 *
 * Parameters:
 *   GPIOx - Pointer to the GPIO structure for the specific GPIO port
 *   Pin   - Pin number to configure (GPIO_Pin_N)
 *   AFx   - Desired alternate function (GPIO_AlternateFunction_N)
 *
 * Returns:
 *   E_OK   - If configuration was successful.
 */
ReturnType GPIO_Alternate_Function_Set(GPIO_ST *GPIOx, GPIO_Pin_N Pin, GPIO_AlternateFunction_N AFx)
{
    // Clear the current alternate function for the specified pin
    CLEAR_BIT(GPIOx->AFR[(Pin / GPIO_AFRx_PINS_PER_REGISTER)],
             (GPIO_AFRx_AFSELx_MASK << ((Pin % GPIO_AFRx_PINS_PER_REGISTER) * GPIO_AFRx_AFSELx_SIZE)));
    
    // Set the new alternate function for the specified pin
    SET_BIT(GPIOx->AFR[(Pin / GPIO_AFRx_PINS_PER_REGISTER)], 
           ((AFx & GPIO_AFRx_AFSELx_MASK) << ((Pin % GPIO_AFRx_PINS_PER_REGISTER) * GPIO_AFRx_AFSELx_SIZE)));

    return E_OK;
}

/*
 * Function: GPIO_OutputData_Get
 * -----------------------------
 * Reads the output data register for the specified pin.
 *
 * Parameters:
 *   GPIOx - Pointer to the GPIO structure for the specific GPIO port
 *   Pin   - Pin number to read (GPIO_Pin_N)
 *
 * Returns:
 *   boolean - true if the pin is set, false if it is reset
 */
boolean GPIO_OutputData_Get(GPIO_ST *GPIOx, GPIO_Pin_N Pin)
{
    // Read the output data register for the specified pin and return as boolean (true for set, false for reset)
    return (boolean)((READ_BIT(GPIOx->ODR, (GPIO_ODR_ODx_MASK << (Pin * GPIO_ODR_ODx_SIZE)))) ? true : false);
}

/*
 * Function: GPIO_OutputData_Set
 * -----------------------------
 * Sets the output data register for the specified pin.
 *
 * Parameters:
 *   GPIOx - Pointer to the GPIO structure for the specific GPIO port
 *   Pin   - Pin number to set (GPIO_Pin_N)
 *
 * Returns:
 *   E_OK   - If the operation was successful.
 */
ReturnType GPIO_OutputData_Set(GPIO_ST *GPIOx, GPIO_Pin_N Pin)
{
    // Set the output data register for the specified pin
    SET_BIT(GPIOx->ODR, (GPIO_ODR_ODx_MASK << (Pin * GPIO_ODR_ODx_SIZE)));

    return E_OK;
}

/*
 * Function: GPIO_OutputData_Reset
 * -------------------------------
 * Clears the output data register for the specified pin.
 *
 * Parameters:
 *   GPIOx - Pointer to the GPIO structure for the specific GPIO port
 *   Pin   - Pin number to reset (GPIO_Pin_N)
 *
 * Returns:
 *   E_OK   - If the operation was successful.
 */
ReturnType GPIO_OutputData_Reset(GPIO_ST *GPIOx, GPIO_Pin_N Pin)
{
    // Clear the output data register for the specified pin
    CLEAR_BIT(GPIOx->ODR, (GPIO_ODR_ODx_MASK << (Pin * GPIO_ODR_ODx_SIZE)));

    return E_OK;
}

/*
 * Function: GPIO_OutputData_Toggle
 * --------------------------------
 * Toggles the output data register for the specified pin.
 *
 * Parameters:
 *   GPIOx - Pointer to the GPIO structure for the specific GPIO port
 *   Pin   - Pin number to toggle (GPIO_Pin_N)
 *
 * Returns:
 *   E_OK   - If the operation was successful.
 */
ReturnType GPIO_OutputData_Toggle(GPIO_ST *GPIOx, GPIO_Pin_N Pin)
{
    // Toggle the output data register for the specified pin
    if (GPIO_OutputData_Get(GPIOx, Pin))
    {
        GPIO_OutputData_Reset(GPIOx, Pin);  // Pin is set, so reset it
    }
    else
    {
        GPIO_OutputData_Set(GPIOx, Pin);    // Pin is reset, so set it
    }

    return E_OK;
}
