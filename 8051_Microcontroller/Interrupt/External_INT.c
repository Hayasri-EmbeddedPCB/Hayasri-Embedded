#include <reg51.h>
sbit led = P1^0;
sbit s1 = P3^2;
void ext_isr() interrupt 0
{
	led =~led;
}
void main (){
	led = 0;
	EA = 1;
	IT0 = 1;
	EX0 =1;
	while (1){
	}
}
