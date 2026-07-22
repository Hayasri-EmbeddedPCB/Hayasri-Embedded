#include <reg51.h>
#define stepper_motor P2
void delay(){
	unsigned int i,j;
	for(i=0;i<100;i++){
		for(j=0;j<1275;j++){
		}
	}
}
unsigned char seg_code[]={
	0x08,0x04,0x02,0x01
};
void main()
{
	unsigned int i;
	while(1){
		for(i=0;i<8;i++){
			P2=seg_code[i];
			delay();
		}
	}
}
