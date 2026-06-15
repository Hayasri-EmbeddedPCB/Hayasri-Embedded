#include <stdio.h>

int main() {
    int arr[]={5,10,15,20,25};
    int *p=arr;
    int total=0;
    float avg;
    for (int i=0;i<5;i++){
        printf("Value in arr :%d\n",*p);
        total+=*p;
        p++;
    }
    printf("total marks of all students : %d\n",total);
    avg = total/5.0;
    printf("Average of all students: %2f\n ",avg);
    return 0;
}
//output
Value in arr :5
Value in arr :10
Value in arr :15
Value in arr :20
Value in arr :25
total marks of all students : 75
Average of all students: 15.000000
