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
	    PORTB=0x01;
		_delay_ms(500);
		PORTC=0x20|PINC;
		_delay_ms(400);
		break;
	  case 0x0d:
	    PORTB=0x02;
		_delay_ms(500);
		PORTC=0x20|PINC;
		_delay_ms(400);
		break;
	  case 0x0b:
		PORTB=0x04;
		_delay_ms(500);
		PORTC=0x20|PINC;
		_delay_ms(400);
		break;
	  case 0x07:
		PORTB=0x08;
		_delay_ms(500);
		PORTC=0x20|PINC;
		_delay_ms(400);
		break;
	  default:
	    PORTB=0x00;
	    PORTC&=0x00;
		break;
		
	}
	
	}
	}