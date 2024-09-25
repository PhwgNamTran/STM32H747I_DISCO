#ifndef STM32H7_TIM_H
#define STM32H7_TIM_H

#include "STM32H747xx.h"
#include "STM32H7_RCC.h"

/* Refer to RM0399 Reference Manual from http://www.st.com and CMSIS Library */

typedef enum
{
    TIM_CounterMode_Up_N = 0,              /*!< Up counting mode */
    TIM_CounterMode_Down_N,                /*!< Down counting mode */
    TIM_CounterMode_EdgeAligned_N,         /*!< Edge-aligned mode */
    TIM_CounterMode_CenterAligned_1_N,     /*!< Center-aligned mode 1 */
    TIM_CounterMode_CenterAligned_2_N,     /*!< Center-aligned mode 2 */
    TIM_CounterMode_CenterAligned_3_N      /*!< Center-aligned mode 3 */
} TIM_CounterMode_N;

typedef enum
{
    TIM_CC1_Interrupt_N = 1U,         /*!< Capture/Compare 1 interrupt */
    TIM_CC2_Interrupt_N = 2U,         /*!< Capture/Compare 2 interrupt */
    TIM_CC3_Interrupt_N = 3U,         /*!< Capture/Compare 3 interrupt */
    TIM_CC4_Interrupt_N = 4U,         /*!< Capture/Compare 4 interrupt */
    TIM_COM_Interrupt_N = 5U          /*!< Communication interrupt */
} TIM_Interrupt_N;

typedef enum
{
    TIM_CC1_DMA_Request_N = 9U,       /*!< Capture/Compare 1 DMA request */
    TIM_CC2_DMA_Request_N = 10U,      /*!< Capture/Compare 2 DMA request */
    TIM_CC3_DMA_Request_N = 11U,      /*!< Capture/Compare 3 DMA request */
    TIM_CC4_DMA_Request_N = 12U,      /*!< Capture/Compare 4 DMA request */
    TIM_COM_DMA_Request_N = 13U       /*!< Communication DMA request */
} TIM_DMA_Request_N;

typedef enum {
    TIM_Mode_TimeBase_N = 0U,         /*!< Timer operates in Time Base mode */
    TIM_Mode_OutputCompare_N,         /*!< Timer operates in Output Compare mode */
    TIM_Mode_PWM_N,                   /*!< Timer operates in PWM mode */
    TIM_Mode_InputCapture_N,          /*!< Timer operates in Input Capture mode */
    TIM_Mode_OnePulse_N,              /*!< Timer operates in One Pulse mode */
    TIM_Mode_Encoder_N,               /*!< Timer operates in Encoder Interface mode */
    TIM_Mode_Master_N,                /*!< Timer operates in Master mode */
    TIM_Mode_Slave_N,                 /*!< Timer operates in Slave mode */
    TIM_Mode_ForcedOutput_N           /*!< Timer operates in Forced Output mode */
} TIM_Mode_N;

typedef enum {
    TIM_Channel_1_N = 1U,             /*!< Channel 1 */
    TIM_Channel_2_N = 2U,             /*!< Channel 2 */
    TIM_Channel_3_N = 3U,             /*!< Channel 3 */
    TIM_Channel_4_N = 4U              /*!< Channel 4 */
} TIM_Channel_N;

extern void TIM_DMA_Interrupt_Mode_Enable(TIM_ST *TIMx, uint8_t DMA_Interrupt_Mode);
extern void TIM_DMA_Interrupt_Mode_Disable(TIM_ST *TIMx, uint8_t DMA_Interrupt_Mode);
extern void TIM_DMA_Interrupt_Clear_Status(TIM_ST *TIMx);
extern boolean TIM_DMA_Interrupt_Check_Status(TIM_ST *TIMx);
extern void TIM_Enable(TIM_ST *TIMx);

#endif