/*
 * uart.c
 *
 * Created: 10/18/2018 10:46:28 AM
 *  Author: dspuser
 */ 

#include "uart.h"
#include <avr/io.h>

#define BUFFER_SIZE 300

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

void osciloscope(uint8_t *buff1, uint8_t *buff2 , uint32_t size,uint16_t tValue){
	int i;
	uint8_t tValueHigh;
	uint8_t tValueLow;
	TransmitChar(0xA0);
	TransmitChar(0xA3);
	TransmitChar(0xB0);
	TransmitChar(0xB3);
	TransmitChar(BUFFER_SIZE >> 8);
	TransmitChar(BUFFER_SIZE & 0x00FF);
	
	for(i=0;i<size;i++){
		TransmitChar(buff1[i]);
	}
	for(i=0;i<size;i++){
		TransmitChar(buff2[i]);
	}
	tValueLow = tValue;
	tValueHigh = tValue >> 8;
	TransmitChar(tValueHigh);
	TransmitChar(tValueLow);
}