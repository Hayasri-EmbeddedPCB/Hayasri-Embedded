#include <stdio.h>

int main() {
    int arr[] = {5,10,15,20,25,30};
 int len;
 len = sizeof(arr)/sizeof(arr[0]);
 printf("sizeofarr is :%d\n",len);
    return 0;
}
//output 
sizeofarr is :6
