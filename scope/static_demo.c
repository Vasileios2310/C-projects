#include <stdio.h>
#include <stdlib.h>

void Func(void);

int main()
{
    int count;
    for(count = 0; count < 5; count++)
    {
        printf("At iteration %d: ", count);
        Func();
    }
    system("PAUSE");
    return 0;
}
/*
    A static variable inside a function keeps its value between invocations.
    A static global variable or function is "seen" only in the file in which it's declared.
*/
void Func(void)
{
    static int x = 0; // initialized only once and holds the value 
    int y = 0; // local variable that everytime holds the value 0

    printf("x = %d , y = %d\n" , x++ , y++);
}