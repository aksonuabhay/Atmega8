#include<avr/io.h>
#include"lcd118010.h"
void main()
{
  lcd_init();
  DDRD=0xf0;
  DDRB=0x0f;
  PORTB=0x00;
  PORTD=0x00;
  DDRC=0x0c;
  PORTC=0x00;
   while(1)
   {
	if(((PINC&0x04)|(PINC&0x08))==0x00)   
	{
		  lcd_init();
		  lcd_string("FORWARD");
		  PORTD=0x50;
		  PORTB=0x01;
	}
	else if (((PINC&0x04)&(PINC&0x08))==0x0c)   
	{	
		  lcd_init();
		  lcd_string("STOP");
		  PORTD=0xf0;
		  PORTB=0x02;
    }
	else if ((PINC&&0x08))  
	{
		  lcd_init();
		  lcd_string("RIGHT");
		  PORTD=0x40;
		  PORTB=0x04;
	}
    else if ((PINC&&0x04))
	{
		  lcd_init();
		  lcd_string("LEFT");
		  PORTD=0x10;
		  PORTB=0x08;
	}
    
		
	  }
 
	
}