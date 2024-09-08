#ifndef CM7_PROJECT_CONFIG_H
#define CM7_PROJECT_CONFIG_H

#include "Common.h"
#include "STM32H747XI_RCC.h"
#include "STM32H747XI_USART.h"

/*
 * Project Configuration:
 * ----------------------
 * This header file defines configuration macros for project-specific features.
 */
#define System_Clock         16000000U
#define System_Clock_Source  System_Clock_Source_HSI

#if(System_Clock_Source == System_Clock_Source_HSI)
#define HSI_DIV              (uint8_t)(HSI_Clock/System_Clock)
#endif

#define USER_LED_1_USED      STD_ON
#define USER_LED_2_USED      STD_OFF
#define USER_LED_3_USED      STD_OFF
#define USER_LED_4_USED      STD_OFF

#define WK_BUTTON_USED              STD_ON
#if(WK_BUTTON_USED)
#define WK_BUTTON_Interrupt_USED    STD_ON
#endif

#define STLINK_VCP_USED                 STD_ON
#if(STLINK_VCP_USED)
#define STLink_VCP_USART_Mode           USART_ASYNC_TX_RX
#define STLink_VCP_Interrupt_USED       STD_ON
#if(STLink_VCP_Interrupt_USED)
#define STLink_VCP_USART_Interrupt_Mode USART_Interrupt_ReceptionDataNotEmpty
#define STLink_VCP_USART_RxBufferSize   8
#endif
#endif

#define TIM2_USED                   STD_OFF
#if(TIM2_USED)
#define TIM2_Interrupt_USED         STD_ON
#define TIM2_PSC                    15999U
#define TIM2_ARR                    999U
#endif

#endif /* PROJECT_CONFIG_H */
