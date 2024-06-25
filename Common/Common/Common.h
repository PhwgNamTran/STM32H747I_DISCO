#ifndef COMMON_H
#define COMMON_H

/*
 * Boolean type definitions.
 */
typedef enum
{
    FALSE, /**< Boolean false */
    TRUE   /**< Boolean true */
} BOOL;

typedef unsigned char UINT8; /**< Unsigned 8-bit integer */
typedef signed char SINT8;   /**< Signed 8-bit integer */

typedef unsigned short int UINT16; /**< Unsigned 16-bit integer */
typedef signed short int SINT16;   /**< Signed 16-bit integer */

typedef unsigned long int UINT32; /**< Unsigned 32-bit integer */
typedef signed long int SINT32;   /**< Signed 32-bit integer */

typedef BOOL ReturnType; /**< Return type */

/*
 * Macros for bit manipulation.
 */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))       /**< Set a bit in a register */
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))      /**< Clear a bit in a register */
#define READ_BIT(REG, BIT)    ((REG) & (BIT))        /**< Read a bit in a register */
#define CHECK_BIT(REG, BIT)   ((READ_BIT(REG, BIT) == (BIT)) ? TRUE : FALSE) /**< Check if a bit is set */
#define CLEAR_REG(REG)        ((REG) = (0x0))        /**< Clear a register */
#define WRITE_REG(REG, VAL)   ((REG) = (VAL))        /**< Write a value to a register */
#define READ_REG(REG)         ((REG))                /**< Read a register */
#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK))) /**< Modify a register */

/*
 * Standard ON and OFF definitions.
 */
#define STD_ON  1  /**< Standard ON */
#define STD_OFF 0  /**< Standard OFF */

#endif /* COMMON_H */
