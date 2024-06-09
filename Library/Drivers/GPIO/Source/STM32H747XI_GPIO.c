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

void GPIO_Mode_Set(GPIO_ST *GPIOx, UINT16 Pin, UINT8 Mode)
{
    // Clear the mode register
    GPIOx->MODER &= ~(GPIO_Mode_Input << (Pin * 2));
    // Set the new mode
    GPIOx->MODER |= ((Mode & 0x3) << (Pin * 2));
}

void GPIO_Pull_Set(GPIO_ST *GPIOx, UINT16 Pin, UINT8 Pull)
{
    // Clear the pull-up/pull-down register
    GPIOx->PUPDR &= ~(GPIO_No_Pull << (Pin * 2));
    // Set the new value
    GPIOx->PUPDR |= ((Pull & 0x3) << (Pin * 2));
}

void GPIO_OutputType_Set(GPIO_ST *GPIOx, UINT16 Pin, UINT8 OutputType)
{
    // Clear the output type register
    GPIOx->OTYPER &= ~(GPIO_Output_PushPull << (Pin * 1));
    // Set the new value
    GPIOx->OTYPER |= ((OutputType & 0x3) << (Pin * 1));
}