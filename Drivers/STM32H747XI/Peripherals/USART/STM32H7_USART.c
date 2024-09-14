#include "STM32H7_USART.h"

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
void USART_PIN_Config(GPIO_ST *GPIOx, uint8_t GPIO_AFx, uint8_t USART_Rx_PIN, uint8_t USART_Tx_PIN)
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
void USART_Config(USART_ST *USARTx, uint32_t SysClock, uint32_t Baudrate, boolean OverSamplingMode,
                                    uint8_t DataLengthCode, uint8_t NumberOfStopBit, uint8_t ParityCheck)
{
    uint32_t Baudrate_DIV;

    // Clear the data length bits in the CR1 register
    CLEAR_BIT(USARTx->CR1, USART_CR1_M1);
    CLEAR_BIT(USARTx->CR1, USART_CR1_M0);
    
    // Set the data length according to the DataLengthCode
    SET_BIT(USARTx->CR1, ((DataLengthCode & 0x2) << USART_CR1_M1_Pos));
    SET_BIT(USARTx->CR1, ((DataLengthCode & 0x1) << USART_CR1_M0_Pos));

    if (OverSamplingMode)
    {
        // Enable oversampling by 8
        SET_BIT(USARTx->CR1, USART_CR1_OVER8);
        
        // Calculate the baud rate divisor for oversampling by 8
        Baudrate_DIV = (uint16_t)(2 * SysClock / Baudrate + 0.5);
        Baudrate_DIV = (Baudrate_DIV & 0xFFF0) | ((Baudrate_DIV & 0x000F) >> 1);
    }
    else
    {
        // Enable oversampling by 16
        CLEAR_BIT(USARTx->CR1, USART_CR1_OVER8);
        
        // Calculate the baud rate divisor for oversampling by 16
        Baudrate_DIV = (uint32_t)(SysClock / Baudrate + 0.5);
    }
    
    // Set the baud rate divisor in the BRR register
    WRITE_REG(USARTx->BRR, Baudrate_DIV);

    // Set the number of stop bits in the CR2 register
    SET_BIT(USARTx->CR2, (NumberOfStopBit << USART_CR2_STOP_Pos));

    if (ParityCheck == USART_Parity_None)
    {
        // Disable parity control
        CLEAR_BIT(USARTx->CR1, USART_CR1_PCE);
    }
    else
    {
        // Enable parity control
        SET_BIT(USARTx->CR1, USART_CR1_PCE);
        
        // Clear parity selection bit
        CLEAR_BIT(USARTx->CR1, USART_CR1_PS);
        
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
 * Function: USART_SetMode
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
void USART_SetMode(USART_ST *USARTx, USART_Mode Mode)
{
    switch (Mode) {
        case USART_ASYNC_TX_ONLY:
            SET_BIT(USARTx->CR1, USART_CR1_TE);   // Enable Transmit
            CLEAR_BIT(USARTx->CR1, USART_CR1_RE); // Disable Receive
            break;
            
        case USART_ASYNC_RX_ONLY:
            CLEAR_BIT(USARTx->CR1, USART_CR1_TE); // Disable Transmit
            SET_BIT(USARTx->CR1, USART_CR1_RE);   // Enable Receive
            break;
            
        case USART_ASYNC_TX_RX:
            SET_BIT(USARTx->CR1, USART_CR1_TE);  // Enable Transmit
            SET_BIT(USARTx->CR1, USART_CR1_RE);  // Enable Receive
            break;
            
        case USART_SYNCHRONOUS:
            SET_BIT(USARTx->CR2, USART_CR2_CLKEN); // Enable clock
            // Configure clock polarity and phase as needed
            // USARTx->CR2 |= (USART_CP0L1 | USART_CPHA_1); // Example setting
            SET_BIT(USARTx->CR1, USART_CR1_TE);  // Enable Transmit
            SET_BIT(USARTx->CR1, USART_CR1_RE);  // Enable Receive
            break;
            
        case USART_SINGLEWIRE:
            SET_BIT(USARTx->CR3, USART_CR3_HDSEL); // Enable single-wire mode
            SET_BIT(USARTx->CR1, USART_CR1_TE);  // Enable Transmit
            SET_BIT(USARTx->CR1, USART_CR1_RE);  // Enable Receive
            break;
            
        case USART_SMARTCARD:
            SET_BIT(USARTx->CR3, USART_CR3_SCEN); // Enable smartcard mode
            SET_BIT(USARTx->CR1, USART_CR1_TE);   // Enable Transmit
            // Configure additional smartcard settings if needed
            break;
            
        case USART_IRDA:
            SET_BIT(USARTx->CR3, USART_CR3_IREN); // Enable IrDA mode
            // Configure low-power mode if necessary
            // SET_BIT(USARTx->CR3, USART_CR3_IRLP);
            SET_BIT(USARTx->CR1, USART_CR1_TE);  // Enable Transmit
            SET_BIT(USARTx->CR1, USART_CR1_RE);  // Enable Receive
            break;
            
        case USART_LIN:
            SET_BIT(USARTx->CR2, USART_CR2_LINEN); // Enable LIN mode
            SET_BIT(USARTx->CR1, USART_CR1_TE);  // Enable Transmit
            SET_BIT(USARTx->CR1, USART_CR1_RE);  // Enable Receive
            break;
            
        case USART_RS485:
            SET_BIT(USARTx->CR3, USART_CR3_DEM); // Enable driver enable mode
            // Configure DE polarity and settings as needed
            SET_BIT(USARTx->CR1, USART_CR1_TE);  // Enable Transmit
            SET_BIT(USARTx->CR1, USART_CR1_RE);  // Enable Receive
            break;
            
        default:
            // Invalid mode, handle error if necessary
            break;
    }
}

/*
 * Function: USART_GetMode
 * -----------------------
 * Determines the current operating mode of the specified USART peripheral by
 * checking the configuration of control registers CR1, CR2, and CR3.
 *
 * Parameters:
 *   USARTx - Pointer to the USART_ST structure representing the USART peripheral
 *            to check. This should be one of the available USART peripherals.
 *
 * Returns:
 *   USART_Mode - An enumeration value indicating the current mode of the USART.
 */
USART_Mode USART_GetMode(USART_ST *USARTx)
{
    USART_Mode l_USART_Mode;

    // Check for Synchronous mode
    if (READ_BIT(USARTx->CR2, USART_CR2_CLKEN)) 
    {
        l_USART_Mode = USART_SYNCHRONOUS;
    }
    // Check for Single-wire half-duplex mode
    else if (READ_BIT(USARTx->CR3, USART_CR3_HDSEL)) 
    {
        l_USART_Mode = USART_SINGLEWIRE;
    }
    // Check for Smartcard mode
    else if (READ_BIT(USARTx->CR3, USART_CR3_SCEN)) 
    {
        l_USART_Mode = USART_SMARTCARD;
    }
    // Check for IrDA mode
    else if (READ_BIT(USARTx->CR3, USART_CR3_IREN)) 
    {
        l_USART_Mode = USART_IRDA;
    }
    // Check for LIN mode
    else if (READ_BIT(USARTx->CR2, USART_CR2_LINEN)) 
    {
        l_USART_Mode = USART_LIN;
    }
    // Check for RS485 mode
    else if (READ_BIT(USARTx->CR3, USART_CR3_DEM)) 
    {
        l_USART_Mode = USART_RS485;
    }
    // Default to asynchronous mode if none of the above modes are set
    else 
    {
        // Check Transmit only
        if (READ_BIT(USARTx->CR1, USART_CR1_TE) && (!READ_BIT(USARTx->CR1, USART_CR1_RE))) 
        {
            l_USART_Mode = USART_ASYNC_TX_ONLY;
        }
        // Check Receive only
        else if ((!READ_BIT(USARTx->CR1, USART_CR1_TE)) && READ_BIT(USARTx->CR1, USART_CR1_RE))
        {
            l_USART_Mode = USART_ASYNC_RX_ONLY;
        }
        // Check Transmit and Receive
        else if (READ_BIT(USARTx->CR1, USART_CR1_TE) && READ_BIT(USARTx->CR1, USART_CR1_RE)) 
        {
            l_USART_Mode = USART_ASYNC_TX_RX;
        }
        else
        {
            l_USART_Mode = USART_ASYNC_TX_RX;
        }
    }

    return l_USART_Mode;
}

/*
 * Function: USART_EnableFIFO
 * --------------------------
 * Enables FIFO mode for the USART peripheral based on its current mode.
 *
 * Parameters:
 *   USARTx - Pointer to the USART_ST structure representing the USART peripheral
 *            to configure.
 * Returns:
 *   None
 *
 * Note:
 *   FIFO mode can be used in standard UART communication, SPI master/slave mode,
 *   and Smartcard modes only. It must not be enabled in IrDA and LIN modes.
 */
void USART_EnableFIFO(USART_ST *USARTx)
{
    // Read the current mode configuration
    USART_Mode l_USART_Mode = USART_GetMode(USARTx);

    switch (l_USART_Mode) 
    {
        case USART_ASYNC_TX_ONLY:
        case USART_ASYNC_RX_ONLY:
        case USART_ASYNC_TX_RX:
        case USART_SYNCHRONOUS:
        case USART_SMARTCARD:
            SET_BIT(USARTx->CR1,USART_CR1_FIFOEN);
            break;
        case USART_IRDA:
        case USART_LIN:
        case USART_SINGLEWIRE:
        case USART_RS485:
            /* Nothing to do: FIFO is not supported in these Mode */
            break;
        default:
            /* Nothing to do, handle invalid case if needed */
            break;
    }
}

/*
 * Function: USART_DisableFIFO
 * ---------------------------
 * Disables FIFO mode for the USART peripheral based on its current mode.
 *
 * Parameters:
 *   USARTx - Pointer to the USART_ST structure representing the USART peripheral
 *            to configure.
 * Returns:
 *   None
 *
 * Note:
 *   This function disables FIFO mode regardless of the current USART mode.
 */
void USART_DisableFIFO(USART_ST *USARTx)
{
    // Read the current mode configuration
    USART_Mode l_USART_Mode = USART_GetMode(USARTx);

    switch (l_USART_Mode) 
    {
        case USART_ASYNC_TX_ONLY:
        case USART_ASYNC_RX_ONLY:
        case USART_ASYNC_TX_RX:
        case USART_SYNCHRONOUS:
        case USART_SMARTCARD:
            CLEAR_BIT(USARTx->CR1, USART_CR1_FIFOEN);
            break;
        case USART_IRDA:
        case USART_LIN:
        case USART_SINGLEWIRE:
        case USART_RS485:
            /* Nothing to do: FIFO is not supported in these Mode */
            break;
        default:
            /* Nothing to do, handle invalid case if needed */
            break;
    }
}

/*
 * Function: USART_IsFIFOEnabled
 * -----------------------------
 * Checks if FIFO mode is enabled for the specified USART peripheral.
 *
 * Parameters:
 *   USARTx - Pointer to the USART_ST structure representing the USART peripheral
 *            to check.
 *
 * Returns:
 *   true if FIFO mode is enabled, false otherwise.
 */
boolean USART_IsFIFOEnabled(USART_ST *USARTx)
{
    // Check if the FIFO enable bit is set in the CR1 register
    return (CHECK_BIT(USARTx->CR1, USART_CR1_FIFOEN));
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
void USART_Enable_Interrupt(USART_ST *USARTx, uint32_t Interrupt_Mode)
{
    if(USART_IsFIFOEnabled(USARTx) == true)
    {
        if (Interrupt_Mode & USART_Interrupt_TransmitFIFONotFull) 
        {
            SET_BIT(USARTx->CR1, USART_CR1_TXEIE);
        }
        if (Interrupt_Mode & USART_Interrupt_TransmitFIFOEmpty) 
        {
            SET_BIT(USARTx->CR1, USART_CR1_TXFEIE);
        }
        if (Interrupt_Mode & USART_Interrupt_TransmitFIFOThresholdReached)
        {
            SET_BIT(USARTx->CR3, USART_CR3_TXFTIE);
        }  
        if (Interrupt_Mode & USART_Interrupt_ReceiveFIFONotEmpty) 
        {
            SET_BIT(USARTx->CR1, USART_CR1_RXNEIE);
        }
        if (Interrupt_Mode & USART_Interrupt_ReceiveFIFOFull) 
        {
            SET_BIT(USARTx->CR1, USART_CR1_RXFFIE);
        }
        if (Interrupt_Mode & USART_Interrupt_ReceiveFIFOThresholdReached) 
        {
            SET_BIT(USARTx->CR3, USART_CR3_RXFTIE);
        }
    }
    // Configure USART interrupts based on the Interrupt_Mode bitmask
    if (Interrupt_Mode & USART_Interrupt_TransmitDataRegisterEmpty) 
    {
        SET_BIT(USARTx->CR1, USART_CR1_TXEIE);
    }
    if (Interrupt_Mode & USART_Interrupt_CTS) 
    {
        SET_BIT(USARTx->CR3, USART_CR3_CTSIE);
    }
    if (Interrupt_Mode & USART_Interrupt_TransmissionComplete) 
    {
        SET_BIT(USARTx->CR1, USART_CR1_TCIE);
    }
    if (Interrupt_Mode & USART_Interrupt_TransmissionCompleteBeforeGuardTime) 
    {
        SET_BIT(USARTx->CR3, USART_CR3_TCBGTIE);
    }
    if (Interrupt_Mode & USART_Interrupt_ReceptionDataNotEmpty) 
    {
        SET_BIT(USARTx->CR1, USART_CR1_RXNEIE);
    }
    if (Interrupt_Mode & USART_Interrupt_OverrunErrorDetected) 
    {
        SET_BIT(USARTx->CR1, USART_CR1_RXNEIE);
    }
    if (Interrupt_Mode & USART_Interrupt_OverrunErrorMultibuffer) 
    {
        SET_BIT(USARTx->CR3, USART_CR3_EIE);
    }
    if (Interrupt_Mode & USART_Interrupt_Idle) 
    {
        SET_BIT(USARTx->CR1, USART_CR1_IDLEIE);
    }
    if (Interrupt_Mode & USART_Interrupt_ParityError) 
    {
        SET_BIT(USARTx->CR1, USART_CR1_PEIE);
    }
    if (Interrupt_Mode & USART_Interrupt_LINBreakDetection) 
    {
        SET_BIT(USARTx->CR2, USART_CR2_LBDIE);
    }
    if (Interrupt_Mode & USART_Interrupt_NoiseError) 
    {
        SET_BIT(USARTx->CR3, USART_CR3_EIE);
    }
    if (Interrupt_Mode & USART_Interrupt_FramingError) 
    {
        SET_BIT(USARTx->CR3, USART_CR3_EIE);
    }
    if (Interrupt_Mode & USART_Interrupt_CharacterMatch) 
    {
        SET_BIT(USARTx->CR1, USART_CR1_CMIE);
    }
    if (Interrupt_Mode & USART_Interrupt_ReceiverTimeout) 
    {
        SET_BIT(USARTx->CR1, USART_CR1_RTOIE);
    }
    if (Interrupt_Mode & USART_Interrupt_EndOfBlock) 
    {
        SET_BIT(USARTx->CR1, USART_CR1_EOBIE);
    }
    if (Interrupt_Mode & USART_Interrupt_WakeupFromLowPowerMode) 
    {
        SET_BIT(USARTx->CR3, USART_CR3_WUFIE);
    }
    if (Interrupt_Mode & USART_Interrupt_SPI_SlaveUnderrun) 
    {
        SET_BIT(USARTx->CR3, USART_CR3_EIE);
    }
}

/*
 * Function: USART_Check_Interrupt_Flag
 * ------------------------------------
 * Checks if a specific interrupt flag is set for the USART peripheral.
 *
 * Parameters:
 *   USARTx - Pointer to the USART_ST structure representing the USART peripheral.
 *   Interrupt_Mode - The specific interrupt mode to check.
 *
 * Returns:
 *   TRUE if the interrupt flag is set, FALSE otherwise.
 */
boolean USART_Check_Interrupt_Flag(USART_ST *USARTx, USART_Interrupt_Mode Interrupt_Mode)
{
    boolean flag_set = false;

    switch (Interrupt_Mode) 
    {
        case USART_Interrupt_TransmitDataRegisterEmpty:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_TXE_TXFNF);
            break;
        case USART_Interrupt_TransmitFIFONotFull:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_TXE_TXFNF);
            break;
        case USART_Interrupt_TransmitFIFOEmpty:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_TXFE);
            break;
        case USART_Interrupt_TransmitFIFOThresholdReached:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_TXFT);
            break;
        case USART_Interrupt_CTS:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_CTSIF);
            break;
        case USART_Interrupt_TransmissionComplete:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_TC);
            break;
        case USART_Interrupt_TransmissionCompleteBeforeGuardTime:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_TCBGT);
            break;
        case USART_Interrupt_ReceptionDataNotEmpty:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_RXNE_RXFNE);
            break;
        case USART_Interrupt_ReceiveFIFONotEmpty:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_RXNE_RXFNE);
            break;
        case USART_Interrupt_ReceiveFIFOFull:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_RXFF);
            break;
        case USART_Interrupt_ReceiveFIFOThresholdReached:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_RXFT);
            break;
        case USART_Interrupt_OverrunErrorDetected:
        case USART_Interrupt_OverrunErrorMultibuffer:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_ORE);
            break;
        case USART_Interrupt_Idle:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_IDLE);
            break;
        case USART_Interrupt_ParityError:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_PE);
            break;
        case USART_Interrupt_LINBreakDetection:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_LBDF);
            break;
        case USART_Interrupt_NoiseError:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_NE);
            break;
        case USART_Interrupt_FramingError:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_FE);
            break;
        case USART_Interrupt_CharacterMatch:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_CMF);
            break;
        case USART_Interrupt_ReceiverTimeout:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_RTOF);
            break;
        case USART_Interrupt_EndOfBlock:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_EOBF);
            break;
        case USART_Interrupt_WakeupFromLowPowerMode:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_WUF);
            break;
        case USART_Interrupt_SPI_SlaveUnderrun:
            flag_set = CHECK_BIT(USARTx->ISR, USART_ISR_UDR);
            break;
        default:
            flag_set = false;
            break;
    }

    return flag_set;
}

