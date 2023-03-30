/*
 * button.c
 *
 * Created: 2022-09-14 9:38:33 PM
 *  Author: pc
 */ 
#include "button.h"

void BUTTON_init(uint8_t buttonport, uint8_t buttonpin)
{
	DIO_init(buttonport, buttonpin, IN);
}
void BUTTON_read(uint8_t buttonport, uint8_t buttonpin, uint8_t *value ) 
{
	DIO_read(buttonport, buttonpin, value);
}

/*void BUTTON_pressed(uint8_t buttonport, uint8_t buttonpin) 
{
	DIO_write(buttonport, buttonpin, HIGH);
}
void BUTTON_notpressed(uint8_t buttonport, uint8_t buttonpin) 
{
	DIO_write(buttonport, buttonpin, LOW);
}
void BUTTON_doublepressed(uint8_t buttonport, uint8_t buttonpin) 
{
	DIO_write(buttonport, buttonpin, HIGH);
}
void BUTTON_longpressed(uint8_t buttonport, uint8_t buttonpin) 
{
	DIO_write(buttonport, buttonpin, HIGH);
}
*/