#ifndef STM32H747XI_RCC_H
#define STM32H747XI_RCC_H

#include "STM32H747xx.h"

/* Refer to RM0399 Reference Manual from http://www.st.com */

#define System_Clock_Source_HSI         1U
#define System_Clock_Source_HSE         2U
#define System_Clock_Source_CSI         3U
#define System_Clock_Source_PLL1_P_CK   4U

#define CR_HSI_POS      0U
#define CR_HSI          (1 << CR_HSI_POS)

#define CR_HSIDIV_POS   3U

#define HSI_Clock   64000000U

#endif