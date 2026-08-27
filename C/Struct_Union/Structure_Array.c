#include <stdio.h>
#include <string.h>
struct students
{
    char name[50];
    int age;
    float marks;
};
int main() {
struct students s[3];
strcpy(s[0].name,"Hayasri");
s[0].age=29;
s[0].marks=95.2;
strcpy(s[1].name,"Shyreas");
s[1].age =31;
s[1].marks=93.2;
strcpy(s[2].name,"Vatsala");
s[2].age=30;
s[2].marks=97;
for (int i=0; i<3;i++){
printf("Name :%s\n",s[i].name);
printf("Age :%d\n",s[i].age);
printf("Marks :%2f\n",s[i].marks);
}
    return 0;
}
//output 
Name :Hayasri
Age :29
Marks :95.199997
Name :Shyreas
Age :31
Marks :93.199997
Name :Vatsala
Age :30
Marks :97.000000
  
