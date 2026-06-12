#include <stdio.h>
#include <string.h>

int main() {
char first[] = "Embedded";
char second[] = "System";
strcat(first,second);
    printf("Joined word is :%s\n",first);
    char course[20];
    strcpy(course,first);
    printf("copied word is :%s\n",course);
    return 0;
}
//ouput
Joined word is :EmbeddedSystem
copied word is :EmbeddedSystem
