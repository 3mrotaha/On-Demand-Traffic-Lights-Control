/*
 * DIO_int.h
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "../../LIB/ErrorStates.h"

#define DIO_uint8_PIN0				0
#define DIO_uint8_PIN1				1
#define DIO_uint8_PIN2				2
#define DIO_uint8_PIN3				3
#define DIO_uint8_PIN4				4
#define DIO_uint8_PIN5				5
#define DIO_uint8_PIN6				6
#define DIO_uint8_PIN7				7

#define DIO_uint8_PORTA				0
#define DIO_uint8_PORTB				1
#define DIO_uint8_PORTC				2
#define DIO_uint8_PORTD				3


#define OUTPUT			1
#define INPUT			0

#define PULL_UP			1
#define FLOAT			0
#define HIGH			1
#define LOW				0

/*********************************************************
** Function Name: DIO_enuInit                           **
** Return Type: ErrorStates_t                           **
** Arguments: None                                      **
** Functionality: Initializes the Digital Input/Output  ** 
**      module.                                         **
*********************************************************/
ErrorStates_t DIO_enuInit(void);

/*********************************************************
** Function Name: DIO_enuSetPortDir                     **
** Return Type: ErrorStates_t                           **
** Arguments: uint8 Copy_uint8PortID,                   **
**        uint8 Copy_uint8Value                         **
** Functionality: Sets the direction of a specific      **
**        digital I/O port.                             **
*********************************************************/
ErrorStates_t DIO_enuSetPortDir(uint8 Copy_uint8PortID, uint8 Copy_uint8Value);

/*********************************************************
** Function Name: DIO_enuSetPortValue                   **
** Return Type: ErrorStates_t                           **
** Arguments: uint8 Copy_uint8PortID,                   ** 
**        uint8 Copy_uint8Value                         **
** Functionality: Sets the value of a specific digital  **
**        I/O port.                                     **
*********************************************************/
ErrorStates_t DIO_enuSetPortValue(uint8 Copy_uint8PortID, uint8 Copy_uint8Value);

/*********************************************************
** Function Name: DIO_enuTogPortValue                   **
** Return Type: ErrorStates_t                           **
** Arguments: uint8 Copy_uint8PortID                    **
** Functionality: Toggles the value of a specific       **
**        digital I/O port.                             **
*********************************************************/
ErrorStates_t DIO_enuTogPortValue(uint8 Copy_uint8PortID);

/*********************************************************
** Function Name: DIO_enuGetPortValue                   **
** Return Type: ErrorStates_t                           **
** Arguments: uint8 Copy_uint8PortID,                   **
**        uint8 *Copy_uint8Value                        **
** Functionality: Gets the value of a specific          ** 
**         digital I/O port.                            **
*********************************************************/
ErrorStates_t DIO_enuGetPortValue(uint8 Copy_uint8PortID, uint8 *Copy_uint8Value);

/*********************************************************
** Function Name: DIO_enuSetPinDir                      **
** Return Type: ErrorStates_t                           **
** Arguments: uint8 Copy_uint8PortID,                   **
**        uint8 Copy_uint8PinID,                        **
**        uint8 Copy_uint8Value                         **
** Functionality: Sets the direction of a specific      **
**        digital I/O pin.                              **
*********************************************************/
ErrorStates_t DIO_enuSetPinDir(uint8 Copy_uint8PortID, uint8 Copy_uint8PinID, uint8 Copy_uint8Value);

/*********************************************************
** Function Name: DIO_enuSetPinValue                    **
** Return Type: ErrorStates_t                           **
** Arguments: uint8 Copy_uint8PortID,                   ** 
**        uint8 Copy_uint8PinID,                        ** 
**        uint8 Copy_uint8Value                         **
** Functionality: Sets the value of a specific          **
**        digital I/O pin.                              **
*********************************************************/
ErrorStates_t DIO_enuSetPinValue(uint8 Copy_uint8PortID, uint8 Copy_uint8PinID, uint8 Copy_uint8Value);

/*********************************************************
** Function Name: DIO_enuTogPinValue                    **
** Return Type: ErrorStates_t                           **
** Arguments: uint8 Copy_uint8PortID,                   ** 
**        uint8 Copy_uint8PinID                         **
** Functionality: Toggles the value of a specific       **
**        digital I/O pin.                              **
*********************************************************/
ErrorStates_t DIO_enuTogPinValue(uint8 Copy_uint8PortID, uint8 Copy_uint8PinID);

/*********************************************************
** Function Name: DIO_enuSetPinValue                    **
** Return Type: ErrorStates_t                           **
** Arguments: uint8 Copy_uint8PortID,                   **
**        uint8 Copy_uint8PinID,                        **
**        uint8 *Copy_uint8Value                        **
** Functionality: Gets the value of a specific          **
**        digital I/O pin.                              **
*********************************************************/
ErrorStates_t DIO_enuGetPinValue(uint8 Copy_uint8PortID, uint8 Copy_uint8PinID, uint8 *Copy_uint8Value);


#endif /* DIO_INT_H_ */
