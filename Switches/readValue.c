/*
 * readValue.c
 *
 * Created: 04.06.2020 10:42:00
 *  Author: Janes
 */ 

#include "tools.h"

uint8_t readValue(void)
{
	DDRC = 0;
	return PINC;
}