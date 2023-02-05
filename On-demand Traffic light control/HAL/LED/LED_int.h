/*
 * LED_int.h
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#ifndef LED_INT_H_
#define LED_INT_H_

/**********************************************************
** Function Name: LED_enuInit                            **
** Return Type: ErrorStates_t                            **
** Arguments: None                                       **
** Functionality: Initializes the LED module.            **
**********************************************************/
ErrorStates_t LED_enuInit(void);

/**********************************************************
** Function Name: LED_enuTurnON                          **
** Return Type: ErrorStates_t                            **
** Arguments: uint8 Copy_uint8LedID                      **
** Functionality:Turns ON the LED specified by the LED ID**
**********************************************************/
ErrorStates_t LED_enuTurnON(uint8 Copy_uint8LedID);

/**********************************************************
** Function Name: LED_enuTurnOFF                         **
** Return Type: ErrorStates_t                            **
** Arguments: uint8 Copy_uint8LedID                      **
** Functionality: Turns OFF the LED specified by         ** 
**			the LED ID.                                      **
**********************************************************/
ErrorStates_t LED_enuTurnOFF(uint8 Copy_uint8LedID);

/**********************************************************
** Function Name: LED_enuToggleState                     **
** Return Type: ErrorStates_t                            **
** Arguments: uint8 Copy_uint8LedID                      **
** Functionality: Toggles the state of the LED specified **
**				  by the LED ID.                               **
**********************************************************/
ErrorStates_t LED_enuToggleState(uint8 Copy_uint8LedID);

#endif /* LED_INT_H_ */
