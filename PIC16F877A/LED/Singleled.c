#include<pic.h>
#define _xtal_frequency 2000000
#define led PORTB
void delay(){
unsigned int i,j;
for(i=0;i<100;i++){
for(j=0;j<1275;j++){
	}
	}
	}
	void main(){
		TRISB=0x00;
	    led=0;
		while(1){
			led=1;
			delay();
			led=0;
			delay();
			}
			}
			
		
