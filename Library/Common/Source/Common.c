#include "Common.h"

/*
Function description: Set value of bits in resgiser to 1
Input: 
        - Register address
        - Mask for target bits
Return value: N/A
*/
void SET_BIT(UINT32 addr, UINT32 bitmask)
{
    REG(addr) |= bitmask;
}

/*
Function description: Set value of bits in resgiser to 0
Input:
        - Register address
        - Mask for target bits
Return value: N/A
*/
void CLEAR_BIT(UINT32 addr, UINT32 bitmask)
{
    REG(addr) &= ~(bitmask);
}

/*
Function description: Check value of bits in resgiser if equal to provided mask
Input:
        - Register address
        - Mask for target bits
Return value:
        - TRUE: value of bits in resgiser equal to provided mask
        - FALSE: value of bits in resgiser if NOT equal to provided mask
*/
BOOL CHECK_BIT(UINT32 addr, UINT32 bitmask)
{
    if((REG(addr) & bitmask) == bitmask)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}