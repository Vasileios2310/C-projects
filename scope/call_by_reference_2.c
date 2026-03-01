#include <stdio.h>
#include <stdlib.h>

/*
    pointer parameter,
    absolute(&b) modifies the original b
*/
void absolute(int *a)
{
    if (*a < 0)
    {
        *a = -(*a);
    }
    return;
}

/*
    normal value parameter
    absoluteByValue(c) only changes a local copy of c
*/
void absoluteByValue(int a)
{
    if (a < 0)
    {
        a = -(a);
    }
    return;
}

int main()
{
    int b = -5; 
    int c = -12;
    printf( "Value of b before invoking absolute is: %d\n" , b ); 
    absolute(&b); //call by reference - pass by value of a pointer.
    printf( "Value of b after invoking absolute is: %d\n" , b ); 

    printf("----------------\n");

    printf( "Value of c before invoking absoluteByValue is: %d\n" , c ); 
    absoluteByValue(c); //call by value
    printf( "Value of c after invoking absoluteByValue is: %d\n" , c ); 


    system("PAUSE"); 
    return 0; 
}