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


/* USART Control Register 1 Bit Position Definitions */
#define USART_CR1_UE_Pos        0   /**< USART Enable */
#define USART_CR1_UESM_Pos      1   /**< USART Enable in Stop Mode */
#define USART_CR1_RE_Pos        2   /**< Receiver Enable */
#define USART_CR1_TE_Pos        3   /**< Transmitter Enable */
#define USART_CR1_IDLEIE_Pos    4   /**< IDLE Interrupt Enable */
#define USART_CR1_RXNEIE_Pos    5   /**< RXNE Interrupt Enable */
#define USART_CR1_RXFNEIE_Pos   5
#define USART_CR1_TCIE_Pos      6   /**< Transmission Complete Interrupt Enable */
#define USART_CR1_TXEIE_Pos     7   /**< TXE Interrupt Enable */
#define USART_CR1_TXFNFIE_Pos   7
#define USART_CR1_PEIE_Pos      8   /**< PE Interrupt Enable */
#define USART_CR1_PS_Pos        9   /**< Parity Selection */
#define USART_CR1_PCE_Pos       10  /**< Parity Control Enable */
#define USART_CR1_WAKE_Pos      11  /**< Wakeup Method */
#define USART_CR1_M0_Pos        12  /**< Word Length Bit 0 */
#define USART_CR1_MME_Pos       13  /**< Mute Mode Enable */
#define USART_CR1_CMIE_Pos      14  /**< Character Match Interrupt Enable */
#define USART_CR1_OVER8_Pos     15  /**< Oversampling Mode */
#define USART_CR1_DEDT_Pos      16  /**< Driver Enable Deassertion Time */
#define USART_CR1_DEAT_Pos      21  /**< Driver Enable Assertion Time */
#define USART_CR1_RTOIE_Pos     26  /**< Receiver Timeout Interrupt Enable */
#define USART_CR1_EOBIE_Pos     27  /**< End of Block Interrupt Enable */
#define USART_CR1_M1_Pos        28  /**< Word Length Bit 1 */
#define USART_CR1_FIFOEN_Pos    29  /**< FIFO Mode Enable */
#define USART_CR1_TXFEIE_Pos    30  /**< TXFIFO Empty Interrupt Enable */
#define USART_CR1_RXFFIE_Pos    31  /**< RXFIFO Full Interrupt Enable */

/* USART Control Register 2 Bit Position Definitions */
#define USART_CR2_SLVEN_Pos     0   /**< Synchronous Slave Mode Enable */
#define USART_CR2_DIS_NSS_Pos   3   /**< Slave Select (NSS) Pin Management */
#define USART_CR2_ADDM7_Pos     4   /**< 7-bit Address Detection/4-bit Address Detection */
#define USART_CR2_LBDL_Pos      5   /**< LIN Break Detection Length */
#define USART_CR2_LBDIE_Pos     6   /**< LIN Break Detection Interrupt Enable */
#define USART_CR2_LBCL_Pos      8   /**< Last Bit Clock Pulse */
#define USART_CR2_CPHA_Pos      9   /**< Clock Phase */
#define USART_CR2_CPOL_Pos      10  /**< Clock Polarity */
#define USART_CR2_CLKEN_Pos     11  /**< Clock Enable */
#define USART_CR2_STOP_Pos      12  /**< STOP Bits */
#define USART_CR2_LINEN_Pos     14  /**< LIN Mode Enable */
#define USART_CR2_SWAP_Pos      15  /**< Swap TX/RX Pins */
#define USART_CR2_RXINV_Pos     16  /**< RX Pin Active Level Inversion */
#define USART_CR2_TXINV_Pos     17  /**< TX Pin Active Level Inversion */
#define USART_CR2_DATAINV_Pos   18  /**< Binary Data Inversion */
#define USART_CR2_MSBFIRST_Pos  19  /**< Most Significant Bit First */
#define USART_CR2_ABREN_Pos     20  /**< Auto Baud Rate Enable */
#define USART_CR2_ABRMODE_Pos   21  /**< Auto Baud Rate Mode */
#define USART_CR2_RTOEN_Pos     23  /**< Receiver Timeout Enable */
#define USART_CR2_ADD_Pos       24  /**< Address of the USART Node */


