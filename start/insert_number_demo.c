#include <stdio.h>

int main()
{
    char choice;

    printf("Give a number between 66 to 90 \t");

    scanf("%d" , &choice);

    char previous_choice = choice -1;
    char next_choice = choice +1;

    printf("Your choices are %c --> %c --> %c , and in ASCII code are %d --> %d --> %d\n" , previous_choice, choice , next_choice , previous_choice , choice , next_choice);
}