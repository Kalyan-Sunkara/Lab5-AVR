/*	Author: ksunk001
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
enum Counter_States {Counter_SMStart, Counter_start} Counter_State;
void SMTick(){
	switch(Counter_State){
		case Counter_SMStart:
			Counter_State = Counter_start;
			break;
		case Counter_start:
			Counter_State =  Counter_wait;
			break;
		default:
			Counter_State = Counter_SMStart;
			break;
	}
	switch(Counter_State) {   // State actions
 		case Counter_SMStart:
			break;
		case Counter_start:
			PORTC = 0x07;
		default:
			break;
		}


}
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	PORTA = 0xFF;

	DDRC = 0xFF;
	PORTC = 0x00;
    /* Insert your solution below */
//	LED_State = LED_SMStart;
	//Counter_State = Counter_start;
    while (1) {
	SMTick();
    }
    return 1;
}
