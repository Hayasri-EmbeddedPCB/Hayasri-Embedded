#include <stdio.h>
struct students
{
    char inital;
    int age;
    float marks;
};
int main() {
struct students s1;
s1.inital='H';
s1.age =29;
s1.marks=95.2;
printf("Inital :%c\n",s1.inital);
printf("Age :%d\n",s1.age);
printf("Marks :%1f\n",s1.marks);
    return 0;
}
//output 
Inital :H
Age :29
Marks :95.199997
