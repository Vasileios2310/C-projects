#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct struct_type {
    int a;
    int b;
    char ch;
};

void func(struct struct_type parm)
{
    printf("%d" , parm.a);
}

int main()
{
    struct struct_type arg;
    arg.a = 1000;
    func(arg);
    return 0;
}
