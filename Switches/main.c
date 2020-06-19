/*
 * Switches.c
 *
 * Created: 04.06.2020 10:23:59
 * Author : Janes
 */ 

#include <avr/io.h>
#include "tools.h"


int main(void)
{
    while (1) 
    {
		showValue(readValue());
    }
}

