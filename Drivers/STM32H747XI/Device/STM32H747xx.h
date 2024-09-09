#ifndef STM32H747xx_H
#define STM32H747xx_H

#include "standard_libs.h"
#include "miscellaneous.h"

/* Refer to RM0399 Reference Manual from http://www.st.com */
/* Refer to CMSIS */

/* START of MEMORY MAP */
#define D1_ITCMRAM_BASE           (0x00000000UL) /*!< Base address of : 64KB RAM reserved for CPU execution/instruction accessible over ITCM  */
#define D1_ITCMICP_BASE           (0x00100000UL) /*!< Base address of : (up to 128KB) embedded Test FLASH memory accessible over ITCM         */
#define D1_DTCMRAM_BASE           (0x20000000UL) /*!< Base address of : 128KB system data RAM accessible over DTCM                            */
#define D1_AXIFLASH_BASE          (0x08000000UL) /*!< Base address of : (up to 2 MB) embedded FLASH memory accessible over AXI                */
#define D1_AXIICP_BASE            (0x1FF00000UL) /*!< Base address of : (up to 128KB) embedded Test FLASH memory accessible over AXI          */
#define D1_AXISRAM_BASE           (0x24000000UL) /*!< Base address of : (up to 512KB) system data RAM accessible over over AXI                */

#define D2_AXISRAM_BASE           (0x10000000UL) /*!< Base address of : (up to 288KB) system data RAM accessible over over AXI                */
#define D2_AHBSRAM_BASE           (0x30000000UL) /*!< Base address of : (up to 288KB) system data RAM accessible over over AXI->AHB Bridge    */

#define D3_BKPSRAM_BASE           (0x38800000UL) /*!< Base address of : Backup SRAM(4 KB) over AXI->AHB Bridge                                */
#define D3_SRAM_BASE              (0x38000000UL) /*!< Base address of : Backup SRAM(64 KB) over AXI->AHB Bridge                               */

#define PERIPH_BASE               (0x40000000UL) /*!< Base address of : AHB/APB Peripherals                                                   */
#define QSPI_BASE                 (0x90000000UL) /*!< Base address of : QSPI memories  accessible over AXI                                    */

#define FLASH_BANK1_BASE          (0x08000000UL) /*!< Base address of : (up to 1 MB) Flash Bank1 accessible over AXI                          */
#define FLASH_BANK2_BASE          (0x08100000UL) /*!< Base address of : (up to 1 MB) Flash Bank2 accessible over AXI                          */
#define FLASH_END                 (0x081FFFFFUL) /*!< FLASH end address                                                                       */

/* Legacy define */
#define FLASH_BASE                FLASH_BANK1_BASE

/*!< Device electronic signature memory map */
#define UID_BASE                  (0x1FF1E800UL)            /*!< Unique device ID register base address */
#define FLASHSIZE_BASE            (0x1FF1E880UL)            /*!< FLASH Size register base address */

/*!< Peripheral memory map */
#define D2_APB1PERIPH_BASE        PERIPH_BASE
#define D2_APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define D2_AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define D2_AHB2PERIPH_BASE       (PERIPH_BASE + 0x08020000UL)

#define D1_APB1PERIPH_BASE       (PERIPH_BASE + 0x10000000UL)
#define D1_AHB1PERIPH_BASE       (PERIPH_BASE + 0x12000000UL)

#define D3_APB1PERIPH_BASE       (PERIPH_BASE + 0x18000000UL)
#define D3_AHB1PERIPH_BASE       (PERIPH_BASE + 0x18020000UL)

/*!< Legacy Peripheral memory map */
#define APB1PERIPH_BASE        PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000UL)

/*!< D1_AHB1PERIPH peripherals */
#define MDMA_BASE             (D1_AHB1PERIPH_BASE + 0x0000UL)
#define DMA2D_BASE            (D1_AHB1PERIPH_BASE + 0x1000UL)
#define JPGDEC_BASE           (D1_AHB1PERIPH_BASE + 0x3000UL)
#define FLASH_R_BASE          (D1_AHB1PERIPH_BASE + 0x2000UL)
#define FMC_R_BASE            (D1_AHB1PERIPH_BASE + 0x4000UL)
#define QSPI_R_BASE           (D1_AHB1PERIPH_BASE + 0x5000UL)
#define DLYB_QSPI_BASE        (D1_AHB1PERIPH_BASE + 0x6000UL)
#define SDMMC1_BASE           (D1_AHB1PERIPH_BASE + 0x7000UL)
#define DLYB_SDMMC1_BASE      (D1_AHB1PERIPH_BASE + 0x8000UL)
#define RAMECC1_BASE          (D1_AHB1PERIPH_BASE + 0x9000UL)

/*!< D2_AHB1PERIPH peripherals */
#define DMA1_BASE               (D2_AHB1PERIPH_BASE + 0x0000UL)
#define DMA2_BASE               (D2_AHB1PERIPH_BASE + 0x0400UL)
#define DMAMUX1_BASE            (D2_AHB1PERIPH_BASE + 0x0800UL)
#define ADC1_BASE               (D2_AHB1PERIPH_BASE + 0x2000UL)
#define ADC2_BASE               (D2_AHB1PERIPH_BASE + 0x2100UL)
#define ADC12_COMMON_BASE       (D2_AHB1PERIPH_BASE + 0x2300UL)
#define ART_BASE                (D2_AHB1PERIPH_BASE + 0x4400UL)
#define ETH_BASE                (D2_AHB1PERIPH_BASE + 0x8000UL)
#define ETH_MAC_BASE            (ETH_BASE)

/*!< USB registers base address */
#define USB1_OTG_HS_PERIPH_BASE              (0x40040000UL)
#define USB2_OTG_FS_PERIPH_BASE              (0x40080000UL)
#define USB_OTG_GLOBAL_BASE                  (0x000UL)
#define USB_OTG_DEVICE_BASE                  (0x800UL)
#define USB_OTG_IN_ENDPOINT_BASE             (0x900UL)
#define USB_OTG_OUT_ENDPOINT_BASE            (0xB00UL)
#define USB_OTG_EP_REG_SIZE                  (0x20UL)
#define USB_OTG_HOST_BASE                    (0x400UL)
#define USB_OTG_HOST_PORT_BASE               (0x440UL)
#define USB_OTG_HOST_CHANNEL_BASE            (0x500UL)
#define USB_OTG_HOST_CHANNEL_SIZE            (0x20UL)
#define USB_OTG_PCGCCTL_BASE                 (0xE00UL)
#define USB_OTG_FIFO_BASE                    (0x1000UL)
#define USB_OTG_FIFO_SIZE                    (0x1000UL)

/*!< D2_AHB2PERIPH peripherals */
#define DCMI_BASE              (D2_AHB2PERIPH_BASE + 0x0000UL)
#define RNG_BASE               (D2_AHB2PERIPH_BASE + 0x1800UL)
#define SDMMC2_BASE            (D2_AHB2PERIPH_BASE + 0x2400UL)
#define DLYB_SDMMC2_BASE       (D2_AHB2PERIPH_BASE + 0x2800UL)
#define RAMECC2_BASE           (D2_AHB2PERIPH_BASE + 0x3000UL)

/*!< D3_AHB1PERIPH peripherals */
#define GPIOA_BASE            (D3_AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (D3_AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (D3_AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (D3_AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE            (D3_AHB1PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE            (D3_AHB1PERIPH_BASE + 0x1400UL)
#define GPIOG_BASE            (D3_AHB1PERIPH_BASE + 0x1800UL)
#define GPIOH_BASE            (D3_AHB1PERIPH_BASE + 0x1C00UL)
#define GPIOI_BASE            (D3_AHB1PERIPH_BASE + 0x2000UL)
#define GPIOJ_BASE            (D3_AHB1PERIPH_BASE + 0x2400UL)
#define GPIOK_BASE            (D3_AHB1PERIPH_BASE + 0x2800UL)
#define RCC_BASE              (D3_AHB1PERIPH_BASE + 0x4400UL)
#define RCC_C1_BASE           (RCC_BASE + 0x130UL)
#define RCC_C2_BASE           (RCC_BASE + 0x190UL)
#define PWR_BASE              (D3_AHB1PERIPH_BASE + 0x4800UL)
#define CRC_BASE              (D3_AHB1PERIPH_BASE + 0x4C00UL)
#define BDMA_BASE             (D3_AHB1PERIPH_BASE + 0x5400UL)
#define DMAMUX2_BASE          (D3_AHB1PERIPH_BASE + 0x5800UL)
#define ADC3_BASE             (D3_AHB1PERIPH_BASE + 0x6000UL)
#define ADC3_COMMON_BASE      (D3_AHB1PERIPH_BASE + 0x6300UL)
#define HSEM_BASE             (D3_AHB1PERIPH_BASE + 0x6400UL)
#define RAMECC3_BASE          (D3_AHB1PERIPH_BASE + 0x7000UL)

/*!< D1_APB1PERIPH peripherals */
#define LTDC_BASE             (D1_APB1PERIPH_BASE + 0x1000UL)
#define LTDC_Layer1_BASE      (LTDC_BASE + 0x84UL)
#define LTDC_Layer2_BASE      (LTDC_BASE + 0x104UL)
#define DSI_BASE              (D1_APB1PERIPH_BASE)
#define WWDG1_BASE            (D1_APB1PERIPH_BASE + 0x3000UL)

/*!< D2_APB1PERIPH peripherals */
#define TIM2_BASE             (D2_APB1PERIPH_BASE + 0x0000UL)
#define TIM3_BASE             (D2_APB1PERIPH_BASE + 0x0400UL)
#define TIM4_BASE             (D2_APB1PERIPH_BASE + 0x0800UL)
#define TIM5_BASE             (D2_APB1PERIPH_BASE + 0x0C00UL)
#define TIM6_BASE             (D2_APB1PERIPH_BASE + 0x1000UL)
#define TIM7_BASE             (D2_APB1PERIPH_BASE + 0x1400UL)
#define TIM12_BASE            (D2_APB1PERIPH_BASE + 0x1800UL)
#define TIM13_BASE            (D2_APB1PERIPH_BASE + 0x1C00UL)
#define TIM14_BASE            (D2_APB1PERIPH_BASE + 0x2000UL)
#define LPTIM1_BASE           (D2_APB1PERIPH_BASE + 0x2400UL)

#define WWDG2_BASE            (D2_APB1PERIPH_BASE + 0x2C00UL)

#define SPI2_BASE             (D2_APB1PERIPH_BASE + 0x3800UL)
#define SPI3_BASE             (D2_APB1PERIPH_BASE + 0x3C00UL)
#define SPDIFRX_BASE          (D2_APB1PERIPH_BASE + 0x4000UL)
#define USART2_BASE           (D2_APB1PERIPH_BASE + 0x4400UL)
#define USART3_BASE           (D2_APB1PERIPH_BASE + 0x4800UL)
#define UART4_BASE            (D2_APB1PERIPH_BASE + 0x4C00UL)
#define UART5_BASE            (D2_APB1PERIPH_BASE + 0x5000UL)
#define I2C1_BASE             (D2_APB1PERIPH_BASE + 0x5400UL)
#define I2C2_BASE             (D2_APB1PERIPH_BASE + 0x5800UL)
#define I2C3_BASE             (D2_APB1PERIPH_BASE + 0x5C00UL)
#define CEC_BASE              (D2_APB1PERIPH_BASE + 0x6C00UL)
#define DAC1_BASE             (D2_APB1PERIPH_BASE + 0x7400UL)
#define UART7_BASE            (D2_APB1PERIPH_BASE + 0x7800UL)
#define UART8_BASE            (D2_APB1PERIPH_BASE + 0x7C00UL)
#define CRS_BASE              (D2_APB1PERIPH_BASE + 0x8400UL)
#define SWPMI1_BASE           (D2_APB1PERIPH_BASE + 0x8800UL)
#define OPAMP_BASE            (D2_APB1PERIPH_BASE + 0x9000UL)
#define OPAMP1_BASE           (D2_APB1PERIPH_BASE + 0x9000UL)
#define OPAMP2_BASE           (D2_APB1PERIPH_BASE + 0x9010UL)
#define MDIOS_BASE            (D2_APB1PERIPH_BASE + 0x9400UL)
#define FDCAN1_BASE           (D2_APB1PERIPH_BASE + 0xA000UL)
#define FDCAN2_BASE           (D2_APB1PERIPH_BASE + 0xA400UL)
#define FDCAN_CCU_BASE        (D2_APB1PERIPH_BASE + 0xA800UL)
#define SRAMCAN_BASE          (D2_APB1PERIPH_BASE + 0xAC00UL)

/*!< D2_APB2PERIPH peripherals */
#define TIM1_BASE             (D2_APB2PERIPH_BASE + 0x0000UL)
#define TIM8_BASE             (D2_APB2PERIPH_BASE + 0x0400UL)
#define USART1_BASE           (D2_APB2PERIPH_BASE + 0x1000UL)
#define USART6_BASE           (D2_APB2PERIPH_BASE + 0x1400UL)
#define SPI1_BASE             (D2_APB2PERIPH_BASE + 0x3000UL)
#define SPI4_BASE             (D2_APB2PERIPH_BASE + 0x3400UL)
#define TIM15_BASE            (D2_APB2PERIPH_BASE + 0x4000UL)
#define TIM16_BASE            (D2_APB2PERIPH_BASE + 0x4400UL)
#define TIM17_BASE            (D2_APB2PERIPH_BASE + 0x4800UL)
#define SPI5_BASE             (D2_APB2PERIPH_BASE + 0x5000UL)
#define SAI1_BASE             (D2_APB2PERIPH_BASE + 0x5800UL)
#define SAI1_Block_A_BASE     (SAI1_BASE + 0x004UL)
#define SAI1_Block_B_BASE     (SAI1_BASE + 0x024UL)
#define SAI2_BASE             (D2_APB2PERIPH_BASE + 0x5C00UL)
#define SAI2_Block_A_BASE     (SAI2_BASE + 0x004UL)
#define SAI2_Block_B_BASE     (SAI2_BASE + 0x024UL)
#define SAI3_BASE             (D2_APB2PERIPH_BASE + 0x6000UL)
#define SAI3_Block_A_BASE     (SAI3_BASE + 0x004UL)
#define SAI3_Block_B_BASE     (SAI3_BASE + 0x024UL)
#define DFSDM1_BASE           (D2_APB2PERIPH_BASE + 0x7000UL)
#define DFSDM1_Channel0_BASE  (DFSDM1_BASE + 0x00UL)
#define DFSDM1_Channel1_BASE  (DFSDM1_BASE + 0x20UL)
#define DFSDM1_Channel2_BASE  (DFSDM1_BASE + 0x40UL)
#define DFSDM1_Channel3_BASE  (DFSDM1_BASE + 0x60UL)
#define DFSDM1_Channel4_BASE  (DFSDM1_BASE + 0x80UL)
#define DFSDM1_Channel5_BASE  (DFSDM1_BASE + 0xA0UL)
#define DFSDM1_Channel6_BASE  (DFSDM1_BASE + 0xC0UL)
#define DFSDM1_Channel7_BASE  (DFSDM1_BASE + 0xE0UL)
#define DFSDM1_Filter0_BASE   (DFSDM1_BASE + 0x100UL)
#define DFSDM1_Filter1_BASE   (DFSDM1_BASE + 0x180UL)
#define DFSDM1_Filter2_BASE   (DFSDM1_BASE + 0x200UL)
#define DFSDM1_Filter3_BASE   (DFSDM1_BASE + 0x280UL)
#define HRTIM1_BASE           (D2_APB2PERIPH_BASE + 0x7400UL)
#define HRTIM1_TIMA_BASE      (HRTIM1_BASE + 0x00000080UL)
#define HRTIM1_TIMB_BASE      (HRTIM1_BASE + 0x00000100UL)
#define HRTIM1_TIMC_BASE      (HRTIM1_BASE + 0x00000180UL)
#define HRTIM1_TIMD_BASE      (HRTIM1_BASE + 0x00000200UL)
#define HRTIM1_TIME_BASE      (HRTIM1_BASE + 0x00000280UL)
#define HRTIM1_COMMON_BASE    (HRTIM1_BASE + 0x00000380UL)

/*!< D3_APB1PERIPH peripherals */
#define EXTI_BASE             (D3_APB1PERIPH_BASE + 0x0000UL)
#define EXTI_D1_BASE          (EXTI_BASE + 0x0080UL)
#define EXTI_D2_BASE          (EXTI_BASE + 0x00C0UL)
#define SYSCFG_BASE           (D3_APB1PERIPH_BASE + 0x0400UL)
#define LPUART1_BASE          (D3_APB1PERIPH_BASE + 0x0C00UL)
#define SPI6_BASE             (D3_APB1PERIPH_BASE + 0x1400UL)
#define I2C4_BASE             (D3_APB1PERIPH_BASE + 0x1C00UL)
#define LPTIM2_BASE           (D3_APB1PERIPH_BASE + 0x2400UL)
#define LPTIM3_BASE           (D3_APB1PERIPH_BASE + 0x2800UL)
#define LPTIM4_BASE           (D3_APB1PERIPH_BASE + 0x2C00UL)
#define LPTIM5_BASE           (D3_APB1PERIPH_BASE + 0x3000UL)
#define COMP12_BASE           (D3_APB1PERIPH_BASE + 0x3800UL)
#define COMP1_BASE            (COMP12_BASE + 0x0CUL)
#define COMP2_BASE            (COMP12_BASE + 0x10UL)
#define VREFBUF_BASE          (D3_APB1PERIPH_BASE + 0x3C00UL)
#define RTC_BASE              (D3_APB1PERIPH_BASE + 0x4000UL)
#define IWDG1_BASE            (D3_APB1PERIPH_BASE + 0x4800UL)

#define IWDG2_BASE            (D3_APB1PERIPH_BASE + 0x4C00UL)

#define SAI4_BASE             (D3_APB1PERIPH_BASE + 0x5400UL)
#define SAI4_Block_A_BASE     (SAI4_BASE + 0x004UL)
#define SAI4_Block_B_BASE     (SAI4_BASE + 0x024UL)

#define BDMA_Channel0_BASE    (BDMA_BASE + 0x0008UL)
#define BDMA_Channel1_BASE    (BDMA_BASE + 0x001CUL)
#define BDMA_Channel2_BASE    (BDMA_BASE + 0x0030UL)
#define BDMA_Channel3_BASE    (BDMA_BASE + 0x0044UL)
#define BDMA_Channel4_BASE    (BDMA_BASE + 0x0058UL)
#define BDMA_Channel5_BASE    (BDMA_BASE + 0x006CUL)
#define BDMA_Channel6_BASE    (BDMA_BASE + 0x0080UL)
#define BDMA_Channel7_BASE    (BDMA_BASE + 0x0094UL)

#define DMAMUX2_Channel0_BASE    (DMAMUX2_BASE)
#define DMAMUX2_Channel1_BASE    (DMAMUX2_BASE + 0x0004UL)
#define DMAMUX2_Channel2_BASE    (DMAMUX2_BASE + 0x0008UL)
#define DMAMUX2_Channel3_BASE    (DMAMUX2_BASE + 0x000CUL)
#define DMAMUX2_Channel4_BASE    (DMAMUX2_BASE + 0x0010UL)
#define DMAMUX2_Channel5_BASE    (DMAMUX2_BASE + 0x0014UL)
#define DMAMUX2_Channel6_BASE    (DMAMUX2_BASE + 0x0018UL)
#define DMAMUX2_Channel7_BASE    (DMAMUX2_BASE + 0x001CUL)

#define DMAMUX2_RequestGenerator0_BASE  (DMAMUX2_BASE + 0x0100UL)
#define DMAMUX2_RequestGenerator1_BASE  (DMAMUX2_BASE + 0x0104UL)
#define DMAMUX2_RequestGenerator2_BASE  (DMAMUX2_BASE + 0x0108UL)
#define DMAMUX2_RequestGenerator3_BASE  (DMAMUX2_BASE + 0x010CUL)
#define DMAMUX2_RequestGenerator4_BASE  (DMAMUX2_BASE + 0x0110UL)
#define DMAMUX2_RequestGenerator5_BASE  (DMAMUX2_BASE + 0x0114UL)
#define DMAMUX2_RequestGenerator6_BASE  (DMAMUX2_BASE + 0x0118UL)
#define DMAMUX2_RequestGenerator7_BASE  (DMAMUX2_BASE + 0x011CUL)

#define DMAMUX2_ChannelStatus_BASE      (DMAMUX2_BASE + 0x0080UL)
#define DMAMUX2_RequestGenStatus_BASE   (DMAMUX2_BASE + 0x0140UL)

#define DMA1_Stream0_BASE     (DMA1_BASE + 0x010UL)
#define DMA1_Stream1_BASE     (DMA1_BASE + 0x028UL)
#define DMA1_Stream2_BASE     (DMA1_BASE + 0x040UL)
#define DMA1_Stream3_BASE     (DMA1_BASE + 0x058UL)
#define DMA1_Stream4_BASE     (DMA1_BASE + 0x070UL)
#define DMA1_Stream5_BASE     (DMA1_BASE + 0x088UL)
#define DMA1_Stream6_BASE     (DMA1_BASE + 0x0A0UL)
#define DMA1_Stream7_BASE     (DMA1_BASE + 0x0B8UL)

#define DMA2_Stream0_BASE     (DMA2_BASE + 0x010UL)
#define DMA2_Stream1_BASE     (DMA2_BASE + 0x028UL)
#define DMA2_Stream2_BASE     (DMA2_BASE + 0x040UL)
#define DMA2_Stream3_BASE     (DMA2_BASE + 0x058UL)
#define DMA2_Stream4_BASE     (DMA2_BASE + 0x070UL)
#define DMA2_Stream5_BASE     (DMA2_BASE + 0x088UL)
#define DMA2_Stream6_BASE     (DMA2_BASE + 0x0A0UL)
#define DMA2_Stream7_BASE     (DMA2_BASE + 0x0B8UL)

#define DMAMUX1_Channel0_BASE    (DMAMUX1_BASE)
#define DMAMUX1_Channel1_BASE    (DMAMUX1_BASE + 0x0004UL)
#define DMAMUX1_Channel2_BASE    (DMAMUX1_BASE + 0x0008UL)
#define DMAMUX1_Channel3_BASE    (DMAMUX1_BASE + 0x000CUL)
#define DMAMUX1_Channel4_BASE    (DMAMUX1_BASE + 0x0010UL)
#define DMAMUX1_Channel5_BASE    (DMAMUX1_BASE + 0x0014UL)
#define DMAMUX1_Channel6_BASE    (DMAMUX1_BASE + 0x0018UL)
#define DMAMUX1_Channel7_BASE    (DMAMUX1_BASE + 0x001CUL)
#define DMAMUX1_Channel8_BASE    (DMAMUX1_BASE + 0x0020UL)
#define DMAMUX1_Channel9_BASE    (DMAMUX1_BASE + 0x0024UL)
#define DMAMUX1_Channel10_BASE   (DMAMUX1_BASE + 0x0028UL)
#define DMAMUX1_Channel11_BASE   (DMAMUX1_BASE + 0x002CUL)
#define DMAMUX1_Channel12_BASE   (DMAMUX1_BASE + 0x0030UL)
#define DMAMUX1_Channel13_BASE   (DMAMUX1_BASE + 0x0034UL)
#define DMAMUX1_Channel14_BASE   (DMAMUX1_BASE + 0x0038UL)
#define DMAMUX1_Channel15_BASE   (DMAMUX1_BASE + 0x003CUL)

