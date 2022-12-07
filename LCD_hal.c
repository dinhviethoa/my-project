/*
 * LCD_hal.c
 *
 * Created: 12/6/2022 2:33:45 PM
 *  Author: Dinh Viet Hoa
 */ 
#include "LCD_hal.h"

void LCD_Init (void){
	LCD_Dpin = 0xFF;
	_delay_ms(15);
	LCD_action(0x02);
	LCD_action(0x28);
	LCD_action(0x0c);
	LCD_action(0x06);
	LCD_action(0x01);
	_delay_ms(2);
}
void LCD_action(unsigned char tem){
	LCD_Port = (LCD_Port & 0x0f) | (tem & 0xf0);
	LCD_Port &= ~(1 << RSPIN);
	LCD_Port |= (1 << ENPIN);
	_delay_us(1);
	LCD_Port &= ~(1 << ENPIN);
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0f) | (tem << 4);
	LCD_Port |= (1 << ENPIN);
	_delay_us(1);
	LCD_Port &= ~(1 << ENPIN);
	_delay_ms(2);
}
void LCD_clear(void){
	LCD_action(0x01);
	_delay_ms(2);
	LCD_action(0x80);
}
void LCD_string(char *str ){
	int i;
	for (i = 0; str[i]!=0; i++){
		LCD_Port = (LCD_Port & 0x0f) | (str[i] & 0xf0);
		LCD_Port |= (1 << RSPIN);
		LCD_Port |= (1 << ENPIN);
		_delay_us(1);
		LCD_Port &= ~(1 << ENPIN);
		_delay_us(200);
		LCD_Port = (LCD_Port & 0x0f) | (str[i] << 4);
		LCD_Port |= (1 << ENPIN);
		_delay_us(1);
		LCD_Port &= ~(1 << ENPIN);
		_delay_ms(2);
	}
}
