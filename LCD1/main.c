/*
 * LCD1.c
 *
 * Created: 10.06.2020 10:58:54
 * Author : Janes
 */ 

#define F_CPU 16000000UL

#define LINEWIDTH 16

#include <util/delay.h>
#include <avr/io.h>
#include <string.h>

#include "lcd.h"


int main(void)
{
	char string[] = "Hello World! Das ist ein seeeeehr langer Text für ein 16 stelliges display!";
	char tmp[LINEWIDTH] = { 0 };
	
	int offset = 0;
	
	lcd_init(LCD_DISP_ON);
	lcd_clrscr();
	lcd_gotoxy(10, 0);-
	lcd_puts(string);
	
	
    while (1) 
    {
		for(int i = 0; i < LINEWIDTH-1; i++)
		{
			tmp[i] = string[i + offset];
		}
		offset++;
		
		lcd_puts(tmp);
		
		_delay_ms(200);
		lcd_clrscr();
		
		if(offset > strlen(string) - LINEWIDTH)
			offset = 0;
    }
	
	return 0;
}

