/*
 * Blink.c
 *
 * Created: 03.01.2019 19:07:57
 * Author : mo6ni
 */ 

#include <avr/io.h>

#define F_CPU 8000000UL

#include <util/delay.h>

int main(void)
{
	unsigned char mms = 0;
	DDRB = 0x03;
		//    76543210
		DDRD &= ~(1<<DDD0);
	DDRC = 0x00;
	DDRD |= 0b01111110;
    /* Replace with your application code */
	PORTD ^= 0b0101110;
	PORTB ^= 0b0000000;
	while (1) 
    {
		if(!(PIND & (1<<PIND7))){
			     if(!(PIND & (1<<PIND2))) PORTD ^= 0b00000110;
			else if(!(PIND & (1<<PIND3))) PORTD ^= 0b00001100;
			else if(!(PIND & (1<<PIND4))) PORTD ^= 0b00011000;
			else if(!(PIND & (1<<PIND5))) PORTD ^= 0b00110000;
		//	else if(!(PIND & (1<<PIND6))) PORTD ^= 0b01100000;
			_delay_ms(300);
		}else if(!(PIND & (1<<PIND0))){
				 if(!(PIND &(1<<PIND1))) PORTD ^=  0b00001100;
			else if(!(PIND &(1<<PIND2))) PORTD ^=  0b00001100;
			else if(!(PIND &(1<<PIND3))) PORTD ^=  0b00011000;
			else if(!(PIND &(1<<PIND4))) PORTD ^=  0b00110000;
			//else if(!(PIND &(1<<PIND5))) PORTD ^= 0b001100000;
			_delay_ms(300);
		}
			mms = PORTD;
		if(!(PINC & (1<<PINC0))){
			char a=0;
			for(;a<10;a++){
			PORTB ^= 0x01;
			_delay_ms(mms);
			}
		}
		//PORTB ^= 0b0000010;
	}
}

