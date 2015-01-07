#include<avr/io.h>
#include<util/delay.h>
#define F_CPU 12000000
void main()
	{
	DDRB=0x0f;
	DDRC=0x20;
	PORTC=0x00;
	PORTB=0x00;
	unsigned int j;
	
	unsigned char i;
	while(1)
	{
		for(i=0x01;i<=0x08;i<<=1)
		{
			PORTB=i;
			for(j=0;j<25000;j++){}
		}
		PORTC=0x20;
		_delay_ms(1000);
		PORTC=0x00;
		
	}
	}