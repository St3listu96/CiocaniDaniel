#define F_CPU 14745600UL

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "uart.h"

#define BUFFER_SIZE 300
#define VT_LO 110
#define VT_HI 140
#define POSITIVE 1


int main(void)
{
    init();
	initADC();
	uint8_t buffer1[BUFFER_SIZE];
	uint8_t buffer2[BUFFER_SIZE];
	uint8_t channel1=1;
	uint8_t channel2=2;
	uint8_t value;
	
		while(1){
			int i=0;
	
			if(POSITIVE == 1){
				value = startADC(channel1);
				while(value < VT_HI){
					value = startADC(channel1);
				}
			
				value = startADC(channel1);
				while(value > VT_LO){
					value = startADC(channel1);
				}
			}
			else{
				value = startADC(channel1);
				while(value > VT_LO){
					value = startADC(channel1);
				}
				
				value = startADC(channel1);
				while(value < VT_HI){
					value = startADC(channel1);
				}
			}
		
			while(i < BUFFER_SIZE){
				buffer1[i] = startADC(channel1);
				buffer2[i] = startADC(channel2);
				i++;
			}
			TransmitChar(0xA0);
			TransmitChar(0xA3);
			TransmitChar(0xB0);
			TransmitChar(0xB3);
			TransmitChar(BUFFER_SIZE >> 8);
			TransmitChar(BUFFER_SIZE & 0x00FF);
			osciloscope(buffer1,buffer2,BUFFER_SIZE);
			TransmitChar(0x00);
			TransmitChar(0x00);
		}
}
