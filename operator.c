#include <stdio.h>

int main (void)
{
    int count=0;
    int answer=0;

    for (count = 1; count <11; count++){
        printf("What is %d + %d ? " , count , count);
        scanf("%d", &answer);

        if (answer == count+count) printf("Right!");
        else{
            printf("Sorry you are wrong\n");
            printf("The answer is %d\n" , count+count);
        }
    }
}