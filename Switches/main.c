#include<avr/io.h>
#include<util/delay.h>
#define F_CPU 12000000
void main()
	{
	DDRB=0x0f;
	DDRC=0x00;
	PORTC=0x0f;
	PORTB=0x00;
	//unsigned int j;
	
	//unsigned char i;
	while(1)
	{
	    if((PINC&0x01)==0x00)
		 PORTB=0x01;
		else if((PINC&0x02)==0x00)
		 PORTB=0x02;
		else if((PINC&0x04)==0x00)
		 PORTB=0x04;
		else if((PINC&0x08)==0x00)
		 PORTB=0x08;
		else
			PORTB=0x00;


		
		
	}
	}