#include <avr/io.h>
void spi_slave_init(void)
{
 DDRB=0x10;
 SPCR=0x60;
}
char spi_slave_receive(void)
{
 while((SPSR&0x08)==0x00);
 return SPDR;
}
void main()
{
 DDRD=0xf0;
 spi_slave_init();
 while(1)
 {
  PORTD=spi_slave_receive(); 
  }
}
