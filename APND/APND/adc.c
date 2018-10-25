#include "adc.h"

void initADC(){
	
	DDRA = 0x00;
	ADCSRA = 0x83;
	
}

int conversion(){
	ADMUX = 0x60;
	ADCSRA = ADCSRA | 0x40;
	while((ADCSRA & 0x40) != 0);
	return ADCH;
}


void readVoltage(){
	char* text;
	if(conversion() == 0){
		int Vresult;
		Vresult = ADCH * 3300 / 255;
		sprintf(text,"U= %d\n",Vresult);
		TransmitString(text);
	}
}