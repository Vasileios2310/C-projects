#include <stdio.h>

int main()
{
    char choice;

    printf("Give a character \t");

    scanf("%c" , &choice);

    char next_choice = choice + 1;

    printf("Your choice is %c and in ASCII code is %d\n" , choice , choice);

    printf("The next character in sequence is %c and in ASCII code is %d\n" , next_choice , next_choice);
}