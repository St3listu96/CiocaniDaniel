#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>

void init();
void TransmitChar(uint8_t ch);
void TransmitString(char* sir);