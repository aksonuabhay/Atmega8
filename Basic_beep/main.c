#include<avr/io.h>
void main()
{
DDRC=0x20;
PORTC=0x00;
while(1)
{
PORTC=0x20;
}
}