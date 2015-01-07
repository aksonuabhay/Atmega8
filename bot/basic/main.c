#include<avr/io.h>
#include"uart.h"
#include"lcd118010.h"
void main()
{
  uart_init();
  lcd_init();
  DDRD=0xf0;
  PORTD=0x00;
   while(1)
   {
	switch(uart_read())   
		{
	      case 'f':
		  case 'F':
		  lcd_gotoxy(0,0);
		  lcd_clear();
		  lcd_string("FORWARD");
		  PORTD=0x50;
		  break;
		  case 'l':
		  case 'L':
		  lcd_gotoxy(0,0);
		  lcd_clear();
		  lcd_string("LEFT");
		  PORTD=0x10;
		  break;
		  case 'r':
		  case 'R':
		  lcd_gotoxy(0,0);
		  lcd_clear();
		  lcd_string("RIGHT");
		  PORTD=0x40;
		  break;
		  case 's':
		  case 'S':
		  lcd_gotoxy(0,0);
		  lcd_clear();
		  lcd_string("STOP");
		  PORTD=0xf0;
		  break;
		  case 'b':
		  case 'B':
		  lcd_gotoxy(0,0);
		  lcd_clear();
		  lcd_string("BACKWARD");
		  PORTD=0xa0;
		  break;
		}
		
	  }
 
	
}