/*
 * Function: USART_Clear_Interrupt_Flag
 * ------------------------------------
 * Clears a specific interrupt flag for the USART peripheral.
 *
 * Parameters:
 *   USARTx - Pointer to the USART_ST structure representing the USART peripheral.
 *   Interrupt_Mode - The specific interrupt mode to clear.
 *
 * Returns:
 *   None
 */
void USART_Clear_Interrupt_Flag(USART_ST *USARTx, USART_Interrupt_Mode Interrupt_Mode)
{
    switch (Interrupt_Mode) 
    {
        case USART_Interrupt_CTS:
            // Clear CTS interrupt flag by writing 1 to CTS clear flag in ICR
            SET_BIT(USARTx->ICR, USART_ICR_CTSCF);
            break;
        case USART_Interrupt_TransmissionComplete:
            // Clear TC flag by writing 1 to TC clear flag in ICR
            SET_BIT(USARTx->ICR, USART_ICR_TCCF);
            break;
        case USART_Interrupt_TransmissionCompleteBeforeGuardTime:
            // Clear TCBGT flag by writing 1 to TCBGT clear flag in ICR
            SET_BIT(USARTx->ICR, USART_ICR_TCBGTCF);
            break;
        case USART_Interrupt_OverrunErrorDetected:
        case USART_Interrupt_OverrunErrorMultibuffer:
            // Clear ORE flag by writing 1 to ORE clear flag in ICR
            SET_BIT(USARTx->ICR, USART_ICR_ORECF);
            break;
        case USART_Interrupt_Idle:
            // Clear IDLE flag by writing 1 to IDLE clear flag in ICR
            SET_BIT(USARTx->ICR, USART_ICR_IDLECF);
            break;
        case USART_Interrupt_ParityError:
            // Clear PE flag by writing 1 to PE clear flag in ICR
            SET_BIT(USARTx->ICR, USART_ICR_PECF);
            break;
        case USART_Interrupt_LINBreakDetection:
            // Clear LBDF flag by writing 1 to LBDF clear flag in ICR
            SET_BIT(USARTx->ICR, USART_ICR_LBDCF);
            break;
        case USART_Interrupt_NoiseError:
            // Clear NE flag by writing 1 to NE clear flag in ICR
            SET_BIT(USARTx->ICR, USART_ICR_NECF);
            break;
        case USART_Interrupt_FramingError:
            // Clear FE flag by writing 1 to FE clear flag in ICR
            SET_BIT(USARTx->ICR, USART_ICR_FECF);
            break;
        case USART_Interrupt_CharacterMatch:
            // Clear CMF flag by writing 1 to CMF clear flag in ICR
            SET_BIT(USARTx->ICR, USART_ICR_CMCF);
            break;
        case USART_Interrupt_ReceiverTimeout:
            // Clear RTOF flag by writing 1 to RTOF clear flag in ICR
            SET_BIT(USARTx->ICR, USART_ICR_RTOCF);
            break;
        case USART_Interrupt_EndOfBlock:
            // Clear EOBF flag by writing 1 to EOBF clear flag in ICR
            SET_BIT(USARTx->ICR, USART_ICR_EOBCF);
            break;
        case USART_Interrupt_WakeupFromLowPowerMode:
            // Clear WUF flag by writing 1 to WUF clear flag in ICR
            SET_BIT(USARTx->ICR, USART_ICR_WUCF);
            break;
        case USART_Interrupt_SPI_SlaveUnderrun:
            // Clear UDR flag by writing 1 to UDR clear flag in ICR
            SET_BIT(USARTx->ICR, USART_ICR_UDRCF);
            break;
        case USART_Interrupt_ReceptionDataNotEmpty:

        case USART_Interrupt_ReceiveFIFONotEmpty:
        case USART_Interrupt_ReceiveFIFOFull:
        case USART_Interrupt_ReceiveFIFOThresholdReached:
        case USART_Interrupt_TransmitDataRegisterEmpty:
        case USART_Interrupt_TransmitFIFONotFull:
        case USART_Interrupt_TransmitFIFOEmpty:
        case USART_Interrupt_TransmitFIFOThresholdReached:
            break;
        default:
            // Handle other cases or invalid interrupts
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
    SET_BIT(USARTx->CR1, USART_CR1_UE);
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
    CLEAR_BIT(USARTx->CR1, USART_CR1_UE);
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
void USART_Transmit_Single_Data(USART_ST *USARTx, uint16_t Data)
{
    // Wait until TXFNF flag is set, indicating transmit data register is not full
    while (!(CHECK_BIT(USARTx->ISR, USART_ISR_TXE_TXFNF)));

    // Write the data to the USART transmit data register
    USARTx->TDR = (Data & 0x1FF);

    // Wait until TC flag is set, indicating transmission complete
    while (!(CHECK_BIT(USARTx->ISR, USART_ISR_TC)));
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
uint16_t USART_Receive_Single_Data(USART_ST *USARTx)
{
    // Read the data from the USART receive data register
    return (uint16_t)(USARTx->RDR & 0x1FF);
}

/*
 * Function: USART_FlushReceiveData
 * --------------------------------
 * Flushes the receive data buffer of the specified USART.
 * 
 * Parameters:
 *   USARTx: Pointer to the USART register structure.
 *
 * Returns:
 *   None
 */
void USART_FlushReceiveData(USART_ST *USARTx) 
{
    SET_BIT(USARTx->RQR, USART_RQR_RXFRQ);  // Set the RXFRQ bit to flush receive data
}

/*
 * Function: USART_FlushTransmitData
 * ---------------------------------
 * Flushes the transmit data buffer of the specified USART.
 * 
 * Parameters:
 *   USARTx: Pointer to the USART register structure.
 *
 * Returns:
 *   None
 */
void USART_FlushTransmitData(USART_ST *USARTx) 
{
    SET_BIT(USARTx->RQR, USART_RQR_TXFRQ);  // Set the TXFRQ bit to flush transmit data
}

/*
 * Function: USART_SendBreakRequest
 * --------------------------------
 * Sends a break request on the specified USART.
 * 
 * Parameters:
 *   USARTx: Pointer to the USART register structure.
 *
 * Returns:
 *   None
 */
void USART_SendBreakRequest(USART_ST *USARTx) 
{
    SET_BIT(USARTx->RQR, USART_RQR_SBKRQ);  // Set the SBKRQ bit to send break request
}

/*
 * Function: USART_EnterMuteMode
 * -----------------------------
 * Enters mute mode on the specified USART.
 * 
 * Parameters:
 *   USARTx: Pointer to the USART register structure.
 *
 * Returns:
 *   None
 */
void USART_EnterMuteMode(USART_ST *USARTx) 
{
    SET_BIT(USARTx->RQR, USART_RQR_MMRQ);  // Set the MMRQ bit to enter mute mode
}

/*
 * Function: USART_AutoBaudRateRequest
 * -----------------------------------
 * Requests auto-baud rate detection on the specified USART.
 * 
 * Parameters:
 *   USARTx: Pointer to the USART register structure.
 *
 * Returns:
 *   None
 */
void USART_AutoBaudRateRequest(USART_ST *USARTx) 
{
    SET_BIT(USARTx->RQR, USART_RQR_ABRRQ);  // Set the ABRRQ bit to request auto-baud rate detection
}
