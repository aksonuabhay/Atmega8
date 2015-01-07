#include <avr/io.h>
#include<avr/interrupt.h>
#define F_CPU 12000000
#include "util/delay.h"
int main(void)
{
	 DDRB=0x0f;
	 TCCR1A=0x03;
	 TCCR1B=0x1A;
	 TCNT1=0x0000;
	 OCR1A=0x7530;
	 OCR1B=0x05dc;
	 TIMSK=0x18;
	 
	 sei();
	 while(1)
		 {
		  // OCR1B=0x05dc;
		   //_delay_ms(2000);
		   
		   OCR1B=0x08ca;
		   _delay_ms(2000);
		   
		   //OCR1B=0x0bb8;
		  // _delay_ms(2000);
			
		 }
 }
 ISR(TIMER1_COMPB_vect)
{
  PORTB=0x00;
 }
  ISR(TIMER1_COMPA_vect)
{
  PORTB=0x0f;
 }