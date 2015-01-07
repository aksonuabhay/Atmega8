#include<avr/io.h>
#include"lcd118010.h"
#include<util/delay.h>

void main()
{
  lcd_init();
	DDRC=0x00;
	PORTC=0x0f;
	unsigned char a=0;
 while(1){
 if((PINC&0x01)==0x00)
 {
 while((PINC&0x01)==0x00);
 a++;
 }
 lcd_gotoxy(0,0);
 lcd_showvalue(a);
}
}
/*unsigned int incrmnt(unsigned int a ,int b)
{
 a+=b;
 return a;
 }*/