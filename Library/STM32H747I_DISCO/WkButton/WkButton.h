#ifndef WKBUTTON_H
#define WKBUTTON_H

#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"
#include "STM32H747XI_EXTI.h"
#include "STM32H747XI_NVIC.h"
#include "STM32H747XI_SYSCFG.h"
#include "STM32H747XI_EXTI.h"
#include "Common.h"

typedef enum
{
    C_Button_Released_N,
    C_Button_Pressed_N, 
} ButtonState_N;

#define WK_Button_ClockSrc    GPIO_C_CLKSRC
#define WK_Button_Port        GPIO_C
#define WK_Button_Port_Num    GPIO_C_Num
#define WK_Button_PIN         13U

#define Button_Pressed        TRUE
#define Button_Released       FALSE

#define WK_Button_Event_Input   Event_Input_EXTI_13
#define WK_Button_IRQn          IRQn_EXTI15_10

extern void WK_Button_Init(void);
extern void WK_Button_Interrupt_Init(void);

extern ButtonState_N WK_Button_State(void);
extern BOOL WK_Button_Pressed_then_Released_B(void);
extern BOOL WK_Button_Released_then_Pressed_B(void);

#endif