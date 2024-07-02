#ifndef USERLED_H
#define USERLED_H

#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"
#include "Common.h"

/* UserLED GPIO Configuration */
#define UserLED_ClockSrc    GPIO_I_CLKSRC /**< UserLED Clock Source */
#define UserLED_Port        GPIO_I       /**< UserLED GPIO Port */

/* UserLED Pin Definitions */
#define UserLED_1_PIN       12U /**< UserLED 1 Pin */
#define UserLED_2_PIN       13U /**< UserLED 2 Pin */
#define UserLED_3_PIN       14U /**< UserLED 3 Pin */
#define UserLED_4_PIN       15U /**< UserLED 4 Pin */

/* UserLED Index Definitions */
#define UserLED_1           0U  /**< UserLED 1 Index */
#define UserLED_2           1U  /**< UserLED 2 Index */
#define UserLED_3           2U  /**< UserLED 3 Index */
#define UserLED_4           3U  /**< UserLED 4 Index */

/*
 * Function declarations for managing UserLEDs:
 *
 * - UserLED_Init: Initialize UserLEDs.
 * - UserLED_ON: Turn ON specified UserLED.
 * - UserLED_OFF: Turn OFF specified UserLED.
 * - UserLED_TOGGLE: Toggle specified UserLED.
 *
 * Parameters:
 *   UserLEDx: UserLED number (0 to 3).
 * Return value:
 *   N/A
 */
extern void UserLED_Init(UINT8 UserLEDx);   /**< Initialize UserLEDs */
extern void UserLED_ON(UINT8 UserLEDx);     /**< Turn ON specified UserLED */
extern void UserLED_OFF(UINT8 UserLEDx);    /**< Turn OFF specified UserLED */
extern void UserLED_TOGGLE(UINT8 UserLEDx); /**< Toggle specified UserLED */


#endif /* USERLED_H */
