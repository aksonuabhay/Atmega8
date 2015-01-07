#include<avr/io.h>
#include<avr/interrupt.h>
#include"util/delay.h"
#define F_CPu 12000000
ISR (TIMER0_OVF_vect)
{
  TCNT0=98;
  PORTB^=0x01;
}
void tx (unsigned char data)
{
 unsigned char i;
 TCCR0=0x01;
 _delay_us(800);
 TCCR0=0x00;
// _delay_us(800);
 for(i=0 ; i<=7 ;i++)
 {
  if((data&0x01)==0x01)
  {
   TCCR0=0x01;
   _delay_us(1600);
   }
   else
   {
    TCCR0=0x00;
	_delay_us(2000);
    }
	data>>=1;
  } 
   TCCR0=0x00;
   PORTC=0x0f;
}
void main()
{
 unsigned char tx1;
 TCNT0=98;
 TCCR0=0x00;
 
 TIMSK=0x01;
 DDRB=0x01;
 PORTB=0x00;
 DDRC=0x00;
 PORTC=0x0f;
 
 sei();
 
 while(1)
 {
   if((PINC&0x01)==0x00)
   {
    while((PINC&0x01)==0x00);
	tx(tx1);
	PORTC=0x0f;
	tx1++;
	}
  }
}