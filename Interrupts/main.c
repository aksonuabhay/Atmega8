#include<avr/io.h>
#include"lcd118010.h"
#include<avr/interrupt.h>
unsigned char x;

ISR (INT0_vect)
{
 x++;
 lcd_gotoxy(1,6);
 lcd_showvalue(x);
 }
void main()
{
    DDRB=0x01;
	PORTB=0x00;
	DDRC=0x00;
	PORTC=0x01;
	lcd_init();
	MCUCR=0x01;
	GICR=0x43;
	if((PINC&0x01)==0x00)
	{
	  PORTB=0x01
	  }
	lcd_string("SIT 2012");
	sei();
	while(1);
 }