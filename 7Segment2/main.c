/*
 * 7Segment_uebung1.c
 *
 * Created: 19.06.2020 11:00:23
 * Author : Janes
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void show7SegHex(uint8_t n)
{
	int num[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 };
	DDRC = 0xFF;
	
	if(n < 16)
		PORTC = num[n];
}


int main(void)
{
	uint8_t count = 0;
	DDRD = 0;
	
	while(1)
	{
		uint8_t tmp = 0xFF;
		count = 0;
		
		//wait for button to be pressed
		while(tmp == 0xFF)
			tmp = PIND;
		
		//invert btn value (buttons are low active)
		tmp = ~tmp;
		
		//convert bin to pin number
		while(tmp > 0)
		{
			tmp >>= 1;
			count++;
		}
		show7SegHex(count);
		_delay_ms(200);
	}
}