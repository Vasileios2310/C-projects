#include <stdio.h>
/*
The size of a pointer in C depends on the architecture (bit system) of the machine, not the data type it points to.
On a 32-bit system, all pointers typically occupy 4 bytes.
On a 64-bit system, all pointers typically occupy 8 bytes.

The reason for the same size is that the pointers store the memory addresses,
no matter what type they are. As the space required to store the addresses of 
the different memory locations is the same, the memory required by one pointer 
type will be equal to the memory required by other pointer types.
*/
int main()
{
    int *ptr1;
    char *ptr2;

    printf("%zu \n" , sizeof(ptr1));
    printf("%zu \n", sizeof(ptr2));

    return 0;
}