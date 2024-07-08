#include "STM32H747XI_USART.h"

/*
 * Function: USART_PIN_Config
 * --------------------------
 * Configures the GPIO pins for USART communication.
 *
 * Parameters:
 *   GPIOx        - Pointer to the GPIO peripheral
 *   GPIO_AFx     - Alternate function number for USART (0-15)
 *   USART_Rx_PIN - GPIO pin number for USART RX (0-15)
 *   USART_Tx_PIN - GPIO pin number for USART TX (0-15)
 *
 * Returns:
 *   None
 */
void USART_PIN_Config(GPIO_ST *GPIOx, UINT8 GPIO_AFx, UINT8 USART_Rx_PIN, UINT8 USART_Tx_PIN)
{
    // Configure the RX pin to alternate function mode
    GPIO_Mode_Set(GPIOx, USART_Rx_PIN, GPIO_Mode_Alternate_Function);
    // Select the alternate function for the RX pin
    GPIO_Select_Alternate_Function(GPIOx, USART_Rx_PIN, GPIO_AFx);

    // Configure the TX pin to alternate function mode
    GPIO_Mode_Set(GPIOx, USART_Tx_PIN, GPIO_Mode_Alternate_Function);
    // Select the alternate function for the TX pin
    GPIO_Select_Alternate_Function(GPIOx, USART_Tx_PIN, GPIO_AFx);
}
