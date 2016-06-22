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
	uint8_t arrPins[]={0,PD0,PD2,PD3};
	arrPins[0]=sizeof(arrPins);	
	Button button(&PINA, &DDRA,arrPins);
	
	
    /* Replace with your application code */
	
	
	
	
	
	
	
	
	button.checkStatusButton();
	button.checkStatusButton();
	
	
	
    while (1) 
    {
		
		
    }
}

void smth(volatile uint8_t number,uint8_t *pArr){

		for (uint8_t i=0;i<number;i++)
		{
			portA.SetPortValues(pArr[i]);
			_delay_ms(1000);
		}
	
		
		
}
