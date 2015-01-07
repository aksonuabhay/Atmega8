#include <avr/io.h>
#define F_CPU 12000000
#include "util/delay.h"
void spi_master_init(void)
{
 DDRD=0x03;
 DDRB=0x2c;
 SPCR=0x70;
}
void master_transmit1(char data)
{
 PORTD=0x00;
 SPDR=data;
 while((SPSR&0x80)==0x00);
 PORTD=0x01;
}
void master_transmit2(char data)
{
 PORTD=0x00;
 SPDR=data;
 while((SPSR&0x80)==0x00);
 PORTD=0x02;
}
void main()
{
 spi_master_init();
 while(1)
 {
  spi_master_transmit1(0x50);
  spi_master_transmit2(0xf0);
  _delay_ms(2000);
  spi_master_transmit1(0xf0);
  spi_master_transmit2(0x50);
  _delay_ms(2000);
 } 
}