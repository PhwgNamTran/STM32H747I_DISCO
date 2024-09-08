#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef bool boolean;
typedef bool ReturnType; /**< Return type */

/*
 * Macros for bit manipulation.
 */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))       /**< Set a bit in a register */
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))      /**< Clear a bit in a register */
#define READ_BIT(REG, BIT)    ((REG) & (BIT))        /**< Read a bit in a register */
#define CHECK_BIT(REG, BIT)   ((READ_BIT(REG, BIT) == (BIT)) ? true : false) /**< Check if a bit is set */
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
