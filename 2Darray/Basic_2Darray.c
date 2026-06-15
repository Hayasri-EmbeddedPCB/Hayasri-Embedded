#include <stdio.h>

int main() {
    int matrix[2][3] ={{1,2,3},{4,5,6}};
    for (int i=0;i<2;i++){
for (int j=0;j<3;j++){
        printf("matrix[%d][%d] = %d\n", i, j, matrix[i][j]);
    }
    }
    return 0;
}
//output 
matrix[0][0] = 1
matrix[0][1] = 2
matrix[0][2] = 3
matrix[1][0] = 4
matrix[1][1] = 5
matrix[1][2] = 6
