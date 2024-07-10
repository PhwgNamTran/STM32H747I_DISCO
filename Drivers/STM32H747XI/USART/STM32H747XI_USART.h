#ifndef STM32H747XI_USART_H
#define STM32H747XI_USART_H

#include "Common.h"
#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"

/* Refer to RM0399 Reference Manual from http://www.st.com and CMSIS Library */

/* USART Register - Refer to CMSIS Library */
typedef struct
{
    volatile UINT32 CR1;    /*!< USART Control register 1,                 Address offset: 0x00 */
    volatile UINT32 CR2;    /*!< USART Control register 2,                 Address offset: 0x04 */
    volatile UINT32 CR3;    /*!< USART Control register 3,                 Address offset: 0x08 */
    volatile UINT32 BRR;    /*!< USART Baud rate register,                 Address offset: 0x0C */
    volatile UINT32 GTPR;   /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
    volatile UINT32 RTOR;   /*!< USART Receiver Time Out register,         Address offset: 0x14 */
    volatile UINT32 RQR;    /*!< USART Request register,                   Address offset: 0x18 */
    volatile UINT32 ISR;    /*!< USART Interrupt and status register,      Address offset: 0x1C */
    volatile UINT32 ICR;    /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
    volatile UINT32 RDR;    /*!< USART Receive Data register,              Address offset: 0x24 */
    volatile UINT32 TDR;    /*!< USART Transmit Data register,             Address offset: 0x28 */
    volatile UINT32 PRESC;  /*!< USART clock Prescaler register,           Address offset: 0x2C */
} USART_ST;

/* USART Control Register 1 Bit Position Definitions */
#define USART_CR1_UE_Pos        0   /**< USART Enable */
#define USART_CR1_PCE_Pos       10  /**< Parity Control Enable */
#define USART_CR1_PS_Pos        11  /**< Parity Selection */
#define USART_CR1_M0_Pos        12  /**< Word Length Bit 0 */
#define USART_CR1_OVER8_Pos     15  /**< Oversampling Mode */
#define USART_CR1_M1_Pos        28  /**< Word Length Bit 1 */

/* USART Control Register 2 Bit Position Definitions */
#define USART_CR2_STOP_Pos      12  /**< STOP Bits */

/* USART Stop Bit Definitions */
#define USART_StopBit_1         0   /**< 1 Stop bit */
#define USART_StopBit_0_5       1   /**< 0.5 Stop bit */
#define USART_StopBit_2         2   /**< 2 Stop bits */
#define USART_StopBit_1_5       3   /**< 1.5 Stop bits */

/* USART Parity Definitions */
#define USART_Parity_None       2   /**< No Parity */
#define USART_Parity_Even       0   /**< Even Parity */
#define USART_Parity_Odd        1   /**< Odd Parity */

/* Base Address of USART/UART */
#define USART1_BASE     0x40011000UL  /**< Base address of USART1 peripheral */
#define USART2_BASE     0x40004400UL  /**< Base address of USART2 peripheral */
#define USART3_BASE     0x40004800UL  /**< Base address of USART3 peripheral */
#define UART4_BASE      0x40004C00UL  /**< Base address of UART4 peripheral */
#define UART5_BASE      0x40005000UL  /**< Base address of UART5 peripheral */
#define USART6_BASE     0x40011400UL  /**< Base address of USART6 peripheral */
#define UART7_BASE      0x40007800UL  /**< Base address of UART7 peripheral */
#define UART8_BASE      0x40007C00UL  /**< Base address of UART8 peripheral */

/* USART/UART Declarations */
#define USART1          ((USART_ST *) USART1_BASE)  /**< USART1 peripheral declaration */
#define USART2          ((USART_ST *) USART2_BASE)  /**< USART2 peripheral declaration */
#define USART3          ((USART_ST *) USART3_BASE)  /**< USART3 peripheral declaration */
#define UART4           ((USART_ST *) UART4_BASE)   /**< UART4 peripheral declaration */
#define UART5           ((USART_ST *) UART5_BASE)   /**< UART5 peripheral declaration */
#define USART6          ((USART_ST *) USART6_BASE)  /**< USART6 peripheral declaration */
#define UART7           ((USART_ST *) UART7_BASE)   /**< UART7 peripheral declaration */
#define UART8           ((USART_ST *) UART8_BASE)   /**< UART8 peripheral declaration */

/* USART/UART Clock Source Definitions in RCC_APB1LENR */
#define USART2_ClockSource      (1 << 17) /**< USART2 Clock Source in RCC_APB1LENR */
#define USART3_ClockSource      (1 << 18) /**< USART3 Clock Source in RCC_APB1LENR */
#define UART4_ClockSource       (1 << 19) /**< UART4 Clock Source in RCC_APB1LENR */
#define UART5_ClockSource       (1 << 20) /**< UART5 Clock Source in RCC_APB1LENR */
#define UART7_ClockSource       (1 << 30) /**< UART7 Clock Source in RCC_APB1LENR */
#define UART8_ClockSource       (1 << 31) /**< UART8 Clock Source in RCC_APB1LENR */

/* USART/UART Clock Source Definitions in RCC_APB2ENR */
#define USART1_ClockSource      (1 << 4)  /**< USART1 Clock Source in RCC_APB2ENR */
#define USART6_ClockSource      (1 << 5)  /**< USART6 Clock Source in RCC_APB2ENR */

extern void USART_PIN_Config(GPIO_ST *GPIOx, UINT8 GPIO_AFx, UINT8 USART_Rx_PIN, UINT8 USART_Tx_PIN);
extern void USART_Config(USART_ST *USARTx, UINT32 SysClock,UINT16 Baudrate, BOOL OverSamplingMode, UINT8 DataLengthCode, UINT8 NumberOfStopBit, UINT8 ParityCheck);
extern void USART_Enable_ClockSource(USART_ST *USARTx);

#endif