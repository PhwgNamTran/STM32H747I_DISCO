#ifndef STM32H747XI_SYSCFG_H
#define STM32H747XI_SYSCFG_H

#include "Common.h"
#include "STM32H747XI_RCC.h"
#include "STM32H747XI_GPIO.h"

/* Refer to RM0399 Reference Manual from http://www.st.com */

#define SYSCFG_BASE     0x58000400UL    /* SYSCFG Base Address */

/* SYSCFG Declaration */
#define SYSCFG         ((SYSCFG_ST *) SYSCFG_BASE)

#define RCC_APB4ENR_SYSCFGEN    (1 << 1)


extern void SYSCFG_Enable(void);
extern void SYSCFG_EXITx_GPIO_Cfg(GPIO_ST *GPIOx, uint8_t GPIO_Pin);

#endif