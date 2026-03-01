#include <stdio.h>

/*
    global struct (out of main)
*/
struct student {
    char name[30];
    float number;
}   student1 , student2; // declare variables of struct


int main()
{
    struct student student3;
    char ch1[30];
    float f;

    scanf("%s", student1.name);
    scanf("%f" , &student2.number);
    //student2.number = f;
        printf ("Name = %s \n", student1.name); 
        printf ("Number = %f \n", student2.number);   
    return (0); 
}