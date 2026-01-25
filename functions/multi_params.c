#include <stdio.h>

void sayHello(char name[] , int age)
{
    printf("Hello my name is %s , i am %d \n" , name , age);
}


int main(void)
{
    sayHello("Alice" , 12);
    sayHello("Bob" , 14);

    return 0;
}