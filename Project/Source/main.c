#include "Common.h"
#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"

int main(void)
{
    /* Enable clock for GPIO_C */
    GPIO_Enable_ClockSource(GPIO_C_CLKSRC);

    /* Set GPIO_C_PIN13 mode as Input Mode */
    CLEAR_BIT(GPIO_C->MODER, (3 << 26));

    /* Reset GPIO_C_PIN13 pull up/down register*/
    CLEAR_BIT(GPIO_C->PUPDR, (3 << 26));

    /* Set GPIO_C_PIN13 register pull-down*/
    SET_BIT(GPIO_C->PUPDR, (2 << 26));

    /* Enable clock for GPIO_I */
    GPIO_Enable_ClockSource(GPIO_I_CLKSRC);

    /* Reset Mode for GPIO_I_PIN12 */
    CLEAR_BIT(GPIO_I->MODER, (3 << 24));

    /* Set GPIO_I_PIN12 mode as General Output Mode */
    SET_BIT(GPIO_I->MODER, (1 << 24));

    /* Set GPIO_I_PIN12 No register pull up/down */
    CLEAR_BIT(GPIO_I->PUPDR, (3 << 24));

    /* Set GPIO_I_PIN12 Output type to Open-drain */
    CLEAR_BIT(GPIO_I->OTYPER, (1 << 12));

    while (1) 
    {
        /* Check if WK_Button is NOT pressed */
        if(CHECK_BIT(GPIO_C->IDR, (1 << 13)))
        {
            /* OFF USER LED1 */
            CLEAR_BIT(GPIO_I->ODR, (1 << 12));
        }
        else
        {
            /* ON USER LED1 */
            SET_BIT(GPIO_I->ODR, (1 << 12));
        }
    }

    return 0;
}