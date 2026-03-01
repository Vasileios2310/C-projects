#include <stdio.h>
#include <stdlib.h>

void Func(int * , int);

int main()
{
    int x = 111;
    int y = 111;

    printf( "Value of x before invoking Func is: %d\n" , x ); 
    printf( "Value of y before invoking Func is: %d\n" , y ); 

    // x --> by reference , y --> by value
    // copy of the address of x and a copy of the value of y
    Func(&x,y);

    printf( "Value of x after invoking Func is: %d\n" , x ); 
    printf( "Value of y after invoking Func is: %d\n" , y ); 

    system("PAUSE");
    return 0;

}

/*
    x is passed as a pointer to its address, 
    so Func can modify the original x in main.
*/
void Func( int *x , int y)
{
    *x = 999;
    y = 999;
    return;
}