/* USART Control Register 3 Bit Position Definitions */
#define USART_CR3_EIE_Pos       0   /**< Error Interrupt Enable */
#define USART_CR3_IREN_Pos      1   /**< IrDA Mode Enable */
#define USART_CR3_IRLP_Pos      2   /**< IrDA Low-Power */
#define USART_CR3_HDSEL_Pos     3   /**< Half-Duplex Selection */
#define USART_CR3_NACK_Pos      4   /**< Smartcard NACK Enable */
#define USART_CR3_SCEN_Pos      5   /**< Smartcard Mode Enable */
#define USART_CR3_DMAR_Pos      6   /**< DMA Enable Receiver */
#define USART_CR3_DMAT_Pos      7   /**< DMA Enable Transmitter */
#define USART_CR3_RTSE_Pos      8   /**< RTS Enable */
#define USART_CR3_CTSE_Pos      9   /**< CTS Enable */
#define USART_CR3_CTSIE_Pos     10  /**< CTS Interrupt Enable */
#define USART_CR3_ONEBIT_Pos    11  /**< One Sample Bit Method Enable */
#define USART_CR3_OVRDIS_Pos    12  /**< Overrun Disable */
#define USART_CR3_DDRE_Pos      13  /**< DMA Disable on Reception Error */
#define USART_CR3_DEM_Pos       14  /**< Driver Enable Mode */
#define USART_CR3_DEP_Pos       15  /**< Driver Enable Polarity Selection */
#define USART_CR3_SCARCNT_Pos   17  /**< Smartcard Auto-Retry Count */
#define USART_CR3_WUS_Pos       20  /**< Wakeup from Stop Mode Interrupt Flag Selection */
#define USART_CR3_WUFIE_Pos     22  /**< Wakeup from Stop Mode Interrupt Enable */
#define USART_CR3_TXFTIE_Pos    23  /**< TXFIFO Threshold Interrupt Enable */
#define USART_CR3_TCBGTIE_Pos   24  /**< Transmission Complete Before Guard Time Interrupt Enable */
#define USART_CR3_RXFTCFG_Pos   25  /**< RXFIFO Threshold Configuration */
#define USART_CR3_RXFTIE_Pos    28  /**< RXFIFO Threshold Interrupt Enable */
#define USART_CR3_TXFTCFG_Pos   29  /**< TXFIFO Threshold Configuration */

/* USART Interrupt and Status Bit Position Definitions */
#define USART_ISR_PE_Pos        0   /**< Parity Error */
#define USART_ISR_FE_Pos        1   /**< Framing Error */
#define USART_ISR_NE_Pos        2   /**< Noise Error */
#define USART_ISR_ORE_Pos       3   /**< Overrun Error */
#define USART_ISR_IDLE_Pos      4   /**< Idle Line Detected */
#define USART_ISR_RXFNE_Pos     5   /**< Read Data Register Not Empty */
#define USART_ISR_TC_Pos        6   /**< Transmission Complete */
#define USART_ISR_TXFNF_Pos     7   /**< Transmit Data Register Not Full */
#define USART_ISR_LBDF_Pos      8   /**< LIN Break Detection Flag */
#define USART_ISR_CTSIF_Pos     9   /**< CTS Interrupt Flag */
#define USART_ISR_CTS_Pos       10  /**< CTS Flag */
#define USART_ISR_RTOF_Pos      11  /**< Receiver Timeout */
#define USART_ISR_EOBF_Pos      12  /**< End of Block Flag */
#define USART_ISR_UDR_Pos       13  /**< SPI Slave underrun error flag */
#define USART_ISR_ABRE_Pos      14  /**< Auto Baud Rate Error */
#define USART_ISR_ABRF_Pos      15  /**< Auto Baud Rate Flag */
#define USART_ISR_BUSY_Pos      16  /**< Busy Flag */
#define USART_ISR_CMF_Pos       17  /**< Character Match Flag */
#define USART_ISR_SBKF_Pos      18  /**< Send Break Flag */
#define USART_ISR_RWU_Pos       19  /**< Receive Wake Up from mute mode Flag */
#define USART_ISR_WUF_Pos       20  /**< Wake Up from stop mode Flag */
#define USART_ISR_TEACK_Pos     21  /**< Transmit Enable Acknowledge Flag */
#define USART_ISR_REACK_Pos     22  /**< Receive Enable Acknowledge Flag */
#define USART_ISR_TXFE_Pos      23  /**< TX FIFO Empty */
#define USART_ISR_RXFF_Pos      24  /**< RX FIFO Full */
#define USART_ISR_TCBGT_Pos     25  /**< Transmission Complete Before Guard Time completion flag */
#define USART_ISR_TXFT_Pos      26  /**< TX FIFO Threshold flag */
#define USART_ISR_RXFT_Pos      27  /**< RX FIFO Threshold flag */

/* USART Oversampling Mode Definitions */
#define USART_OverSamplingBy8   1   /**< 8x oversampling */
#define USART_OverSamplingBy16  0   /**< 16x oversampling */

/* USART Data Bit Length Definitions */
#define USART_DataBit_7         2   /**< 7 data bits in communication */
#define USART_DataBit_8         0   /**< 8 data bits in communication */
#define USART_DataBit_9         1   /**< 9 data bits in communication */

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
extern void USART_Config(USART_ST *USARTx, UINT32 SysClock, UINT32 Baudrate, BOOL OverSamplingMode, UINT8 DataLengthCode, UINT8 NumberOfStopBit, UINT8 ParityCheck);
extern void USART_SetMode(USART_ST *USARTx, USART_Mode Mode);
extern USART_Mode USART_GetMode(USART_ST *USARTx);
extern void USART_EnableFIFO(USART_ST *USARTx);
extern void USART_DisableFIFO(USART_ST *USARTx);
extern void USART_Config_Interrupt(USART_ST *USARTx, UINT32 Interrupt_Mode);
extern void USART_Enable_ClockSource(USART_ST *USARTx);
extern void USART_Enable(USART_ST *USARTx);
extern void USART_Disable(USART_ST *USARTx);
extern void USART_Transmit_Single_Data(USART_ST *USARTx, UINT16 Data);
extern void USART_Transmit(USART_ST *USARTx, const char *str);
extern UINT16 USART_Receive_Single_Data(USART_ST *USARTx);

#endif