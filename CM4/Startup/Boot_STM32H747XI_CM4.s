.syntax unified
.cpu cortex-m7
.fpu softvfp
.thumb

/* start address for the initialization values of the .data section. defined in linker script */
.word _sidata
/* start address for the .data section. defined in linker script */
.word _sdata
/* end address for the .data section. defined in linker script */
.word _edata
/* start address for the .bss section. defined in linker script */
.word _sbss
/* end address for the .bss section. defined in linker script */
.word _ebss
/* stack used for SystemInit_ExtMemCtl; always internal RAM used */
  
.section .text.Reset_Handler
.weak Reset_Handler
.type Reset_Handler, %function

Reset_Handler:
    LDR  sp, =_estack
    /* Call the clock system initialization function.*/
    BL   System_Init

    /* Copy the data segment initializers from flash to SRAM */
    LDR  r0, =_sdata
    LDR  r1, =_edata
    LDR  r2, =_sidata
    MOVS r3, #0
    B    LoopCopyDataInit

    CopyDataInit:
        LDR  r4, [r2, r3]
        STR  r4, [r0, r3]
        ADDS r3, r3, #4

    LoopCopyDataInit:
        ADDS r4, r0, r3
        CMP  r4, r1
        BCC  CopyDataInit
    
    /* Zero fill the bss segment. */
    LDR  r2, =_sbss
    LDR  r4, =_ebss
    MOVS r3, #0
    B    LoopFillZerobss

    FillZerobss:
        STR  r3, [r2]
        ADDS r2, r2, #4

    LoopFillZerobss:
        CMP r2, r4
        BCC FillZerobss

    /* Call static constructors */
    /* BL __libc_init_array */
    
    /* Call the application's entry point. */
    BL main
    BX lr
.size Reset_Handler, .-Reset_Handler
