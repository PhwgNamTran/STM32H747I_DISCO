#ifndef STM32H7_EXTI_H
#define STM32H7_EXTI_H

#include "STM32H747xx.h"

/**
  * @brief   Enum for EXTI Event Input
  */
typedef enum
{
    /*!< Standard External Interrupts */
    EXTI_EventInput_EXTI_0_N                           = 0,    /*!< External Interrupt Line 0 */
    EXTI_EventInput_EXTI_1_N                           = 1,    /*!< External Interrupt Line 1 */
    EXTI_EventInput_EXTI_2_N                           = 2,    /*!< External Interrupt Line 2 */
    EXTI_EventInput_EXTI_3_N                           = 3,    /*!< External Interrupt Line 3 */
    EXTI_EventInput_EXTI_4_N                           = 4,    /*!< External Interrupt Line 4 */
    EXTI_EventInput_EXTI_5_N                           = 5,    /*!< External Interrupt Line 5 */
    EXTI_EventInput_EXTI_6_N                           = 6,    /*!< External Interrupt Line 6 */
    EXTI_EventInput_EXTI_7_N                           = 7,    /*!< External Interrupt Line 7 */
    EXTI_EventInput_EXTI_8_N                           = 8,    /*!< External Interrupt Line 8 */
    EXTI_EventInput_EXTI_9_N                           = 9,    /*!< External Interrupt Line 9 */
    EXTI_EventInput_EXTI_10_N                          = 10,   /*!< External Interrupt Line 10 */
    EXTI_EventInput_EXTI_11_N                          = 11,   /*!< External Interrupt Line 11 */
    EXTI_EventInput_EXTI_12_N                          = 12,   /*!< External Interrupt Line 12 */
    EXTI_EventInput_EXTI_13_N                          = 13,   /*!< External Interrupt Line 13 */
    EXTI_EventInput_EXTI_14_N                          = 14,   /*!< External Interrupt Line 14 */
    EXTI_EventInput_EXTI_15_N                          = 15,   /*!< External Interrupt Line 15 */

    /*!< Peripheral Events */
    EXTI_EventInput_PVD_AVD_N                          = 16,   /*!< Voltage Detector (PVD) and Analog Voltage Detector (AVD) Interrupt */
    EXTI_EventInput_RTC_Alarms_N                       = 17,   /*!< RTC Alarms Interrupt */
    EXTI_EventInput_RTC_Tamper_Timestamp_LSECSS_N      = 18,   /*!< RTC Tamper and Timestamp Interrupt */
    EXTI_EventInput_RTC_Wakeup_Timer_N                 = 19,   /*!< RTC Wakeup Timer Interrupt */
    EXTI_EventInput_COMP1_N                            = 20,   /*!< Comparator 1 Interrupt */
    EXTI_EventInput_COMP2_N                            = 21,   /*!< Comparator 2 Interrupt */

    /*!< I2C Wakeup Events */
    EXTI_EventInput_I2C1_Wakeup_N                      = 22,   /*!< I2C1 Wakeup Interrupt */
    EXTI_EventInput_I2C2_Wakeup_N                      = 23,   /*!< I2C2 Wakeup Interrupt */
    EXTI_EventInput_I2C3_Wakeup_N                      = 24,   /*!< I2C3 Wakeup Interrupt */
    EXTI_EventInput_I2C4_Wakeup_N                      = 25,   /*!< I2C4 Wakeup Interrupt */

    /*!< USART Wakeup Events */
    EXTI_EventInput_USART1_Wakeup_N                    = 26,   /*!< USART1 Wakeup Interrupt */
    EXTI_EventInput_USART2_Wakeup_N                    = 27,   /*!< USART2 Wakeup Interrupt */
    EXTI_EventInput_USART3_Wakeup_N                    = 28,   /*!< USART3 Wakeup Interrupt */
    EXTI_EventInput_USART6_Wakeup_N                    = 29,   /*!< USART6 Wakeup Interrupt */
    EXTI_EventInput_UART4_Wakeup_N                     = 30,   /*!< UART4 Wakeup Interrupt */
    EXTI_EventInput_UART5_Wakeup_N                     = 31,   /*!< UART5 Wakeup Interrupt */
    EXTI_EventInput_UART7_Wakeup_N                     = 32,   /*!< UART7 Wakeup Interrupt */
    EXTI_EventInput_UART8_Wakeup_N                     = 33,   /*!< UART8 Wakeup Interrupt */

    /*!< Low-Power UART Events */
    EXTI_EventInput_LPUART1_RX_Wakeup_N                = 34,   /*!< LPUART1 RX Wakeup Interrupt */
    EXTI_EventInput_LPUART1_TX_Wakeup_N                = 35,   /*!< LPUART1 TX Wakeup Interrupt */

    /*!< SPI Wakeup Events */
    EXTI_EventInput_SPI1_Wakeup_N                      = 36,   /*!< SPI1 Wakeup Interrupt */
    EXTI_EventInput_SPI2_Wakeup_N                      = 37,   /*!< SPI2 Wakeup Interrupt */
    EXTI_EventInput_SPI3_Wakeup_N                      = 38,   /*!< SPI3 Wakeup Interrupt */
    EXTI_EventInput_SPI4_Wakeup_N                      = 39,   /*!< SPI4 Wakeup Interrupt */
    EXTI_EventInput_SPI5_Wakeup_N                      = 40,   /*!< SPI5 Wakeup Interrupt */
    EXTI_EventInput_SPI6_Wakeup_N                      = 41,   /*!< SPI6 Wakeup Interrupt */

    /*!< MDIO and USB Wakeup Events */
    EXTI_EventInput_MDIO_Wakeup_N                      = 42,   /*!< MDIO Wakeup Interrupt */
    EXTI_EventInput_USB1_Wakeup_N                      = 43,   /*!< USB1 Wakeup Interrupt */
    EXTI_EventInput_USB2_Wakeup_N                      = 44,   /*!< USB2 Wakeup Interrupt */

    /*!< Miscellaneous Wakeup and Interrupt Events */
    EXTI_EventInput_DSI_Wakeup_N                       = 46,   /*!< DSI Wakeup Interrupt */
    EXTI_EventInput_LPTIM1_Wakeup_N                    = 47,   /*!< LPTIM1 Wakeup Interrupt */
    EXTI_EventInput_LPTIM2_Wakeup_N                    = 48,   /*!< LPTIM2 Wakeup Interrupt */
    EXTI_EventInput_LPTIM2_Output_N                    = 49,   /*!< LPTIM2 Output Interrupt */
    EXTI_EventInput_LPTIM3_Wakeup_N                    = 50,   /*!< LPTIM3 Wakeup Interrupt */
    EXTI_EventInput_LPTIM3_Output_N                    = 51,   /*!< LPTIM3 Output Interrupt */
    EXTI_EventInput_LPTIM4_Wakeup_N                    = 52,   /*!< LPTIM4 Wakeup Interrupt */
    EXTI_EventInput_LPTIM5_Wakeup_N                    = 53,   /*!< LPTIM5 Wakeup Interrupt */
    EXTI_EventInput_SWPMI_Wakeup_N                     = 54,   /*!< SWPMI Wakeup Interrupt */

    /*!< Wakeup Interrupts */
    EXTI_EventInput_WKUP1_N                            = 55,   /*!< WKUP1 Interrupt */
    EXTI_EventInput_WKUP2_N                            = 56,   /*!< WKUP2 Interrupt */
    EXTI_EventInput_WKUP3_N                            = 57,   /*!< WKUP3 Interrupt */
    EXTI_EventInput_WKUP4_N                            = 58,   /*!< WKUP4 Interrupt */
    EXTI_EventInput_WKUP5_N                            = 59,   /*!< WKUP5 Interrupt */
    EXTI_EventInput_WKUP6_N                            = 60,   /*!< WKUP6 Interrupt */

    /*!< RCC and I2C4 Interrupts */
    EXTI_EventInput_RCC_Interrupt_N                    = 61,   /*!< RCC Interrupt */
    EXTI_EventInput_I2C4_Event_Interrupt_N             = 62,   /*!< I2C4 Event Interrupt */
    EXTI_EventInput_I2C4_Error_Interrupt_N             = 63,   /*!< I2C4 Error Interrupt */

    /*!< Other Interrupts */
    EXTI_EventInput_LPUART1_Global_Interrupt_N         = 64,   /*!< LPUART1 Global Interrupt */
    EXTI_EventInput_SPI6_Interrupt_N                   = 65,   /*!< SPI6 Interrupt */
    EXTI_EventInput_BDMA_CH0_Interrupt_N               = 66,   /*!< BDMA Channel 0 Interrupt */
    EXTI_EventInput_BDMA_CH1_Interrupt_N               = 67,   /*!< BDMA Channel 1 Interrupt */
    EXTI_EventInput_BDMA_CH2_Interrupt_N               = 68,   /*!< BDMA Channel 2 Interrupt */
    EXTI_EventInput_BDMA_CH3_Interrupt_N               = 69,   /*!< BDMA Channel 3 Interrupt */
    EXTI_EventInput_BDMA_CH4_Interrupt_N               = 70,   /*!< BDMA Channel 4 Interrupt */
    EXTI_EventInput_BDMA_CH5_Interrupt_N               = 71,   /*!< BDMA Channel 5 Interrupt */
    EXTI_EventInput_BDMA_CH6_Interrupt_N               = 72,   /*!< BDMA Channel 6 Interrupt */
    EXTI_EventInput_BDMA_CH7_Interrupt_N               = 73,   /*!< BDMA Channel 7 Interrupt */
    EXTI_EventInput_DMAMUX2_Interrupt_N                = 74,   /*!< DMAMUX2 Interrupt */
    EXTI_EventInput_ADC3_Interrupt_N                   = 75,   /*!< ADC3 Interrupt */
    EXTI_EventInput_SAI4_Interrupt_N                   = 76,   /*!< SAI4 Interrupt */
    EXTI_EventInput_HSEM0_Interrupt_N                  = 77,   /*!< HSEM0 Interrupt */
    EXTI_EventInput_HSEM1_Interrupt_N                  = 78,   /*!< HSEM1 Interrupt */

    /*!< Cortex-M Specific Interrupts */
    EXTI_EventInput_CortexM4_SEV_Interrupt_N           = 79,   /*!< Cortex-M4 SEV Interrupt */
    EXTI_EventInput_CortexM7_SEV_Interrupt_N           = 80,   /*!< Cortex-M7 SEV Interrupt */

    /*!< Window Watchdog Interrupts */
    EXTI_EventInput_WWDG1_Reset_N                      = 82,   /*!< WWDG1 Reset Interrupt */
    EXTI_EventInput_WWDG2_Reset_N                      = 84,   /*!< WWDG2 Reset Interrupt */

    /*!< Other Wakeup Events */
    EXTI_EventInput_HDMI_CEC_Wakeup_N                  = 85,   /*!< HDMI CEC Wakeup Interrupt */
    EXTI_EventInput_ETHERNET_Wakeup_N                  = 86,   /*!< Ethernet Wakeup Interrupt */
    EXTI_EventInput_HSECSS_Interrupt_N                 = 87    /*!< HSECSS Interrupt */
} EXTI_EventInput_N;


