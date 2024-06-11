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
    UINT32 IMR1;                /*!< EXTI Interrupt mask register,                    Address offset: 0x80 */
    UINT32 EMR1;                /*!< EXTI Event mask register,                        Address offset: 0x84 */
    UINT32 PR1;                 /*!< EXTI Pending register,                           Address offset: 0x88 */
    UINT32 RESERVED4;           /*!< Reserved,                                        0x8C                 */
    UINT32 IMR2;                /*!< EXTI Interrupt mask register,                    Address offset: 0x90 */
    UINT32 EMR2;                /*!< EXTI Event mask register,                        Address offset: 0x94 */
    UINT32 PR2;                 /*!< EXTI Pending register,                           Address offset: 0x98 */
    UINT32 RESERVED5;           /*!< Reserved,                                        0x9C                 */
    UINT32 IMR3;                /*!< EXTI Interrupt mask register,                    Address offset: 0xA0 */
    UINT32 EMR3;                /*!< EXTI Event mask register,                        Address offset: 0xA4 */
    UINT32 PR3;                 /*!< EXTI Pending register,                           Address offset: 0xA8 */
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

#endif