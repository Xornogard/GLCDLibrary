/*
 * alcd.h
 *
 * Created: 30.01.2019 22:57:07
 *  Author: Xornogard
 */ 


#ifndef ALCD_H_
#define ALCD_H_

#include <avr/io.h>
#define F_CPU 16e6
#include <util/delay.h>
#include <string.h>

#define DATA_PORT PORTD
#define CONTROL_PORT PORTB
#define RS (1<< PB7)
#define E (1 << PB6)

void alcd_init(void);
void alcd_write(char* char_array, uint8_t length);
void alcd_command(uint8_t command);

#endif /* ALCD_H_ */