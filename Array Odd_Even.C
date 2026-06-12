include <stdio.h>

int main() {
    int numbers[5] = {1,3,4,8,7};
    for (int i=0;i<5;i++){
    if (numbers[i] % 2==0){
        printf("it is a even number :%d\n",numbers[i]);
    }
    else{
        printf("it is a odd number :%d\n",numbers[i]);
        
    }
    }
    return 0;
}
//output 

it is a odd number :1
it is a odd number :3
it is a even number :4
it is a even number :8
it is a odd number :7
