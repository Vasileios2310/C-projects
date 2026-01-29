#include <stdio.h>

int checkOddEven(int a)
{

    return(a % 2); //The & operator does a bitwise and
}

int main (void)
{

    int n;

    printf("\n\n Function : check the number is even or odd:\n");
	printf("------------------------------------------------\n");	     
    printf("Input any number : ");
    scanf("%d", &n);

    if(checkOddEven(n) != 0)
    {
        printf("The entered number is odd.\n\n");
    }
    else
    {
        printf("The entered number is even.\n\n");
    }

    return 0;
}