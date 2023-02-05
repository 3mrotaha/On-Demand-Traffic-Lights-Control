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

ErrorStates_t EXINT_enuInit(void);

ErrorStates_t EXINT_enuIntEnable(uint8 Copy_uint8IntID, uint8 Copy_uint8TriggerType);

ErrorStates_t EXINT_enuIntDisable(uint8 Copy_uint8IntID);

ErrorStates_t EXINT_enuCallBack(void (*Copy_pvoidfunCall)(void*), void *Copy_pvoidParameter, uint8 Copy_uint8IntID);

#endif /* EXINT_INT_H_ */
