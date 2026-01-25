#include <stdio.h>

// declare a prototype , so compiler knows that exists and returns void
int get_a_char(void);


int main(void)
{
    char ch;

    ch = get_a_char();
    printf("%c" , ch);

    return 0;
}

// definition
int get_a_char(void)
{
    return 'a';
}