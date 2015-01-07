#include<avr/io.h>                                                                                                                   K
#include"lcd118010.h"
void main()
{
  lcd_init();
  DDRD=0xf0;
  PORTD=0x00;
  DDRC=0x00;
   while(1)
   {
	switch(PINC)   
		{
	      case 0x02:
		  lcd_init();
		  lcd_string("FORWARD");
		  PORTD=0x50;
		  break;
		  case 0x04:
		  lcd_init();
		  lcd_string("LEFT");
		  PORTD=0x10;
		  break;
		  case 0x06:
		  lcd_init();
		  lcd_string("RIGHT");
		  PORTD=0x40;
		  break;
		  case 0x0a:
		  lcd_gotoxy(0,0);
		  lcd_clear();
		  lcd_string("STOP");
		  PORTD=0xf0;
		  break;
		  case 0x08:
		  lcd_init();
		  lcd_string("BACKWARD");
		  PORTD=0xa0;
		  break;
		}
		
	  }
 
	
}