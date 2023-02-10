/*
 * hal_dio_prog.c
 *
 * Created: 2/9/2023 12:38:40 AM
 *  Author: amrmo
 */ 

#include "../../LIB/std_types.h"
#include "../../LIB/ErrorStates.h"
#include "../../MCAL/DIO/DIO_int.h"


ErrorStates_t hal_dio_enuInit(void){
	return DIO_enuInit();
}

ErrorStates_t hal_dio_enuSetPortDir(uint8 Copy_uint8PortID, uint8 Copy_uint8Value){
	return DIO_enuSetPortDir(Copy_uint8PortID, Copy_uint8Value);
}

ErrorStates_t hal_dio_enuSetPortValue(uint8 Copy_uint8PortID, uint8 Copy_uint8Value){
	return DIO_enuSetPortValue(Copy_uint8PortID, Copy_uint8Value);
}

ErrorStates_t hal_dio_enuTogPortValue(uint8 Copy_uint8PortID){
	return DIO_enuTogPortValue(Copy_uint8PortID);
}


ErrorStates_t hal_dio_enuGetPortValue(uint8 Copy_uint8PortID, uint8 *Copy_uint8Value){
	return DIO_enuGetPortValue(Copy_uint8PortID, Copy_uint8Value);
}

ErrorStates_t hal_dio_enuSetPinDir(uint8 Copy_uint8PortID, uint8 Copy_uint8PinID, uint8 Copy_uint8Value){
	return DIO_enuSetPinDir(Copy_uint8PortID, Copy_uint8PinID, Copy_uint8Value);
}

ErrorStates_t hal_dio_enuSetPinValue(uint8 Copy_uint8PortID, uint8 Copy_uint8PinID, uint8 Copy_uint8Value){
	return DIO_enuSetPinValue(Copy_uint8PortID, Copy_uint8PinID, Copy_uint8Value);
}

ErrorStates_t hal_dio_enuTogPinValue(uint8 Copy_uint8PortID, uint8 Copy_uint8PinID){
	return DIO_enuTogPinValue(Copy_uint8PortID, Copy_uint8PinID);
}

ErrorStates_t hal_dio_enuGetPinValue(uint8 Copy_uint8PortID, uint8 Copy_uint8PinID, uint8 *Copy_uint8Value){
	return DIO_enuGetPinValue(Copy_uint8PortID, Copy_uint8PinID, Copy_uint8Value);
}