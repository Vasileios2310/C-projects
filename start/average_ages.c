#include <stdio.h>

int main(){

    int ages[] = {35 , 34 , 71 , 65 , 62 , 71};

    float average = 0;
    float sum = 0;
    int i;

    int length = sizeof(ages) / sizeof(ages[0]);

    for (i = 0; i < length; i++){
        sum += ages[i]; 
    
    }

    average = sum / length;

    printf("the average age is %0.2f", average);
}