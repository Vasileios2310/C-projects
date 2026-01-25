#include <stdio.h>

void myfunc(int *num , int min , int max);

int main(void)
{
    int i;

    printf("Enter a number between 1 to 10");
    myfunc(&i , 1, 10);

    return 0;
}

void myfunc(int *num , int min , int max)
{
    do {
        scanf("%d" , &num);
    } while (*num < min || *num> max); 
}