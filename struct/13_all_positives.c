#include <stdio.h>

int main(void)
{
    int i;
    int A[5];
    int positive;
  

    for (i = 0; i < 5; i++) {
        scanf("%d", &A[i]);
    }

    positive = 1;
    i = 0;
    while ((i < 5) && (positive))
    {
        if (A[i] <= 0)
            positive = 0;
        i++;
    }

    if(positive)
    printf("all positives");
    else
        printf("at least one is negative");
    
}