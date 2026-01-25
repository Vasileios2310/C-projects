#include <stdio.h>

void set_to_10(int a)
{
    a = 10; // changes the copy
}


int main(void)
{
    int x = 5;
    printf("%d :\n" , x);
    
    set_to_10(x);
    printf("%d :\n" , x);

    return 0;
}