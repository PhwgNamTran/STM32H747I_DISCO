#ifndef STM32H7_GPIO_H
#define STM32H7_GPIO_H

#include "STM32H747xx.h"

/**
  * @brief   GPIO Init structure definition
  */
typedef struct
{
  uint32_t Pin;       /*!< Specifies the GPIO pins to be configured. */
  uint32_t Mode;      /*!< Specifies the operating mode for the selected pins. */
  uint32_t Pull;      /*!< Specifies the Pull-up or Pull-Down activation for the selected pins. */
  uint32_t Speed;     /*!< Specifies the speed for the selected pins. */
  uint32_t Alternate; /*!< Peripheral to be connected to the selected pins. */
} GPIO_InitTypeDef;

/**
  * @brief   GPIO Pin structure definition
  */
typedef enum
{
    GPIO_PIN_0  = (uint16_t) 0x0001,  /**< GPIO Pin 0 */
    GPIO_PIN_1  = (uint16_t) 0x0002,  /**< GPIO Pin 1 */
    GPIO_PIN_2  = (uint16_t) 0x0004,  /**< GPIO Pin 2 */
    GPIO_PIN_3  = (uint16_t) 0x0008,  /**< GPIO Pin 3 */
    GPIO_PIN_4  = (uint16_t) 0x0010,  /**< GPIO Pin 4 */
    GPIO_PIN_5  = (uint16_t) 0x0020,  /**< GPIO Pin 5 */
    GPIO_PIN_6  = (uint16_t) 0x0040,  /**< GPIO Pin 6 */
    GPIO_PIN_7  = (uint16_t) 0x0080,  /**< GPIO Pin 7 */
    GPIO_PIN_8  = (uint16_t) 0x0100,  /**< GPIO Pin 8 */
    GPIO_PIN_9  = (uint16_t) 0x0200,  /**< GPIO Pin 9 */
    GPIO_PIN_10 = (uint16_t) 0x0400,  /**< GPIO Pin 10 */
    GPIO_PIN_11 = (uint16_t) 0x0800,  /**< GPIO Pin 11 */
    GPIO_PIN_12 = (uint16_t) 0x1000,  /**< GPIO Pin 12 */
    GPIO_PIN_13 = (uint16_t) 0x2000,  /**< GPIO Pin 13 */
    GPIO_PIN_14 = (uint16_t) 0x4000,  /**< GPIO Pin 14 */
    GPIO_PIN_15 = (uint16_t) 0x8000   /**< GPIO Pin 15 */
} GPIO_PinTypeDef;

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

/**
  * @brief   GPIO Mode structure definition
  */
typedef enum
{
    GPIO_Mode_Input = 0U,                  /**< GPIO Input Mode */
    GPIO_Mode_General_Purpose_Output = 1U, /**< GPIO General Purpose Output Mode */
    GPIO_Mode_Alternate_Function = 2U,     /**< GPIO Alternate Function Mode */
    GPIO_Mode_Analog = 3U                  /**< GPIO Analog Mode */
} GPIO_ModeTypeDef;

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