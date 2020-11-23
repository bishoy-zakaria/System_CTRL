#include"MCU_Lcfg.h"

const Mcu_ConfigType * MCU_PTR ;               // Global variable for the cofiguration

Mcu_RawResetType Mcu_GetResetRawValue ( void)
{
	uint8 regs_val=0;
	regs_val = (RESC & (0x0001003F)) ;
	return regs_val;
}

void Mcu_PerformReset(void)
{
	SET_BIT(APINT , 2);
}

/* *********************** CLOCK_CFG ***************************

MCU_arr = { { Pripheral , PLL , Frequency , PORT } };*/

void Mcu_Init ( const Mcu_ConfigType * ConfigPtr )
{
	MCU_PTR = ConfigPtr ;
}

Mcu_PllStatusType Mcu_GetPllStatus ( void)
{
	uint8 status =0;
	status=GET_BIT(PLLSTAT,0);
	return status;
}

void Mcu_DistributePllClock ( void)
{
	while(Mcu_GetPllStatus() !=1);
	CLR_BIT(RCC,11);
}

void MCU_Source(void)
{
	uint8 i=0;
	RCC |= (XTAL_16_MHz << 6);                     // initialization for the crystal
  	for (i=0 ; i< MAX_Pripheral_Num ;i++)
	{
		if (((MCU_PTR->freq)/ XTAL_Frequency) <= 16) // use RCC register
		{
			if      (Clock_Source   ==    MainOscillator )
				RCC = RCC | (0x00000000);
			else if (Clock_Source   ==    PrecisionInternalOscillator)
		    RCC = RCC | (0x00000010);
			else if (Clock_Source   ==    HibernationModuleClockSource  )
				RCC = RCC | (0x00000020);
			else if (Clock_Source   ==    Low_FrequencyInternalOscillator)
				RCC = RCC | (0x00000030);
		}
		else
		{
			SET_BIT(RCC2,31);           // use RCC2 to earn more dirivates
      
      if      (Clock_Source   ==    MainOscillator )
				RCC2 = RCC2 | (0x00000000);
			else if (Clock_Source   ==    PrecisionInternalOscillator)
		    RCC2 = RCC2 | (0x00000010);
			else if (Clock_Source   ==    HibernationModuleClockSource  )
				RCC2 = RCC2 | (0x00000020);
			else if (Clock_Source   ==    Low_FrequencyInternalOscillator)
				RCC2 = RCC2 | (0x00000030);
		}
	}
	
}

void Mcu_InitClock ( void )
{
	uint8 i=0;
	uint8 Div = 0;
	uint8 Div_PLL = 0;
	
	MCU_Source(); // initialization for the clock source
	
	for(i =0; i< MAX_Pripheral_Num ;i++)
	{
		/* ***************** Gating ************************* */
		SET_BIT(RCGC(MCU_PTR[i].pripheral) , MCU_PTR[i].Pripheral_PORT);
		/* **************** SET Frequency ******************* */
		
		Div = XTAL_Frequency / MCU_PTR[i].freq;
		Div_PLL = 200 / MCU_PTR[i].freq;
		
		if ( MCU_PTR[i].freq < XTAL_Frequency )
		{
			if (Div < 16)             // Using RCC 
			{
				SET_BIT(RCC,22);       // using division bit
				SET_BIT(RCC,11);       // Disable PLL
				RCC |= ((Div-1) << 23);
			}
			else                     
			{
				SET_BIT(RCC2,31);        // using RCC2
				SET_BIT(RCC2,11);       // Disable PLL
				RCC2 |= ((Div-1) << 23);
			}
		}
		
		else                       // will use PLL to multiplicate the frequency
		{
			if(MCU_PTR[i].PLL == enable)
			{
			 RCC |= ((Div_PLL-1) << 23);
			 Mcu_DistributePllClock();
			}
		}
		
	}
}
void GPIO_HIGH_Performace(void)
{
	GPIOHBCTL |= 0xFF;
}


