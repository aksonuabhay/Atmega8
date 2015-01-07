#include<avr/io.h>
#include"uart.h"
void main()
{
	uart_init();
	unsigned char a=(uart_read());
	uart_char(a);
	while(1);
	 //uart_char(a);

}