#include <stdio.h>

void swap(int *i , int *j);

int main(void)
{
    int num1 = 15;
    int num2 = 20;

    printf("Before swap\n");
    printf("%d : num1 , %d : num2" , num1 , num2);

    swap(&num1 , &num2);
    printf("\nAfter swap\n");
    printf("%d : num1 , %d : num2" , num1 , num2);

    return 0;
}


void swap(int *i , int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}