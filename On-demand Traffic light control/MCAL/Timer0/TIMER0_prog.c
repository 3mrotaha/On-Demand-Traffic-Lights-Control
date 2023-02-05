/*
 * TIMER0_prog.c
 *
 *  Created on: Feb 28, 2022
 *      Author: amrmo
 */


#include "../../LIB/std_types.h"
#include "../../LIB/Bit_Level.h"
#include "../../LIB/GPRs.h"

#include "../DIO/DIO_int.h"

#include "TIMER0_config.h"
#include "TIMER0_priv.h"


static uint32 TIMER0_uint32NumOVF;
static uint8 TIMER0_uint32Preload;

static void (*TIMER0_ApfuncCalledFuncs[2])(void*) = {NULL, NULL};
static void* TIMER0_ApvoidParameters[2] = {NULL, NULL};

ErrorStates_t TIMER0_enuInit(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

	TCCR0 &= ~(BIT_MASK3 << TIMER0_CLOCKSELECT_BITS);
	TCCR0 |= (SELECT_CLOCK_SOURCE << TIMER0_CLOCKSELECT_BITS);
	TCCR0 &= ~(BIT_MASK2 << TIMER0_COM_BITS);
	TCCR0 |= (SELECT_COMPARE_OUTPUT_MODE << TIMER0_COM_BITS);
	TIMSK &= ~(BIT_MASK1 << TIMER0_TOIE0_BIT);
	TIMSK &= ~(BIT_MASK1 << TIMER0_OCIE0_BIT);

#if SELECT_WAVE_GENERATION_MODE == TIMER0_OVF_MODE
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM00_BIT);
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM01_BIT);

	Local_enuErrorStates = ES_OK;
#elif SELECT_WAVE_GENERATION_MODE == TIMER0_PHASE_CORRECT_PWM_MODE
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM00_BIT);
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM01_BIT);
	TCCR0 |= (BIT_MASK1 << TIMER0_WGM00_BIT);
	Local_enuErrorStates = ES_OK;
#elif SELECT_WAVE_GENERATION_MODE == TIMER0_CTC_MODE
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM00_BIT);
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM01_BIT);
	TCCR0 |= (BIT_MASK1 << TIMER0_WGM01_BIT);
	Local_enuErrorStates = ES_OK;
#elif SELECT_WAVE_GENERATION_MODE == TIMER0_FAST_PWM_MODE
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM00_BIT);
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM01_BIT);
	TCCR0 |= (BIT_MASK1 << TIMER0_WGM00_BIT);
	TCCR0 |= (BIT_MASK1 << TIMER0_WGM01_BIT);
	Local_enuErrorStates = ES_OK;
#else
#error "Error! you didn't select the wave generation mode"
#endif

	return Local_enuErrorStates;
}

