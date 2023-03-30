/*
 * App.c
 *
 * Created: 2022-09-14 1:53:47 PM
 *  Author: sherif
 */ 
#include "App.h"
void APP_init()
{
	//car led initialization
	LED_init(LED_carport, LED_car_Gpin);
	LED_init(LED_carport, LED_car_Ypin);
	LED_init(LED_carport, LED_car_Rpin);
	//pedestrian led initialization
	LED_init(LED_pedestrianport, LED_ped_Gpin);
	LED_init(LED_pedestrianport, LED_ped_Ypin);
	LED_init(LED_pedestrianport, LED_ped_Rpin);
	//button initialization
	BUTTON_init(BUTTON_port, BUTTON_pin);
	//timer initialization
	TIMER_init();
	//enable global interrupt and rising edge detection
	sei();
	RISING_EDGE_SETUP();
	SETUP_INT0();
}

void APP_start(void)
{

	LED_on(LED_carport,LED_car_Gpin);
	LED_off(LED_carport,LED_car_Ypin);
	LED_off(LED_carport,LED_car_Rpin);
	LED_off(LED_pedestrianport,LED_ped_Rpin);
	LED_off(LED_pedestrianport,LED_ped_Gpin);
	LED_off(LED_pedestrianport,LED_ped_Ypin);

	TIMER_delay(400);

	LED_on(LED_carport,LED_car_Ypin);
	LED_off(LED_carport,LED_car_Gpin);


	TIMER_delay(400);
	/*LED_off(LED_carport,LED_car_Ypin);
	TIMER_delay(1000);
	LED_on(LED_carport,LED_car_Ypin);
	TIMER_delay(1000);*/
	LED_off(LED_carport,LED_car_Ypin);

	//TIMER_delay(3000);

	LED_on(LED_carport,LED_car_Rpin);

	TIMER_delay(400);

}

ISR(EXT_INT_0)
{
	if (((LED_carport & (1<<LED_car_Gpin))>>LED_car_Gpin) == HIGH)
	{
		LED_toggle(LED_pedestrianport,LED_ped_Ypin);
		TIMER_delay(3000);
		LED_off(LED_carport,LED_car_Gpin);
		LED_on(LED_carport,LED_car_Rpin);
		LED_on(LED_pedestrianport,LED_ped_Gpin);
		LED_off(LED_pedestrianport,LED_ped_Ypin);
		TIMER_delay(3000);	
		LED_off(LED_carport,LED_car_Rpin);
		LED_off(LED_pedestrianport,LED_ped_Gpin);
		
	}
	else if (((LED_carport & (1<<LED_car_Ypin))>>LED_car_Ypin) == HIGH)
	{
		LED_on(LED_pedestrianport,LED_ped_Ypin);
		LED_on(LED_carport,LED_car_Ypin);
		TIMER_delay(3000);
		LED_on(LED_carport,LED_car_Rpin);
		LED_on(LED_pedestrianport,LED_ped_Gpin);
		LED_off(LED_pedestrianport,LED_ped_Ypin);
		LED_off(LED_carport,LED_car_Ypin);
		TIMER_delay(3000);
		LED_off(LED_carport,LED_car_Rpin);
		LED_off(LED_pedestrianport,LED_ped_Gpin);
		
		
		
	}
	else if (((LED_carport & (1<<LED_car_Rpin))>>LED_car_Rpin) == HIGH)
	{
		LED_on(LED_carport,LED_car_Rpin);
		LED_on(LED_pedestrianport,LED_ped_Gpin);
		TIMER_delay(3000);
		LED_off(LED_carport,LED_car_Rpin);
		LED_off(LED_pedestrianport,LED_ped_Gpin);
		
			
		
	}

}







