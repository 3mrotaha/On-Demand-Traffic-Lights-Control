/*
 * hal_dio_int.h
 *
 * Created: 2/9/2023 12:37:42 AM
 *  Author: amrmo
 */ 


#ifndef HAL_DIO_INT_H_
#define HAL_DIO_INT_H_


#define hal_dio_uint8_PIN0				0
#define hal_dio_uint8_PIN1				1
#define hal_dio_uint8_PIN2				2
#define hal_dio_uint8_PIN3				3
#define hal_dio_uint8_PIN4				4
#define hal_dio_uint8_PIN5				5
#define hal_dio_uint8_PIN6				6
#define hal_dio_uint8_PIN7				7

#define hal_dio_uint8_PORTA				0
#define hal_dio_uint8_PORTB				1
#define hal_dio_uint8_PORTC				2
#define hal_dio_uint8_PORTD				3


#define OUTPUT			1
#define INPUT			0

#define PULL_UP			1
#define FLOAT			0
#define HIGH			1
#define LOW				0

/*********************************************************
** Function Name: hal_dio_enuInit							**
** Return Type: ErrorStates_t							**
** Arguments: None										**
** Functionality: Initializes the Digital Input/Output	**
**			module.										**
*********************************************************/
ErrorStates_t hal_dio_enuInit(void);

/*********************************************************
** Function Name: hal_dio_enuSetPortDir						**
** Return Type: ErrorStates_t							**
** Arguments: uint8 Copy_uint8PortID,					**
**			  uint8 Copy_uint8Value						**
** Functionality: Sets the direction of a specific		**
**				digital I/O port.						**
*********************************************************/
ErrorStates_t hal_dio_enuSetPortDir(uint8 Copy_uint8PortID, uint8 Copy_uint8Value);

/*********************************************************
** Function Name: hal_dio_enuSetPortValue					**
** Return Type: ErrorStates_t							**
** Arguments: uint8 Copy_uint8PortID,					**
**			  uint8 Copy_uint8Value						**
** Functionality: Sets the value of a specific digital	**
**				I/O port.								**
*********************************************************/
ErrorStates_t hal_dio_enuSetPortValue(uint8 Copy_uint8PortID, uint8 Copy_uint8Value);

/*********************************************************
** Function Name: hal_dio_enuTogPortValue					**
** Return Type: ErrorStates_t							**
** Arguments: uint8 Copy_uint8PortID					**
** Functionality: Toggles the value of a specific		**
**				digital I/O port.						**
*********************************************************/
ErrorStates_t hal_dio_enuTogPortValue(uint8 Copy_uint8PortID);

/*********************************************************
** Function Name: hal_dio_enuGetPortValue					**
** Return Type: ErrorStates_t							**
** Arguments: uint8 Copy_uint8PortID,					**
**			  uint8 *Copy_uint8Value					**
** Functionality: Gets the value of a specific			**
**				 digital I/O port.						**
*********************************************************/
ErrorStates_t hal_dio_enuGetPortValue(uint8 Copy_uint8PortID, uint8 *Copy_uint8Value);

/*********************************************************
** Function Name: hal_dio_enuSetPinDir						**
** Return Type: ErrorStates_t							**
** Arguments: uint8 Copy_uint8PortID,					**
**			  uint8 Copy_uint8PinID,					**
**			  uint8 Copy_uint8Value						**
** Functionality: Sets the direction of a specific		**
**				digital I/O pin.						**
*********************************************************/
ErrorStates_t hal_dio_enuSetPinDir(uint8 Copy_uint8PortID, uint8 Copy_uint8PinID, uint8 Copy_uint8Value);

/*********************************************************
** Function Name: hal_dio_enuSetPinValue					**
** Return Type: ErrorStates_t							**
** Arguments: uint8 Copy_uint8PortID,					**
**			  uint8 Copy_uint8PinID,					**
**			  uint8 Copy_uint8Value						**
** Functionality: Sets the value of a specific			**
**				digital I/O pin.						**
*********************************************************/
ErrorStates_t hal_dio_enuSetPinValue(uint8 Copy_uint8PortID, uint8 Copy_uint8PinID, uint8 Copy_uint8Value);

/*********************************************************
** Function Name: hal_dio_enuTogPinValue					**
** Return Type: ErrorStates_t							**
** Arguments: uint8 Copy_uint8PortID,					**
**			  uint8 Copy_uint8PinID						**
** Functionality: Toggles the value of a specific		**
**				digital I/O pin.						**
*********************************************************/
ErrorStates_t hal_dio_enuTogPinValue(uint8 Copy_uint8PortID, uint8 Copy_uint8PinID);

/*********************************************************
** Function Name: hal_dio_enuSetPinValue					**
** Return Type: ErrorStates_t							**
** Arguments: uint8 Copy_uint8PortID,					**
**			  uint8 Copy_uint8PinID,					**
**			  uint8 *Copy_uint8Value					**
** Functionality: Gets the value of a specific			**
**				digital I/O pin.						**
*********************************************************/
ErrorStates_t hal_dio_enuGetPinValue(uint8 Copy_uint8PortID, uint8 Copy_uint8PinID, uint8 *Copy_uint8Value);




#endif /* HAL_DIO_INT_H_ */