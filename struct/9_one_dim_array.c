#include <stdio.h>

int main(void)
{
    int i;
    int A[10];

    for (i = 0; i < 10; i++) {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < 10; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}