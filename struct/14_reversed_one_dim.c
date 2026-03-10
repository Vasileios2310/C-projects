#include <stdio.h>

int main(void)
{
    int i;
    int A[10];
    int temp;
  

    for (i = 0; i < 15; i++) {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < 15/2; i++) {
        temp = A[i];
        A[i] = A[14-i];
        A[14-i] = temp;
    }

    for(i = 0; i < 15; i++)
    {
        printf("%d" , A[i]);
    }
}