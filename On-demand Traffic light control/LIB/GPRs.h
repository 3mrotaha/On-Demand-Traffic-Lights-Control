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

#define ADMUX			*((volatile uint8*)0x27)
#define ADCSRA			*((volatile uint8*)0x26)
#define ADC_DATA_REGS	*((volatile sint16*)0x24)
#define ADCL			*((volatile sint16*)0x24)
#define ADCH			*((volatile sint16*)0x25)
#define SFIOR			*((volatile uint8*)0x50)

#define MCUCR			*((volatile uint8*)0x55)
#define MCUCSR			*((volatile uint8*)0x54)
#define GICR			*((volatile uint8*)0x5B)
#define GIFR			*((volatile uint8*)0x5A)

#define TCCR0			*((volatile uint8*) 0x53)
#define TCNT0			*((volatile uint8*) 0x52)
#define OCR0			*((volatile uint8*) 0x5C)

#define TCCR1A			*((volatile uint8*)0x4F)
#define TCCR1B			*((volatile uint8*)0x4E)
#define TCNT1H			*((volatile uint8*)0x4D)
#define TCNT1L			*((volatile uint8*)0x4C)
#define TCNT1			*((volatile uint16*)0x4C)
#define OCR1AH			*((volatile uint8*)0x4B)
#define OCR1AL			*((volatile uint8*)0x4A)
#define OCR1A			*((volatile uint16*)0x4A)
#define OCR1BH			*((volatile uint8*)0x49)
#define OCR1BL			*((volatile uint8*)0x48)
#define OCR1B			*((volatile uint16*)0x48)
#define ICR1H			*((volatile uint8*)0x47)
#define ICR1L			*((volatile uint8*)0x46)
#define ICR1			*((volatile uint16*)0x46)

#define TIFR			*((volatile uint8*)0x58)
#define TIMSK			*((volatile uint8*)0x59)

#define TCCR2			*((volatile uint8*)0x45)
#define TCNT2			*((volatile uint8*)0x44)
#define OCR2			*((volatile uint8*)0x43)
#define ASSR			*((volatile uint8*)0x42)

#define UCSRA			*((volatile uint8*)0x2B)
#define UBRRL			*((volatile uint8*)0x29)
#define UDR				*((volatile uint8*)0x2C)
#define UCSRB			*((volatile uint8*)0x2A)
#define UCSRC			*((volatile uint8*)0x40)
#define UBRRH			*((volatile uint8*)0x40)

#define ADC_INT_VECT				__vector_16

#define EX_INT0_VECT				__vector_1

#define EX_INT1_VECT				__vector_2

#define EX_INT2_VECT				__vector_3

#define TIMER0_OVF_VECT				__vector_11

#define TIMER0_COMP_VECT			__vector_10

#define TIMER1_CAPT_VECT			__vector_6

#define TIMER1_COMPA_VECT			__vector_7

#define TIMER1_COMPB_VECT			__vector_8

#define TIMER1_OVF_VECT				__vector_9

#define TIMER2_OVF_VECT				__vector_5

#define TIMER2_COMP_VECT			__vector_4

#define UART_RXC_VECT				__vector_13

#define UART_UDRE_VECT				__vector_14

#define UART_TXC_VECT				__vector_15

#define ISR(VECTOR_NUM)		void VECTOR_NUM(void) __attribute__((signal, used));\
							void VECTOR_NUM(void)


#endif /* GPRS_H_ */
