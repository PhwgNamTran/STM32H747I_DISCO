#include "STM32H747XI_NVIC.h"

void NVIC_EnableIRQ(IRQn_N IRQn)  
{
    UINT32 ISER_Idx = 0;
    UINT32 IRQn_Pos = 0;
    if((UINT8)IRQn >= 0)
    {
        ISER_Idx = ((UINT8)IRQn) >> 5UL;
        IRQn_Pos = 1UL << (((UINT8)IRQn) & 0x1FUL);
        SET_BIT(NVIC->ISER[ISER_Idx], IRQn_Pos);
    }
}

BOOL NVIC_GetEnableIRQ(IRQn_N IRQn)       
{
    UINT32 ISER_Idx = 0;
    UINT32 IRQn_Pos = 0;
    BOOL   IRQn_Enabled = FALSE;

    if((UINT8)IRQn >= 0)
    {
        ISER_Idx = ((UINT8)IRQn) >> 5UL;
        IRQn_Pos = 1UL << (((UINT8)IRQn) & 0x1FUL);
        IRQn_Enabled = CHECK_BIT(NVIC->ISER[ISER_Idx], IRQn_Pos);
    }
    else
    {
        IRQn_Enabled = FALSE;
    }
    return IRQn_Enabled;
}

void NVIC_DisableIRQ(IRQn_N IRQn)      
{

}

UINT32 NVIC_GetPendingIRQ(IRQn_N IRQn)   
{
    return 0;
}

void NVIC_SetPendingIRQ(IRQn_N IRQn) 
{

}

void NVIC_ClearPendingIRQ(IRQn_N IRQn)
{

}

UINT32 NVIC_GetActive(IRQn_N IRQn)
{
    return 0;
}   

void NVIC_SetPriority(IRQn_N IRQn, UINT8 Priority)
{
    if((UINT8)IRQn >= 0)
    {
        SET_BIT(NVIC->IP[((UINT8)IRQn)], (UINT8)((Priority & 0xFFUL)));
    }
}

UINT32 NVIC_GetPriority(IRQn_N IRQn)
{
    return 0;
}                      