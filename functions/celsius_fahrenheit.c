#include <stdio.h>

float toCelsius(float fahrenheit){
    return (5.0 / 9.0) * (fahrenheit -32.0);
}

int main(){

    float far_value = 98.8;

    float result = toCelsius(far_value);

    printf("Fahrenheit : %.2f\n" , far_value);

    printf("Convert to celsious : %.2f\n" , result);

    return 0;
}