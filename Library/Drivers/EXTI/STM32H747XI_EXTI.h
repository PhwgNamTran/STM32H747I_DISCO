#ifndef STM32H747XI_EXTI_H
#define STM32H747XI_EXTI_H

#include "Common.h"

/* Refer to RM0399 Reference Manual from http://www.st.com */

/* EXTI Register - Refer to CMSIS Library */
typedef struct
{
    UINT32 RTSR1;               /*!< EXTI Rising trigger selection register,          Address offset: 0x00 */
    UINT32 FTSR1;               /*!< EXTI Falling trigger selection register,         Address offset: 0x04 */
    UINT32 SWIER1;              /*!< EXTI Software interrupt event register,          Address offset: 0x08 */
    UINT32 D3PMR1;              /*!< EXTI D3 Pending mask register, (same register as to SRDPMR1) Address offset: 0x0C */
    UINT32 D3PCR1L;             /*!< EXTI D3 Pending clear selection register low, (same register as to SRDPCR1L)     Address offset: 0x10 */
    UINT32 D3PCR1H;             /*!< EXTI D3 Pending clear selection register High, (same register as to SRDPCR1H)   Address offset: 0x14 */
    UINT32 RESERVED1[2];        /*!< Reserved,                                        0x18 to 0x1C         */
    UINT32 RTSR2;               /*!< EXTI Rising trigger selection register,          Address offset: 0x20 */
    UINT32 FTSR2;               /*!< EXTI Falling trigger selection register,         Address offset: 0x24 */
    UINT32 SWIER2;              /*!< EXTI Software interrupt event register,          Address offset: 0x28 */
    UINT32 D3PMR2;              /*!< EXTI D3 Pending mask register, (same register as to SRDPMR2) Address offset: 0x2C */
    UINT32 D3PCR2L;             /*!< EXTI D3 Pending clear selection register low, (same register as to SRDPCR2L)  Address offset: 0x30 */
    UINT32 D3PCR2H;             /*!< EXTI D3 Pending clear selection register High, (same register as to SRDPCR2H) Address offset: 0x34 */
    UINT32 RESERVED2[2];        /*!< Reserved,                                        0x38 to 0x3C         */
    UINT32 RTSR3;               /*!< EXTI Rising trigger selection register,          Address offset: 0x40 */
    UINT32 FTSR3;               /*!< EXTI Falling trigger selection register,         Address offset: 0x44 */
    UINT32 SWIER3;              /*!< EXTI Software interrupt event register,          Address offset: 0x48 */
    UINT32 D3PMR3;              /*!< EXTI D3 Pending mask register, (same register as to SRDPMR3) Address offset: 0x4C */
    UINT32 D3PCR3L;             /*!< EXTI D3 Pending clear selection register low, (same register as to SRDPCR3L) Address offset: 0x50 */
    UINT32 D3PCR3H;             /*!< EXTI D3 Pending clear selection register High, (same register as to SRDPCR3H) Address offset: 0x54 */
    UINT32 RESERVED3[10];       /*!< Reserved,                                        0x58 to 0x7C         */
    UINT32 C1IMR1;              /*!< EXTI Interrupt mask register,                    Address offset: 0x80 */
    UINT32 C1EMR1;              /*!< EXTI Event mask register,                        Address offset: 0x84 */
    UINT32 C1PR1;               /*!< EXTI Pending register,                           Address offset: 0x88 */
    UINT32 RESERVED4;           /*!< Reserved,                                        0x8C                 */
    UINT32 C1IMR2;              /*!< EXTI Interrupt mask register,                    Address offset: 0x90 */
    UINT32 C1EMR2;              /*!< EXTI Event mask register,                        Address offset: 0x94 */
    UINT32 C1PR2;               /*!< EXTI Pending register,                           Address offset: 0x98 */
    UINT32 RESERVED5;           /*!< Reserved,                                        0x9C                 */
    UINT32 C1IMR3;              /*!< EXTI Interrupt mask register,                    Address offset: 0xA0 */
    UINT32 C1EMR3;              /*!< EXTI Event mask register,                        Address offset: 0xA4 */
    UINT32 C1PR3;               /*!< EXTI Pending register,                           Address offset: 0xA8 */
    UINT32 RESERVED6[5];        /*!< Reserved,                                        0xAC to 0xBC         */
    UINT32 C2IMR1;              /*!< EXTI Interrupt mask register,                    Address offset: 0xC0 */
    UINT32 C2EMR1;              /*!< EXTI Event mask register,                        Address offset: 0xC4 */
    UINT32 C2PR1;               /*!< EXTI Pending register,                           Address offset: 0xC8 */
    UINT32 RESERVED7;           /*!< Reserved,                                        0xCC                 */
    UINT32 C2IMR2;              /*!< EXTI Interrupt mask register,                    Address offset: 0xD0 */
    UINT32 C2EMR2;              /*!< EXTI Event mask register,                        Address offset: 0xD4 */
    UINT32 C2PR2;               /*!< EXTI Pending register,                           Address offset: 0xD8 */
    UINT32 RESERVED8;           /*!< Reserved,                                        0xDC                 */
    UINT32 C2IMR3;              /*!< EXTI Interrupt mask register,                    Address offset: 0xE0 */
    UINT32 C2EMR3;              /*!< EXTI Event mask register,                        Address offset: 0xE4 */
    UINT32 C2PR3;               /*!< EXTI Pending register,                           Address offset: 0xE8 */
}EXTI_ST;

