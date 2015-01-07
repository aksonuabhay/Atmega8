#include<avr/io.h>
#include<lcd118010.h>
#include<util/delay.h>
void main()
{
    //unsigned char a=0x0000;
	DDRC=0x00;
	
	while(1)
	{
	 lcd_init();
	 ADMUX=0x20;
	 ADCSRA=0xc6;
	 
	// while((ADCSRA&0x10)==0x10);
	// _delay_ms(1000);
	 lcd_showvalue(ADC);
	 //_delay_ms(500);
	 }
 }