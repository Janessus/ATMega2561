/*
 * matrix1.c
 *
 * Created: 26.06.2020 11:18:40
 * Author : Janes
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

/*				
				F
	0 0 0 0		0
	0 0 0 0		0
	0 0 0 0		0
	0 0 0 0		0
	
E	0 0 0 0

*/

int main(void)
{
	DDRE = 0xff; //Spalte
	DDRF = 0xff; //Zeile
	
	PORTE = 0;
	PORTF = 0;
	
    while (1) 
    {
		for(uint16_t k = 1; k <= 0x80; k<<=1)
		{
			PORTF = ~k;
		
			for(uint16_t i = 1; i <= 0x80; i<<=1)
			{
				PORTE = i;
				_delay_ms(300);
			}
		}
	}
}

