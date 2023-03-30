/*
 * DIO.h
 *
 * Created: 2022-09-13 9:28:33 PM
 *  Author: pc
 */ 


#ifndef DIO_H_
#define DIO_H_
//all internal deiver typedefs
typedef unsigned char uint8_t ;
typedef unsigned short uint16_t; 
typedef unsigned int uint32_t ;
/************************************************************************/
/*                      All driver macros                               */
/************************************************************************/
//PortA registers defines
#define PORTA (*(volatile uint8_t*)(0X3B))
#define DDRA (*(volatile uint8_t*)(0x3A))
#define PINA (*(volatile uint8_t*)(0x39))
//portB registers defines
#define PORTB (*(volatile uint8_t*)(0x38))
#define DDRB (*(volatile uint8_t*)(0x37))
#define PINB (*(volatile uint8_t*)(0x36))
//portC registers defines
#define PORTC (*(volatile uint8_t*)(0x35))
#define DDRC (*(volatile uint8_t*)(0x34))
#define PINC (*(volatile uint8_t*)(0x33))
//portD registers defines
#define PORTD (*(volatile uint8_t*)(0x32))
#define DDRD (*(volatile uint8_t*)(0x31))
#define PIND (*(volatile uint8_t*)(0x30))

//****************************
//* Timer0 REGISTERS
//****************************
#define TCNT0 (*(volatile uint8_t*)(0x52))
#define TCCR0 (*(volatile uint8_t*)(0x53))
#define TIFR (*(volatile uint8_t*)(0x58))
#define TIMSK (*(volatile uint8_t*)(0x59))

//****************************
//* Interrupt REGISTERS
//****************************
#define SREG (*(volatile uint8_t*)(0x5F))
#define GICR (*(volatile uint8_t*)(0x5B))
#define MCUCR (*(volatile uint8_t*)(0x55))




//ports defines
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
//directions defines
#define IN 0
#define OUT 1
//values low or high defines
#define LOW 0
#define HIGH 1
//all driver functions prototypes
// DIO functions prototypes
void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);
/*
	Function Name        : DIO_init
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t , uint8_t 
	Function Description : Setting the direction of the pin in a particular register
*/
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value);
/*
	Function Name        : DIO_write
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t , uint8_t
	Function Description : Writing a value to a pin in a particular register
*/
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber);
/*
	Function Name        : DIO_toggle
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t
	Function Description : Toggling a pin in a particular register
*/ 
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value ); // read dio
/*
	Function Name        : DIO_read
	Function Returns     : void
	Function Arguments   : uint8_t
	Function Description : Reading the value of a whole port register
*/



#endif /* DIO_H_ */