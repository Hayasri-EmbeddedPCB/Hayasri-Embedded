#include<reg51.h>
#define Led P2

void delay() {
    unsigned int i;
    for(i=0; i<1000; i++) {  
    }
}

void main() {
    unsigned int j;
	   Led = 0x00;

    while(1) {
        
        for(j=0x01; j<=0x80; j<<=1) { 
            Led = j;
            delay();
        }

       
        for(j=0x80; j>0; j>>=1) {
            Led = j;
            delay();
        }
    }
}



