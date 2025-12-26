#include <stdio.h>

int main(void) {
    int arr[5] = {23, 10, 1, 11, 90};

    printf("Printing Array elements\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Printing Array Elements in Reverse\n");
    for (int i = 4; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
