#include <stdio.h>
#include <math.h>

int main(void){

    double num;

    printf("Give a positive number");

    scanf("%lf",&num);

    if (num<0) {
        printf("The number must be positive: ");
    }
    else {
        printf("The root for number %.2f = %.2f " , num, sqrt(num));   
    }

    return 0;
}