#include <stdio.h>

float getNum(void)
{
    float x;

    printf("Enter a number :");
    scanf("%f" , &x);
    return x;
}


int main()
{
    float i;

    i = getNum();
    printf("%f", i);
    return 0;
}