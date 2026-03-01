#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct address
{
    char name[400];
    char street[400];
    char city[400];
    char state[30];
    char zip[100];
};

int main()
{
    struct address *p;

    if ((p = (struct address*)malloc(sizeof(struct address))) == NULL) {
        printf("Allocation Error\n");
        exit(1);
    }
    printf("Allocation done\n");
    return 0;
}