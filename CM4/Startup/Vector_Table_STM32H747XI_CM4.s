.syntax unified
.cpu cortex-m7
.fpu softvfp
.thumb

.global g_pfnVectors
.global Default_Handler

.section .isr_vector,"a",%progbits
.type g_pfnVectors, %object

g_pfnVectors:
    .word _estack
    .word Reset_Handler                            // Reset                                             
    .word 0                                        // NMI                                               
    .word 0                                        // HardFault                                         
    .word 0                                        // MemManage                                         
    .word 0                                        // BusFault                                          
    .word 0                                        // UsageFault                                        
    .word 0                                        // Reserved                                          
    .word 0                                        // Reserved                                          
    .word 0                                        // Reserved                                          
    .word 0                                        // Reserved                                          
    .word 0                                        // SVC                                               
    .word 0                                        // DebugMon                                          
    .word 0                                        // Reserved                                          
    .word 0                                        // PendSV                                            
    .word 0                                        // SysTick                                           
    /* External */
    .word 0                                        // Window WatchDog Interrupt ( wwdg1_it, wwdg2_it)   
    .word 0                                        // PVD/AVD through EXTI Line detection               
    .word 0                                        // Tamper and TimeStamps through the EXTI line       
    .word 0                                        // RTC Wakeup through the EXTI line                  
    .word 0                                        // FLASH                                             
    .word 0                                        // RCC                                               
    .word 0                                        // EXTI Line0                                        
    .word 0                                        // EXTI Line1                                        
    .word 0                                        // EXTI Line2                                        
    .word 0                                        // EXTI Line3                                        
    .word 0                                        // EXTI Line4                   
    .word 0                                        // DMA1 Stream 0                
    .word 0                                        // DMA1 Stream 1                
    .word 0                                        // DMA1 Stream 2                
    .word 0                                        // DMA1 Stream 3                
    .word 0                                        // DMA1 Stream 4                
    .word 0                                        // DMA1 Stream 5                
    .word 0                                        // DMA1 Stream 6                
    .word 0                                        // ADC1, ADC2 and ADC3s         
    .word 0                                        // FDCAN1 interrupt line 0      
    .word 0                                        // FDCAN2 interrupt line 0      
    .word 0                                        // FDCAN1 interrupt line 1      
    .word 0                                        // FDCAN2 interrupt line 1      
    .word 0                                        // External Line[9:5]s          
    .word 0                                        // TIM1 Break interrupt         
    .word 0                                        // TIM1 Update interrupt        
    .word 0                                        // TIM1 Trigger and Commutation interrupt 
    .word 0                                        // TIM1 Capture Compare         
    .word 0                                        // TIM2                         
    .word 0                                        // TIM3                         
    .word 0                                        // TIM4                         
    .word 0                                        // I2C1 Event                   
    .word 0                                        // I2C1 Error                   
    .word 0                                        // I2C2 Event                   
    .word 0                                        // I2C2 Error                   
    .word 0                                        // SPI1                         
    .word 0                                        // SPI2                         
    .word 0                                        // USART1                       
    .word 0                                        // USART2                       
    .word 0                                        // USART3                       
    .word 0                                        // External Line[15:10]s        
    .word 0                                        // RTC Alarm (A and B) through EXTI Line 
    .word 0                                        // Reserved                     
    .word 0                                        // TIM8 Break and TIM12         
    .word 0                                        // TIM8 Update and TIM13        
    .word 0                                        // TIM8 Trigger and Commutation and TIM14 
    .word 0                                        // TIM8 Capture Compare         
    .word 0                                        // DMA1 Stream7                 
    .word 0                                        // FMC                          
    .word 0                                        // SDMMC1                       
    .word 0                                        // TIM5                         
    .word 0                                        // SPI3                         
    .word 0                                        // UART4                        
    .word 0                                        // UART5                        
    .word 0                                        // TIM6 and DAC1&2 underrun errors 
    .word 0                                        // TIM7                         
    .word 0                                        // DMA2 Stream 0                
    .word 0                                        // DMA2 Stream 1                
    .word 0                                        // DMA2 Stream 2                
    .word 0                                        // DMA2 Stream 3                
    .word 0                                        // DMA2 Stream 4                
    .word 0                                        // Ethernet                     
    .word 0                                        // Ethernet Wakeup through EXTI line 
    .word 0                                        // FDCAN calibration unit interrupt  
    .word 0                                        // CM7 Send event interrupt for CM4  
    .word 0                                        // CM4 Send event interrupt for CM7  
    .word 0                                        // Reserved                     
    .word 0                                        // Reserved                     
    .word 0                                        // DMA2 Stream 5                
    .word 0                                        // DMA2 Stream 6                
    .word 0                                        // DMA2 Stream 7                
    .word 0                                        // USART6                       
    .word 0                                        // I2C3 event                   
    .word 0                                        // I2C3 error                   
    .word 0                                        // USB OTG HS End Point 1 Out   
    .word 0                                        // USB OTG HS End Point 1 In    
    .word 0                                        // USB OTG HS Wakeup through EXTI 
    .word 0                                        // USB OTG HS                   
    .word 0                                        // DCMI                         
    .word 0                                        // Reserved                     
    .word 0                                        // Rng                          
    .word 0                                        // FPU                          
    .word 0                                        // UART7                        
    .word 0                                        // UART8                        
    .word 0                                        // SPI4                         
    .word 0                                        // SPI5                         
    .word 0                                        // SPI6                         
    .word 0                                        // SAI1                         
    .word 0                                        // LTDC                         
    .word 0                                        // LTDC error                   
    .word 0                                        // DMA2D                        
    .word 0                                        // SAI2                         
    .word 0                                        // QUADSPI                      
    .word 0                                        // LPTIM1                       
    .word 0                                        // HDMI_CEC                     
    .word 0                                        // I2C4 Event                   
    .word 0                                        // I2C4 Error                   
    .word 0                                        // SPDIF_RX                     
    .word 0                                        // USB OTG FS End Point 1 Out   
    .word 0                                        // USB OTG FS End Point 1 In    
    .word 0                                        // USB OTG FS Wakeup through EXTI 
    .word 0                                        // USB OTG FS                   
    .word 0                                        // DMAMUX1 Overrun interrupt    
    .word 0                                        // HRTIM Master Timer global Interrupt 
    .word 0                                        // HRTIM Timer A global Interrupt 
    .word 0                                        // HRTIM Timer B global Interrupt 
    .word 0                                        // HRTIM Timer C global Interrupt 
    .word 0                                        // HRTIM Timer D global Interrupt 
    .word 0                                        // HRTIM Timer E global Interrupt 
    .word 0                                        // HRTIM Fault global Interrupt   
    .word 0                                        // DFSDM Filter0 Interrupt        
    .word 0                                        // DFSDM Filter1 Interrupt        
    .word 0                                        // DFSDM Filter2 Interrupt        
    .word 0                                        // DFSDM Filter3 Interrupt        
    .word 0                                        // SAI3 global Interrupt          
    .word 0                                        // Serial Wire Interface 1 global interrupt 
    .word 0                                        // TIM15 global Interrupt      
    .word 0                                        // TIM16 global Interrupt      
    .word 0                                        // TIM17 global Interrupt      
    .word 0                                        // MDIOS Wakeup  Interrupt     
    .word 0                                        // MDIOS global Interrupt      
    .word 0                                        // JPEG global Interrupt       
    .word 0                                        // MDMA global Interrupt       
    .word 0                                        // DSI global Interrupt        
    .word 0                                        // SDMMC2 global Interrupt     
    .word 0                                        // HSEM1 global Interrupt      
    .word 0                                        // HSEM1 global Interrupt      
    .word 0                                        // ADC3 global Interrupt       
    .word 0                                        // DMAMUX Overrun interrupt    
    .word 0                                        // BDMA Channel 0 global Interrupt 
    .word 0                                        // BDMA Channel 1 global Interrupt 
    .word 0                                        // BDMA Channel 2 global Interrupt 
    .word 0                                        // BDMA Channel 3 global Interrupt 
    .word 0                                        // BDMA Channel 4 global Interrupt 
    .word 0                                        // BDMA Channel 5 global Interrupt 
    .word 0                                        // BDMA Channel 6 global Interrupt 
    .word 0                                        // BDMA Channel 7 global Interrupt 
    .word 0                                        // COMP1 global Interrupt     
    .word 0                                        // LP TIM2 global interrupt   
    .word 0                                        // LP TIM3 global interrupt   
    .word 0                                        // LP TIM4 global interrupt   
    .word 0                                        // LP TIM5 global interrupt   
    .word 0                                        // LP UART1 interrupt         
    .word 0                                        // Window Watchdog reset interrupt (exti_d2_wwdg_it, exti_d1_wwdg_it) 
    .word 0                                        // Clock Recovery Global Interrupt 
    .word 0                                        // ECC diagnostic Global Interrupt 
    .word 0                                        // SAI4 global interrupt
    .word 0                                        // Reserved                                                           
    .word 0                                        // Hold core interrupt        
    .word 0                                        // Interrupt for all 6 wake-up pins 

    .weak      SysTick_Handler
    .thumb_set SysTick_Handler,Default_Handler

.size  g_pfnVectors, .-g_pfnVectors


.section .text.Default_Handler,"ax",%progbits
Default_Handler:
    Infinite_Loop:
        B Infinite_Loop
.size Default_Handler, .-Default_Handler