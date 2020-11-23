#ifndef MCU_Regs_H
#define MCU_Regs_H

/************************* NVIC ****************************** */
#define NVIC_EN(x)         (*((volatile uint32*)(0xE000E100+(x*4))))
#define NVIC_DISABLE(x)    (*((volatile uint32*)(0xE000E180+(x*4))))
#define NVIC_PRI(x)        (*((volatile uint32*)(0xE000E400+(x*4))))

/* ************************ SCB ******************************** */
#define Intrrupt_Ctrl      (*((volatile uint32*)(0xE000ED0C )))
	
/* *********************** MCU ******************************* */
#define APINT         (*((volatile uint32*)(0xE000E000+0xD0C)))
#define RESC          (*((volatile uint32*)(0x400FE000+0x05C)))
#define RCC           (*((volatile uint32*)(0x400FE000+0x060)))
#define RCC2          (*((volatile uint32*)(0x400FE000+0x070)))
#define PLLSTAT       (*((volatile uint32*)(0x400FE000+0x168)))
#define RCGC(x)       (*((volatile uint32*)(0x400FE000+0x600+(x*4))))
#define GPIOHBCTL     (*((volatile uint32*)(0x400FE000+0x06C)))

#endif
