#include <stdio.h>
#include <math.h>

int main(void){

    int a;
    int b;
    int max;
    printf("Give the first number");
    scanf("%d",&a);

    printf("Give the second number");
    scanf("%d",&b);

    
    if (a > b){
        max = a;
        printf("The max number between a: %d and b: %d is: %d\n", a, b, max);
    }
    else if (b > a){
        max = b;
        printf("The max number between a: %d and b: %d is: %d\n", a, b, max);
    }
    else {
        printf(" a: %d = b: %d  " ,  a , b );
    }

    // return (a > b) ? a : b;
}