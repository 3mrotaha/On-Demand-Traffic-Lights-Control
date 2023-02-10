/*
 * hal_exint_prog.c
 *
 * Created: 2/9/2023 12:39:12 AM
 *  Author: amrmo
 */ 

#include "../../LIB/std_types.h"
#include "../../LIB/ErrorStates.h"
#include "../../MCAL/EX_Interrupt/EXINT_int.h"


ErrorStates_t hal_exint_enuInit(void){
	return EXINT_enuInit();
}


ErrorStates_t hal_exint_enuIntEnable(uint8 Copy_uint8IntID, uint8 Copy_uint8TriggerType){
	return EXINT_enuIntEnable(Copy_uint8IntID, Copy_uint8TriggerType);
}


ErrorStates_t hal_exint_enuIntDisable(uint8 Copy_uint8IntID){
	return EXINT_enuIntDisable(Copy_uint8IntID);
}


ErrorStates_t hal_exint_enuCallBack(void (*Copy_pvoidfunCall)(void*), void *Copy_pvoidParameter, uint8 Copy_uint8IntID){
	return EXINT_enuCallBack(Copy_pvoidfunCall, Copy_pvoidParameter, Copy_uint8IntID);
}