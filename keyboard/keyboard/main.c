/*
 * keyboard.c
 *
 * Created: 26.06.2020 11:32:04
 * Author : Janes
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

#include "lcd.h"



int keyboard () //Eingabe Routine
{
	DDRC = 0xf8;
	while (1)
	{
		PORTC =  0x70;	//1110 0000			//aktivierezeile 1
		_delay_ms (100);			//LED aus
		if(PINC==0x76) return 1;	//1
		if(PINC==0x75) return 2;    //2
		if(PINC==0x73) return 3; 	//3

		PORTC =  0b01101000;		//aktivierezeile 1
		_delay_ms (1);
		if(PINC==0x6E) return 4;	//4
		if(PINC==0x6D) return 5; 	//5
		if(PINC==0x6B) return 6;	//6

		PORTC =  0b01011000;		//aktivierezeile 1
		_delay_ms (1);
		if(PINC==0x5E) return 7;	//7
		if(PINC==0x5D) return 8;	//8
		if(PINC==0x5B) return 9;	//9

		PORTC =  0b00111000;		//aktivierezeile 1
		_delay_ms (1);
		if(PINC==0x3D) return 0;	//0
		
		PORTC = 0x80; //mit roter LED blinkt
		_delay_ms (20); //LED Ein
	}
}


int main(void)
{
	lcd_init(LCD_DISP_ON);
	char buffer[32];
	
	while(1)
	{
		itoa(keyboard(), buffer, 10);
		lcd_clrscr();
		lcd_puts(buffer);
	}
}