typedef struct
{
    UINT32 IMR1;                /*!< EXTI Interrupt mask register,                Address offset: 0x00 */
    UINT32 EMR1;                /*!< EXTI Event mask register,                    Address offset: 0x04 */
    UINT32 PR1;                 /*!< EXTI Pending register,                       Address offset: 0x08 */
    UINT32 RESERVED1;           /*!< Reserved, 0x0C                                                    */
    UINT32 IMR2;                /*!< EXTI Interrupt mask register,                Address offset: 0x10 */
    UINT32 EMR2;                /*!< EXTI Event mask register,                    Address offset: 0x14 */
    UINT32 PR2;                 /*!< EXTI Pending register,                       Address offset: 0x18 */
    UINT32 RESERVED2;           /*!< Reserved, 0x1C                                                    */
    UINT32 IMR3;                /*!< EXTI Interrupt mask register,                Address offset: 0x20 */
    UINT32 EMR3;                /*!< EXTI Event mask register,                    Address offset: 0x24 */
    UINT32 PR3;                 /*!< EXTI Pending register,                       Address offset: 0x28 */
}EXTI_Core_ST;

#define EXTI_BASE       0x58000000UL    /* EXTI Base Address */
#define EXTI_C1_BASE    0x58000080UL    /* EXTI Core 1 Base Address */
#define EXTI_C2_BASE    0x580000C0UL    /* EXTI Core 2 Base Address */

/* EXTI & EXTI Core Declaration */
#define EXTI         ((EXTI_ST *) EXTI_BASE)
#define EXTI_C1      ((EXTI_Core_ST *) EXTI_C1_BASE)
#define EXTI_C2      ((EXTI_Core_ST *) EXTI_C2_BASE)

