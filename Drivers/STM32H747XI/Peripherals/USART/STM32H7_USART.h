#ifndef STM32H7_USART_H
#define STM32H7_USART_H

#include "STM32H747xx.h"
#include "STM32H7_RCC.h"
#include "STM32H7_GPIO.h"

/* Refer to RM0399 Reference Manual from http://www.st.com and CMSIS Library */

/* Enumeration for USART operating modes */
typedef enum {
    USART_ASYNC_TX_ONLY = 0,   /**< Asynchronous mode: Transmit only */
    USART_ASYNC_RX_ONLY,       /**< Asynchronous mode: Receive only */
    USART_ASYNC_TX_RX,         /**< Asynchronous mode: Transmit and receive */
    USART_SYNCHRONOUS,         /**< Synchronous mode */
    USART_SINGLEWIRE,          /**< Single-wire half-duplex mode */
    USART_SMARTCARD,           /**< Smartcard mode */
    USART_IRDA,                /**< IrDA mode */
    USART_LIN,                 /**< LIN mode */
    USART_RS485                /**< RS485 mode */
} USART_Mode;

/* Enumeration for USART interrupt modes */
typedef enum {
    USART_Interrupt_TransmitDataRegisterEmpty = (1 << 0),           /**< TXE: Transmit Data Register Empty */
    USART_Interrupt_TransmitFIFONotFull = (1 << 1),                 /**< TXFNF: Transmit FIFO Not Full */
    USART_Interrupt_TransmitFIFOEmpty = (1 << 2),                   /**< TXFE: Transmit FIFO Empty */
    USART_Interrupt_TransmitFIFOThresholdReached = (1 << 3),        /**< TXFT: Transmit FIFO Threshold Reached */
    USART_Interrupt_CTS = (1 << 4),                                 /**< CTSIF: CTS Interrupt */
    USART_Interrupt_TransmissionComplete = (1 << 5),                /**< TC: Transmission Complete */
    USART_Interrupt_TransmissionCompleteBeforeGuardTime = (1 << 6), /**< TCBGT: Transmission Complete Before Guard Time */
    USART_Interrupt_ReceptionDataNotEmpty = (1 << 7),               /**< RXNE: Receive Data Register Not Empty */
    USART_Interrupt_ReceiveFIFONotEmpty = (1 << 8),                 /**< RXFNE: Receive FIFO Not Empty */
    USART_Interrupt_ReceiveFIFOFull = (1 << 9),                     /**< RXFF: Receive FIFO Full */
    USART_Interrupt_ReceiveFIFOThresholdReached = (1 << 10),        /**< RXFT: Receive FIFO Threshold Reached */
    USART_Interrupt_OverrunErrorDetected = (1 << 11),               /**< ORE: Overrun Error Detected */
    USART_Interrupt_OverrunErrorMultibuffer = (1 << 12),            /**< ORE: Overrun Error in Multibuffer Communication */
    USART_Interrupt_Idle = (1 << 13),                               /**< IDLE: Idle Line Detected */
    USART_Interrupt_ParityError = (1 << 14),                        /**< PE: Parity Error */
    USART_Interrupt_LINBreakDetection = (1 << 15),                  /**< LBD: LIN Break Detection */
    USART_Interrupt_NoiseError = (1 << 16),                         /**< NE: Noise Error in Multibuffer Communication */
    USART_Interrupt_FramingError = (1 << 17),                       /**< FE: Framing Error in Multibuffer Communication */
    USART_Interrupt_CharacterMatch = (1 << 18),                     /**< CMF: Character Match */
    USART_Interrupt_ReceiverTimeout = (1 << 19),                    /**< RTOF: Receiver Timeout */
    USART_Interrupt_EndOfBlock = (1 << 20),                         /**< EOBF: End of Block */
    USART_Interrupt_WakeupFromLowPowerMode = (1 << 21),             /**< WUF: Wake-up from Low-Power Mode */
    USART_Interrupt_SPI_SlaveUnderrun = (1 << 22)                   /**< UDR: SPI Slave Underrun Error */
} USART_Interrupt_Mode;

/* USART Oversampling Mode Definitions */
#define USART_OverSamplingBy8   1   /**< 8x oversampling */
#define USART_OverSamplingBy16  0   /**< 16x oversampling */

/* USART Data Bit Length Definitions */
#define USART_DataBit_7         2   /**< 7 data bits in communication */
#define USART_DataBit_8         0   /**< 8 data bits in communication */
#define USART_DataBit_9         1   /**< 9 data bits in communication */

/* USART Stop Bit Definitions */
#define USART_STopBit_1         0   /**< 1 Stop bit */
#define USART_STopBit_0_5       1   /**< 0.5 Stop bit */
#define USART_STopBit_2         2   /**< 2 Stop bits */
#define USART_STopBit_1_5       3   /**< 1.5 Stop bits */

/* USART Parity Definitions */
#define USART_Parity_None       2   /**< No Parity */
#define USART_Parity_Even       0   /**< Even Parity */
#define USART_Parity_Odd        1   /**< Odd Parity */

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

extern void USART_PIN_Config(GPIO_ST *GPIOx, uint8_t GPIO_AFx, uint8_t USART_Rx_PIN, uint8_t USART_Tx_PIN);
extern void USART_Config(USART_ST *USARTx, uint32_t SysClock, uint32_t Baudrate, boolean OverSamplingMode, uint8_t DataLengthCode, uint8_t NumberOfStopBit, uint8_t ParityCheck);
extern void USART_SetMode(USART_ST *USARTx, USART_Mode Mode);
extern USART_Mode USART_GetMode(USART_ST *USARTx);
extern void USART_EnableFIFO(USART_ST *USARTx);
extern void USART_DisableFIFO(USART_ST *USARTx);
extern boolean USART_IsFIFOEnabled(USART_ST *USARTx);
extern void USART_Enable_Interrupt(USART_ST *USARTx, uint32_t Interrupt_Mode);
extern boolean USART_Check_Interrupt_Flag(USART_ST *USARTx, USART_Interrupt_Mode Interrupt_Mode);
extern void USART_Clear_Interrupt_Flag(USART_ST *USARTx, USART_Interrupt_Mode Interrupt_Mode);
extern void USART_Enable_ClockSource(USART_ST *USARTx);
extern void USART_Enable(USART_ST *USARTx);
extern void USART_Disable(USART_ST *USARTx);
extern void USART_Transmit_Single_Data(USART_ST *USARTx, uint16_t Data);
extern void USART_Transmit(USART_ST *USARTx, const char *str);
extern uint16_t USART_Receive_Single_Data(USART_ST *USARTx);

extern void USART_FlushReceiveData(USART_ST *USARTx);
extern void USART_FlushTransmitData(USART_ST *USARTx);
extern void USART_SendBreakRequest(USART_ST *USARTx);
extern void USART_EnterMuteMode(USART_ST *USARTx);
extern void USART_AutoBaudRateRequest(USART_ST *USARTx);

#endif