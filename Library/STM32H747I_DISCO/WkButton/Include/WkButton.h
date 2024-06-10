#ifndef WKBUTTON_H
#define WKBUTTON_H

#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"
#include "Common.h"

typedef enum
{
    C_Button_Released_N,
    C_Button_Pressed_N, 
} ButtonState_N;

#define WK_Button_ClockSrc    GPIO_C_CLKSRC
#define WK_Button_Port        GPIO_C
#define WK_Button_PIN         13U

#define Button_Pressed        TRUE
#define Button_Released       FALSE

extern void WK_Button_Init(void);
extern ButtonState_N WK_Button_State(void);
extern BOOL WK_Button_Pressed_then_Released_B(void);

#endif