#ifndef USERLED_H
#define USERLED_H

#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"
#include "Common.h"

#define UserLED_ClockSrc    GPIO_C_CLKSRC
#define UserLED_Port        GPIO_I

#define UserLED_1_PIN       12
#define UserLED_2_PIN       13
#define UserLED_3_PIN       14
#define UserLED_4_PIN       15

#define UserLED_1           0
#define UserLED_2           1
#define UserLED_3           2
#define UserLED_4           3

extern void UserLED_Init(void);
extern void UserLED_ON(UINT8 UserLEDx);
extern void UserLED_OFF(UINT8 UserLEDx);

#endif