#ifndef STM32H747XI_GPIO_H
#define STM32H747XI_GPIO_H

#include "Common.h"
#include "STM32H747XI_RCC.h"

/* Refer to RM0399 Reference Manual from http://www.st.com */

/* GPIO Register - Refer to CMSIS Library */
typedef struct
{
    volatile UINT32 MODER;    /* GPIO port mode register,                  Address offset: 0x00      */
    volatile UINT32 OTYPER;   /* GPIO port output type register,           Address offset: 0x04      */
    volatile UINT32 OSPEEDR;  /* GPIO port output speed register,          Address offset: 0x08      */
    volatile UINT32 PUPDR;    /* GPIO port pull-up/pull-down register,     Address offset: 0x0C      */
    volatile UINT32 IDR;      /* GPIO port input data register,            Address offset: 0x10      */
    volatile UINT32 ODR;      /* GPIO port output data register,           Address offset: 0x14      */
    volatile UINT32 BSRR;     /* GPIO port bit set/reset,                  Address offset: 0x18      */
    volatile UINT32 LCKR;     /* GPIO port configuration lock register,    Address offset: 0x1C      */
    volatile UINT32 AFR[2];   /* GPIO alternate function registers,        Address offset: 0x20-0x24 */
} GPIO_ST;

/* Base Address of GPIO Ports */
#define GPIO_A_BASE 0x58020000U /**< Base address of GPIO Port A */
#define GPIO_B_BASE 0x58020400U /**< Base address of GPIO Port B */
#define GPIO_C_BASE 0x58020800U /**< Base address of GPIO Port C */
#define GPIO_D_BASE 0x58020C00U /**< Base address of GPIO Port D */
#define GPIO_E_BASE 0x58021000U /**< Base address of GPIO Port E */
#define GPIO_F_BASE 0x58021400U /**< Base address of GPIO Port F */
#define GPIO_G_BASE 0x58021800U /**< Base address of GPIO Port G */
#define GPIO_H_BASE 0x58021C00U /**< Base address of GPIO Port H */
#define GPIO_I_BASE 0x58022000U /**< Base address of GPIO Port I */
#define GPIO_J_BASE 0x58022400U /**< Base address of GPIO Port J */
#define GPIO_K_BASE 0x58022800U /**< Base address of GPIO Port K */

/* GPIO Declaration */
#define GPIO_A ((GPIO_ST *) GPIO_A_BASE) /**< GPIO Port A declaration */
#define GPIO_B ((GPIO_ST *) GPIO_B_BASE) /**< GPIO Port B declaration */
#define GPIO_C ((GPIO_ST *) GPIO_C_BASE) /**< GPIO Port C declaration */
#define GPIO_D ((GPIO_ST *) GPIO_D_BASE) /**< GPIO Port D declaration */
#define GPIO_E ((GPIO_ST *) GPIO_E_BASE) /**< GPIO Port E declaration */
#define GPIO_F ((GPIO_ST *) GPIO_F_BASE) /**< GPIO Port F declaration */
#define GPIO_G ((GPIO_ST *) GPIO_G_BASE) /**< GPIO Port G declaration */
#define GPIO_H ((GPIO_ST *) GPIO_H_BASE) /**< GPIO Port H declaration */
#define GPIO_I ((GPIO_ST *) GPIO_I_BASE) /**< GPIO Port I declaration */
#define GPIO_J ((GPIO_ST *) GPIO_J_BASE) /**< GPIO Port J declaration */
#define GPIO_K ((GPIO_ST *) GPIO_K_BASE) /**< GPIO Port K declaration */

/* GPIO Port Number Macros */
#define GPIO_A_Num 0   /**< GPIO Port A number */
#define GPIO_B_Num 1   /**< GPIO Port B number */
#define GPIO_C_Num 2   /**< GPIO Port C number */
#define GPIO_D_Num 3   /**< GPIO Port D number */
#define GPIO_E_Num 4   /**< GPIO Port E number */
#define GPIO_F_Num 5   /**< GPIO Port F number */
#define GPIO_G_Num 6   /**< GPIO Port G number */
#define GPIO_H_Num 7   /**< GPIO Port H number */
#define GPIO_I_Num 8   /**< GPIO Port I number */
#define GPIO_J_Num 9   /**< GPIO Port J number */
#define GPIO_K_Num 10  /**< GPIO Port K number */

/* GPIO Clock Source Bit in AHB4ENR Register */
#define GPIO_A_CLKSRC (1 << GPIO_A_Num) /**< GPIO Port A clock source bit */
#define GPIO_B_CLKSRC (1 << GPIO_B_Num) /**< GPIO Port B clock source bit */
#define GPIO_C_CLKSRC (1 << GPIO_C_Num) /**< GPIO Port C clock source bit */
#define GPIO_D_CLKSRC (1 << GPIO_D_Num) /**< GPIO Port D clock source bit */
#define GPIO_E_CLKSRC (1 << GPIO_E_Num) /**< GPIO Port E clock source bit */
#define GPIO_F_CLKSRC (1 << GPIO_F_Num) /**< GPIO Port F clock source bit */
#define GPIO_G_CLKSRC (1 << GPIO_G_Num) /**< GPIO Port G clock source bit */
#define GPIO_H_CLKSRC (1 << GPIO_H_Num) /**< GPIO Port H clock source bit */
#define GPIO_I_CLKSRC (1 << GPIO_I_Num) /**< GPIO Port I clock source bit */
#define GPIO_J_CLKSRC (1 << GPIO_J_Num) /**< GPIO Port J clock source bit */
#define GPIO_K_CLKSRC (1 << GPIO_K_Num) /**< GPIO Port K clock source bit */

