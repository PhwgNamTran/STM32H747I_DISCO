#ifndef STM32H747XI_GPIO_H
#define STM32H747XI_GPIO_H

#include "Common.h"
#include "STM32H747XI_RCC.h"

/* Refer to RM0399 Reference Manual from http://www.st.com */

/* GPIO Register - Refer to CMSIS Library */
typedef struct
{
    UINT32 MODER;    /* GPIO port mode register,                  Address offset: 0x00      */
    UINT32 OTYPER;   /* GPIO port output type register,           Address offset: 0x04      */
    UINT32 OSPEEDR;  /* GPIO port output speed register,          Address offset: 0x08      */
    UINT32 PUPDR;    /* GPIO port pull-up/pull-down register,     Address offset: 0x0C      */
    UINT32 IDR;      /* GPIO port input data register,            Address offset: 0x10      */
    UINT32 ODR;      /* GPIO port output data register,           Address offset: 0x14      */
    UINT32 BSRR;     /* GPIO port bit set/reset,                  Address offset: 0x18      */
    UINT32 LCKR;     /* GPIO port configuration lock register,    Address offset: 0x1C      */
    UINT32 AFR[2];   /* GPIO alternate function registers,        Address offset: 0x20-0x24 */
} GPIO_ST;

/* Base Address of GPIO Ports */
#define GPIO_A_BASE 0x58020000U
#define GPIO_B_BASE 0x58020400U
#define GPIO_C_BASE 0x58020800U
#define GPIO_D_BASE 0x58020C00U
#define GPIO_E_BASE 0x58021000U
#define GPIO_F_BASE 0x58021400U
#define GPIO_G_BASE 0x58021800U
#define GPIO_H_BASE 0x58021C00U
#define GPIO_I_BASE 0x58022000U
#define GPIO_J_BASE 0x58022400U
#define GPIO_K_BASE 0x58022800U

/* GPIO Declaration */
#define GPIO_A ((GPIO_ST *) GPIO_A_BASE)
#define GPIO_B ((GPIO_ST *) GPIO_B_BASE)
#define GPIO_C ((GPIO_ST *) GPIO_C_BASE)
#define GPIO_D ((GPIO_ST *) GPIO_D_BASE)
#define GPIO_E ((GPIO_ST *) GPIO_E_BASE)
#define GPIO_F ((GPIO_ST *) GPIO_F_BASE)
#define GPIO_G ((GPIO_ST *) GPIO_G_BASE)
#define GPIO_H ((GPIO_ST *) GPIO_H_BASE)
#define GPIO_I ((GPIO_ST *) GPIO_I_BASE)
#define GPIO_J ((GPIO_ST *) GPIO_J_BASE)
#define GPIO_K ((GPIO_ST *) GPIO_K_BASE)

/* GPIO Clocksoure bit in AHB4ENR Register */
#define GPIO_A_CLKSRC (1 << 0)
#define GPIO_B_CLKSRC (1 << 1)
#define GPIO_C_CLKSRC (1 << 2)
#define GPIO_D_CLKSRC (1 << 3)
#define GPIO_E_CLKSRC (1 << 4)
#define GPIO_F_CLKSRC (1 << 5)
#define GPIO_G_CLKSRC (1 << 6)
#define GPIO_H_CLKSRC (1 << 7)
#define GPIO_I_CLKSRC (1 << 8)
#define GPIO_J_CLKSRC (1 << 9)
#define GPIO_K_CLKSRC (1 << 10)

/* GPIO Pin number definition */
#define GPIO_PIN_0     0U
#define GPIO_PIN_1     1U
#define GPIO_PIN_2     2U
#define GPIO_PIN_3     3U
#define GPIO_PIN_4     4U
#define GPIO_PIN_5     5U
#define GPIO_PIN_6     6U
#define GPIO_PIN_7     7U
#define GPIO_PIN_8     8U
#define GPIO_PIN_9     9U
#define GPIO_PIN_10    10U
#define GPIO_PIN_11    11U
#define GPIO_PIN_12    12U
#define GPIO_PIN_13    13U
#define GPIO_PIN_14    14U
#define GPIO_PIN_15    15U

/* GPIO Mode Value */
#define GPIO_Mode_Input                     0U
#define GPIO_Mode_General_Purpose_Output    1U
#define GPIO_Mode_Alternate_Funtion         2U
#define GPIO_Mode_Analog                    3U

extern void GPIO_Enable_ClockSource(UINT16 GPIOx_CLKSRC);
extern void GPIO_Disable_ClockSource(UINT16 GPIOx_CLKSRC);

#endif