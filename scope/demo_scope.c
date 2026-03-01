#include <stdio.h>
#include <stdlib.h>

void duplicate(int a , int b);

int main()
{
    int a = 4;
    int b = 5;

    duplicate(a , b);
    printf("The value of a in main is %d, ", a); 
    printf("the value of b in main is %d\n", b); 
    system("PAUSE");
    return 0;
}

void duplicate(int a , int b)
{
    a *= 2;
    b *= 2;

    printf("The value of a is duplicated to %d:", a);
    printf("The value of b is duplicated to %d:\n", b);
}