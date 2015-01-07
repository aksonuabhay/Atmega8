#include <avr/io.h>
void main()
{
 DDRB=0xff;
 while(1)
 {
  PORTB=~0x05;
  PORTB|=0x88;
  
  }
  }