/*
 * glcd_library.c
 *
 * Created: 30.01.2019 22:26:30
 * Author : Xornogard
 */ 

#include <avr/io.h>
#define F_CPU 16e6
#include <util/delay.h>
#include "glcd/glcd.h"


int main(void)
{
   glcd_init();

   for (uint8_t i=0; i<64; i++)
   {
	   glcd_set_pixel(30, i);
   }


   uint8_t x = 0;
   uint8_t y = 0;

   while (1)
   {
	   glcd_set_pixel(x,y);

	   y++;
	   
	   if(y >= SCREEN_HEIGHT)
	   {
		   x++;
		   y = 0;

		   if(x >= SCREEN_WIDTH)
		   {
			   x = 0;
			   glcd_clear_all();
		   }
	   }

	   _delay_ms(50);
   }
}

