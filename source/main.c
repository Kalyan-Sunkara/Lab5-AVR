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

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x00;
    /* Insert your solution below */
//	unsigned char total = 0;
	unsigned char tmpA = 0;
    while (1) {
	tmpA = PINA & 0x0F;
	if(tmpA == 0){
		PORTC = 0x40;
	}
	else if(tmpA < 3){
		PORTC = 0x60;
	}
	else if(tmpA < 5){
		PORTC = 0x70;
	}
	else if(tmpA < 7){
                PORTC = 0x38;
        }
	else if(tmpA < 10){
		PORTC = 0x3C;
	}
	else if(tmpA < 13){
		PORTC = 0x3E;
	}
	else{
		PORTC = 0x3F;
	}		
}	
    return 1;
}
