#include <reg51.h>
sbit led = P1^0;
void timer_isr() interrupt 1
{
	led =~led;
	TH0 = 0xFC;
	TL0 = 0x66;
}
void main()
	{
	led = 0;
	TMOD = 0x01;
	TH0 = 0xFC;
	TL0 = 0x66;
	EA = 1;
	ET0 =1;
	TR0 = 1;
	while (1){
	}
}
