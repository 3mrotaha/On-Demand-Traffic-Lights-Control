/*
 * GPRs.h
 *
 * Created: 1/28/2023 3:34:34 PM
 *  Author: amrmo
 */ 


#ifndef GPRS_H_
#define GPRS_H_
#define F_CPU			(1000000U)
#define SREG			*((volatile uint8*)0x5F)

#define DDRA			*((volatile uint8*) 0x3A)
#define PORTA			*((volatile uint8*) 0x3B)
#define PINA			*((volatile uint8*) 0x39)
#define DDRB			*((volatile uint8*) 0x37)
#define PORTB			*((volatile uint8*) 0x38)
#define PINB			*((volatile uint8*) 0x36)
#define DDRC			*((volatile uint8*) 0x34)
#define PORTC			*((volatile uint8*) 0x35)
#define PINC			*((volatile uint8*) 0x33)
#define DDRD			*((volatile uint8*) 0x31)
#define PORTD			*((volatile uint8*) 0x32)
#define PIND			*((volatile uint8*) 0x30)

#define MCUCR			*((volatile uint8*)0x55)
#define MCUCSR			*((volatile uint8*)0x54)
#define GICR			*((volatile uint8*)0x5B)
#define GIFR			*((volatile uint8*)0x5A)

#define TCCR0			*((volatile uint8*) 0x53)
#define TCNT0			*((volatile uint8*) 0x52)
#define OCR0			*((volatile uint8*) 0x5C)

#define TIFR			*((volatile uint8*)0x58)
#define TIMSK			*((volatile uint8*)0x59)


#define EX_INT0_VECT				__vector_1

#define EX_INT1_VECT				__vector_2

#define EX_INT2_VECT				__vector_3

#define TIMER0_OVF_VECT				__vector_11

#define TIMER0_COMP_VECT			__vector_10


#define ISR(VECTOR_NUM)		void VECTOR_NUM(void) __attribute__((signal, used));\
							void VECTOR_NUM(void)


#endif /* GPRS_H_ */
