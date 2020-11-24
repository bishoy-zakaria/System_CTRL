#include "MCU.h"
int main()
{
	GPIO_HIGH_Performace();
	MCU_Cfg frequency [MAX_Pripheral_Num] = {
		                                         { ADC, disable  , 10 ,0},
																						 { GPIO , enable   , 10 ,1},
																						 { UART  , disable   , 10 ,1}
																					 };
	Mcu_Init(frequency);
	Mcu_InitClock();
}
