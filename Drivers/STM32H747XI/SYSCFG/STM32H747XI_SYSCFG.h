#ifndef STM32H747XI_SYSCFG_H
#define STM32H747XI_SYSCFG_H

#include "Common.h"
#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"

/* Refer to RM0399 Reference Manual from http://www.st.com */

/* SYSCFG Register - Refer to CMSIS Library */
typedef struct
{
    volatile UINT32 RESERVED1;      /**< Reserved,                                           Address offset: 0x00        */
    volatile UINT32 PMCR;           /**< SYSCFG peripheral mode configuration register,      Address offset: 0x04        */
    volatile UINT32 EXTICR[4];      /**< SYSCFG external interrupt configuration registers,  Address offset: 0x08-0x14   */
    volatile UINT32 CFGR;           /**< SYSCFG configuration registers,                     Address offset: 0x18        */
    volatile UINT32 RESERVED2;      /**< Reserved,                                           Address offset: 0x1C        */
    volatile UINT32 CCCSR;          /**< SYSCFG compensation cell control/status register,   Address offset: 0x20        */
    volatile UINT32 CCVR;           /**< SYSCFG compensation cell value register,            Address offset: 0x24        */
    volatile UINT32 CCCR;           /**< SYSCFG compensation cell code register,             Address offset: 0x28        */
    volatile UINT32 PWRCR;          /**< PWR control register,                               Address offset: 0x2C        */
    volatile UINT32 RESERVED3[61];  /**< Reserved, 0x30-0x120                                                            */
    volatile UINT32 PKGR;           /**< SYSCFG package register,                            Address offset: 0x124       */
    volatile UINT32 RESERVED4[118]; /**< Reserved, 0x128-0x2FC                                                           */
    volatile UINT32 UR0;            /**< SYSCFG user register 0,                             Address offset: 0x300       */
    volatile UINT32 UR1;            /**< SYSCFG user register 1,                             Address offset: 0x304       */
    volatile UINT32 UR2;            /**< SYSCFG user register 2,                             Address offset: 0x308       */
    volatile UINT32 UR3;            /**< SYSCFG user register 3,                             Address offset: 0x30C       */
    volatile UINT32 UR4;            /**< SYSCFG user register 4,                             Address offset: 0x310       */
    volatile UINT32 UR5;            /**< SYSCFG user register 5,                             Address offset: 0x314       */
    volatile UINT32 UR6;            /**< SYSCFG user register 6,                             Address offset: 0x318       */
    volatile UINT32 UR7;            /**< SYSCFG user register 7,                             Address offset: 0x31C       */
    volatile UINT32 UR8;            /**< SYSCFG user register 8,                             Address offset: 0x320       */
    volatile UINT32 UR9;            /**< SYSCFG user register 9,                             Address offset: 0x324       */
    volatile UINT32 UR10;           /**< SYSCFG user register 10,                            Address offset: 0x328       */
    volatile UINT32 UR11;           /**< SYSCFG user register 11,                            Address offset: 0x32C       */
    volatile UINT32 UR12;           /**< SYSCFG user register 12,                            Address offset: 0x330       */
    volatile UINT32 UR13;           /**< SYSCFG user register 13,                            Address offset: 0x334       */
    volatile UINT32 UR14;           /**< SYSCFG user register 14,                            Address offset: 0x338       */
    volatile UINT32 UR15;           /**< SYSCFG user register 15,                            Address offset: 0x33C       */
    volatile UINT32 UR16;           /**< SYSCFG user register 16,                            Address offset: 0x340       */
    volatile UINT32 UR17;           /**< SYSCFG user register 17,                            Address offset: 0x344       */
} SYSCFG_ST;

#define SYSCFG_BASE     0x58000400UL    /* SYSCFG Base Address */

/* SYSCFG Declaration */
#define SYSCFG         ((SYSCFG_ST *) SYSCFG_BASE)

#define RCC_APB4ENR_SYSCFGEN    (1 << 1)


/*
 * External declarations for SYSCFG functions:
 *   - SYSCFG_Enable: Enables the SYSCFG clock in RCC's APB4ENR register.
 *   - SYSCFG_EXITx_GPIO_Cfg: Configures EXTI for external interrupts on a GPIO pin.
 *
 * For SYSCFG_EXITx_GPIO_Cfg:
 *   Parameters:
 *     - GPIO_x_Num: GPIO Port number (e.g., GPIO_K_Num)
 *     - GPIO_Pin: GPIO Pin number (0 to 15)
 *   Notes:
 *     - GPIO K Pin from 8 to 15 is not supported for EXTI.
 */
extern void SYSCFG_Enable(void);
extern void SYSCFG_EXITx_GPIO_Cfg(UINT8 GPIO_x_Num, UINT8 GPIO_Pin);

#endif