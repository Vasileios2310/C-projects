#include <stdio.h>

int main(void)
{
    int i;
    int A[10];
    int count = 0;
    int x;

    for (i = 0; i < 10; i++){
        A[i] = 0;
    }
    do{
        scanf("%d" , &x);
    } while ((x <= 0) || (x > 999));
    while (x > 0)
    {
        A[count] = x % 2;
        x = x / 2;
        count++;
    }
    
    for(i = count - 1; i>=0; i--)
        printf("%d", A[i]);
}