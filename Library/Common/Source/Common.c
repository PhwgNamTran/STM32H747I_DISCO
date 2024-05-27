#include "Common.h"

void SET_BIT(UINT32 addr, UINT32 bitmask)
{
    REG(addr) |= bitmask;
}

void CLEAR_BIT(UINT32 addr, UINT32 bitmask)
{
    REG(addr) &= ~(bitmask);
}