#include <avr/io.h>
#include<avr/interrupt.h>
#define F_CPU 12000000
#include "util/delay.h"
int main(void)
{
	 DDRB=0x0f;
	 DDRC=0x00;
	 PORTC=0x0f;
	 TIMSK=0x0c;
	 PORTB=0x00;
	 TCCR2=0x4c;
	 TCNT2=0x00;
	 OCR2=150;
	 sei();
	 while(1)
		 {
		  if((PINC &0x01) ==0x00)
			  {
				_delay_ms(10);
				OCR2++;
				if(OCR2>=253)
				 OCR2=253;
			   }
		   if((PINC &0x02) ==0x00)
			   {
				_delay_ms(10);
				OCR2--;
				if(OCR2<=3)
				 OCR2=3;
			   }
			
		 }
 }
 ISR(TIMER2_OVF_vect)
{
  PORTB=0x0f;
 }
  ISR(TIMER2_COMP_vect)
{
  PORTB=0x00;
 }