/*uint8_t carLED=0; //0 green 1 yellow 2 red
uint8_t prevcarLED=1;
uint8_t normalmode = 1; //1 normal 0 pedestrian
uint8_t buttonState=0;

void APP_start()
{
	//variable to be used in for loop
	uint8_t i;
	
	//if normal mode or need transition (i.e. car green led or yellow is on)
	if(normalmode || carLED==0 || carLED==1){
		if(!normalmode){
			carLED=1;
		}
		//Configuring Pedestrian LEDs
		LED_off(LED_pedestrianport,LED_ped_Gpin);
		LED_off(LED_pedestrianport,LED_ped_Ypin);
	
		
		switch(carLED){
			//Case GREEN LED
			case 0:
			LED_on(LED_carport,LED_car_Gpin);
			LED_off(LED_carport,LED_car_Ypin);
			LED_off(LED_carport,LED_car_Rpin);
			
			for(i=0;i<40;i++) //set for to timer to check isr normal mode
			{
				TIMER_delay(80);
				if(!normalmode)break;//check if ISR was called
			}
			carLED=1;
			prevcarLED=0;
			break;
			
			
			//Case YELLOW LED
			case 1:
			//if not normalmode then we need to blink both
			
			if(!normalmode)
			 {
				if(prevcarLED!=2)
				   {
					LED_on(LED_pedestrianport,LED_ped_Rpin);
					//blink both yellow leds
					for(i=0;i<5;i++)
					  {
						LED_on(LED_carport,LED_car_Ypin);
						LED_on(LED_pedestrianport,LED_ped_Ypin);
						TIMER_delay(390);
						LED_off(LED_carport,LED_car_Ypin);
						LED_off(LED_pedestrianport,LED_ped_Ypin);
						TIMER_delay(190);
						LED_on(LED_carport,LED_car_Ypin);
						LED_on(LED_pedestrianport,LED_ped_Ypin);
						TIMER_delay(390);
					  }
				   } 
				prevcarLED=1;//to go to Ped lights logic
				carLED=2;
				LED_on(LED_carport,LED_car_Rpin);
				}
		       else 
				{
				//blink car yellow led
				for(i=0;i<5;i++)
				{
					LED_on(LED_carport,LED_car_Ypin);
					TIMER_delay(380);
					LED_off(LED_carport,LED_car_Ypin);
					TIMER_delay(180);
					LED_on(LED_carport,LED_car_Ypin);
					TIMER_delay(380);
					if(!normalmode)//check if ISR was called
					{
						prevcarLED=1;
						break;
					}
				}
			}
			LED_off(LED_carport,LED_car_Ypin);
			LED_off(LED_pedestrianport,LED_ped_Ypin);
			//Configure variables for correct switching
			if(prevcarLED==0)
			{
				carLED=2;
				prevcarLED=1;
				}else if(prevcarLED==2){
				carLED=0;
				prevcarLED=1;
			}
			break;
			//Case RED LED
			case 2:
			LED_off(LED_carport,LED_car_Gpin);
			LED_off(LED_carport,LED_car_Ypin);
			LED_on(LED_carport,LED_car_Rpin);
			for(i=0;i<50;i++)
			{
				TIMER_delay(68);
				if(!normalmode)break;
			}
			prevcarLED=2;
			carLED=1;
			break;
			default:
			carLED=2;
			prevcarLED=1;
			break;
		}
		
		}
		else
		{
		//Configure PED LEDs
		LED_on(LED_pedestrianport,LED_ped_Gpin);
		LED_off(LED_pedestrianport,LED_ped_Ypin);
		LED_off(LED_pedestrianport,LED_ped_Rpin);
		
		//Configure CAR LEDs
		LED_off(LED_carport,LED_car_Gpin);
		LED_off(LED_carport,LED_car_Ypin);
		LED_on(LED_carport,LED_car_Rpin);
		TIMER_delay(5000);//5 sec delay
		
		//make sure car red light is off
		LED_off(LED_carport,LED_car_Rpin);
		
		//blink both yellow while ped green is on
		for(i=0;i<5;i++){
			LED_on(LED_carport,LED_car_Ypin);
			LED_on(LED_pedestrianport,LED_ped_Ypin);
			TIMER_delay(390);
			LED_off(LED_carport,LED_car_Ypin);
			LED_off(LED_pedestrianport,LED_ped_Ypin);
			TIMER_delay(190);
			LED_on(LED_carport,LED_car_Ypin);
			LED_on(LED_pedestrianport,LED_ped_Ypin);
			TIMER_delay(390);
		}
		//Turn off yellow LEDs
		LED_off(LED_carport,LED_car_Ypin);
		LED_off(LED_pedestrianport,LED_ped_Ypin);
		//turn on PED red LED
		LED_on(LED_pedestrianport,LED_ped_Rpin);
		//reset normalmode
		normalmode=1;
		//Configure carLED variables
		carLED=0;
		prevcarLED=1;
	}
	
	
}
ISR(EXT_INT_0)
{
	normalmode=0 ;
}*/





/*void APP_start(void)
{
//PORTA |= (1<<2) ; // Red car ON
	
	
	
		BUTTON_read(BUTTON_port, BUTTON_pin,&buttonState);
		if (buttonState== pressed)
	{
		LED_on(LED_carport, LED_car_Rpin); //red car led ON
		//PORTB |=(1<<0) ; // Green pedes. ON
		LED_on(LED_pedestrianport, LED_ped_Ypin);
		TIMER_delay(5000) ; // wait 5 sec
		LED_off(LED_pedestrianport, LED_ped_Ypin);
		LED_on(LED_pedestrianport, LED_ped_Gpin);
		TIMER_delay(5000) ;
		PORTA &=~(1<<2) ; // Red car OFF
		PORTA |=(1<<0) ; // Green car ON
		PORTB &=(~(1<<0)) ; // Green pedes. OFF
		PORTB |=(1<<2) ; //Red pedes. ON
		TIMER_delay(5000) ;
		PORTA &=(~(1<<0)) ; // Green car OFF*/
	//}
	
	/*if (buttonState== notpressed) 
		{
			LED_on(LED_carport, LED_car_Rpin); //red car led ON
			TIMER_delay(80) ; // wait 5 sec
			LED_off(LED_carport, LED_car_Rpin);// Red Car OFF
			LED_on(LED_carport, LED_car_Ypin);
			TIMER_delay(80) ;
			LED_off(LED_carport, LED_car_Ypin);
			LED_on(LED_carport, LED_car_Gpin);
			TIMER_delay(80) ;
			LED_off(LED_carport, LED_car_Gpin);
			LED_on(LED_carport, LED_car_Ypin);
			TIMER_delay(50000) ;
			LED_off(LED_carport, LED_car_Ypin);
	
			PORTA |= (1<<1) ; // yellow car ON
		TIMER_delay(5000) ;
			PORTA &= (~(1<<1)) ; // yellow car OFF
			PORTA |= (1<<0) ; //Green car ON
			TIMER_delay(5000) ;
			PORTA &= (1<<0) ;
			
			
		
	   }
		
}*/
	

		
		
    