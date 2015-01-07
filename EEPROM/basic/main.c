#include<avr/io.h>
#include "lcd118010.h"
void main()
{
 lcd_init();
 DDRB=0x0f;
 PORTB=0x00;
 unsigned char a;
 while((EECR&0x02)==0x02);
 EEARH=0x00;
 EEARL=0x00;
 EEDR=0x38;
 EECR=0x04;
 EECR=0x02;
 //Write portion over
 //Read portion begins
 while ((EECR&0x02)==0x02);
 EEARH=0x00;
 EEARL=0x00;
 EECR=0x01;
 a=EEDR;
 lcd_char(a);
 if(EEDR==0x38)
 {
  PORTB=0x01;
 }
 }

 