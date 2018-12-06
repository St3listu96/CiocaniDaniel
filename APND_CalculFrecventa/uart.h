#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>

void init();
void TransmitChar(uint8_t ch);
void TransmitString(char* sir);
void osciloscope(uint8_t *buff1, uint8_t *buff2 , uint32_t size, uint16_t tValue);