extern ReturnType EXTI_EventInput_Interrupt_Enable_CPU1(EXTI_EventInput_N EventInput);
extern ReturnType EXTI_EventInput_Interrupt_Enable_CPU2(EXTI_EventInput_N EventInput);

extern ReturnType EXTI_EventInput_Interrupt_Disable_CPU1(EXTI_EventInput_N EventInput);
extern ReturnType EXTI_EventInput_Interrupt_Disable_CPU2(EXTI_EventInput_N EventInput);

extern ReturnType EXTI_Clear_Trigger_Request_Flag_CPU1(EXTI_EventInput_N EventInput);
extern ReturnType EXTI_Clear_Trigger_Request_Flag_CPU2(EXTI_EventInput_N EventInput);

extern boolean    EXTI_Trigger_Request_Occurred_CPU1_B(EXTI_EventInput_N EventInput);
extern boolean    EXTI_Trigger_Request_Occurred_CPU2_B(EXTI_EventInput_N EventInput);

extern ReturnType EXTI_Rising_Trigger_Enable(EXTI_EventInput_N EventInput);
extern ReturnType EXTI_Rising_Trigger_Disable(EXTI_EventInput_N EventInput);

extern ReturnType EXTI_Falling_Trigger_Enable(EXTI_EventInput_N EventInput);
extern ReturnType EXTI_Falling_Trigger_Disable(EXTI_EventInput_N EventInput);

#endif