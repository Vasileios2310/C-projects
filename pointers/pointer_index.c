#include <stdio.h>

int main (void)
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p;
    
    printf("%d , %d , %d\n" , *p , *(p+1) , *(p+2));

    printf("%d , %d , %d ", a[0] , a[1] , a[2]);

}