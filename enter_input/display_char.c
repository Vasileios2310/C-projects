#include <stdio.h>
#include <conio.h>

 int main(void) {

    char ch;

    printf("Enter a character :");
    //ch = getchar();               // needs enter after character
    ch = getche();                  // dont need enter
    printf("\n its ASCII code is %d: " , ch);

    return 0;
}