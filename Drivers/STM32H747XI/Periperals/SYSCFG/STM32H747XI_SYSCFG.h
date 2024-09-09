#ifndef STM32H747XI_SYSCFG_H
#define STM32H747XI_SYSCFG_H

#include "Common.h"
#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"

/* Refer to RM0399 Reference Manual from http://www.st.com */

/* SYSCFG Register - Refer to CMSIS Library */
typedef struct
{
    volatile uint32_t RESERVED1;      /**< Reserved,                                           Address offset: 0x00        */
    volatile uint32_t PMCR;           /**< SYSCFG peripheral mode configuration register,      Address offset: 0x04        */
    volatile uint32_t EXTICR[4];      /**< SYSCFG external interrupt configuration registers,  Address offset: 0x08-0x14   */
    volatile uint32_t CFGR;           /**< SYSCFG configuration registers,                     Address offset: 0x18        */
    volatile uint32_t RESERVED2;      /**< Reserved,                                           Address offset: 0x1C        */
    volatile uint32_t CCCSR;          /**< SYSCFG compensation cell control/status register,   Address offset: 0x20        */
    volatile uint32_t CCVR;           /**< SYSCFG compensation cell value register,            Address offset: 0x24        */
    volatile uint32_t CCCR;           /**< SYSCFG compensation cell code register,             Address offset: 0x28        */
    volatile uint32_t PWRCR;          /**< PWR control register,                               Address offset: 0x2C        */
    volatile uint32_t RESERVED3[61];  /**< Reserved, 0x30-0x120                                                            */
    volatile uint32_t PKGR;           /**< SYSCFG package register,                            Address offset: 0x124       */
    volatile uint32_t RESERVED4[118]; /**< Reserved, 0x128-0x2FC                                                           */
    volatile uint32_t UR0;            /**< SYSCFG user register 0,                             Address offset: 0x300       */
    volatile uint32_t UR1;            /**< SYSCFG user register 1,                             Address offset: 0x304       */
    volatile uint32_t UR2;            /**< SYSCFG user register 2,                             Address offset: 0x308       */
    volatile uint32_t UR3;            /**< SYSCFG user register 3,                             Address offset: 0x30C       */
    volatile uint32_t UR4;            /**< SYSCFG user register 4,                             Address offset: 0x310       */
    volatile uint32_t UR5;            /**< SYSCFG user register 5,                             Address offset: 0x314       */
    volatile uint32_t UR6;            /**< SYSCFG user register 6,                             Address offset: 0x318       */
    volatile uint32_t UR7;            /**< SYSCFG user register 7,                             Address offset: 0x31C       */
    volatile uint32_t UR8;            /**< SYSCFG user register 8,                             Address offset: 0x320       */
    volatile uint32_t UR9;            /**< SYSCFG user register 9,                             Address offset: 0x324       */
    volatile uint32_t UR10;           /**< SYSCFG user register 10,                            Address offset: 0x328       */
    volatile uint32_t UR11;           /**< SYSCFG user register 11,                            Address offset: 0x32C       */
    volatile uint32_t UR12;           /**< SYSCFG user register 12,                            Address offset: 0x330       */
    volatile uint32_t UR13;           /**< SYSCFG user register 13,                            Address offset: 0x334       */
    volatile uint32_t UR14;           /**< SYSCFG user register 14,                            Address offset: 0x338       */
    volatile uint32_t UR15;           /**< SYSCFG user register 15,                            Address offset: 0x33C       */
    volatile uint32_t UR16;           /**< SYSCFG user register 16,                            Address offset: 0x340       */
    volatile uint32_t UR17;           /**< SYSCFG user register 17,                            Address offset: 0x344       */
} SYSCFG_ST;

#define SYSCFG_BASE     0x58000400UL    /* SYSCFG Base Address */

/* SYSCFG Declaration */
#define SYSCFG         ((SYSCFG_ST *) SYSCFG_BASE)

#define RCC_APB4ENR_SYSCFGEN    (1 << 1)


extern void SYSCFG_Enable(void);
extern void SYSCFG_EXITx_GPIO_Cfg(GPIO_ST *GPIOx, uint8_t GPIO_Pin);

#endif