/*
 * pingpong.c
 *
 * Created: 26.05.2020 11:28:36
 *  Author: Janes
 */ 

#include "tools.h"

#define UP 0
#define DOWN 1

// &	and
// |	or
// ^	exor
// <<	shift
// ~	not

void pingPong(void)
{
	    DDRD = 0xff;
	    PORTD = 0;
	    
	    uint8_t i = 0;
		uint8_t state = UP;
	    
	    while (1)
	    {
		    PORTD = (1 << i);
		    _delay_ms(DELAY);
		    
			if(state == UP)
				i++;
			else if(state == DOWN)
				i--;
		    
		    if(i >= 8)
				state = DOWN;
			else if(i == 0 && state == DOWN)
				 state = UP;
			
	    }
}