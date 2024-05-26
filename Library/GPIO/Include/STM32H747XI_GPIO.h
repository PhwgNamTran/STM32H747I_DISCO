#ifndef STM32H747XI_GPIO_H
#define STM32H747XI_GPIO_H

/* Refer to RM0399 Reference Manual from http://www.st.com */

/* Base Address of GPIO Ports */
#define GPIO_A_BASE  0x58020000U
#define GPIO_B_BASE  0x58020400U
#define GPIO_C_BASE  0x58020800U
#define GPIO_D_BASE  0x58020C00U
#define GPIO_E_BASE  0x58021000U
#define GPIO_F_BASE  0x58021400U
#define GPIO_G_BASE  0x58021800U
#define GPIO_H_BASE  0x58021C00U
#define GPIO_I_BASE  0x58022000U
#define GPIO_J_BASE  0x58022400U
#define GPIO_K_BASE  0x58022800U

/* GPIO's Registers offset */
#define GPIO_x_MODER_OFFSET         0x00U
#define GPIO_x_OTYPER_OFFSET        0x04U
#define GPIO_x_OSPEEDR_OFFSET       0x08U
#define GPIO_x_PUPDR_OFFSET         0x0CU
#define GPIO_x_IDR_OFFSET           0x10U
#define GPIO_x_ODR_OFFSET           0x14U
#define GPIO_x_BSRR_OFFSET          0x18U 
#define GPIO_x_LCKR_OFFSET          0x1CU
#define GPIO_x_AFRL_OFFSET          0x20U
#define GPIO_x_AFRH_OFFSET          0x24U

/* GPIO Port A */
#define GPIO_A_MODER         (GPIO_A_BASE + GPIO_x_MODER_OFFSET)
#define GPIO_A_OTYPER        (GPIO_A_BASE + GPIO_x_OTYPER_OFFSET)
#define GPIO_A_OSPEEDR       (GPIO_A_BASE + GPIO_x_OSPEEDR_OFFSET)
#define GPIO_A_PUPDR         (GPIO_A_BASE + GPIO_x_PUPDR_OFFSET)
#define GPIO_A_IDR           (GPIO_A_BASE + GPIO_x_IDR_OFFSET)
#define GPIO_A_ODR           (GPIO_A_BASE + GPIO_x_ODR_OFFSET)
#define GPIO_A_BSRR          (GPIO_A_BASE + GPIO_x_BSRR_OFFSET) 
#define GPIO_A_LCKR          (GPIO_A_BASE + GPIO_x_LCKR_OFFSET)
#define GPIO_A_AFRL          (GPIO_A_BASE + GPIO_x_AFRL_OFFSET)
#define GPIO_A_AFRH          (GPIO_A_BASE + GPIO_x_AFRH_OFFSET)

/* GPIO Port B */
#define GPIO_B_MODER         (GPIO_B_BASE + GPIO_x_MODER_OFFSET)
#define GPIO_B_OTYPER        (GPIO_B_BASE + GPIO_x_OTYPER_OFFSET)
#define GPIO_B_OSPEEDR       (GPIO_B_BASE + GPIO_x_OSPEEDR_OFFSET)
#define GPIO_B_PUPDR         (GPIO_B_BASE + GPIO_x_PUPDR_OFFSET)
#define GPIO_B_IDR           (GPIO_B_BASE + GPIO_x_IDR_OFFSET)
#define GPIO_B_ODR           (GPIO_B_BASE + GPIO_x_ODR_OFFSET)
#define GPIO_B_BSRR          (GPIO_B_BASE + GPIO_x_BSRR_OFFSET) 
#define GPIO_B_LCKR          (GPIO_B_BASE + GPIO_x_LCKR_OFFSET)
#define GPIO_B_AFRL          (GPIO_B_BASE + GPIO_x_AFRL_OFFSET)
#define GPIO_B_AFRH          (GPIO_B_BASE + GPIO_x_AFRH_OFFSET)

/* GPIO Port C */
#define GPIO_C_MODER         (GPIO_C_BASE + GPIO_x_MODER_OFFSET)
#define GPIO_C_OTYPER        (GPIO_C_BASE + GPIO_x_OTYPER_OFFSET)
#define GPIO_C_OSPEEDR       (GPIO_C_BASE + GPIO_x_OSPEEDR_OFFSET)
#define GPIO_C_PUPDR         (GPIO_C_BASE + GPIO_x_PUPDR_OFFSET)
#define GPIO_C_IDR           (GPIO_C_BASE + GPIO_x_IDR_OFFSET)
#define GPIO_C_ODR           (GPIO_C_BASE + GPIO_x_ODR_OFFSET)
#define GPIO_C_BSRR          (GPIO_C_BASE + GPIO_x_BSRR_OFFSET) 
#define GPIO_C_LCKR          (GPIO_C_BASE + GPIO_x_LCKR_OFFSET)
#define GPIO_C_AFRL          (GPIO_C_BASE + GPIO_x_AFRL_OFFSET)
#define GPIO_C_AFRH          (GPIO_C_BASE + GPIO_x_AFRH_OFFSET)

