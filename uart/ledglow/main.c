#include<avr/io.h>
#include"uart.h"
void main()
{
	DDRB=0x0f;
	PORTB=0x00;
	uart_init();
	//uart_char((uart_read()));
	//unsigned char a;
	while(1)
	{ 
	 switch(uart_read())   
		{
	      case '1':
		  PORTB=0x01;
		  break;
		  case '2':
		  PORTB=0x02;
		  break;
		  case '3':
		  PORTB=0x04;
		  break;
		  case '4':
		  PORTB=0x08;
		  break;
	  }
	}

}