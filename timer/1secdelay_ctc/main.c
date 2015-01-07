#include <avr/io.h>
#include<avr/interrupt.h>
void main()
{
 DDRB=0x0f;
 PORTB=0x00;
 TCCR1A=0x00;
 TCCR1B=0x0d;
 OCR1A=11765;
 //TCNT1=0xd20a;
 
 TIMSK=0x14;
 sei();
 while(1);
 }
 /*ISR(TIMER1_OVF_vect)
{
  PORTB=0x00;
  TCNT1=0xd20a;
 }*/
  ISR(TIMER1_COMPA_vect)
{
  PORTB^=0x0f;
 }