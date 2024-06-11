#ifndef STM32H747XI_SYSCFG_H
#define STM32H747XI_SYSCFG_H

#include "Common.h"

/* Refer to RM0399 Reference Manual from http://www.st.com */

/* SYSCFG Register - Refer to CMSIS Library */
typedef struct
{
    UINT32 RESERVED1;      /*!< Reserved,                                           Address offset: 0x00        */
    UINT32 PMCR;           /*!< SYSCFG peripheral mode configuration register,      Address offset: 0x04        */
    UINT32 EXTICR[4];      /*!< SYSCFG external interrupt configuration registers,  Address offset: 0x08-0x14   */
    UINT32 CFGR;           /*!< SYSCFG configuration registers,                     Address offset: 0x18        */
    UINT32 RESERVED2;      /*!< Reserved,                                           Address offset: 0x1C        */
    UINT32 CCCSR;          /*!< SYSCFG compensation cell control/status register,   Address offset: 0x20        */
    UINT32 CCVR;           /*!< SYSCFG compensation cell value register,            Address offset: 0x24        */
    UINT32 CCCR;           /*!< SYSCFG compensation cell code register,             Address offset: 0x28        */
    UINT32 PWRCR;          /*!< PWR control register,                               Address offset: 0x2C        */
    UINT32 RESERVED3[61];  /*!< Reserved, 0x30-0x120                                                            */
    UINT32 PKGR;           /*!< SYSCFG package register,                            Address offset: 0x124       */
    UINT32 RESERVED4[118]; /*!< Reserved, 0x128-0x2FC                                                           */
    UINT32 UR0;            /*!< SYSCFG user register 0,                             Address offset: 0x300       */
    UINT32 UR1;            /*!< SYSCFG user register 1,                             Address offset: 0x304       */
    UINT32 UR2;            /*!< SYSCFG user register 2,                             Address offset: 0x308       */
    UINT32 UR3;            /*!< SYSCFG user register 3,                             Address offset: 0x30C       */
    UINT32 UR4;            /*!< SYSCFG user register 4,                             Address offset: 0x310       */
    UINT32 UR5;            /*!< SYSCFG user register 5,                             Address offset: 0x314       */
    UINT32 UR6;            /*!< SYSCFG user register 6,                             Address offset: 0x318       */
    UINT32 UR7;            /*!< SYSCFG user register 7,                             Address offset: 0x31C       */
    UINT32 UR8;            /*!< SYSCFG user register 8,                             Address offset: 0x320       */
    UINT32 UR9;            /*!< SYSCFG user register 9,                             Address offset: 0x324       */
    UINT32 UR10;           /*!< SYSCFG user register 10,                            Address offset: 0x328       */
    UINT32 UR11;           /*!< SYSCFG user register 11,                            Address offset: 0x32C       */
    UINT32 UR12;           /*!< SYSCFG user register 12,                            Address offset: 0x330       */
    UINT32 UR13;           /*!< SYSCFG user register 13,                            Address offset: 0x334       */
    UINT32 UR14;           /*!< SYSCFG user register 14,                            Address offset: 0x338       */
    UINT32 UR15;           /*!< SYSCFG user register 15,                            Address offset: 0x33C       */
    UINT32 UR16;           /*!< SYSCFG user register 16,                            Address offset: 0x340       */
    UINT32 UR17;           /*!< SYSCFG user register 17,                            Address offset: 0x344       */
} SYSCFG_ST;

#endif