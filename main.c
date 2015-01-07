#include <avr/io.h>
void main()
{
  DDRB=0xff;
  PORTB=~0x09;
  PORTB|=0x88;
  }