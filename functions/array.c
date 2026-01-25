#include <stdio.h>

void myNumber( int age[5])
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d " , age[i]);
    }
}


int main(void)
{
    int numbers[5] = {10 , 20 , 30 , 40 , 50};
    myNumber(numbers);
    return 0;
}