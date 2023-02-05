/*
 * APP_prog.c
 *
 * Created: 2/4/2023 2:59:39 AM
 *  Author: amrmo
 */ 


#include "../LIB/std_types.h"
#include "../LIB/ErrorStates.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/Timer0/TIMER0_int.h"
#include "../MCAL/EX_Interrupt/EXINT_int.h"
#include "../HAL/LED/LED_int.h"

#include "APP_int.h"

uint8 carY_falg = 0, carR_flag = 0, carG_flag = 1;
uint8 ledOrder = 21;
ErrorStates_t App_enuStart(void){
	ErrorStates_t local_enuErrorStates = ES_NOK;
	TIMER0_enuInit();
	EXINT_enuInit();
	LED_enuInit();
	TIMER0_enuSetAsyncDelay(TIME_FOR_LED_STATE, &changeTrafficLed, NULL);
	EXINT_enuCallBack(&on_Press, NULL, EXINTuint8_INT0);
	// initial state of the traffic lights
	carsPass();
	
	// initial state of pedestrian lights
	pedestrainStop();
	
	return ES_OK;
}


void changeTrafficLed(void){
	if(ledOrder <= 0){
		carR_flag = 1;
		carG_flag = 0;
		carY_falg = 0;
		
		carStop();
		pedestrainPass();
		TIMER0_enuSetAsyncDelay(TIME_FOR_LED_STATE, &changeTrafficLed, NULL);
	}
	else if((ledOrder >= 1 && ledOrder < 20) || (ledOrder > 20 && ledOrder < 41)){
		carY_falg = 1;
		carR_flag = 0;
		carG_flag = 0;
		
		carReady();
		pedestrainReady();
		TIMER0_enuSetAsyncDelay(BLINKING_TIME, &changeTrafficLed, NULL);
	}
	else if(ledOrder >= 20 && ledOrder < 21){
		carG_flag = 1;
		carR_flag = 0;
		carY_falg = 0;
		
		carsPass();
		pedestrainStop();
		TIMER0_enuSetAsyncDelay(TIME_FOR_LED_STATE, &changeTrafficLed, NULL);
	}
	
	ledOrder++;
	
	if(ledOrder >= 41){
		ledOrder = 0;
	}
	
	
}


void on_Press(void){
	if(carR_flag == 1){
		// turn on green for pedestrian for 5 s
		pedestrainPass();
		TIMER0_enuSetSyncDelay(TIME_FOR_LED_STATE);
	}
	else if(carG_flag == 1 || carY_falg == 1){
		// turn on the red and yellow for pedestrian for 5 s, after that turn the cars red and the pedestrian green for 5 s
		pedestrainStop();
		for(uint32 Iterator = 0; Iterator < BLINKING_COUNTS(TIME_FOR_LED_STATE, BLINKING_TIME); Iterator++){
			pedestrainReady();
			carReady();
			TIMER0_enuSetSyncDelay(BLINKING_TIME);
		}
		carStop();
		pedestrainPass();
		TIMER0_enuSetSyncDelay(TIME_FOR_LED_STATE);
	}
	
	
	for(uint32 Iterator = 0; Iterator < BLINKING_COUNTS(TIME_FOR_LED_STATE, BLINKING_TIME); Iterator++){
		pedestrainReady();
		carReady();
		TIMER0_enuSetSyncDelay(BLINKING_TIME);
	}
	carsPass();
	pedestrainStop();
	// reset the flags to the car pass state
	ledOrder = 20, carG_flag = 1, carR_flag = 0, carY_falg = 0;
	TIMER0_enuSetAsyncDelay(TIME_FOR_LED_STATE, &changeTrafficLed, NULL);
}


static inline void carStop(void){
	LED_enuTurnON(CAR_RED_LED);
	LED_enuTurnOFF(CAR_YELLOW_LED);
	LED_enuTurnOFF(CAR_GREEN_LED);
}
/*
	this function is used to lighted the RED led for the human to stop until the cars stop
*/ 
static inline void pedestrainStop(void){
	LED_enuTurnON(PEDESTRAIN_RED_LED);
	LED_enuTurnOFF(PEDESTRAIN_YELLOW_LED);
	LED_enuTurnOFF(PEDESTRAIN_GREEN_LED);
}

/*
	this function is used to lighten the Yellow led for the cars to be ready to go or stop
*/
static inline void carReady(void){
	LED_enuToggleState(CAR_YELLOW_LED);
}

/*
	this function is used to blinks the Yellow led for the human to be ready to go or stop
*/
static inline void pedestrainReady(void){
	LED_enuToggleState(PEDESTRAIN_YELLOW_LED);
}

/*
	this function is used to light the green led for the cars to pass
*/ 
static inline void carsPass(void){
	LED_enuTurnON(CAR_GREEN_LED);
	LED_enuTurnOFF(CAR_YELLOW_LED);
	LED_enuTurnOFF(CAR_RED_LED);
}
/*
	this function is used to lighten the green led for the human to pass
*/
static inline void pedestrainPass(void){
	LED_enuTurnOFF(PEDESTRAIN_RED_LED);
	LED_enuTurnOFF(PEDESTRAIN_YELLOW_LED);
	LED_enuTurnON(PEDESTRAIN_GREEN_LED);
}