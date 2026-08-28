#include<pic.h>
#define _XTAL_FREQ 2000000
void delay(){
unsigned int i,j;
	for(i=0;i<100;i++){
		for(j=0;j<1245;j++){
			}
			}
			}
			unsigned char seg_code[]={
				0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F
				};
			void main(){
				unsigned int i;
		TRISB=0x00;
		while(1){
			for(i=0;i<10;i++){
				PORTB=seg_code[i];
				delay();
				}
				}
				}
