#include <stdio.h>

void prompt(char *message , int *number)
{
    printf(message);
    scanf("%d", number);
}


int main(void)
{
    int i;
    prompt("Enter a number\n" , &i);
    printf("Your number is : %d\n" , i);    

    return 0;
}