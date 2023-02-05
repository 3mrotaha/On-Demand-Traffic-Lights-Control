/*
 * DIO_config.h
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

/* PINS DIRECTION */

#define DIO_PA_PIN0_DIR		DIO_uint8_OUTPUT
#define DIO_PA_PIN1_DIR		DIO_uint8_OUTPUT
#define DIO_PA_PIN2_DIR	    DIO_uint8_INPUT
#define DIO_PA_PIN3_DIR		DIO_uint8_OUTPUT
#define DIO_PA_PIN4_DIR		DIO_uint8_OUTPUT
#define DIO_PA_PIN5_DIR     DIO_uint8_INPUT
#define DIO_PA_PIN6_DIR     DIO_uint8_INPUT
#define DIO_PA_PIN7_DIR		DIO_uint8_OUTPUT

#define DIO_PB_PIN0_DIR     DIO_uint8_OUTPUT
#define DIO_PB_PIN1_DIR     DIO_uint8_OUTPUT
#define DIO_PB_PIN2_DIR     DIO_uint8_INPUT
#define DIO_PB_PIN3_DIR     DIO_uint8_OUTPUT
#define DIO_PB_PIN4_DIR     DIO_uint8_OUTPUT
#define DIO_PB_PIN5_DIR     DIO_uint8_INPUT
#define DIO_PB_PIN6_DIR     DIO_uint8_INPUT
#define DIO_PB_PIN7_DIR     DIO_uint8_OUTPUT

#define DIO_PC_PIN0_DIR     DIO_uint8_OUTPUT
#define DIO_PC_PIN1_DIR     DIO_uint8_OUTPUT
#define DIO_PC_PIN2_DIR     DIO_uint8_INPUT
#define DIO_PC_PIN3_DIR     DIO_uint8_OUTPUT
#define DIO_PC_PIN4_DIR     DIO_uint8_OUTPUT
#define DIO_PC_PIN5_DIR     DIO_uint8_INPUT
#define DIO_PC_PIN6_DIR     DIO_uint8_INPUT
#define DIO_PC_PIN7_DIR     DIO_uint8_OUTPUT

#define DIO_PD_PIN0_DIR     DIO_uint8_OUTPUT
#define DIO_PD_PIN1_DIR     DIO_uint8_OUTPUT
#define DIO_PD_PIN2_DIR     DIO_uint8_INPUT
#define DIO_PD_PIN3_DIR     DIO_uint8_OUTPUT
#define DIO_PD_PIN4_DIR     DIO_uint8_OUTPUT
#define DIO_PD_PIN5_DIR     DIO_uint8_INPUT
#define DIO_PD_PIN6_DIR     DIO_uint8_INPUT
#define DIO_PD_PIN7_DIR     DIO_uint8_OUTPUT

/* PINS VALUE */
#define DIO_PA_PIN0_VAL
#define DIO_PA_PIN1_VAL     DIO_uint8_PULL_UP
#define DIO_PA_PIN2_VAL     DIO_uint8_LOW
#define DIO_PA_PIN3_VAL     DIO_uint8_LOW
#define DIO_PA_PIN4_VAL     DIO_uint8_HIGH
#define DIO_PA_PIN5_VAL     DIO_uint8_HIGH
#define DIO_PA_PIN6_VAL     DIO_uint8_HIGH
#define DIO_PA_PIN7_VAL     DIO_uint8_HIGH

#define DIO_PB_PIN0_VAL    	DIO_uint8_PULL_UP
#define DIO_PB_PIN1_VAL    	DIO_uint8_LOW
#define DIO_PB_PIN2_VAL    	DIO_uint8_LOW
#define DIO_PB_PIN3_VAL    	DIO_uint8_HIGH
#define DIO_PB_PIN4_VAL    	DIO_uint8_HIGH
#define DIO_PB_PIN5_VAL    	DIO_uint8_HIGH
#define DIO_PB_PIN6_VAL    	DIO_uint8_HIGH
#define DIO_PB_PIN7_VAL    	DIO_uint8_HIGH


#define DIO_PC_PIN0_VAL   	DIO_uint8_PULL_UP
#define DIO_PC_PIN1_VAL  	DIO_uint8_LOW
#define DIO_PC_PIN2_VAL  	DIO_uint8_LOW
#define DIO_PC_PIN3_VAL  	DIO_uint8_HIGH
#define DIO_PC_PIN4_VAL   	DIO_uint8_HIGH
#define DIO_PC_PIN5_VAL   	DIO_uint8_HIGH
#define DIO_PC_PIN6_VAL   	DIO_uint8_HIGH
#define DIO_PC_PIN7_VAL   	DIO_uint8_HIGH


#define DIO_PD_PIN0_VAL		DIO_uint8_PULL_UP
#define DIO_PD_PIN1_VAL		DIO_uint8_LOW
#define DIO_PD_PIN2_VAL		DIO_uint8_LOW
#define DIO_PD_PIN3_VAL		DIO_uint8_HIGH
#define DIO_PD_PIN4_VAL		DIO_uint8_HIGH
#define DIO_PD_PIN5_VAL		DIO_uint8_HIGH
#define DIO_PD_PIN6_VAL		DIO_uint8_HIGH
#define DIO_PD_PIN7_VAL		DIO_uint8_HIGH




#endif /* DIO_CONFIG_H_ */
