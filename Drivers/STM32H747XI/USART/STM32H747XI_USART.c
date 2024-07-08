#include "STM32H747XI_USART.h"


void USART_PIN_Config(GPIO_ST *GPIOx, UINT8 USART_Rx_PIN, UINT8 USART_Tx_PIN)
{
    GPIO_Mode_Set(GPIOx, USART_Rx_PIN, GPIO_Mode_Alternate_Function);
    GPIO_Mode_Set(GPIOx, USART_Tx_PIN, GPIO_Mode_Alternate_Function);
}