#define DMAMUX1_RequestGenerator0_BASE  (DMAMUX1_BASE + 0x0100UL)
#define DMAMUX1_RequestGenerator1_BASE  (DMAMUX1_BASE + 0x0104UL)
#define DMAMUX1_RequestGenerator2_BASE  (DMAMUX1_BASE + 0x0108UL)
#define DMAMUX1_RequestGenerator3_BASE  (DMAMUX1_BASE + 0x010CUL)
#define DMAMUX1_RequestGenerator4_BASE  (DMAMUX1_BASE + 0x0110UL)
#define DMAMUX1_RequestGenerator5_BASE  (DMAMUX1_BASE + 0x0114UL)
#define DMAMUX1_RequestGenerator6_BASE  (DMAMUX1_BASE + 0x0118UL)
#define DMAMUX1_RequestGenerator7_BASE  (DMAMUX1_BASE + 0x011CUL)

#define DMAMUX1_ChannelStatus_BASE      (DMAMUX1_BASE + 0x0080UL)
#define DMAMUX1_RequestGenStatus_BASE   (DMAMUX1_BASE + 0x0140UL)

/*!< FMC Banks registers base  address */
#define FMC_Bank1_R_BASE      (FMC_R_BASE + 0x0000UL)
#define FMC_Bank1E_R_BASE     (FMC_R_BASE + 0x0104UL)
#define FMC_Bank2_R_BASE      (FMC_R_BASE + 0x0060UL)
#define FMC_Bank3_R_BASE      (FMC_R_BASE + 0x0080UL)
#define FMC_Bank5_6_R_BASE    (FMC_R_BASE + 0x0140UL)

/* Debug MCU registers base address */
#define DBGMCU_BASE           (0x5C001000UL)

#define MDMA_Channel0_BASE    (MDMA_BASE + 0x00000040UL)
#define MDMA_Channel1_BASE    (MDMA_BASE + 0x00000080UL)
#define MDMA_Channel2_BASE    (MDMA_BASE + 0x000000C0UL)
#define MDMA_Channel3_BASE    (MDMA_BASE + 0x00000100UL)
#define MDMA_Channel4_BASE    (MDMA_BASE + 0x00000140UL)
#define MDMA_Channel5_BASE    (MDMA_BASE + 0x00000180UL)
#define MDMA_Channel6_BASE    (MDMA_BASE + 0x000001C0UL)
#define MDMA_Channel7_BASE    (MDMA_BASE + 0x00000200UL)
#define MDMA_Channel8_BASE    (MDMA_BASE + 0x00000240UL)
#define MDMA_Channel9_BASE    (MDMA_BASE + 0x00000280UL)
#define MDMA_Channel10_BASE   (MDMA_BASE + 0x000002C0UL)
#define MDMA_Channel11_BASE   (MDMA_BASE + 0x00000300UL)
#define MDMA_Channel12_BASE   (MDMA_BASE + 0x00000340UL)
#define MDMA_Channel13_BASE   (MDMA_BASE + 0x00000380UL)
#define MDMA_Channel14_BASE   (MDMA_BASE + 0x000003C0UL)
#define MDMA_Channel15_BASE   (MDMA_BASE + 0x00000400UL)

#define RAMECC1_Monitor1_BASE (RAMECC1_BASE + 0x20UL)
#define RAMECC1_Monitor2_BASE (RAMECC1_BASE + 0x40UL)
#define RAMECC1_Monitor3_BASE (RAMECC1_BASE + 0x60UL)
#define RAMECC1_Monitor4_BASE (RAMECC1_BASE + 0x80UL)
#define RAMECC1_Monitor5_BASE (RAMECC1_BASE + 0xA0UL)

#define RAMECC2_Monitor1_BASE (RAMECC2_BASE + 0x20UL)
#define RAMECC2_Monitor2_BASE (RAMECC2_BASE + 0x40UL)
#define RAMECC2_Monitor3_BASE (RAMECC2_BASE + 0x60UL)
#define RAMECC2_Monitor4_BASE (RAMECC2_BASE + 0x80UL)
#define RAMECC2_Monitor5_BASE (RAMECC2_BASE + 0xA0UL)

#define RAMECC3_Monitor1_BASE (RAMECC3_BASE + 0x20UL)
#define RAMECC3_Monitor2_BASE (RAMECC3_BASE + 0x40UL)

#define GPV_BASE              (PERIPH_BASE + 0x11000000UL)

/* END of MEMORY MAP */

/**
 * @brief STM32H7XX Interrupt Number Definition
 */
typedef enum
{
/******  Cortex-M Processor Exceptions Numbers *****************************************************************/
    NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                          */
    HardFault_IRQn              = -13,    /*!< 3 Cortex-M Hard Fault Interrupt                                   */
    MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M Memory Management Interrupt                            */
    BusFault_IRQn               = -11,    /*!< 5 Cortex-M Bus Fault Interrupt                                    */
    UsageFault_IRQn             = -10,    /*!< 6 Cortex-M Usage Fault Interrupt                                  */
    SVCall_IRQn                 = -5,     /*!< 11 Cortex-M SV Call Interrupt                                     */
    DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M Debug Monitor Interrupt                               */
    PendSV_IRQn                 = -2,     /*!< 14 Cortex-M Pend SV Interrupt                                     */
    SysTick_IRQn                = -1,     /*!< 15 Cortex-M System Tick Interrupt                                 */
/******  STM32 specific Interrupt Numbers **********************************************************************/
    WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt ( wwdg1_it, wwdg2_it)                   */
    PVD_AVD_IRQn                = 1,      /*!< PVD/AVD through EXTI Line detection Interrupt                     */
    TAMP_STAMP_IRQn             = 2,      /*!< Tamper and TimeStamp interrupts through the EXTI line             */
    RTC_WKUP_IRQn               = 3,      /*!< RTC Wakeup interrupt through the EXTI line                        */
    FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                            */
    RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                              */
    EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                              */
    EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                              */
    EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                              */
    EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                              */
    EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                              */
    DMA1_Stream0_IRQn           = 11,     /*!< DMA1 Stream 0 global Interrupt                                    */
    DMA1_Stream1_IRQn           = 12,     /*!< DMA1 Stream 1 global Interrupt                                    */
    DMA1_Stream2_IRQn           = 13,     /*!< DMA1 Stream 2 global Interrupt                                    */
    DMA1_Stream3_IRQn           = 14,     /*!< DMA1 Stream 3 global Interrupt                                    */
    DMA1_Stream4_IRQn           = 15,     /*!< DMA1 Stream 4 global Interrupt                                    */
    DMA1_Stream5_IRQn           = 16,     /*!< DMA1 Stream 5 global Interrupt                                    */
    DMA1_Stream6_IRQn           = 17,     /*!< DMA1 Stream 6 global Interrupt                                    */
    ADC_IRQn                    = 18,     /*!< ADC1 and  ADC2 global Interrupts                                  */
    FDCAN1_IT0_IRQn             = 19,     /*!< FDCAN1 Interrupt line 0                                           */
    FDCAN2_IT0_IRQn             = 20,     /*!< FDCAN2 Interrupt line 0                                           */
    FDCAN1_IT1_IRQn             = 21,     /*!< FDCAN1 Interrupt line 1                                           */
    FDCAN2_IT1_IRQn             = 22,     /*!< FDCAN2 Interrupt line 1                                           */
    EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                                     */
    TIM1_BRK_IRQn               = 24,     /*!< TIM1 Break Interrupt                                              */
    TIM1_UP_IRQn                = 25,     /*!< TIM1 Update Interrupt                                             */
    TIM1_TRG_COM_IRQn           = 26,     /*!< TIM1 Trigger and Commutation Interrupt                            */
    TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                                    */
    TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                             */
    TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                             */
    TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                             */
    I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                              */
    I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                              */
    I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                              */
    I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                              */
    SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                             */
    SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                             */
    USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                                           */
    USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                                           */
    USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                                           */
    EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                                   */
    RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
    TIM8_BRK_TIM12_IRQn         = 43,     /*!< TIM8 Break Interrupt and TIM12 global interrupt                   */
    TIM8_UP_TIM13_IRQn          = 44,     /*!< TIM8 Update Interrupt and TIM13 global interrupt                  */
    TIM8_TRG_COM_TIM14_IRQn     = 45,     /*!< TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
    TIM8_CC_IRQn                = 46,     /*!< TIM8 Capture Compare Interrupt                                    */
    DMA1_Stream7_IRQn           = 47,     /*!< DMA1 Stream7 Interrupt                                            */
    FMC_IRQn                    = 48,     /*!< FMC global Interrupt                                              */
    SDMMC1_IRQn                 = 49,     /*!< SDMMC1 global Interrupt                                           */
    TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                             */
    SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                             */
    UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                                            */
    UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                                            */
    TIM6_DAC_IRQn               = 54,     /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
    TIM7_IRQn                   = 55,     /*!< TIM7 global interrupt                                             */
    DMA2_Stream0_IRQn           = 56,     /*!<   DMA2 Stream 0 global Interrupt                                  */
    DMA2_Stream1_IRQn           = 57,     /*!<   DMA2 Stream 1 global Interrupt                                  */
    DMA2_Stream2_IRQn           = 58,     /*!<   DMA2 Stream 2 global Interrupt                                  */
    DMA2_Stream3_IRQn           = 59,     /*!<   DMA2 Stream 3 global Interrupt                                  */
    DMA2_Stream4_IRQn           = 60,     /*!<   DMA2 Stream 4 global Interrupt                                  */
    ETH_IRQn                    = 61,     /*!< Ethernet global Interrupt                                         */
    ETH_WKUP_IRQn               = 62,     /*!< Ethernet Wakeup through EXTI line Interrupt                       */
    FDCAN_CAL_IRQn              = 63,     /*!< FDCAN Calibration unit Interrupt                                  */
    CM7_SEV_IRQn                = 64,     /*!< CM7 Send event interrupt for CM4                                  */
    CM4_SEV_IRQn                = 65,     /*!< CM4 Send event interrupt for CM7                                  */
    DMA2_Stream5_IRQn           = 68,     /*!< DMA2 Stream 5 global interrupt                                    */
    DMA2_Stream6_IRQn           = 69,     /*!< DMA2 Stream 6 global interrupt                                    */
    DMA2_Stream7_IRQn           = 70,     /*!< DMA2 Stream 7 global interrupt                                    */
    USART6_IRQn                 = 71,     /*!< USART6 global interrupt                                           */
    I2C3_EV_IRQn                = 72,     /*!< I2C3 event interrupt                                              */
    I2C3_ER_IRQn                = 73,     /*!< I2C3 error interrupt                                              */
    OTG_HS_EP1_OUT_IRQn         = 74,     /*!< USB OTG HS End Point 1 Out global interrupt                       */
    OTG_HS_EP1_IN_IRQn          = 75,     /*!< USB OTG HS End Point 1 In global interrupt                        */
    OTG_HS_WKUP_IRQn            = 76,     /*!< USB OTG HS Wakeup through EXTI interrupt                          */
    OTG_HS_IRQn                 = 77,     /*!< USB OTG HS global interrupt                                       */
    DCMI_IRQn                   = 78,     /*!< DCMI global interrupt                                             */
    RNG_IRQn                    = 80,     /*!< RNG global interrupt                                              */
    FPU_IRQn                    = 81,     /*!< FPU global interrupt                                              */
    UART7_IRQn                  = 82,     /*!< UART7 global interrupt                                            */
    UART8_IRQn                  = 83,     /*!< UART8 global interrupt                                            */
    SPI4_IRQn                   = 84,     /*!< SPI4 global Interrupt                                             */
    SPI5_IRQn                   = 85,     /*!< SPI5 global Interrupt                                             */
    SPI6_IRQn                   = 86,     /*!< SPI6 global Interrupt                                             */
    SAI1_IRQn                   = 87,     /*!< SAI1 global Interrupt                                             */
    LTDC_IRQn                   = 88,     /*!< LTDC global Interrupt                                             */
    LTDC_ER_IRQn                = 89,     /*!< LTDC Error global Interrupt                                       */
    DMA2D_IRQn                  = 90,     /*!< DMA2D global Interrupt                                            */
    SAI2_IRQn                   = 91,     /*!< SAI2 global Interrupt                                             */
    QUADSPI_IRQn                = 92,     /*!< Quad SPI global interrupt                                         */
    LPTIM1_IRQn                 = 93,     /*!< LP TIM1 interrupt                                                 */
    CEC_IRQn                    = 94,     /*!< HDMI-CEC global Interrupt                                         */
    I2C4_EV_IRQn                = 95,     /*!< I2C4 Event Interrupt                                              */
    I2C4_ER_IRQn                = 96,     /*!< I2C4 Error Interrupt                                              */
    SPDIF_RX_IRQn               = 97,     /*!< SPDIF-RX global Interrupt                                         */
    OTG_FS_EP1_OUT_IRQn         = 98,     /*!< USB OTG HS2 global interrupt                                      */
    OTG_FS_EP1_IN_IRQn          = 99,     /*!< USB OTG HS2 End Point 1 Out global interrupt                      */
    OTG_FS_WKUP_IRQn            = 100,    /*!< USB OTG HS2 End Point 1 In global interrupt                       */
    OTG_FS_IRQn                 = 101,    /*!< USB OTG HS2 Wakeup through EXTI interrupt                         */
    DMAMUX1_OVR_IRQn            = 102,    /*!<DMAMUX1 Overrun interrupt                                          */
    HRTIM1_Master_IRQn          = 103,    /*!< HRTIM Master Timer global Interrupts                              */
    HRTIM1_TIMA_IRQn            = 104,    /*!< HRTIM Timer A global Interrupt                                    */
    HRTIM1_TIMB_IRQn            = 105,    /*!< HRTIM Timer B global Interrupt                                    */
    HRTIM1_TIMC_IRQn            = 106,    /*!< HRTIM Timer C global Interrupt                                    */
    HRTIM1_TIMD_IRQn            = 107,    /*!< HRTIM Timer D global Interrupt                                    */
    HRTIM1_TIME_IRQn            = 108,    /*!< HRTIM Timer E global Interrupt                                    */
    HRTIM1_FLT_IRQn             = 109,    /*!< HRTIM Fault global Interrupt                                      */
    DFSDM1_FLT0_IRQn            = 110,    /*!<DFSDM Filter1 Interrupt                                            */
    DFSDM1_FLT1_IRQn            = 111,    /*!<DFSDM Filter2 Interrupt                                            */
    DFSDM1_FLT2_IRQn            = 112,    /*!<DFSDM Filter3 Interrupt                                            */
    DFSDM1_FLT3_IRQn            = 113,    /*!<DFSDM Filter4 Interrupt                                            */
    SAI3_IRQn                   = 114,    /*!< SAI3 global Interrupt                                             */
    SWPMI1_IRQn                 = 115,    /*!< Serial Wire Interface 1 global interrupt                          */
    TIM15_IRQn                  = 116,    /*!< TIM15 global Interrupt                                            */
    TIM16_IRQn                  = 117,    /*!< TIM16 global Interrupt                                            */
    TIM17_IRQn                  = 118,    /*!< TIM17 global Interrupt                                            */
    MDIOS_WKUP_IRQn             = 119,    /*!< MDIOS Wakeup  Interrupt                                           */
    MDIOS_IRQn                  = 120,    /*!< MDIOS global Interrupt                                            */
    JPEG_IRQn                   = 121,    /*!< JPEG global Interrupt                                             */
    MDMA_IRQn                   = 122,    /*!< MDMA global Interrupt                                             */
    DSI_IRQn                    = 123,    /*!< DSI global Interrupt                                              */
    SDMMC2_IRQn                 = 124,    /*!< SDMMC2 global Interrupt                                           */
    HSEM1_IRQn                  = 125,    /*!< HSEM1 global Interrupt                                            */
    HSEM2_IRQn                  = 126,    /*!< HSEM2 global Interrupt                                            */
    ADC3_IRQn                   = 127,    /*!< ADC3 global Interrupt                                             */
    DMAMUX2_OVR_IRQn            = 128,    /*!<DMAMUX2 Overrun interrupt                                          */
    BDMA_Channel0_IRQn          = 129,    /*!< BDMA Channel 0 global Interrupt                                   */
    BDMA_Channel1_IRQn          = 130,    /*!< BDMA Channel 1 global Interrupt                                   */
    BDMA_Channel2_IRQn          = 131,    /*!< BDMA Channel 2 global Interrupt                                   */
    BDMA_Channel3_IRQn          = 132,    /*!< BDMA Channel 3 global Interrupt                                   */
    BDMA_Channel4_IRQn          = 133,    /*!< BDMA Channel 4 global Interrupt                                   */
    BDMA_Channel5_IRQn          = 134,    /*!< BDMA Channel 5 global Interrupt                                   */
    BDMA_Channel6_IRQn          = 135,    /*!< BDMA Channel 6 global Interrupt                                   */
    BDMA_Channel7_IRQn          = 136,    /*!< BDMA Channel 7 global Interrupt                                   */
    COMP_IRQn                   = 137 ,   /*!< COMP global Interrupt                                             */
    LPTIM2_IRQn                 = 138,    /*!< LP TIM2 global interrupt                                          */
    LPTIM3_IRQn                 = 139,    /*!< LP TIM3 global interrupt                                          */
    LPTIM4_IRQn                 = 140,    /*!< LP TIM4 global interrupt                                          */
    LPTIM5_IRQn                 = 141,    /*!< LP TIM5 global interrupt                                          */
    LPUART1_IRQn                = 142,    /*!< LP UART1 interrupt                                                */
    WWDG_RST_IRQn               = 143,    /*!<Window Watchdog reset interrupt (exti_d2_wwdg_it, exti_d1_wwdg_it) */
    CRS_IRQn                    = 144,    /*!< Clock Recovery Global Interrupt                                   */
    ECC_IRQn                    = 145,    /*!< ECC diagnostic Global Interrupt                                   */
    SAI4_IRQn                   = 146,    /*!< SAI4 global interrupt                                             */
    HOLD_CORE_IRQn              = 148,    /*!< Hold core interrupt                                               */
    WAKEUP_PIN_IRQn             = 149,    /*!< Interrupt for all 6 wake-up pins                                  */
} IRQn_Type;


/* START of Peripheral registers structures */
/**
  * @brief Analog to Digital Converter
  */
typedef struct
{
    volatile uint32_t ISR;              /*!< ADC Interrupt and Status Register,                          Address offset: 0x00 */
    volatile uint32_t IER;              /*!< ADC Interrupt Enable Register,                              Address offset: 0x04 */
    volatile uint32_t CR;               /*!< ADC control register,                                       Address offset: 0x08 */
    volatile uint32_t CFGR;             /*!< ADC Configuration register,                                 Address offset: 0x0C */
    volatile uint32_t CFGR2;            /*!< ADC Configuration register 2,                               Address offset: 0x10 */
    volatile uint32_t SMPR1;            /*!< ADC sample time register 1,                                 Address offset: 0x14 */
    volatile uint32_t SMPR2;            /*!< ADC sample time register 2,                                 Address offset: 0x18 */
    volatile uint32_t PCSEL;            /*!< ADC pre-channel selection,                                  Address offset: 0x1C */
    volatile uint32_t LTR1;             /*!< ADC watchdog Lower threshold register 1,                    Address offset: 0x20 */
    volatile uint32_t HTR1;             /*!< ADC watchdog higher threshold register 1,                   Address offset: 0x24 */
             uint32_t RESERVED1;        /*!< Reserved, 0x028                                                                  */
             uint32_t RESERVED2;        /*!< Reserved, 0x02C                                                                  */
    volatile uint32_t SQR1;             /*!< ADC regular sequence register 1,                            Address offset: 0x30 */
    volatile uint32_t SQR2;             /*!< ADC regular sequence register 2,                            Address offset: 0x34 */
    volatile uint32_t SQR3;             /*!< ADC regular sequence register 3,                            Address offset: 0x38 */
    volatile uint32_t SQR4;             /*!< ADC regular sequence register 4,                            Address offset: 0x3C */
    volatile uint32_t DR;               /*!< ADC regular data register,                                  Address offset: 0x40 */
             uint32_t RESERVED3;        /*!< Reserved, 0x044                                                                  */
             uint32_t RESERVED4;        /*!< Reserved, 0x048                                                                  */
    volatile uint32_t JSQR;             /*!< ADC injected sequence register,                             Address offset: 0x4C */
             uint32_t RESERVED5[4];     /*!< Reserved, 0x050 - 0x05C                                                          */
    volatile uint32_t OFR1;             /*!< ADC offset register 1,                                      Address offset: 0x60 */
    volatile uint32_t OFR2;             /*!< ADC offset register 2,                                      Address offset: 0x64 */
    volatile uint32_t OFR3;             /*!< ADC offset register 3,                                      Address offset: 0x68 */
    volatile uint32_t OFR4;             /*!< ADC offset register 4,                                      Address offset: 0x6C */
             uint32_t RESERVED6[4];     /*!< Reserved, 0x070 - 0x07C                                                          */
    volatile uint32_t JDR1;             /*!< ADC injected data register 1,                               Address offset: 0x80 */
    volatile uint32_t JDR2;             /*!< ADC injected data register 2,                               Address offset: 0x84 */
    volatile uint32_t JDR3;             /*!< ADC injected data register 3,                               Address offset: 0x88 */
    volatile uint32_t JDR4;             /*!< ADC injected data register 4,                               Address offset: 0x8C */
             uint32_t RESERVED7[4];     /*!< Reserved, 0x090 - 0x09C                                                          */
    volatile uint32_t AWD2CR;           /*!< ADC  Analog Watchdog 2 Configuration Register,              Address offset: 0xA0 */
    volatile uint32_t AWD3CR;           /*!< ADC  Analog Watchdog 3 Configuration Register,              Address offset: 0xA4 */
             uint32_t RESERVED8;        /*!< Reserved, 0x0A8                                                                  */
             uint32_t RESERVED9;        /*!< Reserved, 0x0AC                                                                  */
    volatile uint32_t LTR2;             /*!< ADC watchdog Lower threshold register 2,                    Address offset: 0xB0 */
    volatile uint32_t HTR2;             /*!< ADC watchdog Higher threshold register 2,                   Address offset: 0xB4 */
    volatile uint32_t LTR3;             /*!< ADC watchdog Lower threshold register 3,                    Address offset: 0xB8 */
    volatile uint32_t HTR3;             /*!< ADC watchdog Higher threshold register 3,                   Address offset: 0xBC */
    volatile uint32_t DIFSEL;           /*!< ADC  Differential Mode Selection Register,                  Address offset: 0xC0 */
    volatile uint32_t CALFACT;          /*!< ADC  Calibration Factors,                                   Address offset: 0xC4 */
    volatile uint32_t CALFACT2;         /*!< ADC  Linearity Calibration Factors,                         Address offset: 0xC8 */
} ADC_TypeDef;

typedef struct
{
    volatile uint32_t CSR;          /*!< ADC Common status register, Address offset: ADC1/3 base address + 0x300 */
             uint32_t RESERVED;     /*!< Reserved, ADC1/3 base address + 0x304 */
    volatile uint32_t CCR;          /*!< ADC common control register, Address offset: ADC1/3 base address + 0x308 */
    volatile uint32_t CDR;          /*!< ADC common regular data register for dual Address offset: ADC1/3 base address + 0x30C */
    volatile uint32_t CDR2;         /*!< ADC common regular data register for 32-bit dual mode Address offset: ADC1/3 base address + 0x310 */
} ADC_Common_TypeDef;

/**
  * @brief ART
  */