/* GPIO Port D */
#define GPIO_D_MODER         (GPIO_D_BASE + GPIO_x_MODER_OFFSET)
#define GPIO_D_OTYPER        (GPIO_D_BASE + GPIO_x_OTYPER_OFFSET)
#define GPIO_D_OSPEEDR       (GPIO_D_BASE + GPIO_x_OSPEEDR_OFFSET)
#define GPIO_D_PUPDR         (GPIO_D_BASE + GPIO_x_PUPDR_OFFSET)
#define GPIO_D_IDR           (GPIO_D_BASE + GPIO_x_IDR_OFFSET)
#define GPIO_D_ODR           (GPIO_D_BASE + GPIO_x_ODR_OFFSET)
#define GPIO_D_BSRR          (GPIO_D_BASE + GPIO_x_BSRR_OFFSET) 
#define GPIO_D_LCKR          (GPIO_D_BASE + GPIO_x_LCKR_OFFSET)
#define GPIO_D_AFRL          (GPIO_D_BASE + GPIO_x_AFRL_OFFSET)
#define GPIO_D_AFRH          (GPIO_D_BASE + GPIO_x_AFRH_OFFSET)

/* GPIO Port E */
#define GPIO_E_MODER         (GPIO_E_BASE + GPIO_x_MODER_OFFSET)
#define GPIO_E_OTYPER        (GPIO_E_BASE + GPIO_x_OTYPER_OFFSET)
#define GPIO_E_OSPEEDR       (GPIO_E_BASE + GPIO_x_OSPEEDR_OFFSET)
#define GPIO_E_PUPDR         (GPIO_E_BASE + GPIO_x_PUPDR_OFFSET)
#define GPIO_E_IDR           (GPIO_E_BASE + GPIO_x_IDR_OFFSET)
#define GPIO_E_ODR           (GPIO_E_BASE + GPIO_x_ODR_OFFSET)
#define GPIO_E_BSRR          (GPIO_E_BASE + GPIO_x_BSRR_OFFSET) 
#define GPIO_E_LCKR          (GPIO_E_BASE + GPIO_x_LCKR_OFFSET)
#define GPIO_E_AFRL          (GPIO_E_BASE + GPIO_x_AFRL_OFFSET)
#define GPIO_E_AFRH          (GPIO_E_BASE + GPIO_x_AFRH_OFFSET)

/* GPIO Port F */
#define GPIO_F_MODER         (GPIO_F_BASE + GPIO_x_MODER_OFFSET)
#define GPIO_F_OTYPER        (GPIO_F_BASE + GPIO_x_OTYPER_OFFSET)
#define GPIO_F_OSPEEDR       (GPIO_F_BASE + GPIO_x_OSPEEDR_OFFSET)
#define GPIO_F_PUPDR         (GPIO_F_BASE + GPIO_x_PUPDR_OFFSET)
#define GPIO_F_IDR           (GPIO_F_BASE + GPIO_x_IDR_OFFSET)
#define GPIO_F_ODR           (GPIO_F_BASE + GPIO_x_ODR_OFFSET)
#define GPIO_F_BSRR          (GPIO_F_BASE + GPIO_x_BSRR_OFFSET) 
#define GPIO_F_LCKR          (GPIO_F_BASE + GPIO_x_LCKR_OFFSET)
#define GPIO_F_AFRL          (GPIO_F_BASE + GPIO_x_AFRL_OFFSET)
#define GPIO_F_AFRH          (GPIO_F_BASE + GPIO_x_AFRH_OFFSET)

/* GPIO Port G */
#define GPIO_G_MODER         (GPIO_G_BASE + GPIO_x_MODER_OFFSET)
#define GPIO_G_OTYPER        (GPIO_G_BASE + GPIO_x_OTYPER_OFFSET)
#define GPIO_G_OSPEEDR       (GPIO_G_BASE + GPIO_x_OSPEEDR_OFFSET)
#define GPIO_G_PUPDR         (GPIO_G_BASE + GPIO_x_PUPDR_OFFSET)
#define GPIO_G_IDR           (GPIO_G_BASE + GPIO_x_IDR_OFFSET)
#define GPIO_G_ODR           (GPIO_G_BASE + GPIO_x_ODR_OFFSET)
#define GPIO_G_BSRR          (GPIO_G_BASE + GPIO_x_BSRR_OFFSET) 
#define GPIO_G_LCKR          (GPIO_G_BASE + GPIO_x_LCKR_OFFSET)
#define GPIO_G_AFRL          (GPIO_G_BASE + GPIO_x_AFRL_OFFSET)
#define GPIO_G_AFRH          (GPIO_G_BASE + GPIO_x_AFRH_OFFSET)

