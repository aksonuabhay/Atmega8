#include<avr/io.h>
#include<avr/interrupt.h>
#include"lcd118010.h"
void main()
{
	  lcd_init();
// DDRB=0x1f;
 //PORTB=0x00;
 DDRC=0x00;
 DDRD=0x10;
 PORTC=0x01;
 //MCUCR=0x01;
 //GICR=0x43;
 TCNT0=0x00;
  TCCR0=0x07;
 // TIMSK=0x01;
  	 // lcd_showvalue(TCNT0);
// sei();
 while(1)
 {
 if((PINC&0x01)==0x00)
	{
	  while((PINC&0x01)==0x00);
	  PORTC|=0x08;
	  lcd_init();
	  TCNT0++;
      //lcd_gotoxy(0,0);
	  lcd_showvalue(TCNT0);
	   PORTC&=~0x08;
	 
	  }
	  }
}
/*ISR(TIMER0_OVF_vect)
{
  //PORTB^=0x0f;
 lcd_showvalue(TCNT0);
 PORTC&=~0x08;
 }*/