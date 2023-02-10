/*
 * hal_timer0_int.h
 *
 * Created: 2/9/2023 12:40:13 AM
 *  Author: amrmo
 */ 


#ifndef HAL_TIMER0_INT_H_
#define HAL_TIMER0_INT_H_


#define hal_timer0_uint8_NON_PWM_NORMAL						0
#define hal_timer0_uint8_NON_PWM_TOGGLE						1
#define hal_timer0_uint8_NON_PWM_CLEAR 						2
#define hal_timer0_uint8_NON_PWM_SET   						3

#define hal_timer0_uint8FAST_PWM_NORMAL						0
#define hal_timer0_uint8FAST_PWM_CLEAR 						2
#define hal_timer0_uint8FAST_PWM_SET   						3

#define hal_timer0_uint8PHASECORRECT_PWM_NORMAL				0
#define hal_timer0_uint8PHASECORRECT_PWM_CLEAR 				2
#define hal_timer0_uint8PHASECORRECT_PWM_SET   				3

#define hal_timer0_uint8INT_OVF								0
#define hal_timer0_uint8INT_COMP							1

/*********************************************************
** Function Name: hal_timer0_enuInit					**
** Return Type: ErrorStates_t							**
** Arguments: None										**
** Functionality: Initializes the timer0 module.		**
*********************************************************/
ErrorStates_t hal_timer0_enuInit(void);

/*********************************************************
** Function Name: hal_timer0_enuSetSyncDelay			**
** Return Type: ErrorStates_t							**
** Arguments: uint32 Copy_uint32TimeMs					**
** Functionality: Sets the time for synchronous delay	**
** in milliseconds.										**
*********************************************************/
ErrorStates_t hal_timer0_enuSetSyncDelay(uint32 Copy_uint32TimeMs);

/*********************************************************
** Function Name: hal_timer0_enuSetAsyncDelay		    **
** Return Type: ErrorStates_t						    **
** Arguments: uint32 Copy_uint32TimeMs,				    **
**			void (Copy_pfuncCallFunc) (void),		    **
**			void* Copy_pvoidParameter				    **
** Functionality: Sets the time for asynchronous delay  **
**				  in milliseconds.					    **
*********************************************************/
ErrorStates_t hal_timer0_enuSetAsyncDelay(uint32 Copy_uint32TimeMs, void (*Copy_pfuncCallFunc) (void*), void* Copy_pvoidParameter);

/*********************************************************
** Function Name: hal_timer0_enuEnableOVFInterrupt		**
** Return Type: ErrorStates_t							**
** Arguments: None										**
** Functionality: Enables the overflow interrupt.		**
*********************************************************/
ErrorStates_t hal_timer0_enuEnableOVFInterrupt(void);

/*********************************************************
** Function Name: hal_timer0_enuDisableOVFInterrupt		**
** Return Type: ErrorStates_t							**
** Arguments: None										**
** Functionality: Disables the overflow interrupt.		**
*********************************************************/
ErrorStates_t hal_timer0_enuDisableOVFInterrupt(void);

/*********************************************************
** Function Name: hal_timer0_enuSetCompareMatch			**
** Return Type: ErrorStates_t							**
** Arguments: uint8 Copy_uint8Counts,					**
**			  uint8 Copy_uint8OCMode					**
** Functionality: Sets the compare match values for		**
**				  the timer.							**
*********************************************************/
ErrorStates_t hal_timer0_enuSetCompareMatch(uint8 Copy_uint8Counts, uint8 Copy_uint8OCMode);

/*********************************************************
** Function Name: hal_timer0_enuCorrectPhasePWM			**
** Return Type: ErrorStates_t							**
** Arguments: uint8 Copy_uint8Counts,					**
**			  uint8 Copy_uint8OCMode					**
** Functionality: Sets the correct phase PWM values for **
**				  the timer.							**
*********************************************************/
ErrorStates_t hal_timer0_enuCorrectPhasePWM(uint8 Copy_uint8Counts, uint8 Copy_uint8OCMode);

/*********************************************************
** Function Name: hal_timer0_enuFastPWM					**
** Return Type: ErrorStates_t							**
** Arguments: uint8 Copy_uint8Counts,					**
**			  uint8 Copy_uint8OCMode					**
** Functionality: Configures the TIMER0 module to		**
**				work in Fast PWM mode and sets the		**
**			 values of the counts and OC mode.			**
*********************************************************/
ErrorStates_t hal_timer0_enuFastPWM(uint8 Copy_uint8Counts, uint8 Copy_uint8OCMode);

/*********************************************************
** Function Name: hal_timer0_enuFastPWMByDutyCycle		**
** Return Type: ErrorStates_t							**
** Arguments: f32_t Copy_uint8DutyCycle,				**
**			  uint8 Copy_uint8OCMode					**
** Functionality: Configures the TIMER0 module to work	**
**		in Fast PWM mode and sets the values of the		**
**		Duty Cycle and OC mode.							**
*********************************************************/
ErrorStates_t hal_timer0_enuFastPWMByDutyCycle(f32_t Copy_uint8DutyCycle, uint8 Copy_uint8OCMode);

/********************************************************
** Function Name: hal_timer0_enuPhaseCorrectByDutyCycle**
** Return Type: ErrorStates_t						   **
** Arguments: f32_t Copy_uint8DutyCycle,			   **
**            uint8 Copy_uint8OCMode				   **
** Functionality: Configures the TIMER0 module to work **
**		in Phase Correct PWM mode and sets the values  **
**		of the Duty Cycle and OC mode.				   **
*********************************************************/
ErrorStates_t hal_timer0_enuPhaseCorrectByDutyCycle(f32_t Copy_uint8DutyCycle, uint8 Copy_uint8OCMode);

/*********************************************************
** Function Name: hal_timer0_enuEnableCOMPInterrupt		**
** Return Type: ErrorStates_t							**
** Arguments: None										**
** Functionality: Enables the compare match interrupt of**
**				 the TIMER0 module.						**
*********************************************************/
ErrorStates_t hal_timer0_enuEnableCOMPInterrupt(void);

/*********************************************************
** Function Name: hal_timer0_enuDisableCOMPInterrupt	**
** Return Type: ErrorStates_t							**
** Arguments: None										**
** Functionality: Disables the compare match interrupt  **
**				 of the TIMER0 module.					**
*********************************************************/
ErrorStates_t hal_timer0_enuDisableCOMPInterrupt(void);

/*********************************************************
** Function Name: hal_timer0_enuCTCCallBack				**
** Return Type: ErrorStates_t							**
** Arguments: void (Copy_pfuncCallFunc) (void),			**
**			  void* Copy_pvoidParameter					**
** Functionality: Registers a callback function to be	**
**		executed when the compare match interrupt of	**
**		the TIMER0 module is triggered.					**
*********************************************************/
ErrorStates_t hal_timer0_enuCTCCallBack(void (*Copy_pfuncCallFunc) (void*), void* Copy_pvoidParameter);



#endif /* HAL_TIMER0_INT_H_ */