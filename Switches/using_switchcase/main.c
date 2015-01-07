#include<avr/io.h>
#include<util/delay.h>
#define F_CPU 12000000
void main()
	{
	DDRB=0x0f;
	DDRC=0x00;
	PORTC=0x0f;
	PORTB=0x00;
	while(1)
	{
	switch(PINC&0x0f)
	{
	  case 0x0e:
		PORTB=0x01;
		break;
	  case 0x0d:
		PORTB=0x02;
		break;
	  case 0x0b:
		PORTB=0x04;
		break;
	  case 0x07:
		PORTB=0x08;
		break;
	  default:
	    PORTB=0x00;
		
	}
	
	}
	}