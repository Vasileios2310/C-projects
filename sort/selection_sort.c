#include <stdbool.h>
#include <stdio.h>

void selectionSort(int arr[] , int n){

    for (int i = 0; i < n - 1 ; i++ ){
        int min_index = i;

        // iterate through the unsorted portion, to find the actual minimum
        for (int j = i + 1; j < n ; j++){
            if(arr[j] < arr[min_index]){
                // Update min_idx if a smaller element is found
                min_index = j;
            }    
        }
        // Move minimum element to its correct position
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

}

void printArray(int arr[] , int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}