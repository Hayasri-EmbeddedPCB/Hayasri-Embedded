#include <stdio.h>
void bigNum(int x,int y){
    if (x>y){
        printf("X is greater than Y , X is : %d\n",x);
    }
    else {
         printf("Y is greater than X , Y is : %d\n",y);
    }
}
int main()
{
int  a=10,b=20;
bigNum(a,b);
return 0;
}
