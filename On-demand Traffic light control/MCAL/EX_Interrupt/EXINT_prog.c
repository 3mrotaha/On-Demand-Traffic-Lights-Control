/*
 * EXINT_prog.c
 *
 *  Created on: Feb 24, 2022
 *      Author: amrmo
 */

#include "../../LIB/std_types.h"
#include "../../LIB/ErrorStates.h"
#include "../../LIB/Bit_Level.h"
#include "../../LIB/GPRs.h"

#include "EXINT_priv.h"
#include "EXINT_config.h"

extern EXINT_t EXINT_AstrExINTConfig[EXINT_NUM];

void (*EXINT_pvoidfuncCallBack[EXINT_NUM])(void*) = {NULL, NULL, NULL};
void* EXINT_pvoidParameter[EXINT_NUM] = {NULL, NULL, NULL};

ErrorStates_t EXINT_enuInit(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	uint8 Local_uint8Iterator;
	for(Local_uint8Iterator = 0; Local_uint8Iterator < EXINT_NUM; Local_uint8Iterator++){
		if(EXINT_AstrExINTConfig[Local_uint8Iterator].Local_uint8_INTConfig == EXINT_ENABLED){
			MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC00_BIT);
			MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC01_BIT);
			MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC10_BIT);
			MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC11_BIT);
			MCUCSR &= ~(EXINT_BIT_MASK << EXINT_ISC2_BIT);
			SREG |= (EXINT_BIT_MASK << EXINT_I_BIT);
			switch(EXINT_AstrExINTConfig[Local_uint8Iterator].Local_uint8_INTID){
				case EXINT_INT0:
					GICR |= (EXINT_BIT_MASK << EXINT_INT0_BIT);
					MCUCR |= (EXINT_AstrExINTConfig[Local_uint8Iterator].Local_uint8riggerType << EXINT_ISC00_BIT);
					GIFR |= (EXINT_BIT_MASK << EXINT_INT0_BIT);
					Local_enuErrorStates = ES_OK;
					break;
				case EXINT_INT1:
					GICR |= (EXINT_BIT_MASK << EXINT_INT1_BIT);
					MCUCR |= (EXINT_AstrExINTConfig[Local_uint8Iterator].Local_uint8riggerType << EXINT_ISC10_BIT);
					GIFR |= (EXINT_BIT_MASK << EXINT_INT1_BIT);
					Local_enuErrorStates = ES_OK;
					break;
				case EXINT_INT2:
					GICR |= (EXINT_BIT_MASK << EXINT_INT2_BIT);
					if(EXINT_AstrExINTConfig[Local_uint8Iterator].Local_uint8riggerType == EXINT_FALLING_EDGE){
						MCUCSR |= (EXINT2_FALLING_EDGE << EXINT_ISC2_BIT);
					}
					else if(EXINT_AstrExINTConfig[Local_uint8Iterator].Local_uint8riggerType == EXINT_RISING_EDGE){
						MCUCSR |= (EXINT2_RISING_EDGE << EXINT_ISC2_BIT);
					}
					GIFR |= (EXINT_BIT_MASK << EXINT_INT2_BIT);
					Local_enuErrorStates = ES_OK;
					break;
				default:
					Local_enuErrorStates = ES_EXINT_OUT_OF_RANGE;
					break;
			}
		}
	}
	return Local_enuErrorStates;
}

