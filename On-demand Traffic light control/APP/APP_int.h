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

/*
	this function is used to initialize the application by initializing 
	the used peripherals such as dio, timer, external interrupt and hardware used such as the led
	and these peripherals are used to handle the program through interrupt service routine
*/
ErrorStates_t App_enuStart(void);

/*
	this function is used to handle the process happens after the human press the button to
	pass the street. 
	it makes the program enters the pedestrian mode.
*/
void on_Press(void);

/*
	this function helps the start function to switch between the traffic lights every 5 s, changes the flags
	according to the current state of the traffic lights
*/
void changeTrafficLed(void);

/*
	this function is used to lighten the RED led for the card to stop
*/
static inline void carStop(void);
/*
	this function is used to lighted the RED led for the human to stop until the cars stop
*/ 
static inline void pedestrainStop(void);

/*
	this function is used to lighten the Yellow led for the cars to be ready to go or stop
*/
static inline void carReady(void);

/*
	this function is used to blinks the Yellow led for the human to be ready to go or stop
*/
static inline void pedestrainReady(void);

/*
	this function is used to light the green led for the cars to pass
*/ 
static inline void carsPass(void);
/*
	this function is used to lighten the green led for the human to pass
*/
static inline void pedestrainPass(void);
#endif /* APP_INT_H_ */