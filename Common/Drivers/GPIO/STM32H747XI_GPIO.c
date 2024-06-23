#include "STM32H747XI_GPIO.h"

/*
Function description: Enable Clock Source of GPIO Port
Input: GPIO Port A, B, C, ...K.
Return value: N/A
*/
void GPIO_Enable_ClockSource(UINT16 GPIOx_CLKSRC)
{
    SET_BIT(RCC->AHB4ENR, GPIOx_CLKSRC);
}

/*
Function description: Disable Clock Source of GPIO Port
Input: GPIO Port A, B, C, ...K.
Return value: N/A
*/
void GPIO_Disable_ClockSource(UINT16 GPIOx_CLKSRC)
{
    CLEAR_BIT(RCC->AHB4ENR, GPIOx_CLKSRC);
}

/*
Function description: Set value for GPIO Mode register
Input:
        - GPIO Port A, B, C, ...K.
        - GPIO Pin 0, 1, ...15.
        - Mode: Input, Output, Alternate Function, Analog.
Return value: N/A
*/
void GPIO_Mode_Set(GPIO_ST *GPIOx, UINT16 Pin, UINT8 Mode)
{
    // Clear the mode register
    CLEAR_BIT(GPIOx->MODER, (0x3 << (Pin * 2)));
    // Set the new mode
    SET_BIT(GPIOx->MODER, ((Mode & 0x3) << (Pin * 2)));
}

/*
Function description: Set value for GPIO pull up/down resistor 
Input:
        - GPIO Port A, B, C, ...K.
        - GPIO Pin: 0, 1, ...15.
        - Pull mode: No pull, Pull up, Pull down, Reserved.
Return value: N/A
*/
void GPIO_Pull_Set(GPIO_ST *GPIOx, UINT16 Pin, UINT8 Pull)
{
    // Clear the pull-up/pull-down register
    CLEAR_BIT(GPIOx->PUPDR, (0x3 << (Pin * 2)));
    // Set the new value
    SET_BIT(GPIOx->PUPDR, ((Pull & 0x3) << (Pin * 2)));
}

/*
Function description: Set GPIO output type.
Input:
        - GPIO Port A, B, C, ...K.
        - GPIO Pin: 0, 1, ...15.
        - Output type: PushPull, Open drain.
Return value: N/A
*/
void GPIO_OutputType_Set(GPIO_ST *GPIOx, UINT16 Pin, BOOL OutputType)
{
    // Clear the output type register
    CLEAR_BIT(GPIOx->OTYPER, (0x1 << Pin));
    // Set the new value
    SET_BIT(GPIOx->OTYPER, (OutputType << Pin));
}

/*
Function description: Set value of ODR registor of GPIO Pin to 1.
Input:
        - GPIO Port A, B, C, ...K.
        - GPIO Pin: 0, 1, ...15.
Return value: N/A
*/
void GPIO_OutputData_Set(GPIO_ST *GPIOx, UINT16 Pin)
{
    // Set the output data register
    SET_BIT(GPIOx->ODR, (0x1 << Pin));
}

/*
Function description: Reset value of ODR registor of GPIO Pin to 0.
Input:
        - GPIO Port A, B, C, ...K.
        - GPIO Pin: 0, 1, ...15.
Return value: N/A
*/
void GPIO_OutputData_Reset(GPIO_ST *GPIOx, UINT16 Pin)
{
    // Clear the output data register
    CLEAR_BIT(GPIOx->ODR, (0x1 << Pin));
}

/*
Function description: Reverse value of ODR registor of GPIO Pin.
Input:
        - GPIO Port A, B, C, ...K.
        - GPIO Pin: 0, 1, ...15.
Return value: N/A
*/
void GPIO_OutputData_Toggle(GPIO_ST *GPIOx, UINT16 Pin)
{
    // Clear the output data register
    if(READ_BIT(GPIOx->ODR, (0x1 << Pin)))
    {
        CLEAR_BIT(GPIOx->ODR, (0x1 << Pin));
    }
    else
    {
        SET_BIT(GPIOx->ODR, (0x1 << Pin));
    }
}