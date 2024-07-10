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

/*
 * Function: USART_Config
 * ----------------------
 * Configures the USART peripheral with the specified parameters.
 *
 * Parameters:
 *   USARTx            - Pointer to the USART peripheral to configure.
 *   SysClock          - The system clock frequency in Hz.
 *   Baudrate          - The desired baud rate for the USART communication.
 *   OverSamplingMode  - If TRUE, enables oversampling by 8; otherwise, uses oversampling by 16.
 *   DataLengthCode    - The data length (number of data bits).
 *   NumberOfStopBit   - The number of stop bits.
 *   ParityCheck       - The parity check mode (e.g., none, even, odd).
 *
 * Returns:
 *   None
 */
void USART_Config(USART_ST *USARTx, UINT32 SysClock, UINT16 Baudrate, BOOL OverSamplingMode,
                                    UINT8 DataLengthCode, UINT8 NumberOfStopBit, UINT8 ParityCheck)
{
    UINT32 Baudrate_DIV;

    // Clear the data length bits in the CR1 register
    CLEAR_BIT(USARTx->CR1, (1 << USART_CR1_M1_Pos));
    CLEAR_BIT(USARTx->CR1, (1 << USART_CR1_M0_Pos));
    
    // Set the data length according to the DataLengthCode
    SET_BIT(USARTx->CR1, ((DataLengthCode & 0x2) << USART_CR1_M1_Pos));
    SET_BIT(USARTx->CR1, ((DataLengthCode & 0x1) << USART_CR1_M0_Pos));

    if (OverSamplingMode)
    {
        // Enable oversampling by 8
        SET_BIT(USARTx->CR1, (1 << USART_CR1_OVER8_Pos));
        
        // Calculate the baud rate divisor for oversampling by 8
        Baudrate_DIV = (UINT16)(2 * SysClock / Baudrate + 0.5);
        Baudrate_DIV = (Baudrate_DIV & 0xFFF0) | ((Baudrate_DIV & 0x000F) >> 1);
    }
    else
    {
        // Enable oversampling by 16
        CLEAR_BIT(USARTx->CR1, (1 << USART_CR1_OVER8_Pos));
        
        // Calculate the baud rate divisor for oversampling by 16
        Baudrate_DIV = (UINT32)(SysClock / Baudrate + 0.5);
    }
    
    // Set the baud rate divisor in the BRR register
    WRITE_REG(USARTx->BRR, Baudrate_DIV);

    // Set the number of stop bits in the CR2 register
    SET_BIT(USARTx->CR2, (NumberOfStopBit << USART_CR2_STOP_Pos));

    if (ParityCheck == USART_Parity_None)
    {
        // Disable parity control
        CLEAR_BIT(USARTx->CR1, (1 << USART_CR1_PCE_Pos));
    }
    else
    {
        // Enable parity control
        SET_BIT(USARTx->CR1, (1 << USART_CR1_PCE_Pos));
        
        // Clear parity selection bit
        CLEAR_BIT(USARTx->CR1, (1 << USART_CR1_PS_Pos));
        
        // Set parity selection bit according to ParityCheck
        CLEAR_BIT(USARTx->CR1, (ParityCheck << USART_CR1_PS_Pos));
    }
}

/*
 * Function: USART_Enable_ClockSource
 * ----------------------------------
 * Enables the clock source for the specified USART peripheral.
 *
 * Parameters:
 *   USARTx - Pointer to the USART peripheral instance. This parameter can be one of the following values:
 *            - USART1
 *            - USART2
 *            - USART3
 *            - UART4
 *            - UART5
 *            - USART6
 *            - UART7
 *            - UART8
 *
 * Returns:
 *   None
 */
void USART_Enable_ClockSource(USART_ST *USARTx)
{
    // Enable clock source for USART1
    if (USARTx == USART1)
    {
        SET_BIT(RCC->APB2ENR, USART1_ClockSource);
    }
    // Enable clock source for USART2
    else if (USARTx == USART2)
    {
        SET_BIT(RCC->APB1LENR, USART2_ClockSource);
    }
    // Enable clock source for USART3
    else if (USARTx == USART3)
    {
        SET_BIT(RCC->APB1LENR, USART3_ClockSource);
    }
    // Enable clock source for UART4
    else if (USARTx == UART4)
    {
        SET_BIT(RCC->APB1LENR, UART4_ClockSource);
    }
    // Enable clock source for UART5
    else if (USARTx == UART5)
    {
        SET_BIT(RCC->APB1LENR, UART5_ClockSource);
    }
    // Enable clock source for USART6
    else if (USARTx == USART6)
    {
        SET_BIT(RCC->APB2ENR, USART6_ClockSource);
    }
    // Enable clock source for UART7
    else if (USARTx == UART7)
    {
        SET_BIT(RCC->APB1LENR, UART7_ClockSource);
    }
    // Enable clock source for UART8
    else if (USARTx == UART8)
    {
        SET_BIT(RCC->APB1LENR, UART8_ClockSource);
    }
    // No action for invalid USART instance
    else
    {
        // Handle invalid USART instance if needed
    }
}

/*
 * Function: USART_Enable
 * ----------------------
 * Enables the specified USART peripheral by setting the UE bit in the CR1 register.
 *
 * Parameters:
 *   USARTx - Pointer to the USART peripheral instance. This parameter can be one of the following values:
 *            - USART1
 *            - USART2
 *            - USART3
 *            - UART4
 *            - UART5
 *            - USART6
 *            - UART7
 *            - UART8
 *
 * Returns:
 *   None
 */
void USART_Enable(USART_ST *USARTx)
{
    // Enable the USART peripheral by setting the UE bit
    SET_BIT(USARTx->CR1, (1 << USART_CR1_UE_Pos));
}

/*
 * Function: USART_Disable
 * -----------------------
 * Disables the specified USART peripheral by clearing the UE bit in the CR1 register.
 *
 * Parameters:
 *   USARTx - Pointer to the USART peripheral instance. This parameter can be one of the following values:
 *            - USART1
 *            - USART2
 *            - USART3
 *            - UART4
 *            - UART5
 *            - USART6
 *            - UART7
 *            - UART8
 *
 * Returns:
 *   None
 */
void USART_Disable(USART_ST *USARTx)
{
    // Disable the USART peripheral by clearing the UE bit
    CLEAR_BIT(USARTx->CR1, (1 << USART_CR1_UE_Pos));
}

