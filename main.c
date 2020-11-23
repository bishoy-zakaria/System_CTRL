#include "MCU.h"
int main()
{
	GPIO_HIGH_Performace();
	MCU_Cfg frequency [MAX_Pripheral_Num] = {
		                                         { Timer, disable  , 0.5 ,0},
																						 { GPIO , enable   , 25 ,1},
																						 { UART  , enable   , 20 ,0}
																					 };
	Mcu_Init(frequency);
	Mcu_InitClock();
}
