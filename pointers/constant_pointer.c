#include <stdio.h>
/*
In constant pointers, the memory address stored inside the pointer is constant 
and cannot be modified once it is defined.
It will always point to the same memory address.
*/
int main()
{
    int a = 10;
    int b = 20;

    int* const ptr = &a;

    // As we try here to assign ptr a new address, the compiler throws an error 
    // because a constant pointer cannot change the memory location
    // it was originally assigned.
    // ptr = &b;

    printf("%d" , ptr);
    return 0;
}