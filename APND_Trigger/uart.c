/*
 * uart.c
 *
 * Created: 10/18/2018 10:46:28 AM
 *  Author: dspuser
 */ 

#include "uart.h"
#include <avr/io.h>

void init(){
	DDRD = 0x02;
	UCSRB = 0x08;
	UCSRC = 0x86;
	UBRRL = 0x07;
	UBRRH = 0x00;	
}

void TransmitChar(uint8_t ch){
	while (!( UCSRA & (1<<UDRE)));
	UDR = ch;
}

void TransmitString(char* sir){
	int i;
	for(i=0;i<strlen(sir);i++){
		TransmitChar(sir[i]);
	}	
}

void osciloscope(uint8_t *buff1, uint8_t *buff2 , uint32_t size){
	int i;
	for(i=0;i<size;i++){
		TransmitChar(buff1[i]);
	}
	for(i=0;i<size;i++){
		TransmitChar(buff2[i]);
	}
}