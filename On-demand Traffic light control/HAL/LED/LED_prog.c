/*
 * LED_prog.c
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#include "../../LIB/std_types.h"
#include "../../LIB/ErrorStates.h"

#include "LED_config.h"
#include "LED_priv.h"

#include "../../MCAL/DIO/DIO_int.h"

extern LED_t SW_AstrLEDs[LED_NUM];

ErrorStates_t LED_enuInit(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(SW_AstrLEDs != NULL){
		uint8 Local_uint8Iterator;
		for(Local_uint8Iterator = 0; Local_uint8Iterator < LED_NUM; Local_uint8Iterator++){
			Local_enuErrorStates = DIO_enuSetPinDir(SW_AstrLEDs[Local_uint8Iterator].SW_uint8PORTID, SW_AstrLEDs[Local_uint8Iterator].SW_uint8PinID, OUTPUT);
			Local_enuErrorStates = DIO_enuSetPinValue(SW_AstrLEDs[Local_uint8Iterator].SW_uint8PORTID, SW_AstrLEDs[Local_uint8Iterator].SW_uint8PinID, SW_AstrLEDs[Local_uint8Iterator].SW_uint8State);
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}

	return Local_enuErrorStates;
}

ErrorStates_t LED_enuTurnON(uint8 Copy_uint8LedID){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_uint8LedID < LED_NUM){
		if(SW_AstrLEDs[Copy_uint8LedID].SW_uint8Connection == LED_uint8SINK){
			Local_enuErrorStates = DIO_enuSetPinValue(SW_AstrLEDs[Copy_uint8LedID].SW_uint8PORTID, SW_AstrLEDs[Copy_uint8LedID].SW_uint8PinID, LOW);
		}
		else if(SW_AstrLEDs[Copy_uint8LedID].SW_uint8Connection == LED_uint8SOURCE){
			Local_enuErrorStates = DIO_enuSetPinValue(SW_AstrLEDs[Copy_uint8LedID].SW_uint8PORTID, SW_AstrLEDs[Copy_uint8LedID].SW_uint8PinID, HIGH);
		}
		else{
			Local_enuErrorStates = ES_OUT_OF_RANGE;
		}
	}
	else{
		Local_enuErrorStates = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorStates;
}

ErrorStates_t LED_enuTurnOFF(uint8 Copy_uint8LedID){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

	if(Copy_uint8LedID < LED_NUM){
			if(SW_AstrLEDs[Copy_uint8LedID].SW_uint8Connection == LED_uint8SINK){
				Local_enuErrorStates = DIO_enuSetPinValue(SW_AstrLEDs[Copy_uint8LedID].SW_uint8PORTID, SW_AstrLEDs[Copy_uint8LedID].SW_uint8PinID, HIGH);
			}
			else if(SW_AstrLEDs[Copy_uint8LedID].SW_uint8Connection == LED_uint8SOURCE){
				Local_enuErrorStates = DIO_enuSetPinValue(SW_AstrLEDs[Copy_uint8LedID].SW_uint8PORTID, SW_AstrLEDs[Copy_uint8LedID].SW_uint8PinID, LOW);
			}
			else{
				Local_enuErrorStates = ES_OUT_OF_RANGE;
			}
		}
		else{
			Local_enuErrorStates = ES_OUT_OF_RANGE;
		}

	return Local_enuErrorStates;
}

ErrorStates_t LED_enuToggleState(uint8 Copy_uint8LedID){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

	if(Copy_uint8LedID < LED_NUM){
		DIO_enuTogPinValue(SW_AstrLEDs[Copy_uint8LedID].SW_uint8PORTID, SW_AstrLEDs[Copy_uint8LedID].SW_uint8PinID);
	}
	else{
		Local_enuErrorStates = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorStates;
}