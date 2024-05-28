#include "STM32H747XI_GPIO.h"
#include "STM32H747XI_RCC.h"
#include "Common.h"

/*
Function description: Enable Clock Source of GPIO Port
Input: GPIO Port A, B, C, ...K.
Return value: N/A
*/
void GPIO_Enable_ClockSource(GPIO_Port GPIO_Port_Name)
{
    SET_BIT(RCC_AHB4ENR, (1 << GPIO_Port_Name));
}

/*
Function description: Disable Clock Source of GPIO Port
Input: GPIO Port A, B, C, ...K.
Return value: N/A
*/
void GPIO_Disable_ClockSource(GPIO_Port GPIO_Port_Name)
{
    CLEAR_BIT(RCC_AHB4ENR, (1 << GPIO_Port_Name));
}