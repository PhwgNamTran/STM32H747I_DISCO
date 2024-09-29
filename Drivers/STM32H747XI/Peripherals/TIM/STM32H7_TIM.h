#ifndef STM32H7_TIM_H
#define STM32H7_TIM_H

#include "STM32H747xx.h"
#include "STM32H7_RCC.h"

/**
  * @brief  TIM Handle structures definition
  */
typedef struct
{
  TIM_ST                       *Instance;         /*!< Register base address                             */
  TIM_Init_ST                  Init;              /*!< TIM Time Base required parameters                 */
  TIM_ActiveChannel_N          Channel;           /*!< Active channel                                    */
  volatile TIM_State_N         State;             /*!< TIM operation state                               */
  volatile TIM_ChannelState_N  ChannelState[6];   /*!< TIM channel operation state                       */
  volatile TIM_ChannelState_N  ChannelNState[4];  /*!< TIM complementary channel operation state         */
  volatile TIM_DMABurstState_N DMABurstState;     /*!< DMA burst operation state                         */
} TIM_Handle_ST;

/**
  * @brief  TIM Init structures definition
  */
typedef struct
{
  uint32_t            Prescaler;
  uint32_t            CounterMode;
  uint32_t            Period;
  TIM_ClockDivision_N ClockDivision;
  uint32_t            AutoReloadPreload;
} TIM_Init_ST;

/**
  * @brief  TIM Counter Mode structures definition
  */
typedef enum
{
    TIM_COUNTERMODE_UP_N             = 0x00000000UL,    /*!< Up counting mode */
    TIM_COUNTERMODE_DOWN_N           = TIM_CR1_DIR,     /*!< Down counting mode */
    TIM_COUNTERMODE_CENTERALIGNED1_N = TIM_CR1_CMS_0,   /*!< Center-aligned mode 1 */
    TIM_COUNTERMODE_CENTERALIGNED2_N = TIM_CR1_CMS_1,   /*!< Center-aligned mode 2 */
    TIM_COUNTERMODE_CENTERALIGNED3_N = TIM_CR1_CMS      /*!< Center-aligned mode 3 */
} TIM_CounterMode_N;

typedef enum
{
    TIM_UPDATE_INTERRUPT_N  = TIM_DIER_UIE,     /*!< Update interrupt            */
    TIM_CC1_INTERRUPT_N     = TIM_DIER_CC1IE,   /*!< Capture/Compare 1 interrupt */
    TIM_CC2_INTERRUPT_N     = TIM_DIER_CC2IE,   /*!< Capture/Compare 2 interrupt */
    TIM_CC3_INTERRUPT_N     = TIM_DIER_CC3IE,   /*!< Capture/Compare 3 interrupt */
    TIM_CC4_INTERRUPT_N     = TIM_DIER_CC4IE,   /*!< Capture/Compare 4 interrupt */
    TIM_COM_INTERRUPT_N     = TIM_DIER_COMIE,   /*!< Communication interrupt     */
    TIM_TRIGGER_INTERRUPT_N = TIM_DIER_TIE,     /*!< Trigger interrupt           */
    TIM_BREAK_INTERRUPT_N   = TIM_DIER_BIE      /*!< Break interrupt             */
} TIM_Interrupt_N;

/**
  * @brief  TIM DMA Request structures definition
  */
typedef enum
{
    TIM_UPDATE_DMA_REQUEST_N    = TIM_DIER_UDE,        /*!< DMA request is triggered by the update event */
    TIM_CC1_DMA_REQUEST_N       = TIM_DIER_CC1DE,      /*!< Capture/Compare 1 DMA request */
    TIM_CC2_DMA_REQUEST_N       = TIM_DIER_CC2DE,      /*!< Capture/Compare 2 DMA request */
    TIM_CC3_DMA_REQUEST_N       = TIM_DIER_CC3DE,      /*!< Capture/Compare 3 DMA request */
    TIM_CC4_DMA_REQUEST_N       = TIM_DIER_CC4DE,      /*!< Capture/Compare 4 DMA request */
    TIM_COM_DMA_REQUEST_N       = TIM_DIER_COMDE,      /*!< Communication DMA request */
    TIM_TRIGGERED_DMA_REQUEST_N = TIM_DIER_TDE         /*!< DMA request is triggered by the trigger event */
} TIM_DMA_Request_N;

/**
  * @brief  TIM CLock Division definition
  */
typedef enum
{
    TIM_CLOCKDIVISION_DIV1 = 0x00000000UL,     /*!< Clock division: tDTS=tCK_INT   */
    TIM_CLOCKDIVISION_DIV2 = TIM_CR1_CKD_0,    /*!< Clock division: tDTS=2*tCK_INT */
    TIM_CLOCKDIVISION_DIV4 = TIM_CR1_CKD_1     /*!< Clock division: tDTS=4*tCK_INT */
}TIM_ClockDivision_N;

/**
  * @brief  TIM FLAGS definition
  */
