#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Declare a struct, with attributes
 *  - float amount,
 *  - char firstname[30]
 *  - char lastname[30]
 *  - global variacle rec
 */
struct data{
    float amount;
    char firstname[30];
    char lastname[30];
} records;

/**
 * Here data is a variable type struct data
 */
void print_rec(struct data data)
{
    printf("\nDonor %s %s gave euro : %.2f.\n" , data.firstname , data.lastname , data.amount);
}

int main()
{
    printf("Enter the donor's first and last names,\n");
    printf("Seperated by a space");
    scanf("%s %s" , records.firstname , records.lastname);
    printf("Enter the donation amount:\n");
    scanf("%f", &records.amount);
    print_rec(records);
    return 0;
}