typedef struct
{
    volatile uint32_t  CTR;        /*!< ART accelerator - control register */
}ART_TypeDef;

/**
  * @brief VREFBUF
  */
typedef struct
{
    volatile uint32_t CSR;         /*!< VREFBUF control and status register,         Address offset: 0x00 */
    volatile uint32_t CCR;         /*!< VREFBUF calibration and control register,    Address offset: 0x04 */
} VREFBUF_TypeDef;


/**
  * @brief FD Controller Area Network
  */
typedef struct
{
    volatile uint32_t CREL;         /*!< FDCAN Core Release register,                                     Address offset: 0x000 */
    volatile uint32_t ENDN;         /*!< FDCAN Endian register,                                           Address offset: 0x004 */
    volatile uint32_t RESERVED1;    /*!< Reserved,                                                                        0x008 */
    volatile uint32_t DBTP;         /*!< FDCAN Data Bit Timing & Prescaler register,                      Address offset: 0x00C */
    volatile uint32_t TEST;         /*!< FDCAN Test register,                                             Address offset: 0x010 */
    volatile uint32_t RWD;          /*!< FDCAN RAM Watchdog register,                                     Address offset: 0x014 */
    volatile uint32_t CCCR;         /*!< FDCAN CC Control register,                                       Address offset: 0x018 */
    volatile uint32_t NBTP;         /*!< FDCAN Nominal Bit Timing & Prescaler register,                   Address offset: 0x01C */
    volatile uint32_t TSCC;         /*!< FDCAN Timestamp Counter Configuration register,                  Address offset: 0x020 */
    volatile uint32_t TSCV;         /*!< FDCAN Timestamp Counter Value register,                          Address offset: 0x024 */
    volatile uint32_t TOCC;         /*!< FDCAN Timeout Counter Configuration register,                    Address offset: 0x028 */
    volatile uint32_t TOCV;         /*!< FDCAN Timeout Counter Value register,                            Address offset: 0x02C */
    volatile uint32_t RESERVED2[4]; /*!< Reserved,                                                                0x030 - 0x03C */
    volatile uint32_t ECR;          /*!< FDCAN Error Counter register,                                    Address offset: 0x040 */
    volatile uint32_t PSR;          /*!< FDCAN Protocol Status register,                                  Address offset: 0x044 */
    volatile uint32_t TDCR;         /*!< FDCAN Transmitter Delay Compensation register,                   Address offset: 0x048 */
    volatile uint32_t RESERVED3;    /*!< Reserved,                                                                        0x04C */
    volatile uint32_t IR;           /*!< FDCAN Interrupt register,                                        Address offset: 0x050 */
    volatile uint32_t IE;           /*!< FDCAN Interrupt Enable register,                                 Address offset: 0x054 */
    volatile uint32_t ILS;          /*!< FDCAN Interrupt Line Select register,                            Address offset: 0x058 */
    volatile uint32_t ILE;          /*!< FDCAN Interrupt Line Enable register,                            Address offset: 0x05C */
    volatile uint32_t RESERVED4[8]; /*!< Reserved,                                                                0x060 - 0x07C */
    volatile uint32_t GFC;          /*!< FDCAN Global Filter Configuration register,                      Address offset: 0x080 */
    volatile uint32_t SIDFC;        /*!< FDCAN Standard ID Filter Configuration register,                 Address offset: 0x084 */
    volatile uint32_t XIDFC;        /*!< FDCAN Extended ID Filter Configuration register,                 Address offset: 0x088 */
    volatile uint32_t RESERVED5;    /*!< Reserved,                                                                        0x08C */
    volatile uint32_t XIDAM;        /*!< FDCAN Extended ID AND Mask register,                             Address offset: 0x090 */
    volatile uint32_t HPMS;         /*!< FDCAN High Priority Message Status register,                     Address offset: 0x094 */
    volatile uint32_t NDAT1;        /*!< FDCAN New Data 1 register,                                       Address offset: 0x098 */
    volatile uint32_t NDAT2;        /*!< FDCAN New Data 2 register,                                       Address offset: 0x09C */
    volatile uint32_t RXF0C;        /*!< FDCAN Rx FIFO 0 Configuration register,                          Address offset: 0x0A0 */
    volatile uint32_t RXF0S;        /*!< FDCAN Rx FIFO 0 Status register,                                 Address offset: 0x0A4 */
    volatile uint32_t RXF0A;        /*!< FDCAN Rx FIFO 0 Acknowledge register,                            Address offset: 0x0A8 */
    volatile uint32_t RXBC;         /*!< FDCAN Rx Buffer Configuration register,                          Address offset: 0x0AC */
    volatile uint32_t RXF1C;        /*!< FDCAN Rx FIFO 1 Configuration register,                          Address offset: 0x0B0 */
    volatile uint32_t RXF1S;        /*!< FDCAN Rx FIFO 1 Status register,                                 Address offset: 0x0B4 */
    volatile uint32_t RXF1A;        /*!< FDCAN Rx FIFO 1 Acknowledge register,                            Address offset: 0x0B8 */
    volatile uint32_t RXESC;        /*!< FDCAN Rx Buffer/FIFO Element Size Configuration register,        Address offset: 0x0BC */
    volatile uint32_t TXBC;         /*!< FDCAN Tx Buffer Configuration register,                          Address offset: 0x0C0 */
    volatile uint32_t TXFQS;        /*!< FDCAN Tx FIFO/Queue Status register,                             Address offset: 0x0C4 */
    volatile uint32_t TXESC;        /*!< FDCAN Tx Buffer Element Size Configuration register,             Address offset: 0x0C8 */
    volatile uint32_t TXBRP;        /*!< FDCAN Tx Buffer Request Pending register,                        Address offset: 0x0CC */
    volatile uint32_t TXBAR;        /*!< FDCAN Tx Buffer Add Request register,                            Address offset: 0x0D0 */
    volatile uint32_t TXBCR;        /*!< FDCAN Tx Buffer Cancellation Request register,                   Address offset: 0x0D4 */
    volatile uint32_t TXBTO;        /*!< FDCAN Tx Buffer Transmission Occurred register,                  Address offset: 0x0D8 */
    volatile uint32_t TXBCF;        /*!< FDCAN Tx Buffer Cancellation Finished register,                  Address offset: 0x0DC */
    volatile uint32_t TXBTIE;       /*!< FDCAN Tx Buffer Transmission Interrupt Enable register,          Address offset: 0x0E0 */
    volatile uint32_t TXBCIE;       /*!< FDCAN Tx Buffer Cancellation Finished Interrupt Enable register, Address offset: 0x0E4 */
    volatile uint32_t RESERVED6[2]; /*!< Reserved,                                                                0x0E8 - 0x0EC */
    volatile uint32_t TXEFC;        /*!< FDCAN Tx Event FIFO Configuration register,                      Address offset: 0x0F0 */
    volatile uint32_t TXEFS;        /*!< FDCAN Tx Event FIFO Status register,                             Address offset: 0x0F4 */
    volatile uint32_t TXEFA;        /*!< FDCAN Tx Event FIFO Acknowledge register,                        Address offset: 0x0F8 */
    volatile uint32_t RESERVED7;    /*!< Reserved,                                                                        0x0FC */
} FDCAN_GlobalTypeDef;

/**
  * @brief TTFD Controller Area Network
  */
typedef struct
{
    volatile uint32_t TTTMC;          /*!< TT Trigger Memory Configuration register,    Address offset: 0x100 */
    volatile uint32_t TTRMC;          /*!< TT Reference Message Configuration register, Address offset: 0x104 */
    volatile uint32_t TTOCF;          /*!< TT Operation Configuration register,         Address offset: 0x108 */
    volatile uint32_t TTMLM;          /*!< TT Matrix Limits register,                   Address offset: 0x10C */
    volatile uint32_t TURCF;          /*!< TUR Configuration register,                  Address offset: 0x110 */
    volatile uint32_t TTOCN;          /*!< TT Operation Control register,               Address offset: 0x114 */
    volatile uint32_t TTGTP;          /*!< TT Global Time Preset register,              Address offset: 0x118 */
    volatile uint32_t TTTMK;          /*!< TT Time Mark register,                       Address offset: 0x11C */
    volatile uint32_t TTIR;           /*!< TT Interrupt register,                       Address offset: 0x120 */
    volatile uint32_t TTIE;           /*!< TT Interrupt Enable register,                Address offset: 0x124 */
    volatile uint32_t TTILS;          /*!< TT Interrupt Line Select register,           Address offset: 0x128 */
    volatile uint32_t TTOST;          /*!< TT Operation Status register,                Address offset: 0x12C */
    volatile uint32_t TURNA;          /*!< TT TUR Numerator Actual register,            Address offset: 0x130 */
    volatile uint32_t TTLGT;          /*!< TT Local and Global Time register,           Address offset: 0x134 */
    volatile uint32_t TTCTC;          /*!< TT Cycle Time and Count register,            Address offset: 0x138 */
    volatile uint32_t TTCPT;          /*!< TT Capture Time register,                    Address offset: 0x13C */
    volatile uint32_t TTCSM;          /*!< TT Cycle Sync Mark register,                 Address offset: 0x140 */
    volatile uint32_t RESERVED1[111]; /*!< Reserved,                                            0x144 - 0x2FC */
    volatile uint32_t TTTS;           /*!< TT Trigger Select register,                  Address offset: 0x300 */
} TTCAN_TypeDef;

/**
  * @brief FD Controller Area Network
  */
typedef struct
{
    volatile uint32_t CREL;  /*!< Clock Calibration Unit Core Release register, Address offset: 0x00 */
    volatile uint32_t CCFG;  /*!< Calibration Configuration register,           Address offset: 0x04 */
    volatile uint32_t CSTAT; /*!< Calibration Status register,                  Address offset: 0x08 */
    volatile uint32_t CWD;   /*!< Calibration Watchdog register,                Address offset: 0x0C */
    volatile uint32_t IR;    /*!< CCU Interrupt register,                       Address offset: 0x10 */
    volatile uint32_t IE;    /*!< CCU Interrupt Enable register,                Address offset: 0x14 */
} FDCAN_ClockCalibrationUnit_TypeDef;

/**
  * @brief Consumer Electronics Control
  */
typedef struct
{
    volatile uint32_t CR;           /*!< CEC control register,              Address offset:0x00 */
    volatile uint32_t CFGR;         /*!< CEC configuration register,        Address offset:0x04 */
    volatile uint32_t TXDR;         /*!< CEC Tx data register ,             Address offset:0x08 */
    volatile uint32_t RXDR;         /*!< CEC Rx Data Register,              Address offset:0x0C */
    volatile uint32_t ISR;          /*!< CEC Interrupt and Status Register, Address offset:0x10 */
    volatile uint32_t IER;          /*!< CEC interrupt enable register,     Address offset:0x14 */
}CEC_TypeDef;

/**
  * @brief CRC calculation unit
  */
typedef struct
{
    volatile uint32_t DR;          /*!< CRC Data register,                           Address offset: 0x00 */
    volatile uint32_t IDR;         /*!< CRC Independent data register,               Address offset: 0x04 */
    volatile uint32_t CR;          /*!< CRC Control register,                        Address offset: 0x08 */
             uint32_t RESERVED2;   /*!< Reserved,                                                    0x0C */
    volatile uint32_t INIT;        /*!< Initial CRC value register,                  Address offset: 0x10 */
    volatile uint32_t POL;         /*!< CRC polynomial register,                     Address offset: 0x14 */
} CRC_TypeDef;

/**
  * @brief Clock Recovery System
  */
typedef struct
{
    volatile uint32_t CR;            /*!< CRS ccontrol register,              Address offset: 0x00 */
    volatile uint32_t CFGR;          /*!< CRS configuration register,         Address offset: 0x04 */
    volatile uint32_t ISR;           /*!< CRS interrupt and status register,  Address offset: 0x08 */
    volatile uint32_t ICR;           /*!< CRS interrupt flag clear register,  Address offset: 0x0C */
} CRS_TypeDef;

/**
  * @brief Digital to Analog Converter
  */
typedef struct
{
    volatile uint32_t CR;       /*!< DAC control register,                                    Address offset: 0x00 */
    volatile uint32_t SWTRIGR;  /*!< DAC software trigger register,                           Address offset: 0x04 */
    volatile uint32_t DHR12R1;  /*!< DAC channel1 12-bit right-aligned data holding register, Address offset: 0x08 */
    volatile uint32_t DHR12L1;  /*!< DAC channel1 12-bit left aligned data holding register,  Address offset: 0x0C */
    volatile uint32_t DHR8R1;   /*!< DAC channel1 8-bit right aligned data holding register,  Address offset: 0x10 */
    volatile uint32_t DHR12R2;  /*!< DAC channel2 12-bit right aligned data holding register, Address offset: 0x14 */
    volatile uint32_t DHR12L2;  /*!< DAC channel2 12-bit left aligned data holding register,  Address offset: 0x18 */
    volatile uint32_t DHR8R2;   /*!< DAC channel2 8-bit right-aligned data holding register,  Address offset: 0x1C */
    volatile uint32_t DHR12RD;  /*!< Dual DAC 12-bit right-aligned data holding register,     Address offset: 0x20 */
    volatile uint32_t DHR12LD;  /*!< DUAL DAC 12-bit left aligned data holding register,      Address offset: 0x24 */
    volatile uint32_t DHR8RD;   /*!< DUAL DAC 8-bit right aligned data holding register,      Address offset: 0x28 */
    volatile uint32_t DOR1;     /*!< DAC channel1 data output register,                       Address offset: 0x2C */
    volatile uint32_t DOR2;     /*!< DAC channel2 data output register,                       Address offset: 0x30 */
    volatile uint32_t SR;       /*!< DAC status register,                                     Address offset: 0x34 */
    volatile uint32_t CCR;      /*!< DAC calibration control register,                        Address offset: 0x38 */
    volatile uint32_t MCR;      /*!< DAC mode control register,                               Address offset: 0x3C */
    volatile uint32_t SHSR1;    /*!< DAC Sample and Hold sample time register 1,              Address offset: 0x40 */
    volatile uint32_t SHSR2;    /*!< DAC Sample and Hold sample time register 2,              Address offset: 0x44 */
    volatile uint32_t SHHR;     /*!< DAC Sample and Hold hold time register,                  Address offset: 0x48 */
    volatile uint32_t SHRR;     /*!< DAC Sample and Hold refresh time register,               Address offset: 0x4C */
} DAC_TypeDef;

/**
  * @brief DFSDM module registers
  */
typedef struct
{
    volatile uint32_t FLTCR1;          /*!< DFSDM control register1,                          Address offset: 0x100 */
    volatile uint32_t FLTCR2;          /*!< DFSDM control register2,                          Address offset: 0x104 */
    volatile uint32_t FLTISR;          /*!< DFSDM interrupt and status register,              Address offset: 0x108 */
    volatile uint32_t FLTICR;          /*!< DFSDM interrupt flag clear register,              Address offset: 0x10C */
    volatile uint32_t FLTJCHGR;        /*!< DFSDM injected channel group selection register,  Address offset: 0x110 */
    volatile uint32_t FLTFCR;          /*!< DFSDM filter control register,                    Address offset: 0x114 */
    volatile uint32_t FLTJDATAR;       /*!< DFSDM data register for injected group,           Address offset: 0x118 */
    volatile uint32_t FLTRDATAR;       /*!< DFSDM data register for regular group,            Address offset: 0x11C */
    volatile uint32_t FLTAWHTR;        /*!< DFSDM analog watchdog high threshold register,    Address offset: 0x120 */
    volatile uint32_t FLTAWLTR;        /*!< DFSDM analog watchdog low threshold register,     Address offset: 0x124 */
    volatile uint32_t FLTAWSR;         /*!< DFSDM analog watchdog status register             Address offset: 0x128 */
    volatile uint32_t FLTAWCFR;        /*!< DFSDM analog watchdog clear flag register         Address offset: 0x12C */
    volatile uint32_t FLTEXMAX;        /*!< DFSDM extreme detector maximum register,          Address offset: 0x130 */
    volatile uint32_t FLTEXMIN;        /*!< DFSDM extreme detector minimum register           Address offset: 0x134 */
    volatile uint32_t FLTCNVTIMR;      /*!< DFSDM conversion timer,                           Address offset: 0x138 */
} DFSDM_Filter_TypeDef;

/**
  * @brief DFSDM channel configuration registers
  */
typedef struct
{
    volatile uint32_t CHCFGR1;      /*!< DFSDM channel configuration register1,            Address offset: 0x00 */
    volatile uint32_t CHCFGR2;      /*!< DFSDM channel configuration register2,            Address offset: 0x04 */
    volatile uint32_t CHAWSCDR;     /*!< DFSDM channel analog watchdog and
                                         short circuit detector register,                  Address offset: 0x08 */
    volatile uint32_t CHWDATAR;     /*!< DFSDM channel watchdog filter data register,      Address offset: 0x0C */
    volatile uint32_t CHDATINR;     /*!< DFSDM channel data input register,                Address offset: 0x10 */
} DFSDM_Channel_TypeDef;

/**
  * @brief Debug MCU
  */
typedef struct
{
    volatile uint32_t IDCODE;           /*!< MCU device ID code,                     Address offset: 0x00 */
    volatile uint32_t CR;               /*!< Debug MCU configuration register,       Address offset: 0x04 */
    volatile uint32_t  RESERVED4[11];   /*!< Reserved,                               Address offset: 0x08 */
    volatile uint32_t APB3FZ1;          /*!< Debug MCU APB3FZ1 freeze register,      Address offset: 0x34 */
    volatile uint32_t APB3FZ2;          /*!< Debug MCU APB3FZ2 freeze register,      Address offset: 0x38 */
    volatile uint32_t APB1LFZ1;         /*!< Debug MCU APB1LFZ1 freeze register,     Address offset: 0x3C */
    volatile uint32_t APB1LFZ2;         /*!< Debug MCU APB1LFZ2 freeze register,     Address offset: 0x40 */
    volatile uint32_t APB1HFZ1;         /*!< Debug MCU APB1LFZ1 freeze register,     Address offset: 0x44 */
    volatile uint32_t APB1HFZ2;         /*!< Debug MCU APB1LFZ2 freeze register,     Address offset: 0x48 */
    volatile uint32_t APB2FZ1;          /*!< Debug MCU APB2FZ1 freeze register,      Address offset: 0x4C */
    volatile uint32_t APB2FZ2;          /*!< Debug MCU APB2FZ2 freeze register,      Address offset: 0x50 */
    volatile uint32_t APB4FZ1;          /*!< Debug MCU APB4FZ1 freeze register,      Address offset: 0x54 */
    volatile uint32_t APB4FZ2;          /*!< Debug MCU APB4FZ2 freeze register,      Address offset: 0x58 */
}DBGMCU_TypeDef;

/**
  * @brief DCMI
  */
typedef struct
{
    volatile uint32_t CR;       /*!< DCMI control register 1,                       Address offset: 0x00 */
    volatile uint32_t SR;       /*!< DCMI status register,                          Address offset: 0x04 */
    volatile uint32_t RISR;     /*!< DCMI raw interrupt status register,            Address offset: 0x08 */
    volatile uint32_t IER;      /*!< DCMI interrupt enable register,                Address offset: 0x0C */
    volatile uint32_t MISR;     /*!< DCMI masked interrupt status register,         Address offset: 0x10 */
    volatile uint32_t ICR;      /*!< DCMI interrupt clear register,                 Address offset: 0x14 */
    volatile uint32_t ESCR;     /*!< DCMI embedded synchronization code register,   Address offset: 0x18 */
    volatile uint32_t ESUR;     /*!< DCMI embedded synchronization unmask register, Address offset: 0x1C */
    volatile uint32_t CWSTRTR;  /*!< DCMI crop window start,                        Address offset: 0x20 */
    volatile uint32_t CWSIZER;  /*!< DCMI crop window size,                         Address offset: 0x24 */
    volatile uint32_t DR;       /*!< DCMI data register,                            Address offset: 0x28 */
} DCMI_TypeDef;

/**
  * @brief DMA Controller
  */
typedef struct
{
    volatile uint32_t CR;     /*!< DMA stream x configuration register      */
    volatile uint32_t NDTR;   /*!< DMA stream x number of data register     */
    volatile uint32_t PAR;    /*!< DMA stream x peripheral address register */
    volatile uint32_t M0AR;   /*!< DMA stream x memory 0 address register   */
    volatile uint32_t M1AR;   /*!< DMA stream x memory 1 address register   */
    volatile uint32_t FCR;    /*!< DMA stream x FIFO control register       */
} DMA_Stream_TypeDef;

typedef struct
{
    volatile uint32_t LISR;   /*!< DMA low interrupt status register,      Address offset: 0x00 */
    volatile uint32_t HISR;   /*!< DMA high interrupt status register,     Address offset: 0x04 */
    volatile uint32_t LIFCR;  /*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
    volatile uint32_t HIFCR;  /*!< DMA high interrupt flag clear register, Address offset: 0x0C */
} DMA_TypeDef;

typedef struct
{
    volatile uint32_t CCR;          /*!< DMA channel x configuration register          */
    volatile uint32_t CNDTR;        /*!< DMA channel x number of data register         */
    volatile uint32_t CPAR;         /*!< DMA channel x peripheral address register     */
    volatile uint32_t CM0AR;        /*!< DMA channel x memory 0 address register       */
    volatile uint32_t CM1AR;        /*!< DMA channel x memory 1 address register       */
} BDMA_Channel_TypeDef;

typedef struct
{
    volatile uint32_t ISR;          /*!< DMA interrupt status register,               Address offset: 0x00 */
    volatile uint32_t IFCR;         /*!< DMA interrupt flag clear register,           Address offset: 0x04 */
} BDMA_TypeDef;

typedef struct
{
    volatile uint32_t  CCR;        /*!< DMA Multiplexer Channel x Control Register   */
}DMAMUX_Channel_TypeDef;

typedef struct
{
    volatile uint32_t  CSR;      /*!< DMA Channel Status Register     */
    volatile uint32_t  CFR;      /*!< DMA Channel Clear Flag Register */
}DMAMUX_ChannelStatus_TypeDef;

typedef struct
{
    volatile uint32_t  RGCR;        /*!< DMA Request Generator x Control Register   */
}DMAMUX_RequestGen_TypeDef;

typedef struct
{
    volatile uint32_t  RGSR;        /*!< DMA Request Generator Status Register       */
    volatile uint32_t  RGCFR;       /*!< DMA Request Generator Clear Flag Register   */
}DMAMUX_RequestGenStatus_TypeDef;

/**
  * @brief MDMA Controller
  */
typedef struct
{
    volatile uint32_t  GISR0;   /*!< MDMA Global Interrupt/Status Register 0,          Address offset: 0x00 */
}MDMA_TypeDef;

typedef struct
{
    volatile uint32_t  CISR;      /*!< MDMA channel x interrupt/status register,             Address offset: 0x40 */
    volatile uint32_t  CIFCR;     /*!< MDMA channel x interrupt flag clear register,         Address offset: 0x44 */
    volatile uint32_t  CESR;      /*!< MDMA Channel x error status register,                 Address offset: 0x48 */
    volatile uint32_t  CCR;       /*!< MDMA channel x control register,                      Address offset: 0x4C */
    volatile uint32_t  CTCR;      /*!< MDMA channel x Transfer Configuration register,       Address offset: 0x50 */
    volatile uint32_t  CBNDTR;    /*!< MDMA Channel x block number of data register,         Address offset: 0x54 */
    volatile uint32_t  CSAR;      /*!< MDMA channel x source address register,               Address offset: 0x58 */
    volatile uint32_t  CDAR;      /*!< MDMA channel x destination address register,          Address offset: 0x5C */
    volatile uint32_t  CBRUR;     /*!< MDMA channel x Block Repeat address Update register,  Address offset: 0x60 */
    volatile uint32_t  CLAR;      /*!< MDMA channel x Link Address register,                 Address offset: 0x64 */
    volatile uint32_t  CTBR;      /*!< MDMA channel x Trigger and Bus selection Register,    Address offset: 0x68 */
             uint32_t  RESERVED0; /*!< Reserved, 0x6C                                                             */
    volatile uint32_t  CMAR;      /*!< MDMA channel x Mask address register,                 Address offset: 0x70 */
    volatile uint32_t  CMDR;      /*!< MDMA channel x Mask Data register,                    Address offset: 0x74 */
}MDMA_Channel_TypeDef;

