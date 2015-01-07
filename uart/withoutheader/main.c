#include<avr/io.h>
#include"util/delay.h"
void main()
{
	DDRB=0x0f;
	PORTB=0x00;
	UCSRA=0x00;
	UCSRB=0x18;
	UCSRC=0x86;
	UBRRH=0x00;
	UBRRL=0x4D;
	_delay_ms(100);
	//uart_init();
	//uart_char((uart_read()));
	//unsigned char a;
	while(1)
	{ 
	 if((PINC&0x01)==0x00)
	 {
	  while(((PINC&0x01)==0x00));
	  UDR=0x31;
	  while((UCSRA&0x40)==0x00);
	  _delay_ms(100);
	  }
	}

}