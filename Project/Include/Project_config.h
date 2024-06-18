#ifndef PROJECT_CONFIG_H
#define PROJECT_CONFIG_H

#include "Common.h"

#define USER_LED_1_USED      STD_ON
#define USER_LED_2_USED      STD_OFF
#define USER_LED_3_USED      STD_OFF
#define USER_LED_4_USED      STD_OFF     

#define WK_BUTTON_USED       STD_ON
#define WK_BUTTON_INTERRUPT  STD_ON

#define EXTI_0_USED          STD_OFF
#define EXTI_1_USED          STD_OFF
#define EXTI_2_USED          STD_OFF
#define EXTI_3_USED          STD_OFF
#define EXTI_4_USED          STD_OFF
#define EXTI_5_USED          STD_OFF
#define EXTI_6_USED          STD_OFF
#define EXTI_7_USED          STD_OFF
#define EXTI_8_USED          STD_OFF
#define EXTI_9_USED          STD_OFF
#define EXTI_10_USED         STD_OFF
#define EXTI_11_USED         STD_OFF
#define EXTI_12_USED         STD_OFF
#if(WK_BUTTON_INTERRUPT)
#define EXTI_13_USED         STD_ON
#else
#define EXTI_13_USED         STD_OFF
#endif
#define EXTI_14_USED         STD_OFF
#define EXTI_15_USED         STD_OFF




#endif