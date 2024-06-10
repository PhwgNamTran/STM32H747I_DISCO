#ifndef USERLED_H
#define USERLED_H

#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"
#include "Common.h"

#define UserLED_ClockSrc    GPIO_I_CLKSRC
#define UserLED_Port        GPIO_I

#define UserLED_1_PIN       12U
#define UserLED_2_PIN       13U
#define UserLED_3_PIN       14U
#define UserLED_4_PIN       15U

#define UserLED_1           0U
#define UserLED_2           1U
#define UserLED_3           2U
#define UserLED_4           3U

extern void UserLED_Init(void);
extern void UserLED_ON(UINT8 UserLEDx);
extern void UserLED_OFF(UINT8 UserLEDx);

#endif