/* GPIO Pin Number Definitions */
#define GPIO_PIN_0     0U  /**< GPIO Pin 0 */
#define GPIO_PIN_1     1U  /**< GPIO Pin 1 */
#define GPIO_PIN_2     2U  /**< GPIO Pin 2 */
#define GPIO_PIN_3     3U  /**< GPIO Pin 3 */
#define GPIO_PIN_4     4U  /**< GPIO Pin 4 */
#define GPIO_PIN_5     5U  /**< GPIO Pin 5 */
#define GPIO_PIN_6     6U  /**< GPIO Pin 6 */
#define GPIO_PIN_7     7U  /**< GPIO Pin 7 */
#define GPIO_PIN_8     8U  /**< GPIO Pin 8 */
#define GPIO_PIN_9     9U  /**< GPIO Pin 9 */
#define GPIO_PIN_10    10U /**< GPIO Pin 10 */
#define GPIO_PIN_11    11U /**< GPIO Pin 11 */
#define GPIO_PIN_12    12U /**< GPIO Pin 12 */
#define GPIO_PIN_13    13U /**< GPIO Pin 13 */
#define GPIO_PIN_14    14U /**< GPIO Pin 14 */
#define GPIO_PIN_15    15U /**< GPIO Pin 15 */

/* GPIO Alternate Functions number definitions */
#define GPIO_AF_0      0U  /**< GPIO Alternate Function 0 */
#define GPIO_AF_1      1U  /**< GPIO Alternate Function 1 */
#define GPIO_AF_2      2U  /**< GPIO Alternate Function 2 */
#define GPIO_AF_3      3U  /**< GPIO Alternate Function 3 */
#define GPIO_AF_4      4U  /**< GPIO Alternate Function 4 */
#define GPIO_AF_5      5U  /**< GPIO Alternate Function 5 */
#define GPIO_AF_6      6U  /**< GPIO Alternate Function 6 */
#define GPIO_AF_7      7U  /**< GPIO Alternate Function 7 */
#define GPIO_AF_8      8U  /**< GPIO Alternate Function 8 */
#define GPIO_AF_9      9U  /**< GPIO Alternate Function 9 */
#define GPIO_AF_10     10U /**< GPIO Alternate Function 10 */
#define GPIO_AF_11     11U /**< GPIO Alternate Function 11 */
#define GPIO_AF_12     12U /**< GPIO Alternate Function 12 */
#define GPIO_AF_13     13U /**< GPIO Alternate Function 13 */
#define GPIO_AF_14     14U /**< GPIO Alternate Function 14 */
#define GPIO_AF_15     15U /**< GPIO Alternate Function 15 */

/* GPIO Mode Value */
#define GPIO_Mode_Input                     0U  /**< GPIO Input Mode */
#define GPIO_Mode_General_Purpose_Output    1U  /**< GPIO General Purpose Output Mode */
#define GPIO_Mode_Alternate_Function        2U  /**< GPIO Alternate Function Mode */
#define GPIO_Mode_Analog                    3U  /**< GPIO Analog Mode */

/* GPIO Register Pull Value */
#define GPIO_No_Pull                        0U  /**< GPIO No Pull */
#define GPIO_Pull_Up                        1U  /**< GPIO Pull Up */
#define GPIO_Pull_Down                      2U  /**< GPIO Pull Down */
#define GPIO_Pull_Reserved                  3U  /**< GPIO Reserved Pull */

/* GPIO Output Type Value */
#define GPIO_Output_PushPull                0U  /**< GPIO Push-Pull Output Type */
#define GPIO_Output_OpenDrain               1U  /**< GPIO Open-Drain Output Type */



/*
 * Function declarations for GPIO operations:
 *
 * - Enable/Disable GPIO Clock Source.
 * - Set GPIO Mode.
 * - Set GPIO Pull Configuration.
 * - Set GPIO Output Type.
 * - Set GPIO Output Data.
 * - Reset GPIO Output Data.
 * - Toggle GPIO Output Data.
 *
 * Input:
 *   - GPIOx: Pointer to GPIO structure (GPIO_ST).
 *   - Pin: GPIO pin number.
 *   - Mode: GPIO mode (input, output, alternate function, analog).
 *   - Pull: GPIO pull configuration (pull-up, pull-down, none).
 *   - OutputType: GPIO output type (push-pull or open-drain).
 * Return value:
 *   - N/A
 */
extern void GPIO_Enable_ClockSource(UINT16 GPIOx_CLKSRC);
extern void GPIO_Disable_ClockSource(UINT16 GPIOx_CLKSRC);
extern void GPIO_Mode_Set(GPIO_ST *GPIOx, UINT16 Pin, UINT8 Mode);
extern void GPIO_Pull_Set(GPIO_ST *GPIOx, UINT16 Pin, UINT8 Pull);
extern void GPIO_OutputType_Set(GPIO_ST *GPIOx, UINT16 Pin, BOOL OutputType); 
extern void GPIO_OutputData_Set(GPIO_ST *GPIOx, UINT16 Pin);
extern void GPIO_OutputData_Reset(GPIO_ST *GPIOx, UINT16 Pin);
extern void GPIO_OutputData_Toggle(GPIO_ST *GPIOx, UINT16 Pin);

#endif