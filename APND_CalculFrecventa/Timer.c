#include "Timer.h"


void start_timer(void){
	TCCR1B = TCCR1B | 0x02;
}

void stop_timer(void){
	TCCR1B = TCCR1B & 0xF8;
}

uint16_t get_timer_value(void){
	
	uint16_t timerValue;
	timerValue = TCNT1H; 
	timerValue = timerValue << 8;
	timerValue = timerValue | TCNT1L;
	TCNT1H = 0;
	TCNT1L = 0;
	return timerValue;
}