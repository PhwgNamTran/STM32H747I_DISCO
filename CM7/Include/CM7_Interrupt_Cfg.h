#ifndef INTERRUPT_CFG_H
#define INTERRUPT_CFG_H

/*
 * Interrupt Configuration:
 * -------------------------
 * This header file contains configuration macros to enable or disable specific interrupts
 * based on the project requirements.
 */

#define EXTI_0_ENABLED                      STD_OFF
#define EXTI_1_ENABLED                      STD_OFF
#define EXTI_2_ENABLED                      STD_OFF
#define EXTI_3_ENABLED                      STD_OFF
#define EXTI_4_ENABLED                      STD_OFF
#define EXTI_5_ENABLED                      STD_OFF
#define EXTI_6_ENABLED                      STD_OFF
#define EXTI_7_ENABLED                      STD_OFF
#define EXTI_8_ENABLED                      STD_OFF
#define EXTI_9_ENABLED                      STD_OFF
#define EXTI_10_ENABLED                     STD_OFF
#define EXTI_11_ENABLED                     STD_OFF
#define EXTI_12_ENABLED                     STD_OFF

#if (WK_BUTTON_USED && WK_BUTTON_Interrupt_USED)
#define EXTI_13_ENABLED                     STD_ON
#else
#define EXTI_13_ENABLED                     STD_OFF
#endif

#define EXTI_14_ENABLED                     STD_OFF
#define EXTI_15_ENABLED                     STD_OFF

#define PVD_AVD_ENABLED                     STD_OFF
#define RTC_Alarms_ENABLED                  STD_OFF
#define RTC_Tamper_Timestamp_LSECSS_ENABLED STD_OFF
#define RTC_Wakeup_Timer_ENABLED            STD_OFF
#define COMP1_ENABLED                       STD_OFF
#define COMP2_ENABLED                       STD_OFF
#define I2C1_Wakeup_ENABLED                 STD_OFF
#define I2C2_Wakeup_ENABLED                 STD_OFF
#define I2C3_Wakeup_ENABLED                 STD_OFF
#define I2C4_Wakeup_ENABLED                 STD_OFF
#define USART1_Wakeup_ENABLED               STD_OFF
#define USART2_Wakeup_ENABLED               STD_OFF
#define USART3_Wakeup_ENABLED               STD_OFF
#define USART6_Wakeup_ENABLED               STD_OFF
#define UART4_Wakeup_ENABLED                STD_OFF
#define UART5_Wakeup_ENABLED                STD_OFF
#define UART7_Wakeup_ENABLED                STD_OFF
#define UART8_Wakeup_ENABLED                STD_OFF
#define LPUART1_RX_Wakeup_ENABLED           STD_OFF
#define LPUART1_TX_Wakeup_ENABLED           STD_OFF
#define SPI1_Wakeup_ENABLED                 STD_OFF
#define SPI2_Wakeup_ENABLED                 STD_OFF
#define SPI3_Wakeup_ENABLED                 STD_OFF
#define SPI4_Wakeup_ENABLED                 STD_OFF
#define SPI5_Wakeup_ENABLED                 STD_OFF
#define SPI6_Wakeup_ENABLED                 STD_OFF
#define MDIO_Wakeup_ENABLED                 STD_OFF
#define USB1_Wakeup_ENABLED                 STD_OFF
#define USB2_Wakeup_ENABLED                 STD_OFF
#define DSI_Wakeup_ENABLED                  STD_OFF
#define LPTIM1_Wakeup_ENABLED               STD_OFF
#define LPTIM2_Wakeup_ENABLED               STD_OFF
#define LPTIM2_Output_ENABLED               STD_OFF
#define LPTIM3_Wakeup_ENABLED               STD_OFF
#define LPTIM3_Output_ENABLED               STD_OFF
#define LPTIM4_Wakeup_ENABLED               STD_OFF
#define LPTIM5_Wakeup_ENABLED               STD_OFF
#define SWPMI_Wakeup_ENABLED                STD_OFF
#define WKUP1_ENABLED                       STD_OFF
#define WKUP2_ENABLED                       STD_OFF
#define WKUP3_ENABLED                       STD_OFF
#define WKUP4_ENABLED                       STD_OFF
#define WKUP5_ENABLED                       STD_OFF
#define WKUP6_ENABLED                       STD_OFF
#define RCC_Interrupt_ENABLED               STD_OFF
#define I2C4_Event_Interrupt_ENABLED        STD_OFF
#define I2C4_Error_Interrupt_ENABLED        STD_OFF
#define LPUART1_Global_Interrupt_ENABLED    STD_OFF
#define SPI6_Interrupt_ENABLED              STD_OFF
#define BDMA_CH0_Interrupt_ENABLED          STD_OFF
#define BDMA_CH1_Interrupt_ENABLED          STD_OFF
#define BDMA_CH2_Interrupt_ENABLED          STD_OFF
#define BDMA_CH3_Interrupt_ENABLED          STD_OFF
#define BDMA_CH4_Interrupt_ENABLED          STD_OFF
#define BDMA_CH5_Interrupt_ENABLED          STD_OFF
#define BDMA_CH6_Interrupt_ENABLED          STD_OFF
#define BDMA_CH7_Interrupt_ENABLED          STD_OFF
#define DMAMUX2_Interrupt_ENABLED           STD_OFF
#define ADC3_Interrupt_ENABLED              STD_OFF
#define SAI4_Interrupt_ENABLED              STD_OFF
#define HSEM0_Interrupt_ENABLED             STD_OFF
#define HSEM1_Interrupt_ENABLED             STD_OFF
#define CortexM4_SEV_Interrupt_ENABLED      STD_OFF
#define CortexM7_SEV_Interrupt_ENABLED      STD_OFF
#define WWDG1_Reset_ENABLED                 STD_OFF
#define WWDG2_Reset_ENABLED                 STD_OFF
#define HDMI_CEC_Wakeup_ENABLED             STD_OFF
#define ETHERNET_Wakeup_ENABLED             STD_OFF
#define HSECSS_Interrupt_ENABLED            STD_OFF

#endif /* INTERRUPT_CFG_H */
