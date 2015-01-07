#include <avr/io.h>
#define F_CPU 12000000
#include <util/delay.h>
#include "lcd118010.h"

int main(void)
{
 unsigned char i,a[14],temp=0;
 lcd_init();
 lcd_string(" RC 5");
 lcd_cmd(0xc0);
 lcd_string("decoder");
 _delay_ms(1000);
 lcd_clear();
 _delay_ms(100);
 DDRC=0x00;
 DDRD=0xff;
 PORTD=0x00;
 
 while(1)
 {
  if((PINC&0x01)==0x01)
  {
   _delay_us(100);
   for(i=0;i<14;i++)
   {
    if((PINC&0x01)==0x01)
	{
	 a[i]=1;
	 }
	else
	{
	 a[i]=0;
	 }
	_delay_us(1777);
   }
   lcd_gotoxy(0,0);
   lcd_char((a[0])+0x30);
   lcd_char((a[1])+0x30);
   lcd_char((a[2])+0x30);
   lcd_char((a[3])+0x30);
   lcd_char((a[4])+0x30);
   lcd_char((a[5])+0x30);
   lcd_char((a[6])+0x30);
   lcd_char((a[7])+0x30);
   lcd_gotoxy(1,0);
   lcd_char((a[8])+0x30);
   lcd_char((a[9])+0x30);
   lcd_char((a[10])+0x30);
   lcd_char((a[11])+0x30);
   lcd_char((a[12])+0x30);
   lcd_char((a[13])+0x30);
   temp=0x00;
    for(i=8;i<13;i++)
	{
	 if((a[i]&0x01)==0x01)
	 {
	  temp=temp|0x01;
	  }
	 temp<<=1;
	}
	lcd_gotoxy(1,9);
	//temp>>=1;
	lcd_showvalue(temp);
	switch(temp)
	{
	 case 30:
	 PORTD=0x50;
	 break;
	 case 28:
	 PORTD=0xa0;
	 break;
	 case 18:
	 PORTD=0x40;
	 break;
	 case 20:
	 PORTD=0x10;
	 break;
	 case 38:
	 PORTD=0x00;
	 break;
	 }
	 }

}
}
   