#define Event_Input_Source_EXTI_0                           0U
#define Event_Input_Source_EXTI_1                           1U
#define Event_Input_Source_EXTI_2                           2U
#define Event_Input_Source_EXTI_3                           3U
#define Event_Input_Source_EXTI_4                           4U
#define Event_Input_Source_EXTI_5                           5U
#define Event_Input_Source_EXTI_6                           6U
#define Event_Input_Source_EXTI_7                           7U
#define Event_Input_Source_EXTI_8                           8U
#define Event_Input_Source_EXTI_9                           9U
#define Event_Input_Source_EXTI_10                          10U
#define Event_Input_Source_EXTI_11                          11U
#define Event_Input_Source_EXTI_12                          12U
#define Event_Input_Source_EXTI_13                          13U
#define Event_Input_Source_EXTI_14                          14U
#define Event_Input_Source_EXTI_15                          15U
#define Event_Input_Source_PVD_AVD                          16U
#define Event_Input_Source_RTC_Alarms                       17U
#define Event_Input_Source_RTC_Tamper_Timestamp_LSECSS      18U
#define Event_Input_Source_RTC_Wakeup_Timer                 19U
#define Event_Input_Source_COMP1                            20U
#define Event_Input_Source_COMP2                            21U
#define Event_Input_Source_I2C1_Wakeup                      22U
#define Event_Input_Source_I2C2_Wakeup                      23U
#define Event_Input_Source_I2C3_Wakeup                      24U
#define Event_Input_Source_I2C4_Wakeup                      25U
#define Event_Input_Source_USART1_Wakeup                    26U
#define Event_Input_Source_USART2_Wakeup                    27U
#define Event_Input_Source_USART3_Wakeup                    28U
#define Event_Input_Source_USART6_Wakeup                    29U
#define Event_Input_Source_UART4_Wakeup                     30U
#define Event_Input_Source_UART5_Wakeup                     31U
#define Event_Input_Source_UART7_Wakeup                     32U
#define Event_Input_Source_UART8_Wakeup                     33U
#define Event_Input_Source_LPUART1_RX_Wakeup                34U
#define Event_Input_Source_LPUART1_TX_Wakeup                35U
#define Event_Input_Source_SPI1_Wakeup                      36U
#define Event_Input_Source_SPI2_Wakeup                      37U
#define Event_Input_Source_SPI3_Wakeup                      38U
#define Event_Input_Source_SPI4_Wakeup                      39U
#define Event_Input_Source_SPI5_Wakeup                      40U
#define Event_Input_Source_SPI6_Wakeup                      41U
#define Event_Input_Source_MDIO_Wakeup                      42U
#define Event_Input_Source_USB1_Wakeup                      43U
#define Event_Input_Source_USB2_Wakeup                      44U
#define Event_Input_Source_DSI_Wakeup                       46U
#define Event_Input_Source_LPTIM1_Wakeup                    47U
#define Event_Input_Source_LPTIM2_Wakeup                    48U
#define Event_Input_Source_LPTIM2_Output                    49U
#define Event_Input_Source_LPTIM3_Wakeup                    50U
#define Event_Input_Source_LPTIM3_Output                    51U
#define Event_Input_Source_LPTIM4_Wakeup                    52U
#define Event_Input_Source_LPTIM5_Wakeup                    53U
#define Event_Input_Source_SWPMI_Wakeup                     54U
#define Event_Input_Source_WKUP1                            55U
#define Event_Input_Source_WKUP2                            56U
#define Event_Input_Source_WKUP3                            57U
#define Event_Input_Source_WKUP4                            58U
#define Event_Input_Source_WKUP5                            59U
#define Event_Input_Source_WKUP6                            60U
#define Event_Input_Source_RCC_Interrupt                    61U
#define Event_Input_Source_I2C4_Event_Interrupt             62U
#define Event_Input_Source_I2C4_Error_Interrupt             63U
#define Event_Input_Source_LPUART1_Global_Interrupt         64U
#define Event_Input_Source_SPI6_Interrupt                   65U
#define Event_Input_Source_BDMA_CH0_Interrupt               66U
#define Event_Input_Source_BDMA_CH1_Interrupt               67U
#define Event_Input_Source_BDMA_CH2_Interrupt               68U
#define Event_Input_Source_BDMA_CH3_Interrupt               69U
#define Event_Input_Source_BDMA_CH4_Interrupt               70U
#define Event_Input_Source_BDMA_CH5_Interrupt               71U
#define Event_Input_Source_BDMA_CH6_Interrupt               72U
#define Event_Input_Source_BDMA_CH7_Interrupt               73U
#define Event_Input_Source_DMAMUX2_Interrupt                74U
#define Event_Input_Source_ADC3_Interrupt                   75U
#define Event_Input_Source_SAI4_Interrupt                   76U
#define Event_Input_Source_HSEM0_Interrupt                  77U
#define Event_Input_Source_HSEM1_Interrupt                  78U
#define Event_Input_Source_CortexM4_SEV_Interrupt           79U
#define Event_Input_Source_CortexM7_SEV_Interrupt           80U
#define Event_Input_Source_WWDG1_Reset                      82U
#define Event_Input_Source_WWDG2_Reset                      84U
#define Event_Input_Source_HDMI_CEC_Wakeup                  85U
#define Event_Input_Source_ETHERNET_Wakeup                  86U
#define Event_Input_Source_HSECSS_Interrupt                 87U

extern void EXTI_Enable_Event_Input_Interrupt_C1(UINT8 Event_Input);
extern void EXTI_Enable_Event_Input_Interrupt_C2(UINT8 Event_Input);
extern void EXTI_Disable_Event_Input_Interrupt_C1(UINT8 Event_Input);
extern void EXTI_Disable_Event_Input_Interrupt_C2(UINT8 Event_Input);

#endif