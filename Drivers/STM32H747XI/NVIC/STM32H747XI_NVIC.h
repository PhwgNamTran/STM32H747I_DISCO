#ifndef STM32H747XI_NVIC_H
#define STM32H747XI_NVIC_H

#include "Common.h"

/* Refer to RM0399 Reference Manual from http://www.st.com and CMSIS Library */

/*
 * Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
typedef struct
{
    volatile UINT32 ISER[8U];               /**< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
    volatile UINT32 RESERVED0[24U];
    volatile UINT32 ICER[8U];               /**< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
    volatile UINT32 RESERVED1[24U];
    volatile UINT32 ISPR[8U];               /**< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
    volatile UINT32 RESERVED2[24U];
    volatile UINT32 ICPR[8U];               /**< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
    volatile UINT32 RESERVED3[24U];
    volatile UINT32 IABR[8U];               /**< Offset: 0x200 (R/W)  Interrupt Active bit Register */
    volatile UINT32 RESERVED4[56U];
    volatile UINT8  IP[240U];               /**< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
    volatile UINT32 RESERVED5[644U];
    volatile UINT32 STIR;                   /**< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_ST;

/*
 * STM32H7XX Interrupt Number Definition
 */
typedef enum
{
/******  Cortex-M Processor Exceptions Numbers *****************************************************************/
    IRQn_NonMaskableInt         = -14,    /**< 2 Non Maskable Interrupt                                          */
    IRQn_HardFault              = -13,    /**< 3 Cortex-M Hard Fault Interrupt                                   */
    IRQn_MemoryManagement       = -12,    /**< 4 Cortex-M Memory Management Interrupt                            */
    IRQn_BusFault               = -11,    /**< 5 Cortex-M Bus Fault Interrupt                                    */
    IRQn_UsageFault             = -10,    /**< 6 Cortex-M Usage Fault Interrupt                                  */
    IRQn_SVCall                 = -5,     /**< 11 Cortex-M SV Call Interrupt                                     */
    IRQn_DebugMonitor           = -4,     /**< 12 Cortex-M Debug Monitor Interrupt                               */
    IRQn_PendSV                 = -2,     /**< 14 Cortex-M Pend SV Interrupt                                     */
    IRQn_SysTick                = -1,     /**< 15 Cortex-M System Tick Interrupt                                 */
/******  STM32 specific Interrupt Numbers **********************************************************************/
    IRQn_WWDG                   = 0,      /**< Window WatchDog Interrupt ( wwdg1_it, wwdg2_it)                   */
    IRQn_PVD_AVD                = 1,      /**< PVD/AVD through EXTI Line detection Interrupt                     */
    IRQn_TAMP_STAMP             = 2,      /**< Tamper and TimeStamp interrupts through the EXTI line             */
    IRQn_RTC_WKUP               = 3,      /**< RTC Wakeup interrupt through the EXTI line                        */
    IRQn_FLASH                  = 4,      /**< FLASH global Interrupt                                            */
    IRQn_RCC                    = 5,      /**< RCC global Interrupt                                              */
    IRQn_EXTI0                  = 6,      /**< EXTI Line0 Interrupt                                              */
    IRQn_EXTI1                  = 7,      /**< EXTI Line1 Interrupt                                              */
    IRQn_EXTI2                  = 8,      /**< EXTI Line2 Interrupt                                              */
    IRQn_EXTI3                  = 9,      /**< EXTI Line3 Interrupt                                              */
    IRQn_EXTI4                  = 10,     /**< EXTI Line4 Interrupt                                              */
    IRQn_DMA1_Stream0           = 11,     /**< DMA1 Stream 0 global Interrupt                                    */
    IRQn_DMA1_Stream1           = 12,     /**< DMA1 Stream 1 global Interrupt                                    */
    IRQn_DMA1_Stream2           = 13,     /**< DMA1 Stream 2 global Interrupt                                    */
    IRQn_DMA1_Stream3           = 14,     /**< DMA1 Stream 3 global Interrupt                                    */
    IRQn_DMA1_Stream4           = 15,     /**< DMA1 Stream 4 global Interrupt                                    */
    IRQn_DMA1_Stream5           = 16,     /**< DMA1 Stream 5 global Interrupt                                    */
    IRQn_DMA1_Stream6           = 17,     /**< DMA1 Stream 6 global Interrupt                                    */
    IRQn_ADC                    = 18,     /**< ADC1 and  ADC2 global Interrupts                                  */
    IRQn_FDCAN1_IT0             = 19,     /**< FDCAN1 Interrupt line 0                                           */
    IRQn_FDCAN2_IT0             = 20,     /**< FDCAN2 Interrupt line 0                                           */
    IRQn_FDCAN1_IT1             = 21,     /**< FDCAN1 Interrupt line 1                                           */
    IRQn_FDCAN2_IT1             = 22,     /**< FDCAN2 Interrupt line 1                                           */
    IRQn_EXTI9_5                = 23,     /**< External Line[9:5] Interrupts                                     */
    IRQn_TIM1_BRK               = 24,     /**< TIM1 Break Interrupt                                              */
    IRQn_TIM1_UP                = 25,     /**< TIM1 Update Interrupt                                             */
    IRQn_TIM1_TRG_COM           = 26,     /**< TIM1 Trigger and Commutation Interrupt                            */
    IRQn_TIM1_CC                = 27,     /**< TIM1 Capture Compare Interrupt                                    */
    IRQn_TIM2                   = 28,     /**< TIM2 global Interrupt                                             */
    IRQn_TIM3                   = 29,     /**< TIM3 global Interrupt                                             */
    IRQn_TIM4                   = 30,     /**< TIM4 global Interrupt                                             */
    IRQn_I2C1_EV                = 31,     /**< I2C1 Event Interrupt                                              */
    IRQn_I2C1_ER                = 32,     /**< I2C1 Error Interrupt                                              */
    IRQn_I2C2_EV                = 33,     /**< I2C2 Event Interrupt                                              */
    IRQn_I2C2_ER                = 34,     /**< I2C2 Error Interrupt                                              */
    IRQn_SPI1                   = 35,     /**< SPI1 global Interrupt                                             */
    IRQn_SPI2                   = 36,     /**< SPI2 global Interrupt                                             */
    IRQn_USART1                 = 37,     /**< USART1 global Interrupt                                           */
    IRQn_USART2                 = 38,     /**< USART2 global Interrupt                                           */
    IRQn_USART3                 = 39,     /**< USART3 global Interrupt                                           */
    IRQn_EXTI15_10              = 40,     /**< External Line[15:10] Interrupts                                   */
    IRQn_RTC_Alarm              = 41,     /**< RTC Alarm (A and B) through EXTI Line Interrupt                   */
    IRQn_TIM8_BRK_TIM12         = 43,     /**< TIM8 Break Interrupt and TIM12 global interrupt                   */
    IRQn_TIM8_UP_TIM13          = 44,     /**< TIM8 Update Interrupt and TIM13 global interrupt                  */
    IRQn_TIM8_TRG_COM_TIM14     = 45,     /**< TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
    IRQn_TIM8_CC                = 46,     /**< TIM8 Capture Compare Interrupt                                    */
    IRQn_DMA1_Stream7           = 47,     /**< DMA1 Stream7 Interrupt                                            */
    IRQn_FMC                    = 48,     /**< FMC global Interrupt                                              */
    IRQn_SDMMC1                 = 49,     /**< SDMMC1 global Interrupt                                           */
    IRQn_TIM5                   = 50,     /**< TIM5 global Interrupt                                             */
    IRQn_SPI3                   = 51,     /**< SPI3 global Interrupt                                             */
    IRQn_UART4                  = 52,     /**< UART4 global Interrupt                                            */
    IRQn_UART5                  = 53,     /**< UART5 global Interrupt                                            */
    IRQn_TIM6_DAC               = 54,     /**< TIM6 global and DAC1&2 underrun error  interrupts                 */
    IRQn_TIM7                   = 55,     /**< TIM7 global interrupt                                             */
    IRQn_DMA2_Stream0           = 56,     /**<   DMA2 Stream 0 global Interrupt                                  */
    IRQn_DMA2_Stream1           = 57,     /**<   DMA2 Stream 1 global Interrupt                                  */
    IRQn_DMA2_Stream2           = 58,     /**<   DMA2 Stream 2 global Interrupt                                  */
    IRQn_DMA2_Stream3           = 59,     /**<   DMA2 Stream 3 global Interrupt                                  */
    IRQn_DMA2_Stream4           = 60,     /**<   DMA2 Stream 4 global Interrupt                                  */
    IRQn_ETH                    = 61,     /**< Ethernet global Interrupt                                         */
    IRQn_ETH_WKUP               = 62,     /**< Ethernet Wakeup through EXTI line Interrupt                       */
    IRQn_FDCAN_CAL              = 63,     /**< FDCAN Calibration unit Interrupt                                  */
    IRQn_CM7_SEV                = 64,     /**< CM7 Send event interrupt for CM4                                  */
    IRQn_CM4_SEV                = 65,     /**< CM4 Send event interrupt for CM7                                  */
    IRQn_DMA2_Stream5           = 68,     /**< DMA2 Stream 5 global interrupt                                    */
    IRQn_DMA2_Stream6           = 69,     /**< DMA2 Stream 6 global interrupt                                    */
    IRQn_DMA2_Stream7           = 70,     /**< DMA2 Stream 7 global interrupt                                    */
    IRQn_USART6                 = 71,     /**< USART6 global interrupt                                           */
    IRQn_I2C3_EV                = 72,     /**< I2C3 event interrupt                                              */
    IRQn_I2C3_ER                = 73,     /**< I2C3 error interrupt                                              */
    IRQn_OTG_HS_EP1_OUT         = 74,     /**< USB OTG HS End Point 1 Out global interrupt                       */
    IRQn_OTG_HS_EP1_IN          = 75,     /**< USB OTG HS End Point 1 In global interrupt                        */
    IRQn_OTG_HS_WKUP            = 76,     /**< USB OTG HS Wakeup through EXTI interrupt                          */
    IRQn_OTG_HS                 = 77,     /**< USB OTG HS global interrupt                                       */
    IRQn_DCMI                   = 78,     /**< DCMI global interrupt                                             */
    IRQn_RNG                    = 80,     /**< RNG global interrupt                                              */
    IRQn_FPU                    = 81,     /**< FPU global interrupt                                              */
    IRQn_UART7                  = 82,     /**< UART7 global interrupt                                            */
    IRQn_UART8                  = 83,     /**< UART8 global interrupt                                            */
    IRQn_SPI4                   = 84,     /**< SPI4 global Interrupt                                             */
    IRQn_SPI5                   = 85,     /**< SPI5 global Interrupt                                             */
    IRQn_SPI6                   = 86,     /**< SPI6 global Interrupt                                             */
    IRQn_SAI1                   = 87,     /**< SAI1 global Interrupt                                             */
    IRQn_LTDC                   = 88,     /**< LTDC global Interrupt                                             */
    IRQn_LTDC_ER                = 89,     /**< LTDC Error global Interrupt                                       */
    IRQn_DMA2D                  = 90,     /**< DMA2D global Interrupt                                            */
    IRQn_SAI2                   = 91,     /**< SAI2 global Interrupt                                             */
    IRQn_QUADSPI                = 92,     /**< Quad SPI global interrupt                                         */
    IRQn_LPTIM1                 = 93,     /**< LP TIM1 interrupt                                                 */
    IRQn_CEC                    = 94,     /**< HDMI-CEC global Interrupt                                         */
    IRQn_I2C4_EV                = 95,     /**< I2C4 Event Interrupt                                              */
    IRQn_I2C4_ER                = 96,     /**< I2C4 Error Interrupt                                              */
    IRQn_SPDIF_RX               = 97,     /**< SPDIF-RX global Interrupt                                         */
    IRQn_OTG_FS_EP1_OUT         = 98,     /**< USB OTG HS2 global interrupt                                      */
    IRQn_OTG_FS_EP1_IN          = 99,     /**< USB OTG HS2 End Point 1 Out global interrupt                      */
    IRQn_OTG_FS_WKUP            = 100,    /**< USB OTG HS2 End Point 1 In global interrupt                       */
    IRQn_OTG_FS                 = 101,    /**< USB OTG HS2 Wakeup through EXTI interrupt                         */
    IRQn_DMAMUX1_OVR            = 102,    /**<DMAMUX1 Overrun interrupt                                          */
    IRQn_HRTIM1_Master          = 103,    /**< HRTIM Master Timer global Interrupts                              */
    IRQn_HRTIM1_TIMA            = 104,    /**< HRTIM Timer A global Interrupt                                    */
    IRQn_HRTIM1_TIMB            = 105,    /**< HRTIM Timer B global Interrupt                                    */
    IRQn_HRTIM1_TIMC            = 106,    /**< HRTIM Timer C global Interrupt                                    */
    IRQn_HRTIM1_TIMD            = 107,    /**< HRTIM Timer D global Interrupt                                    */
    IRQn_HRTIM1_TIME            = 108,    /**< HRTIM Timer E global Interrupt                                    */
    IRQn_HRTIM1_FLT             = 109,    /**< HRTIM Fault global Interrupt                                      */
    IRQn_DFSDM1_FLT0            = 110,    /**<DFSDM Filter1 Interrupt                                            */
    IRQn_DFSDM1_FLT1            = 111,    /**<DFSDM Filter2 Interrupt                                            */
    IRQn_DFSDM1_FLT2            = 112,    /**<DFSDM Filter3 Interrupt                                            */
    IRQn_DFSDM1_FLT3            = 113,    /**<DFSDM Filter4 Interrupt                                            */
    IRQn_SAI3                   = 114,    /**< SAI3 global Interrupt                                             */
    IRQn_SWPMI1                 = 115,    /**< Serial Wire Interface 1 global interrupt                          */
    IRQn_TIM15                  = 116,    /**< TIM15 global Interrupt                                            */
    IRQn_TIM16                  = 117,    /**< TIM16 global Interrupt                                            */
    IRQn_TIM17                  = 118,    /**< TIM17 global Interrupt                                            */
    IRQn_MDIOS_WKUP             = 119,    /**< MDIOS Wakeup  Interrupt                                           */
    IRQn_MDIOS                  = 120,    /**< MDIOS global Interrupt                                            */
    IRQn_JPEG                   = 121,    /**< JPEG global Interrupt                                             */
    IRQn_MDMA                   = 122,    /**< MDMA global Interrupt                                             */
    IRQn_DSI                    = 123,    /**< DSI global Interrupt                                              */
    IRQn_SDMMC2                 = 124,    /**< SDMMC2 global Interrupt                                           */
    IRQn_HSEM1                  = 125,    /**< HSEM1 global Interrupt                                            */
    IRQn_HSEM2                  = 126,    /**< HSEM2 global Interrupt                                            */
    IRQn_ADC3                   = 127,    /**< ADC3 global Interrupt                                             */
    IRQn_DMAMUX2_OVR            = 128,    /**<DMAMUX2 Overrun interrupt                                          */
    IRQn_BDMA_Channel0          = 129,    /**< BDMA Channel 0 global Interrupt                                   */
    IRQn_BDMA_Channel1          = 130,    /**< BDMA Channel 1 global Interrupt                                   */
    IRQn_BDMA_Channel2          = 131,    /**< BDMA Channel 2 global Interrupt                                   */
    IRQn_BDMA_Channel3          = 132,    /**< BDMA Channel 3 global Interrupt                                   */
    IRQn_BDMA_Channel4          = 133,    /**< BDMA Channel 4 global Interrupt                                   */
    IRQn_BDMA_Channel5          = 134,    /**< BDMA Channel 5 global Interrupt                                   */
    IRQn_BDMA_Channel6          = 135,    /**< BDMA Channel 6 global Interrupt                                   */
    IRQn_BDMA_Channel7          = 136,    /**< BDMA Channel 7 global Interrupt                                   */
    IRQn_COMP                   = 137 ,   /**< COMP global Interrupt                                             */
    IRQn_LPTIM2                 = 138,    /**< LP TIM2 global interrupt                                          */
    IRQn_LPTIM3                 = 139,    /**< LP TIM3 global interrupt                                          */
    IRQn_LPTIM4                 = 140,    /**< LP TIM4 global interrupt                                          */
    IRQn_LPTIM5                 = 141,    /**< LP TIM5 global interrupt                                          */
    IRQn_LPUART1                = 142,    /**< LP UART1 interrupt                                                */
    IRQn_WWDG_RST               = 143,    /**<Window Watchdog reset interrupt (exti_d2_wwdg_it, exti_d1_wwdg_it) */
    IRQn_CRS                    = 144,    /**< Clock Recovery Global Interrupt                                   */
    IRQn_ECC                    = 145,    /**< ECC diagnostic Global Interrupt                                   */
    IRQn_SAI4                   = 146,    /**< SAI4 global interrupt                                             */
    IRQn_HOLD_CORE              = 148,    /**< Hold core interrupt                                               */
    IRQn_WAKEUP_PIN             = 149,    /**< Interrupt for all 6 wake-up pins                                  */
}IRQn_N;

#define NVIC_BASE   0xE000E100UL                /**< NVIC Base Address */
#define NVIC        ((NVIC_ST *) NVIC_BASE)     /**< NVIC structure pointer declaration */

/*
 * NVIC Functions Declarations
 * ---------------------------
 * These functions provide access to NVIC (Nested Vectored Interrupt Controller) operations
 * for enabling/disabling interrupts, managing interrupt pending status, and setting/getting priorities.
 */
extern void   NVIC_EnableIRQ(IRQn_N IRQn);              
extern BOOL   NVIC_GetEnableIRQ(IRQn_N IRQn);           
extern void   NVIC_DisableIRQ(IRQn_N IRQn);             
extern UINT32 NVIC_GetPendingIRQ(IRQn_N IRQn);          
extern void   NVIC_SetPendingIRQ(IRQn_N IRQn);          
extern void   NVIC_ClearPendingIRQ(IRQn_N IRQn);        
extern UINT32 NVIC_GetActive(IRQn_N IRQn);              
extern void   NVIC_SetPriority(IRQn_N IRQn, UINT8 Priority);            
extern UINT32 NVIC_GetPriority(IRQn_N IRQn);                       

#endif