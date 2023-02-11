/*
 * On-demand Traffic light control.c
 *
 * Created: 2/4/2023 2:52:41 AM
 * Author : amrmo
 */ 

#include <util/delay.h>
#include "LIB/std_types.h"
#include "LIB/ErrorStates.h"
#include "MCAL/EX_Interrupt/EXINT_int.h"
#include "MCAL/DIO/DIO_int.h"
void togglePin(void){
	DIO_enuTogPinValue(DIO_uint8_PORTA, DIO_uint8_PIN0);
}

int main(void)
{
	// initialize the interrupt driver
	EXINT_enuInit();
	
	// call back a function
	EXINT_enuCallBack(&togglePin, NULL, EXINTuint8_INT0);
	
	// initailize the pin
	DIO_enuSetPinDir(DIO_uint8_PORTA, DIO_uint8_PIN0, OUTPUT);
	DIO_enuSetPinValue(DIO_uint8_PORTA, DIO_uint8_PIN0, HIGH);
	while(1){

	}
}

