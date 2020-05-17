/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE); 
}

//unsigned short x = ADC;
//unsigned short adc_input;
//unsigned char shifter = (char)adc_input;

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	PORTB = 0x00; DDRB = 0xFF;
//	PORTD = 0x00; DDRD = 0xFF;

//unsigned short x = ADC;
unsigned short adc_input;
//unsigned char shift;
//unsigned char shift2;

    /* Insert your solution below */
	ADC_init();
    while (1) {
	adc_input = ADC;
	if (adc_input > 0x5C){
        	PORTB = 0xFF;
	}
	else if (adc_input > (0x57)){
		PORTB = 0x7F;
	}
	else if (adc_input > (0x52)){
                PORTB = 0x3F;
        }
	else if (adc_input > (0x4D)){
                PORTB = 0x1F;
        }
        else if (adc_input > (0x48)){
                PORTB = 0x0F;
        }

        else if (adc_input > (0x43)){
                PORTB = 0x07;
        }

        else if (adc_input > (0x3E)){
                PORTB = 0x03;
        }

        else if (adc_input > (0x39)){
                PORTB = 0x01;
        }
	else {
		PORTB = 0x00;
	}
    }
    return 1;
}
