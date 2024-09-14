#ifndef STM32H747XI_SYSCFG_H
#define STM32H747XI_SYSCFG_H

#include "STM32H747xx.h"
#include "STM32H7_RCC.h"
#include "STM32H7_GPIO.h"

extern void SYSCFG_Enable(void);
extern void SYSCFG_EXITx_GPIO_Cfg(GPIO_ST *GPIOx, uint8_t GPIO_Pin);

#endif