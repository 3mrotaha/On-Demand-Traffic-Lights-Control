/*
 * hal_exint_int.h
 *
 * Created: 2/9/2023 12:39:40 AM
 *  Author: amrmo
 */ 


#ifndef HAL_EXINT_INT_H_
#define HAL_EXINT_INT_H_

#define hal_exint_uint8_ENABLED				80
#define hal_exint_uint8_DISABLED				82

#define hal_exint_uint8_FALLING_EDGE			2
#define hal_exint_uint8_RISING_EDGE			3
#define hal_exint_uint8_LOW_LEVEL			0
#define hal_exint_uint8_LOGICAL_CHANGE		1

#define hal_exint_uint8_INT0					0
#define hal_exint_uint8_INT1					1
#define hal_exint_uint8_INT2					2

/*********************************************************
** Function Name: hal_exint_enuInit							**
** Return Type: ErrorStates_t							**
** Arguments: None										**
** Functionality: Initializes the External Interrupt	**
**				module.									**
*********************************************************/
ErrorStates_t hal_exint_enuInit(void);

/*********************************************************
** Function Name: hal_exint_enuIntEnable					**
** Return Type: ErrorStates_t							**
** Arguments: uint8 Copy_uint8IntID,					**
**			  uint8 Copy_uint8TriggerType				**
** Functionality: Enables a specific External Interrupt **
**				and sets its trigger type.				**
*********************************************************/
ErrorStates_t hal_exint_enuIntEnable(uint8 Copy_uint8IntID, uint8 Copy_uint8TriggerType);

/*********************************************************
** Function Name: hal_exint_enuIntDisable					**
** Return Type: ErrorStates_t							**
** Arguments: uint8 Copy_uint8IntID						**
** Functionality: Disables a specific External Interrupt**
*********************************************************/
ErrorStates_t hal_exint_enuIntDisable(uint8 Copy_uint8IntID);

/*********************************************************
** Function Name: hal_exint_enuCallBack						**
** Return Type: ErrorStates_t							**
** Arguments: void (Copy_pvoidfunCall)(void),			**
**			  void *Copy_pvoidParameter,				**
**			  uint8 Copy_uint8IntID						**
** Functionality: Registers a callback function to be	**
**		 executed when a specific External Interrupt is **
**		 triggered.										**
*********************************************************/
ErrorStates_t hal_exint_enuCallBack(void (*Copy_pvoidfunCall)(void*), void *Copy_pvoidParameter, uint8 Copy_uint8IntID);



#endif /* HAL_EXINT_INT_H_ */