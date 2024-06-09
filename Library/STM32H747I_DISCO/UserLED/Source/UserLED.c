#include "Common.h"
#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"
#include "UserLED.h"

void UserLED_Init(void)
{
    /* Enable clock for UserLED */
    GPIO_Enable_ClockSource(UserLED_ClockSrc);
}