#ifndef USERLED_H
#define USERLED_H

#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"
#include "Common.h"

#define UserLED_ClockSrc    GPIO_C_CLKSRC

extern void UserLED_Init(void);

#endif