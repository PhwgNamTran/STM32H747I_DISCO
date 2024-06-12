#include "STM32H747XI_SYSCFG.h"

/*
Function description: Enable SYSCFG Clocksource.
Input: N/A
Return value: N/A
*/
void SYSCFG_Enable()
{
    SET_BIT(RCC->APB4ENR, RCC_APB4ENR_SYSCFGEN); 
}

/*
Function description: Enable External Interrupt for GPIO Pin.
Input:
        - GPIO Port A, B, C, ...K number 0, 1, 2, ...10.
        - GPIO Pin: 0, 1, ...15.
Return value: N/A
*/
void SYSCFG_EXITx_GPIO_Enabled(UINT8 GPIO_x_Num, UINT8 GPIO_Pin)
{
    if(GPIO_x_Num == GPIO_K_Num 
       && ((GPIO_PIN_8 <= GPIO_Pin)&&(GPIO_PIN_15 >= GPIO_Pin)))
    {
        /* GPIO K Pin from 8 to 15 not support for EXTI */
    }
    else
    {
        CLEAR_BIT(SYSCFG->EXTICR[GPIO_Pin/4], (GPIO_x_Num << ((GPIO_Pin%4)*4)));
        SET_BIT(SYSCFG->EXTICR[GPIO_Pin/4], (GPIO_x_Num << ((GPIO_Pin%4)*4)));
    }
}