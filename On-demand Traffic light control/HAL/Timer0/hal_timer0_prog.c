/*
 * hal_timer0_prog.c
 *
 * Created: 2/9/2023 12:40:42 AM
 *  Author: amrmo
 */ 

#include "../../LIB/std_types.h"
#include "../../LIB/ErrorStates.h"
#include "../../MCAL/Timer0/TIMER0_int.h"


ErrorStates_t hal_timer0_enuInit(void){
	return TIMER0_enuInit();
}


ErrorStates_t hal_timer0_enuSetSyncDelay(uint32 Copy_uint32TimeMs){
	return TIMER0_enuSetSyncDelay(Copy_uint32TimeMs);
}


ErrorStates_t hal_timer0_enuSetAsyncDelay(uint32 Copy_uint32TimeMs, void (*Copy_pfuncCallFunc) (void*), void* Copy_pvoidParameter){
	return TIMER0_enuSetAsyncDelay(Copy_uint32TimeMs, Copy_pfuncCallFunc, Copy_pvoidParameter);
}


ErrorStates_t hal_timer0_enuEnableOVFInterrupt(void){
	return TIMER0_enuEnableOVFInterrupt();
}


ErrorStates_t hal_timer0_enuDisableOVFInterrupt(void){
	return TIMER0_enuDisableOVFInterrupt();
}


ErrorStates_t hal_timer0_enuSetCompareMatch(uint8 Copy_uint8Counts, uint8 Copy_uint8OCMode){
	return TIMER0_enuSetCompareMatch(Copy_uint8Counts, Copy_uint8OCMode);
}


ErrorStates_t hal_timer0_enuCorrectPhasePWM(uint8 Copy_uint8Counts, uint8 Copy_uint8OCMode){
	return TIMER0_enuCorrectPhasePWM(Copy_uint8Counts, Copy_uint8OCMode);
}


ErrorStates_t hal_timer0_enuFastPWM(uint8 Copy_uint8Counts, uint8 Copy_uint8OCMode){
	return TIMER0_enuFastPWM(Copy_uint8Counts, Copy_uint8OCMode);
}


ErrorStates_t hal_timer0_enuFastPWMByDutyCycle(f32_t Copy_uint8DutyCycle, uint8 Copy_uint8OCMode){
	return TIMER0_enuFastPWMByDutyCycle(Copy_uint8DutyCycle, Copy_uint8OCMode);
}


ErrorStates_t hal_timer0_enuPhaseCorrectByDutyCycle(f32_t Copy_uint8DutyCycle, uint8 Copy_uint8OCMode){
	return TIMER0_enuPhaseCorrectByDutyCycle(Copy_uint8DutyCycle, Copy_uint8OCMode);
}


ErrorStates_t hal_timer0_enuEnableCOMPInterrupt(void){
	return TIMER0_enuDisableCOMPInterrupt();
}


ErrorStates_t hal_timer0_enuDisableCOMPInterrupt(void){
	return TIMER0_enuDisableCOMPInterrupt();
}


ErrorStates_t hal_timer0_enuCTCCallBack(void (*Copy_pfuncCallFunc) (void*), void* Copy_pvoidParameter){
	return TIMER0_enuCTCCallBack(Copy_pfuncCallFunc, Copy_pvoidParameter);
}