/*
 * 7Segment_multiplex.c
 *
 * Created: 26.06.2020 10:08:57
 * Author : Janes
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#define DELAY 5


int main(void)
{
	int segmente[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	int i = 0;
	
	DDRC = 0xFF;
	DDRF = 0xFF;
	
	uint8_t tausend, hundert, zehner, einer;
	
    while (1) 
    {
		for(tausend = 0; tausend <= 9; tausend++)
			for(hundert = 0; hundert <= 9; hundert++)
				for(zehner = 0; zehner <= 9; zehner++)
					for(einer = 0; einer <= 9; einer++)
						for(i = 0; i < 100; i++)
						{
							PORTF = 0xfe; // 1111 1110 //Linke Anzeige
							PORTC = segmente[tausend];
							_delay_ms(DELAY);
			
							PORTF = 0xfd; // 1111 1101
							PORTC = segmente[hundert];
							_delay_ms(DELAY);
			
							PORTF = 0xfb;
							PORTC = segmente[zehner];
							_delay_ms(DELAY);
			
							PORTF = 0xf7; // 1111 0111 //Rechte Anzeige
							PORTC = segmente[einer];
							_delay_ms(DELAY);
						}
    }
}

