#include<avr/io.h>
#include<avr/interrupt.h>
#include"util/delay.h"
#include"lcd118010.h"
#define F_CPu 12000000
int main(void)
{
 unsigned char data,i;
 DDRC=0x00;
 PORTC=0x01;
 lcd_init();
 lcd_string("IR RECEIVER");
 
 while(1)
 {
  if((PINC&0x01)==0x01)
  {
   data=0;
   _delay_us(1500);
   for(i=0 ;i<=7 ;i++)
   {
    data>>=1;
	if((PINC&0x01)==0x01)
	{
      data|=0x80;	
	}
	_delay_us(2000);
	}
	lcd_gotoxy(1,0);
	lcd_showvalue(data);
	_delay_ms(500);
	}
	}
 
}
