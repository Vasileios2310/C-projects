#include <stdio.h>

int main ()
{
    int var = 10;
    int var1 = 10;

    int *ptr = &var;
    int *ptr1 = &var1;

    // deregerence the pointer
    printf("%d \n" , *ptr);

    
    printf("%d" , ptr1);

    return 0;

}