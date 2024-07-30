# STM32H747XI

This project is for my learning and hobby purpose

Learn ARM-Based Mirocontroller programing with bare metal

Hardware: STM32H747I-DISCO Board

Structure:

    - CM4/CM7: Include main function, periperals enable, interrupt enable, ... for each core.

    - Drivers:

        + Common:

        + BoardSupport:
        
        + STM32H747XI:

Progress: Focus on Single core (CM7) first

    1. Makefile, Linkerfile, Start-Up file


    2. RCC (Reset and Clock Control):

        Manages the system clocks and resets for various peripherals.


    3. GPIO (General-Purpose Input/Output):

        Configures the pins of the microcontroller to function as input or output.


    4. SYSCFG, EXTI, and NVIC (System Configuration, External Interrupt, and Nested Vectored Interrupt Controller):

        - SYSCFG: System configuration controller for various system and peripheral settings.

        - EXTI: Manages external interrupts from GPIO pins.

        - NVIC: Manages the priority of interrupts and handles the interrupt vector table.


    5. TIM (Timer):

        Used for generating precise time delays and event counting.


    6. USART (Universal Synchronous/Asynchronous Receiver/Transmitter):

        Used for serial communication, supporting both synchronous and asynchronous modes.
