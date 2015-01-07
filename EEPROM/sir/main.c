#include<avr/io.h>
#include<lcd118010.h>
void write(unsigned int add,unsigned char dat)
{
 while((EECR & 0X02)==0X02);
	 EEAR=add;
	 EEDR=dat;
	 EECR|=(1<<EEMWE);
	 EECR|=(1<<EEWE);
	
}
 int read(unsigned int add)
{unsigned int dat;
 while((EECR & 0x02)==0x02);
 {EEAR=add;
 EECR|=(1<<EERE);
 dat=EEDR;
 //EECR|=(EERE<<1);
 }
 return dat;
}
void main()
{unsigned char a,b;
	lcd_init();
	DDRC=0xf0;
	PORTC=0x00;
	
	
	write(1,4);
	write(0,40)   ;
	write(5,10);
	write(7,14);
	
while(1)
{ if((PINC&0x01)==0x00)
  {while((PINC&0x01)==0x00);
   a=read(b);
   lcd_showvalue(b);
   lcd_string("-");
   lcd_showvalue(a);
   lcd_string(";");
   b++;
   }
}
}