ErrorStates_t TIMER0_enuSetSyncDelay(uint32 Copy_uint32TimeMs){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

	f32_t Local_f32OVFTime = 256 * ((f32_t)PRESCALED_CLOCK_SOURCE / SELECT_TIMER_FREQ);
	f32_t Local_f32NumOVF = Copy_uint32TimeMs/Local_f32OVFTime;
	uint32 Local_uint32NumOvf_int = (uint32)Local_f32NumOVF + 1;

	if((Local_f32NumOVF - (uint32)Local_f32NumOVF) != 0.0){
		f32_t Local_uint8Preload = 256.0 - (256.0 * (Local_f32NumOVF - (uint32)Local_f32NumOVF));
		if((Local_uint8Preload - (uint32)Local_uint8Preload) >= 0.5 && (Local_uint8Preload - (uint32)Local_uint8Preload) < 1){
			TCNT0 = (uint8)Local_uint8Preload + 1;
		}
		else{
			TCNT0 = (uint8)Local_uint8Preload;
		}
	}
	else{
		TIMER0_uint32NumOVF = (uint32)Local_f32NumOVF;
		TCNT0 = 0;
	}

	while(Local_uint32NumOvf_int){
		while(!((TIFR >> TIMER0_TOV0_BIT) & BIT_MASK1));
		TIFR |= (BIT_MASK1 << TIMER0_TOV0_BIT);
		Local_uint32NumOvf_int--;
	}
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t TIMER0_enuSetAsyncDelay(uint32 Copy_uint32TimeMs, void (*Copy_pfuncCallFunc) (void*), void* Copy_pvoidParameter){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

	TIMSK |= (BIT_MASK1 << TIMER0_TOIE0_BIT);
	f32_t Local_f32OVFTime = 256 * ((f32_t)PRESCALED_CLOCK_SOURCE / SELECT_TIMER_FREQ);
	f32_t Local_f32NumOVF = Copy_uint32TimeMs/Local_f32OVFTime;
	uint32 Local_uint32NumOvf_int = (uint32)Local_f32NumOVF + 1;

	if((Local_f32NumOVF - (uint32)Local_f32NumOVF) != 0.0){
		TIMER0_uint32NumOVF = Local_uint32NumOvf_int;
		uint8 Local_uint8Preload = 256.0 - (256.0 * (Local_f32NumOVF - (uint32)Local_f32NumOVF));
		TCNT0 = Local_uint8Preload;
		TIMER0_uint32Preload = Local_uint8Preload;
	}
	else{
		TCNT0 = 0;
		TIMER0_uint32Preload = 0;
		TIMER0_uint32NumOVF = (uint32)Local_f32NumOVF;
	}

	if(Copy_pfuncCallFunc != NULL){
		TIMER0_ApfuncCalledFuncs[TIMER0_INT_OVF] = Copy_pfuncCallFunc;
		TIMER0_ApvoidParameters[TIMER0_INT_OVF] = Copy_pvoidParameter;
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ErrorStates_t TIMER0_enuEnableOVFInterrupt(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	TIMSK |= (BIT_MASK1 << TIMER0_TOIE0_BIT);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t TIMER0_enuDisableOVFInterrupt(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	TIMSK &= ~(BIT_MASK1 << TIMER0_TOIE0_BIT);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t TIMER0_enuSetCompareMatch(uint8 Copy_uint8Counts, uint8 Copy_uint8OCMode){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	Local_enuErrorStates = DIO_enuSetPinDir(DIO_uint8_PORTB, DIO_uint8_PIN3, OUTPUT);
	TCCR0 &= ~(BIT_MASK2 << TIMER0_COM_BITS);
	TCCR0 |= (Copy_uint8OCMode << TIMER0_COM_BITS);
	OCR0 = Copy_uint8Counts;
	TIMSK |= (BIT_MASK1 << TIMER0_OCIE0_BIT);
	return Local_enuErrorStates;
}

ErrorStates_t TIMER0_enuCorrectPhasePWM(uint8 Copy_uint8Counts, uint8 Copy_uint8OCMode){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	Local_enuErrorStates = DIO_enuSetPinDir(DIO_uint8_PORTB, DIO_uint8_PIN3, OUTPUT);
	TCCR0 &= ~(BIT_MASK2 << TIMER0_COM_BITS);
	TCCR0 |= (Copy_uint8OCMode << TIMER0_COM_BITS);
	OCR0 = Copy_uint8Counts;
	TIMSK |= (BIT_MASK1 << TIMER0_OCIE0_BIT);
	return Local_enuErrorStates;
}

ErrorStates_t TIMER0_enuFastPWM(uint8 Copy_uint8Counts, uint8 Copy_uint8OCMode){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	Local_enuErrorStates = DIO_enuSetPinDir(DIO_uint8_PORTB, DIO_uint8_PIN3, OUTPUT);
	TCCR0 &= ~(BIT_MASK2 << TIMER0_COM_BITS);
	TCCR0 |= (Copy_uint8OCMode << TIMER0_COM_BITS);
	OCR0 = Copy_uint8Counts;
	TIMSK |= (BIT_MASK1 << TIMER0_OCIE0_BIT);
	return Local_enuErrorStates;
}

ErrorStates_t TIMER0_enuEnableCOMPInterrupt(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	TIMSK |= (BIT_MASK1 << TIMER0_OCIE0_BIT);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t TIMER0_enuDisableCOMPInterrupt(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	TIMSK &= ~(BIT_MASK1 << TIMER0_OCIE0_BIT);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t TIMER0_enuCTCCallBack(void (*Copy_pfuncCallFunc) (void*), void* Copy_pvoidParameter){

	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_pfuncCallFunc != NULL){
		TIMER0_ApfuncCalledFuncs[TIMER0_INT_COMP] = Copy_pfuncCallFunc;
		TIMER0_ApvoidParameters[TIMER0_INT_COMP] = Copy_pvoidParameter;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}


ErrorStates_t TIMER0_enuFastPWMByDutyCycle(f32_t Copy_uint8DutyCycle, uint8 Copy_uint8OCMode){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

	Local_enuErrorStates = DIO_enuSetPinDir(DIO_uint8_PORTB, DIO_uint8_PIN3, OUTPUT);

	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM00_BIT);
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM01_BIT);
	TCCR0 |= (BIT_MASK1 << TIMER0_WGM00_BIT);
	TCCR0 |= (BIT_MASK1 << TIMER0_WGM01_BIT);

	TCCR0 &= ~(BIT_MASK2 << TIMER0_COM_BITS);
	TCCR0 |= (Copy_uint8OCMode << TIMER0_COM_BITS);

	OCR0 = (uint8)(Copy_uint8DutyCycle * 256.0);

	TIMSK |= (BIT_MASK1 << TIMER0_OCIE0_BIT);
	return Local_enuErrorStates;
}

ErrorStates_t TIMER0_enuPhaseCorrectByDutyCycle(f32_t Copy_uint8DutyCycle, uint8 Copy_uint8OCMode){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

	Local_enuErrorStates = DIO_enuSetPinDir(DIO_uint8_PORTB, DIO_uint8_PIN3, OUTPUT);

	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM00_BIT);
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM01_BIT);
	TCCR0 |= (BIT_MASK1 << TIMER0_WGM00_BIT);

	TCCR0 &= ~(BIT_MASK2 << TIMER0_COM_BITS);
	TCCR0 |= (Copy_uint8OCMode << TIMER0_COM_BITS);

	OCR0 = (uint8)(Copy_uint8DutyCycle * 255.0);

	TIMSK |= (BIT_MASK1 << TIMER0_OCIE0_BIT);
	return Local_enuErrorStates;
}

ISR(TIMER0_OVF_VECT){

	static uint32 counts = 0;
	if(TIMER0_ApfuncCalledFuncs[TIMER0_INT_OVF] != NULL){
		counts++;
		if(counts == TIMER0_uint32NumOVF){
			counts = 0;
			TCNT0 = TIMER0_uint32Preload;
			TIMER0_ApfuncCalledFuncs[TIMER0_INT_OVF](TIMER0_ApvoidParameters[TIMER0_INT_OVF]);
		}
	}
}

ISR(TIMER0_COMP_VECT){
	if(TIMER0_ApfuncCalledFuncs[TIMER0_INT_COMP] != NULL){
		TIMER0_ApfuncCalledFuncs[TIMER0_INT_COMP](TIMER0_ApvoidParameters[TIMER0_INT_COMP]);
	}
}
