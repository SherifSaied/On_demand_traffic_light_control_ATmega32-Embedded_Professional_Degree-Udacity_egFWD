/*
 * timer.h
 *
 * Created: 2022-09-23 8:51:16 AM
 *  Author: sherif
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../DIO driver/DIO.h"
//#include "../../utilities/interrupts.h"

void TIMER_init(void); 
/*
	Function Name        : TIMER_init
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initializing the normal mode of Timer 0.
*/

void TIMER_delay(uint16_t millisecond); 
/*
	Function Name        : TIMER_delay
	Function Returns     : void
	Function Arguments   : uint16_t
	Function Description : make a delay of millisecond.
*/



#endif /* TIMER_H_ */