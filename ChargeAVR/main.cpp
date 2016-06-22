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

int main(void)
{
	portA.SetPortDirection(0xFF);
	
	
	
	Button button(&PINA, &DDRA,3,PD1,PD2,PD3);
	
	
    /* Replace with your application code */
	
	
	
	
	
	
	
	
	button.checkStatusButton();
	button.checkStatusButton();
	
	
	
    while (1) 
    {
		
		
    }
}


