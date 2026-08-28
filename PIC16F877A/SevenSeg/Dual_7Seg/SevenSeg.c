#include<pic.h>
#define _xtal_freq 2000000
#define digital_control1 RB0
#define digital_control2 RB1
#define led PORTC
void delay(){
unsigned int i,j;
for(i=0;i<100;i++){
for(j=0;j<1000;j++){
}
}
}
void main(){
while(1){
TRISC=0x00;
TRISB=0x00;
digital_control1=1;
	led=0x3F;
digital_control2=0;
	delay();
digital_control1=0;
	led=0x6F;
digital_control2=1;
    delay();
	}
}
