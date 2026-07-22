#include <reg51.h>
sbit motor_in1=P2^0;
sbit motor_in2=P2^1;
void delay(){
unsigned int i,j;
for(i=0;i<100;i++){
for(j=0;j<1275;j++){
}
}
}
void main(){
while(1){
motor_in1=1;
motor_in2=0;
delay();
motor_in1=0;
motor_in2=1;
delay();
motor_in1=0;
motor_in2=0;
delay();
}
}
