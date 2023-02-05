/*
 * EXINT_int.h
 *
 *  Created on: Feb 24, 2022
 *      Author: amrmo
 */

#ifndef EXINT_INT_H_
#define EXINT_INT_H_

#define EXINTuint8_ENABLED				80
#define EXINTuint8_DISABLED				82

#define EXINTuint8_FALLING_EDGE			2
#define EXINTuint8_RISING_EDGE			3
#define EXINTuint8_LOW_LEVEL			0
#define EXINTuint8_LOGICAL_CHANGE		1

#define EXINTuint8_INT0					0
#define EXINTuint8_INT1					1
#define EXINTuint8_INT2					2

/*********************************************************
** Function Name: EXINT_enuInit                         **
** Return Type: ErrorStates_t                           **
** Arguments: None                                      **
** Functionality: Initializes the External Interrupt    **
**               module.                                **
*********************************************************/
ErrorStates_t EXINT_enuInit(void);

/*********************************************************
** Function Name: EXINT_enuIntEnable                    **
** Return Type: ErrorStates_t                           **
** Arguments: uint8 Copy_uint8IntID,                    ** 
**         uint8 Copy_uint8TriggerType                  **
** Functionality: Enables a specific External Interrupt **
**         and sets its trigger type.                   **
*********************************************************/
ErrorStates_t EXINT_enuIntEnable(uint8 Copy_uint8IntID, uint8 Copy_uint8TriggerType);

/*********************************************************
** Function Name: EXINT_enuIntDisable                   **
** Return Type: ErrorStates_t                           **
** Arguments: uint8 Copy_uint8IntID                     **
** Functionality: Disables a specific External Interrupt**
*********************************************************/
ErrorStates_t EXINT_enuIntDisable(uint8 Copy_uint8IntID);

/*********************************************************
** Function Name: EXINT_enuCallBack                     **
** Return Type: ErrorStates_t                           **
** Arguments: void (Copy_pvoidfunCall)(void),           **
**        void *Copy_pvoidParameter,                    **
**       uint8 Copy_uint8IntID                          **
** Functionality: Registers a callback function to be   **
**    executed when a specific External Interrupt is    **
**    triggered.                                        **
*********************************************************/
ErrorStates_t EXINT_enuCallBack(void (*Copy_pvoidfunCall)(void*), void *Copy_pvoidParameter, uint8 Copy_uint8IntID);

#endif /* EXINT_INT_H_ */