/**
  * @brief DMA2D Controller
  */
typedef struct
{
    volatile uint32_t CR;            /*!< DMA2D Control Register,                         Address offset: 0x00 */
    volatile uint32_t ISR;           /*!< DMA2D Interrupt Status Register,                Address offset: 0x04 */
    volatile uint32_t IFCR;          /*!< DMA2D Interrupt Flag Clear Register,            Address offset: 0x08 */
    volatile uint32_t FGMAR;         /*!< DMA2D Foreground Memory Address Register,       Address offset: 0x0C */
    volatile uint32_t FGOR;          /*!< DMA2D Foreground Offset Register,               Address offset: 0x10 */
    volatile uint32_t BGMAR;         /*!< DMA2D Background Memory Address Register,       Address offset: 0x14 */
    volatile uint32_t BGOR;          /*!< DMA2D Background Offset Register,               Address offset: 0x18 */
    volatile uint32_t FGPFCCR;       /*!< DMA2D Foreground PFC Control Register,          Address offset: 0x1C */
    volatile uint32_t FGCOLR;        /*!< DMA2D Foreground Color Register,                Address offset: 0x20 */
    volatile uint32_t BGPFCCR;       /*!< DMA2D Background PFC Control Register,          Address offset: 0x24 */
    volatile uint32_t BGCOLR;        /*!< DMA2D Background Color Register,                Address offset: 0x28 */
    volatile uint32_t FGCMAR;        /*!< DMA2D Foreground CLUT Memory Address Register,  Address offset: 0x2C */
    volatile uint32_t BGCMAR;        /*!< DMA2D Background CLUT Memory Address Register,  Address offset: 0x30 */
    volatile uint32_t OPFCCR;        /*!< DMA2D Output PFC Control Register,              Address offset: 0x34 */
    volatile uint32_t OCOLR;         /*!< DMA2D Output Color Register,                    Address offset: 0x38 */
    volatile uint32_t OMAR;          /*!< DMA2D Output Memory Address Register,           Address offset: 0x3C */
    volatile uint32_t OOR;           /*!< DMA2D Output Offset Register,                   Address offset: 0x40 */
    volatile uint32_t NLR;           /*!< DMA2D Number of Line Register,                  Address offset: 0x44 */
    volatile uint32_t LWR;           /*!< DMA2D Line Watermark Register,                  Address offset: 0x48 */
    volatile uint32_t AMTCR;         /*!< DMA2D AHB Master Timer Configuration Register,  Address offset: 0x4C */
             uint32_t RESERVED[236]; /*!< Reserved, 0x50-0x3FF */
    volatile uint32_t FGCLUT[256];   /*!< DMA2D Foreground CLUT,                          Address offset:400-7FF */
    volatile uint32_t BGCLUT[256];   /*!< DMA2D Background CLUT,                          Address offset:800-BFF */
} DMA2D_TypeDef;

/**
  * @brief DSI Controller
  */
typedef struct
{
    volatile uint32_t VR;            /*!< DSI Host Version Register,                                 Address offset: 0x00      */
    volatile uint32_t CR;            /*!< DSI Host Control Register,                                 Address offset: 0x04      */
    volatile uint32_t CCR;           /*!< DSI HOST Clock Control Register,                           Address offset: 0x08      */
    volatile uint32_t LVCIDR;        /*!< DSI Host LTDC VCID Register,                               Address offset: 0x0C      */
    volatile uint32_t LCOLCR;        /*!< DSI Host LTDC Color Coding Register,                       Address offset: 0x10      */
    volatile uint32_t LPCR;          /*!< DSI Host LTDC Polarity Configuration Register,             Address offset: 0x14      */
    volatile uint32_t LPMCR;         /*!< DSI Host Low-Power Mode Configuration Register,            Address offset: 0x18      */
             uint32_t RESERVED0[4];  /*!< Reserved, 0x1C - 0x2B                                                                */
    volatile uint32_t PCR;           /*!< DSI Host Protocol Configuration Register,                  Address offset: 0x2C      */
    volatile uint32_t GVCIDR;        /*!< DSI Host Generic VCID Register,                            Address offset: 0x30      */
    volatile uint32_t MCR;           /*!< DSI Host Mode Configuration Register,                      Address offset: 0x34      */
    volatile uint32_t VMCR;          /*!< DSI Host Video Mode Configuration Register,                Address offset: 0x38      */
    volatile uint32_t VPCR;          /*!< DSI Host Video Packet Configuration Register,              Address offset: 0x3C      */
    volatile uint32_t VCCR;          /*!< DSI Host Video Chunks Configuration Register,              Address offset: 0x40      */
    volatile uint32_t VNPCR;         /*!< DSI Host Video Null Packet Configuration Register,         Address offset: 0x44      */
    volatile uint32_t VHSACR;        /*!< DSI Host Video HSA Configuration Register,                 Address offset: 0x48      */
    volatile uint32_t VHBPCR;        /*!< DSI Host Video HBP Configuration Register,                 Address offset: 0x4C      */
    volatile uint32_t VLCR;          /*!< DSI Host Video Line Configuration Register,                Address offset: 0x50      */
    volatile uint32_t VVSACR;        /*!< DSI Host Video VSA Configuration Register,                 Address offset: 0x54      */
    volatile uint32_t VVBPCR;        /*!< DSI Host Video VBP Configuration Register,                 Address offset: 0x58      */
    volatile uint32_t VVFPCR;        /*!< DSI Host Video VFP Configuration Register,                 Address offset: 0x5C      */
    volatile uint32_t VVACR;         /*!< DSI Host Video VA Configuration Register,                  Address offset: 0x60      */
    volatile uint32_t LCCR;          /*!< DSI Host LTDC Command Configuration Register,              Address offset: 0x64      */
    volatile uint32_t CMCR;          /*!< DSI Host Command Mode Configuration Register,              Address offset: 0x68      */
    volatile uint32_t GHCR;          /*!< DSI Host Generic Header Configuration Register,            Address offset: 0x6C      */
    volatile uint32_t GPDR;          /*!< DSI Host Generic Payload Data Register,                    Address offset: 0x70      */
    volatile uint32_t GPSR;          /*!< DSI Host Generic Packet Status Register,                   Address offset: 0x74      */
    volatile uint32_t TCCR[6];       /*!< DSI Host Timeout Counter Configuration Register,           Address offset: 0x78-0x8F */
    volatile uint32_t TDCR;          /*!< DSI Host 3D Configuration Register,                        Address offset: 0x90      */
    volatile uint32_t CLCR;          /*!< DSI Host Clock Lane Configuration Register,                Address offset: 0x94      */
    volatile uint32_t CLTCR;         /*!< DSI Host Clock Lane Timer Configuration Register,          Address offset: 0x98      */
    volatile uint32_t DLTCR;         /*!< DSI Host Data Lane Timer Configuration Register,           Address offset: 0x9C      */
    volatile uint32_t PCTLR;         /*!< DSI Host PHY Control Register,                             Address offset: 0xA0      */
    volatile uint32_t PCONFR;        /*!< DSI Host PHY Configuration Register,                       Address offset: 0xA4      */
    volatile uint32_t PUCR;          /*!< DSI Host PHY ULPS Control Register,                        Address offset: 0xA8      */
    volatile uint32_t PTTCR;         /*!< DSI Host PHY TX Triggers Configuration Register,           Address offset: 0xAC      */
    volatile uint32_t PSR;           /*!< DSI Host PHY Status Register,                              Address offset: 0xB0      */
             uint32_t RESERVED1[2];  /*!< Reserved, 0xB4 - 0xBB                                                                */
    volatile uint32_t ISR[2];        /*!< DSI Host Interrupt & Status Register,                      Address offset: 0xBC-0xC3 */
    volatile uint32_t IER[2];        /*!< DSI Host Interrupt Enable Register,                        Address offset: 0xC4-0xCB */
             uint32_t RESERVED2[3];  /*!< Reserved, 0xD0 - 0xD7                                                                */
    volatile uint32_t FIR[2];        /*!< DSI Host Force Interrupt Register,                         Address offset: 0xD8-0xDF */
             uint32_t RESERVED3[8];  /*!< Reserved, 0xE0 - 0xFF                                                                */
    volatile uint32_t VSCR;          /*!< DSI Host Video Shadow Control Register,                    Address offset: 0x100     */
             uint32_t RESERVED4[2];  /*!< Reserved, 0x104 - 0x10B                                                              */
    volatile uint32_t LCVCIDR;       /*!< DSI Host LTDC Current VCID Register,                       Address offset: 0x10C     */
    volatile uint32_t LCCCR;         /*!< DSI Host LTDC Current Color Coding Register,               Address offset: 0x110     */
             uint32_t RESERVED5;     /*!< Reserved, 0x114                                                                      */
    volatile uint32_t LPMCCR;        /*!< DSI Host Low-power Mode Current Configuration Register,    Address offset: 0x118     */
             uint32_t RESERVED6[7];  /*!< Reserved, 0x11C - 0x137                                                              */
    volatile uint32_t VMCCR;         /*!< DSI Host Video Mode Current Configuration Register,        Address offset: 0x138     */
    volatile uint32_t VPCCR;         /*!< DSI Host Video Packet Current Configuration Register,      Address offset: 0x13C     */
    volatile uint32_t VCCCR;         /*!< DSI Host Video Chunks Current Configuration Register,     Address offset: 0x140     */
    volatile uint32_t VNPCCR;        /*!< DSI Host Video Null Packet Current Configuration Register, Address offset: 0x144     */
    volatile uint32_t VHSACCR;       /*!< DSI Host Video HSA Current Configuration Register,         Address offset: 0x148     */
    volatile uint32_t VHBPCCR;       /*!< DSI Host Video HBP Current Configuration Register,         Address offset: 0x14C     */
    volatile uint32_t VLCCR;         /*!< DSI Host Video Line Current Configuration Register,        Address offset: 0x150     */
    volatile uint32_t VVSACCR;       /*!< DSI Host Video VSA Current Configuration Register,         Address offset: 0x154     */
    volatile uint32_t VVBPCCR;       /*!< DSI Host Video VBP Current Configuration Register,         Address offset: 0x158     */
    volatile uint32_t VVFPCCR;       /*!< DSI Host Video VFP Current Configuration Register,         Address offset: 0x15C     */
    volatile uint32_t VVACCR;        /*!< DSI Host Video VA Current Configuration Register,          Address offset: 0x160     */
             uint32_t RESERVED7[11]; /*!< Reserved, 0x164 - 0x18F                                                              */
    volatile uint32_t TDCCR;         /*!< DSI Host 3D Current Configuration Register,                Address offset: 0x190     */
             uint32_t RESERVED8[155]; /*!< Reserved, 0x194 - 0x3FF                                                                */
    volatile uint32_t WCFGR;          /*!< DSI Wrapper Configuration Register,                        Address offset: 0x400       */
    volatile uint32_t WCR;            /*!< DSI Wrapper Control Register,                              Address offset: 0x404       */
    volatile uint32_t WIER;           /*!< DSI Wrapper Interrupt Enable Register,                     Address offset: 0x408       */
    volatile uint32_t WISR;           /*!< DSI Wrapper Interrupt and Status Register,                 Address offset: 0x40C       */
    volatile uint32_t WIFCR;          /*!< DSI Wrapper Interrupt Flag Clear Register,                 Address offset: 0x410       */
             uint32_t RESERVED9;      /*!< Reserved, 0x414                                                                        */
    volatile uint32_t WPCR[5];        /*!< DSI Wrapper PHY Configuration Register,                    Address offset: 0x418-0x42B */
             uint32_t RESERVED10;     /*!< Reserved, 0x42C                                                                        */
    volatile uint32_t WRPCR;          /*!< DSI Wrapper Regulator and PLL Control Register, Address offset: 0x430                  */
} DSI_TypeDef;

/**
  * @brief Ethernet MAC
  */
typedef struct
{
    volatile uint32_t MACCR;
    volatile uint32_t MACECR;
    volatile uint32_t MACPFR;
    volatile uint32_t MACWTR;
    volatile uint32_t MACHT0R;
    volatile uint32_t MACHT1R;
             uint32_t RESERVED1[14];
    volatile uint32_t MACVTR;
             uint32_t RESERVED2;
    volatile uint32_t MACVHTR;
             uint32_t RESERVED3;
    volatile uint32_t MACVIR;
    volatile uint32_t MACIVIR;
             uint32_t RESERVED4[2];
    volatile uint32_t MACTFCR;
             uint32_t RESERVED5[7];
    volatile uint32_t MACRFCR;
             uint32_t RESERVED6[7];
    volatile uint32_t MACISR;
    volatile uint32_t MACIER;
    volatile uint32_t MACRXTXSR;
             uint32_t RESERVED7;
    volatile uint32_t MACPCSR;
    volatile uint32_t MACRWKPFR;
             uint32_t RESERVED8[2];
    volatile uint32_t MACLCSR;
    volatile uint32_t MACLTCR;
    volatile uint32_t MACLETR;
    volatile uint32_t MAC1USTCR;
             uint32_t RESERVED9[12];
    volatile uint32_t MACVR;
    volatile uint32_t MACDR;
             uint32_t RESERVED10;
    volatile uint32_t MACHWF0R;
    volatile uint32_t MACHWF1R;
    volatile uint32_t MACHWF2R;
             uint32_t RESERVED11[54];
    volatile uint32_t MACMDIOAR;
    volatile uint32_t MACMDIODR;
             uint32_t RESERVED12[2];
    volatile uint32_t MACARPAR;
             uint32_t RESERVED13[59];
    volatile uint32_t MACA0HR;
    volatile uint32_t MACA0LR;
    volatile uint32_t MACA1HR;
    volatile uint32_t MACA1LR;
    volatile uint32_t MACA2HR;
    volatile uint32_t MACA2LR;
    volatile uint32_t MACA3HR;
    volatile uint32_t MACA3LR;
             uint32_t RESERVED14[248];
    volatile uint32_t MMCCR;
    volatile uint32_t MMCRIR;
    volatile uint32_t MMCTIR;
    volatile uint32_t MMCRIMR;
    volatile uint32_t MMCTIMR;
             uint32_t RESERVED15[14];
    volatile uint32_t MMCTSCGPR;
    volatile uint32_t MMCTMCGPR;
             uint32_t RESERVED16[5];
    volatile uint32_t MMCTPCGR;
             uint32_t RESERVED17[10];
    volatile uint32_t MMCRCRCEPR;
    volatile uint32_t MMCRAEPR;
             uint32_t RESERVED18[10];
    volatile uint32_t MMCRUPGR;
             uint32_t RESERVED19[9];
    volatile uint32_t MMCTLPIMSTR;
    volatile uint32_t MMCTLPITCR;
    volatile uint32_t MMCRLPIMSTR;
    volatile uint32_t MMCRLPITCR;
             uint32_t RESERVED20[65];
    volatile uint32_t MACL3L4C0R;
    volatile uint32_t MACL4A0R;
             uint32_t RESERVED21[2];
    volatile uint32_t MACL3A0R0R;
    volatile uint32_t MACL3A1R0R;
    volatile uint32_t MACL3A2R0R;
    volatile uint32_t MACL3A3R0R;
             uint32_t RESERVED22[4];
    volatile uint32_t MACL3L4C1R;
    volatile uint32_t MACL4A1R;
             uint32_t RESERVED23[2];
    volatile uint32_t MACL3A0R1R;
    volatile uint32_t MACL3A1R1R;
    volatile uint32_t MACL3A2R1R;
    volatile uint32_t MACL3A3R1R;
             uint32_t RESERVED24[108];
    volatile uint32_t MACTSCR;
    volatile uint32_t MACSSIR;
    volatile uint32_t MACSTSR;
    volatile uint32_t MACSTNR;
    volatile uint32_t MACSTSUR;
    volatile uint32_t MACSTNUR;
    volatile uint32_t MACTSAR;
             uint32_t RESERVED25;
    volatile uint32_t MACTSSR;
             uint32_t RESERVED26[3];
    volatile uint32_t MACTTSSNR;
    volatile uint32_t MACTTSSSR;
             uint32_t RESERVED27[2];
    volatile uint32_t MACACR;
             uint32_t RESERVED28;
    volatile uint32_t MACATSNR;
    volatile uint32_t MACATSSR;
    volatile uint32_t MACTSIACR;
    volatile uint32_t MACTSEACR;
    volatile uint32_t MACTSICNR;
    volatile uint32_t MACTSECNR;
             uint32_t RESERVED29[4];
    volatile uint32_t MACPPSCR;
             uint32_t RESERVED30[3];
    volatile uint32_t MACPPSTTSR;
    volatile uint32_t MACPPSTTNR;
    volatile uint32_t MACPPSIR;
    volatile uint32_t MACPPSWR;
             uint32_t RESERVED31[12];
    volatile uint32_t MACPOCR;
    volatile uint32_t MACSPI0R;
    volatile uint32_t MACSPI1R;
    volatile uint32_t MACSPI2R;
    volatile uint32_t MACLMIR;
             uint32_t RESERVED32[11];
    volatile uint32_t MTLOMR;
             uint32_t RESERVED33[7];
    volatile uint32_t MTLISR;
             uint32_t RESERVED34[55];
    volatile uint32_t MTLTQOMR;
    volatile uint32_t MTLTQUR;
    volatile uint32_t MTLTQDR;
             uint32_t RESERVED35[8];
    volatile uint32_t MTLQICSR;
    volatile uint32_t MTLRQOMR;
    volatile uint32_t MTLRQMPOCR;
    volatile uint32_t MTLRQDR;
             uint32_t RESERVED36[177];
    volatile uint32_t DMAMR;
    volatile uint32_t DMASBMR;
    volatile uint32_t DMAISR;
    volatile uint32_t DMADSR;
             uint32_t RESERVED37[60];
    volatile uint32_t DMACCR;
    volatile uint32_t DMACTCR;
    volatile uint32_t DMACRCR;
             uint32_t RESERVED38[2];
    volatile uint32_t DMACTDLAR;
             uint32_t RESERVED39;
    volatile uint32_t DMACRDLAR;
    volatile uint32_t DMACTDTPR;
             uint32_t RESERVED40;
    volatile uint32_t DMACRDTPR;
    volatile uint32_t DMACTDRLR;
    volatile uint32_t DMACRDRLR;
    volatile uint32_t DMACIER;
    volatile uint32_t DMACRIWTR;
    volatile uint32_t DMACSFCSR;
             uint32_t RESERVED41;
    volatile uint32_t DMACCATDR;
             uint32_t RESERVED42;
    volatile uint32_t DMACCARDR;
             uint32_t RESERVED43;
    volatile uint32_t DMACCATBR;
             uint32_t RESERVED44;
    volatile uint32_t DMACCARBR;
    volatile uint32_t DMACSR;
             uint32_t RESERVED45[2];
    volatile uint32_t DMACMFCR;
}ETH_TypeDef;

/**
  * @brief External Interrupt/Event Controller
  */
typedef struct
{
    volatile uint32_t RTSR1;               /*!< EXTI Rising trigger selection register,          Address offset: 0x00 */
    volatile uint32_t FTSR1;               /*!< EXTI Falling trigger selection register,         Address offset: 0x04 */
    volatile uint32_t SWIER1;              /*!< EXTI Software interrupt event register,          Address offset: 0x08 */
    volatile uint32_t D3PMR1;              /*!< EXTI D3 Pending mask register, (same register as to SRDPMR1) Address offset: 0x0C */
    volatile uint32_t D3PCR1L;             /*!< EXTI D3 Pending clear selection register low, (same register as to SRDPCR1L)     Address offset: 0x10 */
    volatile uint32_t D3PCR1H;             /*!< EXTI D3 Pending clear selection register High, (same register as to SRDPCR1H)   Address offset: 0x14 */
             uint32_t RESERVED1[2];        /*!< Reserved,                                        0x18 to 0x1C         */
    volatile uint32_t RTSR2;               /*!< EXTI Rising trigger selection register,          Address offset: 0x20 */
    volatile uint32_t FTSR2;               /*!< EXTI Falling trigger selection register,         Address offset: 0x24 */
    volatile uint32_t SWIER2;              /*!< EXTI Software interrupt event register,          Address offset: 0x28 */
    volatile uint32_t D3PMR2;              /*!< EXTI D3 Pending mask register, (same register as to SRDPMR2) Address offset: 0x2C */
    volatile uint32_t D3PCR2L;             /*!< EXTI D3 Pending clear selection register low, (same register as to SRDPCR2L)  Address offset: 0x30 */
    volatile uint32_t D3PCR2H;             /*!< EXTI D3 Pending clear selection register High, (same register as to SRDPCR2H) Address offset: 0x34 */
             uint32_t RESERVED2[2];        /*!< Reserved,                                        0x38 to 0x3C         */
    volatile uint32_t RTSR3;               /*!< EXTI Rising trigger selection register,          Address offset: 0x40 */
    volatile uint32_t FTSR3;               /*!< EXTI Falling trigger selection register,         Address offset: 0x44 */
    volatile uint32_t SWIER3;              /*!< EXTI Software interrupt event register,          Address offset: 0x48 */
    volatile uint32_t D3PMR3;              /*!< EXTI D3 Pending mask register, (same register as to SRDPMR3) Address offset: 0x4C */
    volatile uint32_t D3PCR3L;             /*!< EXTI D3 Pending clear selection register low, (same register as to SRDPCR3L) Address offset: 0x50 */
    volatile uint32_t D3PCR3H;             /*!< EXTI D3 Pending clear selection register High, (same register as to SRDPCR3H) Address offset: 0x54 */
             uint32_t RESERVED3[10];       /*!< Reserved,                                        0x58 to 0x7C         */
    volatile uint32_t IMR1;                /*!< EXTI Interrupt mask register,                    Address offset: 0x80 */
    volatile uint32_t EMR1;                /*!< EXTI Event mask register,                        Address offset: 0x84 */
    volatile uint32_t PR1;                 /*!< EXTI Pending register,                           Address offset: 0x88 */
             uint32_t RESERVED4;           /*!< Reserved,                                        0x8C                 */
    volatile uint32_t IMR2;                /*!< EXTI Interrupt mask register,                    Address offset: 0x90 */
    volatile uint32_t EMR2;                /*!< EXTI Event mask register,                        Address offset: 0x94 */
    volatile uint32_t PR2;                 /*!< EXTI Pending register,                           Address offset: 0x98 */
             uint32_t RESERVED5;           /*!< Reserved,                                        0x9C                 */
    volatile uint32_t IMR3;                /*!< EXTI Interrupt mask register,                    Address offset: 0xA0 */
    volatile uint32_t EMR3;                /*!< EXTI Event mask register,                        Address offset: 0xA4 */
    volatile uint32_t PR3;                 /*!< EXTI Pending register,                           Address offset: 0xA8 */
             uint32_t RESERVED6[5];        /*!< Reserved,                                        0xAC to 0xBC         */
    volatile uint32_t C2IMR1;              /*!< EXTI Interrupt mask register,                    Address offset: 0xC0 */
    volatile uint32_t C2EMR1;              /*!< EXTI Event mask register,                        Address offset: 0xC4 */
    volatile uint32_t C2PR1;               /*!< EXTI Pending register,                           Address offset: 0xC8 */
             uint32_t RESERVED7;           /*!< Reserved,                                        0xCC                 */
    volatile uint32_t C2IMR2;              /*!< EXTI Interrupt mask register,                    Address offset: 0xD0 */
    volatile uint32_t C2EMR2;              /*!< EXTI Event mask register,                        Address offset: 0xD4 */
    volatile uint32_t C2PR2;               /*!< EXTI Pending register,                           Address offset: 0xD8 */
             uint32_t RESERVED8;           /*!< Reserved,                                        0xDC                 */
    volatile uint32_t C2IMR3;              /*!< EXTI Interrupt mask register,                    Address offset: 0xE0 */
    volatile uint32_t C2EMR3;              /*!< EXTI Event mask register,                        Address offset: 0xE4 */
    volatile uint32_t C2PR3;               /*!< EXTI Pending register,                           Address offset: 0xE8 */
}EXTI_TypeDef;

