#include <stdio.h> 
#include <stdlib.h>


int Func(int x);

int main()
{
    int x = 4;
    printf("The %d! is equal to %d\n", x,Func( x )); 
    system("PAUSE");
    return 0;
}

int Func(int x)
{
    int z = 1;
    if (x > 1)
    {
        z = x * Func(x - 1);
    }
    return z;
}