#include<avr/io.h>
#include<util/delay.h>
void main()
{
	DDRB=0x0f;
	DDRC=0x20;
	PORTC=0x00;
	PORTB=0x00;
	unsigned char i;
	while(1)
	{
		for(i=0x01;i<=0x08;i<<=1)
		{
			PORTB=i;
			-delay_ms(1000);
		}
		PORTC=0x20;
		_delay_ms(1000);
		PORTC=0x00;
		
\	}
}