/*
 * button.h
 *
 * Created: 2022-09-14 9:38:48 PM
 *  Author: pc
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO driver/DIO.h"
#include "../../MCAL/timer driver/timer.h"
//define button state
#define notpressed 0
#define pressed 1

typedef unsigned char uint8_t ;

void BUTTON_init(uint8_t buttonport, uint8_t buttonpin);
/*
	Function Name        : BUTTON_init
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t
	Function Description : Setting a pin in a specific port for the button as an input
*/
void BUTTON_read(uint8_t buttonport, uint8_t buttonpin, uint8_t *value ) ;
/*
	Function Name        : BUTTON_read
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t, uint8_t
	Function Description : Reading the status of the button
*/

/*void BUTTON_pressed(uint8_t buttonport, uint8_t buttonpin) ;
void BUTTON_notpressed(uint8_t buttonport, uint8_t buttonpin) ;
void BUTTON_doublepressed(uint8_t buttonport, uint8_t buttonpin) ;
void BUTTON_longpressed(uint8_t buttonport, uint8_t buttonpin) ;
*/




#endif /* BUTTON_H_ */
