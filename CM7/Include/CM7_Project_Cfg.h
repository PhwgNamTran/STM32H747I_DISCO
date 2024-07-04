#ifndef PROJECT_CONFIG_H
#define PROJECT_CONFIG_H

#include "Common.h"
#include "STM32H747XI_RCC.h"

/*
 * Project Configuration:
 * ----------------------
 * This header file defines configuration macros for project-specific features.
 */
#define System_Clock         16000000U
#define System_Clock_Source  System_Clock_Source_HSI

#if(System_Clock_Source == System_Clock_Source_HSI)
#define HSI_DIV              (UINT8)(HSI_Clock/System_Clock)
#endif

#define USER_LED_1_USED      STD_ON
#define USER_LED_2_USED      STD_OFF
#define USER_LED_3_USED      STD_OFF
#define USER_LED_4_USED      STD_OFF

#define WK_BUTTON_USED       STD_ON
#define WK_BUTTON_Interrupt  STD_OFF

#define TIM2_PSC             15999U
#define TIM2_ARR             999U

#endif /* PROJECT_CONFIG_H */
