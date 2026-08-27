#include<pic.h>
#define _XTAL_FREQ 2000000
#define IN1 RC0
#define IN2 RC1
void delay(){
unsigned int i,j;
for(i=0;i<100;i++){
	for(j=0;j<12000;j++){
		}
		}
		}
		void main(){
			TRISC=0x00;
			while(1){
				//forward
				RC0=1;
				RC1=0;
				delay();
				//stop
				RC0=0;
				RC1=0;
				delay();
				//Reverse
				RC0=0;
				RC1=1;
				delay();
				}
				}
		
