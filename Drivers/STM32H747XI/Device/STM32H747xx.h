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

/*
 * STM32H7XX Interrupt Number Definition
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


/* External Interrupt/Event Controller */
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

#endif