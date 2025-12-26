#include <stdio.h>
// 
int main(){

    int matrix[2][3] = {{1,3,5} , {2,4,6}};
    matrix[0][0] = 111;

    printf("%d\n", matrix[0][2]);
    printf("%d\n", matrix[1][2]);
    printf("%d\n", matrix[0][0]);

    printf("\n");

    int i , j ;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 3; j++){
            printf("%d\n", matrix[i][j]);
        }
    }
}