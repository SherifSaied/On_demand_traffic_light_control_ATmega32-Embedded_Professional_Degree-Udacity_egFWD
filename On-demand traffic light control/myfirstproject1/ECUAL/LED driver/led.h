/*
 * led.h
 *
 * Created: 2022-09-14 7:15:40 PM
 *  Author: pc
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO driver/DIO.h"
#include "../../MCAL/timer driver/timer.h"

typedef unsigned char uint8_t ;
void LED_init(uint8_t ledport, uint8_t ledpin);
/*
	Function Name        : LED_init
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t
	Function Description : Setting the pin connected to the led as an output
*/
void LED_on(uint8_t ledport, uint8_t ledpin) ;
/*
	Function Name        : LED_on
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t
	Function Description : Turning the led on
*/
void LED_off(uint8_t ledport, uint8_t ledpin) ;
/*
	Function Name        : LED_off
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t
	Function Description : Turning the led off
*/
void LED_toggle(uint8_t ledport, uint8_t ledpin) ;
/*
	Function Name        : LED_toggle
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t
	Function Description : Toggling the led
*/
//void LED_blink(uint8_t ledport, uint8_t ledpin, 5000) ;






#endif /* LED_H_ */