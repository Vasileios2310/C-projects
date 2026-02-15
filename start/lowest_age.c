#include <stdio.h>
// a program that finds the lowest age among different ages
int main(){

    int ages[] = {35 , 34 , 71 , 65 , 62 , 71};

    int small_age = ages[0];
    int i;

    int length = sizeof(ages) / sizeof(ages[0]);

    for (i = 0; i < length; i++){
        if (small_age > ages[i]){
            small_age = ages[i];
        }
    }
    printf("the lowest age in ages is %d", small_age);
}