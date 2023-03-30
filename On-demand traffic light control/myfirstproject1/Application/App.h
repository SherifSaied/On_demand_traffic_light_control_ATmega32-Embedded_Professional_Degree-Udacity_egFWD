/*
 * App.h
 *
 * Created: 2022-09-14 1:53:28 PM
 *  Author: pc
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAL/LED driver/led.h"
#include "../ECUAL/Pedestrian Button driver/button.h"
#include "../utilities/interrupts.h"
#include "../MCAL/timer driver/timer.h"

//led car defines
#define LED_carport PORT_A
#define LED_car_Gpin PIN0
#define LED_car_Ypin PIN1
#define LED_car_Rpin PIN2
//led pedes. defines
#define LED_pedestrianport PORT_B
#define LED_ped_Gpin PIN0
#define LED_ped_Ypin PIN1
#define LED_ped_Rpin PIN2
//button defines
#define BUTTON_port PORT_D
#define BUTTON_pin PIN2

//PINS
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


void APP_init();
/*
	Function Name        : APP_init
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initializing And Configuring All The Drivers , Timers And Interrupts.
*/
void APP_start();
/*
	Function Name        : APP_start
	Function Returns     : void
	Function Arguments   : void
	Function Description : Start The Scenario Of The Program Flow.
*/




#endif /* APP_H_ */