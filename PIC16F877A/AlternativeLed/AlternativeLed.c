#include<pic.h>
#define _xtal_frequency 200000
#define led PORTC
void delay(){
	unsigned int i,j;
	for(i=0;i<100;i++){
		for(j=0;j<1275;j++){
			}
			}
			}
			void main(){
				unsigned char k;
				TRISC=0x00;
				led=0;
				while(1){
					for(k=0x01;k<=0x80;k<<=1){
						led=k;
						delay();
						}
				for(k=0x80;k>=0x01;k>>=1){
						led=k;
						delay();
						}
}
}
