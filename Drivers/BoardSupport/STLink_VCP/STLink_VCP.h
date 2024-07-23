#ifndef STLINK_VCP_H
#define STLINK_VCP_H

#include "Common.h"
#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"
#include "STM32H747XI_USART.h"

/* HW configuration for STLink_VCP which connects to USART1 of STM32H747XI on STM32H747I-DISCO */
#define STLink_VCP_USART_GPIO_Port              GPIO_A                /**< GPIO Port for STLink VCP USART */
#define STLink_VCP_USART_GPIO_Port_CLKSRC       GPIO_A_CLKSRC         /**< Clocksource for STLink VCP USART Pin */
#define STLink_VCP_USART_Tx_PIN                 GPIO_PIN_9            /**< GPIO Pin for USART Tx */
#define STLink_VCP_USART_Rx_PIN                 GPIO_PIN_10           /**< GPIO Pin for USART Rx */
#define STLink_VCP_USART_GPIO_AFx               GPIO_AF_7             /**< GPIO Alternate Function for USART */
#define STLink_VCP_USART                        USART1                /**< USART Instance for STLink VCP */

/* Parameter configuration for USART, CAN BE CHANGED */    
#define STLink_VCP_USART_Baudrate               115200UL               /**< Baudrate for USART communication */
#define STLink_VCP_USART_OverSamplingMode       USART_OverSamplingBy16 /**< Oversampling mode for USART */
#define STLink_VCP_USART_DataLengthCode         USART_DataBit_8        /**< Data length code for USART */
#define STLink_VCP_USART_NumberOfStopBit        USART_StopBit_1        /**< Number of stop bits for USART */
#define STLink_VCP_USART_ParityCheck            USART_Parity_None      /**< Parity check mode for USART */

extern void STLink_VCP_Init(UINT32 SysClock_Hz, USART_Mode Mode);
extern void STLink_VCP_Send(const char *str);

#endif