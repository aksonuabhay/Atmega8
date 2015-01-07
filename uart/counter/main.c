#include<avr/io.h>
#include"uart.h"
void main()
{
	DDRC=0x00;
	PORTC=0x01;
	uart_init();
	//uart_char((uart_read()));
	unsigned char a;
	while(1)
	{ 
	    if((PINC&0x01)==0x00)
		{
			while((PINC&0x01)==0x00);
			a++;
		}
	 uart_char(13);
	 uart_num(a);		 
	
	}

}