/**
  * @brief This structure registers corresponds to EXTI_Typdef CPU1/CPU2 registers subset (IMRx, EMRx and PRx),
  *        allowing to define EXTI_D1/EXTI_D2 with rapid/common access to these IMRx, EMRx, PRx registers for CPU1 and CPU2.
  *        Note that EXTI_D1 and EXTI_D2 bases addresses are calculated to point to CPUx first register:
  *           - IMR1   in case of EXTI_D1 that is addressing CPU1 (Cortex-M7)
  *           - C2IMR1 in case of EXTI_D2 that is addressing CPU2 (Cortex-M4)
  *        Note: EXTI_D2 and corresponding C2IMRx, C2EMRx and C2PRx registers are available for Dual Core devices only
  */
typedef struct
{
    volatile uint32_t IMR1;                /*!< EXTI Interrupt mask register,                Address offset: 0x00 */
    volatile uint32_t EMR1;                /*!< EXTI Event mask register,                    Address offset: 0x04 */
    volatile uint32_t PR1;                 /*!< EXTI Pending register,                       Address offset: 0x08 */
             uint32_t RESERVED1;           /*!< Reserved, 0x0C                                                    */
    volatile uint32_t IMR2;                /*!< EXTI Interrupt mask register,                Address offset: 0x10 */
    volatile uint32_t EMR2;                /*!< EXTI Event mask register,                    Address offset: 0x14 */
    volatile uint32_t PR2;                 /*!< EXTI Pending register,                       Address offset: 0x18 */
             uint32_t RESERVED2;           /*!< Reserved, 0x1C                                                    */
    volatile uint32_t IMR3;                /*!< EXTI Interrupt mask register,                Address offset: 0x20 */
    volatile uint32_t EMR3;                /*!< EXTI Event mask register,                    Address offset: 0x24 */
    volatile uint32_t PR3;                 /*!< EXTI Pending register,                       Address offset: 0x28 */
}EXTI_Core_TypeDef;


/**
  * @brief FLASH Registers
  */
typedef struct
{
    volatile uint32_t ACR;             /*!< FLASH access control register,                            Address offset: 0x00  */
    volatile uint32_t KEYR1;           /*!< Flash Key Register for bank1,                             Address offset: 0x04  */
    volatile uint32_t OPTKEYR;         /*!< Flash Option Key Register,                                Address offset: 0x08  */
    volatile uint32_t CR1;             /*!< Flash Control Register for bank1,                         Address offset: 0x0C  */
    volatile uint32_t SR1;             /*!< Flash Status Register for bank1,                          Address offset: 0x10  */
    volatile uint32_t CCR1;            /*!< Flash Control Register for bank1,                         Address offset: 0x14  */
    volatile uint32_t OPTCR;           /*!< Flash Option Control Register,                            Address offset: 0x18  */
    volatile uint32_t OPTSR_CUR;       /*!< Flash Option Status Current Register,                     Address offset: 0x1C  */
    volatile uint32_t OPTSR_PRG;       /*!< Flash Option Status to Program Register,                  Address offset: 0x20  */
    volatile uint32_t OPTCCR;          /*!< Flash Option Clear Control Register,                      Address offset: 0x24  */
    volatile uint32_t PRAR_CUR1;       /*!< Flash Current Protection Address Register for bank1,      Address offset: 0x28  */
    volatile uint32_t PRAR_PRG1;       /*!< Flash Protection Address to Program Register for bank1,   Address offset: 0x2C  */
    volatile uint32_t SCAR_CUR1;       /*!< Flash Current Secure Address Register for bank1,          Address offset: 0x30  */
    volatile uint32_t SCAR_PRG1;       /*!< Flash Secure Address to Program Register for bank1,       Address offset: 0x34  */
    volatile uint32_t WPSN_CUR1;       /*!< Flash Current Write Protection Register on bank1,         Address offset: 0x38  */
    volatile uint32_t WPSN_PRG1;       /*!< Flash Write Protection to Program Register on bank1,      Address offset: 0x3C  */
    volatile uint32_t BOOT7_CUR;       /*!< Flash Current Boot Address for Pelican Core Register,     Address offset: 0x40  */
    volatile uint32_t BOOT7_PRG;       /*!< Flash Boot Address to Program for Pelican Core Register,  Address offset: 0x44  */
    volatile uint32_t BOOT4_CUR;       /*!< Flash Current Boot Address for M4 Core Register,          Address offset: 0x48  */
    volatile uint32_t BOOT4_PRG;       /*!< Flash Boot Address to Program for M4 Core Register,       Address offset: 0x4C  */
    volatile uint32_t CRCCR1;          /*!< Flash CRC Control register For Bank1 Register ,           Address offset: 0x50  */
    volatile uint32_t CRCSADD1;        /*!< Flash CRC Start Address Register for Bank1 ,              Address offset: 0x54  */
    volatile uint32_t CRCEADD1;        /*!< Flash CRC End Address Register for Bank1 ,                Address offset: 0x58  */
    volatile uint32_t CRCDATA;         /*!< Flash CRC Data Register for Bank1 ,                       Address offset: 0x5C  */
    volatile uint32_t ECC_FA1;         /*!< Flash ECC Fail Address For Bank1 Register ,               Address offset: 0x60  */
             uint32_t RESERVED1[40];   /*!< Reserved, 0x64 to 0x100                                                         */
    volatile uint32_t KEYR2;           /*!< Flash Key Register for bank2,                             Address offset: 0x104 */
             uint32_t RESERVED2;       /*!< Reserved, 0x108                                                                 */
    volatile uint32_t CR2;             /*!< Flash Control Register for bank2,                         Address offset: 0x10C */
    volatile uint32_t SR2;             /*!< Flash Status Register for bank2,                          Address offset: 0x110 */
    volatile uint32_t CCR2;            /*!< Flash Status Register for bank2,                          Address offset: 0x114 */
             uint32_t RESERVED3[4];    /*!< Reserved, 0x118 to 0x124                                                        */
    volatile uint32_t PRAR_CUR2;       /*!< Flash Current Protection Address Register for bank2,      Address offset: 0x128 */
    volatile uint32_t PRAR_PRG2;       /*!< Flash Protection Address to Program Register for bank2,   Address offset: 0x12C */
    volatile uint32_t SCAR_CUR2;       /*!< Flash Current Secure Address Register for bank2,          Address offset: 0x130 */
    volatile uint32_t SCAR_PRG2;       /*!< Flash Secure Address Register for bank2,                  Address offset: 0x134 */
    volatile uint32_t WPSN_CUR2;       /*!< Flash Current Write Protection Register on bank2,         Address offset: 0x138 */
    volatile uint32_t WPSN_PRG2;       /*!< Flash Write Protection to Program Register on bank2,      Address offset: 0x13C */
             uint32_t RESERVED4[4];    /*!< Reserved, 0x140 to 0x14C                                                        */
    volatile uint32_t CRCCR2;          /*!< Flash CRC Control register For Bank2 Register ,           Address offset: 0x150 */
    volatile uint32_t CRCSADD2;        /*!< Flash CRC Start Address Register for Bank2 ,              Address offset: 0x154 */
    volatile uint32_t CRCEADD2;        /*!< Flash CRC End Address Register for Bank2 ,                Address offset: 0x158 */
    volatile uint32_t CRCDATA2;        /*!< Flash CRC Data Register for Bank2 ,                       Address offset: 0x15C */
    volatile uint32_t ECC_FA2;         /*!< Flash ECC Fail Address For Bank2 Register ,               Address offset: 0x160 */
} FLASH_TypeDef;

/**
  * @brief Flexible Memory Controller
  */
typedef struct
{
    volatile uint32_t BTCR[8];    /*!< NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR), Address offset: 0x00-1C */
} FMC_Bank1_TypeDef;

/**
  * @brief Flexible Memory Controller Bank1E
  */
typedef struct
{
    volatile uint32_t BWTR[7];    /*!< NOR/PSRAM write timing registers, Address offset: 0x104-0x11C */
} FMC_Bank1E_TypeDef;

/**
  * @brief Flexible Memory Controller Bank2
  */
typedef struct
{
    volatile uint32_t PCR2;       /*!< NAND Flash control register 2,                       Address offset: 0x60 */
    volatile uint32_t SR2;        /*!< NAND Flash FIFO status and interrupt register 2,     Address offset: 0x64 */
    volatile uint32_t PMEM2;      /*!< NAND Flash Common memory space timing register 2,    Address offset: 0x68 */
    volatile uint32_t PATT2;      /*!< NAND Flash Attribute memory space timing register 2, Address offset: 0x6C */
             uint32_t RESERVED0;  /*!< Reserved, 0x70                                                            */
    volatile uint32_t ECCR2;      /*!< NAND Flash ECC result registers 2,                   Address offset: 0x74 */
} FMC_Bank2_TypeDef;

/**
  * @brief Flexible Memory Controller Bank3
  */
typedef struct
{
    volatile uint32_t PCR;       /*!< NAND Flash control register 3,                       Address offset: 0x80 */
    volatile uint32_t SR;        /*!< NAND Flash FIFO status and interrupt register 3,     Address offset: 0x84 */
    volatile uint32_t PMEM;      /*!< NAND Flash Common memory space timing register 3,    Address offset: 0x88 */
    volatile uint32_t PATT;      /*!< NAND Flash Attribute memory space timing register 3, Address offset: 0x8C */
             uint32_t RESERVED;  /*!< Reserved, 0x90                                                            */
    volatile uint32_t ECCR;      /*!< NAND Flash ECC result registers 3,                   Address offset: 0x94 */
} FMC_Bank3_TypeDef;

/**
  * @brief Flexible Memory Controller Bank5 and 6
  */
typedef struct
{
    volatile uint32_t SDCR[2];        /*!< SDRAM Control registers ,      Address offset: 0x140-0x144  */
    volatile uint32_t SDTR[2];        /*!< SDRAM Timing registers ,       Address offset: 0x148-0x14C  */
    volatile uint32_t SDCMR;       /*!< SDRAM Command Mode register,    Address offset: 0x150  */
    volatile uint32_t SDRTR;       /*!< SDRAM Refresh Timer register,   Address offset: 0x154  */
    volatile uint32_t SDSR;        /*!< SDRAM Status register,          Address offset: 0x158  */
} FMC_Bank5_6_TypeDef;

/**
  * @brief General Purpose I/O
  */
