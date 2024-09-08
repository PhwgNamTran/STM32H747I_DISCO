#ifndef WKBUTTON_H
#define WKBUTTON_H

#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"
#include "STM32H747XI_EXTI.h"
#include "STM32H747XI_NVIC.h"
#include "STM32H747XI_SYSCFG.h"
#include "Common.h"

typedef enum
{
    C_Button_Released_N, /**< Button is released */
    C_Button_Pressed_N   /**< Button is pressed */
} ButtonState_N;

#define WK_Button_ClockSrc    GPIO_C_CLKSRC /**< WK Button Clock source */
#define WK_Button_Port        GPIO_C        /**< WK Button GPIO Port */
#define WK_Button_PIN         13U           /**< WK Button GPIO Pin number */

#define Button_Pressed        TRUE          /**< Button is pressed */
#define Button_Released       FALSE         /**< Button is released */

#define WK_Button_Event_Input   Event_Input_EXTI_13 /**< WK Button Event Input */
#define WK_Button_IRQn          IRQn_EXTI15_10      /**< WK Button IRQ number */

/*
 * Function declarations for WK Button management:
 *
 * - WK_Button_Init: Initializes the WK Button.
 * - WK_Button_Interrupt_Init: Initializes WK Button Interrupt.
 * - WK_Button_State: Checks the status of the WK Button.
 * - WK_Button_Pressed_then_Released_B: Checks if WK Button state changed from pressed to released.
 * - WK_Button_Released_then_Pressed_B: Checks if WK Button state changed from released to pressed.
 *
 * Note: WK_Button_Pressed_then_Released_B and WK_Button_Released_then_Pressed_B should be called under a cyclic function or in while(1).
 */
extern void WK_Button_Init(void);
extern void WK_Button_Interrupt_Init(void);
extern ButtonState_N WK_Button_State(void);
extern boolean WK_Button_Pressed_then_Released_B(void);
extern boolean WK_Button_Released_then_Pressed_B(void);


#endif