#include <stdio.h>
#include <stdlib.h>

int x = 12; // global scope
void Func(void);


int main()
{
    printf("The value of x inside of main is %d\n", x);
    int x = 38;
    printf("Now x is %d:\n" , x);   // local scope
    Func();
    x = 22;
    printf("Now x is %d:\n" , x);   // local scope
    system("PAUSE");
    return 0;

}

void Func(void)
{
    printf("The value of x outside of main is %d\n", x); //global x
}