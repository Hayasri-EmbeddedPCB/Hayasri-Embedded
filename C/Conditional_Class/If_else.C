#include <stdio.h>
int main()
{
int marks = 80;
if (marks>=90){
    printf(" Your grade is : A\n",marks);
}
else if (marks>=80){
    printf(" Your grade is : B\n",marks);
}
else if (marks>=70){
    printf(" Your grade is : C\n",marks);
}
else if (marks>=50){
    printf(" Your grade is : D\n",marks);
}
else {
    printf ("Fail",marks);
}
return 0;
}
