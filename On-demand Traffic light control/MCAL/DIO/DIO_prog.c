/*
 * DIO_prog.c
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#include "../../LIB/std_types.h"
#include "../../LIB/ErrorStates.h"
#include "../../LIB/Bit_Level.h"
#include "../../LIB/GPRs.h"

#include "DIO_config.h"
#include "DIO_priv.h"



ErrorStates_t DIO_enuInit(void){
	ErrorStates_t Local_enuErrorState = ES_NOK;

	DDRA = CONC(DIO_PA_PIN0_DIR, DIO_PA_PIN1_DIR, DIO_PA_PIN2_DIR, DIO_PA_PIN3_DIR, DIO_PA_PIN4_DIR, DIO_PA_PIN5_DIR, DIO_PA_PIN6_DIR, DIO_PA_PIN7_DIR);
	DDRB = CONC(DIO_PB_PIN0_DIR, DIO_PB_PIN1_DIR, DIO_PB_PIN2_DIR, DIO_PB_PIN3_DIR, DIO_PB_PIN4_DIR, DIO_PB_PIN5_DIR, DIO_PB_PIN6_DIR, DIO_PB_PIN7_DIR);
	DDRC = CONC(DIO_PC_PIN0_DIR, DIO_PC_PIN1_DIR, DIO_PC_PIN2_DIR, DIO_PC_PIN3_DIR, DIO_PC_PIN4_DIR, DIO_PC_PIN5_DIR, DIO_PC_PIN6_DIR, DIO_PC_PIN7_DIR);
	DDRD = CONC(DIO_PD_PIN0_DIR, DIO_PD_PIN1_DIR, DIO_PD_PIN2_DIR, DIO_PD_PIN3_DIR, DIO_PD_PIN4_DIR, DIO_PD_PIN5_DIR, DIO_PD_PIN6_DIR, DIO_PD_PIN7_DIR);

	PORTA = CONC(DIO_PA_PIN0_VAL, DIO_PA_PIN1_VAL, DIO_PA_PIN2_VAL, DIO_PA_PIN3_VAL, DIO_PA_PIN4_VAL, DIO_PA_PIN5_VAL, DIO_PA_PIN6_VAL, DIO_PA_PIN7_VAL);
	PORTB = CONC(DIO_PB_PIN0_VAL, DIO_PB_PIN1_VAL, DIO_PB_PIN2_VAL, DIO_PB_PIN3_VAL, DIO_PB_PIN4_VAL, DIO_PB_PIN5_VAL, DIO_PB_PIN6_VAL, DIO_PB_PIN7_VAL);
	PORTC = CONC(DIO_PC_PIN0_VAL, DIO_PC_PIN1_VAL, DIO_PC_PIN2_VAL, DIO_PC_PIN3_VAL, DIO_PC_PIN4_VAL, DIO_PC_PIN5_VAL, DIO_PC_PIN6_VAL, DIO_PC_PIN7_VAL);
	PORTD = CONC(DIO_PD_PIN0_VAL, DIO_PD_PIN1_VAL, DIO_PD_PIN2_VAL, DIO_PD_PIN3_VAL, DIO_PD_PIN4_VAL, DIO_PD_PIN5_VAL, DIO_PD_PIN6_VAL, DIO_PD_PIN7_VAL);

	return Local_enuErrorState = ES_OK;
}

ErrorStates_t DIO_enuSetPortDir(uint8 Copy_uint8PortID, uint8 Copy_uint8Value){
	ErrorStates_t Local_enuErrorState = ES_NOK;

	if(Copy_uint8PortID <= DIO_PORTD){

		switch(Copy_uint8PortID){
			case DIO_PORTA:
				DDRA =  Copy_uint8Value;
				break;
			case DIO_PORTB:
				DDRB =  Copy_uint8Value;
				break;
			case DIO_PORTC:
				DDRC =  Copy_uint8Value;
				break;
			case DIO_PORTD:
				DDRD =  Copy_uint8Value;
				break;
		}

		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_PORT_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ErrorStates_t DIO_enuSetPortValue(uint8 Copy_uint8PortID, uint8 Copy_uint8Value){
	ErrorStates_t Local_enuErrorState = ES_NOK;

	if(Copy_uint8PortID <= DIO_PORTD){

		switch(Copy_uint8PortID){
			case DIO_PORTA:
				PORTA =  Copy_uint8Value;
				break;
			case DIO_PORTB:
				PORTB =  Copy_uint8Value;
				break;
			case DIO_PORTC:
				PORTC =  Copy_uint8Value;
				break;
			case DIO_PORTD:
				PORTD =  Copy_uint8Value;
				break;
		}

		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_PORT_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ErrorStates_t DIO_enuTogPortValue(uint8 Copy_uint8PortID){
	ErrorStates_t Local_enuErrorState = ES_NOK;

	if(Copy_uint8PortID <= DIO_PORTD){

		switch(Copy_uint8PortID){
			case DIO_PORTA:
				PORTA = ~PORTA ;
				break;
			case DIO_PORTB:
				PORTB =  ~PORTB;
				break;
			case DIO_PORTC:
				PORTC =  ~PORTC;
				break;
			case DIO_PORTD:
				PORTD =  ~PORTD;
				break;
		}

		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_PORT_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ErrorStates_t DIO_enuGetPortValue(uint8 Copy_uint8PortID, uint8 *Copy_uint8Value){
	ErrorStates_t Local_enuErrorState = ES_NOK;

	if(Copy_uint8PortID <= DIO_PORTD){

		switch(Copy_uint8PortID){
			case DIO_PORTA:
				*Copy_uint8Value = PINA;
				break;
			case DIO_PORTB:
				*Copy_uint8Value = PINB;
				break;
			case DIO_PORTC:
				*Copy_uint8Value = PINC;
				break;
			case DIO_PORTD:
				*Copy_uint8Value = PIND;
				break;
		}

		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_PORT_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ErrorStates_t DIO_enuSetPinDir(uint8 Copy_uint8PortID, uint8 Copy_uint8PinID, uint8 Copy_uint8Value){
	ErrorStates_t Local_enuErrorState = ES_NOK;

	if(Copy_uint8PortID <= DIO_PORTD){
		if(Copy_uint8PinID <= DIO_PIN7){
			switch(Copy_uint8PortID){
				case DIO_PORTA:
					DDRA &= ~(BIT_MASK << Copy_uint8PinID);
					DDRA |= (Copy_uint8Value << Copy_uint8PinID);
					break;
				case DIO_PORTB:
					DDRB &= ~(BIT_MASK << Copy_uint8PinID);
					DDRB |= (Copy_uint8Value << Copy_uint8PinID);
					break;
				case DIO_PORTC:
					DDRC &= ~(BIT_MASK << Copy_uint8PinID);
					DDRC |= (Copy_uint8Value << Copy_uint8PinID);
					break;
				case DIO_PORTD:
					DDRD &= ~(BIT_MASK << Copy_uint8PinID);
					DDRD |= (Copy_uint8Value << Copy_uint8PinID);
					break;
			}
			Local_enuErrorState = ES_OK;
		}
		else{
			Local_enuErrorState = ES_PIN_OUT_OF_RANGE;
		}
	}
	else{
		Local_enuErrorState = ES_PORT_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ErrorStates_t DIO_enuSetPinValue(uint8 Copy_uint8PortID, uint8 Copy_uint8PinID, uint8 Copy_uint8Value){
	ErrorStates_t Local_enuErrorState = ES_NOK;

	if(Copy_uint8PortID <= DIO_PORTD){
		if(Copy_uint8PinID <= DIO_PIN7){
			switch(Copy_uint8PortID){
				case DIO_PORTA:
					PORTA &= ~(BIT_MASK << Copy_uint8PinID);
					PORTA |= (Copy_uint8Value << Copy_uint8PinID);
					break;
				case DIO_PORTB:
					PORTB &= ~(BIT_MASK << Copy_uint8PinID);
					PORTB |= (Copy_uint8Value << Copy_uint8PinID);
					break;
				case DIO_PORTC:
					PORTC &= ~(BIT_MASK << Copy_uint8PinID);
					PORTC |= (Copy_uint8Value << Copy_uint8PinID);
					break;
				case DIO_PORTD:
					PORTD &= ~(BIT_MASK << Copy_uint8PinID);
					PORTD |= (Copy_uint8Value << Copy_uint8PinID);
					break;
			}
			Local_enuErrorState = ES_OK;
		}
		else{
			Local_enuErrorState = ES_PIN_OUT_OF_RANGE;
		}
	}
	else{
		Local_enuErrorState = ES_PORT_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ErrorStates_t DIO_enuTogPinValue(uint8 Copy_uint8PortID, uint8 Copy_uint8PinID){
	ErrorStates_t Local_enuErrorState = ES_NOK;

	if(Copy_uint8PortID <= DIO_PORTD){
		if(Copy_uint8PinID <= DIO_PIN7){
			switch(Copy_uint8PortID){
				case DIO_PORTA:
					PORTA ^= (BIT_MASK << Copy_uint8PinID);
					break;
				case DIO_PORTB:
					PORTB ^= (BIT_MASK << Copy_uint8PinID);
					break;
				case DIO_PORTC:
					PORTC ^= (BIT_MASK << Copy_uint8PinID);
					break;
				case DIO_PORTD:
					PORTD ^= (BIT_MASK << Copy_uint8PinID);
					break;
			}
			Local_enuErrorState = ES_OK;
		}
		else{
			Local_enuErrorState = ES_PIN_OUT_OF_RANGE;
		}
	}
	else{
		Local_enuErrorState = ES_PORT_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ErrorStates_t DIO_enuGetPinValue(uint8 Copy_uint8PortID, uint8 Copy_uint8PinID, uint8 *Copy_uint8Value){
	ErrorStates_t Local_enuErrorState = ES_NOK;

	if(Copy_uint8PortID <= DIO_PORTD){
			if(Copy_uint8PinID <= DIO_PIN7){
				if(Copy_uint8Value != NULL){
					switch(Copy_uint8PortID){
						case DIO_PORTA:
							*Copy_uint8Value = BIT_MASK & (PINA >> Copy_uint8PinID);
							break;
						case DIO_PORTB:
							*Copy_uint8Value = BIT_MASK & (PINB >> Copy_uint8PinID);
							break;
						case DIO_PORTC:
							*Copy_uint8Value = BIT_MASK & (PINC >> Copy_uint8PinID);
							break;
						case DIO_PORTD:
							*Copy_uint8Value = BIT_MASK & (PIND >> Copy_uint8PinID);
							break;
					}
					Local_enuErrorState = ES_OK;
				}
				else{
					Local_enuErrorState = ES_NULL_POINTER;
				}
			}
			else{
				Local_enuErrorState = ES_PIN_OUT_OF_RANGE;
			}
		}
		else{
			Local_enuErrorState = ES_PORT_OUT_OF_RANGE;
		}


	return Local_enuErrorState;
}





