/*
 * ChargeAVR.cpp
 *
 * Created: 20.06.2016 18:37:18
 * Author : OlegAvr
 */ 
#define F_CPU 1000000 


#include <avr/io.h>
#include "buttons/buttons.h"
#include "ioport/IOPort.h"
#include "timers/timer.h"
#include <stdbool.h>
#include <util/delay.h>
#include "../../../../../toolchain/avr8/avr8-gnu-toolchain/avr/include/avr/interrupt.h"


#define TIME_1_SEC				4
#define TIMER0_INTERRUPT		244
void TIMER0_Init();

IOPort portA(&PORTA, &PINA, &DDRA);
IOPort portB(&PORTB, &PINB, &DDRB);
IOPort portC(&PORTC, &PINC, &DDRC);

Timer time;
volatile uint8_t time1000ms=TIME_1_SEC;
int main(void){
	
	portA.SetPortDirection(0xFF);
	portB.SetPortDirection(0xFF);
	portC.SetPortDirection(0xFF);
		
	TIMER0_Init();
	
	Button button(&PIND, &DDRD,&time,3,PD1,PD2,PD3);
	
	
    /* Replace with your application code */
	sei();
	while(1){
		
		//portB.SetPortValues(button.getCurrentStatus());
		//portC.SetPortValues(button.getPreviousStatus());
		if(button.buttonWasPressed()){
			
			portA.SetPortValues(button.getCodePressedButton());
		} 
	}
}
/****************************************************************************/
	
void TIMER0_Init(){
	//Коэф деления 1024 это примерно 1 мс при 1 МГц
	TCCR0|=(1<<CS02)|(1<<CS00);
	TCNT0=0;
	TIMSK|=(1<<OCIE0);
	OCR0=TIMER0_INTERRUPT;
}	
/****************************************************************************/
	
ISR(TIMER0_COMP_vect){
	time1000ms--;	
	if(time1000ms==0){
		time1000ms=TIME_1_SEC;
		time.incrTime();
				
	}
}	
	
	
	
	
	
	

