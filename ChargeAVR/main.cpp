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
#include <stdbool.h>
#include <util/delay.h>




IOPort portA(&PORTA, &PINA, &DDRA);
IOPort portB(&PORTB, &PINB, &DDRB);
IOPort portC(&PORTC, &PINC, &DDRC);

int main(void)
{
	portA.SetPortDirection(0xFF);
	portB.SetPortDirection(0xFF);
	portC.SetPortDirection(0xFF);
	
	Button button(&PIND, &DDRD,3,PD1,PD2,PD3);
	
	
    /* Replace with your application code */
	
	while(1){
		
		//portB.SetPortValues(button.getCurrentStatus());
		//portC.SetPortValues(button.getPreviousStatus());
		if(button.buttonWasPressed()){
			portB.SetPortValues(button.getCurrentStatus());
			portA.SetPortValues(button.getCodePressedButton());
		} else{
			
		}
	}
	
	
	
	
	
	
	
	
	
	
    while (1) 
    {
		
		
    }
}


