#include<avr/io.h>
#include"lcd118010.h"
#include<util/delay.h>

void main()
{
  lcd_init();
    DDRB=0x0f;
	PORTB=0x00;
	DDRC=0x00;
	PORTC=0x0f;
	unsigned int a=0;
 while(1){
 /*lcd_cmd(0x18);
 _delay_ms(500);8*/
 switch(PINC&0x0f)
	{
	  case 0x0e:
	    a+=1;
		PORTB=0x01;
	    lcd_showvalue(a);
		break;
	  case 0x0d:
	    a+=2;
		PORTB=0x02;
	  	lcd_showvalue(a);
		break;
	  case 0x0b:
	    a+=3;
		PORTB=0x04;
		lcd_showvalue(a);
		break;
	  case 0x07:
		a+=4;
		PORTB=0x08;
	    lcd_showvalue(a);
		break;
	 
	}
 }
}
/*unsigned int incrmnt(unsigned int a ,int b)
{
 a+=b;
 return a;
 }*/