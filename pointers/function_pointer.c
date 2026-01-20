#include <stdio.h>
/*
A function pointer is a type of pointer that stores the address of a function,
allowing functions to be passed as arguments and invoked dynamically. It is useful in techniques such as
callback functions, event-driven programs.
*/

int add (int a , int b)
{
    return a + b;
}

int main()
{
    int (*fptr)(int , int);

    fptr = &add;

    printf("%d" , fptr(10 , 18));

    return 0;
}