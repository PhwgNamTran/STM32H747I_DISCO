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

typedef enum
{
    Event_Input_EXTI_0                           = 0,
    Event_Input_EXTI_1                           = 1,
    Event_Input_EXTI_2                           = 2,
    Event_Input_EXTI_3                           = 3,
    Event_Input_EXTI_4                           = 4,
    Event_Input_EXTI_5                           = 5,
    Event_Input_EXTI_6                           = 6,
    Event_Input_EXTI_7                           = 7,
    Event_Input_EXTI_8                           = 8,
    Event_Input_EXTI_9                           = 9,
    Event_Input_EXTI_10                          = 10,
    Event_Input_EXTI_11                          = 11,
    Event_Input_EXTI_12                          = 12,
    Event_Input_EXTI_13                          = 13,
    Event_Input_EXTI_14                          = 14,
    Event_Input_EXTI_15                          = 15,
    Event_Input_PVD_AVD                          = 16,
    Event_Input_RTC_Alarms                       = 17,
    Event_Input_RTC_Tamper_Timestamp_LSECSS      = 18,
    Event_Input_RTC_Wakeup_Timer                 = 19,
    Event_Input_COMP1                            = 20,
    Event_Input_COMP2                            = 21,
    Event_Input_I2C1_Wakeup                      = 22,
    Event_Input_I2C2_Wakeup                      = 23,
    Event_Input_I2C3_Wakeup                      = 24,
    Event_Input_I2C4_Wakeup                      = 25,
    Event_Input_USART1_Wakeup                    = 26,
    Event_Input_USART2_Wakeup                    = 27,
    Event_Input_USART3_Wakeup                    = 28,
    Event_Input_USART6_Wakeup                    = 29,
    Event_Input_UART4_Wakeup                     = 30,
    Event_Input_UART5_Wakeup                     = 31,
    Event_Input_UART7_Wakeup                     = 32,
    Event_Input_UART8_Wakeup                     = 33,
    Event_Input_LPUART1_RX_Wakeup                = 34,
    Event_Input_LPUART1_TX_Wakeup                = 35,
    Event_Input_SPI1_Wakeup                      = 36,
    Event_Input_SPI2_Wakeup                      = 37,
    Event_Input_SPI3_Wakeup                      = 38,
    Event_Input_SPI4_Wakeup                      = 39,
    Event_Input_SPI5_Wakeup                      = 40,
    Event_Input_SPI6_Wakeup                      = 41,
    Event_Input_MDIO_Wakeup                      = 42,
    Event_Input_USB1_Wakeup                      = 43,
    Event_Input_USB2_Wakeup                      = 44,
    Event_Input_DSI_Wakeup                       = 46,
    Event_Input_LPTIM1_Wakeup                    = 47,
    Event_Input_LPTIM2_Wakeup                    = 48,
    Event_Input_LPTIM2_Output                    = 49,
    Event_Input_LPTIM3_Wakeup                    = 50,
    Event_Input_LPTIM3_Output                    = 51,
    Event_Input_LPTIM4_Wakeup                    = 52,
    Event_Input_LPTIM5_Wakeup                    = 53,
    Event_Input_SWPMI_Wakeup                     = 54,
    Event_Input_WKUP1                            = 55,
    Event_Input_WKUP2                            = 56,
    Event_Input_WKUP3                            = 57,
    Event_Input_WKUP4                            = 58,
    Event_Input_WKUP5                            = 59,
    Event_Input_WKUP6                            = 60,
    Event_Input_RCC_Interrupt                    = 61,
    Event_Input_I2C4_Event_Interrupt             = 62,
    Event_Input_I2C4_Error_Interrupt             = 63,
    Event_Input_LPUART1_Global_Interrupt         = 64,
    Event_Input_SPI6_Interrupt                   = 65,
    Event_Input_BDMA_CH0_Interrupt               = 66,
    Event_Input_BDMA_CH1_Interrupt               = 67,
    Event_Input_BDMA_CH2_Interrupt               = 68,
    Event_Input_BDMA_CH3_Interrupt               = 69,
    Event_Input_BDMA_CH4_Interrupt               = 70,
    Event_Input_BDMA_CH5_Interrupt               = 71,
    Event_Input_BDMA_CH6_Interrupt               = 72,
    Event_Input_BDMA_CH7_Interrupt               = 73,
    Event_Input_DMAMUX2_Interrupt                = 74,
    Event_Input_ADC3_Interrupt                   = 75,
    Event_Input_SAI4_Interrupt                   = 76,
    Event_Input_HSEM0_Interrupt                  = 77,
    Event_Input_HSEM1_Interrupt                  = 78,
    Event_Input_CortexM4_SEV_Interrupt           = 79,
    Event_Input_CortexM7_SEV_Interrupt           = 80,
    Event_Input_WWDG1_Reset                      = 82,
    Event_Input_WWDG2_Reset                      = 84,
    Event_Input_HDMI_CEC_Wakeup                  = 85,
    Event_Input_ETHERNET_Wakeup                  = 86,
    Event_Input_HSECSS_Interrupt                 = 87
}Event_Input_N;

#define EXTI_BASE       0x58000000UL    /* EXTI Base Address */
#define EXTI_C1_BASE    0x58000080UL    /* EXTI Core 1 Base Address */
#define EXTI_C2_BASE    0x580000C0UL    /* EXTI Core 2 Base Address */

/* EXTI & EXTI Core Declaration */
#define EXTI         ((EXTI_ST *) EXTI_BASE)
#define EXTI_C1      ((EXTI_Core_ST *) EXTI_C1_BASE)
#define EXTI_C2      ((EXTI_Core_ST *) EXTI_C2_BASE)

extern void EXTI_Enable_Event_Input_Interrupt_C1(Event_Input_N Event_Input);
extern void EXTI_Enable_Event_Input_Interrupt_C2(Event_Input_N Event_Input);
extern void EXTI_Disable_Event_Input_Interrupt_C1(Event_Input_N Event_Input);
extern void EXTI_Disable_Event_Input_Interrupt_C2(Event_Input_N Event_Input);
extern void EXTI_Enable_Rising_Trigger(Event_Input_N Event_Input);
extern void EXTI_Disable_Rising_Trigger(Event_Input_N Event_Input);
extern void EXTI_Enable_Falling_Trigger(Event_Input_N Event_Input);
extern void EXTI_Disable_Falling_Trigger(Event_Input_N Event_Input);

#endif