#include <stdio.h>

int main(void) {
    int a, b, choice;

    do {
        printf("\nChoose operation:\n");
        printf("1) +\n2) -\n3) *\n4) /\n5) %%\n0) Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        if (choice < 1 || choice > 5) {
            printf("Invalid choice.\n");
            continue;
        }

        printf("Give the first number: ");
        scanf("%d", &a);

        printf("Give the second number: ");
        scanf("%d", &b);

        switch (choice) {
            case 1:
                printf("The result is %d\n", a + b);
                break;
            case 2:
                printf("The result is %d\n", a - b);
                break;
            case 3:
                printf("The result is %d\n", a * b);
                break;
            case 4:
                if (b == 0) {
                    printf("Division by zero is forbidden.\n");
                } else {
                    printf("The result is %d\n", a / b); 
                }
                break;
            case 5:
                if (b == 0) {
                    printf("Modulo by zero is forbidden.\n");
                } else {
                    printf("The result is %d\n", a % b);
                }
                break;
        }

    } while (1);

    return 0;
}
