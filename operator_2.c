#include <stdio.h>

int main(void)
{
    int i = 0;
    int a = 0;

    i++; // i increased from 0 to 1
    a = ++i; // first i is increased and after a takes the value from i
    a = i++;  // first a takes the value from i and then i is increased
    printf("i = %d " , i);
    printf("a = %d " , a);

    i--;
    printf("i = %d " , i);

    return 0;

}