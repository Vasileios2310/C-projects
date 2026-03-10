#include <stdio.h>

int main(void)
{
    int i;
    int A[5];
    int max = 0;
    int min = 0;
  

    for (i = 0; i < 5; i++) {
        scanf("%d", &A[i]);
    }

    max = A[0];
    min = A[0];

    for (i = 0; i < 5; i++) {
        if (A[i] > max){
            max = A[i];
        }
        if (A[i] < min){
            min = A[i];
        }
    }
    
    for(i = 0; i < 5; i++){
        if(A[i] == max)
        printf("Max number : %d\n in position : %d\n" , A[i] , max );
        if(A[i] == min)
        printf("Min number : %d\n in position : %d\n" , A[i] , min );
    }
}