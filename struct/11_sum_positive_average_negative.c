#include <stdio.h>

int main(void)
{
    int i;
    int A[10];
    int sum = 0;
    int average = 0;
    int count = 0;

    for (i = 0; i < 10; i++) {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < 10; i++) {
        if (A[i] > 0){
            sum += A[i];
            count++;
        }
        else average += A[i];
    }
    printf("Average = %d\n" ,  average / count );
    printf("Sum = %d " , sum);
    //return 0;
}