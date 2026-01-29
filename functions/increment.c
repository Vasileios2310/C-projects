#include <stdio.h>
/* j --> local varaible, everytime calls increment, it starts with 2 (forgets the value)
*  k --> static storage duration starts with 2 , but holds the value between calls
*/
void increment(void);

int main ()
{
    increment();
    increment();
    increment();
}

void increment(void)
{
    int j = 2;
    static int k = 2;
    printf("j:%d\tk:%d\n", j++, k++);
}