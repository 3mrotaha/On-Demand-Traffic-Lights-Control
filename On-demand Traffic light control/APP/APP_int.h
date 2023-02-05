/*
 * APP_int.h
 *
 * Created: 2/4/2023 2:59:59 AM
 *  Author: amrmo
 */ 


#ifndef APP_INT_H_
#define APP_INT_H_

#define PEDESTRAIN_RED_LED			0
#define PEDESTRAIN_YELLOW_LED		1
#define PEDESTRAIN_GREEN_LED		2

#define CAR_RED_LED					3
#define CAR_YELLOW_LED				4
#define CAR_GREEN_LED				5

#define TIME_FOR_LED_STATE				5000	//	in melliseconds
#define BLINKING_TIME					250		// in milliseconds
#define	BLINKING_COUNTS(TIME_FOR_LED, BLINK_TIME)	((uint32) ((TIME_FOR_LED/BLINK_TIME) + 1))

/**********************************************************
** Function Name: App_enuStart							 **
** Return Type: ErrorStates_t							 **
** Arguments: None										 **
** Functionality: Initializes the used peripherals such  **
**		as DIO, timer, external interrupt and hardware	 **
**		like LED to handle the program through ISR		 **
**********************************************************/
ErrorStates_t App_enuStart(void);

/**********************************************************
** Function Name: on_Press								 **
** Return Type: void									 **
** Arguments: None										 **
** Functionality: Handles the process after human presses**
**			 the button to pass the street by entering	 **
**			 pedestrian mode.							 **
**********************************************************/
void on_Press(void);

/**********************************************************
** Function Name: changeTrafficLed						 **
** Return Type: void									 **
** Arguments: None										 **
** Functionality: Helps the start function switch between**
** the traffic lights every 5 s and change the flags	 **
** according to the current state of the traffic lights. **	
**********************************************************/
void changeTrafficLed(void);

/**********************************************************
** Function Name: carStop								 **
** Return Type: static inline void						 **
** Arguments: None										 **
** Functionality: Lights the RED LED for the car to stop.**
**********************************************************/
static inline void carStop(void);

/**********************************************************
** Function Name: pedestrainStop						 **
** Return Type: static inline void						 **
** Arguments: None										 **
** Functionality: Lights the RED LED for the pedestrian  **
** to stop until cars stop.								 **
**********************************************************/
static inline void pedestrainStop(void);

/**********************************************************
** Function Name: carReady								 **
** Return Type: static inline void						 **
** Arguments: None										 **
** Functionality: Lights the YELLOW LED for the car to be**
**				  ready to go or stop.					 **
**********************************************************/
static inline void carReady(void);

/**********************************************************
** Function Name: pedestrainReady						 **
** Return Type: static inline void						 **
** Arguments: None										 **
** Functionality: Blinks the YELLOW LED for the			 **
**				  pedestrian to be ready to go or stop.  **
**********************************************************/
static inline void pedestrainReady(void);

/**********************************************************
** Function Name: carsPass								 **
** Return Type: static inline void						 **
** Arguments: None										 **
** Functionality: Lights the GREEN LED for the cars to	 ** 
**			     pass.									 **
**********************************************************/ 
static inline void carsPass(void);

/**********************************************************
** Function Name: pedestrainPass						 **
** Return Type: void									 **
** Arguments: None										 **
** Functionality: Lightens the green led for the		 **
**				  human to pass.						 **
**********************************************************/
static inline void pedestrainPass(void);
#endif /* APP_INT_H_ */