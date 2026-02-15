#include <stdio.h>

struct s_type
{
    int i;
    char ch;
    int *p;
    double d;
    // int i_2;
    // char ch_2;
    // int *p_2;
    // double d_2;
} s;


int main(void){
    printf("s_type is %d bytes long" , sizeof(struct s_type));
}