ErrorStates_t EXINT_enuIntEnable(uint8 Copy_uint8IntID, uint8 Copy_uint8TriggerType){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_uint8IntID < EXINT_NUM){
		SREG |= (EXINT_BIT_MASK << EXINT_I_BIT);
		switch(Copy_uint8IntID){
			case EXINT_INT0:
				MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC00_BIT);
				MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC01_BIT);
				GICR |= (EXINT_BIT_MASK << EXINT_INT0_BIT);
				MCUCR |= (Copy_uint8TriggerType << EXINT_ISC00_BIT);
				GIFR |= (EXINT_BIT_MASK << EXINT_INT0_BIT);
				Local_enuErrorStates = ES_OK;
				break;
			case EXINT_INT1:
				MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC10_BIT);
				MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC11_BIT);
				GICR |= (EXINT_BIT_MASK << EXINT_INT1_BIT);
				MCUCR |= (Copy_uint8TriggerType << EXINT_ISC10_BIT);
				GIFR |= (EXINT_BIT_MASK << EXINT_INT1_BIT);
				Local_enuErrorStates = ES_OK;
				break;
			case EXINT_INT2:
				MCUCSR &= ~(EXINT_BIT_MASK << EXINT_ISC2_BIT);
				GICR |= (EXINT_BIT_MASK << EXINT_INT2_BIT);
				MCUCSR |= (Copy_uint8TriggerType << EXINT_ISC2_BIT);
				GIFR |= (EXINT_BIT_MASK << EXINT_INT2_BIT);
				Local_enuErrorStates = ES_OK;
				break;
		default:
			Local_enuErrorStates = ES_EXINT_OUT_OF_RANGE;
			break;
		}
	}
	else{
		Local_enuErrorStates = ES_EXINT_OUT_OF_RANGE;
	}
	return Local_enuErrorStates;
}

ErrorStates_t EXINT_enuIntDisable(uint8 Copy_uint8IntID){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_uint8IntID < EXINT_NUM){
		switch(Copy_uint8IntID){
		case EXINT_INT0:
			GICR &= ~(EXINT_BIT_MASK << EXINT_INT0_BIT);
			MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC00_BIT);
			MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC01_BIT);
			Local_enuErrorStates = ES_OK;
			break;
		case EXINT_INT1:
			GICR &= ~(EXINT_BIT_MASK << EXINT_INT1_BIT);
			MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC10_BIT);
			MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC11_BIT);
			Local_enuErrorStates = ES_OK;
			break;
		case EXINT_INT2:
			GICR &= ~(EXINT_BIT_MASK << EXINT_INT2_BIT);
			MCUCSR &= ~(EXINT_BIT_MASK << EXINT_ISC2_BIT);
			Local_enuErrorStates = ES_OK;
			break;
		default:
			Local_enuErrorStates = ES_EXINT_OUT_OF_RANGE;
			break;
		}
	}
	else{
		Local_enuErrorStates = ES_EXINT_OUT_OF_RANGE;
	}
	return Local_enuErrorStates;
}

ErrorStates_t EXINT_enuCallBack(void (*Copy_pvoidfunCall)(void*), void *Copy_pvoidParameter, uint8 Copy_uint8IntID){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_pvoidfunCall != NULL){
		switch(Copy_uint8IntID){
			case EXINT_INT0:
				EXINT_pvoidfuncCallBack[EXINT_INT0] = Copy_pvoidfunCall;
				EXINT_pvoidParameter[EXINT_INT0] = Copy_pvoidParameter;
				Local_enuErrorStates = ES_OK;
				break;
			case EXINT_INT1:
				EXINT_pvoidfuncCallBack[EXINT_INT1] = Copy_pvoidfunCall;
				EXINT_pvoidParameter[EXINT_INT1] = Copy_pvoidParameter;
				Local_enuErrorStates = ES_OK;
				break;
			case EXINT_INT2:
				EXINT_pvoidfuncCallBack[EXINT_INT2] = Copy_pvoidfunCall;
				EXINT_pvoidParameter[EXINT_INT2] = Copy_pvoidParameter;
				Local_enuErrorStates = ES_OK;
				break;
			default:
				Local_enuErrorStates = ES_EXINT_OUT_OF_RANGE;
				break;
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ISR(EX_INT0_VECT){
	if(EXINT_pvoidfuncCallBack[EXINT_INT0] != NULL){
		EXINT_pvoidfuncCallBack[EXINT_INT0](EXINT_pvoidParameter[EXINT_INT0]);
	}
}

ISR(EX_INT1_VECT){
	if(EXINT_pvoidfuncCallBack[EXINT_INT1] != NULL){
		EXINT_pvoidfuncCallBack[EXINT_INT1](EXINT_pvoidParameter[EXINT_INT1]);
	}
}

ISR(EX_INT2_VECT){
	if(EXINT_pvoidfuncCallBack[EXINT_INT2] != NULL){
		EXINT_pvoidfuncCallBack[EXINT_INT2](EXINT_pvoidParameter[EXINT_INT2]);
	}
}
