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
void USART_Config(USART_ST *USARTx, UINT32 SysClock, UINT32 Baudrate, BOOL OverSamplingMode,
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
 * Function: USART_Config_Mode
 * ----------------------
 * Configures the USART peripheral with the specified mode.
 * 
 * Parameters:
 *   USARTx - Pointer to the USART peripheral (USART_ST *).
 *   Mode - The desired USART mode (USART_Mode).
 *
 * Returns:
 *   None
 */
void USART_Config_Mode(USART_ST *USARTx, USART_Mode Mode)
{
    switch (Mode) {
        case USART_ASYNC_TX_ONLY:
            SET_BIT(USARTx->CR1, (1 << USART_CR1_TE_Pos));   // Enable Transmit
            CLEAR_BIT(USARTx->CR1, (1 << USART_CR1_RE_Pos)); // Disable Receive
            break;
            
        case USART_ASYNC_RX_ONLY:
            CLEAR_BIT(USARTx->CR1, (1 << USART_CR1_TE_Pos)); // Disable Transmit
            SET_BIT(USARTx->CR1, (1 << USART_CR1_RE_Pos));   // Enable Receive
            break;
            
        case USART_ASYNC_TX_RX:
            SET_BIT(USARTx->CR1, (1 << USART_CR1_TE_Pos));  // Enable Transmit
            SET_BIT(USARTx->CR1, (1 << USART_CR1_RE_Pos));  // Enable Receive
            break;
            
        case USART_SYNCHRONOUS:
            SET_BIT(USARTx->CR2, (1 << USART_CR2_CLKEN_Pos)); // Enable clock
            // Configure clock polarity and phase as needed
            // USARTx->CR2 |= (USART_CP0L1 | USART_CPHA_1); // Example setting
            SET_BIT(USARTx->CR1, (1 << USART_CR1_TE_Pos));  // Enable Transmit
            SET_BIT(USARTx->CR1, (1 << USART_CR1_RE_Pos));  // Enable Receive
            break;
            
        case USART_SINGLEWIRE:
            SET_BIT(USARTx->CR3, (1 << USART_CR3_HDSEL_Pos)); // Enable single-wire mode
            SET_BIT(USARTx->CR1, (1 << USART_CR1_TE_Pos));  // Enable Transmit
            SET_BIT(USARTx->CR1, (1 << USART_CR1_RE_Pos));  // Enable Receive
            break;
            
        case USART_SMARTCARD:
            SET_BIT(USARTx->CR3, (1 << USART_CR3_SCEN_Pos)); // Enable smartcard mode
            SET_BIT(USARTx->CR1, (1 << USART_CR1_TE_Pos));   // Enable Transmit
            // Configure additional smartcard settings if needed
            break;
            
        case USART_IRDA:
            SET_BIT(USARTx->CR3, (1 << USART_CR3_IREN_Pos)); // Enable IrDA mode
            // Configure low-power mode if necessary
            // SET_BIT(USARTx->CR3, (1 << USART_CR3_IRLP_Pos));
            SET_BIT(USARTx->CR1, (1 << USART_CR1_TE_Pos));  // Enable Transmit
            SET_BIT(USARTx->CR1, (1 << USART_CR1_RE_Pos));  // Enable Receive
            break;
            
        case USART_LIN:
            SET_BIT(USARTx->CR2, (1 << USART_CR2_LINEN_Pos)); // Enable LIN mode
            SET_BIT(USARTx->CR1, (1 << USART_CR1_TE_Pos));  // Enable Transmit
            SET_BIT(USARTx->CR1, (1 << USART_CR1_RE_Pos));  // Enable Receive
            break;
            
        case USART_RS485:
            SET_BIT(USARTx->CR3, (1 << USART_CR3_DEM_Pos)); // Enable driver enable mode
            // Configure DE polarity and settings as needed
            SET_BIT(USARTx->CR1, (1 << USART_CR1_TE_Pos));  // Enable Transmit
            SET_BIT(USARTx->CR1, (1 << USART_CR1_RE_Pos));  // Enable Receive
            break;
            
        default:
            // Invalid mode, handle error if necessary
            break;
    }
}

/*
 * Function: USART_ConfigInterrupt
 * -------------------------------
 * Configures the USART interrupts based on the specified mode.
 * Enables interrupts according to the provided configuration.
 * 
 * Parameters:
 *   USARTx - Pointer to the USART peripheral (e.g., USART1, USART2, etc.)
 *   Interrupt_Mode - Specifies the interrupt mode(s) to configure
 * 
 * Returns:
 *   None
 */
void USART_Config_Interrupt(USART_ST *USARTx, USART_Interrupt_Mode Interrupt_Mode)
{
    // Configure interrupts based on Interrupt_Mode
    switch (Interrupt_Mode) {
        case USART_Interrupt_TransmitDataRegisterEmpty:
            SET_BIT(USARTx->CR1, (1 << USART_CR1_TXEIE_Pos));
            break;
        case USART_Interrupt_TransmissionComplete:
            SET_BIT(USARTx->CR1, (1 << USART_CR1_TCIE_Pos));
            break;
        case USART_Interrupt_ReceptionDataNotEmpty:
            SET_BIT(USARTx->CR1, (1 << USART_CR1_RXNEIE_Pos));
            break;
        case USART_Interrupt_ParityError:
            SET_BIT(USARTx->CR1, (1 << USART_CR1_PEIE_Pos));
            break;
        case USART_Interrupt_LINBreakDetection:
            SET_BIT(USARTx->CR2, (1 << USART_CR2_LBDIE_Pos));
            break;
        case USART_Interrupt_CTS:
            SET_BIT(USARTx->CR3, (1 << USART_CR3_CTSIE_Pos));
            break;
        default:
            // Handle unknown or unsupported interrupt modes, if necessary
            break;
    }
}

/*
 * Function: USART_Enable
 * ----------------------
 * Enables the USART peripheral.
 * 
 * Parameters:
 *   USARTx - Pointer to the USART peripheral (USART_ST *).
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
 * 
 * Returns:
 *   None
 */
void USART_Disable(USART_ST *USARTx)
{
    // Disable the USART peripheral by clearing the UE bit
    CLEAR_BIT(USARTx->CR1, (1 << USART_CR1_UE_Pos));
}


/**
 * Function: USART_Transmit_Single_Data
 * ------------------------
 * Transmits a single data frame (8 or 9 bits) via the specified USART.
 *
 * Parameters:
 *   USARTx - Pointer to the USART instance to use for transmission.
 *   data - The data frame to transmit (8 or 9 bits).
 *
 * Returns:
 *   None
 */
void USART_Transmit_Single_Data(USART_ST *USARTx, UINT16 Data)
{
    // Wait until TXFNF flag is set, indicating transmit data register is not full
    while (!(CHECK_BIT(USARTx->ISR, (1 << USART_ISR_TXFNF_Pos))));

    // Write the data to the USART transmit data register
    USARTx->TDR = (Data & 0x1FF);

    // Wait until TC flag is set, indicating transmission complete
    while (!(CHECK_BIT(USARTx->ISR, (1 << USART_ISR_TC_Pos))));
}


/**
 * Function: USART_Transmit
 * -------------------------------
 * Transmits a null-terminated string via the specified USART.
 *
 * Parameters:
 *   USARTx - Pointer to the USART instance to use for transmission.
 *   str - Pointer to the null-terminated string to be transmitted.
 *
 * Returns:
 *   None
 */
void USART_Transmit(USART_ST *USARTx, const char *str) {
    while (*str) 
    {
        USART_Transmit_Single_Data(USARTx, *str++);
    }
}

/**
 * Function: USART_Receive_Single_Data
 * -----------------------
 * Receives a single data frame (8 or 9 bits) from the specified USART.
 *
 * Parameters:
 *   USARTx - Pointer to the USART instance to use for reception.
 *
 * Returns:
 *   The received data frame (8 or 9 bits).
 */
UINT16 USART_Receive_Single_Data(USART_ST *USARTx)
{
    // Wait until RXFNE flag is set, indicating receive data register is not empty
    while (!(CHECK_BIT(USARTx->ISR, (1 << USART_ISR_RXFNE_Pos))));

    // Read the data from the USART receive data register
    return (UINT16)(USARTx->RDR & 0x1FF);
}