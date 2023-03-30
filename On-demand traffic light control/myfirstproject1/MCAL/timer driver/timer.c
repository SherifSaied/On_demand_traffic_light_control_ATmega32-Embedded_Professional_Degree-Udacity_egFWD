/*
 * timer.c
 *
 * Created: 2022-09-23 8:51:29 AM
 *  Author: pc
 */ 
#include "timer.h"
#include <math.h>
void TIMER_init()
{
	TCCR0 = 0x00; //normal mode
	TCNT0 =0x00;
	//sei() ;
	//TIMSK |=(1<<0);
	
}

void TIMER_delay(uint16_t millisecond)
{
	uint16_t Timer_initialvalue;
	volatile uint16_t Noverflow; // as for 5 sec will be about 19500 Noverflow
	volatile uint32_t overflowcounter=0;
	double Tmaxdelay;
	double T_tick;
	//default for Prescaler=1
	//at 1MHz 
	T_tick=256.0/1000.0; //ms // T_tick=Prescaler/Fcpu  
    Tmaxdelay=56.536; //ms // Tmaxdelay=2^8*T_tick =256.0*256.0/1000.0
	
	if(millisecond<Tmaxdelay)
	{
		Timer_initialvalue=(Tmaxdelay-millisecond)/T_tick;
		Noverflow=1;
	}
	else if(millisecond==(int)Tmaxdelay)
	{
		Timer_initialvalue=0;
		Noverflow=1;
	}
	else 
	{
		Noverflow=ceil((double)millisecond/Tmaxdelay);
		Timer_initialvalue=((1<<8)-((double)millisecond/T_tick)/Noverflow);
	}
	TCNT0 = Timer_initialvalue;
	TCCR0 |=(1<<2); //select 256prescaler
	//TIMSK |=(1<<0); //overflow inerrupt enable
	
	while(overflowcounter<Noverflow)
	{
		while((TIFR&(1<<0)>>0) ==0); //busy wait
		TIFR |=(1<<0); //clear flag overflow as data sheet when set to 1
		overflowcounter++; //increment counter
		
	}
	
	
	TCCR0 = 0x00; //stop timer 
	
}
