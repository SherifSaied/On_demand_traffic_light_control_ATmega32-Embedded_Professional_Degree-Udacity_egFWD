/*
 *
 * On demand Traffic Lights
 *
 */
 /************************************************************************/
 /* This project is made for controlling the traffic lights              */
 /*				for both cars and pedestrians                            */
 /************************************************************************/
 /*
 *
 *
 * Created: 9/9/2022 2:28:55 PM
 * Author : Sherif
 */ 
#include "Application/App.h"



int main(void)
{
	//intialize
	APP_init();
	
	
	while(1)
	{
		APP_start();
	}
	
    
}


/************************************************************************/
	/*                             Cars LEDs Direction                      */
	/************************************************************************/
	/*DDRA |=(1<<2) ; //Red LED as output
	DDRA |=(1<<1) ; 
	DDRA |=(1<<0) ; 
	*/
	/************************************************************************/
	/*                           pedestrains LEDs Direction                 */
	/************************************************************************/
    /*DDRB |=(1<<2) ; //Red LED as output
    DDRB |=(1<<1) ;
	DDRB |=(1<<0) ;
	*/
	/************************************************************************/
	/*                           push button Direction                      */
	/************************************************************************/
	/*DDRD &=(~(1<<2)) ; //button as input
	//
	PORTA &=~(1<<2) ; // set Red LED for cars OFF
	PORTA &=~(1<<1) ; // set Yellow LED car OFF
	PORTA &=~(1<<0) ;
	PORTB &=~(1<<2) ; //set Red LED for pedestrains OFF
	PORTB &=~(1<<1) ;
	PORTB &=~(1<<0) ;
	*/
