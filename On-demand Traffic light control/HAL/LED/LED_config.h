/*
 * LED_config.h
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_


#define LED_NUM		6

#define LED_SINK	8
#define LED_SOURCE	9

typedef struct{
	uint8 SW_uint8PORTID;
	uint8 SW_uint8PinID;
	uint8 SW_uint8Connection;
	uint8 SW_uint8State;
}LED_t;


#endif /* LED_CONFIG_H_ */
