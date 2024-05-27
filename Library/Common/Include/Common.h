#ifndef COMMON_H
#define COMMON_H

/*******************************************************/
/* START OF TYPEDEF FOR COMMON USE                     */
/*******************************************************/

typedef enum
{
    FALSE,
    TRUE
} BOOL;

typedef unsigned    char           UINT8;
typedef signed      char           SINT8;

typedef unsigned    short int      UINT16;
typedef signed      short int      SINT16;

typedef unsigned    long int       UINT32;
typedef signed      long int       SINT32;

typedef BOOL ReturnType;

/********************************************************/
/* END OF TYPEDEF FOR COMMON USE                        */
/********************************************************/


/********************************************************/
/* START OF MACRO DEFINITION FOR COMMON USE             */
/********************************************************/
#define REG(x) (*(UINT32 *)x)

#define E_OK        FALSE
#define E_NOT_OK    TRUE

/********************************************************/
/* END OF OF MACRO DEFINITION FOR COMMON USE            */
/********************************************************/



/********************************************************/
/* START OF FUNCTION DECLARATION FOR COMMON USE         */
/********************************************************/

extern void SET_BIT(UINT32 addr, UINT32 bitmask);
extern void CLEAR_BIT(UINT32 addr, UINT32 bitmask);

/********************************************************/
/* END OF FUNCTION DECLARATION FOR COMMON USE           */
/********************************************************/

#endif