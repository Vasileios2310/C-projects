#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 120;
    int i;

    printf("The value of x before loop is : %d\n", x);
    for(i = 0; i < 5; i++)
    {
        int x = i;
        printf("The value of x inside the for loop is %d\n", x); 
    }
    printf("The value of x after loop is : %d\n", x);
    system("PAUSE");
    return 0;
}