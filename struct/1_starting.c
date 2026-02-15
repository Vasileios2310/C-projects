#include <stdio.h>

struct s_type
{
    int i;
    char ch;
    double d;
    char str[80];
} s;


int main(void){
    printf("Enter an integer : ");
    scanf("%d", &s.i);

    printf("Enter a character : ");
    scanf(" %c", &s.ch);

    printf("Enter a double : ");
    scanf("%lf", &s.d);

    printf("Enter an string : ");
    scanf("%s", s.str);

    printf("%d %c %f %s ", s.i , s.ch , s.d , s.str);

    return 0;
}