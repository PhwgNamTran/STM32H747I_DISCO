#include "STM32H7_SYSCFG.h"

/*
 * Function: SYSCFG_EXITx_GPIO_Config
 * ----------------------------------
 * Configures the EXTI (External Interrupt) for the specified GPIO pin and maps it to a GPIO port.
 * If the pin belongs to GPIOK (pins 8-15), the configuration is not allowed, and the function will return an error.
 *
 * Parameters:
 *   GPIOx - Pointer to the GPIO port (e.g., GPIOA, GPIOB, etc.)
 *   Pin   - GPIO pin number (GPIO_Pin_N)
 *
 * Returns:
 *   E_OK if the configuration is successful, E_NOT_OK otherwise.
 */
ReturnType SYSCFG_EXITx_GPIO_Config(GPIO_ST *GPIOx, GPIO_Pin_N Pin)
{
    // Return E_NOT_OK if the port is GPIOK and pin is between 8 and 15 (configuration not allowed)
    if ((GPIOx == GPIOK) 
       && ((GPIO_PIN_8_N <= Pin) && (GPIO_PIN_15_N >= Pin)))
    {
        return E_NOT_OK;
    }
    else
    {
        // Clear the current EXTI configuration for the pin
        CLEAR_BIT(SYSCFG->EXTICR[Pin / SYSCFG_EXTICR_EXTIs_PER_REGISTER], 
                  (SYSCFG_EXTICR_EXTIx_MASK << ((Pin % SYSCFG_EXTICR_EXTIs_PER_REGISTER) * SYSCFG_EXTICR_EXTIx_SIZE)));
        
        // Set EXTI line to GPIOA
        if (GPIOx == GPIOA)
        {
            SET_BIT(SYSCFG->EXTICR[Pin / SYSCFG_EXTICR_EXTIs_PER_REGISTER], 
                    (SYSCFG_EXTICR_EXTIx_PA << ((Pin % SYSCFG_EXTICR_EXTIs_PER_REGISTER) * SYSCFG_EXTICR_EXTIx_SIZE)));
        }
        // Set EXTI line to GPIOB
        else if (GPIOx == GPIOB)
        {
            SET_BIT(SYSCFG->EXTICR[Pin / SYSCFG_EXTICR_EXTIs_PER_REGISTER], 
                    (SYSCFG_EXTICR_EXTIx_PB << ((Pin % SYSCFG_EXTICR_EXTIs_PER_REGISTER) * SYSCFG_EXTICR_EXTIx_SIZE)));
        }
        // Set EXTI line to GPIOC
        else if (GPIOx == GPIOC)
        {
            SET_BIT(SYSCFG->EXTICR[Pin / SYSCFG_EXTICR_EXTIs_PER_REGISTER], 
                    (SYSCFG_EXTICR_EXTIx_PC << ((Pin % SYSCFG_EXTICR_EXTIs_PER_REGISTER) * SYSCFG_EXTICR_EXTIx_SIZE)));
        }
        // Set EXTI line to GPIOD
        else if (GPIOx == GPIOD)
        {
            SET_BIT(SYSCFG->EXTICR[Pin / SYSCFG_EXTICR_EXTIs_PER_REGISTER], 
                    (SYSCFG_EXTICR_EXTIx_PD << ((Pin % SYSCFG_EXTICR_EXTIs_PER_REGISTER) * SYSCFG_EXTICR_EXTIx_SIZE)));
        }
        // Set EXTI line to GPIOE
        else if (GPIOx == GPIOE)
        {
            SET_BIT(SYSCFG->EXTICR[Pin / SYSCFG_EXTICR_EXTIs_PER_REGISTER], 
                    (SYSCFG_EXTICR_EXTIx_PE << ((Pin % SYSCFG_EXTICR_EXTIs_PER_REGISTER) * SYSCFG_EXTICR_EXTIx_SIZE)));
        }
        // Set EXTI line to GPIOF
        else if (GPIOx == GPIOF)
        {
            SET_BIT(SYSCFG->EXTICR[Pin / SYSCFG_EXTICR_EXTIs_PER_REGISTER], 
                    (SYSCFG_EXTICR_EXTIx_PF << ((Pin % SYSCFG_EXTICR_EXTIs_PER_REGISTER) * SYSCFG_EXTICR_EXTIx_SIZE)));
        }
        // Set EXTI line to GPIOG
        else if (GPIOx == GPIOG)
        {
            SET_BIT(SYSCFG->EXTICR[Pin / SYSCFG_EXTICR_EXTIs_PER_REGISTER], 
                    (SYSCFG_EXTICR_EXTIx_PG << ((Pin % SYSCFG_EXTICR_EXTIs_PER_REGISTER) * SYSCFG_EXTICR_EXTIx_SIZE)));
        }
        // Set EXTI line to GPIOH
        else if (GPIOx == GPIOH)
        {
            SET_BIT(SYSCFG->EXTICR[Pin / SYSCFG_EXTICR_EXTIs_PER_REGISTER], 
                    (SYSCFG_EXTICR_EXTIx_PH << ((Pin % SYSCFG_EXTICR_EXTIs_PER_REGISTER) * SYSCFG_EXTICR_EXTIx_SIZE)));
        }
        // Set EXTI line to GPIOI
        else if (GPIOx == GPIOI)
        {
            SET_BIT(SYSCFG->EXTICR[Pin / SYSCFG_EXTICR_EXTIs_PER_REGISTER], 
                    (SYSCFG_EXTICR_EXTIx_PI << ((Pin % SYSCFG_EXTICR_EXTIs_PER_REGISTER) * SYSCFG_EXTICR_EXTIx_SIZE)));
        }
        // Set EXTI line to GPIOJ
        else if (GPIOx == GPIOJ)
        {
            SET_BIT(SYSCFG->EXTICR[Pin / SYSCFG_EXTICR_EXTIs_PER_REGISTER], 
                    (SYSCFG_EXTICR_EXTIx_PJ << ((Pin % SYSCFG_EXTICR_EXTIs_PER_REGISTER) * SYSCFG_EXTICR_EXTIx_SIZE)));
        }
        // Set EXTI line to GPIOK
        else if (GPIOx == GPIOK)
        {
            SET_BIT(SYSCFG->EXTICR[Pin / SYSCFG_EXTICR_EXTIs_PER_REGISTER], 
                    (SYSCFG_EXTICR_EXTIx_PK << ((Pin % SYSCFG_EXTICR_EXTIs_PER_REGISTER) * SYSCFG_EXTICR_EXTIx_SIZE)));
        }
        else
        {
            // Return E_NOT_OK if no valid GPIO port is found
            return E_NOT_OK;
        }
    }

    // Return E_OK if configuration is successful
    return E_OK;
}
