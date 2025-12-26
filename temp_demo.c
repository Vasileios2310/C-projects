#include <stdio.h>

int main()
{
    float arr[] = {1 , 2 , 3.5 , 12 , 99};
    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < size; i++){
        printf("%0.2f\n" , arr[i]);
    }

    int arr2[] = {2 , 4 , 6 , 8};

    printf("%d\n" , arr2[1]);

    printf("%0.2f" , arr[1]);


    return 0;
}