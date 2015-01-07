#include<avr/io.h>
#include"uart.h"
void main()
{
	uart_init();
	uart_char('a');
	uart_char(0x62);
	uart_num(23);
	uart_num(234);
	uart_char('\n');
	uart_string("SIT 2012");
  
	while(1);
}