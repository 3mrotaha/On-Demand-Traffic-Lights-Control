/*
 * On-demand Traffic light control.c
 *
 * Created: 2/4/2023 2:52:41 AM
 * Author : amrmo
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "LIB/std_types.h"
#include "LIB/ErrorStates.h"
#include "MCAL/DIO/DIO_int.h"

int main(void)
{
	// set pin direction in PORTA to output
	DIO_enuSetPinDir(DIO_uint8_PORTA, DIO_uint8_PIN0, INPUT);
	
	// get the value on the pin 0 of port A
	uint8 value; // a variable to store the value of the pin
	DIO_enuGetPinValue(DIO_uint8_PORTA, DIO_uint8_PIN0, &value);
	while(1){

	}
}

