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
#define GPIOHBCTL     (*((volatile uint32*)(0x400FE000+0x06C)))
/* ******************* Pripherals Gates ************************* */
#define RCGCWD        (*((volatile uint32*)(0x400FE000+0x600)))
#define RCGCTIMER     (*((volatile uint32*)(0x400FE000+0x604)))
#define RCGCGPIO      (*((volatile uint32*)(0x400FE000+0x608)))
#define RCGCDMA       (*((volatile uint32*)(0x400FE000+0x60C)))
#define RCGCHIB       (*((volatile uint32*)(0x400FE000+0x614)))
#define RCGCUART      (*((volatile uint32*)(0x400FE000+0x618)))
#define RCGCSSI       (*((volatile uint32*)(0x400FE000+0x61C)))
#define RCGCI2C       (*((volatile uint32*)(0x400FE000+0x620)))
#define RCGCUSB       (*((volatile uint32*)(0x400FE000+0x628)))
#define RCGCCAN       (*((volatile uint32*)(0x400FE000+0x634)))
#define RCGCADC       (*((volatile uint32*)(0x400FE000+0x638)))
#define RCGCACMP      (*((volatile uint32*)(0x400FE000+0x63C)))
#define RCGCPWM       (*((volatile uint32*)(0x400FE000+0x640)))
#define RCGCQEI       (*((volatile uint32*)(0x400FE000+0x644)))
#define RCGCEEPROM    (*((volatile uint32*)(0x400FE000+0x658)))
#define RCGCWTIMER    (*((volatile uint32*)(0x400FE000+0x65C)))

#endif
