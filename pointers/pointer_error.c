#include <stdio.h>

int main (void)
{
    // Assigning that to an int * is incompatible
    // int *p;
    double *p;
    double q , temp;
    temp = 1234.34;
    
    p = &temp;
    q = *p;

    printf("%f" , q);

    return 0;

}