#include<avr/io.h>
#include"lcd118010.h"
void main()
{
  lcd_init();
  DDRD=0xf0;
  PORTD=0x00;
  DDRC=0x18;
   while(1)
   {
	if(((PINC&0x10)|(PINC&0x08))==0x00)   
	{
		  lcd_init();
		  lcd_string("FORWARD");
		  PORTD=0x50;
	}
	else if (((PINC&0x10)|(PINC&0x08))==0x18)   
	{	 
		  lcd_init();
		  lcd_string("STOP");
		  PORTD=0xf0;
   	 }
	else if ((PINC&0x08)==0x08)  
	{
		  lcd_init();
		  lcd_string("LEFT");
		  PORTD=0x10;
	}
    	else if ((PINC&0x10)==0x10)
	{
		  lcd_init();
		  lcd_string("RIGHT");
		  PORTD=0x40;
	}
    
		
	  }
 
	
}