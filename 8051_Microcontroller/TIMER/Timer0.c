#include <reg51.h>
void time_delay(){
TMOD=0x01;
TH0=0xEE;
TL0=0x00;
TR0=1;
while(TF0==0);
TR0=0;
TF0=0;
}
void main(){
P1=0x00;
while(1){
P1=0x01;
time_delay();
P1=0x00;
time_delay();
}
}
