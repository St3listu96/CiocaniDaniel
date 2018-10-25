/*
 * UART.c
 *
 * Created: 10/18/2018 10:41:04 AM
 * Author : dspuser
 */ 

#define F_CPU 14745600UL

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "uart.h"


int main(void)
{
    init();
	//initADC();
	while(1){
		readVoltage();
		_delay_ms(100);
	}
}

