/*
 * alcd.c
 *
 * Created: 30.01.2019 22:56:58
 *  Author: Xornogard
 */ 

 #include "alcd.h"

 void alcd_init(void)
 {
	 DDRB = 0xff;
	 DDRD = 0xff;

	 CONTROL_PORT &= ~RS; //R = 0

	 alcd_command(0x38);  //0011 1000
	 alcd_command(0x06);  //0000 0110
	 alcd_command(0x0f);  //0000 1111
	 alcd_command(0x01);  //0000 0001

	 _delay_ms(2);

	 CONTROL_PORT |= RS; //R=1
 }

 void alcd_write(char* char_array, uint8_t length)
 {
	 CONTROL_PORT &= ~RS; //R = 0
	 alcd_command(0x80); //1000 0000
	 CONTROL_PORT |= RS; //R=1

	 for(int i=0; i<length; i++)
	 {
		 alcd_command(*(char_array+i));
		 if(i+1 == 16)
		 {
			 CONTROL_PORT &= ~RS; //R = 0
			 alcd_command(0xc0);  // 1100 000
			 CONTROL_PORT |= RS; //R=1
		 }
	 }
 }

 void alcd_command(uint8_t command)
 {
	 CONTROL_PORT |= E; //E = 1 Rising edge 
	 DATA_PORT = command;
	 _delay_us(30);
	 CONTROL_PORT &= ~E; //E=0 Falling edge 
	 _delay_us(30);
 }