/* GPIO Port H */
#define GPIO_H_MODER         (GPIO_H_BASE + GPIO_x_MODER_OFFSET)
#define GPIO_H_OTYPER        (GPIO_H_BASE + GPIO_x_OTYPER_OFFSET)
#define GPIO_H_OSPEEDR       (GPIO_H_BASE + GPIO_x_OSPEEDR_OFFSET)
#define GPIO_H_PUPDR         (GPIO_H_BASE + GPIO_x_PUPDR_OFFSET)
#define GPIO_H_IDR           (GPIO_H_BASE + GPIO_x_IDR_OFFSET)
#define GPIO_H_ODR           (GPIO_H_BASE + GPIO_x_ODR_OFFSET)
#define GPIO_H_BSRR          (GPIO_H_BASE + GPIO_x_BSRR_OFFSET) 
#define GPIO_H_LCKR          (GPIO_H_BASE + GPIO_x_LCKR_OFFSET)
#define GPIO_H_AFRL          (GPIO_H_BASE + GPIO_x_AFRL_OFFSET)
#define GPIO_H_AFRH          (GPIO_H_BASE + GPIO_x_AFRH_OFFSET)

/* GPIO Port I */
#define GPIO_I_MODER         (GPIO_I_BASE + GPIO_x_MODER_OFFSET)
#define GPIO_I_OTYPER        (GPIO_I_BASE + GPIO_x_OTYPER_OFFSET)
#define GPIO_I_OSPEEDR       (GPIO_I_BASE + GPIO_x_OSPEEDR_OFFSET)
#define GPIO_I_PUPDR         (GPIO_I_BASE + GPIO_x_PUPDR_OFFSET)
#define GPIO_I_IDR           (GPIO_I_BASE + GPIO_x_IDR_OFFSET)
#define GPIO_I_ODR           (GPIO_I_BASE + GPIO_x_ODR_OFFSET)
#define GPIO_I_BSRR          (GPIO_I_BASE + GPIO_x_BSRR_OFFSET) 
#define GPIO_I_LCKR          (GPIO_I_BASE + GPIO_x_LCKR_OFFSET)
#define GPIO_I_AFRL          (GPIO_I_BASE + GPIO_x_AFRL_OFFSET)
#define GPIO_I_AFRH          (GPIO_I_BASE + GPIO_x_AFRH_OFFSET)

/* GPIO Port J */
#define GPIO_J_MODER         (GPIO_J_BASE + GPIO_x_MODER_OFFSET)
#define GPIO_J_OTYPER        (GPIO_J_BASE + GPIO_x_OTYPER_OFFSET)
#define GPIO_J_OSPEEDR       (GPIO_J_BASE + GPIO_x_OSPEEDR_OFFSET)
#define GPIO_J_PUPDR         (GPIO_J_BASE + GPIO_x_PUPDR_OFFSET)
#define GPIO_J_IDR           (GPIO_J_BASE + GPIO_x_IDR_OFFSET)
#define GPIO_J_ODR           (GPIO_J_BASE + GPIO_x_ODR_OFFSET)
#define GPIO_J_BSRR          (GPIO_J_BASE + GPIO_x_BSRR_OFFSET) 
#define GPIO_J_LCKR          (GPIO_J_BASE + GPIO_x_LCKR_OFFSET)
#define GPIO_J_AFRL          (GPIO_J_BASE + GPIO_x_AFRL_OFFSET)
#define GPIO_J_AFRH          (GPIO_J_BASE + GPIO_x_AFRH_OFFSET)

/* GPIO Port K */
#define GPIO_K_MODER         (GPIO_K_BASE + GPIO_x_MODER_OFFSET)
#define GPIO_K_OTYPER        (GPIO_K_BASE + GPIO_x_OTYPER_OFFSET)
#define GPIO_K_OSPEEDR       (GPIO_K_BASE + GPIO_x_OSPEEDR_OFFSET)
#define GPIO_K_PUPDR         (GPIO_K_BASE + GPIO_x_PUPDR_OFFSET)
#define GPIO_K_IDR           (GPIO_K_BASE + GPIO_x_IDR_OFFSET)
#define GPIO_K_ODR           (GPIO_K_BASE + GPIO_x_ODR_OFFSET)
#define GPIO_K_BSRR          (GPIO_K_BASE + GPIO_x_BSRR_OFFSET) 
#define GPIO_K_LCKR          (GPIO_K_BASE + GPIO_x_LCKR_OFFSET)
#define GPIO_K_AFRL          (GPIO_K_BASE + GPIO_x_AFRL_OFFSET)
#define GPIO_K_AFRH          (GPIO_K_BASE + GPIO_x_AFRH_OFFSET)

#endif