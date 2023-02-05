/*
 * TIMER0_int.h
 *
 *  Created on: Feb 28, 2022
 *      Author: amrmo
 */

#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_

#define TIMER0_uint8_NON_PWM_NORMAL						0
#define TIMER0_uint8_NON_PWM_TOGGLE						1
#define TIMER0_uint8_NON_PWM_CLEAR 						2
#define TIMER0_uint8_NON_PWM_SET   						3

#define TIMER0_uint8FAST_PWM_NORMAL						0
#define TIMER0_uint8FAST_PWM_CLEAR 						2
#define TIMER0_uint8FAST_PWM_SET   						3

#define TIMER0_uint8PHASECORRECT_PWM_NORMAL				0
#define TIMER0_uint8PHASECORRECT_PWM_CLEAR 				2
#define TIMER0_uint8PHASECORRECT_PWM_SET   				3

#define TIMER0_uint8INT_OVF								0
#define TIMER0_uint8INT_COMP							1

/*********************************************************
 *********************************************************
 ** Function Name:										**
 ** Return Type:										**
 ** Arguments:											**
 ** Functionality:										**
 ** 													**
 *********************************************************
 *********************************************************/
ErrorStates_t TIMER0_enuInit(void);

ErrorStates_t TIMER0_enuSetSyncDelay(uint32 Copy_uint32TimeMs);

ErrorStates_t TIMER0_enuSetAsyncDelay(uint32 Copy_uint32TimeMs, void (*Copy_pfuncCallFunc) (void*), void* Copy_pvoidParameter);

ErrorStates_t TIMER0_enuEnableOVFInterrupt(void);

ErrorStates_t TIMER0_enuDisableOVFInterrupt(void);

ErrorStates_t TIMER0_enuSetCompareMatch(uint8 Copy_uint8Counts, uint8 Copy_uint8OCMode);

ErrorStates_t TIMER0_enuCorrectPhasePWM(uint8 Copy_uint8Counts, uint8 Copy_uint8OCMode);

ErrorStates_t TIMER0_enuFastPWM(uint8 Copy_uint8Counts, uint8 Copy_uint8OCMode);

ErrorStates_t TIMER0_enuFastPWMByDutyCycle(f32_t Copy_uint8DutyCycle, uint8 Copy_uint8OCMode);

ErrorStates_t TIMER0_enuPhaseCorrectByDutyCycle(f32_t Copy_uint8DutyCycle, uint8 Copy_uint8OCMode);

ErrorStates_t TIMER0_enuEnableCOMPInterrupt(void);

ErrorStates_t TIMER0_enuDisableCOMPInterrupt(void);

ErrorStates_t TIMER0_enuCTCCallBack(void (*Copy_pfuncCallFunc) (void*), void* Copy_pvoidParameter);

#endif /* TIMER0_INT_H_ */
