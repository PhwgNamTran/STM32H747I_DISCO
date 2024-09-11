#ifndef STM32H7_GPIO_H
#define STM32H7_GPIO_H

#include "STM32H747xx.h"

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
 * - Select Alternate function for GPIO Pin.
 *
 * Input:
 *   - GPIOx: Pointer to GPIO structure (GPIO_TypeDef).
 *   - Pin: GPIO pin number.
 *   - Mode: GPIO mode (input, output, alternate function, analog).
 *   - Pull: GPIO pull configuration (pull-up, pull-down, none).
 *   - OutputType: GPIO output type (push-pull or open-drain).
 *   - Alternate function number.
 * Return value:
 *   - N/A
 */
extern void GPIO_Enable_ClockSource(uint16_t GPIOx_CLKSRC);
extern void GPIO_Disable_ClockSource(uint16_t GPIOx_CLKSRC);
extern void GPIO_Mode_Set(GPIO_TypeDef *GPIOx, uint8_t Pin, uint8_t Mode);
extern void GPIO_Pull_Set(GPIO_TypeDef *GPIOx, uint8_t Pin, uint8_t Pull);
extern void GPIO_OutputType_Set(GPIO_TypeDef *GPIOx, uint8_t Pin, boolean OutputType); 
extern void GPIO_OutputData_Set(GPIO_TypeDef *GPIOx, uint8_t Pin);
extern void GPIO_OutputData_Reset(GPIO_TypeDef *GPIOx, uint8_t Pin);
extern void GPIO_OutputData_Toggle(GPIO_TypeDef *GPIOx, uint8_t Pin);
extern void GPIO_Select_Alternate_Function(GPIO_TypeDef *GPIOx, uint8_t Pin, uint8_t AFx);

#endif