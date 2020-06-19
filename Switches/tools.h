/*
 * tools.h
 *
 * Created: 04.06.2020 10:25:22
 *  Author: Janes
 */ 


#ifndef TOOLS_H_
#define TOOLS_H_

	#define F_CPU 16000000UL
	#include <stdint.h>
	#include <util/delay.h>
	#include <avr/io.h>
	
	uint8_t readValue(void);
	void showValue(uint8_t value);


#endif /* TOOLS_H_ */