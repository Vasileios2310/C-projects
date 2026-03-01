#include <stdio.h>

int recur(int a)
{
    int result ;
    if(a < 3)
    {
        printf("*** a = %d\n" , a);
        result = recur(a+1) + 10;
    }
    else result = 0;
    printf("a=%d	apot=%d\n", a, result);
    return	result;
}

int main(void)
{
    int b;
    b = recur(1);
    printf("b=%d" , b);
}