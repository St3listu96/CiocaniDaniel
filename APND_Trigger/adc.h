#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>

uint8_t readVoltage(uint8_t channel);
void initADC();
uint8_t startADC(uint8_t channel);