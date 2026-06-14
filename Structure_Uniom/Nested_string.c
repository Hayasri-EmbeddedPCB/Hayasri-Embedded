#include <stdio.h>
#include <string.h>

struct address {
    char city[20];
    int pincode;
    int door;
};

struct student {
    char name[20];
    struct address addr;  
};

int main() {
    struct student s1;

    strcpy(s1.name, "Priya");
    strcpy(s1.addr.city, "Coimbatore");
    s1.addr.pincode = 642001;
    s1.addr.door = 2;

    printf("Name    : %s\n", s1.name);
    printf("City    : %s\n", s1.addr.city);
    printf("Pincode : %d\n", s1.addr.pincode);
    printf("Door No : %d\n", s1.addr.door);

    return 0;
}

//output 
Name    : Priya
City    : Coimbatore
Pincode : 642001
Door No : 2