typedef struct
{
    volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
    volatile uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
    volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
    volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
    volatile uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
    volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
    volatile uint32_t BSRR;     /*!< GPIO port bit set/reset,               Address offset: 0x18      */
    volatile uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
    volatile uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

/**
  * @brief Operational Amplifier (OPAMP)
  */
typedef struct
{
    volatile uint32_t CSR;          /*!< OPAMP control/status register,                      Address offset: 0x00 */
    volatile uint32_t OTR;          /*!< OPAMP offset trimming register for normal mode,     Address offset: 0x04 */
    volatile uint32_t HSOTR;        /*!< OPAMP offset trimming register for high speed mode, Address offset: 0x08 */
} OPAMP_TypeDef;

/**
  * @brief System configuration controller
  */
typedef struct
{
             uint32_t RESERVED1;      /*!< Reserved,                                           Address offset: 0x00        */
    volatile uint32_t PMCR;           /*!< SYSCFG peripheral mode configuration register,      Address offset: 0x04        */
    volatile uint32_t EXTICR[4];      /*!< SYSCFG external interrupt configuration registers,  Address offset: 0x08-0x14   */
    volatile uint32_t CFGR;           /*!< SYSCFG configuration registers,                     Address offset: 0x18        */
             uint32_t RESERVED2;      /*!< Reserved,                                           Address offset: 0x1C        */
    volatile uint32_t CCCSR;          /*!< SYSCFG compensation cell control/status register,   Address offset: 0x20        */
    volatile uint32_t CCVR;           /*!< SYSCFG compensation cell value register,            Address offset: 0x24        */
    volatile uint32_t CCCR;           /*!< SYSCFG compensation cell code register,             Address offset: 0x28        */
    volatile uint32_t PWRCR;          /*!< PWR control register,                               Address offset: 0x2C        */
             uint32_t RESERVED3[61];  /*!< Reserved, 0x30-0x120                                                            */
    volatile uint32_t PKGR;           /*!< SYSCFG package register,                            Address offset: 0x124       */
             uint32_t RESERVED4[118]; /*!< Reserved, 0x128-0x2FC                                                           */
    volatile uint32_t UR0;            /*!< SYSCFG user register 0,                             Address offset: 0x300       */
    volatile uint32_t UR1;            /*!< SYSCFG user register 1,                             Address offset: 0x304       */
    volatile uint32_t UR2;            /*!< SYSCFG user register 2,                             Address offset: 0x308       */
    volatile uint32_t UR3;            /*!< SYSCFG user register 3,                             Address offset: 0x30C       */
    volatile uint32_t UR4;            /*!< SYSCFG user register 4,                             Address offset: 0x310       */
    volatile uint32_t UR5;            /*!< SYSCFG user register 5,                             Address offset: 0x314       */
    volatile uint32_t UR6;            /*!< SYSCFG user register 6,                             Address offset: 0x318       */
    volatile uint32_t UR7;            /*!< SYSCFG user register 7,                             Address offset: 0x31C       */
    volatile uint32_t UR8;            /*!< SYSCFG user register 8,                             Address offset: 0x320       */
    volatile uint32_t UR9;            /*!< SYSCFG user register 9,                             Address offset: 0x324       */
    volatile uint32_t UR10;           /*!< SYSCFG user register 10,                            Address offset: 0x328       */
    volatile uint32_t UR11;           /*!< SYSCFG user register 11,                            Address offset: 0x32C       */
    volatile uint32_t UR12;           /*!< SYSCFG user register 12,                            Address offset: 0x330       */
    volatile uint32_t UR13;           /*!< SYSCFG user register 13,                            Address offset: 0x334       */
    volatile uint32_t UR14;           /*!< SYSCFG user register 14,                            Address offset: 0x338       */
    volatile uint32_t UR15;           /*!< SYSCFG user register 15,                            Address offset: 0x33C       */
    volatile uint32_t UR16;           /*!< SYSCFG user register 16,                            Address offset: 0x340       */
    volatile uint32_t UR17;           /*!< SYSCFG user register 17,                            Address offset: 0x344       */
} SYSCFG_TypeDef;

/**
  * @brief Inter-integrated Circuit Interface
  */
typedef struct
{
    volatile uint32_t CR1;      /*!< I2C Control register 1,            Address offset: 0x00 */
    volatile uint32_t CR2;      /*!< I2C Control register 2,            Address offset: 0x04 */
    volatile uint32_t OAR1;     /*!< I2C Own address 1 register,        Address offset: 0x08 */
    volatile uint32_t OAR2;     /*!< I2C Own address 2 register,        Address offset: 0x0C */
    volatile uint32_t TIMINGR;  /*!< I2C Timing register,               Address offset: 0x10 */
    volatile uint32_t TIMEOUTR; /*!< I2C Timeout register,              Address offset: 0x14 */
    volatile uint32_t ISR;      /*!< I2C Interrupt and status register, Address offset: 0x18 */
    volatile uint32_t ICR;      /*!< I2C Interrupt clear register,      Address offset: 0x1C */
    volatile uint32_t PECR;     /*!< I2C PEC register,                  Address offset: 0x20 */
    volatile uint32_t RXDR;     /*!< I2C Receive data register,         Address offset: 0x24 */
    volatile uint32_t TXDR;     /*!< I2C Transmit data register,        Address offset: 0x28 */
} I2C_TypeDef;

/**
  * @brief Independent WATCHDOG
  */
typedef struct
{
    volatile uint32_t KR;   /*!< IWDG Key register,       Address offset: 0x00 */
    volatile uint32_t PR;   /*!< IWDG Prescaler register, Address offset: 0x04 */
    volatile uint32_t RLR;  /*!< IWDG Reload register,    Address offset: 0x08 */
    volatile uint32_t SR;   /*!< IWDG Status register,    Address offset: 0x0C */
    volatile uint32_t WINR; /*!< IWDG Window register,    Address offset: 0x10 */
} IWDG_TypeDef;

/**
  * @brief JPEG Codec
  */
typedef struct
{
    volatile uint32_t CONFR0;          /*!< JPEG Codec Control Register (JPEG_CONFR0),        Address offset: 00h       */
    volatile uint32_t CONFR1;          /*!< JPEG Codec Control Register (JPEG_CONFR1),        Address offset: 04h       */
    volatile uint32_t CONFR2;          /*!< JPEG Codec Control Register (JPEG_CONFR2),        Address offset: 08h       */
    volatile uint32_t CONFR3;          /*!< JPEG Codec Control Register (JPEG_CONFR3),        Address offset: 0Ch       */
    volatile uint32_t CONFR4;          /*!< JPEG Codec Control Register (JPEG_CONFR4),        Address offset: 10h       */
    volatile uint32_t CONFR5;          /*!< JPEG Codec Control Register (JPEG_CONFR5),        Address offset: 14h       */
    volatile uint32_t CONFR6;          /*!< JPEG Codec Control Register (JPEG_CONFR6),        Address offset: 18h       */
    volatile uint32_t CONFR7;          /*!< JPEG Codec Control Register (JPEG_CONFR7),        Address offset: 1Ch       */
             uint32_t Reserved20[4];   /* Reserved                                            Address offset: 20h-2Ch   */
    volatile uint32_t CR;              /*!< JPEG Control Register (JPEG_CR),                  Address offset: 30h       */
    volatile uint32_t SR;              /*!< JPEG Status Register (JPEG_SR),                   Address offset: 34h       */
    volatile uint32_t CFR;             /*!< JPEG Clear Flag Register (JPEG_CFR),              Address offset: 38h       */
             uint32_t Reserved3c;      /* Reserved                                            Address offset: 3Ch       */
    volatile uint32_t DIR;             /*!< JPEG Data Input Register (JPEG_DIR),              Address offset: 40h       */
    volatile uint32_t DOR;             /*!< JPEG Data Output Register (JPEG_DOR),             Address offset: 44h       */
             uint32_t Reserved48[2];   /* Reserved                                            Address offset: 48h-4Ch   */
    volatile uint32_t QMEM0[16];       /*!< JPEG quantization tables 0,                       Address offset: 50h-8Ch   */
    volatile uint32_t QMEM1[16];       /*!< JPEG quantization tables 1,                       Address offset: 90h-CCh   */
    volatile uint32_t QMEM2[16];       /*!< JPEG quantization tables 2,                       Address offset: D0h-10Ch  */
    volatile uint32_t QMEM3[16];       /*!< JPEG quantization tables 3,                       Address offset: 110h-14Ch */
    volatile uint32_t HUFFMIN[16];     /*!< JPEG HuffMin tables,                              Address offset: 150h-18Ch */
    volatile uint32_t HUFFBASE[32];    /*!< JPEG HuffSymb tables,                             Address offset: 190h-20Ch */
    volatile uint32_t HUFFSYMB[84];    /*!< JPEG HUFFSYMB tables,                             Address offset: 210h-35Ch */
    volatile uint32_t DHTMEM[103];     /*!< JPEG DHTMem tables,                               Address offset: 360h-4F8h */
             uint32_t Reserved4FC;     /* Reserved                                            Address offset: 4FCh      */
    volatile uint32_t HUFFENC_AC0[88]; /*!< JPEG encodor, AC Huffman table 0,                 Address offset: 500h-65Ch */
    volatile uint32_t HUFFENC_AC1[88]; /*!< JPEG encodor, AC Huffman table 1,                 Address offset: 660h-7BCh */
    volatile uint32_t HUFFENC_DC0[8];  /*!< JPEG encodor, DC Huffman table 0,                 Address offset: 7C0h-7DCh */
    volatile uint32_t HUFFENC_DC1[8];  /*!< JPEG encodor, DC Huffman table 1,                 Address offset: 7E0h-7FCh */
} JPEG_TypeDef;

/**
  * @brief LCD-TFT Display Controller
  */
typedef struct
{
             uint32_t RESERVED0[2];  /*!< Reserved, 0x00-0x04                                                       */
    volatile uint32_t SSCR;          /*!< LTDC Synchronization Size Configuration Register,    Address offset: 0x08 */
    volatile uint32_t BPCR;          /*!< LTDC Back Porch Configuration Register,              Address offset: 0x0C */
    volatile uint32_t AWCR;          /*!< LTDC Active Width Configuration Register,            Address offset: 0x10 */
    volatile uint32_t TWCR;          /*!< LTDC Total Width Configuration Register,             Address offset: 0x14 */
    volatile uint32_t GCR;           /*!< LTDC Global Control Register,                        Address offset: 0x18 */
             uint32_t RESERVED1[2];  /*!< Reserved, 0x1C-0x20                                                       */
    volatile uint32_t SRCR;          /*!< LTDC Shadow Reload Configuration Register,           Address offset: 0x24 */
             uint32_t RESERVED2[1];  /*!< Reserved, 0x28                                                            */
    volatile uint32_t BCCR;          /*!< LTDC Background Color Configuration Register,        Address offset: 0x2C */
             uint32_t RESERVED3[1];  /*!< Reserved, 0x30                                                            */
    volatile uint32_t IER;           /*!< LTDC Interrupt Enable Register,                      Address offset: 0x34 */
    volatile uint32_t ISR;           /*!< LTDC Interrupt Status Register,                      Address offset: 0x38 */
    volatile uint32_t ICR;           /*!< LTDC Interrupt Clear Register,                       Address offset: 0x3C */
    volatile uint32_t LIPCR;         /*!< LTDC Line Interrupt Position Configuration Register, Address offset: 0x40 */
    volatile uint32_t CPSR;          /*!< LTDC Current Position Status Register,               Address offset: 0x44 */
    volatile uint32_t CDSR;          /*!< LTDC Current Display Status Register,                 Address offset: 0x48 */
} LTDC_TypeDef;

/**
  * @brief LCD-TFT Display layer x Controller
  */
typedef struct
{
    volatile uint32_t CR;            /*!< LTDC Layerx Control Register                                  Address offset: 0x84 */
    volatile uint32_t WHPCR;         /*!< LTDC Layerx Window Horizontal Position Configuration Register Address offset: 0x88 */
    volatile uint32_t WVPCR;         /*!< LTDC Layerx Window Vertical Position Configuration Register   Address offset: 0x8C */
    volatile uint32_t CKCR;          /*!< LTDC Layerx Color Keying Configuration Register               Address offset: 0x90 */
    volatile uint32_t PFCR;          /*!< LTDC Layerx Pixel Format Configuration Register               Address offset: 0x94 */
    volatile uint32_t CACR;          /*!< LTDC Layerx Constant Alpha Configuration Register             Address offset: 0x98 */
    volatile uint32_t DCCR;          /*!< LTDC Layerx Default Color Configuration Register              Address offset: 0x9C */
    volatile uint32_t BFCR;          /*!< LTDC Layerx Blending Factors Configuration Register           Address offset: 0xA0 */
             uint32_t RESERVED0[2];  /*!< Reserved */
    volatile uint32_t CFBAR;         /*!< LTDC Layerx Color Frame Buffer Address Register               Address offset: 0xAC */
    volatile uint32_t CFBLR;         /*!< LTDC Layerx Color Frame Buffer Length Register                Address offset: 0xB0 */
    volatile uint32_t CFBLNR;        /*!< LTDC Layerx ColorFrame Buffer Line Number Register            Address offset: 0xB4 */
             uint32_t RESERVED1[3];  /*!< Reserved */
    volatile uint32_t CLUTWR;        /*!< LTDC Layerx CLUT Write Register                               Address offset: 0x144 */
} LTDC_Layer_TypeDef;

/**
  * @brief Power Control
  */
typedef struct
{
    volatile uint32_t CR1;       /*!< PWR power control register 1,            Address offset: 0x00 */
    volatile uint32_t CSR1;      /*!< PWR power control status register 1,     Address offset: 0x04 */
    volatile uint32_t CR2;       /*!< PWR power control register 2,            Address offset: 0x08 */
    volatile uint32_t CR3;       /*!< PWR power control register 3,            Address offset: 0x0C */
    volatile uint32_t CPUCR;     /*!< PWR CPU control register,                Address offset: 0x10 */
    volatile uint32_t CPU2CR;    /*!< PWR CPU2 control register,               Address offset: 0x14 */
    volatile uint32_t D3CR;      /*!< PWR D3 domain control register,          Address offset: 0x18 */
             uint32_t RESERVED1; /*!< Reserved,                                Address offset: 0x1C */
    volatile uint32_t WKUPCR;    /*!< PWR wakeup clear register,               Address offset: 0x20 */
    volatile uint32_t WKUPFR;    /*!< PWR wakeup flag register,                Address offset: 0x24 */
    volatile uint32_t WKUPEPR;   /*!< PWR wakeup enable and polarity register, Address offset: 0x28 */
} PWR_TypeDef;

/**
  * @brief Reset and Clock Control
  */
typedef struct
{
    volatile uint32_t CR;             /*!< RCC clock control register,                                              Address offset: 0x00  */
    volatile uint32_t HSICFGR;        /*!< HSI Clock Calibration Register,                                          Address offset: 0x04  */
    volatile uint32_t CRRCR;          /*!< Clock Recovery RC  Register,                                             Address offset: 0x08  */
    volatile uint32_t CSICFGR;        /*!< CSI Clock Calibration Register,                                          Address offset: 0x0C  */
    volatile uint32_t CFGR;           /*!< RCC clock configuration register,                                        Address offset: 0x10  */
             uint32_t RESERVED1;      /*!< Reserved,                                                                Address offset: 0x14  */
    volatile uint32_t D1CFGR;         /*!< RCC Domain 1 configuration register,                                     Address offset: 0x18  */
    volatile uint32_t D2CFGR;         /*!< RCC Domain 2 configuration register,                                     Address offset: 0x1C  */
    volatile uint32_t D3CFGR;         /*!< RCC Domain 3 configuration register,                                     Address offset: 0x20  */
             uint32_t RESERVED2;      /*!< Reserved,                                                                Address offset: 0x24  */
    volatile uint32_t PLLCKSELR;      /*!< RCC PLLs Clock Source Selection Register,                                Address offset: 0x28  */
    volatile uint32_t PLLCFGR;        /*!< RCC PLLs  Configuration Register,                                        Address offset: 0x2C  */
    volatile uint32_t PLL1DIVR;       /*!< RCC PLL1 Dividers Configuration Register,                                Address offset: 0x30  */
    volatile uint32_t PLL1FRACR;      /*!< RCC PLL1 Fractional Divider Configuration Register,                      Address offset: 0x34  */
    volatile uint32_t PLL2DIVR;       /*!< RCC PLL2 Dividers Configuration Register,                                Address offset: 0x38  */
    volatile uint32_t PLL2FRACR;      /*!< RCC PLL2 Fractional Divider Configuration Register,                      Address offset: 0x3C  */
    volatile uint32_t PLL3DIVR;       /*!< RCC PLL3 Dividers Configuration Register,                                Address offset: 0x40  */
    volatile uint32_t PLL3FRACR;      /*!< RCC PLL3 Fractional Divider Configuration Register,                      Address offset: 0x44  */
             uint32_t RESERVED3;      /*!< Reserved,                                                                Address offset: 0x48  */
    volatile uint32_t D1CCIPR;        /*!< RCC Domain 1 Kernel Clock Configuration Register                         Address offset: 0x4C  */
    volatile uint32_t D2CCIP1R;       /*!< RCC Domain 2 Kernel Clock Configuration Register                         Address offset: 0x50  */
    volatile uint32_t D2CCIP2R;       /*!< RCC Domain 2 Kernel Clock Configuration Register                         Address offset: 0x54  */
    volatile uint32_t D3CCIPR;        /*!< RCC Domain 3 Kernel Clock Configuration Register                         Address offset: 0x58  */
             uint32_t RESERVED4;      /*!< Reserved,                                                                Address offset: 0x5C  */
    volatile uint32_t CIER;           /*!< RCC Clock Source Interrupt Enable Register                               Address offset: 0x60  */
    volatile uint32_t CIFR;           /*!< RCC Clock Source Interrupt Flag Register                                 Address offset: 0x64  */
    volatile uint32_t CICR;           /*!< RCC Clock Source Interrupt Clear Register                                Address offset: 0x68  */
             uint32_t RESERVED5;      /*!< Reserved,                                                                Address offset: 0x6C  */
    volatile uint32_t BDCR;           /*!< RCC Vswitch Backup Domain Control Register,                              Address offset: 0x70  */
    volatile uint32_t CSR;            /*!< RCC clock control & status register,                                     Address offset: 0x74  */
             uint32_t RESERVED6;      /*!< Reserved,                                                                Address offset: 0x78  */
    volatile uint32_t AHB3RSTR;       /*!< RCC AHB3 peripheral reset register,                                      Address offset: 0x7C  */
    volatile uint32_t AHB1RSTR;       /*!< RCC AHB1 peripheral reset register,                                      Address offset: 0x80  */
    volatile uint32_t AHB2RSTR;       /*!< RCC AHB2 peripheral reset register,                                      Address offset: 0x84  */
    volatile uint32_t AHB4RSTR;       /*!< RCC AHB4 peripheral reset register,                                      Address offset: 0x88  */
    volatile uint32_t APB3RSTR;       /*!< RCC APB3 peripheral reset register,                                      Address offset: 0x8C  */
    volatile uint32_t APB1LRSTR;      /*!< RCC APB1 peripheral reset Low Word register,                             Address offset: 0x90  */
    volatile uint32_t APB1HRSTR;      /*!< RCC APB1 peripheral reset High Word register,                            Address offset: 0x94  */
    volatile uint32_t APB2RSTR;       /*!< RCC APB2 peripheral reset register,                                      Address offset: 0x98  */
    volatile uint32_t APB4RSTR;       /*!< RCC APB4 peripheral reset register,                                      Address offset: 0x9C  */
    volatile uint32_t GCR;            /*!< RCC RCC Global Control  Register,                                        Address offset: 0xA0  */
             uint32_t RESERVED8;      /*!< Reserved,                                                                Address offset: 0xA4  */
    volatile uint32_t D3AMR;          /*!< RCC Domain 3 Autonomous Mode Register,                                   Address offset: 0xA8  */
             uint32_t RESERVED11[9];  /*!< Reserved, 0xAC-0xCC                                                      Address offset: 0xAC  */
    volatile uint32_t RSR;            /*!< RCC Reset status register,                                               Address offset: 0xD0  */
    volatile uint32_t AHB3ENR;        /*!< RCC AHB3 peripheral clock  register,                                     Address offset: 0xD4  */
    volatile uint32_t AHB1ENR;        /*!< RCC AHB1 peripheral clock  register,                                     Address offset: 0xD8  */
    volatile uint32_t AHB2ENR;        /*!< RCC AHB2 peripheral clock  register,                                     Address offset: 0xDC  */
    volatile uint32_t AHB4ENR;        /*!< RCC AHB4 peripheral clock  register,                                     Address offset: 0xE0  */
    volatile uint32_t APB3ENR;        /*!< RCC APB3 peripheral clock  register,                                     Address offset: 0xE4  */
    volatile uint32_t APB1LENR;       /*!< RCC APB1 peripheral clock  Low Word register,                            Address offset: 0xE8  */
    volatile uint32_t APB1HENR;       /*!< RCC APB1 peripheral clock  High Word register,                           Address offset: 0xEC  */
    volatile uint32_t APB2ENR;        /*!< RCC APB2 peripheral clock  register,                                     Address offset: 0xF0  */
    volatile uint32_t APB4ENR;        /*!< RCC APB4 peripheral clock  register,                                     Address offset: 0xF4  */
             uint32_t RESERVED12;     /*!< Reserved,                                                                Address offset: 0xF8  */
    volatile uint32_t AHB3LPENR;      /*!< RCC AHB3 peripheral sleep clock  register,                               Address offset: 0xFC  */
    volatile uint32_t AHB1LPENR;      /*!< RCC AHB1 peripheral sleep clock  register,                               Address offset: 0x100 */
    volatile uint32_t AHB2LPENR;      /*!< RCC AHB2 peripheral sleep clock  register,                               Address offset: 0x104 */
    volatile uint32_t AHB4LPENR;      /*!< RCC AHB4 peripheral sleep clock  register,                               Address offset: 0x108 */
    volatile uint32_t APB3LPENR;      /*!< RCC APB3 peripheral sleep clock  register,                               Address offset: 0x10C */
    volatile uint32_t APB1LLPENR;     /*!< RCC APB1 peripheral sleep clock  Low Word register,                      Address offset: 0x110 */
    volatile uint32_t APB1HLPENR;     /*!< RCC APB1 peripheral sleep clock  High Word register,                     Address offset: 0x114 */
    volatile uint32_t APB2LPENR;      /*!< RCC APB2 peripheral sleep clock  register,                               Address offset: 0x118 */
    volatile uint32_t APB4LPENR;      /*!< RCC APB4 peripheral sleep clock  register,                               Address offset: 0x11C */
             uint32_t RESERVED13[4];  /*!< Reserved, 0x120-0x12C                                                    Address offset: 0x120 */
} RCC_TypeDef;

typedef struct
{
    volatile uint32_t RSR;          /*!< RCC Reset status register,                                               Address offset: 0x00 */
    volatile uint32_t AHB3ENR;      /*!< RCC AHB3 peripheral clock  register,                            Address offset: 0x04 */
    volatile uint32_t AHB1ENR;      /*!< RCC AHB1 peripheral clock  register,                            Address offset: 0x08 */
    volatile uint32_t AHB2ENR;      /*!< RCC AHB2 peripheral clock  register,                            Address offset: 0x0C */
    volatile uint32_t AHB4ENR;      /*!< RCC AHB4 peripheral clock  register,                            Address offset: 0x10 */
    volatile uint32_t APB3ENR;      /*!< RCC APB3 peripheral clock  register,                            Address offset: 0x14 */
    volatile uint32_t APB1LENR;     /*!< RCC APB1 peripheral clock  Low Word register,                   Address offset: 0x18 */
    volatile uint32_t APB1HENR;     /*!< RCC APB1 peripheral clock  High Word register,                  Address offset: 0x1C */
    volatile uint32_t APB2ENR;      /*!< RCC APB2 peripheral clock  register,                            Address offset: 0x20 */
    volatile uint32_t APB4ENR;      /*!< RCC APB4 peripheral clock  register,                            Address offset: 0x24 */
             uint32_t RESERVED9;    /*!< Reserved,                                                       Address offset: 0x28 */
    volatile uint32_t AHB3LPENR;    /*!< RCC AHB3 peripheral sleep clock  register,                      Address offset: 0x3C */
    volatile uint32_t AHB1LPENR;    /*!< RCC AHB1 peripheral sleep clock  register,                      Address offset: 0x40 */
    volatile uint32_t AHB2LPENR;    /*!< RCC AHB2 peripheral sleep clock  register,                      Address offset: 0x44 */
    volatile uint32_t AHB4LPENR;    /*!< RCC AHB4 peripheral sleep clock  register,                      Address offset: 0x48 */
    volatile uint32_t APB3LPENR;    /*!< RCC APB3 peripheral sleep clock  register,                      Address offset: 0x4C */
    volatile uint32_t APB1LLPENR;   /*!< RCC APB1 peripheral sleep clock  Low Word register,             Address offset: 0x50 */
    volatile uint32_t APB1HLPENR;   /*!< RCC APB1 peripheral sleep clock  High Word register,            Address offset: 0x54 */
    volatile uint32_t APB2LPENR;    /*!< RCC APB2 peripheral sleep clock  register,                      Address offset: 0x58 */
    volatile uint32_t APB4LPENR;    /*!< RCC APB4 peripheral sleep clock  register,                      Address offset: 0x5C */
             uint32_t RESERVED10[4];/*!< Reserved, 0x60-0x6C                                             Address offset: 0x60 */

} RCC_Core_TypeDef;

/**
  * @brief Real-Time Clock
  */
typedef struct
{
    volatile uint32_t TR;         /*!< RTC time register,                                         Address offset: 0x00 */
    volatile uint32_t DR;         /*!< RTC date register,                                         Address offset: 0x04 */
    volatile uint32_t CR;         /*!< RTC control register,                                      Address offset: 0x08 */
    volatile uint32_t ISR;        /*!< RTC initialization and status register,                    Address offset: 0x0C */
    volatile uint32_t PRER;       /*!< RTC prescaler register,                                    Address offset: 0x10 */
    volatile uint32_t WUTR;       /*!< RTC wakeup timer register,                                 Address offset: 0x14 */
             uint32_t RESERVED;   /*!< Reserved,                                                  Address offset: 0x18 */
    volatile uint32_t ALRMAR;     /*!< RTC alarm A register,                                      Address offset: 0x1C */
    volatile uint32_t ALRMBR;     /*!< RTC alarm B register,                                      Address offset: 0x20 */
    volatile uint32_t WPR;        /*!< RTC write protection register,                             Address offset: 0x24 */
    volatile uint32_t SSR;        /*!< RTC sub second register,                                   Address offset: 0x28 */
    volatile uint32_t SHIFTR;     /*!< RTC shift control register,                                Address offset: 0x2C */
    volatile uint32_t TSTR;       /*!< RTC time stamp time register,                              Address offset: 0x30 */
    volatile uint32_t TSDR;       /*!< RTC time stamp date register,                              Address offset: 0x34 */
    volatile uint32_t TSSSR;      /*!< RTC time-stamp sub second register,                        Address offset: 0x38 */
    volatile uint32_t CALR;       /*!< RTC calibration register,                                  Address offset: 0x3C */
    volatile uint32_t TAMPCR;     /*!< RTC tamper configuration register,                         Address offset: 0x40 */
    volatile uint32_t ALRMASSR;   /*!< RTC alarm A sub second register,                           Address offset: 0x44 */
    volatile uint32_t ALRMBSSR;   /*!< RTC alarm B sub second register,                           Address offset: 0x48 */
    volatile uint32_t OR;         /*!< RTC option register,                                       Address offset: 0x4C */
    volatile uint32_t BKP0R;      /*!< RTC backup register 0,                                     Address offset: 0x50 */
    volatile uint32_t BKP1R;      /*!< RTC backup register 1,                                     Address offset: 0x54 */
    volatile uint32_t BKP2R;      /*!< RTC backup register 2,                                     Address offset: 0x58 */
    volatile uint32_t BKP3R;      /*!< RTC backup register 3,                                     Address offset: 0x5C */
    volatile uint32_t BKP4R;      /*!< RTC backup register 4,                                     Address offset: 0x60 */
    volatile uint32_t BKP5R;      /*!< RTC backup register 5,                                     Address offset: 0x64 */
    volatile uint32_t BKP6R;      /*!< RTC backup register 6,                                     Address offset: 0x68 */
    volatile uint32_t BKP7R;      /*!< RTC backup register 7,                                     Address offset: 0x6C */
    volatile uint32_t BKP8R;      /*!< RTC backup register 8,                                     Address offset: 0x70 */
    volatile uint32_t BKP9R;      /*!< RTC backup register 9,                                     Address offset: 0x74 */
    volatile uint32_t BKP10R;     /*!< RTC backup register 10,                                    Address offset: 0x78 */
    volatile uint32_t BKP11R;     /*!< RTC backup register 11,                                    Address offset: 0x7C */
    volatile uint32_t BKP12R;     /*!< RTC backup register 12,                                    Address offset: 0x80 */
    volatile uint32_t BKP13R;     /*!< RTC backup register 13,                                    Address offset: 0x84 */
    volatile uint32_t BKP14R;     /*!< RTC backup register 14,                                    Address offset: 0x88 */
    volatile uint32_t BKP15R;     /*!< RTC backup register 15,                                    Address offset: 0x8C */
    volatile uint32_t BKP16R;     /*!< RTC backup register 16,                                    Address offset: 0x90 */
    volatile uint32_t BKP17R;     /*!< RTC backup register 17,                                    Address offset: 0x94 */
    volatile uint32_t BKP18R;     /*!< RTC backup register 18,                                    Address offset: 0x98 */
    volatile uint32_t BKP19R;     /*!< RTC backup register 19,                                    Address offset: 0x9C */
    volatile uint32_t BKP20R;     /*!< RTC backup register 20,                                    Address offset: 0xA0 */
    volatile uint32_t BKP21R;     /*!< RTC backup register 21,                                    Address offset: 0xA4 */
    volatile uint32_t BKP22R;     /*!< RTC backup register 22,                                    Address offset: 0xA8 */
    volatile uint32_t BKP23R;     /*!< RTC backup register 23,                                    Address offset: 0xAC */
    volatile uint32_t BKP24R;     /*!< RTC backup register 24,                                    Address offset: 0xB0 */
    volatile uint32_t BKP25R;     /*!< RTC backup register 25,                                    Address offset: 0xB4 */
    volatile uint32_t BKP26R;     /*!< RTC backup register 26,                                    Address offset: 0xB8 */
    volatile uint32_t BKP27R;     /*!< RTC backup register 27,                                    Address offset: 0xBC */
    volatile uint32_t BKP28R;     /*!< RTC backup register 28,                                    Address offset: 0xC0 */
    volatile uint32_t BKP29R;     /*!< RTC backup register 29,                                    Address offset: 0xC4 */
    volatile uint32_t BKP30R;     /*!< RTC backup register 30,                                    Address offset: 0xC8 */
    volatile uint32_t BKP31R;     /*!< RTC backup register 31,                                    Address offset: 0xCC */
} RTC_TypeDef;

/**
  * @brief Serial Audio Interface
  */
typedef struct
{
    volatile uint32_t GCR;           /*!< SAI global configuration register, Address offset: 0x00 */
             uint32_t RESERVED0[16]; /*!< Reserved, 0x04 - 0x43                                   */
    volatile uint32_t PDMCR;         /*!< SAI PDM control register,          Address offset: 0x44 */
    volatile uint32_t PDMDLY;        /*!< SAI PDM delay register,            Address offset: 0x48 */
} SAI_TypeDef;

typedef struct
{
    volatile uint32_t CR1;      /*!< SAI block x configuration register 1,     Address offset: 0x04 */
    volatile uint32_t CR2;      /*!< SAI block x configuration register 2,     Address offset: 0x08 */
    volatile uint32_t FRCR;     /*!< SAI block x frame configuration register, Address offset: 0x0C */
    volatile uint32_t SLOTR;    /*!< SAI block x slot register,                Address offset: 0x10 */
    volatile uint32_t IMR;      /*!< SAI block x interrupt mask register,      Address offset: 0x14 */
    volatile uint32_t SR;       /*!< SAI block x status register,              Address offset: 0x18 */
    volatile uint32_t CLRFR;    /*!< SAI block x clear flag register,          Address offset: 0x1C */
    volatile uint32_t DR;       /*!< SAI block x data register,                Address offset: 0x20 */
} SAI_Block_TypeDef;

/**
  * @brief SPDIF-RX Interface
  */
typedef struct
{
    volatile uint32_t   CR;           /*!< Control register,                   Address offset: 0x00 */
    volatile uint32_t   IMR;          /*!< Interrupt mask register,            Address offset: 0x04 */
    volatile uint32_t   SR;           /*!< Status register,                    Address offset: 0x08 */
    volatile uint32_t   IFCR;         /*!< Interrupt Flag Clear register,      Address offset: 0x0C */
    volatile uint32_t   DR;           /*!< Data input register,                Address offset: 0x10 */
    volatile uint32_t   CSR;          /*!< Channel Status register,            Address offset: 0x14 */
    volatile uint32_t   DIR;          /*!< Debug Information register,         Address offset: 0x18 */
             uint32_t   RESERVED2;    /*!< Reserved,  0x1A                                          */
} SPDIFRX_TypeDef;

/**
  * @brief Secure digital input/output Interface
  */
typedef struct
{
    volatile       uint32_t POWER;          /*!< SDMMC power control register,             Address offset: 0x00  */
    volatile       uint32_t CLKCR;          /*!< SDMMC clock control register,             Address offset: 0x04  */
    volatile       uint32_t ARG;            /*!< SDMMC argument register,                  Address offset: 0x08  */
    volatile       uint32_t CMD;            /*!< SDMMC command register,                   Address offset: 0x0C  */
    volatile const uint32_t RESPCMD;        /*!< SDMMC command response register,          Address offset: 0x10  */
    volatile const uint32_t RESP1;          /*!< SDMMC response 1 register,                Address offset: 0x14  */
    volatile const uint32_t RESP2;          /*!< SDMMC response 2 register,                Address offset: 0x18  */
    volatile const uint32_t RESP3;          /*!< SDMMC response 3 register,                Address offset: 0x1C  */
    volatile const uint32_t RESP4;          /*!< SDMMC response 4 register,                Address offset: 0x20  */
    volatile       uint32_t DTIMER;         /*!< SDMMC data timer register,                Address offset: 0x24  */
    volatile       uint32_t DLEN;           /*!< SDMMC data length register,               Address offset: 0x28  */
    volatile       uint32_t DCTRL;          /*!< SDMMC data control register,              Address offset: 0x2C  */
    volatile const uint32_t DCOUNT;         /*!< SDMMC data counter register,              Address offset: 0x30  */
    volatile const uint32_t STA;            /*!< SDMMC status register,                    Address offset: 0x34  */
    volatile       uint32_t ICR;            /*!< SDMMC interrupt clear register,           Address offset: 0x38  */
    volatile       uint32_t MASK;           /*!< SDMMC mask register,                      Address offset: 0x3C  */
    volatile       uint32_t ACKTIME;        /*!< SDMMC Acknowledgement timer register,     Address offset: 0x40  */
                   uint32_t RESERVED0[3];   /*!< Reserved, 0x44 - 0x4C - 0x4C                                    */
    volatile       uint32_t IDMACTRL;       /*!< SDMMC DMA control register,               Address offset: 0x50  */
    volatile       uint32_t IDMABSIZE;      /*!< SDMMC DMA buffer size register,           Address offset: 0x54  */
    volatile       uint32_t IDMABASE0;      /*!< SDMMC DMA buffer 0 base address register, Address offset: 0x58  */
    volatile       uint32_t IDMABASE1;      /*!< SDMMC DMA buffer 1 base address register, Address offset: 0x5C  */
                   uint32_t RESERVED1[8];   /*!< Reserved, 0x60-0x7C                                             */
    volatile       uint32_t FIFO;           /*!< SDMMC data FIFO register,                 Address offset: 0x80  */
                   uint32_t RESERVED2[222]; /*!< Reserved, 0x84-0x3F8                                            */
    volatile       uint32_t IPVR;           /*!< SDMMC data FIFO register,                 Address offset: 0x3FC */
} SDMMC_TypeDef;


/**
  * @brief Delay Block DLYB
  */
typedef struct
{
    volatile uint32_t CR;          /*!< DELAY BLOCK control register,  Address offset: 0x00 */
    volatile uint32_t CFGR;        /*!< DELAY BLOCK configuration register,  Address offset: 0x04 */
} DLYB_TypeDef;

/**
  * @brief HW Semaphore HSEM
  */
typedef struct
{
    volatile uint32_t R[32];      /*!< 2-step write lock and read back registers,     Address offset: 00h-7Ch  */
    volatile uint32_t RLR[32];    /*!< 1-step read lock registers,                    Address offset: 80h-FCh  */
    volatile uint32_t C1IER;      /*!< HSEM Interrupt 0 enable register ,             Address offset: 100h     */
    volatile uint32_t C1ICR;      /*!< HSEM Interrupt 0 clear register ,              Address offset: 104h     */
    volatile uint32_t C1ISR;      /*!< HSEM Interrupt 0 Status register ,             Address offset: 108h     */
    volatile uint32_t C1MISR;     /*!< HSEM Interrupt 0 Masked Status register ,      Address offset: 10Ch     */
    volatile uint32_t C2IER;      /*!< HSEM Interrupt 1 enable register ,             Address offset: 110h     */
    volatile uint32_t C2ICR;      /*!< HSEM Interrupt 1 clear register ,              Address offset: 114h     */
    volatile uint32_t C2ISR;      /*!< HSEM Interrupt 1 Status register ,             Address offset: 118h     */
    volatile uint32_t C2MISR;     /*!< HSEM Interrupt 1 Masked Status register ,      Address offset: 11Ch     */
             uint32_t Reserved[8];   /* Reserved                                         Address offset: 120h-13Ch*/
    volatile uint32_t CR;         /*!< HSEM Semaphore clear register ,                Address offset: 140h      */
    volatile uint32_t KEYR;       /*!< HSEM Semaphore clear key register ,            Address offset: 144h      */

} HSEM_TypeDef;

typedef struct
{
    volatile uint32_t IER;        /*!< HSEM interrupt enable register ,                Address offset:   0h     */
    volatile uint32_t ICR;        /*!< HSEM interrupt clear register ,                 Address offset:   4h     */
    volatile uint32_t ISR;        /*!< HSEM interrupt status register ,                Address offset:   8h     */
    volatile uint32_t MISR;       /*!< HSEM masked interrupt status register ,         Address offset:   Ch     */
} HSEM_Common_TypeDef;

/**
  * @brief Serial Peripheral Interface
  */
typedef struct
{
    volatile uint32_t CR1;           /*!< SPI/I2S Control register 1,                      Address offset: 0x00 */
    volatile uint32_t CR2;           /*!< SPI Control register 2,                          Address offset: 0x04 */
    volatile uint32_t CFG1;          /*!< SPI Configuration register 1,                    Address offset: 0x08 */
    volatile uint32_t CFG2;          /*!< SPI Configuration register 2,                    Address offset: 0x0C */
    volatile uint32_t IER;           /*!< SPI/I2S Interrupt Enable register,               Address offset: 0x10 */
    volatile uint32_t SR;            /*!< SPI/I2S Status register,                         Address offset: 0x14 */
    volatile uint32_t IFCR;          /*!< SPI/I2S Interrupt/Status flags clear register,   Address offset: 0x18 */
             uint32_t RESERVED0;     /*!< Reserved, 0x1C                                                        */
    volatile uint32_t TXDR;          /*!< SPI/I2S Transmit data register,                  Address offset: 0x20 */
             uint32_t RESERVED1[3];  /*!< Reserved, 0x24-0x2C                                                   */
    volatile uint32_t RXDR;          /*!< SPI/I2S Receive data register,                   Address offset: 0x30 */
             uint32_t RESERVED2[3];  /*!< Reserved, 0x34-0x3C                                                   */
    volatile uint32_t CRCPOLY;       /*!< SPI CRC Polynomial register,                     Address offset: 0x40 */
    volatile uint32_t TXCRC;         /*!< SPI Transmitter CRC register,                    Address offset: 0x44 */
    volatile uint32_t RXCRC;         /*!< SPI Receiver CRC register,                       Address offset: 0x48 */
    volatile uint32_t UDRDR;         /*!< SPI Underrun data register,                      Address offset: 0x4C */
    volatile uint32_t I2SCFGR;       /*!< I2S Configuration register,                      Address offset: 0x50 */

} SPI_TypeDef;
/**
  * @brief QUAD Serial Peripheral Interface
  */
typedef struct
{
    volatile uint32_t CR;       /*!< QUADSPI Control register,                           Address offset: 0x00 */
    volatile uint32_t DCR;      /*!< QUADSPI Device Configuration register,              Address offset: 0x04 */
    volatile uint32_t SR;       /*!< QUADSPI Status register,                            Address offset: 0x08 */
    volatile uint32_t FCR;      /*!< QUADSPI Flag Clear register,                        Address offset: 0x0C */
    volatile uint32_t DLR;      /*!< QUADSPI Data Length register,                       Address offset: 0x10 */
    volatile uint32_t CCR;      /*!< QUADSPI Communication Configuration register,       Address offset: 0x14 */
    volatile uint32_t AR;       /*!< QUADSPI Address register,                           Address offset: 0x18 */
    volatile uint32_t ABR;      /*!< QUADSPI Alternate Bytes register,                   Address offset: 0x1C */
    volatile uint32_t DR;       /*!< QUADSPI Data register,                              Address offset: 0x20 */
    volatile uint32_t PSMKR;    /*!< QUADSPI Polling Status Mask register,               Address offset: 0x24 */
    volatile uint32_t PSMAR;    /*!< QUADSPI Polling Status Match register,              Address offset: 0x28 */
    volatile uint32_t PIR;      /*!< QUADSPI Polling Interval register,                  Address offset: 0x2C */
    volatile uint32_t LPTR;     /*!< QUADSPI Low Power Timeout register,                 Address offset: 0x30 */
} QUADSPI_TypeDef;

/**
  * @brief TIM
  */
typedef struct
{
    volatile uint32_t CR1;         /*!< TIM control register 1,                   Address offset: 0x00 */
    volatile uint32_t CR2;         /*!< TIM control register 2,                   Address offset: 0x04 */
    volatile uint32_t SMCR;        /*!< TIM slave mode control register,          Address offset: 0x08 */
    volatile uint32_t DIER;        /*!< TIM DMA/interrupt enable register,        Address offset: 0x0C */
    volatile uint32_t SR;          /*!< TIM status register,                      Address offset: 0x10 */
    volatile uint32_t EGR;         /*!< TIM event generation register,            Address offset: 0x14 */
    volatile uint32_t CCMR1;       /*!< TIM capture/compare mode register 1,      Address offset: 0x18 */
    volatile uint32_t CCMR2;       /*!< TIM capture/compare mode register 2,      Address offset: 0x1C */
    volatile uint32_t CCER;        /*!< TIM capture/compare enable register,      Address offset: 0x20 */
    volatile uint32_t CNT;         /*!< TIM counter register,                     Address offset: 0x24 */
    volatile uint32_t PSC;         /*!< TIM prescaler,                            Address offset: 0x28 */
    volatile uint32_t ARR;         /*!< TIM auto-reload register,                 Address offset: 0x2C */
    volatile uint32_t RCR;         /*!< TIM repetition counter register,          Address offset: 0x30 */
    volatile uint32_t CCR1;        /*!< TIM capture/compare register 1,           Address offset: 0x34 */
    volatile uint32_t CCR2;        /*!< TIM capture/compare register 2,           Address offset: 0x38 */
    volatile uint32_t CCR3;        /*!< TIM capture/compare register 3,           Address offset: 0x3C */
    volatile uint32_t CCR4;        /*!< TIM capture/compare register 4,           Address offset: 0x40 */
    volatile uint32_t BDTR;        /*!< TIM break and dead-time register,         Address offset: 0x44 */
    volatile uint32_t DCR;         /*!< TIM DMA control register,                 Address offset: 0x48 */
    volatile uint32_t DMAR;        /*!< TIM DMA address for full transfer,        Address offset: 0x4C */
             uint32_t RESERVED1;   /*!< Reserved, 0x50                                                 */
    volatile uint32_t CCMR3;       /*!< TIM capture/compare mode register 3,      Address offset: 0x54 */
    volatile uint32_t CCR5;        /*!< TIM capture/compare register5,            Address offset: 0x58 */
    volatile uint32_t CCR6;        /*!< TIM capture/compare register6,            Address offset: 0x5C */
    volatile uint32_t AF1;         /*!< TIM alternate function option register 1, Address offset: 0x60 */
    volatile uint32_t AF2;         /*!< TIM alternate function option register 2, Address offset: 0x64 */
    volatile uint32_t TISEL;       /*!< TIM Input Selection register,             Address offset: 0x68 */
} TIM_TypeDef;

/**
  * @brief LPTIMIMER
  */
typedef struct
{
    volatile uint32_t ISR;      /*!< LPTIM Interrupt and Status register,         Address offset: 0x00 */
    volatile uint32_t ICR;      /*!< LPTIM Interrupt Clear register,              Address offset: 0x04 */
    volatile uint32_t IER;      /*!< LPTIM Interrupt Enable register,             Address offset: 0x08 */
    volatile uint32_t CFGR;     /*!< LPTIM Configuration register,                Address offset: 0x0C */
    volatile uint32_t CR;       /*!< LPTIM Control register,                      Address offset: 0x10 */
    volatile uint32_t CMP;      /*!< LPTIM Compare register,                      Address offset: 0x14 */
    volatile uint32_t ARR;      /*!< LPTIM Autoreload register,                   Address offset: 0x18 */
    volatile uint32_t CNT;      /*!< LPTIM Counter register,                      Address offset: 0x1C */
             uint32_t RESERVED1;    /*!< Reserved, 0x20                                                    */
    volatile uint32_t CFGR2;    /*!< LPTIM Configuration register,                Address offset: 0x24 */
} LPTIM_TypeDef;

/**
  * @brief Comparator
  */
typedef struct
{
    volatile uint32_t SR;        /*!< Comparator status register,                    Address offset: 0x00 */
    volatile uint32_t ICFR;      /*!< Comparator interrupt clear flag register,       Address offset: 0x04 */
    volatile uint32_t OR;        /*!< Comparator option register,                  Address offset: 0x08 */
} COMPOPT_TypeDef;

typedef struct
{
    volatile uint32_t CFGR;      /*!< Comparator configuration register  ,           Address offset: 0x00 */
} COMP_TypeDef;

typedef struct
{
    volatile uint32_t CFGR;       /*!< COMP control and status register, used for bits common to several COMP instances, Address offset: 0x00 */
} COMP_Common_TypeDef;

/**
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */
typedef struct
{
    volatile uint32_t CR1;    /*!< USART Control register 1,                 Address offset: 0x00 */
    volatile uint32_t CR2;    /*!< USART Control register 2,                 Address offset: 0x04 */
    volatile uint32_t CR3;    /*!< USART Control register 3,                 Address offset: 0x08 */
    volatile uint32_t BRR;    /*!< USART Baud rate register,                 Address offset: 0x0C */
    volatile uint32_t GTPR;   /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
    volatile uint32_t RTOR;   /*!< USART Receiver Time Out register,         Address offset: 0x14 */
    volatile uint32_t RQR;    /*!< USART Request register,                   Address offset: 0x18 */
    volatile uint32_t ISR;    /*!< USART Interrupt and status register,      Address offset: 0x1C */
    volatile uint32_t ICR;    /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
    volatile uint32_t RDR;    /*!< USART Receive Data register,              Address offset: 0x24 */
    volatile uint32_t TDR;    /*!< USART Transmit Data register,             Address offset: 0x28 */
    volatile uint32_t PRESC;  /*!< USART clock Prescaler register,           Address offset: 0x2C */
} USART_TypeDef;

/**
  * @brief Single Wire Protocol Master Interface SPWMI
  */
typedef struct
{
    volatile uint32_t CR;          /*!< SWPMI Configuration/Control register,     Address offset: 0x00 */
    volatile uint32_t BRR;         /*!< SWPMI bitrate register,                   Address offset: 0x04 */
             uint32_t RESERVED1;     /*!< Reserved, 0x08                                                 */
    volatile uint32_t ISR;         /*!< SWPMI Interrupt and Status register,      Address offset: 0x0C */
    volatile uint32_t ICR;         /*!< SWPMI Interrupt Flag Clear register,      Address offset: 0x10 */
    volatile uint32_t IER;         /*!< SWPMI Interrupt Enable register,          Address offset: 0x14 */
    volatile uint32_t RFL;         /*!< SWPMI Receive Frame Length register,      Address offset: 0x18 */
    volatile uint32_t TDR;         /*!< SWPMI Transmit data register,             Address offset: 0x1C */
    volatile uint32_t RDR;         /*!< SWPMI Receive data register,              Address offset: 0x20 */
    volatile uint32_t OR;          /*!< SWPMI Option register,                    Address offset: 0x24 */
} SWPMI_TypeDef;

/**
  * @brief Window WATCHDOG
  */

typedef struct
{
    volatile uint32_t CR;   /*!< WWDG Control register,       Address offset: 0x00 */
    volatile uint32_t CFR;  /*!< WWDG Configuration register, Address offset: 0x04 */
    volatile uint32_t SR;   /*!< WWDG Status register,        Address offset: 0x08 */
} WWDG_TypeDef;


/**
  * @brief RAM_ECC_Specific_Registers
  */
typedef struct
{
    volatile uint32_t CR;           /*!< RAMECC monitor configuration register          */
    volatile uint32_t SR;           /*!< RAMECC monitor status register                 */
    volatile uint32_t FAR;          /*!< RAMECC monitor failing address register        */
    volatile uint32_t FDRL;         /*!< RAMECC monitor failing data low register       */
    volatile uint32_t FDRH;         /*!< RAMECC monitor failing data high register      */
    volatile uint32_t FECR;         /*!< RAMECC monitor failing ECC error code register */
} RAMECC_MonitorTypeDef;

typedef struct
{
    volatile uint32_t IER;          /*!< RAMECC interrupt enable register */
} RAMECC_TypeDef;

/**
  * @brief High resolution Timer (HRTIM)
  */
/* HRTIM master registers definition */
typedef struct
{
    volatile uint32_t MCR;            /*!< HRTIM Master Timer control register,                     Address offset: 0x00 */
    volatile uint32_t MISR;           /*!< HRTIM Master Timer interrupt status register,            Address offset: 0x04 */
    volatile uint32_t MICR;           /*!< HRTIM Master Timer interrupt clear register,             Address offset: 0x08 */
    volatile uint32_t MDIER;          /*!< HRTIM Master Timer DMA/interrupt enable register         Address offset: 0x0C */
    volatile uint32_t MCNTR;          /*!< HRTIM Master Timer counter register,                     Address offset: 0x10 */
    volatile uint32_t MPER;           /*!< HRTIM Master Timer period register,                      Address offset: 0x14 */
    volatile uint32_t MREP;           /*!< HRTIM Master Timer repetition register,                  Address offset: 0x18 */
    volatile uint32_t MCMP1R;         /*!< HRTIM Master Timer compare 1 register,                   Address offset: 0x1C */
             uint32_t RESERVED0;     /*!< Reserved,                                                                 0x20 */
    volatile uint32_t MCMP2R;         /*!< HRTIM Master Timer compare 2 register,                   Address offset: 0x24 */
    volatile uint32_t MCMP3R;         /*!< HRTIM Master Timer compare 3 register,                   Address offset: 0x28 */
    volatile uint32_t MCMP4R;         /*!< HRTIM Master Timer compare 4 register,                   Address offset: 0x2C */
             uint32_t RESERVED1[20];  /*!< Reserved,                                                          0x30..0x7C */
}HRTIM_Master_TypeDef;

/* HRTIM Timer A to E registers definition */
typedef struct
{
    volatile uint32_t TIMxCR;     /*!< HRTIM Timerx control register,                              Address offset: 0x00 */
    volatile uint32_t TIMxISR;    /*!< HRTIM Timerx interrupt status register,                     Address offset: 0x04 */
    volatile uint32_t TIMxICR;    /*!< HRTIM Timerx interrupt clear register,                      Address offset: 0x08 */
    volatile uint32_t TIMxDIER;   /*!< HRTIM Timerx DMA/interrupt enable register,                 Address offset: 0x0C */
    volatile uint32_t CNTxR;      /*!< HRTIM Timerx counter register,                              Address offset: 0x10 */
    volatile uint32_t PERxR;      /*!< HRTIM Timerx period register,                               Address offset: 0x14 */
    volatile uint32_t REPxR;      /*!< HRTIM Timerx repetition register,                           Address offset: 0x18 */
    volatile uint32_t CMP1xR;     /*!< HRTIM Timerx compare 1 register,                            Address offset: 0x1C */
    volatile uint32_t CMP1CxR;    /*!< HRTIM Timerx compare 1 compound register,                   Address offset: 0x20 */
    volatile uint32_t CMP2xR;     /*!< HRTIM Timerx compare 2 register,                            Address offset: 0x24 */
    volatile uint32_t CMP3xR;     /*!< HRTIM Timerx compare 3 register,                            Address offset: 0x28 */
    volatile uint32_t CMP4xR;     /*!< HRTIM Timerx compare 4 register,                            Address offset: 0x2C */
    volatile uint32_t CPT1xR;     /*!< HRTIM Timerx capture 1 register,                            Address offset: 0x30 */
    volatile uint32_t CPT2xR;     /*!< HRTIM Timerx capture 2 register,                            Address offset: 0x34 */
    volatile uint32_t DTxR;       /*!< HRTIM Timerx dead time register,                            Address offset: 0x38 */
    volatile uint32_t SETx1R;     /*!< HRTIM Timerx output 1 set register,                         Address offset: 0x3C */
    volatile uint32_t RSTx1R;     /*!< HRTIM Timerx output 1 reset register,                       Address offset: 0x40 */
    volatile uint32_t SETx2R;     /*!< HRTIM Timerx output 2 set register,                         Address offset: 0x44 */
    volatile uint32_t RSTx2R;     /*!< HRTIM Timerx output 2 reset register,                       Address offset: 0x48 */
    volatile uint32_t EEFxR1;     /*!< HRTIM Timerx external event filtering 1 register,           Address offset: 0x4C */
    volatile uint32_t EEFxR2;     /*!< HRTIM Timerx external event filtering 2 register,           Address offset: 0x50 */
    volatile uint32_t RSTxR;      /*!< HRTIM Timerx Reset register,                                Address offset: 0x54 */
    volatile uint32_t CHPxR;      /*!< HRTIM Timerx Chopper register,                              Address offset: 0x58 */
    volatile uint32_t CPT1xCR;    /*!< HRTIM Timerx Capture 1 register,                            Address offset: 0x5C */
    volatile uint32_t CPT2xCR;    /*!< HRTIM Timerx Capture 2 register,                            Address offset: 0x60 */
    volatile uint32_t OUTxR;      /*!< HRTIM Timerx Output register,                               Address offset: 0x64 */
    volatile uint32_t FLTxR;      /*!< HRTIM Timerx Fault register,                                Address offset: 0x68 */
             uint32_t RESERVED0[5];  /*!< Reserved,                                                          0x6C..0x7C */
}HRTIM_Timerx_TypeDef;

/* HRTIM common register definition */
typedef struct
{
    volatile uint32_t CR1;        /*!< HRTIM control register1,                                    Address offset: 0x00 */
    volatile uint32_t CR2;        /*!< HRTIM control register2,                                    Address offset: 0x04 */
    volatile uint32_t ISR;        /*!< HRTIM interrupt status register,                            Address offset: 0x08 */
    volatile uint32_t ICR;        /*!< HRTIM interrupt clear register,                             Address offset: 0x0C */
    volatile uint32_t IER;        /*!< HRTIM interrupt enable register,                            Address offset: 0x10 */
    volatile uint32_t OENR;       /*!< HRTIM Output enable register,                               Address offset: 0x14 */
    volatile uint32_t ODISR;      /*!< HRTIM Output disable register,                              Address offset: 0x18 */
    volatile uint32_t ODSR;       /*!< HRTIM Output disable status register,                       Address offset: 0x1C */
    volatile uint32_t BMCR;       /*!< HRTIM Burst mode control register,                          Address offset: 0x20 */
    volatile uint32_t BMTRGR;     /*!< HRTIM Burst mode trigger register,                          Address offset: 0x24 */
    volatile uint32_t BMCMPR;     /*!< HRTIM Burst mode compare register,                          Address offset: 0x28 */
    volatile uint32_t BMPER;      /*!< HRTIM Burst mode period register,                           Address offset: 0x2C */
    volatile uint32_t EECR1;      /*!< HRTIM Timer external event control register1,               Address offset: 0x30 */
    volatile uint32_t EECR2;      /*!< HRTIM Timer external event control register2,               Address offset: 0x34 */
    volatile uint32_t EECR3;      /*!< HRTIM Timer external event control register3,               Address offset: 0x38 */
    volatile uint32_t ADC1R;      /*!< HRTIM ADC Trigger 1 register,                               Address offset: 0x3C */
    volatile uint32_t ADC2R;      /*!< HRTIM ADC Trigger 2 register,                               Address offset: 0x40 */
    volatile uint32_t ADC3R;      /*!< HRTIM ADC Trigger 3 register,                               Address offset: 0x44 */
    volatile uint32_t ADC4R;      /*!< HRTIM ADC Trigger 4 register,                               Address offset: 0x48 */
    volatile uint32_t RESERVED0;  /*!< Reserved,                                                   Address offset: 0x4C */
    volatile uint32_t FLTINR1;    /*!< HRTIM Fault input register1,                                Address offset: 0x50 */
    volatile uint32_t FLTINR2;    /*!< HRTIM Fault input register2,                                Address offset: 0x54 */
    volatile uint32_t BDMUPR;     /*!< HRTIM Burst DMA Master Timer update register,               Address offset: 0x58 */
    volatile uint32_t BDTAUPR;    /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x5C */
    volatile uint32_t BDTBUPR;    /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x60 */
    volatile uint32_t BDTCUPR;    /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x64 */
    volatile uint32_t BDTDUPR;    /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x68 */
    volatile uint32_t BDTEUPR;    /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x6C */
    volatile uint32_t BDMADR;     /*!< HRTIM Burst DMA Master Data register,                       Address offset: 0x70 */
}HRTIM_Common_TypeDef;

/* HRTIM  register definition */
typedef struct {
  HRTIM_Master_TypeDef sMasterRegs;
  HRTIM_Timerx_TypeDef sTimerxRegs[5];
              uint32_t RESERVED0[32];
  HRTIM_Common_TypeDef sCommonRegs;
}HRTIM_TypeDef;

/**
  * @brief RNG
  */
typedef struct
{
    volatile uint32_t CR;  /*!< RNG control register, Address offset: 0x00 */
    volatile uint32_t SR;  /*!< RNG status register,  Address offset: 0x04 */
    volatile uint32_t DR;  /*!< RNG data register,    Address offset: 0x08 */
} RNG_TypeDef;

/**
  * @brief MDIOS
  */
typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t WRFR;
    volatile uint32_t CWRFR;
    volatile uint32_t RDFR;
    volatile uint32_t CRDFR;
    volatile uint32_t SR;
    volatile uint32_t CLRFR;
             uint32_t RESERVED[57];
    volatile uint32_t DINR0;
    volatile uint32_t DINR1;
    volatile uint32_t DINR2;
    volatile uint32_t DINR3;
    volatile uint32_t DINR4;
    volatile uint32_t DINR5;
    volatile uint32_t DINR6;
    volatile uint32_t DINR7;
    volatile uint32_t DINR8;
    volatile uint32_t DINR9;
    volatile uint32_t DINR10;
    volatile uint32_t DINR11;
    volatile uint32_t DINR12;
    volatile uint32_t DINR13;
    volatile uint32_t DINR14;
    volatile uint32_t DINR15;
    volatile uint32_t DINR16;
    volatile uint32_t DINR17;
    volatile uint32_t DINR18;
    volatile uint32_t DINR19;
    volatile uint32_t DINR20;
    volatile uint32_t DINR21;
    volatile uint32_t DINR22;
    volatile uint32_t DINR23;
    volatile uint32_t DINR24;
    volatile uint32_t DINR25;
    volatile uint32_t DINR26;
    volatile uint32_t DINR27;
    volatile uint32_t DINR28;
    volatile uint32_t DINR29;
    volatile uint32_t DINR30;
    volatile uint32_t DINR31;
    volatile uint32_t DOUTR0;
    volatile uint32_t DOUTR1;
    volatile uint32_t DOUTR2;
    volatile uint32_t DOUTR3;
    volatile uint32_t DOUTR4;
    volatile uint32_t DOUTR5;
    volatile uint32_t DOUTR6;
    volatile uint32_t DOUTR7;
    volatile uint32_t DOUTR8;
    volatile uint32_t DOUTR9;
    volatile uint32_t DOUTR10;
    volatile uint32_t DOUTR11;
    volatile uint32_t DOUTR12;
    volatile uint32_t DOUTR13;
    volatile uint32_t DOUTR14;
    volatile uint32_t DOUTR15;
    volatile uint32_t DOUTR16;
    volatile uint32_t DOUTR17;
    volatile uint32_t DOUTR18;
    volatile uint32_t DOUTR19;
    volatile uint32_t DOUTR20;
    volatile uint32_t DOUTR21;
    volatile uint32_t DOUTR22;
    volatile uint32_t DOUTR23;
    volatile uint32_t DOUTR24;
    volatile uint32_t DOUTR25;
    volatile uint32_t DOUTR26;
    volatile uint32_t DOUTR27;
    volatile uint32_t DOUTR28;
    volatile uint32_t DOUTR29;
    volatile uint32_t DOUTR30;
    volatile uint32_t DOUTR31;
} MDIOS_TypeDef;

