#include <reg51.h>
sbit Led = P1^0;
sbit s1 = P2^0;
void delay(){
unsigned int i,j;
for (i=0;i<100;i++){
for (j=0;j<1245;j++){
}
}
}
void main(){
Led = 0;
if (s1==0){
Led = 1;
delay();
}
if (s1==1){
Led = 0;
delay();
}
}
