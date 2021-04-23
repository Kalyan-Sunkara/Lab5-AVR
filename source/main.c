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
enum Festive_States {Festive_SMStart, Festive_stop, Festive_start, Festive_triplet1, Festive_triplet1_wait, Festive_triplet2, Festive_triplet2_wait} Festive_State;
void SMTick(){
	switch(Festive_State){
		case Festive_SMStart:
			Festive_State = Festive_start;
			break;
		case Festive_start:
			if((~PINA & 0x01) == 0x00){
				Festive_State = Festive_start;	
			}
			else if((~PINA & 0x01) == 0x01){
				Festive_State = Festive_triplet1;
			}
			else{}
			break;
		case Festive_triplet1:
			if((~PINA & 0x01) == 0x01){
				Festive_State = Festive_triplet1;
			}
			else if((~PINA & 0x01) == 0x00){
				Festive_State = Festive_triplet1_wait;
			}
			else{
				Festive_State = Festive_start;
			}
			break;
		case Festive_triplet1_wait:
			if((~PINA & 0x01) == 0x01){
				Festive_State = Festive_triplet2;
			}
			else if((~PINA & 0x01) == 0x00){
				Festive_State = Festive_triplet1_wait;
			}
			else{
				Festive_State = Festive_start;
			}
			break;
		case Festive_triplet2:
			if((~PINA & 0x01) == 0x01){
				Festive_State = Festive_triplet2;
			}
			else if((~PINA & 0x01) == 0x00){
				Festive_State = Festive_triplet2_wait;
			}
			else{
				Festive_State = Festive_start;
			}
			break;
		case Festive_triplet2_wait:
			if((~PINA & 0x01) == 0x01){
				Festive_State = Festive_start;
			}
			else if((~PINA & 0x01) == 0x00){
				Festive_State = Festive_triplet2_wait;
			}
			else{
				Festive_State = Festive_start;
			}
			break;
		case Festive_stop:
			break;
		default:
			Festive_State = Festive_SMStart;
			break;
	}
	switch(Festive_State) {   // State actions
 		case Festive_SMStart:
			break;
		case Festive_start:
			PORTB = 0x3F;
			break;
		case Festive_triplet1:
			PORTB = 0x15;
			break;
		case Festive_triplet1_wait:
			break;
		case Festive_triplet2:
			PORTB = 0x2A;
			break;
		case Festive_triplet2_wait:
			break;
		case Festive_stop:
			break;
		default:
			break;
		}


}
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	PORTA = 0xFF;

	DDRB = 0xFF;
	PORTB = 0x00;
	
	DDRC = 0xFF;
	PORTC = 0x00;
    /* Insert your solution below */
//	LED_State = LED_SMStart;
	//Counter_State = Counter_start;
    while (1) {
	SMTick();
	PORTC = Festive_State;
    }
    return 1;
}
