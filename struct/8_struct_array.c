#include <stdio.h>


struct data{
    char phone[10];
    char firstname[30];
    char lastname[30];
} records;

struct data list[4];
int i;

int main()
{
    for (int i = 0; i < 4; i++)
    {
        printf("\nEnter first name: ");
        scanf("%s" , list[i].firstname);
        printf("\nEnter last name: ");
        scanf("%s" , list[i].lastname);
        printf("Enter phone in 123-4567 format: "); 
        scanf("%s", list[i].phone); 
    }
    printf("\n\n");
    for(int i = 0; i < 4; i++)
    {
        printf("Name: %s %s", list[i].firstname, list[i].lastname); 
        printf("\t\tPhone: %s\n", list[i].phone); 
    }
    return 0;
}