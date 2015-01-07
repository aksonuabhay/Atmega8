#include<avr/io.h>
#include<util/delay.h>
#define F_CPU 12000000
void main()
	{
	DDRB=0x0f;
	DDRC=0x20;
	PORTC=0x0f;
	PORTB=0x00;
	//unsigned char a;
	while(1)
	{
	switch(PINC&0x0f)
	{
	  case 0x0e:
		PORTC|=0x20;
		break;
	  case 0x0d:
		PORTC|=~0x20;
		break;
	  /*case 0x0b:
		PORTC|=0x20;
		break;
	  case 0x07:
		PORTC|=0x20;
		break;*/
	  default:
	    PORTC&=0x00;
		break;
		
	}
	
	}
	}