/*
 * TIMER0_int.h
 *
 *  Created on: Feb 28, 2022
 *      Author: amrmo
 */

#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_

#define TIMER0_uint8_NON_PWM_NORMAL             0
#define TIMER0_uint8_NON_PWM_TOGGLE             1
#define TIMER0_uint8_NON_PWM_CLEAR              2
#define TIMER0_uint8_NON_PWM_SET                3

#define TIMER0_uint8FAST_PWM_NORMAL             0
#define TIMER0_uint8FAST_PWM_CLEAR              2
#define TIMER0_uint8FAST_PWM_SET                3

#define TIMER0_uint8PHASECORRECT_PWM_NORMAL     0
#define TIMER0_uint8PHASECORRECT_PWM_CLEAR      2
#define TIMER0_uint8PHASECORRECT_PWM_SET        3

#define TIMER0_uint8INT_OVF                     0
#define TIMER0_uint8INT_COMP                    1

/********************************************************
** Function Name: TIMER0_enuInit                       **
** Return Type: ErrorStates_t                          **
** Arguments: None                                     **
** Functionality: Initializes the timer0 module.       **
*********************************************************/
ErrorStates_t TIMER0_enuInit(void);

/********************************************************
** Function Name: TIMER0_enuSetSyncDelay               **
** Return Type: ErrorStates_t                          **
** Arguments: uint32 Copy_uint32TimeMs                 **
** Functionality: Sets the time for synchronous delay  **
** in milliseconds.                                    **
*********************************************************/
ErrorStates_t TIMER0_enuSetSyncDelay(uint32 Copy_uint32TimeMs);

/********************************************************
** Function Name: TIMER0_enuSetAsyncDelay              **
** Return Type: ErrorStates_t                          **
** Arguments: uint32 Copy_uint32TimeMs,                **
**      void (Copy_pfuncCallFunc) (void),              **
**      void* Copy_pvoidParameter                      **
** Functionality: Sets the time for asynchronous delay **
**          in milliseconds.                           **
*********************************************************/
ErrorStates_t TIMER0_enuSetAsyncDelay(uint32 Copy_uint32TimeMs, void (*Copy_pfuncCallFunc) (void*), void* Copy_pvoidParameter);

/********************************************************
** Function Name: TIMER0_enuEnableOVFInterrupt          **
** Return Type: ErrorStates_t                           **
** Arguments: None                                      **
** Functionality: Enables the overflow interrupt.       **
*********************************************************/
ErrorStates_t TIMER0_enuEnableOVFInterrupt(void);

/********************************************************
** Function Name: TIMER0_enuDisableOVFInterrupt        **
** Return Type: ErrorStates_t                          **
** Arguments: None                                     **
** Functionality: Disables the overflow interrupt.     **
*********************************************************/
ErrorStates_t TIMER0_enuDisableOVFInterrupt(void);

/********************************************************
** Function Name: TIMER0_enuSetCompareMatch            **
** Return Type: ErrorStates_t                          **
** Arguments: uint8 Copy_uint8Counts,                  **
**        uint8 Copy_uint8OCMode                       **
** Functionality: Sets the compare match values for    **
**          the timer.                                 **
*********************************************************/
ErrorStates_t TIMER0_enuSetCompareMatch(uint8 Copy_uint8Counts, uint8 Copy_uint8OCMode);

/********************************************************
** Function Name: TIMER0_enuCorrectPhasePWM            **
** Return Type: ErrorStates_t                          **
** Arguments: uint8 Copy_uint8Counts,                  **
**        uint8 Copy_uint8OCMode                       **
** Functionality: Sets the correct phase PWM values for**
**          the timer.                                 **
*********************************************************/
ErrorStates_t TIMER0_enuCorrectPhasePWM(uint8 Copy_uint8Counts, uint8 Copy_uint8OCMode);

/********************************************************
** Function Name: TIMER0_enuFastPWM                    **
** Return Type: ErrorStates_t                          **
** Arguments: uint8 Copy_uint8Counts,                  **
**        uint8 Copy_uint8OCMode                       **
** Functionality: Configures the TIMER0 module to      ** 
**        work in Fast PWM mode and sets the           **
**       values of the counts and OC mode.             **
*********************************************************/
ErrorStates_t TIMER0_enuFastPWM(uint8 Copy_uint8Counts, uint8 Copy_uint8OCMode);

/********************************************************
** Function Name: TIMER0_enuFastPWMByDutyCycle         **
** Return Type: ErrorStates_t                          **
** Arguments: f32_t Copy_uint8DutyCycle,               ** 
**        uint8 Copy_uint8OCMode                       **
** Functionality: Configures the TIMER0 module to work **
**    in Fast PWM mode and sets the values of the      ** 
**    Duty Cycle and OC mode.                          **
*********************************************************/
ErrorStates_t TIMER0_enuFastPWMByDutyCycle(f32_t Copy_uint8DutyCycle, uint8 Copy_uint8OCMode);

/*******************************************************
** Function Name: TIMER0_enuPhaseCorrectByDutyCycle   **
** Return Type: ErrorStates_t                         **
** Arguments: f32_t Copy_uint8DutyCycle,              **
**            uint8 Copy_uint8OCMode                  **
** Functionality: Configures the TIMER0 module to work**
**    in Phase Correct PWM mode and sets the values   **
**    of the Duty Cycle and OC mode.                  **
********************************************************/
ErrorStates_t TIMER0_enuPhaseCorrectByDutyCycle(f32_t Copy_uint8DutyCycle, uint8 Copy_uint8OCMode);

/********************************************************
** Function Name: TIMER0_enuEnableCOMPInterrupt        **
** Return Type: ErrorStates_t                          **
** Arguments: None                                     **
** Functionality: Enables the compare match interrupt of**
**         the TIMER0 module.                          **
*********************************************************/
ErrorStates_t TIMER0_enuEnableCOMPInterrupt(void);

/********************************************************
** Function Name: TIMER0_enuDisableCOMPInterrupt       **
** Return Type: ErrorStates_t                          **
** Arguments: None                                     **
** Functionality: Disables the compare match interrupt **
**                of the TIMER0 module.                **
*********************************************************/
ErrorStates_t TIMER0_enuDisableCOMPInterrupt(void);

/********************************************************
** Function Name: TIMER0_enuCTCCallBack                **
** Return Type: ErrorStates_t                          **
** Arguments: void (Copy_pfuncCallFunc) (void),        **
**        void* Copy_pvoidParameter                    **
** Functionality: Registers a callback function to be  ** 
**    executed when the compare match interrupt of     ** 
**    the TIMER0 module is triggered.                  **
*********************************************************/
ErrorStates_t TIMER0_enuCTCCallBack(void (*Copy_pfuncCallFunc) (void*), void* Copy_pvoidParameter);

#endif /* TIMER0_INT_H_ */
