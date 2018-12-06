#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>

void start_timer(void);
void stop_timer(void);
uint16_t get_timer_value(void);