/*
 * LCD_hal.h
 *
 * Created: 12/6/2022 2:34:25 PM
 *  Author: Dinh Viet Hoa
 */ 


#ifndef LCD_HAL_H_
#define LCD_HAL_H_
#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define LCD_Port PORTD
#define LCD_Dpin DDRD
#define RSPIN PD0
#define ENPIN PD1

void LCD_Init (void);
void LCD_action(unsigned char tem);
void LCD_clear(void);
void LCD_string(char *str );


#endif /* LCD_HAL_H_ */
