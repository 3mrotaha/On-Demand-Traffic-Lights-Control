/*
 * LED_config.c
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#include "../../LIB/std_types.h"
#include "../../LIB/ErrorStates.h"

#include "LED_config.h"
#include "LED_priv.h"

#include "../../MCAL/DIO/DIO_int.h"


LED_t SW_AstrLEDs[LED_NUM] = {	
	
	{DIO_uint8_PORTB, DIO_uint8_PIN0, LED_SOURCE, LOW},
	{DIO_uint8_PORTB, DIO_uint8_PIN1, LED_SOURCE, LOW},
	{DIO_uint8_PORTB, DIO_uint8_PIN2, LED_SOURCE, LOW},
		
	{DIO_uint8_PORTA, DIO_uint8_PIN0, LED_SOURCE, LOW},
	{DIO_uint8_PORTA, DIO_uint8_PIN1, LED_SOURCE, LOW},
	{DIO_uint8_PORTA, DIO_uint8_PIN2, LED_SOURCE, LOW},
		
};
