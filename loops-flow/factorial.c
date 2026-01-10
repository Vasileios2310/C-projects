#include <stdio.h>

int main() {

    int choice;
    int fact = 1;

    printf("Insert a positive integer ");
    scanf("%d" , &choice);

    if (choice < 0){
        printf("Please insert a positive integer");
        return 1;
    }

    while (choice >= 0)
    {
        for (int i = 1; i <= choice; i++){
        fact *= i; 
    }
    printf("Factorial for %d = %d\n" , choice , fact);
    return 0;
    }
}