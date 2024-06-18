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

#define GPIO_A_Num 0
#define GPIO_B_Num 1
#define GPIO_C_Num 2
#define GPIO_D_Num 3
#define GPIO_E_Num 4
#define GPIO_F_Num 5
#define GPIO_G_Num 6
#define GPIO_H_Num 7
#define GPIO_I_Num 8
#define GPIO_J_Num 9
#define GPIO_K_Num 10

/* GPIO Clocksoure bit in AHB4ENR Register */
#define GPIO_A_CLKSRC (1 << GPIO_A_Num)
#define GPIO_B_CLKSRC (1 << GPIO_B_Num)
#define GPIO_C_CLKSRC (1 << GPIO_C_Num)
#define GPIO_D_CLKSRC (1 << GPIO_D_Num)
#define GPIO_E_CLKSRC (1 << GPIO_E_Num)
#define GPIO_F_CLKSRC (1 << GPIO_F_Num)
#define GPIO_G_CLKSRC (1 << GPIO_G_Num)
#define GPIO_H_CLKSRC (1 << GPIO_H_Num)
#define GPIO_I_CLKSRC (1 << GPIO_I_Num)
#define GPIO_J_CLKSRC (1 << GPIO_J_Num)
#define GPIO_K_CLKSRC (1 << GPIO_K_Num)

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

/* GPIO Reister Pull Value */
#define GPIO_No_Pull                        0U
#define GPIO_Pull_Up                        1U
#define GPIO_Pull_Down                      2U
#define GPIO_Pull_Reserved                  3U

/* GPIO Output Type Value */
#define GPIO_Output_PushPull                0U
#define GPIO_Output_OpenDrain               1U

extern void GPIO_Enable_ClockSource(UINT16 GPIOx_CLKSRC);
extern void GPIO_Disable_ClockSource(UINT16 GPIOx_CLKSRC);
extern void GPIO_Mode_Set(GPIO_ST *GPIOx, UINT16 Pin, UINT8 Mode);
extern void GPIO_Pull_Set(GPIO_ST *GPIOx, UINT16 Pin, UINT8 Pull);
extern void GPIO_OutputType_Set(GPIO_ST *GPIOx, UINT16 Pin, BOOL OutputType); 
extern void GPIO_OutputData_Set(GPIO_ST *GPIOx, UINT16 Pin);
extern void GPIO_OutputData_Reset(GPIO_ST *GPIOx, UINT16 Pin);
extern void GPIO_OutputData_Toggle(GPIO_ST *GPIOx, UINT16 Pin);

#endif