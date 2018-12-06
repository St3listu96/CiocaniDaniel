#define F_CPU 14745600UL

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "uart.h"
#include "adc.h"
#include "Timer.h"

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
	uint16_t timerValue;
	
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
			start_timer();
			while(i < BUFFER_SIZE){
				buffer1[i] = startADC(channel1);
				buffer2[i] = startADC(channel2);
				i++;
			}
			stop_timer();
			timerValue = get_timer_value();
			osciloscope(buffer1,buffer2,BUFFER_SIZE,timerValue);
		}
}