typedef enum {
    TIM_FLAG_UPDATE_N       = TIM_SR_UIF,     /*!< Update interrupt flag         */
    TIM_FLAG_CC1_N          = TIM_SR_CC1IF,   /*!< Capture/Compare 1 interrupt flag */
    TIM_FLAG_CC2_N          = TIM_SR_CC2IF,   /*!< Capture/Compare 2 interrupt flag */
    TIM_FLAG_CC3_N          = TIM_SR_CC3IF,   /*!< Capture/Compare 3 interrupt flag */
    TIM_FLAG_CC4_N          = TIM_SR_CC4IF,   /*!< Capture/Compare 4 interrupt flag */
    TIM_FLAG_CC5_N          = TIM_SR_CC5IF,   /*!< Capture/Compare 5 interrupt flag */
    TIM_FLAG_CC6_N          = TIM_SR_CC6IF,   /*!< Capture/Compare 6 interrupt flag */
    TIM_FLAG_COM_N          = TIM_SR_COMIF,   /*!< Commutation interrupt flag    */
    TIM_FLAG_TRIGGER_N      = TIM_SR_TIF,     /*!< Trigger interrupt flag        */
    TIM_FLAG_BREAK_N        = TIM_SR_BIF,     /*!< Break interrupt flag          */
    TIM_FLAG_BREAK2_N       = TIM_SR_B2IF,    /*!< Break 2 interrupt flag        */
    TIM_FLAG_SYSTEM_BREAK_N = TIM_SR_SBIF,    /*!< System Break interrupt flag   */
    TIM_FLAG_CC1OF_N        = TIM_SR_CC1OF,   /*!< Capture 1 overcapture flag    */
    TIM_FLAG_CC2OF_N        = TIM_SR_CC2OF,   /*!< Capture 2 overcapture flag    */
    TIM_FLAG_CC3OF_N        = TIM_SR_CC3OF,   /*!< Capture 3 overcapture flag    */
    TIM_FLAG_CC4OF_N        = TIM_SR_CC4OF    /*!< Capture 4 overcapture flag    */
} TIM_FLAG_N;

/**
  * @brief  TIM Channel structures definition
  */
typedef enum
{
  TIM_CHANNEL_1   = 0x00000000UL,    /*!< The channel 1 */
  TIM_CHANNEL_2   = 0x00000004UL,    /*!< The channel 2 */
  TIM_CHANNEL_3   = 0x00000008UL,    /*!< The channel 3 */
  TIM_CHANNEL_4   = 0x0000000CUL,    /*!< The channel 4 */
  TIM_CHANNEL_5   = 0x00000010UL,    /*!< The channel 5 */
  TIM_CHANNEL_6   = 0x00000014UL,    /*!< The channel 6 */
  TIM_CHANNEL_ALL = 0x0000003CUL     /*!< All channels  */
} TIM_Channel_N;

/**
  * @brief  TIM Active Channel structures definition
  */
typedef enum
{
  TIM_ACTIVE_CHANNEL_1       = 0x00000001UL,    /*!< The active channel is 1     */
  TIM_ACTIVE_CHANNEL_2       = 0x00000002UL,    /*!< The active channel is 2     */
  TIM_ACTIVE_CHANNEL_3       = 0x00000004UL,    /*!< The active channel is 3     */
  TIM_ACTIVE_CHANNEL_4       = 0x00000008UL,    /*!< The active channel is 4     */
  TIM_ACTIVE_CHANNEL_5       = 0x00000010UL,    /*!< The active channel is 5     */
  TIM_ACTIVE_CHANNEL_6       = 0x00000020UL,    /*!< The active channel is 6     */
  TIM_ACTIVE_CHANNEL_CLEARED = 0x00000000UL     /*!< All active channels cleared */
} TIM_ActiveChannel_N;

/**
  * @brief  TIM State structures definition
  */
typedef enum
{
  TIM_STATE_RESET   = 0x00U,    /*!< Peripheral not yet initialized or disabled  */
  TIM_STATE_READY   = 0x01U,    /*!< Peripheral Initialized and ready for use    */
  TIM_STATE_BUSY    = 0x02U,    /*!< An internal process is ongoing              */
  TIM_STATE_TIMEOUT = 0x03U,    /*!< Timeout state                               */
  TIM_STATE_ERROR   = 0x04U     /*!< Reception process is ongoing                */
} TIM_State_N;

/**
  * @brief  TIM Channel States definition
  */
typedef enum
{
  TIM_CHANNEL_STATE_RESET = 0x00U,    /*!< TIM Channel initial state                         */
  TIM_CHANNEL_STATE_READY = 0x01U,    /*!< TIM Channel ready for use                         */
  TIM_CHANNEL_STATE_BUSY  = 0x02U     /*!< An internal process is ongoing on the TIM channel */
} TIM_ChannelState_N;

/**
  * @brief  TIM DMA Burst States definition
  */
typedef enum
{
  DMA_BURST_STATE_RESET = 0x00U,    /*!< DMA Burst initial state */
  DMA_BURST_STATE_READY = 0x01U,    /*!< DMA Burst ready for use */
  DMA_BURST_STATE_BUSY  = 0x02U     /*!< Ongoing DMA Burst       */
} TIM_DMABurstState_N;

extern void TIM_DMA_Interrupt_Mode_Enable(TIM_ST *TIMx, uint8_t DMA_Interrupt_Mode);
extern void TIM_DMA_Interrupt_Mode_Disable(TIM_ST *TIMx, uint8_t DMA_Interrupt_Mode);
extern void TIM_DMA_Interrupt_Clear_Status(TIM_ST *TIMx);
extern boolean TIM_DMA_Interrupt_Check_Status(TIM_ST *TIMx);
extern void TIM_Enable(TIM_ST *TIMx);

#endif