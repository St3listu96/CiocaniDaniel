#include "adc.h"

void initADC(){
	
	DDRA = 0x00;
	ADCSRA = 0x87;
}

uint8_t startADC(uint8_t channel){
	if(channel == 1){
		ADMUX = 0x60;
	}
	else if(channel == 2){
		ADMUX = 0x61;
	}
	
	ADCSRA = ADCSRA | 0x40;
	while((ADCSRA & 0x40) != 0);
	return ADCH;
}




uint8_t readVoltage(uint8_t channel){
	uint32_t Vresult;
	uint32_t aux = 0;
	aux = startADC(channel);
	Vresult = (aux * 3300) / 255;
	return Vresult;
}