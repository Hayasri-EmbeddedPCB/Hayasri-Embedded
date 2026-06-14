#include <stdio.h>
#include <string.h>

union students {
    char name[20];
    int age;
    float marks;
};

int main() {
    union students d;

    // ஒண்ணு போட்டு print, பிறகு இன்னொண்ணு!
    strcpy(d.name, "Priya");
    printf("Name  : %s\n", d.name);   // ✅

    d.age = 21;
    printf("Age   : %d\n", d.age);    // ✅

    d.marks = 82.45;
    printf("Marks : %.2f\n", d.marks); // ✅

    // Size பாரு!
    printf("Size  : %lu bytes\n", sizeof(d)); // 20 bytes only!

    return 0;
}
//output 
Name  : Priya
Age   : 21
Marks : 82.45
Size  : 20 bytes
  
