#ifndef SYSTEM_INIT_H
#define SYSTEM_INIT_H

/*
 * System Initialization:
 * ----------------------
 * This header file declares functions for initializing the system and peripherals.
 */

extern void System_Init(void);         /**< Initialize the system */
extern void Peripherals_Init(void);     /**< Initialize peripherals */
extern void SystemClock_Config(void);
extern void Timer_2_Init(void);

#endif /* SYSTEM_INIT_H */
