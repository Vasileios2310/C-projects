#include <stdio.h>
// skip negative values, but stop the loop completely if we find a zero:
int main(){
    int ages[] = {-35 , 34 , -71 , -65 , 62 , 0 , -5};
    int my_number;
    int i;
    int length = sizeof(ages) / sizeof(ages[0]);

    for (i = 0; i < length; i++){
        if (ages[i] < 0){
            continue;
        }
        if (ages[i] == 0){
            break;
        }
    }
      printf("the zero number is in position %d", i);
}