#ifndef COMMON_H
#define COMMON_H

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

#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CHECK_BIT(REG, BIT)   ((READ_BIT(REG, BIT)==(BIT))?TRUE:FALSE)

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))


#define STD_ON  TRUE
#define STD_OFF FALSE

#endif