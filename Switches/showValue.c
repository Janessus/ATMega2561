/*
 * showValue.c
 *
 * Created: 04.06.2020 10:42:16
 *  Author: Janes
 */ 
#include "tools.h"
#define DELAY 100

// 0000 0000
// 0010 0000

// 0010 0000
// 0010 0000
// 0000 0000

void showValue(uint8_t value)
{
	DDRD = 0xFF;
	PORTD ^= ~value;
	_delay_ms(DELAY);
}
