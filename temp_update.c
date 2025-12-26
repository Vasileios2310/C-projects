#include <stdio.h>

int main(){

    int arr[] = {1 , 3 , 5 , 7 , 9};
    int size = sizeof(arr)/sizeof(arr[0]);

    arr[0] = 11;
    arr[1] = 33;

    for(int i = 0; i < size; i++){
        printf("%d\n" , arr[i]);
    }
    printf("\n");
}