/**
  * @brief USB_OTG_Core_Registers
  */
typedef struct
{
    volatile uint32_t GOTGCTL;              /*!< USB_OTG Control and Status Register          000h */
    volatile uint32_t GOTGINT;              /*!< USB_OTG Interrupt Register                   004h */
    volatile uint32_t GAHBCFG;              /*!< Core AHB Configuration Register              008h */
    volatile uint32_t GUSBCFG;              /*!< Core USB Configuration Register              00Ch */
    volatile uint32_t GRSTCTL;              /*!< Core Reset Register                          010h */
    volatile uint32_t GINTSTS;              /*!< Core Interrupt Register                      014h */
    volatile uint32_t GINTMSK;              /*!< Core Interrupt Mask Register                 018h */
    volatile uint32_t GRXSTSR;              /*!< Receive Sts Q Read Register                  01Ch */
    volatile uint32_t GRXSTSP;              /*!< Receive Sts Q Read & POP Register            020h */
    volatile uint32_t GRXFSIZ;              /*!< Receive FIFO Size Register                   024h */
    volatile uint32_t DIEPTXF0_HNPTXFSIZ;   /*!< EP0 / Non Periodic Tx FIFO Size Register     028h */
    volatile uint32_t HNPTXSTS;             /*!< Non Periodic Tx FIFO/Queue Sts reg           02Ch */
             uint32_t Reserved30[2];        /*!< Reserved                                     030h */
    volatile uint32_t GCCFG;                /*!< General Purpose IO Register                  038h */
    volatile uint32_t CID;                  /*!< User ID Register                             03Ch */
    volatile uint32_t GSNPSID;              /*!< USB_OTG core ID                                040h*/
    volatile uint32_t GHWCFG1;              /*!< User HW config1                                044h*/
    volatile uint32_t GHWCFG2;              /*!< User HW config2                                048h*/
    volatile uint32_t GHWCFG3;              /*!< User HW config3                              04Ch */
             uint32_t Reserved6;            /*!< Reserved                                     050h */
    volatile uint32_t GLPMCFG;              /*!< LPM Register                                 054h */
    volatile uint32_t GPWRDN;               /*!< Power Down Register                          058h */
    volatile uint32_t GDFIFOCFG;            /*!< DFIFO Software Config Register               05Ch */
    volatile uint32_t GADPCTL;              /*!< ADP Timer, Control and Status Register       60Ch */
    uint32_t  Reserved43[39];               /*!< Reserved                                058h-0FFh */
    volatile uint32_t HPTXFSIZ;             /*!< Host Periodic Tx FIFO Size Reg               100h */
    volatile uint32_t DIEPTXF[0x0F];        /*!< dev Periodic Transmit FIFO */
} USB_OTG_GlobalTypeDef;

