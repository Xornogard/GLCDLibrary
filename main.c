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

void glcd_test_mixed();


int main(void)
{
	glcd_init();

	glcd_test_mixed();
}

void glcd_test_mixed()
{
	uint8_t x = 0;
	uint8_t y = 0;
	uint8_t horizontal = 0;

	while (1)
	{
		glcd_set_pixel(x,y);

		if(horizontal)
		{
			x++;
			
			if(x >= SCREEN_WIDTH)
			{
				x = SINGLE_CONTROLLER_SCREEN_WIDTH;
				y++;

				if(y >= SCREEN_HEIGHT)
				{
					x = 0;
					y = 0;
					horizontal = 0;
					glcd_clear_all();
				}
			}
		}
		else
		{
			y++;
			
			if(y >= SCREEN_HEIGHT)
			{
				x++;
				y = 0;

				if(x >= SINGLE_CONTROLLER_SCREEN_WIDTH)
				{
					horizontal = 1;
				}
			}
		}

		_delay_ms(2);
	}
}
