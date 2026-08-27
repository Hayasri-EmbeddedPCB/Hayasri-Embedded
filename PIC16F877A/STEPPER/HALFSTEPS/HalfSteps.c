#include<pic.h>
#define _XTAL_FREQ 2000000
#define motor PORTB
void delay(){
unsigned int i,j;
	for(i=0;i<100;i++){
	for(j=0;j<1245;j++){
		}
		}
		}
		unsigned char full_steps[]={
			0x80,0x0C,0x04,0x06,0x02,0x03,0x01,0x09
			};
			void main(){
				unsigned int i;
                TRISB=0x00;
                while(1){
				for(i=0;i<8;i++){
					PORTB=full_steps[i];
					delay();
					}
					}
					}
		