/**
  * @brief USB_OTG_device_Registers
  */
typedef struct
{
    volatile uint32_t DCFG;            /*!< dev Configuration Register   800h */
    volatile uint32_t DCTL;            /*!< dev Control Register         804h */
    volatile uint32_t DSTS;            /*!< dev Status Register (RO)     808h */
             uint32_t Reserved0C;      /*!< Reserved                     80Ch */
    volatile uint32_t DIEPMSK;         /*!< dev IN Endpoint Mask         810h */
    volatile uint32_t DOEPMSK;         /*!< dev OUT Endpoint Mask        814h */
    volatile uint32_t DAINT;           /*!< dev All Endpoints Itr Reg    818h */
    volatile uint32_t DAINTMSK;        /*!< dev All Endpoints Itr Mask   81Ch */
             uint32_t Reserved20;      /*!< Reserved                     820h */
             uint32_t Reserved9;       /*!< Reserved                     824h */
    volatile uint32_t DVBUSDIS;        /*!< dev VBUS discharge Register  828h */
    volatile uint32_t DVBUSPULSE;      /*!< dev VBUS Pulse Register      82Ch */
    volatile uint32_t DTHRCTL;         /*!< dev threshold                830h */
    volatile uint32_t DIEPEMPMSK;      /*!< dev empty msk                834h */
    volatile uint32_t DEACHINT;        /*!< dedicated EP interrupt       838h */
    volatile uint32_t DEACHMSK;        /*!< dedicated EP msk             83Ch */
             uint32_t Reserved40;      /*!< dedicated EP mask            840h */
    volatile uint32_t DINEP1MSK;       /*!< dedicated EP mask            844h */
             uint32_t Reserved44[15];  /*!< Reserved                 844-87Ch */
    volatile uint32_t DOUTEP1MSK;      /*!< dedicated EP msk             884h */
} USB_OTG_DeviceTypeDef;


/**
  * @brief USB_OTG_IN_Endpoint-Specific_Register
  */
typedef struct
{
    volatile uint32_t DIEPCTL;           /*!< dev IN Endpoint Control Reg    900h + (ep_num * 20h) + 00h */
             uint32_t Reserved04;        /*!< Reserved                       900h + (ep_num * 20h) + 04h */
    volatile uint32_t DIEPINT;           /*!< dev IN Endpoint Itr Reg        900h + (ep_num * 20h) + 08h */
             uint32_t Reserved0C;        /*!< Reserved                       900h + (ep_num * 20h) + 0Ch */
    volatile uint32_t DIEPTSIZ;          /*!< IN Endpoint Txfer Size         900h + (ep_num * 20h) + 10h */
    volatile uint32_t DIEPDMA;           /*!< IN Endpoint DMA Address Reg    900h + (ep_num * 20h) + 14h */
    volatile uint32_t DTXFSTS;           /*!< IN Endpoint Tx FIFO Status Reg 900h + (ep_num * 20h) + 18h */
             uint32_t Reserved18;        /*!< Reserved  900h+(ep_num*20h)+1Ch-900h+ (ep_num * 20h) + 1Ch */
} USB_OTG_INEndpointTypeDef;

/**
  * @brief USB_OTG_OUT_Endpoint-Specific_Registers
  */
typedef struct
{
    volatile uint32_t DOEPCTL;       /*!< dev OUT Endpoint Control Reg           B00h + (ep_num * 20h) + 00h */
             uint32_t Reserved04;    /*!< Reserved                               B00h + (ep_num * 20h) + 04h */
    volatile uint32_t DOEPINT;       /*!< dev OUT Endpoint Itr Reg               B00h + (ep_num * 20h) + 08h */
             uint32_t Reserved0C;    /*!< Reserved                               B00h + (ep_num * 20h) + 0Ch */
    volatile uint32_t DOEPTSIZ;      /*!< dev OUT Endpoint Txfer Size            B00h + (ep_num * 20h) + 10h */
    volatile uint32_t DOEPDMA;       /*!< dev OUT Endpoint DMA Address           B00h + (ep_num * 20h) + 14h */
             uint32_t Reserved18[2]; /*!< Reserved B00h + (ep_num * 20h) + 18h - B00h + (ep_num * 20h) + 1Ch */
} USB_OTG_OUTEndpointTypeDef;


/**
  * @brief USB_OTG_Host_Mode_Register_Structures
  */
typedef struct
{
    volatile uint32_t HCFG;             /*!< Host Configuration Register          400h */
    volatile uint32_t HFIR;             /*!< Host Frame Interval Register         404h */
    volatile uint32_t HFNUM;            /*!< Host Frame Nbr/Frame Remaining       408h */
             uint32_t Reserved40C;      /*!< Reserved                             40Ch */
    volatile uint32_t HPTXSTS;          /*!< Host Periodic Tx FIFO/ Queue Status  410h */
    volatile uint32_t HAINT;            /*!< Host All Channels Interrupt Register 414h */
    volatile uint32_t HAINTMSK;         /*!< Host All Channels Interrupt Mask     418h */
} USB_OTG_HostTypeDef;

/**
  * @brief USB_OTG_Host_Channel_Specific_Registers
  */
typedef struct
{
    volatile uint32_t HCCHAR;           /*!< Host Channel Characteristics Register    500h */
    volatile uint32_t HCSPLT;           /*!< Host Channel Split Control Register      504h */
    volatile uint32_t HCINT;            /*!< Host Channel Interrupt Register          508h */
    volatile uint32_t HCINTMSK;         /*!< Host Channel Interrupt Mask Register     50Ch */
    volatile uint32_t HCTSIZ;           /*!< Host Channel Transfer Size Register      510h */
    volatile uint32_t HCDMA;            /*!< Host Channel DMA Address Register        514h */
  uint32_t Reserved[2];           /*!< Reserved                                      */
} USB_OTG_HostChannelTypeDef;

/**
  * @brief Global Programmer View
  */
typedef struct
{
             uint32_t RESERVED0[2036];     /*!< Reserved,                                                                           Address offset: 0x00-0x1FCC     */
    volatile uint32_t AXI_PERIPH_ID_4;     /*!< AXI interconnect - peripheral ID4 register,                                         Address offset: 0x1FD0          */
             uint32_t AXI_PERIPH_ID_5;     /*!< Reserved,                                                                           Address offset: 0x1FD4          */
             uint32_t AXI_PERIPH_ID_6;     /*!< Reserved,                                                                           Address offset: 0x1FD8          */
             uint32_t AXI_PERIPH_ID_7;     /*!< Reserved,                                                                           Address offset: 0x1FDC          */
    volatile uint32_t AXI_PERIPH_ID_0;     /*!< AXI interconnect - peripheral ID0 register,                                         Address offset: 0x1FE0          */
    volatile uint32_t AXI_PERIPH_ID_1;     /*!< AXI interconnect - peripheral ID1 register,                                         Address offset: 0x1FE4          */
    volatile uint32_t AXI_PERIPH_ID_2;     /*!< AXI interconnect - peripheral ID2 register,                                         Address offset: 0x1FE8          */
    volatile uint32_t AXI_PERIPH_ID_3;     /*!< AXI interconnect - peripheral ID3 register,                                         Address offset: 0x1FEC          */
    volatile uint32_t AXI_COMP_ID_0;       /*!< AXI interconnect - component ID0 register,                                          Address offset: 0x1FF0          */
    volatile uint32_t AXI_COMP_ID_1;       /*!< AXI interconnect - component ID1 register,                                          Address offset: 0x1FF4          */
    volatile uint32_t AXI_COMP_ID_2;       /*!< AXI interconnect - component ID2 register,                                          Address offset: 0x1FF8          */
    volatile uint32_t AXI_COMP_ID_3;       /*!< AXI interconnect - component ID3 register,                                          Address offset: 0x1FFC          */
             uint32_t RESERVED1[2];        /*!< Reserved,                                                                           Address offset: 0x2000-0x2004   */
    volatile uint32_t AXI_TARG1_FN_MOD_ISS_BM;  /*!< AXI interconnect - TARG 1 bus matrix issuing functionality register,           Address offset: 0x2008          */
             uint32_t RESERVED2[6];        /*!< Reserved,                                                                           Address offset: 0x200C-0x2020   */
    volatile uint32_t AXI_TARG1_FN_MOD2;   /*!< AXI interconnect - TARG 1 bus matrix functionality 2 register,                      Address offset: 0x2024          */
             uint32_t RESERVED3;           /*!< Reserved,                                                                           Address offset: 0x2028          */
    volatile uint32_t AXI_TARG1_FN_MOD_LB; /*!< AXI interconnect - TARG 1 long burst functionality modification register,           Address offset: 0x202C          */
             uint32_t RESERVED4[54];       /*!< Reserved,                                                                           Address offset: 0x2030-0x2104   */
    volatile uint32_t AXI_TARG1_FN_MOD;    /*!< AXI interconnect - TARG 1 issuing functionality modification register,              Address offset: 0x2108          */
             uint32_t RESERVED5[959];      /*!< Reserved,                                                                           Address offset: 0x210C-0x3004   */
    volatile uint32_t AXI_TARG2_FN_MOD_ISS_BM;  /*!< AXI interconnect - TARG 2 bus matrix issuing functionality register,           Address offset: 0x3008          */
             uint32_t RESERVED6[6];        /*!< Reserved,                                                                           Address offset: 0x300C-0x3020   */
    volatile uint32_t AXI_TARG2_FN_MOD2;   /*!< AXI interconnect - TARG 2 bus matrix functionality 2 register,                      Address offset: 0x3024          */
             uint32_t RESERVED7;           /*!< Reserved,                                                                           Address offset: 0x3028          */
    volatile uint32_t AXI_TARG2_FN_MOD_LB; /*!< AXI interconnect - TARG 2 long burst functionality modification register,           Address offset: 0x302C          */
             uint32_t RESERVED8[54];       /*!< Reserved,                                                                           Address offset: 0x3030-0x3104   */
    volatile uint32_t AXI_TARG2_FN_MOD;    /*!< AXI interconnect - TARG 2 issuing functionality modification register,              Address offset: 0x3108          */
             uint32_t RESERVED9[959];      /*!< Reserved,                                                                           Address offset: 0x310C-0x4004   */
    volatile uint32_t AXI_TARG3_FN_MOD_ISS_BM;   /*!< AXI interconnect - TARG 3 bus matrix issuing functionality register,          Address offset: 0x4008          */
             uint32_t RESERVED10[1023];    /*!< Reserved,                                                                           Address offset: 0x400C-0x5004   */
    volatile uint32_t AXI_TARG4_FN_MOD_ISS_BM;  /*!< AXI interconnect - TARG 4 bus matrix issuing functionality register,           Address offset: 0x5008          */
             uint32_t RESERVED11[1023];    /*!< Reserved,                                                                           Address offset: 0x500C-0x6004   */
    volatile uint32_t AXI_TARG5_FN_MOD_ISS_BM;  /*!< AXI interconnect - TARG 5 bus matrix issuing functionality register,           Address offset: 0x6008          */
             uint32_t RESERVED12[1023];    /*!< Reserved,                                                                           Address offset: 0x600C-0x7004   */
    volatile uint32_t AXI_TARG6_FN_MOD_ISS_BM;  /*!< AXI interconnect - TARG 6 bus matrix issuing functionality register,           Address offset: 0x7008          */
             uint32_t RESERVED13[1023];    /*!< Reserved,                                                                           Address offset: 0x700C-0x8004   */
    volatile uint32_t AXI_TARG7_FN_MOD_ISS_BM;  /*!< AXI interconnect - TARG 7 bus matrix issuing functionality register,           Address offset: 0x8008          */
             uint32_t RESERVED14[6];       /*!< Reserved,                                                                           Address offset: 0x800C-0x8020   */
    volatile uint32_t AXI_TARG7_FN_MOD2;   /*!< AXI interconnect - TARG 7 bus matrix functionality 2 register,                      Address offset: 0x8024          */
             uint32_t RESERVED15;          /*!< Reserved,                                                                           Address offset: 0x8028          */
    volatile uint32_t AXI_TARG7_FN_MOD_LB; /*!< AXI interconnect - TARG 7 long burst functionality modification register,           Address offset: 0x802C          */
             uint32_t RESERVED16[54];      /*!< Reserved,                                                                           Address offset: 0x8030-0x8104   */
    volatile uint32_t AXI_TARG7_FN_MOD;    /*!< AXI interconnect - TARG 7 issuing functionality modification register,              Address offset: 0x8108          */
             uint32_t RESERVED17[59334];   /*!< Reserved,                                                                          Address offset: 0x810C-0x42020  */
    volatile uint32_t AXI_INI1_FN_MOD2;    /*!< AXI interconnect - INI 1 functionality modification 2 register,                     Address offset: 0x42024         */
    volatile uint32_t AXI_INI1_FN_MOD_AHB; /*!< AXI interconnect - INI 1 AHB functionality modification register,                   Address offset: 0x42028         */
             uint32_t RESERVED18[53];      /*!< Reserved,                                                                           Address offset: 0x4202C-0x420FC */
    volatile uint32_t AXI_INI1_READ_QOS;   /*!< AXI interconnect - INI 1 read QoS register,                                         Address offset: 0x42100         */
    volatile uint32_t AXI_INI1_WRITE_QOS;  /*!< AXI interconnect - INI 1 write QoS register,                                        Address offset: 0x42104         */
    volatile uint32_t AXI_INI1_FN_MOD;     /*!< AXI interconnect - INI 1 issuing functionality modification register,               Address offset: 0x42108         */
             uint32_t RESERVED19[1021];    /*!< Reserved,                                                                           Address offset: 0x4210C-0x430FC */
    volatile uint32_t AXI_INI2_READ_QOS;   /*!< AXI interconnect - INI 2 read QoS register,                                         Address offset: 0x43100         */
    volatile uint32_t AXI_INI2_WRITE_QOS;  /*!< AXI interconnect - INI 2 write QoS register,                                        Address offset: 0x43104         */
    volatile uint32_t AXI_INI2_FN_MOD;     /*!< AXI interconnect - INI 2 issuing functionality modification register,               Address offset: 0x43108         */
             uint32_t RESERVED20[966];     /*!< Reserved,                                                                           Address offset: 0x4310C-0x44020 */
    volatile uint32_t AXI_INI3_FN_MOD2;    /*!< AXI interconnect - INI 3 functionality modification 2 register,                     Address offset: 0x44024         */
    volatile uint32_t AXI_INI3_FN_MOD_AHB; /*!< AXI interconnect - INI 3 AHB functionality modification register,                   Address offset: 0x44028         */
             uint32_t RESERVED21[53];      /*!< Reserved,                                                                           Address offset: 0x4402C-0x440FC */
    volatile uint32_t AXI_INI3_READ_QOS;   /*!< AXI interconnect - INI 3 read QoS register,                                         Address offset: 0x44100         */
    volatile uint32_t AXI_INI3_WRITE_QOS;  /*!< AXI interconnect - INI 3 write QoS register,                                        Address offset: 0x44104         */
    volatile uint32_t AXI_INI3_FN_MOD;     /*!< AXI interconnect - INI 3 issuing functionality modification register,               Address offset: 0x44108         */
             uint32_t RESERVED22[1021];    /*!< Reserved,                                                                           Address offset: 0x4410C-0x450FC */
    volatile uint32_t AXI_INI4_READ_QOS;   /*!< AXI interconnect - INI 4 read QoS register,                                         Address offset: 0x45100         */
    volatile uint32_t AXI_INI4_WRITE_QOS;  /*!< AXI interconnect - INI 4 write QoS register,                                        Address offset: 0x45104         */
    volatile uint32_t AXI_INI4_FN_MOD;     /*!< AXI interconnect - INI 4 issuing functionality modification register,               Address offset: 0x45108         */
             uint32_t RESERVED23[1021];    /*!< Reserved,                                                                           Address offset: 0x4510C-0x460FC */
    volatile uint32_t AXI_INI5_READ_QOS;   /*!< AXI interconnect - INI 5 read QoS register,                                         Address offset: 0x46100         */
    volatile uint32_t AXI_INI5_WRITE_QOS;  /*!< AXI interconnect - INI 5 write QoS register,                                        Address offset: 0x46104         */
    volatile uint32_t AXI_INI5_FN_MOD;     /*!< AXI interconnect - INI 5 issuing functionality modification register,               Address offset: 0x46108         */
             uint32_t RESERVED24[1021];    /*!< Reserved,                                                                           Address offset: 0x4610C-0x470FC */
    volatile uint32_t AXI_INI6_READ_QOS;   /*!< AXI interconnect - INI 6 read QoS register,                                         Address offset: 0x47100         */
    volatile uint32_t AXI_INI6_WRITE_QOS;  /*!< AXI interconnect - INI 6 write QoS register,                                        Address offset: 0x47104         */
    volatile uint32_t AXI_INI6_FN_MOD;     /*!< AXI interconnect - INI 6 issuing functionality modification register,               Address offset: 0x47108         */
             uint32_t RESERVED25[1021];    /*!< Reserved,                                                                           Address offset: 0x4710C-0x480FC */
    volatile uint32_t AXI_INI7_READ_QOS;   /*!< AXI interconnect - INI 7 read QoS register,                                         Address offset: 0x48100         */
    volatile uint32_t AXI_INI7_WRITE_QOS;  /*!< AXI interconnect - INI 7 write QoS register,                                        Address offset: 0x48104         */
    volatile uint32_t AXI_INI7_FN_MOD;     /*!< AXI interconnect - INI 7 issuing functionality modification register,               Address offset: 0x48108         */
} GPV_TypeDef;

/* END of Peripheral registers structures */

#endif